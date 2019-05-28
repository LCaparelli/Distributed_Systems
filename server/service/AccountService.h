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
    std::string create_account(std::string request);
    std::string find_account(long id);
    std::string update_account(long id, Account update_account);
    std::string delete_account(long id);
    bool does_account_exists(std::vector<Account, std::allocator<Account>>::iterator it);
    std::vector<Account, std::allocator<Account>>::iterator get_account_iterator(long id) const;
};
#endif //EPDSID2_ACCOUNTSERVICE_H