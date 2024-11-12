#include "ska_hvac.h"

Ska_Hvac::Ska_Hvac(QObject *parent)
    : QObject{parent}
{

    memset(&m_ska_x_hvac, 0, sizeof(m_ska_x_hvac));

    init_ska_x_hvac1_table(SKA_VEHICLE_NUM::SKA1);
    init_ska_x_hvac2_table(SKA_VEHICLE_NUM::SKA1);
    init_ska_x_hvac3_table(SKA_VEHICLE_NUM::SKA1);


    init_ska_x_hvac1_table(SKA_VEHICLE_NUM::SKA2);
    init_ska_x_hvac2_table(SKA_VEHICLE_NUM::SKA2);
    init_ska_x_hvac3_table(SKA_VEHICLE_NUM::SKA2);


    make_signal_slot_connection();

}

Ska_Hvac::~Ska_Hvac()
{

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            delete m_tableWidget[i][j];
            m_tableWidget[i][j] = nullptr; // Güvenlik için nullptr atayın
        }
    }
}

void Ska_Hvac::make_signal_slot_connection()
{


    // SKA1 HVAC1 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][HVAC1], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1, HVAC1);
    });

    // SKA1 HVAC2 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][HVAC2], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1, HVAC2);
    });

    // SKA1 HVAC3 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][HVAC3], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1, HVAC3);
    });

    //////////////////////////////////// SKA2 //////////////////////////////////////////////
    // SKA2 HVAC1 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][HVAC1], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2, HVAC1);
    });

    // SKA2 HVAC2 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][HVAC2], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2, HVAC2);
    });

    // SKA2 HVAC3 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][HVAC3], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2, HVAC3);
    });


}


void Ska_Hvac::update_hvac1_map(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);

    m_inputs_map[ska_num][HVAC1].at("Software_Version_Major") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Software_Version_Major;
    m_inputs_map[ska_num][HVAC1].at("Software_Version_Minor") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Software_Version_Minor;
    m_inputs_map[ska_num][HVAC1].at("Outside_Air_Temp") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Outside_Air_Temp;
    m_inputs_map[ska_num][HVAC1].at("Ice_Temp") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Ice_Temp;
    m_inputs_map[ska_num][HVAC1].at("Supply_Air_Temp") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Supply_Air_Temp;
    m_inputs_map[ska_num][HVAC1].at("Inside_Air_Temp") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Inside_Air_Temp;
    m_inputs_map[ska_num][HVAC1].at("Set_Point_Temp") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Set_Point_Temp;
    m_inputs_map[ska_num][HVAC1].at("Evap_Fans_Speed") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Evap_Fans_Speed;
    m_inputs_map[ska_num][HVAC1].at("reserved_8") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved_8;
    m_inputs_map[ska_num][HVAC1].at("reserved_9") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved_9;
    m_inputs_map[ska_num][HVAC1].at("Smoke_Detector") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Smoke_Detector;
    m_inputs_map[ska_num][HVAC1].at("HVAC_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.HVAC_On;
    m_inputs_map[ska_num][HVAC1].at("Auto_Mode") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Auto_Mode;
    m_inputs_map[ska_num][HVAC1].at("Manual_Mode") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Manual_Mode;
    m_inputs_map[ska_num][HVAC1].at("Ventilation_Mode") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Ventilation_Mode;
    m_inputs_map[ska_num][HVAC1].at("Ventilation_Fan_Speed_Bit1") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Ventilation_Fan_Speed_Bit1;
    m_inputs_map[ska_num][HVAC1].at("Ventilation_Fan_Speed_Bit2") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Ventilation_Fan_Speed_Bit2;
    m_inputs_map[ska_num][HVAC1].at("Ventilation_Fan_Speed_Bit3") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Ventilation_Fan_Speed_Bit3;
    m_inputs_map[ska_num][HVAC1].at("Reduce_Mode") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Reduce_Mode;
    m_inputs_map[ska_num][HVAC1].at("Emergency_Mode") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Emergency_Mode;
    m_inputs_map[ska_num][HVAC1].at("Self_Test_Mode") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Self_Test_Mode;
    m_inputs_map[ska_num][HVAC1].at("Standby_Mode") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Standby_Mode;
    m_inputs_map[ska_num][HVAC1].at("Fire_Mode") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Fire_Mode;
    m_inputs_map[ska_num][HVAC1].at("Inside_Fire_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Inside_Fire_On;
    m_inputs_map[ska_num][HVAC1].at("bit94") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit94;
    m_inputs_map[ska_num][HVAC1].at("Full_Cooling") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Full_Cooling;
    m_inputs_map[ska_num][HVAC1].at("bit96") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit96;
    m_inputs_map[ska_num][HVAC1].at("Full_Heating") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Full_Heating;
    m_inputs_map[ska_num][HVAC1].at("Off_Enable") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Off_Enable;
    m_inputs_map[ska_num][HVAC1].at("Self_Test_Not_Ok") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Self_Test_Not_Ok;
    m_inputs_map[ska_num][HVAC1].at("Self_Test_Ok") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Self_Test_Ok;
    m_inputs_map[ska_num][HVAC1].at("PC_Software_Connected") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.PC_Software_Connected;
    m_inputs_map[ska_num][HVAC1].at("bit102") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit102;
    m_inputs_map[ska_num][HVAC1].at("bit103") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit103;
    m_inputs_map[ska_num][HVAC1].at("Heat1_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Heat1_On;
    m_inputs_map[ska_num][HVAC1].at("Heat2_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Heat2_On;
    m_inputs_map[ska_num][HVAC1].at("bit106") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit106;
    m_inputs_map[ska_num][HVAC1].at("bit107") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit107;
    m_inputs_map[ska_num][HVAC1].at("Compressor1_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Compressor1_On;
    m_inputs_map[ska_num][HVAC1].at("bit109") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit109;
    m_inputs_map[ska_num][HVAC1].at("Emerg_Inv_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Emerg_Inv_On;
    m_inputs_map[ska_num][HVAC1].at("Evap_Sel1_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Evap_Sel1_On;
    m_inputs_map[ska_num][HVAC1].at("reserved14") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved14;
    m_inputs_map[ska_num][HVAC1].at("reserved15") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved15;
    m_inputs_map[ska_num][HVAC1].at("Fresh_Air_Damp_Pos") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Fresh_Air_Damp_Pos;
    m_inputs_map[ska_num][HVAC1].at("Minor_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Minor_Fault;
    m_inputs_map[ska_num][HVAC1].at("Major_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Major_Fault;
    m_inputs_map[ska_num][HVAC1].at("Low_Press1_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Low_Press1_Fault;
    m_inputs_map[ska_num][HVAC1].at("bit139") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit139;
    m_inputs_map[ska_num][HVAC1].at("High_Press1_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.High_Press1_Fault;
    m_inputs_map[ska_num][HVAC1].at("bit141") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit141;
    m_inputs_map[ska_num][HVAC1].at("Cond_Fan1_Therm_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Cond_Fan1_Therm_Fault;
    m_inputs_map[ska_num][HVAC1].at("bit143") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit143;
    m_inputs_map[ska_num][HVAC1].at("First_Lev_Therm_75_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.First_Lev_Therm_75_Fault;
    m_inputs_map[ska_num][HVAC1].at("First_Lev_Therm_85_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.First_Lev_Therm_85_Fault;
    m_inputs_map[ska_num][HVAC1].at("Evap_Fan1_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Evap_Fan1_Fault;
    m_inputs_map[ska_num][HVAC1].at("bit147") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit147;
    m_inputs_map[ska_num][HVAC1].at("bit148") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit148;
    m_inputs_map[ska_num][HVAC1].at("Three_Phase_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Three_Phase_Fault;
    m_inputs_map[ska_num][HVAC1].at("Emerg_Inv_Input_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Emerg_Inv_Input_Fault;
    m_inputs_map[ska_num][HVAC1].at("Emerg_Inv_Output_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Emerg_Inv_Output_Fault;
    m_inputs_map[ska_num][HVAC1].at("Third_Level_Therm_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Third_Level_Therm_Fault;
    m_inputs_map[ska_num][HVAC1].at("Evap_Therm1_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Evap_Therm1_Fault;
    m_inputs_map[ska_num][HVAC1].at("bit154") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit154;
    m_inputs_map[ska_num][HVAC1].at("Smoke_Detector_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Smoke_Detector_Fault;
    m_inputs_map[ska_num][HVAC1].at("Comp1_Therm_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Comp1_Therm_Fault;
    m_inputs_map[ska_num][HVAC1].at("bit157") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit157;
    m_inputs_map[ska_num][HVAC1].at("bit158") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit158;
    m_inputs_map[ska_num][HVAC1].at("bit159") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit159;
    m_inputs_map[ska_num][HVAC1].at("bit160") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit160;
    m_inputs_map[ska_num][HVAC1].at("bit161") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit161;
    m_inputs_map[ska_num][HVAC1].at("Cont_Evap_Solenoid1_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Cont_Evap_Solenoid1_Fault;
    m_inputs_map[ska_num][HVAC1].at("bit163") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit163;
    m_inputs_map[ska_num][HVAC1].at("bit164") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit164;
    m_inputs_map[ska_num][HVAC1].at("bit165") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit165;
    m_inputs_map[ska_num][HVAC1].at("Cont_Bypass_Solenoid1_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Cont_Bypass_Solenoid1_Fault;
    m_inputs_map[ska_num][HVAC1].at("Cont_Heater1_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Cont_Heater1_Fault;
    m_inputs_map[ska_num][HVAC1].at("Cont_Heater2_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Cont_Heater2_Fault;
    m_inputs_map[ska_num][HVAC1].at("Cont_Evap_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Cont_Evap_Fault;
    m_inputs_map[ska_num][HVAC1].at("Cont_Cond_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Cont_Cond_Fault;
    m_inputs_map[ska_num][HVAC1].at("bit171") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit171;
    m_inputs_map[ska_num][HVAC1].at("bit172") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit172;
    m_inputs_map[ska_num][HVAC1].at("Cont_Emergency_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Cont_Emergency_Fault;
    m_inputs_map[ska_num][HVAC1].at("Comp1_Contc_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Comp1_Contc_Fault;
    m_inputs_map[ska_num][HVAC1].at("bit175") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit175;
    m_inputs_map[ska_num][HVAC1].at("Icing_Detect_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Icing_Detect_Fault;
    m_inputs_map[ska_num][HVAC1].at("Supply_Cooling_Detect_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Supply_Cooling_Detect_Fault;
    m_inputs_map[ska_num][HVAC1].at("Supply_Heating_Detect_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Supply_Heating_Detect_Fault;
    m_inputs_map[ska_num][HVAC1].at("Cooling_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Cooling_Fault;
    m_inputs_map[ska_num][HVAC1].at("Heating_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Heating_Fault;
    m_inputs_map[ska_num][HVAC1].at("bit181") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit181;
    m_inputs_map[ska_num][HVAC1].at("bit182") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit182;
    m_inputs_map[ska_num][HVAC1].at("bit183") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit183;
    m_inputs_map[ska_num][HVAC1].at("reserved23") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved23;
    m_inputs_map[ska_num][HVAC1].at("reserved24") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved24;
    m_inputs_map[ska_num][HVAC1].at("reserved25") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved25;
    m_inputs_map[ska_num][HVAC1].at("reserved26") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved26;
    m_inputs_map[ska_num][HVAC1].at("reserved27") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved27;
    m_inputs_map[ska_num][HVAC1].at("reserved28") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved28;
    m_inputs_map[ska_num][HVAC1].at("reserved29") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved29;
    m_inputs_map[ska_num][HVAC1].at("reserved30") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved30;
    m_inputs_map[ska_num][HVAC1].at("reserved31") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved31;




}

void Ska_Hvac::update_hvac2_map(SKA_VEHICLE_NUM ska_x_num){
    int ska_num = static_cast<int>(ska_x_num);
    m_inputs_map[ska_num][HVAC2].at("Software_Version_Major") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Software_Version_Major;
    m_inputs_map[ska_num][HVAC2].at("Software_Version_Minor") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Software_Version_Minor;
    m_inputs_map[ska_num][HVAC2].at("Outside_Air_Temp") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Outside_Air_Temp;
    m_inputs_map[ska_num][HVAC2].at("Ice_Temp") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Ice_Temp;
    m_inputs_map[ska_num][HVAC2].at("Supply_Air_Temp") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Supply_Air_Temp;
    m_inputs_map[ska_num][HVAC2].at("Inside_Air_Temp") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Inside_Air_Temp;
    m_inputs_map[ska_num][HVAC2].at("Set_Point_Temp") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Set_Point_Temp;
    m_inputs_map[ska_num][HVAC2].at("Evap_Fans_Speed") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Evap_Fans_Speed;
    m_inputs_map[ska_num][HVAC2].at("CO2_Sensor") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.CO2_Sensor;
    m_inputs_map[ska_num][HVAC2].at("Smoke_Detector") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Smoke_Detector;
    m_inputs_map[ska_num][HVAC2].at("HVAC_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.HVAC_On;
    m_inputs_map[ska_num][HVAC2].at("Auto_Mode") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Auto_Mode;
    m_inputs_map[ska_num][HVAC2].at("bit83") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit83;
    m_inputs_map[ska_num][HVAC2].at("bit84") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit84;
    m_inputs_map[ska_num][HVAC2].at("bit85") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit85;
    m_inputs_map[ska_num][HVAC2].at("bit86") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit86;
    m_inputs_map[ska_num][HVAC2].at("bit87") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit87;
    m_inputs_map[ska_num][HVAC2].at("Reduce_Mode") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Reduce_Mode;
    m_inputs_map[ska_num][HVAC2].at("Emergency_Mode") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Emergency_Mode;
    m_inputs_map[ska_num][HVAC2].at("Self_Test_Mode") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Self_Test_Mode;
    m_inputs_map[ska_num][HVAC2].at("bit91") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit91;
    m_inputs_map[ska_num][HVAC2].at("Fire_Mode") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Fire_Mode;
    m_inputs_map[ska_num][HVAC2].at("Inside_Fire_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Inside_Fire_On;
    m_inputs_map[ska_num][HVAC2].at("Half_Cooling") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Half_Cooling;
    m_inputs_map[ska_num][HVAC2].at("Full_Cooling") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Full_Cooling;
    m_inputs_map[ska_num][HVAC2].at("Half_Heating") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Half_Heating;
    m_inputs_map[ska_num][HVAC2].at("Full_Heating") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Full_Heating;
    m_inputs_map[ska_num][HVAC2].at("Off_Enable") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Off_Enable;
    m_inputs_map[ska_num][HVAC2].at("Self_Test_Not_Ok") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Self_Test_Not_Ok;
    m_inputs_map[ska_num][HVAC2].at("Self_Test_Ok") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Self_Test_Ok;
    m_inputs_map[ska_num][HVAC2].at("PC_Software_Connected") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.PC_Software_Connected;
    m_inputs_map[ska_num][HVAC2].at("Cond_Fans_Low") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cond_Fans_Low;
    m_inputs_map[ska_num][HVAC2].at("Cond_Fans_High") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cond_Fans_High;
    m_inputs_map[ska_num][HVAC2].at("Heat1_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Heat1_On;
    m_inputs_map[ska_num][HVAC2].at("Heat2_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Heat2_On;
    m_inputs_map[ska_num][HVAC2].at("Floor_Heat1_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Floor_Heat1_On;
    m_inputs_map[ska_num][HVAC2].at("Floor_Heat2_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Floor_Heat2_On;
    m_inputs_map[ska_num][HVAC2].at("Compressor1_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Compressor1_On;
    m_inputs_map[ska_num][HVAC2].at("Compressor2_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Compressor2_On;
    m_inputs_map[ska_num][HVAC2].at("Emerg_Inv_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Emerg_Inv_On;
    m_inputs_map[ska_num][HVAC2].at("Evap_Sel1_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Evap_Sel1_On;
    m_inputs_map[ska_num][HVAC2].at("Evap_Sel2_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Evap_Sel2_On;
    m_inputs_map[ska_num][HVAC2].at("bit113") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit113;
    m_inputs_map[ska_num][HVAC2].at("bit114") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit114;
    m_inputs_map[ska_num][HVAC2].at("bit115") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit115;
    m_inputs_map[ska_num][HVAC2].at("bit116") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit116;
    m_inputs_map[ska_num][HVAC2].at("bit117") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit117;
    m_inputs_map[ska_num][HVAC2].at("bit118") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit118;
    m_inputs_map[ska_num][HVAC2].at("bit119") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit119;
    m_inputs_map[ska_num][HVAC2].at("Emerg_Shut_Air_Damp_Pos") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Emerg_Shut_Air_Damp_Pos;
    m_inputs_map[ska_num][HVAC2].at("Fresh_Air_Damp_Pos") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Fresh_Air_Damp_Pos;
    m_inputs_map[ska_num][HVAC2].at("Minor_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Minor_Fault;
    m_inputs_map[ska_num][HVAC2].at("Major_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Major_Fault;
    m_inputs_map[ska_num][HVAC2].at("Low_Press1_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Low_Press1_Fault;
    m_inputs_map[ska_num][HVAC2].at("Low_Press2_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Low_Press2_Fault;
    m_inputs_map[ska_num][HVAC2].at("High_Press1_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.High_Press1_Fault;
    m_inputs_map[ska_num][HVAC2].at("High_Press2_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.High_Press2_Fault;
    m_inputs_map[ska_num][HVAC2].at("Cond_Fan1_Therm_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cond_Fan1_Therm_Fault;
    m_inputs_map[ska_num][HVAC2].at("First_Lev_Therm_7585_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.First_Lev_Therm_7585_Fault;
    m_inputs_map[ska_num][HVAC2].at("bit144") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit144;
    m_inputs_map[ska_num][HVAC2].at("bit145") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit145;
    m_inputs_map[ska_num][HVAC2].at("Evap_Fan1_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Evap_Fan1_Fault;
    m_inputs_map[ska_num][HVAC2].at("Evap_Fan2_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Evap_Fan2_Fault;
    m_inputs_map[ska_num][HVAC2].at("Evap_Fan12_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Evap_Fan12_Fault;
    m_inputs_map[ska_num][HVAC2].at("Three_Phase_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Three_Phase_Fault;
    m_inputs_map[ska_num][HVAC2].at("Emerg_Inv_Input_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Emerg_Inv_Input_Fault;
    m_inputs_map[ska_num][HVAC2].at("Emerg_Inv_Output_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Emerg_Inv_Output_Fault;
    m_inputs_map[ska_num][HVAC2].at("Third_Level_Therm_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Third_Level_Therm_Fault;
    m_inputs_map[ska_num][HVAC2].at("Evap_Therm1_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Evap_Therm1_Fault;
    m_inputs_map[ska_num][HVAC2].at("Evap_Therm2_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Evap_Therm2_Fault;
    m_inputs_map[ska_num][HVAC2].at("Smoke_Detector_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Smoke_Detector_Fault;
    m_inputs_map[ska_num][HVAC2].at("Comp1_Therm_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Comp1_Therm_Fault;
    m_inputs_map[ska_num][HVAC2].at("Comp1_Overload_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Comp1_Overload_Fault;
    m_inputs_map[ska_num][HVAC2].at("Comp2_Therm_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Comp2_Therm_Fault;
    m_inputs_map[ska_num][HVAC2].at("Comp2_Overload_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Comp2_Overload_Fault;
    m_inputs_map[ska_num][HVAC2].at("Evap_Inv_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Evap_Inv_Fault;
    m_inputs_map[ska_num][HVAC2].at("Cond_Fan2_Therm_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cond_Fan2_Therm_Fault;
    m_inputs_map[ska_num][HVAC2].at("Cont_Evap_Solenoid1_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Evap_Solenoid1_Fault;
    m_inputs_map[ska_num][HVAC2].at("Cont_Evap_Solenoid2_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Evap_Solenoid2_Fault;
    m_inputs_map[ska_num][HVAC2].at("Cont_Cap_Solenoid1_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Cap_Solenoid1_Fault;
    m_inputs_map[ska_num][HVAC2].at("Cont_Cap_Solenoid2_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Cap_Solenoid2_Fault;
    m_inputs_map[ska_num][HVAC2].at("Cont_Heater1_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Heater1_Fault;
    m_inputs_map[ska_num][HVAC2].at("Cont_Heater2_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Heater2_Fault;
    m_inputs_map[ska_num][HVAC2].at("Cont_Evap_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Evap_Fault;
    m_inputs_map[ska_num][HVAC2].at("Cont_Cond_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Cond_Fault;
    m_inputs_map[ska_num][HVAC2].at("Cont_Cond_Fan_Low_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Cond_Fan_Low_Fault;
    m_inputs_map[ska_num][HVAC2].at("Cont_Cond_Fan_High_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Cond_Fan_High_Fault;
    m_inputs_map[ska_num][HVAC2].at("Cont_Emergency_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Emergency_Fault;
    m_inputs_map[ska_num][HVAC2].at("Comp1_Contc_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Comp1_Contc_Fault;
    m_inputs_map[ska_num][HVAC2].at("Comp2_Contc_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Comp2_Contc_Fault;
    m_inputs_map[ska_num][HVAC2].at("Icing_Detect_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Icing_Detect_Fault;
    m_inputs_map[ska_num][HVAC2].at("Supply_Cooling_Detect_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Supply_Cooling_Detect_Fault;
    m_inputs_map[ska_num][HVAC2].at("Supply_Heating_Detect_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Supply_Heating_Detect_Fault;
    m_inputs_map[ska_num][HVAC2].at("Cooling_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cooling_Fault;
    m_inputs_map[ska_num][HVAC2].at("Heating_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Heating_Fault;
    m_inputs_map[ska_num][HVAC2].at("bit180") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit180;
    m_inputs_map[ska_num][HVAC2].at("bit181") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit181;
    m_inputs_map[ska_num][HVAC2].at("bit182") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit182;
    m_inputs_map[ska_num][HVAC2].at("reserved23") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.reserved23;
    m_inputs_map[ska_num][HVAC2].at("reserved24") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.reserved24;
    m_inputs_map[ska_num][HVAC2].at("reserved25") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.reserved25;
    m_inputs_map[ska_num][HVAC2].at("reserved26") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.reserved26;
    m_inputs_map[ska_num][HVAC2].at("reserved27") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.reserved27;
    m_inputs_map[ska_num][HVAC2].at("reserved28") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.reserved28;
    m_inputs_map[ska_num][HVAC2].at("reserved29") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.reserved29;
    m_inputs_map[ska_num][HVAC2].at("reserved30") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.reserved30;
    m_inputs_map[ska_num][HVAC2].at("reserved31") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.reserved31;

}

void Ska_Hvac::update_hvac3_map(SKA_VEHICLE_NUM ska_x_num){
    int ska_num = static_cast<int>(ska_x_num);
    m_inputs_map[ska_num][HVAC3].at("Software_Version_Major") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Software_Version_Major;
    m_inputs_map[ska_num][HVAC3].at("Software_Version_Minor") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Software_Version_Minor;
    m_inputs_map[ska_num][HVAC3].at("Outside_Air_Temp") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Outside_Air_Temp;
    m_inputs_map[ska_num][HVAC3].at("Ice_Temp") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Ice_Temp;
    m_inputs_map[ska_num][HVAC3].at("Supply_Air_Temp") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Supply_Air_Temp;
    m_inputs_map[ska_num][HVAC3].at("Inside_Air_Temp") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Inside_Air_Temp;
    m_inputs_map[ska_num][HVAC3].at("Set_Point_Temp") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Set_Point_Temp;
    m_inputs_map[ska_num][HVAC3].at("Evap_Fans_Speed") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Evap_Fans_Speed;
    m_inputs_map[ska_num][HVAC3].at("CO2_Sensor") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.CO2_Sensor;
    m_inputs_map[ska_num][HVAC3].at("Smoke_Detector") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Smoke_Detector;
    m_inputs_map[ska_num][HVAC3].at("HVAC_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.HVAC_On;
    m_inputs_map[ska_num][HVAC3].at("Auto_Mode") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Auto_Mode;
    m_inputs_map[ska_num][HVAC3].at("bit83") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit83;
    m_inputs_map[ska_num][HVAC3].at("bit84") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit84;
    m_inputs_map[ska_num][HVAC3].at("bit85") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit85;
    m_inputs_map[ska_num][HVAC3].at("bit86") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit86;
    m_inputs_map[ska_num][HVAC3].at("bit87") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit87;
    m_inputs_map[ska_num][HVAC3].at("Reduce_Mode") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Reduce_Mode;
    m_inputs_map[ska_num][HVAC3].at("Emergency_Mode") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Emergency_Mode;
    m_inputs_map[ska_num][HVAC3].at("Self_Test_Mode") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Self_Test_Mode;
    m_inputs_map[ska_num][HVAC3].at("Spare") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Spare;
    m_inputs_map[ska_num][HVAC3].at("Fire_Mode") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Fire_Mode;
    m_inputs_map[ska_num][HVAC3].at("Inside_Fire_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Inside_Fire_On;
    m_inputs_map[ska_num][HVAC3].at("Half_Cooling") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Half_Cooling;
    m_inputs_map[ska_num][HVAC3].at("Full_Cooling") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Full_Cooling;
    m_inputs_map[ska_num][HVAC3].at("Half_Heating") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Half_Heating;
    m_inputs_map[ska_num][HVAC3].at("Full_Heating") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Full_Heating;
    m_inputs_map[ska_num][HVAC3].at("Off_Enable") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Off_Enable;
    m_inputs_map[ska_num][HVAC3].at("Self_Test_Not_Ok") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Self_Test_Not_Ok;
    m_inputs_map[ska_num][HVAC3].at("Self_Test_Ok") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Self_Test_Ok;
    m_inputs_map[ska_num][HVAC3].at("PC_Software_Connected") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.PC_Software_Connected;
    m_inputs_map[ska_num][HVAC3].at("Cond_Fans_Low") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cond_Fans_Low;
    m_inputs_map[ska_num][HVAC3].at("Cond_Fans_High") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cond_Fans_High;
    m_inputs_map[ska_num][HVAC3].at("Heat1_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Heat1_On;
    m_inputs_map[ska_num][HVAC3].at("Heat2_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Heat2_On;
    m_inputs_map[ska_num][HVAC3].at("Floor_Heat1_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Floor_Heat1_On;
    m_inputs_map[ska_num][HVAC3].at("Floor_Heat2_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Floor_Heat2_On;
    m_inputs_map[ska_num][HVAC3].at("Compressor1_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Compressor1_On;
    m_inputs_map[ska_num][HVAC3].at("Compressor2_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Compressor2_On;
    m_inputs_map[ska_num][HVAC3].at("Emerg_Inv_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Emerg_Inv_On;
    m_inputs_map[ska_num][HVAC3].at("Evap_Sel1_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Evap_Sel1_On;
    m_inputs_map[ska_num][HVAC3].at("Evap_Sel2_On") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Evap_Sel2_On;
    m_inputs_map[ska_num][HVAC3].at("bit97") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit97;
    m_inputs_map[ska_num][HVAC3].at("bit98") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit98;
    m_inputs_map[ska_num][HVAC3].at("bit99") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit99;
    m_inputs_map[ska_num][HVAC3].at("bit100") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit100;
    m_inputs_map[ska_num][HVAC3].at("bit101") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit101;
    m_inputs_map[ska_num][HVAC3].at("bit102") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit102;
    m_inputs_map[ska_num][HVAC3].at("bit103") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit103;
    m_inputs_map[ska_num][HVAC3].at("Emerg_Shut_Air_Damp_Pos") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Emerg_Shut_Air_Damp_Pos;
    m_inputs_map[ska_num][HVAC3].at("Fresh_Air_Damp_Pos") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Fresh_Air_Damp_Pos;
    m_inputs_map[ska_num][HVAC3].at("Minor_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Minor_Fault;
    m_inputs_map[ska_num][HVAC3].at("Major_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Major_Fault;
    m_inputs_map[ska_num][HVAC3].at("Low_Press1_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Low_Press1_Fault;
    m_inputs_map[ska_num][HVAC3].at("Low_Press2_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Low_Press2_Fault;
    m_inputs_map[ska_num][HVAC3].at("High_Press1_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.High_Press1_Fault;
    m_inputs_map[ska_num][HVAC3].at("High_Press2_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.High_Press2_Fault;
    m_inputs_map[ska_num][HVAC3].at("Cond_Fan1_Therm_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cond_Fan1_Therm_Fault;
    m_inputs_map[ska_num][HVAC3].at("First_Lev_Therm_7585_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.First_Lev_Therm_7585_Fault;
    m_inputs_map[ska_num][HVAC3].at("bit144") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit144;
    m_inputs_map[ska_num][HVAC3].at("bit145") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit145;
    m_inputs_map[ska_num][HVAC3].at("Evap_Fan1_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Evap_Fan1_Fault;
    m_inputs_map[ska_num][HVAC3].at("Evap_Fan2_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Evap_Fan2_Fault;
    m_inputs_map[ska_num][HVAC3].at("Evap_Fan12_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Evap_Fan12_Fault;
    m_inputs_map[ska_num][HVAC3].at("Three_Phase_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Three_Phase_Fault;
    m_inputs_map[ska_num][HVAC3].at("Emerg_Inv_Input_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Emerg_Inv_Input_Fault;
    m_inputs_map[ska_num][HVAC3].at("Emerg_Inv_Output_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Emerg_Inv_Output_Fault;
    m_inputs_map[ska_num][HVAC3].at("Third_Level_Therm_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Third_Level_Therm_Fault;
    m_inputs_map[ska_num][HVAC3].at("Evap_Therm1_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Evap_Therm1_Fault;
    m_inputs_map[ska_num][HVAC3].at("Evap_Therm2_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Evap_Therm2_Fault;
    m_inputs_map[ska_num][HVAC3].at("Smoke_Detector_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Smoke_Detector_Fault;
    m_inputs_map[ska_num][HVAC3].at("Comp1_Therm_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Comp1_Therm_Fault;
    m_inputs_map[ska_num][HVAC3].at("Comp1_Overload_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Comp1_Overload_Fault;
    m_inputs_map[ska_num][HVAC3].at("Comp2_Therm_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Comp2_Therm_Fault;
    m_inputs_map[ska_num][HVAC3].at("Comp2_Overload_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Comp2_Overload_Fault;
    m_inputs_map[ska_num][HVAC3].at("Evap_Inv_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Evap_Inv_Fault;
    m_inputs_map[ska_num][HVAC3].at("Cond_Fan2_Therm_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cond_Fan2_Therm_Fault;
    m_inputs_map[ska_num][HVAC3].at("Cont_Evap_Solenoid1_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Evap_Solenoid1_Fault;
    m_inputs_map[ska_num][HVAC3].at("Cont_Evap_Solenoid2_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Evap_Solenoid2_Fault;
    m_inputs_map[ska_num][HVAC3].at("Cont_Cap_Solenoid1_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Cap_Solenoid1_Fault;
    m_inputs_map[ska_num][HVAC3].at("Cont_Cap_Solenoid2_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Cap_Solenoid2_Fault;
    m_inputs_map[ska_num][HVAC3].at("Cont_Heater1_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Heater1_Fault;
    m_inputs_map[ska_num][HVAC3].at("Cont_Heater2_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Heater2_Fault;
    m_inputs_map[ska_num][HVAC3].at("Cont_Evap_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Evap_Fault;
    m_inputs_map[ska_num][HVAC3].at("Cont_Cond_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Cond_Fault;
    m_inputs_map[ska_num][HVAC3].at("Cont_Cond_Fan_Low_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Cond_Fan_Low_Fault;
    m_inputs_map[ska_num][HVAC3].at("Cont_Cond_Fan_High_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Cond_Fan_High_Fault;
    m_inputs_map[ska_num][HVAC3].at("Cont_Emergency_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Emergency_Fault;
    m_inputs_map[ska_num][HVAC3].at("Comp1_Contc_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Comp1_Contc_Fault;
    m_inputs_map[ska_num][HVAC3].at("Comp2_Contc_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Comp2_Contc_Fault;
    m_inputs_map[ska_num][HVAC3].at("Icing_Detect_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Icing_Detect_Fault;
    m_inputs_map[ska_num][HVAC3].at("Supply_Cooling_Detect_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Supply_Cooling_Detect_Fault;
    m_inputs_map[ska_num][HVAC3].at("Supply_Heating_Detect_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Supply_Heating_Detect_Fault;
    m_inputs_map[ska_num][HVAC3].at("Cooling_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cooling_Fault;
    m_inputs_map[ska_num][HVAC3].at("Heating_Fault") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Heating_Fault;
    m_inputs_map[ska_num][HVAC3].at("bit181") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit181;
    m_inputs_map[ska_num][HVAC3].at("bit182") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit182;
    m_inputs_map[ska_num][HVAC3].at("bit183") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit183;
    m_inputs_map[ska_num][HVAC3].at("reserved23") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.reserved23;
    m_inputs_map[ska_num][HVAC3].at("reserved24") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.reserved24;
    m_inputs_map[ska_num][HVAC3].at("reserved25") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.reserved25;
    m_inputs_map[ska_num][HVAC3].at("reserved26") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.reserved26;
    m_inputs_map[ska_num][HVAC3].at("reserved27") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.reserved27;
    m_inputs_map[ska_num][HVAC3].at("reserved28") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.reserved28;
    m_inputs_map[ska_num][HVAC3].at("reserved29") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.reserved29;
    m_inputs_map[ska_num][HVAC3].at("reserved30") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.reserved30;
    m_inputs_map[ska_num][HVAC3].at("reserved31") = m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.reserved31;

}

void Ska_Hvac::set_data_struct(const QByteArray &input, const SKA_VEHICLE_NUM &ska_x_num)
{
    //int oa_num = static_cast<int>(oa_x_num);
    qDebug() << "azdan az çoktan çok " ;
    qDebug() << "size of input " << input.size();
    qDebug() << "Gelen input verileri :  " << input;
    //qDebug() << "Gelen input veri tipi : " << typeof(input);


    int ska_num = static_cast<int>(ska_x_num);

    qDebug() << "SET DATA STRUCT SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][HVAC1]->columnCount() ;
    if (input.size() == sizeof(m_ska_x_hvac[ska_num])) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        //memcpy(&m_oa_x_etcs[oa_num], input.constData(), sizeof(m_oa_x_etcs[oa_num]));

        qDebug() << "SIZE of HVAC1 :  " << sizeof(m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bytes);
        qDebug() << "SIZE of HVAC2 :  " << sizeof(m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bytes);
        qDebug() << "SIZE of HVAC3 :  " << sizeof(m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bytes);


        // İlk alanı kopyala
        memcpy(&m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bytes, input.constData(), sizeof(m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bytes));

        QByteArray data =  input.mid(0, 32);
        qDebug() << "32 Bytelık data :  " << data;
        update_hvac1_map(ska_x_num);
        //set_struct_mvb1(oa_x_num);
        update_table(ska_x_num,Ska_Hvac::HVAC1);

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

void Ska_Hvac::update_table(SKA_VEHICLE_NUM ska_x_num, HVAC_NUM hvac_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    // İndeksleri kullanarak tabloyu güncelle
    qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][HVAC1]->columnCount() ;
    std::vector<int> valueColumns = {1, 3, 5, 7};
    for(const auto & map:m_inputs_map[ska_num][hvac_num]){


        utils::setTableWidgetValueByNameWithoutColumn(m_tableWidget[ska_num][hvac_num], map.first, map.second);
        //qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT INSIDE FOR LOOP ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;

        //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,3, map.second);
        //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,5, map.second);
        //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,7, map.second);
    }
}

void Ska_Hvac::set_struct_hvac1(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Software_Version_Major = m_inputs_map[ska_num][HVAC1].at("Software_Version_Major");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Software_Version_Minor = m_inputs_map[ska_num][HVAC1].at("Software_Version_Minor");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Outside_Air_Temp = m_inputs_map[ska_num][HVAC1].at("Outside_Air_Temp");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Ice_Temp = m_inputs_map[ska_num][HVAC1].at("Ice_Temp");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Supply_Air_Temp = m_inputs_map[ska_num][HVAC1].at("Supply_Air_Temp");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Inside_Air_Temp = m_inputs_map[ska_num][HVAC1].at("Inside_Air_Temp");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Set_Point_Temp = m_inputs_map[ska_num][HVAC1].at("Set_Point_Temp");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Evap_Fans_Speed = m_inputs_map[ska_num][HVAC1].at("Evap_Fans_Speed");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved_8 = m_inputs_map[ska_num][HVAC1].at("reserved_8");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved_9 = m_inputs_map[ska_num][HVAC1].at("reserved_9");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Smoke_Detector = m_inputs_map[ska_num][HVAC1].at("Smoke_Detector");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.HVAC_On = m_inputs_map[ska_num][HVAC1].at("HVAC_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Auto_Mode = m_inputs_map[ska_num][HVAC1].at("Auto_Mode");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Manual_Mode = m_inputs_map[ska_num][HVAC1].at("Manual_Mode");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Ventilation_Mode = m_inputs_map[ska_num][HVAC1].at("Ventilation_Mode");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Ventilation_Fan_Speed_Bit1 = m_inputs_map[ska_num][HVAC1].at("Ventilation_Fan_Speed_Bit1");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Ventilation_Fan_Speed_Bit2 = m_inputs_map[ska_num][HVAC1].at("Ventilation_Fan_Speed_Bit2");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Ventilation_Fan_Speed_Bit3 = m_inputs_map[ska_num][HVAC1].at("Ventilation_Fan_Speed_Bit3");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Reduce_Mode = m_inputs_map[ska_num][HVAC1].at("Reduce_Mode");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Emergency_Mode = m_inputs_map[ska_num][HVAC1].at("Emergency_Mode");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Self_Test_Mode = m_inputs_map[ska_num][HVAC1].at("Self_Test_Mode");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Standby_Mode = m_inputs_map[ska_num][HVAC1].at("Standby_Mode");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Fire_Mode = m_inputs_map[ska_num][HVAC1].at("Fire_Mode");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Inside_Fire_On = m_inputs_map[ska_num][HVAC1].at("Inside_Fire_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit94 = m_inputs_map[ska_num][HVAC1].at("bit94");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Full_Cooling = m_inputs_map[ska_num][HVAC1].at("Full_Cooling");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit96 = m_inputs_map[ska_num][HVAC1].at("bit96");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Full_Heating = m_inputs_map[ska_num][HVAC1].at("Full_Heating");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Off_Enable = m_inputs_map[ska_num][HVAC1].at("Off_Enable");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Self_Test_Not_Ok = m_inputs_map[ska_num][HVAC1].at("Self_Test_Not_Ok");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Self_Test_Ok = m_inputs_map[ska_num][HVAC1].at("Self_Test_Ok");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.PC_Software_Connected = m_inputs_map[ska_num][HVAC1].at("PC_Software_Connected");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit102 = m_inputs_map[ska_num][HVAC1].at("bit102");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit103 = m_inputs_map[ska_num][HVAC1].at("bit103");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Heat1_On = m_inputs_map[ska_num][HVAC1].at("Heat1_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Heat2_On = m_inputs_map[ska_num][HVAC1].at("Heat2_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit106 = m_inputs_map[ska_num][HVAC1].at("bit106");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit107 = m_inputs_map[ska_num][HVAC1].at("bit107");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Compressor1_On = m_inputs_map[ska_num][HVAC1].at("Compressor1_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit109 = m_inputs_map[ska_num][HVAC1].at("bit109");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Emerg_Inv_On = m_inputs_map[ska_num][HVAC1].at("Emerg_Inv_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Evap_Sel1_On = m_inputs_map[ska_num][HVAC1].at("Evap_Sel1_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved14 = m_inputs_map[ska_num][HVAC1].at("reserved14");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved15 = m_inputs_map[ska_num][HVAC1].at("reserved15");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Fresh_Air_Damp_Pos = m_inputs_map[ska_num][HVAC1].at("Fresh_Air_Damp_Pos");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Minor_Fault = m_inputs_map[ska_num][HVAC1].at("Minor_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Major_Fault = m_inputs_map[ska_num][HVAC1].at("Major_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Low_Press1_Fault = m_inputs_map[ska_num][HVAC1].at("Low_Press1_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit139 = m_inputs_map[ska_num][HVAC1].at("bit139");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.High_Press1_Fault = m_inputs_map[ska_num][HVAC1].at("High_Press1_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit141 = m_inputs_map[ska_num][HVAC1].at("bit141");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Cond_Fan1_Therm_Fault = m_inputs_map[ska_num][HVAC1].at("Cond_Fan1_Therm_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit143 = m_inputs_map[ska_num][HVAC1].at("bit143");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.First_Lev_Therm_75_Fault = m_inputs_map[ska_num][HVAC1].at("First_Lev_Therm_75_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.First_Lev_Therm_85_Fault = m_inputs_map[ska_num][HVAC1].at("First_Lev_Therm_85_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Evap_Fan1_Fault = m_inputs_map[ska_num][HVAC1].at("Evap_Fan1_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit147 = m_inputs_map[ska_num][HVAC1].at("bit147");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit148 = m_inputs_map[ska_num][HVAC1].at("bit148");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Three_Phase_Fault = m_inputs_map[ska_num][HVAC1].at("Three_Phase_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Emerg_Inv_Input_Fault = m_inputs_map[ska_num][HVAC1].at("Emerg_Inv_Input_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Emerg_Inv_Output_Fault = m_inputs_map[ska_num][HVAC1].at("Emerg_Inv_Output_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Third_Level_Therm_Fault = m_inputs_map[ska_num][HVAC1].at("Third_Level_Therm_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Evap_Therm1_Fault = m_inputs_map[ska_num][HVAC1].at("Evap_Therm1_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit154 = m_inputs_map[ska_num][HVAC1].at("bit154");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Smoke_Detector_Fault = m_inputs_map[ska_num][HVAC1].at("Smoke_Detector_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Comp1_Therm_Fault = m_inputs_map[ska_num][HVAC1].at("Comp1_Therm_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit157 = m_inputs_map[ska_num][HVAC1].at("bit157");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit158 = m_inputs_map[ska_num][HVAC1].at("bit158");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit159 = m_inputs_map[ska_num][HVAC1].at("bit159");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit160 = m_inputs_map[ska_num][HVAC1].at("bit160");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit161 = m_inputs_map[ska_num][HVAC1].at("bit161");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Cont_Evap_Solenoid1_Fault = m_inputs_map[ska_num][HVAC1].at("Cont_Evap_Solenoid1_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit163 = m_inputs_map[ska_num][HVAC1].at("bit163");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit164 = m_inputs_map[ska_num][HVAC1].at("bit164");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit165 = m_inputs_map[ska_num][HVAC1].at("bit165");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Cont_Bypass_Solenoid1_Fault = m_inputs_map[ska_num][HVAC1].at("Cont_Bypass_Solenoid1_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Cont_Heater1_Fault = m_inputs_map[ska_num][HVAC1].at("Cont_Heater1_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Cont_Heater2_Fault = m_inputs_map[ska_num][HVAC1].at("Cont_Heater2_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Cont_Evap_Fault = m_inputs_map[ska_num][HVAC1].at("Cont_Evap_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Cont_Cond_Fault = m_inputs_map[ska_num][HVAC1].at("Cont_Cond_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit171 = m_inputs_map[ska_num][HVAC1].at("bit171");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit172 = m_inputs_map[ska_num][HVAC1].at("bit172");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Cont_Emergency_Fault = m_inputs_map[ska_num][HVAC1].at("Cont_Emergency_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Comp1_Contc_Fault = m_inputs_map[ska_num][HVAC1].at("Comp1_Contc_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit175 = m_inputs_map[ska_num][HVAC1].at("bit175");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Icing_Detect_Fault = m_inputs_map[ska_num][HVAC1].at("Icing_Detect_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Supply_Cooling_Detect_Fault = m_inputs_map[ska_num][HVAC1].at("Supply_Cooling_Detect_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Supply_Heating_Detect_Fault = m_inputs_map[ska_num][HVAC1].at("Supply_Heating_Detect_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Cooling_Fault = m_inputs_map[ska_num][HVAC1].at("Cooling_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.Heating_Fault = m_inputs_map[ska_num][HVAC1].at("Heating_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit181 = m_inputs_map[ska_num][HVAC1].at("bit181");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit182 = m_inputs_map[ska_num][HVAC1].at("bit182");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.bit183 = m_inputs_map[ska_num][HVAC1].at("bit183");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved23 = m_inputs_map[ska_num][HVAC1].at("reserved23");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved24 = m_inputs_map[ska_num][HVAC1].at("reserved24");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved25 = m_inputs_map[ska_num][HVAC1].at("reserved25");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved26 = m_inputs_map[ska_num][HVAC1].at("reserved26");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved27 = m_inputs_map[ska_num][HVAC1].at("reserved27");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved28 = m_inputs_map[ska_num][HVAC1].at("reserved28");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved29 = m_inputs_map[ska_num][HVAC1].at("reserved29");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved30 = m_inputs_map[ska_num][HVAC1].at("reserved30");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb13_hvac1.bits.reserved31 = m_inputs_map[ska_num][HVAC1].at("reserved31");


}

void Ska_Hvac::set_struct_hvac2(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Software_Version_Major = m_inputs_map[ska_num][HVAC2].at("Software_Version_Major");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Software_Version_Minor = m_inputs_map[ska_num][HVAC2].at("Software_Version_Minor");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Outside_Air_Temp = m_inputs_map[ska_num][HVAC2].at("Outside_Air_Temp");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Ice_Temp = m_inputs_map[ska_num][HVAC2].at("Ice_Temp");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Supply_Air_Temp = m_inputs_map[ska_num][HVAC2].at("Supply_Air_Temp");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Inside_Air_Temp = m_inputs_map[ska_num][HVAC2].at("Inside_Air_Temp");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Set_Point_Temp = m_inputs_map[ska_num][HVAC2].at("Set_Point_Temp");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Evap_Fans_Speed = m_inputs_map[ska_num][HVAC2].at("Evap_Fans_Speed");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.CO2_Sensor = m_inputs_map[ska_num][HVAC2].at("CO2_Sensor");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Smoke_Detector = m_inputs_map[ska_num][HVAC2].at("Smoke_Detector");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.HVAC_On = m_inputs_map[ska_num][HVAC2].at("HVAC_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Auto_Mode = m_inputs_map[ska_num][HVAC2].at("Auto_Mode");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit83 = m_inputs_map[ska_num][HVAC2].at("bit83");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit84 = m_inputs_map[ska_num][HVAC2].at("bit84");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit85 = m_inputs_map[ska_num][HVAC2].at("bit85");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit86 = m_inputs_map[ska_num][HVAC2].at("bit86");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit87 = m_inputs_map[ska_num][HVAC2].at("bit87");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Reduce_Mode = m_inputs_map[ska_num][HVAC2].at("Reduce_Mode");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Emergency_Mode = m_inputs_map[ska_num][HVAC2].at("Emergency_Mode");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Self_Test_Mode = m_inputs_map[ska_num][HVAC2].at("Self_Test_Mode");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit91 = m_inputs_map[ska_num][HVAC2].at("bit91");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Fire_Mode = m_inputs_map[ska_num][HVAC2].at("Fire_Mode");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Inside_Fire_On = m_inputs_map[ska_num][HVAC2].at("Inside_Fire_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Half_Cooling = m_inputs_map[ska_num][HVAC2].at("Half_Cooling");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Full_Cooling = m_inputs_map[ska_num][HVAC2].at("Full_Cooling");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Half_Heating = m_inputs_map[ska_num][HVAC2].at("Half_Heating");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Full_Heating = m_inputs_map[ska_num][HVAC2].at("Full_Heating");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Off_Enable = m_inputs_map[ska_num][HVAC2].at("Off_Enable");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Self_Test_Not_Ok = m_inputs_map[ska_num][HVAC2].at("Self_Test_Not_Ok");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Self_Test_Ok = m_inputs_map[ska_num][HVAC2].at("Self_Test_Ok");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.PC_Software_Connected = m_inputs_map[ska_num][HVAC2].at("PC_Software_Connected");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cond_Fans_Low = m_inputs_map[ska_num][HVAC2].at("Cond_Fans_Low");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cond_Fans_High = m_inputs_map[ska_num][HVAC2].at("Cond_Fans_High");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Heat1_On = m_inputs_map[ska_num][HVAC2].at("Heat1_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Heat2_On = m_inputs_map[ska_num][HVAC2].at("Heat2_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Floor_Heat1_On = m_inputs_map[ska_num][HVAC2].at("Floor_Heat1_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Floor_Heat2_On = m_inputs_map[ska_num][HVAC2].at("Floor_Heat2_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Compressor1_On = m_inputs_map[ska_num][HVAC2].at("Compressor1_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Compressor2_On = m_inputs_map[ska_num][HVAC2].at("Compressor2_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Emerg_Inv_On = m_inputs_map[ska_num][HVAC2].at("Emerg_Inv_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Evap_Sel1_On = m_inputs_map[ska_num][HVAC2].at("Evap_Sel1_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Evap_Sel2_On = m_inputs_map[ska_num][HVAC2].at("Evap_Sel2_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit113 = m_inputs_map[ska_num][HVAC2].at("bit113");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit114 = m_inputs_map[ska_num][HVAC2].at("bit114");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit115 = m_inputs_map[ska_num][HVAC2].at("bit115");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit116 = m_inputs_map[ska_num][HVAC2].at("bit116");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit117 = m_inputs_map[ska_num][HVAC2].at("bit117");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit118 = m_inputs_map[ska_num][HVAC2].at("bit118");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit119 = m_inputs_map[ska_num][HVAC2].at("bit119");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Emerg_Shut_Air_Damp_Pos = m_inputs_map[ska_num][HVAC2].at("Emerg_Shut_Air_Damp_Pos");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Fresh_Air_Damp_Pos = m_inputs_map[ska_num][HVAC2].at("Fresh_Air_Damp_Pos");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Minor_Fault = m_inputs_map[ska_num][HVAC2].at("Minor_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Major_Fault = m_inputs_map[ska_num][HVAC2].at("Major_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Low_Press1_Fault = m_inputs_map[ska_num][HVAC2].at("Low_Press1_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Low_Press2_Fault = m_inputs_map[ska_num][HVAC2].at("Low_Press2_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.High_Press1_Fault = m_inputs_map[ska_num][HVAC2].at("High_Press1_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.High_Press2_Fault = m_inputs_map[ska_num][HVAC2].at("High_Press2_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cond_Fan1_Therm_Fault = m_inputs_map[ska_num][HVAC2].at("Cond_Fan1_Therm_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.First_Lev_Therm_7585_Fault = m_inputs_map[ska_num][HVAC2].at("First_Lev_Therm_7585_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit144 = m_inputs_map[ska_num][HVAC2].at("bit144");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit145 = m_inputs_map[ska_num][HVAC2].at("bit145");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Evap_Fan1_Fault = m_inputs_map[ska_num][HVAC2].at("Evap_Fan1_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Evap_Fan2_Fault = m_inputs_map[ska_num][HVAC2].at("Evap_Fan2_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Evap_Fan12_Fault = m_inputs_map[ska_num][HVAC2].at("Evap_Fan12_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Three_Phase_Fault = m_inputs_map[ska_num][HVAC2].at("Three_Phase_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Emerg_Inv_Input_Fault = m_inputs_map[ska_num][HVAC2].at("Emerg_Inv_Input_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Emerg_Inv_Output_Fault = m_inputs_map[ska_num][HVAC2].at("Emerg_Inv_Output_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Third_Level_Therm_Fault = m_inputs_map[ska_num][HVAC2].at("Third_Level_Therm_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Evap_Therm1_Fault = m_inputs_map[ska_num][HVAC2].at("Evap_Therm1_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Evap_Therm2_Fault = m_inputs_map[ska_num][HVAC2].at("Evap_Therm2_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Smoke_Detector_Fault = m_inputs_map[ska_num][HVAC2].at("Smoke_Detector_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Comp1_Therm_Fault = m_inputs_map[ska_num][HVAC2].at("Comp1_Therm_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Comp1_Overload_Fault = m_inputs_map[ska_num][HVAC2].at("Comp1_Overload_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Comp2_Therm_Fault = m_inputs_map[ska_num][HVAC2].at("Comp2_Therm_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Comp2_Overload_Fault = m_inputs_map[ska_num][HVAC2].at("Comp2_Overload_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Evap_Inv_Fault = m_inputs_map[ska_num][HVAC2].at("Evap_Inv_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cond_Fan2_Therm_Fault = m_inputs_map[ska_num][HVAC2].at("Cond_Fan2_Therm_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Evap_Solenoid1_Fault = m_inputs_map[ska_num][HVAC2].at("Cont_Evap_Solenoid1_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Evap_Solenoid2_Fault = m_inputs_map[ska_num][HVAC2].at("Cont_Evap_Solenoid2_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Cap_Solenoid1_Fault = m_inputs_map[ska_num][HVAC2].at("Cont_Cap_Solenoid1_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Cap_Solenoid2_Fault = m_inputs_map[ska_num][HVAC2].at("Cont_Cap_Solenoid2_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit166 = m_inputs_map[ska_num][HVAC2].at("bit166");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Heater1_Fault = m_inputs_map[ska_num][HVAC2].at("Cont_Heater1_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Heater2_Fault = m_inputs_map[ska_num][HVAC2].at("Cont_Heater2_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Evap_Fault = m_inputs_map[ska_num][HVAC2].at("Cont_Evap_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Cond_Fault = m_inputs_map[ska_num][HVAC2].at("Cont_Cond_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Cond_Fan_Low_Fault = m_inputs_map[ska_num][HVAC2].at("Cont_Cond_Fan_Low_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Cond_Fan_High_Fault = m_inputs_map[ska_num][HVAC2].at("Cont_Cond_Fan_High_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cont_Emergency_Fault = m_inputs_map[ska_num][HVAC2].at("Cont_Emergency_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Comp1_Contc_Fault = m_inputs_map[ska_num][HVAC2].at("Comp1_Contc_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Comp2_Contc_Fault = m_inputs_map[ska_num][HVAC2].at("Comp2_Contc_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Icing_Detect_Fault = m_inputs_map[ska_num][HVAC2].at("Icing_Detect_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Supply_Cooling_Detect_Fault = m_inputs_map[ska_num][HVAC2].at("Supply_Cooling_Detect_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Supply_Heating_Detect_Fault = m_inputs_map[ska_num][HVAC2].at("Supply_Heating_Detect_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Cooling_Fault = m_inputs_map[ska_num][HVAC2].at("Cooling_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.Heating_Fault = m_inputs_map[ska_num][HVAC2].at("Heating_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit180 = m_inputs_map[ska_num][HVAC2].at("bit180");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit181 = m_inputs_map[ska_num][HVAC2].at("bit181");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.bit182 = m_inputs_map[ska_num][HVAC2].at("bit182");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.reserved23 = m_inputs_map[ska_num][HVAC2].at("reserved23");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.reserved24 = m_inputs_map[ska_num][HVAC2].at("reserved24");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.reserved25 = m_inputs_map[ska_num][HVAC2].at("reserved25");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.reserved26 = m_inputs_map[ska_num][HVAC2].at("reserved26");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.reserved27 = m_inputs_map[ska_num][HVAC2].at("reserved27");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.reserved28 = m_inputs_map[ska_num][HVAC2].at("reserved28");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.reserved29 = m_inputs_map[ska_num][HVAC2].at("reserved29");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.reserved30 = m_inputs_map[ska_num][HVAC2].at("reserved30");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb14_hvac2.bits.reserved31 = m_inputs_map[ska_num][HVAC2].at("reserved31");

}
void Ska_Hvac::set_struct_hvac3(SKA_VEHICLE_NUM ska_x_num) {
    int ska_num = static_cast<int>(ska_x_num);
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Software_Version_Major = m_inputs_map[ska_num][HVAC3].at("Software_Version_Major");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Software_Version_Minor = m_inputs_map[ska_num][HVAC3].at("Software_Version_Minor");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Outside_Air_Temp = m_inputs_map[ska_num][HVAC3].at("Outside_Air_Temp");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Ice_Temp = m_inputs_map[ska_num][HVAC3].at("Ice_Temp");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Supply_Air_Temp = m_inputs_map[ska_num][HVAC3].at("Supply_Air_Temp");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Inside_Air_Temp = m_inputs_map[ska_num][HVAC3].at("Inside_Air_Temp");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Set_Point_Temp = m_inputs_map[ska_num][HVAC3].at("Set_Point_Temp");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Evap_Fans_Speed = m_inputs_map[ska_num][HVAC3].at("Evap_Fans_Speed");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.CO2_Sensor = m_inputs_map[ska_num][HVAC3].at("CO2_Sensor");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Smoke_Detector = m_inputs_map[ska_num][HVAC3].at("Smoke_Detector");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.HVAC_On = m_inputs_map[ska_num][HVAC3].at("HVAC_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Auto_Mode = m_inputs_map[ska_num][HVAC3].at("Auto_Mode");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit83 = m_inputs_map[ska_num][HVAC3].at("bit83");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit84 = m_inputs_map[ska_num][HVAC3].at("bit84");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit85 = m_inputs_map[ska_num][HVAC3].at("bit85");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit86 = m_inputs_map[ska_num][HVAC3].at("bit86");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit87 = m_inputs_map[ska_num][HVAC3].at("bit87");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Reduce_Mode = m_inputs_map[ska_num][HVAC3].at("Reduce_Mode");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Emergency_Mode = m_inputs_map[ska_num][HVAC3].at("Emergency_Mode");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Self_Test_Mode = m_inputs_map[ska_num][HVAC3].at("Self_Test_Mode");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Spare = m_inputs_map[ska_num][HVAC3].at("Spare");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Fire_Mode = m_inputs_map[ska_num][HVAC3].at("Fire_Mode");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Inside_Fire_On = m_inputs_map[ska_num][HVAC3].at("Inside_Fire_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Half_Cooling = m_inputs_map[ska_num][HVAC3].at("Half_Cooling");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Full_Cooling = m_inputs_map[ska_num][HVAC3].at("Full_Cooling");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Half_Heating = m_inputs_map[ska_num][HVAC3].at("Half_Heating");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Full_Heating = m_inputs_map[ska_num][HVAC3].at("Full_Heating");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Off_Enable = m_inputs_map[ska_num][HVAC3].at("Off_Enable");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Self_Test_Not_Ok = m_inputs_map[ska_num][HVAC3].at("Self_Test_Not_Ok");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Self_Test_Ok = m_inputs_map[ska_num][HVAC3].at("Self_Test_Ok");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.PC_Software_Connected = m_inputs_map[ska_num][HVAC3].at("PC_Software_Connected");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cond_Fans_Low = m_inputs_map[ska_num][HVAC3].at("Cond_Fans_Low");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cond_Fans_High = m_inputs_map[ska_num][HVAC3].at("Cond_Fans_High");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Heat1_On = m_inputs_map[ska_num][HVAC3].at("Heat1_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Heat2_On = m_inputs_map[ska_num][HVAC3].at("Heat2_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Floor_Heat1_On = m_inputs_map[ska_num][HVAC3].at("Floor_Heat1_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Floor_Heat2_On = m_inputs_map[ska_num][HVAC3].at("Floor_Heat2_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Compressor1_On = m_inputs_map[ska_num][HVAC3].at("Compressor1_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Compressor2_On = m_inputs_map[ska_num][HVAC3].at("Compressor2_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Emerg_Inv_On = m_inputs_map[ska_num][HVAC3].at("Emerg_Inv_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Evap_Sel1_On = m_inputs_map[ska_num][HVAC3].at("Evap_Sel1_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Evap_Sel2_On = m_inputs_map[ska_num][HVAC3].at("Evap_Sel2_On");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit97 = m_inputs_map[ska_num][HVAC3].at("bit97");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit98 = m_inputs_map[ska_num][HVAC3].at("bit98");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit99 = m_inputs_map[ska_num][HVAC3].at("bit99");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit100 = m_inputs_map[ska_num][HVAC3].at("bit100");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit101 = m_inputs_map[ska_num][HVAC3].at("bit101");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit102 = m_inputs_map[ska_num][HVAC3].at("bit102");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit103 = m_inputs_map[ska_num][HVAC3].at("bit103");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Emerg_Shut_Air_Damp_Pos = m_inputs_map[ska_num][HVAC3].at("Emerg_Shut_Air_Damp_Pos");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Fresh_Air_Damp_Pos = m_inputs_map[ska_num][HVAC3].at("Fresh_Air_Damp_Pos");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Minor_Fault = m_inputs_map[ska_num][HVAC3].at("Minor_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Major_Fault = m_inputs_map[ska_num][HVAC3].at("Major_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Low_Press1_Fault = m_inputs_map[ska_num][HVAC3].at("Low_Press1_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Low_Press2_Fault = m_inputs_map[ska_num][HVAC3].at("Low_Press2_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.High_Press1_Fault = m_inputs_map[ska_num][HVAC3].at("High_Press1_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.High_Press2_Fault = m_inputs_map[ska_num][HVAC3].at("High_Press2_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cond_Fan1_Therm_Fault = m_inputs_map[ska_num][HVAC3].at("Cond_Fan1_Therm_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.First_Lev_Therm_7585_Fault = m_inputs_map[ska_num][HVAC3].at("First_Lev_Therm_7585_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit144 = m_inputs_map[ska_num][HVAC3].at("bit144");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit145 = m_inputs_map[ska_num][HVAC3].at("bit145");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Evap_Fan1_Fault = m_inputs_map[ska_num][HVAC3].at("Evap_Fan1_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Evap_Fan2_Fault = m_inputs_map[ska_num][HVAC3].at("Evap_Fan2_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Evap_Fan12_Fault = m_inputs_map[ska_num][HVAC3].at("Evap_Fan12_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Three_Phase_Fault = m_inputs_map[ska_num][HVAC3].at("Three_Phase_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Emerg_Inv_Input_Fault = m_inputs_map[ska_num][HVAC3].at("Emerg_Inv_Input_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Emerg_Inv_Output_Fault = m_inputs_map[ska_num][HVAC3].at("Emerg_Inv_Output_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Third_Level_Therm_Fault = m_inputs_map[ska_num][HVAC3].at("Third_Level_Therm_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Evap_Therm1_Fault = m_inputs_map[ska_num][HVAC3].at("Evap_Therm1_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Evap_Therm2_Fault = m_inputs_map[ska_num][HVAC3].at("Evap_Therm2_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Smoke_Detector_Fault = m_inputs_map[ska_num][HVAC3].at("Smoke_Detector_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Comp1_Therm_Fault = m_inputs_map[ska_num][HVAC3].at("Comp1_Therm_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Comp1_Overload_Fault = m_inputs_map[ska_num][HVAC3].at("Comp1_Overload_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Comp2_Therm_Fault = m_inputs_map[ska_num][HVAC3].at("Comp2_Therm_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Comp2_Overload_Fault = m_inputs_map[ska_num][HVAC3].at("Comp2_Overload_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Evap_Inv_Fault = m_inputs_map[ska_num][HVAC3].at("Evap_Inv_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cond_Fan2_Therm_Fault = m_inputs_map[ska_num][HVAC3].at("Cond_Fan2_Therm_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Evap_Solenoid1_Fault = m_inputs_map[ska_num][HVAC3].at("Cont_Evap_Solenoid1_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Evap_Solenoid2_Fault = m_inputs_map[ska_num][HVAC3].at("Cont_Evap_Solenoid2_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Cap_Solenoid1_Fault = m_inputs_map[ska_num][HVAC3].at("Cont_Cap_Solenoid1_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Cap_Solenoid2_Fault = m_inputs_map[ska_num][HVAC3].at("Cont_Cap_Solenoid2_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit166 = m_inputs_map[ska_num][HVAC3].at("bit166");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Heater1_Fault = m_inputs_map[ska_num][HVAC3].at("Cont_Heater1_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Heater2_Fault = m_inputs_map[ska_num][HVAC3].at("Cont_Heater2_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Evap_Fault = m_inputs_map[ska_num][HVAC3].at("Cont_Evap_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Cond_Fault = m_inputs_map[ska_num][HVAC3].at("Cont_Cond_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Cond_Fan_Low_Fault = m_inputs_map[ska_num][HVAC3].at("Cont_Cond_Fan_Low_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Cond_Fan_High_Fault = m_inputs_map[ska_num][HVAC3].at("Cont_Cond_Fan_High_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cont_Emergency_Fault = m_inputs_map[ska_num][HVAC3].at("Cont_Emergency_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Comp1_Contc_Fault = m_inputs_map[ska_num][HVAC3].at("Comp1_Contc_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Comp2_Contc_Fault = m_inputs_map[ska_num][HVAC3].at("Comp2_Contc_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Icing_Detect_Fault = m_inputs_map[ska_num][HVAC3].at("Icing_Detect_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Supply_Cooling_Detect_Fault = m_inputs_map[ska_num][HVAC3].at("Supply_Cooling_Detect_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Supply_Heating_Detect_Fault = m_inputs_map[ska_num][HVAC3].at("Supply_Heating_Detect_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Cooling_Fault = m_inputs_map[ska_num][HVAC3].at("Cooling_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.Heating_Fault = m_inputs_map[ska_num][HVAC3].at("Heating_Fault");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit181 = m_inputs_map[ska_num][HVAC3].at("bit181");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit182 = m_inputs_map[ska_num][HVAC3].at("bit182");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.bit183 = m_inputs_map[ska_num][HVAC3].at("bit183");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.reserved23 = m_inputs_map[ska_num][HVAC3].at("reserved23");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.reserved24 = m_inputs_map[ska_num][HVAC3].at("reserved24");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.reserved25 = m_inputs_map[ska_num][HVAC3].at("reserved25");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.reserved26 = m_inputs_map[ska_num][HVAC3].at("reserved26");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.reserved27 = m_inputs_map[ska_num][HVAC3].at("reserved27");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.reserved28 = m_inputs_map[ska_num][HVAC3].at("reserved28");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.reserved29 = m_inputs_map[ska_num][HVAC3].at("reserved29");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.reserved30 = m_inputs_map[ska_num][HVAC3].at("reserved30");
    m_ska_x_hvac[ska_num].ska_vh_riom_ccu_mvb15_hvac3.bits.reserved31 = m_inputs_map[ska_num][HVAC3].at("reserved31");

}
void Ska_Hvac::init_ska_x_hvac1_table(SKA_VEHICLE_NUM vehicle_type)
{
    int ska_num = static_cast<int>(vehicle_type);
    m_inputs_map[ska_num][HVAC1] = {
        {"Software_Version_Major", 0},
        {"Software_Version_Minor", 0},
        {"Outside_Air_Temp", 0},
        {"Ice_Temp", 0},
        {"Supply_Air_Temp", 0},
        {"Inside_Air_Temp", 0},
        {"Set_Point_Temp", 0},
        {"Evap_Fans_Speed", 0},
        {"reserved_8", 0},
        {"reserved_9", 0},
        {"Smoke_Detector", 0},
        {"HVAC_On", 0},
        {"Auto_Mode", 0},
        {"Manual_Mode", 0},
        {"Ventilation_Mode", 0},
        {"Ventilation_Fan_Speed_Bit1", 0},
        {"Ventilation_Fan_Speed_Bit2", 0},
        {"Ventilation_Fan_Speed_Bit3", 0},
        {"Reduce_Mode", 0},
        {"Emergency_Mode", 0},
        {"Self_Test_Mode", 0},
        {"Standby_Mode", 0},
        {"Fire_Mode", 0},
        {"Inside_Fire_On", 0},
        {"bit94", 0},
        {"Full_Cooling", 0},
        {"bit96", 0},
        {"Full_Heating", 0},
        {"Off_Enable", 0},
        {"Self_Test_Not_Ok", 0},
        {"Self_Test_Ok", 0},
        {"PC_Software_Connected", 0},
        {"bit102", 0},
        {"bit103", 0},
        {"Heat1_On", 0},
        {"Heat2_On", 0},
        {"bit106", 0},
        {"bit107", 0},
        {"Compressor1_On", 0},
        {"bit109", 0},
        {"Emerg_Inv_On", 0},
        {"Evap_Sel1_On", 0},
        {"reserved14", 0},
        {"reserved15", 0},
        {"Fresh_Air_Damp_Pos", 0},
        {"Minor_Fault", 0},
        {"Major_Fault", 0},
        {"Low_Press1_Fault", 0},
        {"bit139", 0},
        {"High_Press1_Fault", 0},
        {"bit141", 0},
        {"Cond_Fan1_Therm_Fault", 0},
        {"bit143", 0},
        {"First_Lev_Therm_75_Fault", 0},
        {"First_Lev_Therm_85_Fault", 0},
        {"Evap_Fan1_Fault", 0},
        {"bit147", 0},
        {"bit148", 0},
        {"Three_Phase_Fault", 0},
        {"Emerg_Inv_Input_Fault", 0},
        {"Emerg_Inv_Output_Fault", 0},
        {"Third_Level_Therm_Fault", 0},
        {"Evap_Therm1_Fault", 0},
        {"bit154", 0},
        {"Smoke_Detector_Fault", 0},
        {"Comp1_Therm_Fault", 0},
        {"bit157", 0},
        {"bit158", 0},
        {"bit159", 0},
        {"bit160", 0},
        {"bit161", 0},
        {"Cont_Evap_Solenoid1_Fault", 0},
        {"bit163", 0},
        {"bit164", 0},
        {"bit165", 0},
        {"Cont_Bypass_Solenoid1_Fault", 0},
        {"Cont_Heater1_Fault", 0},
        {"Cont_Heater2_Fault", 0},
        {"Cont_Evap_Fault", 0},
        {"Cont_Cond_Fault", 0},
        {"bit171", 0},
        {"bit172", 0},
        {"Cont_Emergency_Fault", 0},
        {"Comp1_Contc_Fault", 0},
        {"bit175", 0},
        {"Icing_Detect_Fault", 0},
        {"Supply_Cooling_Detect_Fault", 0},
        {"Supply_Heating_Detect_Fault", 0},
        {"Cooling_Fault", 0},
        {"Heating_Fault", 0},
        {"bit181", 0},
        {"bit182", 0},
        {"bit183", 0},
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


    /*m_tableWidget[ska_num][HVAC1] = new QTableWidget();
    m_tableWidget[ska_num][HVAC1]->setColumnCount(2);
    m_tableWidget[ska_num][HVAC1]->setRowCount(m_inputs_map[ska_num][HVAC1].size());
    m_tableWidget[ska_num][HVAC1]->setHorizontalHeaderLabels(table_name[ska_num][HVAC1]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[ska_num][HVAC1]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[ska_num][HVAC1]->setItem(row, 0, item_name);
        m_tableWidget[ska_num][HVAC1]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[ska_num][HVAC1]->resizeColumnsToContents();*/

    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[ska_num][HVAC1].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[ska_num][HVAC1] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[ska_num][HVAC1]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[ska_num][HVAC1]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[ska_num][HVAC1]->setItem(row, column, item_name);
        m_tableWidget[ska_num][HVAC1]->setItem(row, column + 1, item_val); // Değer

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[ska_num][HVAC1]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][HVAC1]->columnCount() ;
}

void Ska_Hvac::init_ska_x_hvac2_table(SKA_VEHICLE_NUM vehicle_type)
{
    int ska_num = static_cast<int>(vehicle_type);
    m_inputs_map[ska_num][HVAC2] = {
                                    {"Software_Version_Major", 0},
                                    {"Software_Version_Minor", 0},
                                    {"Outside_Air_Temp", 0},
                                    {"Ice_Temp", 0},
                                    {"Supply_Air_Temp", 0},
                                    {"Inside_Air_Temp", 0},
                                    {"Set_Point_Temp", 0},
                                    {"Evap_Fans_Speed", 0},
                                    {"CO2_Sensor", 0},
                                    {"Smoke_Detector", 0},
                                    {"HVAC_On", 0},
                                    {"Auto_Mode", 0},
                                    {"bit83", 0},
                                    {"bit84", 0},
                                    {"bit85", 0},
                                    {"bit86", 0},
                                    {"bit87", 0},
                                    {"Reduce_Mode", 0},
                                    {"Emergency_Mode", 0},
                                    {"Self_Test_Mode", 0},
                                    {"bit91", 0},
                                    {"Fire_Mode", 0},
                                    {"Inside_Fire_On", 0},
                                    {"Half_Cooling", 0},
                                    {"Full_Cooling", 0},
                                    {"Half_Heating", 0},
                                    {"Full_Heating", 0},
                                    {"Off_Enable", 0},
                                    {"Self_Test_Not_Ok", 0},
                                    {"Self_Test_Ok", 0},
                                    {"PC_Software_Connected", 0},
                                    {"Cond_Fans_Low", 0},
                                    {"Cond_Fans_High", 0},
                                    {"Heat1_On", 0},
                                    {"Heat2_On", 0},
                                    {"Floor_Heat1_On", 0},
                                    {"Floor_Heat2_On", 0},
                                    {"Compressor1_On", 0},
                                    {"Compressor2_On", 0},
                                    {"Emerg_Inv_On", 0},
                                    {"Evap_Sel1_On", 0},
                                    {"Evap_Sel2_On", 0},
                                    {"bit113", 0},
                                    {"bit114", 0},
                                    {"bit115", 0},
                                    {"bit116", 0},
                                    {"bit117", 0},
                                    {"bit118", 0},
                                    {"bit119", 0},
                                    {"Emerg_Shut_Air_Damp_Pos", 0},
                                    {"Fresh_Air_Damp_Pos", 0},
                                    {"Minor_Fault", 0},
                                    {"Major_Fault", 0},
                                    {"Low_Press1_Fault", 0},
                                    {"Low_Press2_Fault", 0},
                                    {"High_Press1_Fault", 0},
                                    {"High_Press2_Fault", 0},
                                    {"Cond_Fan1_Therm_Fault", 0},
                                    {"First_Lev_Therm_7585_Fault", 0},
                                    {"bit144", 0},
                                    {"bit145", 0},
                                    {"Evap_Fan1_Fault", 0},
                                    {"Evap_Fan2_Fault", 0},
                                    {"Evap_Fan12_Fault", 0},
                                    {"Three_Phase_Fault", 0},
                                    {"Emerg_Inv_Input_Fault", 0},
                                    {"Emerg_Inv_Output_Fault", 0},
                                    {"Third_Level_Therm_Fault", 0},
                                    {"Evap_Therm1_Fault", 0},
                                    {"Evap_Therm2_Fault", 0},
                                    {"Smoke_Detector_Fault", 0},
                                    {"Comp1_Therm_Fault", 0},
                                    {"Comp1_Overload_Fault", 0},
                                    {"Comp2_Therm_Fault", 0},
                                    {"Comp2_Overload_Fault", 0},
                                    {"Evap_Inv_Fault", 0},
                                    {"Cond_Fan2_Therm_Fault", 0},
                                    {"Cont_Evap_Solenoid1_Fault", 0},
                                    {"Cont_Evap_Solenoid2_Fault", 0},
                                    {"Cont_Cap_Solenoid1_Fault", 0},
                                    {"Cont_Cap_Solenoid2_Fault", 0},
                                    {"bit166", 0},
                                    {"Cont_Heater1_Fault", 0},
                                    {"Cont_Heater2_Fault", 0},
                                    {"Cont_Evap_Fault", 0},
                                    {"Cont_Cond_Fault", 0},
                                    {"Cont_Cond_Fan_Low_Fault", 0},
                                    {"Cont_Cond_Fan_High_Fault", 0},
                                    {"Cont_Emergency_Fault", 0},
                                    {"Comp1_Contc_Fault", 0},
                                    {"Comp2_Contc_Fault", 0},
                                    {"Icing_Detect_Fault", 0},
                                    {"Supply_Cooling_Detect_Fault", 0},
                                    {"Supply_Heating_Detect_Fault", 0},
                                    {"Cooling_Fault", 0},
                                    {"Heating_Fault", 0},
                                    {"bit180", 0},
                                    {"bit181", 0},
                                    {"bit182", 0},
                                    {"reserved23", 0},
                                    {"reserved24", 0},
                                    {"reserved25", 0},
                                    {"reserved26", 0},
                                    {"reserved27", 0},
                                    {"reserved28", 0},
                                    {"reserved29", 0},
                                    {"reserved30", 0},
                                    {"reserved31", 0},
                                    };



    /*m_tableWidget[ska_num][HVAC2] = new QTableWidget();
    m_tableWidget[ska_num][HVAC2]->setColumnCount(2);
    m_tableWidget[ska_num][HVAC2]->setRowCount(m_inputs_map[ska_num][HVAC2].size());
    m_tableWidget[ska_num][HVAC2]->setHorizontalHeaderLabels(table_name[ska_num][HVAC2]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[ska_num][HVAC2]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[ska_num][HVAC2]->setItem(row, 0, item_name);
        m_tableWidget[ska_num][HVAC2]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[ska_num][HVAC2]->resizeColumnsToContents();*/

    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[ska_num][HVAC2].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[ska_num][HVAC2] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[ska_num][HVAC2]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[ska_num][HVAC2]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[ska_num][HVAC2]->setItem(row, column, item_name);
        m_tableWidget[ska_num][HVAC2]->setItem(row, column + 1, item_val); // Değer

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[ska_num][HVAC2]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][HVAC2]->columnCount() ;
}

void Ska_Hvac::init_ska_x_hvac3_table(SKA_VEHICLE_NUM vehicle_type)
{
    int ska_num = static_cast<int>(vehicle_type);
    m_inputs_map[ska_num][HVAC3] = {
                                    {"Software_Version_Major", 0},
                                    {"Software_Version_Minor", 0},
                                    {"Outside_Air_Temp", 0},
                                    {"Ice_Temp", 0},
                                    {"Supply_Air_Temp", 0},
                                    {"Inside_Air_Temp", 0},
                                    {"Set_Point_Temp", 0},
                                    {"Evap_Fans_Speed", 0},
                                    {"CO2_Sensor", 0},
                                    {"Smoke_Detector", 0},
                                    {"HVAC_On", 0},
                                    {"Auto_Mode", 0},
                                    {"bit83", 0},
                                    {"bit84", 0},
                                    {"bit85", 0},
                                    {"bit86", 0},
                                    {"bit87", 0},
                                    {"Reduce_Mode", 0},
                                    {"Emergency_Mode", 0},
                                    {"Self_Test_Mode", 0},
                                    {"Spare", 0},
                                    {"Fire_Mode", 0},
                                    {"Inside_Fire_On", 0},
                                    {"Half_Cooling", 0},
                                    {"Full_Cooling", 0},
                                    {"Half_Heating", 0},
                                    {"Full_Heating", 0},
                                    {"Off_Enable", 0},
                                    {"Self_Test_Not_Ok", 0},
                                    {"Self_Test_Ok", 0},
                                    {"PC_Software_Connected", 0},
                                    {"Cond_Fans_Low", 0},
                                    {"Cond_Fans_High", 0},
                                    {"Heat1_On", 0},
                                    {"Heat2_On", 0},
                                    {"Floor_Heat1_On", 0},
                                    {"Floor_Heat2_On", 0},
                                    {"Compressor1_On", 0},
                                    {"Compressor2_On", 0},
                                    {"Emerg_Inv_On", 0},
                                    {"Evap_Sel1_On", 0},
                                    {"Evap_Sel2_On", 0},
                                    {"bit97", 0},
                                    {"bit98", 0},
                                    {"bit99", 0},
                                    {"bit100", 0},
                                    {"bit101", 0},
                                    {"bit102", 0},
                                    {"bit103", 0},
                                    {"Emerg_Shut_Air_Damp_Pos", 0},
                                    {"Fresh_Air_Damp_Pos", 0},
                                    {"Minor_Fault", 0},
                                    {"Major_Fault", 0},
                                    {"Low_Press1_Fault", 0},
                                    {"Low_Press2_Fault", 0},
                                    {"High_Press1_Fault", 0},
                                    {"High_Press2_Fault", 0},
                                    {"Cond_Fan1_Therm_Fault", 0},
                                    {"First_Lev_Therm_7585_Fault", 0},
                                    {"bit144", 0},
                                    {"bit145", 0},
                                    {"Evap_Fan1_Fault", 0},
                                    {"Evap_Fan2_Fault", 0},
                                    {"Evap_Fan12_Fault", 0},
                                    {"Three_Phase_Fault", 0},
                                    {"Emerg_Inv_Input_Fault", 0},
                                    {"Emerg_Inv_Output_Fault", 0},
                                    {"Third_Level_Therm_Fault", 0},
                                    {"Evap_Therm1_Fault", 0},
                                    {"Evap_Therm2_Fault", 0},
                                    {"Smoke_Detector_Fault", 0},
                                    {"Comp1_Therm_Fault", 0},
                                    {"Comp1_Overload_Fault", 0},
                                    {"Comp2_Therm_Fault", 0},
                                    {"Comp2_Overload_Fault", 0},
                                    {"Evap_Inv_Fault", 0},
                                    {"Cond_Fan2_Therm_Fault", 0},
                                    {"Cont_Evap_Solenoid1_Fault", 0},
                                    {"Cont_Evap_Solenoid2_Fault", 0},
                                    {"Cont_Cap_Solenoid1_Fault", 0},
                                    {"Cont_Cap_Solenoid2_Fault", 0},
                                    {"bit166", 0},
                                    {"Cont_Heater1_Fault", 0},
                                    {"Cont_Heater2_Fault", 0},
                                    {"Cont_Evap_Fault", 0},
                                    {"Cont_Cond_Fault", 0},
                                    {"Cont_Cond_Fan_Low_Fault", 0},
                                    {"Cont_Cond_Fan_High_Fault", 0},
                                    {"Cont_Emergency_Fault", 0},
                                    {"Comp1_Contc_Fault", 0},
                                    {"Comp2_Contc_Fault", 0},
                                    {"Icing_Detect_Fault", 0},
                                    {"Supply_Cooling_Detect_Fault", 0},
                                    {"Supply_Heating_Detect_Fault", 0},
                                    {"Cooling_Fault", 0},
                                    {"Heating_Fault", 0},
                                    {"bit181", 0},
                                    {"bit182", 0},
                                    {"bit183", 0},
                                    {"reserved23", 0},
                                    {"reserved24", 0},
                                    {"reserved25", 0},
                                    {"reserved26", 0},
                                    {"reserved27", 0},
                                    {"reserved28", 0},
                                    {"reserved29", 0},
                                    {"reserved30", 0},
                                    {"reserved31", 0},
                                    };



    /*m_tableWidget[ska_num][HVAC3] = new QTableWidget();
    m_tableWidget[ska_num][HVAC3]->setColumnCount(2);
    m_tableWidget[ska_num][HVAC3]->setRowCount(m_inputs_map[ska_num][HVAC3].size());
    m_tableWidget[ska_num][HVAC3]->setHorizontalHeaderLabels(table_name[ska_num][HVAC3]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[ska_num][HVAC3]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[ska_num][HVAC3]->setItem(row, 0, item_name);
        m_tableWidget[ska_num][HVAC3]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[ska_num][HVAC3]->resizeColumnsToContents();*/

    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[ska_num][HVAC3].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[ska_num][HVAC3] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[ska_num][HVAC3]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[ska_num][HVAC3]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[ska_num][HVAC3]->setItem(row, column, item_name);
        m_tableWidget[ska_num][HVAC3]->setItem(row, column + 1, item_val); // Değer

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[ska_num][HVAC3]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][HVAC3]->columnCount() ;
}

void Ska_Hvac::update_struct_with_map(SKA_VEHICLE_NUM ska_x_num, HVAC_NUM HVAC_NUM)
{
    int ska_num = static_cast<int>(ska_x_num);
    // Define a lambda function to reduce redundancy
    auto setInputMap = [&](const QString& signal_name) {
        m_inputs_map[ska_num][HVAC_NUM][signal_name] = utils::getTableWidgetValueByNameWithoutColumn(m_tableWidget[ska_num][HVAC_NUM], signal_name).toInt();
    };
    // update map with given tableWidget values
    for(const auto& map : m_inputs_map[ska_num][HVAC_NUM])
    {
        setInputMap(map.first);
    }
    // set struct parameters with given updated map parameters
    set_struct_hvac1(ska_x_num);
    set_struct_hvac2(ska_x_num);
    set_struct_hvac3(ska_x_num);

}
