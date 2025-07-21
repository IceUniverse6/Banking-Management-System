#ifndef VIEWALLCOSTUMERSPAGE_H
#define VIEWALLCOSTUMERSPAGE_H

#include <QDialog>

namespace Ui {
class ViewAllCostumersPage;
}

class ViewAllCostumersPage : public QDialog
{
    Q_OBJECT

public:
    explicit ViewAllCostumersPage(QWidget *parent = nullptr);
    ~ViewAllCostumersPage();

private:
    Ui::ViewAllCostumersPage *ui;
};

#endif // VIEWALLCOSTUMERSPAGE_H
