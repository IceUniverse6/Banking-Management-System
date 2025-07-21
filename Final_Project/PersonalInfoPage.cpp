#include "PersonalInfoPage.h"
#include "ui_PersonalInfoPage.h"

PersonalInfoPage::PersonalInfoPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PersonalInfoPage)
{
    ui->setupUi(this);
}

PersonalInfoPage::~PersonalInfoPage()
{
    delete ui;
}
