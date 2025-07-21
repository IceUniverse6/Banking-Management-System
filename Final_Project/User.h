#ifndef USER_H
#define USER_H
#include"LinkedList.h"

#include<QString>

class Admin;
class Account;
class Costumer;


class User
{
private:
    QString firstName;
    QString lastName;
    QString nationalIdNumber;
    int age;
    QString userName;
    QString password;
public:
    User(const QString&, const QString&, const QString&, int, const QString&, const QString&);
    virtual ~User()=default;

    static std::shared_ptr<User> signIn(const QString&, const QString&, const LinkedList<User>&);
    static std::shared_ptr<User> signUp(const QString&, const QString&, const QString&, int , const QString&, const QString&, LinkedList<User>&, bool);

    static bool removeCostumer(const QString&, LinkedList<User>&);

    static bool isNationalIdUnique(const QString&, const LinkedList<User>&);
    static bool isUserNameUnique(const QString&, const LinkedList<User>&);


    static std::shared_ptr<User> findUserByUserName(const QString&, const LinkedList<User>&);

    void setFirstName(const QString&);
    void setLastName(const QString&);
    void setNationalId(const QString&);
    void setAge(int);
    void setUserName(const QString&);
    void setPassword(const QString&);


    const QString& getFirstName()const;
    const QString& getLastName()const;
    const QString& getNationalId()const;
    int getAge()const;
    const QString& getUserName()const;
    const QString& getPassword()const;
};

#endif // USER_H
