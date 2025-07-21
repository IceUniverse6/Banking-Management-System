#ifndef CHOOSEACCOUNTSFORTRANSFER_H
#define CHOOSEACCOUNTSFORTRANSFER_H

#include <QDialog>

namespace Ui {
class ChooseAccountsForTransfer;
}

class ChooseAccountsForTransfer : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseAccountsForTransfer(QWidget *parent = nullptr);
    ~ChooseAccountsForTransfer();

private:
    Ui::ChooseAccountsForTransfer *ui;
};

#endif // CHOOSEACCOUNTSFORTRANSFER_H
