#include "ViewAllAccountsPage.h"
#include "ui_ViewAllAccountsPage.h"

ViewAllAccountsPage::ViewAllAccountsPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewAllAccountsPage)
{
    ui->setupUi(this);
}

ViewAllAccountsPage::~ViewAllAccountsPage()
{
    delete ui;
}
