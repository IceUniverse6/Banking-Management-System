#include "FindCostumerPage.h"
#include "ui_FindCostumerPage.h"

#include"EditCostumerInfoPage.h"
#include"Costumer.h"
#include<QMessageBox>

FindCostumerPage::FindCostumerPage(const LinkedList<User>& allUsers, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FindCostumerPage)
    ,allUsers(allUsers)
{
    ui->setupUi(this);
    this->setWindowTitle("یافتن مشتری");


    QObject::connect(ui->userNameList, &QListWidget::itemClicked, this, [=](QListWidgetItem* item){
        if(!ui->userNameField->text().isEmpty()){
            ui->userNameField->clear();
        }
        ui->userNameField->setText(item->text());
    });

    for(size_t i=0; i<allUsers.getListSize(); i++){

        if(std::dynamic_pointer_cast<Costumer>(allUsers[i])){
            ui->costumersList->addItem(allUsers[i]->getFirstName()+ " " +allUsers[i]->getLastName());
            ui->userNameList->addItem(allUsers[i]->getUserName());
        }
    }
}

FindCostumerPage::~FindCostumerPage()
{
    delete ui;
}

void FindCostumerPage::on_searchButton_clicked()
{

    QString userName = ui->userNameField->text();

    if(userName.isEmpty()){
        std::shared_ptr<QMessageBox> emptyField = std::make_shared<QMessageBox>();
        emptyField->setText("نام کاربری وارد نشده!");
        emptyField->setWindowTitle("نقص اطلاعات");
        emptyField->setIcon(QMessageBox::Critical);
        emptyField->exec();
        return;
    }

    std::shared_ptr<User> foundUser = User::findUserByUserName(userName,allUsers);

    if(!foundUser){

        std::shared_ptr<QMessageBox> notFound = std::make_shared<QMessageBox>();
        notFound->setText("مشتری در سیستم یافت نشد!");
        notFound->setWindowTitle("کاربر یافت نشد");
        notFound->setIcon(QMessageBox::Critical);
        notFound->exec();
        return;

    }


    if(std::dynamic_pointer_cast<Costumer>(foundUser)){
        std::shared_ptr<EditCostumerInfoPage> editCostumerInfoPage = std::make_shared<EditCostumerInfoPage>(foundUser, allUsers);
        editCostumerInfoPage->exec();
        return;
    }
    else{
        std::shared_ptr<QMessageBox> error = std::make_shared<QMessageBox>();
        error->setText("در یافتن کاربر مشکلی پیش آمد!");
        error->setWindowTitle("مشکلی رخ داد");
        error->setIcon(QMessageBox::Critical);
        error->exec();
        return;

    }
}

