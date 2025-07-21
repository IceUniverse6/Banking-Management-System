#include "TransferMoneyPage.h"
#include "ui_TransferMoneyPage.h"

#include<QMessageBox>

TransferMoneyPage::TransferMoneyPage(const QString& amount,std::shared_ptr<Account> fromAccount, std::shared_ptr<Account> toAccount,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TransferMoneyPage)
    ,fromAccount(fromAccount)
    ,toAccount(toAccount)
{
    ui->setupUi(this);
    this->setWindowTitle("انتقال وجه");

    ui->fromCardNumber->setText(fromAccount->getCardNumber());
    ui->fromOwner->setText(fromAccount->getOwnerName());

    ui->toCardNumber->setText(toAccount->getCardNumber());
    ui->toOwner->setText(toAccount->getOwnerName());

    ui->amount->setText(amount);
}

TransferMoneyPage::~TransferMoneyPage()
{
    delete ui;
}

void TransferMoneyPage::on_returnButton_clicked()
{
    this->close();
    return;
}


void TransferMoneyPage::on_generateDynamicSecondPassButton_clicked()
{
    if(QDate::currentDate()>fromAccount->getExpirationDate()){
        std::shared_ptr<QMessageBox> expired = std::make_shared<QMessageBox>();
        expired->setText("به علت منقضی شدن کارت، امکان صدور رمز دوم پویا وجود ندارد!");
        expired->setWindowTitle("کارت منقضی");
        expired->setIcon(QMessageBox::Critical);
        expired->exec();
        return;
    }

    QString dynamicSecondPass = Account::generateRandomDigits(6);
    fromAccount->setDynamicSecondPassword(dynamicSecondPass);
    ui->secondPassField->setText(dynamicSecondPass);
}


void TransferMoneyPage::on_transferButton_clicked()
{
    QString secondPass = ui->secondPassField->text();
    QString cvv2 = ui->cvv2Field->text();
    QString expirationDate = ui->expirationDateField->text();
    double amount = ui->amount->text().toDouble();

    if((secondPass.isEmpty())||(cvv2.isEmpty())||(expirationDate.isEmpty())){
        std::shared_ptr<QMessageBox> emptyField = std::make_shared<QMessageBox>();
        emptyField->setText("لطفا اطلاعات کارت را به صورت کامل وارد کنید!");
        emptyField->setWindowTitle("نقص اطلاعات");
        emptyField->setIcon(QMessageBox::Critical);
        emptyField->exec();
        return;
    }

    if(amount>100000){
        if(secondPass==fromAccount->getStaticSecondPassword()){
            std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
            error->setText("برای تراکنش های بیشتر از 100000 تومان لطفا از رمز دوم پویا استفاده کنید!");
            error->setWindowTitle("استفاده از رمز پویا");
            error->setIcon(QMessageBox::Critical);
            error->exec();
            return;
        }

        if(secondPass!=fromAccount->getDynamicSecondPassword()){
            std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
            error->setText("رمز پویای وارد شده نامعتبر است! مجددا درخواست کنید");
            error->setWindowTitle("رمز نامعتبر");
            error->setIcon(QMessageBox::Critical);
            error->exec();
            fromAccount->clearDynamicSecondPassword();
            return;
        }
    }
    else{
        if(secondPass!=fromAccount->getStaticSecondPassword()){
            std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
            error->setText("رمز دوم وارد شده نامعتبر است!");
            error->setWindowTitle("رمز نامعتبر");
            error->setIcon(QMessageBox::Critical);
            error->exec();
            return;
        }

        if(secondPass!=fromAccount->getDynamicSecondPassword()){
            std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
            error->setText("رمز پویای وارد شده نامعتبر است! مجددا درخواست کنید");
            error->setWindowTitle("رمز نامعتبر");
            error->setIcon(QMessageBox::Critical);
            error->exec();
            fromAccount->clearDynamicSecondPassword();
            return;
        }
    }


    if(cvv2!=fromAccount->getCvv2()){
        std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
        error->setText("شناسه cvv2 اشتباه است!");
        error->setWindowTitle("شناسه کارت نامعتبر");
        error->setIcon(QMessageBox::Critical);
        error->exec();
        return;
    }

    if(expirationDate!=fromAccount->getExpirationDate().toString("MM/yy")){
        std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
        error->setText("تاریخ انقضای کارت اشتباه است!");
        error->setWindowTitle("انقضای نامعتبر");
        error->setIcon(QMessageBox::Critical);
        error->exec();
        return;
    }

    if(QDate::currentDate()>fromAccount->getExpirationDate()){
        std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
        error->setText("به علت منقضی شدن کارت امکان تراکنش وجود ندارد!");
        error->setWindowTitle("کارت منقضی");
        error->setIcon(QMessageBox::Critical);
        error->exec();
        return;
    }


    try{

        if(Account::transfer(fromAccount, toAccount, amount)){
            std::shared_ptr<QMessageBox> success = std::make_shared<QMessageBox>();
            success->setText("تراکنش با موفقیت انجام شد!");
            success->setWindowTitle("تراکنش موفق");
            success->setIcon(QMessageBox::Information);
            this->close();
            success->exec();
            fromAccount->clearDynamicSecondPassword();
            return;
        }

    }catch(std::exception& ex){
        std::shared_ptr<QMessageBox> failed = std::make_shared<QMessageBox>();
        failed->setText(QString::fromUtf8(ex.what()));
        failed->setWindowTitle("تراکنش ناموفق");
        failed->setIcon(QMessageBox::Critical);
        failed->exec();
        fromAccount->clearDynamicSecondPassword();
        return;
    }
}
