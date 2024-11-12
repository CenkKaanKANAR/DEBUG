#include "ska_ccu_do_card.h"
#include "utils.h"
#include <QDebug>

Ska_Ccu_Do_Card::Ska_Ccu_Do_Card(QObject *parent)
    : QObject{parent}
{
    // Init SKA1 Table Contents
    init_ska_x_table(SKA_VEHICLE_NUM::SKA1);

    // Init SKA2 Table Contents
    init_ska_x_table(SKA_VEHICLE_NUM::SKA2);

    make_signal_slot_connection();
}

Ska_Ccu_Do_Card::~Ska_Ccu_Do_Card()
{
    for(int i= 0; i<2; i++)
    {
        delete m_tableWidget[i];
    }
}

void Ska_Ccu_Do_Card::make_signal_slot_connection()
{
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1);
    });

    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2);
    });
}

void Ska_Ccu_Do_Card::init_ska_x_table(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_inputs_map[ska_num] = {
        {"CCU_DO0" , 0},
        {"CCU_DO1" , 0},
        {"CCU_DO2" , 0},
        {"CCU_DO3" , 0},
        {"bit4" , 0},
        {"bit5" , 0},
        {"bit6" , 0},
        {"bit7" , 0}
    };

    m_tableWidget[ska_num] = new QTableWidget();
    m_tableWidget[ska_num] ->setColumnCount(2);
    m_tableWidget[ska_num] ->setRowCount(m_inputs_map[ska_num].size());
    m_tableWidget[ska_num]->setHorizontalHeaderLabels(table_name[ska_num]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[ska_num]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[ska_num]->setItem(row, 0, item_name);
        m_tableWidget[ska_num]->setItem(row, 1, item_val);
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[ska_num]->resizeColumnsToContents();
}

void Ska_Ccu_Do_Card::update_map(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_inputs_map[ska_num].at("CCU_DO0") = m_ska_x_ccu_do_card[ska_num].bits.CCU_DO0;
    m_inputs_map[ska_num].at("CCU_DO1") = m_ska_x_ccu_do_card[ska_num].bits.CCU_DO1;
    m_inputs_map[ska_num].at("CCU_DO2") = m_ska_x_ccu_do_card[ska_num].bits.CCU_DO2;
    m_inputs_map[ska_num].at("CCU_DO3") = m_ska_x_ccu_do_card[ska_num].bits.CCU_DO3;
    m_inputs_map[ska_num].at("bit4")    = m_ska_x_ccu_do_card[ska_num].bits.bit4   ;
    m_inputs_map[ska_num].at("bit5")    = m_ska_x_ccu_do_card[ska_num].bits.bit5   ;
    m_inputs_map[ska_num].at("bit6")    = m_ska_x_ccu_do_card[ska_num].bits.bit6   ;
    m_inputs_map[ska_num].at("bit7")    = m_ska_x_ccu_do_card[ska_num].bits.bit7   ;
}

void Ska_Ccu_Do_Card::update_table(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);

    for(const auto & map:m_inputs_map[ska_num]){
        //qDebug() <<  map.first << map.second;
        utils::setTableWidgetValueByName(m_tableWidget[ska_num], map.first, 1, map.second );
    }
}


void Ska_Ccu_Do_Card::update_struct_with_map(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    // Define a lambda function to reduce redundancy
    auto setInputMap = [&](const QString& signal_name) {
        m_inputs_map[ska_num][signal_name] = utils::getTableWidgetValueByName(m_tableWidget[ska_num], signal_name, 1).toInt();
    };

    // update map with given tableWidget values
    for(const auto& map : m_inputs_map[ska_num])
    {
        setInputMap(map.first);
    }
    // set struct parameters with given updated map parameters
    set_struct(ska_x_num);
}

void Ska_Ccu_Do_Card::set_struct(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);

    m_ska_x_ccu_do_card[ska_num].bits.CCU_DO0   = m_inputs_map[ska_num].at("CCU_DO0");
    m_ska_x_ccu_do_card[ska_num].bits.CCU_DO1   = m_inputs_map[ska_num].at("CCU_DO1");
    m_ska_x_ccu_do_card[ska_num].bits.CCU_DO2   = m_inputs_map[ska_num].at("CCU_DO2");
    m_ska_x_ccu_do_card[ska_num].bits.CCU_DO3   = m_inputs_map[ska_num].at("CCU_DO3");
    m_ska_x_ccu_do_card[ska_num].bits.bit4      = m_inputs_map[ska_num].at("bit4");
    m_ska_x_ccu_do_card[ska_num].bits.bit5      = m_inputs_map[ska_num].at("bit5");
    m_ska_x_ccu_do_card[ska_num].bits.bit6      = m_inputs_map[ska_num].at("bit6");
    m_ska_x_ccu_do_card[ska_num].bits.bit7      = m_inputs_map[ska_num].at("bit7");

}
