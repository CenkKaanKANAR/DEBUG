#include "ccu_to_all_bcus.h"
#include <QDebug>

Ccu_To_All_Bcus::Ccu_To_All_Bcus(QObject *parent)
    : QObject{parent}
{
    init_table();
}

Ccu_To_All_Bcus::~Ccu_To_All_Bcus()
{
    delete m_tableWidget;
}

void Ccu_To_All_Bcus::set_data_struct(const QByteArray &output)
{

    if (output.size() == sizeof(m_ccu_to_all_bcus.bytes)) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        memcpy(m_ccu_to_all_bcus.bytes, output.constData(), sizeof(m_ccu_to_all_bcus.bytes));
        update_map();
        update_table();
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }
}

void Ccu_To_All_Bcus::init_table()
{
    m_outputs_map = {

        {"XLifeSign",0},
        {"ReleaseHoldingBrakeRequest",0},
        {"bit17",0},
        {"bit18",0},
        {"C_WSP_start_testrun",0},
        {"bit20",0},
        {"C_ASC_active",0},
        {"C_CalcMass",0},
        {"bit23",0},
        {"C_Sanding_activated",0},
        {"C_Sanding_Request_Short",0},
        {"C_Sanding_Request_Long",0},
        {"C_Sanding_Test",0},
        {"C_Sanding_drying_on",0},
        {"bit29",0},
        {"bit30",0},
        {"bit31",0},
        {"TL_EBLoop_R_Closed",0},
        {"bit33",0},
        {"TL_Braking_Bit1",0},
        {"TL_Braking_Bit2",0},
        {"TL_Braking_Bit3",0},
        {"TL_Traction",0},
        {"bit38",0},
        {"bit39",0},
        {"reserved_5",0},
        {"S_PB_EmerRel_Conf_SKA1",0},
        {"S_PB_EmerRel_Conf_SKA2",0},
        {"S_PB_EmerRel_Conf_OA1",0},
        {"S_PB_EmerRel_Conf_OA2",0},
        {"bit52",0},
        {"bit53",0},
        {"bit54",0},
        {"bit55",0},
        {"C_ASC_Brake_demand_SKA1",0},
        {"C_ASC_Brake_demand_OA1",0},
        {"C_ASC_Brake_demand_OA2",0},
        {"C_ASC_Brake_demand_SKA2",0},
        {"reserved_15",0}

        };

    QStringList table_name = {"ccu_to_all_bcus", "value"};

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

void Ccu_To_All_Bcus::update_table()
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

void Ccu_To_All_Bcus::update_map()
{
    m_outputs_map.at("XLifeSign")                     = m_ccu_to_all_bcus.bits.XLifeSign;
    m_outputs_map.at("ReleaseHoldingBrakeRequest")                     = m_ccu_to_all_bcus.bits.ReleaseHoldingBrakeRequest;
    m_outputs_map.at("bit17")                     = m_ccu_to_all_bcus.bits.bit17;
    m_outputs_map.at("bit18")                     = m_ccu_to_all_bcus.bits.bit18;
    m_outputs_map.at("C_WSP_start_testrun")                     = m_ccu_to_all_bcus.bits.C_WSP_start_testrun;
    m_outputs_map.at("bit20")                     = m_ccu_to_all_bcus.bits.bit20;
    m_outputs_map.at("C_ASC_active")                     = m_ccu_to_all_bcus.bits.C_ASC_active;
    m_outputs_map.at("C_CalcMass")                     = m_ccu_to_all_bcus.bits.C_CalcMass;
    m_outputs_map.at("bit23")                     = m_ccu_to_all_bcus.bits.bit23;
    m_outputs_map.at("C_Sanding_activated")                     = m_ccu_to_all_bcus.bits.C_Sanding_activated;
    m_outputs_map.at("C_Sanding_Request_Short")                     = m_ccu_to_all_bcus.bits.C_Sanding_Request_Short;
    m_outputs_map.at("C_Sanding_Request_Long")                     = m_ccu_to_all_bcus.bits.C_Sanding_Request_Long;
    m_outputs_map.at("C_Sanding_Test")                     = m_ccu_to_all_bcus.bits.C_Sanding_Test;
    m_outputs_map.at("C_Sanding_drying_on")                     = m_ccu_to_all_bcus.bits.C_Sanding_drying_on;
    m_outputs_map.at("bit29")                     = m_ccu_to_all_bcus.bits.bit29;
    m_outputs_map.at("bit30")                     = m_ccu_to_all_bcus.bits.bit30;
    m_outputs_map.at("bit31")                     = m_ccu_to_all_bcus.bits.bit31;
    m_outputs_map.at("TL_EBLoop_R_Closed")                     = m_ccu_to_all_bcus.bits.TL_EBLoop_R_Closed;
    m_outputs_map.at("bit33")                     = m_ccu_to_all_bcus.bits.bit33;
    m_outputs_map.at("TL_Braking_Bit1")                     = m_ccu_to_all_bcus.bits.TL_Braking_Bit1;
    m_outputs_map.at("TL_Braking_Bit2")                     = m_ccu_to_all_bcus.bits.TL_Braking_Bit2;
    m_outputs_map.at("TL_Braking_Bit3")                     = m_ccu_to_all_bcus.bits.TL_Braking_Bit3;
    m_outputs_map.at("TL_Traction")                     = m_ccu_to_all_bcus.bits.TL_Traction;
    m_outputs_map.at("bit38")                     = m_ccu_to_all_bcus.bits.bit38;
    m_outputs_map.at("bit39")                     = m_ccu_to_all_bcus.bits.bit39;
    m_outputs_map.at("reserved_5")                     = m_ccu_to_all_bcus.bits.reserved_5;
    m_outputs_map.at("S_PB_EmerRel_Conf_SKA1")                     = m_ccu_to_all_bcus.bits.S_PB_EmerRel_Conf_SKA1;
    m_outputs_map.at("S_PB_EmerRel_Conf_SKA2")                     = m_ccu_to_all_bcus.bits.S_PB_EmerRel_Conf_SKA2;
    m_outputs_map.at("S_PB_EmerRel_Conf_OA1")                     = m_ccu_to_all_bcus.bits.S_PB_EmerRel_Conf_OA1;
    m_outputs_map.at("S_PB_EmerRel_Conf_OA2")                     = m_ccu_to_all_bcus.bits.S_PB_EmerRel_Conf_OA2;
    m_outputs_map.at("bit52")                     = m_ccu_to_all_bcus.bits.bit52;
    m_outputs_map.at("bit53")                     = m_ccu_to_all_bcus.bits.bit53;
    m_outputs_map.at("bit54")                     = m_ccu_to_all_bcus.bits.bit54;
    m_outputs_map.at("bit55")                     = m_ccu_to_all_bcus.bits.bit55;
    m_outputs_map.at("C_ASC_Brake_demand_SKA1")                     = m_ccu_to_all_bcus.bits.C_ASC_Brake_demand_SKA1;
    m_outputs_map.at("C_ASC_Brake_demand_OA1")                     = m_ccu_to_all_bcus.bits.C_ASC_Brake_demand_OA1;
    m_outputs_map.at("C_ASC_Brake_demand_OA2")                     = m_ccu_to_all_bcus.bits.C_ASC_Brake_demand_OA2;
    m_outputs_map.at("C_ASC_Brake_demand_SKA2")                     = m_ccu_to_all_bcus.bits.C_ASC_Brake_demand_SKA2;
    m_outputs_map.at("reserved_15")                     = m_ccu_to_all_bcus.bits.reserved_15;


}
