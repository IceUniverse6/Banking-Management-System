#include "AddNewCostumerPage.h"
#include "ui_AddNewCostumerPage.h"

AddNewCostumerPage::AddNewCostumerPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddNewCostumerPage)
{
    ui->setupUi(this);
}

AddNewCostumerPage::~AddNewCostumerPage()
{
    delete ui;
}
