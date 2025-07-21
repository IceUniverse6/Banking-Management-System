#include "CostumersInfoPage.h"
#include "ui_CostumersInfoPage.h"

CostumersInfoPage::CostumersInfoPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CostumersInfoPage)
{
    ui->setupUi(this);
}

CostumersInfoPage::~CostumersInfoPage()
{
    delete ui;
}
