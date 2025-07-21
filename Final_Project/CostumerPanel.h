#ifndef COSTUMERPANEL_H
#define COSTUMERPANEL_H

#include <QMainWindow>

namespace Ui {
class CostumerPanel;
}

class CostumerPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit CostumerPanel(QWidget *parent = nullptr);
    ~CostumerPanel();

private:
    Ui::CostumerPanel *ui;
};

#endif // COSTUMERPANEL_H
