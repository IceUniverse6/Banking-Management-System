#ifndef DETAILEDACCOUNTINFOPAGE_H
#define DETAILEDACCOUNTINFOPAGE_H

#include"Account.h"

#include <QDialog>

namespace Ui {
class DetailedAccountInfoPage;
}

class DetailedAccountInfoPage : public QDialog
{
    Q_OBJECT

public:
    explicit DetailedAccountInfoPage(std::shared_ptr<Account>, QWidget *parent = nullptr);
    ~DetailedAccountInfoPage();

private slots:
    void on_okButton_clicked();

private:
    Ui::DetailedAccountInfoPage *ui;
};

#endif // DETAILEDACCOUNTINFOPAGE_H
