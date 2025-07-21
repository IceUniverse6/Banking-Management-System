#include "ViewAllAdminsPage.h"
#include "ui_ViewAllAdminsPage.h"

ViewAllAdminsPage::ViewAllAdminsPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewAllAdminsPage)
{
    ui->setupUi(this);
}

ViewAllAdminsPage::~ViewAllAdminsPage()
{
    delete ui;
}
