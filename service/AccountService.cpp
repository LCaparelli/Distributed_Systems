#include "AccountService.h"
#include "../ServerEndpoint.h"
#include <pthread.h>

using json = nlohmann::json;

//function to create accounts, it parses the request and puts a new account in the vector
std::string AccountService::createAccount(std::string request) {
    json j = json::parse(request);

    Account newAccount(
            move(j["name"].get<std::string>()),
            move(j["address"].get<std::string>()),
            j["balance"].get<float>());

    std::string response;

    pthread_mutex_lock(&account_mutex);
    auto it = std::find_if(accounts.begin(), accounts.end(), [&](const Account& account) {
        return account.name() == newAccount.name();
    });

    if (it == end(accounts)) {
        accounts.push_back(newAccount);

        pthread_mutex_unlock(&account_mutex);

        response = "Account Created! \n name: " + j["name"].get<std::string>()
                   + "\n address: " + j["address"].get<std::string>() +
                   "\n balance: " + std::to_string(j["balance"].get<float>());
    } else {
        pthread_mutex_unlock(&account_mutex);
        response = "Account already exists!";
    }
    return response;
}

//function to find an account, given the accounts owner name
std::string AccountService::findAccount(std::string name) {
    pthread_mutex_lock(&account_mutex);
    auto it = std::find_if(accounts.begin(), accounts.end(), [&](const Account& account) {
        return account.name() == name;
    });
    pthread_mutex_unlock(&account_mutex);

    if (it == end(accounts)) {
        return "Account doesn't exist";
    } else {
        const auto& foundAccount = *it;
        return foundAccount.toJSON();
    }

}