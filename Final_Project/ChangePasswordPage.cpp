#include "ChangePasswordPage.h"
#include "ui_ChangePasswordPage.h"

ChangePasswordPage::ChangePasswordPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChangePasswordPage)
{
    ui->setupUi(this);
}

ChangePasswordPage::~ChangePasswordPage()
{
    delete ui;
}
