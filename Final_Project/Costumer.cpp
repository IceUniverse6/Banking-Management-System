#include "Costumer.h"
#include"Account.h"

Costumer::Costumer(const QString& firstName
                   , const QString& lastName
                   , const QString& nationalIdNumber
                   , int age
                   , const QString& userName
                   , const QString& password)
    :User(firstName, lastName, nationalIdNumber, age, userName, password)
{}

void Costumer::addAccount(std::shared_ptr<Account> newAccount){

    accounts.listPushBack(newAccount);

}
bool Costumer::removeAccount(const QString& accountNumber){

    std::shared_ptr<Node<Account>> previousAccount=nullptr;
    std::shared_ptr<Node<Account>> currentAccount=accounts.getListHead();

    while (currentAccount != nullptr) {
        if (currentAccount->getData()->getAccountNumber() == accountNumber) {
            if (previousAccount == nullptr) {
                accounts.setListHead(currentAccount->getNext());
                if (accounts.getListTail() == currentAccount) {
                    accounts.setListTail(nullptr);
                }
            } else {
                previousAccount->setNext(currentAccount->getNext());
                if (accounts.getListTail() == currentAccount) {
                    accounts.setListTail(previousAccount);
                }
            }

            accounts.setListSize(accounts.getListSize() - 1);
            return true;
        }

        previousAccount = currentAccount;
        currentAccount = currentAccount->getNext();
    }

    return false;


}

bool Costumer::removeAccounts(){

    accounts.clearList();
    return true;
}

size_t Costumer::getNumberOfAccounts()const{

    return accounts.getListSize();

}

const LinkedList<Account>& Costumer::getAccounts()const{
    return accounts;
}
