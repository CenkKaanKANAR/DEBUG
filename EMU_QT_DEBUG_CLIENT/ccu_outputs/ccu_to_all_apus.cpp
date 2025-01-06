#include "ccu_to_all_apus.h"
#include <QDebug>


Ccu_To_All_APUS::Ccu_To_All_APUS(QObject *parent)
    : QObject{parent}
{
    memset(m_ccu_to_all_apus.bytes, 0, sizeof(m_ccu_to_all_apus));
    init_table();
}

Ccu_To_All_APUS::~Ccu_To_All_APUS()
{
    delete m_tableWidget;
}

void Ccu_To_All_APUS::set_data_struct(const QByteArray &output)
{

    if (output.size() == sizeof(m_ccu_to_all_apus.bytes)) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        memcpy(m_ccu_to_all_apus.bytes, output.constData(), sizeof(m_ccu_to_all_apus.bytes));
        update_map();
        update_table();
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }
}

void Ccu_To_All_APUS::init_table()
{
    m_outputs_map = {

      {"Lifesign",0},
      {"APU_OA1_Start",0},
      {"APU_OA2_Start",0},
      {"APU_OA1_Reset",0},
      {"APU_OA2_Reset",0},
      {"APU_OA1_LV_Inhibit",0},
      {"APU_OA2_LV_Inhibit",0},
      {"bit22",0},
      {"bit23",0},
      {"APU_OA1_HV_Expected",0},
      {"APU_OA2_HV_Expected",0},
      {"Workshop_OA1_Left",0},
      {"Workshop_OA1_Right",0},
      {"Workshop_OA2_Left",0},
      {"Workshop_OA2_Right",0},
      {"Degraded_Mode",0},
      {"bit31",0},
      {"reserved_4",0},
      {"Catenary_Voltage",0},
      {"reserved_7",0},


};

QStringList table_name = {"ccu_to_all_apus", "value"};

m_tableWidget = new QTableWidget();
m_tableWidget->setColumnCount(2);
m_tableWidget->setRowCount(m_outputs_map.size());
m_tableWidget->setHorizontalHeaderLabels(table_name);
m_tableWidget->setObjectName("ccu_to_all_apus");

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


void Ccu_To_All_APUS::update_struct_with_map()
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


void Ccu_To_All_APUS::update_table()
{


    for(const auto & map:m_outputs_map){
        //qDebug() <<  map.first << map.second;
        utils::setTableWidgetValueByName(m_tableWidget, map.first, 1, map.second );
    }
}

void Ccu_To_All_APUS::update_map()
{

    m_outputs_map.at("Lifesign")                                   = m_ccu_to_all_apus.bits.Lifesign;
    m_outputs_map.at("APU_OA1_Start")                                   = m_ccu_to_all_apus.bits.APU_OA1_Start;
    m_outputs_map.at("APU_OA2_Start")                                   = m_ccu_to_all_apus.bits.APU_OA2_Start;
    m_outputs_map.at("APU_OA1_Reset")                                   = m_ccu_to_all_apus.bits.APU_OA1_Reset;
    m_outputs_map.at("APU_OA2_Reset")                                   = m_ccu_to_all_apus.bits.APU_OA2_Reset;
    m_outputs_map.at("APU_OA1_LV_Inhibit")                                   = m_ccu_to_all_apus.bits.APU_OA1_LV_Inhibit;
    m_outputs_map.at("APU_OA2_LV_Inhibit")                                   = m_ccu_to_all_apus.bits.APU_OA2_LV_Inhibit;
    m_outputs_map.at("bit22")                                   = m_ccu_to_all_apus.bits.bit22;
    m_outputs_map.at("bit23")                                   = m_ccu_to_all_apus.bits.bit23;
    m_outputs_map.at("APU_OA1_HV_Expected")                                   = m_ccu_to_all_apus.bits.APU_OA1_HV_Expected;
    m_outputs_map.at("APU_OA2_HV_Expected")                                   = m_ccu_to_all_apus.bits.APU_OA2_HV_Expected;
    m_outputs_map.at("Workshop_OA1_Left")                                   = m_ccu_to_all_apus.bits.Workshop_OA1_Left;
    m_outputs_map.at("Workshop_OA1_Right")                                   = m_ccu_to_all_apus.bits.Workshop_OA1_Right;
    m_outputs_map.at("Workshop_OA2_Left")                                   = m_ccu_to_all_apus.bits.Workshop_OA2_Left;
    m_outputs_map.at("Workshop_OA2_Right")                                   = m_ccu_to_all_apus.bits.Workshop_OA2_Right;
    m_outputs_map.at("Degraded_Mode")                                   = m_ccu_to_all_apus.bits.Degraded_Mode;
    m_outputs_map.at("bit31")                                   = m_ccu_to_all_apus.bits.bit31;
    m_outputs_map.at("reserved_4")                                   = m_ccu_to_all_apus.bits.reserved_4;
    m_outputs_map.at("Catenary_Voltage")                                   = m_ccu_to_all_apus.bits.Catenary_Voltage;
    m_outputs_map.at("bit55reserved_7")                                   = m_ccu_to_all_apus.bits.reserved_7;




}

void Ccu_To_All_APUS::set_struct() {



    m_ccu_to_all_apus.bits.Lifesign                          = m_outputs_map.at("Lifesign") ;
    m_ccu_to_all_apus.bits.APU_OA1_Start                          = m_outputs_map.at("APU_OA1_Start") ;
    m_ccu_to_all_apus.bits.APU_OA2_Start                          = m_outputs_map.at("APU_OA2_Start") ;
    m_ccu_to_all_apus.bits.APU_OA1_Reset                          = m_outputs_map.at("APU_OA1_Reset") ;
    m_ccu_to_all_apus.bits.APU_OA2_Reset                          = m_outputs_map.at("APU_OA2_Reset") ;
    m_ccu_to_all_apus.bits.APU_OA1_LV_Inhibit                          = m_outputs_map.at("APU_OA1_LV_Inhibit") ;
    m_ccu_to_all_apus.bits.APU_OA2_LV_Inhibit                          = m_outputs_map.at("APU_OA2_LV_Inhibit") ;
    m_ccu_to_all_apus.bits.bit22                          = m_outputs_map.at("bit22") ;
    m_ccu_to_all_apus.bits.bit23                          = m_outputs_map.at("bit23") ;
    m_ccu_to_all_apus.bits.APU_OA1_HV_Expected                          = m_outputs_map.at("APU_OA1_HV_Expected") ;
    m_ccu_to_all_apus.bits.APU_OA2_HV_Expected                          = m_outputs_map.at("APU_OA2_HV_Expected") ;
    m_ccu_to_all_apus.bits.Workshop_OA1_Left                          = m_outputs_map.at("Workshop_OA1_Left") ;
    m_ccu_to_all_apus.bits.Workshop_OA1_Right                          = m_outputs_map.at("Workshop_OA1_Right") ;
    m_ccu_to_all_apus.bits.Workshop_OA2_Left                          = m_outputs_map.at("Workshop_OA2_Left") ;
    m_ccu_to_all_apus.bits.Workshop_OA2_Right                          = m_outputs_map.at("Workshop_OA2_Right") ;
    m_ccu_to_all_apus.bits.Degraded_Mode                          = m_outputs_map.at("Degraded_Mode") ;
    m_ccu_to_all_apus.bits.bit31                          = m_outputs_map.at("bit31") ;
    m_ccu_to_all_apus.bits.reserved_4                          = m_outputs_map.at("reserved_4") ;
    m_ccu_to_all_apus.bits.Catenary_Voltage                          = m_outputs_map.at("Catenary_Voltage") ;
    m_ccu_to_all_apus.bits.reserved_7                          = m_outputs_map.at("reserved_7") ;



}
