#include "ccu_to_oax_etcs.h"
#include <QDebug>

Ccu_To_Oax_Etcs::Ccu_To_Oax_Etcs(QObject *parent)
    : QObject{parent}
{
    init_oa1_table();
    init_oa2_table();
}

Ccu_To_Oax_Etcs::~Ccu_To_Oax_Etcs()
{
    for (auto tableWidget : m_tableWidget) {
        delete tableWidget;
    }
}

void Ccu_To_Oax_Etcs::set_data_struct(const QByteArray &output, const OA_VEHICLE_NUM &oa_x_num)
{
    int ska_num = static_cast<int>(oa_x_num);
    if (output.size() == sizeof(m_ccu_to_oax_etcs[ska_num].bytes)) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        memcpy(m_ccu_to_oax_etcs[ska_num].bytes, output.constData(), sizeof(m_ccu_to_oax_etcs[ska_num].bytes));
        update_map(oa_x_num);
        update_table(oa_x_num);
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }
}

void Ccu_To_Oax_Etcs::init_oa1_table()
{
    m_outputs_map[get_index(OA_VEHICLE_NUM::OA1)] = {
         {"Lifesign", 0},
         {"bit0", 0},
         {"bit1", 0},
         {"bit2", 0},
         {"bit3", 0},
         {"bit4", 0},
         {"bit5", 0},
         {"bit6", 0},
         {"bit7", 0},
         {"TR_OBU_TrainSleep", 0},
         {"TR_OBU_TrainSleep_Not", 0},
         {"bit10", 0},
         {"TR_OBU_NLEnabled", 0},
         {"TR_OBU_DirectionFW", 0},
         {"TR_OBU_DirectionBW", 0},
         {"TR_OBU_CabStatusA", 0},
         {"TR_OBU_CabStatusB", 0},
         {"bit16", 0},
         {"bit17", 0},
         {"TR_OBU_Train_Integrity", 0},
         {"bit19",0},
         {"TR_OBU_Traction_Status", 0},
         {"TR_OBU_AirTightFitted", 0},
         {"bit22", 0},
         {"bit23", 0},
         {"reserved_5", 0},
         {"reserved_6", 0},
         {"Brake_status_EP_S", 0},
         {"Brake_status_EP_S_Not", 0},
         {"bit24", 0},
         {"bit25", 0},
         {"Brake_status_RP_S", 0},
         {"Brake_status_RP_S_Not", 0},
         {"bit26", 0},
         {"bit27", 0},
         {"reserved_8", 0},
         {"reserved_9_10", 0},
         {"TR_OBU_Train_Control_0", 0},
         {"TR_OBU_Train_Control_1", 0},
         {"TR_OBU_Train_Control_2", 0},
         {"TR_OBU_Train_Control_3", 0},
         {"bit28", 0},
         {"bit29", 0},
         {"bit30", 0},
         {"bit31", 0},
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
         {"reserved_31", 0},
        };
    QStringList table_name = {"ccu_to_oa1_etcs", "value"};

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

void Ccu_To_Oax_Etcs::init_oa2_table()
{
    // Copy Assignment Operator
    m_outputs_map[get_index(OA_VEHICLE_NUM::OA2)] =  m_outputs_map[get_index(OA_VEHICLE_NUM::OA1)];
    QStringList table_name = {"ccu_to_oa2_etcs", "value"};

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

void Ccu_To_Oax_Etcs::update_table(OA_VEHICLE_NUM oa_x_num)
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

void Ccu_To_Oax_Etcs::update_map(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);

    m_outputs_map[oa_num].at("Lifesign") = m_ccu_to_oax_etcs.at(oa_num).bits.Lifesign;
    m_outputs_map[oa_num].at("bit0")      = m_ccu_to_oax_etcs.at(oa_num).bits.bit0;
    m_outputs_map[oa_num].at("bit1")      = m_ccu_to_oax_etcs.at(oa_num).bits.bit1;
    m_outputs_map[oa_num].at("bit2")      = m_ccu_to_oax_etcs.at(oa_num).bits.bit2;
    m_outputs_map[oa_num].at("bit3")      = m_ccu_to_oax_etcs.at(oa_num).bits.bit3;
    m_outputs_map[oa_num].at("bit4")      = m_ccu_to_oax_etcs.at(oa_num).bits.bit4;
    m_outputs_map[oa_num].at("bit5")      = m_ccu_to_oax_etcs.at(oa_num).bits.bit5;
    m_outputs_map[oa_num].at("bit6")      = m_ccu_to_oax_etcs.at(oa_num).bits.bit6;
    m_outputs_map[oa_num].at("bit7")      = m_ccu_to_oax_etcs.at(oa_num).bits.bit7;
    m_outputs_map[oa_num].at("TR_OBU_TrainSleep")     = m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_TrainSleep;
    m_outputs_map[oa_num].at("TR_OBU_TrainSleep_Not") = m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_TrainSleep_Not;
    m_outputs_map[oa_num].at("bit10")                 = m_ccu_to_oax_etcs.at(oa_num).bits.bit10;
    m_outputs_map[oa_num].at("TR_OBU_NLEnabled")      = m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_NLEnabled;
    m_outputs_map[oa_num].at("TR_OBU_DirectionFW")    = m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_DirectionFW;
    m_outputs_map[oa_num].at("TR_OBU_DirectionBW")    = m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_DirectionBW;
    m_outputs_map[oa_num].at("TR_OBU_CabStatusA")     = m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_CabStatusA;
    m_outputs_map[oa_num].at("TR_OBU_CabStatusB")     = m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_CabStatusB;
    m_outputs_map[oa_num].at("bit16")                 = m_ccu_to_oax_etcs.at(oa_num).bits.bit16;
    m_outputs_map[oa_num].at("bit17")                 = m_ccu_to_oax_etcs.at(oa_num).bits.bit17;
    m_outputs_map[oa_num].at("TR_OBU_Train_Integrity")= m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_Train_Integrity;
    m_outputs_map[oa_num].at("bit19")                 = m_ccu_to_oax_etcs.at(oa_num).bits.bit19;
    m_outputs_map[oa_num].at("TR_OBU_Traction_Status")= m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_Traction_Status;
    m_outputs_map[oa_num].at("TR_OBU_AirTightFitted") = m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_AirTightFitted;
    m_outputs_map[oa_num].at("bit22")                 = m_ccu_to_oax_etcs.at(oa_num).bits.bit22;
    m_outputs_map[oa_num].at("bit23")                 = m_ccu_to_oax_etcs.at(oa_num).bits.bit23;
    m_outputs_map[oa_num].at("reserved_5")            = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_5;
    m_outputs_map[oa_num].at("reserved_6")            = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_6;
    m_outputs_map[oa_num].at("Brake_status_EP_S")     = m_ccu_to_oax_etcs.at(oa_num).bits.Brake_status_EP_S;
    m_outputs_map[oa_num].at("Brake_status_EP_S_Not") = m_ccu_to_oax_etcs.at(oa_num).bits.Brake_status_EP_S_Not;
    m_outputs_map[oa_num].at("bit24")                 = m_ccu_to_oax_etcs.at(oa_num).bits.bit24;
    m_outputs_map[oa_num].at("bit25")                 = m_ccu_to_oax_etcs.at(oa_num).bits.bit25;
    m_outputs_map[oa_num].at("Brake_status_RP_S")     = m_ccu_to_oax_etcs.at(oa_num).bits.Brake_status_RP_S;
    m_outputs_map[oa_num].at("Brake_status_RP_S_Not") = m_ccu_to_oax_etcs.at(oa_num).bits.Brake_status_RP_S_Not;
    m_outputs_map[oa_num].at("bit26")                 = m_ccu_to_oax_etcs.at(oa_num).bits.bit26;
    m_outputs_map[oa_num].at("bit27")                 = m_ccu_to_oax_etcs.at(oa_num).bits.bit27;
    m_outputs_map[oa_num].at("reserved_8")            = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_8;
    m_outputs_map[oa_num].at("reserved_9_10")         = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_9_10;
    m_outputs_map[oa_num].at("TR_OBU_Train_Control_0")= m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_Train_Control_0;
    m_outputs_map[oa_num].at("TR_OBU_Train_Control_1")= m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_Train_Control_1;
    m_outputs_map[oa_num].at("TR_OBU_Train_Control_2")= m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_Train_Control_2;
    m_outputs_map[oa_num].at("TR_OBU_Train_Control_3")= m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_Train_Control_3;
    m_outputs_map[oa_num].at("bit28")                 = m_ccu_to_oax_etcs.at(oa_num).bits.bit28;
    m_outputs_map[oa_num].at("bit29")                 = m_ccu_to_oax_etcs.at(oa_num).bits.bit29;
    m_outputs_map[oa_num].at("bit30")                 = m_ccu_to_oax_etcs.at(oa_num).bits.bit30;
    m_outputs_map[oa_num].at("bit31")                 = m_ccu_to_oax_etcs.at(oa_num).bits.bit31;
    m_outputs_map[oa_num].at("reserved_12")           = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_12;
    m_outputs_map[oa_num].at("reserved_13")           = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_13;
    m_outputs_map[oa_num].at("reserved_14")           = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_14;
    m_outputs_map[oa_num].at("reserved_15")           = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_15;
    m_outputs_map[oa_num].at("reserved_16")           = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_16;
    m_outputs_map[oa_num].at("reserved_17")           = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_17;
    m_outputs_map[oa_num].at("reserved_18")           = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_18;
    m_outputs_map[oa_num].at("reserved_19")           = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_19;
    m_outputs_map[oa_num].at("reserved_20")           = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_20;
    m_outputs_map[oa_num].at("reserved_21")           = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_21;
    m_outputs_map[oa_num].at("reserved_22")           = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_22;
    m_outputs_map[oa_num].at("reserved_23")           = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_23;
    m_outputs_map[oa_num].at("reserved_24")           = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_24;
    m_outputs_map[oa_num].at("reserved_25")           = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_25;
    m_outputs_map[oa_num].at("reserved_26")           = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_26;
    m_outputs_map[oa_num].at("reserved_27")           = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_27;
    m_outputs_map[oa_num].at("reserved_28")           = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_28;
    m_outputs_map[oa_num].at("reserved_29")           = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_29;
    m_outputs_map[oa_num].at("reserved_30")           = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_30;
    m_outputs_map[oa_num].at("reserved_31")           = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_31;
}
