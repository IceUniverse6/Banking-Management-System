#include "InterestFreeAccount.h"

InterestFreeAccount::InterestFreeAccount(const std::shared_ptr<Costumer>& owner
                                         , const QString& cardNumber
                                         , const QString& accountNumber
                                         , const QString& shebaNumber
                                         , const QString& cvv2
                                         , const QDate& expirationDate
                                         , const QString& password
                                         , const QString& staticSecondPass
                                         , double balance=0)
    :Account(owner, cardNumber, accountNumber, shebaNumber, cvv2, expirationDate, password, staticSecondPass, balance)
{}

QString InterestFreeAccount::getAccountType()const{

    return "قرض الحسنه";

}
