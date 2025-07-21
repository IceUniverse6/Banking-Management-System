#ifndef CHOOSEACCOUNTPAGE_H
#define CHOOSEACCOUNTPAGE_H

#include <QDialog>

namespace Ui {
class ChooseAccountPage;
}

class ChooseAccountPage : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseAccountPage(QWidget *parent = nullptr);
    ~ChooseAccountPage();

private:
    Ui::ChooseAccountPage *ui;
};

#endif // CHOOSEACCOUNTPAGE_H
