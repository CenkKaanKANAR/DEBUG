#include "panel16.h"
#include "ui_panel16.h"

Panel16::Panel16(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel16)
{
    ui->setupUi(this);
}

Panel16::~Panel16()
{
    delete ui;
}
