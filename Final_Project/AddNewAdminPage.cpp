#include "AddNewAdminPage.h"
#include "ui_AddNewAdminPage.h"

AddNewAdminPage::AddNewAdminPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddNewAdminPage)
{
    ui->setupUi(this);
}

AddNewAdminPage::~AddNewAdminPage()
{
    delete ui;
}
