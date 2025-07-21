#ifndef EDITADMININFOPAGE_H
#define EDITADMININFOPAGE_H

#include"User.h"

#include <QDialog>

namespace Ui {
class EditAdminInfoPage;
}

class EditAdminInfoPage : public QDialog
{
    Q_OBJECT

public:
    explicit EditAdminInfoPage(const LinkedList<User>&, std::shared_ptr<User>, QWidget *parent = nullptr);
    ~EditAdminInfoPage();

private slots:
    void on_editInfoButton_clicked();

private:
    Ui::EditAdminInfoPage *ui;
    std::shared_ptr<User> adminUser;
    const LinkedList<User>& allUsers;
};

#endif // EDITADMININFOPAGE_H
