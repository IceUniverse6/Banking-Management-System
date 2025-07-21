#include "CreateNewBankAccountPage.h"
#include "ui_CreateNewBankAccountPage.h"

#include"AccountInfoPage.h"

#include"QMessageBox"

CreateNewBankAccountPage::CreateNewBankAccountPage(const LinkedList<User>& allUsers, LinkedList<Account>& allAccounts, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateNewBankAccountPage)
    ,allUsers(allUsers)
    ,allAccounts(allAccounts)
{
    ui->setupUi(this);
    this->setWindowTitle("ساخت حساب بانکی");
}

CreateNewBankAccountPage::~CreateNewBankAccountPage()
{
    delete ui;
}

void CreateNewBankAccountPage::on_createAccountButton_clicked()
{

    QString firstName = ui->firstNameField->text();
    QString lastName = ui->lastNameField->text();
    QString nationalId = ui->nationalIdField->text();

    QString accountType;

    QString password = ui->passwordField->text();
    QString staticSecondPass = ui->staticSecondPassField->text();
    QString balance = ui->balanceField->text();

    if((firstName.isEmpty())||(lastName.isEmpty())||(nationalId.isEmpty())){

        std::shared_ptr<QMessageBox> emptyField = std::make_shared<QMessageBox>();
        emptyField->setText("اطلاعات مشتری ناقص است!");
        emptyField->setWindowTitle("نقص اطلاعات");
        emptyField->setIcon(QMessageBox::Critical);
        emptyField->exec();
        return;
    }


    if(nationalId.length()!=10){

        std::shared_ptr<QMessageBox> lengthError = std::make_shared<QMessageBox>();
        lengthError->setText("کد ملی وارد شده نامعتبر است!");
        lengthError->setWindowTitle("ورودی نامعتبر");
        lengthError->setIcon(QMessageBox::Critical);
        lengthError->exec();
        return;

    }


    if(ui->buttonGroup->checkedButton()){

        accountType=ui->buttonGroup->checkedButton()->text();

        if((password.isEmpty())||(staticSecondPass.isEmpty())||(balance.isEmpty())){

            std::shared_ptr<QMessageBox> emptyField = std::make_shared<QMessageBox>();
            emptyField->setText("اطلاعات حساب ناقص است!");
            emptyField->setWindowTitle("نقص اطلاعات");
            emptyField->setIcon(QMessageBox::Critical);
            emptyField->exec();
            return;
        }

        if(password.length()!=4){

            std::shared_ptr<QMessageBox> lengthError = std::make_shared<QMessageBox>();
            lengthError->setText("رمز اول باید چهار رقم باشد!");
            lengthError->setWindowTitle("ورودی نامعتبر");
            lengthError->setIcon(QMessageBox::Critical);
            lengthError->exec();
            return;

        }

        if((staticSecondPass.length()<4)||(staticSecondPass.length()>8)){


            std::shared_ptr<QMessageBox> lengthError = std::make_shared<QMessageBox>();
            lengthError->setText("طول رمز دوم ثابت باید بین 4 تا 8 رقم باشد!");
            lengthError->setWindowTitle("ورودی نامعتبر");
            lengthError->setIcon(QMessageBox::Critical);
            lengthError->exec();
            return;
        }

        if(balance.toDouble()<50000){

            std::shared_ptr<QMessageBox> amountError = std::make_shared<QMessageBox>();
            amountError->setText("موجودی اولیه باید حداقل 50000 هزار تومان باشد!");
            amountError->setWindowTitle("عدم رعایت حداقل موجودی");
            amountError->setIcon(QMessageBox::Critical);
            amountError->exec();
            return;

        }



    }
    else{
        std::shared_ptr<QMessageBox> emptyField = std::make_shared<QMessageBox>();
        emptyField->setText("انتخاب نوع حساب الزامی است!");
        emptyField->setWindowTitle("نقص اطلاعات");
        emptyField->setIcon(QMessageBox::Critical);
        emptyField->exec();
        return;
    }


    try{

        std::shared_ptr<Account> createdAccount = Account::createAccount(firstName, lastName, nationalId, accountType, password, staticSecondPass, balance.toDouble(), allUsers, allAccounts);

        if(createdAccount){

            this->close();
            std::shared_ptr<QMessageBox> success = std::make_shared<QMessageBox>();
            success->setText("حساب با موفقیت ساخته شد!");
            success->setWindowTitle("ساخت حساب");
            success->setIcon(QMessageBox::Information);
            success->exec();


            std::shared_ptr<AccountInfoPage> accountInfoPage = std::make_shared<AccountInfoPage>(createdAccount);
            accountInfoPage->exec();
            return;

        }

        else{

            std::shared_ptr<QMessageBox> notFound = std::make_shared<QMessageBox>();
            notFound->setText("کاربر با مشخصات مذکور در سیستم وجود ندارد!");
            notFound->setWindowTitle("نیافتن کاربر");
            notFound->setIcon(QMessageBox::Critical);
            notFound->exec();
            return;

        }

    } catch(const std::exception& ex){


        std::shared_ptr<QMessageBox> failed = std::make_shared<QMessageBox>();
        failed->setText("تعداد حساب های کاربر به حداکثر رسیده!");
        failed->setWindowTitle("حداکثر تعداد حساب");
        failed->setIcon(QMessageBox::Critical);
        failed->exec();
        return;

    }


}

