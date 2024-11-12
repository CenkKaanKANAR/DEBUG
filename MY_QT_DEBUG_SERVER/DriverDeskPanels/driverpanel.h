#ifndef DRIVERPANEL_H
#define DRIVERPANEL_H


#include <QMainWindow>
#include "DriverPanels/panel14.h"
#include "DriverPanels/panel9.h"
#include "DriverPanels/panel22.h"
#include "DriverPanels/panel16.h"
#include "DriverPanels/panel8.h"
#include "DriverPanels/panel12.h"
#include "DriverPanels/panel13.h"
#include "DriverPanels/panelx.h"
#include "DriverPanels/panely.h"
#include <QGraphicsView>




QT_BEGIN_NAMESPACE
namespace Ui { class DriverPanel; }
QT_END_NAMESPACE

class DriverPanel : public QMainWindow
{
    Q_OBJECT

public:
    DriverPanel(QWidget *parent = nullptr);
    void initPanels();
    ~DriverPanel();
    void showPanel8Popup();
    void showPanel13Popup();
    bool eventFilter(QObject *obj, QEvent *event) override ;
    void rotated_label(QLabel * label);
    void rotateLabel(QGraphicsView *view, QLabel *label, qreal angle);

signals:
    void backtoMainMenuSignal();

private:
    Ui::DriverPanel *ui;

    Panel14* panel14 = nullptr;
    Panel9* panel9 = nullptr;
    Panel22 * panel22 = nullptr;
    Panel16 * panel16 = nullptr;
    Panel8 * panel8 = nullptr;
    Panel12* panel12 = nullptr;
    Panel13* panel13 = nullptr;
    PanelX* panelx = nullptr;
    PanelY* panely = nullptr;
};
#endif // DRIVERPANEL_H
