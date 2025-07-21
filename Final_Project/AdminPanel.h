#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include"Admin.h"
#include"Account.h"

#include <QMainWindow>

namespace Ui {
class AdminPanel;
}

class AdminPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminPanel(std::shared_ptr<Admin>, LinkedList<User>&, LinkedList<Account>&, QWidget *parent = nullptr);
    ~AdminPanel();


private slots:
    void on_viewPersonalInfoButton_clicked();

    void on_viewAllCostumersButton_clicked();

    void on_viewAllAdminsButton_clicked();

    void on_viewAllAccountsButton_clicked();

    void on_signOutButton_clicked();

    void on_addNewAdminButton_clicked();

    void on_addNewCostumerButton_clicked();

    void on_addNewBankAccountButton_clicked();

    void on_removeCostumerButton_clicked();

    void on_removeBankAccountButton_clicked();

    void on_editPersonalInfoButton_clicked();

    void on_editCostumersInfoButton_clicked();

private:
    Ui::AdminPanel *ui;

    std::shared_ptr<Admin> adminUser;

    LinkedList<User>& allUsers;
    LinkedList<Account>& allAccounts;
};

#endif // ADMINPANEL_H
