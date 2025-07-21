#include"Admin.h"
#include"Costumer.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QMessageBox>

MainWindow::MainWindow(LinkedList<User>& allUsers, LinkedList<Account>& allAccounts, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,allUsers(allUsers)
    ,allAccounts(allAccounts)
{
    ui->setupUi(this);
    this->setWindowTitle("سیستم مدیریت بانکی");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_enterButton_clicked()
{
    QString userName=ui->userNameField->text();
    QString password=ui->passwordField->text();


    if((userName.isEmpty())||(password.isEmpty())){
        std::shared_ptr<QMessageBox> warning = std::make_shared<QMessageBox>();
        warning->setWindowTitle("اطلاعات");
        warning->setIcon(QMessageBox::Critical);
        warning->setText("فیلدهای مربوطه باید پر باشند!");
        warning->exec();
        return;
    }

    else{
        std::shared_ptr<User> targetUser = User::signIn(userName, password, this->allUsers);


        if(adminPanel){
            adminPanel->close();
            adminPanel.reset();
        }
        if(costumerPanel){
            costumerPanel->close();
            costumerPanel.reset();
        }

        if(targetUser){

            std::shared_ptr<Admin> adminUser = std::dynamic_pointer_cast<Admin>(targetUser);
            std::shared_ptr<Costumer> costumerUser = std::dynamic_pointer_cast<Costumer>(targetUser);

            if(adminUser){

                adminPanel = std::make_shared<AdminPanel>(adminUser, this->allUsers, this->allAccounts);
                adminPanel->show();
                return;
            }
            if(costumerUser){
                costumerPanel=std::make_shared<CostumerPanel>(costumerUser, this->allUsers, this->allAccounts);
                costumerPanel->show();
                return;
            }
        }
        else{
            std::shared_ptr<QMessageBox> notFound = std::make_shared<QMessageBox>();
            notFound->setWindowTitle("کاربر یافت نشد");
            notFound->setIcon(QMessageBox::Critical);
            notFound->setText("کاربر با این مشخصات در سیستم وجود ندارد!");
            notFound->exec();
        }
    }
}

