#ifndef ACCOUNTINFOPAGE_H
#define ACCOUNTINFOPAGE_H

#include <QDialog>

namespace Ui {
class AccountInfoPage;
}

class AccountInfoPage : public QDialog
{
    Q_OBJECT

public:
    explicit AccountInfoPage(QWidget *parent = nullptr);
    ~AccountInfoPage();

private:
    Ui::AccountInfoPage *ui;
};

#endif // ACCOUNTINFOPAGE_H
