#include "EditAdminInfoPage.h"
#include "ui_EditAdminInfoPage.h"

EditAdminInfoPage::EditAdminInfoPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditAdminInfoPage)
{
    ui->setupUi(this);
}

EditAdminInfoPage::~EditAdminInfoPage()
{
    delete ui;
}
