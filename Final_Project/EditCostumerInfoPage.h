#ifndef EDITCOSTUMERINFOPAGE_H
#define EDITCOSTUMERINFOPAGE_H

#include <QDialog>

namespace Ui {
class EditCostumerInfoPage;
}

class EditCostumerInfoPage : public QDialog
{
    Q_OBJECT

public:
    explicit EditCostumerInfoPage(QWidget *parent = nullptr);
    ~EditCostumerInfoPage();

private:
    Ui::EditCostumerInfoPage *ui;
};

#endif // EDITCOSTUMERINFOPAGE_H
