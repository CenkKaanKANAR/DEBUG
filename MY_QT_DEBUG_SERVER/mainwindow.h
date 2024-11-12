#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QUdpSocket>
#include <QTcpSocket>
#include <QList>
#include <QMessageBox>
#include <qledlabel.h>
#include <QDialog>
#include <QVBoxLayout>
#include "ReadShmDialog.h"
#include "udphandler.h"

class CCU_Table;

enum class UdpConnetionState{Connected, Disconnected};
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString getIpAdress();
    quint16 getPortAdress();
    void tcp_connection_heartbeat(qint64 bytesWritten);
    void makeSignalSlotConnection();
    void applyMainwindowStyleSheetConfiguration();
    void init_readDialogDockWidget();
    UdpConnetionState m_udpConnectionState;


public slots:
    void readUdpSocketMessages(QByteArray data);
    void sendSystemModulesToCommOverUdp(QByteArray sendData);

private slots:

    void on_pushButton_read_dialog_clicked();
    void on_pushButton_send_test_message_clicked();
    void on_pushButton_connect_udp_socket_clicked();
    void on_pushButton_clear_text_box_2_clicked();
    void on_pushButton_save_log_clicked();

    void on_pushButton_ccu_table_clicked();

    void on_pushButton_connection_window_widget_clicked();

signals:
    void send_shared_memory_read_json_data_to_read_dialog(QByteArray shm_read_data);
    void udptransmissionErrorOccured();
private:
    Ui::MainWindow *ui;

    QTimer *timer_heartbeat = nullptr;  // QTimer'ı sınıfın bir üyesi olarak tanımla
    bool tcp_heartbeat = false;

    bool clientSocketConnectionStatus = false;

    //QTcpSocket* TCPSocket = nullptr;
    QUdpSocket* UDPSocket = nullptr;

    QLedLabel *led1 = nullptr;
    QLedLabel *led2 = nullptr;
    QLedLabel *led3 = nullptr;
    QLedLabel *led4 = nullptr;

    ReadShmDialog * m_ReadDialog = nullptr;
    UdpHandler *m_UdpHandler = nullptr;
    QDockWidget *m_dockWidget = nullptr;
    CCU_Table * m_ccuTableHandler = nullptr;





};
#endif // MAINWINDOW_H
