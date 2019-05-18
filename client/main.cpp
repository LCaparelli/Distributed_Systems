#include <iostream>
#include <iostream>
#include "../socket/ClientSocket.h"
#include "../socket/SocketException.h"

std::string getRequest();

int main() {
    ClientSocket client_socket("localhost", 8080);

    auto request = getRequest();

    client_socket << request;
    client_socket >> request;

    std::cout << request << std::endl;

    return 0;

}

std::string getRequest() {
    std::string operation, name, address, balance, request, id;

    std::getline(std::cin, operation);
    if (operation == "GET") {
        std::getline(std::cin, id);


        request = "{\"operation\":\"" + operation +
                  "\",\"id\":" + id + "}";
    } else if(operation == "POST"){
        std::getline(std::cin, name);
        std::getline(std::cin, address);
        std::getline(std::cin, balance);

        request = "{\"operation\":\"" + operation +
                  "\",\"name\":\"" + name +
                  "\",\"address\":\"" + address +
                  "\", \"balance\":" + balance +
                  "}";
    } else {
        std::cout << "Uso indevido. Operações permitidas:\nGET\n<id>\n************\nPOST\n<nome>\n<endereço>\n<saldo>\n";
        exit(1);
    }

    return request;
}