#include "oa_apu.h"

#include "utils.h"

OA_APU::OA_APU(QObject *parent)
    : QObject{parent}
{

    memset(&m_oa_x_apu, 0, sizeof(m_oa_x_apu));
    // Init OA1 Table Contents
    init_oa_apu_mvb1_table(OA_VEHICLE_NUM::OA1);
    init_oa_apu_mvb2_table(OA_VEHICLE_NUM::OA1);
    init_oa_apu_mvb3_table(OA_VEHICLE_NUM::OA1);

    // Init OA2 Table Contents
    init_oa_apu_mvb1_table(OA_VEHICLE_NUM::OA2);
    init_oa_apu_mvb2_table(OA_VEHICLE_NUM::OA2);
    init_oa_apu_mvb3_table(OA_VEHICLE_NUM::OA2);

    qDebug() << "SIZE OF OA APU IS : " << sizeof(oa_apu);

    make_signal_slot_connection();


}


OA_APU::~OA_APU()
{
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            delete m_tableWidget[i][j];
            m_tableWidget[i][j] = nullptr; // Güvenlik için nullptr atayın
        }
    }
}


void OA_APU::make_signal_slot_connection()
{
    // OA1 MVB1 connection slot
    connect(m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)][MVB1], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(OA_VEHICLE_NUM::OA1, MVB1);
    });
    // OA1 MVB2 connection slot
    connect(m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)][MVB2], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(OA_VEHICLE_NUM::OA1, MVB2);
    });
    // OA1 MVB3 connection slot
    connect(m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)][MVB3], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(OA_VEHICLE_NUM::OA1, MVB3);
    });
    /////////////////////////////////////////////////////////////////////////////////////////////////////

    // OA2 MVB1 connection slot
    connect(m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)][MVB1], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(OA_VEHICLE_NUM::OA2, MVB1);
    });
    // OA2 MVB2 connection slot
    connect(m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)][MVB2], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(OA_VEHICLE_NUM::OA2, MVB2);
    });
    // OA2 MVB3 connection slot
    connect(m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)][MVB3], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(OA_VEHICLE_NUM::OA2, MVB3);
    });
}

void OA_APU::set_data_struct(const QByteArray &input, const OA_VEHICLE_NUM &oa_x_num)
{

    //int oa_num = static_cast<int>(oa_x_num);
    qDebug() << "azdan az çoktan çok " ;
    qDebug() << "size of input " << input.size();
    qDebug() << "Gelen input verileri :  " << input;
    //qDebug() << "Gelen input veri tipi : " << typeof(input);


    int oa_num = static_cast<int>(oa_x_num);

    qDebug() << "SET DATA STRUCT SIZE of OA_APU COLUMN COUNT ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;
    if (input.size() == sizeof(m_oa_x_apu[oa_num])) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        //memcpy(&m_oa_x_etcs[oa_num], input.constData(), sizeof(m_oa_x_etcs[oa_num]));

        qDebug() << "SIZE of MVB1 :  " << sizeof(m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bytes);
        qDebug() << "SIZE of MVB2 :  " << sizeof(m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bytes);
        qDebug() << "SIZE of MVB3 :  " << sizeof(m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bytes);


        // İlk alanı kopyala
        memcpy(&m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bytes, input.constData(), sizeof(m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bytes));

        QByteArray data =  input.mid(0, 32);
        qDebug() << "32 Bytelık data :  " << data;
        qDebug() << "update map1 üstü";
        update_mvb1_map(oa_x_num);
        qDebug() << "update map1 altı";
        //set_struct_mvb1(oa_x_num);
        update_table(oa_x_num,OA_APU::MVB1);
        qDebug() << "update table1 altı";

        // İkinci alanı kopyala, input.constData() + sizeof(etcs_ccu_mvb1) kadar ilerleyerek
        memcpy(&m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bytes, input.constData() + sizeof(m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bytes), sizeof(m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bytes));
        qDebug() << "update map2 üstü";
        update_mvb2_map(oa_x_num);
        qDebug() << "update map2 altı";
        //set_struct_mvb2(oa_x_num);
        update_table(oa_x_num,OA_APU::MVB2);
        qDebug() << "update table2 altı";

        // Üçüncü alanı kopyala, input.constData() + sizeof(etcs_ccu_mvb1) + sizeof(etcs_ccu_mvb2) kadar ilerleyerek
        memcpy(&m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bytes, input.constData() + sizeof(m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bytes) + sizeof(m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bytes), sizeof(m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bytes));
        qDebug() << "update map3 üstü";
        update_mvb3_map(oa_x_num);
        qDebug() << "update map3 altı";
         //set_struct_mvb3(oa_x_num);
        update_table(oa_x_num,OA_APU::MVB3);
        qDebug() << "update table3 altı";
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

void OA_APU::update_struct_with_map(OA_VEHICLE_NUM oa_x_num, OA_MVB_NUM mvb_num)
{
    int oa_num = static_cast<int>(oa_x_num);

    // Define a lambda function to reduce redundancy
    auto setInputMap = [&](const QString& signal_name) {
        m_inputs_map[oa_num][mvb_num][signal_name] = utils::getTableWidgetValueByNameWithoutColumn(m_tableWidget[oa_num][mvb_num], signal_name).toInt();
    };
    // update map with given tableWidget values
    for(const auto& map : m_inputs_map[oa_num][mvb_num])
    {
        setInputMap(map.first);
    }
    // set struct parameters with given updated map parameters

    // set struct parameters with given updated map parameters
    set_struct_mvb1(oa_x_num);
    set_struct_mvb2(oa_x_num);
    set_struct_mvb3(oa_x_num);
}

void OA_APU::update_mvb1_map(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);

    qDebug() << "KAAN 1";
    m_inputs_map[oa_num][MVB1].at("Lifesign")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Lifesign;
    m_inputs_map[oa_num][MVB1].at("APUC_App_State")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.APUC_App_State;
    m_inputs_map[oa_num][MVB1].at("Door_Open")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Door_Open;
    m_inputs_map[oa_num][MVB1].at("Mode_Select")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Mode_Select;
    m_inputs_map[oa_num][MVB1].at("APU_Emergency")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.APU_Emergency;
    m_inputs_map[oa_num][MVB1].at("APU_Start_Status")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.APU_Start_Status;
    m_inputs_map[oa_num][MVB1].at("Reset_Ack")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Reset_Ack;
    m_inputs_map[oa_num][MVB1].at("bit23")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.bit23;
    qDebug() << "KAAN 2";
    m_inputs_map[oa_num][MVB1].at("APS_Ok")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.APS_Ok;
    m_inputs_map[oa_num][MVB1].at("MV_Output_Ok")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.MV_Output_Ok;
    m_inputs_map[oa_num][MVB1].at("HV_Presence")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.HV_Presence;
    m_inputs_map[oa_num][MVB1].at("APS_Out_Con_Loop_out")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.APS_Out_Con_Loop_out;
    m_inputs_map[oa_num][MVB1].at("LV_Output_Ok")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.LV_Output_Ok;
    m_inputs_map[oa_num][MVB1].at("bit29")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.bit29;
    m_inputs_map[oa_num][MVB1].at("bit30")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.bit30;
    m_inputs_map[oa_num][MVB1].at("bit31")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.bit31;
    m_inputs_map[oa_num][MVB1].at("reserved_4")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.reserved_4;
    qDebug() << "KAAN 3";
    m_inputs_map[oa_num][MVB1].at("SW_Ver")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.SW_Ver;
    m_inputs_map[oa_num][MVB1].at("Catenary_Voltage")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Catenary_Voltage;
    m_inputs_map[oa_num][MVB1].at("Fault_Code_APUC")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Fault_Code_APUC;
    m_inputs_map[oa_num][MVB1].at("Fault_Code_PFC1")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Fault_Code_PFC1;
    m_inputs_map[oa_num][MVB1].at("Fault_Code_PFC2")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Fault_Code_PFC2;
    m_inputs_map[oa_num][MVB1].at("Fault_Code_VSI1")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Fault_Code_VSI1;
    m_inputs_map[oa_num][MVB1].at("Fault_Code_VSI2")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Fault_Code_VSI2;
    m_inputs_map[oa_num][MVB1].at("Fault_Code_BCH")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Fault_Code_BCH;
    m_inputs_map[oa_num][MVB1].at("reserved_14")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.reserved_14;
    m_inputs_map[oa_num][MVB1].at("reserved_15")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.reserved_15;
    qDebug() << "KAAN 4";


}

void OA_APU::update_mvb2_map(OA_VEHICLE_NUM oa_x_num)
{

    int oa_num = static_cast<int>(oa_x_num);
    qDebug() << "CEKO 1";
    m_inputs_map[oa_num][MVB2].at("Lifesign")                          =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.Lifesign;
    m_inputs_map[oa_num][MVB2].at("PFC1_App_State")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC1_App_State;
    m_inputs_map[oa_num][MVB2].at("PFC2_App_State")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC2_App_State;
    m_inputs_map[oa_num][MVB2].at("VSI1_App_State")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.VSI1_App_State;
    m_inputs_map[oa_num][MVB2].at("VSI2_App_State")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.VSI2_App_State;
    m_inputs_map[oa_num][MVB2].at("BCH_App_State")                     =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.BCH_App_State;
    m_inputs_map[oa_num][MVB2].at("bit26")                             =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.bit26;
    m_inputs_map[oa_num][MVB2].at("bit27")                             =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.bit27;
    m_inputs_map[oa_num][MVB2].at("bit28")                             =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.bit28;
    m_inputs_map[oa_num][MVB2].at("bit29")                             =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.bit29;
    m_inputs_map[oa_num][MVB2].at("bit30")                             =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.bit30;
    m_inputs_map[oa_num][MVB2].at("bit31")                             =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.bit31;
    m_inputs_map[oa_num][MVB2].at("PFC_A_CAN")                         =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC_A_CAN;
    qDebug() << "CEKO 2";
    m_inputs_map[oa_num][MVB2].at("PFC_B_CAN")                         =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC_B_CAN;
    m_inputs_map[oa_num][MVB2].at("VSI_A_CAN")                         =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.VSI_A_CAN;
    m_inputs_map[oa_num][MVB2].at("VSI_B_CAN")                         =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.VSI_B_CAN;
    m_inputs_map[oa_num][MVB2].at("BCH_CAN")                           =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.BCH_CAN;
    m_inputs_map[oa_num][MVB2].at("bit37")                             =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.bit37;
    m_inputs_map[oa_num][MVB2].at("bit38")                             =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.bit38;
    m_inputs_map[oa_num][MVB2].at("bit39")                             =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.bit39;
    m_inputs_map[oa_num][MVB2].at("reserved_5")                        =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.reserved_5;
    m_inputs_map[oa_num][MVB2].at("PFC1_Vs")                           =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC1_Vs;
    m_inputs_map[oa_num][MVB2].at("PFC1_Is")                           =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC1_Is;
    m_inputs_map[oa_num][MVB2].at("PFC1_Fs")                           =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC1_Fs;
    m_inputs_map[oa_num][MVB2].at("PFC1_Vo")                           =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC1_Vo;
    m_inputs_map[oa_num][MVB2].at("PFC1_Temp1")                         =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC1_Temp1;
    qDebug() << "CEKO 3";
    m_inputs_map[oa_num][MVB2].at("PFC1_Temp2")                         =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC1_Temp2;
    m_inputs_map[oa_num][MVB2].at("reserved_16")                       =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.reserved_16;
    m_inputs_map[oa_num][MVB2].at("PFC2_Vs")                           =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC2_Vs;
    m_inputs_map[oa_num][MVB2].at("PFC2_Is")                           =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC2_Is;
    m_inputs_map[oa_num][MVB2].at("PFC2_Fs")                           =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC2_Fs;
    m_inputs_map[oa_num][MVB2].at("PFC2_Vo")                           =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC2_Vo;
    m_inputs_map[oa_num][MVB2].at("PFC2_Temp1")                         =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC2_Temp1;
    m_inputs_map[oa_num][MVB2].at("PFC2_Temp2")                         =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC2_Temp2;
    m_inputs_map[oa_num][MVB2].at("reserved_27")                       =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.reserved_27;
    m_inputs_map[oa_num][MVB2].at("reserved_28")                       =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.reserved_28;
    m_inputs_map[oa_num][MVB2].at("reserved_29")                       =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.reserved_29;
    m_inputs_map[oa_num][MVB2].at("reserved_30")                       =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.reserved_30;
    m_inputs_map[oa_num][MVB2].at("reserved_31")                       =m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.reserved_31;
    qDebug() << "CEKO 4";

}

void OA_APU::update_mvb3_map(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);

    m_inputs_map[oa_num][MVB3].at("Lifesign")                   =m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.Lifesign;
    m_inputs_map[oa_num][MVB3].at("VSI1_Vs")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI1_Vs;
    m_inputs_map[oa_num][MVB3].at("VSI1_Vo")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI1_Vo;
    m_inputs_map[oa_num][MVB3].at("VSI1_Io")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI1_Io;
    m_inputs_map[oa_num][MVB3].at("VSI1_Fo")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI1_Fo;
    m_inputs_map[oa_num][MVB3].at("VSI1_Temp1")                 =m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI1_Temp1;
    m_inputs_map[oa_num][MVB3].at("VSI1_Temp2")                 =m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI1_Temp2;
    m_inputs_map[oa_num][MVB3].at("reserved_12")                =m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.reserved_12;
    m_inputs_map[oa_num][MVB3].at("VSI2_Vs")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI2_Vs;
    m_inputs_map[oa_num][MVB3].at("VSI2_Vo")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI2_Vo;
    m_inputs_map[oa_num][MVB3].at("VSI2_Io")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI2_Io;
    m_inputs_map[oa_num][MVB3].at("VSI2_Fo")                    =m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI2_Fo;
    m_inputs_map[oa_num][MVB3].at("VSI2_Temp1")                 =m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI2_Temp1;
    m_inputs_map[oa_num][MVB3].at("VSI2_Temp2")                 =m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI2_Temp2;
    m_inputs_map[oa_num][MVB3].at("reserved_23")                =m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.reserved_23;
    m_inputs_map[oa_num][MVB3].at("BCH_Vs")                     =m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.BCH_Vs;
    m_inputs_map[oa_num][MVB3].at("BCH_Vo")                     =m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.BCH_Vo;
    m_inputs_map[oa_num][MVB3].at("BCH_Io")                     =m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.BCH_Io;
    m_inputs_map[oa_num][MVB3].at("BCH_Temp1")                  =m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.BCH_Temp1;
    m_inputs_map[oa_num][MVB3].at("BCH_Temp2")                  =m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.BCH_Temp2;



}

void OA_APU::update_table(OA_VEHICLE_NUM oa_x_num, OA_MVB_NUM mvb_num)
{
    int oa_num = static_cast<int>(oa_x_num);
    // İndeksleri kullanarak tabloyu güncelle
    //qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;
    std::vector<int> valueColumns = {1, 3, 5, 7};
    for(const auto & map:m_inputs_map[oa_num][mvb_num]){


        utils::setTableWidgetValueByNameWithoutColumn(m_tableWidget[oa_num][mvb_num], map.first, map.second);
        //qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT INSIDE FOR LOOP ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;

        //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,3, map.second);
        //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,5, map.second);
        //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,7, map.second);
    }
}



void OA_APU::set_struct_mvb1(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Lifesign = m_inputs_map[oa_num][MVB1].at("Lifesign")            ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.APUC_App_State = m_inputs_map[oa_num][MVB1].at("APUC_App_State")      ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Door_Open = m_inputs_map[oa_num][MVB1].at("Door_Open")           ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Mode_Select = m_inputs_map[oa_num][MVB1].at("Mode_Select")         ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.APU_Emergency = m_inputs_map[oa_num][MVB1].at("APU_Emergency")       ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.APU_Start_Status = m_inputs_map[oa_num][MVB1].at("APU_Start_Status")    ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Reset_Ack = m_inputs_map[oa_num][MVB1].at("Reset_Ack")           ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.bit23 = m_inputs_map[oa_num][MVB1].at("bit23")               ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.APS_Ok = m_inputs_map[oa_num][MVB1].at("APS_Ok")              ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.MV_Output_Ok = m_inputs_map[oa_num][MVB1].at("MV_Output_Ok")        ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.HV_Presence = m_inputs_map[oa_num][MVB1].at("HV_Presence")         ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.APS_Out_Con_Loop_out = m_inputs_map[oa_num][MVB1].at("APS_Out_Con_Loop_out");
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.LV_Output_Ok = m_inputs_map[oa_num][MVB1].at("LV_Output_Ok")        ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.bit29 = m_inputs_map[oa_num][MVB1].at("bit29")               ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.bit30 = m_inputs_map[oa_num][MVB1].at("bit30")               ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.bit31 = m_inputs_map[oa_num][MVB1].at("bit31")               ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.reserved_4 = m_inputs_map[oa_num][MVB1].at("reserved_4")          ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.SW_Ver = m_inputs_map[oa_num][MVB1].at("SW_Ver")              ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Catenary_Voltage = m_inputs_map[oa_num][MVB1].at("Catenary_Voltage")    ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Fault_Code_APUC = m_inputs_map[oa_num][MVB1].at("Fault_Code_APUC")     ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Fault_Code_PFC1 = m_inputs_map[oa_num][MVB1].at("Fault_Code_PFC1")     ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Fault_Code_PFC2 = m_inputs_map[oa_num][MVB1].at("Fault_Code_PFC2")     ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Fault_Code_VSI1 = m_inputs_map[oa_num][MVB1].at("Fault_Code_VSI1")     ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Fault_Code_VSI2 = m_inputs_map[oa_num][MVB1].at("Fault_Code_VSI2")     ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.Fault_Code_BCH = m_inputs_map[oa_num][MVB1].at("Fault_Code_BCH")      ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.reserved_14 = m_inputs_map[oa_num][MVB1].at("reserved_14")         ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb1.bits.reserved_15 = m_inputs_map[oa_num][MVB1].at("reserved_15")         ;



}

void OA_APU::set_struct_mvb2(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);

    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.Lifesign = m_inputs_map[oa_num][MVB2].at("Lifesign")       ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC1_App_State = m_inputs_map[oa_num][MVB2].at("PFC1_App_State") ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC2_App_State = m_inputs_map[oa_num][MVB2].at("PFC2_App_State") ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.VSI1_App_State = m_inputs_map[oa_num][MVB2].at("VSI1_App_State") ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.VSI2_App_State = m_inputs_map[oa_num][MVB2].at("VSI2_App_State") ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.BCH_App_State = m_inputs_map[oa_num][MVB2].at("BCH_App_State")  ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.bit26 = m_inputs_map[oa_num][MVB2].at("bit26")          ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.bit27 = m_inputs_map[oa_num][MVB2].at("bit27")          ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.bit28 = m_inputs_map[oa_num][MVB2].at("bit28")          ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.bit29 = m_inputs_map[oa_num][MVB2].at("bit29")          ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.bit30 = m_inputs_map[oa_num][MVB2].at("bit30")          ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.bit31 = m_inputs_map[oa_num][MVB2].at("bit31")          ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC_A_CAN = m_inputs_map[oa_num][MVB2].at("PFC_A_CAN")      ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC_B_CAN = m_inputs_map[oa_num][MVB2].at("PFC_B_CAN")      ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.VSI_A_CAN = m_inputs_map[oa_num][MVB2].at("VSI_A_CAN")      ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.VSI_B_CAN = m_inputs_map[oa_num][MVB2].at("VSI_B_CAN")      ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.BCH_CAN = m_inputs_map[oa_num][MVB2].at("BCH_CAN")        ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.bit37 = m_inputs_map[oa_num][MVB2].at("bit37")          ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.bit38 = m_inputs_map[oa_num][MVB2].at("bit38")          ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.bit39 = m_inputs_map[oa_num][MVB2].at("bit39")          ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.reserved_5 = m_inputs_map[oa_num][MVB2].at("reserved_5")     ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC1_Vs = m_inputs_map[oa_num][MVB2].at("PFC1_Vs")        ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC1_Is = m_inputs_map[oa_num][MVB2].at("PFC1_Is")        ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC1_Fs = m_inputs_map[oa_num][MVB2].at("PFC1_Fs")        ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC1_Vo = m_inputs_map[oa_num][MVB2].at("PFC1_Vo")        ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC1_Temp1 = m_inputs_map[oa_num][MVB2].at("PFC1_Temp1")      ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC1_Temp2 = m_inputs_map[oa_num][MVB2].at("PFC1_Temp2")      ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.reserved_16 = m_inputs_map[oa_num][MVB2].at("reserved_16")    ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC2_Vs = m_inputs_map[oa_num][MVB2].at("PFC2_Vs")        ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC2_Is = m_inputs_map[oa_num][MVB2].at("PFC2_Is")        ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC2_Fs = m_inputs_map[oa_num][MVB2].at("PFC2_Fs")        ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC2_Vo = m_inputs_map[oa_num][MVB2].at("PFC2_Vo")        ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC2_Temp1 = m_inputs_map[oa_num][MVB2].at("PFC2_Temp1")      ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.PFC2_Temp2 = m_inputs_map[oa_num][MVB2].at("PFC2_Temp2")      ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.reserved_27 = m_inputs_map[oa_num][MVB2].at("reserved_27")    ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.reserved_28 = m_inputs_map[oa_num][MVB2].at("reserved_28")    ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.reserved_29 = m_inputs_map[oa_num][MVB2].at("reserved_29")    ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.reserved_30 = m_inputs_map[oa_num][MVB2].at("reserved_30")    ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb2.bits.reserved_31 = m_inputs_map[oa_num][MVB2].at("reserved_31")    ;






}

void OA_APU::set_struct_mvb3(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);

    m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.Lifesign = m_inputs_map[oa_num][MVB3].at("Lifesign")    ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI1_Vs = m_inputs_map[oa_num][MVB3].at("VSI1_Vs")     ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI1_Vo = m_inputs_map[oa_num][MVB3].at("VSI1_Vo")     ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI1_Io = m_inputs_map[oa_num][MVB3].at("VSI1_Io")     ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI1_Fo = m_inputs_map[oa_num][MVB3].at("VSI1_Fo")     ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI1_Temp1 = m_inputs_map[oa_num][MVB3].at("VSI1_Temp1")  ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI1_Temp2 = m_inputs_map[oa_num][MVB3].at("VSI1_Temp2")  ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.reserved_12 = m_inputs_map[oa_num][MVB3].at("reserved_12") ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI2_Vs = m_inputs_map[oa_num][MVB3].at("VSI2_Vs")     ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI2_Vo = m_inputs_map[oa_num][MVB3].at("VSI2_Vo")     ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI2_Io = m_inputs_map[oa_num][MVB3].at("VSI2_Io")     ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI2_Fo = m_inputs_map[oa_num][MVB3].at("VSI2_Fo")     ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI2_Temp1 = m_inputs_map[oa_num][MVB3].at("VSI2_Temp1")  ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.VSI2_Temp2 = m_inputs_map[oa_num][MVB3].at("VSI2_Temp2")  ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.reserved_23 = m_inputs_map[oa_num][MVB3].at("reserved_23") ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.BCH_Vs = m_inputs_map[oa_num][MVB3].at("BCH_Vs")      ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.BCH_Vo = m_inputs_map[oa_num][MVB3].at("BCH_Vo")      ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.BCH_Io = m_inputs_map[oa_num][MVB3].at("BCH_Io")      ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.BCH_Temp1 = m_inputs_map[oa_num][MVB3].at("BCH_Temp1")   ;
    m_oa_x_apu[oa_num].oa_apu_ccu_mvb3.bits.BCH_Temp2 = m_inputs_map[oa_num][MVB3].at("BCH_Temp2")   ;



}

void OA_APU::init_oa_apu_mvb1_table(OA_VEHICLE_NUM vehicle_type)
{
    int oa_num = static_cast<int>(vehicle_type);
    m_inputs_map[oa_num][MVB1] = {
                                  {"Lifesign",0},
                                  {"APUC_App_State",0},
                                  {"Door_Open",0},
                                  {"Mode_Select",0},
                                  {"APU_Emergency",0},
                                  {"APU_Start_Status",0},
                                  {"Reset_Ack",0},
                                  {"bit23",0},
                                  {"APS_Ok",0},
                                  {"MV_Output_Ok",0},
                                  {"HV_Presence",0},
                                  {"APS_Out_Con_Loop_out",0},
                                  {"LV_Output_Ok",0},
                                  {"bit29",0},
                                  {"bit30",0},
                                  {"bit31",0},
                                  {"reserved_4",0},
                                  {"SW_Ver",0},
                                  {"Catenary_Voltage",0},
                                  {"Fault_Code_APUC",0},
                                  {"Fault_Code_PFC1",0},
                                  {"Fault_Code_PFC2",0},
                                  {"Fault_Code_VSI1",0},
                                  {"Fault_Code_VSI2",0},
                                  {"Fault_Code_BCH",0},
                                  {"reserved_14",0},
                                  {"reserved_15",0},


                                  };

    //QStringList headers;
    //headers << table_name[oa_num][MVB1] << "Value" << table_name[oa_num][MVB1] << "Value";
    /*m_tableWidget[oa_num][MVB1] = new QTableWidget();
    m_tableWidget[oa_num][MVB1]->setColumnCount(2);
    m_tableWidget[oa_num][MVB1]->setRowCount(m_inputs_map[oa_num][MVB1].size());
    m_tableWidget[oa_num][MVB1]->setHorizontalHeaderLabels(table_name[oa_num][MVB1]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[oa_num][MVB1]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[oa_num][MVB1]->setItem(row, 0, item_name);
        m_tableWidget[oa_num][MVB1]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[oa_num][MVB1]->resizeColumnsToContents();*/
    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[oa_num][MVB1].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[oa_num][MVB1] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[oa_num][MVB1]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[oa_num][MVB1]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[oa_num][MVB1]->setItem(row, column, item_name);
        m_tableWidget[oa_num][MVB1]->setItem(row, column + 1, item_val); // Değer
        item_name->setBackground(QColor("turquoise"));  // Turkuaz
        item_val->setBackground(QColor("turquoise"));  // Turkuaz

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[oa_num][MVB1]->resizeColumnsToContents();
    //qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;





}

void OA_APU::init_oa_apu_mvb2_table(OA_VEHICLE_NUM vehicle_type)
{
    int oa_num = static_cast<int>(vehicle_type);
    m_inputs_map[oa_num][MVB2] = {
                                  {"Lifesign",0},
                                  {"PFC1_App_State",0},
                                  {"PFC2_App_State",0},
                                  {"VSI1_App_State",0},
                                  {"VSI2_App_State",0},
                                  {"BCH_App_State",0},
                                  {"bit26",0},
                                  {"bit27",0},
                                  {"bit28",0},
                                  {"bit29",0},
                                  {"bit30",0},
                                  {"bit31",0},
                                  {"PFC_A_CAN",0},
                                  {"PFC_B_CAN",0},
                                  {"VSI_A_CAN",0},
                                  {"VSI_B_CAN",0},
                                  {"BCH_CAN",0},
                                  {"bit37",0},
                                  {"bit38",0},
                                  {"bit39",0},
                                  {"reserved_5",0},
                                  {"PFC1_Vs",0},
                                  {"PFC1_Is",0},
                                  {"PFC1_Fs",0},
                                  {"PFC1_Vo",0},
                                  {"PFC1_Temp1",0},
                                  {"PFC1_Temp2",0},
                                  {"reserved_16",0},
                                  {"PFC2_Vs",0},
                                  {"PFC2_Is",0},
                                  {"PFC2_Fs",0},
                                  {"PFC2_Vo",0},
                                  {"PFC2_Temp1",0},
                                  {"PFC2_Temp2",0},
                                  {"reserved_27",0},
                                  {"reserved_28",0},
                                  {"reserved_29",0},
                                  {"reserved_30",0},
                                  {"reserved_31",0},

                                  };

    /*m_tableWidget[oa_num][MVB2] = new QTableWidget();
    m_tableWidget[oa_num][MVB2]->setColumnCount(2);
    m_tableWidget[oa_num][MVB2]->setRowCount(m_inputs_map[oa_num][MVB2].size());
    m_tableWidget[oa_num][MVB2]->setHorizontalHeaderLabels(table_name[oa_num][MVB2]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[oa_num][MVB2]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[oa_num][MVB2]->setItem(row, 0, item_name);
        m_tableWidget[oa_num][MVB2]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[oa_num][MVB2]->resizeColumnsToContents();*/

    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[oa_num][MVB2].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[oa_num][MVB2] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[oa_num][MVB2]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[oa_num][MVB2]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[oa_num][MVB2]->setItem(row, column, item_name);
        m_tableWidget[oa_num][MVB2]->setItem(row, column + 1, item_val); // Değer
        item_name->setBackground(QColor("turquoise"));  // Turkuaz
        item_val->setBackground(QColor("turquoise"));  // Turkuaz

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[oa_num][MVB2]->resizeColumnsToContents();
    //qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[oa_num][MVB2]->columnCount() ;




}

void OA_APU::init_oa_apu_mvb3_table(OA_VEHICLE_NUM vehicle_type)
{
    int oa_num = static_cast<int>(vehicle_type);
    m_inputs_map[oa_num][MVB3] = {
                                  {"Lifesign",0},
                                  {"VSI1_Vs",0},
                                  {"VSI1_Vo",0},
                                  {"VSI1_Io",0},
                                  {"VSI1_Fo",0},
                                  {"VSI1_Temp1",0},
                                  {"VSI1_Temp2",0},
                                  {"reserved_12",0},
                                  {"VSI2_Vs",0},
                                  {"VSI2_Vo",0},
                                  {"VSI2_Io",0},
                                  {"VSI2_Fo",0},
                                  {"VSI2_Temp1",0},
                                  {"VSI2_Temp2",0},
                                  {"reserved_23",0},
                                  {"BCH_Vs",0},
                                  {"BCH_Vo",0},
                                  {"BCH_Io",0},
                                  {"BCH_Temp1",0},
                                  {"BCH_Temp2",0},
                                  };

    /*m_tableWidget[oa_num][MVB3] = new QTableWidget();
    m_tableWidget[oa_num][MVB3]->setColumnCount(2);
    m_tableWidget[oa_num][MVB3]->setRowCount(m_inputs_map[oa_num][MVB3].size());
    m_tableWidget[oa_num][MVB3]->setHorizontalHeaderLabels(table_name[oa_num][MVB3]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[oa_num][MVB3]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[oa_num][MVB3]->setItem(row, 0, item_name);
        m_tableWidget[oa_num][MVB3]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[oa_num][MVB3]->resizeColumnsToContents();*/

    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[oa_num][MVB3].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[oa_num][MVB3] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[oa_num][MVB3]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[oa_num][MVB3]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[oa_num][MVB3]->setItem(row, column, item_name);
        m_tableWidget[oa_num][MVB3]->setItem(row, column + 1, item_val); // Değer
        item_name->setBackground(QColor("turquoise"));  // Turkuaz
        item_val->setBackground(QColor("turquoise"));  // Turkuaz

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[oa_num][MVB3]->resizeColumnsToContents();
    //qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[oa_num][MVB3]->columnCount() ;

}



