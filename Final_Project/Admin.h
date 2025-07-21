#ifndef ADMIN_H
#define ADMIN_H
#include"User.h"

class Admin: public User
{
public:
    Admin(const QString&, const QString&, const QString&, int, const QString&, const QString&);
};

#endif // ADMIN_H
