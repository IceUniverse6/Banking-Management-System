#ifndef ADDNEWADMINPAGE_H
#define ADDNEWADMINPAGE_H

#include"User.h"

#include <QDialog>

namespace Ui {
class AddNewAdminPage;
}

class AddNewAdminPage : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewAdminPage(LinkedList<User>&, QWidget *parent = nullptr);
    ~AddNewAdminPage();

private slots:
    void on_createAccountButton_clicked();

private:
    Ui::AddNewAdminPage *ui;
    LinkedList<User>& allUsers;
};

#endif // ADDNEWADMINPAGE_H
