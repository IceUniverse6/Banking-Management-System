#include "RemoveAccountPage.h"
#include "ui_RemoveAccountPage.h"
#include"Costumer.h"

#include"QMessageBox"

RemoveAccountPage::RemoveAccountPage(LinkedList<Account>& allAccounts, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RemoveAccountPage)
    ,allAccounts(allAccounts)
{
    ui->setupUi(this);
    this->setWindowTitle("حذف حساب");

    if(allAccounts.getListSize()==0){

        ui->ownerList->addItem("اطلاعات موجود نیست");
        ui->accountTypeList->addItem("اطلاعات موجود نیست");
        ui->accountNumberList->addItem("اطلاعات موجود نیست");
    }

    else{

        QObject::connect(ui->accountNumberList, &QListWidget::itemClicked, this, [=](QListWidgetItem* item){
            if(!ui->accountNumberField->text().isEmpty()){
                ui->accountNumberField->clear();
            }
            ui->accountNumberField->setText(item->text());
        });


        for(size_t i=0; i<allAccounts.getListSize(); i++){
            ui->ownerList->addItem(allAccounts[i]->getOwnerName());
            ui->accountTypeList->addItem(allAccounts[i]->getAccountType());
            ui->accountNumberList->addItem(allAccounts[i]->getAccountNumber());
        }
    }
}

RemoveAccountPage::~RemoveAccountPage()
{
    delete ui;
}

void RemoveAccountPage::on_removeAccountButton_clicked()
{

    QString accountNumber = ui->accountNumberField->text();

    if(accountNumber.isEmpty()){

        std::shared_ptr<QMessageBox> emptyField = std::make_shared<QMessageBox>();
        emptyField->setText("لطفا حساب مدنظر را وارد کنید!");
        emptyField->setWindowTitle("نقص اطلاعات");
        emptyField->setIcon(QMessageBox::Critical);
        emptyField->exec();
        return;

    }

    std::shared_ptr<Account> foundAccount = Account::findAccountByAccountNumber(accountNumber, allAccounts);

    if(foundAccount){

        std::shared_ptr<Costumer> owner = foundAccount->getOwner();

        bool check1 = Account::removeAccount(foundAccount->getAccountNumber(), allAccounts);
        bool check2 = owner->removeAccount(foundAccount->getAccountNumber());


        if(check1&&check2){

            std::shared_ptr<QMessageBox> success = std::make_shared<QMessageBox>();
            success->setText("حساب با موفقیت از سیستم حذف شد");
            success->setWindowTitle("حذف موفق");
            success->setIcon(QMessageBox::Information);
            this->close();
            success->exec();
            return;

        }

        else{

            std::shared_ptr<QMessageBox> failed = std::make_shared<QMessageBox>();
            failed->setText("مشکلی در حذف حساب پیش آمد!");
            failed->setWindowTitle("مشکلی رخ داد");
            failed->setIcon(QMessageBox::Critical);
            this->close();
            failed->exec();
            return;

        }

    }

    else{
        std::shared_ptr<QMessageBox> notFound = std::make_shared<QMessageBox>();
        notFound->setText("حساب در سیستم یافت نشد!");
        notFound->setWindowTitle("حساب یافت نشد");
        notFound->setIcon(QMessageBox::Critical);
        notFound->exec();
        return;
    }

}

