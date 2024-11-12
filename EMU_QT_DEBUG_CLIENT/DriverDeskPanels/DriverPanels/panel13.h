#ifndef PANEL13_H
#define PANEL13_H

#include <QDialog>

namespace Ui {
class Panel13;
}

class Panel13 : public QDialog
{
    Q_OBJECT

public:
    explicit Panel13(QWidget *parent = nullptr,  Qt::WindowFlags flags=Qt::Popup);
    ~Panel13();

private:
    Ui::Panel13 *ui;
};

#endif // PANEL13_H
