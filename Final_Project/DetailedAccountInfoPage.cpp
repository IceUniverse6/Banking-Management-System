#include "DetailedAccountInfoPage.h"
#include "ui_DetailedAccountInfoPage.h"

DetailedAccountInfoPage::DetailedAccountInfoPage(std::shared_ptr<Account> targetAccount, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DetailedAccountInfoPage)
{
    ui->setupUi(this);
    this->setWindowTitle("اطلاعات حساب");

    ui->owner->setText(targetAccount->getOwnerName());
    ui->accountNumber->setText(targetAccount->getAccountNumber());
    ui->cardNumber->setText(targetAccount->getCardNumber());
    ui->shebaNumber->setText(targetAccount->getShebaNumber());
    ui->cvv2->setText(targetAccount->getCvv2());
    ui->expirationDate->setText(targetAccount->getExpirationDate().toString("MM/yy"));
    ui->balance->setText(QString::number(targetAccount->getBalance(), 'f', 3));
}

DetailedAccountInfoPage::~DetailedAccountInfoPage()
{
    delete ui;
}

void DetailedAccountInfoPage::on_okButton_clicked()
{
    this->close();
    return;
}

