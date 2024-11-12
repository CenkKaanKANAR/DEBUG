#include "panel12.h"
#include "ui_panel12.h"



Panel12::Panel12(QWidget *parent, Qt::WindowFlags flags) :
    QDialog(parent, flags),
    ui(new Ui::Panel12)
{
    ui->setupUi(this);
    initPanel12Indicators();
}

Panel12::~Panel12()
{
    delete ui;
}

void Panel12::initPanel12Indicators()
{

    // QVBoxLayout'ı oluşturun
    QVBoxLayout *VlayoutItem = new QVBoxLayout();

    // İlk sıra için QHBoxLayout oluşturun
    QHBoxLayout *firstRowLayout = new QHBoxLayout();


    // İlk Led Indicator ve etiketi ekleyin
    LedIndicator *zeroSpeedByPassLocalTrainLedIndicator = new LedIndicator(this);
    zeroSpeedByPassLocalTrainLedIndicator->setLedSize(30);
    zeroSpeedByPassLocalTrainLedIndicator->setOnColor(Qt::blue);
    zeroSpeedByPassLocalTrainLedIndicator->setOffColor(Qt::red);
    firstRowLayout->addWidget(zeroSpeedByPassLocalTrainLedIndicator);

    QLabel *label1 = new QLabel("ZERO SPEED BY-PASS LOCAL TRAIN ");
    firstRowLayout->addWidget(label1);

    // İlk sırayı ana QVBoxLayout'a ekleyin
    VlayoutItem->addLayout(firstRowLayout);

    // İkinci sıra için QHBoxLayout oluşturun
    QHBoxLayout *secondRowLayout = new QHBoxLayout();

    // İkinci Led Indicator ve etiketi ekleyin
    LedIndicator *zeroSpeedByPassRemoteTrainLedIndicator = new LedIndicator(this);
    zeroSpeedByPassRemoteTrainLedIndicator->setLedSize(30);
    zeroSpeedByPassRemoteTrainLedIndicator->setOnColor(Qt::blue);
    zeroSpeedByPassRemoteTrainLedIndicator->setOffColor(Qt::red);
    secondRowLayout->addWidget(zeroSpeedByPassRemoteTrainLedIndicator);
    QLabel *label2 = new QLabel("ZERO SPEED BY-PASS REMOTE TRAIN ");
    secondRowLayout->addWidget(label2);

    // İkinci sırayı ana QVBoxLayout'a ekleyin
    VlayoutItem->addLayout(secondRowLayout);

    // Üçüncü sıra için QHBoxLayout oluşturun

    // WHISTLE PUSHBUTTON ekleyin
    QPushButton *whistlePushButton = new QPushButton(this);
    whistlePushButton->setText("WHISTLE");
    QHBoxLayout *thirdRowLayout = new QHBoxLayout();
    thirdRowLayout->addWidget(whistlePushButton);

    // Üçüncü sırayı ana QVBoxLayout'a ekleyin
    VlayoutItem->addLayout(thirdRowLayout);

    // Ana QVBoxLayout'ı ui->horizontalLayout'a ekleyin
    ui->verticalLayout->addLayout(VlayoutItem);


}
