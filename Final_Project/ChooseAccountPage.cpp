#include "ChooseAccountPage.h"
#include "ui_ChooseAccountPage.h"

#include"ChangePasswordPage.h"

#include<QMessageBox>

ChooseAccountPage::ChooseAccountPage(const LinkedList<Account>& accounts, int passType, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChooseAccountPage)
    ,accounts(accounts)
{
    ui->setupUi(this);
    this->passType=passType;
    this->setWindowTitle("انتخاب حساب");

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

ChooseAccountPage::~ChooseAccountPage()
{
    delete ui;
}

void ChooseAccountPage::on_okButton_clicked()
{

    QString accountNumber = ui->accountNumberField->text();

    if(accountNumber.isEmpty()){

        std::shared_ptr<QMessageBox> emptyField = std::make_shared<QMessageBox>();
        emptyField->setText("فیلد شماره حساب نباید خالی باشد!");
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

    std::shared_ptr<Account> targetAccount = Account::findAccountByAccountNumber(accountNumber, accounts);

    if(targetAccount){
        std::shared_ptr<ChangePasswordPage> changePasswordPage = std::make_shared<ChangePasswordPage>(nullptr, targetAccount, passType);
        changePasswordPage->exec();
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


void ChooseAccountPage::on_returnButton_clicked()
{
    this->close();
    return;
}

