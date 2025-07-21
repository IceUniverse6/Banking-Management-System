#ifndef CHANGEPASSWORDPAGE_H
#define CHANGEPASSWORDPAGE_H

#include"User.h"
#include"Account.h"

#include <QDialog>

namespace Ui {
class ChangePasswordPage;
}

class ChangePasswordPage : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePasswordPage(std::shared_ptr<User>, std::shared_ptr<Account>, int,  QWidget *parent = nullptr);
    ~ChangePasswordPage();

private slots:
    void on_okButton_clicked();

    void on_returnButton_clicked();

private:
    Ui::ChangePasswordPage *ui;
    int passType;
    std::shared_ptr<User> targetUser;
    std::shared_ptr<Account> targetAccount;
};

#endif // CHANGEPASSWORDPAGE_H
