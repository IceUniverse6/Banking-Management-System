#include "EditAdminInfoPage.h"
#include "ui_EditAdminInfoPage.h"


#include<QMessageBox>

EditAdminInfoPage::EditAdminInfoPage(const LinkedList<User>& allUsers, std::shared_ptr<User> adminUser,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditAdminInfoPage)
    ,adminUser(adminUser)
    ,allUsers(allUsers)
{
    ui->setupUi(this);
    this->setWindowTitle("ویرایش اطلاعات");
}

EditAdminInfoPage::~EditAdminInfoPage()
{
    delete ui;
}

void EditAdminInfoPage::on_editInfoButton_clicked()
{
    QString firstName = ui->firstNameField->text();
    QString lastName = ui->lastNameField->text();
    QString nationalId = ui->nationalIdField->text();
    QString age = ui->ageField->text();
    QString userName = ui->userNameField->text();
    QString password = ui->passwordField->text();

    if(!nationalId.isEmpty()){

        if(nationalId.length()!=10){
            std::shared_ptr<QMessageBox> lengthError = std::make_shared<QMessageBox>();
            lengthError->setText("کد ملی باید 10 رقم باشد!");
            lengthError->setWindowTitle("ورودی نامعتبر");
            lengthError->setIcon(QMessageBox::Critical);
            lengthError->exec();
            return;
        }

        if(nationalId==adminUser->getNationalId()){
            std::shared_ptr<QMessageBox> notChanged = std::make_shared<QMessageBox>();
            notChanged->setText("کد ملی جدید باید با کد ملی ثبت شده متفاوت باشد!");
            notChanged->setWindowTitle("یکسان بودن کدملی ها");
            notChanged->setIcon(QMessageBox::Critical);
            notChanged->exec();
            return;
        }

        if(!User::isNationalIdUnique(nationalId, allUsers)){
            std::shared_ptr<QMessageBox> notUnique = std::make_shared<QMessageBox>();
            notUnique->setText("کد ملی در حال حاضر در سامانه ثبت شده!");
            notUnique->setWindowTitle("عدم یکتایی");
            notUnique->setIcon(QMessageBox::Critical);
            notUnique->exec();
            return;
        }
    }

    if(!userName.isEmpty()){

        if(userName==adminUser->getUserName()){
            std::shared_ptr<QMessageBox> notChanged = std::make_shared<QMessageBox>();
            notChanged->setText("نام کاربری جدید با نام کاربری ثبت شده باید متفاوت باشد!");
            notChanged->setWindowTitle("یکسان بودن نام کاربری ها");
            notChanged->setIcon(QMessageBox::Critical);
            notChanged->exec();
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
    }

    if(!age.isEmpty()){

        if(age.toInt()<18){
            std::shared_ptr<QMessageBox> ageLimit = std::make_shared<QMessageBox>();
            ageLimit->setText("حداقل سن برای ساخت حساب 18 سال می باشد!");
            ageLimit->setWindowTitle("محدودیت سن");
            ageLimit->setIcon(QMessageBox::Critical);
            ageLimit->exec();
            return;
        }
    }

    if(!password.isEmpty()){

        if(password==adminUser->getPassword()){

            std::shared_ptr<QMessageBox> notChanged = std::make_shared<QMessageBox>();
            notChanged->setText("رمز جدید با رمز قبلی باید متفاوت باشد!");
            notChanged->setWindowTitle("یکسان بودن  رمزها");
            notChanged->setIcon(QMessageBox::Critical);
            notChanged->exec();
            return;
        }
    }

    if(!firstName.isEmpty()){
        adminUser->setFirstName(firstName);
    }
    if(!lastName.isEmpty()){
        adminUser->setLastName(lastName);
    }
    if(!nationalId.isEmpty()){
        adminUser->setNationalId(nationalId);
    }
    if(!age.isEmpty()){
        adminUser->setAge(age.toInt());
    }
    if(!userName.isEmpty()){
        adminUser->setUserName(userName);
    }
    if(!password.isEmpty()){
        adminUser->setPassword(password);
    }


    std::shared_ptr<QMessageBox> success = std::make_shared<QMessageBox>();
    success->setText("اطلاعات با موفقیت ویرایش شدند!");
    success->setWindowTitle("ویرایش موفق");
    success->setIcon(QMessageBox::Information);
    this->close();
    success->exec();
    return;
}

