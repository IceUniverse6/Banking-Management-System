#include<ctime>
#include "mainwindow.h"

#include"LinkedList.h"
#include"User.h"
#include"Account.h"

#include"Admin.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    srand(time(0));

    QApplication a(argc, argv);


    LinkedList<User> allUsers;
    LinkedList<Account> allAccounts;
    std::shared_ptr<Admin> firstAdmin = std::make_shared<Admin>("علی", "عزیزی", "1234567890", 20, "admin1", "1234");

    allUsers.listPushBack(firstAdmin);


    MainWindow w(allUsers, allAccounts);
    w.show();
    return a.exec();
}
