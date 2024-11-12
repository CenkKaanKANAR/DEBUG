#ifndef PANEL12_H
#define PANEL12_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include "DriverDeskPanels/led/ledindicator.h"

namespace Ui {
class Panel12;
}

class Panel12 : public QDialog
{
    Q_OBJECT

public:
    explicit Panel12(QWidget *parent, Qt::WindowFlags flags);
    void initPanel12Indicators();
    ~Panel12();

private:
    Ui::Panel12 *ui;
    LedIndicator* myLedIndicator = nullptr;
    LedIndicator* led1 = nullptr;
    LedIndicator* led2 = nullptr;
    LedIndicator* led3 = nullptr;
    LedIndicator* led4 = nullptr;
};

#endif // PANEL12_H
