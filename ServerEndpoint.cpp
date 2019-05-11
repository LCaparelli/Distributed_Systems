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

int main() {
    // Create the socket
    ServerSocket server(8080);

    while (true) {

        ServerSocket new_sock;
        server.accept(new_sock);

        while (true) {
            std::string request;
            new_sock >> request;
            std::string response = processRequest(request);
            new_sock << response;
        }


    }

    return 0;
}






