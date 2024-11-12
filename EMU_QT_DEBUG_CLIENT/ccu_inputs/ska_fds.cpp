#include "ska_fds.h"
#include "utils.h"

SKA_FDS::SKA_FDS(QObject *parent)
    : QObject{parent}
{
    memset(&m_ska_x_fds, 0, sizeof(m_ska_x_fds));
    init_ska_x_fds1_table(SKA_VEHICLE_NUM::SKA1);
    init_ska_x_fds2_table(SKA_VEHICLE_NUM::SKA1);
    init_ska_x_fds3_table(SKA_VEHICLE_NUM::SKA1);


    init_ska_x_fds1_table(SKA_VEHICLE_NUM::SKA2);
    init_ska_x_fds2_table(SKA_VEHICLE_NUM::SKA2);
    init_ska_x_fds3_table(SKA_VEHICLE_NUM::SKA2);

    make_signal_slot_connection();

}

SKA_FDS::~SKA_FDS()
{

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            delete m_tableWidget[i][j];
            m_tableWidget[i][j] = nullptr; // Güvenlik için nullptr atayın
        }
    }
}

void SKA_FDS::make_signal_slot_connection()
{
    // SKA1 FDS1 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][FDS1], &QTableWidget::itemChanged,this, [&](){
        qDebug() << "item changed";
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1, FDS1);
    });

    // SKA1 FDS2 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][FDS2], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1, FDS2);
    });

    // SKA1 FDS3 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][FDS3], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1, FDS3);
    });

    ////////////////////////////////////// SKA2 //////////////////////////////////////////7
    // SKA2 FDS1 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][FDS1], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2, FDS1);
    });

    // SKA2 FDS2 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][FDS2], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2, FDS2);
    });

    // SKA2 FDS3 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][FDS3], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2, FDS3);
    });
}



void SKA_FDS::update_fds1_map(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);

    m_inputs_map[ska_num][FDS1].at("S_FDCU_Master")                        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_FDCU_Master                          ;
    m_inputs_map[ska_num][FDS1].at("S_FDCU_General_fire")                  =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_FDCU_General_fire                    ;
    m_inputs_map[ska_num][FDS1].at("S_FDCU_Unmuted_fire_alarm")            =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_FDCU_Unmuted_fire_alarm              ;
    m_inputs_map[ska_num][FDS1].at("S_FDCU_Fire_fault_reset_feedback_RPDO")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_FDCU_Fire_fault_reset_feedback_RPDO  ;
    m_inputs_map[ska_num][FDS1].at("S_FDCU_General_fault")                 =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_FDCU_General_fault                   ;
    m_inputs_map[ska_num][FDS1].at("S_FDCU_Unmuted_fault_alarm")           =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_FDCU_Unmuted_fault_alarm             ;
    m_inputs_map[ska_num][FDS1].at("S_FDCU_Prealarm")                      =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_FDCU_Prealarm                        ;
    m_inputs_map[ska_num][FDS1].at("S_FDCU_Resound_alarm_feedback_RPDO")   =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_FDCU_Resound_alarm_feedback_RPDO     ;
    m_inputs_map[ska_num][FDS1].at("reserved1")                            =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.reserved1                          ;

    m_inputs_map[ska_num][FDS1].at("S_SKA1_SFD1_Smoke_alarm")                   =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_SKA1_SFD1_Smoke_alarm                     ;
    m_inputs_map[ska_num][FDS1].at("S_SKA1_SFD1_Heat_alarm")                    =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_SKA1_SFD1_Heat_alarm                      ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_Disconnection")                 =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_Disconnection                   ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_FC128")                         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_FC128                           ;
    m_inputs_map[ska_num][FDS1].at("bit20")                                     =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit20                                       ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_FC159                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_FC130")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_FC130                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_FC143                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_FC129                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_FC181                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_FC190                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_FC229                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_FC232                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_FC138                           ;
    m_inputs_map[ska_num][FDS1].at("bit30")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit30                                       ;
    m_inputs_map[ska_num][FDS1].at("bit31")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit31                                       ;
    m_inputs_map[ska_num][FDS1].at("S_SKA1_SFD2_Smoke_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_SKA1_SFD2_Smoke_alarm                     ;
    m_inputs_map[ska_num][FDS1].at("S_SKA1_SFD2_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_SKA1_SFD2_Heat_alarm                      ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_Disconnection                   ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_FC128                           ;
    m_inputs_map[ska_num][FDS1].at("bit36")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit36                                       ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_FC159                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_FC130")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_FC130                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_FC143                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_FC129                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_FC181                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_FC190                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_FC229                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_FC232                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_FC138                           ;
    m_inputs_map[ska_num][FDS1].at("bit46")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit46                                       ;
    m_inputs_map[ska_num][FDS1].at("bit47")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit47                                       ;
    m_inputs_map[ska_num][FDS1].at("S_SKA1_SFD3_Smoke_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_SKA1_SFD3_Smoke_alarm                     ;
    m_inputs_map[ska_num][FDS1].at("S_SKA1_SFD3_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_SKA1_SFD3_Heat_alarm                      ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_Disconnection                   ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_FC128                           ;
    m_inputs_map[ska_num][FDS1].at("bit52")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit52                                       ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_FC159                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_FC130")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_FC130                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_FC143                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_FC129                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_FC181                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_FC190                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_FC229                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_FC232                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_FC138                           ;
    m_inputs_map[ska_num][FDS1].at("bit62")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit62                                       ;
    m_inputs_map[ska_num][FDS1].at("bit63")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit63                                       ;
    m_inputs_map[ska_num][FDS1].at("S_SKA1_SFD4_Smoke_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_SKA1_SFD4_Smoke_alarm                     ;
    m_inputs_map[ska_num][FDS1].at("S_SKA1_SFD4_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_SKA1_SFD4_Heat_alarm                      ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_Disconnection                   ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_FC128                           ;
    m_inputs_map[ska_num][FDS1].at("bit68")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit68                                       ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_FC159                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_FC130")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_FC130                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_FC143                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_FC129                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_FC181                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_FC190                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_FC229                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_FC232                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_FC138                           ;
    m_inputs_map[ska_num][FDS1].at("bit78")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit78                                       ;
    m_inputs_map[ska_num][FDS1].at("bit79")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit79                                       ;
    m_inputs_map[ska_num][FDS1].at("S_SKA1_SFD5_Smoke_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_SKA1_SFD5_Smoke_alarm                     ;
    m_inputs_map[ska_num][FDS1].at("S_SKA1_SFD5_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_SKA1_SFD5_Heat_alarm                      ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_Disconnection                   ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_FC128                           ;
    m_inputs_map[ska_num][FDS1].at("bit84")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit84                                       ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_FC159                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_FC130")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_FC130                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_FC143                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_FC129                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_FC181                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_FC190                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_FC229                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_FC232                           ;
    m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_FC138                           ;
    m_inputs_map[ska_num][FDS1].at("bit94")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit94                                       ;
    m_inputs_map[ska_num][FDS1].at("bit95")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit95                                       ;
    m_inputs_map[ska_num][FDS1].at("S_OA1_SFD1_Smoke_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA1_SFD1_Smoke_alarm                      ;
    m_inputs_map[ska_num][FDS1].at("S_OA1_SFD1_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA1_SFD1_Heat_alarm                       ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_Disconnection                    ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_FC128                            ;
    m_inputs_map[ska_num][FDS1].at("bit100")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit100                                      ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_FC159                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_FC130")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_FC130                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_FC143                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_FC129                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_FC181                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_FC190                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_FC229                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_FC232                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_FC138                            ;
    m_inputs_map[ska_num][FDS1].at("bit110")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit110                                      ;
    m_inputs_map[ska_num][FDS1].at("bit111")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit111                                      ;
    m_inputs_map[ska_num][FDS1].at("S_OA1_SFD2_Smoke_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA1_SFD2_Smoke_alarm                      ;
    m_inputs_map[ska_num][FDS1].at("S_OA1_SFD2_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA1_SFD2_Heat_alarm                       ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_Disconnection                    ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_FC128                            ;
    m_inputs_map[ska_num][FDS1].at("bit116")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit116                                      ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_FC159                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_FC130")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_FC130                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_FC143                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_FC129                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_FC181                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_FC190                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_FC229                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_FC232                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_FC138                            ;
    m_inputs_map[ska_num][FDS1].at("bit126")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit126                                      ;
    m_inputs_map[ska_num][FDS1].at("bit127")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit127                                      ;
    m_inputs_map[ska_num][FDS1].at("S_OA1_SFD3_Smoke_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA1_SFD3_Smoke_alarm                      ;
    m_inputs_map[ska_num][FDS1].at("S_OA1_SFD3_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA1_SFD3_Heat_alarm                       ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_Disconnection                    ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_FC128                            ;
    m_inputs_map[ska_num][FDS1].at("bit132")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit132                                      ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_FC159                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_FC130")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_FC130                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_FC143                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_FC129                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_FC181                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_FC190                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_FC229                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_FC232                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_FC138                            ;
    m_inputs_map[ska_num][FDS1].at("bit142")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit142                                      ;
    m_inputs_map[ska_num][FDS1].at("bit143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit143                                      ;
    m_inputs_map[ska_num][FDS1].at("S_OA1_SFD4_Smoke_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA1_SFD4_Smoke_alarm                      ;
    m_inputs_map[ska_num][FDS1].at("S_OA1_SFD4_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA1_SFD4_Heat_alarm                       ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_Disconnection                    ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_FC128                            ;
    m_inputs_map[ska_num][FDS1].at("bit148")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit148                                      ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_FC159                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_FC130")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_FC130                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_FC143                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_FC129                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_FC181                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_FC190                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_FC229                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_FC232                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_FC138                            ;
    m_inputs_map[ska_num][FDS1].at("bit158")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit158                                      ;
    m_inputs_map[ska_num][FDS1].at("bit159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit159                                      ;
    m_inputs_map[ska_num][FDS1].at("S_OA1_SFD5_Smoke_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA1_SFD5_Smoke_alarm                      ;
    m_inputs_map[ska_num][FDS1].at("S_OA1_SFD5_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA1_SFD5_Heat_alarm                       ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_Disconnection                    ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_FC128                            ;
    m_inputs_map[ska_num][FDS1].at("bit164")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit164                                      ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_FC159                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_FC130")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_FC130                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_FC143                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_FC129                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_FC181                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_FC190                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_FC229                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_FC232                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_FC138                            ;
    m_inputs_map[ska_num][FDS1].at("bit174")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit174                                      ;
    m_inputs_map[ska_num][FDS1].at("bit175")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit175                                      ;
    m_inputs_map[ska_num][FDS1].at("S_OA2_SFD1_Smoke_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA2_SFD1_Smoke_alarm                      ;
    m_inputs_map[ska_num][FDS1].at("S_OA2_SFD1_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA2_SFD1_Heat_alarm                       ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_Disconnection                    ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_FC128                            ;
    m_inputs_map[ska_num][FDS1].at("bit180")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit180                                      ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_FC159                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_FC130")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_FC130                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_FC143                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_FC129                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_FC181                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_FC190                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_FC229                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_FC232                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_FC138                            ;
    m_inputs_map[ska_num][FDS1].at("bit190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit190                                      ;
    m_inputs_map[ska_num][FDS1].at("bit191")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit191                                      ;
    m_inputs_map[ska_num][FDS1].at("S_OA2_SFD2_Smoke_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA2_SFD2_Smoke_alarm                      ;
    m_inputs_map[ska_num][FDS1].at("S_OA2_SFD2_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA2_SFD2_Heat_alarm                       ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_Disconnection                    ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_FC128                            ;
    m_inputs_map[ska_num][FDS1].at("bit196")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit196                                      ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_FC159                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_FC130")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_FC130                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_FC143                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_FC129                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_FC181                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_FC190                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_FC229                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_FC232                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_FC138                            ;
    m_inputs_map[ska_num][FDS1].at("bit206")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit206                                      ;
    m_inputs_map[ska_num][FDS1].at("bit207")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit207                                      ;
    m_inputs_map[ska_num][FDS1].at("S_OA2_SFD3_Smoke_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA2_SFD3_Smoke_alarm                      ;
    m_inputs_map[ska_num][FDS1].at("S_OA2_SFD3_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA2_SFD3_Heat_alarm                       ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_Disconnection                    ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_FC128                            ;
    m_inputs_map[ska_num][FDS1].at("bit212")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit212                                      ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_FC159                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_FC130")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_FC130                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_FC143                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_FC129                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_FC181                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_FC190                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_FC229                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_FC232                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_FC138                            ;
    m_inputs_map[ska_num][FDS1].at("bit222")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit222                                      ;
    m_inputs_map[ska_num][FDS1].at("bit223")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit223                                      ;
    m_inputs_map[ska_num][FDS1].at("S_OA2_SFD4_Smoke_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA2_SFD4_Smoke_alarm                      ;
    m_inputs_map[ska_num][FDS1].at("S_OA2_SFD4_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA2_SFD4_Heat_alarm                       ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_Disconnection                    ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_FC128                            ;
    m_inputs_map[ska_num][FDS1].at("bit228")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit228                                      ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_FC159                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_FC130")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_FC130                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_FC143                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_FC129                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_FC181                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_FC190                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_FC229                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_FC232                            ;
    m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_FC138                            ;
    m_inputs_map[ska_num][FDS1].at("bit238")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit238                                      ;
    m_inputs_map[ska_num][FDS1].at("bit239")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit239                                      ;
    m_inputs_map[ska_num][FDS1].at("reserved_30")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.reserved_30                                 ;
    m_inputs_map[ska_num][FDS1].at("reserved_31")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.reserved_31                                 ;
}


void SKA_FDS::set_struct_fds1(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);

    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_FDCU_Master                          =m_inputs_map[ska_num][FDS1].at("S_FDCU_Master");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_FDCU_General_fire                    =m_inputs_map[ska_num][FDS1].at("S_FDCU_General_fire");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_FDCU_Unmuted_fire_alarm              =m_inputs_map[ska_num][FDS1].at("S_FDCU_Unmuted_fire_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_FDCU_Fire_fault_reset_feedback_RPDO  =m_inputs_map[ska_num][FDS1].at("S_FDCU_Fire_fault_reset_feedback_RPDO");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_FDCU_General_fault                   =m_inputs_map[ska_num][FDS1].at("S_FDCU_General_fault");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_FDCU_Unmuted_fault_alarm             =m_inputs_map[ska_num][FDS1].at("S_FDCU_Unmuted_fault_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_FDCU_Prealarm                        =m_inputs_map[ska_num][FDS1].at("S_FDCU_Prealarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_FDCU_Resound_alarm_feedback_RPDO     =m_inputs_map[ska_num][FDS1].at("S_FDCU_Resound_alarm_feedback_RPDO");

    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.reserved1                               =m_inputs_map[ska_num][FDS1].at("reserved1");

    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_SKA1_SFD1_Smoke_alarm                     =m_inputs_map[ska_num][FDS1].at("S_SKA1_SFD1_Smoke_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_SKA1_SFD1_Heat_alarm                      =m_inputs_map[ska_num][FDS1].at("S_SKA1_SFD1_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_Disconnection                   =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_FC128                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit20                                       =m_inputs_map[ska_num][FDS1].at("bit20");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_FC159                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_FC130                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_FC130");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_FC143                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_FC129                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_FC181                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_FC190                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_FC229                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_FC232                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD1_FC138                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD1_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit30                                       =m_inputs_map[ska_num][FDS1].at("bit30");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit31                                       =m_inputs_map[ska_num][FDS1].at("bit31");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_SKA1_SFD2_Smoke_alarm                     =m_inputs_map[ska_num][FDS1].at("S_SKA1_SFD2_Smoke_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_SKA1_SFD2_Heat_alarm                      =m_inputs_map[ska_num][FDS1].at("S_SKA1_SFD2_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_Disconnection                   =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_FC128                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit36                                       =m_inputs_map[ska_num][FDS1].at("bit36");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_FC159                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_FC130                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_FC130");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_FC143                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_FC129                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_FC181                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_FC190                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_FC229                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_FC232                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD2_FC138                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD2_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit46                                       =m_inputs_map[ska_num][FDS1].at("bit46");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit47                                       =m_inputs_map[ska_num][FDS1].at("bit47");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_SKA1_SFD3_Smoke_alarm                     =m_inputs_map[ska_num][FDS1].at("S_SKA1_SFD3_Smoke_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_SKA1_SFD3_Heat_alarm                      =m_inputs_map[ska_num][FDS1].at("S_SKA1_SFD3_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_Disconnection                   =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_FC128                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit52                                       =m_inputs_map[ska_num][FDS1].at("bit52");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_FC159                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_FC130                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_FC130");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_FC143                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_FC129                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_FC181                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_FC190                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_FC229                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_FC232                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD3_FC138                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD3_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit62                                       =m_inputs_map[ska_num][FDS1].at("bit62");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit63                                       =m_inputs_map[ska_num][FDS1].at("bit63");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_SKA1_SFD4_Smoke_alarm                     =m_inputs_map[ska_num][FDS1].at("S_SKA1_SFD4_Smoke_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_SKA1_SFD4_Heat_alarm                      =m_inputs_map[ska_num][FDS1].at("S_SKA1_SFD4_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_Disconnection                   =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_FC128                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit68                                       =m_inputs_map[ska_num][FDS1].at("bit68");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_FC159                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_FC130                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_FC130");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_FC143                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_FC129                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_FC181                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_FC190                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_FC229                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_FC232                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD4_FC138                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD4_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit78                                       =m_inputs_map[ska_num][FDS1].at("bit78");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit79                                       =m_inputs_map[ska_num][FDS1].at("bit79");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_SKA1_SFD5_Smoke_alarm                     =m_inputs_map[ska_num][FDS1].at("S_SKA1_SFD5_Smoke_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_SKA1_SFD5_Heat_alarm                      =m_inputs_map[ska_num][FDS1].at("S_SKA1_SFD5_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_Disconnection                   =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_FC128                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit84                                       =m_inputs_map[ska_num][FDS1].at("bit84");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_FC159                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_FC130                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_FC130");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_FC143                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_FC129                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_FC181                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_FC190                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_FC229                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_FC232                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_SKA1_SFD5_FC138                           =m_inputs_map[ska_num][FDS1].at("D_SKA1_SFD5_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit94                                       =m_inputs_map[ska_num][FDS1].at("bit94");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit95                                       =m_inputs_map[ska_num][FDS1].at("bit95");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA1_SFD1_Smoke_alarm                      =m_inputs_map[ska_num][FDS1].at("S_OA1_SFD1_Smoke_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA1_SFD1_Heat_alarm                       =m_inputs_map[ska_num][FDS1].at("S_OA1_SFD1_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_Disconnection                    =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_FC128                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit100                                      =m_inputs_map[ska_num][FDS1].at("bit100");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_FC159                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_FC130                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_FC130");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_FC143                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_FC129                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_FC181                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_FC190                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_FC229                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_FC232                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD1_FC138                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD1_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit110                                      =m_inputs_map[ska_num][FDS1].at("bit110");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit111                                      =m_inputs_map[ska_num][FDS1].at("bit111");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA1_SFD2_Smoke_alarm                      =m_inputs_map[ska_num][FDS1].at("S_OA1_SFD2_Smoke_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA1_SFD2_Heat_alarm                       =m_inputs_map[ska_num][FDS1].at("S_OA1_SFD2_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_Disconnection                    =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_FC128                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit116                                      =m_inputs_map[ska_num][FDS1].at("bit116");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_FC159                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_FC130                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_FC130");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_FC143                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_FC129                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_FC181                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_FC190                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_FC229                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_FC232                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD2_FC138                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD2_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit126                                      =m_inputs_map[ska_num][FDS1].at("bit126");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit127                                      =m_inputs_map[ska_num][FDS1].at("bit127");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA1_SFD3_Smoke_alarm                      =m_inputs_map[ska_num][FDS1].at("S_OA1_SFD3_Smoke_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA1_SFD3_Heat_alarm                       =m_inputs_map[ska_num][FDS1].at("S_OA1_SFD3_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_Disconnection                    =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_FC128                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit132                                      =m_inputs_map[ska_num][FDS1].at("bit132");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_FC159                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_FC130                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_FC130");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_FC143                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_FC129                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_FC181                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_FC190                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_FC229                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_FC232                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD3_FC138                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD3_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit142                                      =m_inputs_map[ska_num][FDS1].at("bit142");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit143                                      =m_inputs_map[ska_num][FDS1].at("bit143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA1_SFD4_Smoke_alarm                      =m_inputs_map[ska_num][FDS1].at("S_OA1_SFD4_Smoke_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA1_SFD4_Heat_alarm                       =m_inputs_map[ska_num][FDS1].at("S_OA1_SFD4_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_Disconnection                    =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_FC128                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit148                                      =m_inputs_map[ska_num][FDS1].at("bit148");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_FC159                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_FC130                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_FC130");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_FC143                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_FC129                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_FC181                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_FC190                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_FC229                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_FC232                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD4_FC138                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD4_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit158                                      =m_inputs_map[ska_num][FDS1].at("bit158");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit159                                      =m_inputs_map[ska_num][FDS1].at("bit159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA1_SFD5_Smoke_alarm                      =m_inputs_map[ska_num][FDS1].at("S_OA1_SFD5_Smoke_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA1_SFD5_Heat_alarm                       =m_inputs_map[ska_num][FDS1].at("S_OA1_SFD5_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_Disconnection                    =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_FC128                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit164                                      =m_inputs_map[ska_num][FDS1].at("bit164");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_FC159                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_FC130                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_FC130");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_FC143                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_FC129                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_FC181                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_FC190                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_FC229                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_FC232                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA1_SFD5_FC138                            =m_inputs_map[ska_num][FDS1].at("D_OA1_SFD5_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit174                                      =m_inputs_map[ska_num][FDS1].at("bit174");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit175                                      =m_inputs_map[ska_num][FDS1].at("bit175");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA2_SFD1_Smoke_alarm                      =m_inputs_map[ska_num][FDS1].at("S_OA2_SFD1_Smoke_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA2_SFD1_Heat_alarm                       =m_inputs_map[ska_num][FDS1].at("S_OA2_SFD1_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_Disconnection                    =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_FC128                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit180                                      =m_inputs_map[ska_num][FDS1].at("bit180");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_FC159                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_FC130                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_FC130");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_FC143                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_FC129                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_FC181                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_FC190                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_FC229                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_FC232                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD1_FC138                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD1_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit190                                      =m_inputs_map[ska_num][FDS1].at("bit190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit191                                      =m_inputs_map[ska_num][FDS1].at("bit191");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA2_SFD2_Smoke_alarm                      =m_inputs_map[ska_num][FDS1].at("S_OA2_SFD2_Smoke_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA2_SFD2_Heat_alarm                       =m_inputs_map[ska_num][FDS1].at("S_OA2_SFD2_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_Disconnection                    =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_FC128                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit196                                      =m_inputs_map[ska_num][FDS1].at("bit196");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_FC159                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_FC130                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_FC130");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_FC143                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_FC129                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_FC181                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_FC190                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_FC229                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_FC232                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD2_FC138                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD2_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit206                                      =m_inputs_map[ska_num][FDS1].at("bit206");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit207                                      =m_inputs_map[ska_num][FDS1].at("bit207");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA2_SFD3_Smoke_alarm                      =m_inputs_map[ska_num][FDS1].at("S_OA2_SFD3_Smoke_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA2_SFD3_Heat_alarm                       =m_inputs_map[ska_num][FDS1].at("S_OA2_SFD3_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_Disconnection                    =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_FC128                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit212                                      =m_inputs_map[ska_num][FDS1].at("bit212");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_FC159                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_FC130                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_FC130");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_FC143                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_FC129                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_FC181                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_FC190                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_FC229                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_FC232                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD3_FC138                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD3_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit222                                      =m_inputs_map[ska_num][FDS1].at("bit222");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit223                                      =m_inputs_map[ska_num][FDS1].at("bit223");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA2_SFD4_Smoke_alarm                      =m_inputs_map[ska_num][FDS1].at("S_OA2_SFD4_Smoke_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.S_OA2_SFD4_Heat_alarm                       =m_inputs_map[ska_num][FDS1].at("S_OA2_SFD4_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_Disconnection                    =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_FC128                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit228                                      =m_inputs_map[ska_num][FDS1].at("bit228");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_FC159                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_FC130                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_FC130");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_FC143                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_FC129                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_FC181                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_FC190                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_FC229                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_FC232                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.D_OA2_SFD4_FC138                            =m_inputs_map[ska_num][FDS1].at("D_OA2_SFD4_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit238                                      =m_inputs_map[ska_num][FDS1].at("bit238");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.bit239                                      =m_inputs_map[ska_num][FDS1].at("bit239");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.reserved_30                                 =m_inputs_map[ska_num][FDS1].at("reserved_30");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bits.reserved_31                                 =m_inputs_map[ska_num][FDS1].at("reserved_31");


}



void SKA_FDS::init_ska_x_fds1_table(SKA_VEHICLE_NUM vehicle_type)
{
    int ska_num = static_cast<int>(vehicle_type);
    m_inputs_map[ska_num][FDS1] = {
        {"S_FDCU_Master", 0},
        {"S_FDCU_General_fire", 0},
        {"S_FDCU_Unmuted_fire_alarm", 0},
        {"S_FDCU_Fire_fault_reset_feedback_RPDO", 0},
        {"S_FDCU_General_fault", 0},
        {"S_FDCU_Unmuted_fault_alarm", 0},
        {"S_FDCU_Prealarm", 0},
        {"S_FDCU_Resound_alarm_feedback_RPDO", 0},
        {"reserved1", 0},
        {"S_SKA1_SFD1_Smoke_alarm", 0},
        {"S_SKA1_SFD1_Heat_alarm", 0},
        {"D_SKA1_SFD1_Disconnection", 0},
        {"D_SKA1_SFD1_FC128", 0},
        {"bit20", 0},
        {"D_SKA1_SFD1_FC159", 0},
        {"D_SKA1_SFD1_FC130", 0},
        {"D_SKA1_SFD1_FC143", 0},
        {"D_SKA1_SFD1_FC129", 0},
        {"D_SKA1_SFD1_FC181", 0},
        {"D_SKA1_SFD1_FC190", 0},
        {"D_SKA1_SFD1_FC229", 0},
        {"D_SKA1_SFD1_FC232", 0},
        {"D_SKA1_SFD1_FC138", 0},
        {"bit30", 0},
        {"bit31", 0},
        {"S_SKA1_SFD2_Smoke_alarm", 0},
        {"S_SKA1_SFD2_Heat_alarm", 0},
        {"D_SKA1_SFD2_Disconnection", 0},
        {"D_SKA1_SFD2_FC128", 0},
        {"bit36", 0},
        {"D_SKA1_SFD2_FC159", 0},
        {"D_SKA1_SFD2_FC130", 0},
        {"D_SKA1_SFD2_FC143", 0},
        {"D_SKA1_SFD2_FC129", 0},
        {"D_SKA1_SFD2_FC181", 0},
        {"D_SKA1_SFD2_FC190", 0},
        {"D_SKA1_SFD2_FC229", 0},
        {"D_SKA1_SFD2_FC232", 0},
        {"D_SKA1_SFD2_FC138", 0},
        {"bit46", 0},
        {"bit47", 0},
        {"S_SKA1_SFD3_Smoke_alarm", 0},
        {"S_SKA1_SFD3_Heat_alarm", 0},
        {"D_SKA1_SFD3_Disconnection", 0},
        {"D_SKA1_SFD3_FC128", 0},
        {"bit52", 0},
        {"D_SKA1_SFD3_FC159", 0},
        {"D_SKA1_SFD3_FC130", 0},
        {"D_SKA1_SFD3_FC143", 0},
        {"D_SKA1_SFD3_FC129", 0},
        {"D_SKA1_SFD3_FC181", 0},
        {"D_SKA1_SFD3_FC190", 0},
        {"D_SKA1_SFD3_FC229", 0},
        {"D_SKA1_SFD3_FC232", 0},
        {"D_SKA1_SFD3_FC138", 0},
        {"bit62", 0},
        {"bit63", 0},
        {"S_SKA1_SFD4_Smoke_alarm", 0},
        {"S_SKA1_SFD4_Heat_alarm", 0},
        {"D_SKA1_SFD4_Disconnection", 0},
        {"D_SKA1_SFD4_FC128", 0},
        {"bit68", 0},
        {"D_SKA1_SFD4_FC159", 0},
        {"D_SKA1_SFD4_FC130", 0},
        {"D_SKA1_SFD4_FC143", 0},
        {"D_SKA1_SFD4_FC129", 0},
        {"D_SKA1_SFD4_FC181", 0},
        {"D_SKA1_SFD4_FC190", 0},
        {"D_SKA1_SFD4_FC229", 0},
        {"D_SKA1_SFD4_FC232", 0},
        {"D_SKA1_SFD4_FC138", 0},
        {"bit78", 0},
        {"bit79", 0},
        {"S_SKA1_SFD5_Smoke_alarm", 0},
        {"S_SKA1_SFD5_Heat_alarm", 0},
        {"D_SKA1_SFD5_Disconnection", 0},
        {"D_SKA1_SFD5_FC128", 0},
        {"bit84", 0},
        {"D_SKA1_SFD5_FC159", 0},
        {"D_SKA1_SFD5_FC130", 0},
        {"D_SKA1_SFD5_FC143", 0},
        {"D_SKA1_SFD5_FC129", 0},
        {"D_SKA1_SFD5_FC181", 0},
        {"D_SKA1_SFD5_FC190", 0},
        {"D_SKA1_SFD5_FC229", 0},
        {"D_SKA1_SFD5_FC232", 0},
        {"D_SKA1_SFD5_FC138", 0},
        {"bit94", 0},
        {"bit95", 0},
        {"S_OA1_SFD1_Smoke_alarm", 0},
        {"S_OA1_SFD1_Heat_alarm", 0},
        {"D_OA1_SFD1_Disconnection", 0},
        {"D_OA1_SFD1_FC128", 0},
        {"bit100", 0},
        {"D_OA1_SFD1_FC159", 0},
        {"D_OA1_SFD1_FC130", 0},
        {"D_OA1_SFD1_FC143", 0},
        {"D_OA1_SFD1_FC129", 0},
        {"D_OA1_SFD1_FC181", 0},
        {"D_OA1_SFD1_FC190", 0},
        {"D_OA1_SFD1_FC229", 0},
        {"D_OA1_SFD1_FC232", 0},
        {"D_OA1_SFD1_FC138", 0},
        {"bit110", 0},
        {"bit111", 0},
        {"S_OA1_SFD2_Smoke_alarm", 0},
        {"S_OA1_SFD2_Heat_alarm", 0},
        {"D_OA1_SFD2_Disconnection", 0},
        {"D_OA1_SFD2_FC128", 0},
        {"bit116", 0},
        {"D_OA1_SFD2_FC159", 0},
        {"D_OA1_SFD2_FC130", 0},
        {"D_OA1_SFD2_FC143", 0},
        {"D_OA1_SFD2_FC129", 0},
        {"D_OA1_SFD2_FC181", 0},
        {"D_OA1_SFD2_FC190", 0},
        {"D_OA1_SFD2_FC229", 0},
        {"D_OA1_SFD2_FC232", 0},
        {"D_OA1_SFD2_FC138", 0},
        {"bit126", 0},
        {"bit127", 0},
        {"S_OA1_SFD3_Smoke_alarm", 0},
        {"S_OA1_SFD3_Heat_alarm", 0},
        {"D_OA1_SFD3_Disconnection", 0},
        {"D_OA1_SFD3_FC128", 0},
        {"bit132", 0},
        {"D_OA1_SFD3_FC159", 0},
        {"D_OA1_SFD3_FC130", 0},
        {"D_OA1_SFD3_FC143", 0},
        {"D_OA1_SFD3_FC129", 0},
        {"D_OA1_SFD3_FC181", 0},
        {"D_OA1_SFD3_FC190", 0},
        {"D_OA1_SFD3_FC229", 0},
        {"D_OA1_SFD3_FC232", 0},
        {"D_OA1_SFD3_FC138", 0},
        {"bit142", 0},
        {"bit143", 0},
        {"S_OA1_SFD4_Smoke_alarm", 0},
        {"S_OA1_SFD4_Heat_alarm", 0},
        {"D_OA1_SFD4_Disconnection", 0},
        {"D_OA1_SFD4_FC128", 0},
        {"bit148", 0},
        {"D_OA1_SFD4_FC159", 0},
        {"D_OA1_SFD4_FC130", 0},
        {"D_OA1_SFD4_FC143", 0},
        {"D_OA1_SFD4_FC129", 0},
        {"D_OA1_SFD4_FC181", 0},
        {"D_OA1_SFD4_FC190", 0},
        {"D_OA1_SFD4_FC229", 0},
        {"D_OA1_SFD4_FC232", 0},
        {"D_OA1_SFD4_FC138", 0},
        {"bit158", 0},
        {"bit159", 0},
        {"S_OA1_SFD5_Smoke_alarm", 0},
        {"S_OA1_SFD5_Heat_alarm", 0},
        {"D_OA1_SFD5_Disconnection", 0},
        {"D_OA1_SFD5_FC128", 0},
        {"bit164", 0},
        {"D_OA1_SFD5_FC159", 0},
        {"D_OA1_SFD5_FC130", 0},
        {"D_OA1_SFD5_FC143", 0},
        {"D_OA1_SFD5_FC129", 0},
        {"D_OA1_SFD5_FC181", 0},
        {"D_OA1_SFD5_FC190", 0},
        {"D_OA1_SFD5_FC229", 0},
        {"D_OA1_SFD5_FC232", 0},
        {"D_OA1_SFD5_FC138", 0},
        {"bit174", 0},
        {"bit175", 0},
        {"S_OA2_SFD1_Smoke_alarm", 0},
        {"S_OA2_SFD1_Heat_alarm", 0},
        {"D_OA2_SFD1_Disconnection", 0},
        {"D_OA2_SFD1_FC128", 0},
        {"bit180", 0},
        {"D_OA2_SFD1_FC159", 0},
        {"D_OA2_SFD1_FC130", 0},
        {"D_OA2_SFD1_FC143", 0},
        {"D_OA2_SFD1_FC129", 0},
        {"D_OA2_SFD1_FC181", 0},
        {"D_OA2_SFD1_FC190", 0},
        {"D_OA2_SFD1_FC229", 0},
        {"D_OA2_SFD1_FC232", 0},
        {"D_OA2_SFD1_FC138", 0},
        {"bit190", 0},
        {"bit191", 0},
        {"S_OA2_SFD2_Smoke_alarm", 0},
        {"S_OA2_SFD2_Heat_alarm", 0},
        {"D_OA2_SFD2_Disconnection", 0},
        {"D_OA2_SFD2_FC128", 0},
        {"bit196", 0},
        {"D_OA2_SFD2_FC159", 0},
        {"D_OA2_SFD2_FC130", 0},
        {"D_OA2_SFD2_FC143", 0},
        {"D_OA2_SFD2_FC129", 0},
        {"D_OA2_SFD2_FC181", 0},
        {"D_OA2_SFD2_FC190", 0},
        {"D_OA2_SFD2_FC229", 0},
        {"D_OA2_SFD2_FC232", 0},
        {"D_OA2_SFD2_FC138", 0},
        {"bit206", 0},
        {"bit207", 0},
        {"S_OA2_SFD3_Smoke_alarm", 0},
        {"S_OA2_SFD3_Heat_alarm", 0},
        {"D_OA2_SFD3_Disconnection", 0},
        {"D_OA2_SFD3_FC128", 0},
        {"bit212", 0},
        {"D_OA2_SFD3_FC159", 0},
        {"D_OA2_SFD3_FC130", 0},
        {"D_OA2_SFD3_FC143", 0},
        {"D_OA2_SFD3_FC129", 0},
        {"D_OA2_SFD3_FC181", 0},
        {"D_OA2_SFD3_FC190", 0},
        {"D_OA2_SFD3_FC229", 0},
        {"D_OA2_SFD3_FC232", 0},
        {"D_OA2_SFD3_FC138", 0},
        {"bit222", 0},
        {"bit223", 0},
        {"S_OA2_SFD4_Smoke_alarm", 0},
        {"S_OA2_SFD4_Heat_alarm", 0},
        {"D_OA2_SFD4_Disconnection", 0},
        {"D_OA2_SFD4_FC128", 0},
        {"bit228", 0},
        {"D_OA2_SFD4_FC159", 0},
        {"D_OA2_SFD4_FC130", 0},
        {"D_OA2_SFD4_FC143", 0},
        {"D_OA2_SFD4_FC129", 0},
        {"D_OA2_SFD4_FC181", 0},
        {"D_OA2_SFD4_FC190", 0},
        {"D_OA2_SFD4_FC229", 0},
        {"D_OA2_SFD4_FC232", 0},
        {"D_OA2_SFD4_FC138", 0},
        {"bit238", 0},
        {"bit239", 0},
        {"reserved_30", 0},
        {"reserved_31", 0}

    };

    /*m_tableWidget[ska_num][FDS1] = new QTableWidget();
    m_tableWidget[ska_num][FDS1]->setColumnCount(2);
    m_tableWidget[ska_num][FDS1]->setRowCount(m_inputs_map[ska_num][FDS1].size());
    m_tableWidget[ska_num][FDS1]->setHorizontalHeaderLabels(table_name[ska_num][FDS1]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[ska_num][FDS1]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[ska_num][FDS1]->setItem(row, 0, item_name);
        m_tableWidget[ska_num][FDS1]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[ska_num][FDS1]->resizeColumnsToContents();*/


    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[ska_num][FDS1].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[ska_num][FDS1] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[ska_num][FDS1]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[ska_num][FDS1]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[ska_num][FDS1]->setItem(row, column, item_name);
        m_tableWidget[ska_num][FDS1]->setItem(row, column + 1, item_val); // Değer

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[ska_num][FDS1]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][FDS1]->columnCount() ;
}

void SKA_FDS::init_ska_x_fds2_table(SKA_VEHICLE_NUM vehicle_type)
{
    int ska_num = static_cast<int>(vehicle_type);
    m_inputs_map[ska_num][FDS2] = {
        {"S_OA2_SFD5_Smoke_alarm", 0},
        {"S_OA2_SFD5_Heat_alarm", 0},
        {"D_OA2_SFD5_Disconnection", 0},
        {"D_OA2_SFD5_FC128", 0},
        {"bit4", 0},
        {"D_OA2_SFD5_FC159", 0},
        {"D_OA2_SFD5_FC130", 0},
        {"D_OA2_SFD5_FC143", 0},
        {"D_OA2_SFD5_FC129", 0},
        {"D_OA2_SFD5_FC181", 0},
        {"D_OA2_SFD5_FC190", 0},
        {"D_OA2_SFD5_FC229", 0},
        {"D_OA2_SFD5_FC232", 0},
        {"D_OA2_SFD5_FC138", 0},
        {"bit14", 0},
        {"bit15", 0},
        {"S_SKA2_SFD1_Smoke_alarm", 0},
        {"S_SKA2_SFD1_Heat_alarm", 0},
        {"D_SKA2_SFD1_Disconnection", 0},
        {"D_SKA2_SFD1_FC128", 0},
        {"bit20", 0},
        {"D_SKA2_SFD1_FC159", 0},
        {"D_SKA2_SFD1_FC130", 0},
        {"D_SKA2_SFD1_FC143", 0},
        {"D_SKA2_SFD1_FC129", 0},
        {"D_SKA2_SFD1_FC181", 0},
        {"D_SKA2_SFD1_FC190", 0},
        {"D_SKA2_SFD1_FC229", 0},
        {"D_SKA2_SFD1_FC232", 0},
        {"D_SKA2_SFD1_FC138", 0},
        {"bit30", 0},
        {"bit31", 0},
        {"S_SKA2_SFD2_Smoke_alarm", 0},
        {"S_SKA2_SFD2_Heat_alarm", 0},
        {"D_SKA2_SFD2_Disconnection", 0},
        {"D_SKA2_SFD2_FC128", 0},
        {"bit36", 0},
        {"D_SKA2_SFD2_FC159", 0},
        {"D_SKA2_SFD2_FC130", 0},
        {"D_SKA2_SFD2_FC143", 0},
        {"D_SKA2_SFD2_FC129", 0},
        {"D_SKA2_SFD2_FC181", 0},
        {"D_SKA2_SFD2_FC190", 0},
        {"D_SKA2_SFD2_FC229", 0},
        {"D_SKA2_SFD2_FC232", 0},
        {"D_SKA2_SFD2_FC138", 0},
        {"bit46", 0},
        {"bit47", 0},
        {"S_SKA2_SFD3_Smoke_alarm", 0},
        {"S_SKA2_SFD3_Heat_alarm", 0},
        {"D_SKA2_SFD3_Disconnection", 0},
        {"D_SKA2_SFD3_FC128", 0},
        {"bit52", 0},
        {"D_SKA2_SFD3_FC159", 0},
        {"D_SKA2_SFD3_FC130", 0},
        {"D_SKA2_SFD3_FC143", 0},
        {"D_SKA2_SFD3_FC129", 0},
        {"D_SKA2_SFD3_FC181", 0},
        {"D_SKA2_SFD3_FC190", 0},
        {"D_SKA2_SFD3_FC229", 0},
        {"D_SKA2_SFD3_FC232", 0},
        {"D_SKA2_SFD3_FC138", 0},
        {"bit62", 0},
        {"bit63", 0},
        {"S_SKA2_SFD4_Smoke_alarm", 0},
        {"S_SKA2_SFD4_Heat_alarm", 0},
        {"D_SKA2_SFD4_Disconnection", 0},
        {"D_SKA2_SFD4_FC128", 0},
        {"bit68", 0},
        {"D_SKA2_SFD4_FC159", 0},
        {"D_SKA2_SFD4_FC130", 0},
        {"D_SKA2_SFD4_FC143", 0},
        {"D_SKA2_SFD4_FC129", 0},
        {"D_SKA2_SFD4_FC181", 0},
        {"D_SKA2_SFD4_FC190", 0},
        {"D_SKA2_SFD4_FC229", 0},
        {"D_SKA2_SFD4_FC232", 0},
        {"D_SKA2_SFD4_FC138", 0},
        {"bit78", 0},
        {"bit79", 0},
        {"S_SKA2_SFD5_Smoke_alarm", 0},
        {"S_SKA2_SFD5_Heat_alarm", 0},
        {"D_SKA2_SFD5_Disconnection", 0},
        {"D_SKA2_SFD5_FC128", 0},
        {"bit84", 0},
        {"D_SKA2_SFD5_FC159", 0},
        {"D_SKA2_SFD5_FC130", 0},
        {"D_SKA2_SFD5_FC143", 0},
        {"D_SKA2_SFD5_FC129", 0},
        {"D_SKA2_SFD5_FC181", 0},
        {"D_SKA2_SFD5_FC190", 0},
        {"D_SKA2_SFD5_FC229", 0},
        {"D_SKA2_SFD5_FC232", 0},
        {"D_SKA2_SFD5_FC138", 0},
        {"bit94", 0},
        {"bit95", 0},
        {"bit96", 0},
        {"S_SKA1_CS_IC22_1_Heat_alarm", 0},
        {"D_SKA1_CS_IC22_1_Disconnection", 0},
        {"D_SKA1_CS_IC22_1_FC128", 0},
        {"D_SKA1_CS_IC22_1_FC149", 0},
        {"D_SKA1_CS_IC22_1_FC159", 0},
        {"D_SKA1_CS_IC22_1_FC143", 0},
        {"D_SKA1_CS_IC22_1_FC129", 0},
        {"D_SKA1_CS_IC22_1_FC137", 0},
        {"D_SKA1_CS_IC22_1_FC181", 0},
        {"D_SKA1_CS_IC22_1_FC190", 0},
        {"D_SKA1_CS_IC22_1_FC229", 0},
        {"D_SKA1_CS_IC22_1_FC232", 0},
        {"D_SKA1_CS_IC22_1_FC233", 0},
        {"D_SKA1_CS_IC22_1_FC138", 0},
        {"bit111", 0},
        {"bit112", 0},
        {"S_SKA1_CS_IC22_2_Heat_alarm", 0},
        {"D_SKA1_CS_IC22_2_Disconnection", 0},
        {"D_SKA1_CS_IC22_2_FC128", 0},
        {"D_SKA1_CS_IC22_2_FC149", 0},
        {"D_SKA1_CS_IC22_2_FC159", 0},
        {"D_SKA1_CS_IC22_2_FC143", 0},
        {"D_SKA1_CS_IC22_2_FC129", 0},
        {"D_SKA1_CS_IC22_2_FC137", 0},
        {"D_SKA1_CS_IC22_2_FC181", 0},
        {"D_SKA1_CS_IC22_2_FC190", 0},
        {"D_SKA1_CS_IC22_2_FC229", 0},
        {"D_SKA1_CS_IC22_2_FC232", 0},
        {"D_SKA1_CS_IC22_2_FC233", 0},
        {"D_SKA1_CS_IC22_2_FC138", 0},
        {"bit127", 0},
        {"bit128", 0},
        {"S_SKA1_CS_IC22_3_Heat_alarm", 0},
        {"D_SKA1_CS_IC22_3_Disconnection", 0},
        {"D_SKA1_CS_IC22_3_FC128", 0},
        {"D_SKA1_CS_IC22_3_FC149", 0},
        {"D_SKA1_CS_IC22_3_FC159", 0},
        {"D_SKA1_CS_IC22_3_FC143", 0},
        {"D_SKA1_CS_IC22_3_FC129", 0},
        {"D_SKA1_CS_IC22_3_FC137", 0},
        {"D_SKA1_CS_IC22_3_FC181", 0},
        {"D_SKA1_CS_IC22_3_FC190", 0},
        {"D_SKA1_CS_IC22_3_FC229", 0},
        {"D_SKA1_CS_IC22_3_FC232", 0},
        {"D_SKA1_CS_IC22_3_FC233", 0},
        {"D_SKA1_CS_IC22_3_FC138", 0},
        {"bit143", 0},
        {"bit144", 0},
        {"S_OA1_CS_IC22_1_Heat_alarm", 0},
        {"D_OA1_CS_IC22_1_Disconnection", 0},
        {"D_OA1_CS_IC22_1_FC128", 0},
        {"D_OA1_CS_IC22_1_FC149", 0},
        {"D_OA1_CS_IC22_1_FC159", 0},
        {"D_OA1_CS_IC22_1_FC143", 0},
        {"D_OA1_CS_IC22_1_FC129", 0},
        {"D_OA1_CS_IC22_1_FC137", 0},
        {"D_OA1_CS_IC22_1_FC181", 0},
        {"D_OA1_CS_IC22_1_FC190", 0},
        {"D_OA1_CS_IC22_1_FC229", 0},
        {"D_OA1_CS_IC22_1_FC232", 0},
        {"D_OA1_CS_IC22_1_FC233", 0},
        {"D_OA1_CS_IC22_1_FC138", 0},
        {"bit159", 0},
        {"bit160", 0},
        {"S_OA1_CS_IC22_2_Heat_alarm", 0},
        {"D_OA1_CS_IC22_2_Disconnection", 0},
        {"D_OA1_CS_IC22_2_FC128", 0},
        {"D_OA1_CS_IC22_2_FC149", 0},
        {"D_OA1_CS_IC22_2_FC159", 0},
        {"D_OA1_CS_IC22_2_FC143", 0},
        {"D_OA1_CS_IC22_2_FC129", 0},
        {"D_OA1_CS_IC22_2_FC137", 0},
        {"D_OA1_CS_IC22_2_FC181", 0},
        {"D_OA1_CS_IC22_2_FC190", 0},
        {"D_OA1_CS_IC22_2_FC229", 0},
        {"D_OA1_CS_IC22_2_FC232", 0},
        {"D_OA1_CS_IC22_2_FC233", 0},
        {"D_OA1_CS_IC22_2_FC138", 0},
        {"bit175", 0},
        {"bit176", 0},
        {"S_OA1_CS_IC22_3_Heat_alarm", 0},
        {"D_OA1_CS_IC22_3_Disconnection", 0},
        {"D_OA1_CS_IC22_3_FC128", 0},
        {"D_OA1_CS_IC22_3_FC149", 0},
        {"D_OA1_CS_IC22_3_FC159", 0},
        {"D_OA1_CS_IC22_3_FC143", 0},
        {"D_OA1_CS_IC22_3_FC129", 0},
        {"D_OA1_CS_IC22_3_FC137", 0},
        {"D_OA1_CS_IC22_3_FC181", 0},
        {"D_OA1_CS_IC22_3_FC190", 0},
        {"D_OA1_CS_IC22_3_FC229", 0},
        {"D_OA1_CS_IC22_3_FC232", 0},
        {"D_OA1_CS_IC22_3_FC233", 0},
        {"D_OA1_CS_IC22_3_FC138", 0},
        {"bit191", 0},
        {"bit192", 0},
        {"S_OA2_CS_IC22_1_Heat_alarm", 0},
        {"D_OA2_CS_IC22_1_Disconnection", 0},
        {"D_OA2_CS_IC22_1_FC128", 0},
        {"D_OA2_CS_IC22_1_FC149", 0},
        {"D_OA2_CS_IC22_1_FC159", 0},
        {"D_OA2_CS_IC22_1_FC143", 0},
        {"D_OA2_CS_IC22_1_FC129", 0},
        {"D_OA2_CS_IC22_1_FC137", 0},
        {"D_OA2_CS_IC22_1_FC181", 0},
        {"D_OA2_CS_IC22_1_FC190", 0},
        {"D_OA2_CS_IC22_1_FC229", 0},
        {"D_OA2_CS_IC22_1_FC232", 0},
        {"D_OA2_CS_IC22_1_FC233", 0},
        {"D_OA2_CS_IC22_1_FC138", 0},
        {"bit207", 0},
        {"bit208", 0},
        {"S_OA2_CS_IC22_2_Heat_alarm", 0},
        {"D_OA2_CS_IC22_2_Disconnection", 0},
        {"D_OA2_CS_IC22_2_FC128", 0},
        {"D_OA2_CS_IC22_2_FC149", 0},
        {"D_OA2_CS_IC22_2_FC159", 0},
        {"D_OA2_CS_IC22_2_FC143", 0},
        {"D_OA2_CS_IC22_2_FC129", 0},
        {"D_OA2_CS_IC22_2_FC137", 0},
        {"D_OA2_CS_IC22_2_FC181", 0},
        {"D_OA2_CS_IC22_2_FC190", 0},
        {"D_OA2_CS_IC22_2_FC229", 0},
        {"D_OA2_CS_IC22_2_FC232", 0},
        {"D_OA2_CS_IC22_2_FC233", 0},
        {"D_OA2_CS_IC22_2_FC138", 0},
        {"bit223", 0},
        {"bit224", 0},
        {"S_OA2_CS_IC22_3_Heat_alarm", 0},
        {"D_OA2_CS_IC22_3_Disconnection", 0},
        {"D_OA2_CS_IC22_3_FC128", 0},
        {"D_OA2_CS_IC22_3_FC149", 0},
        {"D_OA2_CS_IC22_3_FC159", 0},
        {"D_OA2_CS_IC22_3_FC143", 0},
        {"D_OA2_CS_IC22_3_FC129", 0},
        {"D_OA2_CS_IC22_3_FC137", 0},
        {"D_OA2_CS_IC22_3_FC181", 0},
        {"D_OA2_CS_IC22_3_FC190", 0},
        {"D_OA2_CS_IC22_3_FC229", 0},
        {"D_OA2_CS_IC22_3_FC232", 0},
        {"D_OA2_CS_IC22_3_FC233", 0},
        {"D_OA2_CS_IC22_3_FC138", 0},
        {"bit239", 0},
        {"reserved_30", 0},
        {"reserved_31", 0}
    };

    /*m_tableWidget[ska_num][FDS2] = new QTableWidget();
    m_tableWidget[ska_num][FDS2]->setColumnCount(2);
    m_tableWidget[ska_num][FDS2]->setRowCount(m_inputs_map[ska_num][FDS2].size());
    m_tableWidget[ska_num][FDS2]->setHorizontalHeaderLabels(table_name[ska_num][FDS2]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[ska_num][FDS2]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[ska_num][FDS2]->setItem(row, 0, item_name);
        m_tableWidget[ska_num][FDS2]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[ska_num][FDS2]->resizeColumnsToContents();*/

    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[ska_num][FDS2].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[ska_num][FDS2] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[ska_num][FDS2]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[ska_num][FDS2]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[ska_num][FDS2]->setItem(row, column, item_name);
        m_tableWidget[ska_num][FDS2]->setItem(row, column + 1, item_val); // Değer

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[ska_num][FDS2]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][FDS2]->columnCount() ;
}


void SKA_FDS::update_fds2_map(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_inputs_map[ska_num][FDS2].at("S_OA2_SFD5_Smoke_alarm")    =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_OA2_SFD5_Smoke_alarm             ;
    m_inputs_map[ska_num][FDS2].at("S_OA2_SFD5_Heat_alarm")     =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_OA2_SFD5_Heat_alarm              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_Disconnection")  =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_Disconnection           ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_FC128 ")         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_FC128                   ;
    m_inputs_map[ska_num][FDS2].at("bit4")                      =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit4                               ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_FC159")          =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_FC159                   ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_FC130")          =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_FC130                   ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_FC143")          =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_FC143                   ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_FC129")          =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_FC129                   ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_FC181")          =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_FC181                   ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_FC190")          =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_FC190                   ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_FC229")          =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_FC229                   ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_FC232")          =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_FC232                   ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_FC138")          =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_FC138                   ;
    m_inputs_map[ska_num][FDS2].at("bit14")                     =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit14                              ;
    m_inputs_map[ska_num][FDS2].at("bit15")                     =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit15                              ;
    m_inputs_map[ska_num][FDS2].at("S_SKA2_SFD1_Smoke_alarm")   =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA2_SFD1_Smoke_alarm            ;
    m_inputs_map[ska_num][FDS2].at("S_SKA2_SFD1_Heat_alarm")    =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA2_SFD1_Heat_alarm             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_Disconnection") =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_Disconnection          ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_FC128")         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_FC128                  ;
    m_inputs_map[ska_num][FDS2].at("bit20")                     =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit20                              ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_FC159")         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_FC159                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_FC130")         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_FC130                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_FC143")         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_FC143                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_FC129")         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_FC129                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_FC181")         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_FC181                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_FC190")         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_FC190                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_FC229")         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_FC229                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_FC232")         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_FC232                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_FC138")         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_FC138                  ;
    m_inputs_map[ska_num][FDS2].at("bit30")                     =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit30                              ;
    m_inputs_map[ska_num][FDS2].at("bit31")                     =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit31                              ;
    m_inputs_map[ska_num][FDS2].at("S_SKA2_SFD2_Smoke_alarm")   =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA2_SFD2_Smoke_alarm            ;
    m_inputs_map[ska_num][FDS2].at("S_SKA2_SFD2_Heat_alarm")    =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA2_SFD2_Heat_alarm             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_Disconnection") =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_Disconnection          ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_FC128")         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_FC128                  ;
    m_inputs_map[ska_num][FDS2].at("bit36")                     =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit36                              ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_FC159                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_FC130")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_FC130                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_FC143                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_FC129                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_FC181                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_FC190                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_FC229                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_FC232                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_FC138                  ;
    m_inputs_map[ska_num][FDS2].at("bit46")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit46                              ;
    m_inputs_map[ska_num][FDS2].at("bit47")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit47                              ;
    m_inputs_map[ska_num][FDS2].at("S_SKA2_SFD3_Smoke_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA2_SFD3_Smoke_alarm            ;
    m_inputs_map[ska_num][FDS2].at("S_SKA2_SFD3_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA2_SFD3_Heat_alarm             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_Disconnection          ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_FC128                  ;
    m_inputs_map[ska_num][FDS2].at("bit52")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit52                              ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_FC159                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_FC130")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_FC130                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_FC143                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_FC129                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_FC181                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_FC190                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_FC229                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_FC232                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_FC138                  ;
    m_inputs_map[ska_num][FDS2].at("bit62")             =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit62                              ;
    m_inputs_map[ska_num][FDS2].at("bit63")             =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit63                              ;
    m_inputs_map[ska_num][FDS2].at("S_SKA2_SFD4_Smoke_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA2_SFD4_Smoke_alarm            ;
    m_inputs_map[ska_num][FDS2].at("S_SKA2_SFD4_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA2_SFD4_Heat_alarm             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_Disconnection          ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_FC128                  ;
    m_inputs_map[ska_num][FDS2].at("bit68")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit68                              ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_FC159                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_FC130")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_FC130                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_FC143                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_FC129                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_FC181                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_FC190                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_FC229                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_FC232                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_FC138                  ;
    m_inputs_map[ska_num][FDS2].at("bit78")             =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit78                              ;
    m_inputs_map[ska_num][FDS2].at("bit79")             =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit79                              ;
    m_inputs_map[ska_num][FDS2].at("S_SKA2_SFD5_Smoke_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA2_SFD5_Smoke_alarm            ;
    m_inputs_map[ska_num][FDS2].at("S_SKA2_SFD5_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA2_SFD5_Heat_alarm             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_Disconnection          ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_FC128                  ;
    m_inputs_map[ska_num][FDS2].at("bit84")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit84                              ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_FC159                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_FC130")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_FC130                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_FC143                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_FC129                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_FC181                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_FC190                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_FC229                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_FC232                  ;
    m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_FC138                  ;
    m_inputs_map[ska_num][FDS2].at("bit94")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit94                              ;
    m_inputs_map[ska_num][FDS2].at("bit95")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit95                              ;
    m_inputs_map[ska_num][FDS2].at("bit96")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit96                              ;
    m_inputs_map[ska_num][FDS2].at("S_SKA1_CS_IC22_1_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA1_CS_IC22_1_Heat_alarm        ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_Disconnection     ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC128             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC149")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC149             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC159             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC143             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC129             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC137")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC137             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC181             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC190             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC229             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC232             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC233")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC233             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC138             ;
    m_inputs_map[ska_num][FDS2].at("bit111")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit111                             ;
    m_inputs_map[ska_num][FDS2].at("bit112")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit112                             ;
    m_inputs_map[ska_num][FDS2].at("S_SKA1_CS_IC22_2_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA1_CS_IC22_2_Heat_alarm        ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_Disconnection     ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC128             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC149")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC149             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC159             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC143             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC129             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC137")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC137             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC181             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC190             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC229             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC232             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC233")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC233             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC138             ;
    m_inputs_map[ska_num][FDS2].at("bit127")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit127                             ;
    m_inputs_map[ska_num][FDS2].at("bit128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit128                             ;
    m_inputs_map[ska_num][FDS2].at("S_SKA1_CS_IC22_3_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA1_CS_IC22_3_Heat_alarm        ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_Disconnection     ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC128             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC149")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC149             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC159             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC143             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC129             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC137")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC137             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC181             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC190             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC229             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC232             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC233")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC233             ;
    m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC138             ;
    m_inputs_map[ska_num][FDS2].at("bit143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit143                             ;
    m_inputs_map[ska_num][FDS2].at("bit144")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit144                             ;
    m_inputs_map[ska_num][FDS2].at("S_OA1_CS_IC22_1_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_OA1_CS_IC22_1_Heat_alarm         ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_Disconnection      ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC128              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC149")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC149              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC159              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC143              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC129              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC137")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC137              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC181              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC190              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC229              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC232              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC233")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC233              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC138              ;
    m_inputs_map[ska_num][FDS2].at("bit159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit159                             ;
    m_inputs_map[ska_num][FDS2].at("bit160")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit160                             ;
    m_inputs_map[ska_num][FDS2].at("S_OA1_CS_IC22_2_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_OA1_CS_IC22_2_Heat_alarm         ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_Disconnection      ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC128              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC149")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC149              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC159              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC143              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC129              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC137")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC137              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC181              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC190              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC229              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC232              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC233")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC233              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC138              ;
    m_inputs_map[ska_num][FDS2].at("bit175")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit175                             ;
    m_inputs_map[ska_num][FDS2].at("bit176")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit176                             ;
    m_inputs_map[ska_num][FDS2].at("S_OA1_CS_IC22_3_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_OA1_CS_IC22_3_Heat_alarm         ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_Disconnection      ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC128              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC149")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC149              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC159              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC143              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC129              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC137")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC137              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC181              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC190              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC229              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC232              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC233")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC233              ;
    m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC138              ;
    m_inputs_map[ska_num][FDS2].at("bit191")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit191                             ;
    m_inputs_map[ska_num][FDS2].at("bit192")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit192                             ;
    m_inputs_map[ska_num][FDS2].at("S_OA2_CS_IC22_1_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_OA2_CS_IC22_1_Heat_alarm         ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_Disconnection      ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC128              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC149")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC149              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC159              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC143              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC129              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC137")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC137              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC181              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC190              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC229              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC232              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC233")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC233              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC138              ;
    m_inputs_map[ska_num][FDS2].at("bit207")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit207                             ;
    m_inputs_map[ska_num][FDS2].at("bit208")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit208                             ;
    m_inputs_map[ska_num][FDS2].at("S_OA2_CS_IC22_2_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_OA2_CS_IC22_2_Heat_alarm         ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_Disconnection      ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC128              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC149")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC149              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC159              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC143              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC129              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC137")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC137              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC181              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC190              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC229              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC232              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC233")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC233              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC138              ;
    m_inputs_map[ska_num][FDS2].at("bit223")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit223                             ;
    m_inputs_map[ska_num][FDS2].at("bit224")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit224                             ;
    m_inputs_map[ska_num][FDS2].at("S_OA2_CS_IC22_3_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_OA2_CS_IC22_3_Heat_alarm         ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_Disconnection      ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC128              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC149")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC149              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC159              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC143              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC129              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC137")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC137              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC181              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC190              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC229              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC232              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC233")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC233              ;
    m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC138              ;
    m_inputs_map[ska_num][FDS2].at("bit239")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit239                              ;
    m_inputs_map[ska_num][FDS2].at("reserved_30")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.reserved_30                        ;
    m_inputs_map[ska_num][FDS2].at("reserved_31")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.reserved_31                        ;
}



void SKA_FDS::set_struct_fds2(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);


    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_OA2_SFD5_Smoke_alarm              =m_inputs_map[ska_num][FDS2].at("S_OA2_SFD5_Smoke_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_OA2_SFD5_Heat_alarm               =m_inputs_map[ska_num][FDS2].at("S_OA2_SFD5_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_Disconnection            =m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_FC128                    =m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit4                                =m_inputs_map[ska_num][FDS2].at("bit4");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_FC159                    =m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_FC130                    =m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_FC130");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_FC143                    =m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_FC129                    =m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_FC181                    =m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_FC190                    =m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_FC229                    =m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_FC232                    =m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_SFD5_FC138                    =m_inputs_map[ska_num][FDS2].at("D_OA2_SFD5_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit14                               =m_inputs_map[ska_num][FDS2].at("bit14");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit15                               =m_inputs_map[ska_num][FDS2].at("bit15");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA2_SFD1_Smoke_alarm             =m_inputs_map[ska_num][FDS2].at("S_SKA2_SFD1_Smoke_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA2_SFD1_Heat_alarm              =m_inputs_map[ska_num][FDS2].at("S_SKA2_SFD1_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_Disconnection           =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_FC128                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit20                               =m_inputs_map[ska_num][FDS2].at("bit20");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_FC159                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_FC130                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_FC130");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_FC143                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_FC129                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_FC181                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_FC190                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_FC229                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_FC232                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD1_FC138                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD1_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit30                               =m_inputs_map[ska_num][FDS2].at("bit30");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit31                               =m_inputs_map[ska_num][FDS2].at("bit31");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA2_SFD2_Smoke_alarm             =m_inputs_map[ska_num][FDS2].at("S_SKA2_SFD2_Smoke_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA2_SFD2_Heat_alarm              =m_inputs_map[ska_num][FDS2].at("S_SKA2_SFD2_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_Disconnection           =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_FC128                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit36                               =m_inputs_map[ska_num][FDS2].at("bit36");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_FC159                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_FC130                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_FC130");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_FC143                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_FC129                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_FC181                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_FC190                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_FC229                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_FC232                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD2_FC138                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD2_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit46                               =m_inputs_map[ska_num][FDS2].at("bit46");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit47                               =m_inputs_map[ska_num][FDS2].at("bit47");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA2_SFD3_Smoke_alarm             =m_inputs_map[ska_num][FDS2].at("S_SKA2_SFD3_Smoke_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA2_SFD3_Heat_alarm              =m_inputs_map[ska_num][FDS2].at("S_SKA2_SFD3_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_Disconnection           =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_FC128                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit52                               =m_inputs_map[ska_num][FDS2].at("bit52");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_FC159                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_FC130                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_FC130");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_FC143                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_FC129                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_FC181                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_FC190                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_FC229                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_FC232                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD3_FC138                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD3_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit62                               =m_inputs_map[ska_num][FDS2].at("bit62");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit63                               =m_inputs_map[ska_num][FDS2].at("bit63");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA2_SFD4_Smoke_alarm             =m_inputs_map[ska_num][FDS2].at("S_SKA2_SFD4_Smoke_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA2_SFD4_Heat_alarm              =m_inputs_map[ska_num][FDS2].at("S_SKA2_SFD4_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_Disconnection           =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_FC128                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit68                               =m_inputs_map[ska_num][FDS2].at("bit68");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_FC159                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_FC130                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_FC130");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_FC143                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_FC129                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_FC181                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_FC190                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_FC229                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_FC232                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD4_FC138                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD4_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit78                               =m_inputs_map[ska_num][FDS2].at("bit78");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit79                               =m_inputs_map[ska_num][FDS2].at("bit79");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA2_SFD5_Smoke_alarm             =m_inputs_map[ska_num][FDS2].at("S_SKA2_SFD5_Smoke_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA2_SFD5_Heat_alarm              =m_inputs_map[ska_num][FDS2].at("S_SKA2_SFD5_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_Disconnection           =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_FC128                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit84                               =m_inputs_map[ska_num][FDS2].at("bit84");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_FC159                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_FC130                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_FC130");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_FC143                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_FC129                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_FC181                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_FC190                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_FC229                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_FC232                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA2_SFD5_FC138                   =m_inputs_map[ska_num][FDS2].at("D_SKA2_SFD5_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit94                               =m_inputs_map[ska_num][FDS2].at("bit94");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit95                               =m_inputs_map[ska_num][FDS2].at("bit95");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit96                               =m_inputs_map[ska_num][FDS2].at("bit96");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA1_CS_IC22_1_Heat_alarm         =m_inputs_map[ska_num][FDS2].at("S_SKA1_CS_IC22_1_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_Disconnection      =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC128              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC149              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC149");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC159              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC143              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC129              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC137              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC137");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC181              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC190              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC229              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC232              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC233              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC233");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_1_FC138              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_1_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit111                              =m_inputs_map[ska_num][FDS2].at("bit111");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit112                              =m_inputs_map[ska_num][FDS2].at("bit112");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA1_CS_IC22_2_Heat_alarm         =m_inputs_map[ska_num][FDS2].at("S_SKA1_CS_IC22_2_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_Disconnection      =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC128              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC149              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC149");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC159              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC143              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC129              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC137              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC137");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC181              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC190              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC229              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC232              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC233              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC233");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_2_FC138              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_2_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit127                              =m_inputs_map[ska_num][FDS2].at("bit127");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit128                              =m_inputs_map[ska_num][FDS2].at("bit128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_SKA1_CS_IC22_3_Heat_alarm         =m_inputs_map[ska_num][FDS2].at("S_SKA1_CS_IC22_3_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_Disconnection      =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC128              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC149              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC149");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC159              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC143              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC129              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC137              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC137");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC181              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC190              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC229              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC232              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC233              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC233");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_SKA1_CS_IC22_3_FC138              =m_inputs_map[ska_num][FDS2].at("D_SKA1_CS_IC22_3_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit143                              =m_inputs_map[ska_num][FDS2].at("bit143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit144                              =m_inputs_map[ska_num][FDS2].at("bit144");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_OA1_CS_IC22_1_Heat_alarm          =m_inputs_map[ska_num][FDS2].at("S_OA1_CS_IC22_1_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_Disconnection       =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC128               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC149               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC149");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC159               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC143               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC129               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC137               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC137");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC181               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC190               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC229               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC232               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC233               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC233");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_1_FC138               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_1_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit159                              =m_inputs_map[ska_num][FDS2].at("bit159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit160                              =m_inputs_map[ska_num][FDS2].at("bit160");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_OA1_CS_IC22_2_Heat_alarm          =m_inputs_map[ska_num][FDS2].at("S_OA1_CS_IC22_2_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_Disconnection       =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC128               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC149               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC149");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC159               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC143               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC129               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC137               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC137");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC181               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC190               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC229               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC232               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC233               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC233");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_2_FC138               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_2_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit175                              =m_inputs_map[ska_num][FDS2].at("bit175");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit176                              =m_inputs_map[ska_num][FDS2].at("bit176");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_OA1_CS_IC22_3_Heat_alarm          =m_inputs_map[ska_num][FDS2].at("S_OA1_CS_IC22_3_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_Disconnection       =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC128               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC149               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC149");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC159               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC143               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC129               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC137               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC137");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC181               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC190               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC229               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC232               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC233               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC233");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA1_CS_IC22_3_FC138               =m_inputs_map[ska_num][FDS2].at("D_OA1_CS_IC22_3_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit191                              =m_inputs_map[ska_num][FDS2].at("bit191");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit192                              =m_inputs_map[ska_num][FDS2].at("bit192");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_OA2_CS_IC22_1_Heat_alarm          =m_inputs_map[ska_num][FDS2].at("S_OA2_CS_IC22_1_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_Disconnection       =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC128               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC149               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC149");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC159               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC143               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC129               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC137               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC137");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC181               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC190               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC229               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC232               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC233               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC233");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_1_FC138               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_1_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit207                              =m_inputs_map[ska_num][FDS2].at("bit207");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit208                              =m_inputs_map[ska_num][FDS2].at("bit208");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_OA2_CS_IC22_2_Heat_alarm          =m_inputs_map[ska_num][FDS2].at("S_OA2_CS_IC22_2_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_Disconnection       =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC128               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC149               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC149");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC159               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC143               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC129               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC137               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC137");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC181               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC190               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC229               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC232               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC233               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC233");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_2_FC138               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_2_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit223                              =m_inputs_map[ska_num][FDS2].at("bit223");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit224                              =m_inputs_map[ska_num][FDS2].at("bit224");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.S_OA2_CS_IC22_3_Heat_alarm          =m_inputs_map[ska_num][FDS2].at("S_OA2_CS_IC22_3_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_Disconnection       =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC128               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC149               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC149");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC159               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC143               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC129               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC137               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC137");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC181               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC190               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC229               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC232               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC233               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC233");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.D_OA2_CS_IC22_3_FC138               =m_inputs_map[ska_num][FDS2].at("D_OA2_CS_IC22_3_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.bit239                              =m_inputs_map[ska_num][FDS2].at("bit239");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.reserved_30                         =m_inputs_map[ska_num][FDS2].at("reserved_30");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bits.reserved_31                         =m_inputs_map[ska_num][FDS2].at("reserved_31");

}

void SKA_FDS::update_fds3_map(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_inputs_map[ska_num][FDS3].at("bit0")                          =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit0                                ;
    m_inputs_map[ska_num][FDS3].at("S_SKA2_CS_IC22_1_Heat_alarm")   =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.S_SKA2_CS_IC22_1_Heat_alarm         ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_Disconnection      ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC128")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC128              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC149")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC149              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC159")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC159              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC143")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC143              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC129")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC129              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC137")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC137              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC181")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC181              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC190")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC190              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC229")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC229              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC232")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC232              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC233")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC233              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC138")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC138              ;
    m_inputs_map[ska_num][FDS3].at("bit15")                         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit15                               ;
    m_inputs_map[ska_num][FDS3].at("bit16")                         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit16                               ;
    m_inputs_map[ska_num][FDS3].at("S_SKA2_CS_IC22_2_Heat_alarm")   =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.S_SKA2_CS_IC22_2_Heat_alarm         ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_Disconnection      ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC128")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC128              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC149")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC149              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC159")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC159              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC143")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC143              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC129")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC129              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC137")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC137              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC181")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC181              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC190")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC190              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC229")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC229              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC232")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC232              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC233")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC233              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC138")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC138              ;
    m_inputs_map[ska_num][FDS3].at("bit31")                         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit31                               ;
    m_inputs_map[ska_num][FDS3].at("bit32")                         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit32                               ;
    m_inputs_map[ska_num][FDS3].at("S_SKA2_CS_IC22_3_Heat_alarm")   =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.S_SKA2_CS_IC22_3_Heat_alarm         ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_Disconnection      ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC128")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC128              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC149")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC149              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC159")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC159              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC143")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC143              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC129")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC129              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC137")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC137              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC181")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC181              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC190")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC190              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC229")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC229              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC232")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC232              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC233")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC233              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC138")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC138              ;
    m_inputs_map[ska_num][FDS3].at("bit47")                         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit47                               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC128")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC128              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC230")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC230              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC231")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC231              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC168")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC168              ;
    m_inputs_map[ska_num][FDS3].at("bit52")                         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit52                               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC140")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC140              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC159")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC159              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC155")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC155              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC156")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC156              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC141")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC141              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC142")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC142              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC143")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC143              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC169")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC169              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC183")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC183              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC184")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC184              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC153")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC153              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC176")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC176              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC181")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC181              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC189")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC189              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC210")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC210              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC213")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC213              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC217")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC217              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC218")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC218              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC229")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC229              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC232")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC232              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC152")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC152              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC209")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC209              ;
    m_inputs_map[ska_num][FDS3].at("bit75")                         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit75                               ;
    m_inputs_map[ska_num][FDS3].at("bit76")                         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit76                               ;
    m_inputs_map[ska_num][FDS3].at("bit77")                         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit77                               ;
    m_inputs_map[ska_num][FDS3].at("S_SKA2_CS_IC22_1_Heat_alarm")   =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.S_SKA2_CS_IC22_1_Heat_alarm         ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_Disconnection      ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC128")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC128              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC149")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC149              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC159")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC159              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC143")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC143              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC129")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC129              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC137")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC137              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC181")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC181              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC190")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC190              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC229")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC229              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC232")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC232              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC233")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC233              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC138")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC138              ;
    m_inputs_map[ska_num][FDS3].at("bit15")                         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit15                               ;
    m_inputs_map[ska_num][FDS3].at("bit16")                         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit16                               ;
    m_inputs_map[ska_num][FDS3].at("S_SKA2_CS_IC22_2_Heat_alarm")   =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.S_SKA2_CS_IC22_2_Heat_alarm         ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_Disconnection      ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC128")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC128              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC149")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC149              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC159")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC159              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC143")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC143              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC129")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC129              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC137")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC137              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC181")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC181              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC190")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC190              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC229")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC229              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC232")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC232              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC233")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC233              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC138")        =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC138              ;
    m_inputs_map[ska_num][FDS3].at("bit31")                         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit31                               ;
    m_inputs_map[ska_num][FDS3].at("bit32")                         =m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit32                               ;
    m_inputs_map[ska_num][FDS3].at("S_SKA2_CS_IC22_3_Heat_alarm")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.S_SKA2_CS_IC22_3_Heat_alarm         ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_Disconnection")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_Disconnection      ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC128              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC149")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC149              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC159              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC143              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC129")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC129              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC137")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC137              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC181              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC190              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC229              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC232              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC233")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC233              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC138")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC138              ;
    m_inputs_map[ska_num][FDS3].at("bit47")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit47                               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC128              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC230")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC230              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC231")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC231              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC168")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC168              ;
    m_inputs_map[ska_num][FDS3].at("bit52")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit52                               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC140")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC140              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC159              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC155")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC155              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC156")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC156              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC141")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC141              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC142")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC142              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC143              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC169")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC169              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC183")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC183              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC184")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC184              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC153")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC153              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC176")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC176              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC181              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC189")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC189              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC210")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC210              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC213")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC213              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC217")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC217              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC218")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC218              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC229              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC232              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC152")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC152              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC209")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC209              ;
    m_inputs_map[ska_num][FDS3].at("bit75")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit75                               ;
    m_inputs_map[ska_num][FDS3].at("bit76")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit76                               ;
    m_inputs_map[ska_num][FDS3].at("bit77")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit77                               ;
    m_inputs_map[ska_num][FDS3].at("bit78")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit78                               ;
    m_inputs_map[ska_num][FDS3].at("bit79")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit79                               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC128                  ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC230")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC230                  ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC231")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC231                  ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC168")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC168                  ;
    m_inputs_map[ska_num][FDS3].at("bit84")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit84                               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC137")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC137                  ;
    m_inputs_map[ska_num][FDS3].at("bit86")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit86                               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC143                  ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC169")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC169                  ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC225")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC225                  ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC176")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC176                  ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC210")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC210                  ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC213")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC213                  ;
    m_inputs_map[ska_num][FDS3].at("bit93")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit93                               ;
    m_inputs_map[ska_num][FDS3].at("bit94")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit94                               ;
    m_inputs_map[ska_num][FDS3].at("bit95")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit95                               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC128              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC230")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC230              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC231")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC231              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC168")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC168              ;
    m_inputs_map[ska_num][FDS3].at("bit100")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit100                              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC140")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC140              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC159")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC159              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC155")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC155              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC156")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC156              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC141")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC141              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC142")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC142              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC143              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC169")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC169              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC183")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC183              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC184")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC184              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC153")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC153              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC176")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC176              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC181")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC181              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC189")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC189              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC210")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC210              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC213")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC213              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC217")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC217              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC218")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC218              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC229")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC229              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC232              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC152")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC152              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC209")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC209              ;
    m_inputs_map[ska_num][FDS3].at("bit123")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit123                              ;
    m_inputs_map[ska_num][FDS3].at("bit124")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit124                              ;
    m_inputs_map[ska_num][FDS3].at("bit125")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit125                              ;
    m_inputs_map[ska_num][FDS3].at("bit126")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit126                              ;
    m_inputs_map[ska_num][FDS3].at("bit127")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit127                              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC128                  ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC230")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC230                  ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC231")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC231                  ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC168")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC168                  ;
    m_inputs_map[ska_num][FDS3].at("bit132")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit132                              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC137")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC137                  ;
    m_inputs_map[ska_num][FDS3].at("bit134")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit134                              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC143                  ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC169")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC169                  ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC225")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC225                  ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC176")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC176                  ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC210")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC210                  ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC213")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC213                  ;
    m_inputs_map[ska_num][FDS3].at("bit141")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit141                              ;
    m_inputs_map[ska_num][FDS3].at("bit142")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit142                              ;
    m_inputs_map[ska_num][FDS3].at("bit143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit143                              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_FC128               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_FC230")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_FC230               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_FC231")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_FC231               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_FC168")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_FC168               ;
    m_inputs_map[ska_num][FDS3].at("bit148")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit148                              ;
    m_inputs_map[ska_num][FDS3].at("bit149")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit149                              ;
    m_inputs_map[ska_num][FDS3].at("bit150")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit150                              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_FC143               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_FC169")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_FC169               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_FC183")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_FC183               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_FC184")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_FC184               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_FC216")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_FC216               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_FC232               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_Relay_1_Any_fault")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_Relay_1_Any_fault   ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_Relay_2_Any_fault")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_Relay_2_Any_fault   ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_Relay_3_Any_fault")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_Relay_3_Any_fault   ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_Relay_4_Any_fault")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_Relay_4_Any_fault   ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_Relay_5_Any_fault")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_Relay_5_Any_fault   ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_Relay_6_Any_fault")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_Relay_6_Any_fault   ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_Relay_7_Any_fault")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_Relay_7_Any_fault   ;
    m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_Relay_8_Any_fault")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_Relay_8_Any_fault   ;
    m_inputs_map[ska_num][FDS3].at("bit165")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit165                              ;
    m_inputs_map[ska_num][FDS3].at("bit166")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit166                              ;
    m_inputs_map[ska_num][FDS3].at("bit167")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit167                              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_FC128")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_FC128               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_FC230")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_FC230               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_FC231")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_FC231               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_FC168")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_FC168               ;
    m_inputs_map[ska_num][FDS3].at("bit172")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit172                              ;
    m_inputs_map[ska_num][FDS3].at("bit173")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit173                              ;
    m_inputs_map[ska_num][FDS3].at("bit174")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit174                              ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_FC143")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_FC143               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_FC169")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_FC169               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_FC183")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_FC183               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_FC184")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_FC184               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_FC216")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_FC216               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_FC232")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_FC232               ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_Relay_1_Any_fault")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_Relay_1_Any_fault   ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_Relay_2_Any_fault")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_Relay_2_Any_fault   ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_Relay_3_Any_fault")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_Relay_3_Any_fault   ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_Relay_4_Any_fault")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_Relay_4_Any_fault   ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_Relay_5_Any_fault")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_Relay_5_Any_fault   ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_Relay_6_Any_fault")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_Relay_6_Any_fault   ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_Relay_7_Any_fault")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_Relay_7_Any_fault   ;
    m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_Relay_8_Any_fault")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_Relay_8_Any_fault   ;
    m_inputs_map[ska_num][FDS3].at("bit189")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit189                              ;
    m_inputs_map[ska_num][FDS3].at("bit190")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit190                              ;
    m_inputs_map[ska_num][FDS3].at("bit191")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit191                              ;
    m_inputs_map[ska_num][FDS3].at("reserved_24")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.reserved_24                  ;
    m_inputs_map[ska_num][FDS3].at("SW_Release_Version")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.SW_Release_Version                  ;
    m_inputs_map[ska_num][FDS3].at("SW_Major_Version")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.SW_Major_Version                    ;
    m_inputs_map[ska_num][FDS3].at("SW_Minor_Version")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.SW_Minor_Version                    ;
    //m_inputs_map[ska_num][FDS3].at("SW_Built_Version")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.SW_Built_Version                    ;
    m_inputs_map[ska_num][FDS3].at("Application_Identifier")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.Application_Identifier              ;
    m_inputs_map[ska_num][FDS3].at("reserved_29")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.reserved_29                         ;
    m_inputs_map[ska_num][FDS3].at("reserved_30")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.reserved_30                         ;
    m_inputs_map[ska_num][FDS3].at("reserved_31")=m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.reserved_31                         ;

}

void SKA_FDS::update_table(SKA_VEHICLE_NUM ska_x_num,FDS_NUM fds_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    // İndeksleri kullanarak tabloyu güncelle
    qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][FDS1]->columnCount() ;
    std::vector<int> valueColumns = {1, 3, 5, 7};
    for(const auto & map:m_inputs_map[ska_num][fds_num]){


            utils::setTableWidgetValueByNameWithoutColumn(m_tableWidget[ska_num][fds_num], map.first, map.second);
            //qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT INSIDE FOR LOOP ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;

            //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,3, map.second);
            //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,5, map.second);
            //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,7, map.second);
    }
}

void SKA_FDS::set_data_struct(const QByteArray &input, const SKA_VEHICLE_NUM &ska_x_num)
{
    //int oa_num = static_cast<int>(oa_x_num);
    qDebug() << "azdan az çoktan çok " ;
    qDebug() << "size of input " << input.size();
    qDebug() << "Gelen input verileri :  " << input;
    //qDebug() << "Gelen input veri tipi : " << typeof(input);


    int ska_num = static_cast<int>(ska_x_num);
    qDebug() << "bassana lan şunu sizeof(m_oa_x_jru[oa_num])  " << sizeof(m_ska_x_fds[ska_num]);

    if (input.size() == sizeof(m_ska_x_fds[ska_num])) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        //memcpy(&m_oa_x_etcs[oa_num], input.constData(), sizeof(m_oa_x_etcs[oa_num]));

        qDebug() << "SIZE of FDS1 :  " << sizeof(m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bytes);



        // İlk alanı kopyala
        memcpy(&m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bytes, input.constData(), sizeof(m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bytes));

        QByteArray data =  input.mid(0, 32);
        qDebug() << "32 Bytelık data :  " << data;
        update_fds1_map(ska_x_num);
        //set_struct_mvb1(oa_x_num);
        update_table(ska_x_num,FDS1);

        //İkinci alanı kopyala

        //memcpy(&m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bytes, input.constData() + sizeof(m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb6_fds1.bytes) , sizeof(m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb7_fds2.bytes));
        //qDebug() << "fds2 map üstü :  " << data;
        //update_fds2_map(ska_x_num);
        //qDebug() << "fds2 map altı table üstü :  " << data;

        //set_struct_mvb1(oa_x_num);
        //update_table(ska_x_num,FDS2);
        //  qDebug() << "table ALTI :  " << data;
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

void SKA_FDS::update_struct_with_map(SKA_VEHICLE_NUM ska_x_num, FDS_NUM fds_num)
{

    int ska_num = static_cast<int>(ska_x_num);
    // Define a lambda function to reduce redundancy
    auto setInputMap = [&](const QString& signal_name) {
        m_inputs_map[ska_num][fds_num][signal_name] = utils::getTableWidgetValueByNameWithoutColumn(m_tableWidget[ska_num][fds_num], signal_name).toInt();
    };
    // update map with given tableWidget values
    for(const auto& map : m_inputs_map[ska_num][fds_num])
    {
        setInputMap(map.first);
    }
    // set struct parameters with given updated map parameters
    set_struct_fds1(ska_x_num);
    set_struct_fds2(ska_x_num);
    //set_struct_fds3(ska_x_num);

}

void SKA_FDS::set_struct_fds3(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);

    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit0                                = m_inputs_map[ska_num][FDS3].at("bit0");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.S_SKA2_CS_IC22_1_Heat_alarm         = m_inputs_map[ska_num][FDS3].at("S_SKA2_CS_IC22_1_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_Disconnection      = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC128              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC149              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC149");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC159              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC143              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC129              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC137              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC137");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC181              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC190              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC229              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC232              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC233              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC233");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC138              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit15                               = m_inputs_map[ska_num][FDS3].at("bit15");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit16                               = m_inputs_map[ska_num][FDS3].at("bit16");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.S_SKA2_CS_IC22_2_Heat_alarm         = m_inputs_map[ska_num][FDS3].at("S_SKA2_CS_IC22_2_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_Disconnection      = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC128              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC149              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC149");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC159              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC143              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC129              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC137              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC137");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC181              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC190              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC229              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC232              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC233              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC233");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC138              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit31                               = m_inputs_map[ska_num][FDS3].at("bit31");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit32                               = m_inputs_map[ska_num][FDS3].at("bit32");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.S_SKA2_CS_IC22_3_Heat_alarm         = m_inputs_map[ska_num][FDS3].at("S_SKA2_CS_IC22_3_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_Disconnection      = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC128              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC149              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC149");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC159              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC143              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC129              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC137              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC137");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC181              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC190              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC229              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC232              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC233              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC233");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC138              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit47                               = m_inputs_map[ska_num][FDS3].at("bit47");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC128              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC230              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC230");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC231              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC231");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC168              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC168");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit52                               = m_inputs_map[ska_num][FDS3].at("bit52");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC140              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC140");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC159              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC155              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC155");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC156              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC156");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC141              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC141");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC142              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC142");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC143              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC169              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC169");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC183              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC183");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC184              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC184");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC153              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC153");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC176              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC176");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC181              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC189              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC189");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC210              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC210");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC213              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC213");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC217              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC217");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC218              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC218");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC229              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC232              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC152              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC152");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC209              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC209");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit75                               = m_inputs_map[ska_num][FDS3].at("bit75");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit76                               = m_inputs_map[ska_num][FDS3].at("bit76");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit77                               = m_inputs_map[ska_num][FDS3].at("bit77");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.S_SKA2_CS_IC22_1_Heat_alarm         = m_inputs_map[ska_num][FDS3].at("S_SKA2_CS_IC22_1_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_Disconnection      = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC128              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC149              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC149");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC159              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC143              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC129              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC137              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC137");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC181              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC190              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC229              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC232              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC233              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC233");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_1_FC138              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_1_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit15                               = m_inputs_map[ska_num][FDS3].at("bit15");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit16                               = m_inputs_map[ska_num][FDS3].at("bit16");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.S_SKA2_CS_IC22_2_Heat_alarm         = m_inputs_map[ska_num][FDS3].at("S_SKA2_CS_IC22_2_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_Disconnection      = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC128              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC149              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC149");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC159              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC143              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC129              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC137              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC137");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC181              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC190              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC229              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC232              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC233              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC233");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_2_FC138              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_2_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit31                               = m_inputs_map[ska_num][FDS3].at("bit31");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit32                               = m_inputs_map[ska_num][FDS3].at("bit32");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.S_SKA2_CS_IC22_3_Heat_alarm         = m_inputs_map[ska_num][FDS3].at("S_SKA2_CS_IC22_3_Heat_alarm");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_Disconnection      = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_Disconnection");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC128              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC149              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC149");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC159              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC143              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC129              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC129");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC137              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC137");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC181              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC190              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC229              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC232              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC233              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC233");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_IC22_3_FC138              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_IC22_3_FC138");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit47                               = m_inputs_map[ska_num][FDS3].at("bit47");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC128              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC230              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC230");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC231              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC231");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC168              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC168");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit52                               = m_inputs_map[ska_num][FDS3].at("bit52");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC140              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC140");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC159              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC155              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC155");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC156              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC156");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC141              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC141");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC142              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC142");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC143              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC169              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC169");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC183              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC183");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC184              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC184");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC153              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC153");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC176              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC176");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC181              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC189              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC189");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC210              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC210");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC213              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC213");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC217              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC217");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC218              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC218");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC229              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC232              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC152              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC152");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CS_Loop_M_FC209              = m_inputs_map[ska_num][FDS3].at("D_SKA1_CS_Loop_M_FC209");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit75                               = m_inputs_map[ska_num][FDS3].at("bit75");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit76                               = m_inputs_map[ska_num][FDS3].at("bit76");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit77                               = m_inputs_map[ska_num][FDS3].at("bit77");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit78                               = m_inputs_map[ska_num][FDS3].at("bit78");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit79                               = m_inputs_map[ska_num][FDS3].at("bit79");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC128                  = m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC230                  = m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC230");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC231                  = m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC231");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC168                  = m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC168");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit84                               = m_inputs_map[ska_num][FDS3].at("bit84");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC137                  = m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC137");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit86                               = m_inputs_map[ska_num][FDS3].at("bit86");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC143                  = m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC169                  = m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC169");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC225                  = m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC225");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC176                  = m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC176");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC210                  = m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC210");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_CM_22_FC213                  = m_inputs_map[ska_num][FDS3].at("D_SKA1_CM_22_FC213");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit93                               = m_inputs_map[ska_num][FDS3].at("bit93");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit94                               = m_inputs_map[ska_num][FDS3].at("bit94");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit95                               = m_inputs_map[ska_num][FDS3].at("bit95");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC128              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC230              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC230");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC231              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC231");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC168              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC168");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit100                              = m_inputs_map[ska_num][FDS3].at("bit100");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC140              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC140");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC159              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC159");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC155              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC155");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC156              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC156");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC141              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC141");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC142              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC142");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC143              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC169              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC169");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC183              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC183");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC184              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC184");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC153              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC153");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC176              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC176");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC181              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC181");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC189              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC189");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC210              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC210");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC213              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC213");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC217              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC217");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC218              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC218");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC229              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC229");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC232              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC152              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC152");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CS_Loop_M_FC209              = m_inputs_map[ska_num][FDS3].at("D_SKA2_CS_Loop_M_FC209");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit123                              = m_inputs_map[ska_num][FDS3].at("bit123");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit124                              = m_inputs_map[ska_num][FDS3].at("bit124");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit125                              = m_inputs_map[ska_num][FDS3].at("bit125");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit126                              = m_inputs_map[ska_num][FDS3].at("bit126");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit127                              = m_inputs_map[ska_num][FDS3].at("bit127");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC128                  = m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC230                  = m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC230");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC231                  = m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC231");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC168                  = m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC168");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit132                              = m_inputs_map[ska_num][FDS3].at("bit132");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC137                  = m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC137");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit134                              = m_inputs_map[ska_num][FDS3].at("bit134");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC143                  = m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC169                  = m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC169");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC225                  = m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC225");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC176                  = m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC176");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC210                  = m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC210");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_CM_22_FC213                  = m_inputs_map[ska_num][FDS3].at("D_SKA2_CM_22_FC213");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit141                              = m_inputs_map[ska_num][FDS3].at("bit141");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit142                              = m_inputs_map[ska_num][FDS3].at("bit142");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit143                              = m_inputs_map[ska_num][FDS3].at("bit143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_FC128               = m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_FC230               = m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_FC230");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_FC231               = m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_FC231");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_FC168               = m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_FC168");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit148                              = m_inputs_map[ska_num][FDS3].at("bit148");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit149                              = m_inputs_map[ska_num][FDS3].at("bit149");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit150                              = m_inputs_map[ska_num][FDS3].at("bit150");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_FC143               = m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_FC169               = m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_FC169");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_FC183               = m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_FC183");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_FC184               = m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_FC184");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_FC216               = m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_FC216");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_FC232               = m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_Relay_1_Any_fault   = m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_Relay_1_Any_fault");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_Relay_2_Any_fault   = m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_Relay_2_Any_fault");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_Relay_3_Any_fault   = m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_Relay_3_Any_fault");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_Relay_4_Any_fault   = m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_Relay_4_Any_fault");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_Relay_5_Any_fault   = m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_Relay_5_Any_fault");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_Relay_6_Any_fault   = m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_Relay_6_Any_fault");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_Relay_7_Any_fault   = m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_Relay_7_Any_fault");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA1_Relay_M8_Relay_8_Any_fault   = m_inputs_map[ska_num][FDS3].at("D_SKA1_Relay_M8_Relay_8_Any_fault");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit165                              = m_inputs_map[ska_num][FDS3].at("bit165");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit166                              = m_inputs_map[ska_num][FDS3].at("bit166");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit167                              = m_inputs_map[ska_num][FDS3].at("bit167");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_FC128               = m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_FC128");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_FC230               = m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_FC230");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_FC231               = m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_FC231");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_FC168               = m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_FC168");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit172                              = m_inputs_map[ska_num][FDS3].at("bit172");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit173                              = m_inputs_map[ska_num][FDS3].at("bit173");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit174                              = m_inputs_map[ska_num][FDS3].at("bit174");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_FC143               = m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_FC143");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_FC169               = m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_FC169");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_FC183               = m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_FC183");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_FC184               = m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_FC184");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_FC216               = m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_FC216");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_FC232               = m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_FC232");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_Relay_1_Any_fault   = m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_Relay_1_Any_fault");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_Relay_2_Any_fault   = m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_Relay_2_Any_fault");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_Relay_3_Any_fault   = m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_Relay_3_Any_fault");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_Relay_4_Any_fault   = m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_Relay_4_Any_fault");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_Relay_5_Any_fault   = m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_Relay_5_Any_fault");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_Relay_6_Any_fault   = m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_Relay_6_Any_fault");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_Relay_7_Any_fault   = m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_Relay_7_Any_fault");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.D_SKA2_Relay_M8_Relay_8_Any_fault   = m_inputs_map[ska_num][FDS3].at("D_SKA2_Relay_M8_Relay_8_Any_fault");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit189                              = m_inputs_map[ska_num][FDS3].at("bit189");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit190                              = m_inputs_map[ska_num][FDS3].at("bit190");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.bit191                              = m_inputs_map[ska_num][FDS3].at("bit191");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.reserved_24                   = m_inputs_map[ska_num][FDS3].at("reserved24");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.SW_Release_Version                  = m_inputs_map[ska_num][FDS3].at("SW_Release_Version");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.SW_Major_Version                    = m_inputs_map[ska_num][FDS3].at("SW_Major_Version");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.SW_Minor_Version                    = m_inputs_map[ska_num][FDS3].at("SW_Minor_Version");
    //m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.SW_Built_Version                    = m_inputs_map[ska_num][FDS3].at("SW_Built_Version");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.Application_Identifier              = m_inputs_map[ska_num][FDS3].at("Application_Identifier");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.reserved_29                         = m_inputs_map[ska_num][FDS3].at("reserved_29");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.reserved_30                         = m_inputs_map[ska_num][FDS3].at("reserved_30");
    m_ska_x_fds[ska_num].ska_vh_riom_ccu_mvb8_fds3.bits.reserved_31                         = m_inputs_map[ska_num][FDS3].at("reserved_31");


}
void SKA_FDS::init_ska_x_fds3_table(SKA_VEHICLE_NUM vehicle_type)
{
    int ska_num = static_cast<int>(vehicle_type);
    m_inputs_map[ska_num][FDS3] = {
        {"bit0", 0},
        {"S_SKA2_CS_IC22_1_Heat_alarm", 0},
        {"D_SKA2_CS_IC22_1_Disconnection", 0},
        {"D_SKA2_CS_IC22_1_FC128", 0},
        {"D_SKA2_CS_IC22_1_FC149", 0},
        {"D_SKA2_CS_IC22_1_FC159", 0},
        {"D_SKA2_CS_IC22_1_FC143", 0},
        {"D_SKA2_CS_IC22_1_FC129", 0},
        {"D_SKA2_CS_IC22_1_FC137", 0},
        {"D_SKA2_CS_IC22_1_FC181", 0},
        {"D_SKA2_CS_IC22_1_FC190", 0},
        {"D_SKA2_CS_IC22_1_FC229", 0},
        {"D_SKA2_CS_IC22_1_FC232", 0},
        {"D_SKA2_CS_IC22_1_FC233", 0},
        {"D_SKA2_CS_IC22_1_FC138", 0},
        {"bit15", 0},
        {"bit16", 0},
        {"S_SKA2_CS_IC22_2_Heat_alarm", 0},
        {"D_SKA2_CS_IC22_2_Disconnection", 0},
        {"D_SKA2_CS_IC22_2_FC128", 0},
        {"D_SKA2_CS_IC22_2_FC149", 0},
        {"D_SKA2_CS_IC22_2_FC159", 0},
        {"D_SKA2_CS_IC22_2_FC143", 0},
        {"D_SKA2_CS_IC22_2_FC129", 0},
        {"D_SKA2_CS_IC22_2_FC137", 0},
        {"D_SKA2_CS_IC22_2_FC181", 0},
        {"D_SKA2_CS_IC22_2_FC190", 0},
        {"D_SKA2_CS_IC22_2_FC229", 0},
        {"D_SKA2_CS_IC22_2_FC232", 0},
        {"D_SKA2_CS_IC22_2_FC233", 0},
        {"D_SKA2_CS_IC22_2_FC138", 0},
        {"bit31", 0},
        {"bit32", 0},
        {"S_SKA2_CS_IC22_3_Heat_alarm", 0},
        {"D_SKA2_CS_IC22_3_Disconnection", 0},
        {"D_SKA2_CS_IC22_3_FC128", 0},
        {"D_SKA2_CS_IC22_3_FC149", 0},
        {"D_SKA2_CS_IC22_3_FC159", 0},
        {"D_SKA2_CS_IC22_3_FC143", 0},
        {"D_SKA2_CS_IC22_3_FC129", 0},
        {"D_SKA2_CS_IC22_3_FC137", 0},
        {"D_SKA2_CS_IC22_3_FC181", 0},
        {"D_SKA2_CS_IC22_3_FC190", 0},
        {"D_SKA2_CS_IC22_3_FC229", 0},
        {"D_SKA2_CS_IC22_3_FC232", 0},
        {"D_SKA2_CS_IC22_3_FC233", 0},
        {"D_SKA2_CS_IC22_3_FC138", 0},
        {"bit47", 0},
        {"D_SKA1_CS_Loop_M_FC128", 0},
        {"D_SKA1_CS_Loop_M_FC230", 0},
        {"D_SKA1_CS_Loop_M_FC231", 0},
        {"D_SKA1_CS_Loop_M_FC168", 0},
        {"bit52", 0},
        {"D_SKA1_CS_Loop_M_FC140", 0},
        {"D_SKA1_CS_Loop_M_FC159", 0},
        {"D_SKA1_CS_Loop_M_FC155", 0},
        {"D_SKA1_CS_Loop_M_FC156", 0},
        {"D_SKA1_CS_Loop_M_FC141", 0},
        {"D_SKA1_CS_Loop_M_FC142", 0},
        {"D_SKA1_CS_Loop_M_FC143", 0},
        {"D_SKA1_CS_Loop_M_FC169", 0},
        {"D_SKA1_CS_Loop_M_FC183", 0},
        {"D_SKA1_CS_Loop_M_FC184", 0},
        {"D_SKA1_CS_Loop_M_FC153", 0},
        {"D_SKA1_CS_Loop_M_FC176", 0},
        {"D_SKA1_CS_Loop_M_FC181", 0},
        {"D_SKA1_CS_Loop_M_FC189", 0},
        {"D_SKA1_CS_Loop_M_FC210", 0},
        {"D_SKA1_CS_Loop_M_FC213", 0},
        {"D_SKA1_CS_Loop_M_FC217", 0},
        {"D_SKA1_CS_Loop_M_FC218", 0},
        {"D_SKA1_CS_Loop_M_FC229", 0},
        {"D_SKA1_CS_Loop_M_FC232", 0},
        {"D_SKA1_CS_Loop_M_FC152", 0},
        {"D_SKA1_CS_Loop_M_FC209", 0},
        {"bit75", 0},
        {"bit76", 0},
        {"bit77", 0},
        {"S_SKA2_CS_IC22_1_Heat_alarm", 0},
        {"D_SKA2_CS_IC22_1_Disconnection", 0},
        {"D_SKA2_CS_IC22_1_FC128", 0},
        {"D_SKA2_CS_IC22_1_FC149", 0},
        {"D_SKA2_CS_IC22_1_FC159", 0},
        {"D_SKA2_CS_IC22_1_FC143", 0},
        {"D_SKA2_CS_IC22_1_FC129", 0},
        {"D_SKA2_CS_IC22_1_FC137", 0},
        {"D_SKA2_CS_IC22_1_FC181", 0},
        {"D_SKA2_CS_IC22_1_FC190", 0},
        {"D_SKA2_CS_IC22_1_FC229", 0},
        {"D_SKA2_CS_IC22_1_FC232", 0},
        {"D_SKA2_CS_IC22_1_FC233", 0},
        {"D_SKA2_CS_IC22_1_FC138", 0},
        {"bit15", 0},
        {"bit16", 0},
        {"S_SKA2_CS_IC22_2_Heat_alarm", 0},
        {"D_SKA2_CS_IC22_2_Disconnection", 0},
        {"D_SKA2_CS_IC22_2_FC128", 0},
        {"D_SKA2_CS_IC22_2_FC149", 0},
        {"D_SKA2_CS_IC22_2_FC159", 0},
        {"D_SKA2_CS_IC22_2_FC143", 0},
        {"D_SKA2_CS_IC22_2_FC129", 0},
        {"D_SKA2_CS_IC22_2_FC137", 0},
        {"D_SKA2_CS_IC22_2_FC181", 0},
        {"D_SKA2_CS_IC22_2_FC190", 0},
        {"D_SKA2_CS_IC22_2_FC229", 0},
        {"D_SKA2_CS_IC22_2_FC232", 0},
        {"D_SKA2_CS_IC22_2_FC233", 0},
        {"D_SKA2_CS_IC22_2_FC138", 0},
        {"bit31", 0},
        {"bit32", 0},
        {"S_SKA2_CS_IC22_3_Heat_alarm", 0},
        {"D_SKA2_CS_IC22_3_Disconnection", 0},
        {"D_SKA2_CS_IC22_3_FC128", 0},
        {"D_SKA2_CS_IC22_3_FC149", 0},
        {"D_SKA2_CS_IC22_3_FC159", 0},
        {"D_SKA2_CS_IC22_3_FC143", 0},
        {"D_SKA2_CS_IC22_3_FC129", 0},
        {"D_SKA2_CS_IC22_3_FC137", 0},
        {"D_SKA2_CS_IC22_3_FC181", 0},
        {"D_SKA2_CS_IC22_3_FC190", 0},
        {"D_SKA2_CS_IC22_3_FC229", 0},
        {"D_SKA2_CS_IC22_3_FC232", 0},
        {"D_SKA2_CS_IC22_3_FC233", 0},
        {"D_SKA2_CS_IC22_3_FC138", 0},
        {"bit47", 0},
        {"D_SKA1_CS_Loop_M_FC128", 0},
        {"D_SKA1_CS_Loop_M_FC230", 0},
        {"D_SKA1_CS_Loop_M_FC231", 0},
        {"D_SKA1_CS_Loop_M_FC168", 0},
        {"bit52", 0},
        {"D_SKA1_CS_Loop_M_FC140", 0},
        {"D_SKA1_CS_Loop_M_FC159", 0},
        {"D_SKA1_CS_Loop_M_FC155", 0},
        {"D_SKA1_CS_Loop_M_FC156", 0},
        {"D_SKA1_CS_Loop_M_FC141", 0},
        {"D_SKA1_CS_Loop_M_FC142", 0},
        {"D_SKA1_CS_Loop_M_FC143", 0},
        {"D_SKA1_CS_Loop_M_FC169", 0},
        {"D_SKA1_CS_Loop_M_FC183", 0},
        {"D_SKA1_CS_Loop_M_FC184", 0},
        {"D_SKA1_CS_Loop_M_FC153", 0},
        {"D_SKA1_CS_Loop_M_FC176", 0},
        {"D_SKA1_CS_Loop_M_FC181", 0},
        {"D_SKA1_CS_Loop_M_FC189", 0},
        {"D_SKA1_CS_Loop_M_FC210", 0},
        {"D_SKA1_CS_Loop_M_FC213", 0},
        {"D_SKA1_CS_Loop_M_FC217", 0},
        {"D_SKA1_CS_Loop_M_FC218", 0},
        {"D_SKA1_CS_Loop_M_FC229", 0},
        {"D_SKA1_CS_Loop_M_FC232", 0},
        {"D_SKA1_CS_Loop_M_FC152", 0},
        {"D_SKA1_CS_Loop_M_FC209", 0},
        {"bit75", 0},
        {"bit76", 0},
        {"bit77", 0},
        {"bit78", 0},
        {"bit79", 0},
        {"D_SKA1_CM_22_FC128", 0},
        {"D_SKA1_CM_22_FC230", 0},
        {"D_SKA1_CM_22_FC231", 0},
        {"D_SKA1_CM_22_FC168", 0},
        {"bit84", 0},
        {"D_SKA1_CM_22_FC137", 0},
        {"bit86", 0},
        {"D_SKA1_CM_22_FC143", 0},
        {"D_SKA1_CM_22_FC169", 0},
        {"D_SKA1_CM_22_FC225", 0},
        {"D_SKA1_CM_22_FC176", 0},
        {"D_SKA1_CM_22_FC210", 0},
        {"D_SKA1_CM_22_FC213", 0},
        {"bit93", 0},
        {"bit94", 0},
        {"bit95", 0},
        {"D_SKA2_CS_Loop_M_FC128", 0},
        {"D_SKA2_CS_Loop_M_FC230", 0},
        {"D_SKA2_CS_Loop_M_FC231", 0},
        {"D_SKA2_CS_Loop_M_FC168", 0},
        {"bit100", 0},
        {"D_SKA2_CS_Loop_M_FC140", 0},
        {"D_SKA2_CS_Loop_M_FC159", 0},
        {"D_SKA2_CS_Loop_M_FC155", 0},
        {"D_SKA2_CS_Loop_M_FC156", 0},
        {"D_SKA2_CS_Loop_M_FC141", 0},
        {"D_SKA2_CS_Loop_M_FC142", 0},
        {"D_SKA2_CS_Loop_M_FC143", 0},
        {"D_SKA2_CS_Loop_M_FC169", 0},
        {"D_SKA2_CS_Loop_M_FC183", 0},
        {"D_SKA2_CS_Loop_M_FC184", 0},
        {"D_SKA2_CS_Loop_M_FC153", 0},
        {"D_SKA2_CS_Loop_M_FC176", 0},
        {"D_SKA2_CS_Loop_M_FC181", 0},
        {"D_SKA2_CS_Loop_M_FC189", 0},
        {"D_SKA2_CS_Loop_M_FC210", 0},
        {"D_SKA2_CS_Loop_M_FC213", 0},
        {"D_SKA2_CS_Loop_M_FC217", 0},
        {"D_SKA2_CS_Loop_M_FC218", 0},
        {"D_SKA2_CS_Loop_M_FC229", 0},
        {"D_SKA2_CS_Loop_M_FC232", 0},
        {"D_SKA2_CS_Loop_M_FC152", 0},
        {"D_SKA2_CS_Loop_M_FC209", 0},
        {"bit123", 0},
        {"bit124", 0},
        {"bit125", 0},
        {"bit126", 0},
        {"bit127", 0},
        {"D_SKA2_CM_22_FC128", 0},
        {"D_SKA2_CM_22_FC230", 0},
        {"D_SKA2_CM_22_FC231", 0},
        {"D_SKA2_CM_22_FC168", 0},
        {"bit132", 0},
        {"D_SKA2_CM_22_FC137", 0},
        {"bit134", 0},
        {"D_SKA2_CM_22_FC143", 0},
        {"D_SKA2_CM_22_FC169", 0},
        {"D_SKA2_CM_22_FC225", 0},
        {"D_SKA2_CM_22_FC176", 0},
        {"D_SKA2_CM_22_FC210", 0},
        {"D_SKA2_CM_22_FC213", 0},
        {"bit141", 0},
        {"bit142", 0},
        {"bit143", 0},
        {"D_SKA1_Relay_M8_FC128", 0},
        {"D_SKA1_Relay_M8_FC230", 0},
        {"D_SKA1_Relay_M8_FC231", 0},
        {"D_SKA1_Relay_M8_FC168", 0},
        {"bit148", 0},
        {"bit149", 0},
        {"bit150", 0},
        {"D_SKA1_Relay_M8_FC143", 0},
        {"D_SKA1_Relay_M8_FC169", 0},
        {"D_SKA1_Relay_M8_FC183", 0},
        {"D_SKA1_Relay_M8_FC184", 0},
        {"D_SKA1_Relay_M8_FC216", 0},
        {"D_SKA1_Relay_M8_FC232", 0},
        {"D_SKA1_Relay_M8_Relay_1_Any_fault", 0},
        {"D_SKA1_Relay_M8_Relay_2_Any_fault", 0},
        {"D_SKA1_Relay_M8_Relay_3_Any_fault", 0},
        {"D_SKA1_Relay_M8_Relay_4_Any_fault", 0},
        {"D_SKA1_Relay_M8_Relay_5_Any_fault", 0},
        {"D_SKA1_Relay_M8_Relay_6_Any_fault", 0},
        {"D_SKA1_Relay_M8_Relay_7_Any_fault", 0},
        {"D_SKA1_Relay_M8_Relay_8_Any_fault", 0},
        {"bit165", 0},
        {"bit166", 0},
        {"bit167", 0},
        {"D_SKA2_Relay_M8_FC128", 0},
        {"D_SKA2_Relay_M8_FC230", 0},
        {"D_SKA2_Relay_M8_FC231", 0},
        {"D_SKA2_Relay_M8_FC168", 0},
        {"bit172", 0},
        {"bit173", 0},
        {"bit174", 0},
        {"D_SKA2_Relay_M8_FC143", 0},
        {"D_SKA2_Relay_M8_FC169", 0},
        {"D_SKA2_Relay_M8_FC183", 0},
        {"D_SKA2_Relay_M8_FC184", 0},
        {"D_SKA2_Relay_M8_FC216", 0},
        {"D_SKA2_Relay_M8_FC232", 0},
        {"D_SKA2_Relay_M8_Relay_1_Any_fault", 0},
        {"D_SKA2_Relay_M8_Relay_2_Any_fault", 0},
        {"D_SKA2_Relay_M8_Relay_3_Any_fault", 0},
        {"D_SKA2_Relay_M8_Relay_4_Any_fault", 0},
        {"D_SKA2_Relay_M8_Relay_5_Any_fault", 0},
        {"D_SKA2_Relay_M8_Relay_6_Any_fault", 0},
        {"D_SKA2_Relay_M8_Relay_7_Any_fault", 0},
        {"D_SKA2_Relay_M8_Relay_8_Any_fault", 0},
        {"bit189", 0},
        {"bit190", 0},
        {"bit191", 0},
        {"reserved_34", 0},
        {"SW_Release_Version", 0},
        {"SW_Major_Version", 0},
        {"SW_Minor_Version", 0},
        //{"SW_Built_Version", 0},
        {"Application_Identifier", 0},
        {"reserved_29", 0},
        {"reserved_30", 0},
        {"reserved_31", 0},

    };

    /*m_tableWidget[ska_num][FDS3] = new QTableWidget();
    m_tableWidget[ska_num][FDS3]->setColumnCount(2);
    m_tableWidget[ska_num][FDS3]->setRowCount(m_inputs_map[ska_num][FDS3].size());
    m_tableWidget[ska_num][FDS3]->setHorizontalHeaderLabels(table_name[ska_num][FDS3]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[ska_num][FDS3]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[ska_num][FDS3]->setItem(row, 0, item_name);
        m_tableWidget[ska_num][FDS3]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[ska_num][FDS3]->resizeColumnsToContents();*/

    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[ska_num][FDS3].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[ska_num][FDS3] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[ska_num][FDS3]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[ska_num][FDS3]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[ska_num][FDS3]->setItem(row, column, item_name);
        m_tableWidget[ska_num][FDS3]->setItem(row, column + 1, item_val); // Değer

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[ska_num][FDS3]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][FDS3]->columnCount() ;
}

