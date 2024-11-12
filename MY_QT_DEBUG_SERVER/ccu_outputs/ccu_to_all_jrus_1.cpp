#include "ccu_to_all_jrus_1.h"
#include <QDebug>

Ccu_To_All_Jrus_1::Ccu_To_All_Jrus_1(QObject *parent)
    : QObject{parent}
{
    init_table();
}

Ccu_To_All_Jrus_1::~Ccu_To_All_Jrus_1()
{
    delete m_tableWidget;
}

void Ccu_To_All_Jrus_1::set_data_struct(const QByteArray &output)
{
    if (output.size() == sizeof(m_ccu_to_all_jrus_1.bytes)) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        memcpy(m_ccu_to_all_jrus_1.bytes, output.constData(), sizeof(m_ccu_to_all_jrus_1.bytes));
        update_map();
        update_table();
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }
}

void Ccu_To_All_Jrus_1::init_table()
{
    m_outputs_map = {
        {"Lifesign", 0},
        {"Badge_id_byte1", 0},
        {"Badge_id_byte2", 0},
        {"Badge_id_byte3", 0},
        {"Badge_id_byte4", 0},
        {"Badge_id_byte5", 0},
        {"Badge_id_byte6", 0},
        {"Badge_id_byte7", 0},
        {"reserved_9", 0},
        {"OA1_JRU_ID_valid", 0},
        {"OA1_JRU_ID_invalid", 0},
        {"OA2_JRU_ID_valid", 0},
        {"OA2_JRU_ID_invalid", 0},
        {"Login_status", 0},
        {"bit85", 0},
        {"bit86", 0},
        {"bit87", 0},
        {"ATS_brake_request", 0},
        {"DAC_brake_request", 0},
        {"HORN_request", 0},
        {"bit91", 0},
        {"bit92", 0},
        {"bit93", 0},
        {"bit94", 0},
        {"bit95", 0},
        {"S_PrkBrAp", 0},
        {"S_HolBrAp", 0},
        {"Park_mode_active", 0},
        {"S_PnBrAp_SKA1_Bo1", 0},
        {"S_PnBrAp_SKA1_Bo2", 0},
        {"S_PnBrAp_OA1_Bo1", 0},
        {"S_PnBrAp_OA1_Bo2", 0},
        {"S_PnBrAp_OA2_Bo1", 0},
        {"S_PnBrAp_OA2_Bo2", 0},
        {"S_PnBrAp_SKA2_Bo1", 0},
        {"S_PnBrAp_SKA2_Bo2", 0},
        {"S_PrkBrRe_SKA1", 0},
        {"S_PrkBrRe_SKA2", 0},
        {"S_PrkBrRe_OA1", 0},
        {"S_PrkBrRe_OA2", 0},
        {"bit111", 0},
        {"X_VAxl1", 0},
        {"X_VAxl2", 0},
        {"X_VAxl3", 0},
        {"X_VAxl4", 0},
        {"X_Vref", 0},
        {"S_WSPTest_Run", 0},
        {"S_WSPactive_SKA1_Bo1", 0},
        {"S_WSPactive_SKA1_Bo2", 0},
        {"S_WSPactive_OA1_Bo1", 0},
        {"S_WSPactive_OA1_Bo2", 0},
        {"S_WSPactive_OA2_Bo1", 0},
        {"S_WSPactive_OA2_Bo2", 0},
        {"S_WSPactive_SKA2_Bo1", 0},
        {"S_WSPactive_SKA2_Bo2", 0},
        {"S_Sanding_Heating_Release", 0},
        {"S_Sanding_requested", 0},
        {"WFL_Spray_Enable", 0},
        {"S_ASC_Mode_active", 0},
        {"bit205", 0},
        {"bit206", 0},
        {"bit207", 0},
        {"SIGNAL_SPEED", 0},
        {"SKA1_HVAC1_ON", 0},
        {"SKA1_HVAC2_ON", 0},
        {"SKA2_HVAC1_ON", 0},
        {"SKA2_HVAC2_ON", 0},
        {"OA1_HVAC1_ON", 0},
        {"OA1_HVAC2_ON", 0},
        {"OA2_HVAC1_ON", 0},
        {"OA2_HVAC2_ON", 0},
        {"SKA1_CONTACTOR_HVAC_LEFT_SIDE", 0},
        {"SKA1_CONTACTOR_HVAC_RIGHT_SIDE", 0},
        {"SKA2_CONTACTOR_HVAC_LEFT_SIDE", 0},
        {"SKA2_CONTACTOR_HVAC_RIGHT_SIDE", 0},
        {"OA1_CONTACTOR_HVAC_LEFT_SIDE", 0},
        {"OA1_CONTACTOR_HVAC_RIGHT_SIDE", 0},
        {"OA2_CONTACTOR_HVAC_LEFT_SIDE", 0},
        {"OA2_CONTACTOR_HVAC_RIGHT_SIDE", 0},
        {"SKA1_DUMPER", 0},
        {"SKA2_DUMPER", 0},
        {"SKA1_WINDSCREEN_HEATING", 0},
        {"SKA1_WIPER_SYSTEM_FUNCTION_OK", 0},
        {"SKA1_WIPER_LEVEL_WASH_WATER_TANK", 0},
        {"SKA1_FULL_LIGHT_MARKER_LIGHT", 0},
        {"SKA1_DIMMED_HEAD_LIGHT_MARKER_LIGHT", 0},
        {"SKA1_MARKER_LIGHT", 0},
        {"SKA1_DIMMED_MARKER_LIGHT", 0},
        {"SKA2_WINDSCREEN_HEATING", 0},
        {"SKA2_WIPER_SYSTEM_FUNCTION_OK", 0},
        {"SKA2_WIPER_LEVEL_WASH_WATER_TANK", 0},
        {"SKA2_FULL_LIGHT_MARKER_LIGHT", 0},
        {"SKA2_DIMMED_HEAD_LIGHT_MARKER_LIGHT", 0},
        {"SKA2_MARKER_LIGHT", 0},
        {"SKA2_DIMMED_MARKER_LIGHT", 0},
    };

    QStringList table_name = {"ccu_to_all_jrus_1", "value"};

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
}

void Ccu_To_All_Jrus_1::update_table()
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

void Ccu_To_All_Jrus_1::update_map()
{

    m_outputs_map.at("Lifesign")                = m_ccu_to_all_jrus_1.bits.Lifesign;
    m_outputs_map.at("Badge_id_byte1")          = m_ccu_to_all_jrus_1.bits.Badge_id_byte1;
    m_outputs_map.at("Badge_id_byte2")          = m_ccu_to_all_jrus_1.bits.Badge_id_byte2;
    m_outputs_map.at("Badge_id_byte3")          = m_ccu_to_all_jrus_1.bits.Badge_id_byte3;
    m_outputs_map.at("Badge_id_byte4")          = m_ccu_to_all_jrus_1.bits.Badge_id_byte4;
    m_outputs_map.at("Badge_id_byte5")          = m_ccu_to_all_jrus_1.bits.Badge_id_byte5;
    m_outputs_map.at("Badge_id_byte6")          = m_ccu_to_all_jrus_1.bits.Badge_id_byte6;
    m_outputs_map.at("Badge_id_byte7")          = m_ccu_to_all_jrus_1.bits.Badge_id_byte7;
    m_outputs_map.at("reserved_9")              = m_ccu_to_all_jrus_1.bits.reserved_9;
    m_outputs_map.at("OA1_JRU_ID_valid")        = m_ccu_to_all_jrus_1.bits.OA1_JRU_ID_valid;
    m_outputs_map.at("OA2_JRU_ID_invalid")      = m_ccu_to_all_jrus_1.bits.OA2_JRU_ID_invalid;
    m_outputs_map.at("OA2_JRU_ID_invalid")      = m_ccu_to_all_jrus_1.bits.OA2_JRU_ID_invalid;
    m_outputs_map.at("OA2_JRU_ID_invalid")      = m_ccu_to_all_jrus_1.bits.OA2_JRU_ID_invalid;
    m_outputs_map.at("Login_status")            = m_ccu_to_all_jrus_1.bits.Login_status;
    m_outputs_map.at("bit85")                   = m_ccu_to_all_jrus_1.bits.bit85;
    m_outputs_map.at("bit86")                   = m_ccu_to_all_jrus_1.bits.bit86;
    m_outputs_map.at("bit87")                   = m_ccu_to_all_jrus_1.bits.bit87;
    m_outputs_map.at("ATS_brake_request")       = m_ccu_to_all_jrus_1.bits.ATS_brake_request;
    m_outputs_map.at("DAC_brake_request")       = m_ccu_to_all_jrus_1.bits.DAC_brake_request;
    m_outputs_map.at("HORN_request")            = m_ccu_to_all_jrus_1.bits.HORN_request;
    m_outputs_map.at("bit91")                   = m_ccu_to_all_jrus_1.bits.bit91;
    m_outputs_map.at("bit92")                   = m_ccu_to_all_jrus_1.bits.bit92;
    m_outputs_map.at("bit93")                   = m_ccu_to_all_jrus_1.bits.bit93;
    m_outputs_map.at("bit94")                   = m_ccu_to_all_jrus_1.bits.bit94;
    m_outputs_map.at("bit95")                   = m_ccu_to_all_jrus_1.bits.bit95;
    m_outputs_map.at("S_PrkBrAp")               = m_ccu_to_all_jrus_1.bits.S_PrkBrAp;
    m_outputs_map.at("S_HolBrAp")               = m_ccu_to_all_jrus_1.bits.S_HolBrAp;
    m_outputs_map.at("Park_mode_active")        = m_ccu_to_all_jrus_1.bits.Park_mode_active;
    m_outputs_map.at("S_PnBrAp_SKA1_Bo1")       = m_ccu_to_all_jrus_1.bits.S_PnBrAp_SKA1_Bo1;
    m_outputs_map.at("S_PnBrAp_SKA1_Bo2")       = m_ccu_to_all_jrus_1.bits.S_PnBrAp_SKA1_Bo2;
    m_outputs_map.at("S_PnBrAp_OA1_Bo1")        = m_ccu_to_all_jrus_1.bits.S_PnBrAp_OA1_Bo1;
    m_outputs_map.at("S_PnBrAp_OA1_Bo2")        = m_ccu_to_all_jrus_1.bits.S_PnBrAp_OA1_Bo2;
    m_outputs_map.at("S_PnBrAp_OA2_Bo1")        = m_ccu_to_all_jrus_1.bits.S_PnBrAp_OA2_Bo1;
    m_outputs_map.at("S_PnBrAp_OA2_Bo2")        = m_ccu_to_all_jrus_1.bits.S_PnBrAp_OA2_Bo2;
    m_outputs_map.at("S_PnBrAp_SKA2_Bo1")       = m_ccu_to_all_jrus_1.bits.S_PnBrAp_SKA2_Bo1;
    m_outputs_map.at("S_PnBrAp_SKA2_Bo2")       = m_ccu_to_all_jrus_1.bits.S_PnBrAp_SKA2_Bo2;
    m_outputs_map.at("S_PrkBrRe_SKA1")          = m_ccu_to_all_jrus_1.bits.S_PrkBrRe_SKA1;
    m_outputs_map.at("S_PrkBrRe_SKA2")          = m_ccu_to_all_jrus_1.bits.S_PrkBrRe_SKA2;
    m_outputs_map.at("S_PrkBrRe_OA1")           = m_ccu_to_all_jrus_1.bits.S_PrkBrRe_OA1;
    m_outputs_map.at("S_PrkBrRe_OA2")           = m_ccu_to_all_jrus_1.bits.S_PrkBrRe_OA2;
    m_outputs_map.at("bit111")                  = m_ccu_to_all_jrus_1.bits.bit111;
    m_outputs_map.at("X_VAxl1")                 = m_ccu_to_all_jrus_1.bits.X_VAxl1;
    m_outputs_map.at("X_VAxl2")                 = m_ccu_to_all_jrus_1.bits.X_VAxl2;
    m_outputs_map.at("X_VAxl3")                 = m_ccu_to_all_jrus_1.bits.X_VAxl3;
    m_outputs_map.at("X_VAxl4")                 = m_ccu_to_all_jrus_1.bits.X_VAxl4;
    m_outputs_map.at("X_Vref")                  = m_ccu_to_all_jrus_1.bits.X_Vref;
    m_outputs_map.at("S_WSPTest_Run")           = m_ccu_to_all_jrus_1.bits.S_WSPTest_Run;
    m_outputs_map.at("S_WSPactive_SKA1_Bo1")     = m_ccu_to_all_jrus_1.bits.S_WSPactive_SKA1_Bo1;
    m_outputs_map.at("S_WSPactive_SKA1_Bo2")     = m_ccu_to_all_jrus_1.bits.S_WSPactive_SKA1_Bo2;
    m_outputs_map.at("S_WSPactive_OA1_Bo1")       = m_ccu_to_all_jrus_1.bits.S_WSPactive_OA1_Bo1;
    m_outputs_map.at("S_WSPactive_OA1_Bo2")       = m_ccu_to_all_jrus_1.bits.S_WSPactive_OA1_Bo2;
    m_outputs_map.at("S_WSPactive_OA2_Bo1")       = m_ccu_to_all_jrus_1.bits.S_WSPactive_OA2_Bo1;
    m_outputs_map.at("S_WSPactive_OA2_Bo2")       = m_ccu_to_all_jrus_1.bits.S_WSPactive_OA2_Bo2;
    m_outputs_map.at("S_WSPactive_SKA2_Bo1")        = m_ccu_to_all_jrus_1.bits.S_WSPactive_SKA2_Bo1;
    m_outputs_map.at("S_WSPactive_SKA2_Bo2")        = m_ccu_to_all_jrus_1.bits.S_WSPactive_SKA2_Bo2;
    m_outputs_map.at("S_Sanding_Heating_Release")   = m_ccu_to_all_jrus_1.bits.S_Sanding_Heating_Release;
    m_outputs_map.at("S_Sanding_requested")         = m_ccu_to_all_jrus_1.bits.S_Sanding_requested;
    m_outputs_map.at("WFL_Spray_Enable")            = m_ccu_to_all_jrus_1.bits.WFL_Spray_Enable;
    m_outputs_map.at("S_ASC_Mode_active")           = m_ccu_to_all_jrus_1.bits.S_ASC_Mode_active;
    m_outputs_map.at("bit205")                      = m_ccu_to_all_jrus_1.bits.bit205;
    m_outputs_map.at("bit206")                      = m_ccu_to_all_jrus_1.bits.bit206;
    m_outputs_map.at("bit207")                      = m_ccu_to_all_jrus_1.bits.bit207;
    m_outputs_map.at("SIGNAL_SPEED")                = m_ccu_to_all_jrus_1.bits.SIGNAL_SPEED;
    m_outputs_map.at("SKA1_HVAC1_ON")               = m_ccu_to_all_jrus_1.bits.SKA1_HVAC1_ON;
    m_outputs_map.at("SKA1_HVAC2_ON")               = m_ccu_to_all_jrus_1.bits.SKA1_HVAC2_ON;
    m_outputs_map.at("SKA2_HVAC1_ON")               = m_ccu_to_all_jrus_1.bits.SKA2_HVAC1_ON;
    m_outputs_map.at("SKA2_HVAC2_ON")               = m_ccu_to_all_jrus_1.bits.SKA2_HVAC2_ON;
    m_outputs_map.at("OA1_HVAC1_ON")                        = m_ccu_to_all_jrus_1.bits.OA1_HVAC1_ON;
    m_outputs_map.at("OA1_HVAC2_ON")                        = m_ccu_to_all_jrus_1.bits.OA1_HVAC2_ON;
    m_outputs_map.at("OA2_HVAC1_ON")                        = m_ccu_to_all_jrus_1.bits.OA2_HVAC1_ON;
    m_outputs_map.at("OA2_HVAC2_ON")                        = m_ccu_to_all_jrus_1.bits.OA2_HVAC2_ON;
    m_outputs_map.at("SKA1_CONTACTOR_HVAC_LEFT_SIDE")       = m_ccu_to_all_jrus_1.bits.SKA1_CONTACTOR_HVAC_LEFT_SIDE;
    m_outputs_map.at("SKA1_CONTACTOR_HVAC_RIGHT_SIDE")      = m_ccu_to_all_jrus_1.bits.SKA1_CONTACTOR_HVAC_RIGHT_SIDE;
    m_outputs_map.at("SKA2_CONTACTOR_HVAC_LEFT_SIDE")       = m_ccu_to_all_jrus_1.bits.SKA2_CONTACTOR_HVAC_LEFT_SIDE;
    m_outputs_map.at("SKA2_CONTACTOR_HVAC_RIGHT_SIDE")      = m_ccu_to_all_jrus_1.bits.SKA2_CONTACTOR_HVAC_RIGHT_SIDE;
    m_outputs_map.at("OA1_CONTACTOR_HVAC_LEFT_SIDE")        = m_ccu_to_all_jrus_1.bits.OA1_CONTACTOR_HVAC_LEFT_SIDE;
    m_outputs_map.at("OA1_CONTACTOR_HVAC_RIGHT_SIDE")       = m_ccu_to_all_jrus_1.bits.OA1_CONTACTOR_HVAC_RIGHT_SIDE;
    m_outputs_map.at("OA2_CONTACTOR_HVAC_LEFT_SIDE")        = m_ccu_to_all_jrus_1.bits.OA2_CONTACTOR_HVAC_LEFT_SIDE;
    m_outputs_map.at("OA2_CONTACTOR_HVAC_RIGHT_SIDE")       = m_ccu_to_all_jrus_1.bits.OA2_CONTACTOR_HVAC_RIGHT_SIDE;
    m_outputs_map.at("SKA1_DUMPER")                         = m_ccu_to_all_jrus_1.bits.SKA1_DUMPER;
    m_outputs_map.at("SKA2_DUMPER")                         = m_ccu_to_all_jrus_1.bits.SKA2_DUMPER;
    m_outputs_map.at("SKA1_WINDSCREEN_HEATING")             = m_ccu_to_all_jrus_1.bits.SKA1_WINDSCREEN_HEATING;
    m_outputs_map.at("SKA1_WIPER_SYSTEM_FUNCTION_OK")       = m_ccu_to_all_jrus_1.bits.SKA1_WIPER_SYSTEM_FUNCTION_OK;
    m_outputs_map.at("SKA1_WIPER_LEVEL_WASH_WATER_TANK")    = m_ccu_to_all_jrus_1.bits.SKA1_WIPER_LEVEL_WASH_WATER_TANK;
    m_outputs_map.at("SKA1_FULL_LIGHT_MARKER_LIGHT")        = m_ccu_to_all_jrus_1.bits.SKA1_FULL_LIGHT_MARKER_LIGHT;
    m_outputs_map.at("SKA1_DIMMED_HEAD_LIGHT_MARKER_LIGHT") = m_ccu_to_all_jrus_1.bits.SKA1_DIMMED_HEAD_LIGHT_MARKER_LIGHT;
    m_outputs_map.at("SKA1_MARKER_LIGHT")                   = m_ccu_to_all_jrus_1.bits.SKA1_MARKER_LIGHT;
    m_outputs_map.at("SKA1_DIMMED_MARKER_LIGHT")            = m_ccu_to_all_jrus_1.bits.SKA1_DIMMED_MARKER_LIGHT;
    m_outputs_map.at("SKA2_WINDSCREEN_HEATING")             = m_ccu_to_all_jrus_1.bits.SKA2_WINDSCREEN_HEATING;
    m_outputs_map.at("SKA2_WIPER_SYSTEM_FUNCTION_OK")       = m_ccu_to_all_jrus_1.bits.SKA2_WIPER_SYSTEM_FUNCTION_OK;
    m_outputs_map.at("SKA2_WIPER_LEVEL_WASH_WATER_TANK")        = m_ccu_to_all_jrus_1.bits.SKA2_WIPER_LEVEL_WASH_WATER_TANK;
    m_outputs_map.at("SKA2_FULL_LIGHT_MARKER_LIGHT")            = m_ccu_to_all_jrus_1.bits.SKA2_FULL_LIGHT_MARKER_LIGHT;
    m_outputs_map.at("SKA2_DIMMED_HEAD_LIGHT_MARKER_LIGHT")     = m_ccu_to_all_jrus_1.bits.SKA2_DIMMED_HEAD_LIGHT_MARKER_LIGHT;
    m_outputs_map.at("SKA2_MARKER_LIGHT")                       = m_ccu_to_all_jrus_1.bits.SKA2_MARKER_LIGHT;
    m_outputs_map.at("SKA2_DIMMED_MARKER_LIGHT")                = m_ccu_to_all_jrus_1.bits.SKA2_DIMMED_MARKER_LIGHT;

}
