#ifndef PANELY_H
#define PANELY_H

#include <QWidget>
#include "DriverDeskPanels/switch/switch.h"
#include <QLineEdit>

namespace Ui {
class PanelY;
}

class PanelY : public QWidget
{
    Q_OBJECT

public:
    explicit PanelY(QWidget *parent = nullptr);
    void initSwitch();
    ~PanelY();
    void saveData();

private:
    Ui::PanelY *ui;
    QLineEdit *adLineEdit;
    QLineEdit *soyadLineEdit;
    SwitchButton * m_switch = nullptr;
};

#endif // PANELY_H
