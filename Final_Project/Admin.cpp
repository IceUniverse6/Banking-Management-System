#include "Admin.h"

Admin::Admin(const QString& firstName
             , const QString& lastName
             , const QString& nationalIdNumber
             , int age
             , const QString& userName
             , const QString& password)
    :User(firstName, lastName, nationalIdNumber, age, userName, password)
{}
