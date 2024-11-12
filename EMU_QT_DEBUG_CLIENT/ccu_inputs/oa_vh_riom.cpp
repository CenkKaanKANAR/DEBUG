#include "oa_vh_riom.h"

Oa_Vh_Riom::Oa_Vh_Riom(QObject *parent)
    : QObject{parent}
{
    memset(&m_oa_x_vh_riom, 0, sizeof(m_oa_x_vh_riom));

    init_inputs_table(OA_VEHICLE_NUM::OA1);
    init_inputs_table(OA_VEHICLE_NUM::OA2);

    init_status_table(OA_VEHICLE_NUM::OA1);
    init_status_table(OA_VEHICLE_NUM::OA2);


    qDebug() << "MERHABA" ;
    make_signal_slot_connection();

}

Oa_Vh_Riom::~Oa_Vh_Riom()
{

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            delete m_tableWidget[i][j];
            m_tableWidget[i][j] = nullptr; // Güvenlik için nullptr atayın
        }
    }

}



void Oa_Vh_Riom::make_signal_slot_connection()
{

    qDebug() << "SELAMLAR" ;
    //OA1_STATUS
    connect(m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)][STATUS0], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(OA_VEHICLE_NUM::OA1, STATUS0);
    });

    //OA1_INPUTS
    connect(m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)][MVB1], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(OA_VEHICLE_NUM::OA1, MVB1);
    });



    //OA2_STATUS
    connect(m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)][STATUS0], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(OA_VEHICLE_NUM::OA2, STATUS0);
    });

    //OA2_INPUTS
    connect(m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)][MVB1], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(OA_VEHICLE_NUM::OA2, MVB1);
    });

}

void Oa_Vh_Riom::init_inputs_table(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);
    m_inputs_map[oa_num][MVB1] = {
        {"MANUAL_POWER_SUPPLY_PRIVILEGED_LOAD_Lp", 0},
        {"CONTACTOR_PRIVILEGE_LOAD_Lp", 0},
        {"SAFETY_BATTERY_CASE", 0},
        {"SL_APS_START", 0},
        {"CONVERTER_APS_OK", 0},
        {"CONVERTER_MV_OK", 0},
        {"CONVERTER_HV_PRESENCE", 0},
        {"BATTERY_CHARGER_OK", 0},
        {"PLANT_3_0_CB_PROTECTION", 0},
        {"CONTACTORS_SOCKETS_WORKSHOP_LEFT_INSERTED", 0},
        {"CONTACTORS_SOCKETS_WORKSHOP_RIGHT_INSERTED", 0},
        {"CONTACTOR_DEGRADE_MODE_MV_OA_CARS", 0},
        {"READY_VCB", 0},
        {"VCB_CLOSE", 0},
        {"OPEN_VCB_FOR_HIGH_CURRENT", 0},
        {"FAST_OPEN_VCB", 0},
        {"CONTACTOR_2_1_NORMAL_LOAD_Ln", 0},
        {"DEVICE_ID_DI_0", 0},
        {"DEVICE_ID_DI_1", 0},
        {"DEVICE_ID_DI_2", 0},
        {"DEVICE_ID_DI_3", 0},
        {"DEVICE_ID_DI_4", 0},
        {"DEVICE_ID_DI_5", 0},
        {"CABINET_TEST_HW_OK_HEALT_RIOM_2", 0},
        {"EARTHING_SWITCH_SERVICE_POSITION", 0},
        {"EARTHING_SWITCH_EARTH_POSITION", 0},
        {"EARTHING_PANEL_YELLOW_KEY_EXTRACTED", 0},
        {"HV_DISCONNECTOR_MOVING_OR_CLOSE_D", 0},
        {"HV_DISCONNECTOR_CLOSED_E", 0},
        {"HV_DISCONNECTOR_MOVING_OR_OPEN_A", 0},
        {"HV_DISCONNECTOR_OPENED_B", 0},
        {"PLANT_3_1_CB_PROTECTION", 0},
        {"PANTOGRAPH_AIR_PRESSURE_COMPRESSOR", 0},
        {"PANTOGRAPH_COMMAND_MOTOR_COMPRESSOR_INPUT", 0},
        {"PLANT_3_2_CB_PROTECTION", 0},
        {"FAST_OPEN_ADD", 0},
        {"PRESSURE_PS1_SAFEGUARD_ADD", 0},
        {"PANTOGRAPH_INSULATED", 0},
        {"PRESSURE_GOVERNOR_PANTOGRAPH", 0},
        {"POSITION_1_PANTOGRAPH_ENABLED", 0},
        {"POSITION_0_PANTOGRAPH_ISOLATED", 0},
        {"bit41", 0},
        {"bit42", 0},
        {"bit43", 0},
        {"bit44", 0},
        {"bit45", 0},
        {"bit46", 0},
        {"bit47", 0},
        {"TRAFO_NOT_FULL_SPEED", 0},
        {"TRAFO_FULL_SPEED", 0},
        {"TRAFO_NOT_LOW_SPEED", 0},
        {"TRAFO_LOW_SPEED", 0},
        {"PLANT_3_7_CB_PROTECTION", 0},
        {"TRAFO_PRESSURE_RELIEF_DEVICE_TRIP_1", 0},
        {"TRAFO_PRESSURE_RELIEF_DEVICE_TRIP_2", 0},
        {"TRAFO_OIL_FLOW_ALARM", 0},
        {"TRAFO_COOLANT_LEVEL_ALARM", 0},
        {"TRAFO_OVER_TEMP_OTP1_ALARM", 0},
        {"TRAFO_OVER_TEMP_OTP2_ALARM", 0},
        {"VENTILATION_TRANSFORMER_CB_PROTECTION", 0},
        {"HVAC_1_FLOOR_HEATER_1_START", 0},
        {"HVAC_1_FLOOR_HEATER_2_START", 0},
        {"HVAC_1_CB_PROTECTION", 0},
        {"HVAC_2_FLOOR_HEATER_1_START", 0},
        {"HVAC_2_FLOOR_HEATER_2_START", 0},
        {"bit65", 0},
        {"bit66", 0},
        {"bit67", 0},
        {"bit68", 0},
        {"bit69", 0},
        {"bit70", 0},
        {"bit71", 0},
        {"HVAC_2_CB_PROTECTION", 0},
        {"HVAC_1_ON_INPUT", 0},
        {"HVAC_2_ON_INPUT", 0},
        {"THERMOSTAT_HEATING_LEFT_SIDE", 0},
        {"CONTACTOR_HEATING_COMPARTMENT_LEFT_SIDE", 0},
        {"HEATING_COMPARTMENT_LEFT_SIDE_CB_PROTECTION", 0},
        {"THERMOSTAT_HEATING_RIGHT_SIDE", 0},
        {"CONTACTOR_HEATING_COMPARTMENT_RIGHT_SIDE", 0},
        {"HEATING_COMPARTMENT_RIGHT_SIDE_CB_PROTECTION", 0},
        {"PLANT_4_0_CB_PROTECTION", 0},
        {"COMPRESSOR_ON", 0},
        {"MOTOR_COMPRESSOR_CB_PROTECTION", 0},
        {"PLANT_4_4_CB_PROTECTION", 0},
        {"PRESSURE_GOVERNORS_COMPRESSOR_CONTROL_1", 0},
        {"PRESSURE_GOVERNORS_COMPRESSOR_CONTROL_2", 0},
        {"ISOLATION_COCKS_AIR_SUPPLY_UNIT", 0},
        {"PRESSURE_GOVERNOR_BP_NO_EMERGENCY_BRAKE", 0},
        {"MOTOR_COMPRESSOR_CURRENT_MONITORING", 0},
        {"bit90", 0},
        {"bit91", 0},
        {"bit92", 0},
        {"bit93", 0},
        {"bit94", 0},
        {"bit95", 0},
        {"PRESSURE_GOVERNOR_PB_RELEASED", 0},
        {"PRESSURE_GOVERNOR_R_CPRESS__APPL_BO1", 0},
        {"PRESSURE_GOVERNOR_R_CPRESS__APPL_BO2", 0},
        {"ISOLATION_COCKS_PNEUMATIC_BRAKE", 0},
        {"ISOLATION_COCKS_DIRECT_BRAKE", 0},
        {"ISOLATION_COCKS_INDIRECT_BRAKE", 0},
        {"ISOLATION_COCKS_DIRECT_BRAKE_BO1", 0},
        {"ISOLATION_COCKS_DIRECT_BRAKE_BO2", 0},
        {"ISOLATION_COCKS_PB_ISOLATED", 0},
        {"ISOLATION_COCKS_RESERVE", 0},
        {"EBCU_C_FCTOK", 0},
        {"EBCU_SPEED_10_Km_H", 0},
        {"PRESSURE_GOVERNORS_AIR_SUSPENSION_BO1", 0},
        {"PRESSURE_GOVERNORS_AIR_SUSPENSION_BO2", 0},
        {"LOW_MRP_PRESSUR_GOVERNOR", 0},
        {"ZERO_SPEED", 0},
        {"PLANT_4_5_CB_PROTECTION", 0},
        {"CABINET_RIOM_1_CB_PROTECTION", 0},
        {"EMERGENCY_BRAKE_FROM_BCU", 0},
        {"WSP_R_vGt5kmhDoor", 0},
        {"BCU_ZERO_SPEED", 0},
        {"RESERVE", 0},
        {"FIRE_EXTINGUISHER_1_PRESENCE", 0},
        {"FIRE_EXTINGUISHER_2_PRESENCE", 0},
        {"RELAY_CONTROL_EMERGENCY_LOOP", 0},
        {"PLANT_4_7_CB_PROTECTION", 0},
        {"HANDLE_1_PASSENGER_ALARM", 0},
        {"HANDLE_3_PASSENGER_ALARM", 0},
        {"HANDLE_5_PASSENGER_ALARM", 0},
        {"HANDLE_7_PASSENGER_ALARM", 0},
        {"HANDLE_2_PASSENGER_ALARM", 0},
        {"HANDLE_4_PASSENGER_ALARM", 0},
        {"HANDLE_6_PASSENGER_ALARM", 0},
        {"HANDLE_8_PASSENGER_ALARM", 0},
        {"DOOR_1_FULLY_OPENED", 0},
        {"DOOR_2_FULLY_OPENED", 0},
        {"DOOR_3_FULLY_OPENED", 0},
        {"DOOR_4_FULLY_OPENED", 0},
        {"DOOR_5_FULLY_OPENED", 0},
        {"DOOR_6_FULLY_OPENED", 0},
        {"DOOR_7_FULLY_OPENED", 0},
        {"CABINET_RIOM_2_CB_PROTECTION", 0},
        {"ETCS_EMERGENCY_BRAKE_COMMAND_1", 0},
        {"ETCS_EMERGENCY_BRAKE_COMMAND_2", 0},
        {"ETCS_MAIN_POWER_COMMAND", 0},
        {"ETCS_TRACTION_CUT_OFF", 0},
        {"ETCS_REGENERATIVE_BRAKE_INHIBIT", 0},
        {"bit143", 0},
        {"DOOR_8_FULLY_OPENED", 0},
        {"PLANT_5_3_CB_PROTECTION", 0},
        {"PLANT_6_0_CB_PROTECTION", 0},
        {"PLANT_6_5_CB_PROTECTION", 0},
        {"CONTACTOR_VEHICLE_LIGHTS_ON", 0},
        {"CONTACTOR_VEHICLE_HALF_LIGHT", 0},
        {"CONTACTOR_VEHICLE_EMERGENCY_LIGHT", 0},
        {"PLANT_7_0_CB_PROTECTION", 0},
        {"ETCS_EQUIPMENT_POWER_SUPPLY_APPLIED", 0},
        {"PLANT_7_8_CB_PROTECTION", 0},
        {"JRU_FAULT", 0},
        {"ETHERNET_SWITCH_1_PAPIS_ALARM", 0},
        {"ETHERNET_SWITCH_2_PAPIS_ALARM", 0},
        {"ETCS_reserved_1", 0},
        {"ETCS_PANTOGRAPH_COMMAND", 0},
        {"ETCS_AIR_TIGHTNESS", 0},
        {"ETCS_LEFT_DOORS_OPEN_PERMISSION", 0},
        {"ETCS_RIGHT_DOORS_OPEN_PERMISSION", 0},
        {"ETCS_FULL_SERVICE_BRAKING_COMMAND", 0},
        {"bit163", 0},
        {"bit164", 0},
        {"bit165", 0},
        {"CB_PROTECTION_AXLE_BOX", 0},
        {"bit167", 0},
        {"TEMPERATURE_PROBE_RTD_1", 0},
        {"TEMPERATURE_PROBE_RTD_2", 0},
        {"MEASURING_BATTERY_VOLTAGE", 0},
        {"TRANSDUCER_HV_VOLTAGE_VCB_IN", 0},
        {"TRANSDUCER_HV_CURRENT_VCB_IN", 0},
        {"reserved_31", 0}
    };

    /*QStringList table_name = {"oa_vh_riom_ccu_mvb1_inputs", "value"};

    //m_tableWidget.push_back(new QTableWidget());
    m_tableWidget[oa_num][MVB1] = new QTableWidget();
    m_tableWidget[oa_num][MVB1] ->setColumnCount(2);
    m_tableWidget[oa_num][MVB1] ->setRowCount(m_inputs_map[oa_num][MVB1].size());
    m_tableWidget[oa_num][MVB1]->setHorizontalHeaderLabels(table_name);

    int row = 0;
    for (const auto& pair:  m_inputs_map[oa_num][MVB1]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[oa_num][MVB1]->setItem(row, 0, item_name);
        m_tableWidget[oa_num][MVB1]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[oa_num][MVB1]->resizeColumnsToContents();*/

    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[oa_num][MVB1].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[oa_num][MVB1] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[oa_num][MVB1]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[oa_num][MVB1]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[oa_num][MVB1]->setItem(row, column, item_name);
        m_tableWidget[oa_num][MVB1]->setItem(row, column + 1, item_val); // Değer
        item_name->setBackground(QColor("turquoise"));  // Turkuaz
        item_val->setBackground(QColor("turquoise"));  // Turkuaz

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[oa_num][MVB1]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;





}

void Oa_Vh_Riom::init_status_table(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);
    m_inputs_map[oa_num][STATUS0] = {
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
                {"AIM01_Module_Error",0},
                {"AIM01_Heartbeat_error",0},
                {"bit74",0},
                {"bit75",0},
                {"bit76",0},
                {"bit77",0},
                {"bit78",0},
                {"bit79",0},
                {"PTI2037A_Module_Error",0},
                {"PTI2037A_Heartbeat_error",0},
                {"PTI2037A_Channel_1_Status",0},
                {"PTI2037A_Channel_2_Status",0},
                {"PTI2037A_Channel_3_Status",0},
                {"PTI2037A_Channel_4_Status",0},
                {"PTI2037A_Channel_5_Status",0},
                {"PTI2037A_Channel_6_Status",0},
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
                {"HVAC1_CANopen_Fault",0},
                {"HVAC2_CANopen_Fault",0},
                {"bit114",0},
                {"bit115",0},
                {"bit116",0},
                {"bit117",0},
                {"bit118",0},
                {"bit119",0},
                {"reserved_15",0}

    };

    /*QStringList table_name = {"oa_vh_riom_ccu_mvb_status", "value"};

    //m_tableWidget.push_back(new QTableWidget());
    m_tableWidget[oa_num][STATUS0] = new QTableWidget();
    m_tableWidget[oa_num][STATUS0] ->setColumnCount(2);
    m_tableWidget[oa_num][STATUS0] ->setRowCount(m_inputs_map[oa_num][STATUS0].size());
    m_tableWidget[oa_num][STATUS0]->setHorizontalHeaderLabels(table_name);

    int row = 0;
    for (const auto& pair:  m_inputs_map[oa_num][STATUS0]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[oa_num][STATUS0]->setItem(row, 0, item_name);
        m_tableWidget[oa_num][STATUS0]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[oa_num][STATUS0]->resizeColumnsToContents();*/

    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[oa_num][STATUS0].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[oa_num][STATUS0] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[oa_num][STATUS0]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[oa_num][STATUS0]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[oa_num][STATUS0]->setItem(row, column, item_name);
        m_tableWidget[oa_num][STATUS0]->setItem(row, column + 1, item_val); // Değer
        item_name->setBackground(QColor("turquoise"));  // Turkuaz
        item_val->setBackground(QColor("turquoise"));  // Turkuaz

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[oa_num][STATUS0]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[oa_num][STATUS0]->columnCount() ;

}

void Oa_Vh_Riom::update_inputs_map(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);

    m_inputs_map[oa_num][MVB1].at("MANUAL_POWER_SUPPLY_PRIVILEGED_LOAD_Lp")      = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.MANUAL_POWER_SUPPLY_PRIVILEGED_LOAD_Lp;
    m_inputs_map[oa_num][MVB1].at("CONTACTOR_PRIVILEGE_LOAD_Lp")                 = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONTACTOR_PRIVILEGE_LOAD_Lp;
    m_inputs_map[oa_num][MVB1].at("SAFETY_BATTERY_CASE")                         = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.SAFETY_BATTERY_CASE;
    m_inputs_map[oa_num][MVB1].at("SL_APS_START")                                = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.SL_APS_START;
    m_inputs_map[oa_num][MVB1].at("CONVERTER_APS_OK")                            = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONVERTER_APS_OK;
    m_inputs_map[oa_num][MVB1].at("CONVERTER_MV_OK")                             = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONVERTER_MV_OK;
    m_inputs_map[oa_num][MVB1].at("CONVERTER_HV_PRESENCE")                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONVERTER_HV_PRESENCE;
    m_inputs_map[oa_num][MVB1].at("BATTERY_CHARGER_OK")                          = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.BATTERY_CHARGER_OK;
    m_inputs_map[oa_num][MVB1].at("PLANT_3_0_CB_PROTECTION")                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_3_0_CB_PROTECTION;
    m_inputs_map[oa_num][MVB1].at("CONTACTORS_SOCKETS_WORKSHOP_LEFT_INSERTED")   = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONTACTORS_SOCKETS_WORKSHOP_LEFT_INSERTED;
    m_inputs_map[oa_num][MVB1].at("CONTACTORS_SOCKETS_WORKSHOP_RIGHT_INSERTED")  = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONTACTORS_SOCKETS_WORKSHOP_RIGHT_INSERTED;
    m_inputs_map[oa_num][MVB1].at("CONTACTOR_DEGRADE_MODE_MV_OA_CARS")           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONTACTOR_DEGRADE_MODE_MV_OA_CARS;
    m_inputs_map[oa_num][MVB1].at("READY_VCB")                                   = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.READY_VCB;
    m_inputs_map[oa_num][MVB1].at("VCB_CLOSE")                                   = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.VCB_CLOSE;
    m_inputs_map[oa_num][MVB1].at("OPEN_VCB_FOR_HIGH_CURRENT")                   = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.OPEN_VCB_FOR_HIGH_CURRENT;
    m_inputs_map[oa_num][MVB1].at("FAST_OPEN_VCB")                               = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.FAST_OPEN_VCB;
    m_inputs_map[oa_num][MVB1].at("CONTACTOR_2_1_NORMAL_LOAD_Ln")                = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONTACTOR_2_1_NORMAL_LOAD_Ln;
    m_inputs_map[oa_num][MVB1].at("DEVICE_ID_DI_0")                              = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_0;
    m_inputs_map[oa_num][MVB1].at("DEVICE_ID_DI_1")                              = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_1;
    m_inputs_map[oa_num][MVB1].at("DEVICE_ID_DI_2")                              = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_2;
    m_inputs_map[oa_num][MVB1].at("DEVICE_ID_DI_3")                              = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_3;
    m_inputs_map[oa_num][MVB1].at("DEVICE_ID_DI_4")                              = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_4;
    m_inputs_map[oa_num][MVB1].at("DEVICE_ID_DI_5")                              = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_5;
    m_inputs_map[oa_num][MVB1].at("CABINET_TEST_HW_OK_HEALT_RIOM_2")             = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CABINET_TEST_HW_OK_HEALT_RIOM_2;
    m_inputs_map[oa_num][MVB1].at("EARTHING_SWITCH_SERVICE_POSITION")            = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.EARTHING_SWITCH_SERVICE_POSITION;
    m_inputs_map[oa_num][MVB1].at("EARTHING_SWITCH_EARTH_POSITION")              = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.EARTHING_SWITCH_EARTH_POSITION;
    m_inputs_map[oa_num][MVB1].at("EARTHING_PANEL_YELLOW_KEY_EXTRACTED")         = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.EARTHING_PANEL_YELLOW_KEY_EXTRACTED;
    m_inputs_map[oa_num][MVB1].at("HV_DISCONNECTOR_MOVING_OR_CLOSE_D")           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HV_DISCONNECTOR_MOVING_OR_CLOSE_D;
    m_inputs_map[oa_num][MVB1].at("HV_DISCONNECTOR_CLOSED_E")                    = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HV_DISCONNECTOR_CLOSED_E;
    m_inputs_map[oa_num][MVB1].at("HV_DISCONNECTOR_MOVING_OR_OPEN_A")            = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HV_DISCONNECTOR_MOVING_OR_OPEN_A;
    m_inputs_map[oa_num][MVB1].at("HV_DISCONNECTOR_OPENED_B")                    = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HV_DISCONNECTOR_OPENED_B;
    m_inputs_map[oa_num][MVB1].at("PLANT_3_1_CB_PROTECTION")                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_3_1_CB_PROTECTION;
    m_inputs_map[oa_num][MVB1].at("PANTOGRAPH_AIR_PRESSURE_COMPRESSOR")          = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PANTOGRAPH_AIR_PRESSURE_COMPRESSOR;
    m_inputs_map[oa_num][MVB1].at("PANTOGRAPH_COMMAND_MOTOR_COMPRESSOR_INPUT")   = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PANTOGRAPH_COMMAND_MOTOR_COMPRESSOR_INPUT;
    m_inputs_map[oa_num][MVB1].at("PLANT_3_2_CB_PROTECTION")                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_3_2_CB_PROTECTION;
    m_inputs_map[oa_num][MVB1].at("FAST_OPEN_ADD")                               = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.FAST_OPEN_ADD;
    m_inputs_map[oa_num][MVB1].at("PRESSURE_PS1_SAFEGUARD_ADD")                  = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PRESSURE_PS1_SAFEGUARD_ADD;
    m_inputs_map[oa_num][MVB1].at("PANTOGRAPH_INSULATED")                        = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PANTOGRAPH_INSULATED;
    m_inputs_map[oa_num][MVB1].at("PRESSURE_GOVERNOR_PANTOGRAPH")                = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PRESSURE_GOVERNOR_PANTOGRAPH;
    m_inputs_map[oa_num][MVB1].at("POSITION_1_PANTOGRAPH_ENABLED")               = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.POSITION_1_PANTOGRAPH_ENABLED;
    m_inputs_map[oa_num][MVB1].at("POSITION_0_PANTOGRAPH_ISOLATED")              = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.POSITION_0_PANTOGRAPH_ISOLATED;

    m_inputs_map[oa_num][MVB1].at("bit41")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit41;
    m_inputs_map[oa_num][MVB1].at("bit42")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit42;
    m_inputs_map[oa_num][MVB1].at("bit43")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit43;
    m_inputs_map[oa_num][MVB1].at("bit44")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit44;
    m_inputs_map[oa_num][MVB1].at("bit45")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit45;
    m_inputs_map[oa_num][MVB1].at("bit46")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit46;
    m_inputs_map[oa_num][MVB1].at("bit47")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit47;
    m_inputs_map[oa_num][MVB1].at("TRAFO_NOT_FULL_SPEED")                        = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRAFO_NOT_FULL_SPEED;
    m_inputs_map[oa_num][MVB1].at("TRAFO_FULL_SPEED")                            = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRAFO_FULL_SPEED;
    m_inputs_map[oa_num][MVB1].at("TRAFO_NOT_LOW_SPEED")                         = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRAFO_NOT_LOW_SPEED;
    m_inputs_map[oa_num][MVB1].at("TRAFO_LOW_SPEED")                             = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRAFO_LOW_SPEED;
    m_inputs_map[oa_num][MVB1].at("PLANT_3_7_CB_PROTECTION")                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_3_7_CB_PROTECTION;
    m_inputs_map[oa_num][MVB1].at("TRAFO_PRESSURE_RELIEF_DEVICE_TRIP_1")         = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRAFO_PRESSURE_RELIEF_DEVICE_TRIP_1;
    m_inputs_map[oa_num][MVB1].at("TRAFO_PRESSURE_RELIEF_DEVICE_TRIP_2")         = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRAFO_PRESSURE_RELIEF_DEVICE_TRIP_2;
    m_inputs_map[oa_num][MVB1].at("TRAFO_OIL_FLOW_ALARM")                        = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRAFO_OIL_FLOW_ALARM;
    m_inputs_map[oa_num][MVB1].at("TRAFO_COOLANT_LEVEL_ALARM")                   = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRAFO_COOLANT_LEVEL_ALARM;
    m_inputs_map[oa_num][MVB1].at("TRAFO_OVER_TEMP_OTP1_ALARM")                  = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRAFO_OVER_TEMP_OTP1_ALARM;
    m_inputs_map[oa_num][MVB1].at("TRAFO_OVER_TEMP_OTP2_ALARM")                  = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRAFO_OVER_TEMP_OTP2_ALARM;
    m_inputs_map[oa_num][MVB1].at("VENTILATION_TRANSFORMER_CB_PROTECTION")       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.VENTILATION_TRANSFORMER_CB_PROTECTION;
    m_inputs_map[oa_num][MVB1].at("HVAC_1_FLOOR_HEATER_1_START")                 = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HVAC_1_FLOOR_HEATER_1_START;
    m_inputs_map[oa_num][MVB1].at("HVAC_1_FLOOR_HEATER_2_START")                 = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HVAC_1_FLOOR_HEATER_2_START;
    m_inputs_map[oa_num][MVB1].at("HVAC_1_CB_PROTECTION")                        = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HVAC_1_CB_PROTECTION;
    m_inputs_map[oa_num][MVB1].at("HVAC_2_FLOOR_HEATER_1_START")                 = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HVAC_2_FLOOR_HEATER_1_START;
    m_inputs_map[oa_num][MVB1].at("HVAC_2_FLOOR_HEATER_2_START")                 = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HVAC_2_FLOOR_HEATER_2_START;
    m_inputs_map[oa_num][MVB1].at("bit65")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit65;
    m_inputs_map[oa_num][MVB1].at("bit66")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit66;
    m_inputs_map[oa_num][MVB1].at("bit67")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit67;
    m_inputs_map[oa_num][MVB1].at("bit68")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit68;
    m_inputs_map[oa_num][MVB1].at("bit69")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit69;
    m_inputs_map[oa_num][MVB1].at("bit70")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit70;
    m_inputs_map[oa_num][MVB1].at("bit71")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit71;
    m_inputs_map[oa_num][MVB1].at("HVAC_2_CB_PROTECTION")                        = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HVAC_2_CB_PROTECTION;
    m_inputs_map[oa_num][MVB1].at("HVAC_1_ON_INPUT")                             = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HVAC_1_ON_INPUT;
    m_inputs_map[oa_num][MVB1].at("HVAC_2_ON_INPUT")                             = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HVAC_2_ON_INPUT;
    m_inputs_map[oa_num][MVB1].at("THERMOSTAT_HEATING_LEFT_SIDE")                = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.THERMOSTAT_HEATING_LEFT_SIDE;
    m_inputs_map[oa_num][MVB1].at("CONTACTOR_HEATING_COMPARTMENT_LEFT_SIDE")     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONTACTOR_HEATING_COMPARTMENT_LEFT_SIDE;
    m_inputs_map[oa_num][MVB1].at("HEATING_COMPARTMENT_LEFT_SIDE_CB_PROTECTION") = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HEATING_COMPARTMENT_LEFT_SIDE_CB_PROTECTION;
    m_inputs_map[oa_num][MVB1].at("THERMOSTAT_HEATING_RIGHT_SIDE")               = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.THERMOSTAT_HEATING_RIGHT_SIDE;
    m_inputs_map[oa_num][MVB1].at("CONTACTOR_HEATING_COMPARTMENT_RIGHT_SIDE")    = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONTACTOR_HEATING_COMPARTMENT_RIGHT_SIDE;
    m_inputs_map[oa_num][MVB1].at("HEATING_COMPARTMENT_RIGHT_SIDE_CB_PROTECTION")= m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HEATING_COMPARTMENT_RIGHT_SIDE_CB_PROTECTION;
    m_inputs_map[oa_num][MVB1].at("PLANT_4_0_CB_PROTECTION")                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_4_0_CB_PROTECTION;
    m_inputs_map[oa_num][MVB1].at("COMPRESSOR_ON")                               = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.COMPRESSOR_ON;
    m_inputs_map[oa_num][MVB1].at("MOTOR_COMPRESSOR_CB_PROTECTION")              = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.MOTOR_COMPRESSOR_CB_PROTECTION;
    m_inputs_map[oa_num][MVB1].at("PLANT_4_4_CB_PROTECTION")                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_4_4_CB_PROTECTION;
    m_inputs_map[oa_num][MVB1].at("PRESSURE_GOVERNORS_COMPRESSOR_CONTROL_1")     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PRESSURE_GOVERNORS_COMPRESSOR_CONTROL_1;
    m_inputs_map[oa_num][MVB1].at("PRESSURE_GOVERNORS_COMPRESSOR_CONTROL_2")     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PRESSURE_GOVERNORS_COMPRESSOR_CONTROL_2;
    m_inputs_map[oa_num][MVB1].at("ISOLATION_COCKS_AIR_SUPPLY_UNIT")             = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ISOLATION_COCKS_AIR_SUPPLY_UNIT;
    m_inputs_map[oa_num][MVB1].at("PRESSURE_GOVERNOR_BP_NO_EMERGENCY_BRAKE")     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PRESSURE_GOVERNOR_BP_NO_EMERGENCY_BRAKE;
    m_inputs_map[oa_num][MVB1].at("MOTOR_COMPRESSOR_CURRENT_MONITORING")         = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.MOTOR_COMPRESSOR_CURRENT_MONITORING;
    m_inputs_map[oa_num][MVB1].at("bit90")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit90;
    m_inputs_map[oa_num][MVB1].at("bit91")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit91;
    m_inputs_map[oa_num][MVB1].at("bit92")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit92;
    m_inputs_map[oa_num][MVB1].at("bit93")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit93;
    m_inputs_map[oa_num][MVB1].at("bit94")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit94;
    m_inputs_map[oa_num][MVB1].at("bit95")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit95;


    m_inputs_map[oa_num][MVB1].at("PRESSURE_GOVERNOR_PB_RELEASED")               = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PRESSURE_GOVERNOR_PB_RELEASED;
    m_inputs_map[oa_num][MVB1].at("PRESSURE_GOVERNOR_R_CPRESS__APPL_BO1")        = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PRESSURE_GOVERNOR_R_CPRESS__APPL_BO1;
    m_inputs_map[oa_num][MVB1].at("PRESSURE_GOVERNOR_R_CPRESS__APPL_BO2")        = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PRESSURE_GOVERNOR_R_CPRESS__APPL_BO2;
    m_inputs_map[oa_num][MVB1].at("ISOLATION_COCKS_PNEUMATIC_BRAKE")             = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ISOLATION_COCKS_PNEUMATIC_BRAKE;
    m_inputs_map[oa_num][MVB1].at("ISOLATION_COCKS_DIRECT_BRAKE")                = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ISOLATION_COCKS_DIRECT_BRAKE;
    m_inputs_map[oa_num][MVB1].at("ISOLATION_COCKS_INDIRECT_BRAKE")              = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ISOLATION_COCKS_INDIRECT_BRAKE;
    m_inputs_map[oa_num][MVB1].at("ISOLATION_COCKS_DIRECT_BRAKE_BO1")            = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ISOLATION_COCKS_DIRECT_BRAKE_BO1;
    m_inputs_map[oa_num][MVB1].at("ISOLATION_COCKS_DIRECT_BRAKE_BO2")            = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ISOLATION_COCKS_DIRECT_BRAKE_BO2;
    m_inputs_map[oa_num][MVB1].at("ISOLATION_COCKS_PB_ISOLATED")                 = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ISOLATION_COCKS_PB_ISOLATED;
    m_inputs_map[oa_num][MVB1].at("ISOLATION_COCKS_RESERVE")                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ISOLATION_COCKS_RESERVE;
    m_inputs_map[oa_num][MVB1].at("EBCU_C_FCTOK")                                = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.EBCU_C_FCTOK;
    m_inputs_map[oa_num][MVB1].at("EBCU_SPEED_10_Km_H")                          = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.EBCU_SPEED_10_Km_H;
    m_inputs_map[oa_num][MVB1].at("PRESSURE_GOVERNORS_AIR_SUSPENSION_BO1")       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PRESSURE_GOVERNORS_AIR_SUSPENSION_BO1;
    m_inputs_map[oa_num][MVB1].at("PRESSURE_GOVERNORS_AIR_SUSPENSION_BO2")       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PRESSURE_GOVERNORS_AIR_SUSPENSION_BO2;
    m_inputs_map[oa_num][MVB1].at("LOW_MRP_PRESSUR_GOVERNOR")                    = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.LOW_MRP_PRESSUR_GOVERNOR;
    m_inputs_map[oa_num][MVB1].at("ZERO_SPEED")                                  = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ZERO_SPEED;
    m_inputs_map[oa_num][MVB1].at("PLANT_4_5_CB_PROTECTION")                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_4_5_CB_PROTECTION;
    m_inputs_map[oa_num][MVB1].at("CABINET_RIOM_1_CB_PROTECTION")                = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CABINET_RIOM_1_CB_PROTECTION;
    m_inputs_map[oa_num][MVB1].at("EMERGENCY_BRAKE_FROM_BCU")                    = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.EMERGENCY_BRAKE_FROM_BCU;
    m_inputs_map[oa_num][MVB1].at("WSP_R_vGt5kmhDoor")                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.WSP_R_vGt5kmhDoor;
    m_inputs_map[oa_num][MVB1].at("BCU_ZERO_SPEED")                              = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.BCU_ZERO_SPEED;
    m_inputs_map[oa_num][MVB1].at("RESERVE")                                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.RESERVE;
    m_inputs_map[oa_num][MVB1].at("FIRE_EXTINGUISHER_1_PRESENCE")                = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.FIRE_EXTINGUISHER_1_PRESENCE;
    m_inputs_map[oa_num][MVB1].at("FIRE_EXTINGUISHER_2_PRESENCE")                = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.FIRE_EXTINGUISHER_2_PRESENCE;
    m_inputs_map[oa_num][MVB1].at("RELAY_CONTROL_EMERGENCY_LOOP")                = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.RELAY_CONTROL_EMERGENCY_LOOP;
    m_inputs_map[oa_num][MVB1].at("PLANT_4_7_CB_PROTECTION")                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_4_7_CB_PROTECTION;
    m_inputs_map[oa_num][MVB1].at("HANDLE_1_PASSENGER_ALARM")                    = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HANDLE_1_PASSENGER_ALARM;
    m_inputs_map[oa_num][MVB1].at("HANDLE_3_PASSENGER_ALARM")                    = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HANDLE_3_PASSENGER_ALARM;
    m_inputs_map[oa_num][MVB1].at("HANDLE_5_PASSENGER_ALARM")                    = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HANDLE_5_PASSENGER_ALARM;
    m_inputs_map[oa_num][MVB1].at("HANDLE_7_PASSENGER_ALARM")                    = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HANDLE_7_PASSENGER_ALARM;
    m_inputs_map[oa_num][MVB1].at("HANDLE_2_PASSENGER_ALARM")                    = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HANDLE_2_PASSENGER_ALARM;
    m_inputs_map[oa_num][MVB1].at("HANDLE_4_PASSENGER_ALARM")                    = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HANDLE_4_PASSENGER_ALARM;
    m_inputs_map[oa_num][MVB1].at("HANDLE_6_PASSENGER_ALARM")                    = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HANDLE_6_PASSENGER_ALARM;
    m_inputs_map[oa_num][MVB1].at("HANDLE_8_PASSENGER_ALARM")                    = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HANDLE_8_PASSENGER_ALARM;
    m_inputs_map[oa_num][MVB1].at("DOOR_1_FULLY_OPENED")                         = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DOOR_1_FULLY_OPENED;
    m_inputs_map[oa_num][MVB1].at("DOOR_2_FULLY_OPENED")                         = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DOOR_2_FULLY_OPENED;
    m_inputs_map[oa_num][MVB1].at("DOOR_3_FULLY_OPENED")                         = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DOOR_3_FULLY_OPENED;
    m_inputs_map[oa_num][MVB1].at("DOOR_4_FULLY_OPENED")                         = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DOOR_4_FULLY_OPENED;
    m_inputs_map[oa_num][MVB1].at("DOOR_5_FULLY_OPENED")                         = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DOOR_5_FULLY_OPENED;
    m_inputs_map[oa_num][MVB1].at("DOOR_6_FULLY_OPENED")                         = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DOOR_6_FULLY_OPENED;
    m_inputs_map[oa_num][MVB1].at("DOOR_7_FULLY_OPENED")                         = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DOOR_7_FULLY_OPENED;
    m_inputs_map[oa_num][MVB1].at("CABINET_RIOM_2_CB_PROTECTION")               = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CABINET_RIOM_2_CB_PROTECTION;
    m_inputs_map[oa_num][MVB1].at("ETCS_EMERGENCY_BRAKE_COMMAND_1")              = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_EMERGENCY_BRAKE_COMMAND_1;
    m_inputs_map[oa_num][MVB1].at("ETCS_EMERGENCY_BRAKE_COMMAND_2")              = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_EMERGENCY_BRAKE_COMMAND_2;
    m_inputs_map[oa_num][MVB1].at("ETCS_MAIN_POWER_COMMAND")                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_MAIN_POWER_COMMAND;
    m_inputs_map[oa_num][MVB1].at("ETCS_TRACTION_CUT_OFF")                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_TRACTION_CUT_OFF;
    m_inputs_map[oa_num][MVB1].at("ETCS_REGENERATIVE_BRAKE_INHIBIT")             = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_REGENERATIVE_BRAKE_INHIBIT;
    m_inputs_map[oa_num][MVB1].at("bit143")                                      = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit143;
    m_inputs_map[oa_num][MVB1].at("DOOR_8_FULLY_OPENED")                         = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DOOR_8_FULLY_OPENED;
    m_inputs_map[oa_num][MVB1].at("PLANT_5_3_CB_PROTECTION")                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_5_3_CB_PROTECTION;
    m_inputs_map[oa_num][MVB1].at("PLANT_6_0_CB_PROTECTION")                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_6_0_CB_PROTECTION;
    m_inputs_map[oa_num][MVB1].at("PLANT_6_5_CB_PROTECTION")                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_6_5_CB_PROTECTION;
    m_inputs_map[oa_num][MVB1].at("CONTACTOR_VEHICLE_LIGHTS_ON")                 = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONTACTOR_VEHICLE_LIGHTS_ON;
    m_inputs_map[oa_num][MVB1].at("CONTACTOR_VEHICLE_HALF_LIGHT")                = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONTACTOR_VEHICLE_HALF_LIGHT;
    m_inputs_map[oa_num][MVB1].at("CONTACTOR_VEHICLE_EMERGENCY_LIGHT")           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONTACTOR_VEHICLE_EMERGENCY_LIGHT;
    m_inputs_map[oa_num][MVB1].at("PLANT_7_0_CB_PROTECTION")                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_7_0_CB_PROTECTION;
    m_inputs_map[oa_num][MVB1].at("ETCS_EQUIPMENT_POWER_SUPPLY_APPLIED")         = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_EQUIPMENT_POWER_SUPPLY_APPLIED;
    m_inputs_map[oa_num][MVB1].at("PLANT_7_8_CB_PROTECTION")                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_7_8_CB_PROTECTION;
    m_inputs_map[oa_num][MVB1].at("JRU_FAULT")                                   = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.JRU_FAULT;
    m_inputs_map[oa_num][MVB1].at("ETHERNET_SWITCH_1_PAPIS_ALARM")               = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETHERNET_SWITCH_1_PAPIS_ALARM;
    m_inputs_map[oa_num][MVB1].at("ETHERNET_SWITCH_2_PAPIS_ALARM")               = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETHERNET_SWITCH_2_PAPIS_ALARM;
    //m_inputs_map[oa_nu[MVB1]m].at("ETCS_ISOLATION_SIGNAL")                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_ISOLATION_SIGNAL;
    m_inputs_map[oa_num][MVB1].at("ETCS_reserved_1")                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_reserved_1;
    m_inputs_map[oa_num][MVB1].at("ETCS_PANTOGRAPH_COMMAND")                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_PANTOGRAPH_COMMAND;
    m_inputs_map[oa_num][MVB1].at("ETCS_AIR_TIGHTNESS")                          = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_AIR_TIGHTNESS;
    m_inputs_map[oa_num][MVB1].at("ETCS_LEFT_DOORS_OPEN_PERMISSION")             = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_LEFT_DOORS_OPEN_PERMISSION;
    m_inputs_map[oa_num][MVB1].at("ETCS_RIGHT_DOORS_OPEN_PERMISSION")            = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_RIGHT_DOORS_OPEN_PERMISSION;
    //m_inputs_map[oa_nu[MVB1]m].at("bit162")                                      = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit162;
    m_inputs_map[oa_num][MVB1].at("ETCS_FULL_SERVICE_BRAKING_COMMAND")           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_FULL_SERVICE_BRAKING_COMMAND;
    m_inputs_map[oa_num][MVB1].at("bit163")                                      = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit163;
    m_inputs_map[oa_num][MVB1].at("bit164")                                      = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit164;
    m_inputs_map[oa_num][MVB1].at("bit165")                                      = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit165;
    m_inputs_map[oa_num][MVB1].at("CB_PROTECTION_AXLE_BOX")                      = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CB_PROTECTION_AXLE_BOX;
    m_inputs_map[oa_num][MVB1].at("bit167")                                      = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit167;
    m_inputs_map[oa_num][MVB1].at("MEASURING_BATTERY_VOLTAGE")                   = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.MEASURING_BATTERY_VOLTAGE;
    m_inputs_map[oa_num][MVB1].at("TRANSDUCER_HV_VOLTAGE_VCB_IN")                = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRANSDUCER_HV_VOLTAGE_VCB_IN;
    m_inputs_map[oa_num][MVB1].at("TRANSDUCER_HV_CURRENT_VCB_IN")                = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRANSDUCER_HV_CURRENT_VCB_IN;
    m_inputs_map[oa_num][MVB1].at("TEMPERATURE_PROBE_RTD_1")                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TEMPERATURE_PROBE_RTD_1;
    m_inputs_map[oa_num][MVB1].at("TEMPERATURE_PROBE_RTD_2")                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TEMPERATURE_PROBE_RTD_2;
    //m_inputs_map[oa_nu[MVB1]m].at("reserved_29")                                 = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.reserved_29;
    //m_inputs_map[oa_nu[MVB1]m].at("reserved_30")                                 = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.reserved_30;
    m_inputs_map[oa_num][MVB1].at("reserved_31")                                 = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.reserved_31;

}


void Oa_Vh_Riom::update_status_map(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);
    m_inputs_map[oa_num][STATUS0].at("lifesign")                                                        = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.lifesign;
    m_inputs_map[oa_num][STATUS0].at("DIO01_Module_Error")                                              = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO01_Module_Error;
    m_inputs_map[oa_num][STATUS0].at("DIO01_Output_Overcurrent")                                        = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO01_Output_Overcurrent;
    m_inputs_map[oa_num][STATUS0].at("DIO01_Heartbeat_error")                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO01_Heartbeat_error;
    m_inputs_map[oa_num][STATUS0].at("DIO01_Group_1_Voltage_error")                                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO01_Group_1_Voltage_error;
    m_inputs_map[oa_num][STATUS0].at("DIO01_Group_2_Voltage_error")                                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO01_Group_2_Voltage_error;
    m_inputs_map[oa_num][STATUS0].at("DIO01_Board_Temperature_error")                                   = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO01_Board_Temperature_error;
    m_inputs_map[oa_num][STATUS0].at("bit22")                                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit22;
    m_inputs_map[oa_num][STATUS0].at("bit23")                                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit23;
    m_inputs_map[oa_num][STATUS0].at("DIO02_Module_Error")                                              = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO02_Module_Error;
    m_inputs_map[oa_num][STATUS0].at("DIO02_Output_Overcurrent")                                        = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO02_Output_Overcurrent;
    m_inputs_map[oa_num][STATUS0].at("DIO02_Heartbeat_error")                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO02_Heartbeat_error;
    m_inputs_map[oa_num][STATUS0].at("DIO02_Group_1_Voltage_error")                                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO02_Group_1_Voltage_error;
    m_inputs_map[oa_num][STATUS0].at("DIO02_Group_2_Voltage_error")                                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO02_Group_2_Voltage_error;
    m_inputs_map[oa_num][STATUS0].at("DIO02_Board_Temperature_error")                                   = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO02_Board_Temperature_error;
    m_inputs_map[oa_num][STATUS0].at("bit30")                                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit30;
    m_inputs_map[oa_num][STATUS0].at("bit31")                                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit31;
    m_inputs_map[oa_num][STATUS0].at("DIO03_Module_Error")                                              = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO03_Module_Error;
    m_inputs_map[oa_num][STATUS0].at("DIO03_Output_Overcurrent")                                        = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO03_Output_Overcurrent;
    m_inputs_map[oa_num][STATUS0].at("DIO03_Heartbeat_error")                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO03_Heartbeat_error;
    m_inputs_map[oa_num][STATUS0].at("DIO03_Group_1_Voltage_error")                                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO03_Group_1_Voltage_error;
    m_inputs_map[oa_num][STATUS0].at("DIO03_Group_2_Voltage_error")                                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO03_Group_2_Voltage_error;
    m_inputs_map[oa_num][STATUS0].at("DIO03_Board_Temperature_error")                                   = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO03_Board_Temperature_error;
    m_inputs_map[oa_num][STATUS0].at("bit38")                                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit38;
    m_inputs_map[oa_num][STATUS0].at("bit39")                                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit39;
    m_inputs_map[oa_num][STATUS0].at("DIO04_Module_Error")                                              = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO04_Module_Error;
    m_inputs_map[oa_num][STATUS0].at("DIO04_Output_Overcurrent")                                        = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO04_Output_Overcurrent;
    m_inputs_map[oa_num][STATUS0].at("DIO04_Heartbeat_error")                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO04_Heartbeat_error;
    m_inputs_map[oa_num][STATUS0].at("DIO04_Group_1_Voltage_error")                                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO04_Group_1_Voltage_error;
    m_inputs_map[oa_num][STATUS0].at("DIO04_Group_2_Voltage_error")                                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO04_Group_2_Voltage_error;
    m_inputs_map[oa_num][STATUS0].at("DIO04_Board_Temperature_error")                                   = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO04_Board_Temperature_error;
    m_inputs_map[oa_num][STATUS0].at("bit46")                                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit46;
    m_inputs_map[oa_num][STATUS0].at("bit47")                                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit47;
    m_inputs_map[oa_num][STATUS0].at("DIO05_Module_Error")                                              = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO05_Module_Error;
    m_inputs_map[oa_num][STATUS0].at("DIO05_Output_Overcurrent")                                        = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO05_Output_Overcurrent;
    m_inputs_map[oa_num][STATUS0].at("DIO05_Heartbeat_error")                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO05_Heartbeat_error;
    m_inputs_map[oa_num][STATUS0].at("DIO05_Group_1_Voltage_error")                                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO05_Group_1_Voltage_error;
    m_inputs_map[oa_num][STATUS0].at("DIO05_Group_2_Voltage_error")                                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO05_Group_2_Voltage_error;
    m_inputs_map[oa_num][STATUS0].at("DIO05_Board_Temperature_error")                                   = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO05_Board_Temperature_error;
    m_inputs_map[oa_num][STATUS0].at("bit54")                                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit54;
    m_inputs_map[oa_num][STATUS0].at("bit55")                                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit55;
    m_inputs_map[oa_num][STATUS0].at("DIO06_Module_Error")                                              = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO06_Module_Error;
    m_inputs_map[oa_num][STATUS0].at("DIO06_Output_Overcurrent")                                        = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO06_Output_Overcurrent;
    m_inputs_map[oa_num][STATUS0].at("DIO06_Heartbeat_error")                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO06_Heartbeat_error;
    m_inputs_map[oa_num][STATUS0].at("DIO06_Group_1_Voltage_error")                                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO06_Group_1_Voltage_error;
    m_inputs_map[oa_num][STATUS0].at("DIO06_Group_2_Voltage_error")                                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO06_Group_2_Voltage_error;
    m_inputs_map[oa_num][STATUS0].at("DIO06_Board_Temperature_error")                                   = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO06_Board_Temperature_error;
    m_inputs_map[oa_num][STATUS0].at("bit62")                                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit62;
    m_inputs_map[oa_num][STATUS0].at("bit63")                                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit63;
    m_inputs_map[oa_num][STATUS0].at("DIO07_Module_Error")                                              = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO07_Module_Error;
    m_inputs_map[oa_num][STATUS0].at("DIO07_Output_Overcurrent")                                        = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO07_Output_Overcurrent;
    m_inputs_map[oa_num][STATUS0].at("DIO07_Heartbeat_error")                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO07_Heartbeat_error;
    m_inputs_map[oa_num][STATUS0].at("DIO07_Group_1_Voltage_error")                                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO07_Group_1_Voltage_error;
    m_inputs_map[oa_num][STATUS0].at("DIO07_Group_2_Voltage_error")                                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO07_Group_2_Voltage_error;
    m_inputs_map[oa_num][STATUS0].at("DIO07_Board_Temperature_error")                                   = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO07_Board_Temperature_error;
    m_inputs_map[oa_num][STATUS0].at("bit70")                                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit70;
    m_inputs_map[oa_num][STATUS0].at("bit71")                                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit71;
    m_inputs_map[oa_num][STATUS0].at("AIM01_Module_Error")                                              = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.AIM01_Module_Error;
    m_inputs_map[oa_num][STATUS0].at("AIM01_Heartbeat_error")                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.AIM01_Heartbeat_error;
    m_inputs_map[oa_num][STATUS0].at("bit74")                                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit74;
    m_inputs_map[oa_num][STATUS0].at("bit75")                                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit75;
    m_inputs_map[oa_num][STATUS0].at("bit76")                                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit76;
    m_inputs_map[oa_num][STATUS0].at("bit77")                                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit77;
    m_inputs_map[oa_num][STATUS0].at("bit78")                                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit78;
    m_inputs_map[oa_num][STATUS0].at("bit79")                                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit79;
    m_inputs_map[oa_num][STATUS0].at("PTI2037A_Module_Error")                                           = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.PTI2037A_Module_Error;
    m_inputs_map[oa_num][STATUS0].at("PTI2037A_Heartbeat_error")                                        = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.PTI2037A_Heartbeat_error;
    m_inputs_map[oa_num][STATUS0].at("PTI2037A_Channel_1_Status")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.PTI2037A_Channel_1_Status;
    m_inputs_map[oa_num][STATUS0].at("PTI2037A_Channel_2_Status")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.PTI2037A_Channel_2_Status;
    m_inputs_map[oa_num][STATUS0].at("PTI2037A_Channel_3_Status")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.PTI2037A_Channel_3_Status;
    m_inputs_map[oa_num][STATUS0].at("PTI2037A_Channel_4_Status")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.PTI2037A_Channel_4_Status;
    m_inputs_map[oa_num][STATUS0].at("PTI2037A_Channel_5_Status")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.PTI2037A_Channel_5_Status;
    m_inputs_map[oa_num][STATUS0].at("PTI2037A_Channel_6_Status")                                       = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.PTI2037A_Channel_6_Status;
    m_inputs_map[oa_num][STATUS0].at("reserved_11")                                                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.reserved_11;
    m_inputs_map[oa_num][STATUS0].at("reserved_12")                                                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.reserved_12;
    m_inputs_map[oa_num][STATUS0].at("R1_DCU_CANopen_Fault")                                            = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.R1_DCU_CANopen_Fault;
    m_inputs_map[oa_num][STATUS0].at("R2_DCU_CANopen_Fault")                                            = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.R2_DCU_CANopen_Fault;
    m_inputs_map[oa_num][STATUS0].at("R3_DCU_CANopen_Fault")                                            = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.R3_DCU_CANopen_Fault;
    m_inputs_map[oa_num][STATUS0].at("R4_DCU_CANopen_Fault")                                            = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.R4_DCU_CANopen_Fault;
    m_inputs_map[oa_num][STATUS0].at("L1_DCU_CANopen_Fault")                                            = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.L1_DCU_CANopen_Fault;
    m_inputs_map[oa_num][STATUS0].at("L2_DCU_CANopen_Fault")                                            = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.L2_DCU_CANopen_Fault;
    m_inputs_map[oa_num][STATUS0].at("L3_DCU_CANopen_Fault")                                            = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.L3_DCU_CANopen_Fault;
    m_inputs_map[oa_num][STATUS0].at("L4_DCU_CANopen_Fault")                                            = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.L4_DCU_CANopen_Fault;
    m_inputs_map[oa_num][STATUS0].at("HVAC1_CANopen_Fault")                                             = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.HVAC1_CANopen_Fault;
    m_inputs_map[oa_num][STATUS0].at("HVAC2_CANopen_Fault")                                             = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.HVAC2_CANopen_Fault;
    m_inputs_map[oa_num][STATUS0].at("bit114")                                                          = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit114;
    m_inputs_map[oa_num][STATUS0].at("bit115")                                                          = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit115;
    m_inputs_map[oa_num][STATUS0].at("bit116")                                                          = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit116;
    m_inputs_map[oa_num][STATUS0].at("bit117")                                                          = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit117;
    m_inputs_map[oa_num][STATUS0].at("bit118")                                                          = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit118;
    m_inputs_map[oa_num][STATUS0].at("bit119")                                                          = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit119;
    m_inputs_map[oa_num][STATUS0].at("reserved_15")                                                     = m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.reserved_15;




}









void Oa_Vh_Riom::update_table(OA_VEHICLE_NUM oa_x_num,MVB_NUM mvb_num)
{
    int oa_num = static_cast<int>(oa_x_num);
    for(const auto & map:m_inputs_map[oa_num][mvb_num]){
        utils::setTableWidgetValueByNameWithoutColumn(m_tableWidget[oa_num][mvb_num], map.first, map.second );
    }


}

void Oa_Vh_Riom::set_data_struct(const QByteArray &input, const OA_VEHICLE_NUM &oa_x_num)
{
    //int oa_num = static_cast<int>(oa_x_num);
    qDebug() << "azdan az çoktan çok " ;
    qDebug() << "size of input " << input.size();
    qDebug() << "Gelen input verileri :  " << input;
    //qDebug() << "Gelen input veri tipi : " << typeof(input);


    int oa_num = static_cast<int>(oa_x_num);
    qDebug() << "bassana lan şunu sizeof(m_oa_x_jru[oa_num])  " << sizeof(m_oa_x_vh_riom[oa_num]);

    if (input.size() == sizeof(m_oa_x_vh_riom[oa_num])) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        //memcpy(&m_oa_x_etcs[oa_num], input.constData(), sizeof(m_oa_x_etcs[oa_num]));

        qDebug() << "SIZE of MVB1 :  " << sizeof(m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bytes);

        // İlk alanı kopyala
        memcpy(&m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bytes, input.constData(), sizeof(m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bytes));
        update_status_map(oa_x_num);
        update_table(oa_x_num,STATUS0);

        // İkinci alanı kopyala
        memcpy(&m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bytes, input.constData() + sizeof(m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bytes),sizeof(m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bytes));
        update_inputs_map(oa_x_num);
        update_table(oa_x_num,MVB1);


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


void Oa_Vh_Riom::update_struct_with_map(OA_VEHICLE_NUM oa_x_num, MVB_NUM mvb_num)
{
    qDebug() << "UPDATE STRUCT WITH MAP" ;
    int oa_num = static_cast<int>(oa_x_num);
    // Define a lambda function to reduce redundancy
    auto setInputMap = [&](const QString& signal_name) {
        m_inputs_map[oa_num][mvb_num][signal_name] = utils::getTableWidgetValueByNameWithoutColumn(m_tableWidget[oa_num][mvb_num], signal_name).toInt();
    };

    // update map with given tableWidget values
    for(const auto& map : m_inputs_map[oa_num][mvb_num])
    {
        setInputMap(map.first);
        //qDebug() << "map.first:" << map.first << "val:" << map.second;
    }
    // set struct parameters with given updated map parameters
    set_inputs_struct(oa_x_num);
    set_status_struct(oa_x_num);

}

void Oa_Vh_Riom::set_inputs_struct(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);

    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.MANUAL_POWER_SUPPLY_PRIVILEGED_LOAD_Lp           = m_inputs_map[oa_num][MVB1].at("MANUAL_POWER_SUPPLY_PRIVILEGED_LOAD_Lp");
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONTACTOR_PRIVILEGE_LOAD_Lp                      = m_inputs_map[oa_num][MVB1].at("CONTACTOR_PRIVILEGE_LOAD_Lp");
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.SAFETY_BATTERY_CASE                              = m_inputs_map[oa_num][MVB1].at("SAFETY_BATTERY_CASE");
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.SL_APS_START                                     = m_inputs_map[oa_num][MVB1].at("SL_APS_START");
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONVERTER_APS_OK                                 = m_inputs_map[oa_num][MVB1].at("CONVERTER_APS_OK") ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONVERTER_MV_OK                                  = m_inputs_map[oa_num][MVB1].at("CONVERTER_MV_OK")   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONVERTER_HV_PRESENCE                            = m_inputs_map[oa_num][MVB1].at("CONVERTER_HV_PRESENCE") ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.BATTERY_CHARGER_OK                               = m_inputs_map[oa_num][MVB1].at("BATTERY_CHARGER_OK");
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_3_0_CB_PROTECTION                          = m_inputs_map[oa_num][MVB1].at("PLANT_3_0_CB_PROTECTION")  ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONTACTORS_SOCKETS_WORKSHOP_LEFT_INSERTED        = m_inputs_map[oa_num][MVB1].at("CONTACTORS_SOCKETS_WORKSHOP_LEFT_INSERTED");
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONTACTORS_SOCKETS_WORKSHOP_RIGHT_INSERTED       = m_inputs_map[oa_num][MVB1].at("CONTACTORS_SOCKETS_WORKSHOP_RIGHT_INSERTED") ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONTACTOR_DEGRADE_MODE_MV_OA_CARS                = m_inputs_map[oa_num][MVB1].at("CONTACTOR_DEGRADE_MODE_MV_OA_CARS") ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.READY_VCB                                        = m_inputs_map[oa_num][MVB1].at("READY_VCB");
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.VCB_CLOSE                                        = m_inputs_map[oa_num][MVB1].at("VCB_CLOSE") ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.OPEN_VCB_FOR_HIGH_CURRENT                        = m_inputs_map[oa_num][MVB1].at("OPEN_VCB_FOR_HIGH_CURRENT") ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.FAST_OPEN_VCB                                    = m_inputs_map[oa_num][MVB1].at("FAST_OPEN_VCB")                               ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONTACTOR_2_1_NORMAL_LOAD_Ln                     = m_inputs_map[oa_num][MVB1].at("CONTACTOR_2_1_NORMAL_LOAD_Ln")                 ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_0                                   = m_inputs_map[oa_num][MVB1].at("DEVICE_ID_DI_0");
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_1                                   = m_inputs_map[oa_num][MVB1].at("DEVICE_ID_DI_1");
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_2                                   = m_inputs_map[oa_num][MVB1].at("DEVICE_ID_DI_2");
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_3                                   = m_inputs_map[oa_num][MVB1].at("DEVICE_ID_DI_3");
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_4                                   = m_inputs_map[oa_num][MVB1].at("DEVICE_ID_DI_4");
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_5                                   = m_inputs_map[oa_num][MVB1].at("DEVICE_ID_DI_5");
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CABINET_TEST_HW_OK_HEALT_RIOM_2                  = m_inputs_map[oa_num][MVB1].at("CABINET_TEST_HW_OK_HEALT_RIOM_2")     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.EARTHING_SWITCH_SERVICE_POSITION                 = m_inputs_map[oa_num][MVB1].at("EARTHING_SWITCH_SERVICE_POSITION")   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.EARTHING_SWITCH_EARTH_POSITION                   = m_inputs_map[oa_num][MVB1].at("EARTHING_SWITCH_EARTH_POSITION")       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.EARTHING_PANEL_YELLOW_KEY_EXTRACTED              = m_inputs_map[oa_num][MVB1].at("EARTHING_PANEL_YELLOW_KEY_EXTRACTED")    ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HV_DISCONNECTOR_MOVING_OR_CLOSE_D                = m_inputs_map[oa_num][MVB1].at("HV_DISCONNECTOR_MOVING_OR_CLOSE_D")    ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HV_DISCONNECTOR_CLOSED_E                         = m_inputs_map[oa_num][MVB1].at("HV_DISCONNECTOR_CLOSED_E")              ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HV_DISCONNECTOR_MOVING_OR_OPEN_A                 = m_inputs_map[oa_num][MVB1].at("HV_DISCONNECTOR_MOVING_OR_OPEN_A")      ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HV_DISCONNECTOR_OPENED_B                         = m_inputs_map[oa_num][MVB1].at("HV_DISCONNECTOR_OPENED_B")              ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_3_1_CB_PROTECTION                          = m_inputs_map[oa_num][MVB1].at("PLANT_3_1_CB_PROTECTION")                ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PANTOGRAPH_AIR_PRESSURE_COMPRESSOR               = m_inputs_map[oa_num][MVB1].at("PANTOGRAPH_AIR_PRESSURE_COMPRESSOR")      ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PANTOGRAPH_COMMAND_MOTOR_COMPRESSOR_INPUT        = m_inputs_map[oa_num][MVB1].at("PANTOGRAPH_COMMAND_MOTOR_COMPRESSOR_INPUT")   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_3_2_CB_PROTECTION                          = m_inputs_map[oa_num][MVB1].at("PLANT_3_2_CB_PROTECTION")           ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.FAST_OPEN_ADD                                    = m_inputs_map[oa_num][MVB1].at("FAST_OPEN_ADD")                   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PRESSURE_PS1_SAFEGUARD_ADD                       = m_inputs_map[oa_num][MVB1].at("PRESSURE_PS1_SAFEGUARD_ADD")         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PANTOGRAPH_INSULATED                             = m_inputs_map[oa_num][MVB1].at("PANTOGRAPH_INSULATED")             ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PRESSURE_GOVERNOR_PANTOGRAPH                     = m_inputs_map[oa_num][MVB1].at("PRESSURE_GOVERNOR_PANTOGRAPH")     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.POSITION_1_PANTOGRAPH_ENABLED                    = m_inputs_map[oa_num][MVB1].at("POSITION_1_PANTOGRAPH_ENABLED")   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.POSITION_0_PANTOGRAPH_ISOLATED                   = m_inputs_map[oa_num][MVB1].at("POSITION_0_PANTOGRAPH_ISOLATED")     ;


    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit41                                            = m_inputs_map[oa_num][MVB1].at("bit41");
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit42                                            = m_inputs_map[oa_num][MVB1].at("bit42");
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit43                                            = m_inputs_map[oa_num][MVB1].at("bit43");
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit44                                            = m_inputs_map[oa_num][MVB1].at("bit44");
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit45                                            = m_inputs_map[oa_num][MVB1].at("bit45");
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit46                                            = m_inputs_map[oa_num][MVB1].at("bit46");
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit47                                            = m_inputs_map[oa_num][MVB1].at("bit47");
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRAFO_NOT_FULL_SPEED                             = m_inputs_map[oa_num][MVB1].at("TRAFO_NOT_FULL_SPEED")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRAFO_FULL_SPEED                                 = m_inputs_map[oa_num][MVB1].at("TRAFO_FULL_SPEED")                             ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRAFO_NOT_LOW_SPEED                              = m_inputs_map[oa_num][MVB1].at("TRAFO_NOT_LOW_SPEED")                           ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRAFO_LOW_SPEED                                  = m_inputs_map[oa_num][MVB1].at("TRAFO_LOW_SPEED")                               ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_3_7_CB_PROTECTION                          = m_inputs_map[oa_num][MVB1].at("PLANT_3_7_CB_PROTECTION")                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRAFO_PRESSURE_RELIEF_DEVICE_TRIP_1              = m_inputs_map[oa_num][MVB1].at("TRAFO_PRESSURE_RELIEF_DEVICE_TRIP_1")           ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRAFO_PRESSURE_RELIEF_DEVICE_TRIP_2              = m_inputs_map[oa_num][MVB1].at("TRAFO_PRESSURE_RELIEF_DEVICE_TRIP_2")           ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRAFO_OIL_FLOW_ALARM                             = m_inputs_map[oa_num][MVB1].at("TRAFO_OIL_FLOW_ALARM")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRAFO_COOLANT_LEVEL_ALARM                        = m_inputs_map[oa_num][MVB1].at("TRAFO_COOLANT_LEVEL_ALARM")                   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRAFO_OVER_TEMP_OTP1_ALARM                       = m_inputs_map[oa_num][MVB1].at("TRAFO_OVER_TEMP_OTP1_ALARM")                     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRAFO_OVER_TEMP_OTP2_ALARM                       = m_inputs_map[oa_num][MVB1].at("TRAFO_OVER_TEMP_OTP2_ALARM")                     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.VENTILATION_TRANSFORMER_CB_PROTECTION            = m_inputs_map[oa_num][MVB1].at("VENTILATION_TRANSFORMER_CB_PROTECTION")       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HVAC_1_FLOOR_HEATER_1_START                      = m_inputs_map[oa_num][MVB1].at("HVAC_1_FLOOR_HEATER_1_START")                   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HVAC_1_FLOOR_HEATER_2_START                      = m_inputs_map[oa_num][MVB1].at("HVAC_1_FLOOR_HEATER_2_START")                   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HVAC_1_CB_PROTECTION                             = m_inputs_map[oa_num][MVB1].at("HVAC_1_CB_PROTECTION")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HVAC_2_FLOOR_HEATER_1_START                      = m_inputs_map[oa_num][MVB1].at("HVAC_2_FLOOR_HEATER_1_START")                   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HVAC_2_FLOOR_HEATER_2_START                      = m_inputs_map[oa_num][MVB1].at("HVAC_2_FLOOR_HEATER_2_START")                   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit65                                            = m_inputs_map[oa_num][MVB1].at("bit65")                                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit66                                            = m_inputs_map[oa_num][MVB1].at("bit66")                                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit67                                            = m_inputs_map[oa_num][MVB1].at("bit67")                                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit68                                            = m_inputs_map[oa_num][MVB1].at("bit68")                                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit69                                            = m_inputs_map[oa_num][MVB1].at("bit69")                                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit70                                            = m_inputs_map[oa_num][MVB1].at("bit70")                                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit71                                            = m_inputs_map[oa_num][MVB1].at("bit71")                                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HVAC_2_CB_PROTECTION                             = m_inputs_map[oa_num][MVB1].at("HVAC_2_CB_PROTECTION")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HVAC_1_ON_INPUT                                  = m_inputs_map[oa_num][MVB1].at("HVAC_1_ON_INPUT")                               ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HVAC_2_ON_INPUT                                  = m_inputs_map[oa_num][MVB1].at("HVAC_2_ON_INPUT")                               ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.THERMOSTAT_HEATING_LEFT_SIDE                     = m_inputs_map[oa_num][MVB1].at("THERMOSTAT_HEATING_LEFT_SIDE")                ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONTACTOR_HEATING_COMPARTMENT_LEFT_SIDE          = m_inputs_map[oa_num][MVB1].at("CONTACTOR_HEATING_COMPARTMENT_LEFT_SIDE")       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HEATING_COMPARTMENT_LEFT_SIDE_CB_PROTECTION      = m_inputs_map[oa_num][MVB1].at("HEATING_COMPARTMENT_LEFT_SIDE_CB_PROTECTION")   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.THERMOSTAT_HEATING_RIGHT_SIDE                    = m_inputs_map[oa_num][MVB1].at("THERMOSTAT_HEATING_RIGHT_SIDE")               ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONTACTOR_HEATING_COMPARTMENT_RIGHT_SIDE         = m_inputs_map[oa_num][MVB1].at("CONTACTOR_HEATING_COMPARTMENT_RIGHT_SIDE")     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HEATING_COMPARTMENT_RIGHT_SIDE_CB_PROTECTION     = m_inputs_map[oa_num][MVB1].at("HEATING_COMPARTMENT_RIGHT_SIDE_CB_PROTECTION") ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_4_0_CB_PROTECTION                          = m_inputs_map[oa_num][MVB1].at("PLANT_4_0_CB_PROTECTION")                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.COMPRESSOR_ON                                    = m_inputs_map[oa_num][MVB1].at("COMPRESSOR_ON")                               ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.MOTOR_COMPRESSOR_CB_PROTECTION                   = m_inputs_map[oa_num][MVB1].at("MOTOR_COMPRESSOR_CB_PROTECTION")                 ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_4_4_CB_PROTECTION                          = m_inputs_map[oa_num][MVB1].at("PLANT_4_4_CB_PROTECTION")                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PRESSURE_GOVERNORS_COMPRESSOR_CONTROL_1          = m_inputs_map[oa_num][MVB1].at("PRESSURE_GOVERNORS_COMPRESSOR_CONTROL_1")       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PRESSURE_GOVERNORS_COMPRESSOR_CONTROL_2          = m_inputs_map[oa_num][MVB1].at("PRESSURE_GOVERNORS_COMPRESSOR_CONTROL_2")       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ISOLATION_COCKS_AIR_SUPPLY_UNIT                  = m_inputs_map[oa_num][MVB1].at("ISOLATION_COCKS_AIR_SUPPLY_UNIT")               ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PRESSURE_GOVERNOR_BP_NO_EMERGENCY_BRAKE          = m_inputs_map[oa_num][MVB1].at("PRESSURE_GOVERNOR_BP_NO_EMERGENCY_BRAKE")       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.MOTOR_COMPRESSOR_CURRENT_MONITORING              = m_inputs_map[oa_num][MVB1].at("MOTOR_COMPRESSOR_CURRENT_MONITORING")           ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit90                                            = m_inputs_map[oa_num][MVB1].at("bit90")                                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit91                                            = m_inputs_map[oa_num][MVB1].at("bit91")                                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit92                                            = m_inputs_map[oa_num][MVB1].at("bit92")                                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit93                                            = m_inputs_map[oa_num][MVB1].at("bit93")                                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit94                                            = m_inputs_map[oa_num][MVB1].at("bit94")                                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit95                                            = m_inputs_map[oa_num][MVB1].at("bit95")                                       ;

    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PRESSURE_GOVERNOR_PB_RELEASED                    = m_inputs_map[oa_num][MVB1].at("PRESSURE_GOVERNOR_PB_RELEASED")               ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PRESSURE_GOVERNOR_R_CPRESS__APPL_BO1             = m_inputs_map[oa_num][MVB1].at("PRESSURE_GOVERNOR_R_CPRESS__APPL_BO1")         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PRESSURE_GOVERNOR_R_CPRESS__APPL_BO2             = m_inputs_map[oa_num][MVB1].at("PRESSURE_GOVERNOR_R_CPRESS__APPL_BO2")         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ISOLATION_COCKS_PNEUMATIC_BRAKE                  = m_inputs_map[oa_num][MVB1].at("ISOLATION_COCKS_PNEUMATIC_BRAKE")               ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ISOLATION_COCKS_DIRECT_BRAKE                     = m_inputs_map[oa_num][MVB1].at("ISOLATION_COCKS_DIRECT_BRAKE")                 ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ISOLATION_COCKS_INDIRECT_BRAKE                   = m_inputs_map[oa_num][MVB1].at("ISOLATION_COCKS_INDIRECT_BRAKE")                 ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ISOLATION_COCKS_DIRECT_BRAKE_BO1                 = m_inputs_map[oa_num][MVB1].at("ISOLATION_COCKS_DIRECT_BRAKE_BO1")             ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ISOLATION_COCKS_DIRECT_BRAKE_BO2                 = m_inputs_map[oa_num][MVB1].at("ISOLATION_COCKS_DIRECT_BRAKE_BO2")             ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ISOLATION_COCKS_PB_ISOLATED                      = m_inputs_map[oa_num][MVB1].at("ISOLATION_COCKS_PB_ISOLATED")                   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ISOLATION_COCKS_RESERVE                          = m_inputs_map[oa_num][MVB1].at("ISOLATION_COCKS_RESERVE")                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.EBCU_C_FCTOK                                     = m_inputs_map[oa_num][MVB1].at("EBCU_C_FCTOK")                                 ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.EBCU_SPEED_10_Km_H                               = m_inputs_map[oa_num][MVB1].at("EBCU_SPEED_10_Km_H")                             ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PRESSURE_GOVERNORS_AIR_SUSPENSION_BO1            = m_inputs_map[oa_num][MVB1].at("PRESSURE_GOVERNORS_AIR_SUSPENSION_BO1")       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PRESSURE_GOVERNORS_AIR_SUSPENSION_BO2            = m_inputs_map[oa_num][MVB1].at("PRESSURE_GOVERNORS_AIR_SUSPENSION_BO2")       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.LOW_MRP_PRESSUR_GOVERNOR                         = m_inputs_map[oa_num][MVB1].at("LOW_MRP_PRESSUR_GOVERNOR")                     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ZERO_SPEED                                       = m_inputs_map[oa_num][MVB1].at("ZERO_SPEED")                                     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_4_5_CB_PROTECTION                          = m_inputs_map[oa_num][MVB1].at("PLANT_4_5_CB_PROTECTION")                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CABINET_RIOM_1_CB_PROTECTION                     = m_inputs_map[oa_num][MVB1].at("CABINET_RIOM_1_CB_PROTECTION")                 ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.EMERGENCY_BRAKE_FROM_BCU                         = m_inputs_map[oa_num][MVB1].at("EMERGENCY_BRAKE_FROM_BCU")                     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.WSP_R_vGt5kmhDoor                                = m_inputs_map[oa_num][MVB1].at("WSP_R_vGt5kmhDoor")                           ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.BCU_ZERO_SPEED                                   = m_inputs_map[oa_num][MVB1].at("BCU_ZERO_SPEED")                                 ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.RESERVE                                          = m_inputs_map[oa_num][MVB1].at("RESERVE")                                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.FIRE_EXTINGUISHER_1_PRESENCE                     = m_inputs_map[oa_num][MVB1].at("FIRE_EXTINGUISHER_1_PRESENCE")                 ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.FIRE_EXTINGUISHER_2_PRESENCE                     = m_inputs_map[oa_num][MVB1].at("FIRE_EXTINGUISHER_2_PRESENCE")                 ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.RELAY_CONTROL_EMERGENCY_LOOP                     = m_inputs_map[oa_num][MVB1].at("RELAY_CONTROL_EMERGENCY_LOOP")                 ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_4_7_CB_PROTECTION                          = m_inputs_map[oa_num][MVB1].at("PLANT_4_7_CB_PROTECTION")                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HANDLE_1_PASSENGER_ALARM                         = m_inputs_map[oa_num][MVB1].at("HANDLE_1_PASSENGER_ALARM")                     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HANDLE_3_PASSENGER_ALARM                         = m_inputs_map[oa_num][MVB1].at("HANDLE_3_PASSENGER_ALARM")                     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HANDLE_5_PASSENGER_ALARM                         = m_inputs_map[oa_num][MVB1].at("HANDLE_5_PASSENGER_ALARM")                     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HANDLE_7_PASSENGER_ALARM                         = m_inputs_map[oa_num][MVB1].at("HANDLE_7_PASSENGER_ALARM")                     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HANDLE_2_PASSENGER_ALARM                         = m_inputs_map[oa_num][MVB1].at("HANDLE_2_PASSENGER_ALARM")                     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HANDLE_4_PASSENGER_ALARM                         = m_inputs_map[oa_num][MVB1].at("HANDLE_4_PASSENGER_ALARM")                     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HANDLE_6_PASSENGER_ALARM                         = m_inputs_map[oa_num][MVB1].at("HANDLE_6_PASSENGER_ALARM")                     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.HANDLE_8_PASSENGER_ALARM                         = m_inputs_map[oa_num][MVB1].at("HANDLE_8_PASSENGER_ALARM")                     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DOOR_1_FULLY_OPENED                              = m_inputs_map[oa_num][MVB1].at("DOOR_1_FULLY_OPENED")                           ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DOOR_2_FULLY_OPENED                              = m_inputs_map[oa_num][MVB1].at("DOOR_2_FULLY_OPENED")                           ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DOOR_3_FULLY_OPENED                              = m_inputs_map[oa_num][MVB1].at("DOOR_3_FULLY_OPENED")                           ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DOOR_4_FULLY_OPENED                              = m_inputs_map[oa_num][MVB1].at("DOOR_4_FULLY_OPENED")                           ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DOOR_5_FULLY_OPENED                              = m_inputs_map[oa_num][MVB1].at("DOOR_5_FULLY_OPENED")                           ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DOOR_6_FULLY_OPENED                              = m_inputs_map[oa_num][MVB1].at("DOOR_6_FULLY_OPENED")                           ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DOOR_7_FULLY_OPENED                              = m_inputs_map[oa_num][MVB1].at("DOOR_7_FULLY_OPENED")                           ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CABINET_RIOM_2_CB_PROTECTION                     = m_inputs_map[oa_num][MVB1].at("CABINET_RIOM_2_CB_PROTECTION")                 ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_EMERGENCY_BRAKE_COMMAND_1                   = m_inputs_map[oa_num][MVB1].at("ETCS_EMERGENCY_BRAKE_COMMAND_1")                 ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_EMERGENCY_BRAKE_COMMAND_2                   = m_inputs_map[oa_num][MVB1].at("ETCS_EMERGENCY_BRAKE_COMMAND_2")                 ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_MAIN_POWER_COMMAND                          = m_inputs_map[oa_num][MVB1].at("ETCS_MAIN_POWER_COMMAND")                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_TRACTION_CUT_OFF                            = m_inputs_map[oa_num][MVB1].at("ETCS_TRACTION_CUT_OFF")                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_REGENERATIVE_BRAKE_INHIBIT                  = m_inputs_map[oa_num][MVB1].at("ETCS_REGENERATIVE_BRAKE_INHIBIT")               ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit143                                           = m_inputs_map[oa_num][MVB1].at("bit143")                                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.DOOR_8_FULLY_OPENED                              = m_inputs_map[oa_num][MVB1].at("DOOR_8_FULLY_OPENED")                           ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_5_3_CB_PROTECTION                          = m_inputs_map[oa_num][MVB1].at("PLANT_5_3_CB_PROTECTION")                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_6_0_CB_PROTECTION                          = m_inputs_map[oa_num][MVB1].at("PLANT_6_0_CB_PROTECTION")                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_6_5_CB_PROTECTION                          = m_inputs_map[oa_num][MVB1].at("PLANT_6_5_CB_PROTECTION")                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONTACTOR_VEHICLE_LIGHTS_ON                      = m_inputs_map[oa_num][MVB1].at("CONTACTOR_VEHICLE_LIGHTS_ON")                   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONTACTOR_VEHICLE_HALF_LIGHT                     = m_inputs_map[oa_num][MVB1].at("CONTACTOR_VEHICLE_HALF_LIGHT")                 ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CONTACTOR_VEHICLE_EMERGENCY_LIGHT                = m_inputs_map[oa_num][MVB1].at("CONTACTOR_VEHICLE_EMERGENCY_LIGHT")           ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_7_0_CB_PROTECTION                          = m_inputs_map[oa_num][MVB1].at("PLANT_7_0_CB_PROTECTION")                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_EQUIPMENT_POWER_SUPPLY_APPLIED              = m_inputs_map[oa_num][MVB1].at("ETCS_EQUIPMENT_POWER_SUPPLY_APPLIED")           ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.PLANT_7_8_CB_PROTECTION                          = m_inputs_map[oa_num][MVB1].at("PLANT_7_8_CB_PROTECTION")                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.JRU_FAULT                                        = m_inputs_map[oa_num][MVB1].at("JRU_FAULT")                                   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETHERNET_SWITCH_1_PAPIS_ALARM                    = m_inputs_map[oa_num][MVB1].at("ETHERNET_SWITCH_1_PAPIS_ALARM")               ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETHERNET_SWITCH_2_PAPIS_ALARM                    = m_inputs_map[oa_num][MVB1].at("ETHERNET_SWITCH_2_PAPIS_ALARM")               ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_reserved_1  = m_inputs_map[oa_num][MVB1].at("ETCS_reserved_1") ;
    //m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_ISOLATION_SIGNAL                            = m_inputs_map[oa_num].at("ETCS_ISOLATION_SIGNAL")                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_PANTOGRAPH_COMMAND                          = m_inputs_map[oa_num][MVB1].at("ETCS_PANTOGRAPH_COMMAND")                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_AIR_TIGHTNESS                               = m_inputs_map[oa_num][MVB1].at("ETCS_AIR_TIGHTNESS")                             ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_LEFT_DOORS_OPEN_PERMISSION                  = m_inputs_map[oa_num][MVB1].at("ETCS_LEFT_DOORS_OPEN_PERMISSION")               ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_RIGHT_DOORS_OPEN_PERMISSION                 = m_inputs_map[oa_num][MVB1].at("ETCS_RIGHT_DOORS_OPEN_PERMISSION")             ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.ETCS_FULL_SERVICE_BRAKING_COMMAND = m_inputs_map[oa_num][MVB1].at("ETCS_FULL_SERVICE_BRAKING_COMMAND")           ;
    //m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit162                                           = m_inputs_map[oa_num].at("bit162")                                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit163                                           = m_inputs_map[oa_num][MVB1].at("bit163")                                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit164                                           = m_inputs_map[oa_num][MVB1].at("bit164")                                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit165                                           = m_inputs_map[oa_num][MVB1].at("bit165")                                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.CB_PROTECTION_AXLE_BOX                           = m_inputs_map[oa_num][MVB1].at("CB_PROTECTION_AXLE_BOX")                        ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.bit167                                           = m_inputs_map[oa_num][MVB1].at("bit167")                                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.MEASURING_BATTERY_VOLTAGE                        = m_inputs_map[oa_num][MVB1].at("MEASURING_BATTERY_VOLTAGE")                   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRANSDUCER_HV_VOLTAGE_VCB_IN                     = m_inputs_map[oa_num][MVB1].at("TRANSDUCER_HV_VOLTAGE_VCB_IN")                 ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TRANSDUCER_HV_CURRENT_VCB_IN                     = m_inputs_map[oa_num][MVB1].at("TRANSDUCER_HV_CURRENT_VCB_IN")                 ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TEMPERATURE_PROBE_RTD_2                          = m_inputs_map[oa_num][MVB1].at("TEMPERATURE_PROBE_RTD_2")                       ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.TEMPERATURE_PROBE_RTD_1                          = m_inputs_map[oa_num][MVB1].at("TEMPERATURE_PROBE_RTD_1");
    //m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.reserved_29                                      = m_inputs_map[oa_num].at("reserved_29")                                   ;
    //m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.reserved_30                                      = m_inputs_map[oa_num].at("reserved_30")                                   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb1_inputs.bits.reserved_31                                      = m_inputs_map[oa_num][MVB1].at("reserved_31")                                   ;

}

void Oa_Vh_Riom::set_status_struct(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);

    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.lifesign                                                    = m_inputs_map[oa_num][STATUS0].at("lifesign")                      ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO01_Module_Error                                      = m_inputs_map[oa_num][STATUS0].at("DIO01_Module_Error")            ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO01_Output_Overcurrent              = m_inputs_map[oa_num][STATUS0].at("DIO01_Output_Overcurrent")      ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO01_Heartbeat_error                 = m_inputs_map[oa_num][STATUS0].at("DIO01_Heartbeat_error")         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO01_Group_1_Voltage_error               = m_inputs_map[oa_num][STATUS0].at("DIO01_Group_1_Voltage_error")   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO01_Group_2_Voltage_error               = m_inputs_map[oa_num][STATUS0].at("DIO01_Group_2_Voltage_error")   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO01_Board_Temperature_error                 = m_inputs_map[oa_num][STATUS0].at("DIO01_Board_Temperature_error") ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit22                 = m_inputs_map[oa_num][STATUS0].at("bit22")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit23                 = m_inputs_map[oa_num][STATUS0].at("bit23")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO02_Module_Error                = m_inputs_map[oa_num][STATUS0].at("DIO02_Module_Error")            ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO02_Output_Overcurrent              = m_inputs_map[oa_num][STATUS0].at("DIO02_Output_Overcurrent")      ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO02_Heartbeat_error                 = m_inputs_map[oa_num][STATUS0].at("DIO02_Heartbeat_error")         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO02_Group_1_Voltage_error               = m_inputs_map[oa_num][STATUS0].at("DIO02_Group_1_Voltage_error")   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO02_Group_2_Voltage_error               = m_inputs_map[oa_num][STATUS0].at("DIO02_Group_2_Voltage_error")   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO02_Board_Temperature_error                 = m_inputs_map[oa_num][STATUS0].at("DIO02_Board_Temperature_error") ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit30                 = m_inputs_map[oa_num][STATUS0].at("bit30")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit31                 = m_inputs_map[oa_num][STATUS0].at("bit31")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO03_Module_Error                = m_inputs_map[oa_num][STATUS0].at("DIO03_Module_Error")            ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO03_Output_Overcurrent              = m_inputs_map[oa_num][STATUS0].at("DIO03_Output_Overcurrent")      ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO03_Heartbeat_error                 = m_inputs_map[oa_num][STATUS0].at("DIO03_Heartbeat_error")         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO03_Group_1_Voltage_error               = m_inputs_map[oa_num][STATUS0].at("DIO03_Group_1_Voltage_error")   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO03_Group_2_Voltage_error               = m_inputs_map[oa_num][STATUS0].at("DIO03_Group_2_Voltage_error")   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO03_Board_Temperature_error                 = m_inputs_map[oa_num][STATUS0].at("DIO03_Board_Temperature_error") ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit38                 = m_inputs_map[oa_num][STATUS0].at("bit38")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit39                 = m_inputs_map[oa_num][STATUS0].at("bit39")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO04_Module_Error                = m_inputs_map[oa_num][STATUS0].at("DIO04_Module_Error")            ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO04_Output_Overcurrent              = m_inputs_map[oa_num][STATUS0].at("DIO04_Output_Overcurrent")      ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO04_Heartbeat_error                 = m_inputs_map[oa_num][STATUS0].at("DIO04_Heartbeat_error")         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO04_Group_1_Voltage_error               = m_inputs_map[oa_num][STATUS0].at("DIO04_Group_1_Voltage_error")   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO04_Group_2_Voltage_error               = m_inputs_map[oa_num][STATUS0].at("DIO04_Group_2_Voltage_error")   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO04_Board_Temperature_error                 = m_inputs_map[oa_num][STATUS0].at("DIO04_Board_Temperature_error") ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit46                 = m_inputs_map[oa_num][STATUS0].at("bit46")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit47                 = m_inputs_map[oa_num][STATUS0].at("bit47")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO05_Module_Error                = m_inputs_map[oa_num][STATUS0].at("DIO05_Module_Error")            ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO05_Output_Overcurrent              = m_inputs_map[oa_num][STATUS0].at("DIO05_Output_Overcurrent")      ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO05_Heartbeat_error                 = m_inputs_map[oa_num][STATUS0].at("DIO05_Heartbeat_error")         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO05_Group_1_Voltage_error               = m_inputs_map[oa_num][STATUS0].at("DIO05_Group_1_Voltage_error")   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO05_Group_2_Voltage_error               = m_inputs_map[oa_num][STATUS0].at("DIO05_Group_2_Voltage_error")   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO05_Board_Temperature_error                 = m_inputs_map[oa_num][STATUS0].at("DIO05_Board_Temperature_error") ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit54                 = m_inputs_map[oa_num][STATUS0].at("bit54")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit55                 = m_inputs_map[oa_num][STATUS0].at("bit55")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO06_Module_Error                = m_inputs_map[oa_num][STATUS0].at("DIO06_Module_Error")            ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO06_Output_Overcurrent              = m_inputs_map[oa_num][STATUS0].at("DIO06_Output_Overcurrent")      ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO06_Heartbeat_error                 = m_inputs_map[oa_num][STATUS0].at("DIO06_Heartbeat_error")         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO06_Group_1_Voltage_error               = m_inputs_map[oa_num][STATUS0].at("DIO06_Group_1_Voltage_error")   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO06_Group_2_Voltage_error               = m_inputs_map[oa_num][STATUS0].at("DIO06_Group_2_Voltage_error")   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO06_Board_Temperature_error                 = m_inputs_map[oa_num][STATUS0].at("DIO06_Board_Temperature_error") ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit62                 = m_inputs_map[oa_num][STATUS0].at("bit62")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit63                 = m_inputs_map[oa_num][STATUS0].at("bit63")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO07_Module_Error                = m_inputs_map[oa_num][STATUS0].at("DIO07_Module_Error")            ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO07_Output_Overcurrent              = m_inputs_map[oa_num][STATUS0].at("DIO07_Output_Overcurrent")      ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO07_Heartbeat_error                 = m_inputs_map[oa_num][STATUS0].at("DIO07_Heartbeat_error")         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO07_Group_1_Voltage_error               = m_inputs_map[oa_num][STATUS0].at("DIO07_Group_1_Voltage_error")   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO07_Group_2_Voltage_error               = m_inputs_map[oa_num][STATUS0].at("DIO07_Group_2_Voltage_error")   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.DIO07_Board_Temperature_error                 = m_inputs_map[oa_num][STATUS0].at("DIO07_Board_Temperature_error") ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit70                 = m_inputs_map[oa_num][STATUS0].at("bit70")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit71                 = m_inputs_map[oa_num][STATUS0].at("bit71")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.AIM01_Module_Error                = m_inputs_map[oa_num][STATUS0].at("AIM01_Module_Error")            ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.AIM01_Heartbeat_error                 = m_inputs_map[oa_num][STATUS0].at("AIM01_Heartbeat_error")         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit74                 = m_inputs_map[oa_num][STATUS0].at("bit74")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit75                 = m_inputs_map[oa_num][STATUS0].at("bit75")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit76                 = m_inputs_map[oa_num][STATUS0].at("bit76")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit77                 = m_inputs_map[oa_num][STATUS0].at("bit77")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit78                 = m_inputs_map[oa_num][STATUS0].at("bit78")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit79                 = m_inputs_map[oa_num][STATUS0].at("bit79")                         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.PTI2037A_Module_Error                 = m_inputs_map[oa_num][STATUS0].at("PTI2037A_Module_Error")         ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.PTI2037A_Heartbeat_error              = m_inputs_map[oa_num][STATUS0].at("PTI2037A_Heartbeat_error")      ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.PTI2037A_Channel_1_Status                 = m_inputs_map[oa_num][STATUS0].at("PTI2037A_Channel_1_Status")     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.PTI2037A_Channel_2_Status                 = m_inputs_map[oa_num][STATUS0].at("PTI2037A_Channel_2_Status")     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.PTI2037A_Channel_3_Status                 = m_inputs_map[oa_num][STATUS0].at("PTI2037A_Channel_3_Status")     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.PTI2037A_Channel_4_Status                 = m_inputs_map[oa_num][STATUS0].at("PTI2037A_Channel_4_Status")     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.PTI2037A_Channel_5_Status                 = m_inputs_map[oa_num][STATUS0].at("PTI2037A_Channel_5_Status")     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.PTI2037A_Channel_6_Status                 = m_inputs_map[oa_num][STATUS0].at("PTI2037A_Channel_6_Status")     ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.reserved_11               = m_inputs_map[oa_num][STATUS0].at("reserved_11")                   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.reserved_12               = m_inputs_map[oa_num][STATUS0].at("reserved_12")                   ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.R1_DCU_CANopen_Fault              = m_inputs_map[oa_num][STATUS0].at("R1_DCU_CANopen_Fault")          ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.R2_DCU_CANopen_Fault              = m_inputs_map[oa_num][STATUS0].at("R2_DCU_CANopen_Fault")          ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.R3_DCU_CANopen_Fault              = m_inputs_map[oa_num][STATUS0].at("R3_DCU_CANopen_Fault")          ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.R4_DCU_CANopen_Fault              = m_inputs_map[oa_num][STATUS0].at("R4_DCU_CANopen_Fault")          ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.L1_DCU_CANopen_Fault              = m_inputs_map[oa_num][STATUS0].at("L1_DCU_CANopen_Fault")          ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.L2_DCU_CANopen_Fault              = m_inputs_map[oa_num][STATUS0].at("L2_DCU_CANopen_Fault")          ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.L3_DCU_CANopen_Fault              = m_inputs_map[oa_num][STATUS0].at("L3_DCU_CANopen_Fault")          ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.L4_DCU_CANopen_Fault              = m_inputs_map[oa_num][STATUS0].at("L4_DCU_CANopen_Fault")          ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.HVAC1_CANopen_Fault               = m_inputs_map[oa_num][STATUS0].at("HVAC1_CANopen_Fault")           ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.HVAC2_CANopen_Fault               = m_inputs_map[oa_num][STATUS0].at("HVAC2_CANopen_Fault")           ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit114                = m_inputs_map[oa_num][STATUS0].at("bit114")                        ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit115                = m_inputs_map[oa_num][STATUS0].at("bit115")                        ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit116                = m_inputs_map[oa_num][STATUS0].at("bit116")                        ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit117                = m_inputs_map[oa_num][STATUS0].at("bit117")                        ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit118                = m_inputs_map[oa_num][STATUS0].at("bit118")                        ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.bit119                = m_inputs_map[oa_num][STATUS0].at("bit119")                        ;
    m_oa_x_vh_riom[oa_num].oa_vh_riom_ccu_mvb_status.bits.reserved_15               = m_inputs_map[oa_num][STATUS0].at("reserved_15")                   ;
}

