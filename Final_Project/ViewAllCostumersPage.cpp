#include "ViewAllCostumersPage.h"
#include "ui_ViewAllCostumersPage.h"

#include"CostumersInfoPage.h"

#include"Costumer.h"

#include<QMessageBox>

ViewAllCostumersPage::ViewAllCostumersPage(const LinkedList<User>& allUsers, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewAllCostumersPage)
    ,allUsers(allUsers)
{
    ui->setupUi(this);
    this->setWindowTitle("لیست مشتری ها");

    QObject::connect(ui->userNameList, &QListWidget::itemClicked, this, [=](QListWidgetItem* item){
        if(!ui->userNameField->text().isEmpty()){
            ui->userNameField->clear();
        }
        ui->userNameField->setText(item->text());
    });


    for(size_t i=0; i<allUsers.getListSize(); i++){

        if(std::dynamic_pointer_cast<Costumer>(allUsers[i])){
            ui->costumersList->addItem(allUsers[i]->getFirstName()+" "+allUsers[i]->getLastName());
            ui->userNameList->addItem(allUsers[i]->getUserName());
        }
    }
}

ViewAllCostumersPage::~ViewAllCostumersPage()
{
    delete ui;
}

void ViewAllCostumersPage::on_searchButton_clicked()
{
    QString userName = ui->userNameField->text();

    if(userName.isEmpty()){
        std::shared_ptr<QMessageBox> emptyField = std::make_shared<QMessageBox>();
        emptyField->setText("نام کاربری وارد نشده!");
        emptyField->setWindowTitle("نقص اطلاعات");
        emptyField->setIcon(QMessageBox::Critical);
        emptyField->exec();
        return;
    }

    std::shared_ptr<User> foundUser = User::findUserByUserName(userName,allUsers);

    if(!foundUser){

        std::shared_ptr<QMessageBox> notFound = std::make_shared<QMessageBox>();
        notFound->setText("مشتری در سیستم یافت نشد!");
        notFound->setWindowTitle("مشتری یافت نشد");
        notFound->setIcon(QMessageBox::Critical);
        notFound->exec();
        return;

    }


    if(std::dynamic_pointer_cast<Costumer>(foundUser)){
        std::shared_ptr<CostumersInfoPage> costumersInfoPage = std::make_shared<CostumersInfoPage>(std::dynamic_pointer_cast<Costumer>(foundUser));
        costumersInfoPage->exec();
        return;
    }
    else{
        std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
        error->setText("در یافتن کاربر مشکلی پیش آمد!");
        error->setWindowTitle("مشکلی رخ داد");
        error->setIcon(QMessageBox::Critical);
        error->exec();
        return;
    }
}

void ViewAllCostumersPage::on_returnButton_clicked()
{
    this->close();
    return;
}

