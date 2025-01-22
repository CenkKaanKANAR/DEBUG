#include "ccu_to_all_tcus.h"
#include <QDebug>

Ccu_To_All_TCUS::Ccu_To_All_TCUS(QObject *parent)
    : QObject{parent}
{
    memset(m_ccu_to_all_tcus.bytes, 0, sizeof(m_ccu_to_all_tcus));
    init_table();
}

Ccu_To_All_TCUS::~Ccu_To_All_TCUS()
{
    delete m_tableWidget;
}

void Ccu_To_All_TCUS::set_data_struct(const QByteArray &output)
{

    if (output.size() == sizeof(m_ccu_to_all_tcus.bytes)) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        memcpy(m_ccu_to_all_tcus.bytes, output.constData(), sizeof(m_ccu_to_all_tcus.bytes));
        update_map();
        update_table();
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }
}

void Ccu_To_All_TCUS::init_table()
{
    m_outputs_map = {

            {"Lifesign",0},
            {"TL_Enable_TC1_SKA1",0},
            {"TL_Enable_TC2_SKA1",0},
            {"TL_Enable_TC1_SKA2",0},
            {"TL_Enable_TC2_SKA2",0},
            {"TL_Normal_Rescue_SKA1",0},
            {"TL_Normal_Rescue_SKA2",0},
            {"TL_Speed_Limit_SKA1",0},
            {"TL_Speed_Limit_SKA2",0},
            {"TL_Cabs_Mode",0},
            {"TL_SKA1_Forward",0},
            {"TL_SKA1_Reverse",0},
            {"TL_SKA2_Forward",0},
            {"TL_SKA2_Reverse",0},
            {"TL_Traction_CutOff_SKA1",0},
            {"TL_Traction_CutOff_SKA2",0},
            {"bit31",0},
            {"TL_Relay_Security_Emergency_Loop_SKA1",0},
            {"TL_Relay_Security_Emergency_Loop_SKA2",0},
            {"TL_MC_S1",0},
            {"TL_MC_S2",0},
            {"TL_MC_S3",0},
            {"TL_MC_S4",0},
            {"TL_MC_S5",0},
            {"TL_MC_S6",0},
            {"STS_Cutoff_bypass",0},
            {"TL_VCB_On_Off_OA1",0},
            {"TL_VCB_On_Off_OA2",0},
            {"VCB_Opening_Warning",0},
            {"TC_SKA1_HV_Expected",0},
            {"TC_SKA2_HV_Expected",0},
            {"bit46",0},
            {"bit47",0},
            {"Cmd_Traction_Null",0},
            {"Cmd_Traction_Cutoff",0},
            {"Cmd_EDB_Deactivate",0},
            {"Cmd_Speed_Limit",0},
            {"Cmd_ASC_Mode",0},
            {"bit53",0},
            {"bit54",0},
            {"bit55",0},
            {"Cmd_Traction_Reduction_Lvl1_SKA1",0},
            {"Cmd_Traction_Reduction_Lvl2_SKA1",0},
            {"Cmd_Traction_Reduction_Lvl1_SKA2",0},
            {"Cmd_Traction_Reduction_Lvl2_SKA2",0},
            {"bit60",0},
            {"bit61",0},
            {"bit62",0},
            {"bit63",0},
            {"Cmd_Reset_SKA1_TC1",0},
            {"Cmd_Reset_SKA1_TC2",0},
            {"Cmd_Reset_SKA2_TC1",0},
            {"Cmd_Reset_SKA2_TC2",0},
            {"Cmd_OOS_SKA1_TC1",0},
            {"Cmd_OOS_SKA1_TC2",0},
            {"Cmd_OOS_SKA2_TC1",0},
            {"Cmd_OOS_SKA2_TC2",0},
            {"reserved_9",0},
            {"ASC_Target",0},
            {"Train_Speed",0},
            {"reserved_12",0},
            {"SKA1_wheel_diameter_1",0},
            {"SKA1_wheel_diameter_2",0},
            {"SKA1_wheel_diameter_3",0},
            {"SKA1_wheel_diameter_4",0},
            {"SKA2_wheel_diameter_1",0},
            {"SKA2_wheel_diameter_2",0},
            {"SKA2_wheel_diameter_3",0},
            {"SKA2_wheel_diameter_4",0},
            {"reserved_29",0},
            {"Catenary_Voltage",0},

};

    QStringList table_name = {"ccu_to_all_tcus", "value"};

    m_tableWidget = new QTableWidget();
    m_tableWidget->setColumnCount(2);
    m_tableWidget->setRowCount(m_outputs_map.size());
    m_tableWidget->setHorizontalHeaderLabels(table_name);
    m_tableWidget->setObjectName("ccu_to_all_tcus");

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
}


void Ccu_To_All_TCUS::update_struct_with_map()
{


    auto setInputMap = [&](const QString& signal_name) {
        m_outputs_map[signal_name] = utils::getTableWidgetValueByNameWithoutColumn(m_tableWidget, signal_name).toInt();
    };
    // update map with given tableWidget values
    for(const auto& map : m_outputs_map)
    {
        setInputMap(map.first);
    }
    // set struct parameters with given updated map parameters
    set_struct();
}


void Ccu_To_All_TCUS::update_table()
{


    for(const auto & map:m_outputs_map){
        //qDebug() <<  map.first << map.second;
        utils::setTableWidgetValueByName(m_tableWidget, map.first, 1, map.second );
    }
}

void Ccu_To_All_TCUS::update_map() {

    m_outputs_map.at("Lifesign")                                   = m_ccu_to_all_tcus.bits.Lifesign;
    m_outputs_map.at("TL_Enable_TC1_SKA1")                                   = m_ccu_to_all_tcus.bits.TL_Enable_TC1_SKA1;
    m_outputs_map.at("TL_Enable_TC2_SKA1")                                   = m_ccu_to_all_tcus.bits.TL_Enable_TC2_SKA1;
    m_outputs_map.at("TL_Enable_TC1_SKA2")                                   = m_ccu_to_all_tcus.bits.TL_Enable_TC1_SKA2;
    m_outputs_map.at("TL_Enable_TC2_SKA2")                                   = m_ccu_to_all_tcus.bits.TL_Enable_TC2_SKA2;
    m_outputs_map.at("TL_Normal_Rescue_SKA1")                                   = m_ccu_to_all_tcus.bits.TL_Normal_Rescue_SKA1;
    m_outputs_map.at("TL_Normal_Rescue_SKA2")                                   = m_ccu_to_all_tcus.bits.TL_Normal_Rescue_SKA2;
    m_outputs_map.at("TL_Speed_Limit_SKA1")                                   = m_ccu_to_all_tcus.bits.TL_Speed_Limit_SKA1;
    m_outputs_map.at("TL_Speed_Limit_SKA2")                                   = m_ccu_to_all_tcus.bits.TL_Speed_Limit_SKA2;
    m_outputs_map.at("TL_Cabs_Mode")                                   = m_ccu_to_all_tcus.bits.TL_Cabs_Mode;
    m_outputs_map.at("TL_SKA1_Forward")                                   = m_ccu_to_all_tcus.bits.TL_SKA1_Forward;
    m_outputs_map.at("TL_SKA1_Reverse")                                   = m_ccu_to_all_tcus.bits.TL_SKA1_Reverse;
    m_outputs_map.at("TL_SKA2_Forward")                                   = m_ccu_to_all_tcus.bits.TL_SKA2_Forward;
    m_outputs_map.at("TL_SKA2_Reverse")                                   = m_ccu_to_all_tcus.bits.TL_SKA2_Reverse;
    m_outputs_map.at("TL_Traction_CutOff_SKA1")                                   = m_ccu_to_all_tcus.bits.TL_Traction_CutOff_SKA1;
    m_outputs_map.at("TL_Traction_CutOff_SKA2")                                   = m_ccu_to_all_tcus.bits.TL_Traction_CutOff_SKA2;
    m_outputs_map.at("bit31")                                   = m_ccu_to_all_tcus.bits.bit31;
    m_outputs_map.at("TL_Relay_Security_Emergency_Loop_SKA1")                                   = m_ccu_to_all_tcus.bits.TL_Relay_Security_Emergency_Loop_SKA1;
    m_outputs_map.at("TL_Relay_Security_Emergency_Loop_SKA2")                                   = m_ccu_to_all_tcus.bits.TL_Relay_Security_Emergency_Loop_SKA2;
    m_outputs_map.at("TL_MC_S1")                                   = m_ccu_to_all_tcus.bits.TL_MC_S1;
    m_outputs_map.at("TL_MC_S2")                                   = m_ccu_to_all_tcus.bits.TL_MC_S2;
    m_outputs_map.at("TL_MC_S3")                                   = m_ccu_to_all_tcus.bits.TL_MC_S3;
    m_outputs_map.at("TL_MC_S4")                                   = m_ccu_to_all_tcus.bits.TL_MC_S4;
    m_outputs_map.at("TL_MC_S5")                                   = m_ccu_to_all_tcus.bits.TL_MC_S5;
    m_outputs_map.at("TL_MC_S6")                                   = m_ccu_to_all_tcus.bits.TL_MC_S6;
    m_outputs_map.at("STS_Cutoff_bypass")                                   = m_ccu_to_all_tcus.bits.STS_Cutoff_bypass;
    m_outputs_map.at("TL_VCB_On_Off_OA1")                                   = m_ccu_to_all_tcus.bits.TL_VCB_On_Off_OA1;
    m_outputs_map.at("TL_VCB_On_Off_OA2")                                   = m_ccu_to_all_tcus.bits.TL_VCB_On_Off_OA2;
    m_outputs_map.at("VCB_Opening_Warning")                                   = m_ccu_to_all_tcus.bits.VCB_Opening_Warning;
    m_outputs_map.at("TC_SKA1_HV_Expected")                                   = m_ccu_to_all_tcus.bits.TC_SKA1_HV_Expected;
    m_outputs_map.at("TC_SKA2_HV_Expected")                                   = m_ccu_to_all_tcus.bits.TC_SKA2_HV_Expected;
    m_outputs_map.at("bit46")                                   = m_ccu_to_all_tcus.bits.bit46;
    m_outputs_map.at("bit47")                                   = m_ccu_to_all_tcus.bits.bit47;
    m_outputs_map.at("Cmd_Traction_Null")                                   = m_ccu_to_all_tcus.bits.Cmd_Traction_Null;
    m_outputs_map.at("Cmd_Traction_Cutoff")                                   = m_ccu_to_all_tcus.bits.Cmd_Traction_Cutoff;
    m_outputs_map.at("Cmd_EDB_Deactivate")                                   = m_ccu_to_all_tcus.bits.Cmd_EDB_Deactivate;
    m_outputs_map.at("Cmd_Speed_Limit")                                   = m_ccu_to_all_tcus.bits.Cmd_Speed_Limit;
    m_outputs_map.at("Cmd_ASC_Mode")                                   = m_ccu_to_all_tcus.bits.Cmd_ASC_Mode;
    m_outputs_map.at("bit53")                                   = m_ccu_to_all_tcus.bits.bit53;
    m_outputs_map.at("bit54")                                   = m_ccu_to_all_tcus.bits.bit54;
    m_outputs_map.at("bit55")                                   = m_ccu_to_all_tcus.bits.bit55;
    m_outputs_map.at("Cmd_Traction_Reduction_Lvl1_SKA1")                                   = m_ccu_to_all_tcus.bits.Cmd_Traction_Reduction_Lvl1_SKA1;
    m_outputs_map.at("Cmd_Traction_Reduction_Lvl2_SKA1")                                   = m_ccu_to_all_tcus.bits.Cmd_Traction_Reduction_Lvl2_SKA1;
    m_outputs_map.at("Cmd_Traction_Reduction_Lvl1_SKA2")                                   = m_ccu_to_all_tcus.bits.Cmd_Traction_Reduction_Lvl1_SKA2;
    m_outputs_map.at("Cmd_Traction_Reduction_Lvl2_SKA2")                                   = m_ccu_to_all_tcus.bits.Cmd_Traction_Reduction_Lvl2_SKA2;
    m_outputs_map.at("bit60")                                   = m_ccu_to_all_tcus.bits.bit60;
    m_outputs_map.at("bit61")                                   = m_ccu_to_all_tcus.bits.bit61;
    m_outputs_map.at("bit62")                                   = m_ccu_to_all_tcus.bits.bit62;
    m_outputs_map.at("bit63")                                   = m_ccu_to_all_tcus.bits.bit63;
    m_outputs_map.at("Cmd_Reset_SKA1_TC1")                                   = m_ccu_to_all_tcus.bits.Cmd_Reset_SKA1_TC1;
    m_outputs_map.at("Cmd_Reset_SKA1_TC2")                                   = m_ccu_to_all_tcus.bits.Cmd_Reset_SKA1_TC2;
    m_outputs_map.at("Cmd_Reset_SKA2_TC1")                                   = m_ccu_to_all_tcus.bits.Cmd_Reset_SKA2_TC1;
    m_outputs_map.at("Cmd_Reset_SKA2_TC2")                                   = m_ccu_to_all_tcus.bits.Cmd_Reset_SKA2_TC2;
    m_outputs_map.at("Cmd_OOS_SKA1_TC1")                                   = m_ccu_to_all_tcus.bits.Cmd_OOS_SKA1_TC1;
    m_outputs_map.at("Cmd_OOS_SKA1_TC2")                                   = m_ccu_to_all_tcus.bits.Cmd_OOS_SKA1_TC2;
    m_outputs_map.at("Cmd_OOS_SKA2_TC1")                                   = m_ccu_to_all_tcus.bits.Cmd_OOS_SKA2_TC1;
    m_outputs_map.at("Cmd_OOS_SKA2_TC2")                                   = m_ccu_to_all_tcus.bits.Cmd_OOS_SKA2_TC2;
    m_outputs_map.at("reserved_9")                                   = m_ccu_to_all_tcus.bits.reserved_9;
    m_outputs_map.at("ASC_Target")                                   = m_ccu_to_all_tcus.bits.ASC_Target;
    m_outputs_map.at("Train_Speed")                                   = m_ccu_to_all_tcus.bits.Train_Speed;
    m_outputs_map.at("reserved_12")                                   = m_ccu_to_all_tcus.bits.reserved_12;
    m_outputs_map.at("SKA1_wheel_diameter_1")                                   = m_ccu_to_all_tcus.bits.SKA1_wheel_diameter_1;
    m_outputs_map.at("SKA1_wheel_diameter_2")                                   = m_ccu_to_all_tcus.bits.SKA1_wheel_diameter_2;
    m_outputs_map.at("SKA1_wheel_diameter_3")                                   = m_ccu_to_all_tcus.bits.SKA1_wheel_diameter_3;
    m_outputs_map.at("SKA1_wheel_diameter_4")                                   = m_ccu_to_all_tcus.bits.SKA1_wheel_diameter_4;
    m_outputs_map.at("SKA2_wheel_diameter_1")                                   = m_ccu_to_all_tcus.bits.SKA2_wheel_diameter_1;
    m_outputs_map.at("SKA2_wheel_diameter_2")                                   = m_ccu_to_all_tcus.bits.SKA2_wheel_diameter_2;
    m_outputs_map.at("SKA2_wheel_diameter_3")                                   = m_ccu_to_all_tcus.bits.SKA2_wheel_diameter_3;
    m_outputs_map.at("SKA2_wheel_diameter_4")                                   = m_ccu_to_all_tcus.bits.SKA2_wheel_diameter_4;
    m_outputs_map.at("reserved_29")                                   = m_ccu_to_all_tcus.bits.reserved_29;
    m_outputs_map.at("Catenary_Voltage")                                   = m_ccu_to_all_tcus.bits.Catenary_Voltage;




}

void Ccu_To_All_TCUS::set_struct() {


    m_ccu_to_all_tcus.bits.Lifesign                         = m_outputs_map.at("Lifesign") ;
    m_ccu_to_all_tcus.bits.TL_Enable_TC1_SKA1                         = m_outputs_map.at("TL_Enable_TC1_SKA1") ;
    m_ccu_to_all_tcus.bits.TL_Enable_TC2_SKA1                         = m_outputs_map.at("TL_Enable_TC2_SKA1") ;
    m_ccu_to_all_tcus.bits.TL_Enable_TC1_SKA2                         = m_outputs_map.at("TL_Enable_TC1_SKA2") ;
    m_ccu_to_all_tcus.bits.TL_Enable_TC2_SKA2                         = m_outputs_map.at("TL_Enable_TC2_SKA2") ;
    m_ccu_to_all_tcus.bits.TL_Normal_Rescue_SKA1                         = m_outputs_map.at("TL_Normal_Rescue_SKA1") ;
    m_ccu_to_all_tcus.bits.TL_Normal_Rescue_SKA2                         = m_outputs_map.at("TL_Normal_Rescue_SKA2") ;
    m_ccu_to_all_tcus.bits.TL_Speed_Limit_SKA1                         = m_outputs_map.at("TL_Speed_Limit_SKA1") ;
    m_ccu_to_all_tcus.bits.TL_Speed_Limit_SKA2                         = m_outputs_map.at("TL_Speed_Limit_SKA2") ;
    m_ccu_to_all_tcus.bits.TL_Cabs_Mode                         = m_outputs_map.at("TL_Cabs_Mode") ;
    m_ccu_to_all_tcus.bits.TL_SKA1_Forward                         = m_outputs_map.at("TL_SKA1_Forward") ;
    m_ccu_to_all_tcus.bits.TL_SKA1_Reverse                         = m_outputs_map.at("TL_SKA1_Reverse") ;
    m_ccu_to_all_tcus.bits.TL_SKA2_Forward                         = m_outputs_map.at("TL_SKA2_Forward") ;
    m_ccu_to_all_tcus.bits.TL_SKA2_Reverse                         = m_outputs_map.at("TL_SKA2_Reverse") ;
    m_ccu_to_all_tcus.bits.TL_Traction_CutOff_SKA1                         = m_outputs_map.at("TL_Traction_CutOff_SKA1") ;
    m_ccu_to_all_tcus.bits.TL_Traction_CutOff_SKA2                         = m_outputs_map.at("TL_Traction_CutOff_SKA2") ;
    m_ccu_to_all_tcus.bits.bit31                         = m_outputs_map.at("bit31") ;
    m_ccu_to_all_tcus.bits.TL_Relay_Security_Emergency_Loop_SKA1                         = m_outputs_map.at("TL_Relay_Security_Emergency_Loop_SKA1") ;
    m_ccu_to_all_tcus.bits.TL_Relay_Security_Emergency_Loop_SKA2                         = m_outputs_map.at("TL_Relay_Security_Emergency_Loop_SKA2") ;
    m_ccu_to_all_tcus.bits.TL_MC_S1                         = m_outputs_map.at("TL_MC_S1") ;
    m_ccu_to_all_tcus.bits.TL_MC_S2                         = m_outputs_map.at("TL_MC_S2") ;
    m_ccu_to_all_tcus.bits.TL_MC_S3                         = m_outputs_map.at("TL_MC_S3") ;
    m_ccu_to_all_tcus.bits.TL_MC_S4                         = m_outputs_map.at("TL_MC_S4") ;
    m_ccu_to_all_tcus.bits.TL_MC_S5                         = m_outputs_map.at("TL_MC_S5") ;
    m_ccu_to_all_tcus.bits.TL_MC_S6                         = m_outputs_map.at("TL_MC_S6") ;
    m_ccu_to_all_tcus.bits.STS_Cutoff_bypass                         = m_outputs_map.at("STS_Cutoff_bypass") ;
    m_ccu_to_all_tcus.bits.TL_VCB_On_Off_OA1                         = m_outputs_map.at("TL_VCB_On_Off_OA1") ;
    m_ccu_to_all_tcus.bits.TL_VCB_On_Off_OA2                         = m_outputs_map.at("TL_VCB_On_Off_OA2") ;
    m_ccu_to_all_tcus.bits.VCB_Opening_Warning                         = m_outputs_map.at("VCB_Opening_Warning") ;
    m_ccu_to_all_tcus.bits.TC_SKA1_HV_Expected                         = m_outputs_map.at("TC_SKA1_HV_Expected") ;
    m_ccu_to_all_tcus.bits.TC_SKA2_HV_Expected                         = m_outputs_map.at("TC_SKA2_HV_Expected") ;
    m_ccu_to_all_tcus.bits.bit46                         = m_outputs_map.at("bit46") ;
    m_ccu_to_all_tcus.bits.bit47                         = m_outputs_map.at("bit47") ;
    m_ccu_to_all_tcus.bits.Cmd_Traction_Null                         = m_outputs_map.at("Cmd_Traction_Null") ;
    m_ccu_to_all_tcus.bits.Cmd_Traction_Cutoff                         = m_outputs_map.at("Cmd_Traction_Cutoff") ;
    m_ccu_to_all_tcus.bits.Cmd_EDB_Deactivate                         = m_outputs_map.at("Cmd_EDB_Deactivate") ;
    m_ccu_to_all_tcus.bits.Cmd_Speed_Limit                         = m_outputs_map.at("Cmd_Speed_Limit") ;
    m_ccu_to_all_tcus.bits.Cmd_ASC_Mode                         = m_outputs_map.at("Cmd_ASC_Mode") ;
    m_ccu_to_all_tcus.bits.bit53                         = m_outputs_map.at("bit53") ;
    m_ccu_to_all_tcus.bits.bit54                         = m_outputs_map.at("bit54") ;
    m_ccu_to_all_tcus.bits.bit55                         = m_outputs_map.at("bit55") ;
    m_ccu_to_all_tcus.bits.Cmd_Traction_Reduction_Lvl1_SKA1                         = m_outputs_map.at("Cmd_Traction_Reduction_Lvl1_SKA1") ;
    m_ccu_to_all_tcus.bits.Cmd_Traction_Reduction_Lvl2_SKA1                         = m_outputs_map.at("Cmd_Traction_Reduction_Lvl2_SKA1") ;
    m_ccu_to_all_tcus.bits.Cmd_Traction_Reduction_Lvl1_SKA2                         = m_outputs_map.at("Cmd_Traction_Reduction_Lvl1_SKA2") ;
    m_ccu_to_all_tcus.bits.Cmd_Traction_Reduction_Lvl2_SKA2                         = m_outputs_map.at("Cmd_Traction_Reduction_Lvl2_SKA2") ;
    m_ccu_to_all_tcus.bits.bit60                         = m_outputs_map.at("bit60") ;
    m_ccu_to_all_tcus.bits.bit61                         = m_outputs_map.at("bit61") ;
    m_ccu_to_all_tcus.bits.bit62                         = m_outputs_map.at("bit62") ;
    m_ccu_to_all_tcus.bits.bit63                         = m_outputs_map.at("bit63") ;
    m_ccu_to_all_tcus.bits.Cmd_Reset_SKA1_TC1                         = m_outputs_map.at("Cmd_Reset_SKA1_TC1") ;
    m_ccu_to_all_tcus.bits.Cmd_Reset_SKA1_TC2                         = m_outputs_map.at("Cmd_Reset_SKA1_TC2") ;
    m_ccu_to_all_tcus.bits.Cmd_Reset_SKA2_TC1                         = m_outputs_map.at("Cmd_Reset_SKA2_TC1") ;
    m_ccu_to_all_tcus.bits.Cmd_Reset_SKA2_TC2                         = m_outputs_map.at("Cmd_Reset_SKA2_TC2") ;
    m_ccu_to_all_tcus.bits.Cmd_OOS_SKA1_TC1                         = m_outputs_map.at("Cmd_OOS_SKA1_TC1") ;
    m_ccu_to_all_tcus.bits.Cmd_OOS_SKA1_TC2                         = m_outputs_map.at("Cmd_OOS_SKA1_TC2") ;
    m_ccu_to_all_tcus.bits.Cmd_OOS_SKA2_TC1                         = m_outputs_map.at("Cmd_OOS_SKA2_TC1") ;
    m_ccu_to_all_tcus.bits.Cmd_OOS_SKA2_TC2                         = m_outputs_map.at("Cmd_OOS_SKA2_TC2") ;
    m_ccu_to_all_tcus.bits.reserved_9                         = m_outputs_map.at("reserved_9") ;
    m_ccu_to_all_tcus.bits.ASC_Target                         = m_outputs_map.at("ASC_Target") ;
    m_ccu_to_all_tcus.bits.Train_Speed                         = m_outputs_map.at("Train_Speed") ;
    m_ccu_to_all_tcus.bits.reserved_12                         = m_outputs_map.at("reserved_12") ;
    m_ccu_to_all_tcus.bits.SKA1_wheel_diameter_1                         = m_outputs_map.at("SKA1_wheel_diameter_1") ;
    m_ccu_to_all_tcus.bits.SKA1_wheel_diameter_2                         = m_outputs_map.at("SKA1_wheel_diameter_2") ;
    m_ccu_to_all_tcus.bits.SKA1_wheel_diameter_3                         = m_outputs_map.at("SKA1_wheel_diameter_3") ;
    m_ccu_to_all_tcus.bits.SKA1_wheel_diameter_4                         = m_outputs_map.at("SKA1_wheel_diameter_4") ;
    m_ccu_to_all_tcus.bits.SKA2_wheel_diameter_1                         = m_outputs_map.at("SKA2_wheel_diameter_1") ;
    m_ccu_to_all_tcus.bits.SKA2_wheel_diameter_2                         = m_outputs_map.at("SKA2_wheel_diameter_2") ;
    m_ccu_to_all_tcus.bits.SKA2_wheel_diameter_3                         = m_outputs_map.at("SKA2_wheel_diameter_3") ;
    m_ccu_to_all_tcus.bits.SKA2_wheel_diameter_4                         = m_outputs_map.at("SKA2_wheel_diameter_4") ;
    m_ccu_to_all_tcus.bits.reserved_29                         = m_outputs_map.at("reserved_29") ;
    m_ccu_to_all_tcus.bits.Catenary_Voltage                         = m_outputs_map.at("Catenary_Voltage") ;







}
