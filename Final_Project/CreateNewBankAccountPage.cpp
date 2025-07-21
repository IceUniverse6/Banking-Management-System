#include "CreateNewBankAccountPage.h"
#include "ui_CreateNewBankAccountPage.h"

CreateNewBankAccountPage::CreateNewBankAccountPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateNewBankAccountPage)
{
    ui->setupUi(this);
}

CreateNewBankAccountPage::~CreateNewBankAccountPage()
{
    delete ui;
}
