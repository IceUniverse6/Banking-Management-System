#ifndef DETAILEDACCOUNTINFOPAGE_H
#define DETAILEDACCOUNTINFOPAGE_H

#include <QDialog>

namespace Ui {
class DetailedAccountInfoPage;
}

class DetailedAccountInfoPage : public QDialog
{
    Q_OBJECT

public:
    explicit DetailedAccountInfoPage(QWidget *parent = nullptr);
    ~DetailedAccountInfoPage();

private:
    Ui::DetailedAccountInfoPage *ui;
};

#endif // DETAILEDACCOUNTINFOPAGE_H
