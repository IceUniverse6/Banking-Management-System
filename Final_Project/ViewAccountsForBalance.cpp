#include "ViewAccountsForBalance.h"
#include "ui_ViewAccountsForBalance.h"


#include<QMessageBox>

ViewAccountsForBalance::ViewAccountsForBalance(const LinkedList<Account>& accounts, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewAccountsForBalance)
    ,accounts(accounts)
{
    ui->setupUi(this);
    this->setWindowTitle("لیست حساب ها");

    if(accounts.getListSize()==0){

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

        for(size_t i=0; i<accounts.getListSize(); i++){
            ui->accountTypeList->addItem(accounts[i]->getAccountType());
            ui->accountNumberList->addItem(accounts[i]->getAccountNumber());
        }
    }
}

ViewAccountsForBalance::~ViewAccountsForBalance()
{
    delete ui;
}


void ViewAccountsForBalance::on_okButton_clicked()
{

    QString accountNumber = ui->accountNumberField->text();

    if(accountNumber.isEmpty()){
        std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
        error->setText("فیلد شماره حساب نمی تواند خالی باشد!");
        error->setWindowTitle("نقص اطلاعات");
        error->setIcon(QMessageBox::Critical);
        error->exec();
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

    std::shared_ptr<Account> targetAccount = Account::findAccountByAccountNumber(accountNumber, accounts);

    if(targetAccount){


        std::shared_ptr<QMessageBox> balanceBox = std::make_shared<QMessageBox>();
        QString balance = QString::number(targetAccount->getBalance(), 'f', 3);
        balanceBox->setText("موجودی حساب: " + balance);
        balanceBox->setWindowTitle("موجودی حساب");
        balanceBox->setIcon(QMessageBox::Information);
        balanceBox->exec();
        return;
    }
    else{
        std::shared_ptr<QMessageBox> notFound = std::make_shared<QMessageBox>();
        notFound->setText("حساب با این شماره یافت نشد!");
        notFound->setWindowTitle("نیافتن حساب");
        notFound->setIcon(QMessageBox::Critical);
        notFound->exec();
        return;
    }
}

void ViewAccountsForBalance::on_returnButton_clicked()
{
    this->close();
    return;
}

