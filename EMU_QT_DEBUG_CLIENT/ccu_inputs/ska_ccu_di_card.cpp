#include "ska_ccu_di_card.h"
#include "utils.h"
#include <QDebug>

Ska_Ccu_Di_Card::Ska_Ccu_Di_Card(QObject *parent)
    : QObject{parent}
{
    // Init SKA1 Table Contents
    init_ska_x_table();

    // Init SKA2 Table Contents


    make_signal_slot_connection();
}

Ska_Ccu_Di_Card::~Ska_Ccu_Di_Card()
{

        delete m_tableWidget;

}

void Ska_Ccu_Di_Card::make_signal_slot_connection()
{

    connect(m_tableWidget, &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map();
    });

}

void Ska_Ccu_Di_Card::init_ska_x_table()
{

    m_inputs_map = {
        {"CCU_DI0" , 0},
        {"CCU_DI1" , 0},
        {"CCU_DI2" , 0},
        {"CCU_DI3" , 0},
        {"CCU_DI4" , 0},
        {"CCU_DI5" , 0},
        {"CCU_DI6" , 0},
        {"CCU_DI7" , 0},
        {"CCU_DI8" , 0},
        {"CCU_DI9" , 0},
        {"CCU_DI10", 0},
        {"CCU_DI11", 0},
        {"bit12" , 0},
        {"bit13" , 0},
        {"bit14" , 0},
        {"bit15" , 0}
    };

    m_tableWidget = new QTableWidget();
    m_tableWidget ->setColumnCount(2);
    m_tableWidget ->setRowCount(m_inputs_map.size());
    m_tableWidget->setHorizontalHeaderLabels(table_name[0]);

    int row = 0;
    for (const auto& pair:  m_inputs_map) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget->setItem(row, 0, item_name);
        m_tableWidget->setItem(row, 1, item_val);
        item_name->setBackground(QColor("turquoise"));  // Turkuaz
        item_val->setBackground(QColor("turquoise"));  // Turkuaz
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget->resizeColumnsToContents();
}


void Ska_Ccu_Di_Card::update_map()
{

    m_inputs_map.at("CCU_DI0")     = m_ska_x_ccu_di_card.bits.CCU_DI0;
    m_inputs_map.at("CCU_DI1")     = m_ska_x_ccu_di_card.bits.CCU_DI1;
    m_inputs_map.at("CCU_DI2")     = m_ska_x_ccu_di_card.bits.CCU_DI2;
    m_inputs_map.at("CCU_DI3")     = m_ska_x_ccu_di_card.bits.CCU_DI3;
    m_inputs_map.at("CCU_DI4")     = m_ska_x_ccu_di_card.bits.CCU_DI4;
    m_inputs_map.at("CCU_DI5")     = m_ska_x_ccu_di_card.bits.CCU_DI5;
    m_inputs_map.at("CCU_DI6")     = m_ska_x_ccu_di_card.bits.CCU_DI6;
    m_inputs_map.at("CCU_DI7")     = m_ska_x_ccu_di_card.bits.CCU_DI7;
    m_inputs_map.at("CCU_DI8")     = m_ska_x_ccu_di_card.bits.CCU_DI8;
    m_inputs_map.at("CCU_DI9")     = m_ska_x_ccu_di_card.bits.CCU_DI9;
    m_inputs_map.at("CCU_DI10")    = m_ska_x_ccu_di_card.bits.CCU_DI10;
    m_inputs_map.at("CCU_DI11")    = m_ska_x_ccu_di_card.bits.CCU_DI11;
    m_inputs_map.at("bit12")       = m_ska_x_ccu_di_card.bits.bit12;
    m_inputs_map.at("bit13")       = m_ska_x_ccu_di_card.bits.bit13;
    m_inputs_map.at("bit14")       = m_ska_x_ccu_di_card.bits.bit14;
    m_inputs_map.at("bit15")       = m_ska_x_ccu_di_card.bits.bit15;


}

void Ska_Ccu_Di_Card::update_table()
{
    for(const auto & map:m_inputs_map){
        //qDebug() <<  map.first << map.second;
        utils::setTableWidgetValueByName(m_tableWidget, map.first, 1, map.second );
    }

}

void Ska_Ccu_Di_Card::set_data_struct(const QByteArray &input)
{

    //int oa_num = static_cast<int>(oa_x_num);
     qDebug() << "DI CARD SET DATA STUCT IÇINDE " ;
    qDebug() << "azdan az çoktan çok " ;
    qDebug() << "size of input " << input.size();
    qDebug() << "Gelen input verileri :  " << input;
    //qDebug() << "Gelen input veri tipi : " << typeof(input);


    qDebug() << "bassana lan şunu sizeof(ska_di_card)  " << sizeof(m_ska_x_ccu_di_card);

    if (input.size() == sizeof(m_ska_x_ccu_di_card)) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        //memcpy(&m_oa_x_etcs[oa_num], input.constData(), sizeof(m_oa_x_etcs[oa_num]));

        qDebug() << "SIZE of DI CARD :  " << sizeof(m_ska_x_ccu_di_card.bytes);



        // İlk alanı kopyala
        memcpy(&m_ska_x_ccu_di_card.bytes, input.constData(), sizeof(m_ska_x_ccu_di_card.bytes));

        QByteArray data =  input.mid(0, 32);
        qDebug() << "32 Bytelık data :  " << data;
        update_map();
        //set_struct_mvb1(oa_x_num);
        update_table();

        //update maps

        //
        //
        //update tables

        //
        //
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }

}


void Ska_Ccu_Di_Card::update_struct_with_map()
{
    qDebug() << "Merhaba Update Struct with map GRİŞİ" ;

    auto setInputMap = [&](const QString& signal_name) {
        m_inputs_map[signal_name] = utils::getTableWidgetValueByNameWithoutColumn(m_tableWidget, signal_name).toInt();
    };
    // update map with given tableWidget values
    for(const auto& map : m_inputs_map)
    {
        setInputMap(map.first);
    }
    // set struct parameters with given updated map parameters
    set_struct();
}

void Ska_Ccu_Di_Card::set_struct()
{

    m_ska_x_ccu_di_card.bits.CCU_DI0   =m_inputs_map.at("CCU_DI0");
    m_ska_x_ccu_di_card.bits.CCU_DI1   =m_inputs_map.at("CCU_DI1");
    m_ska_x_ccu_di_card.bits.CCU_DI2   =m_inputs_map.at("CCU_DI2");
    m_ska_x_ccu_di_card.bits.CCU_DI3   =m_inputs_map.at("CCU_DI3");
    m_ska_x_ccu_di_card.bits.CCU_DI4   =m_inputs_map.at("CCU_DI4");
    m_ska_x_ccu_di_card.bits.CCU_DI5   =m_inputs_map.at("CCU_DI5");
    m_ska_x_ccu_di_card.bits.CCU_DI6   =m_inputs_map.at("CCU_DI6");
    m_ska_x_ccu_di_card.bits.CCU_DI7   =m_inputs_map.at("CCU_DI7");
    m_ska_x_ccu_di_card.bits.CCU_DI8   =m_inputs_map.at("CCU_DI8");
    m_ska_x_ccu_di_card.bits.CCU_DI9   =m_inputs_map.at("CCU_DI9");
    m_ska_x_ccu_di_card.bits.CCU_DI10  =m_inputs_map.at("CCU_DI10");
    m_ska_x_ccu_di_card.bits.CCU_DI11  =m_inputs_map.at("CCU_DI11");
    m_ska_x_ccu_di_card.bits.bit12     =m_inputs_map.at("bit12");
    m_ska_x_ccu_di_card.bits.bit13     =m_inputs_map.at("bit13");
    m_ska_x_ccu_di_card.bits.bit14     =m_inputs_map.at("bit14");
    m_ska_x_ccu_di_card.bits.bit15     =m_inputs_map.at("bit15");

}
