#ifndef CHANGEPASSWORDPAGE_H
#define CHANGEPASSWORDPAGE_H

#include <QDialog>

namespace Ui {
class ChangePasswordPage;
}

class ChangePasswordPage : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePasswordPage(QWidget *parent = nullptr);
    ~ChangePasswordPage();

private:
    Ui::ChangePasswordPage *ui;
};

#endif // CHANGEPASSWORDPAGE_H
