#include "AccountModel.h"
#include "../json/single_include/nlohmann/json.hpp"

using json = nlohmann::json;
using namespace std;

//Account data structure
Account::Account(long id, string name, string address, float balance)
        : id_(id), name_(move(name)), address_(move(address)), balance_(balance) {}

string Account::address() const {
    return address_;
}

string Account::name() const {
    return name_;
}

float Account::balance() const {
    return balance_;
}

long Account::id() const {
    return id_;
}

void Account::set_address(string address) {
    address_ = move(address);
}

void Account::set_name(string name) {
    name_ = move(name);
}

void Account::set_balance(float balance) {
    balance_ = balance;
}

string Account::toJSON() const {
    json j;
    j["id"] = id();
    j["name"] = name();
    j["address"] = address();
    j["balance"] = balance();
    return j.dump();
}
