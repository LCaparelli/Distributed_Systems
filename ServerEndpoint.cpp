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
#include <queue>


#define NUM_THREADS 10

using json = nlohmann::json;
using namespace std;

pthread_mutex_t account_mutex;
std::vector<Account> accounts;
pthread_cond_t work_cond;
pthread_mutex_t queue_mutex;

queue<ServerSocket*> socket_FIFO_queue;

std::string processRequest(std::string &request) {
    json requestJson = json::parse(request);
    std::string operation = requestJson["operation"].get<std::string>();
    AccountService accountService;

    if (operation == "POST") {
        return accountService.createAccount(request);
    } else {
        string name = requestJson["name"].get<std::string>();
        return accountService.findAccount(name);
    }

}

void* work_on_request(void *arg) {
    while (true) {
        pthread_cond_wait(&work_cond, &queue_mutex);
        auto* sock = socket_FIFO_queue.front();
        socket_FIFO_queue.pop();
        pthread_mutex_unlock(&queue_mutex);

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

}


int main() {
    // Create the socket
    ServerSocket server(8080);

    pthread_mutex_init(&account_mutex, nullptr);
    pthread_mutex_init(&queue_mutex, nullptr);
    pthread_cond_init(&work_cond, nullptr);

    // Initialize thread pool
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_t new_thread;
        pthread_create(&new_thread, nullptr, work_on_request, nullptr);
    }


    while (true) {
        ServerSocket new_sock;
        try {
            while (server.accept(new_sock)) {
                pthread_mutex_lock(&queue_mutex);
                socket_FIFO_queue.push(&new_sock);
                pthread_cond_signal(&work_cond);
            }
        } catch (SocketException& e) {}
    }

    return 0;
}






