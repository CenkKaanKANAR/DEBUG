#include "ska_ccu_dd_riom_mvb1_d_outputs.h"
#include <QDebug>

Ska_Ccu_DD_Riom_Mvb1_d_Outputs::Ska_Ccu_DD_Riom_Mvb1_d_Outputs(QObject *parent)
    : QObject{parent}
{
    init_ska1_table();
    init_ska2_table();
}

Ska_Ccu_DD_Riom_Mvb1_d_Outputs::~Ska_Ccu_DD_Riom_Mvb1_d_Outputs()
{
    for (auto tableWidget : m_tableWidget) {
        delete tableWidget;
    }
}

/**
 * @brief Sets the data structure for SKA CCU DD RIOM MVB1-D outputs.
 *
 * This function sets the data structure for the specified SKA vehicle number using the provided
 * QByteArray. It verifies the size of the QByteArray to ensure it matches the expected size
 * of the data structure. If the size is correct, it copies the data from the QByteArray to the
 * appropriate data structure, updates the corresponding map, and updates the table.
 * If the size is incorrect, it outputs a debug message indicating a size mismatch.
 *
 * @param output The QByteArray containing the output data to be set.
 * @param ska_x_num The SKA vehicle number for which the data is being set.
 */
void Ska_Ccu_DD_Riom_Mvb1_d_Outputs::set_data_struct(const QByteArray &output, const SKA_VEHICLE_NUM &ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    if (output.size() == sizeof(m_ska_ccu_dd_riom_mvb1_d_outputs[ska_num].bytes)) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        memcpy(m_ska_ccu_dd_riom_mvb1_d_outputs[ska_num].bytes, output.constData(), sizeof(m_ska_ccu_dd_riom_mvb1_d_outputs[ska_num].bytes));
        update_map(ska_x_num);
        update_table(ska_x_num);
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }
}

/**
 * @brief Initializes the table for SKA1 CCU DD RIOM MVB1-D outputs.
 *
 * This function sets up a QTableWidget for displaying the SKA1 CCU DD RIOM MVB1-D output values.
 * It initializes a map with output parameter names and their corresponding initial values.
 * The table is then populated with these values and added to the widget list for SKA1.
 * Finally, the columns are resized to fit their contents.
 */
void Ska_Ccu_DD_Riom_Mvb1_d_Outputs::init_ska1_table()
{
    m_outputs_map[get_index(SKA_VEHICLE_NUM::SKA1)] = {
        {"bit0", 0},
        {"bit1", 0},
        {"MODE_PARKING_ON", 0},
        {"SIGNALING_AIR_SUSPENSION_FAILURE", 0},
        {"bit4", 0},
        {"bit5", 0},
        {"bit6", 0},
        {"CONTROL_DESK_TEST_HW_HEALT_RIOM_1", 0},
        {"bit8", 0},
        {"WFL_SPRAY_ENABLE", 0},
        {"WFL_DIRECTION", 0},
        {"EMERGENCY_EGRESS_DEVICE_OUTPUT", 0},
        {"BY_PASS_HATCH_UNLOCK", 0},
        {"HATCH_UNLOCK", 0},
        {"COMMAND_OPENING_HATCH", 0},
        {"COMMAND_CLOSING_HATCH", 0},
        {"WIPER_MIDDLE_POSITION_REQUEST", 0},
        {"DIMMED_HEAD_LIGHT_LEFT_CENTRAL", 0},
        {"TAIL_RED_LIGHT_LEFT", 0},
        {"DIMMED_HEAD_LIGHT_RIGHT_CENTRAL", 0},
        {"bit20", 0},
        {"bit21", 0},
        {"bit22", 0},
        {"bit23", 0},
        {"TAIL_RED_LIGHT_RIGHT", 0},
        {"DIMMED_MARKER_LIGHT_LEFT_RIGHT_CENTRAL", 0},
        {"FULL_MARKER_LIGHT_LEFT_RIGHT_CENTRAL", 0},
        {"FULL_HEAD_LIGHT_LEFT_RIGHT_CENTRAL", 0},
        {"bit28", 0},
        {"bit29", 0},
        {"bit30", 0},
        {"bit31", 0},
        {"reserved4", 0},
        {"reserved5", 0},
        {"reserved6", 0},
        {"reserved7", 0}
    };


    QStringList table_name = {"ska_1_ccu_dd_riom_mvb1_d_outputs", "value"};

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
    // Resize the table widget contents
    m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)]->resizeColumnsToContents();

}
/*
 *
 * This function sets up the table widget for displaying the outputs of the SKA2 vehicle.
 * It first copies the output map from SKA1 to SKA2 to ensure consistent initial values.
 * Then, it creates a new QTableWidget for SKA2, sets the column count, row count, and header labels,
 * and populates the table with the output map data. Finally, it resizes the columns to fit the content.
 */
void Ska_Ccu_DD_Riom_Mvb1_d_Outputs::init_ska2_table()
{
    m_outputs_map[get_index(SKA_VEHICLE_NUM::SKA2)] =  m_outputs_map[get_index(SKA_VEHICLE_NUM::SKA1)];
    QStringList table_name = {"ska_2_ccu_dd_riom_mvb1_d_outputs", "value"};

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

/**
 * @brief Updates the table widget for the specified SKA vehicle with current data.
 *
 * This function clears the table widget associated with the given SKA vehicle number,
 * and then repopulates it with the current output data stored in the m_outputs_map.
 *
 * @param ska_x_num The vehicle number (SKA1, SKA2, etc.) for which the table should be updated.
 */
void Ska_Ccu_DD_Riom_Mvb1_d_Outputs::update_table(SKA_VEHICLE_NUM ska_x_num)
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


/**
 * @brief Updates the output map with the latest data for the specified SKA vehicle.
 *
 * This function retrieves the current data from the `m_ska_ccu_dd_riom_mvb1_d_outputs` array
 * for the given SKA vehicle number and updates the corresponding entries in the `m_outputs_map`.
 *
 * @param ska_x_num The vehicle number (SKA1, SKA2, etc.) for which the map should be updated.
 */
void Ska_Ccu_DD_Riom_Mvb1_d_Outputs::update_map(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_outputs_map[ska_num].at("bit0")                                      = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.bit0;
    m_outputs_map[ska_num].at("bit1")                                      = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.bit1;
    m_outputs_map[ska_num].at("MODE_PARKING_ON")                           = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.MODE_PARKING_ON;
    m_outputs_map[ska_num].at("SIGNALING_AIR_SUSPENSION_FAILURE")          = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.SIGNALING_AIR_SUSPENSION_FAILURE;
    m_outputs_map[ska_num].at("bit4")                                      = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.bit4;
    m_outputs_map[ska_num].at("bit5")                                      = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.bit5;
    m_outputs_map[ska_num].at("bit6")                                      = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.bit6;
    m_outputs_map[ska_num].at("CONTROL_DESK_TEST_HW_HEALT_RIOM_1")         = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.CONTROL_DESK_TEST_HW_HEALT_RIOM_1;
    m_outputs_map[ska_num].at("bit8")                                      = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.bit8;
    m_outputs_map[ska_num].at("WFL_SPRAY_ENABLE")                          = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.WFL_SPRAY_ENABLE;
    m_outputs_map[ska_num].at("WFL_DIRECTION")                             = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.WFL_DIRECTION;
    m_outputs_map[ska_num].at("EMERGENCY_EGRESS_DEVICE_OUTPUT")            = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.EMERGENCY_EGRESS_DEVICE_OUTPUT;
    m_outputs_map[ska_num].at("BY_PASS_HATCH_UNLOCK")                      = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.BY_PASS_HATCH_UNLOCK;
    m_outputs_map[ska_num].at("HATCH_UNLOCK")                              = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.HATCH_UNLOCK;
    m_outputs_map[ska_num].at("COMMAND_OPENING_HATCH")                     = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.COMMAND_OPENING_HATCH;
    m_outputs_map[ska_num].at("COMMAND_CLOSING_HATCH")                     = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.COMMAND_CLOSING_HATCH;
    m_outputs_map[ska_num].at("WIPER_MIDDLE_POSITION_REQUEST")             = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.WIPER_MIDDLE_POSITION_REQUEST;
    m_outputs_map[ska_num].at("DIMMED_HEAD_LIGHT_LEFT_CENTRAL")            = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.DIMMED_HEAD_LIGHT_LEFT_CENTRAL;
    m_outputs_map[ska_num].at("TAIL_RED_LIGHT_LEFT")                       = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.TAIL_RED_LIGHT_LEFT;
    m_outputs_map[ska_num].at("DIMMED_MARKER_LIGHT_LEFT_RIGHT_CENTRAL")    = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.DIMMED_MARKER_LIGHT_LEFT_RIGHT_CENTRAL;
    m_outputs_map[ska_num].at("bit20")                                     = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.bit20;
    m_outputs_map[ska_num].at("bit21")                                     = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.bit21;
    m_outputs_map[ska_num].at("bit22")                                     = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.bit22;
    m_outputs_map[ska_num].at("bit23")                                     = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.bit23;
    m_outputs_map[ska_num].at("TAIL_RED_LIGHT_RIGHT")                      = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.TAIL_RED_LIGHT_RIGHT;
    m_outputs_map[ska_num].at("DIMMED_MARKER_LIGHT_LEFT_RIGHT_CENTRAL")    = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.DIMMED_MARKER_LIGHT_LEFT_RIGHT_CENTRAL;
    m_outputs_map[ska_num].at("FULL_MARKER_LIGHT_LEFT_RIGHT_CENTRAL")      = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.FULL_MARKER_LIGHT_LEFT_RIGHT_CENTRAL;
    m_outputs_map[ska_num].at("FULL_HEAD_LIGHT_LEFT_RIGHT_CENTRAL")        = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.FULL_HEAD_LIGHT_LEFT_RIGHT_CENTRAL;
    m_outputs_map[ska_num].at("bit28")                                     = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.bit28;
    m_outputs_map[ska_num].at("bit29")                                     = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.bit29;
    m_outputs_map[ska_num].at("bit30")                                     = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.bit30;
    m_outputs_map[ska_num].at("bit31")                                     = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.bit31;
    m_outputs_map[ska_num].at("reserved4")                                 = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.reserved4;
    m_outputs_map[ska_num].at("reserved5")                                 = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.reserved5;
    m_outputs_map[ska_num].at("reserved6")                                 = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.reserved6;
    m_outputs_map[ska_num].at("reserved7")                                 = m_ska_ccu_dd_riom_mvb1_d_outputs.at(ska_num).bits.reserved7;

}
