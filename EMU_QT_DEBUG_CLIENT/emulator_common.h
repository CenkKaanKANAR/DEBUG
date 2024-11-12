#ifndef EMULATOR__H
#define EMULATOR__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>




struct emulator_config
{
    union
    {
        uint8_t bytes[8];
        struct
        {
            uint8_t emul_connected :1;  //byte0
            uint8_t emul_in_config_mode :1;
            uint8_t emul_ready :1;/*config completed*/
            uint8_t reserved3 :1;/*config completed*/
            uint8_t reserved4 :1;/*config completed*/
            uint8_t reserved5 :1;/*config completed*/
            uint8_t ska_input :1;/*config completed*/ /*0X250 2bytes*/
            uint8_t reserved7 : 1;
            uint8_t ska1_ddinputs_m:1;  /*0x211 16*/  				//byte1
            uint8_t ska1_vhinputs_m:1;  /*0x411 32*/
            uint8_t ska2_ddinputs_m:1;  /*0x2D1 16*/
            uint8_t ska2_vhinputs_m:1;  /*0x4D1 32*/
            uint8_t oa1_vhinputs_m:1;   /*0x451 32*/
            uint8_t oa2_vhinputs_m:1;   /*0x491 32*/
            uint8_t ska1_dcu:1;         /*0x412 32 32 32 16*/
            uint8_t ska2_dcu:1;         /*0x4D2 32 32 32 16*/
            uint8_t oa1_dcu:1;          /*0x452 32 32 32 16*/		//byte2
            uint8_t oa2_dcu:1;          /*0x492 32 32 32 16*/
            uint8_t ska1_fds:1;         /*0x416 32 32 32*/
            uint8_t ska2_fds:1;         /*0x4D6 32 32 32*/
            uint8_t ska1_hvac:1;     	/*0x41D 32 32 32*/
            uint8_t ska2_hvac:1;     	/*0X4DD 32 32 32*/
            uint8_t reserved22:1;       /*reserved added instead of ska1_hvac_ps*/
            uint8_t reserved23:1;       /*reserved added instead of ska2_hvac_ps*/   /*3rd byte*/
            uint8_t oa1_hvac:1;     	 /*0x456 32 32*/
            uint8_t oa2_hvac:1;      	 /*0x496 32 32*/
            uint8_t ska1_papis:1;       /*0x41A 32 32 32 */
            uint8_t ska2_papis:1;       /*0x4DA 32 32 32 */
            uint8_t ska1_ats:1;         /*0x419 16*/
            uint8_t ska2_ats:1;         /*0x4D9 16*/
            uint8_t ska1_bcu:1;         /*0x601 32 16 32*/
            uint8_t ska2_bcu:1;         /*0x6C1 32 16 32*/     //byte4
            uint8_t oa1_bcu:1;          /*0x641 32 16*/
            uint8_t oa2_bcu:1;          /*0x681 32 16*/
            uint8_t oa1_etcs:1;         /*0x941 32 32 32*/
            uint8_t oa2_etcs:1;         /*0x981 32 32 32*/
            uint8_t oa1_jru:1;          /*0xA41 32*/
            uint8_t oa2_jru:1;          /*0xA81 32*/
            uint8_t oa1_apu:1;          /*0X841 16 32 32*/
            uint8_t oa2_apu:1;          /*0X881 16 32 32*/     //byte5
            uint8_t ska1_tcu1:1;         /*0x701 32 32*/
            uint8_t ska1_tcu2:1;         /*0x708 32 32*/
            uint8_t ska2_tcu1:1;         /*0x7C1 32 32*/
            uint8_t ska2_tcu2:1;         /*0x7C8 32 32*/
            uint8_t ska1_wtbgw:1;       /**/
            uint8_t ska2_wtbgw:1;       /**/
            uint8_t ska1_hmi:1;         /**/
            uint8_t ska2_hmi:1;         /**/           //byte6
            uint16_t portId;

        }bits;
    };

};


typedef enum emulator_states
{
    INIT,
    WAIT,
    COMMUNICATE
}emulator_states_t;

typedef struct emulator_config emulator_config_t;


#endif/*EMULATOR__H*/
