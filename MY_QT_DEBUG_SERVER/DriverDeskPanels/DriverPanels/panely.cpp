#include "panely.h"
#include "ui_panely.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSlider>
#include <QLayout>
#include <QDebug>
#include <QLabel>
#include <QMouseEvent>  // Bu satırı ekleyin

PanelY::PanelY(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PanelY)
{
    ui->setupUi(this);
    initSwitch();
}

void PanelY::initSwitch()
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel("Ad ve Soyad:", this);
    layout->addWidget(label);

    m_switch = new SwitchButton();

    adLineEdit = new QLineEdit(this);
    soyadLineEdit = new QLineEdit(this);
    layout->addWidget(adLineEdit);
    layout->addWidget(soyadLineEdit);

    QPushButton *saveButton = new QPushButton("Kaydet", this);
    connect(saveButton, &QPushButton::clicked, this, &PanelY::saveData);
    connect(m_switch, &SwitchButton::valueChanged, this, [=]() {
        qDebug() << m_switch->value();

    });
    layout->addWidget(saveButton);
    layout->addWidget(m_switch);

    setLayout(layout);
    setGeometry(300, 300, 300, 150);
}


PanelY::~PanelY()
{
    delete ui;
}

void PanelY::saveData()
{
    QString ad = adLineEdit->text();
    QString soyad = soyadLineEdit->text();
    qDebug("Ad: %s, Soyad: %s", qPrintable(ad), qPrintable(soyad));
    qDebug() <<"switch:" << m_switch->value();
    close();
}
