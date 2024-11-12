#include "panel22.h"
#include "ui_panel22.h"

Panel22::Panel22(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel22)
{
    ui->setupUi(this);
}

Panel22::~Panel22()
{
    delete ui;
}
