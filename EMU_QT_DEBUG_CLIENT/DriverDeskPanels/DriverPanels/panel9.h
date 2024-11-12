#ifndef PANEL9_H
#define PANEL9_H

#include <QWidget>

namespace Ui {
class Panel9;
}

class Panel9 : public QWidget
{
    Q_OBJECT

public:
    explicit Panel9(QWidget *parent = nullptr);
    ~Panel9();

private:
    Ui::Panel9 *ui;
};

#endif // PANEL9_H
