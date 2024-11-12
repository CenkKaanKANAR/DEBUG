#include "panel14.h"
#include "ui_panel14.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

Panel14::Panel14(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel14)
{
    ui->setupUi(this);
    initPanel14Indicators();
}

Panel14::~Panel14()
{
    delete ui;
}

void Panel14::initPanel14Indicators()
{
    // QVBoxLayout'ı oluşturun
    QVBoxLayout *VlayoutItem = new QVBoxLayout();

    // İlk sıra için QHBoxLayout oluşturun
    QHBoxLayout *firstRowLayout = new QHBoxLayout();


    // İlk Led Indicator ve etiketi ekleyin
    LedIndicator *alarmPassOutOfFireLedIndicator = new LedIndicator(this);
    alarmPassOutOfFireLedIndicator->setLedSize(30);
    alarmPassOutOfFireLedIndicator->setOnColor(Qt::blue);
    alarmPassOutOfFireLedIndicator->setOffColor(Qt::red);
    firstRowLayout->addWidget(alarmPassOutOfFireLedIndicator);

    QLabel *label1 = new QLabel("ALARM PASS OUT OF FIRE");
    firstRowLayout->addWidget(label1);

    // İlk sırayı ana QVBoxLayout'a ekleyin
    VlayoutItem->addLayout(firstRowLayout);

    // İkinci sıra için QHBoxLayout oluşturun
    QHBoxLayout *secondRowLayout = new QHBoxLayout();

    // İkinci Led Indicator ve etiketi ekleyin
    LedIndicator *alarmPassInServiceLedIndicator = new LedIndicator(this);
    alarmPassInServiceLedIndicator->setLedSize(30);
    alarmPassInServiceLedIndicator->setOnColor(Qt::blue);
    alarmPassInServiceLedIndicator->setOffColor(Qt::red);
    secondRowLayout->addWidget(alarmPassInServiceLedIndicator);
    QLabel *label2 = new QLabel("ALARM PASS. IN SERVICE ");
    secondRowLayout->addWidget(label2);

    // İkinci sırayı ana QVBoxLayout'a ekleyin
    VlayoutItem->addLayout(secondRowLayout);

    // Üçüncü sıra için QHBoxLayout oluşturun

    // NEUTRILIZATION ALARM PASSENGERS ekleyin
    QPushButton *neutrilizationAlarmPassengersPushButton = new QPushButton(this);
    neutrilizationAlarmPassengersPushButton->setText("NEUTRILIZATION ALARM PASSENGERS");
    QHBoxLayout *thirdRowLayout = new QHBoxLayout();
    thirdRowLayout->addWidget(neutrilizationAlarmPassengersPushButton);

    // Üçüncü sırayı ana QVBoxLayout'a ekleyin
    VlayoutItem->addLayout(thirdRowLayout);

    // Ana QVBoxLayout'ı ui->horizontalLayout'a ekleyin
    ui->verticalLayout->addLayout(VlayoutItem);
}
