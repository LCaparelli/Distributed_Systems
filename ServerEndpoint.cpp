//
// Created by darocha on 11/05/19.
//
#include "socket/ServerSocket.h"
#include <string>
#include <iostream>
#include "json/single_include/nlohmann/json.hpp"
#include "model/AccountModel.h"
#include <mutex>
#include "service/AccountService.h"
#include<pthread.h>
#include "socket/SocketException.h"
#include <sys/socket.h>


//#define NUM_THREADS 10

pthread_mutex_t account_mutex;

using json = nlohmann::json;
using namespace std;

std::string processRequest(std::string &request) {
    json requestJson = json::parse(request);
    std::string operation = requestJson["operation"].get<std::string>();
    AccountService accountService;
    if (operation == "POST") {
        return accountService.createAccount(request);
    } else {
        return accountService.findAccount(request);
    }
}

void* start_processing_thread(void* arg) {
    auto s = (ServerSocket*) arg;

    ServerSocket new_sock;
    s->accept(new_sock);

    try {
        std::string request;
        new_sock >> request;
        std::string response = processRequest(request);
        new_sock << response;
    } catch (SocketException& e) {
        std::cout << e.description();
    }

}

int main() {
    // Create the socket
    ServerSocket server(8080);

    //pthread_t threads[NUM_THREADS];
    //int active_threads = 0;

    pthread_mutex_init(&account_mutex, nullptr);

    while (true) {
        try {
            pthread_t new_thread;
            pthread_create(&new_thread, nullptr, &start_processing_thread, &server);
        } catch (SocketException &e) {
            std::cout << e.description();
        }


    }

    return 0;
}






