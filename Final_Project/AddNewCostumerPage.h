#ifndef ADDNEWCOSTUMERPAGE_H
#define ADDNEWCOSTUMERPAGE_H

#include"User.h"

#include <QDialog>

namespace Ui {
class AddNewCostumerPage;
}

class AddNewCostumerPage : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewCostumerPage(LinkedList<User>&, QWidget *parent = nullptr);
    ~AddNewCostumerPage();

private slots:
    void on_createAccountButton_clicked();

private:
    Ui::AddNewCostumerPage *ui;
    LinkedList<User>& allUsers;
};

#endif // ADDNEWCOSTUMERPAGE_H
