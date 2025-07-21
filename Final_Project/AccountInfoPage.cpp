#include "AccountInfoPage.h"
#include "ui_AccountInfoPage.h"

AccountInfoPage::AccountInfoPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AccountInfoPage)
{
    ui->setupUi(this);
}

AccountInfoPage::~AccountInfoPage()
{
    delete ui;
}
