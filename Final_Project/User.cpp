#include "User.h"
#include"Admin.h"
#include"Costumer.h"
#include"Account.h"
#include"LinkedList.h"

User::User(const QString& firstName
           , const QString& lastName
           , const QString& nationalIdNumber
           , int age
           , const QString& userName
           , const QString& password)
    :firstName(firstName), lastName(lastName), nationalIdNumber(nationalIdNumber), age(age), userName(userName), password(password)
{}


void User::setFirstName(const QString& firstName){
    this->firstName=firstName;
}
void User::setLastName(const QString& lastName){
    this->lastName=lastName;
}
void User::setNationalId(const QString& nationalId){
    this->nationalIdNumber=nationalId;
}
void User::setAge(int age){
    this->age=age;
}
void User::setUserName(const QString& userName){
    this->userName=userName;
}
void User::setPassword(const QString& password){
    this->password=password;
}

const QString& User::getFirstName()const{
    return firstName;
}
const QString& User::getLastName()const{
    return lastName;
}
const QString& User::getNationalId()const{
    return nationalIdNumber;
}
int User::getAge()const{
    return age;
}
const QString& User::getUserName()const{
    return userName;
}
const QString& User::getPassword()const{
    return password;
}

std::shared_ptr<User> User::signIn(const QString& inputUserName, const QString& inputPassword, const LinkedList<User>& allUsers){

    for(size_t i=0; i<allUsers.getListSize(); i++){

        if((allUsers[i]->getUserName()==inputUserName)&&(allUsers[i]->getPassword()==inputPassword)){
            return allUsers[i];
        }
    }

    return nullptr;

}
std::shared_ptr<User> User::signUp(const QString& firstName
                                   , const QString& lastName
                                   , const QString& nationalId
                                   , int age
                                   , const QString& userName
                                   , const QString& password
                                   , LinkedList<User>& allUsers
                                   , bool isAdmin)
{

    for(size_t i=0; i<allUsers.getListSize(); i++){
        if((allUsers[i]->getNationalId()==nationalId)||(allUsers[i]->getUserName()==userName)){
            return nullptr;
        }
    }

    if(isAdmin){

        std::shared_ptr<Admin> newAdmin = std::make_shared<Admin>(firstName, lastName, nationalId, age, userName, password);
        allUsers.listPushBack(newAdmin);
        return newAdmin;

    }
    else{
        std::shared_ptr<Costumer> newCostumer = std::make_shared<Costumer>(firstName, lastName, nationalId, age, userName, password);
        allUsers.listPushBack(newCostumer);
        return newCostumer;
    }



    return nullptr;
}


bool User::removeCostumer(const QString& userName, LinkedList<User>& allUsers){

    std::shared_ptr<Node<User>> previousUser=nullptr;
    std::shared_ptr<Node<User>> currentUser=allUsers.getListHead();

    while (currentUser != nullptr) {
        if (currentUser->getData()->getUserName() == userName) {
            if (previousUser == nullptr) {
                allUsers.setListHead(currentUser->getNext());
                if (allUsers.getListTail() == currentUser) {
                    allUsers.setListTail(nullptr);
                }
            } else {
                previousUser->setNext(currentUser->getNext());
                if (allUsers.getListTail() == currentUser) {
                    allUsers.setListTail(previousUser);
                }
            }

            allUsers.setListSize(allUsers.getListSize() - 1);
            return true;
        }

        previousUser = currentUser;
        currentUser = currentUser->getNext();
    }

    return false;
}

bool User::isNationalIdUnique(const QString& nationalId, const LinkedList<User>& allUsers){

    for(size_t i=0; i<allUsers.getListSize(); i++){

        if(allUsers[i]->getNationalId()==nationalId){
            return false;
        }

    }

    return true;

}
bool User::isUserNameUnique(const QString& userName, const LinkedList<User>& allUsers){

    for(size_t i=0; i<allUsers.getListSize(); i++){

        if(allUsers[i]->getUserName()==userName){
            return false;
        }

    }

    return true;

}


std::shared_ptr<User> User::findUserByUserName(const QString& userName, const LinkedList<User>& allUsers){

    for(size_t i=0; i<allUsers.getListSize(); i++){

        if(allUsers[i]->getUserName()==userName){
            return allUsers[i];
        }
    }
    return nullptr;

}
