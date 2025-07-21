QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Account.cpp \
    AddNewAdminPage.cpp \
    Admin.cpp \
    Costumer.cpp \
    CostumersInfoPage.cpp \
    CurrentAccount.cpp \
    DepositAccount.cpp \
    DetailedAccountInfoPage.cpp \
    InterestFreeAccount.cpp \
    PersonalInfoPage.cpp \
    User.cpp \
    ViewAllAccountsPage.cpp \
    ViewAllAdminsPage.cpp \
    ViewAllCostumersPage.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Account.h \
    AddNewAdminPage.h \
    Admin.h \
    Costumer.h \
    CostumersInfoPage.h \
    CurrentAccount.h \
    DepositAccount.h \
    DetailedAccountInfoPage.h \
    InterestFreeAccount.h \
    LinkedList.h \
    Node.h \
    PersonalInfoPage.h \
    User.h \
    ViewAllAccountsPage.h \
    ViewAllAdminsPage.h \
    ViewAllCostumersPage.h \
    mainwindow.h

FORMS += \
    AddNewAdminPage.ui \
    CostumersInfoPage.ui \
    DetailedAccountInfoPage.ui \
    PersonalInfoPage.ui \
    ViewAllAccountsPage.ui \
    ViewAllAdminsPage.ui \
    ViewAllCostumersPage.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
