#ifndef EPDSID_ACCOUNTMODEL_H
#define EPDSID_ACCOUNTMODEL_H


#include <string>

class Account {
public:
    Account(long id, std::string name, std::string address, float balance);

    std::string address() const;

    std::string name() const;

    float balance() const;

    long id() const;

    std::string toJSON() const;

private:
    std::string name_;
    std::string address_;
    float balance_;
    long id_;
};

#endif //EPDSID_ACCOUNTMODEL_H
