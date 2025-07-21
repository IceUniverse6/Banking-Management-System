#include "CostumerPanel.h"
#include "ui_CostumerPanel.h"

CostumerPanel::CostumerPanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CostumerPanel)
{
    ui->setupUi(this);
}

CostumerPanel::~CostumerPanel()
{
    delete ui;
}
