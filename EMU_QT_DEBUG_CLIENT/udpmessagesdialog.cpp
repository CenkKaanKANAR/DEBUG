#include "udpmessagesdialog.h"

UdpMessagesDialog::UdpMessagesDialog(QWidget *parent) :
    QDialog(parent),
    messageTextEdit(new QTextEdit(this)),
    sizeLabel(new QLabel(this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    messageTextEdit->setReadOnly(true);
    messageTextEdit->setStyleSheet("font-family: monospace;");  // Byte'ların düzgün görünmesi için

    sizeLabel->setStyleSheet("font-size: 10px; color: gray;");  // Boyutu küçük göster

    layout->addWidget(messageTextEdit);
    layout->addWidget(sizeLabel);

    setLayout(layout);
    setWindowTitle("UDP Mesajları");
}

void UdpMessagesDialog::appendMessage(QByteArray data, int size)
{
    qDebug() << "APPEND MESSAGE DATA : " << data;
    qDebug() << "APPEND MESSAGE DATASIZE : " << data.size();
    QString message;
    for (int i = 0; i < size; ++i) {
        message += "b" + QString::number(static_cast<unsigned char>(i)) + " :";
        message += QString::number(static_cast<unsigned char>(data[i]), 16).toUpper() + " ";  // Byte'ları hex formatında yazdır

    }
    qDebug() << "QSTRING MESAJI : " << message ;
    messageTextEdit->append(">> " + message);
    sizeLabel->setText("Veri Boyutu: " + QString::number(size) + " byte");
}
