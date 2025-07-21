QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Account.cpp \
    AccountInfoPage.cpp \
    AddNewAdminPage.cpp \
    AddNewCostumerPage.cpp \
    Admin.cpp \
    ChangePasswordPage.cpp \
    ChooseAccountPage.cpp \
    Costumer.cpp \
    CostumersInfoPage.cpp \
    CreateNewBankAccountPage.cpp \
    CurrentAccount.cpp \
    DepositAccount.cpp \
    DetailedAccountInfoPage.cpp \
    EditAdminInfoPage.cpp \
    EditCostumerInfoPage.cpp \
    FindCostumerPage.cpp \
    InterestFreeAccount.cpp \
    PersonalInfoPage.cpp \
    RemoveAccountPage.cpp \
    RemoveCostumerAccountPage.cpp \
    User.cpp \
    ViewAllAccountsPage.cpp \
    ViewAllAdminsPage.cpp \
    ViewAllCostumersPage.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Account.h \
    AccountInfoPage.h \
    AddNewAdminPage.h \
    AddNewCostumerPage.h \
    Admin.h \
    ChangePasswordPage.h \
    ChooseAccountPage.h \
    Costumer.h \
    CostumersInfoPage.h \
    CreateNewBankAccountPage.h \
    CurrentAccount.h \
    DepositAccount.h \
    DetailedAccountInfoPage.h \
    EditAdminInfoPage.h \
    EditCostumerInfoPage.h \
    FindCostumerPage.h \
    InterestFreeAccount.h \
    LinkedList.h \
    Node.h \
    PersonalInfoPage.h \
    RemoveAccountPage.h \
    RemoveCostumerAccountPage.h \
    User.h \
    ViewAllAccountsPage.h \
    ViewAllAdminsPage.h \
    ViewAllCostumersPage.h \
    mainwindow.h

FORMS += \
    AccountInfoPage.ui \
    AddNewAdminPage.ui \
    AddNewCostumerPage.ui \
    ChangePasswordPage.ui \
    ChooseAccountPage.ui \
    CostumersInfoPage.ui \
    CreateNewBankAccountPage.ui \
    DetailedAccountInfoPage.ui \
    EditAdminInfoPage.ui \
    EditCostumerInfoPage.ui \
    FindCostumerPage.ui \
    PersonalInfoPage.ui \
    RemoveAccountPage.ui \
    RemoveCostumerAccountPage.ui \
    ViewAllAccountsPage.ui \
    ViewAllAdminsPage.ui \
    ViewAllCostumersPage.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
