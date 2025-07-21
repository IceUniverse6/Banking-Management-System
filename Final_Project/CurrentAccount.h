#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H
#include"Account.h"

class CurrentAccount:public Account
{
public:
    CurrentAccount(const std::shared_ptr<Costumer>&, const QString&, const QString&, const QString&, const QString&, const QDate&, const QString&, const QString&, double);

    QString getAccountType()const;
};

#endif // CURRENTACCOUNT_H
