#include "ChooseAccountsForTransfer.h"
#include "ui_ChooseAccountsForTransfer.h"

#include"TransferMoneyPage.h"

#include<QMessageBox>

ChooseAccountsForTransfer::ChooseAccountsForTransfer(const LinkedList<Account>& costumerAccounts, const LinkedList<Account>& allAccounts, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChooseAccountsForTransfer)
    , costumerAccounts(costumerAccounts)
    ,allAccounts(allAccounts)
{
    ui->setupUi(this);
    this->setWindowTitle("انتخاب حساب");


    if(costumerAccounts.getListSize()==0){

        ui->accountTypeList->addItem("اطلاعات موجود نیست");
        ui->cardNumberList->addItem("اطلاعات موجود نیست");
    }

    else{

        QObject::connect(ui->cardNumberList, &QListWidget::itemClicked, this, [=](QListWidgetItem* item){
            if(!ui->fromCardNumberField->text().isEmpty()){
                ui->fromCardNumberField->clear();
            }
            ui->fromCardNumberField->setText(item->text());
        });


        for(size_t i=0; i<costumerAccounts.getListSize(); i++){
            ui->accountTypeList->addItem(costumerAccounts[i]->getAccountType());
            ui->cardNumberList->addItem(costumerAccounts[i]->getCardNumber());
        }

    }
}

ChooseAccountsForTransfer::~ChooseAccountsForTransfer()
{
    delete ui;
}

void ChooseAccountsForTransfer::on_okButton_clicked()
{
    QString fromCardNumber = ui->fromCardNumberField->text();
    QString toCardNumber = ui->toCardNumberField->text();
    QString amount = ui->amountField->text();


    if((fromCardNumber.isEmpty())||(toCardNumber.isEmpty())||(amount.isEmpty())){

        std::shared_ptr<QMessageBox> emptyField = std::make_shared<QMessageBox>();
        emptyField->setText("تمامی فیلدها باید پر باشند!");
        emptyField->setWindowTitle("نقص اطلاعات");
        emptyField->setIcon(QMessageBox::Critical);
        emptyField->exec();
        return;
    }

    if(fromCardNumber.length()!=19){

        std::shared_ptr<QMessageBox> lengthError = std::make_shared<QMessageBox>();
        lengthError->setText("فرمت شماره کارت مبدا وارد شده نامعتبر است!");
        lengthError->setWindowTitle("ورودی نامعتبر");
        lengthError->setIcon(QMessageBox::Critical);
        lengthError->exec();
        return;

    }

    if(toCardNumber.length()!=19){

        std::shared_ptr<QMessageBox> lengthError = std::make_shared<QMessageBox>();
        lengthError->setText("فرمت شماره کارت مقصد وارد شده نامعتبر است!");
        lengthError->setWindowTitle("ورودی نامعتبر");
        lengthError->setIcon(QMessageBox::Critical);
        lengthError->exec();
        return;

    }

    if(amount.toFloat()<0){

        std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
        error->setText("مقدار وجه انتقالی نامعتبر است!");
        error->setWindowTitle("ورودی نامعتبر");
        error->setIcon(QMessageBox::Critical);
        error->exec();
        return;
    }
    if(amount.toFloat()<1000){

        std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
        error->setText("حداقل مقدار تراکنش 1000 تومان می باشد!");
        error->setWindowTitle("عدم رعایت حداقل تراکنش");
        error->setIcon(QMessageBox::Critical);
        error->exec();
        return;
    }
    if(amount.toFloat()>3000000){

        std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
        error->setText("حداکثر مقدار هر تراکنش 3,000,000 تومان می باشد!");
        error->setWindowTitle("عدم رعایت حداکثر تراکنش");
        error->setIcon(QMessageBox::Critical);
        error->exec();
        return;

    }

    if(fromCardNumber==toCardNumber){

        std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
        error->setText("شماره کارت مبدا و مقصد نمی تواند یکسان باشد!");
        error->setWindowTitle("شماره کارت یکسان");
        error->setIcon(QMessageBox::Critical);
        error->exec();
        return;

    }

    std::shared_ptr<Account> fromAccount = Account::findAccountByCardNumber(fromCardNumber, costumerAccounts);
    std::shared_ptr<Account> toAccount = Account::findAccountByCardNumber(toCardNumber, allAccounts);

    if(!fromAccount){
        std::shared_ptr<QMessageBox> notFound = std::make_shared<QMessageBox>();
        notFound->setText("شماره کارت مبدا یافت نشد!");
        notFound->setWindowTitle("نیافتن حساب");
        notFound->setIcon(QMessageBox::Critical);
        notFound->exec();
        return;
    }

    if(!toAccount){
        std::shared_ptr<QMessageBox> notFound = std::make_shared<QMessageBox>();
        notFound->setText("شماره کارت مقصد وارد شده نامعتبر است!");
        notFound->setWindowTitle("نامعتبر بودن حساب ورودی");
        notFound->setIcon(QMessageBox::Critical);
        notFound->exec();
        return;
    }

    std::shared_ptr<TransferMoneyPage> transferMoneyPage = std::make_shared<TransferMoneyPage>(amount, fromAccount, toAccount);
    transferMoneyPage->exec();
    return;
}


void ChooseAccountsForTransfer::on_returnButton_clicked()
{
    this->close();
    return;
}

