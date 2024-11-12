#include "ska_bcu.h"
#include <QBitArray>
Ska_Bcu::Ska_Bcu(QObject *parent)
    : QObject{parent}
{

    // Reset Struct values
    memset(&m_ska_x_bcu, 0, sizeof(m_ska_x_bcu));
    // Init SKA1 Table Contents
    init_oa_x_mvb1_table(SKA_VEHICLE_NUM::SKA1);
    init_oa_x_mvb2_table(SKA_VEHICLE_NUM::SKA1);
    //init_oa_x_mvb3_table(SKA_VEHICLE_NUM::SKA1);

    // Init SKA2 Table Contents
    init_oa_x_mvb1_table(SKA_VEHICLE_NUM::SKA2);
    init_oa_x_mvb2_table(SKA_VEHICLE_NUM::SKA2);
    //init_oa_x_mvb3_table(SKA_VEHICLE_NUM::SKA2);

    make_signal_slot_connection();

}

Ska_Bcu::~Ska_Bcu()
{

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            delete m_tableWidget[i][j];
            m_tableWidget[i][j] = nullptr; // Güvenlik için nullptr atayın
        }
    }

}



void Ska_Bcu::make_signal_slot_connection()
{

    // SKA1 MVB1 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][MVB1], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1, MVB1);
    });

    // SKA1 MVB2 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][MVB2], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1, MVB2);
    });

    /* SKA1 MVB3 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][MVB3], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1, MVB3);
    });*/


    // SKA2 MVB1 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][MVB1], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2, MVB1);
    });

    // SKA2 MVB2 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][MVB2], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2, MVB2);
    });

    /* SKA2 MVB3 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][MVB3], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2, MVB3);
    });*/
}

void Ska_Bcu::update_struct_with_map(SKA_VEHICLE_NUM ska_x_num, SKA_MVB_NUM mvb_num)
{

    int ska_num = static_cast<int>(ska_x_num);
    qDebug() << "- -- -- ska num:"<< ska_num;
    // Define a lambda function to reduce redundancy
    auto setInputMap = [&](const QString& signal_name) {
        m_inputs_map[ska_num][mvb_num][signal_name] = utils::getTableWidgetValueByNameWithoutColumn(m_tableWidget[ska_num][mvb_num], signal_name).toInt();
    };
    // update map with given tableWidget values
    for(const auto& map : m_inputs_map[ska_num][mvb_num])
    {
        setInputMap(map.first);
    }
    // set struct parameters with given updated map parameters
    set_struct_mvb1(ska_x_num);
    set_struct_mvb2(ska_x_num);
    //set_struct_mvb3(ska_x_num);
}

void Ska_Bcu::set_data_struct(const QByteArray &input, const SKA_VEHICLE_NUM &ska_x_num)
{
    //int oa_num = static_cast<int>(oa_x_num);
    qDebug() << "azdan az çoktan çok " ;
    qDebug() << "size of input " << input.size();
    qDebug() << "Gelen input verileri :  " << input;
    //qDebug() << "Gelen input veri tipi : " << typeof(input);


    int ska_num = static_cast<int>(ska_x_num);

    qDebug() << "SET DATA STRUCT SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][MVB1]->columnCount() ;
    if (input.size() == sizeof(m_ska_x_bcu[ska_num])) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        //memcpy(&m_oa_x_etcs[oa_num], input.constData(), sizeof(m_oa_x_etcs[oa_num]));

        qDebug() << "SIZE of MVB1 :  " << sizeof(m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bytes);
        qDebug() << "SIZE of MVB2 :  " << sizeof(m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bytes);
        //qDebug() << "SIZE of MVB3 :  " << sizeof(m_ska_x_bcu[ska_num].oa_etcs_ccu_mvb3.bytes);


        // İlk alanı kopyala
        memcpy(&m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bytes, input.constData(), sizeof(m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bytes));

        QByteArray data =  input.mid(0, 32);
        qDebug() << "32 Bytelık data :  " << data;
        update_mvb1_map(ska_x_num);
        //set_struct_mvb1(oa_x_num);
        update_table(ska_x_num,Ska_Bcu::MVB1);

        // İkinci alanı kopyala, input.constData() + sizeof(etcs_ccu_mvb1) kadar ilerleyerek
        memcpy(&m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bytes, input.constData() + sizeof(m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bytes) + 8, sizeof(m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bytes));
        update_mvb2_map(ska_x_num);
        //set_struct_mvb2(oa_x_num);
        update_table(ska_x_num,Ska_Bcu::MVB2);


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

void Ska_Bcu::update_mvb1_map(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);

    m_inputs_map[ska_num][MVB1].at("XLifeSign")            = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.XLifeSign;
    m_inputs_map[ska_num][MVB1].at("EBCU_MainVersion")     = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.EBCU_MainVersion;
    m_inputs_map[ska_num][MVB1].at("EBCU_SubVersion")      = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.EBCU_SubVersion;
    m_inputs_map[ska_num][MVB1].at("X_Cpress")             = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_Cpress;
    m_inputs_map[ska_num][MVB1].at("X_Tpress")             = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_Tpress;
    m_inputs_map[ska_num][MVB1].at("X_PrkBrPress_1")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_PrkBrPress_1,
    m_inputs_map[ska_num][MVB1].at("X_PrkBrPress_2")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_PrkBrPress_2;
    m_inputs_map[ska_num][MVB1].at("X_BPPress")            = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_BPPress;
    m_inputs_map[ska_num][MVB1].at("X_MRPPress")           = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_MRPPress;
    m_inputs_map[ska_num][MVB1].at("reserved10")           = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.reserved10;

    m_inputs_map[ska_num][MVB1].at("X_LoadWeight")         = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_LoadWeight;
    m_inputs_map[ska_num][MVB1].at("X_VAxl1")              = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_VAxl1;
    m_inputs_map[ska_num][MVB1].at("X_VAxl2")              = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_VAxl2;
    m_inputs_map[ska_num][MVB1].at("X_VAxl3")              = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_VAxl3;
    m_inputs_map[ska_num][MVB1].at("X_VAxl4")              = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_VAxl4;    ;
    m_inputs_map[ska_num][MVB1].at("X_Vref")               = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_Vref;

    m_inputs_map[ska_num][MVB1].at("reserved23")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.reserved23;
    m_inputs_map[ska_num][MVB1].at("reserved24")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.reserved24;
    m_inputs_map[ska_num][MVB1].at("S_HolBrRe")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_HolBrRe ;
    m_inputs_map[ska_num][MVB1].at("V_HolBrRe")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.V_HolBrRe ;
    m_inputs_map[ska_num][MVB1].at("S_HolBrAp")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_HolBrAp ;
    m_inputs_map[ska_num][MVB1].at("V_HolBrAp")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.V_HolBrAp ;
    m_inputs_map[ska_num][MVB1].at("S_PrkBrRe")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_PrkBrRe ;
    m_inputs_map[ska_num][MVB1].at("V_PrkBrRe")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.V_PrkBrRe ;
    m_inputs_map[ska_num][MVB1].at("S_PrkBrReNot")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_PrkBrReNot;
    m_inputs_map[ska_num][MVB1].at("V_PrkBrReNot")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.V_PrkBrReNot;
    m_inputs_map[ska_num][MVB1].at("S_PnBrRe_Bo1")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_PnBrRe_Bo1;
    m_inputs_map[ska_num][MVB1].at("V_PnBrRe_Bo1")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.V_PnBrRe_Bo1;
    m_inputs_map[ska_num][MVB1].at("S_PnBrAp_Bo1")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_PnBrAp_Bo1;
    m_inputs_map[ska_num][MVB1].at("V_PnBrAp_Bo1")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.V_PnBrAp_Bo1;
    m_inputs_map[ska_num][MVB1].at("S_PnBrRe_Bo2")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_PnBrRe_Bo2;
    m_inputs_map[ska_num][MVB1].at("V_PnBrRe_Bo2")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.V_PnBrRe_Bo2;
    m_inputs_map[ska_num][MVB1].at("S_PnBrAp_Bo2")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_PnBrAp_Bo2;
    m_inputs_map[ska_num][MVB1].at("V_PnBrAp_Bo2")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.V_PnBrAp_Bo2;
    m_inputs_map[ska_num][MVB1].at("S_EmergBrLoopOpen")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_EmergBrLoopOpen;
    m_inputs_map[ska_num][MVB1].at("S_TLHolBrRe")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_TLHolBrRe;
    m_inputs_map[ska_num][MVB1].at("S_TLBrakingBit1")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_TLBrakingBit1;
    m_inputs_map[ska_num][MVB1].at("S_TLBrakingBit2")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_TLBrakingBit2;
    m_inputs_map[ska_num][MVB1].at("S_TLBrakingBit3")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_TLBrakingBit3;
    m_inputs_map[ska_num][MVB1].at("S_TLTraction")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_TLTraction;
    m_inputs_map[ska_num][MVB1].at("S_WSPTest_Run")        = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_WSPTest_Run;
    m_inputs_map[ska_num][MVB1].at("S_WSPTest_Run_abbort")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_WSPTest_Run_abbort;
    m_inputs_map[ska_num][MVB1].at("S_WSPactive_Bo1")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_WSPactive_Bo1;
    m_inputs_map[ska_num][MVB1].at("S_WSPok_Bo1")          = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_WSPok_Bo1;
    m_inputs_map[ska_num][MVB1].at("S_WSPactive_Bo2")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_WSPactive_Bo2;
    m_inputs_map[ska_num][MVB1].at("S_WSPok_Bo2")          = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_WSPok_Bo2;
    m_inputs_map[ska_num][MVB1].at("S_Degraded_Mode")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_Degraded_Mode;
    m_inputs_map[ska_num][MVB1].at("S_ASC_Mode_active")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_ASC_Mode_active;

    m_inputs_map[ska_num][MVB1].at("S_Standstill")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_Standstill;
    m_inputs_map[ska_num][MVB1].at("S_EBCU_EBL_Open_PB")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_EBCU_EBL_Open_PB;
    m_inputs_map[ska_num][MVB1].at("IC_PneuBr")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.IC_PneuBr;
    m_inputs_map[ska_num][MVB1].at("IC_DirectBr")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.IC_DirectBr;
    m_inputs_map[ska_num][MVB1].at("IC_Cpress_Bo1")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.IC_Cpress_Bo1;
    m_inputs_map[ska_num][MVB1].at("IC_Cpress_Bo2")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.IC_Cpress_Bo2;
    m_inputs_map[ska_num][MVB1].at("IC_PrkBr")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.IC_PrkBr;
    m_inputs_map[ska_num][MVB1].at("IC_Sanding")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.IC_Sanding;
    m_inputs_map[ska_num][MVB1].at("IC_InDirectBr")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.IC_InDirectBr;
    m_inputs_map[ska_num][MVB1].at("S_DoorsClosedLocked")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_DoorsClosedLocked;
    m_inputs_map[ska_num][MVB1].at("S_ED_fade_Out")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_ED_fade_Out;
    m_inputs_map[ska_num][MVB1].at("S_BpApValid")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_BpApValid;
    m_inputs_map[ska_num][MVB1].at("S_BpAP")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_BpAP;
    m_inputs_map[ska_num][MVB1].at("S_Sanding_Heating_Release")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_Sanding_Heating_Release;
    m_inputs_map[ska_num][MVB1].at("S_Sanding_Active")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_Sanding_Active;
    m_inputs_map[ska_num][MVB1].at("bit246")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.bit246;
    m_inputs_map[ska_num][MVB1].at("bit247")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.bit247;
    m_inputs_map[ska_num][MVB1].at("bit248")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.bit248;
    //m_inputs_map[ska_num][MVB1].at("reserved31")       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.reserved31;


}

void Ska_Bcu::update_mvb2_map(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_inputs_map[ska_num][MVB2].at("XLifeSign")                              = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.XLifeSign;
    m_inputs_map[ska_num][MVB2].at("DIA_BOARD_CB09_02")                     = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARD_CB09_02;
    m_inputs_map[ska_num][MVB2].at("DIA_BOARD_MB04_04")                     = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARD_MB04_04;
    m_inputs_map[ska_num][MVB2].at("DIA_BOARD_MB03_06")                     = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARD_MB03_06;
    m_inputs_map[ska_num][MVB2].at("DIA_BOARD_MB03_07")                     = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARD_MB03_07;
    m_inputs_map[ska_num][MVB2].at("DIA_BOARD_EB01_08")                     = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARD_EB01_08;
    m_inputs_map[ska_num][MVB2].at("DIA_BOARD_EB02_09")                     = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARD_EB02_09;
    m_inputs_map[ska_num][MVB2].at("bit23")                                  = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit23;
    m_inputs_map[ska_num][MVB2].at("bit24")                                  = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit24;
    m_inputs_map[ska_num][MVB2].at("DIA_BOARDCODING_MB04_04")                = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARDCODING_MB04_04;
    m_inputs_map[ska_num][MVB2].at("DIA_BOARDCODING_MB03_06")                = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARDCODING_MB03_06;
    m_inputs_map[ska_num][MVB2].at("DIA_BOARDCODING_MB03_07")                = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARDCODING_MB03_07;
    m_inputs_map[ska_num][MVB2].at("DIA_BOARDCODING_EB01_08")                = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARDCODING_EB01_08;
    m_inputs_map[ska_num][MVB2].at("DIA_BOARDCODING_EB02_09")                = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARDCODING_EB02_09;
    m_inputs_map[ska_num][MVB2].at("bit30")                                  = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit30;
    m_inputs_map[ska_num][MVB2].at("bit31")                                  = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit31;
    m_inputs_map[ska_num][MVB2].at("bit32")                                  = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit32;
    m_inputs_map[ska_num][MVB2].at("DIA_CAN_COMM_CB09_02")                   = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_CAN_COMM_CB09_02;
    m_inputs_map[ska_num][MVB2].at("DIA_CAN_COMM_MB04_03")                   = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_CAN_COMM_MB04_03;
    m_inputs_map[ska_num][MVB2].at("DIA_CAN_COMM_MB03_06")                   = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_CAN_COMM_MB03_06;
    m_inputs_map[ska_num][MVB2].at("DIA_CAN_COMM_MB03_07")                   = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_CAN_COMM_MB03_07;
    m_inputs_map[ska_num][MVB2].at("DIA_CAN_COMM_EB01_08")                   = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_CAN_COMM_EB01_08;
    m_inputs_map[ska_num][MVB2].at("DIA_CAN_COMM_EB02_09")                   = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_CAN_COMM_EB02_09;
    m_inputs_map[ska_num][MVB2].at("bit39")                                  = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit39;
    m_inputs_map[ska_num][MVB2].at("bit40")                                  = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit40;
    m_inputs_map[ska_num][MVB2].at("DIA_PSENSOR_C")                           = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PSENSOR_C;
    m_inputs_map[ska_num][MVB2].at("DIA_PSENSOR_BP")                          = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PSENSOR_BP;
    m_inputs_map[ska_num][MVB2].at("DIA_PSENSOR1_PB")                        = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PSENSOR1_PB;
    m_inputs_map[ska_num][MVB2].at("DIA_PSENSOR2_PB")                        = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PSENSOR2_PB;
    m_inputs_map[ska_num][MVB2].at("DIA_PSENSOR_CVD")                        = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PSENSOR_CVD;
    m_inputs_map[ska_num][MVB2].at("DIA_PSENSOR_T")                          = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PSENSOR_T;
    m_inputs_map[ska_num][MVB2].at("DIA_PSENSOR_R")                          = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PSENSOR_R;
    m_inputs_map[ska_num][MVB2].at("DIA_PSENSOR_CVI")                        = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PSENSOR_CVI;
    m_inputs_map[ska_num][MVB2].at("DIA_PSENSOR_MRP")                        = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PSENSOR_MRP;
    m_inputs_map[ska_num][MVB2].at("DIA_REL_EBCU_FCT_OK")                   = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_REL_EBCU_FCT_OK;
    m_inputs_map[ska_num][MVB2].at("DIA_REL_EBCU_EBLOOP_Y_OPEN")             = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_REL_EBCU_EBLOOP_Y_OPEN;
    m_inputs_map[ska_num][MVB2].at("DIA_REL_EBCU_C_EDCUTOFF")                = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_REL_EBCU_C_EDCUTOFF;
    m_inputs_map[ska_num][MVB2].at("DIA_REL_WSP_R_VLT5KMHDOOR")              = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_REL_WSP_R_VLT5KMHDOOR;
    m_inputs_map[ska_num][MVB2].at("DIA_REL_WSP_R_VGT5KMHDOOR")              = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_REL_WSP_R_VGT5KMHDOOR;
    m_inputs_map[ska_num][MVB2].at("DIA_REL_WSP_R_VGT10KMHDOOR")             = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_REL_WSP_R_VGT10KMHDOOR;
    m_inputs_map[ska_num][MVB2].at("bit56")                                 = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit56;
    m_inputs_map[ska_num][MVB2].at("DIA_WSP_FSI_AXLE1")                     = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_FSI_AXLE1;
    m_inputs_map[ska_num][MVB2].at("DIA_WSP_FSI_AXLE2")                     = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_FSI_AXLE2;
    m_inputs_map[ska_num][MVB2].at("DIA_WSP_FSI_AXLE3")                     = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_FSI_AXLE3;
    m_inputs_map[ska_num][MVB2].at("DIA_WSP_FSI_AXLE4")                     = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_FSI_AXLE4;
    m_inputs_map[ska_num][MVB2].at("DIA_SPEED_DV1")                        = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_SPEED_DV1;
    m_inputs_map[ska_num][MVB2].at("DIA_SPEED_DV2")                        = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_SPEED_DV2;
    m_inputs_map[ska_num][MVB2].at("DIA_SPEED_DV3")                        = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_SPEED_DV3;
    m_inputs_map[ska_num][MVB2].at("DIA_SPEED_DV4")                        = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_SPEED_DV4;
    m_inputs_map[ska_num][MVB2].at("DIA_POP_WSP_Y_HOLD_AX1")                = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_HOLD_AX1;
    m_inputs_map[ska_num][MVB2].at("DIA_POP_WSP_Y_HOLD_AX2")                = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_HOLD_AX2;
    m_inputs_map[ska_num][MVB2].at("DIA_POP_WSP_Y_HOLD_AX3")                = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_HOLD_AX3;
    m_inputs_map[ska_num][MVB2].at("DIA_POP_WSP_Y_HOLD_AX4")                = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_HOLD_AX4;
    m_inputs_map[ska_num][MVB2].at("DIA_POP_WSP_Y_RELEASE_AX1")             = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_RELEASE_AX1;
    m_inputs_map[ska_num][MVB2].at("DIA_POP_WSP_Y_RELEASE_AX2")             = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_RELEASE_AX2;
    m_inputs_map[ska_num][MVB2].at("DIA_POP_WSP_Y_RELEASE_AX3")             = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_RELEASE_AX3;
    m_inputs_map[ska_num][MVB2].at("DIA_POP_WSP_Y_RELEASE_AX4")             = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_RELEASE_AX4;
    m_inputs_map[ska_num][MVB2].at("DIA_WSP_TIMEOUT_AX1")                   = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_TIMEOUT_AX1;
    m_inputs_map[ska_num][MVB2].at("DIA_WSP_TIMEOUT_AX2")                   = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_TIMEOUT_AX2;
    m_inputs_map[ska_num][MVB2].at("DIA_WSP_TIMEOUT_AX3")                   = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_TIMEOUT_AX3;
    m_inputs_map[ska_num][MVB2].at("DIA_WSP_TIMEOUT_AX4")                   = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_TIMEOUT_AX4;
    m_inputs_map[ska_num][MVB2].at("DIA_UWR_TIMEOUT_BO1")                   = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_UWR_TIMEOUT_BO1;
    m_inputs_map[ska_num][MVB2].at("DIA_UWR_TIMEOUT_BO2")                   = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_UWR_TIMEOUT_BO2;
    m_inputs_map[ska_num][MVB2].at("DIA_WSP_FAILURE_BO1")                   = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_FAILURE_BO1;
    m_inputs_map[ska_num][MVB2].at("DIA_WSP_FAILURE_BO2")                   = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_FAILURE_BO2;
    m_inputs_map[ska_num][MVB2].at("DIA_ASSF")                               = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_ASSF;
    m_inputs_map[ska_num][MVB2].at("DIA_WSP_TEST_ABORTED")                   = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_TEST_ABORTED;
    m_inputs_map[ska_num][MVB2].at("DIA_WSP_CONF")                           = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_CONF;
    m_inputs_map[ska_num][MVB2].at("DIA_CAR_CONFIGURATION")                  = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_CAR_CONFIGURATION;
    m_inputs_map[ska_num][MVB2].at("DIA_EDACTUAL_Bo1_FAILURE")               = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_EDACTUAL_Bo1_FAILURE;
    m_inputs_map[ska_num][MVB2].at("DIA_EDACTUAL_Bo2_FAILURE")               = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_EDACTUAL_Bo2_FAILURE;
    m_inputs_map[ska_num][MVB2].at("bit87")                                 = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit87;
    m_inputs_map[ska_num][MVB2].at("bit88")                                 = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit88;
    m_inputs_map[ska_num][MVB2].at("DIA_POP_SA_DIRECTION_S1")               = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_SA_DIRECTION_S1;
    m_inputs_map[ska_num][MVB2].at("DIA_POP_SA_DIRECTION_S2")               = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_SA_DIRECTION_S2;
    m_inputs_map[ska_num][MVB2].at("DIA_POP_SA_DRYING")                     = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_SA_DRYING;
    m_inputs_map[ska_num][MVB2].at("DIA_POP_SA_BLOWOUT")                    = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_SA_BLOWOUT;
    m_inputs_map[ska_num][MVB2].at("DIA_SANDING_DISTURBED")                 = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_SANDING_DISTURBED;
    m_inputs_map[ska_num][MVB2].at("bit94")                                 = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit94;
    m_inputs_map[ska_num][MVB2].at("bit95")                                 = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit95;
    m_inputs_map[ska_num][MVB2].at("bit96")                                 = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit96;
    m_inputs_map[ska_num][MVB2].at("DIA_DCL_INCPRESS")                      = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_DCL_INCPRESS;
    m_inputs_map[ska_num][MVB2].at("DIA_DCL_DECPRESS")                      = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_DCL_DECPRESS;
    m_inputs_map[ska_num][MVB2].at("DIA_DCL_CONFIG")                        = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_DCL_CONFIG;
    m_inputs_map[ska_num][MVB2].at("DIA_DCL_DEVIATION")                     = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_DCL_DEVIATION;
    m_inputs_map[ska_num][MVB2].at("DIA_DCL_OFFSET")                        = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_DCL_OFFSET;
    m_inputs_map[ska_num][MVB2].at("DIA_DIRECTBRAKE_DIST")                 = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_DIRECTBRAKE_DIST;
    m_inputs_map[ska_num][MVB2].at("DIA_EMERGVALVE")                        = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_EMERGVALVE;
    m_inputs_map[ska_num][MVB2].at("bit104")                                = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit104;
    m_inputs_map[ska_num][MVB2].at("DIA_AIR_SUSP_PRESS_LOW")                = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_AIR_SUSP_PRESS_LOW;
    m_inputs_map[ska_num][MVB2].at("DIA_AIR_SUSP_PRESS_HIGH")               = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_AIR_SUSP_PRESS_HIGH;
    m_inputs_map[ska_num][MVB2].at("DIA_AIR_SUSP_PRESS_BURST")             = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_AIR_SUSP_PRESS_BURST;
    m_inputs_map[ska_num][MVB2].at("DIA_AIR_SUSP_PRESS_ERROR")             = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_AIR_SUSP_PRESS_ERROR;
    m_inputs_map[ska_num][MVB2].at("DIA_MR_PRESS_LOW")                      = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_MR_PRESS_LOW;
    m_inputs_map[ska_num][MVB2].at("DIA_MR_PRESS_ERR")                      = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_MR_PRESS_ERR;
    m_inputs_map[ska_num][MVB2].at("DIA_R_PRESS_LOW")                       = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_R_PRESS_LOW;
    m_inputs_map[ska_num][MVB2].at("DIA_R_PRESS_ERROR")                     = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_R_PRESS_ERROR;
    m_inputs_map[ska_num][MVB2].at("DIA_HBRELEASE_TRAINLINE_IMPL")         = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_HBRELEASE_TRAINLINE_IMPL;
    m_inputs_map[ska_num][MVB2].at("DIA_TRACTION_TRAINLINE_IMPL")          = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_TRACTION_TRAINLINE_IMPL;
    m_inputs_map[ska_num][MVB2].at("DIA_EMERGENCY_TRAINLINE_IMPL")        = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_EMERGENCY_TRAINLINE_IMPL;
    m_inputs_map[ska_num][MVB2].at("DIA_BRAKE_BITS_IMPL")                  = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BRAKE_BITS_IMPL;
    m_inputs_map[ska_num][MVB2].at("DIA_BRAKE_NOT_RELEASED_Bo1")          = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BRAKE_NOT_RELEASED_Bo1;
    m_inputs_map[ska_num][MVB2].at("DIA_BRAKE_NOT_RELEASED_Bo2")          = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BRAKE_NOT_RELEASED_Bo2;
    m_inputs_map[ska_num][MVB2].at("DIA_BRAKE_NOT_APPLIED_Bo1")          = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BRAKE_NOT_APPLIED_Bo1;
    m_inputs_map[ska_num][MVB2].at("DIA_BRAKE_NOT_APPLIED_Bo2")          = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BRAKE_NOT_APPLIED_Bo2;
    m_inputs_map[ska_num][MVB2].at("DIA_PB_NOT_RELEASED")                  = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PB_NOT_RELEASED;
    m_inputs_map[ska_num][MVB2].at("DIA_PB_HOSE_BURST")                    = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PB_HOSE_BURST;
    m_inputs_map[ska_num][MVB2].at("DIA_PB_PG_IMPLAUSIBLE")               = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PB_PG_IMPLAUSIBLE;
    m_inputs_map[ska_num][MVB2].at("DIA_MVB_ERROR_BCU")                    = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_MVB_ERROR_BCU;
    m_inputs_map[ska_num][MVB2].at("DIA_MVB_ERROR_TCU")                    = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_MVB_ERROR_TCU;
    m_inputs_map[ska_num][MVB2].at("DIA_MVB_ERROR_VCU")                    = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_MVB_ERROR_VCU;
    m_inputs_map[ska_num][MVB2].at("bit127")                               = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit127;
    m_inputs_map[ska_num][MVB2].at("bit128")                               = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit128;




}

void Ska_Bcu::update_table(SKA_VEHICLE_NUM ska_x_num, SKA_MVB_NUM mvb_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    // İndeksleri kullanarak tabloyu güncelle
    qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][MVB1]->columnCount() ;
    std::vector<int> valueColumns = {1, 3, 5, 7};
    for(const auto & map:m_inputs_map[ska_num][mvb_num]){


        utils::setTableWidgetValueByNameWithoutColumn(m_tableWidget[ska_num][mvb_num], map.first, map.second);
        //qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT INSIDE FOR LOOP ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;

        //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,3, map.second);
        //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,5, map.second);
        //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,7, map.second);
    }
}


/*
void Ska_Bcu::update_mvb3_map(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_inputs_map[ska_num][MVB3].at("DIA_BOARD_CB09_A2")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARD_CB09_A2;
    m_inputs_map[ska_num][MVB3].at("bit1")                             =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit1;
    m_inputs_map[ska_num][MVB3].at("DIA_CAN_COMM_MB04_04")             =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_CAN_COMM_MB04_04;
    m_inputs_map[ska_num][MVB3].at("DIA_CAN_COMM_MB03_06")             =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_CAN_COMM_MB03_06;
    m_inputs_map[ska_num][MVB3].at("DIA_CAN_COMM_MB03_07")             =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_CAN_COMM_MB03_07;
    m_inputs_map[ska_num][MVB3].at("DIA_CAN_COMM_MB03_08")             =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_CAN_COMM_MB03_08;
    m_inputs_map[ska_num][MVB3].at("DIA_BOARD_MB04_A4")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARD_MB04_A4;
    m_inputs_map[ska_num][MVB3].at("DIA_BOARDCODING_MB04_04")          =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARDCODING_MB04_04;
    m_inputs_map[ska_num][MVB3].at("DIA_EDACTUAL_AX3_FAILURE")         =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_EDACTUAL_AX3_FAILURE;
    m_inputs_map[ska_num][MVB3].at("DIA_EDACTUAL_AX4_FAILURE")         =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_EDACTUAL_AX4_FAILURE;
    m_inputs_map[ska_num][MVB3].at("bit10")                            =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit10;
    m_inputs_map[ska_num][MVB3].at("DIA_CAN_COMM_EB01_09")             =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_CAN_COMM_EB01_09;
    m_inputs_map[ska_num][MVB3].at("DIA_CAN_COMM_EB02_10")             =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_CAN_COMM_EB02_10;
    m_inputs_map[ska_num][MVB3].at("bit13")                            =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit13;
    m_inputs_map[ska_num][MVB3].at("bit14")                            =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit14;
    m_inputs_map[ska_num][MVB3].at("bit15")                            =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit15;
    m_inputs_map[ska_num][MVB3].at("DIA_BOARD_MB03_A6")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARD_MB03_A6;
    m_inputs_map[ska_num][MVB3].at("DIA_BOARDCODING_MB03_06")          =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARDCODING_MB03_06;
    m_inputs_map[ska_num][MVB3].at("bit18")                            =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit18;
    m_inputs_map[ska_num][MVB3].at("bit19")                            =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit19;
    m_inputs_map[ska_num][MVB3].at("bit20")                            =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit20;
    m_inputs_map[ska_num][MVB3].at("DIA_CAN_COMM_CB09_02")             =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_CAN_COMM_CB09_02;
    m_inputs_map[ska_num][MVB3].at("DIA_BOARD_MB03_A7")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARD_MB03_A7;
    m_inputs_map[ska_num][MVB3].at("bit23")                            =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit23;
    m_inputs_map[ska_num][MVB3].at("DIA_BOARDCODING_MB03_07")          =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARDCODING_MB03_07;
    m_inputs_map[ska_num][MVB3].at("DIA_MVB_SBM_BCU")                  =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_MVB_SBM_BCU;
    m_inputs_map[ska_num][MVB3].at("DIA_MVB_GW_SBM")                   =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_MVB_GW_SBM;
    m_inputs_map[ska_num][MVB3].at("bit27")                            =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit27;
    m_inputs_map[ska_num][MVB3].at("DIA_MVB_GW_TBM")                   =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_MVB_GW_TBM;
    m_inputs_map[ska_num][MVB3].at("DIA_BOARD_MB03_A8")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARD_MB03_A8;
    m_inputs_map[ska_num][MVB3].at("DIA_BOARDCODING_MB03_08")          =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARDCODING_MB03_08;
    m_inputs_map[ska_num][MVB3].at("DIA_WSP_FSI_AXLE1")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_FSI_AXLE1;
    m_inputs_map[ska_num][MVB3].at("DIA_WSP_FSI_AXLE2")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_FSI_AXLE2;
    m_inputs_map[ska_num][MVB3].at("DIA_WSP_FSI_AXLE3")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_FSI_AXLE3;
    m_inputs_map[ska_num][MVB3].at("DIA_WSP_FSI_AXLE4")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_FSI_AXLE4;
    m_inputs_map[ska_num][MVB3].at("DIA_BOARD_EB01_09")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARD_EB01_09;
    m_inputs_map[ska_num][MVB3].at("DIA_BOARDCODING_EB01_09")          =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARDCODING_EB01_09;
    m_inputs_map[ska_num][MVB3].at("DIA_BOARD_EB02_10")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARD_EB02_10;
    m_inputs_map[ska_num][MVB3].at("DIA_BOARDCODING_EB02_10")          =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARDCODING_EB02_10;
    m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_C_TB")                 =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_C_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_C_MB")                 =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_C_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_PB_TB")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_PB_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_MRP")                  =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_MRP;
    m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_CVD_TB")               =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_CVD_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_T_TB")                 =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_T_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_R_TB")                 =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_R_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_CVI_TB")               =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_CVI_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_DCL_INCPRESS_TB")              =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_INCPRESS_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_DCL_DECPRESS_TB")              =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_DECPRESS_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_CVD_MB")               =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_CVD_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_T_MB")                 =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_T_MB;
    m_inputs_map[ska_num][MVB3].at("bit51")                            =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit51;
    m_inputs_map[ska_num][MVB3].at("DIA_PB_PG_IMPLAUSIBLE")            =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PB_PG_IMPLAUSIBLE;
    m_inputs_map[ska_num][MVB3].at("DIA_PB_HOSE_BURST_TB")             =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PB_HOSE_BURST_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_MR_PRESS_LOW")                 =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_MR_PRESS_LOW;
    m_inputs_map[ska_num][MVB3].at("DIA_MR_PRESS_ERR")                 =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_MR_PRESS_ERR;
    m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_R_MB")                 =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_R_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_CVI_MB")               =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_CVI_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_DCL_INCPRESS_MB")              =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_INCPRESS_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_DCL_DECPRESS_MB")              =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_DECPRESS_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_POP_BP_Test")                  =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_BP_Test;
    m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_C_TB_WSP")             =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_C_TB_WSP;
    m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_C_MB_WSP")             =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_C_MB_WSP;
    m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_BP")                   =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_BP;
    m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_CV_SA")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_CV_SA;
    m_inputs_map[ska_num][MVB3].at("DIA_DCL_INCPRESS_SA")              =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_INCPRESS_SA;
    m_inputs_map[ska_num][MVB3].at("DIA_DCL_DECPRESS_SA")              =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_DECPRESS_SA;
    m_inputs_map[ska_num][MVB3].at("DIA_POP_SANDING_S2")               =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_SANDING_S2;
    m_inputs_map[ska_num][MVB3].at("DIA_POP_SANDING_S1")               =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_SANDING_S1;
    m_inputs_map[ska_num][MVB3].at("DIA_REL_EBCUFCTOK")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_REL_EBCUFCTOK;
    m_inputs_map[ska_num][MVB3].at("DIA_REL_EBCU_EBLOOP_Y_OPEN")       =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_REL_EBCU_EBLOOP_Y_OPEN;
    m_inputs_map[ska_num][MVB3].at("DIA_REL_EBCU_BRAKE_TEST_OK")       =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_REL_EBCU_BRAKE_TEST_OK;
    m_inputs_map[ska_num][MVB3].at("DIA_REL_WSP_R_VLT5KMHDOOR")        =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_REL_WSP_R_VLT5KMHDOOR;
    m_inputs_map[ska_num][MVB3].at("DIA_REL_WSP_R_VGT5KMHDOOR")        =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_REL_WSP_R_VGT5KMHDOOR;
    m_inputs_map[ska_num][MVB3].at("DIA_REL_WSP_R_VGT10KMHDOOR")       =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_REL_WSP_R_VGT10KMHDOOR;
    m_inputs_map[ska_num][MVB3].at("DIA_WSP_TIMEOUT_AX1")              =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_TIMEOUT_AX1;
    m_inputs_map[ska_num][MVB3].at("DIA_WSP_TIMEOUT_AX2")              =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_TIMEOUT_AX2;
    m_inputs_map[ska_num][MVB3].at("DIA_UWR_TIMEOUT_TB")               =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_UWR_TIMEOUT_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_POP_WSP_Y_HOLD_AX1")           =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_WSP_Y_HOLD_AX1;
    m_inputs_map[ska_num][MVB3].at("DIA_POP_WSP_Y_RELEASE_AX1")        =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_WSP_Y_RELEASE_AX1;
    m_inputs_map[ska_num][MVB3].at("DIA_POP_WSP_Y_HOLD_AX2")           =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_WSP_Y_HOLD_AX2;
    m_inputs_map[ska_num][MVB3].at("DIA_POP_WSP_Y_RELEASE_AX2")        =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_WSP_Y_RELEASE_AX2;
    m_inputs_map[ska_num][MVB3].at("DIA_WSP_FAILURE_TB")               =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_FAILURE_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_SPEED_DV1")                    =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_SPEED_DV1;
    m_inputs_map[ska_num][MVB3].at("DIA_SPEED_DV2")                    =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_SPEED_DV2;
    m_inputs_map[ska_num][MVB3].at("DIA_WSP_TIMEOUT_AX3")              =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_TIMEOUT_AX3;
    m_inputs_map[ska_num][MVB3].at("DIA_WSP_TIMEOUT_AX4")              =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_TIMEOUT_AX4;
    m_inputs_map[ska_num][MVB3].at("DIA_UWR_TIMEOUT_MB")               =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_UWR_TIMEOUT_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_POP_WSP_Y_HOLD_AX3")           =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_WSP_Y_HOLD_AX3;
    m_inputs_map[ska_num][MVB3].at("DIA_POP_WSP_Y_RELEASE_AX3")        =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_WSP_Y_RELEASE_AX3;
    m_inputs_map[ska_num][MVB3].at("DIA_POP_WSP_Y_HOLD_AX4")           =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_WSP_Y_HOLD_AX4;
    m_inputs_map[ska_num][MVB3].at("DIA_POP_WSP_Y_RELEASE_AX4")        =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_WSP_Y_RELEASE_AX4;
    m_inputs_map[ska_num][MVB3].at("DIA_WSP_FAILURE_MB")               =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_FAILURE_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_SPEED_DV3")                    =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_SPEED_DV3;
    m_inputs_map[ska_num][MVB3].at("DIA_SPEED_DV4")                    =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_SPEED_DV4;
    m_inputs_map[ska_num][MVB3].at("DIA_ASSF")                         =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_ASSF;
    m_inputs_map[ska_num][MVB3].at("DIA_WSP_TEST_ABORTED")             =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_TEST_ABORTED;
    m_inputs_map[ska_num][MVB3].at("DIA_DCL_CONFIG_TB")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_CONFIG_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_DCL_DEVIATION_TB")             =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_DEVIATION_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_DCL_OFFSET_TB")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_OFFSET_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_DCL_CONFIG_MB")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_CONFIG_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_DCL_DEVIATION_MB")             =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_DEVIATION_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_DCL_OFFSET_MB")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_OFFSET_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_CAR_CONFIGURATION")            =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_CAR_CONFIGURATION;
    m_inputs_map[ska_num][MVB3].at("DIA_HBRELEASE_TRAINLINE_IML")      =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_HBRELEASE_TRAINLINE_IMPL;
    m_inputs_map[ska_num][MVB3].at("DIA_TRACTION_TRAINLINE_IMPL")      =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_TRACTION_TRAINLINE_IMPL;
    m_inputs_map[ska_num][MVB3].at("DIA_EMERGENCY_TRAINLINE_IMPL")     =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_EMERGENCY_TRAINLINE_IMPL;
    m_inputs_map[ska_num][MVB3].at("DIA_BRAKE_BITS_IMPL")              =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BRAKE_BITS_IMPL;
    m_inputs_map[ska_num][MVB3].at("DIA_AIR_SUSP_PRESS_LOW_TB")        =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_AIR_SUSP_PRESS_LOW_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_AIR_SUSP_PRESS_INVALID_MB")    =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_AIR_SUSP_PRESS_INVALID_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_AIR_SUSP_PRESS_ERROR_TB")      =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_AIR_SUSP_PRESS_ERROR_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_R_PRESS_LOW_TB")               =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_R_PRESS_LOW_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_R_PRESS_ERROR_TB")             =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_R_PRESS_ERROR_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_C_PRESS_HOSE_BREAK_TB")        =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_C_PRESS_HOSE_BREAK_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_DIRECTBRAKE_DIST_TB")          =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DIRECTBRAKE_DIST_TB;
    m_inputs_map[ska_num][MVB3].at("bit115")                           =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit115;
    m_inputs_map[ska_num][MVB3].at("DIA_BRAKE_NOT_RELEASED_TB")        =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BRAKE_NOT_RELEASED_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_BRAKE_NOT_APPLIED_TB")         =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BRAKE_NOT_APPLIED_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_INDIRECTBRAKE_NOT_APPLIED_TB") =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_INDIRECTBRAKE_NOT_APPLIED_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_EMERGVALVE_TB")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_EMERGVALVE_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_PB_NOT_RELEASED_TB")           =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PB_NOT_RELEASED_TB;
    m_inputs_map[ska_num][MVB3].at("DIA_AIR_SUSP_PRESS_LOW_MB")        =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_AIR_SUSP_PRESS_LOW_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_AIR_SUSP_PRESS_INVALID_MB")    =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_AIR_SUSP_PRESS_INVALID_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_AIR_SUSP_PRESS_ERROR_MB")      =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_AIR_SUSP_PRESS_ERROR_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_R_PRESS_LOW_MB")               =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_R_PRESS_LOW_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_R_PRESS_ERROR_MB")             =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_R_PRESS_ERROR_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_C_PRESS_HOSE_BRAKE_MB")        =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_C_PRESS_HOSE_BRAKE_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_DIRECTBRAKE_DIST_MB")          =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DIRECTBRAKE_DIST_MB;
    m_inputs_map[ska_num][MVB3].at("bit128")                           =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit128;
    m_inputs_map[ska_num][MVB3].at("DIA_BRAKE_NOT_RELEASED_MB")        =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BRAKE_NOT_RELEASED_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_BRAKE_NOT_APPLIED_MB")         =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BRAKE_NOT_APPLIED_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_INDIRECTBRAKE_NOT_APPLIED_MB") =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_INDIRECTBRAKE_NOT_APPLIED_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_EMERGVALVE_MB")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_EMERGVALVE_MB;
    m_inputs_map[ska_num][MVB3].at("DIA_SANDING_DISTURBED")            =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_SANDING_DISTURBED;
    m_inputs_map[ska_num][MVB3].at("DIA_MVB_BCU_BCU")                  =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_MVB_BCU_BCU;
    m_inputs_map[ska_num][MVB3].at("DIA_MVB_TCU_BCU")                  =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_MVB_TCU_BCU;
    m_inputs_map[ska_num][MVB3].at("DIA_MVB_CCU_BCU")                  =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_MVB_CCU_BCU;
    m_inputs_map[ska_num][MVB3].at("DIA_DCL_DEVIATION_SA")             =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_DEVIATION_SA;
    m_inputs_map[ska_num][MVB3].at("DIA_DCL_OFFSET_SA")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_OFFSET_SA;
    m_inputs_map[ska_num][MVB3].at("DIA_DCL_CONFIG_SA")                =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_CONFIG_SA;
    m_inputs_map[ska_num][MVB3].at("bit140")                           =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit140;
    m_inputs_map[ska_num][MVB3].at("bit141")                           =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit141;
    m_inputs_map[ska_num][MVB3].at("bit142")                           =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit142;
    m_inputs_map[ska_num][MVB3].at("bit143")                           =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit143;
    m_inputs_map[ska_num][MVB3].at("bit144")                           =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit144;
    m_inputs_map[ska_num][MVB3].at("bit145")                           =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit145;
    m_inputs_map[ska_num][MVB3].at("bit146")                           =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit146;
    m_inputs_map[ska_num][MVB3].at("bit147")                           =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit147;
    m_inputs_map[ska_num][MVB3].at("bit148")                           =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit148;
    m_inputs_map[ska_num][MVB3].at("bit149")                           =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit149;
    m_inputs_map[ska_num][MVB3].at("bit150")                           =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit150;
    m_inputs_map[ska_num][MVB3].at("bit151")                           =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit151;
    m_inputs_map[ska_num][MVB3].at("reserved21")                       =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved21;
    m_inputs_map[ska_num][MVB3].at("reserved22")                       =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved22;
    m_inputs_map[ska_num][MVB3].at("reserved23")                       =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved23;
    m_inputs_map[ska_num][MVB3].at("reserved24")                       =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved24;
    m_inputs_map[ska_num][MVB3].at("reserved25")                       =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved25;
    m_inputs_map[ska_num][MVB3].at("reserved26")                       =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved26;
    m_inputs_map[ska_num][MVB3].at("reserved27")                       =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved27;
    m_inputs_map[ska_num][MVB3].at("reserved28")                       =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved28;
    m_inputs_map[ska_num][MVB3].at("reserved29")                       =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved29;
    m_inputs_map[ska_num][MVB3].at("reserved30")                       =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved30;
    m_inputs_map[ska_num][MVB3].at("reserved31")                       =  m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved31;

}*/

void Ska_Bcu::set_struct_mvb1(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);

    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.XLifeSign = m_inputs_map[ska_num][MVB1].at("XLifeSign")            ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.EBCU_MainVersion = m_inputs_map[ska_num][MVB1].at("EBCU_MainVersion")     ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.EBCU_SubVersion = m_inputs_map[ska_num][MVB1].at("EBCU_SubVersion")      ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_Cpress = m_inputs_map[ska_num][MVB1].at("X_Cpress")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_Tpress= m_inputs_map[ska_num][MVB1].at("X_Tpress")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_PrkBrPress_1= m_inputs_map[ska_num][MVB1].at("X_PrkBrPress_1")       ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_PrkBrPress_2 =     m_inputs_map[ska_num][MVB1].at("X_PrkBrPress_2");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_BPPress= m_inputs_map[ska_num][MVB1].at("X_BPPress")            ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_MRPPress = m_inputs_map[ska_num][MVB1].at("X_MRPPress")           ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.reserved10 = m_inputs_map[ska_num][MVB1].at("reserved10")           ;

    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_LoadWeight=        m_inputs_map[ska_num][MVB1].at("X_LoadWeight")   ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_VAxl1     =   m_inputs_map[ska_num][MVB1].at("X_VAxl1")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_VAxl2     =   m_inputs_map[ska_num][MVB1].at("X_VAxl2")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_VAxl3     =   m_inputs_map[ska_num][MVB1].at("X_VAxl3")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_VAxl4     =       m_inputs_map[ska_num][MVB1].at("X_VAxl4")         ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.X_Vref      =  m_inputs_map[ska_num][MVB1].at("X_Vref")               ;

    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.reserved23          =     m_inputs_map[ska_num][MVB1].at("reserved23");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.reserved24          =     m_inputs_map[ska_num][MVB1].at("reserved24");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_HolBrRe       =         m_inputs_map[ska_num][MVB1].at("S_HolBrRe") ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.V_HolBrRe           =     m_inputs_map[ska_num][MVB1].at("V_HolBrRe") ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_HolBrAp           =     m_inputs_map[ska_num][MVB1].at("S_HolBrAp") ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.V_HolBrAp           =     m_inputs_map[ska_num][MVB1].at("V_HolBrAp") ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_PrkBrRe           =     m_inputs_map[ska_num][MVB1].at("S_PrkBrRe") ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.V_PrkBrRe           =     m_inputs_map[ska_num][MVB1].at("V_PrkBrRe") ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_PrkBrReNot        =       m_inputs_map[ska_num][MVB1].at("S_PrkBrReNot");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.V_PrkBrReNot        =       m_inputs_map[ska_num][MVB1].at("V_PrkBrReNot");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_PnBrRe_Bo1        =       m_inputs_map[ska_num][MVB1].at("S_PnBrRe_Bo1");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.V_PnBrRe_Bo1        =       m_inputs_map[ska_num][MVB1].at("V_PnBrRe_Bo1");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_PnBrAp_Bo1        =       m_inputs_map[ska_num][MVB1].at("S_PnBrAp_Bo1");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.V_PnBrAp_Bo1        =       m_inputs_map[ska_num][MVB1].at("V_PnBrAp_Bo1");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_PnBrRe_Bo2        =       m_inputs_map[ska_num][MVB1].at("S_PnBrRe_Bo2");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.V_PnBrRe_Bo2        =       m_inputs_map[ska_num][MVB1].at("V_PnBrRe_Bo2");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_PnBrAp_Bo2        =       m_inputs_map[ska_num][MVB1].at("S_PnBrAp_Bo2");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.V_PnBrAp_Bo2        =       m_inputs_map[ska_num][MVB1].at("V_PnBrAp_Bo2");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_EmergBrLoopOpen   =            m_inputs_map[ska_num][MVB1].at("S_EmergBrLoopOpen")  ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_TLHolBrRe         =      m_inputs_map[ska_num][MVB1].at("S_TLHolBrRe")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_TLBrakingBit1     =          m_inputs_map[ska_num][MVB1].at("S_TLBrakingBit1")      ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_TLBrakingBit2     =          m_inputs_map[ska_num][MVB1].at("S_TLBrakingBit2")      ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_TLBrakingBit3     =          m_inputs_map[ska_num][MVB1].at("S_TLBrakingBit3")      ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_TLTraction        =       m_inputs_map[ska_num][MVB1].at("S_TLTraction")   ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_WSPTest_Run       =        m_inputs_map[ska_num][MVB1].at("S_WSPTest_Run")  ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_WSPTest_Run_abbort=               m_inputs_map[ska_num][MVB1].at("S_WSPTest_Run_abbort")  ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_WSPactive_Bo1     =          m_inputs_map[ska_num][MVB1].at("S_WSPactive_Bo1");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_WSPok_Bo1         =      m_inputs_map[ska_num][MVB1].at("S_WSPok_Bo1") ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_WSPactive_Bo2     =          m_inputs_map[ska_num][MVB1].at("S_WSPactive_Bo2");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_WSPok_Bo2         =      m_inputs_map[ska_num][MVB1].at("S_WSPok_Bo2");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_Degraded_Mode     =          m_inputs_map[ska_num][MVB1].at("S_Degraded_Mode");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_ASC_Mode_active   =            m_inputs_map[ska_num][MVB1].at("S_ASC_Mode_active");


    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_Standstill = m_inputs_map[ska_num][MVB1].at("S_Standstill")              ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_EBCU_EBL_Open_PB = m_inputs_map[ska_num][MVB1].at("S_EBCU_EBL_Open_PB")      ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.IC_PneuBr = m_inputs_map[ska_num][MVB1].at("IC_PneuBr")                 ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.IC_DirectBr = m_inputs_map[ska_num][MVB1].at("IC_DirectBr")               ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.IC_Cpress_Bo1 = m_inputs_map[ska_num][MVB1].at("IC_Cpress_Bo1")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.IC_Cpress_Bo2 = m_inputs_map[ska_num][MVB1].at("IC_Cpress_Bo2")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.IC_PrkBr = m_inputs_map[ska_num][MVB1].at("IC_PrkBr")                  ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.IC_Sanding = m_inputs_map[ska_num][MVB1].at("IC_Sanding")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.IC_InDirectBr = m_inputs_map[ska_num][MVB1].at("IC_InDirectBr")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_DoorsClosedLocked = m_inputs_map[ska_num][MVB1].at("S_DoorsClosedLocked")       ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_ED_fade_Out = m_inputs_map[ska_num][MVB1].at("S_ED_fade_Out")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_BpApValid = m_inputs_map[ska_num][MVB1].at("S_BpApValid")               ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_BpAP = m_inputs_map[ska_num][MVB1].at("S_BpAP")                    ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_Sanding_Heating_Release = m_inputs_map[ska_num][MVB1].at("S_Sanding_Heating_Release") ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.S_Sanding_Active = m_inputs_map[ska_num][MVB1].at("S_Sanding_Active")          ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.bit246 = m_inputs_map[ska_num][MVB1].at("bit246")                    ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.bit247 = m_inputs_map[ska_num][MVB1].at("bit247")                    ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.bit248 = m_inputs_map[ska_num][MVB1].at("bit248")                    ;
    //m_inputs_map[ska_num][MVB1].at("reserved31")              = m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb1.bits.reserved31;

}

void Ska_Bcu::set_struct_mvb2(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.XLifeSign=           m_inputs_map[ska_num][MVB2].at("XLifeSign");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARD_CB09_02=           m_inputs_map[ska_num][MVB2].at("DIA_BOARD_CB09_02");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARD_MB04_04=           m_inputs_map[ska_num][MVB2].at("DIA_BOARD_MB04_04");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARD_MB03_06=           m_inputs_map[ska_num][MVB2].at("DIA_BOARD_MB03_06");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARD_MB03_07=           m_inputs_map[ska_num][MVB2].at("DIA_BOARD_MB03_07");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARD_EB01_08=           m_inputs_map[ska_num][MVB2].at("DIA_BOARD_EB01_08");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARD_EB02_09=           m_inputs_map[ska_num][MVB2].at("DIA_BOARD_EB02_09");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit23=           m_inputs_map[ska_num][MVB2].at("bit23");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit24=           m_inputs_map[ska_num][MVB2].at("bit24");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARDCODING_MB04_04=           m_inputs_map[ska_num][MVB2].at("DIA_BOARDCODING_MB04_04");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARDCODING_MB03_06=           m_inputs_map[ska_num][MVB2].at("DIA_BOARDCODING_MB03_06");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARDCODING_MB03_07=           m_inputs_map[ska_num][MVB2].at("DIA_BOARDCODING_MB03_07");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARDCODING_EB01_08=           m_inputs_map[ska_num][MVB2].at("DIA_BOARDCODING_EB01_08");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BOARDCODING_EB02_09=           m_inputs_map[ska_num][MVB2].at("DIA_BOARDCODING_EB02_09");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit30=           m_inputs_map[ska_num][MVB2].at("bit30");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit31=           m_inputs_map[ska_num][MVB2].at("bit31");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit32=           m_inputs_map[ska_num][MVB2].at("bit32");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_CAN_COMM_CB09_02=           m_inputs_map[ska_num][MVB2].at("DIA_CAN_COMM_CB09_02");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_CAN_COMM_MB04_03=           m_inputs_map[ska_num][MVB2].at("DIA_CAN_COMM_MB04_03");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_CAN_COMM_MB03_06=           m_inputs_map[ska_num][MVB2].at("DIA_CAN_COMM_MB03_06");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_CAN_COMM_MB03_07=           m_inputs_map[ska_num][MVB2].at("DIA_CAN_COMM_MB03_07");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_CAN_COMM_EB01_08=           m_inputs_map[ska_num][MVB2].at("DIA_CAN_COMM_EB01_08");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_CAN_COMM_EB02_09=           m_inputs_map[ska_num][MVB2].at("DIA_CAN_COMM_EB02_09");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit39=           m_inputs_map[ska_num][MVB2].at("bit39");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit40=           m_inputs_map[ska_num][MVB2].at("bit40");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PSENSOR_C=           m_inputs_map[ska_num][MVB2].at("DIA_PSENSOR_C");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PSENSOR_BP=           m_inputs_map[ska_num][MVB2].at("DIA_PSENSOR_BP");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PSENSOR1_PB=           m_inputs_map[ska_num][MVB2].at("DIA_PSENSOR1_PB");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PSENSOR2_PB=           m_inputs_map[ska_num][MVB2].at("DIA_PSENSOR2_PB");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PSENSOR_CVD=           m_inputs_map[ska_num][MVB2].at("DIA_PSENSOR_CVD");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PSENSOR_T=           m_inputs_map[ska_num][MVB2].at("DIA_PSENSOR_T");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PSENSOR_R=           m_inputs_map[ska_num][MVB2].at("DIA_PSENSOR_R");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PSENSOR_CVI=           m_inputs_map[ska_num][MVB2].at("DIA_PSENSOR_CVI");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PSENSOR_MRP=           m_inputs_map[ska_num][MVB2].at("DIA_PSENSOR_MRP");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_REL_EBCU_FCT_OK=           m_inputs_map[ska_num][MVB2].at("DIA_REL_EBCU_FCT_OK");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_REL_EBCU_EBLOOP_Y_OPEN=           m_inputs_map[ska_num][MVB2].at("DIA_REL_EBCU_EBLOOP_Y_OPEN");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_REL_EBCU_C_EDCUTOFF=           m_inputs_map[ska_num][MVB2].at("DIA_REL_EBCU_C_EDCUTOFF");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_REL_WSP_R_VLT5KMHDOOR=           m_inputs_map[ska_num][MVB2].at("DIA_REL_WSP_R_VLT5KMHDOOR");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_REL_WSP_R_VGT5KMHDOOR=           m_inputs_map[ska_num][MVB2].at("DIA_REL_WSP_R_VGT5KMHDOOR");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_REL_WSP_R_VGT10KMHDOOR=           m_inputs_map[ska_num][MVB2].at("DIA_REL_WSP_R_VGT10KMHDOOR");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit56=           m_inputs_map[ska_num][MVB2].at("bit56");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_FSI_AXLE1=           m_inputs_map[ska_num][MVB2].at("DIA_WSP_FSI_AXLE1");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_FSI_AXLE2=           m_inputs_map[ska_num][MVB2].at("DIA_WSP_FSI_AXLE2");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_FSI_AXLE3=           m_inputs_map[ska_num][MVB2].at("DIA_WSP_FSI_AXLE3");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_FSI_AXLE4=           m_inputs_map[ska_num][MVB2].at("DIA_WSP_FSI_AXLE4");
     m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_SPEED_DV1=           m_inputs_map[ska_num][MVB2].at("DIA_SPEED_DV1");
     m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_SPEED_DV2=           m_inputs_map[ska_num][MVB2].at("DIA_SPEED_DV2");
     m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_SPEED_DV3=           m_inputs_map[ska_num][MVB2].at("DIA_SPEED_DV3");
     m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_SPEED_DV4=           m_inputs_map[ska_num][MVB2].at("DIA_SPEED_DV4");
     m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_HOLD_AX1=           m_inputs_map[ska_num][MVB2].at("DIA_POP_WSP_Y_HOLD_AX1");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_HOLD_AX2=           m_inputs_map[ska_num][MVB2].at("DIA_POP_WSP_Y_HOLD_AX2");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_HOLD_AX3=           m_inputs_map[ska_num][MVB2].at("DIA_POP_WSP_Y_HOLD_AX3");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_HOLD_AX4=           m_inputs_map[ska_num][MVB2].at("DIA_POP_WSP_Y_HOLD_AX4");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_RELEASE_AX1=           m_inputs_map[ska_num][MVB2].at("DIA_POP_WSP_Y_RELEASE_AX1");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_RELEASE_AX2=           m_inputs_map[ska_num][MVB2].at("DIA_POP_WSP_Y_RELEASE_AX2");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_RELEASE_AX3=           m_inputs_map[ska_num][MVB2].at("DIA_POP_WSP_Y_RELEASE_AX3");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_RELEASE_AX4=           m_inputs_map[ska_num][MVB2].at("DIA_POP_WSP_Y_RELEASE_AX4");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_TIMEOUT_AX1=           m_inputs_map[ska_num][MVB2].at("DIA_WSP_TIMEOUT_AX1");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_TIMEOUT_AX2=           m_inputs_map[ska_num][MVB2].at("DIA_WSP_TIMEOUT_AX2");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_TIMEOUT_AX3=           m_inputs_map[ska_num][MVB2].at("DIA_WSP_TIMEOUT_AX3");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_TIMEOUT_AX4=           m_inputs_map[ska_num][MVB2].at("DIA_WSP_TIMEOUT_AX4");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_UWR_TIMEOUT_BO1=           m_inputs_map[ska_num][MVB2].at("DIA_UWR_TIMEOUT_BO1");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_UWR_TIMEOUT_BO2=           m_inputs_map[ska_num][MVB2].at("DIA_UWR_TIMEOUT_BO2");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_FAILURE_BO1=           m_inputs_map[ska_num][MVB2].at("DIA_WSP_FAILURE_BO1");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_FAILURE_BO2=           m_inputs_map[ska_num][MVB2].at("DIA_WSP_FAILURE_BO2");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_ASSF=           m_inputs_map[ska_num][MVB2].at("DIA_ASSF");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_TEST_ABORTED=           m_inputs_map[ska_num][MVB2].at("DIA_WSP_TEST_ABORTED");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_WSP_CONF=           m_inputs_map[ska_num][MVB2].at("DIA_WSP_CONF");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_CAR_CONFIGURATION=           m_inputs_map[ska_num][MVB2].at("DIA_CAR_CONFIGURATION");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_EDACTUAL_Bo1_FAILURE=           m_inputs_map[ska_num][MVB2].at("DIA_EDACTUAL_Bo1_FAILURE");
       m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_EDACTUAL_Bo2_FAILURE=           m_inputs_map[ska_num][MVB2].at("DIA_EDACTUAL_Bo2_FAILURE");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit87=           m_inputs_map[ska_num][MVB2].at("bit87");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit88=           m_inputs_map[ska_num][MVB2].at("bit88");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_SA_DIRECTION_S1=           m_inputs_map[ska_num][MVB2].at("DIA_POP_SA_DIRECTION_S1");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_SA_DIRECTION_S2=          m_inputs_map[ska_num][MVB2].at("DIA_POP_SA_DIRECTION_S2");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_SA_DRYING=           m_inputs_map[ska_num][MVB2].at("DIA_POP_SA_DRYING");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_POP_SA_BLOWOUT=           m_inputs_map[ska_num][MVB2].at("DIA_POP_SA_BLOWOUT");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_SANDING_DISTURBED=           m_inputs_map[ska_num][MVB2].at("DIA_SANDING_DISTURBED");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit94=           m_inputs_map[ska_num][MVB2].at("bit94");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit95=           m_inputs_map[ska_num][MVB2].at("bit95");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit96=           m_inputs_map[ska_num][MVB2].at("bit96");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_DCL_INCPRESS=           m_inputs_map[ska_num][MVB2].at("DIA_DCL_INCPRESS");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_DCL_DECPRESS=           m_inputs_map[ska_num][MVB2].at("DIA_DCL_DECPRESS");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_DCL_CONFIG=           m_inputs_map[ska_num][MVB2].at("DIA_DCL_CONFIG");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_DCL_DEVIATION=           m_inputs_map[ska_num][MVB2].at("DIA_DCL_DEVIATION")=
          m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_DCL_OFFSET;           m_inputs_map[ska_num][MVB2].at("DIA_DCL_OFFSET");
          m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_DIRECTBRAKE_DIST=           m_inputs_map[ska_num][MVB2].at("DIA_DIRECTBRAKE_DIST");
          m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_EMERGVALVE=           m_inputs_map[ska_num][MVB2].at("DIA_EMERGVALVE");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit104=           m_inputs_map[ska_num][MVB2].at("bit104");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_AIR_SUSP_PRESS_LOW=           m_inputs_map[ska_num][MVB2].at("DIA_AIR_SUSP_PRESS_LOW");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_AIR_SUSP_PRESS_HIGH=           m_inputs_map[ska_num][MVB2].at("DIA_AIR_SUSP_PRESS_HIGH");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_AIR_SUSP_PRESS_BURST=           m_inputs_map[ska_num][MVB2].at("DIA_AIR_SUSP_PRESS_BURST");
      m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_AIR_SUSP_PRESS_ERROR=           m_inputs_map[ska_num][MVB2].at("DIA_AIR_SUSP_PRESS_ERROR");
     m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_MR_PRESS_LOW=           m_inputs_map[ska_num][MVB2].at("DIA_MR_PRESS_LOW")                         ;
     m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_MR_PRESS_ERR=           m_inputs_map[ska_num][MVB2].at("DIA_MR_PRESS_ERR");
     m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_R_PRESS_LOW=           m_inputs_map[ska_num][MVB2].at("DIA_R_PRESS_LOW");
     m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_R_PRESS_ERROR=           m_inputs_map[ska_num][MVB2].at("DIA_R_PRESS_ERROR");
     m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_HBRELEASE_TRAINLINE_IMPL=           m_inputs_map[ska_num][MVB2].at("DIA_HBRELEASE_TRAINLINE_IMPL");
     m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_TRACTION_TRAINLINE_IMPL=           m_inputs_map[ska_num][MVB2].at("DIA_TRACTION_TRAINLINE_IMPL");
     m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_EMERGENCY_TRAINLINE_IMPL=           m_inputs_map[ska_num][MVB2].at("DIA_EMERGENCY_TRAINLINE_IMPL") ;
     m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BRAKE_BITS_IMPL=           m_inputs_map[ska_num][MVB2].at("DIA_BRAKE_BITS_IMPL");
     m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BRAKE_NOT_RELEASED_Bo1=           m_inputs_map[ska_num][MVB2].at("DIA_BRAKE_NOT_RELEASED_Bo1")     ;
     m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BRAKE_NOT_RELEASED_Bo2=           m_inputs_map[ska_num][MVB2].at("DIA_BRAKE_NOT_RELEASED_Bo2")     ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BRAKE_NOT_APPLIED_Bo1=           m_inputs_map[ska_num][MVB2].at("DIA_BRAKE_NOT_APPLIED_Bo1")        ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_BRAKE_NOT_APPLIED_Bo2=           m_inputs_map[ska_num][MVB2].at("DIA_BRAKE_NOT_APPLIED_Bo2")        ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PB_NOT_RELEASED=           m_inputs_map[ska_num][MVB2].at("DIA_PB_NOT_RELEASED");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PB_HOSE_BURST=           m_inputs_map[ska_num][MVB2].at("DIA_PB_HOSE_BURST");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_PB_PG_IMPLAUSIBLE=           m_inputs_map[ska_num][MVB2].at("DIA_PB_PG_IMPLAUSIBLE")               ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_MVB_ERROR_BCU=           m_inputs_map[ska_num][MVB2].at("DIA_MVB_ERROR_BCU");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_MVB_ERROR_TCU=           m_inputs_map[ska_num][MVB2].at("DIA_MVB_ERROR_TCU");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.DIA_MVB_ERROR_VCU=           m_inputs_map[ska_num][MVB2].at("DIA_MVB_ERROR_VCU");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit127=           m_inputs_map[ska_num][MVB2].at("bit127");
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb2.bits.bit128=           m_inputs_map[ska_num][MVB2].at("bit128");


}
/*
void Ska_Bcu::set_struct_mvb3(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARD_CB09_A2                        =m_inputs_map[ska_num][MVB3].at("DIA_BOARD_CB09_A2")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit1                                     =m_inputs_map[ska_num][MVB3].at("bit1")                             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_CAN_COMM_MB04_04                     =m_inputs_map[ska_num][MVB3].at("DIA_CAN_COMM_MB04_04")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_CAN_COMM_MB03_06                     =m_inputs_map[ska_num][MVB3].at("DIA_CAN_COMM_MB03_06")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_CAN_COMM_MB03_07                     =m_inputs_map[ska_num][MVB3].at("DIA_CAN_COMM_MB03_07")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_CAN_COMM_MB03_08                     =m_inputs_map[ska_num][MVB3].at("DIA_CAN_COMM_MB03_08")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARD_MB04_A4                        =m_inputs_map[ska_num][MVB3].at("DIA_BOARD_MB04_A4")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARDCODING_MB04_04                  =m_inputs_map[ska_num][MVB3].at("DIA_BOARDCODING_MB04_04")          ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_EDACTUAL_AX3_FAILURE                 =m_inputs_map[ska_num][MVB3].at("DIA_EDACTUAL_AX3_FAILURE")         ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_EDACTUAL_AX4_FAILURE                 =m_inputs_map[ska_num][MVB3].at("DIA_EDACTUAL_AX4_FAILURE")         ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit10                                    =m_inputs_map[ska_num][MVB3].at("bit10")                            ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_CAN_COMM_EB01_09                     =m_inputs_map[ska_num][MVB3].at("DIA_CAN_COMM_EB01_09")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_CAN_COMM_EB02_10                     =m_inputs_map[ska_num][MVB3].at("DIA_CAN_COMM_EB02_10")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit13                                    =m_inputs_map[ska_num][MVB3].at("bit13")                            ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit14                                    =m_inputs_map[ska_num][MVB3].at("bit14")                            ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit15                                    =m_inputs_map[ska_num][MVB3].at("bit15")                            ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARD_MB03_A6                        =m_inputs_map[ska_num][MVB3].at("DIA_BOARD_MB03_A6")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARDCODING_MB03_06                  =m_inputs_map[ska_num][MVB3].at("DIA_BOARDCODING_MB03_06")          ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit18                                    =m_inputs_map[ska_num][MVB3].at("bit18")                            ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit19                                    =m_inputs_map[ska_num][MVB3].at("bit19")                            ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit20                                    =m_inputs_map[ska_num][MVB3].at("bit20")                            ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_CAN_COMM_CB09_02                     =m_inputs_map[ska_num][MVB3].at("DIA_CAN_COMM_CB09_02")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARD_MB03_A7                        =m_inputs_map[ska_num][MVB3].at("DIA_BOARD_MB03_A7")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit23                                    =m_inputs_map[ska_num][MVB3].at("bit23")                            ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARDCODING_MB03_07                  =m_inputs_map[ska_num][MVB3].at("DIA_BOARDCODING_MB03_07")          ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_MVB_SBM_BCU                          =m_inputs_map[ska_num][MVB3].at("DIA_MVB_SBM_BCU")                  ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_MVB_GW_SBM                           =m_inputs_map[ska_num][MVB3].at("DIA_MVB_GW_SBM")                   ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit27                                    =m_inputs_map[ska_num][MVB3].at("bit27")                            ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_MVB_GW_TBM                           =m_inputs_map[ska_num][MVB3].at("DIA_MVB_GW_TBM")                   ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARD_MB03_A8                        =m_inputs_map[ska_num][MVB3].at("DIA_BOARD_MB03_A8")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARDCODING_MB03_08                  =m_inputs_map[ska_num][MVB3].at("DIA_BOARDCODING_MB03_08")          ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_FSI_AXLE1                        =m_inputs_map[ska_num][MVB3].at("DIA_WSP_FSI_AXLE1")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_FSI_AXLE2                        =m_inputs_map[ska_num][MVB3].at("DIA_WSP_FSI_AXLE2")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_FSI_AXLE3                        =m_inputs_map[ska_num][MVB3].at("DIA_WSP_FSI_AXLE3")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_FSI_AXLE4                        =m_inputs_map[ska_num][MVB3].at("DIA_WSP_FSI_AXLE4")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARD_EB01_09                        =m_inputs_map[ska_num][MVB3].at("DIA_BOARD_EB01_09")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARDCODING_EB01_09                  =m_inputs_map[ska_num][MVB3].at("DIA_BOARDCODING_EB01_09")          ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARD_EB02_10                        =m_inputs_map[ska_num][MVB3].at("DIA_BOARD_EB02_10")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BOARDCODING_EB02_10                  =m_inputs_map[ska_num][MVB3].at("DIA_BOARDCODING_EB02_10")          ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_C_TB                         =m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_C_TB")                 ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_C_MB                         =m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_C_MB")                 ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_PB_TB                        =m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_PB_TB")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_MRP                          =m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_MRP")                  ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_CVD_TB                       =m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_CVD_TB")               ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_T_TB                         =m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_T_TB")                 ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_R_TB                         =m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_R_TB")                 ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_CVI_TB                       =m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_CVI_TB")               ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_INCPRESS_TB                      =m_inputs_map[ska_num][MVB3].at("DIA_DCL_INCPRESS_TB")              ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_DECPRESS_TB                      =m_inputs_map[ska_num][MVB3].at("DIA_DCL_DECPRESS_TB")              ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_CVD_MB                       =m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_CVD_MB")               ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_T_MB                         =m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_T_MB")                 ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit51                                    =m_inputs_map[ska_num][MVB3].at("bit51")                            ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PB_PG_IMPLAUSIBLE                    =m_inputs_map[ska_num][MVB3].at("DIA_PB_PG_IMPLAUSIBLE")            ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PB_HOSE_BURST_TB                     =m_inputs_map[ska_num][MVB3].at("DIA_PB_HOSE_BURST_TB")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_MR_PRESS_LOW                         =m_inputs_map[ska_num][MVB3].at("DIA_MR_PRESS_LOW")                 ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_MR_PRESS_ERR                         =m_inputs_map[ska_num][MVB3].at("DIA_MR_PRESS_ERR")                 ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_R_MB                         =m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_R_MB")                 ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_CVI_MB                       =m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_CVI_MB")               ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_INCPRESS_MB                      =m_inputs_map[ska_num][MVB3].at("DIA_DCL_INCPRESS_MB")              ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_DECPRESS_MB                      =m_inputs_map[ska_num][MVB3].at("DIA_DCL_DECPRESS_MB")              ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_BP_Test                          =m_inputs_map[ska_num][MVB3].at("DIA_POP_BP_Test")                  ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_C_TB_WSP                     =m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_C_TB_WSP")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_C_MB_WSP                     =m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_C_MB_WSP")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_BP                           =m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_BP")                   ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PSENSOR_CV_SA                        =m_inputs_map[ska_num][MVB3].at("DIA_PSENSOR_CV_SA")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_INCPRESS_SA                      =m_inputs_map[ska_num][MVB3].at("DIA_DCL_INCPRESS_SA")              ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_DECPRESS_SA                      =m_inputs_map[ska_num][MVB3].at("DIA_DCL_DECPRESS_SA")              ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_SANDING_S2                       =m_inputs_map[ska_num][MVB3].at("DIA_POP_SANDING_S2")               ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_SANDING_S1                       =m_inputs_map[ska_num][MVB3].at("DIA_POP_SANDING_S1")               ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_REL_EBCUFCTOK                        =m_inputs_map[ska_num][MVB3].at("DIA_REL_EBCUFCTOK")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_REL_EBCU_EBLOOP_Y_OPEN               =m_inputs_map[ska_num][MVB3].at("DIA_REL_EBCU_EBLOOP_Y_OPEN")       ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_REL_EBCU_BRAKE_TEST_OK               =m_inputs_map[ska_num][MVB3].at("DIA_REL_EBCU_BRAKE_TEST_OK")       ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_REL_WSP_R_VLT5KMHDOOR                =m_inputs_map[ska_num][MVB3].at("DIA_REL_WSP_R_VLT5KMHDOOR")        ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_REL_WSP_R_VGT5KMHDOOR                =m_inputs_map[ska_num][MVB3].at("DIA_REL_WSP_R_VGT5KMHDOOR")        ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_REL_WSP_R_VGT10KMHDOOR               =m_inputs_map[ska_num][MVB3].at("DIA_REL_WSP_R_VGT10KMHDOOR")       ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_TIMEOUT_AX1                      =m_inputs_map[ska_num][MVB3].at("DIA_WSP_TIMEOUT_AX1")              ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_TIMEOUT_AX2                      =m_inputs_map[ska_num][MVB3].at("DIA_WSP_TIMEOUT_AX2")              ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_UWR_TIMEOUT_TB                       =m_inputs_map[ska_num][MVB3].at("DIA_UWR_TIMEOUT_TB")               ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_WSP_Y_HOLD_AX1                   =m_inputs_map[ska_num][MVB3].at("DIA_POP_WSP_Y_HOLD_AX1")           ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_WSP_Y_RELEASE_AX1                =m_inputs_map[ska_num][MVB3].at("DIA_POP_WSP_Y_RELEASE_AX1")        ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_WSP_Y_HOLD_AX2                   =m_inputs_map[ska_num][MVB3].at("DIA_POP_WSP_Y_HOLD_AX2")           ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_WSP_Y_RELEASE_AX2                =m_inputs_map[ska_num][MVB3].at("DIA_POP_WSP_Y_RELEASE_AX2")        ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_FAILURE_TB                       =m_inputs_map[ska_num][MVB3].at("DIA_WSP_FAILURE_TB")               ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_SPEED_DV1                            =m_inputs_map[ska_num][MVB3].at("DIA_SPEED_DV1")                    ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_SPEED_DV2                            =m_inputs_map[ska_num][MVB3].at("DIA_SPEED_DV2")                    ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_TIMEOUT_AX3                      =m_inputs_map[ska_num][MVB3].at("DIA_WSP_TIMEOUT_AX3")              ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_TIMEOUT_AX4                      =m_inputs_map[ska_num][MVB3].at("DIA_WSP_TIMEOUT_AX4")              ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_UWR_TIMEOUT_MB                       =m_inputs_map[ska_num][MVB3].at("DIA_UWR_TIMEOUT_MB")               ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_WSP_Y_HOLD_AX3                   =m_inputs_map[ska_num][MVB3].at("DIA_POP_WSP_Y_HOLD_AX3")           ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_WSP_Y_RELEASE_AX3                =m_inputs_map[ska_num][MVB3].at("DIA_POP_WSP_Y_RELEASE_AX3")        ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_WSP_Y_HOLD_AX4                   =m_inputs_map[ska_num][MVB3].at("DIA_POP_WSP_Y_HOLD_AX4")           ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_POP_WSP_Y_RELEASE_AX4                =m_inputs_map[ska_num][MVB3].at("DIA_POP_WSP_Y_RELEASE_AX4")        ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_FAILURE_MB                       =m_inputs_map[ska_num][MVB3].at("DIA_WSP_FAILURE_MB")               ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_SPEED_DV3                            =m_inputs_map[ska_num][MVB3].at("DIA_SPEED_DV3")                    ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_SPEED_DV4                            =m_inputs_map[ska_num][MVB3].at("DIA_SPEED_DV4")                    ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_ASSF                                 =m_inputs_map[ska_num][MVB3].at("DIA_ASSF")                         ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_WSP_TEST_ABORTED                     =m_inputs_map[ska_num][MVB3].at("DIA_WSP_TEST_ABORTED")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_CONFIG_TB                        =m_inputs_map[ska_num][MVB3].at("DIA_DCL_CONFIG_TB")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_DEVIATION_TB                     =m_inputs_map[ska_num][MVB3].at("DIA_DCL_DEVIATION_TB")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_OFFSET_TB                        =m_inputs_map[ska_num][MVB3].at("DIA_DCL_OFFSET_TB")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_CONFIG_MB                        =m_inputs_map[ska_num][MVB3].at("DIA_DCL_CONFIG_MB")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_DEVIATION_MB                     =m_inputs_map[ska_num][MVB3].at("DIA_DCL_DEVIATION_MB")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_OFFSET_MB                        =m_inputs_map[ska_num][MVB3].at("DIA_DCL_OFFSET_MB")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_CAR_CONFIGURATION                    =m_inputs_map[ska_num][MVB3].at("DIA_CAR_CONFIGURATION")            ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_HBRELEASE_TRAINLINE_IMPL             =m_inputs_map[ska_num][MVB3].at("DIA_HBRELEASE_TRAINLINE_IML")      ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_TRACTION_TRAINLINE_IMPL              =m_inputs_map[ska_num][MVB3].at("DIA_TRACTION_TRAINLINE_IMPL")      ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_EMERGENCY_TRAINLINE_IMPL             =m_inputs_map[ska_num][MVB3].at("DIA_EMERGENCY_TRAINLINE_IMPL")     ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BRAKE_BITS_IMPL                      =m_inputs_map[ska_num][MVB3].at("DIA_BRAKE_BITS_IMPL")              ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_AIR_SUSP_PRESS_LOW_TB                =m_inputs_map[ska_num][MVB3].at("DIA_AIR_SUSP_PRESS_LOW_TB")        ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_AIR_SUSP_PRESS_INVALID_MB            =m_inputs_map[ska_num][MVB3].at("DIA_AIR_SUSP_PRESS_INVALID_MB")    ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_AIR_SUSP_PRESS_ERROR_TB              =m_inputs_map[ska_num][MVB3].at("DIA_AIR_SUSP_PRESS_ERROR_TB")      ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_R_PRESS_LOW_TB                       =m_inputs_map[ska_num][MVB3].at("DIA_R_PRESS_LOW_TB")               ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_R_PRESS_ERROR_TB                     =m_inputs_map[ska_num][MVB3].at("DIA_R_PRESS_ERROR_TB")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_C_PRESS_HOSE_BREAK_TB                =m_inputs_map[ska_num][MVB3].at("DIA_C_PRESS_HOSE_BREAK_TB")        ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DIRECTBRAKE_DIST_TB                  =m_inputs_map[ska_num][MVB3].at("DIA_DIRECTBRAKE_DIST_TB")          ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit115                                   =m_inputs_map[ska_num][MVB3].at("bit115")                           ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BRAKE_NOT_RELEASED_TB                =m_inputs_map[ska_num][MVB3].at("DIA_BRAKE_NOT_RELEASED_TB")        ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BRAKE_NOT_APPLIED_TB                 =m_inputs_map[ska_num][MVB3].at("DIA_BRAKE_NOT_APPLIED_TB")         ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_INDIRECTBRAKE_NOT_APPLIED_TB         =m_inputs_map[ska_num][MVB3].at("DIA_INDIRECTBRAKE_NOT_APPLIED_TB") ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_EMERGVALVE_TB                        =m_inputs_map[ska_num][MVB3].at("DIA_EMERGVALVE_TB")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_PB_NOT_RELEASED_TB                   =m_inputs_map[ska_num][MVB3].at("DIA_PB_NOT_RELEASED_TB")           ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_AIR_SUSP_PRESS_LOW_MB                =m_inputs_map[ska_num][MVB3].at("DIA_AIR_SUSP_PRESS_LOW_MB")        ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_AIR_SUSP_PRESS_INVALID_MB            =m_inputs_map[ska_num][MVB3].at("DIA_AIR_SUSP_PRESS_INVALID_MB")    ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_AIR_SUSP_PRESS_ERROR_MB              =m_inputs_map[ska_num][MVB3].at("DIA_AIR_SUSP_PRESS_ERROR_MB")      ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_R_PRESS_LOW_MB                       =m_inputs_map[ska_num][MVB3].at("DIA_R_PRESS_LOW_MB")               ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_R_PRESS_ERROR_MB                     =m_inputs_map[ska_num][MVB3].at("DIA_R_PRESS_ERROR_MB")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_C_PRESS_HOSE_BRAKE_MB                =m_inputs_map[ska_num][MVB3].at("DIA_C_PRESS_HOSE_BRAKE_MB")        ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DIRECTBRAKE_DIST_MB                  =m_inputs_map[ska_num][MVB3].at("DIA_DIRECTBRAKE_DIST_MB")          ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit128                                   =m_inputs_map[ska_num][MVB3].at("bit128")                           ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BRAKE_NOT_RELEASED_MB                =m_inputs_map[ska_num][MVB3].at("DIA_BRAKE_NOT_RELEASED_MB")        ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_BRAKE_NOT_APPLIED_MB                 =m_inputs_map[ska_num][MVB3].at("DIA_BRAKE_NOT_APPLIED_MB")         ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_INDIRECTBRAKE_NOT_APPLIED_MB         =m_inputs_map[ska_num][MVB3].at("DIA_INDIRECTBRAKE_NOT_APPLIED_MB") ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_EMERGVALVE_MB                        =m_inputs_map[ska_num][MVB3].at("DIA_EMERGVALVE_MB")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_SANDING_DISTURBED                    =m_inputs_map[ska_num][MVB3].at("DIA_SANDING_DISTURBED")            ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_MVB_BCU_BCU                          =m_inputs_map[ska_num][MVB3].at("DIA_MVB_BCU_BCU")                  ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_MVB_TCU_BCU                          =m_inputs_map[ska_num][MVB3].at("DIA_MVB_TCU_BCU")                  ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_MVB_CCU_BCU                          =m_inputs_map[ska_num][MVB3].at("DIA_MVB_CCU_BCU")                  ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_DEVIATION_SA                     =m_inputs_map[ska_num][MVB3].at("DIA_DCL_DEVIATION_SA")             ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_OFFSET_SA                        =m_inputs_map[ska_num][MVB3].at("DIA_DCL_OFFSET_SA")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.DIA_DCL_CONFIG_SA                        =m_inputs_map[ska_num][MVB3].at("DIA_DCL_CONFIG_SA")                ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit140                                   =m_inputs_map[ska_num][MVB3].at("bit140")                           ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit141                                   =m_inputs_map[ska_num][MVB3].at("bit141")                           ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit142                                   =m_inputs_map[ska_num][MVB3].at("bit142")                           ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit143                                   =m_inputs_map[ska_num][MVB3].at("bit143")                           ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit144                                   =m_inputs_map[ska_num][MVB3].at("bit144")                           ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit145                                   =m_inputs_map[ska_num][MVB3].at("bit145")                           ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit146                                   =m_inputs_map[ska_num][MVB3].at("bit146")                           ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit147                                   =m_inputs_map[ska_num][MVB3].at("bit147")                           ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit148                                   =m_inputs_map[ska_num][MVB3].at("bit148")                           ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit149                                   =m_inputs_map[ska_num][MVB3].at("bit149")                           ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit150                                   =m_inputs_map[ska_num][MVB3].at("bit150")                           ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.bit151                                   =m_inputs_map[ska_num][MVB3].at("bit151")                           ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved21                               =m_inputs_map[ska_num][MVB3].at("reserved21")                       ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved22                               =m_inputs_map[ska_num][MVB3].at("reserved22")                       ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved23                               =m_inputs_map[ska_num][MVB3].at("reserved23")                       ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved24                               =m_inputs_map[ska_num][MVB3].at("reserved24")                       ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved25                               =m_inputs_map[ska_num][MVB3].at("reserved25")                       ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved26                               =m_inputs_map[ska_num][MVB3].at("reserved26")                       ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved27                               =m_inputs_map[ska_num][MVB3].at("reserved27")                       ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved28                               =m_inputs_map[ska_num][MVB3].at("reserved28")                       ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved29                               =m_inputs_map[ska_num][MVB3].at("reserved29")                       ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved30                               =m_inputs_map[ska_num][MVB3].at("reserved30")                       ;
    m_ska_x_bcu[ska_num].ska_bcu_ccu_mvb3.bits.reserved31                               =m_inputs_map[ska_num][MVB3].at("reserved31")                       ;

}*/

void Ska_Bcu::init_oa_x_mvb1_table(SKA_VEHICLE_NUM vehicle_type)
{
    int ska_num = static_cast<int>(vehicle_type);
    m_inputs_map[ska_num][MVB1] = {
        {"XLifeSign", 0},               // byte 0
        {"EBCU_MainVersion", 0},        // byte 2
        {"EBCU_SubVersion", 0},
        {"X_Cpress", 0},
        {"X_Tpress", 0},
        {"X_PrkBrPress_1", 0},
        {"X_PrkBrPress_2", 0},
        {"X_BPPress", 0},
        {"X_MRPPress", 0},
        {"reserved10", 0},              // byte 10
        {"X_LoadWeight", 0},            // byte 11
        {"X_VAxl1", 0},                 // byte 13
        {"X_VAxl2", 0},                 // byte 15
        {"X_VAxl3", 0},                 // byte 17
        {"X_VAxl4", 0},                 // byte 19
        {"X_Vref", 0},                  // byte 21
        {"reserved23", 0},              // byte 23
        {"reserved24", 0},              // byte 24
        {"S_HolBrRe", 0},               // byte 25
        {"V_HolBrRe", 0},
        {"S_HolBrAp", 0},
        {"V_HolBrAp", 0},
        {"S_PrkBrRe", 0},
        {"V_PrkBrRe", 0},
        {"S_PrkBrReNot", 0},
        {"V_PrkBrReNot", 0},
        {"S_PnBrRe_Bo1", 0},           // byte 26
        {"V_PnBrRe_Bo1", 0},
        {"S_PnBrAp_Bo1", 0},
        {"V_PnBrAp_Bo1", 0},
        {"S_PnBrRe_Bo2", 0},
        {"V_PnBrRe_Bo2", 0},
        {"S_PnBrAp_Bo2", 0},
        {"V_PnBrAp_Bo2", 0},
        {"S_EmergBrLoopOpen", 0},      // byte 27
        {"S_TLHolBrRe", 0},
        {"S_TLBrakingBit1", 0},
        {"S_TLBrakingBit2", 0},
        {"S_TLBrakingBit3", 0},
        {"S_TLTraction", 0},
        {"S_WSPTest_Run", 0},
        {"S_WSPTest_Run_abbort", 0},
        {"S_WSPactive_Bo1", 0},        // byte 28
        {"S_WSPok_Bo1", 0},
        {"S_WSPactive_Bo2", 0},
        {"S_WSPok_Bo2", 0},
        {"S_Degraded_Mode", 0},
        {"S_ASC_Mode_active", 0},
        {"S_Standstill", 0},
        {"S_EBCU_EBL_Open_PB", 0},
        {"IC_PneuBr", 0},              // byte 29
        {"IC_DirectBr", 0},
        {"IC_Cpress_Bo1", 0},
        {"IC_Cpress_Bo2", 0},
        {"IC_PrkBr", 0},
        {"IC_Sanding", 0},
        {"IC_InDirectBr", 0},
        {"S_DoorsClosedLocked", 0},
        {"S_ED_fade_Out", 0},          // byte 30
        {"S_BpApValid", 0},
        {"S_BpAP", 0},
        {"S_Sanding_Heating_Release", 0},
        {"S_Sanding_Active", 0},
        {"bit246", 0},
        {"bit247", 0},
        {"bit248", 0},
        //{"reserved31", 0}
    };

    /*m_tableWidget[ska_num][MVB1] = new QTableWidget();
    m_tableWidget[ska_num][MVB1]->setColumnCount(2);
    m_tableWidget[ska_num][MVB1]->setRowCount(m_inputs_map[ska_num][MVB1].size());
    m_tableWidget[ska_num][MVB1]->setHorizontalHeaderLabels(table_name[ska_num][MVB1]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[ska_num][MVB1]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[ska_num][MVB1]->setItem(row, 0, item_name);
        m_tableWidget[ska_num][MVB1]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[ska_num][MVB1]->resizeColumnsToContents();*/

    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[ska_num][MVB1].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[ska_num][MVB1] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[ska_num][MVB1]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[ska_num][MVB1]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[ska_num][MVB1]->setItem(row, column, item_name);
        m_tableWidget[ska_num][MVB1]->setItem(row, column + 1, item_val); // Değer

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[ska_num][MVB1]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][MVB1]->columnCount() ;

}

void Ska_Bcu::init_oa_x_mvb2_table(SKA_VEHICLE_NUM vehicle_type)
{
    int ska_num = static_cast<int>(vehicle_type);
    m_inputs_map[ska_num][MVB2] = {
                                   {"XLifeSign", 0}, // byte0
                                   {"DIA_BOARD_CB09_02", 0}, // byte2
                                   {"DIA_BOARD_MB04_04", 0},
                                   {"DIA_BOARD_MB03_06", 0},
                                   {"DIA_BOARD_MB03_07", 0},
                                   {"DIA_BOARD_EB01_08", 0},
                                   {"DIA_BOARD_EB02_09", 0},
                                   {"bit23", 0},
                                   {"bit24", 0},
                                   {"DIA_BOARDCODING_MB04_04", 0}, // byte3
                                   {"DIA_BOARDCODING_MB03_06", 0},
                                   {"DIA_BOARDCODING_MB03_07", 0},
                                   {"DIA_BOARDCODING_EB01_08", 0},
                                   {"DIA_BOARDCODING_EB02_09", 0},
                                   {"bit30", 0},
                                   {"bit31", 0},
                                   {"bit32", 0},
                                   {"DIA_CAN_COMM_CB09_02", 0}, // byte4
                                   {"DIA_CAN_COMM_MB04_03", 0},
                                   {"DIA_CAN_COMM_MB03_06", 0},
                                   {"DIA_CAN_COMM_MB03_07", 0},
                                   {"DIA_CAN_COMM_EB01_08", 0},
                                   {"DIA_CAN_COMM_EB02_09", 0},
                                   {"bit39", 0},
                                   {"bit40", 0},
                                   {"DIA_PSENSOR_C", 0}, // byte5
                                   {"DIA_PSENSOR_BP", 0},
                                   {"DIA_PSENSOR1_PB", 0},
                                   {"DIA_PSENSOR2_PB", 0},
                                   {"DIA_PSENSOR_CVD", 0},
                                   {"DIA_PSENSOR_T", 0},
                                   {"DIA_PSENSOR_R", 0},
                                   {"DIA_PSENSOR_CVI", 0},
                                   {"DIA_PSENSOR_MRP", 0}, // byte6
                                   {"DIA_REL_EBCU_FCT_OK", 0},
                                   {"DIA_REL_EBCU_EBLOOP_Y_OPEN", 0},
                                   {"DIA_REL_EBCU_C_EDCUTOFF", 0},
                                   {"DIA_REL_WSP_R_VLT5KMHDOOR", 0},
                                   {"DIA_REL_WSP_R_VGT5KMHDOOR", 0},
                                   {"DIA_REL_WSP_R_VGT10KMHDOOR", 0},
                                   {"bit56", 0},
                                   {"DIA_WSP_FSI_AXLE1", 0}, // byte7
                                   {"DIA_WSP_FSI_AXLE2", 0},
                                   {"DIA_WSP_FSI_AXLE3", 0},
                                   {"DIA_WSP_FSI_AXLE4", 0},
                                   {"DIA_SPEED_DV1", 0},
                                   {"DIA_SPEED_DV2", 0},
                                   {"DIA_SPEED_DV3", 0},
                                   {"DIA_SPEED_DV4", 0},
                                   {"DIA_POP_WSP_Y_HOLD_AX1", 0}, // byte8
                                   {"DIA_POP_WSP_Y_HOLD_AX2", 0},
                                   {"DIA_POP_WSP_Y_HOLD_AX3", 0},
                                   {"DIA_POP_WSP_Y_HOLD_AX4", 0},
                                   {"DIA_POP_WSP_Y_RELEASE_AX1", 0},
                                   {"DIA_POP_WSP_Y_RELEASE_AX2", 0},
                                   {"DIA_POP_WSP_Y_RELEASE_AX3", 0},
                                   {"DIA_POP_WSP_Y_RELEASE_AX4", 0},
                                   {"DIA_WSP_TIMEOUT_AX1", 0}, // byte9
                                   {"DIA_WSP_TIMEOUT_AX2", 0},
                                   {"DIA_WSP_TIMEOUT_AX3", 0},
                                   {"DIA_WSP_TIMEOUT_AX4", 0},
                                   {"DIA_UWR_TIMEOUT_BO1", 0},
                                   {"DIA_UWR_TIMEOUT_BO2", 0},
                                   {"DIA_WSP_FAILURE_BO1", 0},
                                   {"DIA_WSP_FAILURE_BO2", 0},
                                   {"DIA_ASSF", 0}, // byte10
                                   {"DIA_WSP_TEST_ABORTED", 0},
                                   {"DIA_WSP_CONF", 0},
                                   {"DIA_CAR_CONFIGURATION", 0},
                                   {"DIA_EDACTUAL_Bo1_FAILURE", 0},
                                   {"DIA_EDACTUAL_Bo2_FAILURE", 0},
                                   {"bit87", 0},
                                   {"bit88", 0},
                                   {"DIA_POP_SA_DIRECTION_S1", 0}, // byte11
                                   {"DIA_POP_SA_DIRECTION_S2", 0},
                                   {"DIA_POP_SA_DRYING", 0},
                                   {"DIA_POP_SA_BLOWOUT", 0},
                                   {"DIA_SANDING_DISTURBED", 0},
                                   {"bit94", 0},
                                   {"bit95", 0},
                                   {"bit96", 0},
                                   {"DIA_DCL_INCPRESS", 0}, // byte12
                                   {"DIA_DCL_DECPRESS", 0},
                                   {"DIA_DCL_CONFIG", 0},
                                   {"DIA_DCL_DEVIATION", 0},
                                   {"DIA_DCL_OFFSET", 0},
                                   {"DIA_DIRECTBRAKE_DIST", 0},
                                   {"DIA_EMERGVALVE", 0},
                                   {"bit104", 0},
                                   {"DIA_AIR_SUSP_PRESS_LOW", 0}, // byte13
                                   {"DIA_AIR_SUSP_PRESS_HIGH", 0},
                                   {"DIA_AIR_SUSP_PRESS_BURST", 0},
                                   {"DIA_AIR_SUSP_PRESS_ERROR", 0},
                                   {"DIA_MR_PRESS_LOW", 0},
                                   {"DIA_MR_PRESS_ERR", 0},
                                   {"DIA_R_PRESS_LOW", 0},
                                   {"DIA_R_PRESS_ERROR", 0},
                                   {"DIA_HBRELEASE_TRAINLINE_IMPL", 0}, // byte14
                                   {"DIA_TRACTION_TRAINLINE_IMPL", 0},
                                   {"DIA_EMERGENCY_TRAINLINE_IMPL", 0},
                                   {"DIA_BRAKE_BITS_IMPL", 0},
                                   {"DIA_BRAKE_NOT_RELEASED_Bo1", 0},
                                   {"DIA_BRAKE_NOT_RELEASED_Bo2", 0},
                                   {"DIA_BRAKE_NOT_APPLIED_Bo1", 0},
                                   {"DIA_BRAKE_NOT_APPLIED_Bo2", 0},
                                   {"DIA_PB_NOT_RELEASED", 0}, // byte15
                                   {"DIA_PB_HOSE_BURST", 0},
                                   {"DIA_PB_PG_IMPLAUSIBLE", 0},
                                   {"DIA_MVB_ERROR_BCU", 0},
                                   {"DIA_MVB_ERROR_TCU", 0},
                                   {"DIA_MVB_ERROR_VCU", 0},
                                   {"bit127", 0},
                                   {"bit128", 0}

    };

    /*m_tableWidget[ska_num][MVB2] = new QTableWidget();
    m_tableWidget[ska_num][MVB2]->setColumnCount(2);
    m_tableWidget[ska_num][MVB2]->setRowCount(m_inputs_map[ska_num][MVB2].size());
    m_tableWidget[ska_num][MVB2]->setHorizontalHeaderLabels(table_name[ska_num][MVB2]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[ska_num][MVB2]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[ska_num][MVB2]->setItem(row, 0, item_name);
        m_tableWidget[ska_num][MVB2]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[ska_num][MVB2]->resizeColumnsToContents();*/


    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[ska_num][MVB2].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[ska_num][MVB2] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[ska_num][MVB2]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[ska_num][MVB2]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[ska_num][MVB2]->setItem(row, column, item_name);
        m_tableWidget[ska_num][MVB2]->setItem(row, column + 1, item_val); // Değer

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[ska_num][MVB2]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][MVB2]->columnCount() ;

}
/*
void Ska_Bcu::init_oa_x_mvb3_table(SKA_VEHICLE_NUM vehicle_type)
{
    int ska_num = static_cast<int>(vehicle_type);
    m_inputs_map[ska_num][MVB3] = {
        {"DIA_BOARD_CB09_A2", 0},
        {"bit1", 0},
        {"DIA_CAN_COMM_MB04_04", 0},
        {"DIA_CAN_COMM_MB03_06", 0},
        {"DIA_CAN_COMM_MB03_07", 0},
        {"DIA_CAN_COMM_MB03_08", 0},
        {"DIA_BOARD_MB04_A4", 0},
        {"DIA_BOARDCODING_MB04_04", 0},
        {"DIA_EDACTUAL_AX3_FAILURE", 0},
        {"DIA_EDACTUAL_AX4_FAILURE", 0},
        {"bit10", 0},
        {"DIA_CAN_COMM_EB01_09", 0},
        {"DIA_CAN_COMM_EB02_10", 0},
        {"bit13", 0},
        {"bit14", 0},
        {"bit15", 0},
        {"DIA_BOARD_MB03_A6", 0},
        {"DIA_BOARDCODING_MB03_06", 0},
        {"bit18", 0},
        {"bit19", 0},
        {"bit20", 0},
        {"DIA_CAN_COMM_CB09_02", 0},
        {"DIA_BOARD_MB03_A7", 0},
        {"bit23", 0},
        {"DIA_BOARDCODING_MB03_07", 0},
        {"DIA_MVB_SBM_BCU", 0},
        {"DIA_MVB_GW_SBM", 0},
        {"bit27", 0},
        {"DIA_MVB_GW_TBM", 0},
        {"DIA_BOARD_MB03_A8", 0},
        {"DIA_BOARDCODING_MB03_08", 0},
        {"DIA_WSP_FSI_AXLE1", 0},
        {"DIA_WSP_FSI_AXLE2", 0},
        {"DIA_WSP_FSI_AXLE3", 0},
        {"DIA_WSP_FSI_AXLE4", 0},
        {"DIA_BOARD_EB01_09", 0},
        {"DIA_BOARDCODING_EB01_09", 0},
        {"DIA_BOARD_EB02_10", 0},
        {"DIA_BOARDCODING_EB02_10", 0},
        {"DIA_PSENSOR_C_TB", 0},
        {"DIA_PSENSOR_C_MB", 0},
        {"DIA_PSENSOR_PB_TB", 0},
        {"DIA_PSENSOR_MRP", 0},
        {"DIA_PSENSOR_CVD_TB", 0},
        {"DIA_PSENSOR_T_TB", 0},
        {"DIA_PSENSOR_R_TB", 0},
        {"DIA_PSENSOR_CVI_TB", 0},
        {"DIA_DCL_INCPRESS_TB", 0},
        {"DIA_DCL_DECPRESS_TB", 0},
        {"DIA_PSENSOR_CVD_MB", 0},
        {"DIA_PSENSOR_T_MB", 0},
        {"bit51", 0},
        {"DIA_PB_PG_IMPLAUSIBLE", 0},
        {"DIA_PB_HOSE_BURST_TB", 0},
        {"DIA_MR_PRESS_LOW", 0},
        {"DIA_MR_PRESS_ERR", 0},
        {"DIA_PSENSOR_R_MB", 0},
        {"DIA_PSENSOR_CVI_MB", 0},
        {"DIA_DCL_INCPRESS_MB", 0},
        {"DIA_DCL_DECPRESS_MB", 0},
        {"DIA_POP_BP_Test", 0},
        {"DIA_PSENSOR_C_TB_WSP", 0},
        {"DIA_PSENSOR_C_MB_WSP", 0},
        {"DIA_PSENSOR_BP", 0},
        {"DIA_PSENSOR_CV_SA", 0},
        {"DIA_DCL_INCPRESS_SA", 0},
        {"DIA_DCL_DECPRESS_SA", 0},
        {"DIA_POP_SANDING_S2", 0},
        {"DIA_POP_SANDING_S1", 0},
        {"DIA_REL_EBCUFCTOK", 0},
        {"DIA_REL_EBCU_EBLOOP_Y_OPEN", 0},
        {"DIA_REL_EBCU_BRAKE_TEST_OK", 0},
        {"DIA_REL_WSP_R_VLT5KMHDOOR", 0},
        {"DIA_REL_WSP_R_VGT5KMHDOOR", 0},
        {"DIA_REL_WSP_R_VGT10KMHDOOR", 0},
        {"DIA_WSP_TIMEOUT_AX1", 0},
        {"DIA_WSP_TIMEOUT_AX2", 0},
        {"DIA_UWR_TIMEOUT_TB", 0},
        {"DIA_POP_WSP_Y_HOLD_AX1", 0},
        {"DIA_POP_WSP_Y_RELEASE_AX1", 0},
        {"DIA_POP_WSP_Y_HOLD_AX2", 0},
        {"DIA_POP_WSP_Y_RELEASE_AX2", 0},
        {"DIA_WSP_FAILURE_TB", 0},
        {"DIA_SPEED_DV1", 0},
        {"DIA_SPEED_DV2", 0},
        {"DIA_WSP_TIMEOUT_AX3", 0},
        {"DIA_WSP_TIMEOUT_AX4", 0},
        {"DIA_UWR_TIMEOUT_MB", 0},
        {"DIA_POP_WSP_Y_HOLD_AX3", 0},
        {"DIA_POP_WSP_Y_RELEASE_AX3", 0},
        {"DIA_POP_WSP_Y_HOLD_AX4", 0},
        {"DIA_POP_WSP_Y_RELEASE_AX4", 0},
        {"DIA_WSP_FAILURE_MB", 0},
        {"DIA_SPEED_DV3", 0},
        {"DIA_SPEED_DV4", 0},
        {"DIA_ASSF", 0},
        {"DIA_WSP_TEST_ABORTED", 0},
        {"DIA_DCL_CONFIG_TB", 0},
        {"DIA_DCL_DEVIATION_TB", 0},
        {"DIA_DCL_OFFSET_TB", 0},
        {"DIA_DCL_CONFIG_MB", 0},
        {"DIA_DCL_DEVIATION_MB", 0},
        {"DIA_DCL_OFFSET_MB", 0},
        {"DIA_CAR_CONFIGURATION", 0},
        {"DIA_HBRELEASE_TRAINLINE_IM", 0},
        {"DIA_TRACTION_TRAINLINE_IMP", 0},
        {"DIA_EMERGENCY_TRAINLINE_IM", 0},
        {"DIA_BRAKE_BITS_IMPL", 0},
        {"DIA_AIR_SUSP_PRESS_LOW_TB", 0},
        {"DIA_AIR_SUSP_PRESS_INVALID", 0},
        {"DIA_AIR_SUSP_PRESS_ERROR_T", 0},
        {"DIA_R_PRESS_LOW_TB", 0},
        {"DIA_R_PRESS_ERROR_TB", 0},
        {"DIA_C_PRESS_HOSE_BREAK_TB", 0},
        {"DIA_DIRECTBRAKE_DIST_TB", 0},
        {"bit115", 0},
        {"DIA_BRAKE_NOT_RELEASED_TB", 0},
        {"DIA_BRAKE_NOT_APPLIED_TB", 0},
        {"DIA_INDIRECTBRAKE_NOT_APPL", 0},
        {"DIA_EMERGVALVE_TB", 0},
        {"DIA_PB_NOT_RELEASED_TB", 0},
        {"DIA_AIR_SUSP_PRESS_LOW_MB", 0},
        {"DIA_AIR_SUSP_PRESS_INVALID", 0},
        {"DIA_AIR_SUSP_PRESS_ERROR_M", 0},
        {"DIA_R_PRESS_LOW_MB", 0},
        {"DIA_R_PRESS_ERROR_MB", 0},
        {"DIA_C_PRESS_HOSE_BRAKE_MB", 0},
        {"DIA_DIRECTBRAKE_DIST_MB", 0},
        {"bit128", 0},
        {"DIA_BRAKE_NOT_RELEASED_MB", 0},
        {"DIA_BRAKE_NOT_APPLIED_MB", 0},
        {"DIA_INDIRECTBRAKE_NOT_APPL", 0},
        {"DIA_EMERGVALVE_MB", 0},
        {"DIA_SANDING_DISTURBED", 0},
        {"DIA_MVB_BCU_BCU", 0},
        {"DIA_MVB_TCU_BCU", 0},
        {"DIA_MVB_CCU_BCU", 0},
        {"DIA_DCL_DEVIATION_SA", 0},
        {"DIA_DCL_OFFSET_SA", 0},
        {"DIA_DCL_CONFIG_SA", 0},
        {"bit140", 0},
        {"bit141", 0},
        {"bit142", 0},
        {"bit143", 0},
        {"bit144", 0},
        {"bit145", 0},
        {"bit146", 0},
        {"bit147", 0},
        {"bit148", 0},
        {"bit149", 0},
        {"bit150", 0},
        {"bit151", 0},
        {"reserved21", 0},
        {"reserved22", 0},
        {"reserved23", 0},
        {"reserved24", 0},
        {"reserved25", 0},
        {"reserved26", 0},
        {"reserved27", 0},
        {"reserved28", 0},
        {"reserved29", 0},
        {"reserved30", 0},
        {"reserved31", 0}
    };

    m_tableWidget[ska_num][MVB3] = new QTableWidget();
    m_tableWidget[ska_num][MVB3]->setColumnCount(2);
    m_tableWidget[ska_num][MVB3]->setRowCount(m_inputs_map[ska_num][MVB3].size());
    m_tableWidget[ska_num][MVB3]->setHorizontalHeaderLabels(table_name[ska_num][MVB3]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[ska_num][MVB3]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[ska_num][MVB3]->setItem(row, 0, item_name);
        m_tableWidget[ska_num][MVB3]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[ska_num][MVB3]->resizeColumnsToContents();
}*/



