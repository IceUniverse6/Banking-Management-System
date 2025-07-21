#ifndef INTERESTFREEACCOUNT_H
#define INTERESTFREEACCOUNT_H
#include"Account.h"

class InterestFreeAccount: public Account
{
public:
    InterestFreeAccount(const std::shared_ptr<Costumer>&, const QString&, const QString&, const QString&, const QString&, const QDate&, const QString&, const QString&, double);


    QString getAccountType()const;
};

#endif // INTERESTFREEACCOUNT_H
