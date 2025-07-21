#include "PersonalInfoPage.h"
#include "ui_PersonalInfoPage.h"

PersonalInfoPage::PersonalInfoPage(std::shared_ptr<User> user,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PersonalInfoPage)
{
    ui->setupUi(this);
    this->setWindowTitle("اطلاعات شخصی");

    ui->firstName->setText(user->getFirstName());
    ui->lastName->setText(user->getLastName());
    ui->userName->setText(user->getUserName());
    ui->nationalId->setText(user->getNationalId());
    ui->age->setText(QString::number(user->getAge()));
}

PersonalInfoPage::~PersonalInfoPage()
{
    delete ui;
}

void PersonalInfoPage::on_okButton_clicked()
{
    this->close();
    return;
}

