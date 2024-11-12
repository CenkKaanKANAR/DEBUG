#include "ccu_to_all_jrus_2.h"

Ccu_To_All_Jrus_2::Ccu_To_All_Jrus_2(QObject *parent)
    : QObject{parent}
{
    init_table();
}

Ccu_To_All_Jrus_2::~Ccu_To_All_Jrus_2()
{
    delete m_tableWidget;
}

void Ccu_To_All_Jrus_2::set_data_struct(const QByteArray &output)
{
    if (output.size() == sizeof(m_ccu_to_all_jrus_2.bytes)) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        memcpy(m_ccu_to_all_jrus_2.bytes, output.constData(), sizeof(m_ccu_to_all_jrus_2.bytes));
        update_map();
        update_table();
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }
}

void Ccu_To_All_Jrus_2::init_table()
{
    m_outputs_map = {
        {"Lifesign", 0},
        {"SKA1_Inside_temperature", 0},
        {"SKA2_Inside_temperature", 0},
        {"OA1_Inside_temperature", 0},
        {"OA2_Inside_temperature", 0},
        {"SKA1_FAST_OPEN_ADD", 0},
        {"SKA2_FAST_OPEN_ADD", 0},
        {"OA1_FAST_OPEN_ADD", 0},
        {"OA2_FAST_OPEN_ADD", 0},
        {"SKA1_TRACTION_CUT_OFF_LOOP", 0},
        {"SKA2_TRACTION_CUT_OFF_LOOP", 0},
        {"OA1_BATTERY_CHARGER_OK", 0},
        {"OA2_BATTERY_CHARGER_OK", 0},
        {"SKA1_DOOR_1_FULLY_OPENED", 0},
        {"SKA1_DOOR_2_FULLY_OPENED", 0},
        {"SKA1_DOOR_3_FULLY_OPENED", 0},
        {"SKA1_DOOR_4_FULLY_OPENED", 0},
        {"SKA1_DOOR_5_FULLY_OPENED", 0},
        {"SKA1_DOOR_6_FULLY_OPENED", 0},
        {"SKA1_DOOR_7_FULLY_OPENED", 0},
        {"SKA1_DOOR_8_FULLY_OPENED", 0},
        {"SKA2_DOOR_1_FULLY_OPENED", 0},
        {"SKA2_DOOR_2_FULLY_OPENED", 0},
        {"SKA2_DOOR_3_FULLY_OPENED", 0},
        {"SKA2_DOOR_4_FULLY_OPENED", 0},
        {"SKA2_DOOR_5_FULLY_OPENED", 0},
        {"SKA2_DOOR_6_FULLY_OPENED", 0},
        {"SKA2_DOOR_7_FULLY_OPENED", 0},
        {"SKA2_DOOR_8_FULLY_OPENED", 0},
        {"OA1_DOOR_1_FULLY_OPENED", 0},
        {"OA1_DOOR_2_FULLY_OPENED", 0},
        {"OA1_DOOR_3_FULLY_OPENED", 0},
        {"OA1_DOOR_4_FULLY_OPENED", 0},
        {"OA1_DOOR_5_FULLY_OPENED", 0},
        {"OA1_DOOR_6_FULLY_OPENED", 0},
        {"OA1_DOOR_7_FULLY_OPENED", 0},
        {"OA1_DOOR_8_FULLY_OPENED", 0},
        {"OA2_DOOR_1_FULLY_OPENED", 0},
        {"OA2_DOOR_2_FULLY_OPENED", 0},
        {"OA2_DOOR_3_FULLY_OPENED", 0},
        {"OA2_DOOR_4_FULLY_OPENED", 0},
        {"OA2_DOOR_5_FULLY_OPENED", 0},
        {"OA2_DOOR_6_FULLY_OPENED", 0},
        {"OA2_DOOR_7_FULLY_OPENED", 0},
        {"OA2_DOOR_8_FULLY_OPENED", 0},
        {"SKA1_DCU_DoorR1_DoorClosedAndLocked", 0},
        {"SKA1_DCU_DoorR2_DoorClosedAndLocked", 0},
        {"SKA1_DCU_DoorR3_DoorClosedAndLocked", 0},
        {"SKA1_DCU_DoorR4_DoorClosedAndLocked", 0},
        {"SKA1_DCU_DoorL1_DoorClosedAndLocked", 0},
        {"SKA1_DCU_DoorL2_DoorClosedAndLocked", 0},
        {"SKA1_DCU_DoorL3_DoorClosedAndLocked", 0},
        {"SKA1_DCU_DoorL4_DoorClosedAndLocked", 0},
        {"SKA2_DCU_DoorR1_DoorClosedAndLocked", 0},
        {"SKA2_DCU_DoorR2_DoorClosedAndLocked", 0},
        {"SKA2_DCU_DoorR3_DoorClosedAndLocked", 0},
        {"SKA2_DCU_DoorR4_DoorClosedAndLocked", 0},
        {"SKA2_DCU_DoorL1_DoorClosedAndLocked", 0},
        {"SKA2_DCU_DoorL2_DoorClosedAndLocked", 0},
        {"SKA2_DCU_DoorL3_DoorClosedAndLocked", 0},
        {"SKA2_DCU_DoorL4_DoorClosedAndLocked", 0},
        {"OA1_DCU_DoorR1_DoorClosedAndLocked", 0},
        {"OA1_DCU_DoorR2_DoorClosedAndLocked", 0},
        {"OA1_DCU_DoorR3_DoorClosedAndLocked", 0},
        {"OA1_DCU_DoorR4_DoorClosedAndLocked", 0},
        {"OA1_DCU_DoorL1_DoorClosedAndLocked", 0},
        {"OA1_DCU_DoorL2_DoorClosedAndLocked", 0},
        {"OA1_DCU_DoorL3_DoorClosedAndLocked", 0},
        {"OA1_DCU_DoorL4_DoorClosedAndLocked", 0},
        {"OA2_DCU_DoorR1_DoorClosedAndLocked", 0},
        {"OA2_DCU_DoorR2_DoorClosedAndLocked", 0},
        {"OA2_DCU_DoorR3_DoorClosedAndLocked", 0},
        {"OA2_DCU_DoorR4_DoorClosedAndLocked", 0},
        {"OA2_DCU_DoorL1_DoorClosedAndLocked", 0},
        {"OA2_DCU_DoorL2_DoorClosedAndLocked", 0},
        {"OA2_DCU_DoorL3_DoorClosedAndLocked", 0},
        {"OA2_DCU_DoorL4_DoorClosedAndLocked", 0},
        {"SKA1_DCU_DoorR1_TCMS_TLRelease", 0},
        {"SKA1_DCU_DoorR2_TCMS_TLRelease", 0},
        {"SKA1_DCU_DoorR3_TCMS_TLRelease", 0},
        {"SKA1_DCU_DoorR4_TCMS_TLRelease", 0},
        {"SKA1_DCU_DoorL1_TCMS_TLRelease", 0},
        {"SKA1_DCU_DoorL2_TCMS_TLRelease", 0},
        {"SKA1_DCU_DoorL3_TCMS_TLRelease", 0},
        {"SKA1_DCU_DoorL4_TCMS_TLRelease", 0},
        {"SKA2_DCU_DoorR1_TCMS_TLRelease", 0},
        {"SKA2_DCU_DoorR2_TCMS_TLRelease", 0},
        {"SKA2_DCU_DoorR3_TCMS_TLRelease", 0},
        {"SKA2_DCU_DoorR4_TCMS_TLRelease", 0},
        {"SKA2_DCU_DoorL1_TCMS_TLRelease", 0},
        {"SKA2_DCU_DoorL2_TCMS_TLRelease", 0},
        {"SKA2_DCU_DoorL3_TCMS_TLRelease", 0},
        {"SKA2_DCU_DoorL4_TCMS_TLRelease", 0},
        {"OA1_DCU_DoorR1_TCMS_TLRelease", 0},
        {"OA1_DCU_DoorR2_TCMS_TLRelease", 0},
        {"OA1_DCU_DoorR3_TCMS_TLRelease", 0},
        {"OA1_DCU_DoorR4_TCMS_TLRelease", 0},
        {"OA1_DCU_DoorL1_TCMS_TLRelease", 0},
        {"OA1_DCU_DoorL2_TCMS_TLRelease", 0},
        {"OA1_DCU_DoorL3_TCMS_TLRelease", 0},
        {"OA1_DCU_DoorL4_TCMS_TLRelease", 0},
        {"OA2_DCU_DoorR1_TCMS_TLRelease", 0},
        {"OA2_DCU_DoorR2_TCMS_TLRelease", 0},
        {"OA2_DCU_DoorR3_TCMS_TLRelease", 0},
        {"OA2_DCU_DoorR4_TCMS_TLRelease", 0},
        {"OA2_DCU_DoorL1_TCMS_TLRelease", 0},
        {"OA2_DCU_DoorL2_TCMS_TLRelease", 0},
        {"OA2_DCU_DoorL3_TCMS_TLRelease", 0},
        {"OA2_DCU_DoorL4_TCMS_TLRelease", 0},
        {"SKA1_DCU_DoorR1_TCMS_OutofService ", 0},
        {"SKA1_DCU_DoorR2_TCMS_OutofService ", 0},
        {"SKA1_DCU_DoorR3_TCMS_OutofService ", 0},
        {"SKA1_DCU_DoorR4_TCMS_OutofService ", 0},
        {"SKA1_DCU_DoorL1_TCMS_OutofService ", 0},
        {"SKA1_DCU_DoorL2_TCMS_OutofService ", 0},
        {"SKA1_DCU_DoorL3_TCMS_OutofService ", 0},
        {"SKA1_DCU_DoorL4_TCMS_OutofService ", 0},
        {"SKA2_DCU_DoorR1_TCMS_OutofService ", 0},
        {"SKA2_DCU_DoorR2_TCMS_OutofService ", 0},
        {"SKA2_DCU_DoorR3_TCMS_OutofService ", 0},
        {"SKA2_DCU_DoorR4_TCMS_OutofService ", 0},
        {"SKA2_DCU_DoorL1_TCMS_OutofService ", 0},
        {"SKA2_DCU_DoorL2_TCMS_OutofService ", 0},
        {"SKA2_DCU_DoorL3_TCMS_OutofService ", 0},
        {"SKA2_DCU_DoorL4_TCMS_OutofService ", 0},
        {"OA1_DCU_DoorR1_TCMS_OutofService", 0},
        {"OA1_DCU_DoorR2_TCMS_OutofService", 0},
        {"OA1_DCU_DoorR3_TCMS_OutofService", 0},
        {"OA1_DCU_DoorR4_TCMS_OutofService", 0},
        {"OA1_DCU_DoorL1_TCMS_OutofService", 0},
        {"OA1_DCU_DoorL2_TCMS_OutofService", 0},
        {"OA1_DCU_DoorL3_TCMS_OutofService", 0},
        {"OA1_DCU_DoorL4_TCMS_OutofService", 0},
        {"OA2_DCU_DoorR1_TCMS_OutofService", 0},
        {"OA2_DCU_DoorR2_TCMS_OutofService", 0},
        {"OA2_DCU_DoorR3_TCMS_OutofService", 0},
        {"OA2_DCU_DoorR4_TCMS_OutofService", 0},
        {"OA2_DCU_DoorL1_TCMS_OutofService", 0},
        {"OA2_DCU_DoorL2_TCMS_OutofService", 0},
        {"OA2_DCU_DoorL3_TCMS_OutofService", 0},
        {"OA2_DCU_DoorL4_TCMS_OutofService", 0},
        {"SKA1_DCU_DoorR1_DoorObstDet", 0},
        {"SKA1_DCU_DoorR2_DoorObstDet", 0},
        {"SKA1_DCU_DoorR3_DoorObstDet", 0},
        {"SKA1_DCU_DoorR4_DoorObstDet", 0},
        {"SKA1_DCU_DoorL1_DoorObstDet", 0},
        {"SKA1_DCU_DoorL2_DoorObstDet", 0},
        {"SKA1_DCU_DoorL3_DoorObstDet", 0},
        {"SKA1_DCU_DoorL4_DoorObstDet", 0},
        {"SKA2_DCU_DoorR1_DoorObstDet", 0},
        {"SKA2_DCU_DoorR2_DoorObstDet", 0},
        {"SKA2_DCU_DoorR3_DoorObstDet", 0},
        {"SKA2_DCU_DoorR4_DoorObstDet", 0},
        {"SKA2_DCU_DoorL1_DoorObstDet", 0},
        {"SKA2_DCU_DoorL2_DoorObstDet", 0},
        {"SKA2_DCU_DoorL3_DoorObstDet", 0},
        {"SKA2_DCU_DoorL4_DoorObstDet", 0},
        {"OA1_DCU_DoorR1_DoorObstDet", 0},
        {"OA1_DCU_DoorR2_DoorObstDet", 0},
        {"OA1_DCU_DoorR3_DoorObstDet", 0},
        {"OA1_DCU_DoorR4_DoorObstDet", 0},
        {"OA1_DCU_DoorL1_DoorObstDet", 0},
        {"OA1_DCU_DoorL2_DoorObstDet", 0},
        {"OA1_DCU_DoorL3_DoorObstDet", 0},
        {"OA1_DCU_DoorL4_DoorObstDet", 0},
        {"OA2_DCU_DoorR1_DoorObstDet", 0},
        {"OA2_DCU_DoorR2_DoorObstDet", 0},
        {"OA2_DCU_DoorR3_DoorObstDet", 0},
        {"OA2_DCU_DoorR4_DoorObstDet", 0},
        {"OA2_DCU_DoorL1_DoorObstDet", 0},
        {"OA2_DCU_DoorL2_DoorObstDet", 0},
        {"OA2_DCU_DoorL3_DoorObstDet", 0},
        {"OA2_DCU_DoorL4_DoorObstDet", 0},
        {"SKA1_DCU_DoorR1_DoorAntiDrag", 0},
        {"SKA1_DCU_DoorR2_DoorAntiDrag", 0},
        {"SKA1_DCU_DoorR3_DoorAntiDrag", 0},
        {"SKA1_DCU_DoorR4_DoorAntiDrag", 0},
        {"SKA1_DCU_DoorL1_DoorAntiDrag", 0},
        {"SKA1_DCU_DoorL2_DoorAntiDrag", 0},
        {"SKA1_DCU_DoorL3_DoorAntiDrag", 0},
        {"SKA1_DCU_DoorL4_DoorAntiDrag", 0},
        {"SKA2_DCU_DoorR1_DoorAntiDrag", 0},
        {"SKA2_DCU_DoorR2_DoorAntiDrag", 0},
        {"SKA2_DCU_DoorR3_DoorAntiDrag", 0},
        {"SKA2_DCU_DoorR4_DoorAntiDrag", 0},
        {"SKA2_DCU_DoorL1_DoorAntiDrag", 0},
        {"SKA2_DCU_DoorL2_DoorAntiDrag", 0},
        {"SKA2_DCU_DoorL3_DoorAntiDrag", 0},
        {"SKA2_DCU_DoorL4_DoorAntiDrag", 0},
        {"OA1_DCU_DoorR1_DoorAntiDrag", 0},
        {"OA1_DCU_DoorR2_DoorAntiDrag", 0},
        {"OA1_DCU_DoorR3_DoorAntiDrag", 0},
        {"OA1_DCU_DoorR4_DoorAntiDrag", 0},
        {"OA1_DCU_DoorL1_DoorAntiDrag", 0},
        {"OA1_DCU_DoorL2_DoorAntiDrag", 0},
        {"OA1_DCU_DoorL3_DoorAntiDrag", 0},
        {"OA1_DCU_DoorL4_DoorAntiDrag", 0},
        {"OA2_DCU_DoorR1_DoorAntiDrag", 0},
        {"OA2_DCU_DoorR2_DoorAntiDrag", 0},
        {"OA2_DCU_DoorR3_DoorAntiDrag", 0},
        {"OA2_DCU_DoorR4_DoorAntiDrag", 0},
        {"OA2_DCU_DoorL1_DoorAntiDrag", 0},
        {"OA2_DCU_DoorL2_DoorAntiDrag", 0},
        {"OA2_DCU_DoorL3_DoorAntiDrag", 0},
        {"OA2_DCU_DoorL4_DoorAntiDrag", 0},
        {"bit248", 0},
        {"bit249", 0},
        {"bit250", 0},
        {"bit251", 0},
        {"bit252", 0},
        {"bit253", 0},
        {"bit254", 0},
        {"bit255", 0}
    };

    QStringList table_name = {"ccu_to_all_jrus_2", "value"};

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

void Ccu_To_All_Jrus_2::update_table()
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

void Ccu_To_All_Jrus_2::update_map()
{

    m_outputs_map.at("Lifesign")                    = m_ccu_to_all_jrus_2.bits.Lifesign;
    m_outputs_map.at("SKA1_Inside_temperature")     = m_ccu_to_all_jrus_2.bits.SKA1_Inside_temperature;
    m_outputs_map.at("SKA2_Inside_temperature")     = m_ccu_to_all_jrus_2.bits.SKA2_Inside_temperature;
    m_outputs_map.at("OA1_Inside_temperature")      = m_ccu_to_all_jrus_2.bits.OA1_Inside_temperature;
    m_outputs_map.at("OA2_Inside_temperature")      = m_ccu_to_all_jrus_2.bits.OA2_Inside_temperature;
    m_outputs_map.at("SKA1_FAST_OPEN_ADD")          = m_ccu_to_all_jrus_2.bits.SKA1_FAST_OPEN_ADD;
    m_outputs_map.at("SKA2_FAST_OPEN_ADD")          = m_ccu_to_all_jrus_2.bits.SKA2_FAST_OPEN_ADD;
    m_outputs_map.at("OA1_FAST_OPEN_ADD")           = m_ccu_to_all_jrus_2.bits.OA1_FAST_OPEN_ADD;
    m_outputs_map.at("OA2_FAST_OPEN_ADD")           = m_ccu_to_all_jrus_2.bits.OA2_FAST_OPEN_ADD;
    m_outputs_map.at("SKA1_TRACTION_CUT_OFF_LOOP")  = m_ccu_to_all_jrus_2.bits.SKA1_TRACTION_CUT_OFF_LOOP;
    m_outputs_map.at("SKA2_TRACTION_CUT_OFF_LOOP")  = m_ccu_to_all_jrus_2.bits.SKA2_TRACTION_CUT_OFF_LOOP;
    m_outputs_map.at("OA1_BATTERY_CHARGER_OK")      = m_ccu_to_all_jrus_2.bits.OA1_BATTERY_CHARGER_OK;
    m_outputs_map.at("OA2_BATTERY_CHARGER_OK")      = m_ccu_to_all_jrus_2.bits.OA2_BATTERY_CHARGER_OK;
    m_outputs_map.at("SKA1_DOOR_1_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.SKA1_DOOR_1_FULLY_OPENED;
    m_outputs_map.at("SKA1_DOOR_2_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.SKA1_DOOR_2_FULLY_OPENED;
    m_outputs_map.at("SKA1_DOOR_3_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.SKA1_DOOR_3_FULLY_OPENED;
    m_outputs_map.at("SKA1_DOOR_4_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.SKA1_DOOR_4_FULLY_OPENED;
    m_outputs_map.at("SKA1_DOOR_5_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.SKA1_DOOR_5_FULLY_OPENED;
    m_outputs_map.at("SKA1_DOOR_6_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.SKA1_DOOR_6_FULLY_OPENED;
    m_outputs_map.at("SKA1_DOOR_7_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.SKA1_DOOR_7_FULLY_OPENED;
    m_outputs_map.at("SKA1_DOOR_8_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.SKA1_DOOR_8_FULLY_OPENED;
    m_outputs_map.at("SKA2_DOOR_1_FULLY_OPENED")   = m_ccu_to_all_jrus_2.bits.SKA2_DOOR_1_FULLY_OPENED;
    m_outputs_map.at("SKA2_DOOR_2_FULLY_OPENED")   = m_ccu_to_all_jrus_2.bits.SKA2_DOOR_2_FULLY_OPENED;
    m_outputs_map.at("SKA2_DOOR_3_FULLY_OPENED")   = m_ccu_to_all_jrus_2.bits.SKA2_DOOR_3_FULLY_OPENED;
    m_outputs_map.at("SKA2_DOOR_4_FULLY_OPENED")   = m_ccu_to_all_jrus_2.bits.SKA2_DOOR_4_FULLY_OPENED;
    m_outputs_map.at("SKA2_DOOR_5_FULLY_OPENED")   = m_ccu_to_all_jrus_2.bits.SKA2_DOOR_5_FULLY_OPENED;
    m_outputs_map.at("SKA2_DOOR_6_FULLY_OPENED")   = m_ccu_to_all_jrus_2.bits.SKA2_DOOR_6_FULLY_OPENED;
    m_outputs_map.at("SKA2_DOOR_7_FULLY_OPENED")   = m_ccu_to_all_jrus_2.bits.SKA2_DOOR_7_FULLY_OPENED;
    m_outputs_map.at("SKA2_DOOR_8_FULLY_OPENED")   = m_ccu_to_all_jrus_2.bits.SKA2_DOOR_8_FULLY_OPENED;
    m_outputs_map.at("OA1_DOOR_1_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.OA1_DOOR_1_FULLY_OPENED;
    m_outputs_map.at("OA1_DOOR_2_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.OA1_DOOR_2_FULLY_OPENED;
    m_outputs_map.at("OA1_DOOR_3_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.OA1_DOOR_3_FULLY_OPENED;
    m_outputs_map.at("OA1_DOOR_4_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.OA1_DOOR_4_FULLY_OPENED;
    m_outputs_map.at("OA1_DOOR_5_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.OA1_DOOR_5_FULLY_OPENED;
    m_outputs_map.at("OA1_DOOR_6_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.OA1_DOOR_6_FULLY_OPENED;
    m_outputs_map.at("OA1_DOOR_7_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.OA1_DOOR_7_FULLY_OPENED;
    m_outputs_map.at("OA1_DOOR_8_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.OA1_DOOR_8_FULLY_OPENED;
    m_outputs_map.at("OA2_DOOR_1_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.OA2_DOOR_1_FULLY_OPENED;
    m_outputs_map.at("OA2_DOOR_2_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.OA2_DOOR_2_FULLY_OPENED;
    m_outputs_map.at("OA2_DOOR_3_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.OA2_DOOR_3_FULLY_OPENED;
    m_outputs_map.at("OA2_DOOR_4_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.OA2_DOOR_4_FULLY_OPENED;
    m_outputs_map.at("OA2_DOOR_5_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.OA2_DOOR_5_FULLY_OPENED;
    m_outputs_map.at("OA2_DOOR_6_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.OA2_DOOR_6_FULLY_OPENED;
    m_outputs_map.at("OA2_DOOR_7_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.OA2_DOOR_7_FULLY_OPENED;
    m_outputs_map.at("OA2_DOOR_8_FULLY_OPENED")    = m_ccu_to_all_jrus_2.bits.OA2_DOOR_8_FULLY_OPENED;
    m_outputs_map.at("SKA1_DCU_DoorR1_DoorClosedAndLocked")    = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorR1_DoorClosedAndLocked;
    m_outputs_map.at("SKA1_DCU_DoorR2_DoorClosedAndLocked")    = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorR2_DoorClosedAndLocked;
    m_outputs_map.at("SKA1_DCU_DoorR3_DoorClosedAndLocked")    = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorR3_DoorClosedAndLocked;
    m_outputs_map.at("SKA1_DCU_DoorR4_DoorClosedAndLocked")    = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorR4_DoorClosedAndLocked;
    m_outputs_map.at("SKA1_DCU_DoorL1_DoorClosedAndLocked")    = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorL1_DoorClosedAndLocked;
    m_outputs_map.at("SKA1_DCU_DoorL2_DoorClosedAndLocked")    = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorL2_DoorClosedAndLocked;
    m_outputs_map.at("SKA1_DCU_DoorL3_DoorClosedAndLocked")    = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorL3_DoorClosedAndLocked;
    m_outputs_map.at("SKA1_DCU_DoorL4_DoorClosedAndLocked")    = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorL4_DoorClosedAndLocked;
    m_outputs_map.at("SKA2_DCU_DoorR1_DoorClosedAndLocked")    = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorR1_DoorClosedAndLocked;
    m_outputs_map.at("SKA2_DCU_DoorR2_DoorClosedAndLocked")    = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorR2_DoorClosedAndLocked;
    m_outputs_map.at("SKA2_DCU_DoorR3_DoorClosedAndLocked")    = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorR3_DoorClosedAndLocked;
    m_outputs_map.at("SKA2_DCU_DoorR4_DoorClosedAndLocked")    = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorR4_DoorClosedAndLocked;
    m_outputs_map.at("SKA2_DCU_DoorL1_DoorClosedAndLocked")    = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorL1_DoorClosedAndLocked;
    m_outputs_map.at("SKA2_DCU_DoorL2_DoorClosedAndLocked")    = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorL2_DoorClosedAndLocked;
    m_outputs_map.at("SKA2_DCU_DoorL3_DoorClosedAndLocked")    = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorL3_DoorClosedAndLocked;
    m_outputs_map.at("SKA2_DCU_DoorL4_DoorClosedAndLocked")    = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorL4_DoorClosedAndLocked;
    m_outputs_map.at("OA1_DCU_DoorR1_DoorClosedAndLocked")     = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorR1_DoorClosedAndLocked;
    m_outputs_map.at("OA1_DCU_DoorR2_DoorClosedAndLocked")     = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorR2_DoorClosedAndLocked;
    m_outputs_map.at("OA1_DCU_DoorR3_DoorClosedAndLocked")     = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorR3_DoorClosedAndLocked;
    m_outputs_map.at("OA1_DCU_DoorR4_DoorClosedAndLocked")     = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorR4_DoorClosedAndLocked;
    m_outputs_map.at("OA1_DCU_DoorL1_DoorClosedAndLocked")     = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorL1_DoorClosedAndLocked;
    m_outputs_map.at("OA1_DCU_DoorL2_DoorClosedAndLocked")     = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorL2_DoorClosedAndLocked;
    m_outputs_map.at("OA1_DCU_DoorL3_DoorClosedAndLocked")     = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorL3_DoorClosedAndLocked;
    m_outputs_map.at("OA1_DCU_DoorL4_DoorClosedAndLocked")     = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorL4_DoorClosedAndLocked;
    m_outputs_map.at("OA2_DCU_DoorR1_DoorClosedAndLocked")     = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorR1_DoorClosedAndLocked;
    m_outputs_map.at("OA2_DCU_DoorR2_DoorClosedAndLocked")     = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorR2_DoorClosedAndLocked;
    m_outputs_map.at("OA2_DCU_DoorR3_DoorClosedAndLocked")     = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorR3_DoorClosedAndLocked;
    m_outputs_map.at("OA2_DCU_DoorR4_DoorClosedAndLocked")     = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorR4_DoorClosedAndLocked;
    m_outputs_map.at("OA2_DCU_DoorL1_DoorClosedAndLocked")     = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorL1_DoorClosedAndLocked;
    m_outputs_map.at("OA2_DCU_DoorL2_DoorClosedAndLocked")     = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorL2_DoorClosedAndLocked;
    m_outputs_map.at("OA2_DCU_DoorL3_DoorClosedAndLocked")     = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorL3_DoorClosedAndLocked;
    m_outputs_map.at("OA2_DCU_DoorL4_DoorClosedAndLocked")     = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorL4_DoorClosedAndLocked;
    m_outputs_map.at("SKA1_DCU_DoorR1_TCMS_TLRelease")         = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorR1_TCMS_TLRelease;
    m_outputs_map.at("SKA1_DCU_DoorR2_TCMS_TLRelease")         = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorR2_TCMS_TLRelease;
    m_outputs_map.at("SKA1_DCU_DoorR3_TCMS_TLRelease")         = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorR3_TCMS_TLRelease;
    m_outputs_map.at("SKA1_DCU_DoorR4_TCMS_TLRelease")         = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorR4_TCMS_TLRelease;
    m_outputs_map.at("SKA1_DCU_DoorL1_TCMS_TLRelease")         = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorL1_TCMS_TLRelease;
    m_outputs_map.at("SKA1_DCU_DoorL2_TCMS_TLRelease")         = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorL2_TCMS_TLRelease;
    m_outputs_map.at("SKA1_DCU_DoorL3_TCMS_TLRelease")         = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorL3_TCMS_TLRelease;
    m_outputs_map.at("SKA1_DCU_DoorL4_TCMS_TLRelease")         = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorL4_TCMS_TLRelease;
    m_outputs_map.at("SKA2_DCU_DoorR1_TCMS_TLRelease")         = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorR1_TCMS_TLRelease;
    m_outputs_map.at("SKA2_DCU_DoorR2_TCMS_TLRelease")         = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorR2_TCMS_TLRelease;
    m_outputs_map.at("SKA2_DCU_DoorR3_TCMS_TLRelease")         = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorR3_TCMS_TLRelease;
    m_outputs_map.at("SKA2_DCU_DoorR4_TCMS_TLRelease")         = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorR4_TCMS_TLRelease;
    m_outputs_map.at("SKA2_DCU_DoorL1_TCMS_TLRelease")         = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorL1_TCMS_TLRelease;
    m_outputs_map.at("SKA2_DCU_DoorL2_TCMS_TLRelease")         = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorL2_TCMS_TLRelease;
    m_outputs_map.at("SKA2_DCU_DoorL3_TCMS_TLRelease")         = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorL3_TCMS_TLRelease;
    m_outputs_map.at("SKA2_DCU_DoorL4_TCMS_TLRelease")         = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorL4_TCMS_TLRelease;
    m_outputs_map.at("OA1_DCU_DoorR1_TCMS_TLRelease")          = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorR1_TCMS_TLRelease;
    m_outputs_map.at("OA1_DCU_DoorR2_TCMS_TLRelease")          = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorR2_TCMS_TLRelease;
    m_outputs_map.at("OA1_DCU_DoorR3_TCMS_TLRelease")          = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorR3_TCMS_TLRelease;
    m_outputs_map.at("OA1_DCU_DoorR4_TCMS_TLRelease")          = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorR4_TCMS_TLRelease;
    m_outputs_map.at("OA1_DCU_DoorL1_TCMS_TLRelease")          = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorL1_TCMS_TLRelease;
    m_outputs_map.at("OA1_DCU_DoorL2_TCMS_TLRelease")          = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorL2_TCMS_TLRelease;
    m_outputs_map.at("OA1_DCU_DoorL3_TCMS_TLRelease")          = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorL3_TCMS_TLRelease;
    m_outputs_map.at("OA1_DCU_DoorL4_TCMS_TLRelease")          = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorL4_TCMS_TLRelease;
    m_outputs_map.at("OA2_DCU_DoorR1_TCMS_TLRelease")          = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorR1_TCMS_TLRelease;
    m_outputs_map.at("OA2_DCU_DoorR2_TCMS_TLRelease")          = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorR2_TCMS_TLRelease;
    m_outputs_map.at("OA2_DCU_DoorR3_TCMS_TLRelease")          = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorR3_TCMS_TLRelease;
    m_outputs_map.at("OA2_DCU_DoorR4_TCMS_TLRelease")          = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorR4_TCMS_TLRelease;
    m_outputs_map.at("OA2_DCU_DoorL1_TCMS_TLRelease")          = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorL1_TCMS_TLRelease;
    m_outputs_map.at("OA2_DCU_DoorL2_TCMS_TLRelease")          = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorL2_TCMS_TLRelease;
    m_outputs_map.at("OA2_DCU_DoorL3_TCMS_TLRelease")          = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorL3_TCMS_TLRelease;
    m_outputs_map.at("OA2_DCU_DoorL4_TCMS_TLRelease")          = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorL4_TCMS_TLRelease;
    m_outputs_map.at("SKA1_DCU_DoorR1_TCMS_OutofService")      = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorR1_TCMS_OutofService;
    m_outputs_map.at("SKA1_DCU_DoorR2_TCMS_OutofService")      = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorR2_TCMS_OutofService;
    m_outputs_map.at("SKA1_DCU_DoorR3_TCMS_OutofService")      = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorR3_TCMS_OutofService;
    m_outputs_map.at("SKA1_DCU_DoorR4_TCMS_OutofService")      = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorR4_TCMS_OutofService;
    m_outputs_map.at("SKA1_DCU_DoorL1_TCMS_OutofService")      = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorL1_TCMS_OutofService;
    m_outputs_map.at("SKA1_DCU_DoorL2_TCMS_OutofService")      = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorL2_TCMS_OutofService;
    m_outputs_map.at("SKA1_DCU_DoorL3_TCMS_OutofService")      = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorL3_TCMS_OutofService;
    m_outputs_map.at("SKA1_DCU_DoorL4_TCMS_OutofService")      = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorL4_TCMS_OutofService;
    m_outputs_map.at("SKA2_DCU_DoorR1_TCMS_OutofService")      = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorR1_TCMS_OutofService;
    m_outputs_map.at("SKA2_DCU_DoorR2_TCMS_OutofService")      = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorR2_TCMS_OutofService;
    m_outputs_map.at("SKA2_DCU_DoorR3_TCMS_OutofService")      = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorR3_TCMS_OutofService;
    m_outputs_map.at("SKA2_DCU_DoorR4_TCMS_OutofService")      = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorR4_TCMS_OutofService;
    m_outputs_map.at("SKA2_DCU_DoorL1_TCMS_OutofService")      = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorL1_TCMS_OutofService;
    m_outputs_map.at("SKA2_DCU_DoorL2_TCMS_OutofService")      = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorL2_TCMS_OutofService;
    m_outputs_map.at("SKA2_DCU_DoorL3_TCMS_OutofService")      = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorL3_TCMS_OutofService;
    m_outputs_map.at("SKA2_DCU_DoorL4_TCMS_OutofService")      = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorL4_TCMS_OutofService;
    m_outputs_map.at("OA1_DCU_DoorR1_TCMS_OutofService")       = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorR1_TCMS_OutofService;
    m_outputs_map.at("OA1_DCU_DoorR2_TCMS_OutofService")       = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorR2_TCMS_OutofService;
    m_outputs_map.at("OA1_DCU_DoorR3_TCMS_OutofService")       = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorR3_TCMS_OutofService;
    m_outputs_map.at("OA1_DCU_DoorR4_TCMS_OutofService")       = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorR4_TCMS_OutofService;
    m_outputs_map.at("OA1_DCU_DoorL1_TCMS_OutofService")       = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorL1_TCMS_OutofService;
    m_outputs_map.at("OA1_DCU_DoorL2_TCMS_OutofService")       = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorL2_TCMS_OutofService;
    m_outputs_map.at("OA1_DCU_DoorL3_TCMS_OutofService")       = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorL3_TCMS_OutofService;
    m_outputs_map.at("OA1_DCU_DoorL4_TCMS_OutofService")       = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorL4_TCMS_OutofService;
    m_outputs_map.at("OA2_DCU_DoorR1_TCMS_OutofService")       = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorR1_TCMS_OutofService;
    m_outputs_map.at("OA2_DCU_DoorR2_TCMS_OutofService")       = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorR2_TCMS_OutofService;
    m_outputs_map.at("OA2_DCU_DoorR3_TCMS_OutofService")       = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorR3_TCMS_OutofService;
    m_outputs_map.at("OA2_DCU_DoorR4_TCMS_OutofService")       = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorR4_TCMS_OutofService;
    m_outputs_map.at("OA2_DCU_DoorL1_TCMS_OutofService")       = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorL1_TCMS_OutofService;
    m_outputs_map.at("OA2_DCU_DoorL2_TCMS_OutofService")       = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorL2_TCMS_OutofService;
    m_outputs_map.at("OA2_DCU_DoorL3_TCMS_OutofService")       = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorL3_TCMS_OutofService;
    m_outputs_map.at("OA2_DCU_DoorL4_TCMS_OutofService")       = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorL4_TCMS_OutofService;
    m_outputs_map.at("SKA1_DCU_DoorR1_DoorObstDet")            = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorR1_DoorObstDet;
    m_outputs_map.at("SKA1_DCU_DoorR2_DoorObstDet")            = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorR2_DoorObstDet;
    m_outputs_map.at("SKA1_DCU_DoorR3_DoorObstDet")            = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorR3_DoorObstDet;
    m_outputs_map.at("SKA1_DCU_DoorR4_DoorObstDet")            = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorR4_DoorObstDet;
    m_outputs_map.at("SKA1_DCU_DoorL1_DoorObstDet")            = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorL1_DoorObstDet;
    m_outputs_map.at("SKA1_DCU_DoorL2_DoorObstDet")            = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorL2_DoorObstDet;
    m_outputs_map.at("SKA1_DCU_DoorL3_DoorObstDet")            = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorL3_DoorObstDet;
    m_outputs_map.at("SKA1_DCU_DoorL4_DoorObstDet")            = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorL4_DoorObstDet;
    m_outputs_map.at("SKA2_DCU_DoorR1_DoorObstDet")            = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorR1_DoorObstDet;
    m_outputs_map.at("SKA2_DCU_DoorR2_DoorObstDet")            = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorR2_DoorObstDet;
    m_outputs_map.at("SKA2_DCU_DoorR3_DoorObstDet")            = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorR3_DoorObstDet;
    m_outputs_map.at("SKA2_DCU_DoorR4_DoorObstDet")            = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorR4_DoorObstDet;
    m_outputs_map.at("SKA2_DCU_DoorL1_DoorObstDet")            = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorL1_DoorObstDet;
    m_outputs_map.at("SKA2_DCU_DoorL2_DoorObstDet")            = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorL2_DoorObstDet;
    m_outputs_map.at("SKA2_DCU_DoorL3_DoorObstDet")            = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorL3_DoorObstDet;
    m_outputs_map.at("SKA2_DCU_DoorL4_DoorObstDet")            = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorL4_DoorObstDet;
    m_outputs_map.at("OA1_DCU_DoorR1_DoorObstDet")             = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorR1_DoorObstDet;
    m_outputs_map.at("OA1_DCU_DoorR2_DoorObstDet")             = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorR2_DoorObstDet;
    m_outputs_map.at("OA1_DCU_DoorR3_DoorObstDet")             = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorR3_DoorObstDet;
    m_outputs_map.at("OA1_DCU_DoorR4_DoorObstDet")             = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorR4_DoorObstDet;
    m_outputs_map.at("OA1_DCU_DoorL1_DoorObstDet")             = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorL1_DoorObstDet;
    m_outputs_map.at("OA1_DCU_DoorL2_DoorObstDet")             = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorL2_DoorObstDet;
    m_outputs_map.at("OA1_DCU_DoorL3_DoorObstDet")             = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorL3_DoorObstDet;
    m_outputs_map.at("OA1_DCU_DoorL4_DoorObstDet")             = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorL4_DoorObstDet;
    m_outputs_map.at("OA2_DCU_DoorR1_DoorObstDet")             = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorR1_DoorObstDet;
    m_outputs_map.at("OA2_DCU_DoorR2_DoorObstDet")             = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorR2_DoorObstDet;
    m_outputs_map.at("OA2_DCU_DoorR3_DoorObstDet")             = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorR3_DoorObstDet;
    m_outputs_map.at("OA2_DCU_DoorR4_DoorObstDet")             = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorR4_DoorObstDet;
    m_outputs_map.at("OA2_DCU_DoorL1_DoorObstDet")             = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorL1_DoorObstDet;
    m_outputs_map.at("OA2_DCU_DoorL2_DoorObstDet")             = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorL2_DoorObstDet;
    m_outputs_map.at("OA2_DCU_DoorL3_DoorObstDet")             = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorL3_DoorObstDet;
    m_outputs_map.at("OA2_DCU_DoorL4_DoorObstDet")             = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorL4_DoorObstDet;
    m_outputs_map.at("SKA1_DCU_DoorR1_DoorAntiDrag")           = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorR1_DoorAntiDrag;
    m_outputs_map.at("SKA1_DCU_DoorR2_DoorAntiDrag")           = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorR2_DoorAntiDrag;
    m_outputs_map.at("SKA1_DCU_DoorR3_DoorAntiDrag")           = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorR3_DoorAntiDrag;
    m_outputs_map.at("SKA1_DCU_DoorR4_DoorAntiDrag")           = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorR4_DoorAntiDrag;
    m_outputs_map.at("SKA1_DCU_DoorL1_DoorAntiDrag")           = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorL1_DoorAntiDrag;
    m_outputs_map.at("SKA1_DCU_DoorL2_DoorAntiDrag")           = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorL2_DoorAntiDrag;
    m_outputs_map.at("SKA1_DCU_DoorL3_DoorAntiDrag")           = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorL3_DoorAntiDrag;
    m_outputs_map.at("SKA1_DCU_DoorL4_DoorAntiDrag")           = m_ccu_to_all_jrus_2.bits.SKA1_DCU_DoorL4_DoorAntiDrag;
    m_outputs_map.at("SKA2_DCU_DoorR1_DoorAntiDrag")           = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorR1_DoorAntiDrag;
    m_outputs_map.at("SKA2_DCU_DoorR2_DoorAntiDrag")           = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorR2_DoorAntiDrag;
    m_outputs_map.at("SKA2_DCU_DoorR3_DoorAntiDrag")           = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorR3_DoorAntiDrag;
    m_outputs_map.at("SKA2_DCU_DoorR4_DoorAntiDrag")           = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorR4_DoorAntiDrag;
    m_outputs_map.at("SKA2_DCU_DoorL1_DoorAntiDrag")           = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorL1_DoorAntiDrag;
    m_outputs_map.at("SKA2_DCU_DoorL2_DoorAntiDrag")           = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorL2_DoorAntiDrag;
    m_outputs_map.at("SKA2_DCU_DoorL3_DoorAntiDrag")           = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorL3_DoorAntiDrag;
    m_outputs_map.at("SKA2_DCU_DoorL4_DoorAntiDrag")           = m_ccu_to_all_jrus_2.bits.SKA2_DCU_DoorL4_DoorAntiDrag;
    m_outputs_map.at("OA1_DCU_DoorR1_DoorAntiDrag")            = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorR1_DoorAntiDrag;
    m_outputs_map.at("OA1_DCU_DoorR2_DoorAntiDrag")            = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorR2_DoorAntiDrag;
    m_outputs_map.at("OA1_DCU_DoorR3_DoorAntiDrag")            = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorR3_DoorAntiDrag;
    m_outputs_map.at("OA1_DCU_DoorR4_DoorAntiDrag")            = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorR4_DoorAntiDrag;
    m_outputs_map.at("OA1_DCU_DoorL1_DoorAntiDrag")            = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorL1_DoorAntiDrag;
    m_outputs_map.at("OA1_DCU_DoorL2_DoorAntiDrag")            = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorL2_DoorAntiDrag;
    m_outputs_map.at("OA1_DCU_DoorL3_DoorAntiDrag")            = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorL3_DoorAntiDrag;
    m_outputs_map.at("OA1_DCU_DoorL4_DoorAntiDrag")            = m_ccu_to_all_jrus_2.bits.OA1_DCU_DoorL4_DoorAntiDrag;
    m_outputs_map.at("OA2_DCU_DoorR1_DoorAntiDrag")            = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorR1_DoorAntiDrag;
    m_outputs_map.at("OA2_DCU_DoorR2_DoorAntiDrag")            = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorR2_DoorAntiDrag;
    m_outputs_map.at("OA2_DCU_DoorR3_DoorAntiDrag")            = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorR3_DoorAntiDrag;
    m_outputs_map.at("OA2_DCU_DoorR4_DoorAntiDrag")            = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorR4_DoorAntiDrag;
    m_outputs_map.at("OA2_DCU_DoorL1_DoorAntiDrag")            = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorL1_DoorAntiDrag;
    m_outputs_map.at("OA2_DCU_DoorL2_DoorAntiDrag")            = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorL2_DoorAntiDrag;
    m_outputs_map.at("OA2_DCU_DoorL3_DoorAntiDrag")            = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorL3_DoorAntiDrag;
    m_outputs_map.at("OA2_DCU_DoorL4_DoorAntiDrag")            = m_ccu_to_all_jrus_2.bits.OA2_DCU_DoorL4_DoorAntiDrag;
    m_outputs_map.at("bit248")                                 = m_ccu_to_all_jrus_2.bits.bit248;
    m_outputs_map.at("bit249")                                 = m_ccu_to_all_jrus_2.bits.bit249;
    m_outputs_map.at("bit250")                                 = m_ccu_to_all_jrus_2.bits.bit250;
    m_outputs_map.at("bit251")                                 = m_ccu_to_all_jrus_2.bits.bit251;
    m_outputs_map.at("bit252")                                 = m_ccu_to_all_jrus_2.bits.bit252;
    m_outputs_map.at("bit253")                                 = m_ccu_to_all_jrus_2.bits.bit253;
    m_outputs_map.at("bit254")                                 = m_ccu_to_all_jrus_2.bits.bit254;
    m_outputs_map.at("bit255")                                 = m_ccu_to_all_jrus_2.bits.bit255;
}
