#include "ChooseAccountPage.h"
#include "ui_ChooseAccountPage.h"

ChooseAccountPage::ChooseAccountPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChooseAccountPage)
{
    ui->setupUi(this);
}

ChooseAccountPage::~ChooseAccountPage()
{
    delete ui;
}
