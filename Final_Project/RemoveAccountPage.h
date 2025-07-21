#ifndef REMOVEACCOUNTPAGE_H
#define REMOVEACCOUNTPAGE_H
#include"Account.h"

#include <QDialog>

namespace Ui {
class RemoveAccountPage;
}

class RemoveAccountPage : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveAccountPage(LinkedList<Account>&, QWidget *parent = nullptr);
    ~RemoveAccountPage();

private slots:
    void on_removeAccountButton_clicked();

private:
    Ui::RemoveAccountPage *ui;
    LinkedList<Account>& allAccounts;
};

#endif // REMOVEACCOUNTPAGE_H
