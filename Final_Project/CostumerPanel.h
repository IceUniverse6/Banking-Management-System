#ifndef COSTUMERPANEL_H
#define COSTUMERPANEL_H

#include"Costumer.h"

#include <QMainWindow>

namespace Ui {
class CostumerPanel;
}

class CostumerPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit CostumerPanel(std::shared_ptr<Costumer>, LinkedList<User>&, LinkedList<Account>&, QWidget *parent = nullptr);
    ~CostumerPanel();

private slots:
    void on_viewPersonalInfoButton_clicked();

    void on_viewAccountsButton_clicked();

    void on_signOutButton_clicked();

    void on_changeAccountPassButton_clicked();

    void on_changefirstPassButton_clicked();

    void on_changeStaticSecondPassButton_clicked();

    void on_getBalanceButton_clicked();

    void on_transferMoneyButton_clicked();

private:
    Ui::CostumerPanel *ui;

    std::shared_ptr<Costumer> costumerUser;
    LinkedList<User>& allUsers;
    LinkedList<Account>& allAccounts;
};

#endif // COSTUMERPANEL_H
