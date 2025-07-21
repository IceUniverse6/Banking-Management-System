#ifndef DEPOSITACCOUNT_H
#define DEPOSITACCOUNT_H
#include"Account.h"

class DepositAccount: public Account
{
public:
    DepositAccount(const std::shared_ptr<Costumer>&, const QString&, const QString&, const QString&, const QString&, const QDate&, const QString&, const QString&, double);

    QString getAccountType()const;
};

#endif // DEPOSITACCOUNT_H
