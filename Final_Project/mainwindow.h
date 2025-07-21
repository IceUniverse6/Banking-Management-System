#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"User.h"
#include"Account.h"

#include"AdminPanel.h"
#include"CostumerPanel.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(LinkedList<User>&, LinkedList<Account>&, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_enterButton_clicked();

private:
    Ui::MainWindow *ui;

    LinkedList<User>& allUsers;
    LinkedList<Account>& allAccounts;
    std::shared_ptr<AdminPanel> adminPanel;
    std::shared_ptr<CostumerPanel> costumerPanel;
};
#endif // MAINWINDOW_H
