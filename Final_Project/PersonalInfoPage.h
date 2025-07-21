#ifndef PERSONALINFOPAGE_H
#define PERSONALINFOPAGE_H

#include"User.h"

#include <QDialog>

namespace Ui {
class PersonalInfoPage;
}

class PersonalInfoPage : public QDialog
{
    Q_OBJECT

public:
    explicit PersonalInfoPage(std::shared_ptr<User>, QWidget *parent = nullptr);
    ~PersonalInfoPage();

private slots:
    void on_okButton_clicked();

private:
    Ui::PersonalInfoPage *ui;
};

#endif // PERSONALINFOPAGE_H
