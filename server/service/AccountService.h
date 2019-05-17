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
};
#endif //EPDSID2_ACCOUNTSERVICE_H