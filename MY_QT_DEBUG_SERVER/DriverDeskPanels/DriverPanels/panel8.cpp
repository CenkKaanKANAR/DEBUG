#include "panel8.h"
#include "ui_panel8.h"

Panel8::Panel8(QWidget *parent,  Qt::WindowFlags flags) :
    QDialog(parent, flags),
    ui(new Ui::Panel8)
{
    ui->setupUi(this);
}

Panel8::~Panel8()
{
    delete ui;
}
