#include "AccountInfoPage.h"
#include "ui_AccountInfoPage.h"

AccountInfoPage::AccountInfoPage(const std::shared_ptr<Account> account, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AccountInfoPage)
{
    ui->setupUi(this);

    this->setWindowTitle("اطلاعات حساب");

    ui->accountType->setText(account->getAccountType());
    ui->shebaNumber->setText(account->getShebaNumber());
    ui->cardNumber->setText(account->getCardNumber());
    ui->owner->setText(account->getOwnerName());
    ui->expirationDate->setText(account->getExpirationDate().toString("MM/yy"));
    ui->cvv2->setText(account->getCvv2());
}

AccountInfoPage::~AccountInfoPage()
{
    delete ui;
}

void AccountInfoPage::on_pushButton_clicked()
{
    this->close();
    return;
}

