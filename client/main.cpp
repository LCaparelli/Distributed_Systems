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
    if (operation == "GET" || operation == "DELETE") {
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
    } else if(operation == "PUT") {
        std::getline(std::cin, id);
        std::getline(std::cin, name);
        std::getline(std::cin, address);
        std::getline(std::cin, balance);

        request = "{\"operation\":\"" + operation +
                  "\",\"id\":" + id +
                  ",\"name\":\"" + name +
                  "\",\"address\":\"" + address +
                  "\", \"balance\":" + balance +
                  "}";
    } else {
        std::string error = "Uso indevido. Operações permitidas:\n"
                            "GET|DELETE\n"
                            "<id>\n"
                            "***********************************\n"
                            "POST\n"
                            "<nome>\n"
                            "<endereço>\n"
                            "<saldo>\n"
                            "***********************************\n"
                            "PUT\n"
                            "<id>\n"
                            "<nome>\n"
                            "<endereço>\n"
                            "<saldo>\n";
        std::cerr << error;
        exit(1);
    }
    return request;
}