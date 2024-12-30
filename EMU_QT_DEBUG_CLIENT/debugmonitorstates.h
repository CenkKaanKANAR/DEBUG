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




// External declaration of global state arrays
// Declare the arrays as extern so they are available globally
/*extern const char *ssf_emu_config_states_name[];
extern const char *ssf_emu_coupled_vehicle_states_name[];
extern const char *ssf_emu_sequence_states_name[];
extern const char *ssf_emu_cac_states_name[];
extern const char *ssf_emu_dir_states_name[];
extern const char *ssf_emu_mascon_states_name[];
extern const char *ssf_ccu_location_states_name[];
extern const char *ssf_ccu_direction_states_name[];
extern const char *ssf_ccu_role_states_name[];
extern const char *ssf_idm_reply_states_name[];
extern const char *ssf_idm_session_states_name[];
extern const char *ssf_idm_second_card_states_name[];
extern const char *ssf_idm_user_role_states_name[];
extern const char *ssf_hvm_earth_states_name[];
extern const char *ssf_hvm_line_select_states_name[];
extern const char *ssf_hvm_usable_line_states_name[];
extern const char *ssf_hvm_reset_procedure_states_name[];
extern const char *ssf_hvm_action_states_name[];
extern const char *ssf_linm_hv_level_states_name[];*/

struct SystemFunctionState {
    QString functionName;   // Function name (e.g., "ssf_emu_config_states")
    QString preState;       // Previous state
    QString currentState;   // Current state
};
/*struct StateDefinition {
    QStringList stateNames;
    int stateCount;
};*/
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
    QUdpSocket *udpSocket;  // UDP soket nesnesi
    //QVBoxLayout *layout;
    //QByteArray dataIncoming = nullptr;

public slots:

    void handleUdpMessage(const QByteArray& recv_data);
private slots:
    void onReadyRead();  // UDP verisi geldiğinde çalışacak slot
    void onStateFunctionChanged(int index);

signals:
    void customSignal(const QList<SystemFunctionState> &states);
};

#endif // DEBUG_MONITOR_STATES_H

