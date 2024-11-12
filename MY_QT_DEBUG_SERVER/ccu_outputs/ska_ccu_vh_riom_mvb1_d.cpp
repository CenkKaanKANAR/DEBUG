#include <QTableWidget>
#include <QDebug>

#include "ccu_outputs/ska_ccu_vh_riom_mvb1_d.h"
Ska_ccu_vh_riom_mvb1_d::Ska_ccu_vh_riom_mvb1_d(QObject *parent)
    : QObject{parent}

{
    //memset(m_ska_ccu_vh_riom_mvb1_d_outputs, 0, sizeof(*m_ska_ccu_vh_riom_mvb1_d_outputs));
    init_ska1_table();
    init_ska2_table();
}

Ska_ccu_vh_riom_mvb1_d::~Ska_ccu_vh_riom_mvb1_d()
{
    qDebug() << "Ska_ccu_vh_riom_mvb1_d dustrcutor";

    for (auto tableWidget : m_tableWidget) {
        delete tableWidget;
    }
}

void Ska_ccu_vh_riom_mvb1_d::set_data_struct(const QByteArray& output, const SKA_VEHICLE_NUM& ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    if (output.size() == sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs[ska_num].bytes)) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
       memcpy(m_ska_ccu_vh_riom_mvb1_d_outputs[ska_num].bytes, output.constData(), sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs[ska_num].bytes));
       update_map(ska_x_num);
       update_table(ska_x_num);
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }

}

void Ska_ccu_vh_riom_mvb1_d::show_table_widget_contents()
{
/*
    for(int i= 0; i< m_tableWidget[SKA1]->rowCount(); i++)
    {
        qDebug() << "Table name:" << utils::get_table_item_name(m_tableWidget[SKA1], i) << "Table val:" << utils::get_table_item(m_tableWidget[SKA1], i);

    }
*/
}



void Ska_ccu_vh_riom_mvb1_d::init_ska1_table()
{
    //int index = static_cast<int>(indx);
    m_outputs_map[get_index(SKA_VEHICLE_NUM::SKA1)] = {
        {"CONTACTOR_MAINTENANCE_COMMAND", 0},
        {"ENABLE_TC_1", 0},
        {"ENABLE_TC_2", 0},
        {"IDRELAY_1", 0},
        {"IDRELAY_2", 0},
        {"bit5", 0},
        {"bit6", 0},
        {"CABINET_TEST_HW_HEALT_RIOM_1", 0},
        {"NORMAL_RESCUE_MODE", 0},
        {"SPEED_LIMIT", 0},
        {"TRACTION_NULL", 0},
        {"bit11", 0},
        {"bit12", 0},
        {"bit13", 0},
        {"bit14", 0},
        {"bit15", 0},
        {"CAB_MODE", 0},
        {"HVAC_1_ON_OFF", 0},
        {"HVAC_1_FAILURE", 0},
        {"bit19", 0},
        {"bit20", 0},
        {"bit21", 0},
        {"bit22", 0},
        {"bit23", 0},
        {"HVAC_2_ON_OFF", 0},
        {"HVAC_2_FAILURE", 0},
        {"TL_HB_C_RELEASE", 0},
        {"bit27", 0},
        {"bit28", 0},
        {"bit29", 0},
        {"bit30", 0},
        {"bit31", 0},
        {"MRP_ISOLATION_COMMAND", 0},
        {"PASSENGERS_ALARM_OUT_OF_SERVICE", 0},
        {"HEATING_CARTRIGE_HEATER", 0},
        {"bit35", 0},
        {"bit36", 0},
        {"bit37", 0},
        {"bit38", 0},
        {"bit39", 0},
        {"HEATING_SAND_TUBE", 0},
        {"TEST_SAND_LEVELS_SENSORS_BOGIE_1", 0},
        {"TEST_SAND_LEVELS_SENSORS_BOGIE_2", 0},
        {"bit43", 0},
        {"bit44", 0},
        {"bit45", 0},
        {"bit46", 0},
        {"bit47", 0},
        {"LIGHT_OFF_COMMAND", 0},
        {"LIGHT_COMMAND_FULL_LIGHT", 0},
        {"HALF_LIGHT_COMMAND", 0},
        {"EMERGENCY_LIGHT_COMMAND", 0},
        {"bit52", 0},
        {"bit53", 0},
        {"bit54", 0},
        {"bit55", 0},
        {"reserved_7", 0},
        {"reserved_8", 0},
        {"reserved_9", 0},
        {"reserved_10", 0},
        {"reserved_11", 0},
        {"reserved_12", 0},
        {"reserved_13", 0},
        {"reserved_14", 0},
        {"reserved_15", 0}
    };

    QStringList table_name = {"ska_1_ccu_vh_riom_mvb1_d", "value"};

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

void Ska_ccu_vh_riom_mvb1_d::init_ska2_table()
{
    m_outputs_map[get_index(SKA_VEHICLE_NUM::SKA2)] =  m_outputs_map[get_index(SKA_VEHICLE_NUM::SKA1)];
    QStringList table_name = {"ska_2_ccu_vh_riom_mvb1_d", "value"};

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

void Ska_ccu_vh_riom_mvb1_d::update_table(SKA_VEHICLE_NUM ska_x_num)
{

    //qDebug() << "table updated";
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

void Ska_ccu_vh_riom_mvb1_d::update_map(SKA_VEHICLE_NUM ska_x_num)
{
    //qDebug() << "map updated";
    int ska_num = static_cast<int>(ska_x_num);


    m_outputs_map[ska_num].at("CONTACTOR_MAINTENANCE_COMMAND")      = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.CONTACTOR_MAINTENANCE_COMMAND;
    m_outputs_map[ska_num].at("ENABLE_TC_1")                        = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.ENABLE_TC_1;
    m_outputs_map[ska_num].at("ENABLE_TC_2")                        = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.ENABLE_TC_2;
    m_outputs_map[ska_num].at("IDRELAY_1")                          = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.IDRELAY_1;
    m_outputs_map[ska_num].at("IDRELAY_2")                          = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.IDRELAY_2;
    m_outputs_map[ska_num].at("bit5")                               = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit5;
    m_outputs_map[ska_num].at("bit6")                               = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit6;
    m_outputs_map[ska_num].at("CABINET_TEST_HW_HEALT_RIOM_1")       = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.CABINET_TEST_HW_HEALT_RIOM_1;
    m_outputs_map[ska_num].at("NORMAL_RESCUE_MODE")                 = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.NORMAL_RESCUE_MODE;
    m_outputs_map[ska_num].at("SPEED_LIMIT")                        = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.SPEED_LIMIT;
    m_outputs_map[ska_num].at("TRACTION_NULL")                      = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.TRACTION_NULL;
    m_outputs_map[ska_num].at("bit11")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit11;
    m_outputs_map[ska_num].at("bit12")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit12;
    m_outputs_map[ska_num].at("bit13")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit13;
    m_outputs_map[ska_num].at("bit14")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit14;
    m_outputs_map[ska_num].at("bit15")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit15;
    m_outputs_map[ska_num].at("CAB_MODE")                           = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.CAB_MODE;
    m_outputs_map[ska_num].at("HVAC_1_ON_OFF")                      = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.HVAC_1_ON_OFF;
    m_outputs_map[ska_num].at("HVAC_1_FAILURE")                     = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.HVAC_1_FAILURE;
    m_outputs_map[ska_num].at("bit19")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit19;
    m_outputs_map[ska_num].at("bit20")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit20;
    m_outputs_map[ska_num].at("bit21")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit21;
    m_outputs_map[ska_num].at("bit22")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit22;
    m_outputs_map[ska_num].at("bit23")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit23;
    m_outputs_map[ska_num].at("HVAC_2_ON_OFF")                      = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.HVAC_2_ON_OFF;
    m_outputs_map[ska_num].at("HVAC_2_FAILURE")                     = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.HVAC_2_FAILURE;
    m_outputs_map[ska_num].at("TL_HB_C_RELEASE")                    = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.TL_HB_C_RELEASE;
    m_outputs_map[ska_num].at("bit27")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit27;
    m_outputs_map[ska_num].at("bit28")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit28;
    m_outputs_map[ska_num].at("bit29")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit29;
    m_outputs_map[ska_num].at("bit30")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit30;
    m_outputs_map[ska_num].at("bit31")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit31;
    m_outputs_map[ska_num].at("MRP_ISOLATION_COMMAND")              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.MRP_ISOLATION_COMMAND;
    m_outputs_map[ska_num].at("PASSENGERS_ALARM_OUT_OF_SERVICE")    = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.PASSENGERS_ALARM_OUT_OF_SERVICE;
    m_outputs_map[ska_num].at("HEATING_CARTRIGE_HEATER")            = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.HEATING_CARTRIGE_HEATER;
    m_outputs_map[ska_num].at("bit35")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit35;
    m_outputs_map[ska_num].at("bit36")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit36;
    m_outputs_map[ska_num].at("bit37")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit37;
    m_outputs_map[ska_num].at("bit38")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit38;
    m_outputs_map[ska_num].at("bit39")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit39;
    m_outputs_map[ska_num].at("HEATING_SAND_TUBE")                  = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.HEATING_SAND_TUBE;
    m_outputs_map[ska_num].at("TEST_SAND_LEVELS_SENSORS_BOGIE_1")   = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.TEST_SAND_LEVELS_SENSORS_BOGIE_1;
    m_outputs_map[ska_num].at("TEST_SAND_LEVELS_SENSORS_BOGIE_2")   = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.TEST_SAND_LEVELS_SENSORS_BOGIE_2;
    m_outputs_map[ska_num].at("bit43")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit43;
    m_outputs_map[ska_num].at("bit44")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit44;
    m_outputs_map[ska_num].at("bit45")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit45;
    m_outputs_map[ska_num].at("bit46")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit46;
    m_outputs_map[ska_num].at("bit47")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit47;
    m_outputs_map[ska_num].at("LIGHT_OFF_COMMAND")                  = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.LIGHT_OFF_COMMAND;
    m_outputs_map[ska_num].at("LIGHT_COMMAND_FULL_LIGHT")           = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.LIGHT_COMMAND_FULL_LIGHT;
    m_outputs_map[ska_num].at("HALF_LIGHT_COMMAND")                 = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.HALF_LIGHT_COMMAND;
    m_outputs_map[ska_num].at("EMERGENCY_LIGHT_COMMAND")            = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.EMERGENCY_LIGHT_COMMAND;
    m_outputs_map[ska_num].at("bit52")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit52;
    m_outputs_map[ska_num].at("bit53")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit53;
    m_outputs_map[ska_num].at("bit54")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit54;
    m_outputs_map[ska_num].at("bit55")                              = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.bit55;
    m_outputs_map[ska_num].at("reserved_7")                         = m_ska_ccu_vh_riom_mvb1_d_outputs.at(ska_num).bits.reserved_7;


}
