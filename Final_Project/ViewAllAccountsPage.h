#ifndef VIEWALLACCOUNTSPAGE_H
#define VIEWALLACCOUNTSPAGE_H

#include <QDialog>

namespace Ui {
class ViewAllAccountsPage;
}

class ViewAllAccountsPage : public QDialog
{
    Q_OBJECT

public:
    explicit ViewAllAccountsPage(QWidget *parent = nullptr);
    ~ViewAllAccountsPage();

private:
    Ui::ViewAllAccountsPage *ui;
};

#endif // VIEWALLACCOUNTSPAGE_H
