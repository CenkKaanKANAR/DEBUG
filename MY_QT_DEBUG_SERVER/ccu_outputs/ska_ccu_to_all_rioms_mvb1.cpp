#include "ska_ccu_to_all_rioms_mvb1.h"
#include <QDebug>

Ska_Ccu_To_All_Rioms_Mvb1::Ska_Ccu_To_All_Rioms_Mvb1(QObject *parent)
    : QObject{parent}
{
    init_table();
}

Ska_Ccu_To_All_Rioms_Mvb1::~Ska_Ccu_To_All_Rioms_Mvb1()
{
    delete m_tableWidget;
}

void Ska_Ccu_To_All_Rioms_Mvb1::set_data_struct(const QByteArray &output)
{
    if (output.size() == sizeof(m_ska_ccu_to_all_rioms_mvb1.bytes)) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        memcpy(m_ska_ccu_to_all_rioms_mvb1.bytes, output.constData(), sizeof(m_ska_ccu_to_all_rioms_mvb1.bytes));
        update_map();
        update_table();
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }
}

void Ska_Ccu_To_All_Rioms_Mvb1::init_table()
{

    m_outputs_map = {

        {"Lifesign",0},
        {"Timestamp_Time",0},
        {"Timestamp_Date",0},
        {"GPS_latitude_masterTCMS",0},
        {"GPS_longtitude_masterTCMS",0},
        {"Coupling",0},
        {"Lead_follow",0},
        {"Cabin_active",0},
        {"Direction",0},
        {"Zero_speed",0},
        {"Doors_enabled_left_side",0},
        {"Doors_enabled_right_side",0},
        {"Doors_open_left_side",0},
        {"Doors_open_right_side",0},
        {"OA1_PantoUp",0},
        {"OA2_PantoUp",0},
        {"Parking_mode",0},
        {"Train_Speed",0},
        {"reserved_19",0},
        {"Outside_Temp",0},
        {"Inside_Temp",0},
        {"reserved_22",0},
        {"SKA1_DCU1_EEDOp",0},
        {"SKA1_DCU2_EEDOp",0},
        {"SKA1_DCU3_EEDOp",0},
        {"SKA1_DCU4_EEDOp",0},
        {"SKA1_DCU5_EEDOp",0},
        {"SKA1_DCU6_EEDOp",0},
        {"SKA1_DCU7_EEDOp",0},
        {"SKA1_DCU8_EEDOp",0},
        {"OA1_DCU1_EEDOp",0},
        {"OA1_DCU2_EEDOp",0},
        {"OA1_DCU3_EEDOp",0},
        {"OA1_DCU4_EEDOp",0},
        {"OA1_DCU5_EEDOp",0},
        {"OA1_DCU6_EEDOp",0},
        {"OA1_DCU7_EEDOp",0},
        {"OA1_DCU8_EEDOp",0},
        {"OA2_DCU1_EEDOp",0},
        {"OA2_DCU2_EEDOp",0},
        {"OA2_DCU3_EEDOp",0},
        {"OA2_DCU4_EEDOp",0},
        {"OA2_DCU5_EEDOp",0},
        {"OA2_DCU6_EEDOp",0},
        {"OA2_DCU7_EEDOp",0},
        {"OA2_DCU8_EEDOp",0},
        {"SKA2_DCU1_EEDOp",0},
        {"SKA2_DCU2_EEDOp",0},
        {"SKA2_DCU3_EEDOp",0},
        {"SKA2_DCU4_EEDOp",0},
        {"SKA2_DCU5_EEDOp",0},
        {"SKA2_DCU6_EEDOp",0},
        {"SKA2_DCU7_EEDOp",0},
        {"SKA2_DCU8_EEDOp",0},
        {"SKA1_Brake_Handle_1",0},
        {"SKA1_Brake_Handle_2",0},
        {"SKA1_Brake_Handle_3",0},
        {"SKA1_Brake_Handle_4",0},
        {"SKA1_Brake_Handle_5",0},
        {"SKA1_Brake_Handle_6",0},
        {"SKA1_Brake_Handle_7",0},
        {"SKA1_Brake_Handle_8",0},
        {"OA1_Brake_Handle_1",0},
        {"OA1_Brake_Handle_2",0},
        {"OA1_Brake_Handle_3",0},
        {"OA1_Brake_Handle_4",0},
        {"OA1_Brake_Handle_5",0},
        {"OA1_Brake_Handle_6",0},
        {"OA1_Brake_Handle_7",0},
        {"OA1_Brake_Handle_8",0},
        {"OA2_Brake_Handle_1",0},
        {"OA2_Brake_Handle_2",0},
        {"OA2_Brake_Handle_3",0},
        {"OA2_Brake_Handle_4",0},
        {"OA2_Brake_Handle_5",0},
        {"OA2_Brake_Handle_6",0},
        {"OA2_Brake_Handle_7",0},
        {"OA2_Brake_Handle_8",0},
        {"SKA2_Brake_Handle_1",0},
        {"SKA2_Brake_Handle_2",0},
        {"SKA2_Brake_Handle_3",0},
        {"SKA2_Brake_Handle_4",0},
        {"SKA2_Brake_Handle_5",0},
        {"SKA2_Brake_Handle_6",0},
        {"SKA2_Brake_Handle_7",0},
        {"SKA2_Brake_Handle_8",0},
        {"reserved_31",0}


    };

    QStringList table_name = {"m_ska_ccu_to_all_rioms_mvb1", "value"};

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

void Ska_Ccu_To_All_Rioms_Mvb1::update_table()
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

void Ska_Ccu_To_All_Rioms_Mvb1::update_map()
{


    m_outputs_map.at("Lifesign")          = m_ska_ccu_to_all_rioms_mvb1.bits.Lifesign;
    m_outputs_map.at("Timestamp_Time")          = m_ska_ccu_to_all_rioms_mvb1.bits.Timestamp_Time;
    m_outputs_map.at("Timestamp_Date")          = m_ska_ccu_to_all_rioms_mvb1.bits.Timestamp_Date;
    m_outputs_map.at("GPS_latitude_masterTCMS")          = m_ska_ccu_to_all_rioms_mvb1.bits.GPS_latitude_masterTCMS;
    m_outputs_map.at("GPS_longtitude_masterTCMS")          = m_ska_ccu_to_all_rioms_mvb1.bits.GPS_longtitude_masterTCMS;
    m_outputs_map.at("Coupling")          = m_ska_ccu_to_all_rioms_mvb1.bits.Coupling;
    m_outputs_map.at("Lead_follow")          = m_ska_ccu_to_all_rioms_mvb1.bits.Lead_follow;
    m_outputs_map.at("Cabin_active")          = m_ska_ccu_to_all_rioms_mvb1.bits.Cabin_active;
    m_outputs_map.at("Direction")          = m_ska_ccu_to_all_rioms_mvb1.bits.Direction;
    m_outputs_map.at("Zero_speed")          = m_ska_ccu_to_all_rioms_mvb1.bits.Zero_speed;
    m_outputs_map.at("Doors_enabled_left_side")          = m_ska_ccu_to_all_rioms_mvb1.bits.Doors_enabled_left_side;
    m_outputs_map.at("Doors_enabled_right_side")          = m_ska_ccu_to_all_rioms_mvb1.bits.Doors_enabled_right_side;
    m_outputs_map.at("Doors_open_left_side")          = m_ska_ccu_to_all_rioms_mvb1.bits.Doors_open_left_side;
    m_outputs_map.at("Doors_open_right_side")          = m_ska_ccu_to_all_rioms_mvb1.bits.Doors_open_right_side;
    m_outputs_map.at("OA1_PantoUp")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA1_PantoUp;
    m_outputs_map.at("OA2_PantoUp")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA2_PantoUp;
    m_outputs_map.at("Parking_mode")          = m_ska_ccu_to_all_rioms_mvb1.bits.Parking_mode;
    m_outputs_map.at("Train_Speed")          = m_ska_ccu_to_all_rioms_mvb1.bits.Train_Speed;
    m_outputs_map.at("reserved_19")          = m_ska_ccu_to_all_rioms_mvb1.bits.reserved_19;
    m_outputs_map.at("Outside_Temp")          = m_ska_ccu_to_all_rioms_mvb1.bits.Outside_Temp;
    m_outputs_map.at("Inside_Temp")          = m_ska_ccu_to_all_rioms_mvb1.bits.Inside_Temp;
    m_outputs_map.at("reserved_22")          = m_ska_ccu_to_all_rioms_mvb1.bits.reserved_22;
    m_outputs_map.at("SKA1_DCU1_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA1_DCU1_EEDOp;
    m_outputs_map.at("SKA1_DCU2_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA1_DCU2_EEDOp;
    m_outputs_map.at("SKA1_DCU3_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA1_DCU3_EEDOp;
    m_outputs_map.at("SKA1_DCU4_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA1_DCU4_EEDOp;
    m_outputs_map.at("SKA1_DCU5_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA1_DCU5_EEDOp;
    m_outputs_map.at("SKA1_DCU6_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA1_DCU6_EEDOp;
    m_outputs_map.at("SKA1_DCU7_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA1_DCU7_EEDOp;
    m_outputs_map.at("SKA1_DCU8_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA1_DCU8_EEDOp;
    m_outputs_map.at("OA1_DCU1_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA1_DCU1_EEDOp;
    m_outputs_map.at("OA1_DCU2_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA1_DCU2_EEDOp;
    m_outputs_map.at("OA1_DCU3_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA1_DCU3_EEDOp;
    m_outputs_map.at("OA1_DCU4_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA1_DCU4_EEDOp;
    m_outputs_map.at("OA1_DCU5_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA1_DCU5_EEDOp;
    m_outputs_map.at("OA1_DCU6_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA1_DCU6_EEDOp;
    m_outputs_map.at("OA1_DCU7_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA1_DCU7_EEDOp;
    m_outputs_map.at("OA1_DCU8_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA1_DCU8_EEDOp;
    m_outputs_map.at("OA2_DCU1_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA2_DCU1_EEDOp;
    m_outputs_map.at("OA2_DCU2_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA2_DCU2_EEDOp;
    m_outputs_map.at("OA2_DCU3_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA2_DCU3_EEDOp;
    m_outputs_map.at("OA2_DCU4_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA2_DCU4_EEDOp;
    m_outputs_map.at("OA2_DCU5_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA2_DCU5_EEDOp;
    m_outputs_map.at("OA2_DCU6_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA2_DCU6_EEDOp;
    m_outputs_map.at("OA2_DCU7_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA2_DCU7_EEDOp;
    m_outputs_map.at("OA2_DCU8_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA2_DCU8_EEDOp;
    m_outputs_map.at("SKA2_DCU1_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA2_DCU1_EEDOp;
    m_outputs_map.at("SKA2_DCU2_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA2_DCU2_EEDOp;
    m_outputs_map.at("SKA2_DCU3_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA2_DCU3_EEDOp;
    m_outputs_map.at("SKA2_DCU4_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA2_DCU4_EEDOp;
    m_outputs_map.at("SKA2_DCU5_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA2_DCU5_EEDOp;
    m_outputs_map.at("SKA2_DCU6_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA2_DCU6_EEDOp;
    m_outputs_map.at("SKA2_DCU7_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA2_DCU7_EEDOp;
    m_outputs_map.at("SKA2_DCU8_EEDOp")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA2_DCU8_EEDOp;
    m_outputs_map.at("SKA1_Brake_Handle_1")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA1_Brake_Handle_1;
    m_outputs_map.at("SKA1_Brake_Handle_2")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA1_Brake_Handle_2;
    m_outputs_map.at("SKA1_Brake_Handle_3")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA1_Brake_Handle_3;
    m_outputs_map.at("SKA1_Brake_Handle_4")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA1_Brake_Handle_4;
    m_outputs_map.at("SKA1_Brake_Handle_5")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA1_Brake_Handle_5;
    m_outputs_map.at("SKA1_Brake_Handle_6")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA1_Brake_Handle_6;
    m_outputs_map.at("SKA1_Brake_Handle_7")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA1_Brake_Handle_7;
    m_outputs_map.at("SKA1_Brake_Handle_8")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA1_Brake_Handle_8;
    m_outputs_map.at("OA1_Brake_Handle_1")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA1_Brake_Handle_1;
    m_outputs_map.at("OA1_Brake_Handle_2")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA1_Brake_Handle_2;
    m_outputs_map.at("OA1_Brake_Handle_3")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA1_Brake_Handle_3;
    m_outputs_map.at("OA1_Brake_Handle_4")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA1_Brake_Handle_4;
    m_outputs_map.at("OA1_Brake_Handle_5")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA1_Brake_Handle_5;
    m_outputs_map.at("OA1_Brake_Handle_6")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA1_Brake_Handle_6;
    m_outputs_map.at("OA1_Brake_Handle_7")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA1_Brake_Handle_7;
    m_outputs_map.at("OA1_Brake_Handle_8")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA1_Brake_Handle_8;
    m_outputs_map.at("OA2_Brake_Handle_1")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA2_Brake_Handle_1;
    m_outputs_map.at("OA2_Brake_Handle_2")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA2_Brake_Handle_2;
    m_outputs_map.at("OA2_Brake_Handle_3")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA2_Brake_Handle_3;
    m_outputs_map.at("OA2_Brake_Handle_4")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA2_Brake_Handle_4;
    m_outputs_map.at("OA2_Brake_Handle_5")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA2_Brake_Handle_5;
    m_outputs_map.at("OA2_Brake_Handle_6")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA2_Brake_Handle_6;
    m_outputs_map.at("OA2_Brake_Handle_7")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA2_Brake_Handle_7;
    m_outputs_map.at("OA2_Brake_Handle_8")          = m_ska_ccu_to_all_rioms_mvb1.bits.OA2_Brake_Handle_8;
    m_outputs_map.at("SKA2_Brake_Handle_1")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA2_Brake_Handle_1;
    m_outputs_map.at("SKA2_Brake_Handle_2")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA2_Brake_Handle_2;
    m_outputs_map.at("SKA2_Brake_Handle_3")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA2_Brake_Handle_3;
    m_outputs_map.at("SKA2_Brake_Handle_4")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA2_Brake_Handle_4;
    m_outputs_map.at("SKA2_Brake_Handle_5")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA2_Brake_Handle_5;
    m_outputs_map.at("SKA2_Brake_Handle_6")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA2_Brake_Handle_6;
    m_outputs_map.at("SKA2_Brake_Handle_7")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA2_Brake_Handle_7;
    m_outputs_map.at("SKA2_Brake_Handle_8")          = m_ska_ccu_to_all_rioms_mvb1.bits.SKA2_Brake_Handle_8;
    m_outputs_map.at("reserved31")          = m_ska_ccu_to_all_rioms_mvb1.bits.reserved_31;

}

