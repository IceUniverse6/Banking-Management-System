#include "TransferMoneyPage.h"
#include "ui_TransferMoneyPage.h"

TransferMoneyPage::TransferMoneyPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TransferMoneyPage)
{
    ui->setupUi(this);
}

TransferMoneyPage::~TransferMoneyPage()
{
    delete ui;
}
