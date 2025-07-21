#include "ChangePasswordPage.h"
#include "ui_ChangePasswordPage.h"

#include<QMessageBox>

ChangePasswordPage::ChangePasswordPage(std::shared_ptr<User> targetUser, std::shared_ptr<Account> targetAccount, int passType,  QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChangePasswordPage)
{
    ui->setupUi(this);
    this->passType=passType;
    this->targetUser=targetUser;
    this->targetAccount=targetAccount;
    this->setWindowTitle("تغییر رمز");

    if(passType==1){
        ui->passwordType->setText("حساب کاربری");
    }
    else if(passType==2){
        ui->passwordType->setText("رمز اول حساب");
    }
    else if(passType==3){
        ui->passwordType->setText("رمز دوم ثابت");
    }
}

ChangePasswordPage::~ChangePasswordPage()
{
    delete ui;
}

void ChangePasswordPage::on_okButton_clicked()
{
    QString currentPassword = ui->currentPasswordField->text();
    QString newPassword = ui->newPasswordField->text();
    QString confirmNewPassword = ui->confirmNewPasswordField->text();

    if((currentPassword.isEmpty())||(newPassword.isEmpty())||(confirmNewPassword.isEmpty())){

        std::shared_ptr<QMessageBox> emptyField = std::make_shared<QMessageBox>();
        emptyField->setText("تمامی فیلدها باید پر شوند!");
        emptyField->setWindowTitle("نقص اطلاعات");
        emptyField->setIcon(QMessageBox::Critical);
        emptyField->exec();
        return;
    }

    if(passType==1){

        if(currentPassword!=targetUser->getPassword()){
            std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
            error->setText("رمز فعلی اشتباه است!");
            error->setWindowTitle("رمز نادرست");
            error->setIcon(QMessageBox::Critical);
            error->exec();
            return;
        }

        if(newPassword!=confirmNewPassword){

            std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
            error->setText("لطفا رمز جدید را تایید کنید!");
            error->setWindowTitle("تایید رمز جدید");
            error->setIcon(QMessageBox::Critical);
            error->exec();
            return;
        }

        if(newPassword==targetUser->getPassword()){
            std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
            error->setText("رمز جدید نمی تواند با رمز قبلی یکسان باشد!");
            error->setWindowTitle("یکسان بودن رمزها");
            error->setIcon(QMessageBox::Critical);
            error->exec();
            return;
        }

        targetUser->setPassword(newPassword);
    }
    else if(passType==2){

        if(currentPassword!=targetAccount->getPassword()){
            std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
            error->setText("رمز فعلی اشتباه است!");
            error->setWindowTitle("رمز نادرست");
            error->setIcon(QMessageBox::Critical);
            error->exec();
            return;
        }

        if(newPassword.length()!=4){

            std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
            error->setText("طول رمز اول باید 4 رقم باشد!");
            error->setWindowTitle("رمز نامعتبر");
            error->setIcon(QMessageBox::Critical);
            error->exec();
            return;
        }

        if(newPassword!=confirmNewPassword){

            std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
            error->setText("لطفا رمز جدید را تایید کنید!");
            error->setWindowTitle("تایید رمز جدید");
            error->setIcon(QMessageBox::Critical);
            error->exec();
            return;
        }


        if(newPassword==targetAccount->getPassword()){
            std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
            error->setText("رمز جدید نمی تواند با رمز قبلی یکسان باشد!");
            error->setWindowTitle("یکسان بودن رمزها");
            error->setIcon(QMessageBox::Critical);
            error->exec();
            return;
        }

        targetAccount->setPassword(newPassword);

    }


    else if(passType==3){


        if(currentPassword!=targetAccount->getStaticSecondPassword()){
            std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
            error->setText("رمز فعلی اشتباه است!");
            error->setWindowTitle("رمز نادرست");
            error->setIcon(QMessageBox::Critical);
            error->exec();
            return;
        }

        if((newPassword.length()<4)||(newPassword.length()>8)){

            std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
            error->setText("طول رمز دوم ثابت باید بین 4 تا 8 رقم باشد!");
            error->setWindowTitle("رمز نامعتبر");
            error->setIcon(QMessageBox::Critical);
            error->exec();
            return;
        }

        if(newPassword!=confirmNewPassword){

            std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
            error->setText("لطفا رمز جدید را تایید کنید!");
            error->setWindowTitle("تایید رمز جدید");
            error->setIcon(QMessageBox::Critical);
            error->exec();
            return;
        }

        if(newPassword==targetAccount->getStaticSecondPassword()){
            std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
            error->setText("رمز جدید نمی تواند با رمز قبلی یکسان باشد!");
            error->setWindowTitle("یکسان بودن رمزها");
            error->setIcon(QMessageBox::Critical);
            error->exec();
            return;
        }


        targetAccount->setStaticSecondPassword(newPassword);
    }


    std::shared_ptr<QMessageBox> success = std::make_shared<QMessageBox>();
    success->setText("تغییر رمز با موفقیت انجام شد!");
    success->setWindowTitle("تغییر رمز موفق");
    success->setIcon(QMessageBox::Information);
    this->close();
    success->exec();
    return;
}


void ChangePasswordPage::on_returnButton_clicked()
{
    this->close();
    return;
}

