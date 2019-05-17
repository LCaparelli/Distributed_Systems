#include "AccountService.h"
#include "../ServerEndpoint.h"
#include <pthread.h>
#include <sstream>

using json = nlohmann::json;


std::string floatToString(float val) {
    std::ostringstream ss;
    ss << val;
    return ss.str();
}

//function to create accounts, it parses the request and puts a new account in the vector
std::string AccountService::createAccount(std::string request) {
    json j = json::parse(request);
    global_id++;
    Account newAccount(
            global_id,
            move(j["name"].get<std::string>()),
            move(j["address"].get<std::string>()),
            j["balance"].get<float>());

    std::string response;

    pthread_mutex_lock(&account_mutex);

    accounts.push_back(newAccount);

    pthread_mutex_unlock(&account_mutex);

    response = "Account Created! \n id: " + std::to_string(global_id)
            + "\n name: " + j["name"].get<std::string>()
            + "\n address: " + j["address"].get<std::string>() +
            "\n balance: " + floatToString(j["balance"].get<float>());

    return response;
}

//function to find an account, given the accounts owner name
std::string AccountService::findAccount(long id) {
    pthread_mutex_lock(&account_mutex);
    auto it = std::find_if(accounts.begin(), accounts.end(), [&](const Account& account) {
        return account.id() == id;
    });
    pthread_mutex_unlock(&account_mutex);

    if (it == end(accounts)) {
        return "Account doesn't exist";
    } else {
        const auto& foundAccount = *it;
        return foundAccount.toJSON();
    }

}