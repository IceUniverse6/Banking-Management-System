#include "AdminPanel.h"
#include "ui_AdminPanel.h"

AdminPanel::AdminPanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminPanel)
{
    ui->setupUi(this);
}

AdminPanel::~AdminPanel()
{
    delete ui;
}
