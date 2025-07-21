#ifndef ADDNEWADMINPAGE_H
#define ADDNEWADMINPAGE_H

#include <QDialog>

namespace Ui {
class AddNewAdminPage;
}

class AddNewAdminPage : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewAdminPage(QWidget *parent = nullptr);
    ~AddNewAdminPage();

private:
    Ui::AddNewAdminPage *ui;
};

#endif // ADDNEWADMINPAGE_H
