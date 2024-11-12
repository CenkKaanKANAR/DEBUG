#include "ska_ccu_global_out_mvb2.h"
#include <QDebug>

Ska_Ccu_Global_Out_Mvb2::Ska_Ccu_Global_Out_Mvb2(QObject *parent)
    : QObject{parent}
{
    init_table();
}

Ska_Ccu_Global_Out_Mvb2::~Ska_Ccu_Global_Out_Mvb2()
{
    delete m_tableWidget;
}

void Ska_Ccu_Global_Out_Mvb2::set_data_struct(const QByteArray &output)
{
    if (output.size() == sizeof(m_ska_ccu_global_out_mvb2.bytes)) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        memcpy(m_ska_ccu_global_out_mvb2.bytes, output.constData(), sizeof(m_ska_ccu_global_out_mvb2.bytes));
        update_map();
        update_table();
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }
}

void Ska_Ccu_Global_Out_Mvb2::init_table()
{
    m_outputs_map = {
        {"lifesign", 0},
        {"GPS_latitude_masterTCMS", 0},
        {"GPS_longtitude_masterTCMS", 0},
        {"Outside_air_temperature", 0},
        {"Train_speed", 0},
        {"reserved_12", 0},
        {"reserved_13", 0},
        {"reserved_14", 0},
        {"reserved_15", 0}
    };
    QStringList table_name = {"ska_ccu_global_out_mvb2", "value"};

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
    m_tableWidget->resizeRowsToContents();
}

void Ska_Ccu_Global_Out_Mvb2::update_table()
{
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

void Ska_Ccu_Global_Out_Mvb2::update_map()
{
    m_outputs_map.at("lifesign")                   = m_ska_ccu_global_out_mvb2.bits.lifesign;
    m_outputs_map.at("GPS_latitude_masterTCMS")    = m_ska_ccu_global_out_mvb2.bits.GPS_latitude_masterTCMS;
    m_outputs_map.at("GPS_longtitude_masterTCMS")  = m_ska_ccu_global_out_mvb2.bits.GPS_longtitude_masterTCMS;
    m_outputs_map.at("Outside_air_temperature")    = m_ska_ccu_global_out_mvb2.bits.Outside_air_temperature;
    m_outputs_map.at("Train_speed")                = m_ska_ccu_global_out_mvb2.bits.Train_speed;
    m_outputs_map.at("reserved_12")                = m_ska_ccu_global_out_mvb2.bits.reserved_12;
    m_outputs_map.at("reserved_13")                = m_ska_ccu_global_out_mvb2.bits.reserved_13;
    m_outputs_map.at("reserved_14")                = m_ska_ccu_global_out_mvb2.bits.reserved_14;
    m_outputs_map.at("reserved_15")                = m_ska_ccu_global_out_mvb2.bits.reserved_15;
}
