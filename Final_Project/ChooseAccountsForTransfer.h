#ifndef CHOOSEACCOUNTSFORTRANSFERPAGE_H
#define CHOOSEACCOUNTSFORTRANSFERPAGE_H

#include"Account.h"
#include <QDialog>

namespace Ui {
class ChooseAccountsForTransfer;
}

class ChooseAccountsForTransfer : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseAccountsForTransfer(const LinkedList<Account>&, const LinkedList<Account>&, QWidget *parent = nullptr);
    ~ChooseAccountsForTransfer();

private slots:
    void on_okButton_clicked();

    void on_returnButton_clicked();

private:
    Ui::ChooseAccountsForTransfer *ui;

    const LinkedList<Account>& costumerAccounts;
    const LinkedList<Account>& allAccounts;
};


#endif // CHOOSEACCOUNTSFORTRANSFERPAGE_H
