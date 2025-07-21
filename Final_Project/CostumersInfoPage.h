#ifndef COSTUMERSINFOPAGE_H
#define COSTUMERSINFOPAGE_H

#include"User.h"

#include <QDialog>

namespace Ui {
class CostumersInfoPage;
}

class CostumersInfoPage : public QDialog
{
    Q_OBJECT

public:
    explicit CostumersInfoPage(std::shared_ptr<Costumer>, QWidget *parent = nullptr);
    ~CostumersInfoPage();

private slots:
    void on_returnButton_clicked();

    void on_searchButton_clicked();

private:
    Ui::CostumersInfoPage *ui;
    std::shared_ptr<Costumer> thisCostumer;
    const LinkedList<Account>& costumerAccounts;
};

#endif // COSTUMERSINFOPAGE_H
