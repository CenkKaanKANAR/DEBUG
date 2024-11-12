#include "panel13.h"
#include "ui_panel13.h"

Panel13::Panel13(QWidget *parent,  Qt::WindowFlags flags) :
    QDialog(parent, flags),
    ui(new Ui::Panel13)
{
    ui->setupUi(this);
}

Panel13::~Panel13()
{
    delete ui;
}
