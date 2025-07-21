#ifndef TRANSFERMONEYPAGE_H
#define TRANSFERMONEYPAGE_H

#include <QDialog>

namespace Ui {
class TransferMoneyPage;
}

class TransferMoneyPage : public QDialog
{
    Q_OBJECT

public:
    explicit TransferMoneyPage(QWidget *parent = nullptr);
    ~TransferMoneyPage();

private:
    Ui::TransferMoneyPage *ui;
};

#endif // TRANSFERMONEYPAGE_H
