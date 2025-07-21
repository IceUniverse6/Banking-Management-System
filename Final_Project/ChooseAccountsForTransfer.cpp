#include "ChooseAccountsForTransfer.h"
#include "ui_ChooseAccountsForTransfer.h"

ChooseAccountsForTransfer::ChooseAccountsForTransfer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChooseAccountsForTransfer)
{
    ui->setupUi(this);
}

ChooseAccountsForTransfer::~ChooseAccountsForTransfer()
{
    delete ui;
}
