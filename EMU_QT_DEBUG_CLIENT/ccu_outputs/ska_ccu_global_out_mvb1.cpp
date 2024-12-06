#include "ska_ccu_global_out_mvb1.h"
#include <QDebug>

Ska_Ccu_Global_Out_Mvb1::Ska_Ccu_Global_Out_Mvb1(QObject *parent)
    : QObject{parent}
{
    memset(m_ska_ccu_global_out_mvb1.bytes, 0, sizeof(m_ska_ccu_global_out_mvb1));
    init_table();

}

Ska_Ccu_Global_Out_Mvb1::~Ska_Ccu_Global_Out_Mvb1()
{
    delete m_tableWidget;
}

void Ska_Ccu_Global_Out_Mvb1::set_data_struct(const QByteArray &output)
{
    if (output.size() == sizeof(m_ska_ccu_global_out_mvb1.bytes)) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        memcpy(m_ska_ccu_global_out_mvb1.bytes, output.constData(), sizeof(m_ska_ccu_global_out_mvb1.bytes));
        update_map();
        update_table();
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }
}

void Ska_Ccu_Global_Out_Mvb1::init_table()
{
    m_outputs_map = {
        {"Lifesign", 0},
        {"reserved_1", 0},
        {"reserved_2", 0},
        {"ccu_time", 0},
        //{"actual_time_seconds", 0},
        //{"actual_time_ticks", 0},
        {"S_Coupling", 0},
        {"S_Lead_Follow_consist", 0},
        {"S_CAB_Active", 0},

        {"S_Direction", 0},

        {"CouplingStatus", 0},

        {"_1stTrainSetConfiguration", 0},

        {"_2ndTrainSetConfiguration", 0},

        {"reserved_12", 0},
        {"reserved_13", 0},
        {"reserved_14", 0},
        {"reserved_15", 0},
    };
    QStringList table_name = {"ska_ccu_global_out_mvb1", "value"};

    m_tableWidget = new QTableWidget();
    m_tableWidget->setColumnCount(2);
    m_tableWidget->setRowCount(m_outputs_map.size());
    m_tableWidget->setHorizontalHeaderLabels(table_name);
    m_tableWidget->setObjectName("ska_ccu_global_out_mvb1");

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


void Ska_Ccu_Global_Out_Mvb1::update_struct_with_map()
{
    qDebug() << "Merhaba Update Struct with map GRİŞİ" ;

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



void Ska_Ccu_Global_Out_Mvb1::update_table()
{

    for(const auto & map:m_outputs_map){
        //qDebug() <<  map.first << map.second;
        utils::setTableWidgetValueByName(m_tableWidget, map.first, 1, map.second );
    }
}

void Ska_Ccu_Global_Out_Mvb1::update_map()
{

    m_outputs_map.at("Lifesign")                    = m_ska_ccu_global_out_mvb1.bits.Lifesign;
    m_outputs_map.at("reserved_1")                  = m_ska_ccu_global_out_mvb1.bits.reserved_1;
    m_outputs_map.at("reserved_2")                  = m_ska_ccu_global_out_mvb1.bits.reserved_2;
    m_outputs_map.at("S_Coupling")                  = m_ska_ccu_global_out_mvb1.bits.S_Coupling;
    m_outputs_map.at("S_Lead_Follow_consist")       = m_ska_ccu_global_out_mvb1.bits.S_Lead_Follow_consist;
    m_outputs_map.at("S_CAB_Active")                = m_ska_ccu_global_out_mvb1.bits.S_CAB_Active;
    m_outputs_map.at("S_Direction")                 = m_ska_ccu_global_out_mvb1.bits.S_Direction;
    m_outputs_map.at("CouplingStatus")              = m_ska_ccu_global_out_mvb1.bits.CouplingStatus;
    m_outputs_map.at("_1stTrainSetConfiguration")   = m_ska_ccu_global_out_mvb1.bits._1stTrainSetConfiguration;
    m_outputs_map.at("_2ndTrainSetConfiguration")   = m_ska_ccu_global_out_mvb1.bits._2ndTrainSetConfiguration;
    m_outputs_map.at("reserved_12")                 = m_ska_ccu_global_out_mvb1.bits.reserved_12;
    m_outputs_map.at("reserved_13")                 = m_ska_ccu_global_out_mvb1.bits.reserved_13;
    m_outputs_map.at("reserved_14")                 = m_ska_ccu_global_out_mvb1.bits.reserved_14;
    m_outputs_map.at("reserved_15")                 = m_ska_ccu_global_out_mvb1.bits.reserved_15;
}



void Ska_Ccu_Global_Out_Mvb1::set_struct()
{
    m_ska_ccu_global_out_mvb1.bits.Lifesign = m_outputs_map.at("Lifesign")                  ;
    m_ska_ccu_global_out_mvb1.bits.reserved_1 = m_outputs_map.at("reserved_1")                ;
    m_ska_ccu_global_out_mvb1.bits.reserved_2 = m_outputs_map.at("reserved_2")                ;
    m_ska_ccu_global_out_mvb1.bits.S_Coupling = m_outputs_map.at("S_Coupling")                ;
    m_ska_ccu_global_out_mvb1.bits.S_Lead_Follow_consist = m_outputs_map.at("S_Lead_Follow_consist")     ;
    m_ska_ccu_global_out_mvb1.bits.S_CAB_Active = m_outputs_map.at("S_CAB_Active")              ;
    m_ska_ccu_global_out_mvb1.bits.S_Direction = m_outputs_map.at("S_Direction")               ;
    m_ska_ccu_global_out_mvb1.bits.CouplingStatus = m_outputs_map.at("CouplingStatus")            ;
    m_ska_ccu_global_out_mvb1.bits._1stTrainSetConfiguration = m_outputs_map.at("_1stTrainSetConfiguration") ;
    m_ska_ccu_global_out_mvb1.bits._2ndTrainSetConfiguration = m_outputs_map.at("_2ndTrainSetConfiguration") ;
    m_ska_ccu_global_out_mvb1.bits.reserved_12 = m_outputs_map.at("reserved_12")               ;
    m_ska_ccu_global_out_mvb1.bits.reserved_13 = m_outputs_map.at("reserved_13")               ;
    m_ska_ccu_global_out_mvb1.bits.reserved_14 = m_outputs_map.at("reserved_14")               ;
    m_ska_ccu_global_out_mvb1.bits.reserved_15 = m_outputs_map.at("reserved_15")               ;


}
