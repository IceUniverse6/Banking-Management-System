#include<ctime>


#include "Account.h"
#include"Costumer.h"
#include"DepositAccount.h"
#include"CurrentAccount.h"
#include"InterestFreeAccount.h"

Account::Account(const std::shared_ptr<Costumer>& owner
                 , const QString& cardNumber
                 , const QString& accountNumber
                 , const QString& shebaNumber
                 , const QString& cvv2
                 , const QDate& expirationDate
                 , const QString& password
                 , const QString& staticSecondPass
                 , double balance)
    :owner(owner),
    cardNumber(cardNumber),
    accountNumber(accountNumber),
    shebaNumber(shebaNumber),
    cvv2(cvv2),
    balance(balance),
    expirationDate(expirationDate),
    password(password),
    staticSecondPassword(staticSecondPass)
    ,dailyTransfer(0)
    ,lastTransferDate(QDate::currentDate().addDays(-1))
{}

bool Account::deposit(double amount){
    if (amount <= 0){
        return false;
    }
    balance += amount;
    return true;
}
bool Account::withdrawl(double amount){
    if (amount <= 0 || amount > balance) {
        return false;
    }
    balance -= amount;
    return true;
}

std::shared_ptr<Account> Account::createAccount(const QString& firstName
                                                , const QString& lastName
                                                , const QString& nationalId
                                                , const QString& accountType
                                                , const QString& accountPassword
                                                , const QString& staticSecondPass
                                                , double balance
                                                , const LinkedList<User>& allUsers
                                                , LinkedList<Account>& allAccounts)
{
    for(size_t i=0; i<allUsers.getListSize(); i++){


        if((allUsers[i]->getFirstName()==firstName)&&(allUsers[i]->getLastName()==lastName)&&(allUsers[i]->getNationalId()==nationalId)){

            std::shared_ptr<Costumer> targetCostumer = std::dynamic_pointer_cast<Costumer>(allUsers[i]);

            if(targetCostumer){

                if(targetCostumer->getNumberOfAccounts()==5){

                    throw std::runtime_error("1");

                }


                QString cardNumber=createCardNumber(accountType, allAccounts);
                QString accountNumber=createAccountNumber(accountType, allAccounts);
                QString shebaNumber=createShebaNumber(accountType, allAccounts);
                QString cvv2=createCvv2(allAccounts);

                QDate expirationDate=QDate::currentDate().addYears(5);
                QString staticSecondPassword=staticSecondPass;


                if(accountType=="سپرده"){

                    std::shared_ptr<DepositAccount> newAccount=std::make_shared<DepositAccount>(targetCostumer, cardNumber, accountNumber, shebaNumber, cvv2, expirationDate, accountPassword, staticSecondPassword, balance);

                    allAccounts.listPushBack(newAccount);
                    targetCostumer->addAccount(newAccount);
                    return newAccount;

                }
                else if(accountType=="جاری"){

                    std::shared_ptr<CurrentAccount> newAccount=std::make_shared<CurrentAccount>(targetCostumer, cardNumber, accountNumber, shebaNumber, cvv2, expirationDate, accountPassword, staticSecondPassword, balance);

                    allAccounts.listPushBack(newAccount);
                    targetCostumer->addAccount(newAccount);
                    return newAccount;
                }
                else if(accountType=="قرض الحسنه"){

                    std::shared_ptr<InterestFreeAccount> newAccount=std::make_shared<InterestFreeAccount>(targetCostumer, cardNumber, accountNumber, shebaNumber, cvv2, expirationDate, accountPassword, staticSecondPassword, balance);

                    allAccounts.listPushBack(newAccount);
                    targetCostumer->addAccount(newAccount);
                    return newAccount;
                }
            }
        }
    }
    return nullptr;

}
bool Account::removeAccount(const QString& accountNumber, LinkedList<Account>& allAccounts){
    std::shared_ptr<Node<Account>> previousAccount=nullptr;
    std::shared_ptr<Node<Account>> currentAccount=allAccounts.getListHead();

    while (currentAccount != nullptr) {
        if (currentAccount->getData()->getAccountNumber() == accountNumber) {
            if (previousAccount == nullptr) {
                allAccounts.setListHead(currentAccount->getNext());
                if (allAccounts.getListTail() == currentAccount) {
                    allAccounts.setListTail(nullptr);
                }
            } else {
                previousAccount->setNext(currentAccount->getNext());
                if (allAccounts.getListTail() == currentAccount) {
                    allAccounts.setListTail(previousAccount);
                }
            }

            allAccounts.setListSize(allAccounts.getListSize() - 1);
            return true;
        }

        previousAccount = currentAccount;
        currentAccount = currentAccount->getNext();
    }
    return false;
}

bool Account::removeAccounts(const LinkedList<Account>& targetAccounts, LinkedList<Account>& allAccounts){


    for(size_t i=0; i<targetAccounts.getListSize(); i++){

        if(!Account::removeAccount(targetAccounts[i]->getAccountNumber(), allAccounts)){

            return false;

        }
    }

    return true;
}



bool Account::transfer(std::shared_ptr<Account> fromAccount, std::shared_ptr<Account> toAccount, double amount){

    QDate today = QDate::currentDate();
    if (fromAccount->lastTransferDate != today) {
        fromAccount->resetDailyTransfer();
        fromAccount->setLastTransferDate(today);
    }

    if(fromAccount->getDailyTransfer()+amount>6000000){
        throw std::runtime_error("سقف تراکنش روزانه رد شده!");
    }

    double fee = amount*0.0001;
    double totalDebit = amount-fee;


    if(fromAccount->getBalance()<totalDebit){
        throw std::runtime_error("موجودی حساب کافی نیست!");
    }

    if((fromAccount->withdrawl(totalDebit))&&(toAccount->deposit(totalDebit))){
        fromAccount->addToDailyTransfer(amount);
        return true;
    }
    return false;
}

QString Account::createCardNumber(const QString& accountType, const LinkedList<Account>& allAccounts){
    QString cardNumber;
    if(accountType=="سپرده"){
        cardNumber="1234-0001";
    }
    else if(accountType=="جاری"){
        cardNumber="1234-0002";
    }
    else if(accountType=="قرض الحسنه"){
        cardNumber="1234-0003";
    }

    while(true){
        for(size_t i=0; i<2; i++){
            cardNumber+="-";
            cardNumber+=generateRandomDigits(4);
        }

        if(isCardNumberUnique(cardNumber, allAccounts)){
            break;
        }
        else{
            cardNumber.truncate(9);
            continue;
        }
    }

    return cardNumber;

}
QString Account::createAccountNumber(const QString& accountType, const LinkedList<Account>& allAccounts){
    QString accountNumber;

    if(accountType=="سپرده"){
        accountNumber="123-01-";
    }
    else if(accountType=="جاری"){
        accountNumber="123-02-";
    }
    else if(accountType=="قرض الحسنه"){
        accountNumber="123-03-";
    }

    while(true){
        accountNumber+=generateRandomDigits(8);

        if(isAccountNumberUnique(accountNumber, allAccounts)){
            break;
        }
        else{
            accountNumber.truncate(7);
            continue;
        }
    }

    return accountNumber;

}
QString Account::createShebaNumber(const QString& accountType, const LinkedList<Account>& allAccounts){


    QString shebaNumber;

    shebaNumber="IR12";

    if(accountType=="سپرده"){
        shebaNumber+="01";
    }
    else if(accountType=="جاری"){
        shebaNumber+="02";
    }
    else if(accountType=="قرض الحسنه"){
        shebaNumber+="03";
    }

    while(true){
        shebaNumber+=generateRandomDigits(14);

        if(isShebaNumberUnique(shebaNumber, allAccounts)){
            break;
        }
        else{
            shebaNumber.truncate(6);
            continue;
        }

    }

    return shebaNumber;

}
QString Account::createCvv2(const LinkedList<Account>& allAccounts){

    QString cvv2;

    while(true){

        cvv2=generateRandomDigits(4);

        if(isCvv2Unique(cvv2, allAccounts)){
            break;
        }
        else{
            cvv2.clear();
            continue;
        }
    }

    return cvv2;
}


QString Account::generateRandomDigits(size_t count){

    QString randomString="";

    for(size_t i=0; i<count; i++){

        char randomDigit = (rand()%10)+'0';
        randomString+=randomDigit;
    }
    return randomString;


}
bool Account::isCardNumberUnique(const QString& cardNumber, const LinkedList<Account>& allAccounts){


    for(size_t i=0; i<allAccounts.getListSize(); i++){

        if(allAccounts[i]->getCardNumber()==cardNumber){
            return false;
        }

    }

    return true;

}
bool Account::isAccountNumberUnique(const QString& accountNumber, const LinkedList<Account>& allAccounts){


    for(size_t i=0; i<allAccounts.getListSize(); i++){

        if(allAccounts[i]->getAccountNumber()==accountNumber){
            return false;
        }

    }

    return true;

}
bool Account::isShebaNumberUnique(const QString& shebaNumber, const LinkedList<Account>& allAccounts){


    for(size_t i=0; i<allAccounts.getListSize(); i++){

        if(allAccounts[i]->getShebaNumber()==shebaNumber){
            return false;
        }

    }

    return true;

}
bool Account::isCvv2Unique(const QString& cvv2, const LinkedList<Account>& allAccounts){

    for(size_t i=0; i<allAccounts.getListSize(); i++){

        if(allAccounts[i]->getCvv2()==cvv2){
            return false;
        }
    }

    return true;
}

std::shared_ptr<Account> Account::findAccountByAccountNumber(const QString& accountNumber, const LinkedList<Account>& allAccounts){

    for(size_t i=0; i<allAccounts.getListSize(); i++){

        if(allAccounts[i]->getAccountNumber()==accountNumber){

            return allAccounts[i];
        }
    }
    return nullptr;
}
std::shared_ptr<Account> Account::findAccountByCardNumber(const QString& cardNumber, const LinkedList<Account>& allAccounts){

    for(size_t i=0; i<allAccounts.getListSize(); i++){

        if(allAccounts[i]->getCardNumber()==cardNumber){

            return allAccounts[i];
        }
    }
    return nullptr;

}


void Account::setCardNumber(const QString& cardNumber){
    this->cardNumber=cardNumber;
}
void Account::setAccountNumber(const QString& accountNumber){
    this->accountNumber=accountNumber;
}
void Account::setShebaNumber(const QString& shebaNumber){
    this->shebaNumber=shebaNumber;
}
void Account::setCvv2(const QString& cvv2){
    this->cvv2=cvv2;
}
void Account::setBalance(double balance){
    this->balance=balance;
}
void Account::setExpirationDate(const QDate& expirationDate){
    this->expirationDate=expirationDate;
}
void Account::setPassword(const QString& password){
    this->password=password;
}
void Account::setStaticSecondPassword(const QString& staticSecondPass){
    this->staticSecondPassword=staticSecondPass;
}
void Account::setDynamicSecondPassword(const QString& dynamicSecondPass){
    this->dynamicSecondPassword=dynamicSecondPass;
}
void Account::addToDailyTransfer(double amount){
    this->dailyTransfer+=amount;
}
void Account::resetDailyTransfer(){
    this->dailyTransfer=0;
}
void Account::setLastTransferDate(QDate date){
    this->lastTransferDate=date;
}
void Account::clearDynamicSecondPassword(){
    dynamicSecondPassword.clear();
}
const std::shared_ptr<Costumer> Account::getOwner()const{
    return owner;
}
const QString Account::getOwnerName()const{
    QString fullName = owner->getFirstName()+ " "+owner->getLastName();
    return fullName;
}
const QString& Account::getCardNumber()const{
    return cardNumber;
}
const QString& Account::getAccountNumber()const{
    return accountNumber;
}
const QString& Account::getShebaNumber()const{
    return shebaNumber;
}
const QString& Account::getCvv2()const{
    return cvv2;
}
double Account::getBalance()const{
    return balance;
}
const QDate& Account::getExpirationDate()const{
    return expirationDate;
}
const QString& Account::getPassword()const{
    return password;
}
const QString& Account::getStaticSecondPassword()const{
    return staticSecondPassword;
}
const QString& Account::getDynamicSecondPassword()const{
    return dynamicSecondPassword;
}
double Account::getDailyTransfer()const{
    return dailyTransfer;
}
QDate Account::getLastTransferDate()const{
    return lastTransferDate;
}
