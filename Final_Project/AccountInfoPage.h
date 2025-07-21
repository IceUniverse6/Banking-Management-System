#ifndef ACCOUNTINFOPAGE_H
#define ACCOUNTINFOPAGE_H

#include"Account.h"
#include <QDialog>

namespace Ui {
class AccountInfoPage;
}

class AccountInfoPage : public QDialog
{
    Q_OBJECT

public:
    explicit AccountInfoPage(const std::shared_ptr<Account>, QWidget *parent = nullptr);
    ~AccountInfoPage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AccountInfoPage *ui;
};

#endif // ACCOUNTINFOPAGE_H
