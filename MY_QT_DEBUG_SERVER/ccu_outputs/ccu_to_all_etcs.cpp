#include "ccu_to_all_etcs.h"
#include <QDebug>
Ccu_To_All_Etcs::Ccu_To_All_Etcs(QObject *parent)
    : QObject{parent}
{
     init_table();
}

Ccu_To_All_Etcs::~Ccu_To_All_Etcs()
{
    delete m_tableWidget;
}

void Ccu_To_All_Etcs::set_data_struct(const QByteArray &output)
{
    if (output.size() == sizeof(m_ccu_to_all_etcs.bytes)) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        memcpy(m_ccu_to_all_etcs.bytes, output.constData(), sizeof(m_ccu_to_all_etcs.bytes));
        update_map();
        update_table();
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }
}

void Ccu_To_All_Etcs::init_table()
{
    m_outputs_map = {
        {"Lifesign", 0},
        {"bit0", 0},
        {"bit1", 0},
        {"bit2", 0},
        {"bit3", 0},
        {"bit4", 0},
        {"bit5", 0},
        {"bit6", 0},
        {"bit7", 0},
        {"bit8", 0},
        {"bit9", 0},
        {"Train_data_Brake_Position", 0},
        {"bit14", 0},
        {"bit15", 0},
        {"reserved_4", 0},
        {"reserved_5", 0},
        {"TR_OBU_BrakePercentage", 0},
        {"reserved_7", 0},
        {"reserved_8", 0},
        {"TR_OBU_TrainLength", 0},
        {"TR_OBU_LoadingGauge", 0},
        {"TR_OBU_AxleLoadCat", 0},
        {"TR_OBU_TrainCatCantDef", 0},
        {"TR_OBU_TS_M_VOLTAGE", 0},
        {"TR_OBU_TS_NID_CTRACTION", 0},
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
        {"reserved_31", 0},
    };

    QStringList table_name = {"ccu_to_all_etcs", "value"};

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

void Ccu_To_All_Etcs::update_table()
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

void Ccu_To_All_Etcs::update_map()
{

    m_outputs_map.at("Lifesign")                   = m_ccu_to_all_etcs.bits.Lifesign;
    m_outputs_map.at("bit0")                       = m_ccu_to_all_etcs.bits.bit0;
    m_outputs_map.at("bit1")                       = m_ccu_to_all_etcs.bits.bit1;
    m_outputs_map.at("bit2")                       = m_ccu_to_all_etcs.bits.bit2;
    m_outputs_map.at("bit3")                       = m_ccu_to_all_etcs.bits.bit3;
    m_outputs_map.at("bit4")                       = m_ccu_to_all_etcs.bits.bit4;
    m_outputs_map.at("bit5")                       = m_ccu_to_all_etcs.bits.bit5;
    m_outputs_map.at("bit6")                       = m_ccu_to_all_etcs.bits.bit6;
    m_outputs_map.at("bit7")                       = m_ccu_to_all_etcs.bits.bit7;
    m_outputs_map.at("bit8")                       = m_ccu_to_all_etcs.bits.bit8;
    m_outputs_map.at("bit9")                       = m_ccu_to_all_etcs.bits.bit9;
    m_outputs_map.at("Train_data_Brake_Position")                 = m_ccu_to_all_etcs.bits.Train_data_Brake_Position;
    m_outputs_map.at("bit14")                                 = m_ccu_to_all_etcs.bits.bit14;
    m_outputs_map.at("bit15")                                 = m_ccu_to_all_etcs.bits.bit15;
    m_outputs_map.at("reserved_4")                            = m_ccu_to_all_etcs.bits.reserved_4;
    m_outputs_map.at("reserved_5")                            = m_ccu_to_all_etcs.bits.reserved_5;
    m_outputs_map.at("TR_OBU_BrakePercentage")                = m_ccu_to_all_etcs.bits.TR_OBU_BrakePercentage;
    m_outputs_map.at("reserved_7")                            = m_ccu_to_all_etcs.bits.reserved_7;
    m_outputs_map.at("reserved_8")                            = m_ccu_to_all_etcs.bits.reserved_8;
    m_outputs_map.at("TR_OBU_TrainLength")                    = m_ccu_to_all_etcs.bits.TR_OBU_TrainLength;
    m_outputs_map.at("TR_OBU_LoadingGauge")                   = m_ccu_to_all_etcs.bits.TR_OBU_LoadingGauge;
    m_outputs_map.at("TR_OBU_AxleLoadCat")                    = m_ccu_to_all_etcs.bits.TR_OBU_AxleLoadCat;
    m_outputs_map.at("TR_OBU_TrainCatCantDef")                = m_ccu_to_all_etcs.bits.TR_OBU_TrainCatCantDef;
    m_outputs_map.at("TR_OBU_TS_M_VOLTAGE")                    = m_ccu_to_all_etcs.bits.TR_OBU_TS_M_VOLTAGE;
    m_outputs_map.at("TR_OBU_TS_NID_CTRACTION")                = m_ccu_to_all_etcs.bits.TR_OBU_TS_NID_CTRACTION;
    m_outputs_map.at("reserved_17")                            = m_ccu_to_all_etcs.bits.reserved_17;
    m_outputs_map.at("reserved_18")                            = m_ccu_to_all_etcs.bits.reserved_18;
    m_outputs_map.at("reserved_19")                            = m_ccu_to_all_etcs.bits.reserved_19;
    m_outputs_map.at("reserved_20")                            = m_ccu_to_all_etcs.bits.reserved_20;
    m_outputs_map.at("reserved_21")                            = m_ccu_to_all_etcs.bits.reserved_21;
    m_outputs_map.at("reserved_22")                            = m_ccu_to_all_etcs.bits.reserved_22;
    m_outputs_map.at("reserved_23")                            = m_ccu_to_all_etcs.bits.reserved_23;
    m_outputs_map.at("reserved_24")                            = m_ccu_to_all_etcs.bits.reserved_24;
    m_outputs_map.at("reserved_25")                            = m_ccu_to_all_etcs.bits.reserved_25;
    m_outputs_map.at("reserved_26")                            = m_ccu_to_all_etcs.bits.reserved_26;
    m_outputs_map.at("reserved_27")                            = m_ccu_to_all_etcs.bits.reserved_27;
    m_outputs_map.at("reserved_28")                            = m_ccu_to_all_etcs.bits.reserved_28;
    m_outputs_map.at("reserved_29")                            = m_ccu_to_all_etcs.bits.reserved_29;
    m_outputs_map.at("reserved_30")                            = m_ccu_to_all_etcs.bits.reserved_30;
    m_outputs_map.at("reserved_31")                            = m_ccu_to_all_etcs.bits.reserved_31;
}
