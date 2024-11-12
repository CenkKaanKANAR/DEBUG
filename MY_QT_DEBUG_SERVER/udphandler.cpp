#include "udphandler.h"
#include <unistd.h>

UdpHandler::UdpHandler(QObject *parent)
    : QObject{parent}, UDPSocket(new QUdpSocket())
{
    connect(UDPSocket, &QUdpSocket::bytesWritten, this, &UdpHandler::bytesSend);
    connect(UDPSocket, &QUdpSocket::readyRead,this, &UdpHandler::readyRead);
}

UdpHandler::~UdpHandler()
{
    delete UDPSocket;
}

bool UdpHandler::initUdpConnection(const QString IpAdress, const uint16_t portAdress)
{

    UDPSocket->connectToHost(QHostAddress(IpAdress), portAdress);


    if (UDPSocket->waitForConnected(3000)) {
        qDebug() << "UDP Socket is Connected";
        return true;
    } else {
        qDebug() << "UDP Network Connection failed";
        emit udpSocketConnectionFailed();
        return false;
    }
}

void UdpHandler::disconnectUdpConnection()
{
    UDPSocket->disconnectFromHost();
    UDPSocket->waitForDisconnected(3000);
}

qint64 UdpHandler::sendMessage(QByteArray &sendData, quint64 size)
{
    qint64 bytesWritten = UDPSocket->write(sendData.data(), size);

    if(bytesWritten < 0)
    {
        qDebug() <<  "transmissionErrorOccured " + UDPSocket->errorString();;
        emit transmissionErrorOccured(QString::number(bytesWritten));
    }
    return bytesWritten;
}

void UdpHandler::readyRead()
{
    //QByteArray data = UDPSocket->readAll();
    while (UDPSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(static_cast<int>(UDPSocket->pendingDatagramSize()));
        QHostAddress sender;
        quint16 senderPort;

        UDPSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        //handleDatagram(datagram);
        emit receivedUdpMessage(datagram);
    }


}

void UdpHandler::handleDatagram(const QByteArray& datagram) {
    // Gelen paketi işleme kodunuz
    qDebug() << "Received datagram:" << datagram;
    // Her paketi burada ayrı ayrı ele alabilirsiniz
}
void UdpHandler::bytesSend(qint64 size)
{

    emit udpBytesWritten(size);

}
