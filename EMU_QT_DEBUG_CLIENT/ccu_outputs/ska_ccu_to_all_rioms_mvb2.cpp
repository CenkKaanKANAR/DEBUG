#include "ska_ccu_to_all_rioms_mvb2.h"
#include <QDebug>

Ska_Ccu_To_All_Rioms_Mvb2::Ska_Ccu_To_All_Rioms_Mvb2(QObject *parent)
    : QObject{parent}
{
    init_table();
}

Ska_Ccu_To_All_Rioms_Mvb2::~Ska_Ccu_To_All_Rioms_Mvb2()
{
    delete m_tableWidget;
}

void Ska_Ccu_To_All_Rioms_Mvb2::set_data_struct(const QByteArray &output)
{
    if (output.size() == sizeof(m_ska_ccu_to_all_rioms_mvb2.bytes)) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        memcpy(m_ska_ccu_to_all_rioms_mvb2.bytes, output.constData(), sizeof(m_ska_ccu_to_all_rioms_mvb2.bytes));
        update_map();
        update_table();
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }
}

void Ska_Ccu_To_All_Rioms_Mvb2::init_table()
{
    m_outputs_map = {

    {"DriverID_Byte1",0},
        {"DriverID_Byte2",0},
        {"DriverID_Byte3",0},
        {"DriverID_Byte4",0},
        {"DriverID_Byte5",0},
        {"DriverID_Byte6",0},
        {"DriverID_Byte7",0},
        {"reserved_7",0},
        {"TrainID_Byte1",0},
        {"TrainID_Byte2",0},
        {"TrainID_Byte3",0},
        {"TrainID_Byte4",0},
        {"TrainID_Byte5",0},
        {"TrainID_Byte6",0},
        {"TrainID_Byte7",0},
        {"TrainID_Byte8",0},
        {"TrainID_Byte9",0},
        {"TrainID_Byte10",0},
        {"TrainID_Byte11",0},
        {"TrainID_Byte12",0},
        {"reserved_20",0},
        {"Distance_in_pulse",0},
        {"reserved_25",0},
        {"TCMS_TLCentrClose",0},
        {"TCMS_TLStandstill",0},
        {"TCMS_TLCentrOpen",0},
        {"TCMS_TLSuppEmergOp",0},
        {"TCMS_TIL",0},
        {"TCMS_LoopLSDoorNotEmergOp",0},
        {"bit214",0},
        {"bit215",0},
        {"reserved_27",0},
        {"HVAC_Offset",0},
        {"reserved_29",0},
        {"reserved_30",0},
    {"reserved_31",0}




};

QStringList table_name = {"ska_ccu_to_all_rioms_mvb2", "value"};

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

void Ska_Ccu_To_All_Rioms_Mvb2::update_table()
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

void Ska_Ccu_To_All_Rioms_Mvb2::update_map()
{

    m_outputs_map.at("DriverID_Byte1")               = m_ska_ccu_to_all_rioms_mvb2.bits.DriverID_Byte1;
    m_outputs_map.at("DriverID_Byte2")               = m_ska_ccu_to_all_rioms_mvb2.bits.DriverID_Byte2;
    m_outputs_map.at("DriverID_Byte3")               = m_ska_ccu_to_all_rioms_mvb2.bits.DriverID_Byte3;
    m_outputs_map.at("DriverID_Byte4")               = m_ska_ccu_to_all_rioms_mvb2.bits.DriverID_Byte4;
    m_outputs_map.at("DriverID_Byte5")               = m_ska_ccu_to_all_rioms_mvb2.bits.DriverID_Byte5;
    m_outputs_map.at("DriverID_Byte6")               = m_ska_ccu_to_all_rioms_mvb2.bits.DriverID_Byte6;
    m_outputs_map.at("DriverID_Byte7")               = m_ska_ccu_to_all_rioms_mvb2.bits.DriverID_Byte7;
    m_outputs_map.at("reserved_7")                   = m_ska_ccu_to_all_rioms_mvb2.bits.reserved_7;
    m_outputs_map.at("TrainID_Byte1")                = m_ska_ccu_to_all_rioms_mvb2.bits.TrainID_Byte1;
    m_outputs_map.at("TrainID_Byte2")                = m_ska_ccu_to_all_rioms_mvb2.bits.TrainID_Byte2;
    m_outputs_map.at("TrainID_Byte3")                = m_ska_ccu_to_all_rioms_mvb2.bits.TrainID_Byte3;
    m_outputs_map.at("TrainID_Byte4")                = m_ska_ccu_to_all_rioms_mvb2.bits.TrainID_Byte4;
    m_outputs_map.at("TrainID_Byte5")                = m_ska_ccu_to_all_rioms_mvb2.bits.TrainID_Byte5;
    m_outputs_map.at("TrainID_Byte6")                = m_ska_ccu_to_all_rioms_mvb2.bits.TrainID_Byte6;
    m_outputs_map.at("TrainID_Byte7")                = m_ska_ccu_to_all_rioms_mvb2.bits.TrainID_Byte7;
    m_outputs_map.at("TrainID_Byte8")                = m_ska_ccu_to_all_rioms_mvb2.bits.TrainID_Byte8;
    m_outputs_map.at("TrainID_Byte9")                = m_ska_ccu_to_all_rioms_mvb2.bits.TrainID_Byte9;
    m_outputs_map.at("TrainID_Byte10")               = m_ska_ccu_to_all_rioms_mvb2.bits.TrainID_Byte10;
    m_outputs_map.at("TrainID_Byte11")               = m_ska_ccu_to_all_rioms_mvb2.bits.TrainID_Byte11;
    m_outputs_map.at("TrainID_Byte12")               = m_ska_ccu_to_all_rioms_mvb2.bits.TrainID_Byte12;
    m_outputs_map.at("reserved_20")                  = m_ska_ccu_to_all_rioms_mvb2.bits.reserved_20;
    m_outputs_map.at("Distance_in_pulse")            = m_ska_ccu_to_all_rioms_mvb2.bits.Distance_in_pulse;
    m_outputs_map.at("reserved_25")                  = m_ska_ccu_to_all_rioms_mvb2.bits.reserved_25;
    m_outputs_map.at("TCMS_TLCentrClose")            = m_ska_ccu_to_all_rioms_mvb2.bits.TCMS_TLCentrClose;
    m_outputs_map.at("TCMS_TLStandstill")            = m_ska_ccu_to_all_rioms_mvb2.bits.TCMS_TLStandstill;
    m_outputs_map.at("TCMS_TLCentrOpen")             = m_ska_ccu_to_all_rioms_mvb2.bits.TCMS_TLCentrOpen;
    m_outputs_map.at("TCMS_TLSuppEmergOp")           = m_ska_ccu_to_all_rioms_mvb2.bits.TCMS_TLSuppEmergOp;
    m_outputs_map.at("TCMS_TIL")                     = m_ska_ccu_to_all_rioms_mvb2.bits.TCMS_TIL;
    m_outputs_map.at("TCMS_LoopLSDoorNotEmergOp")    = m_ska_ccu_to_all_rioms_mvb2.bits.TCMS_LoopLSDoorNotEmergOp;
    m_outputs_map.at("bit214")                       = m_ska_ccu_to_all_rioms_mvb2.bits.bit214;
    m_outputs_map.at("bit215")                       = m_ska_ccu_to_all_rioms_mvb2.bits.bit215;
    m_outputs_map.at("reserved_27")                  = m_ska_ccu_to_all_rioms_mvb2.bits.reserved_27;
    m_outputs_map.at("HVAC_Offset")                  = m_ska_ccu_to_all_rioms_mvb2.bits.HVAC_Offset;
    m_outputs_map.at("reserved_29")                  = m_ska_ccu_to_all_rioms_mvb2.bits.reserved_29;
    m_outputs_map.at("reserved_30")                  = m_ska_ccu_to_all_rioms_mvb2.bits.reserved_30;
    m_outputs_map.at("reserved_31")                  = m_ska_ccu_to_all_rioms_mvb2.bits.reserved_31;


}
