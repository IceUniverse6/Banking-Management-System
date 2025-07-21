#ifndef PERSONALINFOPAGE_H
#define PERSONALINFOPAGE_H

#include <QDialog>

namespace Ui {
class PersonalInfoPage;
}

class PersonalInfoPage : public QDialog
{
    Q_OBJECT

public:
    explicit PersonalInfoPage(QWidget *parent = nullptr);
    ~PersonalInfoPage();

private:
    Ui::PersonalInfoPage *ui;
};

#endif // PERSONALINFOPAGE_H
