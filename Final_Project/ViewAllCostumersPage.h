#ifndef VIEWALLCOSTUMERSPAGE_H
#define VIEWALLCOSTUMERSPAGE_H

#include"User.h"

#include <QDialog>

namespace Ui {
class ViewAllCostumersPage;
}

class ViewAllCostumersPage : public QDialog
{
    Q_OBJECT

public:
    explicit ViewAllCostumersPage(const LinkedList<User>&, QWidget *parent = nullptr);
    ~ViewAllCostumersPage();

private slots:
    void on_searchButton_clicked();

    void on_returnButton_clicked();

private:
    Ui::ViewAllCostumersPage *ui;
    const LinkedList<User>& allUsers;
};

#endif // VIEWALLCOSTUMERSPAGE_H
