#ifndef UDPHANDLER_H
#define UDPHANDLER_H

#include <QObject>
#include <QTcpServer>
#include <QUdpSocket>
#include <QMessageBox>

class UdpHandler : public QObject
{
    Q_OBJECT
public:
    explicit UdpHandler(QObject *parent = nullptr);
    ~UdpHandler();
    bool initUdpConnection(const QString IpAdress, const uint16_t portAdress);
    void disconnectUdpConnection();
    qint64 sendMessage(QByteArray& sendData, quint64 size);
    QUdpSocket* UDPSocket = nullptr;
    void handleDatagram(const QByteArray& packet);


public slots:
    void bytesSend(qint64 size);
    void readyRead();


signals:
    void receivedUdpMessage(QByteArray data);
    void transmissionErrorOccured(QString errorString);
    void udpBytesWritten(qint64 size);
    void udpSocketConnectionFailed();
};

#endif // UDPHANDLER_H
