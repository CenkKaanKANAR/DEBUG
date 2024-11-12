#include "ska_ccu_vh_riom_mvb2_dcu.h"
#include <QDebug>

Ska_Ccu_Vh_Riom_Mvb2_Dcu::Ska_Ccu_Vh_Riom_Mvb2_Dcu(QObject *parent)
    : QObject{parent}
{
    //memset(m_ska_ccu_vh_riom_mvb1_d_outputs, 0, sizeof(*m_ska_ccu_vh_riom_mvb1_d_outputs));
    init_ska1_table();
    init_ska2_table();
}

Ska_Ccu_Vh_Riom_Mvb2_Dcu::~Ska_Ccu_Vh_Riom_Mvb2_Dcu()
{

    for (auto tableWidget : m_tableWidget) {
        delete tableWidget;
    }
}

void Ska_Ccu_Vh_Riom_Mvb2_Dcu::set_data_struct(const QByteArray &output, const SKA_VEHICLE_NUM &ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    if (output.size() == sizeof(m_ska_ccu_vh_riom_mvb2_dcu[ska_num].bytes)) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        memcpy(m_ska_ccu_vh_riom_mvb2_dcu[ska_num].bytes, output.constData(), sizeof(m_ska_ccu_vh_riom_mvb2_dcu[ska_num].bytes));
        update_map(ska_x_num);
        update_table(ska_x_num);
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }
}

void Ska_Ccu_Vh_Riom_Mvb2_Dcu::init_ska1_table()
{
    m_outputs_map[get_index(SKA_VEHICLE_NUM::SKA1)] = {
        {"R1_TCMS_EEDreset", 0},
        {"R1_TCMS_TLRelease", 0},
        {"R1_TCMS_LoopLSDoorNotEmergOp", 0},
        {"R1_TCMS_DoorFullyOpen", 0},
        {"R2_TCMS_EEDreset", 0},
        {"R2_TCMS_TLRelease", 0},
        {"R2_TCMS_LoopLSDoorNotEmergOp", 0},
        {"R2_TCMS_DoorFullyOpen", 0},
        {"R3_TCMS_EEDreset", 0},
        {"R3_TCMS_TLRelease", 0},
        {"R3_TCMS_LoopLSDoorNotEmergOp", 0},
        {"R3_TCMS_DoorFullyOpen", 0},
        {"R4_TCMS_EEDreset", 0},
        {"R4_TCMS_TLRelease", 0},
        {"R4_TCMS_LoopLSDoorNotEmergOp", 0},
        {"R4_TCMS_DoorFullyOpen", 0},
        {"L1_TCMS_EEDreset", 0},
        {"L1_TCMS_TLRelease", 0},
        {"L1_TCMS_LoopLSDoorNotEmergOp", 0},
        {"L1_TCMS_DoorFullyOpen", 0},
        {"L2_TCMS_EEDreset", 0},
        {"L2_TCMS_TLRelease", 0},
        {"L2_TCMS_LoopLSDoorNotEmergOp", 0},
        {"L2_TCMS_DoorFullyOpen", 0},
        {"L3_TCMS_EEDreset", 0},
        {"L3_TCMS_TLRelease", 0},
        {"L3_TCMS_LoopLSDoorNotEmergOp", 0},
        {"L3_TCMS_DoorFullyOpen", 0},
        {"L4_TCMS_EEDreset", 0},
        {"L4_TCMS_TLRelease", 0},
        {"L4_TCMS_LoopLSDoorNotEmergOp", 0},
        {"L4_TCMS_DoorFullyOpen", 0},
        {"reserved_4", 0},
        {"reserved_5", 0},
        {"bit48", 0},
        {"HVACC_Reduce_Mode", 0},
        {"bit50", 0},
        {"HVACC_Cabin_Active", 0},
        {"HVACC_Automatic_Dumper_Switch", 0},
        {"HVACC_Close_Dumper", 0},
        {"bit54", 0},
        {"bit55", 0},
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
        {"C_RstFduX", 0},
        {"bit97", 0},
        {"C_Resound", 0},
        {"bit99", 0},
        {"bit100", 0},
        {"bit101", 0},
        {"bit102", 0},
        {"bit103", 0},
        {"reserved_13", 0},
        {"reserved_14", 0},
        {"reserved_15", 0},
        };
    //Ska_Ccu_Vh_Riom_Mvb2_Dcu
    QStringList table_name = {"ska_1_ccu_vh_riom_mvb2_dcu", "value"};

    m_tableWidget.push_back(new QTableWidget());
    m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)] ->setColumnCount(2);
    m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)] ->setRowCount(m_outputs_map[get_index(SKA_VEHICLE_NUM::SKA1)].size());
    m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)]->setHorizontalHeaderLabels(table_name);

    int row = 0;
    for (const auto& pair:  m_outputs_map[get_index(SKA_VEHICLE_NUM::SKA1)]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)]->setItem(row, 0, item_name);
        m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)]->resizeColumnsToContents();
}

void Ska_Ccu_Vh_Riom_Mvb2_Dcu::init_ska2_table()
{
    m_outputs_map[get_index(SKA_VEHICLE_NUM::SKA2)] =  m_outputs_map[get_index(SKA_VEHICLE_NUM::SKA1)];
    QStringList table_name = {"ska_2_ccu_vh_riom_mvb2_dcu", "value"};

    m_tableWidget.push_back(new QTableWidget());
    m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)] ->setColumnCount(2);
    m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)] ->setRowCount(m_outputs_map[get_index(SKA_VEHICLE_NUM::SKA2)].size());
    m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)]->setHorizontalHeaderLabels(table_name);

    int row = 0;
    for (const auto& pair:  m_outputs_map[get_index(SKA_VEHICLE_NUM::SKA2)]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)]->setItem(row, 0, item_name);
        m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }

    m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)]->resizeColumnsToContents();
}

void Ska_Ccu_Vh_Riom_Mvb2_Dcu::update_table(SKA_VEHICLE_NUM ska_x_num)
{

    int ska_num = static_cast<int>(ska_x_num);

    // Tabloyu temizleyin

    m_tableWidget[ska_num]->setRowCount(0);
    //tableWidget->clear();

    // Haritadaki verilerle tabloyu doldurun
    int row = 0;
    for (auto it = m_outputs_map[ska_num].begin(); it != m_outputs_map[ska_num].end(); ++it)
    {
        m_tableWidget[ska_num]->insertRow(row);
        //qDebug() <<"first:" << it->first << "second:" << it->second;
        QTableWidgetItem *keyItem   = new QTableWidgetItem(it->first); // Anahtar
        QTableWidgetItem *valueItem = new QTableWidgetItem(QString::number(it->second)); // Değer

        m_tableWidget[ska_num]->setItem(row, 0, keyItem);
        m_tableWidget[ska_num]->setItem(row, 1, valueItem);

        row++;
    }
}

void Ska_Ccu_Vh_Riom_Mvb2_Dcu::update_map(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_outputs_map[ska_num].at("R1_TCMS_EEDreset")                   = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.R1_TCMS_EEDreset;
    m_outputs_map[ska_num].at("R1_TCMS_TLRelease")                 = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.R1_TCMS_TLRelease;
    m_outputs_map[ska_num].at("R1_TCMS_LoopLSDoorNotEmergOp")     = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.R1_TCMS_LoopLSDoorNotEmergOp;
    m_outputs_map[ska_num].at("R1_TCMS_DoorFullyOpen")             = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.R1_TCMS_DoorFullyOpen;
    m_outputs_map[ska_num].at("R2_TCMS_EEDreset")                   = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.R2_TCMS_EEDreset;
    m_outputs_map[ska_num].at("R2_TCMS_TLRelease")                 = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.R2_TCMS_TLRelease;
    m_outputs_map[ska_num].at("R2_TCMS_LoopLSDoorNotEmergOp")     = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.R2_TCMS_LoopLSDoorNotEmergOp;
    m_outputs_map[ska_num].at("R2_TCMS_DoorFullyOpen")             = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.R2_TCMS_DoorFullyOpen;
    m_outputs_map[ska_num].at("R3_TCMS_EEDreset")                   = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.R3_TCMS_EEDreset;
    m_outputs_map[ska_num].at("R3_TCMS_TLRelease")                 = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.R3_TCMS_TLRelease;
    m_outputs_map[ska_num].at("R3_TCMS_LoopLSDoorNotEmergOp")     = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.R3_TCMS_LoopLSDoorNotEmergOp;
    m_outputs_map[ska_num].at("R3_TCMS_DoorFullyOpen")             = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.R3_TCMS_DoorFullyOpen;
    m_outputs_map[ska_num].at("R4_TCMS_EEDreset")                   = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.R4_TCMS_EEDreset;
    m_outputs_map[ska_num].at("R4_TCMS_TLRelease")                 = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.R4_TCMS_TLRelease;
    m_outputs_map[ska_num].at("R4_TCMS_LoopLSDoorNotEmergOp")     = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.R4_TCMS_LoopLSDoorNotEmergOp;
    m_outputs_map[ska_num].at("R4_TCMS_DoorFullyOpen")             = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.R4_TCMS_DoorFullyOpen;
    m_outputs_map[ska_num].at("L1_TCMS_EEDreset")                   = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.L1_TCMS_EEDreset;
    m_outputs_map[ska_num].at("L1_TCMS_TLRelease")                 = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.L1_TCMS_TLRelease;
    m_outputs_map[ska_num].at("L1_TCMS_LoopLSDoorNotEmergOp")     = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.L1_TCMS_LoopLSDoorNotEmergOp;
    m_outputs_map[ska_num].at("L1_TCMS_DoorFullyOpen")             = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.L1_TCMS_DoorFullyOpen;
    m_outputs_map[ska_num].at("L2_TCMS_EEDreset")                   = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.L2_TCMS_EEDreset;
    m_outputs_map[ska_num].at("L2_TCMS_TLRelease")                 = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.L2_TCMS_TLRelease;
    m_outputs_map[ska_num].at("L2_TCMS_LoopLSDoorNotEmergOp")     = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.L2_TCMS_LoopLSDoorNotEmergOp;
    m_outputs_map[ska_num].at("L2_TCMS_DoorFullyOpen")             = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.L2_TCMS_DoorFullyOpen;
    m_outputs_map[ska_num].at("L3_TCMS_EEDreset")                   = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.L3_TCMS_EEDreset;
    m_outputs_map[ska_num].at("L3_TCMS_TLRelease")                 = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.L3_TCMS_TLRelease;
    m_outputs_map[ska_num].at("L3_TCMS_LoopLSDoorNotEmergOp")     = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.L3_TCMS_LoopLSDoorNotEmergOp;
    m_outputs_map[ska_num].at("L3_TCMS_DoorFullyOpen")             = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.L3_TCMS_DoorFullyOpen;
    m_outputs_map[ska_num].at("L4_TCMS_EEDreset")                   = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.L4_TCMS_EEDreset;
    m_outputs_map[ska_num].at("L4_TCMS_TLRelease")                 = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.L4_TCMS_TLRelease;
    m_outputs_map[ska_num].at("L4_TCMS_LoopLSDoorNotEmergOp")     = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.L4_TCMS_LoopLSDoorNotEmergOp;
    m_outputs_map[ska_num].at("L4_TCMS_DoorFullyOpen")             = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.L4_TCMS_DoorFullyOpen;
    m_outputs_map[ska_num].at("reserved_4")                         = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.reserved_4;
    m_outputs_map[ska_num].at("reserved_5")                         = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.reserved_5;
    m_outputs_map[ska_num].at("bit48")                              = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.bit48;
    m_outputs_map[ska_num].at("HVACC_Reduce_Mode")                 = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.HVACC_Reduce_Mode;
    m_outputs_map[ska_num].at("bit50")                              = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.bit50;
    m_outputs_map[ska_num].at("HVACC_Cabin_Active")                = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.HVACC_Cabin_Active;
    m_outputs_map[ska_num].at("HVACC_Automatic_Dumper_Switch")    = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.HVACC_Automatic_Dumper_Switch;
    m_outputs_map[ska_num].at("HVACC_Close_Dumper")                = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.HVACC_Close_Dumper;
    m_outputs_map[ska_num].at("bit54")                              = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.bit54;
    m_outputs_map[ska_num].at("bit55")                              = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.bit55;
    m_outputs_map[ska_num].at("HVAC1_HVAC_On")                      = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.HVAC1_HVAC_On;
    m_outputs_map[ska_num].at("HVAC1_Reduce_Mode")                 = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.HVAC1_Reduce_Mode;
    m_outputs_map[ska_num].at("HVAC1_Door_Open")                   = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.HVAC1_Door_Open;
    m_outputs_map[ska_num].at("bit59")                              = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.bit59;
    m_outputs_map[ska_num].at("HVAC1_Automatic_Dumper_Switch")     = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.HVAC1_Automatic_Dumper_Switch;
    m_outputs_map[ska_num].at("HVAC1_Close_Dumper")                = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.HVAC1_Close_Dumper;
    m_outputs_map[ska_num].at("bit62")                              = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.bit62;
    m_outputs_map[ska_num].at("bit63")                              = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.bit63;
    m_outputs_map[ska_num].at("HVAC2_HVAC_On")                      = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.HVAC2_HVAC_On;
    m_outputs_map[ska_num].at("HVAC2_Reduce_Mode")                 = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.HVAC2_Reduce_Mode;
    m_outputs_map[ska_num].at("HVAC2_Door_Open")                   = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.HVAC2_Door_Open;
    m_outputs_map[ska_num].at("bit67")                              = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.bit67;
    m_outputs_map[ska_num].at("HVAC2_Automatic_Dumper_Switch")     = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.HVAC2_Automatic_Dumper_Switch;
    m_outputs_map[ska_num].at("HVAC2_Close_Dumper")                = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.HVAC2_Close_Dumper;
    m_outputs_map[ska_num].at("bit70")                              = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.bit70;
    m_outputs_map[ska_num].at("bit71")                              = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.bit71;
    m_outputs_map[ska_num].at("reserved_9")                        = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.reserved_9;
    m_outputs_map[ska_num].at("reserved_10")                       = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.reserved_10;
    m_outputs_map[ska_num].at("reserved_11")                       = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.reserved_11;
    m_outputs_map[ska_num].at("C_RstFduX")                         = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.C_RstFduX;
    m_outputs_map[ska_num].at("bit97")                              = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.bit97;
    m_outputs_map[ska_num].at("C_Resound")                          = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.C_Resound;
    m_outputs_map[ska_num].at("bit99")                              = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.bit99;
    m_outputs_map[ska_num].at("bit100")                             = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.bit100;
    m_outputs_map[ska_num].at("bit101")                             = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.bit101;
    m_outputs_map[ska_num].at("bit102")                             = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.bit102;
    m_outputs_map[ska_num].at("bit103")                             = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.bit103;
    m_outputs_map[ska_num].at("reserved_13")                       = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.reserved_13;
    m_outputs_map[ska_num].at("reserved_14")                       = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.reserved_14;
    m_outputs_map[ska_num].at("reserved_15")                       = m_ska_ccu_vh_riom_mvb2_dcu.at(ska_num).bits.reserved_15;


}
//all signal maps m_outputs_map[ska_num]["signal_name"] replaced with m_outputs_map[ska_num].at("signal_name")
