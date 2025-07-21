#include "ViewAllAdminsPage.h"
#include "ui_ViewAllAdminsPage.h"

#include"Admin.h"

ViewAllAdminsPage::ViewAllAdminsPage(const LinkedList<User>& allUsers, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewAllAdminsPage)
{
    ui->setupUi(this);
    this->setWindowTitle("مشاهده ادمین ها");


    for(size_t i=0; i<allUsers.getListSize(); i++){

        if(std::dynamic_pointer_cast<Admin>(allUsers[i])){

            QString userStr = QString("نام: %1 | کد ملی: %2").arg(allUsers[i]->getFirstName() + " " + allUsers[i]->getLastName()).arg(allUsers[i]->getNationalId());
            ui->adminsList->addItem(userStr);

        }

    }
}

ViewAllAdminsPage::~ViewAllAdminsPage()
{
    delete ui;
}

void ViewAllAdminsPage::on_okButton_clicked()
{
    this->close();
    return;
}

