#include "ccu_to_all_jrus_3.h"

Ccu_To_All_Jrus_3::Ccu_To_All_Jrus_3(QObject *parent)
    : QObject{parent}
{
    init_table();
}

Ccu_To_All_Jrus_3::~Ccu_To_All_Jrus_3()
{
    delete m_tableWidget;
}

void Ccu_To_All_Jrus_3::set_data_struct(const QByteArray &output)
{
    if (output.size() == sizeof(m_ccu_to_all_jrus_3.bytes)) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        memcpy(m_ccu_to_all_jrus_3.bytes, output.constData(), sizeof(m_ccu_to_all_jrus_3.bytes));
        update_map();
        update_table();
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }
}

void Ccu_To_All_Jrus_3::init_table()
{
    m_outputs_map = {
        {"Lifesign", 0},
        {"GPSLongtitudeMasterTCMS", 0},
        {"GPSLatitudeMasterTCMS", 0},
        {"ServiceID_Byte0", 0},
        {"ServiceID_Byte1", 0},
        {"ServiceID_Byte2", 0},
        {"ServiceID_Byte3", 0},
        {"ServiceID_Byte4", 0},
        {"ServiceID_Byte5", 0},
        {"ServiceID_Byte6", 0},
        {"ServiceID_Byte7", 0},
        {"SKA1_D_SFD1_FC129", 0},
        {"SKA1_D_SFD2_FC129", 0},
        {"SKA1_D_SFD3_FC129", 0},
        {"SKA1_D_SFD4_FC129", 0},
        {"SKA1_D_SFD5_FC129", 0},
        {"SKA2_D_SFD1_FC129", 0},
        {"SKA2_D_SFD2_FC129", 0},
        {"SKA2_D_SFD3_FC129", 0},
        {"SKA2_D_SFD4_FC129", 0},
        {"SKA2_D_SFD5_FC129", 0},
        {"OA1_D_SFD1_FC129", 0},
        {"OA1_D_SFD2_FC129", 0},
        {"OA1_D_SFD3_FC129", 0},
        {"OA1_D_SFD4_FC129", 0},
        {"OA1_D_SFD5_FC129", 0},
        {"OA2_D_SFD1_FC129", 0},
        {"OA2_D_SFD2_FC129", 0},
        {"OA2_D_SFD3_FC129", 0},
        {"OA2_D_SFD4_FC129", 0},
        {"OA2_D_SFD5_FC129", 0},
        {"SKA1_D_CS_IC22_1_FC129", 0},
        {"SKA1_D_CS_IC22_2_FC129", 0},
        {"SKA1_D_CS_IC22_3_FC129", 0},
        {"SKA2_D_CS_IC22_1_FC129", 0},
        {"SKA2_D_CS_IC22_2_FC129", 0},
        {"SKA2_D_CS_IC22_3_FC129", 0},
        {"OA1_D_CS_IC22_1_FC129", 0},
        {"OA1_D_CS_IC22_2_FC129", 0},
        {"bit172", 0},
        {"bit173", 0},
        {"bit174", 0},
        {"bit175", 0},
        {"S_SKA1_FDCU_General_fire", 0},
        {"S_SKA1_FDCU_Unmuted_fire_alarm", 0},
        {"S_SKA1_FDCU_Fire_fault_reset_feedback_RPDO", 0},
        {"S_SKA1_FDCU_General_fault", 0},
        {"S_SKA1_FDCU_Unmuted_fault_alarm", 0},
        {"S_SKA2_FDCU_General_fire", 0},
        {"S_SKA2_FDCU_Unmuted_fire_alarm", 0},
        {"S_SKA2_FDCU_Fire_fault_reset_feedback_RPDO", 0},
        {"S_SKA2_FDCU_General_fault", 0},
        {"S_SKA2_FDCU_Unmuted_fault_alarm", 0},
        {"bit186", 0},
        {"bit187", 0},
        {"bit188", 0},
        {"bit189", 0},
        {"bit190", 0},
        {"bit191", 0},
        {"SKA1_DCU_DoorR1_EEDOp", 0},
        {"SKA1_DCU_DoorR2_EEDOp", 0},
        {"SKA1_DCU_DoorR3_EEDOp", 0},
        {"SKA1_DCU_DoorR4_EEDOp", 0},
        {"SKA1_DCU_DoorL1_EEDOp", 0},
        {"SKA1_DCU_DoorL2_EEDOp", 0},
        {"SKA1_DCU_DoorL3_EEDOp", 0},
        {"SKA1_DCU_DoorL4_EEDOp", 0},
        {"SKA2_DCU_DoorR1_EEDOp", 0},
        {"SKA2_DCU_DoorR2_EEDOp", 0},
        {"SKA2_DCU_DoorR3_EEDOp", 0},
        {"SKA2_DCU_DoorR4_EEDOp", 0},
        {"SKA2_DCU_DoorL1_EEDOp", 0},
        {"SKA2_DCU_DoorL2_EEDOp", 0},
        {"SKA2_DCU_DoorL3_EEDOp", 0},
        {"SKA2_DCU_DoorL4_EEDOp", 0},
        {"OA1_DCU_DoorR1_EEDOp", 0},
        {"OA1_DCU_DoorR2_EEDOp", 0},
        {"OA1_DCU_DoorR3_EEDOp", 0},
        {"OA1_DCU_DoorR4_EEDOp", 0},
        {"OA1_DCU_DoorL1_EEDOp", 0},
        {"OA1_DCU_DoorL2_EEDOp", 0},
        {"OA1_DCU_DoorL3_EEDOp", 0},
        {"OA1_DCU_DoorL4_EEDOp", 0},
        {"OA2_DCU_DoorR1_EEDOp", 0},
        {"OA2_DCU_DoorR2_EEDOp", 0},
        {"OA2_DCU_DoorR3_EEDOp", 0},
        {"OA2_DCU_DoorR4_EEDOp", 0},
        {"OA2_DCU_DoorL1_EEDOp", 0},
        {"OA2_DCU_DoorL2_EEDOp", 0},
        {"OA2_DCU_DoorL3_EEDOp", 0},
        {"OA2_DCU_DoorL4_EEDOp", 0},
        {"OA1_ETCS_LEFT_DOORS_OPEN_PER", 0},
        {"OA1_ETCS_RIGHT_DOORS_OPEN_PER", 0},
        {"OA2_ETCS_LEFT_DOORS_OPEN_PER", 0},
        {"OA2_ETCS_RIGHT_DOORS_OPEN_PER", 0},
        {"SKA1_ENABLE_DOORS_1357", 0},
        {"SKA1_ENABLE_DOORS_2468", 0},
        {"SKA2_ENABLE_DOORS_1357", 0},
        {"SKA2_ENABLE_DOORS_2468", 0},
        {"Outside_Temperature", 0},
        {"X_LoadWeight", 0}


    };

    QStringList table_name = {"ccu_to_all_jrus_3", "value"};

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

void Ccu_To_All_Jrus_3::update_table()
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

void Ccu_To_All_Jrus_3::update_map()
{

    m_outputs_map.at("Lifesign")                    = m_ccu_to_all_jrus_3.bits.Lifesign;
    m_outputs_map.at("GPSLongtitudeMasterTCMS")     = m_ccu_to_all_jrus_3.bits.GPSLongtitudeMasterTCMS;
    m_outputs_map.at("GPSLatitudeMasterTCMS")       = m_ccu_to_all_jrus_3.bits.GPSLatitudeMasterTCMS;
    m_outputs_map.at("ServiceID_Byte0")             = m_ccu_to_all_jrus_3.bits.ServiceID_Byte0;
    m_outputs_map.at("ServiceID_Byte1")             = m_ccu_to_all_jrus_3.bits.ServiceID_Byte1;
    m_outputs_map.at("ServiceID_Byte2")             = m_ccu_to_all_jrus_3.bits.ServiceID_Byte2;
    m_outputs_map.at("ServiceID_Byte3")             = m_ccu_to_all_jrus_3.bits.ServiceID_Byte3;
    m_outputs_map.at("ServiceID_Byte4")             = m_ccu_to_all_jrus_3.bits.ServiceID_Byte4;
    m_outputs_map.at("ServiceID_Byte5")             = m_ccu_to_all_jrus_3.bits.ServiceID_Byte5;
    m_outputs_map.at("ServiceID_Byte6")             = m_ccu_to_all_jrus_3.bits.ServiceID_Byte6;
    m_outputs_map.at("ServiceID_Byte7")             = m_ccu_to_all_jrus_3.bits.ServiceID_Byte7;
    m_outputs_map.at("SKA1_D_SFD1_FC129")           = m_ccu_to_all_jrus_3.bits.SKA1_D_SFD1_FC129;
    m_outputs_map.at("SKA1_D_SFD2_FC129")           = m_ccu_to_all_jrus_3.bits.SKA1_D_SFD2_FC129;
    m_outputs_map.at("SKA1_D_SFD3_FC129")           = m_ccu_to_all_jrus_3.bits.SKA1_D_SFD3_FC129;
    m_outputs_map.at("SKA1_D_SFD4_FC129")           = m_ccu_to_all_jrus_3.bits.SKA1_D_SFD4_FC129;
    m_outputs_map.at("SKA1_D_SFD5_FC129")           = m_ccu_to_all_jrus_3.bits.SKA1_D_SFD5_FC129;
    m_outputs_map.at("SKA2_D_SFD1_FC129")           = m_ccu_to_all_jrus_3.bits.SKA2_D_SFD1_FC129;
    m_outputs_map.at("SKA2_D_SFD2_FC129")           = m_ccu_to_all_jrus_3.bits.SKA2_D_SFD2_FC129;
    m_outputs_map.at("SKA2_D_SFD3_FC129")           = m_ccu_to_all_jrus_3.bits.SKA2_D_SFD3_FC129;
    m_outputs_map.at("SKA2_D_SFD4_FC129")           = m_ccu_to_all_jrus_3.bits.SKA2_D_SFD4_FC129;
    m_outputs_map.at("SKA2_D_SFD5_FC129")           = m_ccu_to_all_jrus_3.bits.SKA2_D_SFD5_FC129;
    m_outputs_map.at("OA1_D_SFD1_FC129")            = m_ccu_to_all_jrus_3.bits.OA1_D_SFD1_FC129;
    m_outputs_map.at("OA1_D_SFD2_FC129")            = m_ccu_to_all_jrus_3.bits.OA1_D_SFD2_FC129;
    m_outputs_map.at("OA1_D_SFD3_FC129")            = m_ccu_to_all_jrus_3.bits.OA1_D_SFD3_FC129;
    m_outputs_map.at("OA1_D_SFD4_FC129")            = m_ccu_to_all_jrus_3.bits.OA1_D_SFD4_FC129;
    m_outputs_map.at("OA1_D_SFD5_FC129")            = m_ccu_to_all_jrus_3.bits.OA1_D_SFD5_FC129;
    m_outputs_map.at("OA2_D_SFD1_FC129")            = m_ccu_to_all_jrus_3.bits.OA2_D_SFD1_FC129;
    m_outputs_map.at("OA2_D_SFD2_FC129")            = m_ccu_to_all_jrus_3.bits.OA2_D_SFD2_FC129;
    m_outputs_map.at("OA2_D_SFD3_FC129")            = m_ccu_to_all_jrus_3.bits.OA2_D_SFD3_FC129;
    m_outputs_map.at("OA2_D_SFD4_FC129")            = m_ccu_to_all_jrus_3.bits.OA2_D_SFD4_FC129;
    m_outputs_map.at("OA2_D_SFD5_FC129")            = m_ccu_to_all_jrus_3.bits.OA2_D_SFD5_FC129;
    m_outputs_map.at("SKA1_D_CS_IC22_1_FC129")      = m_ccu_to_all_jrus_3.bits.SKA1_D_CS_IC22_1_FC129;
    m_outputs_map.at("SKA1_D_CS_IC22_2_FC129")      = m_ccu_to_all_jrus_3.bits.SKA1_D_CS_IC22_2_FC129;
    m_outputs_map.at("SKA1_D_CS_IC22_3_FC129")      = m_ccu_to_all_jrus_3.bits.SKA1_D_CS_IC22_3_FC129;
    m_outputs_map.at("SKA2_D_CS_IC22_1_FC129")      = m_ccu_to_all_jrus_3.bits.SKA2_D_CS_IC22_1_FC129;
    m_outputs_map.at("SKA2_D_CS_IC22_2_FC129")      = m_ccu_to_all_jrus_3.bits.SKA2_D_CS_IC22_2_FC129;
    m_outputs_map.at("SKA2_D_CS_IC22_3_FC129")      = m_ccu_to_all_jrus_3.bits.SKA2_D_CS_IC22_3_FC129;
    m_outputs_map.at("OA1_D_CS_IC22_1_FC129")       = m_ccu_to_all_jrus_3.bits.OA1_D_CS_IC22_1_FC129;
    m_outputs_map.at("OA1_D_CS_IC22_2_FC129")       = m_ccu_to_all_jrus_3.bits.OA1_D_CS_IC22_2_FC129;
    m_outputs_map.at("bit172")                      = m_ccu_to_all_jrus_3.bits.bit172;
    m_outputs_map.at("bit173")                                         = m_ccu_to_all_jrus_3.bits.bit173;
    m_outputs_map.at("bit174")                                         = m_ccu_to_all_jrus_3.bits.bit174;
    m_outputs_map.at("bit175")                                         = m_ccu_to_all_jrus_3.bits.bit175;
    m_outputs_map.at("S_SKA1_FDCU_General_fire")                       = m_ccu_to_all_jrus_3.bits.S_SKA1_FDCU_General_fire;
    m_outputs_map.at("S_SKA1_FDCU_Unmuted_fire_alarm")                 = m_ccu_to_all_jrus_3.bits.S_SKA1_FDCU_Unmuted_fire_alarm;
    m_outputs_map.at("S_SKA1_FDCU_Fire_fault_reset_feedback_RPDO")     = m_ccu_to_all_jrus_3.bits.S_SKA1_FDCU_Fire_fault_reset_feedback_RPDO;
    m_outputs_map.at("S_SKA1_FDCU_General_fault")                      = m_ccu_to_all_jrus_3.bits.S_SKA1_FDCU_General_fault;
    m_outputs_map.at("S_SKA1_FDCU_Unmuted_fault_alarm")                = m_ccu_to_all_jrus_3.bits.S_SKA1_FDCU_Unmuted_fault_alarm;
    m_outputs_map.at("S_SKA2_FDCU_General_fire")                       = m_ccu_to_all_jrus_3.bits.S_SKA2_FDCU_General_fire;
    m_outputs_map.at("S_SKA2_FDCU_Unmuted_fire_alarm")                 = m_ccu_to_all_jrus_3.bits.S_SKA2_FDCU_Unmuted_fire_alarm;
    m_outputs_map.at("S_SKA2_FDCU_Fire_fault_reset_feedback_RPDO")     = m_ccu_to_all_jrus_3.bits.S_SKA2_FDCU_Fire_fault_reset_feedback_RPDO;
    m_outputs_map.at("S_SKA2_FDCU_General_fault")                      = m_ccu_to_all_jrus_3.bits.S_SKA2_FDCU_General_fault;
    m_outputs_map.at("S_SKA2_FDCU_Unmuted_fault_alarm")                = m_ccu_to_all_jrus_3.bits.S_SKA2_FDCU_Unmuted_fault_alarm;
    m_outputs_map.at("bit186")                                         = m_ccu_to_all_jrus_3.bits.bit186;
    m_outputs_map.at("bit187")                                         = m_ccu_to_all_jrus_3.bits.bit187;
    m_outputs_map.at("bit188")                                         = m_ccu_to_all_jrus_3.bits.bit188;
    m_outputs_map.at("bit189")                                         = m_ccu_to_all_jrus_3.bits.bit189;
    m_outputs_map.at("bit190")                                         = m_ccu_to_all_jrus_3.bits.bit190;
    m_outputs_map.at("bit191")                                         = m_ccu_to_all_jrus_3.bits.bit191;
    m_outputs_map.at("SKA1_DCU_DoorR1_EEDOp")        = m_ccu_to_all_jrus_3.bits.SKA1_DCU_DoorR1_EEDOp;
    m_outputs_map.at("SKA1_DCU_DoorR2_EEDOp")        = m_ccu_to_all_jrus_3.bits.SKA1_DCU_DoorR2_EEDOp;
    m_outputs_map.at("SKA1_DCU_DoorR3_EEDOp")        = m_ccu_to_all_jrus_3.bits.SKA1_DCU_DoorR3_EEDOp;
    m_outputs_map.at("SKA1_DCU_DoorR4_EEDOp")        = m_ccu_to_all_jrus_3.bits.SKA1_DCU_DoorR4_EEDOp;
    m_outputs_map.at("SKA1_DCU_DoorL1_EEDOp")        = m_ccu_to_all_jrus_3.bits.SKA1_DCU_DoorL1_EEDOp;
    m_outputs_map.at("SKA1_DCU_DoorL2_EEDOp")        = m_ccu_to_all_jrus_3.bits.SKA1_DCU_DoorL2_EEDOp;
    m_outputs_map.at("SKA1_DCU_DoorL3_EEDOp")        = m_ccu_to_all_jrus_3.bits.SKA1_DCU_DoorL3_EEDOp;
    m_outputs_map.at("SKA1_DCU_DoorL4_EEDOp")        = m_ccu_to_all_jrus_3.bits.SKA1_DCU_DoorL4_EEDOp;
    m_outputs_map.at("SKA2_DCU_DoorR1_EEDOp")        = m_ccu_to_all_jrus_3.bits.SKA2_DCU_DoorR1_EEDOp;
    m_outputs_map.at("SKA2_DCU_DoorR2_EEDOp")        = m_ccu_to_all_jrus_3.bits.SKA2_DCU_DoorR2_EEDOp;
    m_outputs_map.at("SKA2_DCU_DoorR3_EEDOp")        = m_ccu_to_all_jrus_3.bits.SKA2_DCU_DoorR3_EEDOp;
    m_outputs_map.at("SKA2_DCU_DoorR4_EEDOp")        = m_ccu_to_all_jrus_3.bits.SKA2_DCU_DoorR4_EEDOp;
    m_outputs_map.at("SKA2_DCU_DoorL1_EEDOp")        = m_ccu_to_all_jrus_3.bits.SKA2_DCU_DoorL1_EEDOp;
    m_outputs_map.at("SKA2_DCU_DoorL2_EEDOp")        = m_ccu_to_all_jrus_3.bits.SKA2_DCU_DoorL2_EEDOp;
    m_outputs_map.at("SKA2_DCU_DoorL3_EEDOp")        = m_ccu_to_all_jrus_3.bits.SKA2_DCU_DoorL3_EEDOp;
    m_outputs_map.at("SKA2_DCU_DoorL4_EEDOp")        = m_ccu_to_all_jrus_3.bits.SKA2_DCU_DoorL4_EEDOp;
    m_outputs_map.at("OA1_DCU_DoorR1_EEDOp")         = m_ccu_to_all_jrus_3.bits.OA1_DCU_DoorR1_EEDOp;
    m_outputs_map.at("OA1_DCU_DoorR2_EEDOp")         = m_ccu_to_all_jrus_3.bits.OA1_DCU_DoorR2_EEDOp;
    m_outputs_map.at("OA1_DCU_DoorR3_EEDOp")         = m_ccu_to_all_jrus_3.bits.OA1_DCU_DoorR3_EEDOp;
    m_outputs_map.at("OA1_DCU_DoorR4_EEDOp")         = m_ccu_to_all_jrus_3.bits.OA1_DCU_DoorR4_EEDOp;
    m_outputs_map.at("OA1_DCU_DoorL1_EEDOp")         = m_ccu_to_all_jrus_3.bits.OA1_DCU_DoorL1_EEDOp;
    m_outputs_map.at("OA1_DCU_DoorL2_EEDOp")         = m_ccu_to_all_jrus_3.bits.OA1_DCU_DoorL2_EEDOp;
    m_outputs_map.at("OA1_DCU_DoorL3_EEDOp")         = m_ccu_to_all_jrus_3.bits.OA1_DCU_DoorL3_EEDOp;
    m_outputs_map.at("OA1_DCU_DoorL4_EEDOp")         = m_ccu_to_all_jrus_3.bits.OA1_DCU_DoorL4_EEDOp;
    m_outputs_map.at("OA2_DCU_DoorR1_EEDOp")         = m_ccu_to_all_jrus_3.bits.OA2_DCU_DoorR1_EEDOp;
    m_outputs_map.at("OA2_DCU_DoorR2_EEDOp")         = m_ccu_to_all_jrus_3.bits.OA2_DCU_DoorR2_EEDOp;
    m_outputs_map.at("OA2_DCU_DoorR3_EEDOp")         = m_ccu_to_all_jrus_3.bits.OA2_DCU_DoorR3_EEDOp;
    m_outputs_map.at("OA2_DCU_DoorR4_EEDOp")         = m_ccu_to_all_jrus_3.bits.OA2_DCU_DoorR4_EEDOp;
    m_outputs_map.at("OA2_DCU_DoorL1_EEDOp")         = m_ccu_to_all_jrus_3.bits.OA2_DCU_DoorL1_EEDOp;
    m_outputs_map.at("OA2_DCU_DoorL2_EEDOp")         = m_ccu_to_all_jrus_3.bits.OA2_DCU_DoorL2_EEDOp;
    m_outputs_map.at("OA2_DCU_DoorL3_EEDOp")         = m_ccu_to_all_jrus_3.bits.OA2_DCU_DoorL3_EEDOp;
    m_outputs_map.at("OA2_DCU_DoorL4_EEDOp")         = m_ccu_to_all_jrus_3.bits.OA2_DCU_DoorL4_EEDOp;
    m_outputs_map.at("OA1_ETCS_LEFT_DOORS_OPEN_PER")           = m_ccu_to_all_jrus_3.bits.OA1_ETCS_LEFT_DOORS_OPEN_PER;
    m_outputs_map.at("OA1_ETCS_RIGHT_DOORS_OPEN_PER")          = m_ccu_to_all_jrus_3.bits.OA1_ETCS_RIGHT_DOORS_OPEN_PER;
    m_outputs_map.at("OA2_ETCS_LEFT_DOORS_OPEN_PER")           = m_ccu_to_all_jrus_3.bits.OA2_ETCS_LEFT_DOORS_OPEN_PER;
    m_outputs_map.at("OA2_ETCS_RIGHT_DOORS_OPEN_PER")          = m_ccu_to_all_jrus_3.bits.OA2_ETCS_RIGHT_DOORS_OPEN_PER;
    m_outputs_map.at("SKA1_ENABLE_DOORS_1357")          = m_ccu_to_all_jrus_3.bits.SKA1_ENABLE_DOORS_1357;
    m_outputs_map.at("SKA1_ENABLE_DOORS_2468")          = m_ccu_to_all_jrus_3.bits.SKA1_ENABLE_DOORS_2468;
    m_outputs_map.at("SKA2_ENABLE_DOORS_1357")          = m_ccu_to_all_jrus_3.bits.SKA2_ENABLE_DOORS_1357;
    m_outputs_map.at("SKA2_ENABLE_DOORS_2468")          = m_ccu_to_all_jrus_3.bits.SKA2_ENABLE_DOORS_2468;
    m_outputs_map.at("Outside_Temperature")             = m_ccu_to_all_jrus_3.bits.Outside_Temperature;
    m_outputs_map.at("X_LoadWeight")                    = m_ccu_to_all_jrus_3.bits.X_LoadWeight;

}
