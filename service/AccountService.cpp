//
// Created by darocha on 11/05/19.
//

#include "AccountService.h"
#include "../ServerEndpoint.h"
#include <pthread.h>


using json = nlohmann::json;

std::string AccountService::createAccount(json request) {
    pthread_mutex_lock(&account_mutex);

    Account newAccount(
            move(request["name"].get<std::string>()),
            move(request["address"].get<std::string>()),
            request["balance"].get<float>());

    accounts.push_back(newAccount);
    pthread_mutex_unlock(&account_mutex);

    return request;
}

std::string AccountService::findAccount(std::string name) {

    Guard guard(accountsLock);

    auto it = std::find_if(accounts.begin(), accounts.end(), [&](const Account& account) {
        return account.name() == name;
    });

    if (it == end(accounts)) {
        return "account doesn't exist";
    } else {
        const auto& foundAccount = *it;
        return foundAccount.toJSON();
    }

}