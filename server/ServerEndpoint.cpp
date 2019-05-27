#include "../socket/ServerSocket.h"
#include <string>
#include <iostream>
#include "json/single_include/nlohmann/json.hpp"
#include "model/AccountModel.h"
#include "service/AccountService.h"
#include <pthread.h>
#include "../socket/SocketException.h"
#include "ServerEndpoint.h"
#include <sys/socket.h>
#include <queue>
#include <set>

#define NUM_THREADS 10

using json = nlohmann::json;
using namespace std;


// Declaration of global variables which will be used for sync
pthread_mutex_t account_mutex;
pthread_cond_t work_cond;
pthread_mutex_t sock_queue_mutex;
pthread_mutex_t id_mutex;
pthread_mutex_t thread_count_mutex;

// Global data structure for keeping accounts
std::vector<Account> accounts;

// Global var for keeping track of working threads
int available_threads = NUM_THREADS;

// ID for accounts
long global_id = 0;

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

    } else if (operation == "GET") {

        long id = requestJson["id"].get<long>();
        return accountService.findAccount(id);

    } else if (operation == "DELETE") {

        long id = requestJson["id"].get<long>();
        return accountService.deleteAccount(id);

    } else if (operation == "PUT") {

        Account updateAccount(
                requestJson["id"].get<long>(),
                move(requestJson["name"].get<std::string>()),
                move(requestJson["address"].get<std::string>()),
                requestJson["balance"].get<float>());

        return accountService.updateAccount(
                requestJson["id"].get<long>(),
                updateAccount);
    }

}

void* create_ephemeral_thread(void* arg) {
    pthread_mutex_lock(&sock_queue_mutex);
    auto* sock = socket_FIFO_queue.front();
    socket_FIFO_queue.pop();
    pthread_mutex_unlock(&sock_queue_mutex);

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
    // Dies as its work is done and it doesn't belong to the original pool
    pthread_exit(nullptr);
}

void* work_on_request(void *arg) {
    // Blocks until the condition signal is received and return code is 0 (successful).
    while (!pthread_cond_wait(&work_cond, &sock_queue_mutex)) {
        /*
         * Entering this code section means this thread acquired the socket queue mutex,
         * no need to lock it. This is done by pthread_cond_wait(). As per
         * pthread_cond_signal(3) man page:
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

        pthread_mutex_lock(&thread_count_mutex);
        available_threads--;
        pthread_mutex_unlock(&thread_count_mutex);

        auto* sock = socket_FIFO_queue.front();
        socket_FIFO_queue.pop();
        pthread_mutex_unlock(&sock_queue_mutex);

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

        pthread_mutex_lock(&thread_count_mutex);
        available_threads++;
        pthread_mutex_unlock(&thread_count_mutex);
    }
}


int main() {
    // Create the socket
    ServerSocket server(8080);

    // Initiate mutexes and condition variable
    pthread_mutex_init(&account_mutex, nullptr);
    pthread_mutex_init(&sock_queue_mutex, nullptr);
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
                pthread_mutex_lock(&sock_queue_mutex);
                socket_FIFO_queue.push(&new_sock);

                pthread_mutex_lock(&thread_count_mutex);
                if(available_threads == 0) {
                    pthread_mutex_unlock(&thread_count_mutex);
                    // generate ephemeral detached thread
                    pthread_t ephemeral_thread;
                    pthread_create(&ephemeral_thread, nullptr, create_ephemeral_thread, nullptr);
                } else {
                    pthread_mutex_unlock(&thread_count_mutex);
                    // Signals one blocked thread there is work to be done
                    pthread_cond_signal(&work_cond);
                }
                pthread_mutex_unlock(&sock_queue_mutex);
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






