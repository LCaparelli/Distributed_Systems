//
// Created by darocha on 11/05/19.
//
#include <iostream>
#include "ServerSocket.h"


ServerSocket::ServerSocket(int port) {
    Socket::create();
    Socket::bind(port);
    Socket::listen();
}

ServerSocket::~ServerSocket() {
}


const ServerSocket &ServerSocket::operator<<(const std::string &s) const {
    Socket::send(s);
    return *this;

}


const ServerSocket &ServerSocket::operator>>(std::string &s) const {
    Socket::recv(s);
    return *this;
}

void ServerSocket::accept(ServerSocket &sock) {
    Socket::accept(sock);
}