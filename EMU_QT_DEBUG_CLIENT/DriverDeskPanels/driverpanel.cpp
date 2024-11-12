#include "driverpanel.h"
#include "ui_driverpanel.h"
#include <QLabel>
#include <QDebug>
#include <QPushButton>
#include <QPushButton>
#include <QSlider>
#include <QLayout>
#include <QDebug>
#include <QLabel>
#include <QMouseEvent>  // Bu satırı ekleyin
#include <QGraphicsScene>
#include <QGraphicsRotation>
#include <QGraphicsProxyWidget>
#include <QGraphicsView>


DriverPanel::DriverPanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DriverPanel)
{
    ui->setupUi(this);
    initPanels();

    ui->label_panel8->setToolTip("Panel8");
    ui->label_panel8->installEventFilter(this);

    ui->label_panel13->setToolTip("Panel13");
    ui->label_panel13->installEventFilter(this);
    connect(ui->actiondeneme, &QAction::triggered, this, &DriverPanel::backtoMainMenuSignal);

}
bool DriverPanel::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            if (obj == ui->label_panel8) {
                showPanel8Popup();
                return true;
            } else if (obj == ui->label_panel13) {
                showPanel13Popup();
                return true;
            }
        }
    }
    return QObject::eventFilter(obj, event);
}

void DriverPanel::rotated_label(QLabel * label)
{

    label->setGeometry(100, 100, 200, 50); // Örnek bir konum ve boyut belirtiyoruz.

    // QLabel'in boyutu için bir QPixmap oluştur
    QPixmap pixmap(label->size());
    pixmap.fill(Qt::transparent); // Arka planı temizle

    // QPixmap üzerine QLabel'i çiz
    QPainter pixmapPainter(&pixmap);
    label->render(&pixmapPainter);
    pixmapPainter.end();

    // QLabel'i döndürmek için dönüşüm matrisi oluştur
    QTransform transform;
    transform.translate(label->width() / 2, label->height() / 2); // Dönüşümün merkezini ayarla
    transform.rotate(50); // 50 derece döndür

    // Dönüştürülmüş QPixmap'i QLabel'in üzerine çiz
    QPainter painter(label);
    painter.drawPixmap(0, 0, pixmap.transformed(transform));

    label->show(); // QLabel'i göster
}

void DriverPanel::rotateLabel(QGraphicsView *view, QLabel *label, qreal angle)
{
    // QLabel'in içeriğini QPixmap'e dönüştür
    QPixmap pixmap(label->size());
    label->render(&pixmap);

    // QLabel'i temsil eden QGraphicsPixmapItem oluştur
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsPixmapItem *item = scene->addPixmap(pixmap);

    // QGraphicsView üzerindeki QLabel'i döndürmek için transform uygula
    item->setTransformOriginPoint(item->boundingRect().center());
    item->setRotation(angle);

    // QGraphicsView'i görüntüle
    view->setScene(scene);
    view->show();
}

void DriverPanel::showPanel8Popup()
{
    if (!panel8) {
        panel8 = new Panel8(this, Qt::Popup);
    }
    panel8->exec();
}

void DriverPanel::showPanel13Popup()
{
    if (!panel13) {
        panel13 = new Panel13(this, Qt::Popup);
    }
    panel13->exec();
}


void DriverPanel::initPanels()
{



    panel9 = new Panel9();
    ui->tabWidget->addTab(panel9,"panel9");

    panel12 = new Panel12(nullptr, Qt::Popup);
    ui->tabWidget->addTab(panel12,"panel12");

    panel14 = new Panel14();
    ui->tabWidget->addTab(panel14,"panel14");

    panel16 = new Panel16();
    ui->tabWidget->addTab(panel16,"panel16");

    panel22 = new Panel22();
    ui->tabWidget->addTab(panel22,"panel22");

    panelx = new PanelX();
    ui->tabWidget->addTab(panelx,"panelX");

    panely = new PanelY();
    ui->tabWidget->addTab(panely,"panelY");

}

DriverPanel::~DriverPanel()
{
    delete ui;
    delete panel8;
    delete panel9;
    delete panel12;
    delete panel14;
    delete panel16;
    delete panel22;
    delete panelx;
    delete panely;
    qDebug() << "DriverPanel Destructor";
}




