#ifndef VIEWACCOUNTSFORBALANCE_H
#define VIEWACCOUNTSFORBALANCE_H

#include"Account.h"

#include <QDialog>

namespace Ui {
class ViewAccountsForBalance;
}

class ViewAccountsForBalance : public QDialog
{
    Q_OBJECT

public:
    explicit ViewAccountsForBalance(const LinkedList<Account>&, QWidget *parent = nullptr);
    ~ViewAccountsForBalance();

private slots:
    void on_okButton_clicked();

    void on_returnButton_clicked();

private:
    Ui::ViewAccountsForBalance *ui;

    const LinkedList<Account>& accounts;
};

#endif // VIEWACCOUNTSFORBALANCE_H
