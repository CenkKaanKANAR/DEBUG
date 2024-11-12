#include "ccu_to_all_jrus_5.h"

Ccu_To_All_Jrus_5::Ccu_To_All_Jrus_5(QObject *parent)
    : QObject{parent}
{
    init_table();
}

Ccu_To_All_Jrus_5::~Ccu_To_All_Jrus_5()
{
    delete m_tableWidget;
}

void Ccu_To_All_Jrus_5::set_data_struct(const QByteArray &output)
{
    if (output.size() == sizeof(m_ccu_to_all_jrus_5.bytes)) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        memcpy(m_ccu_to_all_jrus_5.bytes, output.constData(), sizeof(m_ccu_to_all_jrus_5.bytes));
        update_map();
        update_table();
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }
}

void Ccu_To_All_Jrus_5::init_table()
{
    m_outputs_map = {
        {"Lifesign", 0},
        {"Total_applied_traction_power", 0},
        {"OA1_FAST_OPEN_ADD", 0},
        {"OA2_FAST_OPEN_ADD", 0},
        {"OA1_DEGRADE_MODE_CONTACTOR", 0},
        {"OA2_DEGRADE_MODE_CONTACTOR", 0},
        {"SKA1_TRAIN_KEY_DDESK", 0},
        {"SKA2_TRAIN_KEY_DDESK", 0},
        {"SKA1_COUPLED_TRAIN_TAIL_RELAY", 0},
        {"SKA2_COUPLED_TRAIN_TAIL_RELAY", 0},
        {"OA1_JRU_ID_invalid", 0},
        {"OA2_JRU_ID_valid", 0},
        {"OA2_JRU_ID_invalid", 0},
        {"SPEED_LIMIT", 0},
        {"bit41", 0},
        {"SKA1_Control_Unit_Radio_Thales_CB_Protection", 0},
        {"SKA2_Control_Unit_Radio_Thales_CB_Protection", 0},
        {"SKA1_GSMR_Radio_Voice", 0},
        {"SKA2_GSMR_Radio_Voice", 0},
        {"HORN_request", 0},
        {"bit46", 0},
        {"bit47", 0},
        {"SKA1_TEST_SAND_LEVELS_SENSORS_BOGIE1", 0},
        {"SKA1_TEST_SAND_LEVELS_SENSORS_BOGIE2", 0},
        {"SKA2_TEST_SAND_LEVELS_SENSORS_BOGIE1", 0},
        {"SKA2_TEST_SAND_LEVELS_SENSORS_BOGIE2", 0},
        {"C_Sanding_Test", 0},
        {"bit53", 0},
        {"bit54", 0},
        {"bit55", 0},
        {"reserved_7", 0},
        {"reserved_8", 0},
        {"reserved_9", 0},
        {"reserved_10", 0},
        {"reserved_11", 0},
        {"reserved_12", 0},
        {"reserved_13", 0},
        {"reserved_14", 0},
        {"reserved_15", 0},
        {"reserved_16", 0},
        {"reserved_17", 0},
        {"reserved_18", 0},
        {"reserved_19", 0},
        {"reserved_20", 0},
        {"reserved_21", 0},
        {"reserved_22", 0},
        {"reserved_23", 0},
        {"reserved_24", 0},
        {"reserved_25", 0},
        {"reserved_26", 0},
        {"reserved_27", 0},
        {"reserved_28", 0},
        {"reserved_29", 0},
        {"reserved_30", 0},
        {"reserved_31", 0}
        };

    QStringList table_name = {"ccu_to_all_jrus_5", "value"};

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
void Ccu_To_All_Jrus_5::update_table()
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

void Ccu_To_All_Jrus_5::update_map()
{

    m_outputs_map.at("Lifesign")                                              = m_ccu_to_all_jrus_5.bits.Lifesign;
    m_outputs_map.at("Total_applied_traction_power")                         = m_ccu_to_all_jrus_5.bits. Total_applied_traction_power;
    m_outputs_map.at("OA1_FAST_OPEN_ADD")                                     = m_ccu_to_all_jrus_5.bits.OA1_FAST_OPEN_ADD;
    m_outputs_map.at("OA2_FAST_OPEN_ADD")                                     = m_ccu_to_all_jrus_5.bits.OA2_FAST_OPEN_ADD;
    m_outputs_map.at("OA1_DEGRADE_MODE_CONTACTOR")                            = m_ccu_to_all_jrus_5.bits.OA1_DEGRADE_MODE_CONTACTOR;
    m_outputs_map.at("OA2_DEGRADE_MODE_CONTACTOR")                            = m_ccu_to_all_jrus_5.bits.OA2_DEGRADE_MODE_CONTACTOR;
    m_outputs_map.at("SKA1_TRAIN_KEY_DDESK")                                  = m_ccu_to_all_jrus_5.bits.SKA1_TRAIN_KEY_DDESK;
    m_outputs_map.at("SKA2_TRAIN_KEY_DDESK")                                  = m_ccu_to_all_jrus_5.bits.SKA2_TRAIN_KEY_DDESK;
    m_outputs_map.at("SKA1_COUPLED_TRAIN_TAIL_RELAY")                         = m_ccu_to_all_jrus_5.bits.SKA1_COUPLED_TRAIN_TAIL_RELAY;
    m_outputs_map.at("SKA2_COUPLED_TRAIN_TAIL_RELAY")                         = m_ccu_to_all_jrus_5.bits.SKA2_COUPLED_TRAIN_TAIL_RELAY;
    m_outputs_map.at("SPEED_LIMIT")                                           = m_ccu_to_all_jrus_5.bits.SPEED_LIMIT;
    m_outputs_map.at("bit41")                                                 = m_ccu_to_all_jrus_5.bits.bit41;
    m_outputs_map.at("SKA1_Control_Unit_Radio_Thales_CB_Protection")          = m_ccu_to_all_jrus_5.bits.SKA1_Control_Unit_Radio_Thales_CB_Protection;
    m_outputs_map.at("SKA2_Control_Unit_Radio_Thales_CB_Protection")          = m_ccu_to_all_jrus_5.bits.SKA2_Control_Unit_Radio_Thales_CB_Protection;
    m_outputs_map.at("SKA1_GSMR_Radio_Voice")                                 = m_ccu_to_all_jrus_5.bits.SKA1_GSMR_Radio_Voice;
    m_outputs_map.at("SKA2_GSMR_Radio_Voice")                                 = m_ccu_to_all_jrus_5.bits.SKA2_GSMR_Radio_Voice;
    m_outputs_map.at("bit46")                                                 = m_ccu_to_all_jrus_5.bits.bit46;
    m_outputs_map.at("bit47")                                                 = m_ccu_to_all_jrus_5.bits.bit47;
    m_outputs_map.at("SKA1_TEST_SAND_LEVELS_SENSORS_BOGIE1")          = m_ccu_to_all_jrus_5.bits.SKA1_TEST_SAND_LEVELS_SENSORS_BOGIE1;
    m_outputs_map.at("SKA1_TEST_SAND_LEVELS_SENSORS_BOGIE2")          = m_ccu_to_all_jrus_5.bits.SKA1_TEST_SAND_LEVELS_SENSORS_BOGIE2;
    m_outputs_map.at("SKA2_TEST_SAND_LEVELS_SENSORS_BOGIE1")          = m_ccu_to_all_jrus_5.bits.SKA2_TEST_SAND_LEVELS_SENSORS_BOGIE1;
    m_outputs_map.at("SKA2_TEST_SAND_LEVELS_SENSORS_BOGIE2")          = m_ccu_to_all_jrus_5.bits.SKA2_TEST_SAND_LEVELS_SENSORS_BOGIE2;
    m_outputs_map.at("C_Sanding_Test")                                = m_ccu_to_all_jrus_5.bits.C_Sanding_Test;

    m_outputs_map.at("bit53")          = m_ccu_to_all_jrus_5.bits.bit53;
    m_outputs_map.at("bit54")          = m_ccu_to_all_jrus_5.bits.bit54;
    m_outputs_map.at("bit55")          = m_ccu_to_all_jrus_5.bits.bit55;

    m_outputs_map.at("reserved_7")          = m_ccu_to_all_jrus_5.bits.reserved_7;;
    m_outputs_map.at("reserved_8")          = m_ccu_to_all_jrus_5.bits.reserved_8;;
    m_outputs_map.at("reserved_9")          = m_ccu_to_all_jrus_5.bits.reserved_9;;
    m_outputs_map.at("reserved_10")          = m_ccu_to_all_jrus_5.bits.reserved_10;
    m_outputs_map.at("reserved_11")          = m_ccu_to_all_jrus_5.bits.reserved_11;
    m_outputs_map.at("reserved_12")          = m_ccu_to_all_jrus_5.bits.reserved_12;
    m_outputs_map.at("reserved_13")          = m_ccu_to_all_jrus_5.bits.reserved_13;
    m_outputs_map.at("reserved_14")          = m_ccu_to_all_jrus_5.bits.reserved_14;
    m_outputs_map.at("reserved_15")          = m_ccu_to_all_jrus_5.bits.reserved_15;
    m_outputs_map.at("reserved_16")          = m_ccu_to_all_jrus_5.bits.reserved_16;
    m_outputs_map.at("reserved_17")          = m_ccu_to_all_jrus_5.bits.reserved_17;
    m_outputs_map.at("reserved_18")          = m_ccu_to_all_jrus_5.bits.reserved_18;
    m_outputs_map.at("reserved_19")          = m_ccu_to_all_jrus_5.bits.reserved_19;
    m_outputs_map.at("reserved_20")          = m_ccu_to_all_jrus_5.bits.reserved_20;
    m_outputs_map.at("reserved_21")          = m_ccu_to_all_jrus_5.bits.reserved_21;
    m_outputs_map.at("reserved_22")          = m_ccu_to_all_jrus_5.bits.reserved_22;

    m_outputs_map.at("reserved_23")          = m_ccu_to_all_jrus_5.bits.reserved_23;
    m_outputs_map.at("reserved_24")          = m_ccu_to_all_jrus_5.bits.reserved_24;
    m_outputs_map.at("reserved_25")          = m_ccu_to_all_jrus_5.bits.reserved_25;
    m_outputs_map.at("reserved_26")          = m_ccu_to_all_jrus_5.bits.reserved_26;
    m_outputs_map.at("reserved_27")          = m_ccu_to_all_jrus_5.bits.reserved_27;
    m_outputs_map.at("reserved_28")          = m_ccu_to_all_jrus_5.bits.reserved_28;
    m_outputs_map.at("reserved_29")          = m_ccu_to_all_jrus_5.bits.reserved_29;
    m_outputs_map.at("reserved_30")          = m_ccu_to_all_jrus_5.bits.reserved_30;
    m_outputs_map.at("reserved_31")          = m_ccu_to_all_jrus_5.bits.reserved_31;



}
