#include "AccountService.h"
#include "../ServerEndpoint.h"
#include <pthread.h>
#include <sstream>


using json = nlohmann::json;

//util function to convert float to string
std::string floatToString(float val) {
    std::ostringstream ss;
    ss << val;
    return ss.str();
}

//function to create accounts, it parses the request and puts a new account in the vector
std::string AccountService::create_account(std::string request) {
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

//this function checks if an iterator is at the end of the vector, if it is at the end then the account wasnt found
//otherwise the account was found
bool AccountService::does_account_exists(std::vector<Account, std::allocator<Account>>::iterator it) {
    pthread_mutex_lock(&account_mutex);
    const std::vector<Account, std::allocator<Account>>::iterator &accountsEnd = end(accounts);
    pthread_mutex_unlock(&account_mutex);

    return !(it == accountsEnd);
}


//function to find an account, given the accounts owner name
std::string AccountService::find_account(long id) {
    auto it = get_account_iterator(id);
    bool accountExists = does_account_exists(it);

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

//this function returns the iterator at the desired account position
std::vector<Account, std::allocator<Account>>::iterator AccountService::get_account_iterator(long id) const {
    pthread_mutex_lock(&account_mutex);
    auto it = find_if(accounts.begin(), accounts.end(), [&](const Account& account) {
        return account.id() == id;
    });
    pthread_mutex_unlock(&account_mutex);
    return it;
}


//this function updates the account
std::string AccountService::update_account(long id, Account update_account) {
    auto it = get_account_iterator(id);
    bool accountExists = does_account_exists(it);

    if (!accountExists) {
        return "Account doesn't exist.";
    } else {

        pthread_mutex_lock(&account_mutex);

        auto& foundAccount = *it;

        foundAccount.set_address(update_account.address());
        foundAccount.set_balance(update_account.balance());
        foundAccount.set_name(update_account.name());

        pthread_mutex_unlock(&account_mutex);

        std::string response = "Account Updated!\n id:" + std::to_string(id) +
                               "\n name: " + foundAccount.name()
                               + "\n address: " + foundAccount.address() +
                               "\n balance: " + floatToString(foundAccount.balance());
        return response;
    }
}

//this function deletes the account
std::string AccountService::delete_account(long id) {
    auto it = get_account_iterator(id);
    bool accountExists = does_account_exists(it);

    if (!accountExists) {
        return "Account doesn't exist.";
    } else {
        pthread_mutex_lock(&account_mutex);
        accounts.erase(it);
        pthread_mutex_unlock(&account_mutex);
        return "Account Deleted.";
    }
}