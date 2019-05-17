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


// Declaration of global variables which will be used for sync
pthread_mutex_t account_mutex;
pthread_cond_t work_cond;
pthread_mutex_t queue_mutex;

// Global data structure keeping accounts
std::vector<Account> accounts;

// Global socket queue to be used by threads
queue<ServerSocket*> socket_FIFO_queue;

std::string processRequest(std::string &request) {
    // Parse request string into json object
    json requestJson = json::parse(request);
    // Fetches operation from request
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
    // Blocks until the condition signal is received and return code is 0 (successful).
    while (!pthread_cond_wait(&work_cond, &queue_mutex)) {
        /*
         * Entering this code section means this thread acquired the mutex, no need to
         * lock it. This is done by pthread_cond_wait(). As per pthread_cond_signal(3)
         * man page:
         *
         * When each thread unblocked as a result of a pthread_cond_broadcast()
         * or pthread_cond_signal() returns from its call to pthread_cond_wait()
         * or pthread_cond_timedwait(), the thread shall own the mutex with which
         * it called pthread_cond_wait() or pthread_cond_timedwait(). The thread(s)
         * that are unblocked shall contend for the mutex according to the scheduling
         * policy (if applicable), and as if each had called pthread_mutex_lock().
         *
         * The next step is to acquire the socket from the queue and unlocking the
         * queue mutex.
         */

        auto* sock = socket_FIFO_queue.front();
        socket_FIFO_queue.pop();
        pthread_mutex_unlock(&queue_mutex);

        std::string request;
        try {
            // Read request from socket
            *sock >> request;
            if (!request.empty()) {
                // Process request and stores response
                std::string response = processRequest(request);
                // Writes response to socket stream
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

    // Initiate mutexes and condition variable
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
            // Blocks until a new request is received
            while (server.accept(new_sock)) {
                // Locks socket FIFO queue access in order to write to it
                pthread_mutex_lock(&queue_mutex);
                socket_FIFO_queue.push(&new_sock);
                // Signals one blocked thread there is work to be done
                pthread_cond_signal(&work_cond);
                pthread_mutex_unlock(&queue_mutex);
            }
        } catch (SocketException& e) {}
    }

    /*
     * This program can only be interrupted via signals, usually signal 2 (SIGINT) from
     * user interrupt (Ctrl+C) or signals 9 (SIGKILL) and 15 (SIGTERM). Due to that we
     * don't add a return statement for main nor do we destruct the mutexes,
     * condition variables and threads, as they will all be reclaimed by the OS once
     * the process exits and its memory address freed.
     */
}






