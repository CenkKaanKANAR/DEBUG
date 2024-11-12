#include "oa_ccu_vh_riom_mvb2_dcu.h"
#include <QDebug>

Oa_Ccu_Vh_Riom_Mvb2_Dcu::Oa_Ccu_Vh_Riom_Mvb2_Dcu(QObject *parent)
    : QObject{parent}
{
    init_oa1_table();
    init_oa2_table();
}

Oa_Ccu_Vh_Riom_Mvb2_Dcu::~Oa_Ccu_Vh_Riom_Mvb2_Dcu()
{
    for (auto tableWidget : m_tableWidget) {
        delete tableWidget;
    }
}


void Oa_Ccu_Vh_Riom_Mvb2_Dcu::set_data_struct(const QByteArray &output, const OA_VEHICLE_NUM &oa_x_num)
{
    int ska_num = static_cast<int>(oa_x_num);
    if (output.size() == sizeof(m_oa_ccu_vh_riom_mvb2_dcu[ska_num].bytes)) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        memcpy(m_oa_ccu_vh_riom_mvb2_dcu[ska_num].bytes, output.constData(), sizeof(m_oa_ccu_vh_riom_mvb2_dcu[ska_num].bytes));
        update_map(oa_x_num);
        update_table(oa_x_num);
    }
    else
    {
        qDebug() << "Error: Output size mismatch" << "Oa_Ccu_Vh_Riom_Mvb2_Dcu: " << ska_num;
    }
}



void Oa_Ccu_Vh_Riom_Mvb2_Dcu::init_oa1_table()
{
    m_outputs_map[get_index(OA_VEHICLE_NUM::OA1)] = {
        {"DoorR1_TCMS_EEDreset", 0},
        {"DoorR1_TCMS_TLRelease", 0},
        {"DoorR1_TCMS_LoopLSDoorNotEmergOp", 0},
        {"DoorR1_TCMS_DoorFullyOpen", 0},
        {"DoorR2_TCMS_EEDreset", 0},
        {"DoorR2_TCMS_TLRelease", 0},
        {"DoorR2_TCMS_LoopLSDoorNotEmergOp", 0},
        {"DoorR2_TCMS_DoorFullyOpen", 0},
        {"DoorR3_TCMS_EEDreset", 0},
        {"DoorR3_TCMS_TLRelease", 0},
        {"DoorR3_TCMS_LoopLSDoorNotEmergOp", 0},
        {"DoorR3_TCMS_DoorFullyOpen", 0},
        {"DoorR4_TCMS_EEDreset", 0},
        {"DoorR4_TCMS_TLRelease", 0},
        {"DoorR4_TCMS_LoopLSDoorNotEmergOp", 0},
        {"DoorR4_TCMS_DoorFullyOpen", 0},
        {"DoorL1_TCMS_EEDreset", 0},
        {"DoorL1_TCMS_TLRelease", 0},
        {"DoorL1_TCMS_LoopLSDoorNotEmergOp", 0},
        {"DoorL1_TCMS_DoorFullyOpen", 0},
        {"DoorL2_TCMS_EEDreset", 0},
        {"DoorL2_TCMS_TLRelease", 0},
        {"DoorL2_TCMS_LoopLSDoorNotEmergOp", 0},
        {"DoorL2_TCMS_DoorFullyOpen", 0},
        {"DoorL3_TCMS_EEDreset", 0},
        {"DoorL3_TCMS_TLRelease", 0},
        {"DoorL3_TCMS_LoopLSDoorNotEmergOp", 0},
        {"DoorL3_TCMS_DoorFullyOpen", 0},
        {"DoorL4_TCMS_EEDreset", 0},
        {"DoorL4_TCMS_TLRelease", 0},
        {"DoorL4_TCMS_LoopLSDoorNotEmergOp", 0},
        {"DoorL4_TCMS_DoorFullyOpen", 0},
        {"HVAC1_HVAC_On", 0},
        {"HVAC1_Reduce_Mode", 0},
        {"HVAC1_Door_Open", 0},
        {"bit59", 0},
        {"HVAC1_Automatic_Dumper_Switch", 0},
        {"HVAC1_Close_Dumper", 0},
        {"bit62", 0},
        {"bit63", 0},
        {"HVAC2_HVAC_On", 0},
        {"HVAC2_Reduce_Mode", 0},
        {"HVAC2_Door_Open", 0},
        {"bit67", 0},
        {"HVAC2_Automatic_Dumper_Switch", 0},
        {"HVAC2_Close_Dumper", 0},
        {"bit70", 0},
        {"bit71", 0},
        {"reserved_9", 0},
        {"reserved_10", 0},
        {"reserved_11", 0},
        {"reserved_12", 0},
        {"reserved_13", 0},
        {"reserved_14", 0},
        {"reserved_15", 0},
        {"reserved_4", 0},
        {"reserved_5", 0},
        {"reserved_6", 0},
        };

    QStringList table_name = {"oa_1_ccu_vh_riom_mvb2_dcu", "value"};

    m_tableWidget.push_back(new QTableWidget());
    m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)] ->setColumnCount(2);
    m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)] ->setRowCount(m_outputs_map[get_index(OA_VEHICLE_NUM::OA1)].size());
    m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)]->setHorizontalHeaderLabels(table_name);

    int row = 0;
    for (const auto& pair:  m_outputs_map[get_index(OA_VEHICLE_NUM::OA1)]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)]->setItem(row, 0, item_name);
        m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }

    m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)]->resizeColumnsToContents();
}



void Oa_Ccu_Vh_Riom_Mvb2_Dcu::init_oa2_table()
{
    // copy assignment operator
    m_outputs_map[get_index(OA_VEHICLE_NUM::OA2)] =  m_outputs_map[get_index(OA_VEHICLE_NUM::OA1)];
    QStringList table_name = {"oa_2_ccu_vh_riom_mvb2_dcu", "value"};

    m_tableWidget.push_back(new QTableWidget());
    m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)] ->setColumnCount(2);
    m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)] ->setRowCount(m_outputs_map[get_index(OA_VEHICLE_NUM::OA2)].size());
    m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)]->setHorizontalHeaderLabels(table_name);

    int row = 0;
    for (const auto& pair:  m_outputs_map[get_index(OA_VEHICLE_NUM::OA2)]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)]->setItem(row, 0, item_name);
        m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)]->resizeColumnsToContents();
}



void Oa_Ccu_Vh_Riom_Mvb2_Dcu::update_table(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);

    // Tabloyu temizleyin

    m_tableWidget[oa_num]->setRowCount(0);
    //tableWidget->clear();

    // Haritadaki verilerle tabloyu doldurun
    int row = 0;
    for (auto it = m_outputs_map[oa_num].begin(); it != m_outputs_map[oa_num].end(); ++it)
    {
        m_tableWidget[oa_num]->insertRow(row);
        //qDebug() <<"first:" << it->first << "second:" << it->second;
        QTableWidgetItem *keyItem   = new QTableWidgetItem(it->first); // Anahtar
        QTableWidgetItem *valueItem = new QTableWidgetItem(QString::number(it->second)); // Değer

        m_tableWidget[oa_num]->setItem(row, 0, keyItem);
        m_tableWidget[oa_num]->setItem(row, 1, valueItem);

        row++;
    }
}


void Oa_Ccu_Vh_Riom_Mvb2_Dcu::update_map(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);
    m_outputs_map[oa_num].at("R1_TCMS_EEDreset")              = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.R1_TCMS_EEDreset;
    m_outputs_map[oa_num].at("R1_TCMS_TLRelease")             = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.R1_TCMS_TLRelease;
    m_outputs_map[oa_num].at("R1_TCMS_LoopLSDoorNotEmergOp")  = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.R1_TCMS_LoopLSDoorNotEmergOp;
    m_outputs_map[oa_num].at("R1_TCMS_DoorFullyOpen")         = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.R1_TCMS_DoorFullyOpen;
    m_outputs_map[oa_num].at("R2_TCMS_EEDreset")              = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.R2_TCMS_EEDreset;
    m_outputs_map[oa_num].at("R2_TCMS_TLRelease")             = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.R2_TCMS_TLRelease;
    m_outputs_map[oa_num].at("R2_TCMS_LoopLSDoorNotEmergOp")  = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.R2_TCMS_LoopLSDoorNotEmergOp;
    m_outputs_map[oa_num].at("R2_TCMS_DoorFullyOpen")         = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.R2_TCMS_DoorFullyOpen;
    m_outputs_map[oa_num].at("R3_TCMS_EEDreset")              = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.R3_TCMS_EEDreset;
    m_outputs_map[oa_num].at("R3_TCMS_TLRelease")             = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.R3_TCMS_TLRelease;
    m_outputs_map[oa_num].at("R3_TCMS_LoopLSDoorNotEmergOp")  = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.R3_TCMS_LoopLSDoorNotEmergOp;
    m_outputs_map[oa_num].at("R3_TCMS_DoorFullyOpen")         = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.R3_TCMS_DoorFullyOpen;
    m_outputs_map[oa_num].at("R4_TCMS_EEDreset")              = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.R4_TCMS_EEDreset;
    m_outputs_map[oa_num].at("R4_TCMS_TLRelease")             = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.R4_TCMS_TLRelease;
    m_outputs_map[oa_num].at("R4_TCMS_LoopLSDoorNotEmergOp")  = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.R4_TCMS_LoopLSDoorNotEmergOp;
    m_outputs_map[oa_num].at("R4_TCMS_DoorFullyOpen")         = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.R4_TCMS_DoorFullyOpen;
    m_outputs_map[oa_num].at("L1_TCMS_EEDreset")              = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.L1_TCMS_EEDreset;
    m_outputs_map[oa_num].at("L1_TCMS_TLRelease")             = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.L1_TCMS_TLRelease;
    m_outputs_map[oa_num].at("L1_TCMS_LoopLSDoorNotEmergOp")  = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.L1_TCMS_LoopLSDoorNotEmergOp;
    m_outputs_map[oa_num].at("L1_TCMS_DoorFullyOpen")         = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.L1_TCMS_DoorFullyOpen;
    m_outputs_map[oa_num].at("L2_TCMS_EEDreset")              = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.L2_TCMS_EEDreset;
    m_outputs_map[oa_num].at("L2_TCMS_TLRelease")             = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.L2_TCMS_TLRelease;
    m_outputs_map[oa_num].at("L2_TCMS_LoopLSDoorNotEmergOp")  = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.L2_TCMS_LoopLSDoorNotEmergOp;
    m_outputs_map[oa_num].at("L2_TCMS_DoorFullyOpen")         = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.L2_TCMS_DoorFullyOpen;
    m_outputs_map[oa_num].at("L3_TCMS_EEDreset")              = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.L3_TCMS_EEDreset;
    m_outputs_map[oa_num].at("L3_TCMS_TLRelease")             = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.L3_TCMS_TLRelease;
    m_outputs_map[oa_num].at("L3_TCMS_LoopLSDoorNotEmergOp")  = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.L3_TCMS_LoopLSDoorNotEmergOp;
    m_outputs_map[oa_num].at("L3_TCMS_DoorFullyOpen")         = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.L3_TCMS_DoorFullyOpen;
    m_outputs_map[oa_num].at("L4_TCMS_EEDreset")              = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.L4_TCMS_EEDreset;
    m_outputs_map[oa_num].at("L4_TCMS_TLRelease")             = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.L4_TCMS_TLRelease;
    m_outputs_map[oa_num].at("L4_TCMS_LoopLSDoorNotEmergOp")  = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.L4_TCMS_LoopLSDoorNotEmergOp;
    m_outputs_map[oa_num].at("L4_TCMS_DoorFullyOpen")         = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.L4_TCMS_DoorFullyOpen;
    m_outputs_map[oa_num].at("HVAC1_HVAC_On")                 = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.HVAC1_HVAC_On;
    m_outputs_map[oa_num].at("HVAC1_Reduce_Mode")             = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.HVAC1_Reduce_Mode;
    m_outputs_map[oa_num].at("HVAC1_Door_Open")               = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.HVAC1_Door_Open;
    m_outputs_map[oa_num].at("HVAC1_Automatic_Dumper_Switch") = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.HVAC1_Automatic_Dumper_Switch;
    m_outputs_map[oa_num].at("HVAC1_Close_Dumper")            = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.HVAC1_Close_Dumper;
    m_outputs_map[oa_num].at("HVAC2_HVAC_On")                 = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.HVAC2_HVAC_On;
    m_outputs_map[oa_num].at("HVAC2_Reduce_Mode")             = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.HVAC2_Reduce_Mode;
    m_outputs_map[oa_num].at("HVAC2_Door_Open")               = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.HVAC2_Door_Open;
    m_outputs_map[oa_num].at("HVAC2_Automatic_Dumper_Switch") = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.HVAC2_Automatic_Dumper_Switch;
    m_outputs_map[oa_num].at("HVAC2_Close_Dumper")            = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.HVAC2_Close_Dumper;
    m_outputs_map[oa_num].at("bit59")                         = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.bit59;
    m_outputs_map[oa_num].at("bit62")                         = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.bit62;
    m_outputs_map[oa_num].at("bit63")                         = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.bit63;
    m_outputs_map[oa_num].at("bit67")                         = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.bit67;
    m_outputs_map[oa_num].at("bit70")                         = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.bit70;
    m_outputs_map[oa_num].at("bit71")                         = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.bit71;
    m_outputs_map[oa_num].at("reserved_4")                    = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.reserved_4;
    m_outputs_map[oa_num].at("reserved_5")                    = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.reserved_5;
    m_outputs_map[oa_num].at("reserved_6")                    = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.reserved_6;
    m_outputs_map[oa_num].at("reserved_9")                    = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.reserved_9;
    m_outputs_map[oa_num].at("reserved_10")                   = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.reserved_10;
    m_outputs_map[oa_num].at("reserved_11")                   = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.reserved_11;
    m_outputs_map[oa_num].at("reserved_12")                   = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.reserved_12;
    m_outputs_map[oa_num].at("reserved_13")                   = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.reserved_13;
    m_outputs_map[oa_num].at("reserved_14")                   = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.reserved_14;
    m_outputs_map[oa_num].at("reserved_15")                   = m_oa_ccu_vh_riom_mvb2_dcu.at(oa_num).bits.reserved_15;

}
