#ifndef PANEL16_H
#define PANEL16_H

#include <QWidget>

namespace Ui {
class Panel16;
}

class Panel16 : public QWidget
{
    Q_OBJECT

public:
    explicit Panel16(QWidget *parent = nullptr);
    ~Panel16();

private:
    Ui::Panel16 *ui;
};

#endif // PANEL16_H
