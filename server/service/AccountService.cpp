#include "AccountService.h"
#include "../ServerEndpoint.h"
#include <pthread.h>
#include <sstream>

#define INVALID_BALANCE 999999999999

using json = nlohmann::json;


std::string floatToString(float val) {
    std::ostringstream ss;
    ss << val;
    return ss.str();
}

//function to create accounts, it parses the request and puts a new account in the vector
std::string AccountService::createAccount(std::string request) {
    json j = json::parse(request);

    pthread_mutex_lock(&id_mutex);
    global_id++;
    pthread_mutex_unlock(&id_mutex);

    Account newAccount(
            global_id,
            move(j["name"].get<std::string>()),
            move(j["address"].get<std::string>()),
            j["balance"].get<float>());

    std::string response;

    pthread_mutex_lock(&account_mutex);

    accounts.push_back(newAccount);

    pthread_mutex_unlock(&account_mutex);

    response = "Account created! \n id: " + std::to_string(global_id)
            + "\n name: " + j["name"].get<std::string>()
            + "\n address: " + j["address"].get<std::string>() +
            "\n balance: " + floatToString(j["balance"].get<float>());

    return response;
}


bool AccountService::doesAccountExists(std::vector<Account, std::allocator<Account>>::iterator it) {
    return !(it == end(accounts));
}


//function to find an account, given the accounts owner name
std::string AccountService::findAccount(long id) {
    auto it = getAccountIterator(id);
    bool accountExists = doesAccountExists(it);

    if (!accountExists) {
        return "Account doesn't exist.";
    } else {
        const auto& foundAccount = *it;

        std::string response = "Found account!\n name: " + foundAccount.name()
                   + "\n address: " + foundAccount.address() +
                   "\n balance: " + floatToString(foundAccount.balance());
        return response;
    }

}


std::vector<Account, std::allocator<Account>>::iterator AccountService::getAccountIterator(long id) const {
    pthread_mutex_lock(&account_mutex);
    auto it = find_if(accounts.begin(), accounts.end(), [&](const Account& account) {
        return account.id() == id;
    });
    pthread_mutex_unlock(&account_mutex);
    return it;
}


std::string AccountService::updateAccount(long id, Account updateAccount) {
    auto it = getAccountIterator(id);
    bool accountExists = doesAccountExists(it);

    if (!accountExists) {
        return "Account doesn't exist.";
    } else {

        auto& foundAccount = *it;

        if (!updateAccount.address().empty()) {
            foundAccount.setAddress(updateAccount.address());
        }

        if (updateAccount.balance() != INVALID_BALANCE) {
            foundAccount.setBalance(updateAccount.balance());
        }

        if (!updateAccount.name().empty()) {
            foundAccount.setName(updateAccount.name());
        }


        std::string response = "Account Updated!\n name: " + foundAccount.name()
                               + "\n address: " + foundAccount.address() +
                               "\n balance: " + floatToString(foundAccount.balance());
        return response;
    }
}

std::string AccountService::deleteAccount(long id) {
    auto it = getAccountIterator(id);
    bool accountExists = doesAccountExists(it);

    if (!accountExists) {
        return "Account doesn't exist.";
    } else {
        pthread_mutex_lock(&account_mutex);
        accounts.erase(it);
        pthread_mutex_lock(&account_mutex);
        return "Account Deleted;";
    }
}