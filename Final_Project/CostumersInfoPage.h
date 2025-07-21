#ifndef COSTUMERSINFOPAGE_H
#define COSTUMERSINFOPAGE_H

#include <QDialog>

namespace Ui {
class CostumersInfoPage;
}

class CostumersInfoPage : public QDialog
{
    Q_OBJECT

public:
    explicit CostumersInfoPage(QWidget *parent = nullptr);
    ~CostumersInfoPage();

private:
    Ui::CostumersInfoPage *ui;
};

#endif // COSTUMERSINFOPAGE_H
