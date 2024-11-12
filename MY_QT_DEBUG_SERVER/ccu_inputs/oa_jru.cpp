#include "oa_jru.h"
#include "utils.h"
//BURADA KALDIK AT()
Oa_Jru::Oa_Jru(QObject *parent)
    : QObject{parent}
{
    // reset values
    memset(&m_oa_x_jru, 0, sizeof(m_oa_x_jru));
    // Init OA1 Table Contents
    init_oa_x_mvb1_table(OA_VEHICLE_NUM::OA1);
    // Init OA2 Table Contents
    init_oa_x_mvb1_table(OA_VEHICLE_NUM::OA2);

    make_signal_slot_connection();


}


Oa_Jru::~Oa_Jru()
{
    for (int i = 0; i < 2; ++i) {
        delete m_tableWidget[i];
        m_tableWidget[i]= nullptr;
    }
}

void Oa_Jru::make_signal_slot_connection()
{
    // OA1 MVB1 connection slot
    connect(m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(OA_VEHICLE_NUM::OA1, MVB1);
    });
    // OA1 MVB2 connection slot
    connect(m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(OA_VEHICLE_NUM::OA2, MVB1);
    });
}


void Oa_Jru::set_data_struct(const QByteArray &input, const OA_VEHICLE_NUM &oa_x_num)
{

    //int oa_num = static_cast<int>(oa_x_num);
    qDebug() << "azdan az çoktan çok " ;
    qDebug() << "size of input " << input.size();
    qDebug() << "Gelen input verileri :  " << input;
    //qDebug() << "Gelen input veri tipi : " << typeof(input);


    int oa_num = static_cast<int>(oa_x_num);
    qDebug() << "bassana lan şunu sizeof(m_oa_x_jru[oa_num])  " << sizeof(m_oa_x_jru[oa_num]);

    if (input.size() == sizeof(m_oa_x_jru[oa_num])) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        //memcpy(&m_oa_x_etcs[oa_num], input.constData(), sizeof(m_oa_x_etcs[oa_num]));

        qDebug() << "SIZE of MVB1 :  " << sizeof(m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bytes);



        // İlk alanı kopyala
        memcpy(&m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bytes, input.constData(), sizeof(m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bytes));

        QByteArray data =  input.mid(0, 32);
        qDebug() << "32 Bytelık data :  " << data;
        update_mvb1_map(oa_x_num);
        //set_struct_mvb1(oa_x_num);
        update_table(oa_x_num);

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


void Oa_Jru::update_table(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);
    // İndeksleri kullanarak tabloyu güncelle
    qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT ========== :  " << m_tableWidget[oa_num]->columnCount() ;
    std::vector<int> valueColumns = {1, 3, 5, 7};
    for(const auto & map:m_inputs_map[oa_num]){


        utils::setTableWidgetValueByNameWithoutColumn(m_tableWidget[oa_num], map.first, map.second);
        //qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT INSIDE FOR LOOP ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;

        //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,3, map.second);
        //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,5, map.second);
        //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,7, map.second);
    }

}

void Oa_Jru::update_mvb1_map(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);
    m_inputs_map[oa_num].at("Speed")                       = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Speed;
    m_inputs_map[oa_num].at("Milage_today")                = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Milage_today;
    m_inputs_map[oa_num].at("Milage_total")                = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Milage_total;
    m_inputs_map[oa_num].at("Badge_id_byte1")              = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Badge_id_byte1;
    m_inputs_map[oa_num].at("Badge_id_byte2")              = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Badge_id_byte2;
    m_inputs_map[oa_num].at("Badge_id_byte3")              = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Badge_id_byte3;
    m_inputs_map[oa_num].at("Badge_id_byte4")              = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Badge_id_byte4;
    m_inputs_map[oa_num].at("Badge_id_byte5")              = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Badge_id_byte5;
    m_inputs_map[oa_num].at("Badge_id_byte6")              = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Badge_id_byte6;
    m_inputs_map[oa_num].at("Badge_id_byte7")              = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Badge_id_byte7;
    m_inputs_map[oa_num].at("Memory_fullness")             = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Memory_fullness;
    m_inputs_map[oa_num].at("Current_internal_temp")       = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Current_internal_temp;
    m_inputs_map[oa_num].at("Number_of_active_warnings")   = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Number_of_active_warnings;
    m_inputs_map[oa_num].at("Number_of_active_errors")     = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Number_of_active_errors;
    m_inputs_map[oa_num].at("Number_of_active_criticals")  = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Number_of_active_criticals;
    m_inputs_map[oa_num].at("Temp_warning")                = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Temp_warning;
    m_inputs_map[oa_num].at("SABO_speed_difference")       = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.SABO_speed_difference;
    m_inputs_map[oa_num].at("SABO_comp_result_fail")       = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.SABO_comp_result_fail;
    m_inputs_map[oa_num].at("Zero_speed")                  = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Zero_speed;
    m_inputs_map[oa_num].at("Emergency_brake")             = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Emergency_brake;
    m_inputs_map[oa_num].at("Emergency_reset")             = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Emergency_reset;
    m_inputs_map[oa_num].at("bit182")                      = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit182;
    m_inputs_map[oa_num].at("bit183")                      = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit183;
    m_inputs_map[oa_num].at("Code_01") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_01;
    m_inputs_map[oa_num].at("Code_02") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_02;
    m_inputs_map[oa_num].at("Code_03") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_03;
    m_inputs_map[oa_num].at("Code_04") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_04;
    m_inputs_map[oa_num].at("Code_05") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_05;
    m_inputs_map[oa_num].at("Code_06") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_06;
    m_inputs_map[oa_num].at("Code_07") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_07;
    m_inputs_map[oa_num].at("Code_08") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_08;
    m_inputs_map[oa_num].at("Code_09") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_09;
    m_inputs_map[oa_num].at("Code_10") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_10;
    m_inputs_map[oa_num].at("Code_11") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_11;
    m_inputs_map[oa_num].at("Code_12") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_12;
    m_inputs_map[oa_num].at("Code_13") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_13;
    m_inputs_map[oa_num].at("Code_14") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_14;
    m_inputs_map[oa_num].at("Code_15") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_15;
    m_inputs_map[oa_num].at("Code_16") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_16;
    m_inputs_map[oa_num].at("Code_17") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_17;
    m_inputs_map[oa_num].at("Code_18") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_18;
    m_inputs_map[oa_num].at("Code_19") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_19;
    m_inputs_map[oa_num].at("Code_20") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_20;
    m_inputs_map[oa_num].at("Code_21") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_21;
    m_inputs_map[oa_num].at("Code_22") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_22;
    m_inputs_map[oa_num].at("Code_23") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_23;
    m_inputs_map[oa_num].at("Code_24") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_24;
    m_inputs_map[oa_num].at("Code_25") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_25;
    m_inputs_map[oa_num].at("Code_26") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_26;
    m_inputs_map[oa_num].at("Code_27") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_27;
    m_inputs_map[oa_num].at("Code_28") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_28;
    m_inputs_map[oa_num].at("Code_29") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_29;
    m_inputs_map[oa_num].at("Code_30") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_30;
    m_inputs_map[oa_num].at("Code_32") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_32;
    m_inputs_map[oa_num].at("Code_33") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_33;
    m_inputs_map[oa_num].at("Code_34") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_34;
    m_inputs_map[oa_num].at("Code_35") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_35;
    m_inputs_map[oa_num].at("bit218")  = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit218;
    m_inputs_map[oa_num].at("bit219")  = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit219;
    m_inputs_map[oa_num].at("bit220")  = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit220;
    m_inputs_map[oa_num].at("bit221")  = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit221;
    m_inputs_map[oa_num].at("bit222")  = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit222;
    m_inputs_map[oa_num].at("bit223")  = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit223;
    m_inputs_map[oa_num].at("Code_100") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_100;
    m_inputs_map[oa_num].at("Code_101") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_101;
    m_inputs_map[oa_num].at("Code_102") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_102;
    m_inputs_map[oa_num].at("Code_103") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_103;
    m_inputs_map[oa_num].at("Code_104") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_104;
    m_inputs_map[oa_num].at("Code_105") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_105;
    m_inputs_map[oa_num].at("Code_106") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_106;
    m_inputs_map[oa_num].at("Code_107") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_107;
    m_inputs_map[oa_num].at("Code_108") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_108;
    m_inputs_map[oa_num].at("Code_109") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_109;
    m_inputs_map[oa_num].at("Code_110") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_110;
    m_inputs_map[oa_num].at("bit227") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit227;
    m_inputs_map[oa_num].at("bit228") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit228;
    m_inputs_map[oa_num].at("bit229") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit229;
    m_inputs_map[oa_num].at("bit230") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit230;
    m_inputs_map[oa_num].at("bit231") = m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit231;

}

void Oa_Jru::update_struct_with_map(OA_VEHICLE_NUM oa_x_num, OA_MVB_NUM mvb_num)
{
    (void)mvb_num; // unused_variable
    int oa_num = static_cast<int>(oa_x_num);
    // Define a lambda function to reduce redundancy
    auto setInputMap = [&](const QString& signal_name) {
        m_inputs_map[oa_num][signal_name] = utils::getTableWidgetValueByNameWithoutColumn(m_tableWidget[oa_num], signal_name).toInt();
    };
    // update map with given tableWidget values
    for(const auto& map : m_inputs_map[oa_num])
    {
        setInputMap(map.first);
    }
    // set struct parameters with given updated map parameters
    set_struct_mvb1(oa_x_num);
}


void Oa_Jru::set_struct_mvb1(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);

m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Speed                       = m_inputs_map[oa_num].at("Speed");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Milage_today                = m_inputs_map[oa_num].at("Milage_today");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Milage_total                = m_inputs_map[oa_num].at("Milage_total");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Badge_id_byte1              = m_inputs_map[oa_num].at("Badge_id_byte1");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Badge_id_byte2              = m_inputs_map[oa_num].at("Badge_id_byte2");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Badge_id_byte3              = m_inputs_map[oa_num].at("Badge_id_byte3");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Badge_id_byte4              = m_inputs_map[oa_num].at("Badge_id_byte4");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Badge_id_byte5              = m_inputs_map[oa_num].at("Badge_id_byte5");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Badge_id_byte6              = m_inputs_map[oa_num].at("Badge_id_byte6");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Badge_id_byte7              = m_inputs_map[oa_num].at("Badge_id_byte7");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Memory_fullness             = m_inputs_map[oa_num].at("Memory_fullness");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Current_internal_temp       = m_inputs_map[oa_num].at("Current_internal_temp");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Number_of_active_warnings   = m_inputs_map[oa_num].at("Number_of_active_warnings");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Number_of_active_errors     = m_inputs_map[oa_num].at("Number_of_active_errors");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Number_of_active_criticals  = m_inputs_map[oa_num].at("Number_of_active_criticals");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Temp_warning                = m_inputs_map[oa_num].at("Temp_warning");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.SABO_speed_difference       = m_inputs_map[oa_num].at("SABO_speed_difference");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.SABO_comp_result_fail       = m_inputs_map[oa_num].at("SABO_comp_result_fail");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Zero_speed                  = m_inputs_map[oa_num].at("Zero_speed");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Emergency_brake             = m_inputs_map[oa_num].at("Emergency_brake");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Emergency_reset             = m_inputs_map[oa_num].at("Emergency_reset");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit182                      = m_inputs_map[oa_num].at("bit182");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit183                      = m_inputs_map[oa_num].at("bit183");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_01                     = m_inputs_map[oa_num].at("Code_01");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_02                     = m_inputs_map[oa_num].at("Code_02");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_03                     = m_inputs_map[oa_num].at("Code_03");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_04                     = m_inputs_map[oa_num].at("Code_04");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_05                     = m_inputs_map[oa_num].at("Code_05");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_06                     = m_inputs_map[oa_num].at("Code_06");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_07                     = m_inputs_map[oa_num].at("Code_07");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_08                     = m_inputs_map[oa_num].at("Code_08");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_09                     = m_inputs_map[oa_num].at("Code_09");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_10                     = m_inputs_map[oa_num].at("Code_10");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_11                     = m_inputs_map[oa_num].at("Code_11");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_12                     = m_inputs_map[oa_num].at("Code_12");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_13                     = m_inputs_map[oa_num].at("Code_13");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_14                     = m_inputs_map[oa_num].at("Code_14");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_15                     = m_inputs_map[oa_num].at("Code_15");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_16                     = m_inputs_map[oa_num].at("Code_16");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_17                     = m_inputs_map[oa_num].at("Code_17");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_18                     = m_inputs_map[oa_num].at("Code_18");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_19                     = m_inputs_map[oa_num].at("Code_19");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_20                     = m_inputs_map[oa_num].at("Code_20");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_21                     = m_inputs_map[oa_num].at("Code_21");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_22                     = m_inputs_map[oa_num].at("Code_22");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_23                     = m_inputs_map[oa_num].at("Code_23");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_24                     = m_inputs_map[oa_num].at("Code_24");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_25                     = m_inputs_map[oa_num].at("Code_25");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_26                     = m_inputs_map[oa_num].at("Code_26");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_27                     = m_inputs_map[oa_num].at("Code_27");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_28                     = m_inputs_map[oa_num].at("Code_28");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_29                     = m_inputs_map[oa_num].at("Code_29");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_30                     = m_inputs_map[oa_num].at("Code_30");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_32                     = m_inputs_map[oa_num].at("Code_32");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_33                     = m_inputs_map[oa_num].at("Code_33");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_34                     = m_inputs_map[oa_num].at("Code_34");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_35                     = m_inputs_map[oa_num].at("Code_35");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit218                      = m_inputs_map[oa_num].at("bit218");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit219                      = m_inputs_map[oa_num].at("bit219");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit220                      = m_inputs_map[oa_num].at("bit220");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit221                      = m_inputs_map[oa_num].at("bit221");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit222                      = m_inputs_map[oa_num].at("bit222");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit223                      = m_inputs_map[oa_num].at("bit223");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_100                    = m_inputs_map[oa_num].at("Code_100");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_101                    = m_inputs_map[oa_num].at("Code_101");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_102                    = m_inputs_map[oa_num].at("Code_102");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_103                    = m_inputs_map[oa_num].at("Code_103");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_104                    = m_inputs_map[oa_num].at("Code_104");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_105                    = m_inputs_map[oa_num].at("Code_105");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_106                    = m_inputs_map[oa_num].at("Code_106");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_107                    = m_inputs_map[oa_num].at("Code_107");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_108                    = m_inputs_map[oa_num].at("Code_108");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_109                    = m_inputs_map[oa_num].at("Code_109");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.Code_110                    = m_inputs_map[oa_num].at("Code_110");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit227                      = m_inputs_map[oa_num].at("bit227");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit228                      = m_inputs_map[oa_num].at("bit228");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit229                      = m_inputs_map[oa_num].at("bit229");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit230                      = m_inputs_map[oa_num].at("bit230");
m_oa_x_jru[oa_num].oa_jru_ccu_mvb1.bits.bit231                      = m_inputs_map[oa_num].at("bit231");


}

void Oa_Jru::init_oa_x_mvb1_table(OA_VEHICLE_NUM vehicle_type)
{
    int oa_num = static_cast<int>(vehicle_type);
    m_inputs_map[oa_num] = {
        {"Speed", 0},
        {"Milage_today", 0},
        {"Milage_total", 0},
        {"Badge_id_byte1", 0},
        {"Badge_id_byte2", 0},
        {"Badge_id_byte3", 0},
        {"Badge_id_byte4", 0},
        {"Badge_id_byte5", 0},
        {"Badge_id_byte6", 0},
        {"Badge_id_byte7", 0},
        {"Memory_fullness", 0},
        {"Current_internal_temp", 0},
        {"Number_of_active_warnings", 0},
        {"Number_of_active_errors", 0},
        {"Number_of_active_criticals", 0},
        {"Temp_warning", 0},
        {"SABO_speed_difference", 0},
        {"SABO_comp_result_fail", 0},
        {"Zero_speed", 0},
        {"Emergency_brake", 0},
        {"Emergency_reset", 0},
        {"bit182", 0},
        {"bit183", 0},
        {"Code_01", 0},
        {"Code_02", 0},
        {"Code_03", 0},
        {"Code_04", 0},
        {"Code_05", 0},
        {"Code_06", 0},
        {"Code_07", 0},
        {"Code_08", 0},
        {"Code_09", 0},
        {"Code_10", 0},
        {"Code_11", 0},
        {"Code_12", 0},
        {"Code_13", 0},
        {"Code_14", 0},
        {"Code_15", 0},
        {"Code_16", 0},
        {"Code_17", 0},
        {"Code_18", 0},
        {"Code_19", 0},
        {"Code_20", 0},
        {"Code_21", 0},
        {"Code_22", 0},
        {"Code_23", 0},
        {"Code_24", 0},
        {"Code_25", 0},
        {"Code_26", 0},
        {"Code_27", 0},
        {"Code_28", 0},
        {"Code_29", 0},
        {"Code_30", 0},
        {"Code_32", 0},
        {"Code_33", 0},
        {"Code_34", 0},
        {"Code_35", 0},
        {"bit218", 0},
        {"bit219", 0},
        {"bit220", 0},
        {"bit221", 0},
        {"bit222", 0},
        {"bit223", 0},
        {"Code_100", 0},
        {"Code_101", 0},
        {"Code_102", 0},
        {"Code_103", 0},
        {"Code_104", 0},
        {"Code_105", 0},
        {"Code_106", 0},
        {"Code_107", 0},
        {"Code_108", 0},
        {"Code_109", 0},
        {"Code_110", 0},
        {"bit227", 0},
        {"bit228", 0},
        {"bit229", 0},
        {"bit230", 0},
        {"bit231", 0}
    };

    /*m_tableWidget[oa_num] = new QTableWidget();
    m_tableWidget[oa_num]->setColumnCount(2);
    m_tableWidget[oa_num]->setRowCount(m_inputs_map[oa_num].size());
    m_tableWidget[oa_num]->setHorizontalHeaderLabels(table_name[oa_num]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[oa_num]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[oa_num]->setItem(row, 0, item_name);
        m_tableWidget[oa_num]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[oa_num]->resizeColumnsToContents();*/


    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[oa_num].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[oa_num] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[oa_num]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[oa_num]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[oa_num]->setItem(row, column, item_name);
        m_tableWidget[oa_num]->setItem(row, column + 1, item_val); // Değer

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[oa_num]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[oa_num]->columnCount() ;

}
