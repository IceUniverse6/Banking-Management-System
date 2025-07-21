#ifndef VIEWACCOUNTSFORBALANCE_H
#define VIEWACCOUNTSFORBALANCE_H

#include <QDialog>

namespace Ui {
class ViewAccountsForBalance;
}

class ViewAccountsForBalance : public QDialog
{
    Q_OBJECT

public:
    explicit ViewAccountsForBalance(QWidget *parent = nullptr);
    ~ViewAccountsForBalance();

private:
    Ui::ViewAccountsForBalance *ui;
};

#endif // VIEWACCOUNTSFORBALANCE_H
