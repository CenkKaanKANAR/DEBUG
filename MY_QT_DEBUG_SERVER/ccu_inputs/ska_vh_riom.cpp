#include "ska_vh_riom.h"
#include "utils.h"


SKA_VH_RIOM::SKA_VH_RIOM(QObject *parent)
    : QObject{parent}
{
    memset(m_ska_x_vh_riom, 0, sizeof(m_ska_x_vh_riom));
    init_inputs_table(SKA_VEHICLE_NUM::SKA1);
    init_inputs_table(SKA_VEHICLE_NUM::SKA2);

    init_status_table(SKA_VEHICLE_NUM::SKA1);
    init_status_table(SKA_VEHICLE_NUM::SKA2);
    make_signal_slot_connection();

}

SKA_VH_RIOM::~SKA_VH_RIOM()
{
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            delete m_tableWidget[i][j];
            m_tableWidget[i][j] = nullptr; // Güvenlik için nullptr atayın
        }
    }
}

void SKA_VH_RIOM::init_inputs_table(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_inputs_map[ska_num][MVB1] = {
        {"MANUALPOWER_SUPPLY_PRIVILEGED_LOAD_Lp", 0},
        {"CONTACTOR_PRIVILEGE_LOAD_Lp",0},
        {"DRIVER_LOAD_SELECTOR_ON",0},
        {"PLANT_3_0_CB_PROTECTION",0},
        {"CONTACTOR_MAINTENANCE_SKA_CAR", 0},
        {"VACUUM_OPENING_BY_PASS",0},
        {"FAST_OPEN_VCB",0},
        {"PLANT_3_1_CB_PROTECTION",0},
        {"PLANT_3_2_CB_PROTECTION",0},
        {"FAST_OPEN_ADD",0},
        {"TRAIN_KEY_DRIVER_DESK",0},
        {"RELAY_KEY_DRIVER_DESK_ECDD",0},
        {"COUPLED_TRAIN_TAIL_RELAY",0},
        {"PLANT_3_5_CB_PROTECTION",0},
        {"MV_OUTPUT_MOTOR_1_OK_TC_1",0},
        {"MV_OUTPUT_MOTOR_2_OK_TC_1",0},
        {"HV_PRESENCE_TO_TRACTION_TC_1",0},
        {"DEVICE_ID_DI_0",0},
        {"DEVICE_ID_DI_1",0},
        {"DEVICE_ID_DI_2",0},
        {"DEVICE_ID_DI_3",0},
        {"DEVICE_ID_DI_4",0},
        {"DEVICE_ID_DI_5",0},
        {"CABINET_TEST_HW_OK_HEALT_RIOM_2",0},
        {"TRACTION_OK_2_TC_1",0},
        {"VCB_LOOP_OUT_TC_1",0},
        {"TRACTION_ACTIVE_RELAY_TC_1",0},
        {"EDB_BRAKE_ACTIVE_TC_1",0},
        {"CFIR_TC_1",0},
        {"SYSTEM_RESET_TC_1",0},
        {"MV_OUTPUT_MOTOR_3_OK_TC_2",0},
        {"MV_OUTPUT_MOTOR_4_OK_TC_2",0},
        {"HV_PRESENCE_TO_TRACTION_TC_2",0},
        {"TRACTION_DC_LINK_OK_TC_2",0},
        {"PANTOGRAPH_PERMISSION_TC_2",0},
        {"TRACTION_OK_4_TC_2",0},
        {"TRACTION_OK_3_TC_2",0},
        {"VCB_LOOP_OUT_TC_2",0},
        {"TRACTION_ACTIVE_RELAY_TC_2",0},
        {"EDB_BRAKE_ACTIVE_TC_2",0},
        {"CFIR_TC_2",0},
        {"SYSTEM_RESET_TC_2",0},
        {"VENTILATION_TRACTION_CONVERTER_CB_PROTECTION",0},
        {"SL_CUT_OFF_BYPASS",0},
        {"TRACTION_OK_1_TC_1",0},
        {"CONTACTOR_2_1_NORMAL_LOAD_Ln",0},
        {"TRACTION_DC_LINK_OK_TC_1",0},
        {"PANTOGRAPH_PERMISSION_TC_1",0},
        {"TRACTION_CUT_OFF_LOOP",0},
        {"PLANT_3_7_CB_PROTECTION",0},
        {"HVAC_1_FLOOR_HEATER_1_START",0},
        {"HVAC_1_FLOOR_HEATER_2_START",0},
        {"HVAC_1_CB_PROTECTION",0},
        {"HVAC_2_FLOOR_HEATER_1_START",0},
        {"HVAC_2_FLOOR_HEATER_2_START",0},
        {"HVAC_2_CB_PROTECTION",0},
        {"HVAC_1_ON_INPUT",0},
        {"HVAC_2_ON_INPUT",0},
        {"HVAC_CAB_CB_PROTECTION",0},
        {"THERMOSTAT_HEATING_LEFT_SIDE",0},
        {"CONTACTOR_HEATING_COMPARTMENT_LEFT_SIDE",0},
        {"HEATING_COMPARTMENT_LEFT_SIDE_CB_PROTECTION",0},
        {"THERMOSTAT_HEATING_RIGHT_SIDE",0},
        {"CONTACTOR_HEATING_COMPARTMENT_RIGHT_SIDE",0},
        {"HEATING_COMPARTMENT_RIGHT_SIDE_CB_PROTECTION",0},
        {"PLANT_4_0_CB_PROTECTION",0},
        {"PRESSURE_GOVERNOR_BP_NO_EMERGENCY_BRAKE",0},
        {"PRESSURE_GOVERNOR_PB_RELEASED",0},
        {"bit68",0},
        {"bit69",0},
        {"bit70",0},
        {"bit71",0},
        {"PRESSURE_GOVERNOR_R_CPRESS_APPL_BO1",0},
        {"PRESSURE_GOVERNOR_R_CPRESS_APPL_BO2",0},
        {"ISOLATION_COCKS_PNEUMATIC_BRAKE",0},
        {"ISOLATION_COCKS_DIRECT_BRAKE",0},
        {"ISOLATION_COCKS_INDIRECT_BRAKE",0},
        {"ISOLATION_COCKS_DIRECT_BRAKE_BO1",0},
        {"ISOLATION_COCKS_DIRECT_BRAKE_BO2",0},
        {"ISOLATION_COCKS_PB_ISOLATED",0},
        {"ISOLATION_COCKS_SAND_ISOLATED",0},
        {"AIR_SUSPENSION_STATUSS",0},
        {"BYPASS_MRP_ISOLATION_COCK",0},
        {"EBCU_C_FCTOK",0},
        {"EBCU_SPEED_10_Km_H",0},
        {"PRESSURE_GOVERNORS_EB_DETECTION",0},
        {"PRESSURE_GOVERNORS_FSB_DETECTION",0},
        {"PRESSURE_GOVERNORS_INDIRECT_BRAKE_NOT_RELEASE",0},
        {"PRESSURE_GOVERNORS_AIR_SUSPENSION_BO1",0},
        {"PRESSURE_GOVERNORS_AIR_SUSPENSION_BO2",0},
        {"ISOLATION_COCKS_BP_TO_MRP_BYPASS",0},
        {"ZERO_SPEED",0},
        {"EMERGENCY_BRAKE_FROM_BCU",0},
        {"WSP_R_vGt5kmhDoor",0},
        {"FDU_GENERAL_FAULT",0},
        {"FDU_GENERAL_FIRE",0},
        {"ZERO_SPEED_BY_PASS",0},
        {"PLANT_4_5_CB_PROTECTION",0},
        {"ALARM_PASSENGERS_CB_PROTECTION",0},
        {"RELAY_ALARM_PASSENGERS",0},
        {"RELAY_SECURITY_EMERGENCY_LOOP_CB_PROTECTION",0},
        {"EMERGENCY_BRAKE_CB_PROTECTION",0},
        {"SELECTOR_BY_PASS_PASSANGER_ALARM",0},
        {"INIBITION_PASSENGERS_ALARM_ACTIVE",0},
        {"HANDLE_1_PASSENGER_ALARM",0},
        {"HANDLE_3_PASSENGER_ALARM",0},
        {"HANDLE_5_PASSENGER_ALARM",0},
        {"HANDLE_7_PASSENGER_ALARM",0},
        {"HANDLE_2_PASSENGER_ALARM",0},
        {"HANDLE_4_PASSENGER_ALARM",0},
        {"HANDLE_6_PASSENGER_ALARM",0},
        {"HANDLE_8_PASSENGER_ALARM",0},
        {"RELAY_SECURITY_EMERGENCY_LOOP",0},
        {"RELAY_TRACTION_EMERGENCY_BRAKE",0},
        {"SL_DEAD_MAN_BYPASS",0},
        {"PLANT_4_7_CB_PROTECTION",0},
        {"CABINET_RIOM_1_CB_PROTECTION",0},
        {"BCU_ZERO_SPEED",0},
        {"FIRE_EXTINGUISHER_1_PRESENCE",0},
        {"FIRE_EXTINGUISHER_2_PRESENCE",0},
        {"SIFA_POSITION_HANDLE",0},
        {"SIFA_TRACTION_CONTROL",0},
        {"SAND_LEVEL_SENSOR_BOGIE_1_BEARING_RIGHT",0},
        {"SAND_LEVEL_SENSOR_BOGIE_1_BEARING_LEFT",0},
        {"SAND_LEVEL_SENSOR_BOGIE_2_BEARING_RIGHT",0},
        {"SAND_LEVEL_SENSOR_BOGIE_2_BEARING_LEFT",0},
        {"HORN_1_ISOLATION_COCK",0},
        {"HORN_2_ISOLATION_COCK",0},
        {"PLANT_4_8_CB_PROTECTION",0},
        {"DOOR_1_FULLY_OPENED",0},
        {"DOOR_2_FULLY_OPENED",0},
        {"DOOR_3_FULLY_OPENED",0},
        {"DOOR_4_FULLY_OPENED",0},
        {"DOOR_5_FULLY_OPENED",0},
        {"DOOR_6_FULLY_OPENED",0},
        {"DOOR_7_FULLY_OPENED",0},
        {"DOOR_8_FULLY_OPENED",0},
        {"CLOSING_HATCH",0},
        {"OPENING_HATCH",0},
        {"HATCH_BYBASS",0},
        {"CABINET_RIOM_2_CB_PROTECTION",0},
        {"ETHERNET_SWITCH_1_PAPIS_ALARM",0},
        {"ETHERNET_SWITCH_2_PAPIS_ALARM",0},
        {"bit143",0},
        {"ETCS_EQUIPMENT_POWER_SUPPLY_APPLIED",0},
        {"RELAY_CONTROL_DOORS_LOOP",0},
        {"SL_DOORS_LOOP_BY_PASS",0},
        {"PLANT_5_3_CB_PROTECTION",0},
        {"PLANT_5_5_CB_PROTECTION",0},
        {"DC_DC_OK_ANTIFIRE_SYSTEM",0},
        {"PLANT_6_0_CB_PROTECTION",0},
        {"PLANT_6_5_CB_PROTECTION",0},
        {"INTERNAL_LIGHT_ON_COMMAND",0},
        {"INTERNAL_HALF_LIGHT_COMMAND",0},
        {"INTERNAL_LIGHT_EMERGENCY_COMMAND",0},
        {"PLANT_7_0_CB_PROTECTION",0},
        {"PLANT_7_2_CB_PROTECTION",0},
        {"AUTOMATIC_EXTERNAL_LIGHT_COMMAND",0},
        {"SL_ETCS_BY_PASS",0},
        {"SL_DOORS_SIDE_CONTROL_ETCS_BYPASS",0},
        {"GSM_R_RADIO_DIAGNOSTIC_INFORMATION",0},
        {"GSM_R_RADIO_VOICE",0},
        {"ATS_BYPASS",0},
        {"PLANT_7_7_CB_PROTECTION",0},
        {"PLANT_7_8_CB_PROTECTION",0},
        {"CONTROL_UNIT_RADIO_THALES_CB_PROTECTION",0},
        {"CB_PROTECTION_AXLE_BOX",0},
        {"bit167",0},
        {"spare_21",0},
        {"spare_22",0},
        {"spare_23",0},
        {"spare_24",0},
        {"spare_25",0},
        {"spare_26",0},
        {"spare_27",0},
        {"spare_28",0},
        {"spare_29",0},
        {"spare_30",0},
        {"spare_31",0}
    };

    QStringList table_name = {"ska_1_vh_riom_ccu_mvb1_d_inputs", "value"};

    //m_tableWidget.push_back(new QTableWidget());
    m_tableWidget[ska_num][MVB1] = new QTableWidget();
    m_tableWidget[ska_num][MVB1] ->setColumnCount(2);
    m_tableWidget[ska_num][MVB1] ->setRowCount(m_inputs_map[ska_num][MVB1].size());
    m_tableWidget[ska_num][MVB1]->setHorizontalHeaderLabels(table_name);

    int row = 0;
    for (const auto& pair:  m_inputs_map[ska_num][MVB1]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[ska_num][MVB1]->setItem(row, 0, item_name);
        m_tableWidget[ska_num][MVB1]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[ska_num][MVB1]->resizeColumnsToContents();
}








void SKA_VH_RIOM::init_status_table(SKA_VEHICLE_NUM ska_x_num)
{

    int ska_num = static_cast<int>(ska_x_num);

    m_inputs_map[ska_num][STATUS0] = {

    {"lifesign",0},
        {"DIO01_Module_Error",0},
        {"DIO01_Output_Overcurrent",0},
        {"DIO01_Heartbeat_error",0},
        {"DIO01_Group_1_Voltage_error",0},
        {"DIO01_Group_2_Voltage_error",0},
        {"DIO01_Board_Temperature_error",0},
        {"bit22",0},
        {"bit23",0},
        {"DIO02_Module_Error",0},
        {"DIO02_Output_Overcurrent",0},
        {"DIO02_Heartbeat_error",0},
        {"DIO02_Group_1_Voltage_error",0},
        {"DIO02_Group_2_Voltage_error",0},
        {"DIO02_Board_Temperature_error",0},
        {"bit30",0},
        {"bit31",0},
        {"DIO03_Module_Error",0},
        {"DIO03_Output_Overcurrent",0},
        {"DIO03_Heartbeat_error",0},
        {"DIO03_Group_1_Voltage_error",0},
        {"DIO03_Group_2_Voltage_error",0},
        {"DIO03_Board_Temperature_error",0},
        {"bit38",0},
        {"bit39",0},
        {"DIO04_Module_Error",0},
        {"DIO04_Output_Overcurrent",0},
        {"DIO04_Heartbeat_error",0},
        {"DIO04_Group_1_Voltage_error",0},
        {"DIO04_Group_2_Voltage_error",0},
        {"DIO04_Board_Temperature_error",0},
        {"bit46",0},
        {"bit47",0},
        {"DIO05_Module_Error",0},
        {"DIO05_Output_Overcurrent",0},
        {"DIO05_Heartbeat_error",0},
        {"DIO05_Group_1_Voltage_error",0},
        {"DIO05_Group_2_Voltage_error",0},
        {"DIO05_Board_Temperature_error",0},
        {"bit54",0},
        {"bit55",0},
        {"DIO06_Module_Error",0},
        {"DIO06_Output_Overcurrent",0},
        {"DIO06_Heartbeat_error",0},
        {"DIO06_Group_1_Voltage_error",0},
        {"DIO06_Group_2_Voltage_error",0},
        {"DIO06_Board_Temperature_error",0},
        {"bit62",0},
        {"bit63",0},
        {"DIO07_Module_Error",0},
        {"DIO07_Output_Overcurrent",0},
        {"DIO07_Heartbeat_error",0},
        {"DIO07_Group_1_Voltage_error",0},
        {"DIO07_Group_2_Voltage_error",0},
        {"DIO07_Board_Temperature_error",0},
        {"bit70",0},
        {"bit71",0},
        {"reserved_9",0},
        {"reserved_10",0},
        {"reserved_11",0},
        {"reserved_12",0},
        {"R1_DCU_CANopen_Fault",0},
        {"R2_DCU_CANopen_Fault",0},
        {"R3_DCU_CANopen_Fault",0},
        {"R4_DCU_CANopen_Fault",0},
        {"L1_DCU_CANopen_Fault",0},
        {"L2_DCU_CANopen_Fault",0},
        {"L3_DCU_CANopen_Fault",0},
        {"L4_DCU_CANopen_Fault",0},
        {"FDS_CANopen_Fault",0},
        {"ATS_CANopen_Fault",0},
        {"PAPIS_CANopen_Fault",0},
        {"HVAC_C_CANopen_Fault",0},
        {"HVAC_1_CANopen_Fault",0},
        {"HVAC_2_CANopen_Fault",0},
        {"bit118",0},
        {"bit119",0},
    {"reserved_15",0}


};



QStringList table_name = {"ska_1_dd_riom_ccu_mvb_status", "value"};

//m_tableWidget.push_back(new QTableWidget());
m_tableWidget[ska_num][STATUS0] = new QTableWidget();
m_tableWidget[ska_num][STATUS0] ->setColumnCount(2);
m_tableWidget[ska_num][STATUS0] ->setRowCount(m_inputs_map[ska_num][MVB1].size());
m_tableWidget[ska_num][STATUS0]->setHorizontalHeaderLabels(table_name);

int row = 0;
for (const auto& pair:  m_inputs_map[ska_num][STATUS0]) {
    QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
    QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
    m_tableWidget[ska_num][STATUS0]->setItem(row, 0, item_name);
    m_tableWidget[ska_num][STATUS0]->setItem(row, 1, item_val);
    //m_tableWidget->item(row, 0)->setText(QString(pair.first));
    //m_tableWidget->item(row, 1)->setText(QString(pair.second));
    ++row;
}
// Resize the table widget contents
m_tableWidget[ska_num][STATUS0]->resizeColumnsToContents();


}




void SKA_VH_RIOM::update_inputs_map(SKA_VEHICLE_NUM ska_x_num)
{

    int ska_num = static_cast<int>(ska_x_num);

    m_inputs_map[ska_num][MVB1].at("MANUALPOWER_SUPPLY_PRIVILEGED_LOAD_Lp")           =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.MANUALPOWER_SUPPLY_PRIVILEGED_LOAD_Lp;
    m_inputs_map[ska_num][MVB1].at("CONTACTOR_PRIVILEGE_LOAD_Lp")                     =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CONTACTOR_PRIVILEGE_LOAD_Lp;
    m_inputs_map[ska_num][MVB1].at("DRIVER_LOAD_SELECTOR_ON")                         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DRIVER_LOAD_SELECTOR_ON;
    m_inputs_map[ska_num][MVB1].at("PLANT_3_0_CB_PROTECTION")                         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_3_0_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("CONTACTOR_MAINTENANCE_SKA_CAR")                   =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CONTACTOR_MAINTENANCE_SKA_CAR;
    m_inputs_map[ska_num][MVB1].at("VACUUM_OPENING_BY_PASS")                          =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.VACUUM_OPENING_BY_PASS;
    m_inputs_map[ska_num][MVB1].at("FAST_OPEN_VCB")                                   =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.FAST_OPEN_VCB;
    m_inputs_map[ska_num][MVB1].at("PLANT_3_1_CB_PROTECTION")                         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_3_1_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("PLANT_3_2_CB_PROTECTION")                         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_3_2_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("FAST_OPEN_ADD")                                   =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.FAST_OPEN_ADD;
    m_inputs_map[ska_num][MVB1].at("TRAIN_KEY_DRIVER_DESK")                           =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.TRAIN_KEY_DRIVER_DESK;
    m_inputs_map[ska_num][MVB1].at("RELAY_KEY_DRIVER_DESK_ECDD")                      =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.RELAY_KEY_DRIVER_DESK_ECDD;
    m_inputs_map[ska_num][MVB1].at("COUPLED_TRAIN_TAIL_RELAY")                        =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.COUPLED_TRAIN_TAIL_RELAY;
    m_inputs_map[ska_num][MVB1].at("PLANT_3_5_CB_PROTECTION")                         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_3_5_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("MV_OUTPUT_MOTOR_1_OK_TC_1")                       =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.MV_OUTPUT_MOTOR_1_OK_TC_1;
    m_inputs_map[ska_num][MVB1].at("MV_OUTPUT_MOTOR_2_OK_TC_1")                       =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.MV_OUTPUT_MOTOR_2_OK_TC_1;
    m_inputs_map[ska_num][MVB1].at("HV_PRESENCE_TO_TRACTION_TC_1")                    =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HV_PRESENCE_TO_TRACTION_TC_1;
    m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_0")                                  =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DEVICE_ID_DI_0;
    m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_1")                                  =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DEVICE_ID_DI_1;
    m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_2")                                  =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DEVICE_ID_DI_2;
    m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_3")                                  =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DEVICE_ID_DI_3;
    m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_4")                                  =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DEVICE_ID_DI_4;
    m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_5")                                  =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DEVICE_ID_DI_5;
    m_inputs_map[ska_num][MVB1].at("CABINET_TEST_HW_OK_HEALT_RIOM_2")                 =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CABINET_TEST_HW_OK_HEALT_RIOM_2;
    m_inputs_map[ska_num][MVB1].at("TRACTION_OK_2_TC_1")                              =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.TRACTION_OK_2_TC_1;
    m_inputs_map[ska_num][MVB1].at("VCB_LOOP_OUT_TC_1")                               =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.VCB_LOOP_OUT_TC_1;
    m_inputs_map[ska_num][MVB1].at("TRACTION_ACTIVE_RELAY_TC_1")                      =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.TRACTION_ACTIVE_RELAY_TC_1;
    m_inputs_map[ska_num][MVB1].at("EDB_BRAKE_ACTIVE_TC_1")                           =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.EDB_BRAKE_ACTIVE_TC_1;
    m_inputs_map[ska_num][MVB1].at("CFIR_TC_1")                                       =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CFIR_TC_1;
    m_inputs_map[ska_num][MVB1].at("SYSTEM_RESET_TC_1")                               =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SYSTEM_RESET_TC_1;
    m_inputs_map[ska_num][MVB1].at("MV_OUTPUT_MOTOR_3_OK_TC_2")                       =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.MV_OUTPUT_MOTOR_3_OK_TC_2;
    m_inputs_map[ska_num][MVB1].at("MV_OUTPUT_MOTOR_4_OK_TC_2")                       =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.MV_OUTPUT_MOTOR_4_OK_TC_2;
    m_inputs_map[ska_num][MVB1].at("HV_PRESENCE_TO_TRACTION_TC_2")                    =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HV_PRESENCE_TO_TRACTION_TC_2;
    m_inputs_map[ska_num][MVB1].at("TRACTION_DC_LINK_OK_TC_2")                        =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.TRACTION_DC_LINK_OK_TC_2;
    m_inputs_map[ska_num][MVB1].at("PANTOGRAPH_PERMISSION_TC_2")                      =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PANTOGRAPH_PERMISSION_TC_2;
    m_inputs_map[ska_num][MVB1].at("TRACTION_OK_4_TC_2")                              =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.TRACTION_OK_4_TC_2;
    m_inputs_map[ska_num][MVB1].at("TRACTION_OK_3_TC_2")                              =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.TRACTION_OK_3_TC_2;
    m_inputs_map[ska_num][MVB1].at("VCB_LOOP_OUT_TC_2")                               =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.VCB_LOOP_OUT_TC_2;
    m_inputs_map[ska_num][MVB1].at("TRACTION_ACTIVE_RELAY_TC_2")                      =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.TRACTION_ACTIVE_RELAY_TC_2;
    m_inputs_map[ska_num][MVB1].at("EDB_BRAKE_ACTIVE_TC_2")                           =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.EDB_BRAKE_ACTIVE_TC_2;
    m_inputs_map[ska_num][MVB1].at("CFIR_TC_2")                                       =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CFIR_TC_2;
    m_inputs_map[ska_num][MVB1].at("SYSTEM_RESET_TC_2")                               =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SYSTEM_RESET_TC_2;
    m_inputs_map[ska_num][MVB1].at("VENTILATION_TRACTION_CONVERTER_CB_PROTECTION")    =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.VENTILATION_TRACTION_CONVERTER_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("SL_CUT_OFF_BYPASS")                               =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SL_CUT_OFF_BYPASS;
    m_inputs_map[ska_num][MVB1].at("TRACTION_OK_1_TC_1")                              =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.TRACTION_OK_1_TC_1;
    m_inputs_map[ska_num][MVB1].at("CONTACTOR_2_1_NORMAL_LOAD_Ln")                    =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CONTACTOR_2_1_NORMAL_LOAD_Ln;
    m_inputs_map[ska_num][MVB1].at("TRACTION_DC_LINK_OK_TC_1")                        =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.TRACTION_DC_LINK_OK_TC_1;
    m_inputs_map[ska_num][MVB1].at("PANTOGRAPH_PERMISSION_TC_1")                      =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PANTOGRAPH_PERMISSION_TC_1;
    m_inputs_map[ska_num][MVB1].at("TRACTION_CUT_OFF_LOOP")                           =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.TRACTION_CUT_OFF_LOOP;
    m_inputs_map[ska_num][MVB1].at("PLANT_3_7_CB_PROTECTION")                         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_3_7_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("HVAC_1_FLOOR_HEATER_1_START")                     =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HVAC_1_FLOOR_HEATER_1_START;
    m_inputs_map[ska_num][MVB1].at("HVAC_1_FLOOR_HEATER_2_START")                     =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HVAC_1_FLOOR_HEATER_2_START;
    m_inputs_map[ska_num][MVB1].at("HVAC_1_CB_PROTECTION")                            =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HVAC_1_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("HVAC_2_FLOOR_HEATER_1_START")                     =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HVAC_2_FLOOR_HEATER_1_START;
    m_inputs_map[ska_num][MVB1].at("HVAC_2_FLOOR_HEATER_2_START")                     =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HVAC_2_FLOOR_HEATER_2_START;
    m_inputs_map[ska_num][MVB1].at("HVAC_2_CB_PROTECTION")                            =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HVAC_2_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("HVAC_1_ON_INPUT")                                 =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HVAC_1_ON_INPUT;
    m_inputs_map[ska_num][MVB1].at("HVAC_2_ON_INPUT")                                 =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HVAC_2_ON_INPUT;
    m_inputs_map[ska_num][MVB1].at("HVAC_CAB_CB_PROTECTION")                          =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HVAC_CAB_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("THERMOSTAT_HEATING_LEFT_SIDE")                    =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.THERMOSTAT_HEATING_LEFT_SIDE;
    m_inputs_map[ska_num][MVB1].at("CONTACTOR_HEATING_COMPARTMENT_LEFT_SIDE")         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CONTACTOR_HEATING_COMPARTMENT_LEFT_SIDE;
    m_inputs_map[ska_num][MVB1].at("HEATING_COMPARTMENT_LEFT_SIDE_CB_PROTECTION")     =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HEATING_COMPARTMENT_LEFT_SIDE_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("THERMOSTAT_HEATING_RIGHT_SIDE")                   =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.THERMOSTAT_HEATING_RIGHT_SIDE;
    m_inputs_map[ska_num][MVB1].at("CONTACTOR_HEATING_COMPARTMENT_RIGHT_SIDE")        =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CONTACTOR_HEATING_COMPARTMENT_RIGHT_SIDE;
    m_inputs_map[ska_num][MVB1].at("HEATING_COMPARTMENT_RIGHT_SIDE_CB_PROTECTION")    =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HEATING_COMPARTMENT_RIGHT_SIDE_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("PLANT_4_0_CB_PROTECTION")                         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_4_0_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("PRESSURE_GOVERNOR_BP_NO_EMERGENCY_BRAKE")         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PRESSURE_GOVERNOR_BP_NO_EMERGENCY_BRAKE;
    m_inputs_map[ska_num][MVB1].at("PRESSURE_GOVERNOR_PB_RELEASED")                   =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PRESSURE_GOVERNOR_PB_RELEASED;
    m_inputs_map[ska_num][MVB1].at("bit68")                                           =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.bit68;
    m_inputs_map[ska_num][MVB1].at("bit69")                                           =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.bit69;
    m_inputs_map[ska_num][MVB1].at("bit70")                                           =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.bit70;
    m_inputs_map[ska_num][MVB1].at("bit71")                                           =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.bit71;
    m_inputs_map[ska_num][MVB1].at("PRESSURE_GOVERNOR_R_CPRESS_APPL_BO1")             =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PRESSURE_GOVERNOR_R_CPRESS_APPL_BO1;
    m_inputs_map[ska_num][MVB1].at("PRESSURE_GOVERNOR_R_CPRESS_APPL_BO2")             =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PRESSURE_GOVERNOR_R_CPRESS_APPL_BO2;
    m_inputs_map[ska_num][MVB1].at("ISOLATION_COCKS_PNEUMATIC_BRAKE")                =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ISOLATION_COCKS_PNEUMATIC_BRAKE;
    m_inputs_map[ska_num][MVB1].at("ISOLATION_COCKS_DIRECT_BRAKE")                   =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ISOLATION_COCKS_DIRECT_BRAKE;
    m_inputs_map[ska_num][MVB1].at("ISOLATION_COCKS_INDIRECT_BRAKE")                 =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ISOLATION_COCKS_INDIRECT_BRAKE;
    m_inputs_map[ska_num][MVB1].at("ISOLATION_COCKS_DIRECT_BRAKE_BO1")               =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ISOLATION_COCKS_DIRECT_BRAKE_BO1;
    m_inputs_map[ska_num][MVB1].at("ISOLATION_COCKS_DIRECT_BRAKE_BO2")               =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ISOLATION_COCKS_DIRECT_BRAKE_BO2;
    m_inputs_map[ska_num][MVB1].at("ISOLATION_COCKS_PB_ISOLATED")                    =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ISOLATION_COCKS_PB_ISOLATED;
    m_inputs_map[ska_num][MVB1].at("ISOLATION_COCKS_SAND_ISOLATED")                  =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ISOLATION_COCKS_SAND_ISOLATED;
    m_inputs_map[ska_num][MVB1].at("AIR_SUSPENSION_STATUSS")                          =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.AIR_SUSPENSION_STATUSS;
    m_inputs_map[ska_num][MVB1].at("BYPASS_MRP_ISOLATION_COCK")                      =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.BYPASS_MRP_ISOLATION_COCK;
    m_inputs_map[ska_num][MVB1].at("EBCU_C_FCTOK")                                   =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.EBCU_C_FCTOK;
    m_inputs_map[ska_num][MVB1].at("EBCU_SPEED_10_Km_H")                             =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.EBCU_SPEED_10_Km_H;
    m_inputs_map[ska_num][MVB1].at("PRESSURE_GOVERNORS_EB_DETECTION")                =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PRESSURE_GOVERNORS_EB_DETECTION;
    m_inputs_map[ska_num][MVB1].at("PRESSURE_GOVERNORS_FSB_DETECTION")               =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PRESSURE_GOVERNORS_FSB_DETECTION;
    m_inputs_map[ska_num][MVB1].at("PRESSURE_GOVERNORS_INDIRECT_BRAKE_NOT_RELEASE")  =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PRESSURE_GOVERNORS_INDIRECT_BRAKE_NOT_RELEASE;
    m_inputs_map[ska_num][MVB1].at("PRESSURE_GOVERNORS_AIR_SUSPENSION_BO1")           =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PRESSURE_GOVERNORS_AIR_SUSPENSION_BO1;
    m_inputs_map[ska_num][MVB1].at("PRESSURE_GOVERNORS_AIR_SUSPENSION_BO2")           =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PRESSURE_GOVERNORS_AIR_SUSPENSION_BO2;
    m_inputs_map[ska_num][MVB1].at("ISOLATION_COCKS_BP_TO_MRP_BYPASS")               =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ISOLATION_COCKS_BP_TO_MRP_BYPASS;
    m_inputs_map[ska_num][MVB1].at("ZERO_SPEED")                                     =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ZERO_SPEED;
    m_inputs_map[ska_num][MVB1].at("EMERGENCY_BRAKE_FROM_BCU")                       =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.EMERGENCY_BRAKE_FROM_BCU;
    m_inputs_map[ska_num][MVB1].at("WSP_R_vGt5kmhDoor")                              =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.WSP_R_vGt5kmhDoor;
    m_inputs_map[ska_num][MVB1].at("FDU_GENERAL_FAULT")                              =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.FDU_GENERAL_FAULT;
    m_inputs_map[ska_num][MVB1].at("FDU_GENERAL_FIRE")                               =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.FDU_GENERAL_FIRE;
    m_inputs_map[ska_num][MVB1].at("ZERO_SPEED_BY_PASS")                             =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ZERO_SPEED_BY_PASS;
    m_inputs_map[ska_num][MVB1].at("PLANT_4_5_CB_PROTECTION")                        =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_4_5_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("ALARM_PASSENGERS_CB_PROTECTION")                 =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ALARM_PASSENGERS_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("RELAY_ALARM_PASSENGERS")                         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.RELAY_ALARM_PASSENGERS;
    m_inputs_map[ska_num][MVB1].at("RELAY_SECURITY_EMERGENCY_LOOP_CB_PROTECTION")    =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.RELAY_SECURITY_EMERGENCY_LOOP_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("EMERGENCY_BRAKE_CB_PROTECTION")                  =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.EMERGENCY_BRAKE_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("SELECTOR_BY_PASS_PASSANGER_ALARM")               =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SELECTOR_BY_PASS_PASSANGER_ALARM;
    m_inputs_map[ska_num][MVB1].at("INIBITION_PASSENGERS_ALARM_ACTIVE")               =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.INIBITION_PASSENGERS_ALARM_ACTIVE;
    m_inputs_map[ska_num][MVB1].at("HANDLE_1_PASSENGER_ALARM")                       =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HANDLE_1_PASSENGER_ALARM;
    m_inputs_map[ska_num][MVB1].at("HANDLE_3_PASSENGER_ALARM")                       =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HANDLE_3_PASSENGER_ALARM;
    m_inputs_map[ska_num][MVB1].at("HANDLE_5_PASSENGER_ALARM")                       =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HANDLE_5_PASSENGER_ALARM;
    m_inputs_map[ska_num][MVB1].at("HANDLE_7_PASSENGER_ALARM")                       =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HANDLE_7_PASSENGER_ALARM;
    m_inputs_map[ska_num][MVB1].at("HANDLE_2_PASSENGER_ALARM")                       =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HANDLE_2_PASSENGER_ALARM;
    m_inputs_map[ska_num][MVB1].at("HANDLE_4_PASSENGER_ALARM")                       =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HANDLE_4_PASSENGER_ALARM;
    m_inputs_map[ska_num][MVB1].at("HANDLE_6_PASSENGER_ALARM")                       =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HANDLE_6_PASSENGER_ALARM;
    m_inputs_map[ska_num][MVB1].at("HANDLE_8_PASSENGER_ALARM")                       =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HANDLE_8_PASSENGER_ALARM;
    m_inputs_map[ska_num][MVB1].at("RELAY_SECURITY_EMERGENCY_LOOP")                   =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.RELAY_SECURITY_EMERGENCY_LOOP;
    m_inputs_map[ska_num][MVB1].at("RELAY_TRACTION_EMERGENCY_BRAKE")                  =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.RELAY_TRACTION_EMERGENCY_BRAKE;
    m_inputs_map[ska_num][MVB1].at("SL_DEAD_MAN_BYPASS")                             =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SL_DEAD_MAN_BYPASS;
    m_inputs_map[ska_num][MVB1].at("PLANT_4_7_CB_PROTECTION")                         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_4_7_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("CABINET_RIOM_1_CB_PROTECTION")                    =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CABINET_RIOM_1_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("BCU_ZERO_SPEED")                                  =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.BCU_ZERO_SPEED;
    m_inputs_map[ska_num][MVB1].at("FIRE_EXTINGUISHER_1_PRESENCE")                    =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.FIRE_EXTINGUISHER_1_PRESENCE;
    m_inputs_map[ska_num][MVB1].at("FIRE_EXTINGUISHER_2_PRESENCE")                    =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.FIRE_EXTINGUISHER_2_PRESENCE;
    m_inputs_map[ska_num][MVB1].at("SIFA_POSITION_HANDLE")                            =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SIFA_POSITION_HANDLE;
    m_inputs_map[ska_num][MVB1].at("SIFA_TRACTION_CONTROL")                           =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SIFA_TRACTION_CONTROL;
    m_inputs_map[ska_num][MVB1].at("SAND_LEVEL_SENSOR_BOGIE_1_BEARING_RIGHT")         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SAND_LEVEL_SENSOR_BOGIE_1_BEARING_RIGHT;
    m_inputs_map[ska_num][MVB1].at("SAND_LEVEL_SENSOR_BOGIE_1_BEARING_LEFT")          =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SAND_LEVEL_SENSOR_BOGIE_1_BEARING_LEFT;
    m_inputs_map[ska_num][MVB1].at("SAND_LEVEL_SENSOR_BOGIE_2_BEARING_RIGHT")         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SAND_LEVEL_SENSOR_BOGIE_2_BEARING_RIGHT;
    m_inputs_map[ska_num][MVB1].at("SAND_LEVEL_SENSOR_BOGIE_2_BEARING_LEFT")          =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SAND_LEVEL_SENSOR_BOGIE_2_BEARING_LEFT;
    m_inputs_map[ska_num][MVB1].at("HORN_1_ISOLATION_COCK")                           =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HORN_1_ISOLATION_COCK;
    m_inputs_map[ska_num][MVB1].at("HORN_2_ISOLATION_COCK")                           =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HORN_2_ISOLATION_COCK;
    m_inputs_map[ska_num][MVB1].at("PLANT_4_8_CB_PROTECTION")                         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_4_8_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("DOOR_1_FULLY_OPENED")                             =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DOOR_1_FULLY_OPENED;
    m_inputs_map[ska_num][MVB1].at("DOOR_2_FULLY_OPENED")                             =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DOOR_2_FULLY_OPENED;
    m_inputs_map[ska_num][MVB1].at("DOOR_3_FULLY_OPENED")                             =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DOOR_3_FULLY_OPENED;
    m_inputs_map[ska_num][MVB1].at("DOOR_4_FULLY_OPENED")                             =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DOOR_4_FULLY_OPENED;
    m_inputs_map[ska_num][MVB1].at("DOOR_5_FULLY_OPENED")                             =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DOOR_5_FULLY_OPENED;
    m_inputs_map[ska_num][MVB1].at("DOOR_6_FULLY_OPENED")                             =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DOOR_6_FULLY_OPENED;
    m_inputs_map[ska_num][MVB1].at("DOOR_7_FULLY_OPENED")                             =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DOOR_7_FULLY_OPENED;
    m_inputs_map[ska_num][MVB1].at("DOOR_8_FULLY_OPENED")                             =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DOOR_8_FULLY_OPENED;
    m_inputs_map[ska_num][MVB1].at("CLOSING_HATCH")                                   =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CLOSING_HATCH;
    m_inputs_map[ska_num][MVB1].at("OPENING_HATCH")                                   =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.OPENING_HATCH;
    m_inputs_map[ska_num][MVB1].at("HATCH_BYBASS")                                    =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HATCH_BYBASS;
    m_inputs_map[ska_num][MVB1].at("CABINET_RIOM_2_CB_PROTECTION")                    =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CABINET_RIOM_2_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("ETHERNET_SWITCH_1_PAPIS_ALARM")                   =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ETHERNET_SWITCH_1_PAPIS_ALARM;
    m_inputs_map[ska_num][MVB1].at("ETHERNET_SWITCH_2_PAPIS_ALARM")                   =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ETHERNET_SWITCH_2_PAPIS_ALARM;
    m_inputs_map[ska_num][MVB1].at("bit143")                                          =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.bit143;
    m_inputs_map[ska_num][MVB1].at("ETCS_EQUIPMENT_POWER_SUPPLY_APPLIED")             =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ETCS_EQUIPMENT_POWER_SUPPLY_APPLIED;
    m_inputs_map[ska_num][MVB1].at("RELAY_CONTROL_DOORS_LOOP")                        =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.RELAY_CONTROL_DOORS_LOOP;
    m_inputs_map[ska_num][MVB1].at("SL_DOORS_LOOP_BY_PASS")                           =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SL_DOORS_LOOP_BY_PASS;
    m_inputs_map[ska_num][MVB1].at("PLANT_5_3_CB_PROTECTION")                         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_5_3_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("PLANT_5_5_CB_PROTECTION")                         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_5_5_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("DC_DC_OK_ANTIFIRE_SYSTEM")                        =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DC_DC_OK_ANTIFIRE_SYSTEM;
    m_inputs_map[ska_num][MVB1].at("PLANT_6_0_CB_PROTECTION")                         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_6_0_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("PLANT_6_5_CB_PROTECTION")                         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_6_5_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("INTERNAL_LIGHT_ON_COMMAND")                       =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.INTERNAL_LIGHT_ON_COMMAND;
    m_inputs_map[ska_num][MVB1].at("INTERNAL_HALF_LIGHT_COMMAND")                     =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.INTERNAL_HALF_LIGHT_COMMAND;
    m_inputs_map[ska_num][MVB1].at("INTERNAL_LIGHT_EMERGENCY_COMMAND")                =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.INTERNAL_LIGHT_EMERGENCY_COMMAND;
    m_inputs_map[ska_num][MVB1].at("PLANT_7_0_CB_PROTECTION")                         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_7_0_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("PLANT_7_2_CB_PROTECTION")                         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_7_2_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("AUTOMATIC_EXTERNAL_LIGHT_COMMAND")                =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.AUTOMATIC_EXTERNAL_LIGHT_COMMAND;
    m_inputs_map[ska_num][MVB1].at("SL_ETCS_BY_PASS")                                 =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SL_ETCS_BY_PASS;
    m_inputs_map[ska_num][MVB1].at("SL_DOORS_SIDE_CONTROL_ETCS_BYPASS")               =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SL_DOORS_SIDE_CONTROL_ETCS_BYPASS;
    m_inputs_map[ska_num][MVB1].at("GSM_R_RADIO_DIAGNOSTIC_INFORMATION")              =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.GSM_R_RADIO_DIAGNOSTIC_INFORMATION;
    m_inputs_map[ska_num][MVB1].at("GSM_R_RADIO_VOICE")                               =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.GSM_R_RADIO_VOICE;
    m_inputs_map[ska_num][MVB1].at("ATS_BYPASS")                                      =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ATS_BYPASS;
    m_inputs_map[ska_num][MVB1].at("PLANT_7_7_CB_PROTECTION")                         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_7_7_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("PLANT_7_8_CB_PROTECTION")                         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_7_8_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("CONTROL_UNIT_RADIO_THALES_CB_PROTECTION")         =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CONTROL_UNIT_RADIO_THALES_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("CB_PROTECTION_AXLE_BOX")                          =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CB_PROTECTION_AXLE_BOX;
    m_inputs_map[ska_num][MVB1].at("bit167")                                          =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.bit167;
    m_inputs_map[ska_num][MVB1].at("spare_21")                                        =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_21;
    m_inputs_map[ska_num][MVB1].at("spare_22")                                        =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_22;
    m_inputs_map[ska_num][MVB1].at("spare_23")                                        =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_23;
    m_inputs_map[ska_num][MVB1].at("spare_24")                                        =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_24;
    m_inputs_map[ska_num][MVB1].at("spare_25")                                        =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_25;
    m_inputs_map[ska_num][MVB1].at("spare_26")                                        =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_26;
    m_inputs_map[ska_num][MVB1].at("spare_27")                                        =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_27;
    m_inputs_map[ska_num][MVB1].at("spare_28")                                        =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_28;
    m_inputs_map[ska_num][MVB1].at("spare_29")                                        =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_29;
    m_inputs_map[ska_num][MVB1].at("spare_30")                                        =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_30;
    m_inputs_map[ska_num][MVB1].at("spare_31")                                        =m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_31;

    //qDebug() << "m_inputs_map[ska_num][DRIVER_LOAD_SELECTOR_ON]:"  << m_inputs_map[ska_num]["DRIVER_LOAD_SELECTOR_ON"];
    //qDebug() <<"struct val: " << m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DRIVER_LOAD_SELECTOR_ON;
}

void SKA_VH_RIOM::update_status_map(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);

    m_inputs_map[ska_num][STATUS0].at("lifesign")                                           = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.lifesign;
    m_inputs_map[ska_num][STATUS0].at("DIO01_Module_Error")                                 = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO01_Module_Error;
    m_inputs_map[ska_num][STATUS0].at("DIO01_Output_Overcurrent")                           = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO01_Output_Overcurrent;
    m_inputs_map[ska_num][STATUS0].at("DIO01_Heartbeat_error")                              = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO01_Heartbeat_error;
    m_inputs_map[ska_num][STATUS0].at("DIO01_Group_1_Voltage_error")                        = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO01_Group_1_Voltage_error;
    m_inputs_map[ska_num][STATUS0].at("DIO01_Group_2_Voltage_error")                        = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO01_Group_2_Voltage_error;
    m_inputs_map[ska_num][STATUS0].at("DIO01_Board_Temperature_error")                      = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO01_Board_Temperature_error;
    m_inputs_map[ska_num][STATUS0].at("bit22")                                              = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit22;
    m_inputs_map[ska_num][STATUS0].at("bit23")                                              = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit23;
    m_inputs_map[ska_num][STATUS0].at("DIO02_Module_Error")                                 = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO02_Module_Error;
    m_inputs_map[ska_num][STATUS0].at("DIO02_Output_Overcurrent")                           = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO02_Output_Overcurrent;
    m_inputs_map[ska_num][STATUS0].at("DIO02_Heartbeat_error")                              = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO02_Heartbeat_error;
    m_inputs_map[ska_num][STATUS0].at("DIO02_Group_1_Voltage_error")                        = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO02_Group_1_Voltage_error;
    m_inputs_map[ska_num][STATUS0].at("DIO02_Group_2_Voltage_error")                        = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO02_Group_2_Voltage_error;
    m_inputs_map[ska_num][STATUS0].at("DIO02_Board_Temperature_error")                      = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO02_Board_Temperature_error;
    m_inputs_map[ska_num][STATUS0].at("bit30")                                              = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit30 ;
    m_inputs_map[ska_num][STATUS0].at("bit31")                                              = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit31 ;
    m_inputs_map[ska_num][STATUS0].at("DIO03_Module_Error")                                 = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO03_Module_Error;
    m_inputs_map[ska_num][STATUS0].at("DIO03_Output_Overcurrent")                           = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO03_Output_Overcurrent;
    m_inputs_map[ska_num][STATUS0].at("DIO03_Heartbeat_error")                              = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO03_Heartbeat_error;
    m_inputs_map[ska_num][STATUS0].at("DIO03_Group_1_Voltage_error")                        = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO03_Group_1_Voltage_error;
    m_inputs_map[ska_num][STATUS0].at("DIO03_Group_2_Voltage_error")                        = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO03_Group_2_Voltage_error ;
    m_inputs_map[ska_num][STATUS0].at("DIO03_Board_Temperature_error")                      = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO03_Board_Temperature_error ;
    m_inputs_map[ska_num][STATUS0].at("bit38")                                              = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit38 ;
    m_inputs_map[ska_num][STATUS0].at("bit39")                                              = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit39 ;
    m_inputs_map[ska_num][STATUS0].at("DIO04_Module_Error")                                 = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO04_Module_Error ;
    m_inputs_map[ska_num][STATUS0].at("DIO04_Output_Overcurrent")                           = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO04_Output_Overcurrent ;
    m_inputs_map[ska_num][STATUS0].at("DIO04_Heartbeat_error")                              = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO04_Heartbeat_error ;
    m_inputs_map[ska_num][STATUS0].at("DIO04_Group_1_Voltage_error")                        = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO04_Group_1_Voltage_error ;
    m_inputs_map[ska_num][STATUS0].at("DIO04_Group_2_Voltage_error")                        = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO04_Group_2_Voltage_error ;
    m_inputs_map[ska_num][STATUS0].at("DIO04_Board_Temperature_error")                      = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO04_Board_Temperature_error ;
    m_inputs_map[ska_num][STATUS0].at("bit46")                                              = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit46 ;
    m_inputs_map[ska_num][STATUS0].at("bit47")                                              = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit47 ;
    m_inputs_map[ska_num][STATUS0].at("DIO05_Module_Error")                                 = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO05_Module_Error ;
    m_inputs_map[ska_num][STATUS0].at("DIO05_Output_Overcurrent")                           = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO05_Output_Overcurrent ;
    m_inputs_map[ska_num][STATUS0].at("DIO05_Heartbeat_error")                              = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO05_Heartbeat_error ;
    m_inputs_map[ska_num][STATUS0].at("DIO05_Group_1_Voltage_error")                        = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO05_Group_1_Voltage_error ;
    m_inputs_map[ska_num][STATUS0].at("DIO05_Group_2_Voltage_error")                        = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO05_Group_2_Voltage_error ;
    m_inputs_map[ska_num][STATUS0].at("DIO05_Board_Temperature_error")                      = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO05_Board_Temperature_error ;
    m_inputs_map[ska_num][STATUS0].at("bit54")                                              = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit54 ;
    m_inputs_map[ska_num][STATUS0].at("bit55")                                              = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit55 ;
    m_inputs_map[ska_num][STATUS0].at("DIO06_Module_Error")                                 = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO06_Module_Error ;
    m_inputs_map[ska_num][STATUS0].at("DIO06_Output_Overcurrent")                           = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO06_Output_Overcurrent;
    m_inputs_map[ska_num][STATUS0].at("DIO06_Heartbeat_error")                              = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO06_Heartbeat_error;
    m_inputs_map[ska_num][STATUS0].at("DIO06_Group_1_Voltage_error")                        = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO06_Group_1_Voltage_error ;
    m_inputs_map[ska_num][STATUS0].at("DIO06_Group_2_Voltage_error")                        = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO06_Group_2_Voltage_error ;
    m_inputs_map[ska_num][STATUS0].at("DIO06_Board_Temperature_error")                      = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO06_Board_Temperature_error;
    m_inputs_map[ska_num][STATUS0].at("bit62")                                              = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit62 ;
    m_inputs_map[ska_num][STATUS0].at("bit63")                                              = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit63 ;
    m_inputs_map[ska_num][STATUS0].at("DIO07_Module_Error")                                 = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO07_Module_Error ;
    m_inputs_map[ska_num][STATUS0].at("DIO07_Output_Overcurrent")                           = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO07_Output_Overcurrent ;
    m_inputs_map[ska_num][STATUS0].at("DIO07_Heartbeat_error")                              = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO07_Heartbeat_error ;
    m_inputs_map[ska_num][STATUS0].at("DIO07_Group_1_Voltage_error")                        = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO07_Group_1_Voltage_error ;
    m_inputs_map[ska_num][STATUS0].at("DIO07_Group_2_Voltage_error")                        = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO07_Group_2_Voltage_error ;
    m_inputs_map[ska_num][STATUS0].at("DIO07_Board_Temperature_error")                      = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO07_Board_Temperature_error ;
    m_inputs_map[ska_num][STATUS0].at("bit70")                                              = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit70 ;
    m_inputs_map[ska_num][STATUS0].at("bit71")                                              = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit71 ;
    m_inputs_map[ska_num][STATUS0].at("reserved_9")                                         = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.reserved_9;
    m_inputs_map[ska_num][STATUS0].at("reserved_10")                                        = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.reserved_10;
    m_inputs_map[ska_num][STATUS0].at("reserved_11")                                        = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.reserved_11;
    m_inputs_map[ska_num][STATUS0].at("reserved_12")                                        = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.reserved_12;
    m_inputs_map[ska_num][STATUS0].at("R1_DCU_CANopen_Fault")                               = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.R1_DCU_CANopen_Fault;
    m_inputs_map[ska_num][STATUS0].at("R2_DCU_CANopen_Fault")                               = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.R2_DCU_CANopen_Fault;
    m_inputs_map[ska_num][STATUS0].at("R3_DCU_CANopen_Fault")                               = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.R3_DCU_CANopen_Fault;
    m_inputs_map[ska_num][STATUS0].at("R4_DCU_CANopen_Fault")                               = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.R4_DCU_CANopen_Fault;
    m_inputs_map[ska_num][STATUS0].at("L1_DCU_CANopen_Fault")                               = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.L1_DCU_CANopen_Fault;
    m_inputs_map[ska_num][STATUS0].at("L2_DCU_CANopen_Fault")                               = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.L2_DCU_CANopen_Fault;
    m_inputs_map[ska_num][STATUS0].at("L3_DCU_CANopen_Fault")                               = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.L3_DCU_CANopen_Fault;
    m_inputs_map[ska_num][STATUS0].at("L4_DCU_CANopen_Fault")                               = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.L4_DCU_CANopen_Fault;
    m_inputs_map[ska_num][STATUS0].at("FDS_CANopen_Fault")                                  = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.FDS_CANopen_Fault  ;
    m_inputs_map[ska_num][STATUS0].at("ATS_CANopen_Fault")                                  = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.ATS_CANopen_Fault ;
    m_inputs_map[ska_num][STATUS0].at("PAPIS_CANopen_Fault")                                = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.PAPIS_CANopen_Fault ;
    m_inputs_map[ska_num][STATUS0].at("HVAC_C_CANopen_Fault")                               = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.HVAC_C_CANopen_Fault ;
    m_inputs_map[ska_num][STATUS0].at("HVAC_1_CANopen_Fault")                               = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.HVAC_1_CANopen_Fault ;
    m_inputs_map[ska_num][STATUS0].at("HVAC_2_CANopen_Fault")                               = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.HVAC_2_CANopen_Fault ;
    m_inputs_map[ska_num][STATUS0].at("bit118")                                             = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit118 ;
    m_inputs_map[ska_num][STATUS0].at("bit119")                                             = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit119 ;
    m_inputs_map[ska_num][STATUS0].at("reserved_15")                                        = m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.reserved_15;



}

void SKA_VH_RIOM::update_table(SKA_VEHICLE_NUM ska_x_num,MVB_NUM mvb_num)
{

    int ska_num = static_cast<int>(ska_x_num);

    for(const auto & map:m_inputs_map[ska_num][mvb_num]){
        //qDebug() <<  map.first << map.second;
        utils::setTableWidgetValueByName(m_tableWidget[ska_num][mvb_num], map.first, 1, map.second );
    }
    /*    int ska_num = static_cast<int>(ska_x_num);
    // İndeksleri kullanarak tabloyu güncelle
    qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][FDS1]->columnCount() ;
    std::vector<int> valueColumns = {1, 3, 5, 7};
    for(const auto & map:m_inputs_map[ska_num][fds_num]){


            utils::setTableWidgetValueByNameWithoutColumn(m_tableWidget[ska_num][fds_num], map.first, map.second);
            //qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT INSIDE FOR LOOP ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;

            //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,3, map.second);
            //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,5, map.second);
            //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,7, map.second);
    }*/
}

void SKA_VH_RIOM::set_data_struct(const QByteArray &input, const SKA_VEHICLE_NUM &ska_x_num)
{
    //int oa_num = static_cast<int>(oa_x_num);
    qDebug() << "azdan az çoktan çok " ;
    qDebug() << "size of input " << input.size();
    qDebug() << "Gelen input verileri :  " << input;
    //qDebug() << "Gelen input veri tipi : " << typeof(input);


    int ska_num = static_cast<int>(ska_x_num);
    qDebug() << "bassana lan şunu sizeof(m_oa_x_jru[oa_num])  " << sizeof(m_ska_x_vh_riom[ska_num]);

    if (input.size() == sizeof(m_ska_x_vh_riom[ska_num])) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        //memcpy(&m_oa_x_etcs[oa_num], input.constData(), sizeof(m_oa_x_etcs[oa_num]));

        qDebug() << "SIZE of MVB1 :  " << sizeof(m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bytes);


        // İlk alanı kopyala
        memcpy(&m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bytes, input.constData(), sizeof(m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bytes));
        update_status_map(ska_x_num);
        update_table(ska_x_num,STATUS0);

        // İkinci alanı kopyala
        memcpy(&m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bytes, input.constData() + sizeof(m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bytes), sizeof(m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bytes));
        update_inputs_map(ska_x_num);

        update_table(ska_x_num,MVB1);


        //update maps

        //
        //
        //update tables

        //
        //
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }
}

void SKA_VH_RIOM::update_struct_with_map(SKA_VEHICLE_NUM ska_x_num, MVB_NUM mvb_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    // Define a lambda function to reduce redundancy
    auto setInputMap = [&](const QString& signal_name) {
        m_inputs_map[ska_num][mvb_num][signal_name] = utils::getTableWidgetValueByName(m_tableWidget[ska_num][mvb_num], signal_name, 1).toInt();
    };

    for(const auto& map : m_inputs_map[ska_num][mvb_num])
    {
        setInputMap(map.first);
    }

    set_inputs_struct(ska_x_num);
    set_status_struct(ska_x_num);

}

void SKA_VH_RIOM::set_inputs_struct(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);

    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.MANUALPOWER_SUPPLY_PRIVILEGED_LOAD_Lp        = m_inputs_map[ska_num][MVB1].at("MANUALPOWER_SUPPLY_PRIVILEGED_LOAD_Lp")           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CONTACTOR_PRIVILEGE_LOAD_Lp                  = m_inputs_map[ska_num][MVB1].at("CONTACTOR_PRIVILEGE_LOAD_Lp")                     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DRIVER_LOAD_SELECTOR_ON                      = m_inputs_map[ska_num][MVB1].at("DRIVER_LOAD_SELECTOR_ON")                         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_3_0_CB_PROTECTION                      = m_inputs_map[ska_num][MVB1].at("PLANT_3_0_CB_PROTECTION")                         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CONTACTOR_MAINTENANCE_SKA_CAR                = m_inputs_map[ska_num][MVB1].at("CONTACTOR_MAINTENANCE_SKA_CAR")                   ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.VACUUM_OPENING_BY_PASS                       = m_inputs_map[ska_num][MVB1].at("VACUUM_OPENING_BY_PASS")                          ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.FAST_OPEN_VCB                                = m_inputs_map[ska_num][MVB1].at("FAST_OPEN_VCB")                                   ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_3_1_CB_PROTECTION                      = m_inputs_map[ska_num][MVB1].at("PLANT_3_1_CB_PROTECTION")                         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_3_2_CB_PROTECTION                      = m_inputs_map[ska_num][MVB1].at("PLANT_3_2_CB_PROTECTION")                         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.FAST_OPEN_ADD                                = m_inputs_map[ska_num][MVB1].at("FAST_OPEN_ADD")                                   ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.TRAIN_KEY_DRIVER_DESK                        = m_inputs_map[ska_num][MVB1].at("TRAIN_KEY_DRIVER_DESK")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.RELAY_KEY_DRIVER_DESK_ECDD                   = m_inputs_map[ska_num][MVB1].at("RELAY_KEY_DRIVER_DESK_ECDD")                      ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.COUPLED_TRAIN_TAIL_RELAY                     = m_inputs_map[ska_num][MVB1].at("COUPLED_TRAIN_TAIL_RELAY")                        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_3_5_CB_PROTECTION                      = m_inputs_map[ska_num][MVB1].at("PLANT_3_5_CB_PROTECTION")                         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.MV_OUTPUT_MOTOR_1_OK_TC_1                    = m_inputs_map[ska_num][MVB1].at("MV_OUTPUT_MOTOR_1_OK_TC_1")                       ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.MV_OUTPUT_MOTOR_2_OK_TC_1                    = m_inputs_map[ska_num][MVB1].at("MV_OUTPUT_MOTOR_2_OK_TC_1")                       ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HV_PRESENCE_TO_TRACTION_TC_1                 = m_inputs_map[ska_num][MVB1].at("HV_PRESENCE_TO_TRACTION_TC_1")                    ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DEVICE_ID_DI_0                               = m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_0")                                  ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DEVICE_ID_DI_1                               = m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_1")                                  ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DEVICE_ID_DI_2                               = m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_2")                                  ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DEVICE_ID_DI_3                               = m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_3")                                  ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DEVICE_ID_DI_4                               = m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_4")                                  ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DEVICE_ID_DI_5                               = m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_5")                                  ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CABINET_TEST_HW_OK_HEALT_RIOM_2              = m_inputs_map[ska_num][MVB1].at("CABINET_TEST_HW_OK_HEALT_RIOM_2")                 ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.TRACTION_OK_2_TC_1                           = m_inputs_map[ska_num][MVB1].at("TRACTION_OK_2_TC_1")                              ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.VCB_LOOP_OUT_TC_1                            = m_inputs_map[ska_num][MVB1].at("VCB_LOOP_OUT_TC_1")                               ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.TRACTION_ACTIVE_RELAY_TC_1                   = m_inputs_map[ska_num][MVB1].at("TRACTION_ACTIVE_RELAY_TC_1")                      ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.EDB_BRAKE_ACTIVE_TC_1                        = m_inputs_map[ska_num][MVB1].at("EDB_BRAKE_ACTIVE_TC_1")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CFIR_TC_1                                    = m_inputs_map[ska_num][MVB1].at("CFIR_TC_1")                                       ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SYSTEM_RESET_TC_1                            = m_inputs_map[ska_num][MVB1].at("SYSTEM_RESET_TC_1")                               ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.MV_OUTPUT_MOTOR_3_OK_TC_2                    = m_inputs_map[ska_num][MVB1].at("MV_OUTPUT_MOTOR_3_OK_TC_2")                       ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.MV_OUTPUT_MOTOR_4_OK_TC_2                    = m_inputs_map[ska_num][MVB1].at("MV_OUTPUT_MOTOR_4_OK_TC_2")                       ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HV_PRESENCE_TO_TRACTION_TC_2                 = m_inputs_map[ska_num][MVB1].at("HV_PRESENCE_TO_TRACTION_TC_2")                    ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.TRACTION_DC_LINK_OK_TC_2                     = m_inputs_map[ska_num][MVB1].at("TRACTION_DC_LINK_OK_TC_2")                        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PANTOGRAPH_PERMISSION_TC_2                   = m_inputs_map[ska_num][MVB1].at("PANTOGRAPH_PERMISSION_TC_2")                      ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.TRACTION_OK_4_TC_2                           = m_inputs_map[ska_num][MVB1].at("TRACTION_OK_4_TC_2")                              ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.TRACTION_OK_3_TC_2                           = m_inputs_map[ska_num][MVB1].at("TRACTION_OK_3_TC_2")                              ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.VCB_LOOP_OUT_TC_2                            = m_inputs_map[ska_num][MVB1].at("VCB_LOOP_OUT_TC_2")                               ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.TRACTION_ACTIVE_RELAY_TC_2                   = m_inputs_map[ska_num][MVB1].at("TRACTION_ACTIVE_RELAY_TC_2")                      ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.EDB_BRAKE_ACTIVE_TC_2                        = m_inputs_map[ska_num][MVB1].at("EDB_BRAKE_ACTIVE_TC_2")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CFIR_TC_2                                    = m_inputs_map[ska_num][MVB1].at("CFIR_TC_2")                                       ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SYSTEM_RESET_TC_2                            = m_inputs_map[ska_num][MVB1].at("SYSTEM_RESET_TC_2")                               ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.VENTILATION_TRACTION_CONVERTER_CB_PROTECTION = m_inputs_map[ska_num][MVB1].at("VENTILATION_TRACTION_CONVERTER_CB_PROTECTION")    ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SL_CUT_OFF_BYPASS                            = m_inputs_map[ska_num][MVB1].at("SL_CUT_OFF_BYPASS")                               ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.TRACTION_OK_1_TC_1                           = m_inputs_map[ska_num][MVB1].at("TRACTION_OK_1_TC_1")                              ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CONTACTOR_2_1_NORMAL_LOAD_Ln                 = m_inputs_map[ska_num][MVB1].at("CONTACTOR_2_1_NORMAL_LOAD_Ln")                    ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.TRACTION_DC_LINK_OK_TC_1                     = m_inputs_map[ska_num][MVB1].at("TRACTION_DC_LINK_OK_TC_1")                        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PANTOGRAPH_PERMISSION_TC_1                   = m_inputs_map[ska_num][MVB1].at("PANTOGRAPH_PERMISSION_TC_1")                      ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.TRACTION_CUT_OFF_LOOP                        = m_inputs_map[ska_num][MVB1].at("TRACTION_CUT_OFF_LOOP")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_3_7_CB_PROTECTION                      = m_inputs_map[ska_num][MVB1].at("PLANT_3_7_CB_PROTECTION")                         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HVAC_1_FLOOR_HEATER_1_START                  = m_inputs_map[ska_num][MVB1].at("HVAC_1_FLOOR_HEATER_1_START")                     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HVAC_1_FLOOR_HEATER_2_START                  = m_inputs_map[ska_num][MVB1].at("HVAC_1_FLOOR_HEATER_2_START")                     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HVAC_1_CB_PROTECTION                         = m_inputs_map[ska_num][MVB1].at("HVAC_1_CB_PROTECTION")                            ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HVAC_2_FLOOR_HEATER_1_START                  = m_inputs_map[ska_num][MVB1].at("HVAC_2_FLOOR_HEATER_1_START")                     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HVAC_2_FLOOR_HEATER_2_START                  = m_inputs_map[ska_num][MVB1].at("HVAC_2_FLOOR_HEATER_2_START")                     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HVAC_2_CB_PROTECTION                         = m_inputs_map[ska_num][MVB1].at("HVAC_2_CB_PROTECTION")                            ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HVAC_1_ON_INPUT                              = m_inputs_map[ska_num][MVB1].at("HVAC_1_ON_INPUT")                                 ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HVAC_2_ON_INPUT                              = m_inputs_map[ska_num][MVB1].at("HVAC_2_ON_INPUT")                                 ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HVAC_CAB_CB_PROTECTION                       = m_inputs_map[ska_num][MVB1].at("HVAC_CAB_CB_PROTECTION")                          ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.THERMOSTAT_HEATING_LEFT_SIDE                 = m_inputs_map[ska_num][MVB1].at("THERMOSTAT_HEATING_LEFT_SIDE")                    ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CONTACTOR_HEATING_COMPARTMENT_LEFT_SIDE      = m_inputs_map[ska_num][MVB1].at("CONTACTOR_HEATING_COMPARTMENT_LEFT_SIDE")         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HEATING_COMPARTMENT_LEFT_SIDE_CB_PROTECTION  = m_inputs_map[ska_num][MVB1].at("HEATING_COMPARTMENT_LEFT_SIDE_CB_PROTECTION")     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.THERMOSTAT_HEATING_RIGHT_SIDE                = m_inputs_map[ska_num][MVB1].at("THERMOSTAT_HEATING_RIGHT_SIDE")                   ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CONTACTOR_HEATING_COMPARTMENT_RIGHT_SIDE     = m_inputs_map[ska_num][MVB1].at("CONTACTOR_HEATING_COMPARTMENT_RIGHT_SIDE")        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HEATING_COMPARTMENT_RIGHT_SIDE_CB_PROTECTION = m_inputs_map[ska_num][MVB1].at("HEATING_COMPARTMENT_RIGHT_SIDE_CB_PROTECTION")    ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_4_0_CB_PROTECTION                      = m_inputs_map[ska_num][MVB1].at("PLANT_4_0_CB_PROTECTION")                         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PRESSURE_GOVERNOR_BP_NO_EMERGENCY_BRAKE      = m_inputs_map[ska_num][MVB1].at("PRESSURE_GOVERNOR_BP_NO_EMERGENCY_BRAKE")         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PRESSURE_GOVERNOR_PB_RELEASED                = m_inputs_map[ska_num][MVB1].at("PRESSURE_GOVERNOR_PB_RELEASED")                   ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.bit68                                        = m_inputs_map[ska_num][MVB1].at("bit68")                                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.bit69                                        = m_inputs_map[ska_num][MVB1].at("bit69")                                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.bit70                                        = m_inputs_map[ska_num][MVB1].at("bit70")                                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.bit71                                        = m_inputs_map[ska_num][MVB1].at("bit71")                                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PRESSURE_GOVERNOR_R_CPRESS_APPL_BO1          = m_inputs_map[ska_num][MVB1].at("PRESSURE_GOVERNOR_R_CPRESS_APPL_BO1")             ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PRESSURE_GOVERNOR_R_CPRESS_APPL_BO2          = m_inputs_map[ska_num][MVB1].at("PRESSURE_GOVERNOR_R_CPRESS_APPL_BO2")             ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ISOLATION_COCKS_PNEUMATIC_BRAKE             = m_inputs_map[ska_num][MVB1].at("ISOLATION_COCKS_PNEUMATIC_BRAKE")                ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ISOLATION_COCKS_DIRECT_BRAKE                = m_inputs_map[ska_num][MVB1].at("ISOLATION_COCKS_DIRECT_BRAKE")                   ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ISOLATION_COCKS_INDIRECT_BRAKE              = m_inputs_map[ska_num][MVB1].at("ISOLATION_COCKS_INDIRECT_BRAKE")                 ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ISOLATION_COCKS_DIRECT_BRAKE_BO1            = m_inputs_map[ska_num][MVB1].at("ISOLATION_COCKS_DIRECT_BRAKE_BO1")               ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ISOLATION_COCKS_DIRECT_BRAKE_BO2            = m_inputs_map[ska_num][MVB1].at("ISOLATION_COCKS_DIRECT_BRAKE_BO2")               ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ISOLATION_COCKS_PB_ISOLATED                 = m_inputs_map[ska_num][MVB1].at("ISOLATION_COCKS_PB_ISOLATED")                    ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ISOLATION_COCKS_SAND_ISOLATED               = m_inputs_map[ska_num][MVB1].at("ISOLATION_COCKS_SAND_ISOLATED")                  ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.AIR_SUSPENSION_STATUSS                       = m_inputs_map[ska_num][MVB1].at("AIR_SUSPENSION_STATUSS")                          ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.BYPASS_MRP_ISOLATION_COCK                   = m_inputs_map[ska_num][MVB1].at("BYPASS_MRP_ISOLATION_COCK")                      ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.EBCU_C_FCTOK                                = m_inputs_map[ska_num][MVB1].at("EBCU_C_FCTOK")                                   ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.EBCU_SPEED_10_Km_H                          = m_inputs_map[ska_num][MVB1].at("EBCU_SPEED_10_Km_H")                             ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PRESSURE_GOVERNORS_EB_DETECTION             = m_inputs_map[ska_num][MVB1].at("PRESSURE_GOVERNORS_EB_DETECTION")                ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PRESSURE_GOVERNORS_FSB_DETECTION            = m_inputs_map[ska_num][MVB1].at("PRESSURE_GOVERNORS_FSB_DETECTION")               ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PRESSURE_GOVERNORS_INDIRECT_BRAKE_NOT_RELEASE= m_inputs_map[ska_num][MVB1].at("PRESSURE_GOVERNORS_INDIRECT_BRAKE_NOT_RELEASE")  ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PRESSURE_GOVERNORS_AIR_SUSPENSION_BO1        = m_inputs_map[ska_num][MVB1].at("PRESSURE_GOVERNORS_AIR_SUSPENSION_BO1")           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PRESSURE_GOVERNORS_AIR_SUSPENSION_BO2        = m_inputs_map[ska_num][MVB1].at("PRESSURE_GOVERNORS_AIR_SUSPENSION_BO2")           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ISOLATION_COCKS_BP_TO_MRP_BYPASS            = m_inputs_map[ska_num][MVB1].at("ISOLATION_COCKS_BP_TO_MRP_BYPASS")               ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ZERO_SPEED                                  = m_inputs_map[ska_num][MVB1].at("ZERO_SPEED")                                     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.EMERGENCY_BRAKE_FROM_BCU                    = m_inputs_map[ska_num][MVB1].at("EMERGENCY_BRAKE_FROM_BCU")                       ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.WSP_R_vGt5kmhDoor                           = m_inputs_map[ska_num][MVB1].at("WSP_R_vGt5kmhDoor")                              ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.FDU_GENERAL_FAULT                           = m_inputs_map[ska_num][MVB1].at("FDU_GENERAL_FAULT")                              ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.FDU_GENERAL_FIRE                            = m_inputs_map[ska_num][MVB1].at("FDU_GENERAL_FIRE")                               ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ZERO_SPEED_BY_PASS                          = m_inputs_map[ska_num][MVB1].at("ZERO_SPEED_BY_PASS")                             ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_4_5_CB_PROTECTION                     = m_inputs_map[ska_num][MVB1].at("PLANT_4_5_CB_PROTECTION")                        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ALARM_PASSENGERS_CB_PROTECTION              = m_inputs_map[ska_num][MVB1].at("ALARM_PASSENGERS_CB_PROTECTION")                 ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.RELAY_ALARM_PASSENGERS                      = m_inputs_map[ska_num][MVB1].at("RELAY_ALARM_PASSENGERS")                         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.RELAY_SECURITY_EMERGENCY_LOOP_CB_PROTECTION = m_inputs_map[ska_num][MVB1].at("RELAY_SECURITY_EMERGENCY_LOOP_CB_PROTECTION")    ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.EMERGENCY_BRAKE_CB_PROTECTION               = m_inputs_map[ska_num][MVB1].at("EMERGENCY_BRAKE_CB_PROTECTION")                  ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SELECTOR_BY_PASS_PASSANGER_ALARM            = m_inputs_map[ska_num][MVB1].at("SELECTOR_BY_PASS_PASSANGER_ALARM")               ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.INIBITION_PASSENGERS_ALARM_ACTIVE            = m_inputs_map[ska_num][MVB1].at("INIBITION_PASSENGERS_ALARM_ACTIVE")               ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HANDLE_1_PASSENGER_ALARM                    = m_inputs_map[ska_num][MVB1].at("HANDLE_1_PASSENGER_ALARM")                       ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HANDLE_3_PASSENGER_ALARM                    = m_inputs_map[ska_num][MVB1].at("HANDLE_3_PASSENGER_ALARM")                       ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HANDLE_5_PASSENGER_ALARM                    = m_inputs_map[ska_num][MVB1].at("HANDLE_5_PASSENGER_ALARM")                       ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HANDLE_7_PASSENGER_ALARM                    = m_inputs_map[ska_num][MVB1].at("HANDLE_7_PASSENGER_ALARM")                       ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HANDLE_2_PASSENGER_ALARM                    = m_inputs_map[ska_num][MVB1].at("HANDLE_2_PASSENGER_ALARM")                       ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HANDLE_4_PASSENGER_ALARM                    = m_inputs_map[ska_num][MVB1].at("HANDLE_4_PASSENGER_ALARM")                       ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HANDLE_6_PASSENGER_ALARM                    = m_inputs_map[ska_num][MVB1].at("HANDLE_6_PASSENGER_ALARM")                       ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HANDLE_8_PASSENGER_ALARM                    = m_inputs_map[ska_num][MVB1].at("HANDLE_8_PASSENGER_ALARM")                       ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.RELAY_SECURITY_EMERGENCY_LOOP                = m_inputs_map[ska_num][MVB1].at("RELAY_SECURITY_EMERGENCY_LOOP")                   ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.RELAY_TRACTION_EMERGENCY_BRAKE               = m_inputs_map[ska_num][MVB1].at("RELAY_TRACTION_EMERGENCY_BRAKE")                  ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SL_DEAD_MAN_BYPASS                          = m_inputs_map[ska_num][MVB1].at("SL_DEAD_MAN_BYPASS")                             ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_4_7_CB_PROTECTION                      = m_inputs_map[ska_num][MVB1].at("PLANT_4_7_CB_PROTECTION")                         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CABINET_RIOM_1_CB_PROTECTION                 = m_inputs_map[ska_num][MVB1].at("CABINET_RIOM_1_CB_PROTECTION")                    ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.BCU_ZERO_SPEED                               = m_inputs_map[ska_num][MVB1].at("BCU_ZERO_SPEED")                                  ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.FIRE_EXTINGUISHER_1_PRESENCE                 = m_inputs_map[ska_num][MVB1].at("FIRE_EXTINGUISHER_1_PRESENCE")                    ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.FIRE_EXTINGUISHER_2_PRESENCE                 = m_inputs_map[ska_num][MVB1].at("FIRE_EXTINGUISHER_2_PRESENCE")                    ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SIFA_POSITION_HANDLE                         = m_inputs_map[ska_num][MVB1].at("SIFA_POSITION_HANDLE")                            ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SIFA_TRACTION_CONTROL                        = m_inputs_map[ska_num][MVB1].at("SIFA_TRACTION_CONTROL")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SAND_LEVEL_SENSOR_BOGIE_1_BEARING_RIGHT      = m_inputs_map[ska_num][MVB1].at("SAND_LEVEL_SENSOR_BOGIE_1_BEARING_RIGHT")         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SAND_LEVEL_SENSOR_BOGIE_1_BEARING_LEFT       = m_inputs_map[ska_num][MVB1].at("SAND_LEVEL_SENSOR_BOGIE_1_BEARING_LEFT")          ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SAND_LEVEL_SENSOR_BOGIE_2_BEARING_RIGHT      = m_inputs_map[ska_num][MVB1].at("SAND_LEVEL_SENSOR_BOGIE_2_BEARING_RIGHT")         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SAND_LEVEL_SENSOR_BOGIE_2_BEARING_LEFT       = m_inputs_map[ska_num][MVB1].at("SAND_LEVEL_SENSOR_BOGIE_2_BEARING_LEFT")          ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HORN_1_ISOLATION_COCK                        = m_inputs_map[ska_num][MVB1].at("HORN_1_ISOLATION_COCK")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HORN_2_ISOLATION_COCK                        = m_inputs_map[ska_num][MVB1].at("HORN_2_ISOLATION_COCK")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_4_8_CB_PROTECTION                      = m_inputs_map[ska_num][MVB1].at("PLANT_4_8_CB_PROTECTION")                         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DOOR_1_FULLY_OPENED                          = m_inputs_map[ska_num][MVB1].at("DOOR_1_FULLY_OPENED")                             ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DOOR_2_FULLY_OPENED                          = m_inputs_map[ska_num][MVB1].at("DOOR_2_FULLY_OPENED")                             ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DOOR_3_FULLY_OPENED                          = m_inputs_map[ska_num][MVB1].at("DOOR_3_FULLY_OPENED")                             ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DOOR_4_FULLY_OPENED                          = m_inputs_map[ska_num][MVB1].at("DOOR_4_FULLY_OPENED")                             ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DOOR_5_FULLY_OPENED                          = m_inputs_map[ska_num][MVB1].at("DOOR_5_FULLY_OPENED")                             ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DOOR_6_FULLY_OPENED                          = m_inputs_map[ska_num][MVB1].at("DOOR_6_FULLY_OPENED")                             ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DOOR_7_FULLY_OPENED                          = m_inputs_map[ska_num][MVB1].at("DOOR_7_FULLY_OPENED")                             ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DOOR_8_FULLY_OPENED                          = m_inputs_map[ska_num][MVB1].at("DOOR_8_FULLY_OPENED")                             ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CLOSING_HATCH                                = m_inputs_map[ska_num][MVB1].at("CLOSING_HATCH")                                   ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.OPENING_HATCH                                = m_inputs_map[ska_num][MVB1].at("OPENING_HATCH")                                   ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.HATCH_BYBASS                                 = m_inputs_map[ska_num][MVB1].at("HATCH_BYBASS")                                    ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CABINET_RIOM_2_CB_PROTECTION                 = m_inputs_map[ska_num][MVB1].at("CABINET_RIOM_2_CB_PROTECTION")                    ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ETHERNET_SWITCH_1_PAPIS_ALARM                = m_inputs_map[ska_num][MVB1].at("ETHERNET_SWITCH_1_PAPIS_ALARM")                   ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ETHERNET_SWITCH_2_PAPIS_ALARM                = m_inputs_map[ska_num][MVB1].at("ETHERNET_SWITCH_2_PAPIS_ALARM")                   ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.bit143                                       = m_inputs_map[ska_num][MVB1].at("bit143")                                          ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ETCS_EQUIPMENT_POWER_SUPPLY_APPLIED          = m_inputs_map[ska_num][MVB1].at("ETCS_EQUIPMENT_POWER_SUPPLY_APPLIED")             ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.RELAY_CONTROL_DOORS_LOOP                     = m_inputs_map[ska_num][MVB1].at("RELAY_CONTROL_DOORS_LOOP")                        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SL_DOORS_LOOP_BY_PASS                        = m_inputs_map[ska_num][MVB1].at("SL_DOORS_LOOP_BY_PASS")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_5_3_CB_PROTECTION                      = m_inputs_map[ska_num][MVB1].at("PLANT_5_3_CB_PROTECTION")                         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_5_5_CB_PROTECTION                      = m_inputs_map[ska_num][MVB1].at("PLANT_5_5_CB_PROTECTION")                         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.DC_DC_OK_ANTIFIRE_SYSTEM                     = m_inputs_map[ska_num][MVB1].at("DC_DC_OK_ANTIFIRE_SYSTEM")                        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_6_0_CB_PROTECTION                      = m_inputs_map[ska_num][MVB1].at("PLANT_6_0_CB_PROTECTION")                         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_6_5_CB_PROTECTION                      = m_inputs_map[ska_num][MVB1].at("PLANT_6_5_CB_PROTECTION")                         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.INTERNAL_LIGHT_ON_COMMAND                    = m_inputs_map[ska_num][MVB1].at("INTERNAL_LIGHT_ON_COMMAND")                       ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.INTERNAL_HALF_LIGHT_COMMAND                  = m_inputs_map[ska_num][MVB1].at("INTERNAL_HALF_LIGHT_COMMAND")                     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.INTERNAL_LIGHT_EMERGENCY_COMMAND             = m_inputs_map[ska_num][MVB1].at("INTERNAL_LIGHT_EMERGENCY_COMMAND")                ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_7_0_CB_PROTECTION                      = m_inputs_map[ska_num][MVB1].at("PLANT_7_0_CB_PROTECTION")                         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_7_2_CB_PROTECTION                      = m_inputs_map[ska_num][MVB1].at("PLANT_7_2_CB_PROTECTION")                         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.AUTOMATIC_EXTERNAL_LIGHT_COMMAND             = m_inputs_map[ska_num][MVB1].at("AUTOMATIC_EXTERNAL_LIGHT_COMMAND")                ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SL_ETCS_BY_PASS                              = m_inputs_map[ska_num][MVB1].at("SL_ETCS_BY_PASS")                                 ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.SL_DOORS_SIDE_CONTROL_ETCS_BYPASS            = m_inputs_map[ska_num][MVB1].at("SL_DOORS_SIDE_CONTROL_ETCS_BYPASS")               ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.GSM_R_RADIO_DIAGNOSTIC_INFORMATION           = m_inputs_map[ska_num][MVB1].at("GSM_R_RADIO_DIAGNOSTIC_INFORMATION")                                          ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.GSM_R_RADIO_VOICE                            = m_inputs_map[ska_num][MVB1].at("GSM_R_RADIO_VOICE")                               ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.ATS_BYPASS                                   = m_inputs_map[ska_num][MVB1].at("ATS_BYPASS")                                      ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_7_7_CB_PROTECTION                      = m_inputs_map[ska_num][MVB1].at("PLANT_7_7_CB_PROTECTION")                         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.PLANT_7_8_CB_PROTECTION                      = m_inputs_map[ska_num][MVB1].at("PLANT_7_8_CB_PROTECTION")                         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CONTROL_UNIT_RADIO_THALES_CB_PROTECTION      = m_inputs_map[ska_num][MVB1].at("CONTROL_UNIT_RADIO_THALES_CB_PROTECTION")         ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.CB_PROTECTION_AXLE_BOX                       = m_inputs_map[ska_num][MVB1].at("CB_PROTECTION_AXLE_BOX")                          ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.bit167                                       = m_inputs_map[ska_num][MVB1].at("bit167")                                          ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_21                                     = m_inputs_map[ska_num][MVB1].at("spare_21")                                        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_22                                     = m_inputs_map[ska_num][MVB1].at("spare_22")                                        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_23                                     = m_inputs_map[ska_num][MVB1].at("spare_23")                                        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_24                                     = m_inputs_map[ska_num][MVB1].at("spare_24")                                        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_25                                     = m_inputs_map[ska_num][MVB1].at("spare_25")                                        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_26                                     = m_inputs_map[ska_num][MVB1].at("spare_26")                                        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_27                                     = m_inputs_map[ska_num][MVB1].at("spare_27")                                        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_28                                     = m_inputs_map[ska_num][MVB1].at("spare_28")                                        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_29                                     = m_inputs_map[ska_num][MVB1].at("spare_29")                                        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_30                                     = m_inputs_map[ska_num][MVB1].at("spare_30")                                        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.spare_31                                     = m_inputs_map[ska_num][MVB1].at("spare_31")                                        ;

}




void SKA_VH_RIOM::set_status_struct(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);



    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.lifesign =                                                                                     m_inputs_map[ska_num][STATUS0].at("lifesign")                        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO01_Module_Error =                               m_inputs_map[ska_num][STATUS0].at("DIO01_Module_Error")              ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO01_Output_Overcurrent =                             m_inputs_map[ska_num][STATUS0].at("DIO01_Output_Overcurrent")        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO01_Heartbeat_error =                                m_inputs_map[ska_num][STATUS0].at("DIO01_Heartbeat_error")           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO01_Group_1_Voltage_error =                              m_inputs_map[ska_num][STATUS0].at("DIO01_Group_1_Voltage_error")     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO01_Group_2_Voltage_error =                              m_inputs_map[ska_num][STATUS0].at("DIO01_Group_2_Voltage_error")     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO01_Board_Temperature_error =                                m_inputs_map[ska_num][STATUS0].at("DIO01_Board_Temperature_error")   ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit22 =                                m_inputs_map[ska_num][STATUS0].at("bit22")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit23 =                                m_inputs_map[ska_num][STATUS0].at("bit23")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO02_Module_Error =                               m_inputs_map[ska_num][STATUS0].at("DIO02_Module_Error")              ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO02_Output_Overcurrent =                             m_inputs_map[ska_num][STATUS0].at("DIO02_Output_Overcurrent")        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO02_Heartbeat_error =                                m_inputs_map[ska_num][STATUS0].at("DIO02_Heartbeat_error")           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO02_Group_1_Voltage_error =                              m_inputs_map[ska_num][STATUS0].at("DIO02_Group_1_Voltage_error")     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO02_Group_2_Voltage_error =                              m_inputs_map[ska_num][STATUS0].at("DIO02_Group_2_Voltage_error")     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO02_Board_Temperature_error =                                m_inputs_map[ska_num][STATUS0].at("DIO02_Board_Temperature_error")   ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit30  =                               m_inputs_map[ska_num][STATUS0].at("bit30")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit31  =                               m_inputs_map[ska_num][STATUS0].at("bit31")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO03_Module_Error =                               m_inputs_map[ska_num][STATUS0].at("DIO03_Module_Error")              ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO03_Output_Overcurrent =                             m_inputs_map[ska_num][STATUS0].at("DIO03_Output_Overcurrent")        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO03_Heartbeat_error =                                m_inputs_map[ska_num][STATUS0].at("DIO03_Heartbeat_error")           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO03_Group_1_Voltage_error =                              m_inputs_map[ska_num][STATUS0].at("DIO03_Group_1_Voltage_error")     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO03_Group_2_Voltage_error  =                             m_inputs_map[ska_num][STATUS0].at("DIO03_Group_2_Voltage_error")     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO03_Board_Temperature_error  =                               m_inputs_map[ska_num][STATUS0].at("DIO03_Board_Temperature_error")   ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit38  =                               m_inputs_map[ska_num][STATUS0].at("bit38")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit39  =                               m_inputs_map[ska_num][STATUS0].at("bit39")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO04_Module_Error  =                              m_inputs_map[ska_num][STATUS0].at("DIO04_Module_Error")              ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO04_Output_Overcurrent  =                                m_inputs_map[ska_num][STATUS0].at("DIO04_Output_Overcurrent")        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO04_Heartbeat_error  =                               m_inputs_map[ska_num][STATUS0].at("DIO04_Heartbeat_error")           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO04_Group_1_Voltage_error  =                             m_inputs_map[ska_num][STATUS0].at("DIO04_Group_1_Voltage_error")     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO04_Group_2_Voltage_error  =                             m_inputs_map[ska_num][STATUS0].at("DIO04_Group_2_Voltage_error")     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO04_Board_Temperature_error  =                               m_inputs_map[ska_num][STATUS0].at("DIO04_Board_Temperature_error")   ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit46  =                               m_inputs_map[ska_num][STATUS0].at("bit46")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit47  =                               m_inputs_map[ska_num][STATUS0].at("bit47")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO05_Module_Error  =                              m_inputs_map[ska_num][STATUS0].at("DIO05_Module_Error")              ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO05_Output_Overcurrent  =                                m_inputs_map[ska_num][STATUS0].at("DIO05_Output_Overcurrent")        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO05_Heartbeat_error  =                               m_inputs_map[ska_num][STATUS0].at("DIO05_Heartbeat_error")           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO05_Group_1_Voltage_error  =                             m_inputs_map[ska_num][STATUS0].at("DIO05_Group_1_Voltage_error")     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO05_Group_2_Voltage_error  =                             m_inputs_map[ska_num][STATUS0].at("DIO05_Group_2_Voltage_error")     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO05_Board_Temperature_error  =                               m_inputs_map[ska_num][STATUS0].at("DIO05_Board_Temperature_error")   ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit54  =                               m_inputs_map[ska_num][STATUS0].at("bit54")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit55  =                               m_inputs_map[ska_num][STATUS0].at("bit55")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO06_Module_Error  =                              m_inputs_map[ska_num][STATUS0].at("DIO06_Module_Error")              ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO06_Output_Overcurrent =                             m_inputs_map[ska_num][STATUS0].at("DIO06_Output_Overcurrent")        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO06_Heartbeat_error =                                m_inputs_map[ska_num][STATUS0].at("DIO06_Heartbeat_error")           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO06_Group_1_Voltage_error  =                             m_inputs_map[ska_num][STATUS0].at("DIO06_Group_1_Voltage_error")     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO06_Group_2_Voltage_error  =                             m_inputs_map[ska_num][STATUS0].at("DIO06_Group_2_Voltage_error")     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO06_Board_Temperature_error =                                m_inputs_map[ska_num][STATUS0].at("DIO06_Board_Temperature_error")   ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit62  =                               m_inputs_map[ska_num][STATUS0].at("bit62")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit63  =                               m_inputs_map[ska_num][STATUS0].at("bit63")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO07_Module_Error  =                              m_inputs_map[ska_num][STATUS0].at("DIO07_Module_Error")              ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO07_Output_Overcurrent  =                                m_inputs_map[ska_num][STATUS0].at("DIO07_Output_Overcurrent")        ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO07_Heartbeat_error  =                               m_inputs_map[ska_num][STATUS0].at("DIO07_Heartbeat_error")           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO07_Group_1_Voltage_error  =                             m_inputs_map[ska_num][STATUS0].at("DIO07_Group_1_Voltage_error")     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO07_Group_2_Voltage_error  =                             m_inputs_map[ska_num][STATUS0].at("DIO07_Group_2_Voltage_error")     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.DIO07_Board_Temperature_error  =                               m_inputs_map[ska_num][STATUS0].at("DIO07_Board_Temperature_error")   ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit70  =                               m_inputs_map[ska_num][STATUS0].at("bit70")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit71  =                               m_inputs_map[ska_num][STATUS0].at("bit71")                           ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.reserved_9 =                               m_inputs_map[ska_num][STATUS0].at("reserved_9")                      ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.reserved_10 =                              m_inputs_map[ska_num][STATUS0].at("reserved_10")                     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.reserved_11 =                              m_inputs_map[ska_num][STATUS0].at("reserved_11")                     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.reserved_12 =                              m_inputs_map[ska_num][STATUS0].at("reserved_12")                     ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.R1_DCU_CANopen_Fault =                             m_inputs_map[ska_num][STATUS0].at("R1_DCU_CANopen_Fault")            ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.R2_DCU_CANopen_Fault =                             m_inputs_map[ska_num][STATUS0].at("R2_DCU_CANopen_Fault")            ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.R3_DCU_CANopen_Fault =                             m_inputs_map[ska_num][STATUS0].at("R3_DCU_CANopen_Fault")            ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.R4_DCU_CANopen_Fault =                             m_inputs_map[ska_num][STATUS0].at("R4_DCU_CANopen_Fault")            ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.L1_DCU_CANopen_Fault =                             m_inputs_map[ska_num][STATUS0].at("L1_DCU_CANopen_Fault")            ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.L2_DCU_CANopen_Fault =                             m_inputs_map[ska_num][STATUS0].at("L2_DCU_CANopen_Fault")            ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.L3_DCU_CANopen_Fault =                             m_inputs_map[ska_num][STATUS0].at("L3_DCU_CANopen_Fault")            ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.L4_DCU_CANopen_Fault =                             m_inputs_map[ska_num][STATUS0].at("L4_DCU_CANopen_Fault")            ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.FDS_CANopen_Fault   =                              m_inputs_map[ska_num][STATUS0].at("FDS_CANopen_Fault")               ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.ATS_CANopen_Fault  =                               m_inputs_map[ska_num][STATUS0].at("ATS_CANopen_Fault")               ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.PAPIS_CANopen_Fault  =                             m_inputs_map[ska_num][STATUS0].at("PAPIS_CANopen_Fault")             ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.HVAC_C_CANopen_Fault  =                                m_inputs_map[ska_num][STATUS0].at("HVAC_C_CANopen_Fault")            ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.HVAC_1_CANopen_Fault  =                                m_inputs_map[ska_num][STATUS0].at("HVAC_1_CANopen_Fault")            ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.HVAC_2_CANopen_Fault  =                                m_inputs_map[ska_num][STATUS0].at("HVAC_2_CANopen_Fault")            ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit118  =                              m_inputs_map[ska_num][STATUS0].at("bit118")                          ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.bit119  =                              m_inputs_map[ska_num][STATUS0].at("bit119")                          ;
    m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb_status.bits.reserved_15 =                              m_inputs_map[ska_num][STATUS0].at("reserved_15")                     ;

}



void SKA_VH_RIOM::make_signal_slot_connection()
{


    //SKA1_STATUS
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][STATUS0], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1, STATUS0);
    });

    //SKA1_INPUTS
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][MVB1], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1, MVB1);
    });



    //SKA2_STATUS
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][STATUS0], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2, STATUS0);
    });

    //SKA2_INPUTS
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][MVB1], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2, MVB1);
    });

}
