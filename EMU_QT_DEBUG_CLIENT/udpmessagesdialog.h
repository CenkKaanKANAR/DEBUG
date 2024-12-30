#ifndef UDPMESSAGESDIALOG_H
#define UDPMESSAGESDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>

class UdpMessagesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UdpMessagesDialog(QWidget *parent = nullptr);
    void appendMessage(QByteArray data, int size);

private:
    QTextEdit *messageTextEdit;  // Gelen veriyi byte byte göstermek için
    QLabel *sizeLabel;  // Boyut bilgisini göstermek için
};

#endif // UDPMESSAGESDIALOG_H
