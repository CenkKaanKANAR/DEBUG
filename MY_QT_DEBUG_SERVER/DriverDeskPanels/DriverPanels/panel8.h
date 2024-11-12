#ifndef PANEL8_H
#define PANEL8_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class Panel8;
}

class Panel8 : public QDialog
{
    Q_OBJECT

public:
    explicit Panel8(QWidget *parent, Qt::WindowFlags flags);
    ~Panel8();

private:
    Ui::Panel8 *ui;
};

#endif // PANEL8_H
