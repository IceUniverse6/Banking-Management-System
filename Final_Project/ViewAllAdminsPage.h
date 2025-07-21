#ifndef VIEWALLADMINSPAGE_H
#define VIEWALLADMINSPAGE_H

#include <QDialog>

namespace Ui {
class ViewAllAdminsPage;
}

class ViewAllAdminsPage : public QDialog
{
    Q_OBJECT

public:
    explicit ViewAllAdminsPage(QWidget *parent = nullptr);
    ~ViewAllAdminsPage();

private:
    Ui::ViewAllAdminsPage *ui;
};

#endif // VIEWALLADMINSPAGE_H
