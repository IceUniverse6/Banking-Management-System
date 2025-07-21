#ifndef REMOVEACCOUNTPAGE_H
#define REMOVEACCOUNTPAGE_H

#include <QDialog>

namespace Ui {
class RemoveAccountPage;
}

class RemoveAccountPage : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveAccountPage(QWidget *parent = nullptr);
    ~RemoveAccountPage();

private:
    Ui::RemoveAccountPage *ui;
};

#endif // REMOVEACCOUNTPAGE_H
