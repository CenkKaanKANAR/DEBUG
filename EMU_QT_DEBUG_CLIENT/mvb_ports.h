/*
    MVB SINK and SOURCE IDs and SIZES
*/

//#include <tcn_def.h>
//#include "dg_hdio.h"
#include <stdint.h>
#include <array>
//typedef uint16_t UNSIGNED16;
using UNSIGNED16 = std::array<uint16_t, 2>;
/*TCU WTB mesajları eklenecek*/
constexpr std::array<UNSIGNED16, 19> mvb_sink_addresses_ska1 ={{
    /*RIOMS*/
    /*PORT ID     PORT SIZE */
    {{0x201, 8 }},   /*DD RIOM_M_STATUS*/
    {{0x211, 16}},  /*DD RIOM_M INPUTS*/
    {{0x401, 8 }},   /*VH RIOM_M_STATUS*/
    {{0x411, 32}},  /*VH RIOM_M_INPUTS*/
    {{0x412, 32}},  /*VH RIOM_M_DCU1*/
    {{0x413, 32}},  /*VH RIOM_M_DCU2*/
    {{0x414, 32}},  /*VH RIOM_M_DCU3*/
    {{0x415, 16}},  /*VH RIOM_M_DCU4*/
    {{0x416, 32}},  /*VH RIOM_M_FDS1*/
    {{0x417, 32}},  /*VH RIOM_M_FDS2*/
    {{0x418, 32}},  /*VH RIOM_M_FDS3*/
    {{0x419, 16}},  /*VH RIOM_M_ATS1*/
    {{0x41A, 32}},  /*VH RIOM_M_PAPIS1*/
    {{0x41B, 32}},  /*VH RIOM_M_PAPIS2*/
    {{0x41C, 32}},  /*VH RIOM_M_PAPIS3*/
    {{0x41D, 32}},  /*VH RIOM_M_PAPIS4*/
    /*BCU*/
    {{0x601, 32}},  /*BCU_1*/
    {{0x602, 16}},  /*BCU_2*/
    {{0x603, 32}},   /*BCU_3*/
    /*TCU*/
    /*WTB GW*/
}};


/*TCU WTB mesajları eklenecek*/
constexpr std::array<UNSIGNED16, 19>  mvb_sink_addresses_ska2 = {{
    /*PORT ID     PORT SIZE */
    {{0x2C1, 8 }},  /*DD RIOM_M_STATUS*/
    {{0x2D1, 16}},  /*DD RIOM_M INPUTS*/
    {{0x4C1, 8 }},  /*VH RIOM_M_STATUS*/
    {{0x4D1, 32}},  /*VH RIOM_M_INPUTS*/
    {{0x4D2, 32}},  /*VH RIOM_M_DCU1*/
    {{0x4D3, 32}},  /*VH RIOM_M_DCU2*/
    {{0x4D4, 32}},  /*VH RIOM_M_DCU3*/
    {{0x4D5, 16}},  /*VH RIOM_M_DCU4*/
    {{0x4D6, 32}},  /*VH RIOM_M_FDS1*/
    {{0x4D7, 32}},  /*VH RIOM_M_FDS2*/
    {{0x4D8, 32}}, /*VH RIOM_M_FDS3*/
    {{0x4D9, 16}}, /*VH RIOM_M_ATS1*/
    {{0x4DA, 32}}, /*VH RIOM_M_PAPIS1*/
    {{0x4DB, 32}}, /*VH RIOM_M_PAPIS2*/
    {{0x4DC, 32}}, /*VH RIOM_M_PAPIS3*/
    {{0x4DD, 32}}, /*VH RIOM_M_PAPIS4*/
    /*BCU*/
    {{0x6C1, 32}}, /*BCU_1*/
    {{0x6C2, 16}}, /*BCU_2*/
    {{0x6C3, 32}}, /*BCU_3*/
    /*TCU*/
    /*WTB GW*/
}};

/*APU mesajları eklenecek*/
constexpr std::array<UNSIGNED16, 13>  mvb_sink_addresses_oa1 = {{
    {{ 0x441, 8}},    /*OA1 RIOM_M_STATUS*/
    {{ 0x451, 3}},   /*OA1 RIOM_M INPUTS*/
    {{ 0x452, 3}},   /*OA1 RIOM_M_DCU1*/
    {{ 0x453, 3}},   /*OA1 RIOM_M_DCU2*/
    {{ 0x454, 1}},   /*OA1 RIOM_M_DCU3*/
    {{ 0x455, 1}},   /*OA1 RIOM_M_DCU4*/
    /*ETCS*/
    {{ 0x941, 32}},   /*ETCS1*/
    {{ 0x942, 32}},   /*ETCS2*/
    {{ 0x943, 32}},   /*ETCS3*/
    /*BCU*/
    {{ 0x641, 32}},  /*BCU_1*/
    {{ 0x642, 16}}, /*BCU_2*/
    {{ 0x643, 32}}, /*BCU_3*/
    /*JRU*/
    {{ 0xA41, 32}},   /*JRU_1*/
    /*APU*/
    
    
}};
/*APU mesajları eklenecek*/
constexpr std::array<UNSIGNED16, 13>  mvb_sink_addresses_oa2 = {{
    {{ 0x481, 8 }},    /*OA2 RIOM_M_DCU3*/
    {{ 0x491, 32}},   /*OA2 RIOM_M INPUTS*/
    {{ 0x492, 32}},   /*OA2 RIOM_M_DCU1*/
    {{ 0x493, 32}},   /*OA2 RIOM_M_DCU2*/
    {{ 0x494, 16}},   /*OA2 RIOM_M_DCU3*/
    {{ 0x495, 16}},   /*OA2 RIOM_M_DCU4*/
    /*ETCS*/
    {{ 0x981, 32}},   /*ETCS1*/
    {{ 0x982, 32}},   /*ETCS2*/
    {{ 0x983, 32}},   /*ETCS3*/
    /*BCU*/
    {{ 0x681, 32}}, /*BCU_1*/
    {{ 0x682, 16}}, /*BCU_2*/
    {{ 0x683, 32}}, /*BCU_3*/
    /*JRU*/
    {{0xA81, 32}}  /*JRU_1*/
    /*APU*/
}};

constexpr std::array<UNSIGNED16, 23>  mvb_source_adresses_ccu = {{
    
    {{0x101, 16}},    /*GLOBAL OUT_1*/
    {{0x102, 16}},    /*GLOBAL OUT_2*/
    {{0x111, 16}},    /*GLOBAL ALL RIOM_1*/
    {{0x112, 16}},    /*GLOBAL ALL RIOM_2*/
    /*JRU*/
    {{0x1A1, 32}},    /*JRU_1*/
    {{0x1A2, 32}},    /*JRU_2*/
    {{0x1A3, 32}},    /*JRU_3*/
    {{0x1A4, 32}},    /*JRU_4*/
    {{0x1A5, 32}},    /*JRU_5*/
    /*RIOMS*/
    {{0x011, 8 }},    /*SKA1_DD RIOM_1 OUTPUTS*/
    {{0x021, 8 }},    /*SKA2_DD RIOM_1 OUTPUTS*/
    {{0x031, 16}},   /*SKA1_VH RIOM_1 OUTPUTS*/
    {{0x032, 8 }},    /*SKA1_VH RIOM_1 DOOR COMMANDS*/
    {{0x091, 16}},   /*SKA2_VH RIOM_1 OUTPUTS*/
    {{0x092, 8 }},    /*SKA2_VH RIOM_1 DOOR COMMANDS*/
    {{0x051, 16}},   /*OA1_VH RIOM_1 OUTPUTS*/
    {{0x052, 8 }},    /*OA1_VH RIOM_1 DOOR COMMANDS*/
    {{0x071, 16}},   /*OA2_VH RIOM_1 OUTPUTS*/
    {{0x072, 8 }},    /*OA2_VH RIOM_1 DOOR COMMANDS*/
    /*ETCS*/
    {{0x191, 32}},   /*ETCS_OA1*/
    {{0x192, 32}},   /*ETCS_OA2*/
    {{0x197, 32}},   /*ETCS_ALL*/
    /*BCU*/
    {{0x161, 16}},   /*GLOBAL BCU*/
    /*APU*/
    /*TCU*/
    /*WTB*/

}};
//ETC , JRU, WTB, APU yok galiba, sadece RIOM

enum CCU_OUT_PORTS{
    SKA1_DD_RIOM_1_OUTPUTS          = 0x011,
    SKA2_DD_RIOM_1_OUTPUTS          = 0x021,
    SKA1_VH_RIOM_1_OUTPUTS          = 0x031,
    SKA1_VH_RIOM_1_DOOR_COMMANDS    = 0x032,
    SKA2_VH_RIOM_1_OUTPUTS          = 0x091,
    SKA2_VH_RIOM_1_DOOR_COMMANDS    = 0x092,
    OA1_VH_RIOM_1_OUTPUTS           = 0x051,
    OA1_VH_RIOM_1_DOOR_COMMANDS     = 0x052,
    OA2_VH_RIOM_1_OUTPUTS           = 0x071,
    OA2_VH_RIOM_1_DOOR_COMMANDS     = 0x072

};


enum CCU_OUT_PORTS_SIZE{
    SKA1_DD_RIOM_1_OUTPUTS_SIZE         = 8 ,
    SKA2_DD_RIOM_1_OUTPUTS_SIZE         = 8 ,
    SKA1_VH_RIOM_1_OUTPUTS_SIZE         = 16,
    SKA1_VH_RIOM_1_DOOR_COMMANDS_SIZE   = 8 ,
    SKA2_VH_RIOM_1_OUTPUTS_SIZE         = 16,
    SKA2_VH_RIOM_1_DOOR_COMMANDS_SIZE   = 8 ,
    OA1_VH_RIOM_1_OUTPUTS_SIZE          = 16,
    OA1_VH_RIOM_1_DOOR_COMMANDS_SIZE    = 8 ,
    OA2_VH_RIOM_1_OUTPUTS_SIZE          = 16,
    OA2_VH_RIOM_1_DOOR_COMMANDS_SIZE    = 8

};

/*
enum CCU_IN_PORTS{

    ska1_vh_riom_ccu_mvb9_ats_port                 = 0x419,
    ska2_vh_riom_ccu_mvb9_ats_port                 = 0x4D9,
    ska1_bcu_ccu_mvb1_port                 = 0x601,
    ska2_bcu_ccu_mvb1_port                = 0x6C1,

    ska1_vh_riom_ccu_mvb2_dcu1_port                = 0x412,
    ska2_vh_riom_ccu_mvb2_dcu1_port                = 0x4D2,


    ska1_dd_riom_ccu_mvb_status_port             = 0x201, //STATUS M Ve R OLAYI NEDİR
    ska2_dd_riom_ccu_mvb_status_port             = 0x2C1,

    ska1_dd_riom_ccu_mvb1_inputs_port = 0x211,
    ska2_dd_riom_ccu_mvb1_inputs_port = 0x2D1,

    ska1_vh_riom_ccu_mvb6_fds1_port                 = 0x416,
    ska2_vh_riom_ccu_mvb6_fds1_port              = 0x4D6,
    ska1_vh_riom_ccu_mvb7_fds2_port     = 0x417,
    ska2_vh_riom_ccu_mvb7_fds2_port = 0x4D7,
    ska1_vh_riom_ccu_mvb8_fds3_port = 0x418,
    ska2_vh_riom_ccu_mvb8_fds3_port = 0x4D8,

    ska1_vh_riom_ccu_mvb10_papis1_port               = 0x41A,
    ska2_vh_riom_ccu_mvb10_papis1_port               = 0x4DA,
    ska1_vh_riom_ccu_mvb11_papis2_port =  0x41B,
    ska2_vh_riom_ccu_mvb11_papis2_port = 0x4DB,
    ska1_vh_riom_ccu_mvb12_papis3_port = 0x41C,
    ska2_vh_riom_ccu_mvb12_papis3_port = 0x4DC,
    ska1_vh_riom_ccu_mvb13_papis4_port = 0x41D,
    ska2_vh_riom_ccu_mvb13_papis4_port = 0x4DD,


    ska1_vh_riom_ccu_mvb_status_port             = 0x401,
    ska2_vh_riom_ccu_mvb_status_port             = 0x4c1,
    ska1_vh_riom_ccu_mvb1_d_inputs_port = 0x411,
    ska2_vh_riom_ccu_mvb1_d_inputs_port = 0x4D1,



    oa1_bcu_ccu_mvb1_port                  = 0x641,
    oa2_bcu_ccu_mvb1_port                  = 0x681,
    oa1_bcu_ccu_mvb2_port = 0x642,
    oa2_bcu_ccu_mvb2_port = 0x682,
    oa1_bcu_ccu_mvb3_port = 0x643,
    oa2_bcu_ccu_mvb3_port = 0x683,


    oa1_vh_riom_ccu_mvb2_dcu1_port                  = 0x452,
    oa2_vh_riom_ccu_mvb2_dcu1_port                   = 0x492,
    oa1_vh_riom_ccu_mvb3_dcu2_port = 0x453,
    oa2_vh_riom_ccu_mvb3_dcu2_port = 0x493,
    oa1_vh_riom_ccu_mvb4_dcu3_port = 0x454,
    oa2_vh_riom_ccu_mvb4_dcu3_port = 0x494,
    oa1_vh_riom_ccu_mvb5_dcu4_port = 0x455,
    oa2_vh_riom_ccu_mvb5_dcu4_port = 0x495,



    oa1_etcs_ccu_mvb1_port               = 0x941,
    oa2_etcs_ccu_mvb1_port                 = 0x981,
    oa1_etcs_ccu_mvb2_port = 0x942,
    oa2_etcs_ccu_mvb2_port = 0x982,
    oa1_etcs_ccu_mvb3_port = 0x943,
    oa2_etcs_ccu_mvb3_port = 0x983,



    oa1_jru_ccu_mvb1_port                 = 0xA41,
    oa2_jru_ccu_mvb1_port                 = 0xA81,


    o1_vh_riom_ccu_mvb_status_port              = 0x441,
    o2_vh_riom_ccu_mvb_status_port              = 0x481

};

*/





enum CCU_IN_PORTS{

    SKA1_ATS_INPUTS                 = 0x419,
    SKA2_ATS_INPUTS                 = 0x4D9,
    SKA1_BCU_INPUTS                 = 0x601,
    SKA2_BCU_INPUTS                 = 0x6C1,
    SKA1_CCU_DI_CARD_INPUTS         = 0x250,
    //SKA2_CCU_DI_CARD_INPUTS         = 0x222,
    SKA1_CCU_DO_CARD_INPUTS         = 0x331,
    SKA2_CCU_DO_CARD_INPUTS         = 0x443,//Kendim atadım
    SKA1_DCU_INPUTS                 = 0x412,
    SKA2_DCU_INPUTS                 = 0x4D2,
    SKA1_DD_RIOM_INPUTS             = 0x201,
    SKA2_DD_RIOM_INPUTS             = 0x2C1,
    SKA1_FDS_INPUTS                 = 0x416,
    SKA2_FDS_INPUTS                 = 0x4D6,
    SKA1_PAPIS_INPUTS               = 0x41A,
    SKA2_PAPIS_INPUTS               = 0x4DA,
    SKA1_TCU1_INPUTS                = 0x701,
    SKA2_TCU1_INPUTS                = 0x7C1,
    SKA1_TCU2_INPUTS                = 0x708,
    SKA2_TCU2_INPUTS                = 0x7C8,
    SKA1_VH_RIOM_INPUTS             = 0x401,
    SKA2_VH_RIOM_INPUTS             = 0x4C1,
    SKA1_HVAC_INPUTS                = 0x41D,
    SKA2_HVAC_INPUTS                = 0x4DD,
    OA1_BCU_INPUTS                  = 0x641,
    OA2_BCU_INPUTS                  = 0x681,
    OA1_DCU_INPUTS                  = 0x452,
    OA2_DCU_INPUTS                  = 0x492,
    OA1_ETCS_INPUTS                 = 0x941,
    OA2_ETCS_INPUTS                 = 0x981,
    OA1_JRU_INPUTS                  = 0xA41,
    OA2_JRU_INPUTS                  = 0xA81,
    OA1_HVAC_INPUTS                 = 0x456,
    OA2_HVAC_INPUTS                 = 0x496,
    OA1_VH_RIOM_INPUTS              = 0x441,
    OA2_VH_RIOM_INPUTS              = 0x481,
    OA1_APU_INPUTS                  = 0x841,
    OA2_APU_INPUTS                  = 0x881

};

//ska_vh_riom_ccu_mvb9_ats_port
enum CCU_IN_PORTS_SIZE{

    SKA1_ATS_INPUTS_SIZE                  = 16,
    SKA2_ATS_INPUTS_SIZE                  = 16,
    SKA1_BCU_INPUTS_SIZE                  = 48,
    SKA2_BCU_INPUTS_SIZE                  = 48,
    SKA1_CCU_DI_CARD_INPUTS_SIZE          = 2,
    SKA2_CCU_DI_CARD_INPUTS_SIZE          = 2,
    SKA1_CCU_DO_CARD_INPUTS_SIZE          = 0,
    SKA2_CCU_DO_CARD_INPUTS_SIZE          = 0,
    SKA1_DCU_INPUTS_SIZE                  = 112,
    SKA2_DCU_INPUTS_SIZE                  = 112,
    SKA1_DD_RIOM_INPUTS_SIZE              = 32,
    SKA2_DD_RIOM_INPUTS_SIZE              = 32,
    SKA1_FDS_INPUTS_SIZE                  = 96,
    SKA2_FDS_INPUTS_SIZE                  = 96,
    SKA1_PAPIS_INPUTS_SIZE                = 96,
    SKA2_PAPIS_INPUTS_SIZE                = 96,
    SKA1_VH_RIOM_INPUTS_SIZE              = 48,
    SKA2_VH_RIOM_INPUTS_SIZE              = 48,
    OA1_BCU_INPUTS_SIZE                   = 48,
    OA2_BCU_INPUTS_SIZE                   = 48,
    OA1_DCU_INPUTS_SIZE                   = 112,
    OA2_DCU_INPUTS_SIZE                   = 112,
    OA1_ETCS_INPUTS_SIZE                  = 96,
    OA2_ETCS_INPUTS_SIZE                  = 96,
    OA1_JRU_INPUTS_SIZE                   = 32,
    OA2_JRU_INPUTS_SIZE                   = 32,
    OA1_VH_RIOM_INPUTS_SIZE               = 48,
    OA2_VH_RIOM_INPUTS_SIZE               = 48,
    OA1_HVAC_INPUTS_SIZE                  = 64,
    OA2_HVAC_INPUTS_SIZE                  = 64,
    SKA1_HVAC_INPUTS_SIZE                 = 96,
    SKA2_HVAC_INPUTS_SIZE                 = 96,
    SKA1_TCU1_INPUTS_SIZE                 = 64,
    SKA2_TCU1_INPUTS_SIZE                 = 64,
    SKA1_TCU2_INPUTS_SIZE                 = 64,
    SKA2_TCU2_INPUTS_SIZE                 = 64,
    OA1_APU_INPUTS_SIZE                   = 80,
    OA2_APU_INPUTS_SIZE                   = 80



};

