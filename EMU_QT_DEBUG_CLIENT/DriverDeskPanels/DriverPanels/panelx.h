#ifndef PANELX_H
#define PANELX_H

#include <QWidget>
#include "DriverDeskPanels/speedGauge/qcgaugewidget.h"
namespace Ui {
class PanelX;
}

class PanelX : public QWidget
{
    Q_OBJECT

public:
    explicit PanelX(QWidget *parent = nullptr);
    void initSpeedGauge();
    ~PanelX();

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::PanelX *ui;
    QcGaugeWidget * mSpeedGauge;
    QcNeedleItem *mSpeedNeedle;
};

#endif // PANELX_H
