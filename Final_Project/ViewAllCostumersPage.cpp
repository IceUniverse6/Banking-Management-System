#include "ViewAllCostumersPage.h"
#include "ui_ViewAllCostumersPage.h"

ViewAllCostumersPage::ViewAllCostumersPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewAllCostumersPage)
{
    ui->setupUi(this);
}

ViewAllCostumersPage::~ViewAllCostumersPage()
{
    delete ui;
}
