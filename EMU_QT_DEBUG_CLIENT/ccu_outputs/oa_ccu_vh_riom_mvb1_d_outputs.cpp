#include "oa_ccu_vh_riom_mvb1_d_outputs.h"
#include <QDebug>

Oa_Ccu_Vh_Riom_Mvb1_d_Outputs::Oa_Ccu_Vh_Riom_Mvb1_d_Outputs(QObject *parent)
    : QObject{parent}
{
    init_oa1_table();
    init_oa2_table();
}

Oa_Ccu_Vh_Riom_Mvb1_d_Outputs::~Oa_Ccu_Vh_Riom_Mvb1_d_Outputs()
{
    for (auto tableWidget : m_tableWidget) {
        delete tableWidget;
    }
}

void Oa_Ccu_Vh_Riom_Mvb1_d_Outputs::set_data_struct(const QByteArray &output, const OA_VEHICLE_NUM &oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);
    if (output.size() == sizeof(m_oa_ccu_vh_riom_mvb1_d_outputs[oa_num].bytes)) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        memcpy(m_oa_ccu_vh_riom_mvb1_d_outputs[oa_num].bytes, output.constData(), sizeof(m_oa_ccu_vh_riom_mvb1_d_outputs[oa_num].bytes));
        update_map(oa_x_num);
        update_table(oa_x_num);
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }
}

void Oa_Ccu_Vh_Riom_Mvb1_d_Outputs::init_oa1_table()
{
    m_outputs_map[get_index(OA_VEHICLE_NUM::OA1)] = {
         {"COMMAND_CONTACTOR_PRIVILEGED_LOAD_Lp", 0},
         {"TCMS_IN_RUN", 0},
         {"INIBHIT_APS", 0},
         {"DEGRADE_MODE_MV_OA_CARS", 0},
         {"bit4", 0},
         {"bit5", 0},
         {"bit6", 0},
         {"CABINET_TEST_HW_HEALT_RIOM_1", 0},
         {"VCB_CLOSING_COMMAND_1", 0},
         {"VCB_CLOSING_COMMAND_2", 0},
         {"VCB_OPENING_COMMAND", 0},
         {"OPENING_HV_DISCONNECTOR", 0},
         {"bit12", 0},
         {"bit13", 0},
         {"bit14", 0},
         {"bit15", 0},
         {"CLOSING_HV_DISCONNECTOR", 0},
         {"PANTOGRAPH_COMMAND_MOTOR_COMPRESSOR_OUTPUT", 0},
         {"PANTOGRAPH_COMMAND_RAISING_VALVE", 0},
         {"ADD_LOOP_CONTROL", 0},
         {"bit20", 0},
         {"bit21", 0},
         {"bit22", 0},
         {"bit23", 0},
         {"TRAFO_CONTROL_VOLTAGE_LOW_SPEED", 0},
         {"TRAFO_CONTROL_VOLTAGE_FULL_SPEED", 0},
         {"HVAC_1_ON_OFF", 0},
         {"HVAC_1_FAILURE", 0},
         {"bit28", 0},
         {"bit29", 0},
         {"bit30", 0},
         {"bit31", 0},
         {"HVAC_2_ON_OFF", 0},
         {"HVAC_2_FAILURE", 0},
         {"MOTOR_COMPRESSOR", 0},
         {"bit35", 0},
         {"bit36", 0},
         {"bit37", 0},
         {"bit38", 0},
         {"bit39", 0},
         {"START_COMPRESSOR", 0},
         {"TL_HB_C_RELEASE", 0},
         {"TRAIN_IN_MOVING_TO_ACTIVE_SKA_FRONT_DIRECTION", 0},
         {"SLEEPING_SIGNAL_ETCS", 0},
         {"TRACTION_BRAKE_HANDLE_TRACTION_SIGNAL_ETCS", 0},
         {"TRACTION_BRAKE_HANDLE_BRAKE_SIGNAL_ETCS", 0},
         {"NON_LEADING_SIGNAL_ETCS", 0},
         {"TRAIN_INTEGRITY_SIGNAL_ETCS", 0},
         {"TRAIN_IN_MOVING_TO_OPPOSITE_ACTIVE_SKA_DIRECTION", 0},
         {"BRAKE_DEMAND_FROM_ACTIVE_CABIN", 0},
         {"TRACTION_DEMAND_FROM_ACTIVE_CABIN", 0},
         {"CAB_ACTIVATION_SIGNAL", 0},
         {"bit52", 0},
         {"bit53", 0},
         {"bit54", 0},
         {"bit55", 0},
         {"reserved_7", 0},

    };

    QStringList table_name = {"oa_1_ccu_vh_riom_mvb1_d_outputs", "value"};

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

void Oa_Ccu_Vh_Riom_Mvb1_d_Outputs::init_oa2_table()
{
    // Copy Assignment Operator
    m_outputs_map[get_index(OA_VEHICLE_NUM::OA2)] =  m_outputs_map[get_index(OA_VEHICLE_NUM::OA1)];
    QStringList table_name = {"oa_2_ccu_vh_riom_mvb1_d_outputs", "value"};

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

void Oa_Ccu_Vh_Riom_Mvb1_d_Outputs::update_table(OA_VEHICLE_NUM oa_x_num)
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

void Oa_Ccu_Vh_Riom_Mvb1_d_Outputs::update_map(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);
    m_outputs_map[oa_num].at("COMMAND_CONTACTOR_PRIVILEGED_LOAD_Lp")       = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.COMMAND_CONTACTOR_PRIVILEGED_LOAD_Lp;
    m_outputs_map[oa_num].at("TCMS_IN_RUN")                                = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.TCMS_IN_RUN;
    m_outputs_map[oa_num].at("INIBHIT_APS")                                = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.INIBHIT_APS;
    m_outputs_map[oa_num].at("DEGRADE_MODE_MV_OA_CARS")                    = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.DEGRADE_MODE_MV_OA_CARS;
    m_outputs_map[oa_num].at("bit4")                                       = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit4;
    m_outputs_map[oa_num].at("bit5")                                       = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit5;
    m_outputs_map[oa_num].at("bit6")                                       = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit6;
    m_outputs_map[oa_num].at("CABINET_TEST_HW_HEALT_RIOM_1")               = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.CABINET_TEST_HW_HEALT_RIOM_1;
    m_outputs_map[oa_num].at("VCB_CLOSING_COMMAND_1")                      = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.VCB_CLOSING_COMMAND_1;
    m_outputs_map[oa_num].at("VCB_CLOSING_COMMAND_2")                      = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.VCB_CLOSING_COMMAND_2;
    m_outputs_map[oa_num].at("VCB_OPENING_COMMAND")                        = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.VCB_OPENING_COMMAND;
    m_outputs_map[oa_num].at("OPENING_HV_DISCONNECTOR")                    = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.OPENING_HV_DISCONNECTOR;
    m_outputs_map[oa_num].at("bit12")                                      = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit12;
    m_outputs_map[oa_num].at("bit13")                                      = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit13;
    m_outputs_map[oa_num].at("bit14")                                      = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit14;
    m_outputs_map[oa_num].at("bit15")                                      = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit15;
    m_outputs_map[oa_num].at("CLOSING_HV_DISCONNECTOR")                    = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.CLOSING_HV_DISCONNECTOR;
    m_outputs_map[oa_num].at("PANTOGRAPH_COMMAND_MOTOR_COMPRESSOR_OUTPUT") = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.PANTOGRAPH_COMMAND_MOTOR_COMPRESSOR_OUTPUT;
    m_outputs_map[oa_num].at("PANTOGRAPH_COMMAND_RAISING_VALVE")           = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.PANTOGRAPH_COMMAND_RAISING_VALVE;
    m_outputs_map[oa_num].at("ADD_LOOP_CONTROL")                   = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.ADD_LOOP_CONTROL;
    m_outputs_map[oa_num].at("bit20")                              = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit20;
    m_outputs_map[oa_num].at("bit21")                              = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit21;
    m_outputs_map[oa_num].at("bit22")                              = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit22;
    m_outputs_map[oa_num].at("bit23")                              = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit23;
    m_outputs_map[oa_num].at("TRAFO_CONTROL_VOLTAGE_LOW_SPEED")    = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.TRAFO_CONTROL_VOLTAGE_LOW_SPEED;
    m_outputs_map[oa_num].at("TRAFO_CONTROL_VOLTAGE_FULL_SPEED")   = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.TRAFO_CONTROL_VOLTAGE_FULL_SPEED;
    m_outputs_map[oa_num].at("HVAC_1_ON_OFF")                      = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.HVAC_1_ON_OFF;
    m_outputs_map[oa_num].at("HVAC_1_FAILURE")                     = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.HVAC_1_FAILURE;
    m_outputs_map[oa_num].at("bit28")                              = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit28;
    m_outputs_map[oa_num].at("bit29")                              = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit29;
    m_outputs_map[oa_num].at("bit30")                              = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit30;
    m_outputs_map[oa_num].at("bit31")                              = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit31;
    m_outputs_map[oa_num].at("HVAC_2_ON_OFF")                      = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.HVAC_2_ON_OFF;
    m_outputs_map[oa_num].at("HVAC_2_FAILURE")                     = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.HVAC_2_FAILURE;
    m_outputs_map[oa_num].at("MOTOR_COMPRESSOR")                   = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.MOTOR_COMPRESSOR;
    m_outputs_map[oa_num].at("bit35")                              = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit35;
    m_outputs_map[oa_num].at("bit36")                              = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit36;
    m_outputs_map[oa_num].at("bit37")                              = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit37;
    m_outputs_map[oa_num].at("bit38")                              = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit38;
    m_outputs_map[oa_num].at("bit39")                              = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit39;
    m_outputs_map[oa_num].at("START_COMPRESSOR")                   = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.START_COMPRESSOR;
    m_outputs_map[oa_num].at("TL_HB_C_RELEASE")                    = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.TL_HB_C_RELEASE;
    m_outputs_map[oa_num].at("TRAIN_IN_MOVING_TO_ACTIVE_SKA_FRONT_DIRECTION")      = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.TRAIN_IN_MOVING_TO_ACTIVE_SKA_FRONT_DIRECTION;
    m_outputs_map[oa_num].at("SLEEPING_SIGNAL_ETCS")                             = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.SLEEPING_SIGNAL_ETCS;
    m_outputs_map[oa_num].at("TRACTION_BRAKE_HANDLE_TRACTION_SIGNAL_ETCS")       = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.TRACTION_BRAKE_HANDLE_TRACTION_SIGNAL_ETCS;
    m_outputs_map[oa_num].at("TRACTION_BRAKE_HANDLE_BRAKE_SIGNAL_ETCS")          = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.TRACTION_BRAKE_HANDLE_BRAKE_SIGNAL_ETCS;
    m_outputs_map[oa_num].at("NON_LEADING_SIGNAL_ETCS")                          = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.NON_LEADING_SIGNAL_ETCS;
    m_outputs_map[oa_num].at("TRAIN_INTEGRITY_SIGNAL_ETCS")                      = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.TRAIN_INTEGRITY_SIGNAL_ETCS;
    m_outputs_map[oa_num].at("TRAIN_IN_MOVING_TO_OPPOSITE_ACTIVE_SKA_DIRECTION")   = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.TRAIN_IN_MOVING_TO_OPPOSITE_ACTIVE_SKA_DIRECTION;
    m_outputs_map[oa_num].at("BRAKE_DEMAND_FROM_ACTIVE_CABIN")                     = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.BRAKE_DEMAND_FROM_ACTIVE_CABIN;
    m_outputs_map[oa_num].at("TRACTION_DEMAND_FROM_ACTIVE_CABIN")                  = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.TRACTION_DEMAND_FROM_ACTIVE_CABIN;
    m_outputs_map[oa_num].at("CAB_ACTIVATION_SIGNAL")                              = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.CAB_ACTIVATION_SIGNAL;
    m_outputs_map[oa_num].at("bit52")                                              = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit52;
    m_outputs_map[oa_num].at("bit53")                                              = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit53;
    m_outputs_map[oa_num].at("bit54")                                              = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit54;
    m_outputs_map[oa_num].at("bit55")                                              = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.bit55;
    m_outputs_map[oa_num].at("reserved_7")                                         = m_oa_ccu_vh_riom_mvb1_d_outputs.at(oa_num).bits.reserved_7;


}
