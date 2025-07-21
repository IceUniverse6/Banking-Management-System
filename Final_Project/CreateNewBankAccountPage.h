#ifndef CREATENEWBANKACCOUNTPAGE_H
#define CREATENEWBANKACCOUNTPAGE_H

#include"User.h"
#include"Account.h"

#include <QDialog>

namespace Ui {
class CreateNewBankAccountPage;
}

class CreateNewBankAccountPage : public QDialog
{
    Q_OBJECT

public:
    explicit CreateNewBankAccountPage(const LinkedList<User>&, LinkedList<Account>&, QWidget *parent = nullptr);
    ~CreateNewBankAccountPage();

private slots:
    void on_createAccountButton_clicked();

private:
    Ui::CreateNewBankAccountPage *ui;
    const LinkedList<User>& allUsers;
    LinkedList<Account>& allAccounts;
};

#endif // CREATENEWBANKACCOUNTPAGE_H
