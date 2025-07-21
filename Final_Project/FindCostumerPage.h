#ifndef FINDCOSTUMERPAGE_H
#define FINDCOSTUMERPAGE_H

#include"User.h"
#include <QDialog>

namespace Ui {
class FindCostumerPage;
}

class FindCostumerPage : public QDialog
{
    Q_OBJECT

public:
    explicit FindCostumerPage(const LinkedList<User>&, QWidget *parent = nullptr);
    ~FindCostumerPage();

private slots:
    void on_searchButton_clicked();

private:
    Ui::FindCostumerPage *ui;
    const LinkedList<User>& allUsers;
};

#endif // FINDCOSTUMERPAGE_H
