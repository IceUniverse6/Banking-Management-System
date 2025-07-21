#ifndef VIEWALLACCOUNTSPAGE_H
#define VIEWALLACCOUNTSPAGE_H

#include"Account.h"

#include <QDialog>

namespace Ui {
class ViewAllAccountsPage;
}

class ViewAllAccountsPage : public QDialog
{
    Q_OBJECT

public:
    explicit ViewAllAccountsPage(const LinkedList<Account>&, QWidget *parent = nullptr);
    ~ViewAllAccountsPage();

private slots:
    void on_searchButton_clicked();

    void on_returnButton_clicked();

private:
    Ui::ViewAllAccountsPage *ui;
    const LinkedList<Account>& allAccounts;
};

#endif // VIEWALLACCOUNTSPAGE_H
