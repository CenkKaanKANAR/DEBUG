#include "oa_etcs.h"
#include "utils.h"

Oa_Etcs::Oa_Etcs(QObject *parent)
    : QObject{parent}
{

    memset(&m_oa_x_etcs, 0, sizeof(m_oa_x_etcs));
    // Init OA1 Table Contents
    init_etcs_ccu_mvb1_table(OA_VEHICLE_NUM::OA1);
    init_etcs_ccu_mvb2_table(OA_VEHICLE_NUM::OA1);
    init_etcs_ccu_mvb3_table(OA_VEHICLE_NUM::OA1);

    // Init OA2 Table Contents
    init_etcs_ccu_mvb1_table(OA_VEHICLE_NUM::OA2);
    init_etcs_ccu_mvb2_table(OA_VEHICLE_NUM::OA2);
    init_etcs_ccu_mvb3_table(OA_VEHICLE_NUM::OA2);

    make_signal_slot_connection();


}


Oa_Etcs::~Oa_Etcs()
{
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            delete m_tableWidget[i][j];
            m_tableWidget[i][j] = nullptr; // Güvenlik için nullptr atayın
        }
    }
}


void Oa_Etcs::make_signal_slot_connection()
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

void Oa_Etcs::set_data_struct(const QByteArray &input, const OA_VEHICLE_NUM &oa_x_num)
{

    //int oa_num = static_cast<int>(oa_x_num);
    qDebug() << "azdan az çoktan çok " ;
    qDebug() << "size of input " << input.size();
    qDebug() << "Gelen input verileri :  " << input;
    //qDebug() << "Gelen input veri tipi : " << typeof(input);


    int oa_num = static_cast<int>(oa_x_num);

        qDebug() << "SET DATA STRUCT SIZE of COLUMN COUNT ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;
    if (input.size() == sizeof(m_oa_x_etcs[oa_num])) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        //memcpy(&m_oa_x_etcs[oa_num], input.constData(), sizeof(m_oa_x_etcs[oa_num]));

        qDebug() << "SIZE of MVB1 :  " << sizeof(m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bytes);
        qDebug() << "SIZE of MVB2 :  " << sizeof(m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bytes);
        qDebug() << "SIZE of MVB3 :  " << sizeof(m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bytes);


        // İlk alanı kopyala
        memcpy(&m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bytes, input.constData(), sizeof(m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bytes));

        QByteArray data =  input.mid(0, 32);
        qDebug() << "32 Bytelık data :  " << data;
        update_mvb1_map(oa_x_num);
        //set_struct_mvb1(oa_x_num);
        update_table(oa_x_num,Oa_Etcs::MVB1);

        // İkinci alanı kopyala, input.constData() + sizeof(etcs_ccu_mvb1) kadar ilerleyerek
        memcpy(&m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bytes, input.constData() + sizeof(m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bytes) + 8, sizeof(m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bytes));
        update_mvb2_map(oa_x_num);
        //set_struct_mvb2(oa_x_num);
        update_table(oa_x_num,Oa_Etcs::MVB2);

        // Üçüncü alanı kopyala, input.constData() + sizeof(etcs_ccu_mvb1) + sizeof(etcs_ccu_mvb2) kadar ilerleyerek
        memcpy(&m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bytes, input.constData() + sizeof(m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bytes) + sizeof(m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bytes) + 16, sizeof(m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bytes));
        update_mvb3_map(oa_x_num);
        //set_struct_mvb3(oa_x_num);
        update_table(oa_x_num,Oa_Etcs::MVB3);

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

void Oa_Etcs::update_struct_with_map(OA_VEHICLE_NUM oa_x_num, OA_MVB_NUM mvb_num)
{
    int oa_num = static_cast<int>(oa_x_num);
    // Define a lambda function to reduce redundancy
    //qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;

    auto setInputMap = [&](const QString& signal_name) {
        //m_inputs_map[oa_num][mvb_num][signal_name] = utils::getTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], signal_name).toInt();
        m_inputs_map[oa_num][mvb_num][signal_name] = utils::getTableWidgetValueByNameWithoutColumn(m_tableWidget[oa_num][mvb_num], signal_name).toInt();
        //m_inputs_map[oa_num][mvb_num][signal_name] = utils::getTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], signal_name, 3).toInt();
        //m_inputs_map[oa_num][mvb_num][signal_name] = utils::getTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], signal_name, 5).toInt();
        //m_inputs_map[oa_num][mvb_num][signal_name] = utils::getTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], signal_name, 7).toInt();
    };

    // update map with given tableWidget values
    for(const auto& map : m_inputs_map[oa_num][mvb_num])
    {
        setInputMap(map.first);
    }

    // set struct parameters with given updated map parameters
    set_struct_mvb1(oa_x_num);
    set_struct_mvb2(oa_x_num);
    set_struct_mvb3(oa_x_num);
}

void Oa_Etcs::update_mvb1_map(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);
m_inputs_map[oa_num][MVB1].at("Lifesign")                   =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.Lifesign;
m_inputs_map[oa_num][MVB1].at("Valid")                   =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.Valid;
m_inputs_map[oa_num][MVB1].at("bit2")                      =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit2;
m_inputs_map[oa_num][MVB1].at("bit3")                      =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit3;
m_inputs_map[oa_num][MVB1].at("bit4")                      =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit4;
m_inputs_map[oa_num][MVB1].at("bit5")                      =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit5;
m_inputs_map[oa_num][MVB1].at("bit6")                      =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit6;
m_inputs_map[oa_num][MVB1].at("bit7")                      =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit7;
m_inputs_map[oa_num][MVB1].at("OBU_TR_ServiceBrake")       =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_ServiceBrake;
m_inputs_map[oa_num][MVB1].at("bit9")                      =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit9;
m_inputs_map[oa_num][MVB1].at("OBU_TR_TCO_Cmd")            =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_TCO_Cmd;
m_inputs_map[oa_num][MVB1].at("OBU_TR_RBInhibit_Cmd")      =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_RBInhibit_Cmd;
m_inputs_map[oa_num][MVB1].at("bit12")                     =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit12;
m_inputs_map[oa_num][MVB1].at("bit13")                     =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit13;
m_inputs_map[oa_num][MVB1].at("bit14")                     =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit14;
m_inputs_map[oa_num][MVB1].at("OBU_TR_AT_Cmd")             =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_AT_Cmd;
m_inputs_map[oa_num][MVB1].at("OBU_TR_MPS_Cmd")            =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_MPS_Cmd;
m_inputs_map[oa_num][MVB1].at("OBU_TR_PG_Cmd")             =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_PG_Cmd;
m_inputs_map[oa_num][MVB1].at("OBU_TR_V_Real_Flag")        =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_V_Real_Flag;
m_inputs_map[oa_num][MVB1].at("OBU_TR_EB_Active_Status")   =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_EB_Active_Status;
m_inputs_map[oa_num][MVB1].at("OBU_TR_EB_Test_Status")     =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_EB_Test_Status;
m_inputs_map[oa_num][MVB1].at("OBU_TR_ETCS_Isolated")      =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_ETCS_Isolated;
m_inputs_map[oa_num][MVB1].at("bit22")                     =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit22;
m_inputs_map[oa_num][MVB1].at("bit23")                     =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit23;
m_inputs_map[oa_num][MVB1].at("OBU_TR_CTS_D_Change")       =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_CTS_D_Change;
m_inputs_map[oa_num][MVB1].at("reserved7")                 =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.reserved7;
m_inputs_map[oa_num][MVB1].at("reserved8")                 =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.reserved8;
m_inputs_map[oa_num][MVB1].at("reserved9")                 =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.reserved9;
m_inputs_map[oa_num][MVB1].at("OBU_TR_ACC_D_Change")       =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_ACC_D_Change;
m_inputs_map[oa_num][MVB1].at("OBU_TR_ACC_Limit")          =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_ACC_Limit;
m_inputs_map[oa_num][MVB1].at("OBU_TR_Train_Speed")        =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_Train_Speed;
m_inputs_map[oa_num][MVB1].at("OBU_TR_EVC_M_LEVEL")        =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_EVC_M_LEVEL;
m_inputs_map[oa_num][MVB1].at("OBU_TR_EVC_M_MODE")         =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_EVC_M_MODE;
m_inputs_map[oa_num][MVB1].at("bit128")                    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit128;
m_inputs_map[oa_num][MVB1].at("bit129")                    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit129;
m_inputs_map[oa_num][MVB1].at("bit130")                    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit130;
m_inputs_map[oa_num][MVB1].at("bit131")                    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit131;
m_inputs_map[oa_num][MVB1].at("bit132")                    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit132;
m_inputs_map[oa_num][MVB1].at("bit133")                    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit133;
m_inputs_map[oa_num][MVB1].at("EB1_Test_Output")           =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.EB1_Test_Output;
m_inputs_map[oa_num][MVB1].at("EB2_Test_Output")           =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.EB2_Test_Output;
m_inputs_map[oa_num][MVB1].at("Train_Number[12]")          =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bytes[19];
m_inputs_map[oa_num][MVB1].at("reserved31")                =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.reserved31;

}

void Oa_Etcs::update_mvb2_map(OA_VEHICLE_NUM oa_x_num)
{
   int oa_num = static_cast<int>(oa_x_num);
m_inputs_map[oa_num][MVB2].at("Lifesign")                   =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.Lifesign;
m_inputs_map[oa_num][MVB2].at("Valid")                   =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.Valid;
m_inputs_map[oa_num][MVB2].at("bit2")                      =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit2;
m_inputs_map[oa_num][MVB2].at("bit3")                      =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit3;
m_inputs_map[oa_num][MVB2].at("bit4")                      =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit4;
m_inputs_map[oa_num][MVB2].at("bit5")                      =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit5;
m_inputs_map[oa_num][MVB2].at("bit6")                      =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit6;
m_inputs_map[oa_num][MVB2].at("bit7")                      =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit7;
m_inputs_map[oa_num][MVB2].at("Validity1")                 =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.Validity1;
m_inputs_map[oa_num][MVB2].at("Validity2")                 =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.Validity2;
m_inputs_map[oa_num][MVB2].at("Validity3")                 =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.Validity3;
m_inputs_map[oa_num][MVB2].at("Validity4")                 =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.Validity4;
m_inputs_map[oa_num][MVB2].at("Validity5")                 =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.Validity5;
m_inputs_map[oa_num][MVB2].at("bit13")                     =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit13;
m_inputs_map[oa_num][MVB2].at("bit14")                     =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit14;
m_inputs_map[oa_num][MVB2].at("bit15")                     =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit15;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Left1")           =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Left1;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Right1")          =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Right1;
m_inputs_map[oa_num][MVB2].at("bit18")                     =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit18;
m_inputs_map[oa_num][MVB2].at("bit19")                     =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit19;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height1_Bit0")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height1_Bit0;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height1_Bit1")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height1_Bit1;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height1_Bit2")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height1_Bit2;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height1_Bit3")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height1_Bit3;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Left2")           =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Left2;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Right2")          =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Right2;
m_inputs_map[oa_num][MVB2].at("bit26")                     =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit26;
m_inputs_map[oa_num][MVB2].at("bit27")                     =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit27;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height2_Bit0")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height2_Bit0;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height2_Bit1")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height2_Bit1;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height2_Bit2")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height2_Bit2;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height2_Bit3")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height2_Bit3;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Left3")           =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Left3;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Right3")          =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Right3;
m_inputs_map[oa_num][MVB2].at("bit34")                     =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit34;
m_inputs_map[oa_num][MVB2].at("bit35")                     =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit35;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height3_Bit0")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height3_Bit0;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height3_Bit1")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height3_Bit1;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height3_Bit2")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height3_Bit2;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height3_Bit3")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height3_Bit3;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Left4")           =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Left4;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Right4")          =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Right4;
m_inputs_map[oa_num][MVB2].at("bit42")                     =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit42;
m_inputs_map[oa_num][MVB2].at("bit43")                     =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit43;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height4_Bit0")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height4_Bit0;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height4_Bit1")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height4_Bit1;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height4_Bit2")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height4_Bit2;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height4_Bit3")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height4_Bit3;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Left5")           =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Left5;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Right5")          =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Right5;
m_inputs_map[oa_num][MVB2].at("bit50")                     =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit50;
m_inputs_map[oa_num][MVB2].at("bit51")                     =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit51;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height5_Bit0")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height5_Bit0;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height5_Bit1")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height5_Bit1;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height5_Bit2")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height5_Bit2;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height5_Bit3")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height5_Bit3;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_D_Entry1")        =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_D_Entry1;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_D_Exit1")         =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_D_Exit1;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_D_Entry2")        =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_D_Entry2;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_D_Exit2")         =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_D_Exit2;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_D_Entry3")        =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_D_Entry3;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_D_Exit3")         =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_D_Exit3;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_D_Entry4")        =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_D_Entry4;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_D_Exit4")         =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_D_Exit4;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_D_Entry5")        =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_D_Entry5;
m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_D_Exit5")         =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_D_Exit5;
m_inputs_map[oa_num][MVB2].at("reserved29")                =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.reserved29;
m_inputs_map[oa_num][MVB2].at("reserved30")                =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.reserved30;
m_inputs_map[oa_num][MVB2].at("reserved31")                =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.reserved31;

}

void Oa_Etcs::update_mvb3_map(OA_VEHICLE_NUM oa_x_num)
{
  int oa_num = static_cast<int>(oa_x_num);

m_inputs_map[oa_num][MVB3].at("Lifesign")           =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.Lifesign;
m_inputs_map[oa_num][MVB3].at("Valid")              =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.Valid;
m_inputs_map[oa_num][MVB3].at("bit2")              =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.bit2;
m_inputs_map[oa_num][MVB3].at("bit3")              =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.bit3;
m_inputs_map[oa_num][MVB3].at("bit4")              =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.bit4;
m_inputs_map[oa_num][MVB3].at("bit5")              =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.bit5;
m_inputs_map[oa_num][MVB3].at("bit6")              =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.bit6;
m_inputs_map[oa_num][MVB3].at("bit7")              =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.bit7;
m_inputs_map[oa_num][MVB3].at("OB_TR_TC_ID1")      =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OB_TR_TC_ID1;
m_inputs_map[oa_num][MVB3].at("OB_TR_TC_TYPE1")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OB_TR_TC_TYPE1;
m_inputs_map[oa_num][MVB3].at("OBU_TR_D_ENTRY1")   =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OBU_TR_D_ENTRY1;
m_inputs_map[oa_num][MVB3].at("OBU_TR_D_EXIT1")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OBU_TR_D_EXIT1;
m_inputs_map[oa_num][MVB3].at("OB_TR_TC_ID2")      =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OB_TR_TC_ID2;
m_inputs_map[oa_num][MVB3].at("OB_TR_TC_TYPE2")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OB_TR_TC_TYPE2;
m_inputs_map[oa_num][MVB3].at("OBU_TR_D_ENTRY2")   =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OBU_TR_D_ENTRY2;
m_inputs_map[oa_num][MVB3].at("OBU_TR_D_EXIT2")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OBU_TR_D_EXIT2;
m_inputs_map[oa_num][MVB3].at("OB_TR_TC_ID3")      =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OB_TR_TC_ID3;
m_inputs_map[oa_num][MVB3].at("OB_TR_TC_TYPE3")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OB_TR_TC_TYPE3;
m_inputs_map[oa_num][MVB3].at("OBU_TR_D_ENTRY3")   =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OBU_TR_D_ENTRY3;
m_inputs_map[oa_num][MVB3].at("OBU_TR_D_EXIT3")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OBU_TR_D_EXIT3;
m_inputs_map[oa_num][MVB3].at("OB_TR_TC_ID4")      =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OB_TR_TC_ID4;
m_inputs_map[oa_num][MVB3].at("OB_TR_TC_TYPE4")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OB_TR_TC_TYPE4;
m_inputs_map[oa_num][MVB3].at("OBU_TR_D_ENTRY4")   =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OBU_TR_D_ENTRY4;
m_inputs_map[oa_num][MVB3].at("OBU_TR_D_EXIT4")    =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OBU_TR_D_EXIT4;
m_inputs_map[oa_num][MVB3].at("reserved27")        =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.reserved27;
m_inputs_map[oa_num][MVB3].at("reserved28")        =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.reserved28;
m_inputs_map[oa_num][MVB3].at("reserved29")        =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.reserved29;
m_inputs_map[oa_num][MVB3].at("reserved30")        =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.reserved30;
m_inputs_map[oa_num][MVB3].at("reserved31")        =m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.reserved31;

}

void Oa_Etcs::update_table(OA_VEHICLE_NUM oa_x_num, OA_MVB_NUM mvb_num)
{
    int oa_num = static_cast<int>(oa_x_num);
    // İndeksleri kullanarak tabloyu güncelle
    qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;
    std::vector<int> valueColumns = {1, 3, 5, 7};
    for(const auto & map:m_inputs_map[oa_num][mvb_num]){


            utils::setTableWidgetValueByNameWithoutColumn(m_tableWidget[oa_num][mvb_num], map.first, map.second);
            //qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT INSIDE FOR LOOP ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;

            //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,3, map.second);
            //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,5, map.second);
            //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,7, map.second);
    }

}

void Oa_Etcs::set_struct_mvb1(OA_VEHICLE_NUM oa_x_num)
{
int oa_num = static_cast<int>(oa_x_num);
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.Lifesign               =m_inputs_map[oa_num][MVB1].at("Lifesign");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.Valid               =m_inputs_map[oa_num][MVB1].at("Valid");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit2                  =m_inputs_map[oa_num][MVB1].at("bit2");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit3                  =m_inputs_map[oa_num][MVB1].at("bit3");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit4                  =m_inputs_map[oa_num][MVB1].at("bit4");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit5                  =m_inputs_map[oa_num][MVB1].at("bit5");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit6                  =m_inputs_map[oa_num][MVB1].at("bit6");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit7                  =m_inputs_map[oa_num][MVB1].at("bit7");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_ServiceBrake   =m_inputs_map[oa_num][MVB1].at("OBU_TR_ServiceBrake");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit9                  =m_inputs_map[oa_num][MVB1].at("bit9");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_TCO_Cmd        =m_inputs_map[oa_num][MVB1].at("OBU_TR_TCO_Cmd");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_RBInhibit_Cmd  =m_inputs_map[oa_num][MVB1].at("OBU_TR_RBInhibit_Cmd");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit12                 =m_inputs_map[oa_num][MVB1].at("bit12");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit13                 =m_inputs_map[oa_num][MVB1].at("bit13");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit14                 =m_inputs_map[oa_num][MVB1].at("bit14");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_AT_Cmd         =m_inputs_map[oa_num][MVB1].at("OBU_TR_AT_Cmd");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_MPS_Cmd        =m_inputs_map[oa_num][MVB1].at("OBU_TR_MPS_Cmd");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_PG_Cmd         =m_inputs_map[oa_num][MVB1].at("OBU_TR_PG_Cmd");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_V_Real_Flag    =m_inputs_map[oa_num][MVB1].at("OBU_TR_V_Real_Flag");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_EB_Active_Status = m_inputs_map[oa_num][MVB1].at("OBU_TR_EB_Active_Status");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_EB_Test_Status =m_inputs_map[oa_num][MVB1].at("OBU_TR_EB_Test_Status");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_ETCS_Isolated  =m_inputs_map[oa_num][MVB1].at("OBU_TR_ETCS_Isolated");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit22                 =m_inputs_map[oa_num][MVB1].at("bit22");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit23                 =m_inputs_map[oa_num][MVB1].at("bit23");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_CTS_D_Change   =m_inputs_map[oa_num][MVB1].at("OBU_TR_CTS_D_Change");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.reserved7             =m_inputs_map[oa_num][MVB1].at("reserved7");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.reserved8             =m_inputs_map[oa_num][MVB1].at("reserved8");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.reserved9             =m_inputs_map[oa_num][MVB1].at("reserved9");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_ACC_D_Change   =m_inputs_map[oa_num][MVB1].at("OBU_TR_ACC_D_Change");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_ACC_Limit      =m_inputs_map[oa_num][MVB1].at("OBU_TR_ACC_Limit");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_Train_Speed    =m_inputs_map[oa_num][MVB1].at("OBU_TR_Train_Speed");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_EVC_M_LEVEL    =m_inputs_map[oa_num][MVB1].at("OBU_TR_EVC_M_LEVEL");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.OBU_TR_EVC_M_MODE     =m_inputs_map[oa_num][MVB1].at("OBU_TR_EVC_M_MODE");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit128                =m_inputs_map[oa_num][MVB1].at("bit128");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit129                =m_inputs_map[oa_num][MVB1].at("bit129");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit130                =m_inputs_map[oa_num][MVB1].at("bit130");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit131                =m_inputs_map[oa_num][MVB1].at("bit131");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit132                =m_inputs_map[oa_num][MVB1].at("bit132");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.bit133                =m_inputs_map[oa_num][MVB1].at("bit133");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.EB1_Test_Output       =m_inputs_map[oa_num][MVB1].at("EB1_Test_Output");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.EB2_Test_Output       =m_inputs_map[oa_num][MVB1].at("EB2_Test_Output");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bytes[19]                  =m_inputs_map[oa_num][MVB1].at("Train_Number[12]");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb1.bits.reserved31            =m_inputs_map[oa_num][MVB1].at("reserved31");
}

void Oa_Etcs::set_struct_mvb2(OA_VEHICLE_NUM oa_x_num)
{
int oa_num = static_cast<int>(oa_x_num);
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.Lifesign                  =m_inputs_map[oa_num][MVB2].at("Lifesign")                   ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.Valid                   =m_inputs_map[oa_num][MVB2].at("Valid")                   ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit2                      =m_inputs_map[oa_num][MVB2].at("bit2")                      ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit3                      =m_inputs_map[oa_num][MVB2].at("bit3")                      ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit4                      =m_inputs_map[oa_num][MVB2].at("bit4")                      ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit5                      =m_inputs_map[oa_num][MVB2].at("bit5")                      ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit6                      =m_inputs_map[oa_num][MVB2].at("bit6")                      ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit7                      =m_inputs_map[oa_num][MVB2].at("bit7")                      ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.Validity1                 =m_inputs_map[oa_num][MVB2].at("Validity1")                 ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.Validity2                 =m_inputs_map[oa_num][MVB2].at("Validity2")                 ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.Validity3                 =m_inputs_map[oa_num][MVB2].at("Validity3")                 ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.Validity4                 =m_inputs_map[oa_num][MVB2].at("Validity4")                 ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.Validity5                 =m_inputs_map[oa_num][MVB2].at("Validity5")                 ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit13                     =m_inputs_map[oa_num][MVB2].at("bit13")                     ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit14                     =m_inputs_map[oa_num][MVB2].at("bit14")                     ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit15                     =m_inputs_map[oa_num][MVB2].at("bit15")                     ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Left1           =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Left1")           ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Right1          =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Right1")          ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit18                     =m_inputs_map[oa_num][MVB2].at("bit18")                     ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit19                     =m_inputs_map[oa_num][MVB2].at("bit19")                     ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height1_Bit0    =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height1_Bit0")    ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height1_Bit1    =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height1_Bit1")    ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height1_Bit2    =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height1_Bit2")    ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height1_Bit3    =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height1_Bit3")    ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Left2           =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Left2")           ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Right2          =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Right2")          ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit26                     =m_inputs_map[oa_num][MVB2].at("bit26")                     ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit27                     =m_inputs_map[oa_num][MVB2].at("bit27")                     ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height2_Bit0    =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height2_Bit0")    ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height2_Bit1    =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height2_Bit1")    ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height2_Bit2    =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height2_Bit2")    ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height2_Bit3    =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height2_Bit3")    ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Left3           =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Left3")           ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Right3          =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Right3")          ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit34                     =m_inputs_map[oa_num][MVB2].at("bit34")                     ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit35                     =m_inputs_map[oa_num][MVB2].at("bit35")                     ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height3_Bit0    =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height3_Bit0")    ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height3_Bit1    =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height3_Bit1")    ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height3_Bit2    =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height3_Bit2")    ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height3_Bit3    =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height3_Bit3")    ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Left4           =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Left4")           ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Right4          =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Right4")          ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit42                     =m_inputs_map[oa_num][MVB2].at("bit42")                     ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit43                     =m_inputs_map[oa_num][MVB2].at("bit43")                     ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height4_Bit0    =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height4_Bit0")    ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height4_Bit1    =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height4_Bit1")    ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height4_Bit2    =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height4_Bit2")    ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height4_Bit3    =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height4_Bit3")    ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Left5           =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Left5")           ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Right5          =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Right5")          ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit50                     =m_inputs_map[oa_num][MVB2].at("bit50")                     ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.bit51                     =m_inputs_map[oa_num][MVB2].at("bit51")                     ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height5_Bit0    =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height5_Bit0")    ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height5_Bit1    =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height5_Bit1")    ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height5_Bit2    =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height5_Bit2")    ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_Height5_Bit3    =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_Height5_Bit3")    ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_D_Entry1        =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_D_Entry1")        ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_D_Exit1         =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_D_Exit1")         ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_D_Entry2        =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_D_Entry2")        ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_D_Exit2         =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_D_Exit2")         ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_D_Entry3        =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_D_Entry3")        ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_D_Exit3         =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_D_Exit3")         ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_D_Entry4        =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_D_Entry4")        ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_D_Exit4         =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_D_Exit4")         ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_D_Entry5        =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_D_Entry5")        ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.OBU_TR_SP_D_Exit5         =m_inputs_map[oa_num][MVB2].at("OBU_TR_SP_D_Exit5")         ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.reserved29                =m_inputs_map[oa_num][MVB2].at("reserved29")                ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.reserved30                =m_inputs_map[oa_num][MVB2].at("reserved30")                ;
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb2.bits.reserved31                =m_inputs_map[oa_num][MVB2].at("reserved31")                ;

}

void Oa_Etcs::set_struct_mvb3(OA_VEHICLE_NUM oa_x_num)
{
int oa_num = static_cast<int>(oa_x_num);

m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.Lifesign =m_inputs_map[oa_num][MVB3].at("Lifesign");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.Valid=m_inputs_map[oa_num][MVB3].at("Valid");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.bit2=m_inputs_map[oa_num][MVB3].at("bit2");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.bit3=m_inputs_map[oa_num][MVB3].at("bit3");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.bit4=m_inputs_map[oa_num][MVB3].at("bit4");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.bit5=m_inputs_map[oa_num][MVB3].at("bit5");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.bit6=m_inputs_map[oa_num][MVB3].at("bit6");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.bit7=m_inputs_map[oa_num][MVB3].at("bit7");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OB_TR_TC_ID1=m_inputs_map[oa_num][MVB3].at("OB_TR_TC_ID1");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OB_TR_TC_TYPE1=m_inputs_map[oa_num][MVB3].at("OB_TR_TC_TYPE1");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OBU_TR_D_ENTRY1=m_inputs_map[oa_num][MVB3].at("OBU_TR_D_ENTRY1");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OBU_TR_D_EXIT1=m_inputs_map[oa_num][MVB3].at("OBU_TR_D_EXIT1");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OB_TR_TC_ID2=m_inputs_map[oa_num][MVB3].at("OB_TR_TC_ID2");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OB_TR_TC_TYPE2=m_inputs_map[oa_num][MVB3].at("OB_TR_TC_TYPE2");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OBU_TR_D_ENTRY2=m_inputs_map[oa_num][MVB3].at("OBU_TR_D_ENTRY2");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OBU_TR_D_EXIT2=m_inputs_map[oa_num][MVB3].at("OBU_TR_D_EXIT2");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OB_TR_TC_ID3=m_inputs_map[oa_num][MVB3].at("OB_TR_TC_ID3");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OB_TR_TC_TYPE3=m_inputs_map[oa_num][MVB3].at("OB_TR_TC_TYPE3");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OBU_TR_D_ENTRY3=m_inputs_map[oa_num][MVB3].at("OBU_TR_D_ENTRY3");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OBU_TR_D_EXIT3=m_inputs_map[oa_num][MVB3].at("OBU_TR_D_EXIT3");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OB_TR_TC_ID4=m_inputs_map[oa_num][MVB3].at("OB_TR_TC_ID4");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OB_TR_TC_TYPE4=m_inputs_map[oa_num][MVB3].at("OB_TR_TC_TYPE4");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OBU_TR_D_ENTRY4=m_inputs_map[oa_num][MVB3].at("OBU_TR_D_ENTRY4");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.OBU_TR_D_EXIT4=m_inputs_map[oa_num][MVB3].at("OBU_TR_D_EXIT4");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.reserved27=m_inputs_map[oa_num][MVB3].at("reserved27");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.reserved28=m_inputs_map[oa_num][MVB3].at("reserved28");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.reserved29=m_inputs_map[oa_num][MVB3].at("reserved29");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.reserved30=m_inputs_map[oa_num][MVB3].at("reserved30");
m_oa_x_etcs[oa_num].oa_etcs_ccu_mvb3.bits.reserved31=m_inputs_map[oa_num][MVB3].at("reserved31");


}

void Oa_Etcs::init_etcs_ccu_mvb1_table(OA_VEHICLE_NUM vehicle_type)
{
    int oa_num = static_cast<int>(vehicle_type);
    m_inputs_map[oa_num][MVB1] = {
            {"Lifesign", 0},
            {"Valid", 0},
            {"bit2", 0},
            {"bit3", 0},
            {"bit4", 0},
            {"bit5", 0},
            {"bit6", 0},
            {"bit7", 0},
            {"OBU_TR_ServiceBrake", 0},
            {"bit9", 0},
            {"OBU_TR_TCO_Cmd", 0},
            {"OBU_TR_RBInhibit_Cmd", 0},
            {"bit12", 0},
            {"bit13", 0},
            {"bit14", 0},
            {"OBU_TR_AT_Cmd", 0},
            {"OBU_TR_MPS_Cmd", 0},
            {"OBU_TR_PG_Cmd", 0},
            {"OBU_TR_V_Real_Flag", 0},
            {"OBU_TR_EB_Active_Status", 0},
            {"OBU_TR_EB_Test_Status", 0},
            {"OBU_TR_ETCS_Isolated", 0},
            {"bit22", 0},
            {"bit23", 0},
            {"OBU_TR_CTS_D_Change", 0},
            {"reserved7", 0},
            {"reserved8", 0},
            {"reserved9", 0},
            {"OBU_TR_ACC_D_Change", 0},
            {"OBU_TR_ACC_Limit", 0},
            {"OBU_TR_Train_Speed", 0},
            {"OBU_TR_EVC_M_LEVEL", 0},
            {"OBU_TR_EVC_M_MODE", 0},
            {"bit128", 0},
            {"bit129", 0},
            {"bit130", 0},
            {"bit131", 0},
            {"bit132", 0},
            {"bit133", 0},
            {"EB1_Test_Output", 0},
            {"EB2_Test_Output", 0},
            {"Train_Number[12]", 0},
            {"reserved31", 0}
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
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;


}

void Oa_Etcs::init_etcs_ccu_mvb2_table(OA_VEHICLE_NUM vehicle_type)
{
    int oa_num = static_cast<int>(vehicle_type);
    m_inputs_map[oa_num][MVB2] = {
        {"Lifesign", 0},
        {"Valid", 0},
        {"bit2", 0},
        {"bit3", 0},
        {"bit4", 0},
        {"bit5", 0},
        {"bit6", 0},
        {"bit7", 0},
        {"Validity1", 0},
        {"Validity2", 0},
        {"Validity3", 0},
        {"Validity4", 0},
        {"Validity5", 0},
        {"bit13", 0},
        {"bit14", 0},
        {"bit15", 0},
        {"OBU_TR_SP_Left1", 0},
        {"OBU_TR_SP_Right1", 0},
        {"bit18", 0},
        {"bit19", 0},
        {"OBU_TR_SP_Height1_Bit0", 0},
        {"OBU_TR_SP_Height1_Bit1", 0},
        {"OBU_TR_SP_Height1_Bit2", 0},
        {"OBU_TR_SP_Height1_Bit3", 0},
        {"OBU_TR_SP_Left2", 0},
        {"OBU_TR_SP_Right2", 0},
        {"bit26", 0},
        {"bit27", 0},
        {"OBU_TR_SP_Height2_Bit0", 0},
        {"OBU_TR_SP_Height2_Bit1", 0},
        {"OBU_TR_SP_Height2_Bit2", 0},
        {"OBU_TR_SP_Height2_Bit3", 0},
        {"OBU_TR_SP_Left3", 0},
        {"OBU_TR_SP_Right3", 0},
        {"bit34", 0},
        {"bit35", 0},
        {"OBU_TR_SP_Height3_Bit0", 0},
        {"OBU_TR_SP_Height3_Bit1", 0},
        {"OBU_TR_SP_Height3_Bit2", 0},
        {"OBU_TR_SP_Height3_Bit3", 0},
        {"OBU_TR_SP_Left4", 0},
        {"OBU_TR_SP_Right4", 0},
        {"bit42", 0},
        {"bit43", 0},
        {"OBU_TR_SP_Height4_Bit0", 0},
        {"OBU_TR_SP_Height4_Bit1", 0},
        {"OBU_TR_SP_Height4_Bit2", 0},
        {"OBU_TR_SP_Height4_Bit3", 0},
        {"OBU_TR_SP_Left5", 0},
        {"OBU_TR_SP_Right5", 0},
        {"bit50", 0},
        {"bit51", 0},
        {"OBU_TR_SP_Height5_Bit0", 0},
        {"OBU_TR_SP_Height5_Bit1", 0},
        {"OBU_TR_SP_Height5_Bit2", 0},
        {"OBU_TR_SP_Height5_Bit3", 0},
        {"OBU_TR_SP_D_Entry1", 0},
        {"OBU_TR_SP_D_Exit1", 0},
        {"OBU_TR_SP_D_Entry2", 0},
        {"OBU_TR_SP_D_Exit2", 0},
        {"OBU_TR_SP_D_Entry3", 0},
        {"OBU_TR_SP_D_Exit3", 0},
        {"OBU_TR_SP_D_Entry4", 0},
        {"OBU_TR_SP_D_Exit4", 0},
        {"OBU_TR_SP_D_Entry5", 0},
        {"OBU_TR_SP_D_Exit5", 0},
        {"reserved29", 0},
        {"reserved30", 0},
        {"reserved31", 0}
    };
    /*
    m_tableWidget[oa_num][MVB2] = new QTableWidget();
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
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[oa_num][MVB2]->columnCount() ;




}

void Oa_Etcs::init_etcs_ccu_mvb3_table(OA_VEHICLE_NUM vehicle_type)
{
    int oa_num = static_cast<int>(vehicle_type);
    m_inputs_map[oa_num][MVB3] = {
        {"Lifesign", 0},
        {"Valid", 0},
        {"bit2", 0},
        {"bit3", 0},
        {"bit4", 0},
        {"bit5", 0},
        {"bit6", 0},
        {"bit7", 0},
        {"OB_TR_TC_ID1", 0},
        {"OB_TR_TC_TYPE1", 0},
        {"OBU_TR_D_ENTRY1", 0},
        {"OBU_TR_D_EXIT1", 0},
        {"OB_TR_TC_ID2", 0},
        {"OB_TR_TC_TYPE2", 0},
        {"OBU_TR_D_ENTRY2", 0},
        {"OBU_TR_D_EXIT2", 0},
        {"OB_TR_TC_ID3", 0},
        {"OB_TR_TC_TYPE3", 0},
        {"OBU_TR_D_ENTRY3", 0},
        {"OBU_TR_D_EXIT3", 0},
        {"OB_TR_TC_ID4", 0},
        {"OB_TR_TC_TYPE4", 0},
        {"OBU_TR_D_ENTRY4", 0},
        {"OBU_TR_D_EXIT4", 0},
        {"reserved27", 0},
        {"reserved28", 0},
        {"reserved29", 0},
        {"reserved30", 0},
        {"reserved31", 0}
    };
    /*
    m_tableWidget[oa_num][MVB3] = new QTableWidget();
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
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[oa_num][MVB3]->columnCount() ;





}


