#include "CostumersInfoPage.h"
#include "ui_CostumersInfoPage.h"

#include"Account.h"
#include"Costumer.h"

#include"DetailedAccountInfoPage.h"

#include<QMessageBox>

CostumersInfoPage::CostumersInfoPage(std::shared_ptr<Costumer> targetCostumer, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CostumersInfoPage)
    ,thisCostumer(targetCostumer)
    ,costumerAccounts(targetCostumer->getAccounts())

{
    ui->setupUi(this);
    this->setWindowTitle("اطلاعات مشتری");



    ui->firstName->setText(thisCostumer->getFirstName());
    ui->lastName->setText(thisCostumer->getLastName());
    ui->nationalId->setText(thisCostumer->getNationalId());
    ui->age->setText(QString::number(thisCostumer->getAge()));
    ui->userName->setText(thisCostumer->getUserName());
    ui->numberOfAccounts->setText(QString::number(thisCostumer->getNumberOfAccounts()));


    if(costumerAccounts.getListSize()==0){

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

        for(size_t i=0; i<costumerAccounts.getListSize(); i++){
            ui->accountTypeList->addItem(costumerAccounts[i]->getAccountType());
            ui->accountNumberList->addItem(costumerAccounts[i]->getAccountNumber());
        }
    }
}

CostumersInfoPage::~CostumersInfoPage()
{
    delete ui;
}

void CostumersInfoPage::on_returnButton_clicked()
{
    this->close();
    return;
}


void CostumersInfoPage::on_searchButton_clicked()
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


    for(size_t i=0; i<costumerAccounts.getListSize(); i++){

        if(costumerAccounts[i]->getAccountNumber()==accountNumber){

            std::shared_ptr<DetailedAccountInfoPage> detailedAccountInfoPage = std::make_shared<DetailedAccountInfoPage>(costumerAccounts[i]);
            detailedAccountInfoPage->exec();
            return;
        }
    }


    std::shared_ptr<QMessageBox> warning = std::make_shared<QMessageBox>();
    warning->setText("شماره حساب وارد شده متعلق به این کاربر نیست!");
    warning->setWindowTitle("حساب نامعتبر");
    warning->setIcon(QMessageBox::Critical);
    warning->exec();
    return;



}

