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

//#define NUM_THREADS 10

pthread_mutex_t account_mutex;

using json = nlohmann::json;
using namespace std;

std::string processRequest(std::string& request) {
    json requestJson = json::parse(request);
    std::string operation = requestJson["operation"].get<std::string>();
    AccountService accountService;
    if (operation == "POST") {
        return accountService.createAccount(requestJson);
    } else {
        return accountService.findAccount(requestJson);
    }
}

void *start_processing_thread(void *socket) {
    ServerSocket* sock = (ServerSocket*) socket;


    std::string request;
    *sock >> request;
    std::string response = processRequest(request);
    *sock << response;
}

int main() {
    // Create the socket
    ServerSocket server(8080);

    //pthread_t threads[NUM_THREADS];
    //int active_threads = 0;

    pthread_mutex_init(&account_mutex, NULL);

    while (true) {

        ServerSocket new_sock;
        server.accept(new_sock);

        pthread_t new_thread;
        pthread_create(&new_thread, NULL, &start_processing_thread, (void *)&new_sock);

    }

    return 0;
}






