//
// Created by darocha on 11/05/19.
//

#ifndef EPDSID2_ACCOUNTSERVICE_H
#define EPDSID2_ACCOUNTSERVICE_H

#include "../model/AccountModel.h"
#include <vector>
#include "../json/single_include/nlohmann/json.hpp"


class AccountService {
public:
    std::string createAccount(std::string request);
    std::string findAccount(long id);
    std::string updateAccount(long id, Account updateAccount);
    std::string deleteAccount(long id);
    bool doesAccountExists(std::vector<Account, std::allocator<Account>>::iterator it);
    std::vector<Account, std::allocator<Account>>::iterator getAccountIterator(long id) const;
};
#endif //EPDSID2_ACCOUNTSERVICE_H