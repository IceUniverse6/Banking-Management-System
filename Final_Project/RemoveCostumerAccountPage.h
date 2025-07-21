#ifndef REMOVECOSTUMERACCOUNTPAGE_H
#define REMOVECOSTUMERACCOUNTPAGE_H

#include"User.h"
#include"Account.h"

#include <QDialog>

namespace Ui {
class RemoveCostumerAccountPage;
}

class RemoveCostumerAccountPage : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveCostumerAccountPage(LinkedList<User>&, LinkedList<Account>&, QWidget *parent = nullptr);
    ~RemoveCostumerAccountPage();

private slots:
    void on_removeCostumerButton_clicked();

private:
    Ui::RemoveCostumerAccountPage *ui;
    LinkedList<User>& allUsers;
    LinkedList<Account>& allAccounts;
};

#endif // REMOVECOSTUMERACCOUNTPAGE_H
