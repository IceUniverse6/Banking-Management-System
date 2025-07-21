#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<memory>


#include"User.h"
#include"LinkedList.h"


#include<QString>
#include<QDate>

class Costumer;


class Account
{
private:

    std::shared_ptr<Costumer> owner;
    QString cardNumber;
    QString accountNumber;
    QString shebaNumber;
    QString cvv2;
    double balance;
    QDate expirationDate;
    QString password;
    QString staticSecondPassword;
    QString dynamicSecondPassword;

    double dailyTransfer;
    QDate lastTransferDate;

public:
    Account(const std::shared_ptr<Costumer>&, const QString&, const QString&, const QString&, const QString&, const QDate&, const QString&, const QString&, double);

    bool deposit(double);
    bool withdrawl(double);

    virtual QString getAccountType()const=0;

    //***************************************************************
    static std::shared_ptr<Account> createAccount(const QString&, const QString&, const QString&, const QString&, const QString&, const QString&, double,const LinkedList<User>&, LinkedList<Account>&);
    static bool removeAccount(const QString&, LinkedList<Account>&);
    static bool removeAccounts(const LinkedList<Account>&, LinkedList<Account>&);


    static bool transfer(std::shared_ptr<Account>, std::shared_ptr<Account>, double);

    static  QString createCardNumber(const QString&, const LinkedList<Account>&);
    static  QString createAccountNumber(const QString&, const LinkedList<Account>&);
    static  QString createShebaNumber(const QString&, const LinkedList<Account>&);
    static  QString createCvv2(const LinkedList<Account>&);

    static QString generateRandomDigits(size_t);

    static bool isCardNumberUnique(const QString&, const LinkedList<Account>&);
    static bool isAccountNumberUnique(const QString&, const LinkedList<Account>&);
    static bool isShebaNumberUnique(const QString&, const LinkedList<Account>&);
    static bool isCvv2Unique(const QString&, const LinkedList<Account>&);


    static std::shared_ptr<Account> findAccountByAccountNumber(const QString&, const LinkedList<Account>&);
    static std::shared_ptr<Account> findAccountByCardNumber(const QString&, const LinkedList<Account>&);
    //***************************************************************

    void setCardNumber(const QString&);
    void setAccountNumber(const QString&);
    void setShebaNumber(const QString&);
    void setCvv2(const QString&);
    void setBalance(double);
    void setExpirationDate(const QDate&);
    void setPassword(const QString&);
    void setStaticSecondPassword(const QString&);
    void setDynamicSecondPassword(const QString&);
    void clearDynamicSecondPassword();


    void addToDailyTransfer(double);
    void resetDailyTransfer();
    void setLastTransferDate(QDate);


    const std::shared_ptr<Costumer> getOwner()const;
    const QString getOwnerName()const;
    const QString& getCardNumber()const;
    const QString& getAccountNumber()const;
    const QString& getShebaNumber()const;
    const QString& getCvv2()const;
    double getBalance()const;
    const QDate& getExpirationDate()const;
    const QString& getPassword()const;
    const QString& getStaticSecondPassword()const;
    const QString& getDynamicSecondPassword()const;

    double getDailyTransfer()const;
    QDate getLastTransferDate()const;
};

#endif // ACCOUNT_H.
