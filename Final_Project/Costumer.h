#ifndef COSTUMER_H
#define COSTUMER_H
#include"User.h"

class Account;

class Costumer: public User
{
private:

    LinkedList<Account> accounts;

public:
    Costumer(const QString&, const QString&, const QString&, int, const QString&, const QString&);

    void addAccount(std::shared_ptr<Account>);
    bool removeAccount(const QString&);
    bool removeAccounts();

    size_t getNumberOfAccounts()const;
    const LinkedList<Account>& getAccounts()const;
};

#endif // COSTUMER_H
