#include "RemoveCostumerAccountPage.h"
#include "ui_RemoveCostumerAccountPage.h"
#include"Costumer.h"

#include<QMessageBox>

RemoveCostumerAccountPage::RemoveCostumerAccountPage(LinkedList<User>& allUsers, LinkedList<Account>& allAccounts,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RemoveCostumerAccountPage)
    ,allUsers(allUsers)
    ,allAccounts(allAccounts)
{
    ui->setupUi(this);
    this->setWindowTitle("حذف مشتری");

    QObject::connect(ui->userNameList, &QListWidget::itemClicked, this, [=](QListWidgetItem* item){
        if(!ui->userNameField->text().isEmpty()){
            ui->userNameField->clear();
        }
        ui->userNameField->setText(item->text());
    });

    for(size_t i=0; i<allUsers.getListSize(); i++){

        if(std::dynamic_pointer_cast<Costumer>(allUsers[i])){
            ui->ownerList->addItem(allUsers[i]->getFirstName()+" "+allUsers[i]->getLastName());
            ui->userNameList->addItem(allUsers[i]->getUserName());
        }
    }
}

RemoveCostumerAccountPage::~RemoveCostumerAccountPage()
{
    delete ui;
}

void RemoveCostumerAccountPage::on_removeCostumerButton_clicked()
{
    QString userName = ui->userNameField->text();

    if(userName.isEmpty()){

        std::shared_ptr<QMessageBox> emptyField = std::make_shared<QMessageBox>();
        emptyField->setText("لطفا یک نام کاربری انتخاب کنید");
        emptyField->setWindowTitle("نقص اطلاعات");
        emptyField->setIcon(QMessageBox::Critical);
        emptyField->exec();
        return;

    }

    std::shared_ptr<User> foundCostumer = User::findUserByUserName(userName, allUsers);


    if(foundCostumer){

        std::shared_ptr<Costumer> targetCostumer = std::dynamic_pointer_cast<Costumer>(foundCostumer);

        if(targetCostumer){

            bool check1 = Account::removeAccounts(targetCostumer->getAccounts(), allAccounts);
            bool check2 = targetCostumer->removeAccounts();
            bool check3 = User::removeCostumer(targetCostumer->getUserName(), allUsers);


            if(check1&&check2&&check3){

                std::shared_ptr<QMessageBox> success = std::make_shared<QMessageBox>();
                success->setText("کاربر با موفقیت از سیستم حذف شد");
                success->setWindowTitle("حذف موفق");
                success->setIcon(QMessageBox::Information);
                this->close();
                success->exec();
                return;

            }
            else{

                std::shared_ptr<QMessageBox> failed = std::make_shared<QMessageBox>();
                failed->setText("در حذف کاربر مشکلی پیش آمد");
                failed->setWindowTitle("مشکلی رخ داد");
                failed->setIcon(QMessageBox::Critical);
                this->close();
                failed->exec();
                return;

            }
        }
        else{
            std::shared_ptr<QMessageBox> notFound = std::make_shared<QMessageBox>();
            notFound->setText("کاربر در سیستم یافت نشد!");
            notFound->setWindowTitle("کاربر یافت نشد");
            notFound->setIcon(QMessageBox::Critical);
            notFound->exec();
            return;
        }
    }
    else{

        std::shared_ptr<QMessageBox> notFound = std::make_shared<QMessageBox>();
        notFound->setText("کاربر در سیستم یافت نشد!");
        notFound->setWindowTitle("کاربر یافت نشد");
        notFound->setIcon(QMessageBox::Critical);
        notFound->exec();
        return;
    }
}

