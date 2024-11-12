#ifndef PANEL22_H
#define PANEL22_H

#include <QWidget>

namespace Ui {
class Panel22;
}

class Panel22 : public QWidget
{
    Q_OBJECT

public:
    explicit Panel22(QWidget *parent = nullptr);
    ~Panel22();

private:
    Ui::Panel22 *ui;
};

#endif // PANEL22_H
