//
// Created by darocha on 10/05/19.
//

#include "AccountModel.h"
#include "../json/single_include/nlohmann/json.hpp"

using json = nlohmann::json;
using namespace std;


Account::Account(string name, string address, float balance)
        : name_(move(name)), address_(move(address)), balance_(balance) {}

string Account::address() const {
    return address_;
}

string Account::name() const {
    return name_;
}

float Account::balance() const {
    return balance_;
}

string Account::toJSON() const {
    json j;
    j["name"] = name();
    j["address"] = address();
    j["balance"] = balance();
    return j.dump();
}
