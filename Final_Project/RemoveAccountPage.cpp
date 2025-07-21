#include "RemoveAccountPage.h"
#include "ui_RemoveAccountPage.h"

RemoveAccountPage::RemoveAccountPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RemoveAccountPage)
{
    ui->setupUi(this);
}

RemoveAccountPage::~RemoveAccountPage()
{
    delete ui;
}
