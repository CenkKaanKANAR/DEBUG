#ifndef QLEDLABEL_H
#define QLEDLABEL_H

#include <QLabel>

class QLedLabel : public QLabel
{
    Q_OBJECT
public:
    explicit QLedLabel(QWidget *parent = 0, int size =20);

    enum State{
        StateOk,
        StateOkBlue,
        StateWarning,
        StateError
    };


signals:

public slots:
    void setState(State state);
    void setState(bool state);
    void setColor();
    void setSize(int size);
    int getSize();


private:
    //static const int SIZE = 40;
    QString m_greenSS;
    QString m_redSS;
    QString m_orangeSS;
    QString m_blueSS;

    int m_SIZE;

};

#endif // QLEDLABEL_H
