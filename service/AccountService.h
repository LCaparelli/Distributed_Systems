//
// Created by darocha on 11/05/19.
//

#ifndef EPDSID2_ACCOUNTSERVICE_H
#define EPDSID2_ACCOUNTSERVICE_H

#include <mutex>
#include "../model/AccountModel.h"
#include <vector>
#include "../json/single_include/nlohmann/json.hpp"


class AccountService {
public:
    std::string createAccount(nlohmann::json request);
    std::string findAccount(std::string name);

private:
    typedef std::mutex Lock;
    typedef std::lock_guard<Lock> Guard;
    Lock accountsLock;
    std::vector<Account> accounts;
};
#endif //EPDSID2_ACCOUNTSERVICE_H
