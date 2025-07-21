#include "EditCostumerInfoPage.h"
#include "ui_EditCostumerInfoPage.h"

#include<QMessageBox>

EditCostumerInfoPage::EditCostumerInfoPage(std::shared_ptr<User> targetUser, const LinkedList<User>& allUsers, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditCostumerInfoPage)
    ,allUsers(allUsers)
{
    ui->setupUi(this);
    this->targetUser=targetUser;
    this->setWindowTitle("ویرایش اطلاعات");

}

EditCostumerInfoPage::~EditCostumerInfoPage()
{
    delete ui;
}

void EditCostumerInfoPage::on_editInfoButton_clicked()
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

        if(nationalId==targetUser->getNationalId()){
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

        if(userName==targetUser->getUserName()){
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

        if(password==targetUser->getPassword()){

            std::shared_ptr<QMessageBox> notChanged = std::make_shared<QMessageBox>();
            notChanged->setText("رمز جدید با رمز قبلی باید متفاوت باشد!");
            notChanged->setWindowTitle("یکسان بودن  رمزها");
            notChanged->setIcon(QMessageBox::Critical);
            notChanged->exec();
            return;
        }
    }

    if(!firstName.isEmpty()){
        targetUser->setFirstName(firstName);
    }
    if(!lastName.isEmpty()){
        targetUser->setLastName(lastName);
    }
    if(!nationalId.isEmpty()){
        targetUser->setNationalId(nationalId);
    }
    if(!age.isEmpty()){
        targetUser->setAge(age.toInt());
    }
    if(!userName.isEmpty()){
        targetUser->setUserName(userName);
    }
    if(!password.isEmpty()){
        targetUser->setPassword(password);
    }


    std::shared_ptr<QMessageBox> success = std::make_shared<QMessageBox>();
    success->setText("اطلاعات با موفقیت ویرایش شدند!");
    success->setWindowTitle("ویرایش موفق");
    success->setIcon(QMessageBox::Information);
    this->close();
    success->exec();
    return;

}

