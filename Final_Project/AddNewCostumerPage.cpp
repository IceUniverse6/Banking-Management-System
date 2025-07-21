#include "AddNewCostumerPage.h"
#include "ui_AddNewCostumerPage.h"

#include<QMessageBox>

AddNewCostumerPage::AddNewCostumerPage(LinkedList<User>& allUsers, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddNewCostumerPage)
    ,allUsers(allUsers)
{
    ui->setupUi(this);
    this->setWindowTitle("افزودن مشتری جدید");
}

AddNewCostumerPage::~AddNewCostumerPage()
{
    delete ui;
}

void AddNewCostumerPage::on_createAccountButton_clicked()
{
    QString firstName = ui->firstNameField->text();
    QString lastName = ui->lastNameField->text();
    QString nationalId = ui->nationalIdField->text();
    QString age = ui->ageField->text();
    QString userName = ui->userNameField->text();
    QString password = ui->passwordField->text();


    if((firstName.isEmpty())||(lastName.isEmpty())||(nationalId.isEmpty())||(age.isEmpty())||(userName.isEmpty())||(password.isEmpty())){

        std::shared_ptr<QMessageBox> emptyField = std::make_shared<QMessageBox>();
        emptyField->setText("تمامی فیلدهای خواسته شده باید پر شوند!");
        emptyField->setWindowTitle("نقص اطلاعات");
        emptyField->setIcon(QMessageBox::Critical);
        emptyField->exec();
        return;

    }
    else{


        if(!User::isNationalIdUnique(nationalId, allUsers)){
            std::shared_ptr<QMessageBox> notUnique = std::make_shared<QMessageBox>();
            notUnique->setText("کد ملی در حال حاضر در سامانه ثبت شده!");
            notUnique->setWindowTitle("عدم یکتایی");
            notUnique->setIcon(QMessageBox::Critical);
            notUnique->exec();
            return;
        }
        if(!User::isUserNameUnique(userName, allUsers)){
            std::shared_ptr<QMessageBox> notUnique = std::make_shared<QMessageBox>();
            notUnique->setText("نام کاربری در حال حاضر در سامانه ثبت شده!");
            notUnique->setWindowTitle("عدم یکتایی");
            notUnique->setIcon(QMessageBox::Critical);
            notUnique->exec();
            return;
        }

        if(age.toInt()<18){

            std::shared_ptr<QMessageBox> ageLimit = std::make_shared<QMessageBox>();
            ageLimit->setText("حداقل سن برای ساخت حساب 18 سال می باشد!");
            ageLimit->setWindowTitle("محدودیت سن");
            ageLimit->setIcon(QMessageBox::Critical);
            ageLimit->exec();
            return;

        }

        if(User::signUp(firstName, lastName, nationalId, age.toInt(), userName, password, this->allUsers, false)){
            std::shared_ptr<QMessageBox> addedaccount = std::make_shared<QMessageBox>();
            addedaccount->setText("مشتری جدید با موفقیت به سیستم اضافه شد");
            addedaccount->setWindowTitle("افزوده شدن کاربر جدید");
            addedaccount->setIcon(QMessageBox::Information);
            this->close();
            addedaccount->exec();
            return;
        }
    }
}

