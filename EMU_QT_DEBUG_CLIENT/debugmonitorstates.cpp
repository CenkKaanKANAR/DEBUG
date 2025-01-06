#include "debugmonitorstates.h"
#include <QVBoxLayout>
// debugmonitorstates.cpp


QList<int> stateCounts = {4, 4, 5, 7, 5, 5, 4, 4, 8, 4, 6, 3, 5, 6, 5, 6, 20, 14, 7, 7, 8, 7, 7, 5, 5, 7, 5, 5, 9, 9, 9, 9, 5, 5, 5, 5, 5, 5, 4, 4, 6, 6, 5, 5, 4, 4, 9, 9, 6, 6,
                          5, 5, 6, 6, 9, 9, 5, 5, 5, 6, 6, 6, 9, 9, 5, 5, 6, 6, 6, 6, 7, 4, 5, 5, 4, 2 }; // Array sizes
// Define the arrays here
const char *ssf_emu_config_states_name[] = {"INIT", "WAIT", "SINGLE", "MULTIPLE"};
const char *ssf_emu_coupled_vehicle_states_name[] = {"INIT", "WAIT", "SKA1", "SKA2"};
const char *ssf_emu_sequence_states_name[] = {"INIT", "WAIT", "HEAD_TO_TAIL", "HEAD_TO_HEAD", "TAIL_TO_TAIL"};
const char *ssf_emu_cac_states_name[] = {"INIT", "WAIT", "NO_CAB", "SKA1_ACTIVE", "SKA2_ACTIVE", "SET2_ACTIVE", "ERROR"};
const char *ssf_emu_dir_states_name[] = {"INIT", "WAIT", "NEUTRAL", "FORWARD", "REVERSE"};
const char *ssf_emu_mascon_states_name[] = {"INIT", "WAIT", "NEUTRAL", "TRACTION", "BRAKE"};
const char *ssf_ccu_location_states_name[] = {"INIT", "WAIT", "SKA1", "SKA2"};
const char *ssf_ccu_direction_states_name[] = {"INIT", "WAIT", "INWARD", "OUTWARD"};
const char *ssf_ccu_role_states_name[] = {"INIT", "WAIT", "DEFAULT_SET_MASTER", "DEFAULT_SET_REDUNDANT", "EMU_MASTER", "EMU_REDUNDANT", "FOLLOWING_SET_MASTER", "FOLLOWING_SET_REDUNDANT"};
const char *ssf_idm_reply_states_name[] = {"INIT", "WAIT", "ID_VALID", "ID_INVALID"};
const char *ssf_idm_session_states_name[] = {"INIT", "WAIT", "LOGOUT", "ID_CHECK", "LOGIN", "DDU_LOGOUT"};
const char *ssf_idm_second_card_states_name[] = {"INIT", "WAIT", "SECONDARY_ID"};
const char *ssf_idm_user_role_states_name[] = {"INIT", "WAIT", "DRIVER", "MAINTENANCE", "DEVELOPER_ADMIN"};
const char *ssf_hvm_earth_states_name[] = {"INIT", "WAIT", "ERROR", "SERVICE", "YK_EXTRACTED", "EARTH"};
const char *ssf_hvm_line_select_states_name[] = {"INIT", "WAIT", "NO_LINE", "OA1", "OA2"};
const char *ssf_hvm_usable_line_states_name[] = {"INIT", "WAIT", "ALL_USABLE", "OA1_USABLE", "OA2_USABLE", "NONE_USABLE"};
const char *ssf_hvm_reset_procedure_states_name[] = {"INIT", "WAIT", "NO_RESET", "CHECK_COND", "INIT_HV_LINE", "DR_DECIDE", "DR_PAN1_UP", "DR_MCB1_CLOSE", "CHECK_OC1", "DR_MCB1_OPEN", "DR_PAN1_DOWN", "DR_PAN2_UP", "DR_MCB2_CLOSE", "CHECK_OC2", "DR_MCB2_OPEN", "DR_PAN2_DOWN", "OC1_DETECTED", "OC_PAN1_DOWN", "OC2_DETECTED", "OC_PAN2_DOWN"};
const char *ssf_hvm_action_states_name[] = {"INIT", "WAIT", "NO_ACTION", "HVD_IN", "HVD_OUT", "PAN_IN", "PAN_MCB_OUT", "MCB_BACK_IN", "MCB_IN", "MCB_OUT", "ALL_IN", "ALL_OUT", "WAIT_MCB_OUT", "WAIT_ALL_OUT"};
const char *ssf_linm_hv_level_states_name[] = {"INIT", "WAIT", "LOWER_10KV", "LOW_HV", "RED_PWR", "NOM_PWR", "HIGH_HV"};


const char *ssf_linm_neutral_zone_states_name[] = {"INIT", "WAIT", "ETCS_CONTROL", "IN_RANGE", "ZONE_BEGIN", "CHECK_LINE", "ZONE_END"};
const char *ssf_linm_range_check_states_name[] = { "INIT", "WAIT", "IN_RANGE", "HIGH_TIMER", "OUT_OF_RANGE", "CHECK_RANGE", "RANGE_TIMER" ,"BACK_IN_RANGE" };
const char *ssf_linm_1_current_check_states_name[] = { "INIT",    "WAIT", "NORMAL",  "CHECK_ZERO", "HV_ZERO", "CHECK_SHORT", "HV_SHORT" };
const char *ssf_linm_2_current_check_states_name[] = { "INIT",    "WAIT", "NORMAL",  "CHECK_ZERO", "HV_ZERO", "CHECK_SHORT", "HV_SHORT" };
const char *ssf_hvd_select_states_name[] = { "INIT", "WAIT", "OPEN_SELECTED", "DDU_REQ_CHECK", "CLOSE_SELECTED" };
const char *ssf_hvd_confirm_states_name[] = { "INIT", "WAIT", "UNCONFIRMED", "CHECK_CONFIRM", "CONFIRMED" };
const char *ssf_hvd_config_states_name[] = { "INIT", "WAIT", "WAIT_CONFIRM", "WAIT_HVD_OPEN", "WAIT_HVD_CLOSE", "DONE","ERROR" };
const char *ssf_hvd_1_status_states_name[] = { "INIT", "WAIT", "OPENED", "CLOSED", "MOVING" };
const char *ssf_hvd_2_status_states_name[] = { "INIT", "WAIT", "OPENED", "CLOSED", "MOVING" };
const char *ssf_hvd_1_control_states_name[] = { "INIT", "WAIT", "NO_CMD", "OPEN", "OPEN_250_MS", "CLOSE", "CLOSE_250_MS", "WAIT_20_SEC", "WAIT_15_MIN" };
const char *ssf_hvd_2_control_states_name[] = { "INIT", "WAIT", "NO_CMD", "OPEN", "OPEN_250_MS", "CLOSE", "CLOSE_250_MS", "WAIT_20_SEC", "WAIT_15_MIN" };


const char *ssf_auxc_1_status_states_name[] = { "INIT", "WAIT", "NOT_READY", "READY", "CHECK_MOTOR", "RUNNING", "PRESS_OK", "TIMEOUT" , "ERROR" };
const char *ssf_auxc_2_status_states_name[] = { "INIT", "WAIT", "NOT_READY", "READY", "CHECK_MOTOR", "RUNNING", "PRESS_OK", "TIMEOUT" , "ERROR" };
const char *ssf_auxc_1_control_states_name[] = { "INIT", "WAIT", "STOP", "START", "WAIT4MIN" };
const char *ssf_auxc_2_control_states_name[] = { "INIT", "WAIT", "STOP", "START", "WAIT4MIN" };
const char *ssf_pan_1_readiness_states_name[] = { "INIT", "WAIT", "NOT_READY", "READY", "ISOLATED" };
const char *ssf_pan_2_readiness_states_name[] = { "INIT", "WAIT", "NOT_READY", "READY", "ISOLATED" };
const char *ssf_pan_1_add_status_states_name[] = { "INIT", "WAIT", "WAIT_PAN_UP", "ADD_OK", "ADD_DROP" };
const char *ssf_pan_2_add_status_states_name[] = { "INIT", "WAIT", "WAIT_PAN_UP", "ADD_OK", "ADD_DROP" };
const char *ssf_pan_1_add_control_states_name[] = { "INIT", "WAIT", "RELEASE", "HOLD" };
const char *ssf_pan_2_add_control_states_name[] = { "INIT", "WAIT", "RELEASE", "HOLD" };



const char *ssf_pan_1_status_states_name[] = { "INIT", "WAIT", "DOWN", "CHECK_UP", "UP", "UP_ERROR" };
const char *ssf_pan_2_status_states_name[] = { "INIT", "WAIT", "DOWN", "CHECK_UP", "UP", "UP_ERROR" };
const char *ssf_pan_1_control_states_name[] = { "INIT", "WAIT", "LOWER", "WAIT_PRESS", "RAISE" };
const char *ssf_pan_2_control_states_name[] = { "INIT", "WAIT", "LOWER", "WAIT_PRESS", "RAISE" };
const char *ssf_mcb_1_readiness_states_name[] = { "INIT", "WAIT", "NOT_READY", "READY" };
const char *ssf_mcb_2_readiness_states_name[] = { "INIT", "WAIT", "NOT_READY", "READY" };
const char *ssf_mcb_1_status_states_name[] = {"INIT", "WAIT", "OPENED", "CHECK_CLOSE", "CLOSE_ERROR", "CLOSED", "CHECK_OPEN", "OPEN_ERROR", "ERROR" };
const char *ssf_mcb_2_status_states_name[] = {"INIT", "WAIT", "OPENED", "CHECK_CLOSE", "CLOSE_ERROR", "CLOSED", "CHECK_OPEN", "OPEN_ERROR", "ERROR" };
const char *ssf_mcb_1_control_states_name[] = { "INIT", "WAIT", "OPEN", "CLOSE", "WARN_OPEN", "WAIT_RECLOSE" };
const char *ssf_mcb_2_control_states_name[] = { "INIT", "WAIT", "OPEN", "CLOSE", "WARN_OPEN", "WAIT_RECLOSE" };

const char *ssf_trf_1_readiness_states_name[] = { "INIT", "WAIT", "READY", "FAULT", "OUT_OF_SERVICE" };
const char *ssf_trf_2_readiness_states_name[] = { "INIT", "WAIT", "READY", "FAULT", "OUT_OF_SERVICE" };
const char *ssf_trf_1_temp_states_name[] = { "INIT", "WAIT", "NORMAL", "OVER60", "OVER90", "OVER110" };
const char *ssf_trf_2_temp_states_name[] = { "INIT", "WAIT", "NORMAL", "OVER60", "OVER90", "OVER110" };
const char *ssf_trf_1_status_states_name[] = {"INIT", "WAIT", "OFF", "LOW", "CHECK_FULL", "FULL", "CHECK_LOW", "FULL_ERROR", "LOW_ERROR" };
const char *ssf_trf_2_status_states_name[] = {"INIT", "WAIT", "OFF", "LOW", "CHECK_FULL", "FULL", "CHECK_LOW", "FULL_ERROR", "LOW_ERROR" };
const char *ssf_trf_1_control_states_name[] = { "INIT", "WAIT", "NO_CMD", "LOW_CMD", "FULL_CMD" };
const char *ssf_trf_2_control_states_name[] = { "INIT", "WAIT", "NO_CMD", "LOW_CMD", "FULL_CMD" };
const char *ssf_lvm_control_states_name[] = { "INIT", "WAIT", "LP_OFF", "LP_ON", "LAST_HOLD" };
const char *ssf_comp_select_states_name[] = { "INIT", "WAIT", "NONE", "OA1",  "OA2",  "BOTH" };
const char *ssf_comp_1_heater_states_name[] = { "INIT", "WAIT", "NO_HEAT", "INACTIVE", "PREHEAT", "HEAT" };
const char *ssf_comp_2_heater_states_name[] = { "INIT", "WAIT", "NO_HEAT", "INACTIVE", "PREHEAT", "HEAT" };
const char *ssf_comp_1_status_states_name[] = { "INIT", "WAIT", "NOT_READY", "READY", "CHECK_MOTOR", "RUNNING", "SUPPLY_ERROR", "HIGH_CURRENT", "RELAY_ERROR" };
const char *ssf_comp_2_status_states_name[] = { "INIT", "WAIT", "NOT_READY", "READY", "CHECK_MOTOR", "RUNNING", "SUPPLY_ERROR", "HIGH_CURRENT", "RELAY_ERROR" };
const char *ssf_comp_1_control_states_name[] = { "INIT", "WAIT", "STOP", "WAIT_PREHEAT", "START" };
const char *ssf_comp_2_control_states_name[] = { "INIT", "WAIT", "STOP", "WAIT_PREHEAT", "START" };


const char *ssf_ska_1_tcu_1_mcb_open_states_name[] = { "INIT", "WAIT", "OPENED_MCB", "CATENARY", "JAMMED", "UNKNOWN" };
const char *ssf_ska_1_tcu_2_mcb_open_states_name[] = { "INIT", "WAIT", "OPENED_MCB", "CATENARY", "JAMMED", "UNKNOWN" };
const char *ssf_ska_2_tcu_1_mcb_open_states_name[] = { "INIT", "WAIT", "OPENED_MCB", "CATENARY", "JAMMED", "UNKNOWN" };
const char *ssf_ska_2_tcu_2_mcb_open_states_name[] = { "INIT", "WAIT", "OPENED_MCB", "CATENARY", "JAMMED", "UNKNOWN" };
const char *ssf_park_mode_states_name[] = { "INIT", "WAIT", "OFF", "CHECK_ON", "ON", "CHECK_OFF", "ERROR" };
const char *ssf_door_close_req_states_name[] = { "INIT", "WAIT", "NO_REQ", "CLOSE" };
const char *ssf_door_right_req_states_name[] = { "INIT", "WAIT", "NO_REQ", "RELEASE_RIGHT", "OPEN_RIGHT" };
const char *ssf_door_left_req_states_name[] = { "INIT", "WAIT", "NO_REQ", "RELEASE_LEFT", "OPEN_LEFT" };
const char *ssf_door_reset_req_states_name[] = { "INIT", "WAIT", "NO_REQ", "EED_RESET" };
const char *sf_stat_states_name[] = { "INIT", "WAIT" };


DebugMonitorStates::DebugMonitorStates(QWidget *parent)
    : QWidget(parent),
    table(new QTableWidget(this)),
    openUdpMessagesButton(new QPushButton("Open UDP Messages", this)),
    udpMessagesDialog(new UdpMessagesDialog(this)),systemFunctionComboBox(new QComboBox(this)),
    stateLabel(new QLabel(this))// Her bir nesne için doğru üyelik tanımlanmalı
    //layout(new QVBoxLayout(this))
    //udpSocket(new QUdpSocket(this))

{
    // Initialize the layout
    //QVBoxLayout *layout = new QVBoxLayout(this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    setLayout(layout);  // Set the layout for the widget


    // Initialize UDP socket
    udpSocket = new QUdpSocket(this);

    //QHostAddress ipAddress("192.128.56.28");
    //quint16 port = 7000;

    connect(udpSocket, &QUdpSocket::readyRead, this, &DebugMonitorStates::onReadyRead);

    // Optionally, bind the socket to a specific port (e.g., 12345)
    udpSocket->bind(12345, QUdpSocket::ShareAddress);

    //connect(this,&DebugMonitorStates::customSignal,this,&DebugMonitorStates::updateTable,Qt::QueuedConnection);

    qDebug() << "Constructor içi";
    setupTable();  // Setup the table after setting the layout
    setupUdpDialog(); //Setup pushbutton and UDP Dialog to monitor coming udp state messages
    setupOptionSystemFunc(); //Setup combobox to view a System Function States
    // Ensure button and table are added to the layout in setupTable()



}

DebugMonitorStates::~DebugMonitorStates() {
    //delete table;
        // QWidget automatically handles child widget deletion, so no need to delete table manually
}

void DebugMonitorStates::setupTable() {

    table->setColumnCount(3);
    table->setHorizontalHeaderLabels({"Function", "Pre-State", "Current State"});
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);

    functionNames << "ssf_emu_config"
                  << "ssf_emu_coupled_vehicle"
                  << "ssf_emu_sequence"
                  << "ssf_emu_cac"
                  << "ssf_emu_dir"
                  << "ssf_emu_mascon"
                  << "ssf_ccu_location"
                  << "ssf_ccu_direction"
                  << "ssf_ccu_role"
                  << "ssf_idm_reply"
                  << "ssf_idm_session"
                  << "ssf_idm_second_card"
                  << "ssf_idm_user_role"
                  << "ssf_hvm_earth"
                  << "ssf_hvm_line_select"
                  << "ssf_hvm_usable_line"
                  << "ssf_hvm_reset_procedure"
                  << "ssf_hvm_action"
                  << "ssf_linm_hv_level"
                  << "ssf_linm_neutral_zone"
                  << "ssf_linm_range_check"
                  << "ssf_linm_1_current_check"
                  << "ssf_linm_2_current_check_"
                  << "ssf_hvd_select"
                  << "ssf_hvd_confirm"
                  << "ssf_hvd_config"
                  << "ssf_hvd_1_status"
                  << "ssf_hvd_2_status"
                  << "ssf_hvd_1_control"
                  << "ssf_hvd_2_control"
                  << "ssf_auxc_1_status"
                  << "ssf_auxc_2_status"
                  << "ssf_auxc_1_control"
                  << "ssf_auxc_2_control"
                  << "ssf_pan_1_readiness"
                  << "ssf_pan_2_readiness"
                  << "ssf_pan_1_add_status"
                  << "ssf_pan_2_add_status"
                  << "ssf_pan_1_add_control"
                  << "ssf_pan_2_add_control"
                  << "ssf_pan_1_status"
                  << "ssf_pan_2_status"
                  << "ssf_pan_1_control"
                  << "ssf_pan_2_control"
                  << "ssf_mcb_1_readiness"
                  << "ssf_mcb_2_readiness"
                  << "ssf_mcb_1_status"
                  << "ssf_mcb_2_status"
                  << "ssf_mcb_1_control"
                  << "ssf_mcb_2_control"
                  << "ssf_trf_1_readiness"
                  << "ssf_trf_2_readiness"
                  << "ssf_trf_1_temp"
                  << "ssf_trf_2_temp"
                  << "ssf_trf_1_status"
                  << "ssf_trf_2_status"
                  << "ssf_trf_1_control"
                  << "ssf_trf_2_control"
                  << "ssf_lvm_control"
                  << "ssf_comp_select"
                  << "ssf_comp_1_heater"
                  << "ssf_comp_2_heater"
                  << "ssf_comp_1_status"
                  << "ssf_comp_2_status"
                  << "ssf_comp_1_control"
                  << "ssf_comp_2_control"
                  << "ssf_ska_1_tcu_1_mcb_open"
                  << "ssf_ska_1_tcu_2_mcb_open"
                  << "ssf_ska_2_tcu_1_mcb_open"
                  << "ssf_ska_2_tcu_2_mcb_open"
                  << "ssf_park_mode"
                  << "ssf_door_close_req"
                  << "ssf_door_right_req"
                  << "ssf_door_left_req"
                  << "ssf_door_reset_req"
                  << "sf_stat"

        ;

    // Initialize table with "Unknown" values
    table->setRowCount(76);  // Adjust row count based on the number of functions
    for (int row = 0; row < 76; ++row) {  // 5 functions in total
        table->setItem(row, 0, new QTableWidgetItem(functionNames.at(row)));
        table->setItem(row,1,new QTableWidgetItem("Unknown"));
        table->setItem(row, 1, new QTableWidgetItem("Unknown"));
        table->setItem(row, 2, new QTableWidgetItem("Unknown"));
    }
    table->resizeColumnsToContents();


    // Get the layout
    //QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(this->layout());
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(this->layout());
    if (layout) {
        // Add button first, then the table

        layout->addWidget(table);
        //mainLayout->addLayout(layout);
    }

    // Create test button
    // Test button callback
    QPushButton *testButton = new QPushButton("Load Test Data", this);
    connect(testButton, &QPushButton::clicked, [this]() {
        QByteArray testData(50, 0); // 50-byte length test data

        // Test data for each function and their corresponding pre-state and current-state
        testData[40] = 0; // Pre-state for ssf_emu_config_states_name (Function 1)
        testData[41] = 3; // Current-state for ssf_emu_config_states_name
        testData[42] = 1; // Pre-state for ssf_emu_coupled_vehicle_states_name (Function 2)
        testData[43] = 2; // Current-state for ssf_emu_coupled_vehicle_states_name
        testData[44] = 0; // Pre-state for ssf_emu_sequence_states_name (Function 3)
        testData[45] = 4; // Current-state for ssf_emu_sequence_states_name
        testData[46] = 2; // Pre-state for ssf_emu_cac_states_name (Function 4)
        testData[47] = 6; // Current-state for ssf_emu_cac_states_name
        testData[48] = 3; // Pre-state for ssf_emu_dir_states_name (Function 5)
        testData[49] = 4; // Current-state for ssf_emu_dir_states_name

        testData[50] = 1; // Pre-state for ssf_emu_mascon_states_name (Function 6)
        testData[51] = 3; // Current-state for ssf_emu_mascon_states_name
        testData[52] = 2; // Pre-state for ssf_ccu_location_states_name (Function 7)
        testData[52] = 3; // Current-state for ssf_ccu_location_states_name
        testData[54] = 0; // Pre-state for ssf_ccu_direction_states_name (Function 8)
        testData[55] = 2; // Current-state for ssf_ccu_direction_states_name

        testData[56] = 2; // Pre-state for ssf_ccu_role_states_name (Function 9)
        testData[57] = 4; // Current-state for ssf_ccu_role_states_name
        testData[58] = 1; // Pre-state for ssf_idm_reply_states_name (Function 10)
        testData[59] = 3; // Current-state for ssf_idm_reply_states_name
        testData[60] = 2; // Pre-state for ssf_idm_session_states_name (Function 11)
        testData[61] = 4; // Current-state for ssf_idm_session_states_name
        qDebug() << " TEST VERİSİ" << testData;
        parseSystemStates(testData);
    });
    layout->addWidget(testButton);


}




void DebugMonitorStates::parseSystemStates(const QByteArray& recv_data) {


    int offset = 0; // First 40 bytes reserved for other purposes
    QList<SystemFunctionState> states;


    QList<const char**> stateNames = {
        ssf_emu_config_states_name,
        ssf_emu_coupled_vehicle_states_name,
        ssf_emu_sequence_states_name,
        ssf_emu_cac_states_name,
        ssf_emu_dir_states_name,
        ssf_emu_mascon_states_name,
        ssf_ccu_location_states_name,
        ssf_ccu_direction_states_name,
        ssf_ccu_role_states_name,
        ssf_idm_reply_states_name,
        ssf_idm_session_states_name,
        ssf_idm_second_card_states_name,
        ssf_idm_user_role_states_name,
        ssf_hvm_earth_states_name,
        ssf_hvm_line_select_states_name,
        ssf_hvm_usable_line_states_name,
        ssf_hvm_reset_procedure_states_name,
        ssf_hvm_action_states_name,
        ssf_linm_hv_level_states_name,
        ssf_linm_neutral_zone_states_name,
        ssf_linm_range_check_states_name,
        ssf_linm_1_current_check_states_name,
        ssf_linm_2_current_check_states_name,
        ssf_hvd_select_states_name,
        ssf_hvd_confirm_states_name,
        ssf_hvd_config_states_name,
        ssf_hvd_1_status_states_name,
        ssf_hvd_2_status_states_name,
        ssf_hvd_1_control_states_name,
        ssf_hvd_2_control_states_name,
        ssf_auxc_1_status_states_name,
        ssf_auxc_2_status_states_name,
        ssf_auxc_1_control_states_name,
        ssf_auxc_2_control_states_name,
        ssf_pan_1_readiness_states_name,
        ssf_pan_2_readiness_states_name,
        ssf_pan_1_add_status_states_name,
        ssf_pan_2_add_status_states_name,
        ssf_pan_1_add_control_states_name,
        ssf_pan_2_add_control_states_name,
        ssf_pan_1_status_states_name,
        ssf_pan_2_status_states_name,
        ssf_pan_1_control_states_name,
        ssf_pan_2_control_states_name,
        ssf_mcb_1_readiness_states_name,
        ssf_mcb_2_readiness_states_name,
        ssf_mcb_1_status_states_name,
        ssf_mcb_2_status_states_name,
        ssf_mcb_1_control_states_name,
        ssf_mcb_2_control_states_name,
        ssf_trf_1_readiness_states_name,
        ssf_trf_2_readiness_states_name,
        ssf_trf_1_temp_states_name,
        ssf_trf_2_temp_states_name,
        ssf_trf_1_status_states_name,
        ssf_trf_2_status_states_name,
        ssf_trf_1_control_states_name,
        ssf_trf_2_control_states_name,
        ssf_lvm_control_states_name,
        ssf_comp_select_states_name,
        ssf_comp_1_heater_states_name,
        ssf_comp_2_heater_states_name,
        ssf_comp_1_status_states_name,
        ssf_comp_2_status_states_name,
        ssf_comp_1_control_states_name,
        ssf_comp_2_control_states_name,
        ssf_ska_1_tcu_1_mcb_open_states_name,
        ssf_ska_1_tcu_2_mcb_open_states_name,
        ssf_ska_2_tcu_1_mcb_open_states_name,
        ssf_ska_2_tcu_2_mcb_open_states_name,
        ssf_park_mode_states_name,
        ssf_door_close_req_states_name,
        ssf_door_right_req_states_name,
        ssf_door_left_req_states_name,
        ssf_door_reset_req_states_name,
        sf_stat_states_name
    };


    QByteArray data = recv_data.mid(128,152);
    //QByteArray data = recv_data;
    // Gelen veriyi DebugMonitorStates'den gelen pencereye iletelim
    if (udpMessagesDialog) {
        udpMessagesDialog->appendMessage(data, data.size());  // Veriyi ekle
    }


    for (int i = 0; i < stateNames.size(); ++i) {
        int preStateIndex = static_cast<unsigned char>(data[offset]); // Pre-state
        int currentStateIndex = static_cast<unsigned char>(data[offset + 1]); // Current-state

        if (preStateIndex < 0 || preStateIndex >= stateCounts[i] ||
            currentStateIndex < 0 || currentStateIndex >= stateCounts[i]) {
            offset += 2;
            continue; // Invalid data
        }

        states.append({
            //QString("Function %1").arg(i + 1),
            functionNames.at(i),
            QString(stateNames[i][preStateIndex]),
            QString(stateNames[i][currentStateIndex])
        });

        offset += 2; // Advance by 2 bytes
    }
    qDebug() << "parseSystemStates son";
    qDebug() << "SIZE OF STATES :" << states.size();
    updateTable(states);


}

void DebugMonitorStates::updateTable(const QList<SystemFunctionState> &states) {

    qDebug() << "updateTable başlangıç";
    table->setRowCount(states.size());

    for (int row = 0; row < states.size(); ++row) {
        //table->setItem(row, 0, new QTableWidgetItem(states[row].functionName));
        table->setItem(row, 1, new QTableWidgetItem(states[row].preState));
        table->setItem(row, 2, new QTableWidgetItem(states[row].currentState));

        // Highlight changes
        if (states[row].preState != states[row].currentState) {
            highlightStateChange(table->item(row, 2), true);
        }
    }
     qDebug() << "updateTable son";
    table->resizeColumnsToContents();
}

void DebugMonitorStates::highlightStateChange(QTableWidgetItem *item, bool isChanged) {
    //qDebug() << "HIGHLIGHT BAŞLANGIÇ :" ;
    if (isChanged) {
        item->setBackground(Qt::yellow);
    } else {
        item->setBackground(Qt::white);
    }
}


void DebugMonitorStates::onReadyRead() {

    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        qint64 size = udpSocket->readDatagram(datagram.data(), datagram.size());

        if (size == -1) {
            qWarning() << "Error reading datagram from UDP socket!";
            return;
        }
        // Gelen veriyi DebugMonitorStates'den gelen pencereye iletelim
        if (udpMessagesDialog) {
            udpMessagesDialog->appendMessage(datagram, size);  // Veriyi ekle
        }
        qDebug() << "onReadyRead okunan veri : " << datagram;
        // Gelen veriyi parseSystemStates fonksiyonuna ilet
        parseSystemStates(datagram);
    }


}


void DebugMonitorStates::setupUdpDialog()
{

    // Get the layout
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(this->layout());
    if (layout) {
        layout->addWidget(openUdpMessagesButton);

    }

    connect(openUdpMessagesButton, &QPushButton::clicked, this, &DebugMonitorStates::openUdpMessages);



}

void DebugMonitorStates::openUdpMessages()
{
    udpMessagesDialog->exec();  // Dialog'u modal olarak açıyoruz
}

void DebugMonitorStates::setupOptionSystemFunc()
{
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(this->layout());

    // Add system functions to the combo box
    systemFunctionComboBox->addItem("SELECT A SYSTEM FUCTION");
    systemFunctionComboBox->addItem("SSF Emu Config");
    systemFunctionComboBox->addItem("SSF Emu Coupled Vehicle");
    systemFunctionComboBox->addItem("SSF Emu Sequence");
    systemFunctionComboBox->addItem("SSF Emu CAC");
    systemFunctionComboBox->addItem("SSF Emu Direction");
    systemFunctionComboBox->addItem("SSF Emu Mascon");
    systemFunctionComboBox->addItem("SSF CCU Location");
    systemFunctionComboBox->addItem("SSF CCU Direction");
    systemFunctionComboBox->addItem("SSF CCU Role");
    systemFunctionComboBox->addItem("SSF IDM Reply");
    systemFunctionComboBox->addItem("SSF IDM Session");

    systemFunctionComboBox->addItem("SSF IDM Second Card");
    systemFunctionComboBox->addItem("SSF IDM User Role");
    systemFunctionComboBox->addItem("SSF HVM Earth");
    systemFunctionComboBox->addItem("SSF HVM Line Select");
    systemFunctionComboBox->addItem("SSF HVM Usable Line");
    systemFunctionComboBox->addItem("SSF HVM Reset Procedure");
    systemFunctionComboBox->addItem("SSF HVM Action");
    systemFunctionComboBox->addItem("SSF LINM HV level");


    systemFunctionComboBox->addItem("SSF LINM Neutral Zone");
    systemFunctionComboBox->addItem("SSF LINM Range Check");
    systemFunctionComboBox->addItem("SSF LINM1 Current Check");
    systemFunctionComboBox->addItem("SSF LINM2 Current Check");
    systemFunctionComboBox->addItem("SSF HVD Select");
    systemFunctionComboBox->addItem("SSF HVD Confirm");
    systemFunctionComboBox->addItem("SSF HVD Config");
    systemFunctionComboBox->addItem("SSF HVD1 Status");
    systemFunctionComboBox->addItem("SSF HVD2 Status");
    systemFunctionComboBox->addItem("SSF HVD1 Control");
    systemFunctionComboBox->addItem("SSF HVD2 Control");

    systemFunctionComboBox->addItem("SSF AUXC1 STATUS");
    systemFunctionComboBox->addItem("SSF AUXC2 STATUS");
    systemFunctionComboBox->addItem("SSF AUXC1 CONTROL");
    systemFunctionComboBox->addItem("SSF AUXC2 CONTROL");
    systemFunctionComboBox->addItem("SSF PAN1 READINESS");
    systemFunctionComboBox->addItem("SSF PAN2 READINESS");
    systemFunctionComboBox->addItem("SSF PAN1 ADD STATUS");
    systemFunctionComboBox->addItem("SSF PAN2 ADD STATUS");
    systemFunctionComboBox->addItem("SSF PAN1 ADD CONTROL");
    systemFunctionComboBox->addItem("SSF PAN1 ADD CONTROL");

    systemFunctionComboBox->addItem("SSF PAN1 STATUS");
    systemFunctionComboBox->addItem("SSF PAN2 STATUS");
    systemFunctionComboBox->addItem("SSF PAN1 CONTROL");
    systemFunctionComboBox->addItem("SSF PAN2 CONTROL");
    systemFunctionComboBox->addItem("SSF MCB1 READINESS");
    systemFunctionComboBox->addItem("SSF MCB2 READINESS");
    systemFunctionComboBox->addItem("SSF MCB1 STATUS");
    systemFunctionComboBox->addItem("SSF MCB2 STATUS");
    systemFunctionComboBox->addItem("SSF MCB1 CONTROL");
    systemFunctionComboBox->addItem("SSF MCB2 CONTROL");

    systemFunctionComboBox->addItem("SSF TRF1 READINESS");
    systemFunctionComboBox->addItem("SSF TRF2 READINESS");
    systemFunctionComboBox->addItem("SSF TRF1 TEMP");
    systemFunctionComboBox->addItem("SSF TRF2 TEMP");
    systemFunctionComboBox->addItem("SSF TRF1 STATUS");
    systemFunctionComboBox->addItem("SSF TRF2 STATUS");
    systemFunctionComboBox->addItem("SSF TRF1 CONTROL");
    systemFunctionComboBox->addItem("SSF TRF2 CONTROL");
    systemFunctionComboBox->addItem("SSF LVM CONTROL");
    systemFunctionComboBox->addItem("SSF COMP SELECT");
    systemFunctionComboBox->addItem("SSF COMP1 HEATER");
    systemFunctionComboBox->addItem("SSF COMP2 HEATER");
    systemFunctionComboBox->addItem("SSF COMP1 STATUS CONTROL");
    systemFunctionComboBox->addItem("SSF COMP2 STATUS CONTROL");
    systemFunctionComboBox->addItem("SSF COMP1 CONTROL");
    systemFunctionComboBox->addItem("SSF COMP2 CONTROL");

    systemFunctionComboBox->addItem("SSF SKA1 TCU1 MCB OPEN");
    systemFunctionComboBox->addItem("SSF SKA1 TCU2 MCB OPEN");
    systemFunctionComboBox->addItem("SSF SKA2 TCU1 MCB OPEN");
    systemFunctionComboBox->addItem("SSF SKA2 TCU2 MCB OPEN");
    systemFunctionComboBox->addItem("SSF PARK MODE");
    systemFunctionComboBox->addItem("SSF DOOR CLOSE REQ");
    systemFunctionComboBox->addItem("SSF DOOR RIGHT REQ");
    systemFunctionComboBox->addItem("SSF DOOR LEFT REQ");
    systemFunctionComboBox->addItem("SSF DOOR RESET REQ");
    systemFunctionComboBox->addItem("SF STAT");



    // Add combo box and label to the layout
    layout->addWidget(systemFunctionComboBox);
    layout->addWidget(stateLabel);
    customizeCombobox();

    // Connect the combo box change signal to the slot
    connect(systemFunctionComboBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &DebugMonitorStates::onStateFunctionChanged);


}


//Combobox işlemleri
void DebugMonitorStates::onStateFunctionChanged(int index)
{
    QStringList states;

    switch (index) {
    case 1:  // SS Emu Config
        states = QStringList{"INIT", "WAIT", "SINGLE", "MULTIPLE"};
        break;
    case 2:  // SS Emu Coupled Vehicle
        states = QStringList{"INIT", "WAIT", "SKA1", "SKA2"};
        break;
    case 3:  // SS Emu Sequence
        states = QStringList{"INIT", "WAIT", "HEAD_TO_TAIL", "HEAD_TO_HEAD", "TAIL_TO_TAIL"};
        break;
    case 4:  // SS Emu CAC
        states = QStringList{"INIT", "WAIT", "NO_CAB", "SKA1_ACTIVE", "SKA2_ACTIVE", "SET2_ACTIVE", "ERROR"};
        break;
    case 5:  // SS Emu Direction
        states = QStringList{"INIT", "WAIT", "NEUTRAL", "FORWARD", "REVERSE"};
        break;
    case 6:  // SS Emu Mascon
        states = QStringList{"INIT", "WAIT", "NEUTRAL", "TRACTION", "BRAKE"};
        break;
    case 7:  // SS CCU Location
        states = QStringList{"INIT", "WAIT", "SKA1", "SKA2"};
        break;
    case 8:  // SS CCU Direction
        states = QStringList{"INIT", "WAIT", "INWARD", "OUTWARD"};
        break;
    case 9:  // SS CCU Role
        states = QStringList{"INIT", "WAIT", "DEFAULT_SET_MASTER", "DEFAULT_SET_REDUNDANT", "EMU_MASTER", "EMU_REDUNDANT", "FOLLOWING_SET_MASTER", "FOLLOWING_SET_REDUNDANT"};
        break;
    case 10:  // SS IDM Reply
        states = QStringList{"INIT", "WAIT", "ID_VALID", "ID_INVALID"};
        break;
    case 11:  // SS IDM Session
        states = QStringList{"INIT", "WAIT", "LOGOUT", "ID_CHECK", "LOGIN", "DDU_LOGOUT"};
        break;
    case 12:  //SSF IDM Second Card
        states = QStringList{"INIT", "WAIT", "SECONDARY_ID" };;
        break;
    case 13:  //SSF IDM User Role
        states = QStringList{"INIT", "WAIT", "DRIVER", "MAINTENANCE", "DEVELOPER_ADMIN" };;
        break;
    case 14:  //SSF HVM Earth
        states = QStringList{"INIT", "WAIT", "ERROR", "SERVICE", "YK_EXTRACTED", "EARTH"};;
        break;
    case 15:  //SSF HVM Line Select
        states = QStringList{"INIT", "WAIT", "NO_LINE", "OA1", "OA2" };
        break;
    case 16:  //SSF HVM Usable Line
        states = QStringList{"INIT",   "WAIT", "ALL_USABLE", "OA1_USABLE", "OA2_USABLE", "NONE_USABLE" };
        break;
    case 17:  //SSF HVM Reset Procedure
        states = QStringList{"INIT", "WAIT", "NO_RESET", "CHECK_COND", "INIT_HV_LINE",  "DR_DECIDE", "DR_PAN1_UP", "DR_MCB1_CLOSE", "CHECK_OC1", "DR_MCB1_OPEN", "DR_PAN1_DOWN", "DR_PAN2_UP", "DR_MCB2_CLOSE", "CHECK_OC2", "DR_MCB2_OPEN", "DR_PAN2_DOWN", "OC1_DETECTED",  "OC_PAN1_DOWN", "OC2_DETECTED", "OC_PAN2_DOWN" };
        break;
    case 18:  //SSF HVM Action
        states = QStringList{"INIT", "WAIT", "NO_ACTION", "HVD_IN", "HVD_OUT","PAN_IN", "PAN_MCB_OUT", "MCB_BACK_IN", "MCB_IN", "MCB_OUT", "ALL_IN", "ALL_OUT", "WAIT_MCB_OUT", "WAIT_ALL_OUT" };
        break;
    case 19:  // SSF LINM HV level
        states = QStringList{"INIT", "WAIT", "LOWER_10KV", "LOW_HV", "RED_PWR", "NOM_PWR", "HIGH_HV" };
        break;
    case 20: //ssf_linm_neutral_zone
        states = QStringList{"INIT", "WAIT", "ETCS_CONTROL", "IN_RANGE", "ZONE_BEGIN", "CHECK_LINE", "ZONE_END"};
        break;
    case 21: //ssf_linm_range_check
        states = QStringList{ "INIT", "WAIT", "IN_RANGE", "HIGH_TIMER", "OUT_OF_RANGE", "CHECK_RANGE", "RANGE_TIMER" ,"BACK_IN_RANGE" };
        break;
    case 22: //ssf_linm_1_current_check
        states = QStringList{ "INIT",    "WAIT", "NORMAL",  "CHECK_ZERO", "HV_ZERO", "CHECK_SHORT", "HV_SHORT" };
        break;
    case 23: //ssf_linm_2_current_check
        states = QStringList{ "INIT",    "WAIT", "NORMAL",  "CHECK_ZERO", "HV_ZERO", "CHECK_SHORT", "HV_SHORT" };
        break;
    case 24: //ssf_hvd_select
        states = QStringList{ "INIT", "WAIT", "OPEN_SELECTED", "DDU_REQ_CHECK", "CLOSE_SELECTED" };
        break;
    case 25: //ssf_hvd_confirm
        states = QStringList{ "INIT", "WAIT", "UNCONFIRMED", "CHECK_CONFIRM", "CONFIRMED" };
        break;
    case 26: //ssf_hvd_config
        states = QStringList{ "INIT", "WAIT", "WAIT_CONFIRM", "WAIT_HVD_OPEN", "WAIT_HVD_CLOSE", "DONE","ERROR" };
        break;
    case 27: //ssf_hvd_1_status
        states = QStringList{ "INIT", "WAIT", "OPENED", "CLOSED", "MOVING" };
        break;
    case 28: //ssf_hvd_2_status
        states = QStringList{ "INIT", "WAIT", "OPENED", "CLOSED", "MOVING" };
        break;
    case 29: //ssf_hvd_1_control
        states = QStringList{ "INIT", "WAIT", "NO_CMD", "OPEN", "OPEN_250_MS", "CLOSE", "CLOSE_250_MS", "WAIT_20_SEC", "WAIT_15_MIN" };
        break;
    case 30: //ssf_hvd_2_control
        states = QStringList{ "INIT", "WAIT", "NO_CMD", "OPEN", "OPEN_250_MS", "CLOSE", "CLOSE_250_MS", "WAIT_20_SEC", "WAIT_15_MIN" };
        break;
    case 31: //ssf_auxc_1_status
        states = QStringList{ "INIT", "WAIT", "NOT_READY", "READY", "CHECK_MOTOR", "RUNNING", "PRESS_OK", "TIMEOUT" , "ERROR" };
        break;
    case 32: //ssf_auxc_2_status
        states = QStringList{ "INIT", "WAIT", "NOT_READY", "READY", "CHECK_MOTOR", "RUNNING", "PRESS_OK", "TIMEOUT" , "ERROR" };
        break;
    case 33: //ssf_auxc_1_control
        states = QStringList{ "INIT", "WAIT", "STOP", "START", "WAIT4MIN" };
        break;
    case 34: //ssf_auxc_2_control
        states = QStringList{ "INIT", "WAIT", "STOP", "START", "WAIT4MIN" };
        break;
    case 35: //ssf_pan_1_readiness
        states = QStringList{ "INIT", "WAIT", "NOT_READY", "READY", "ISOLATED" };
        break;
    case 36: //ssf_pan_2_readiness
        states = QStringList{ "INIT", "WAIT", "NOT_READY", "READY", "ISOLATED" };
        break;
    case 37: //ssf_pan_1_add_status
        states = QStringList{ "INIT", "WAIT", "WAIT_PAN_UP", "ADD_OK", "ADD_DROP" };
        break;
    case 38: // ssf_pan_2_add_status
        states = QStringList{ "INIT", "WAIT", "WAIT_PAN_UP", "ADD_OK", "ADD_DROP" };
        break;
    case 39: //ssf_pan_1_add_control
        states = QStringList{ "INIT", "WAIT", "RELEASE", "HOLD" };
        break;
    case 40: //ssf_pan_2_add_control
        states = QStringList{ "INIT", "WAIT", "RELEASE", "HOLD" };
        break;
    case 41: //ssf_pan_1_status
        states = QStringList{ "INIT", "WAIT", "DOWN", "CHECK_UP", "UP", "UP_ERROR" };
        break;
    case 42: //ssf_pan_2_status
        states = QStringList{ "INIT", "WAIT", "DOWN", "CHECK_UP", "UP", "UP_ERROR" };
        break;
    case 43: //ssf_pan_1_control
        states = QStringList{ "INIT", "WAIT", "LOWER", "WAIT_PRESS", "RAISE" };
        break;
    case 44: //ssf_pan_2_control
        states = QStringList{ "INIT", "WAIT", "LOWER", "WAIT_PRESS", "RAISE" };
        break;
    case 45: //ssf_mcb_1_readiness
        states = QStringList{ "INIT", "WAIT", "NOT_READY", "READY" };
        break;
    case 46: //ssf_mcb_2_readiness
        states = QStringList{ "INIT", "WAIT", "NOT_READY", "READY" };
        break;
    case 47: //ssf_mcb_1_status
        states = QStringList{"INIT", "WAIT", "OPENED", "CHECK_CLOSE", "CLOSE_ERROR", "CLOSED", "CHECK_OPEN", "OPEN_ERROR", "ERROR" };
        break;
    case 48: //ssf_mcb_2_status
        states = QStringList{"INIT", "WAIT", "OPENED", "CHECK_CLOSE", "CLOSE_ERROR", "CLOSED", "CHECK_OPEN", "OPEN_ERROR", "ERROR" };
        break;
    case 49: //ssf_mcb_1_control
        states = QStringList{ "INIT", "WAIT", "OPEN", "CLOSE", "WARN_OPEN", "WAIT_RECLOSE" };
        break;
    case 50: //ssf_mcb_2_control
        states = QStringList{ "INIT", "WAIT", "OPEN", "CLOSE", "WARN_OPEN", "WAIT_RECLOSE" };
        break;
    case 51: //ssf_trf_1_readiness
        states = QStringList{ "INIT", "WAIT", "READY", "FAULT", "OUT_OF_SERVICE" };
        break;
    case 52: //ssf_trf_2_readiness
        states = QStringList{ "INIT", "WAIT", "READY", "FAULT", "OUT_OF_SERVICE" };
        break;
    case 53: //ssf_trf_1_temp
        states = QStringList{ "INIT", "WAIT", "NORMAL", "OVER60", "OVER90", "OVER110" };
        break;
    case 54: //ssf_trf_2_temp
        states = QStringList{ "INIT", "WAIT", "NORMAL", "OVER60", "OVER90", "OVER110" };
        break;
    case 55: //ssf_trf_1_status
        states = QStringList{ "INIT", "WAIT", "OFF", "LOW", "CHECK_FULL", "FULL", "CHECK_LOW", "FULL_ERROR", "LOW_ERROR" };
        break;
    case 56: //ssf_trf_2_status
        states = QStringList{"INIT", "WAIT", "OFF", "LOW", "CHECK_FULL", "FULL", "CHECK_LOW", "FULL_ERROR", "LOW_ERROR" };
        break;
    case 57: //ssf_trf_1_control
        states = QStringList{ "INIT", "WAIT", "NO_CMD", "LOW_CMD", "FULL_CMD" };
        break;
    case 58: //ssf_trf_2_control
        states = QStringList{ "INIT", "WAIT", "NO_CMD", "LOW_CMD", "FULL_CMD" };
        break;
    case 59: //ssf_lvm_control
        states = QStringList{ "INIT", "WAIT", "LP_OFF", "LP_ON", "LAST_HOLD" };
        break;
    case 60: //ssf_comp_select
        states = QStringList{ "INIT", "WAIT", "NONE", "OA1",  "OA2",  "BOTH" };
        break;
    case 61: //ssf_comp_1_heater
        states = QStringList{ "INIT", "WAIT", "NO_HEAT", "INACTIVE", "PREHEAT", "HEAT" };
        break;
    case 62: //ssf_comp_2_heater
        states = QStringList{ "INIT", "WAIT", "NO_HEAT", "INACTIVE", "PREHEAT", "HEAT" };
        break;
    case 63: //ssf_comp_1_status
        states = QStringList{ "INIT", "WAIT", "NOT_READY", "READY", "CHECK_MOTOR", "RUNNING", "SUPPLY_ERROR", "HIGH_CURRENT", "RELAY_ERROR" };
        break;
    case 64: //ssf_comp_2_status
        states = QStringList{ "INIT", "WAIT", "NOT_READY", "READY", "CHECK_MOTOR", "RUNNING", "SUPPLY_ERROR", "HIGH_CURRENT", "RELAY_ERROR" };
        break;
    case 65: //ssf_comp_1_control
        states = QStringList{ "INIT", "WAIT", "STOP", "WAIT_PREHEAT", "START" };
        break;
    case 66: //ssf_comp_2_control
        states = QStringList{ "INIT", "WAIT", "STOP", "WAIT_PREHEAT", "START" };
        break;
    case 67: //ssf_ska_1_tcu_1_mcb_open
        states = QStringList{ "INIT", "WAIT", "OPENED_MCB", "CATENARY", "JAMMED", "UNKNOWN" };
        break;
    case 68: //ssf_ska_1_tcu_2_mcb_open
        states = QStringList{ "INIT", "WAIT", "OPENED_MCB", "CATENARY", "JAMMED", "UNKNOWN" };
        break;
    case 69: //ssf_ska_2_tcu_1_mcb_open
        states = QStringList{ "INIT", "WAIT", "OPENED_MCB", "CATENARY", "JAMMED", "UNKNOWN" };
        break;
    case 70: //ssf_ska_2_tcu_2_mcb_open
        states = QStringList{ "INIT", "WAIT", "OPENED_MCB", "CATENARY", "JAMMED", "UNKNOWN" };
        break;
    case 71: //ssf_park_mode
        states = QStringList{ "INIT", "WAIT", "OFF", "CHECK_ON", "ON", "CHECK_OFF", "ERROR" };
        break;
    case 72: //ssf_door_close_req
        states = QStringList{ "INIT", "WAIT", "NO_REQ", "CLOSE" };
        break;
    case 73: //ssf_door_right_req
        states = QStringList{ "INIT", "WAIT", "NO_REQ", "RELEASE_RIGHT", "OPEN_RIGHT" };
        break;
    case 74: //ssf_door_left_req
        states = QStringList{ "INIT", "WAIT", "NO_REQ", "RELEASE_LEFT", "OPEN_LEFT" };
        break;
    case 75: //ssf_door_reset_req
        states = QStringList{ "INIT", "WAIT", "NO_REQ", "EED_RESET" };
        break;
    case 76: //sf_stat
        states = QStringList{ "INIT", "WAIT" };
        break;
    default:
        states = QStringList{"No states available"};
        break;
    }


    stateLabel->setText(states.join("\n"));

    int sizeOfStates = stateCounts.size();
    qDebug() << "size of states array : " << sizeOfStates;


}

void DebugMonitorStates::customizeCombobox()
{
    systemFunctionComboBox->setStyleSheet(
        "QComboBox {"
        "    border: 2px solid #5A5A5A;"
        "    border-radius: 5px;"
        "    padding: 5px;"
        "    background-color: #FFFFFF;"
        "    color: #333333;"
        "}"
        "QComboBox::drop-down {"
        "    border: 0px;"
        "    width: 30px;"
        "    background-color: #EEEEEE;"
        "}"
        "QComboBox::down-arrow {"
        "    image: url(:/icons/chevron-down-solid.svg);"
        "    width: 16px;"
        "    height: 16px;"
        "}"
        "QComboBox QAbstractItemView {"
        "    border: 1px solid #CCCCCC;"
        "    background-color: #F9F9F9;"
        "    selection-background-color: #D6D6D6;"
        "    selection-color: #000000;"
        "}"
        );
}




void DebugMonitorStates::handleUdpMessage(const QByteArray& recv_data) {

    qDebug() << "Received Udp message in Debug Monitor States :" << recv_data;
    parseSystemStates(recv_data);

}
