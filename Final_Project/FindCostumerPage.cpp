#include "FindCostumerPage.h"
#include "ui_FindCostumerPage.h"

FindCostumerPage::FindCostumerPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FindCostumerPage)
{
    ui->setupUi(this);
}

FindCostumerPage::~FindCostumerPage()
{
    delete ui;
}
