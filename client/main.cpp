#include <iostream>
#include <iostream>
#include <algorithm>
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


bool is_digits(const std::string &str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

std::string getRequest() {
    std::string operation, name, address, balance, request, id;
    std::cout << "Digite a operação desejada: ";
    std::getline(std::cin, operation);
    if (operation == "GET" || operation == "DELETE") {

        std::cout << "Digite o id: ";

        std::getline(std::cin, id);


        request = "{\"operation\":\"" + operation +
                  "\",\"id\":" + id + "}";
    } else if(operation == "POST"){

        std::cout << "Digite o nome: ";
        std::getline(std::cin, name);

        std::cout << "Digite o endereço: ";
        std::getline(std::cin, address);

        std::cout << "Digite o saldo: ";
        std::getline(std::cin, balance);

        if (!is_digits(balance)) {
            std::cerr << "Valor inválido, \"balance\" deve conter somente dígitos.";
            exit(1);
        }

        request = "{\"operation\":\"" + operation +
                  "\",\"name\":\"" + name +
                  "\",\"address\":\"" + address +
                  "\", \"balance\":" + balance +
                  "}";
    } else if(operation == "PUT") {

        std::cout << "Digite o id: ";
        std::getline(std::cin, id);

        std::cout << "Digite o nome: ";
        std::getline(std::cin, name);

        std::cout << "Digite o endereço: ";
        std::getline(std::cin, address);

        std::cout << "Digite o saldo: ";
        std::getline(std::cin, balance);

        if (!is_digits(balance)) {
            std::cerr << "Valor inválido, \"balance\" deve conter somente dígitos.";
            exit(1);
        }

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
