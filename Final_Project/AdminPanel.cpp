#include "AdminPanel.h"
#include "ui_AdminPanel.h"

#include"PersonalInfoPage.h"
#include"ViewAllCostumersPage.h"
#include"ViewAllAdminsPage.h"
#include"ViewAllAccountsPage.h"
#include"AddNewAdminPage.h"
#include"AddNewCostumerPage.h"
#include"CreateNewBankAccountPage.h"
#include"RemoveCostumerAccountPage.h"
#include"RemoveAccountPage.h"
#include"EditAdminInfoPage.h"
#include"FindCostumerPage.h"

AdminPanel::AdminPanel(std::shared_ptr<Admin> adminUser, LinkedList<User>& allUsers, LinkedList<Account>& allAccounts,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminPanel)
    ,allUsers(allUsers)
    ,allAccounts(allAccounts)
{
    ui->setupUi(this);
    this->adminUser=adminUser;
    this->setWindowTitle("پنل ادمین");
}

AdminPanel::~AdminPanel()
{
    delete ui;
}

void AdminPanel::on_viewPersonalInfoButton_clicked(){
    std::shared_ptr<PersonalInfoPage> personalInfoPage = std::make_shared<PersonalInfoPage>(adminUser);
    personalInfoPage->exec();
    return;
}

void AdminPanel::on_viewAllCostumersButton_clicked()
{
    std::shared_ptr<ViewAllCostumersPage> viewAllCostumersPage = std::make_shared<ViewAllCostumersPage>(allUsers);
    viewAllCostumersPage->exec();
    return;
}


void AdminPanel::on_viewAllAdminsButton_clicked()
{
    std::shared_ptr<ViewAllAdminsPage> viewAllAdminsPage = std::make_shared<ViewAllAdminsPage>(allUsers);
    viewAllAdminsPage->exec();
    return;
}


void AdminPanel::on_viewAllAccountsButton_clicked()
{
    std::shared_ptr<ViewAllAccountsPage> viewAllAccountsPage = std::make_shared<ViewAllAccountsPage>(allAccounts);
    viewAllAccountsPage->exec();
    return;
}


void AdminPanel::on_signOutButton_clicked(){
    this->close();
    return;
}




void AdminPanel::on_addNewAdminButton_clicked()
{
    std::shared_ptr<AddNewAdminPage> addNewAdminPage = std::make_shared<AddNewAdminPage>(allUsers);
    addNewAdminPage->exec();
    return;
}


void AdminPanel::on_addNewCostumerButton_clicked()
{
    std::shared_ptr<AddNewCostumerPage> addNewCostumerPage = std::make_shared<AddNewCostumerPage>(allUsers);
    addNewCostumerPage->exec();
    return;
}


void AdminPanel::on_addNewBankAccountButton_clicked()
{
    std::shared_ptr<CreateNewBankAccountPage> createNewBankAccountPage = std::make_shared<CreateNewBankAccountPage>(allUsers, allAccounts);
    createNewBankAccountPage->exec();
    return;
}


void AdminPanel::on_removeCostumerButton_clicked()
{
    std::shared_ptr<RemoveCostumerAccountPage> removeCostumerAccountPage = std::make_shared<RemoveCostumerAccountPage>(allUsers, allAccounts);
    removeCostumerAccountPage->exec();
    return;

}


void AdminPanel::on_removeBankAccountButton_clicked()
{
    std::shared_ptr<RemoveAccountPage> removeAccountPage = std::make_shared<RemoveAccountPage>(allAccounts);
    removeAccountPage->exec();
    return;
}


void AdminPanel::on_editPersonalInfoButton_clicked()
{
    std::shared_ptr<EditAdminInfoPage> editAdminInfoPage = std::make_shared<EditAdminInfoPage>(allUsers, adminUser);
    editAdminInfoPage->exec();
    return;
}

void AdminPanel::on_editCostumersInfoButton_clicked()
{
    std::shared_ptr<FindCostumerPage> findCostumerPage = std::make_shared<FindCostumerPage>(allUsers);
    findCostumerPage->exec();
    return;

}

