#ifndef DEBUG_MONITOR_STATES_H
#define DEBUG_MONITOR_STATES_H

#include <QWidget>
#include <QTableWidget>
#include <QByteArray>
#include <QList>
#include <QString>
#include <QPushButton>
#include <QUdpSocket>
#include "udpmessagesdialog.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QComboBox>


struct SystemFunctionState {
    QString functionName;   // Function name (e.g., "ssf_emu_config_states")
    QString preState;       // Previous state
    QString currentState;   // Current state
};

class DebugMonitorStates : public QWidget {
    Q_OBJECT

public:
    explicit DebugMonitorStates(QWidget *parent = nullptr);
    ~DebugMonitorStates();

    void parseSystemStates(const QByteArray& recv_data);
    QStringList functionNames;


private:
    QTableWidget *table;

    void setupTable();
    void updateTable(const QList<SystemFunctionState> &states);
    void highlightStateChange(QTableWidgetItem *item, bool isChanged);
    void setupUdpDialog();
    void openUdpMessages();
    void setupOptionSystemFunc();
    void customizeCombobox();
    //QMap<int, StateDefinition> initializeStateDefinitions();
    QPushButton *openUdpMessagesButton; //Gelen udp mesajlarını gösteren buton
    UdpMessagesDialog *udpMessagesDialog; //Udp message Dialog pointerı
    QComboBox *systemFunctionComboBox;
    QLabel *stateLabel;
    QUdpSocket *udpSocket;  // UDP soket


public slots:

    void handleUdpMessage(const QByteArray& recv_data);
private slots:
    void onReadyRead();  // UDP test verisi geldiğinde çalışacak slot
    void onStateFunctionChanged(int index);

signals:
    void customSignal(const QList<SystemFunctionState> &states);
};

#endif // DEBUG_MONITOR_STATES_H

