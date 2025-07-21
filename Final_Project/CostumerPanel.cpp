#include "CostumerPanel.h"
#include "ui_CostumerPanel.h"

#include"PersonalInfoPage.h"
#include"ViewAllAccountsPage.h"
#include"ChangePasswordPage.h"
#include"ChooseAccountPage.h"
#include"ViewAccountsForBalance.h"
#include"ChooseAccountsForTransfer.h"

CostumerPanel::CostumerPanel(std::shared_ptr<Costumer> costumerUser, LinkedList<User>& allUsers, LinkedList<Account>& allAccounts,  QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CostumerPanel)
    ,allUsers(allUsers)
    ,allAccounts(allAccounts)
{
    ui->setupUi(this);
    this->costumerUser=costumerUser;
    this->setWindowTitle("پنل مشتری");
}

CostumerPanel::~CostumerPanel()
{
    delete ui;
}

void CostumerPanel::on_viewPersonalInfoButton_clicked()
{
    std::shared_ptr<PersonalInfoPage> personalInfoPage = std::make_shared<PersonalInfoPage>(costumerUser);
    personalInfoPage->exec();
    return;
}

void CostumerPanel::on_viewAccountsButton_clicked()
{
    std::shared_ptr<ViewAllAccountsPage> viewAllAccountsPage = std::make_shared<ViewAllAccountsPage>(costumerUser->getAccounts());
    viewAllAccountsPage->exec();
    return;
}


void CostumerPanel::on_signOutButton_clicked()
{
    this->close();
    return;
}


void CostumerPanel::on_changeAccountPassButton_clicked()
{
    std::shared_ptr<ChangePasswordPage> changePasswordPage = std::make_shared<ChangePasswordPage>(costumerUser, nullptr, 1);
    changePasswordPage->exec();
    return;
}


void CostumerPanel::on_changefirstPassButton_clicked()
{
    std::shared_ptr<ChooseAccountPage> chooseAccountPage = std::make_shared<ChooseAccountPage>(costumerUser->getAccounts(), 2);
    chooseAccountPage->exec();
    return;
}


void CostumerPanel::on_changeStaticSecondPassButton_clicked()
{
    std::shared_ptr<ChooseAccountPage> chooseAccountPage = std::make_shared<ChooseAccountPage>(costumerUser->getAccounts(), 3);
    chooseAccountPage->exec();
    return;
}


void CostumerPanel::on_getBalanceButton_clicked()
{
    std::shared_ptr<ViewAccountsForBalance> viewAccountsForBalance = std::make_shared<ViewAccountsForBalance>(costumerUser->getAccounts());
    viewAccountsForBalance->exec();
    return;
}


void CostumerPanel::on_transferMoneyButton_clicked()
{
    std::shared_ptr<ChooseAccountsForTransfer> chooseAccountsForTransfer = std::make_shared<ChooseAccountsForTransfer>(costumerUser->getAccounts(), allAccounts);
    chooseAccountsForTransfer->exec();
    return;
}

