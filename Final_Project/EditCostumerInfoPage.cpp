#include "EditCostumerInfoPage.h"
#include "ui_EditCostumerInfoPage.h"

EditCostumerInfoPage::EditCostumerInfoPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditCostumerInfoPage)
{
    ui->setupUi(this);
}

EditCostumerInfoPage::~EditCostumerInfoPage()
{
    delete ui;
}
