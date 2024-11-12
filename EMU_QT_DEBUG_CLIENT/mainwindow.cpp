#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDateTime>
#include <iostream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTimer>
#include <QDockWidget>
#include "ccu_table.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_udpConnectionState(UdpConnetionState::Disconnected)
    , ui(new Ui::MainWindow)
    , m_ReadDialog(new ReadShmDialog())
    , m_UdpHandler(new UdpHandler)
    , m_dockWidget(new QDockWidget("Read Dialog", this))
    , m_ccuTableHandler(new CCU_Table())



{
    ui->setupUi(this);
    init_readDialogDockWidget();
    applyMainwindowStyleSheetConfiguration();
    ui->stackedWidget_main->addWidget(m_ccuTableHandler);

    makeSignalSlotConnection();
    //Cenk Kaan Kanar
}

MainWindow::~MainWindow()
{
    qDebug() << "MainWindow Destructor";
    delete ui;
    delete m_UdpHandler;
    delete m_ReadDialog;
}

/**
 * @brief Establishes signal-slot connections for the MainWindow.
 *
 * This function sets up the necessary signal-slot connections for the MainWindow.
 * It connects various signals from the UdpHandler to corresponding slots in the MainWindow,
 * ReadShmDialog, and CCU_TableHandler to handle UDP messages and communication system package data.
 * It also connects signals to handle UDP transmission errors and stop the CCU table timer accordingly.
 */
void MainWindow::makeSignalSlotConnection()
{
    connect(m_UdpHandler, &UdpHandler::receivedUdpMessage, this, &MainWindow::readUdpSocketMessages);
    connect(m_UdpHandler, &UdpHandler::receivedUdpMessage, m_ReadDialog, &ReadShmDialog::receive_udp_message);
    connect(m_UdpHandler, &UdpHandler::receivedUdpMessage, m_ccuTableHandler, &CCU_Table::receiveUdpMessage);
    connect(m_UdpHandler, &UdpHandler::receivedUdpMessage, m_ccuTableHandler, &CCU_Table::receiveUdpInMessage);
    connect(m_ccuTableHandler, &CCU_Table::sendCommSystemPackageData, this, &MainWindow::sendSystemModulesToCommOverUdp);
    connect(this, &MainWindow::udptransmissionErrorOccured, m_ccuTableHandler, &CCU_Table::stopCcuTableTimer);
}

void MainWindow::readUdpSocketMessages(QByteArray recv_data)
{

    QString hexString("=>");
    for (int i = 0; i < recv_data.size(); ++i) {
        hexString.append(QString::number(static_cast<unsigned char>(recv_data.at(i)), 16).rightJustified(2, '0').toUpper());
        hexString.append(' ');
    }
    //qDebug() << "Hex Dump (qDebug):" << hexString.trimmed();
    ui->textEdit_client_messages->append(hexString.trimmed());


}

void MainWindow::on_pushButton_connect_udp_socket_clicked()
{
//    if (!clientSocketConnectionStatus) {

//        QString IpAdress = getIpAdress();
//        qint16 portAdress =  getPortAdress();

//        if(m_UdpHandler->initUdpConnection(IpAdress, portAdress)) {
//            clientSocketConnectionStatus = true;
//            ui->pushButton_connect_udp_socket->setText("Disconnect");
//        }
//        else
//        {
//            QMessageBox::critical(this, "UDP Socket", "Socket is not Connected");
//        }

//    }
//    else
//    {
//        m_UdpHandler->disconnectUdpConnection();
//        clientSocketConnectionStatus = false;
//        ui->pushButton_connect_udp_socket->setText("Connect");
//    }

    if(m_udpConnectionState == UdpConnetionState::Disconnected)
    {
        QString IpAdress = getIpAdress();
        qint16 portAdress =  getPortAdress();

        if(m_UdpHandler->initUdpConnection(IpAdress, portAdress)) {
            m_udpConnectionState = UdpConnetionState::Connected;
            ui->pushButton_connect_udp_socket->setText("Disconnect");
        }
        else
        {
            QMessageBox::critical(this, "UDP Socket", "Socket is not Connected");
        }
    }
    else
    {
        m_UdpHandler->disconnectUdpConnection();
        m_udpConnectionState = UdpConnetionState::Disconnected;
        ui->pushButton_connect_udp_socket->setText("Connect");
    }
}


QString MainWindow::getIpAdress()
{
    return ui->lineEdit_server_ip_2->text();
}

quint16 MainWindow::getPortAdress()
{
    return ui->lineEdit_port_adress_2->text().toUInt();
}


void MainWindow::on_pushButton_send_test_message_clicked()
{
    QString testMessage = ui->lineEdit_test_message->text();
    sendSystemModulesToCommOverUdp(testMessage.toUtf8());
}



void MainWindow::sendSystemModulesToCommOverUdp(QByteArray sendData)
{
    if(m_udpConnectionState == UdpConnetionState::Connected)
    {
        qint64 bytesSent = m_UdpHandler->sendMessage(sendData, sendData.size());
        ui->statusbar->clearMessage();
        ui->statusbar->showMessage(QString("%1 bytes sent.").arg(bytesSent),300);

        if(bytesSent < 0){
            qDebug() << "Error";
            emit udptransmissionErrorOccured();
            m_udpConnectionState = UdpConnetionState::Disconnected;
            QMessageBox::critical(this, "UDP Message Sent", "Fail to Send Message");
        }
    }


}

void MainWindow::tcp_connection_heartbeat(qint64 bytesWritten)
{
    if(bytesWritten < 0)
    {
        tcp_heartbeat = false;
        ui->label_heartbeat_2->setState(tcp_heartbeat);
        ui->pushButton_connect_udp_socket->setText("connect");
        clientSocketConnectionStatus = false;
        m_udpConnectionState = UdpConnetionState::Disconnected;

    }
    else {
        //ui->label_heartbeat_2->clear();
        ui->label_heartbeat_2->setState(tcp_heartbeat);
        tcp_heartbeat =!tcp_heartbeat;
        clientSocketConnectionStatus = true;
        m_udpConnectionState = UdpConnetionState::Connected;
    }

}


void MainWindow::on_pushButton_read_dialog_clicked()
{
    m_dockWidget->show();
}


void MainWindow::on_pushButton_clear_text_box_2_clicked()
{
    ui->textEdit_client_messages->clear();
}


void MainWindow::init_readDialogDockWidget()
{
    // 2. QDialog'u QDockWidget içine gömmek
    m_dockWidget->setWidget(m_ReadDialog);

    // 3. QMainWindow'a QDockWidget'ı eklemek
    addDockWidget(Qt::LeftDockWidgetArea, m_dockWidget);

    m_dockWidget->setMinimumWidth(500); // Örnek olarak minimum genişlik ayarı
    m_dockWidget->setFeatures(QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetFloatable);

    m_dockWidget->hide();
}

void MainWindow::on_pushButton_ccu_table_clicked()
{
    static int index = 0;
    //ui->stackedWidget_main->setCurrentIndex(index);
    index++;
    if(index == 3)
        index = 0;

    ui->stackedWidget_main->setCurrentWidget(m_ccuTableHandler);


}

void MainWindow::on_pushButton_save_log_clicked()
{
    QString defaultFileName = "log_" + QDateTime::currentDateTime().toString("yyyy-MM-dd-hh:mm:ss") + ".txt";
    QString selectedFilePath = QFileDialog::getSaveFileName(this, tr("Choose where to save"), defaultFileName,
                                                            tr("Text Files (*.txt)"));


    //QFileInfo fileInfo(selectedFilePath);
    //QString filePathDefault = fileInfo.dir().filePath(defaultFileName);
    qDebug() << selectedFilePath;

    if (!selectedFilePath.isEmpty()) {
        QFile file(selectedFilePath);

        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);

            stream << "Bu bir log dosyasidir.\n";
            QString formattedDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

            stream << "[" << formattedDateTime <<"]"<< Qt::endl;

            stream << "Buraya log mesajlari ekleyebilirsiniz.\n";
            stream << ui->textEdit_client_messages->toPlainText();
            file.flush();
            file.close();
        }
        else {
            QMessageBox::critical(this, tr("Error"), tr("could not save the file"));
            return;
        }
    }
    ui->lineEdit_log_save_path->setText(selectedFilePath );
}


void MainWindow::on_pushButton_connection_window_widget_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(0);
}


void MainWindow::applyMainwindowStyleSheetConfiguration()
{
    this->setStyleSheet(
        "QMainWindow { background-color: #E0E0E0; border: 1px solid #CCCCCC; border-radius: 10px;  }"
        "QPushButton { background-color: #005BBB; color: white; border-radius: 5px; padding: 10px 20px; font-size: 16px; }"
        "QPushButton:hover { background-color: #004B9B; }"
        "QTableWidget { alternate-background-color: #E0E0E0; }"
        "QGroupBox { border: 2px solid #005BBB; margin-top: 10px; }"
        "QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; padding: 0 3px; }"
        "QLineEdit {"
        "    background-color: #FFFFFF;"
        "    border: 1px solid #CCCCCC;"
        "    border-radius: 5px;"
        "    padding: 5px 10px;"
        "    font-size: 14px;"
        "    color: #333333;"
        "}"
        "QLineEdit:focus {"
        "    border: 1px solid #005BBB;"
        "    background-color: #E6F4FF;"
        "}"
        "QComboBox {"
        "    background-color: #FFFFFF;"
        "    border: 1px solid #CCCCCC;"
        "    border-radius: 5px;"
        "    padding: 5px;"
        "    font-size: 14px;"
        "    color: #333333;"
        "}"
        "QComboBox::drop-down {"
        "    subcontrol-origin: padding;"
        "    subcontrol-position: top right;"
        "    width: 20px;"
        "    border-left: 1px solid #CCCCCC;"
        "}"
        "QComboBox::down-arrow {"
        "    image: url(down-arrow.png);"
        "}"
        "QComboBox QAbstractItemView {"
        "    background-color: #FFFFFF;"
        "    selection-background-color: #E6F4FF;"
        "}"

        "QTableWidget {"
        "    background-color: #FFFFFF;"
        "    alternate-background-color: #E0E0E0;"
        "    gridline-color: #CCCCCC;"
        "    font-size: 14px;"
        "    color: #333333;"
        "    selection-background-color: #E6F4FF;"
        "    selection-color: #333333;"
        "}"
        "QHeaderView::section {"
        "    background-color: #005BBB;"
        "    color: white;"
        "    padding: 4px;"
        "    border: 1px solid #CCCCCC;"
        "}"
        "QTableWidget QTableCornerButton::section {"
        "    background-color: #005BBB;"
        "}"

        "QTextEdit {"
        "    background-color: #CCCCCC;"
        "    border: 1px solid #CCCCCC;"
        "    border-radius: 5px;"
        "    padding: 10px;"
        "    font-size: 14px;"
        "    color: #333333;"
        "}"
        "QTextEdit:focus {"
        "    border: 1px solid #005BBB;"
        "    background-color: #E6F4FF;"
        "}"
        "QTabWidget::pane {"
        "    border: 1px solid #CCCCCC;"
        "    border-radius: 5px;"
        "    background-color: #F5F5F5;"
        "}"
        "QTabBar::tab {"
        "    background: #E0E0E0;"
        "    border: 1px solid #CCCCCC;"
        "    border-radius: 5px;"
        "    padding: 10px;"
        "    margin-right: 2px;"
        "}"
        "QTabBar::tab:selected {"
        "    background: #FFFFFF;"
        "    border-color: #005BBB;"
        "    color: #005BBB;"
        "}"
        "QTabBar::tab:hover {"
        "    background: #DDDDDD;"
        "}"
        "QTabBar::tab:!selected {"
        "    margin-top: 2px;"
        "}"
        "QTabWidget::tab-bar {"
        "    alignment: center;"
        "}"

        "QLabel {"
        "    color: #333333;" /* Metin rengi */
        "    font-size: 16px;" /* Metin boyutu */
        "}"

        "QLabel#specificLabel {"
        "    color: #FF0000;" /* Belirli metin rengi */
        "    font-style: italic;" /* Belirli metin stil */
        "}"

        "QLabel:hover {"
        "    background-color: #EFEFEF;" /* Arkaplan rengi değişimi */
        "}"

        "QLabel:pressed {"
        "    color: #0000FF;" /* Tıklama rengi değişimi */
        "}"
        );
}

