#ifndef PANEL14_H
#define PANEL14_H

#include <QWidget>
#include "DriverDeskPanels/led/ledindicator.h"
namespace Ui {
class Panel14;
}

class Panel14 : public QWidget
{
    Q_OBJECT

public:
    explicit Panel14(QWidget *parent = nullptr);
    ~Panel14();
    void initPanel14Indicators();

private:
    Ui::Panel14 *ui;
};

#endif // PANEL14_H
