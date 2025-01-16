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
#include <vector>
#include <string>


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
    QList<int> stateCounts;
    std::vector<std::string> ssf_emu_config_states_name;
    std::vector<std::string> ssf_emu_coupled_vehicle_states_name ;
    std::vector<std::string> ssf_emu_sequence_states_name ;
    std::vector<std::string> ssf_emu_cac_states_name ;
    std::vector<std::string> ssf_emu_dir_states_name ;
    std::vector<std::string> ssf_emu_mascon_states_name ;
    std::vector<std::string> ssf_emu_pan_1_up_cmd_states_name ;
    std::vector<std::string> ssf_emu_pan_2_up_cmd_states_name ;
    std::vector<std::string> ssf_emu_mcb_close_cmd_states_name ;
    std::vector<std::string> ssf_bcu_wsp_test_states_name;
    std::vector<std::string> ssf_ccu_location_states_name ;
    std::vector<std::string> ssf_ccu_direction_states_name ;
    std::vector<std::string> ssf_ccu_role_states_name ;
    std::vector<std::string> ssf_apu_1_enable_states_name ;
    std::vector<std::string> ssf_apu_2_enable_states_name;
    std::vector<std::string> ssf_apu_1_reset_states_name ;
    std::vector<std::string> ssf_apu_2_reset_states_name ;
    std::vector<std::string> ssf_auxc_1_status_states_name ;
    std::vector<std::string> ssf_auxc_2_status_states_name ;
    std::vector<std::string> ssf_auxc_1_control_states_name ;
    std::vector<std::string> ssf_auxc_2_control_states_name ;
    std::vector<std::string> ssf_park_mode_states_name ;
    std::vector<std::string> ssf_hvd_select_states_name ;
    std::vector<std::string> ssf_hvd_confirm_states_name ;
    std::vector<std::string> ssf_hvd_config_states_name;
    std::vector<std::string> ssf_hvd_1_status_states_name ;
    std::vector<std::string> ssf_hvd_2_status_states_name ;
    std::vector<std::string> ssf_hvd_1_control_states_name;
    std::vector<std::string> ssf_hvd_2_control_states_name;
    std::vector<std::string> ssf_idm_1_reply_states_name ;
    std::vector<std::string> ssf_idm_2_reply_states_name  ;
    std::vector<std::string> ssf_idm_session_states_name ;
    std::vector<std::string> ssf_idm_second_card_states_name ;
    std::vector<std::string> ssf_idm_user_role_states_name;
    std::vector<std::string> ssf_pan_1_readiness_states_name ;
    std::vector<std::string> ssf_pan_2_readiness_states_name ;
    std::vector<std::string> ssf_pan_1_add_status_states_name ;
    std::vector<std::string> ssf_pan_2_add_status_states_name ;
    std::vector<std::string> ssf_pan_1_add_control_states_name ;
    std::vector<std::string> ssf_pan_2_add_control_states_name ;
    std::vector<std::string> ssf_pan_1_status_states_name ;
    std::vector<std::string> ssf_pan_2_status_states_name ;
    std::vector<std::string> ssf_pan_1_control_states_name ;
    std::vector<std::string> ssf_pan_2_control_states_name ;
    std::vector<std::string> ssf_mcb_1_readiness_states_name ;
    std::vector<std::string> ssf_mcb_2_readiness_states_name ;
    std::vector<std::string> ssf_mcb_1_status_states_name ;
    std::vector<std::string> ssf_mcb_2_status_states_name ;
    std::vector<std::string> ssf_mcb_1_control_states_name ;
    std::vector<std::string> ssf_mcb_2_control_states_name ;
    std::vector<std::string> ssf_door_close_req_states_name ;
    std::vector<std::string> ssf_door_right_req_states_name ;
    std::vector<std::string> ssf_door_left_req_states_name ;
    std::vector<std::string> ssf_door_reset_req_states_name ;
    std::vector<std::string> ssf_ska_1_tcu_1_mcb_open_states_name;
    std::vector<std::string> ssf_ska_1_tcu_2_mcb_open_states_name;
    std::vector<std::string> ssf_ska_2_tcu_1_mcb_open_states_name;
    std::vector<std::string> ssf_ska_2_tcu_2_mcb_open_states_name;
    std::vector<std::string> ssf_ska_1_tcu_1_enable_states_name ;
    std::vector<std::string> ssf_ska_1_tcu_2_enable_states_name ;
    std::vector<std::string> ssf_ska_2_tcu_1_enable_states_name ;
    std::vector<std::string> ssf_ska_2_tcu_2_enable_states_name ;
    std::vector<std::string> ssf_ska_1_tcu_1_reset_states_name ;
    std::vector<std::string> ssf_ska_1_tcu_2_reset_states_name ;
    std::vector<std::string> ssf_ska_2_tcu_1_reset_states_name ;
    std::vector<std::string> ssf_ska_2_tcu_2_reset_states_name ;
    std::vector<std::string> ssf_linm_hv_level_states_name;
    std::vector<std::string> ssf_linm_neutral_zone_states_name ;
    std::vector<std::string> ssf_linm_range_check_states_name;
    std::vector<std::string> ssf_linm_1_current_check_states_name;
    std::vector<std::string> ssf_linm_2_current_check_states_name ;
    std::vector<std::string> ssf_comp_select_states_name  ;
    std::vector<std::string> ssf_comp_1_heater_states_name ;
    std::vector<std::string> ssf_comp_2_heater_states_name ;
    std::vector<std::string> ssf_comp_1_status_states_name ;
    std::vector<std::string> ssf_comp_2_status_states_name ;
    std::vector<std::string> ssf_comp_1_control_states_name ;
    std::vector<std::string> ssf_comp_2_control_states_name ;
    std::vector<std::string> ssf_sand_enable_states_name  ;
    std::vector<std::string> ssf_sand_dry_states_name;
    std::vector<std::string> ssf_sand_1_heater_states_name ;
    std::vector<std::string> ssf_sand_2_heater_states_name ;
    std::vector<std::string> ssf_sand_control_states_name ;
    std::vector<std::string> ssf_sand_test_states_name ;
    std::vector<std::string> ssf_sand_level_test_states_name ;
    std::vector<std::string> ssf_lvm_control_states_name ;
    std::vector<std::string> ssf_trf_1_readiness_states_name ;
    std::vector<std::string> ssf_trf_2_readiness_states_name ;
    std::vector<std::string> ssf_trf_1_temp_states_name ;
    std::vector<std::string> ssf_trf_2_temp_states_name;
    std::vector<std::string> ssf_trf_1_status_states_name ;
    std::vector<std::string> ssf_trf_2_status_states_name ;
    std::vector<std::string> ssf_trf_1_control_states_name ;
    std::vector<std::string> ssf_trf_2_control_states_name;
    std::vector<std::string> ssf_hvm_earth_states_name ;
    std::vector<std::string> ssf_hvm_line_select_states_name ;
    std::vector<std::string> ssf_hvm_usable_line_states_name ;
    std::vector<std::string> ssf_hvm_reset_procedure_states_name ;
    std::vector<std::string> ssf_hvm_action_states_name ;
    std::vector<std::string> ssf_susp_fault_lamp_states_name ;
    std::vector<std::string> sf_stat_states_name;                                                                                                                                                                                                                                                                                                                         ;


    //STATE NAMES
    QList<std::vector<std::string>> stateNames ;

private:
    QTableWidget *table;

    void setupTable();
    void updateTable(const QList<SystemFunctionState> &states);
    void highlightStateChange(QTableWidgetItem *item, bool isChanged);
    void initVectors();
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

