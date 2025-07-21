#ifndef EDITADMININFOPAGE_H
#define EDITADMININFOPAGE_H

#include <QDialog>

namespace Ui {
class EditAdminInfoPage;
}

class EditAdminInfoPage : public QDialog
{
    Q_OBJECT

public:
    explicit EditAdminInfoPage(QWidget *parent = nullptr);
    ~EditAdminInfoPage();

private:
    Ui::EditAdminInfoPage *ui;
};

#endif // EDITADMININFOPAGE_H
