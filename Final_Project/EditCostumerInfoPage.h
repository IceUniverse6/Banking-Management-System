#ifndef EDITCOSTUMERINFOPAGE_H
#define EDITCOSTUMERINFOPAGE_H

#include"User.h"
#include <QDialog>

namespace Ui {
class EditCostumerInfoPage;
}

class EditCostumerInfoPage : public QDialog
{
    Q_OBJECT

public:
    explicit EditCostumerInfoPage(std::shared_ptr<User>, const LinkedList<User>&, QWidget *parent = nullptr);
    ~EditCostumerInfoPage();

private slots:
    void on_editInfoButton_clicked();

private:
    Ui::EditCostumerInfoPage *ui;
    std::shared_ptr<User> targetUser;
    const LinkedList<User>& allUsers;
};

#endif // EDITCOSTUMERINFOPAGE_H
