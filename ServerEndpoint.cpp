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
    auto* sock = (ServerSocket*) arg;
    std::string request;
    try {
        *sock >> request;
        if (!request.empty()) {
            std::string response = processRequest(request);
            *sock << response;
        }
    } catch (SocketException& e) {
        sock->close();
    }

}

int main() {
    // Create the socket
    ServerSocket server(8080);

    //pthread_t threads[NUM_THREADS];
    //int active_threads = 0;

    pthread_mutex_init(&account_mutex, nullptr);
    while (true) {
        ServerSocket new_sock;
        try {
            while (server.accept(new_sock)) {
                pthread_t new_thread;
                pthread_create(&new_thread, nullptr, &start_processing_thread, (void *) &new_sock);
            }
        } catch (SocketException& e) {}
    }



    return 0;
}






