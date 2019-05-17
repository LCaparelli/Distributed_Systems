#ifndef EPDSID_ACCOUNTMODEL_H
#define EPDSID_ACCOUNTMODEL_H


#include <string>

class Account {
public:
    Account(std::string name, std::string address, float balance);

    std::string address() const;

    std::string name() const;

    float balance() const;

    std::string toJSON() const;

private:
    std::string name_;
    std::string address_;
    float balance_;
};

#endif //EPDSID_ACCOUNTMODEL_H
