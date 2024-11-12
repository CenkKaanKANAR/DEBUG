#include "panel9.h"
#include "ui_panel9.h"

Panel9::Panel9(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel9)
{
    ui->setupUi(this);
}

Panel9::~Panel9()
{
    delete ui;
}
