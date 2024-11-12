#include "ccu_to_all_jrus_4.h"

Ccu_To_All_Jrus_4::Ccu_To_All_Jrus_4(QObject *parent)
    : QObject{parent}
{
        init_table();
}

Ccu_To_All_Jrus_4::~Ccu_To_All_Jrus_4()
{
    delete m_tableWidget;
}

void Ccu_To_All_Jrus_4::set_data_struct(const QByteArray &output)
{
    if (output.size() == sizeof(m_ccu_to_all_jrus_4.bytes)) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        memcpy(m_ccu_to_all_jrus_4.bytes, output.constData(), sizeof(m_ccu_to_all_jrus_4.bytes));
        update_map();
        update_table();
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }
}

void Ccu_To_All_Jrus_4::init_table()
{
    m_outputs_map = {
        {"Lifesign", 0},
        {"X_MRPPress", 0},
        {"X_BPPress", 0},
        {"EB_applied", 0},
        {"SKA1_S_PB_EmerRel_Conf", 0},
        {"SKA2_S_PB_EmerRel_Conf", 0},
        {"OA1_S_PB_EmerRel_Conf", 0},
        {"OA2_S_PB_EmerRel_Conf", 0},
        {"Service_brake_applied", 0},
        {"SKA1_INDIRECT_BRAKE_MANIPOLATOR", 0},
        {"SKA2_INDIRECT_BRAKE_MANIPOLATOR", 0},
        {"OA1_ETCS_LEFT_DOORS_OPEN_PERMISSION", 0},
        {"OA1_ETCS_RIGHT_DOORS_OPEN_PERMISSION", 0},
        {"OA2_ETCS_LEFT_DOORS_OPEN_PERMISSION", 0},
        {"OA2_ETCS_RIGHT_DOORS_OPEN_PERMISSION", 0},
        {"bit44", 0},
        {"bit45", 0},
        {"bit46", 0},
        {"bit47", 0},
        {"Parking_mode_on_off", 0},
        {"PG_NDIRECT_BRAKE_CONTROL", 0},
        {"SKA1_PB_Emergency", 0},
        {"SKA2_PB_Emergency", 0},
        {"SKA1_MC_S1", 0},
        {"SKA1_MC_S2", 0},
        {"SKA1_MC_S3",0},
        {"SKA1_MC_S4",0},
        {"SKA1_MC_S5",0},
        {"SKA1_MC_S6",0},
        {"SKA2_MC_S1",0},
        {"SKA2_MC_S2",0},
        {"SKA2_MC_S3",0},
        {"SKA2_MC_S4",0},
        {"SKA2_MC_S5",0},
        {"SKA2_MC_S6",0},
        {"HORN_1_IC", 0},
        {"HORN_2_IC", 0},
        {"OA1_PG_COMPRESSOR_CONTROL", 0},
        {"OA1_IC_ASU", 0},
        {"OA2_PG_COMPRESSOR_CONTROL", 0},
        {"OA2_IC_ASU", 0},
        {"ISOLATION_COCKS_PNEUMATIC_BRAKE", 0},
        {"ISOLATION_COCKS_INDIRECT_BRAKE", 0},
        {"ISOLATION_COCKS_DIRECT_BRAKE_BO1", 0},
        {"ISOLATION_COCKS_DIRECT_BRAKE_BO2", 0},
        {"ISOLATION_COCKS_PB_ISOLATED", 0},
        {"ISOLATION_COCKS_SAND_ISOLATED", 0},
        {"ISOLATION_COCKS_BP_TO_MRP_BYPASS", 0},
        {"bit77", 0},
        {"bit78", 0},
        {"bit79", 0},
        {"SL_CUT_OFF_BYPASS", 0},
        {"SL_DEAD_MAN_BYPASS", 0},
        {"SL_DOORS_SIDE_CONTROL_ETCS_BYPASS", 0},
        {"SL_ETCS_BYPASS", 0},
        {"ATS_BYPASS", 0},
        {"VACUUM_OPENING_BYPASS", 0},
        {"ZERO_SPEED_BYPASS", 0},
        {"SELECTOR_BYPASS_PASSANGER_ALARM", 0},
        {"SL_DOORS_LOOP_BYPASS", 0},
        {"bit89", 0},
        {"bit90", 0},
        {"bit91", 0},
        {"bit92", 0},
        {"bit93", 0},
        {"bit94", 0},
        {"bit95", 0},
        {"ATS_mode_on", 0},
        {"ZERO_SPEED", 0},
        {"OA1_POSITION_1_PANTOGRAPH_ENABLED ", 0},
        {"OA1_POSITION_0_PANTOGRAPH_ISOLATED", 0},
        {"OA2_POSITION_1_PANTOGRAPH_ENABLED ", 0},
        {"OA2_POSITION_0_PANTOGRAPH_ISOLATED", 0},
        {"OA1_READY_VCB", 0},
        {"OA1_VCB_CLOSE", 0},
        {"OA1_OPEN_VCB_FOR_HIGH_CURRENT", 0},
        {"OA1_FAST_OPEN_VCB", 0},
        {"OA2_READY_VCB", 0},
        {"OA2_VCB_CLOSE", 0},
        {"OA2_OPEN_VCB_FOR_HIGH_CURRENT", 0},
        {"OA2_FAST_OPEN_VCB", 0},
        {"OA1_HV_DISCONNECTOR_MOVING_OR_CLOSE_D", 0},
        {"OA1_HV_DISCONNECTOR_CLOSED_E", 0},
        {"OA1_HV_DISCONNECTOR_MOVING_OR_OPEN_A", 0},
        {"OA1_HV_DISCONNECTOR_OPENED_B", 0},
        {"OA2_HV_DISCONNECTOR_MOVING_OR_CLOSE_D", 0},
        {"OA2_HV_DISCONNECTOR_CLOSED_E", 0},
        {"OA2_HV_DISCONNECTOR_MOVING_OR_OPEN_A", 0},
        {"OA2_HV_DISCONNECTOR_OPENED_B", 0},
        {"RAISING_PANTOGRAPH_1", 0},
        {"DOWN_PANTOGRAPH_1", 0},
        {"RAISING_PANTOGRAPH_2", 0},
        {"DOWN_PANTOGRAPH_2", 0},
        {"SKA1_CLOSING_VACUUM_CIRCUIT_BREAKER", 0},
        {"SKA1_OPENING_VACUUM_CIRCUIT_BREAKER", 0},
        {"SKA2_CLOSING_VACUUM_CIRCUIT_BREAKER", 0},
        {"SKA2_OPENING_VACUUM_CIRCUIT_BREAKER", 0},
        {"OA1_EARTHING_SWITCH_SERVICE_POSITION", 0},
        {"OA1_EARTHING_SWITCH_EARTH_POSITION", 0},
        {"EARTHING_PANEL_YELLOW_KEY_EXTRACTED", 0},
        {"OA2_EARTHING_SWITCH_SERVICE_POSITION", 0},
        {"OA2_EARTHING_SWITCH_EARTH_POSITION", 0},
        {"EARTHING_PANEL_YELLOW_KEY_EXTRACTED_1", 0},
        {"bit132", 0},
        {"bit133", 0},
        {"bit134", 0},
        {"bit135", 0},
        {"TRANSDUCER_HV_VOLTAGE_VCB_IN", 0},
        {"TRANSDUCER_HV_CURRENT_VCB_IN", 0},
        {"SKA1_HANDLE_1_PASSENGER_ALARM", 0},
        {"SKA1_HANDLE_2_PASSENGER_ALARM", 0},
        {"SKA1_HANDLE_3_PASSENGER_ALARM", 0},
        {"SKA1_HANDLE_4_PASSENGER_ALARM", 0},
        {"SKA1_HANDLE_5_PASSENGER_ALARM", 0},
        {"SKA1_HANDLE_6_PASSENGER_ALARM", 0},
        {"SKA1_HANDLE_7_PASSENGER_ALARM", 0},
        {"SKA1_HANDLE_8_PASSENGER_ALARM", 0},
        {"SKA2_HANDLE_1_PASSENGER_ALARM", 0},
        {"SKA2_HANDLE_2_PASSENGER_ALARM", 0},
        {"SKA2_HANDLE_3_PASSENGER_ALARM", 0},
        {"SKA2_HANDLE_4_PASSENGER_ALARM", 0},
        {"SKA2_HANDLE_5_PASSENGER_ALARM", 0},
        {"SKA2_HANDLE_6_PASSENGER_ALARM", 0},
        {"SKA2_HANDLE_7_PASSENGER_ALARM", 0},
        {"SKA2_HANDLE_8_PASSENGER_ALARM", 0},
        {"OA1_HANDLE_1_PASSENGER_ALARM", 0},
        {"OA1_HANDLE_2_PASSENGER_ALARM", 0},
        {"OA1_HANDLE_3_PASSENGER_ALARM", 0},
        {"OA1_HANDLE_4_PASSENGER_ALARM", 0},
        {"OA1_HANDLE_5_PASSENGER_ALARM", 0},
        {"OA1_HANDLE_6_PASSENGER_ALARM", 0},
        {"OA1_HANDLE_7_PASSENGER_ALARM", 0},
        {"OA1_HANDLE_8_PASSENGER_ALARM", 0},
        {"OA2_HANDLE_1_PASSENGER_ALARM", 0},
        {"OA2_HANDLE_2_PASSENGER_ALARM", 0},
        {"OA2_HANDLE_3_PASSENGER_ALARM", 0},
        {"OA2_HANDLE_4_PASSENGER_ALARM", 0},
        {"OA2_HANDLE_5_PASSENGER_ALARM", 0},
        {"OA2_HANDLE_6_PASSENGER_ALARM", 0},
        {"OA2_HANDLE_7_PASSENGER_ALARM", 0},
        {"OA2_HANDLE_8_PASSENGER_ALARM", 0},
        {"SKA1_SAND_LV_SENSOR_BOG1_BEARING_RIGHT", 0},
        {"SKA1_SAND_LV_SENSOR_BOG1_BEARING_LEFT", 0},
        {"SKA1_SAND_LV_SENSOR_BOG2_BEARING_RIGHT", 0},
        {"SKA1_SAND_LV_SENSOR_BOG2_BEARING_LEFT", 0},
        {"SKA2_SAND_LV_SENSOR_BOG1_BEARING_RIGHT", 0},
        {"SKA2_SAND_LV_SENSOR_BOG1_BEARING_LEFT", 0},
        {"SKA2_SAND_LV_SENSOR_BOG2_BEARING_RIGHT", 0},
        {"SKA2_SAND_LV_SENSOR_BOG2_BEARING_LEFT", 0},
        {"SKA1_CCU_OK", 0},
        {"SKA2_CCU_OK", 0},
        {"SKA1_DD_RIOM_M_OK", 0},
        {"SKA1_DD_RIOM_R_OK", 0},
        {"SKA2_DD_RIOM_M_OK", 0},
        {"SKA2_DD_RIOM_R_OK", 0},
        {"SKA1_VH_RIOM_M_OK", 0},
        {"SKA1_VH_RIOM_R_OK", 0},
        {"SKA2_VH_RIOM_M_OK", 0},
        {"SKA2_VH_RIOM_R_OK", 0},
        {"OA1_VH_RIOM_M_OK", 0},
        {"OA1_VH_RIOM_R_OK", 0},
        {"OA2_VH_RIOM_M_OK", 0},
        {"OA2_VH_RIOM_R_OK", 0},
        {"SKA1_HMI_OK", 0},
        {"SKA2_HMI_OK", 0},
        {"OA1_MVB_REPEATER_OK", 0},
        {"OA2_MVB_REPEATER_OK", 0},
        {"SKA1_WTB_GW_OK", 0},
        {"SKA2_WTB_GW_OK", 0},
        {"SKA1_ETH_SW_OK", 0},
        {"SKA2_ETH_SW_OK", 0},
        {"OA1_ETH_SW_OK ", 0},
        {"OA2_ETH_SW_OK ", 0},
        {"OA1_APU_OK", 0},
        {"OA2_APU_OK", 0},
        {"SKA1_TCU1_OK", 0},
        {"SKA1_TCU2_OK", 0},
        {"SKA2_TCU1_OK", 0},
        {"SKA2_TCU2_OK", 0},
        {"SKA1_SIGNALING_AIRSUSP_FAIL", 0},
        {"SKA2_SIGNALING_AIRSUSP_FAIL", 0},
        {"reserved_30", 0},
        {"reserved_31", 0}



    };

    QStringList table_name = {"ccu_to_all_jrus_4", "value"};

    m_tableWidget = new QTableWidget();
    m_tableWidget->setColumnCount(2);
    m_tableWidget->setRowCount(m_outputs_map.size());
    m_tableWidget->setHorizontalHeaderLabels(table_name);

    int row = 0;
    for (const auto& pair:  m_outputs_map) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget->setItem(row, 0, item_name);
        m_tableWidget->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }

    m_tableWidget->resizeColumnsToContents();
}

void Ccu_To_All_Jrus_4::update_table()
{
    // Tabloyu temizleyin
    m_tableWidget->setRowCount(0);
    //tableWidget->clear();

    // Haritadaki verilerle tabloyu doldurun
    int row = 0;
    for (auto it = m_outputs_map.begin(); it != m_outputs_map.end(); ++it)
    {
        m_tableWidget->insertRow(row);
        //qDebug() <<"first:" << it->first << "second:" << it->second;
        QTableWidgetItem *keyItem   = new QTableWidgetItem(it->first); // Anahtar
        QTableWidgetItem *valueItem = new QTableWidgetItem(QString::number(it->second)); // Değer

        m_tableWidget->setItem(row, 0, keyItem);
        m_tableWidget->setItem(row, 1, valueItem);

        row++;
    }
}

void Ccu_To_All_Jrus_4::update_map()
{

    m_outputs_map.at("Lifesign")           = m_ccu_to_all_jrus_4.bits.Lifesign;
    m_outputs_map.at("X_MRPPress")         = m_ccu_to_all_jrus_4.bits.X_MRPPress;
    m_outputs_map.at("X_BPPress")          = m_ccu_to_all_jrus_4.bits.X_BPPress;
    m_outputs_map.at("EB_applied")                         = m_ccu_to_all_jrus_4.bits.EB_applied;
    m_outputs_map.at("SKA1_S_PB_EmerRel_Conf")             = m_ccu_to_all_jrus_4.bits.SKA1_S_PB_EmerRel_Conf;
    m_outputs_map.at("SKA2_S_PB_EmerRel_Conf")             = m_ccu_to_all_jrus_4.bits.SKA2_S_PB_EmerRel_Conf;
    m_outputs_map.at("OA1_S_PB_EmerRel_Conf")              = m_ccu_to_all_jrus_4.bits.OA1_S_PB_EmerRel_Conf;
    m_outputs_map.at("OA2_S_PB_EmerRel_Conf")              = m_ccu_to_all_jrus_4.bits.OA2_S_PB_EmerRel_Conf;
    m_outputs_map.at("Service_brake_applied")              = m_ccu_to_all_jrus_4.bits.Service_brake_applied;
    m_outputs_map.at("SKA1_INDIRECT_BRAKE_MANIPOLATOR")    = m_ccu_to_all_jrus_4.bits.SKA1_INDIRECT_BRAKE_MANIPOLATOR;
    m_outputs_map.at("SKA2_INDIRECT_BRAKE_MANIPOLATOR")    = m_ccu_to_all_jrus_4.bits.SKA2_INDIRECT_BRAKE_MANIPOLATOR;
    m_outputs_map.at("OA1_ETCS_LEFT_DOORS_OPEN_PERMISSION ")           = m_ccu_to_all_jrus_4.bits.OA1_ETCS_LEFT_DOORS_OPEN_PERMISSION ;
    m_outputs_map.at("OA1_ETCS_RIGHT_DOORS_OPEN_PERMISSION")           = m_ccu_to_all_jrus_4.bits.OA1_ETCS_RIGHT_DOORS_OPEN_PERMISSION;
    m_outputs_map.at("OA2_ETCS_LEFT_DOORS_OPEN_PERMISSION ")           = m_ccu_to_all_jrus_4.bits.OA2_ETCS_LEFT_DOORS_OPEN_PERMISSION ;
    m_outputs_map.at("OA2_ETCS_RIGHT_DOORS_OPEN_PERMISSION")           = m_ccu_to_all_jrus_4.bits.OA2_ETCS_RIGHT_DOORS_OPEN_PERMISSION;
    m_outputs_map.at("bit44")           = m_ccu_to_all_jrus_4.bits.bit44;
    m_outputs_map.at("bit45")           = m_ccu_to_all_jrus_4.bits.bit45;
    m_outputs_map.at("bit46")           = m_ccu_to_all_jrus_4.bits.bit46;
    m_outputs_map.at("bit47")           = m_ccu_to_all_jrus_4.bits.bit47;
    m_outputs_map.at("Parking_mode_on_off")           = m_ccu_to_all_jrus_4.bits.Parking_mode_on_off;
    m_outputs_map.at("PG_NDIRECT_BRAKE_CONTROL")           = m_ccu_to_all_jrus_4.bits.PG_NDIRECT_BRAKE_CONTROL;
    m_outputs_map.at("SKA1_PB_Emergency")            = m_ccu_to_all_jrus_4.bits.SKA1_PB_Emergency;
    m_outputs_map.at("SKA2_PB_Emergency")            = m_ccu_to_all_jrus_4.bits.SKA2_PB_Emergency;
    m_outputs_map.at("SKA1_MC_S1")            = m_ccu_to_all_jrus_4.bits.SKA1_MC_S1;
    m_outputs_map.at("SKA1_MC_S2")            = m_ccu_to_all_jrus_4.bits.SKA1_MC_S2;
    m_outputs_map.at("SKA1_MC_S3")            = m_ccu_to_all_jrus_4.bits.SKA1_MC_S3;
    m_outputs_map.at("SKA1_MC_S4")            = m_ccu_to_all_jrus_4.bits.SKA1_MC_S4;
    m_outputs_map.at("SKA1_MC_S5")            = m_ccu_to_all_jrus_4.bits.SKA1_MC_S5;
    m_outputs_map.at("SKA1_MC_S6")            = m_ccu_to_all_jrus_4.bits.SKA1_MC_S6;
    m_outputs_map.at("SKA2_MC_S1")            = m_ccu_to_all_jrus_4.bits.SKA2_MC_S1;
    m_outputs_map.at("SKA2_MC_S2")            = m_ccu_to_all_jrus_4.bits.SKA2_MC_S2;
    m_outputs_map.at("SKA2_MC_S3")      = m_ccu_to_all_jrus_4.bits.SKA2_MC_S3;
    m_outputs_map.at("SKA2_MC_S4")      = m_ccu_to_all_jrus_4.bits.SKA2_MC_S4;
    m_outputs_map.at("SKA2_MC_S5")      = m_ccu_to_all_jrus_4.bits.SKA2_MC_S5;
    m_outputs_map.at("SKA2_MC_S6")      = m_ccu_to_all_jrus_4.bits.SKA2_MC_S6;
    m_outputs_map.at("HORN_1_IC ")      = m_ccu_to_all_jrus_4.bits.HORN_1_IC ;
    m_outputs_map.at("HORN_2_IC ")      = m_ccu_to_all_jrus_4.bits.HORN_2_IC ;
    m_outputs_map.at("OA1_PG_COMPRESSOR_CONTROL")       = m_ccu_to_all_jrus_4.bits.OA1_PG_COMPRESSOR_CONTROL;
    m_outputs_map.at("OA1_IC_ASU")       = m_ccu_to_all_jrus_4.bits.OA1_IC_ASU;
    m_outputs_map.at("OA2_PG_COMPRESSOR_CONTROL")                      = m_ccu_to_all_jrus_4.bits.OA2_PG_COMPRESSOR_CONTROL;
    m_outputs_map.at("OA2_IC_ASU")                                         = m_ccu_to_all_jrus_4.bits.OA2_IC_ASU;
    m_outputs_map.at("ISOLATION_COCKS_PNEUMATIC_BRAKE")                        = m_ccu_to_all_jrus_4.bits.ISOLATION_COCKS_PNEUMATIC_BRAKE;
    m_outputs_map.at("ISOLATION_COCKS_INDIRECT_BRAKE")                         = m_ccu_to_all_jrus_4.bits.ISOLATION_COCKS_INDIRECT_BRAKE;
    m_outputs_map.at("ISOLATION_COCKS_DIRECT_BRAKE_BO1")                       = m_ccu_to_all_jrus_4.bits.ISOLATION_COCKS_DIRECT_BRAKE_BO1;
    m_outputs_map.at("ISOLATION_COCKS_DIRECT_BRAKE_BO2")                       = m_ccu_to_all_jrus_4.bits.ISOLATION_COCKS_DIRECT_BRAKE_BO2;
    m_outputs_map.at("ISOLATION_COCKS_PB_ISOLATED")                            = m_ccu_to_all_jrus_4.bits.ISOLATION_COCKS_PB_ISOLATED;
    m_outputs_map.at("ISOLATION_COCKS_SAND_ISOLATED")                          = m_ccu_to_all_jrus_4.bits.ISOLATION_COCKS_SAND_ISOLATED;
    m_outputs_map.at("ISOLATION_COCKS_BP_TO_MRP_BYPASS")                       = m_ccu_to_all_jrus_4.bits.ISOLATION_COCKS_BP_TO_MRP_BYPASS;
    m_outputs_map.at("bit77")                                         = m_ccu_to_all_jrus_4.bits.bit77;
    m_outputs_map.at("bit78")                                         = m_ccu_to_all_jrus_4.bits.bit78;
    m_outputs_map.at("bit79")                                         = m_ccu_to_all_jrus_4.bits.bit79;
    m_outputs_map.at("SL_CUT_OFF_BYPASS")                                              = m_ccu_to_all_jrus_4.bits.SL_CUT_OFF_BYPASS;//byte 10;
    m_outputs_map.at("SL_DEAD_MAN_BYPASS")                                             = m_ccu_to_all_jrus_4.bits.SL_DEAD_MAN_BYPASS;
    m_outputs_map.at("SL_DOORS_SIDE_CONTROL_ETCS_BYPASS")                              = m_ccu_to_all_jrus_4.bits.SL_DOORS_SIDE_CONTROL_ETCS_BYPASS;
    m_outputs_map.at("SL_ETCS_BYPASS")                                                 = m_ccu_to_all_jrus_4.bits.SL_ETCS_BYPASS;
    m_outputs_map.at("ATS_BYPASS")                                                     = m_ccu_to_all_jrus_4.bits.ATS_BYPASS;
    m_outputs_map.at("VACUUM_OPENING_BYPASS")                                          = m_ccu_to_all_jrus_4.bits.VACUUM_OPENING_BYPASS;
    m_outputs_map.at("ZERO_SPEED_BYPASS")                                              = m_ccu_to_all_jrus_4.bits.ZERO_SPEED_BYPASS;
    m_outputs_map.at("SELECTOR_BYPASS_PASSANGER_ALARM")                                = m_ccu_to_all_jrus_4.bits.SELECTOR_BYPASS_PASSANGER_ALARM;
    m_outputs_map.at("SL_DOORS_LOOP_BYPASS")                                           = m_ccu_to_all_jrus_4.bits.SL_DOORS_LOOP_BYPASS;//byte 11;
    m_outputs_map.at("bit89")                                         = m_ccu_to_all_jrus_4.bits.bit89;
    m_outputs_map.at("bit90")                                         = m_ccu_to_all_jrus_4.bits.bit90;
    m_outputs_map.at("bit91")                                         = m_ccu_to_all_jrus_4.bits.bit91;
    m_outputs_map.at("bit92")                                         = m_ccu_to_all_jrus_4.bits.bit92;
    m_outputs_map.at("bit93")                                         = m_ccu_to_all_jrus_4.bits.bit93;
    m_outputs_map.at("bit94")                                         = m_ccu_to_all_jrus_4.bits.bit94;
    m_outputs_map.at("bit95")                                         = m_ccu_to_all_jrus_4.bits.bit95;
    m_outputs_map.at("ATS_mode_on")                                                                 = m_ccu_to_all_jrus_4.bits.ATS_mode_on;
    m_outputs_map.at("ZERO_SPEED")                                                                  = m_ccu_to_all_jrus_4.bits.ZERO_SPEED;
    m_outputs_map.at("OA1_POSITION_1_PANTOGRAPH_ENABLED")                                           = m_ccu_to_all_jrus_4.bits.OA1_POSITION_1_PANTOGRAPH_ENABLED;
    m_outputs_map.at("OA1_POSITION_0_PANTOGRAPH_ISOLATED")                                          = m_ccu_to_all_jrus_4.bits.OA1_POSITION_0_PANTOGRAPH_ISOLATED;
    m_outputs_map.at("OA2_POSITION_1_PANTOGRAPH_ENABLED")                                           = m_ccu_to_all_jrus_4.bits.OA2_POSITION_1_PANTOGRAPH_ENABLED;
    m_outputs_map.at("OA2_POSITION_0_PANTOGRAPH_ISOLATED")                                          = m_ccu_to_all_jrus_4.bits.OA2_POSITION_0_PANTOGRAPH_ISOLATED;
    m_outputs_map.at("OA1_READY_VCB")                                                               = m_ccu_to_all_jrus_4.bits.OA1_READY_VCB;
    m_outputs_map.at("OA1_VCB_CLOSE")                                                               = m_ccu_to_all_jrus_4.bits.OA1_VCB_CLOSE;
    m_outputs_map.at("OA1_OPEN_VCB_FOR_HIGH_CURRENT")                                               = m_ccu_to_all_jrus_4.bits.OA1_OPEN_VCB_FOR_HIGH_CURRENT;//byte 13;
    m_outputs_map.at("OA1_FAST_OPEN_VCB")                                                           = m_ccu_to_all_jrus_4.bits.OA1_FAST_OPEN_VCB;
    m_outputs_map.at("OA2_READY_VCB")                                         = m_ccu_to_all_jrus_4.bits.OA2_READY_VCB;
    m_outputs_map.at("OA2_VCB_CLOSE")                                         = m_ccu_to_all_jrus_4.bits.OA2_VCB_CLOSE;
    m_outputs_map.at("OA2_OPEN_VCB_FOR_HIGH_CURRENT")                         = m_ccu_to_all_jrus_4.bits.OA2_OPEN_VCB_FOR_HIGH_CURRENT;
    m_outputs_map.at("OA2_FAST_OPEN_VCB")                                     = m_ccu_to_all_jrus_4.bits.OA2_FAST_OPEN_VCB;
    m_outputs_map.at("OA1_HV_DISCONNECTOR_MOVING_OR_CLOSE_D")                 = m_ccu_to_all_jrus_4.bits.OA1_HV_DISCONNECTOR_MOVING_OR_CLOSE_D;
    m_outputs_map.at("OA1_HV_DISCONNECTOR_CLOSED_E")                          = m_ccu_to_all_jrus_4.bits.OA1_HV_DISCONNECTOR_CLOSED_E;
    m_outputs_map.at("OA1_HV_DISCONNECTOR_MOVING_OR_OPEN_A")                  = m_ccu_to_all_jrus_4.bits.OA1_HV_DISCONNECTOR_MOVING_OR_OPEN_A;
    m_outputs_map.at("OA1_HV_DISCONNECTOR_OPENED_B")                          = m_ccu_to_all_jrus_4.bits.OA1_HV_DISCONNECTOR_OPENED_B;
    m_outputs_map.at("OA2_HV_DISCONNECTOR_MOVING_OR_CLOSE_D")                 = m_ccu_to_all_jrus_4.bits.OA2_HV_DISCONNECTOR_MOVING_OR_CLOSE_D;
    m_outputs_map.at("OA2_HV_DISCONNECTOR_CLOSED_E")                          = m_ccu_to_all_jrus_4.bits.OA2_HV_DISCONNECTOR_CLOSED_E;
    m_outputs_map.at("OA2_HV_DISCONNECTOR_MOVING_OR_OPEN_A")                          = m_ccu_to_all_jrus_4.bits.OA2_HV_DISCONNECTOR_MOVING_OR_OPEN_A;
    m_outputs_map.at("OA2_HV_DISCONNECTOR_OPENED_B")                                  = m_ccu_to_all_jrus_4.bits.OA2_HV_DISCONNECTOR_OPENED_B;
    m_outputs_map.at("RAISING_PANTOGRAPH_1")                                          = m_ccu_to_all_jrus_4.bits.RAISING_PANTOGRAPH_1;
    m_outputs_map.at("DOWN_PANTOGRAPH_1")                                             = m_ccu_to_all_jrus_4.bits.DOWN_PANTOGRAPH_1;
    m_outputs_map.at("RAISING_PANTOGRAPH_2")                                          = m_ccu_to_all_jrus_4.bits.RAISING_PANTOGRAPH_2;
    m_outputs_map.at("DOWN_PANTOGRAPH_2")                                             = m_ccu_to_all_jrus_4.bits.DOWN_PANTOGRAPH_2;
    m_outputs_map.at("SKA1_CLOSING_VACUUM_CIRCUIT_BREAKER")                           = m_ccu_to_all_jrus_4.bits.SKA1_CLOSING_VACUUM_CIRCUIT_BREAKER;
    m_outputs_map.at("SKA1_OPENING_VACUUM_CIRCUIT_BREAKER")                           = m_ccu_to_all_jrus_4.bits.SKA1_OPENING_VACUUM_CIRCUIT_BREAKER;
    m_outputs_map.at("SKA2_CLOSING_VACUUM_CIRCUIT_BREAKER")                                         = m_ccu_to_all_jrus_4.bits.SKA2_CLOSING_VACUUM_CIRCUIT_BREAKER;
    m_outputs_map.at("SKA2_OPENING_VACUUM_CIRCUIT_BREAKER")                                         = m_ccu_to_all_jrus_4.bits.SKA2_OPENING_VACUUM_CIRCUIT_BREAKER;
    m_outputs_map.at("OA1_EARTHING_SWITCH_SERVICE_POSITION")                                        = m_ccu_to_all_jrus_4.bits.OA1_EARTHING_SWITCH_SERVICE_POSITION;
    m_outputs_map.at("OA1_EARTHING_SWITCH_EARTH_POSITION")                                          = m_ccu_to_all_jrus_4.bits.OA1_EARTHING_SWITCH_EARTH_POSITION;
    m_outputs_map.at("EARTHING_PANEL_YELLOW_KEY_EXTRACTED")                                         = m_ccu_to_all_jrus_4.bits.EARTHING_PANEL_YELLOW_KEY_EXTRACTED;
    m_outputs_map.at("OA2_EARTHING_SWITCH_SERVICE_POSITION")                                        = m_ccu_to_all_jrus_4.bits.OA2_EARTHING_SWITCH_SERVICE_POSITION;
    m_outputs_map.at("OA2_EARTHING_SWITCH_EARTH_POSITION")                                          = m_ccu_to_all_jrus_4.bits.OA2_EARTHING_SWITCH_EARTH_POSITION;
    m_outputs_map.at("EARTHING_PANEL_YELLOW_KEY_EXTRACTED_1")                                       = m_ccu_to_all_jrus_4.bits.EARTHING_PANEL_YELLOW_KEY_EXTRACTED_1;
    m_outputs_map.at("bit132")                                         = m_ccu_to_all_jrus_4.bits.bit132;
    m_outputs_map.at("bit133")                                         = m_ccu_to_all_jrus_4.bits.bit133;
    m_outputs_map.at("bit134")                                         = m_ccu_to_all_jrus_4.bits.bit134;
    m_outputs_map.at("bit135")                                         = m_ccu_to_all_jrus_4.bits.bit135;
    m_outputs_map.at("TRANSDUCER_HV_VOLTAGE_VCB_IN")                                         = m_ccu_to_all_jrus_4.bits.TRANSDUCER_HV_VOLTAGE_VCB_IN;
    m_outputs_map.at("TRANSDUCER_HV_CURRENT_VCB_IN")                                         = m_ccu_to_all_jrus_4.bits.TRANSDUCER_HV_CURRENT_VCB_IN;
    m_outputs_map.at("SKA1_HANDLE_1_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.SKA1_HANDLE_1_PASSENGER_ALARM;
    m_outputs_map.at("SKA1_HANDLE_2_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.SKA1_HANDLE_2_PASSENGER_ALARM;
    m_outputs_map.at("SKA1_HANDLE_3_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.SKA1_HANDLE_3_PASSENGER_ALARM;
    m_outputs_map.at("SKA1_HANDLE_4_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.SKA1_HANDLE_4_PASSENGER_ALARM;
    m_outputs_map.at("SKA1_HANDLE_5_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.SKA1_HANDLE_5_PASSENGER_ALARM;
    m_outputs_map.at("SKA1_HANDLE_6_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.SKA1_HANDLE_6_PASSENGER_ALARM;
    m_outputs_map.at("SKA1_HANDLE_7_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.SKA1_HANDLE_7_PASSENGER_ALARM;
    m_outputs_map.at("SKA1_HANDLE_8_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.SKA1_HANDLE_8_PASSENGER_ALARM;
    m_outputs_map.at("SKA2_HANDLE_1_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.SKA2_HANDLE_1_PASSENGER_ALARM;
    m_outputs_map.at("SKA2_HANDLE_2_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.SKA2_HANDLE_2_PASSENGER_ALARM;
    m_outputs_map.at("SKA2_HANDLE_3_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.SKA2_HANDLE_3_PASSENGER_ALARM;
    m_outputs_map.at("SKA2_HANDLE_4_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.SKA2_HANDLE_4_PASSENGER_ALARM;
    m_outputs_map.at("SKA2_HANDLE_5_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.SKA2_HANDLE_5_PASSENGER_ALARM;
    m_outputs_map.at("SKA2_HANDLE_6_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.SKA2_HANDLE_6_PASSENGER_ALARM;
    m_outputs_map.at("SKA2_HANDLE_7_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.SKA2_HANDLE_7_PASSENGER_ALARM;
    m_outputs_map.at("SKA2_HANDLE_8_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.SKA2_HANDLE_8_PASSENGER_ALARM;
    m_outputs_map.at("OA1_HANDLE_1_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.OA1_HANDLE_1_PASSENGER_ALARM;
    m_outputs_map.at("OA1_HANDLE_2_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.OA1_HANDLE_2_PASSENGER_ALARM;
    m_outputs_map.at("OA1_HANDLE_3_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.OA1_HANDLE_3_PASSENGER_ALARM;
    m_outputs_map.at("OA1_HANDLE_4_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.OA1_HANDLE_4_PASSENGER_ALARM;
    m_outputs_map.at("OA1_HANDLE_5_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.OA1_HANDLE_5_PASSENGER_ALARM;
    m_outputs_map.at("OA1_HANDLE_6_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.OA1_HANDLE_6_PASSENGER_ALARM;
    m_outputs_map.at("OA1_HANDLE_7_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.OA1_HANDLE_7_PASSENGER_ALARM;
    m_outputs_map.at("OA1_HANDLE_8_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.OA1_HANDLE_8_PASSENGER_ALARM;
    m_outputs_map.at("OA2_HANDLE_1_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.OA2_HANDLE_1_PASSENGER_ALARM;
    m_outputs_map.at("OA2_HANDLE_2_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.OA2_HANDLE_2_PASSENGER_ALARM;
    m_outputs_map.at("OA2_HANDLE_3_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.OA2_HANDLE_3_PASSENGER_ALARM;
    m_outputs_map.at("OA2_HANDLE_4_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.OA2_HANDLE_4_PASSENGER_ALARM;
    m_outputs_map.at("OA2_HANDLE_5_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.OA2_HANDLE_5_PASSENGER_ALARM;
    m_outputs_map.at("OA2_HANDLE_6_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.OA2_HANDLE_6_PASSENGER_ALARM;
    m_outputs_map.at("OA2_HANDLE_7_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.OA2_HANDLE_7_PASSENGER_ALARM;
    m_outputs_map.at("OA2_HANDLE_8_PASSENGER_ALARM")                                         = m_ccu_to_all_jrus_4.bits.OA2_HANDLE_8_PASSENGER_ALARM;
    m_outputs_map.at("SKA1_SAND_LV_SENSOR_BOG1_BEARING_RIGHT")                                         = m_ccu_to_all_jrus_4.bits.SKA1_SAND_LV_SENSOR_BOG1_BEARING_RIGHT;
    m_outputs_map.at("SKA1_SAND_LV_SENSOR_BOG1_BEARING_LEFT")                                         = m_ccu_to_all_jrus_4.bits.SKA1_SAND_LV_SENSOR_BOG1_BEARING_LEFT;
    m_outputs_map.at("SKA1_SAND_LV_SENSOR_BOG2_BEARING_RIGHT")                                         = m_ccu_to_all_jrus_4.bits.SKA1_SAND_LV_SENSOR_BOG2_BEARING_RIGHT;
    m_outputs_map.at("SKA1_SAND_LV_SENSOR_BOG2_BEARING_LEFT")                                         = m_ccu_to_all_jrus_4.bits.SKA1_SAND_LV_SENSOR_BOG2_BEARING_LEFT;
    m_outputs_map.at("SKA2_SAND_LV_SENSOR_BOG1_BEARING_RIGHT")                                         = m_ccu_to_all_jrus_4.bits.SKA2_SAND_LV_SENSOR_BOG1_BEARING_RIGHT;
    m_outputs_map.at("SKA2_SAND_LV_SENSOR_BOG1_BEARING_LEFT")                                         = m_ccu_to_all_jrus_4.bits.SKA2_SAND_LV_SENSOR_BOG1_BEARING_LEFT;
    m_outputs_map.at("SKA2_SAND_LV_SENSOR_BOG2_BEARING_RIGHT")                                         = m_ccu_to_all_jrus_4.bits.SKA2_SAND_LV_SENSOR_BOG2_BEARING_RIGHT;
    m_outputs_map.at("SKA2_SAND_LV_SENSOR_BOG2_BEARING_LEFT")                                         = m_ccu_to_all_jrus_4.bits.SKA2_SAND_LV_SENSOR_BOG2_BEARING_LEFT;
    m_outputs_map.at("SKA1_CCU_OK")                                         = m_ccu_to_all_jrus_4.bits.SKA1_CCU_OK;
    m_outputs_map.at("SKA2_CCU_OK")                                         = m_ccu_to_all_jrus_4.bits.SKA2_CCU_OK;
    m_outputs_map.at("SKA1_DD_RIOM_M_OK")                                         = m_ccu_to_all_jrus_4.bits.SKA1_DD_RIOM_M_OK;
    m_outputs_map.at("SKA1_DD_RIOM_R_OK")                                         = m_ccu_to_all_jrus_4.bits.SKA1_DD_RIOM_R_OK;
    m_outputs_map.at("SKA2_DD_RIOM_M_OK")                                         = m_ccu_to_all_jrus_4.bits.SKA2_DD_RIOM_M_OK;
    m_outputs_map.at("SKA2_DD_RIOM_R_OK")                                         = m_ccu_to_all_jrus_4.bits.SKA2_DD_RIOM_R_OK;
    m_outputs_map.at("SKA1_VH_RIOM_M_OK")                                         = m_ccu_to_all_jrus_4.bits.SKA1_VH_RIOM_M_OK;
    m_outputs_map.at("SKA1_VH_RIOM_R_OK")                                         = m_ccu_to_all_jrus_4.bits.SKA1_VH_RIOM_R_OK;
    m_outputs_map.at("SKA2_VH_RIOM_M_OK")                                         = m_ccu_to_all_jrus_4.bits.SKA2_VH_RIOM_M_OK;
    m_outputs_map.at("SKA2_VH_RIOM_R_OK")                                         = m_ccu_to_all_jrus_4.bits.SKA2_VH_RIOM_R_OK;
    m_outputs_map.at("OA1_VH_RIOM_M_OK ")                                         = m_ccu_to_all_jrus_4.bits.OA1_VH_RIOM_M_OK;
    m_outputs_map.at("OA1_VH_RIOM_R_OK ")                                         = m_ccu_to_all_jrus_4.bits.OA1_VH_RIOM_R_OK;
    m_outputs_map.at("OA2_VH_RIOM_M_OK ")                                         = m_ccu_to_all_jrus_4.bits.OA2_VH_RIOM_M_OK;
    m_outputs_map.at("OA2_VH_RIOM_R_OK ")                                         = m_ccu_to_all_jrus_4.bits.OA2_VH_RIOM_R_OK;
    m_outputs_map.at("SKA1_HMI_OK")                                         = m_ccu_to_all_jrus_4.bits.SKA1_HMI_OK;
    m_outputs_map.at("SKA2_HMI_OK")                                         = m_ccu_to_all_jrus_4.bits.SKA2_HMI_OK;
    m_outputs_map.at("OA1_MVB_REPEATER_OK")                                         = m_ccu_to_all_jrus_4.bits.OA1_MVB_REPEATER_OK;
    m_outputs_map.at("OA2_MVB_REPEATER_OK")                                         = m_ccu_to_all_jrus_4.bits.OA2_MVB_REPEATER_OK;
    m_outputs_map.at("SKA1_WTB_GW_OK")                                         = m_ccu_to_all_jrus_4.bits.SKA1_WTB_GW_OK;
    m_outputs_map.at("SKA2_WTB_GW_OK")                                         = m_ccu_to_all_jrus_4.bits.SKA2_WTB_GW_OK;
    m_outputs_map.at("SKA1_ETH_SW_OK")                                         = m_ccu_to_all_jrus_4.bits.SKA1_ETH_SW_OK;
    m_outputs_map.at("SKA2_ETH_SW_OK")                                         = m_ccu_to_all_jrus_4.bits.SKA2_ETH_SW_OK;
    m_outputs_map.at("OA1_ETH_SW_OK ")                                         = m_ccu_to_all_jrus_4.bits.OA1_ETH_SW_OK;
    m_outputs_map.at("OA2_ETH_SW_OK ")                                         = m_ccu_to_all_jrus_4.bits.OA2_ETH_SW_OK;
    m_outputs_map.at("OA1_APU_OK :1;")                                         = m_ccu_to_all_jrus_4.bits.OA1_APU_OK;
    m_outputs_map.at("OA2_APU_OK :1;")                                         = m_ccu_to_all_jrus_4.bits.OA2_APU_OK;
    m_outputs_map.at("SKA1_TCU1_OK")                                         = m_ccu_to_all_jrus_4.bits.SKA1_TCU1_OK;
    m_outputs_map.at("SKA1_TCU2_OK")                                         = m_ccu_to_all_jrus_4.bits.SKA1_TCU2_OK;
    m_outputs_map.at("SKA2_TCU1_OK")                                         = m_ccu_to_all_jrus_4.bits.SKA2_TCU1_OK;
    m_outputs_map.at("SKA2_TCU2_OK")                                         = m_ccu_to_all_jrus_4.bits.SKA2_TCU2_OK;
    m_outputs_map.at("SKA1_SIGNALING_AIRSUSP_FAIL")                                         = m_ccu_to_all_jrus_4.bits.SKA1_SIGNALING_AIRSUSP_FAIL;
    m_outputs_map.at("SKA2_SIGNALING_AIRSUSP_FAIL")                                         = m_ccu_to_all_jrus_4.bits.SKA2_SIGNALING_AIRSUSP_FAIL;
    m_outputs_map.at("reserved_30")                                         = m_ccu_to_all_jrus_4.bits.reserved_30;
    m_outputs_map.at("reserved_31")                                         = m_ccu_to_all_jrus_4.bits.reserved_31;

}
