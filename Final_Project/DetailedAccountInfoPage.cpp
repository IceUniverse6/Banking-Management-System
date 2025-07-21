#include "DetailedAccountInfoPage.h"
#include "ui_DetailedAccountInfoPage.h"

DetailedAccountInfoPage::DetailedAccountInfoPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DetailedAccountInfoPage)
{
    ui->setupUi(this);
}

DetailedAccountInfoPage::~DetailedAccountInfoPage()
{
    delete ui;
}
