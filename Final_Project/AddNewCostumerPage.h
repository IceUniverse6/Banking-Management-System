#ifndef ADDNEWCOSTUMERPAGE_H
#define ADDNEWCOSTUMERPAGE_H

#include <QDialog>

namespace Ui {
class AddNewCostumerPage;
}

class AddNewCostumerPage : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewCostumerPage(QWidget *parent = nullptr);
    ~AddNewCostumerPage();

private:
    Ui::AddNewCostumerPage *ui;
};

#endif // ADDNEWCOSTUMERPAGE_H
