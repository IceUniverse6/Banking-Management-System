#ifndef TRANSFERMONEYPAGE_H
#define TRANSFERMONEYPAGE_H

#include"Account.h"

#include <QDialog>
#include<QDate>

namespace Ui {
class TransferMoneyPage;
}

class TransferMoneyPage : public QDialog
{
    Q_OBJECT

public:
    explicit TransferMoneyPage(const QString&, std::shared_ptr<Account>, std::shared_ptr<Account>, QWidget *parent = nullptr);
    ~TransferMoneyPage();


private slots:
    void on_returnButton_clicked();

    void on_generateDynamicSecondPassButton_clicked();

    void on_transferButton_clicked();

private:
    Ui::TransferMoneyPage *ui;
    std::shared_ptr<Account> fromAccount;
    std::shared_ptr<Account> toAccount;

};

#endif // TRANSFERMONEYPAGE_H
