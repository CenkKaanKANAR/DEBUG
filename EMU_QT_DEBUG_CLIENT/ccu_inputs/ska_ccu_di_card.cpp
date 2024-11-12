#include "ska_ccu_di_card.h"
#include "utils.h"
#include <QDebug>

Ska_Ccu_Di_Card::Ska_Ccu_Di_Card(QObject *parent)
    : QObject{parent}
{
    // Init SKA1 Table Contents
    init_ska_x_table(SKA_VEHICLE_NUM::SKA1);

    // Init SKA2 Table Contents
    init_ska_x_table(SKA_VEHICLE_NUM::SKA2);

    make_signal_slot_connection();
}

Ska_Ccu_Di_Card::~Ska_Ccu_Di_Card()
{
    for(int i= 0; i<2; i++)
    {
        delete m_tableWidget[i];
    }
}

void Ska_Ccu_Di_Card::make_signal_slot_connection()
{

    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1);
    });

    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2);
    });
}

void Ska_Ccu_Di_Card::init_ska_x_table(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_inputs_map[ska_num] = {
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


void Ska_Ccu_Di_Card::update_map(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_inputs_map[ska_num].at("CCU_DI0")     = m_ska_x_ccu_di_card[ska_num].bits.CCU_DI0;
    m_inputs_map[ska_num].at("CCU_DI1")     = m_ska_x_ccu_di_card[ska_num].bits.CCU_DI1;
    m_inputs_map[ska_num].at("CCU_DI2")     = m_ska_x_ccu_di_card[ska_num].bits.CCU_DI2;
    m_inputs_map[ska_num].at("CCU_DI3")     = m_ska_x_ccu_di_card[ska_num].bits.CCU_DI3;
    m_inputs_map[ska_num].at("CCU_DI4")     = m_ska_x_ccu_di_card[ska_num].bits.CCU_DI4;
    m_inputs_map[ska_num].at("CCU_DI5")     = m_ska_x_ccu_di_card[ska_num].bits.CCU_DI5;
    m_inputs_map[ska_num].at("CCU_DI6")     = m_ska_x_ccu_di_card[ska_num].bits.CCU_DI6;
    m_inputs_map[ska_num].at("CCU_DI7")     = m_ska_x_ccu_di_card[ska_num].bits.CCU_DI7;
    m_inputs_map[ska_num].at("CCU_DI8")     = m_ska_x_ccu_di_card[ska_num].bits.CCU_DI8;
    m_inputs_map[ska_num].at("CCU_DI9")     = m_ska_x_ccu_di_card[ska_num].bits.CCU_DI9;
    m_inputs_map[ska_num].at("CCU_DI10")    = m_ska_x_ccu_di_card[ska_num].bits.CCU_DI10;
    m_inputs_map[ska_num].at("CCU_DI11")    = m_ska_x_ccu_di_card[ska_num].bits.CCU_DI11;
    m_inputs_map[ska_num].at("bit12")       = m_ska_x_ccu_di_card[ska_num].bits.bit12;
    m_inputs_map[ska_num].at("bit13")       = m_ska_x_ccu_di_card[ska_num].bits.bit13;
    m_inputs_map[ska_num].at("bit14")       = m_ska_x_ccu_di_card[ska_num].bits.bit14;
    m_inputs_map[ska_num].at("bit15")       = m_ska_x_ccu_di_card[ska_num].bits.bit15;


}

void Ska_Ccu_Di_Card::update_table(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    // İndeksleri kullanarak tabloyu güncelle
    qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num]->columnCount() ;
    std::vector<int> valueColumns = {1, 3, 5, 7};
    for(const auto & map:m_inputs_map[ska_num]){


        utils::setTableWidgetValueByNameWithoutColumn(m_tableWidget[ska_num], map.first, map.second);
        //qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT INSIDE FOR LOOP ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;

        //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,3, map.second);
        //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,5, map.second);
        //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,7, map.second);
    }

}

void Ska_Ccu_Di_Card::set_data_struct(const QByteArray &input, const SKA_VEHICLE_NUM &ska_x_num)
{

    //int oa_num = static_cast<int>(oa_x_num);
    qDebug() << "azdan az çoktan çok " ;
    qDebug() << "size of input " << input.size();
    qDebug() << "Gelen input verileri :  " << input;
    //qDebug() << "Gelen input veri tipi : " << typeof(input);


    int ska_num = static_cast<int>(ska_x_num);
    qDebug() << "bassana lan şunu sizeof(m_oa_x_jru[oa_num])  " << sizeof(m_ska_x_ccu_di_card[ska_num]);

    if (input.size() == sizeof(m_ska_x_ccu_di_card[ska_num])) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        //memcpy(&m_oa_x_etcs[oa_num], input.constData(), sizeof(m_oa_x_etcs[oa_num]));

        qDebug() << "SIZE of MVB1 :  " << sizeof(m_ska_x_ccu_di_card[ska_num].bytes);



        // İlk alanı kopyala
        memcpy(&m_ska_x_ccu_di_card[ska_num].bytes, input.constData(), sizeof(m_ska_x_ccu_di_card[ska_num].bytes));

        QByteArray data =  input.mid(0, 32);
        qDebug() << "32 Bytelık data :  " << data;
        update_map(ska_x_num);
        //set_struct_mvb1(oa_x_num);
        update_table(ska_x_num);

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


void Ska_Ccu_Di_Card::update_struct_with_map(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    // Define a lambda function to reduce redundancy
    auto setInputMap = [&](const QString& signal_name) {
        m_inputs_map[ska_num][signal_name] = utils::getTableWidgetValueByNameWithoutColumn(m_tableWidget[ska_num], signal_name).toInt();
    };

    // update map with given tableWidget values
    for(const auto& map : m_inputs_map[ska_num])
    {
        setInputMap(map.first);
    }
    // set struct parameters with given updated map parameters
    set_struct(ska_x_num);
}

void Ska_Ccu_Di_Card::set_struct(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_ska_x_ccu_di_card[ska_num].bits.CCU_DI0   =m_inputs_map[ska_num].at("CCU_DI0");
    m_ska_x_ccu_di_card[ska_num].bits.CCU_DI1   =m_inputs_map[ska_num].at("CCU_DI1");
    m_ska_x_ccu_di_card[ska_num].bits.CCU_DI2   =m_inputs_map[ska_num].at("CCU_DI2");
    m_ska_x_ccu_di_card[ska_num].bits.CCU_DI3   =m_inputs_map[ska_num].at("CCU_DI3");
    m_ska_x_ccu_di_card[ska_num].bits.CCU_DI4   =m_inputs_map[ska_num].at("CCU_DI4");
    m_ska_x_ccu_di_card[ska_num].bits.CCU_DI5   =m_inputs_map[ska_num].at("CCU_DI5");
    m_ska_x_ccu_di_card[ska_num].bits.CCU_DI6   =m_inputs_map[ska_num].at("CCU_DI6");
    m_ska_x_ccu_di_card[ska_num].bits.CCU_DI7   =m_inputs_map[ska_num].at("CCU_DI7");
    m_ska_x_ccu_di_card[ska_num].bits.CCU_DI8   =m_inputs_map[ska_num].at("CCU_DI8");
    m_ska_x_ccu_di_card[ska_num].bits.CCU_DI9   =m_inputs_map[ska_num].at("CCU_DI9");
    m_ska_x_ccu_di_card[ska_num].bits.CCU_DI10  =m_inputs_map[ska_num].at("CCU_DI10");
    m_ska_x_ccu_di_card[ska_num].bits.CCU_DI11  =m_inputs_map[ska_num].at("CCU_DI11");
    m_ska_x_ccu_di_card[ska_num].bits.bit12     =m_inputs_map[ska_num].at("bit12");
    m_ska_x_ccu_di_card[ska_num].bits.bit13     =m_inputs_map[ska_num].at("bit13");
    m_ska_x_ccu_di_card[ska_num].bits.bit14     =m_inputs_map[ska_num].at("bit14");
    m_ska_x_ccu_di_card[ska_num].bits.bit15     =m_inputs_map[ska_num].at("bit15");

}
