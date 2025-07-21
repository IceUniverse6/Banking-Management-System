#include "ViewAccountsForBalance.h"
#include "ui_ViewAccountsForBalance.h"

ViewAccountsForBalance::ViewAccountsForBalance(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewAccountsForBalance)
{
    ui->setupUi(this);
}

ViewAccountsForBalance::~ViewAccountsForBalance()
{
    delete ui;
}
