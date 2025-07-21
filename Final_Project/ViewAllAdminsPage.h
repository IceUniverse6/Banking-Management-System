#ifndef VIEWALLADMINSPAGE_H
#define VIEWALLADMINSPAGE_H

#include"User.h"
#include <QDialog>

namespace Ui {
class ViewAllAdminsPage;
}

class ViewAllAdminsPage : public QDialog
{
    Q_OBJECT

public:
    explicit ViewAllAdminsPage(const LinkedList<User>&, QWidget *parent = nullptr);
    ~ViewAllAdminsPage();

private slots:
    void on_okButton_clicked();

private:
    Ui::ViewAllAdminsPage *ui;
};

#endif // VIEWALLADMINSPAGE_H
