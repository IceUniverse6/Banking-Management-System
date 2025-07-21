#ifndef CHOOSEACCOUNTPAGE_H
#define CHOOSEACCOUNTPAGE_H

#include"Account.h"
#include <QDialog>

namespace Ui {
class ChooseAccountPage;
}

class ChooseAccountPage : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseAccountPage(const LinkedList<Account>&, int, QWidget *parent = nullptr);
    ~ChooseAccountPage();

private slots:
    void on_okButton_clicked();

    void on_returnButton_clicked();

private:
    Ui::ChooseAccountPage *ui;
    const LinkedList<Account>& accounts;
    int passType;
};

#endif // CHOOSEACCOUNTPAGE_H
