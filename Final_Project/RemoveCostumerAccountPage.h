#ifndef REMOVECOSTUMERACCOUNTPAGE_H
#define REMOVECOSTUMERACCOUNTPAGE_H

#include <QDialog>

namespace Ui {
class RemoveCostumerAccountPage;
}

class RemoveCostumerAccountPage : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveCostumerAccountPage(QWidget *parent = nullptr);
    ~RemoveCostumerAccountPage();

private:
    Ui::RemoveCostumerAccountPage *ui;
};

#endif // REMOVECOSTUMERACCOUNTPAGE_H
