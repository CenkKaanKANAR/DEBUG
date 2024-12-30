// Header File: SystemFunctionManager.h
#ifndef SYSTEMFUNCTIONMANAGER_H
#define SYSTEMFUNCTIONMANAGER_H

#include <QWidget>
#include <QTableWidget>
#include <QUdpSocket>
#include <QMap>

enum class ssf_linm_range_check_states_name {INIT,
                                             WAIT,
                                             IN_RANGE,
                                             HIGH_TIMER,
                                             OUT_OF_RANGE,
                                             CHECK_RANGE,
                                             RANGE_TIMER,
                                             BACK_IN_RANGE };
class SystemFunctionState {

public:
    QString m_preState = "UNKNOWN";
    QString m_currentState = "UNKNOWN";
};

class SystemFunctionManager : public QWidget {
    Q_OBJECT

public:
    explicit SystemFunctionManager(QWidget *parent = nullptr);
    ~SystemFunctionManager();

private:
    void initializeTable();
    void updateTable(const QList<int>& states);

private slots:
    void processPendingDatagrams();

private:
    QUdpSocket *udpSocket;
    QTableWidget *tableWidget;
    QMap<int, QString> stateMapping; // Mapping from state codes to names
    QMap<QString, SystemFunctionState> systemFunctions; // Tracks pre-state and current-state for each function
    SystemFunctionState *systemFunc1;
    SystemFunctionState *systemFunc2;
};

#endif // SYSTEMFUNCTIONMANAGER_H
