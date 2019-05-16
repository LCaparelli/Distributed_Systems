//
// Created by darocha on 11/05/19.
//

#include "AccountService.h"
#include "../ServerEndpoint.h"
#include <pthread.h>


using json = nlohmann::json;

std::string AccountService::createAccount(std::string request) {
    json j = json::parse(request);

    Account newAccount(
            move(j["name"].get<std::string>()),
            move(j["address"].get<std::string>()),
            j["balance"].get<float>());

    pthread_mutex_lock(&account_mutex);
    accounts.push_back(newAccount);
    pthread_mutex_unlock(&account_mutex);

    std::string response = "Account Created! \n name: " + j["name"].get<std::string>()
            + "\n address: " + j["address"].get<std::string>() +
            "\n balance: " + std::to_string(j["balance"].get<float>());
    return response;
}

std::string AccountService::findAccount(std::string name) {

    auto it = std::find_if(accounts.begin(), accounts.end(), [&](const Account& account) {
        return account.name() == name;
    });

    if (it == end(accounts)) {
        return "Account doesn't exist";
    } else {
        const auto& foundAccount = *it;
        return foundAccount.toJSON();
    }

}