#include "RemoveCostumerAccountPage.h"
#include "ui_RemoveCostumerAccountPage.h"

RemoveCostumerAccountPage::RemoveCostumerAccountPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RemoveCostumerAccountPage)
{
    ui->setupUi(this);
}

RemoveCostumerAccountPage::~RemoveCostumerAccountPage()
{
    delete ui;
}
