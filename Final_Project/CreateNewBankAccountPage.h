#ifndef CREATENEWBANKACCOUNTPAGE_H
#define CREATENEWBANKACCOUNTPAGE_H

#include <QDialog>

namespace Ui {
class CreateNewBankAccountPage;
}

class CreateNewBankAccountPage : public QDialog
{
    Q_OBJECT

public:
    explicit CreateNewBankAccountPage(QWidget *parent = nullptr);
    ~CreateNewBankAccountPage();

private:
    Ui::CreateNewBankAccountPage *ui;
};

#endif // CREATENEWBANKACCOUNTPAGE_H
