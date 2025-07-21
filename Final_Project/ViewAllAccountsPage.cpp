#include "ViewAllAccountsPage.h"
#include "ui_ViewAllAccountsPage.h"

#include"DetailedAccountInfoPage.h"

#include<QMessageBox>

ViewAllAccountsPage::ViewAllAccountsPage(const LinkedList<Account>& allAccounts, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewAllAccountsPage)
    ,allAccounts(allAccounts)
{
    ui->setupUi(this);
    this->setWindowTitle("مشاهده حساب ها");

    if(allAccounts.getListSize()==0){

        ui->accountTypeList->addItem("اطلاعات موجود نیست");
        ui->ownerList->addItem("اطلاعات موجود نیست");
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

            ui->accountTypeList->addItem(allAccounts[i]->getAccountType());
            ui->ownerList->addItem(allAccounts[i]->getOwnerName());
            ui->accountNumberList->addItem(allAccounts[i]->getAccountNumber());
        }
    }
}

ViewAllAccountsPage::~ViewAllAccountsPage()
{
    delete ui;
}

void ViewAllAccountsPage::on_searchButton_clicked()
{
    QString accountNumber = ui->accountNumberField->text();

    if(accountNumber.isEmpty()){

        std::shared_ptr<QMessageBox> emptyField = std::make_shared<QMessageBox>();
        emptyField->setText("شماره حساب وارد نشده!");
        emptyField->setWindowTitle("نقص اطلاعات");
        emptyField->setIcon(QMessageBox::Critical);
        emptyField->exec();
        return;
    }

    if(accountNumber.length()!=15){

        std::shared_ptr<QMessageBox> invalidInput = std::make_shared<QMessageBox>();
        invalidInput->setText("شماره حساب وارد شده نامعتبر است!");
        invalidInput->setWindowTitle("ورودی نامعتبر");
        invalidInput->setIcon(QMessageBox::Critical);
        invalidInput->exec();
        return;

    }

    std::shared_ptr<Account> foundAccount = Account::findAccountByAccountNumber(accountNumber, allAccounts);

    if(foundAccount){
        std::shared_ptr<DetailedAccountInfoPage> detailedAccountInfoPage = std::make_shared<DetailedAccountInfoPage>(foundAccount);
        detailedAccountInfoPage->exec();
        return;
    }
    else{
        std::shared_ptr<QMessageBox> notFound = std::make_shared<QMessageBox>();
        notFound->setText("حساب یافت نشد!");
        notFound->setWindowTitle("حساب یافت نشد");
        notFound->setIcon(QMessageBox::Critical);
        notFound->exec();
        return;
    }
}


void ViewAllAccountsPage::on_returnButton_clicked()
{
    this->close();
    return;
}

