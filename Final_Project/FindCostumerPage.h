#ifndef FINDCOSTUMERPAGE_H
#define FINDCOSTUMERPAGE_H

#include <QDialog>

namespace Ui {
class FindCostumerPage;
}

class FindCostumerPage : public QDialog
{
    Q_OBJECT

public:
    explicit FindCostumerPage(QWidget *parent = nullptr);
    ~FindCostumerPage();

private:
    Ui::FindCostumerPage *ui;
};

#endif // FINDCOSTUMERPAGE_H
