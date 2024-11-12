#ifndef __SHM_DATA_GAZIRAY_H__
#define __SHM_DATA_GAZIRAY_H__

#ifdef __cplusplus
extern "C" {
#endif

//#include "error_info/errors_struct.h"
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

#define NUM_TCUS 4
#define NUM_APUS 2
#define NUM_HVACS 10
#define NUM_BCUS 4
#define NUM_DCUS 32
#define NUM_JRUS 2
#define NUM_ETCS 2
#define NUM_FDUS 2
#define NUM_PAPIS 2
#define NUM_GWS 2

#define __ATTR_PACKED __attribute__((__packed__))

#define UPDATE_TIMESTAMP(obj) ((obj)->last_update = time(NULL))

#define BYTES_TO_WORDS(nbytes) \
(((nbytes) % 2 == 0 ? (nbytes) : (nbytes) + 1) / 2)

#define BYTES_TO_DWORDS(nbytes) \
    (((nbytes) % 4 == 0 ? (nbytes) : (nbytes) + (4 - ((nbytes) % 4))) / 4)

#define BYTES_TO_QWORDS(nbytes) \
    (((nbytes) % 8 == 0 ? (nbytes) : (nbytes) + (8 - ((nbytes) % 8))) / 8)

//#pragma pack(1)

#define IO_RAW_NBYTES_8 8
#define IO_RAW_NBYTES_16 16
#define IO_RAW_NBYTES_32 32

    struct life_sign_counter {
    union {
        uint8_t bytes[2];
        uint16_t words[BYTES_TO_WORDS(2)];
        struct {
            uint16_t byte0 : 8;
            uint16_t byte1 : 8;

        } bits;
    };
};

struct ska_ccu_di_card {
    union {
        uint8_t bytes[2];
        uint16_t words[BYTES_TO_WORDS(2)];
        struct {
            uint8_t CCU_DI0 : 1;
            uint8_t CCU_DI1 : 1;
            uint8_t CCU_DI2 : 1;
            uint8_t CCU_DI3 : 1;
            uint8_t CCU_DI4 : 1;
            uint8_t CCU_DI5 : 1;
            uint8_t CCU_DI6 : 1;
            uint8_t CCU_DI7 : 1;
            uint8_t CCU_DI8 : 1;
            uint8_t CCU_DI9 : 1;
            uint8_t CCU_DI10 : 1;
            uint8_t CCU_DI11 : 1;
            uint8_t bit12 : 1;
            uint8_t bit13 : 1;
            uint8_t bit14 : 1;
            uint8_t bit15 : 1;
        } bits;
    };

};

struct ska_ccu_do_card {
    union {
        uint8_t bytes[1];
        uint16_t words[BYTES_TO_WORDS(2)];
        struct {
            uint8_t CCU_DO0 : 1;
            uint8_t CCU_DO1 : 1;
            uint8_t CCU_DO2 : 1;
            uint8_t CCU_DO3 : 1;
            uint8_t bit4 : 1;
            uint8_t bit5 : 1;
            uint8_t bit6 : 1;
            uint8_t bit7 : 1;
        } bits;
    };

};

/**
 * SKA1_DD_M	0x201
 * SKA1_DD_R	0x202
 * SKA2_DD_M	0x2C1
 * SKA2_DD_R	0x2C2
 * v1.06
 */
struct ska_dd_riom_ccu_mvb_status {
    union {
        uint8_t bytes[IO_RAW_NBYTES_16];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_16)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_16)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_16)];
        struct {
            uint16_t lifesign;//byte 0
            uint8_t DIO01_Module_Error :1; //byte 2
            uint8_t DIO01_Output_Overcurrent :1;
            uint8_t DIO01_Heartbeat_error :1;
            uint8_t DIO01_Group_1_Voltage_error :1;
            uint8_t DIO01_Group_2_Voltage_error :1;
            uint8_t DIO01_Board_Temperature_error :1;
            uint8_t bit22 :1;
            uint8_t bit23 :1;
            uint8_t DIO02_Module_Error :1;//byte 3
            uint8_t DIO02_Output_Overcurrent :1;
            uint8_t DIO02_Heartbeat_error :1;
            uint8_t DIO02_Group_1_Voltage_error :1;
            uint8_t DIO02_Group_2_Voltage_error :1;
            uint8_t DIO02_Board_Temperature_error :1;
            uint8_t bit30 :1;
            uint8_t bit31 :1;
            uint8_t DIO03_Module_Error :1;//byte 4
            uint8_t DIO03_Output_Overcurrent :1;
            uint8_t DIO03_Heartbeat_error :1;
            uint8_t DIO03_Group_1_Voltage_error :1;
            uint8_t DIO03_Group_2_Voltage_error :1;
            uint8_t DIO03_Board_Temperature_error :1;
            uint8_t bit38 :1;
            uint8_t bit39 :1;
            uint8_t DIO04_Module_Error :1;//byte 5
            uint8_t DIO04_Output_Overcurrent :1;
            uint8_t DIO04_Heartbeat_error :1;
            uint8_t DIO04_Group_1_Voltage_error :1;
            uint8_t DIO04_Group_2_Voltage_error :1;
            uint8_t DIO04_Board_Temperature_error :1;
            uint8_t bit46 :1;
            uint8_t bit47 :1;
            uint8_t reserved_6;//byte 6
            uint8_t reserved_7;//byte 7
            uint8_t reserved_8;//byte 8
            uint8_t AIM01_Module_Error :1;//byte 9
            uint8_t AIM01_Heartbeat_error :1;
            uint8_t bit74 :1;
            uint8_t bit75 :1;
            uint8_t bit76 :1;
            uint8_t bit77 :1;
            uint8_t bit78 :1;
            uint8_t bit79 :1;
            uint8_t PTI2037A_Module_Error :1;//byte 10
            uint8_t PTI2037A_Heartbeat_error :1;
            uint8_t PTI2037A_Channel_1_Status :1;
            uint8_t PTI2037A_Channel_2_Status :1;
            uint8_t PTI2037A_Channel_3_Status :1;
            uint8_t PTI2037A_Channel_4_Status :1;
            uint8_t PTI2037A_Channel_5_Status :1;
            uint8_t PTI2037A_Channel_6_Status :1;
            uint8_t reserved_11;//byte 11
            uint8_t reserved_12;//byte 12
            uint8_t reserved_13;//byte 13
            uint8_t reserved_14;//byte 14
            uint8_t reserved_15;//byte 15
        } bits;
    };
};
/**
 * SKA1_DD	0x211
 * OA1	-
 * OA2	-
 * SKA2_DD	0x2D1
 * v1.06
*/

struct ska_dd_riom_ccu_mvb1_inputs {
    union {
        uint8_t bytes[IO_RAW_NBYTES_16];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_16)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_16)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_16)];

        struct {
            uint8_t PB_EMERGENCY_LOWERING_PANTOGRAPH : 1; //byte 0
            uint8_t RELAY_KEY_DRIVER_DESK_CABINET : 1;
            uint8_t LAMP_TEST : 1;
            uint8_t ON_OFF_MODE_PARKING : 1;
            uint8_t CLOSING_VACUUM_CIRCUIT_BREAKER : 1;
            uint8_t OPENING_VACUUM_CIRCUIT_BREAKER : 1;
            uint8_t RAISING_PANTOGRAPH_1 : 1;
            uint8_t DOWN_PANTOGRAPH_1 : 1;
            uint8_t RAISING_PANTOGRAPH_2 : 1; //byte 1
            uint8_t DOWN_PANTOGRAPH_2 : 1;
            uint8_t LEVER_SPEED_0 : 1;
            uint8_t LEVER_SPEED_1 : 1;
            uint8_t bit12 : 1;
            uint8_t bit13 : 1;
            uint8_t bit14 : 1;
            uint8_t bit15 : 1;
            uint8_t bit16 : 1; //byte 2
            uint8_t DEVICE_ID_DI_0 : 1;
            uint8_t DEVICE_ID_DI_1 : 1;
            uint8_t DEVICE_ID_DI_2 : 1;
            uint8_t DEVICE_ID_DI_3 : 1;
            uint8_t DEVICE_ID_DI_4 : 1;
            uint8_t DEVICE_ID_DI_5 : 1;
            uint8_t CONTROL_DESK_TEST_HW_OK_HEALT_RIOM_2 : 1;
            uint8_t MC_EMERGENCY_BRAKE : 1; //byte 3
            uint8_t PRESSURE_GOVERNOR_INDIRECT_BRAKE_CONTROL : 1;
            uint8_t MC_S1 : 1;
            uint8_t MC_S2 : 1;
            uint8_t MC_S3 : 1;
            uint8_t MC_S4 : 1;
            uint8_t MC_S5 : 1;
            uint8_t MC_S6 : 1;
            uint8_t NEUTRAL_N_DIRECTION : 1; //byte 4
            uint8_t FORWARD_F_DIRECTION : 1;
            uint8_t REVERSE_R_DIRECTION : 1;
            uint8_t AUTOMATIC_DUMPER : 1;
            uint8_t CONTROL_DESK_RIOM_1_CB_PROTECTION : 1;
            uint8_t HATCH_FULL_CLOSED : 1;
            uint8_t HATCH_FULL_OPEN : 1;
            uint8_t bit39 : 1;
            uint8_t bit40 : 1; //byte 5
            uint8_t bit41 : 1;
            uint8_t bit42 : 1;
            uint8_t bit43 : 1;
            uint8_t bit44 : 1;
            uint8_t bit45 : 1;
            uint8_t bit46 : 1;
            uint8_t bit47 : 1;
            uint8_t MANUAL_CLOSING_DUMPER : 1; //byte 6
            uint8_t PARKING_BRAKE_APPLICATION : 1;
            uint8_t PARKING_BRAKE_RELEASE : 1;
            uint8_t PUSHBUTTON_EMERGENCY : 1;
            uint8_t INDIRECT_BRAKE_MANIPULATOR : 1;
            uint8_t DMU_FAULT_SIGNAL : 1;
            uint8_t SANDING_COMMAND_AUTO : 1;
            uint8_t SANDING_COMMAND_LONG_TIME : 1;
            uint8_t SANDING_COMMAND_SHORT_TIME : 1; //byte 7
            uint8_t EMERGENCY_EGRESS_DEVICE_INPUT : 1;
            uint8_t OPENING_DOORS_1357 : 1;
            uint8_t ENABLE_DOORS_1357 : 1;
            uint8_t CONTROL_DESK_RIOM_2_CB_PROTECTION : 1;
            uint8_t bit61 : 1;
            uint8_t bit62 : 1;
            uint8_t bit63 : 1;
            uint8_t bit64 : 1; //byte 8
            uint8_t bit65 : 1;
            uint8_t bit66 : 1;
            uint8_t bit67 : 1;
            uint8_t bit68 : 1;
            uint8_t bit69 : 1;
            uint8_t bit70 : 1;
            uint8_t bit71 : 1;
            uint8_t OPENING_DOORS_2468 : 1; //byte 9
            uint8_t ENABLE_DOORS_2468 : 1;
            uint8_t PB_CLOSING_DOORS : 1;
            uint8_t DECOUPLING_AUTOMATIC_COUPLER : 1;
            uint8_t FIRE_ALARM_RESET_FAULT_RESET : 1;
            uint8_t WINDSCREEN_HEATING : 1;
            uint8_t WIPER_SYSTEM_FUNCTION_OK : 1;
            uint8_t WIPER_LEVEL_WASH_WATER_TANK : 1;
            uint8_t FULL_LIGHT_MARKER_LIGHT : 1; //byte 10
            uint8_t DIMMED_HEAD_LIGHT_MARKER_LIGHT : 1;
            uint8_t MARKER_LIGHT : 1;
            uint8_t DIMMED_MARKER_LIGHT : 1;
            uint8_t bit84 : 1;
            uint8_t bit85 : 1;
            uint8_t bit86 : 1;
            uint8_t bit87 : 1;
            uint8_t bit88 : 1; //byte 11
            uint8_t bit89 : 1;
            uint8_t bit90 : 1;
            uint8_t bit91 : 1;
            uint8_t bit92 : 1;
            uint8_t bit93 : 1;
            uint8_t bit94 : 1;
            uint8_t bit95 : 1;
            uint16_t signal_speed; //byte 12
            uint8_t reserved_14;
            uint8_t reserved_15;

        } bits;
        time_t last_update;
    };
};

/**
 * SKA1_VH_M	0x401
 * SKA1_VH_R	0x402
 * SKA2_VH_M	0x4C1
 * SKA2_VH_R	0x4C2
 * v1.07
*/
struct ska_vh_riom_ccu_mvb_status {
    union {
        uint8_t bytes[IO_RAW_NBYTES_16];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_16)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_16)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_16)];
        struct {
            uint16_t  lifesign ;//byte 0
            uint8_t DIO01_Module_Error : 1;// byte 2
            uint8_t DIO01_Output_Overcurrent : 1;
            uint8_t DIO01_Heartbeat_error : 1;
            uint8_t DIO01_Group_1_Voltage_error : 1;
            uint8_t DIO01_Group_2_Voltage_error : 1;
            uint8_t DIO01_Board_Temperature_error : 1;
            uint8_t bit22 : 1;
            uint8_t bit23 : 1;
            uint8_t DIO02_Module_Error : 1;//byte 3
            uint8_t DIO02_Output_Overcurrent : 1;
            uint8_t DIO02_Heartbeat_error : 1;
            uint8_t DIO02_Group_1_Voltage_error : 1;
            uint8_t DIO02_Group_2_Voltage_error : 1;
            uint8_t DIO02_Board_Temperature_error : 1;
            uint8_t bit30 : 1;
            uint8_t bit31 : 1;
            uint8_t DIO03_Module_Error : 1;//byte 4
            uint8_t DIO03_Output_Overcurrent : 1;
            uint8_t DIO03_Heartbeat_error : 1;
            uint8_t DIO03_Group_1_Voltage_error : 1;
            uint8_t DIO03_Group_2_Voltage_error : 1;
            uint8_t DIO03_Board_Temperature_error : 1;
            uint8_t bit38 : 1;
            uint8_t bit39 : 1;
            uint8_t DIO04_Module_Error : 1;//byte 5
            uint8_t DIO04_Output_Overcurrent : 1;
            uint8_t DIO04_Heartbeat_error : 1;
            uint8_t DIO04_Group_1_Voltage_error : 1;
            uint8_t DIO04_Group_2_Voltage_error : 1;
            uint8_t DIO04_Board_Temperature_error : 1;
            uint8_t bit46 : 1;
            uint8_t bit47 : 1;
            uint8_t DIO05_Module_Error : 1;//byte 6
            uint8_t DIO05_Output_Overcurrent : 1;
            uint8_t DIO05_Heartbeat_error : 1;
            uint8_t DIO05_Group_1_Voltage_error : 1;
            uint8_t DIO05_Group_2_Voltage_error : 1;
            uint8_t DIO05_Board_Temperature_error : 1;
            uint8_t bit54 : 1;
            uint8_t bit55 : 1;
            uint8_t DIO06_Module_Error : 1;//byte 7
            uint8_t DIO06_Output_Overcurrent : 1;
            uint8_t DIO06_Heartbeat_error : 1;
            uint8_t DIO06_Group_1_Voltage_error : 1;
            uint8_t DIO06_Group_2_Voltage_error : 1;
            uint8_t DIO06_Board_Temperature_error : 1;
            uint8_t bit62 : 1;
            uint8_t bit63 : 1;
            uint8_t DIO07_Module_Error : 1;//byte 8
            uint8_t DIO07_Output_Overcurrent : 1;
            uint8_t DIO07_Heartbeat_error : 1;
            uint8_t DIO07_Group_1_Voltage_error : 1;
            uint8_t DIO07_Group_2_Voltage_error : 1;
            uint8_t DIO07_Board_Temperature_error : 1;
            uint8_t bit70 : 1;
            uint8_t bit71 : 1;
            uint8_t reserved_9; //byte 9
            uint8_t reserved_10;//byte 10
            uint8_t reserved_11;//byte 11
            uint8_t reserved_12;//byte 12
            uint8_t R1_DCU_CANopen_Fault : 1;
            uint8_t R2_DCU_CANopen_Fault : 1;
            uint8_t R3_DCU_CANopen_Fault : 1;
            uint8_t R4_DCU_CANopen_Fault : 1;
            uint8_t L1_DCU_CANopen_Fault : 1;
            uint8_t L2_DCU_CANopen_Fault : 1;
            uint8_t L3_DCU_CANopen_Fault : 1;
            uint8_t L4_DCU_CANopen_Fault : 1;
            uint8_t FDS_CANopen_Fault : 1;
            uint8_t ATS_CANopen_Fault : 1;
            uint8_t PAPIS_CANopen_Fault : 1;
            uint8_t HVAC_C_CANopen_Fault : 1;
            uint8_t HVAC_1_CANopen_Fault : 1;
            uint8_t HVAC_2_CANopen_Fault : 1;
            uint8_t bit118 : 1;
            uint8_t bit119 : 1;
            uint8_t reserved_15;//byte 15

        } bits;
        time_t last_update;
    };
};
/**
 * SKA1_VH	0x411
 * OA1	-
 * OA2	-
 * SKA2_VH	0x4D1
 * v1.07
*/
struct ska_vh_riom_ccu_mvb1_d_inputs {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint8_t MANUALPOWER_SUPPLY_PRIVILEGED_LOAD_Lp : 1; //byte-0
            uint8_t CONTACTOR_PRIVILEGE_LOAD_Lp : 1;
            uint8_t DRIVER_LOAD_SELECTOR_ON : 1;
            uint8_t PLANT_3_0_CB_PROTECTION : 1;
            uint8_t CONTACTOR_MAINTENANCE_SKA_CAR : 1;
            uint8_t VACUUM_OPENING_BY_PASS : 1;
            uint8_t FAST_OPEN_VCB : 1;
            uint8_t PLANT_3_1_CB_PROTECTION : 1;
            uint8_t PLANT_3_2_CB_PROTECTION : 1; //byte 1
            uint8_t FAST_OPEN_ADD : 1;
            uint8_t TRAIN_KEY_DRIVER_DESK : 1;
            uint8_t RELAY_KEY_DRIVER_DESK_ECDD : 1;
            uint8_t COUPLED_TRAIN_TAIL_RELAY : 1;
            uint8_t PLANT_3_5_CB_PROTECTION : 1;
            uint8_t MV_OUTPUT_MOTOR_1_OK_TC_1 : 1;
            uint8_t MV_OUTPUT_MOTOR_2_OK_TC_1 : 1;
            uint8_t HV_PRESENCE_TO_TRACTION_TC_1 : 1; //byte 2
            uint8_t DEVICE_ID_DI_0 : 1;
            uint8_t DEVICE_ID_DI_1 : 1;
            uint8_t DEVICE_ID_DI_2 : 1;
            uint8_t DEVICE_ID_DI_3 : 1;
            uint8_t DEVICE_ID_DI_4 : 1;
            uint8_t DEVICE_ID_DI_5 : 1;
            uint8_t CABINET_TEST_HW_OK_HEALT_RIOM_2 : 1;
            uint8_t TRACTION_OK_2_TC_1 : 1; //byte 3
            uint8_t VCB_LOOP_OUT_TC_1 : 1;
            uint8_t TRACTION_ACTIVE_RELAY_TC_1 : 1;
            uint8_t EDB_BRAKE_ACTIVE_TC_1 : 1;
            uint8_t CFIR_TC_1 : 1;
            uint8_t SYSTEM_RESET_TC_1 : 1;
            uint8_t MV_OUTPUT_MOTOR_3_OK_TC_2 : 1;
            uint8_t MV_OUTPUT_MOTOR_4_OK_TC_2 : 1;
            uint8_t HV_PRESENCE_TO_TRACTION_TC_2 : 1; //byte 4
            uint8_t TRACTION_DC_LINK_OK_TC_2 : 1;
            uint8_t PANTOGRAPH_PERMISSION_TC_2 : 1;
            uint8_t TRACTION_OK_4_TC_2 : 1;
            uint8_t TRACTION_OK_3_TC_2 : 1;
            uint8_t VCB_LOOP_OUT_TC_2 : 1;
            uint8_t TRACTION_ACTIVE_RELAY_TC_2 : 1;
            uint8_t EDB_BRAKE_ACTIVE_TC_2 : 1;
            uint8_t CFIR_TC_2 : 1; //byte 5
            uint8_t SYSTEM_RESET_TC_2 : 1;
            uint8_t VENTILATION_TRACTION_CONVERTER_CB_PROTECTION : 1;
            uint8_t SL_CUT_OFF_BYPASS : 1;
            uint8_t TRACTION_OK_1_TC_1 : 1;
            uint8_t CONTACTOR_2_1_NORMAL_LOAD_Ln : 1;
            uint8_t TRACTION_DC_LINK_OK_TC_1 : 1;
            uint8_t PANTOGRAPH_PERMISSION_TC_1 : 1;
            uint8_t TRACTION_CUT_OFF_LOOP : 1; //byte 6
            uint8_t PLANT_3_7_CB_PROTECTION : 1;
            uint8_t HVAC_1_FLOOR_HEATER_1_START : 1;
            uint8_t HVAC_1_FLOOR_HEATER_2_START : 1;
            uint8_t HVAC_1_CB_PROTECTION : 1;
            uint8_t HVAC_2_FLOOR_HEATER_1_START : 1;
            uint8_t HVAC_2_FLOOR_HEATER_2_START : 1;
            uint8_t HVAC_2_CB_PROTECTION : 1;
            uint8_t HVAC_1_ON_INPUT : 1; //byte 7
            uint8_t HVAC_2_ON_INPUT : 1;
            uint8_t HVAC_CAB_CB_PROTECTION : 1;
            uint8_t THERMOSTAT_HEATING_LEFT_SIDE : 1;
            uint8_t CONTACTOR_HEATING_COMPARTMENT_LEFT_SIDE : 1;
            uint8_t HEATING_COMPARTMENT_LEFT_SIDE_CB_PROTECTION : 1;
            uint8_t THERMOSTAT_HEATING_RIGHT_SIDE : 1;
            uint8_t CONTACTOR_HEATING_COMPARTMENT_RIGHT_SIDE : 1;
            uint8_t HEATING_COMPARTMENT_RIGHT_SIDE_CB_PROTECTION : 1; //byte 8
            uint8_t PLANT_4_0_CB_PROTECTION : 1;
            uint8_t PRESSURE_GOVERNOR_BP_NO_EMERGENCY_BRAKE : 1;
            uint8_t PRESSURE_GOVERNOR_PB_RELEASED : 1;
            uint8_t bit68 : 1;
            uint8_t bit69 : 1;
            uint8_t bit70 : 1;
            uint8_t bit71 : 1;
            uint8_t PRESSURE_GOVERNOR_R_CPRESS_APPL_BO1 : 1; //byte 9
            uint8_t PRESSURE_GOVERNOR_R_CPRESS_APPL_BO2 : 1;
            uint8_t ISOLATION_COCKS_PNEUMATIC_BRAKE : 1;
            uint8_t ISOLATION_COCKS_DIRECT_BRAKE : 1;
            uint8_t ISOLATION_COCKS_INDIRECT_BRAKE : 1;
            uint8_t ISOLATION_COCKS_DIRECT_BRAKE_BO1 : 1;
            uint8_t ISOLATION_COCKS_DIRECT_BRAKE_BO2 : 1;
            uint8_t ISOLATION_COCKS_PB_ISOLATED : 1;
            uint8_t ISOLATION_COCKS_SAND_ISOLATED : 1; //byte 10
            uint8_t AIR_SUSPENSION_STATUSS : 1;
            uint8_t BYPASS_MRP_ISOLATION_COCK : 1;
            uint8_t EBCU_C_FCTOK : 1;
            uint8_t EBCU_SPEED_10_Km_H : 1;
            uint8_t PRESSURE_GOVERNORS_EB_DETECTION : 1;
            uint8_t PRESSURE_GOVERNORS_FSB_DETECTION : 1;
            uint8_t PRESSURE_GOVERNORS_INDIRECT_BRAKE_NOT_RELEASE : 1;
            uint8_t PRESSURE_GOVERNORS_AIR_SUSPENSION_BO1 : 1; //byte 11
            uint8_t PRESSURE_GOVERNORS_AIR_SUSPENSION_BO2 : 1;
            uint8_t ISOLATION_COCKS_BP_TO_MRP_BYPASS : 1;
            uint8_t ZERO_SPEED : 1;
            uint8_t EMERGENCY_BRAKE_FROM_BCU : 1;
            uint8_t WSP_R_vGt5kmhDoor : 1;
            uint8_t FDU_GENERAL_FAULT : 1;
            uint8_t FDU_GENERAL_FIRE : 1;
            uint8_t ZERO_SPEED_BY_PASS : 1; //byte 12
            uint8_t PLANT_4_5_CB_PROTECTION : 1;
            uint8_t ALARM_PASSENGERS_CB_PROTECTION : 1;
            uint8_t RELAY_ALARM_PASSENGERS : 1;
            uint8_t RELAY_SECURITY_EMERGENCY_LOOP_CB_PROTECTION : 1;
            uint8_t EMERGENCY_BRAKE_CB_PROTECTION : 1;
            uint8_t SELECTOR_BY_PASS_PASSANGER_ALARM : 1;
            uint8_t INIBITION_PASSENGERS_ALARM_ACTIVE : 1;
            uint8_t HANDLE_1_PASSENGER_ALARM : 1; //byte 13
            uint8_t HANDLE_3_PASSENGER_ALARM : 1;
            uint8_t HANDLE_5_PASSENGER_ALARM : 1;
            uint8_t HANDLE_7_PASSENGER_ALARM : 1;
            uint8_t HANDLE_2_PASSENGER_ALARM : 1;
            uint8_t HANDLE_4_PASSENGER_ALARM : 1;
            uint8_t HANDLE_6_PASSENGER_ALARM : 1;
            uint8_t HANDLE_8_PASSENGER_ALARM : 1;
            uint8_t RELAY_SECURITY_EMERGENCY_LOOP : 1; //byte 14
            uint8_t RELAY_TRACTION_EMERGENCY_BRAKE : 1;
            uint8_t SL_DEAD_MAN_BYPASS : 1;
            uint8_t PLANT_4_7_CB_PROTECTION : 1;
            uint8_t CABINET_RIOM_1_CB_PROTECTION : 1;
            uint8_t BCU_ZERO_SPEED : 1;
            uint8_t FIRE_EXTINGUISHER_1_PRESENCE : 1;
            uint8_t FIRE_EXTINGUISHER_2_PRESENCE : 1;
            uint8_t SIFA_POSITION_HANDLE : 1; //byte 15
            uint8_t SIFA_TRACTION_CONTROL : 1;
            uint8_t SAND_LEVEL_SENSOR_BOGIE_1_BEARING_RIGHT : 1;
            uint8_t SAND_LEVEL_SENSOR_BOGIE_1_BEARING_LEFT : 1;
            uint8_t SAND_LEVEL_SENSOR_BOGIE_2_BEARING_RIGHT : 1;
            uint8_t SAND_LEVEL_SENSOR_BOGIE_2_BEARING_LEFT : 1;
            uint8_t HORN_1_ISOLATION_COCK : 1;
            uint8_t HORN_2_ISOLATION_COCK : 1;
            uint8_t PLANT_4_8_CB_PROTECTION : 1; //byte 16
            uint8_t DOOR_1_FULLY_OPENED : 1;
            uint8_t DOOR_2_FULLY_OPENED : 1;
            uint8_t DOOR_3_FULLY_OPENED : 1;
            uint8_t DOOR_4_FULLY_OPENED : 1;
            uint8_t DOOR_5_FULLY_OPENED : 1;
            uint8_t DOOR_6_FULLY_OPENED : 1;
            uint8_t DOOR_7_FULLY_OPENED : 1;
            uint8_t DOOR_8_FULLY_OPENED : 1; //byte 17
            uint8_t CLOSING_HATCH : 1;
            uint8_t OPENING_HATCH : 1;
            uint8_t HATCH_BYBASS : 1;
            uint8_t CABINET_RIOM_2_CB_PROTECTION : 1;
            uint8_t ETHERNET_SWITCH_1_PAPIS_ALARM : 1;
            uint8_t ETHERNET_SWITCH_2_PAPIS_ALARM : 1;
            uint8_t bit143 : 1;
            uint8_t ETCS_EQUIPMENT_POWER_SUPPLY_APPLIED : 1; //byte 18
            uint8_t RELAY_CONTROL_DOORS_LOOP : 1;
            uint8_t SL_DOORS_LOOP_BY_PASS : 1;
            uint8_t PLANT_5_3_CB_PROTECTION : 1;
            uint8_t PLANT_5_5_CB_PROTECTION : 1;
            uint8_t DC_DC_OK_ANTIFIRE_SYSTEM : 1;
            uint8_t PLANT_6_0_CB_PROTECTION : 1;
            uint8_t PLANT_6_5_CB_PROTECTION : 1;
            uint8_t INTERNAL_LIGHT_ON_COMMAND : 1; //byte 19
            uint8_t INTERNAL_HALF_LIGHT_COMMAND : 1;
            uint8_t INTERNAL_LIGHT_EMERGENCY_COMMAND : 1;
            uint8_t PLANT_7_0_CB_PROTECTION : 1;
            uint8_t PLANT_7_2_CB_PROTECTION : 1;
            uint8_t AUTOMATIC_EXTERNAL_LIGHT_COMMAND : 1;
            uint8_t SL_ETCS_BY_PASS : 1;
            uint8_t SL_DOORS_SIDE_CONTROL_ETCS_BYPASS : 1;
            uint8_t GSM_R_RADIO_DIAGNOSTIC_INFORMATION : 1; //byte 20
            uint8_t GSM_R_RADIO_VOICE : 1;
            uint8_t ATS_BYPASS : 1;
            uint8_t PLANT_7_7_CB_PROTECTION : 1;
            uint8_t PLANT_7_8_CB_PROTECTION : 1;
            uint8_t CONTROL_UNIT_RADIO_THALES_CB_PROTECTION : 1;
            uint8_t CB_PROTECTION_AXLE_BOX : 1;
            uint8_t bit167 : 1;
            uint8_t spare_21;
            uint8_t spare_22;
            uint8_t spare_23;
            uint8_t spare_24;
            uint8_t spare_25;
            uint8_t spare_26;
            uint8_t spare_27;
            uint8_t spare_28;
            uint8_t spare_29;
            uint8_t spare_30;
            uint8_t spare_31;
        } bits;
        time_t last_update;
    };
};

/**
 * SKA1_VH	0x412
 * OA1	-
 * OA2	-
 * SKA2_VH	0x4D2
 * v 1.07
*/
struct ska_vh_riom_ccu_mvb2_dcu1 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint8_t R1_DCU_IFESmartAssistDCU : 1; //byte 0
            uint8_t R1_DCU_SuppEmergOp : 1;
            uint8_t R1_DCU_DoorAntiDrag : 1;
            uint8_t R1_DCU_DoorObstDet : 1;
            uint8_t R1_DCU_DoorMoveMonit : 1;
            uint8_t R1_DCU_EntrRel : 1;
            uint8_t R1_DCU_DoorClosed : 1;
            uint8_t R1_DCU_DoorClosedAndLocked : 1;
            uint8_t R1_DCU_DoorFullyOpen : 1; //byte 1
            uint8_t R1_DCU_DoorOutOfService : 1;
            uint8_t R1_DCU_DoorUnlEmergOp : 1;
            uint8_t R1_DCU_EEDOp : 1;
            uint8_t R1_DCU_EADOp : 1;
            uint8_t R1_DCU_PBOpenDLRightOutsideOp : 1;
            uint8_t R1_DCU_PBOpenDLRightInsideOp : 1;
            uint8_t R1_DCU_PBPRMPortalInsideOp : 1;
            uint8_t R1_DCU_LightBarrierPortalInsideInterr : 1; //byte 2
            uint8_t R1_DCU_OutputTIL1 : 1;
            uint8_t R1_DCU_DC001 : 1;
            uint8_t R1_DCU_DC002 : 1;
            uint8_t R1_DCU_DC003 : 1;
            uint8_t R1_DCU_DC004 : 1;
            uint8_t R1_DCU_DC005 : 1;
            uint8_t R1_DCU_DC006 : 1;
            uint8_t R1_DCU_DC007 : 1; //byte 3
            uint8_t R1_DCU_DC008 : 1;
            uint8_t R1_DCU_DC009 : 1;
            uint8_t R1_DCU_DC010 : 1;
            uint8_t R1_DCU_DC013 : 1;
            uint8_t R1_DCU_DC014 : 1;
            uint8_t R1_DCU_DC015 : 1;
            uint8_t R1_DCU_DC016 : 1;
            uint8_t R1_DCU_DC017 : 1; //byte 4
            uint8_t R1_DCU_DC018 : 1;
            uint8_t R1_DCU_DC019 : 1;
            uint8_t R1_DCU_DC020 : 1;
            uint8_t R1_DCU_DC021 : 1;
            uint8_t R1_DCU_DC022 : 1;
            uint8_t R1_DCU_DC027 : 1;
            uint8_t R1_DCU_DC028 : 1;
            uint8_t R1_DCU_DC029 : 1; //byte 5
            uint8_t R1_DCU_DC030 : 1;
            uint8_t R1_DCU_DC031 : 1;
            uint8_t R1_DCU_DC033 : 1;
            uint8_t R1_DCU_DC037 : 1;
            uint8_t R1_DCU_DC042 : 1;
            uint8_t R1_DCU_DC043 : 1;
            uint8_t R1_DCU_DC044 : 1;
            uint8_t R1_DCU_DC046 : 1; //byte 6
            uint8_t R1_DCU_DC048 : 1;
            uint8_t R1_DCU_DC049 : 1;
            uint8_t R1_DCU_DC050 : 1;
            uint8_t R1_DCU_DC051 : 1;
            uint8_t R1_DCU_DC052 : 1;
            uint8_t R1_DCU_DC053 : 1;
            uint8_t R1_DCU_DC065 : 1;
            uint8_t R1_DCU_DC066 : 1; //byte 7
            uint8_t R1_DCU_DC067 : 1;
            uint8_t R1_DCU_DC068 : 1;
            uint8_t R1_DCU_DC069 : 1;
            uint8_t R1_DCU_DC090 : 1;
            uint8_t R1_DCU_DC091 : 1;
            uint8_t R1_DCU_DC098 : 1;
            uint8_t R1_DCU_DC099 : 1;
            uint8_t R1_DCU_DC101 : 1; //byte 8
            uint8_t R1_DCU_DC102 : 1;
            uint8_t R1_DCU_DC103 : 1;
            uint8_t R1_DCU_DC105 : 1;
            uint8_t R1_DCU_DC106 : 1;
            uint8_t R1_DCU_DC111 : 1;
            uint8_t R1_DCU_DC116 : 1;
            uint8_t R1_DCU_DiagPrioA : 1;
            uint8_t R1_DCU_DiagPrioB : 1; //byte 9
            uint8_t bit73 : 1;
            uint8_t bit74 : 1;
            uint8_t bit75 : 1;
            uint8_t bit76 : 1;
            uint8_t bit77 : 1;
            uint8_t bit78 : 1;
            uint8_t bit79 : 1;
            uint8_t R2_DCU_IFESmartAssistDCU : 1; //byte 10
            uint8_t R2_DCU_SuppEmergOp : 1;
            uint8_t R2_DCU_DoorAntiDrag : 1;
            uint8_t R2_DCU_DoorObstDet : 1;
            uint8_t R2_DCU_DoorMoveMonit : 1;
            uint8_t R2_DCU_EntrRel : 1;
            uint8_t R2_DCU_DoorClosed : 1;
            uint8_t R2_DCU_DoorClosedAndLocked : 1;
            uint8_t R2_DCU_DoorFullyOpen : 1; //byte 11
            uint8_t R2_DCU_DoorOutOfService : 1;
            uint8_t R2_DCU_DoorUnlEmergOp : 1;
            uint8_t R2_DCU_EEDOp : 1;
            uint8_t R2_DCU_EADOp : 1;
            uint8_t R2_DCU_PBOpenDLRightOutsideOp : 1;
            uint8_t R2_DCU_PBOpenDLRightInsideOp : 1;
            uint8_t R2_DCU_PBPRMPortalInsideOp : 1;
            uint8_t R2_DCU_LightBarrierPortalInsideInterr : 1; //byte 12
            uint8_t R2_DCU_OutputTIL1 : 1;
            uint8_t R2_DCU_DC001 : 1;
            uint8_t R2_DCU_DC002 : 1;
            uint8_t R2_DCU_DC003 : 1;
            uint8_t R2_DCU_DC004 : 1;
            uint8_t R2_DCU_DC005 : 1;
            uint8_t R2_DCU_DC006 : 1;
            uint8_t R2_DCU_DC007 : 1; //byte 13
            uint8_t R2_DCU_DC008 : 1;
            uint8_t R2_DCU_DC009 : 1;
            uint8_t R2_DCU_DC010 : 1;
            uint8_t R2_DCU_DC013 : 1;
            uint8_t R2_DCU_DC014 : 1;
            uint8_t R2_DCU_DC015 : 1;
            uint8_t R2_DCU_DC016 : 1;
            uint8_t R2_DCU_DC017 : 1; //byte 14
            uint8_t R2_DCU_DC018 : 1;
            uint8_t R2_DCU_DC019 : 1;
            uint8_t R2_DCU_DC020 : 1;
            uint8_t R2_DCU_DC021 : 1;
            uint8_t R2_DCU_DC022 : 1;
            uint8_t R2_DCU_DC027 : 1;
            uint8_t R2_DCU_DC028 : 1;
            uint8_t R2_DCU_DC029 : 1; //byte 15
            uint8_t R2_DCU_DC030 : 1;
            uint8_t R2_DCU_DC031 : 1;
            uint8_t R2_DCU_DC033 : 1;
            uint8_t R2_DCU_DC037 : 1;
            uint8_t R2_DCU_DC042 : 1;
            uint8_t R2_DCU_DC043 : 1;
            uint8_t R2_DCU_DC044 : 1;
            uint8_t R2_DCU_DC046 : 1; //byte 16
            uint8_t R2_DCU_DC048 : 1;
            uint8_t R2_DCU_DC049 : 1;
            uint8_t R2_DCU_DC050 : 1;
            uint8_t R2_DCU_DC051 : 1;
            uint8_t R2_DCU_DC052 : 1;
            uint8_t R2_DCU_DC053 : 1;
            uint8_t R2_DCU_DC065 : 1;
            uint8_t R2_DCU_DC066 : 1; //byte 17
            uint8_t R2_DCU_DC067 : 1;
            uint8_t R2_DCU_DC068 : 1;
            uint8_t R2_DCU_DC069 : 1;
            uint8_t R2_DCU_DC090 : 1;
            uint8_t R2_DCU_DC091 : 1;
            uint8_t R2_DCU_DC098 : 1;
            uint8_t R2_DCU_DC099 : 1;
            uint8_t R2_DCU_DC101 : 1; //byte 18
            uint8_t R2_DCU_DC102 : 1;
            uint8_t R2_DCU_DC103 : 1;
            uint8_t R2_DCU_DC105 : 1;
            uint8_t R2_DCU_DC106 : 1;
            uint8_t R2_DCU_DC111 : 1;
            uint8_t R2_DCU_DC116 : 1;
            uint8_t R2_DCU_DiagPrioA : 1;
            uint8_t R2_DCU_DiagPrioB : 1; //byte 19
            uint8_t bit153 : 1;
            uint8_t bit154 : 1;
            uint8_t bit155 : 1;
            uint8_t bit156 : 1;
            uint8_t bit157 : 1;
            uint8_t bit158 : 1;
            uint8_t bit159 : 1;
            uint8_t R3_DCU_IFESmartAssistDCU : 1; //byte 20
            uint8_t R3_DCU_SuppEmergOp : 1;
            uint8_t R3_DCU_DoorAntiDrag : 1;
            uint8_t R3_DCU_DoorObstDet : 1;
            uint8_t R3_DCU_DoorMoveMonit : 1;
            uint8_t R3_DCU_EntrRel : 1;
            uint8_t R3_DCU_DoorClosed : 1;
            uint8_t R3_DCU_DoorClosedAndLocked : 1;
            uint8_t R3_DCU_DoorFullyOpen : 1; //byte 21
            uint8_t R3_DCU_DoorOutOfService : 1;
            uint8_t R3_DCU_DoorUnlEmergOp : 1;
            uint8_t R3_DCU_EEDOp : 1;
            uint8_t R3_DCU_EADOp : 1;
            uint8_t R3_DCU_PBOpenDLRightOutsideOp : 1;
            uint8_t R3_DCU_PBOpenDLRightInsideOp : 1;
            uint8_t R3_DCU_PBPRMPortalInsideOp : 1;
            uint8_t R3_DCU_LightBarrierPortalInsideInterr : 1; //byte 22
            uint8_t R3_DCU_OutputTIL1 : 1;
            uint8_t R3_DCU_DC001 : 1;
            uint8_t R3_DCU_DC002 : 1;
            uint8_t R3_DCU_DC003 : 1;
            uint8_t R3_DCU_DC004 : 1;
            uint8_t R3_DCU_DC005 : 1;
            uint8_t R3_DCU_DC006 : 1;
            uint8_t R3_DCU_DC007 : 1; //byte 23
            uint8_t R3_DCU_DC008 : 1;
            uint8_t R3_DCU_DC009 : 1;
            uint8_t R3_DCU_DC010 : 1;
            uint8_t R3_DCU_DC013 : 1;
            uint8_t R3_DCU_DC014 : 1;
            uint8_t R3_DCU_DC015 : 1;
            uint8_t R3_DCU_DC016 : 1;
            uint8_t R3_DCU_DC017 : 1; //byte 24
            uint8_t R3_DCU_DC018 : 1;
            uint8_t R3_DCU_DC019 : 1;
            uint8_t R3_DCU_DC020 : 1;
            uint8_t R3_DCU_DC021 : 1;
            uint8_t R3_DCU_DC022 : 1;
            uint8_t R3_DCU_DC027 : 1;
            uint8_t R3_DCU_DC028 : 1;
            uint8_t R3_DCU_DC029 : 1; //byte 25
            uint8_t R3_DCU_DC030 : 1;
            uint8_t R3_DCU_DC031 : 1;
            uint8_t R3_DCU_DC033 : 1;
            uint8_t R3_DCU_DC037 : 1;
            uint8_t R3_DCU_DC042 : 1;
            uint8_t R3_DCU_DC043 : 1;
            uint8_t R3_DCU_DC044 : 1;
            uint8_t R3_DCU_DC046 : 1; //byte 26
            uint8_t R3_DCU_DC048 : 1;
            uint8_t R3_DCU_DC049 : 1;
            uint8_t R3_DCU_DC050 : 1;
            uint8_t R3_DCU_DC051 : 1;
            uint8_t R3_DCU_DC052 : 1;
            uint8_t R3_DCU_DC053 : 1;
            uint8_t R3_DCU_DC065 : 1;
            uint8_t R3_DCU_DC066 : 1; //byte 27
            uint8_t R3_DCU_DC067 : 1;
            uint8_t R3_DCU_DC068 : 1;
            uint8_t R3_DCU_DC069 : 1;
            uint8_t R3_DCU_DC090 : 1;
            uint8_t R3_DCU_DC091 : 1;
            uint8_t R3_DCU_DC098 : 1;
            uint8_t R3_DCU_DC099 : 1;
            uint8_t R3_DCU_DC101 : 1; //byte 28
            uint8_t R3_DCU_DC102 : 1;
            uint8_t R3_DCU_DC103 : 1;
            uint8_t R3_DCU_DC105 : 1;
            uint8_t R3_DCU_DC106 : 1;
            uint8_t R3_DCU_DC111 : 1;
            uint8_t R3_DCU_DC116 : 1;
            uint8_t R3_DCU_DiagPrioA : 1;
            uint8_t R3_DCU_DiagPrioB : 1; //byte 29
            uint8_t bit233 : 1;
            uint8_t bit234 : 1;
            uint8_t bit235 : 1;
            uint8_t bit236 : 1;
            uint8_t bit237 : 1;
            uint8_t bit238 : 1;
            uint8_t bit239 : 1;
            uint8_t reserved_30;
            uint8_t reserved_31;

        } bits;
        time_t last_update;
    };
};

/**
 * SKA1_VH	0x413
 * OA1	-
 * OA2	-
 * SKA2_VH	0x4D3
 * v1.07
*/
struct ska_vh_riom_ccu_mvb3_dcu2 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint8_t R4_DCU_IFESmartAssistDCU : 1; //byte 0
            uint8_t R4_DCU_SuppEmergOp : 1;
            uint8_t R4_DCU_DoorAntiDrag : 1;
            uint8_t R4_DCU_DoorObstDet : 1;
            uint8_t R4_DCU_DoorMoveMonit : 1;
            uint8_t R4_DCU_EntrRel : 1;
            uint8_t R4_DCU_DoorClosed : 1;
            uint8_t R4_DCU_DoorClosedAndLocked : 1;
            uint8_t R4_DCU_DoorFullyOpen : 1; //byte 1
            uint8_t R4_DCU_DoorOutOfService : 1;
            uint8_t R4_DCU_DoorUnlEmergOp : 1;
            uint8_t R4_DCU_EEDOp : 1;
            uint8_t R4_DCU_EADOp : 1;
            uint8_t R4_DCU_PBOpenDLRightOutsideOp : 1;
            uint8_t R4_DCU_PBOpenDLRightInsideOp : 1;
            uint8_t R4_DCU_PBPRMPortalInsideOp : 1;
            uint8_t R4_DCU_LightBarrierPortalInsideInterr : 1; //byte 2
            uint8_t R4_DCU_OutputTIL1 : 1;
            uint8_t R4_DCU_DC001 : 1;
            uint8_t R4_DCU_DC002 : 1;
            uint8_t R4_DCU_DC003 : 1;
            uint8_t R4_DCU_DC004 : 1;
            uint8_t R4_DCU_DC005 : 1;
            uint8_t R4_DCU_DC006 : 1;
            uint8_t R4_DCU_DC007 : 1; //byte 3
            uint8_t R4_DCU_DC008 : 1;
            uint8_t R4_DCU_DC009 : 1;
            uint8_t R4_DCU_DC010 : 1;
            uint8_t R4_DCU_DC013 : 1;
            uint8_t R4_DCU_DC014 : 1;
            uint8_t R4_DCU_DC015 : 1;
            uint8_t R4_DCU_DC016 : 1;
            uint8_t R4_DCU_DC017 : 1; //byte 4
            uint8_t R4_DCU_DC018 : 1;
            uint8_t R4_DCU_DC019 : 1;
            uint8_t R4_DCU_DC020 : 1;
            uint8_t R4_DCU_DC021 : 1;
            uint8_t R4_DCU_DC022 : 1;
            uint8_t R4_DCU_DC027 : 1;
            uint8_t R4_DCU_DC028 : 1;
            uint8_t R4_DCU_DC029 : 1; //byte 5
            uint8_t R4_DCU_DC030 : 1;
            uint8_t R4_DCU_DC031 : 1;
            uint8_t R4_DCU_DC033 : 1;
            uint8_t R4_DCU_DC037 : 1;
            uint8_t R4_DCU_DC042 : 1;
            uint8_t R4_DCU_DC043 : 1;
            uint8_t R4_DCU_DC044 : 1;
            uint8_t R4_DCU_DC046 : 1; //byte 6
            uint8_t R4_DCU_DC048 : 1;
            uint8_t R4_DCU_DC049 : 1;
            uint8_t R4_DCU_DC050 : 1;
            uint8_t R4_DCU_DC051 : 1;
            uint8_t R4_DCU_DC052 : 1;
            uint8_t R4_DCU_DC053 : 1;
            uint8_t R4_DCU_DC065 : 1;
            uint8_t R4_DCU_DC066 : 1; //byte 7
            uint8_t R4_DCU_DC067 : 1;
            uint8_t R4_DCU_DC068 : 1;
            uint8_t R4_DCU_DC069 : 1;
            uint8_t R4_DCU_DC090 : 1;
            uint8_t R4_DCU_DC091 : 1;
            uint8_t R4_DCU_DC098 : 1;
            uint8_t R4_DCU_DC099 : 1;
            uint8_t R4_DCU_DC101 : 1; //byte 8
            uint8_t R4_DCU_DC102 : 1;
            uint8_t R4_DCU_DC103 : 1;
            uint8_t R4_DCU_DC105 : 1;
            uint8_t R4_DCU_DC106 : 1;
            uint8_t R4_DCU_DC111 : 1;
            uint8_t R4_DCU_DC116 : 1;
            uint8_t R4_DCU_DiagPrioA : 1;
            uint8_t R4_DCU_DiagPrioB : 1; //byte 9
            uint8_t bit73 : 1;
            uint8_t bit74 : 1;
            uint8_t bit75 : 1;
            uint8_t bit76 : 1;
            uint8_t bit77 : 1;
            uint8_t bit78 : 1;
            uint8_t bit79 : 1;
            uint8_t L1_DCU_IFESmartAssistDCU : 1; //byte 10
            uint8_t L1_DCU_SuppEmergOp : 1;
            uint8_t L1_DCU_DoorAntiDrag : 1;
            uint8_t L1_DCU_DoorObstDet : 1;
            uint8_t L1_DCU_DoorMoveMonit : 1;
            uint8_t L1_DCU_EntrRel : 1;
            uint8_t L1_DCU_DoorClosed : 1;
            uint8_t L1_DCU_DoorClosedAndLocked : 1;
            uint8_t L1_DCU_DoorFullyOpen : 1; //byte 11
            uint8_t L1_DCU_DoorOutOfService : 1;
            uint8_t L1_DCU_DoorUnlEmergOp : 1;
            uint8_t L1_DCU_EEDOp : 1;
            uint8_t L1_DCU_EADOp : 1;
            uint8_t L1_DCU_PBOpenDLRightOutsideOp : 1;
            uint8_t L1_DCU_PBOpenDLRightInsideOp : 1;
            uint8_t L1_DCU_PBPRMPortalInsideOp : 1;
            uint8_t L1_DCU_LightBarrierPortalInsideInterr : 1; //byte 12
            uint8_t L1_DCU_OutputTIL1 : 1;
            uint8_t L1_DCU_DC001 : 1;
            uint8_t L1_DCU_DC002 : 1;
            uint8_t L1_DCU_DC003 : 1;
            uint8_t L1_DCU_DC004 : 1;
            uint8_t L1_DCU_DC005 : 1;
            uint8_t L1_DCU_DC006 : 1;
            uint8_t L1_DCU_DC007 : 1; //byte 13
            uint8_t L1_DCU_DC008 : 1;
            uint8_t L1_DCU_DC009 : 1;
            uint8_t L1_DCU_DC010 : 1;
            uint8_t L1_DCU_DC013 : 1;
            uint8_t L1_DCU_DC014 : 1;
            uint8_t L1_DCU_DC015 : 1;
            uint8_t L1_DCU_DC016 : 1;
            uint8_t L1_DCU_DC017 : 1; //byte 14
            uint8_t L1_DCU_DC018 : 1;
            uint8_t L1_DCU_DC019 : 1;
            uint8_t L1_DCU_DC020 : 1;
            uint8_t L1_DCU_DC021 : 1;
            uint8_t L1_DCU_DC022 : 1;
            uint8_t L1_DCU_DC027 : 1;
            uint8_t L1_DCU_DC028 : 1;
            uint8_t L1_DCU_DC029 : 1; //byte 15
            uint8_t L1_DCU_DC030 : 1;
            uint8_t L1_DCU_DC031 : 1;
            uint8_t L1_DCU_DC033 : 1;
            uint8_t L1_DCU_DC037 : 1;
            uint8_t L1_DCU_DC042 : 1;
            uint8_t L1_DCU_DC043 : 1;
            uint8_t L1_DCU_DC044 : 1;
            uint8_t L1_DCU_DC046 : 1; //byte 16
            uint8_t L1_DCU_DC048 : 1;
            uint8_t L1_DCU_DC049 : 1;
            uint8_t L1_DCU_DC050 : 1;
            uint8_t L1_DCU_DC051 : 1;
            uint8_t L1_DCU_DC052 : 1;
            uint8_t L1_DCU_DC053 : 1;
            uint8_t L1_DCU_DC065 : 1;
            uint8_t L1_DCU_DC066 : 1; //byte 17
            uint8_t L1_DCU_DC067 : 1;
            uint8_t L1_DCU_DC068 : 1;
            uint8_t L1_DCU_DC069 : 1;
            uint8_t L1_DCU_DC090 : 1;
            uint8_t L1_DCU_DC091 : 1;
            uint8_t L1_DCU_DC098 : 1;
            uint8_t L1_DCU_DC099 : 1;
            uint8_t L1_DCU_DC101 : 1; //byte 18
            uint8_t L1_DCU_DC102 : 1;
            uint8_t L1_DCU_DC103 : 1;
            uint8_t L1_DCU_DC105 : 1;
            uint8_t L1_DCU_DC106 : 1;
            uint8_t L1_DCU_DC111 : 1;
            uint8_t L1_DCU_DC116 : 1;
            uint8_t L1_DCU_DiagPrioA : 1;
            uint8_t L1_DCU_DiagPrioB : 1; //byte 19
            uint8_t bit153 : 1;
            uint8_t bit154 : 1;
            uint8_t bit155 : 1;
            uint8_t bit156 : 1;
            uint8_t bit157 : 1;
            uint8_t bit158 : 1;
            uint8_t bit159 : 1;
            uint8_t L2_DCU_IFESmartAssistDCU : 1; //byte 20
            uint8_t L2_DCU_SuppEmergOp : 1;
            uint8_t L2_DCU_DoorAntiDrag : 1;
            uint8_t L2_DCU_DoorObstDet : 1;
            uint8_t L2_DCU_DoorMoveMonit : 1;
            uint8_t L2_DCU_EntrRel : 1;
            uint8_t L2_DCU_DoorClosed : 1;
            uint8_t L2_DCU_DoorClosedAndLocked : 1;
            uint8_t L2_DCU_DoorFullyOpen : 1; //byte 21
            uint8_t L2_DCU_DoorOutOfService : 1;
            uint8_t L2_DCU_DoorUnlEmergOp : 1;
            uint8_t L2_DCU_EEDOp : 1;
            uint8_t L2_DCU_EADOp : 1;
            uint8_t L2_DCU_PBOpenDLRightOutsideOp : 1;
            uint8_t L2_DCU_PBOpenDLRightInsideOp : 1;
            uint8_t L2_DCU_PBPRMPortalInsideOp : 1;
            uint8_t L2_DCU_LightBarrierPortalInsideInterr : 1; //byte 22
            uint8_t L2_DCU_OutputTIL1 : 1;
            uint8_t L2_DCU_DC001 : 1;
            uint8_t L2_DCU_DC002 : 1;
            uint8_t L2_DCU_DC003 : 1;
            uint8_t L2_DCU_DC004 : 1;
            uint8_t L2_DCU_DC005 : 1;
            uint8_t L2_DCU_DC006 : 1;
            uint8_t L2_DCU_DC007 : 1; //byte 23
            uint8_t L2_DCU_DC008 : 1;
            uint8_t L2_DCU_DC009 : 1;
            uint8_t L2_DCU_DC010 : 1;
            uint8_t L2_DCU_DC013 : 1;
            uint8_t L2_DCU_DC014 : 1;
            uint8_t L2_DCU_DC015 : 1;
            uint8_t L2_DCU_DC016 : 1;
            uint8_t L2_DCU_DC017 : 1; //byte 24
            uint8_t L2_DCU_DC018 : 1;
            uint8_t L2_DCU_DC019 : 1;
            uint8_t L2_DCU_DC020 : 1;
            uint8_t L2_DCU_DC021 : 1;
            uint8_t L2_DCU_DC022 : 1;
            uint8_t L2_DCU_DC027 : 1;
            uint8_t L2_DCU_DC028 : 1;
            uint8_t L2_DCU_DC029 : 1; //byte 25
            uint8_t L2_DCU_DC030 : 1;
            uint8_t L2_DCU_DC031 : 1;
            uint8_t L2_DCU_DC033 : 1;
            uint8_t L2_DCU_DC037 : 1;
            uint8_t L2_DCU_DC042 : 1;
            uint8_t L2_DCU_DC043 : 1;
            uint8_t L2_DCU_DC044 : 1;
            uint8_t L2_DCU_DC046 : 1; //byte 26
            uint8_t L2_DCU_DC048 : 1;
            uint8_t L2_DCU_DC049 : 1;
            uint8_t L2_DCU_DC050 : 1;
            uint8_t L2_DCU_DC051 : 1;
            uint8_t L2_DCU_DC052 : 1;
            uint8_t L2_DCU_DC053 : 1;
            uint8_t L2_DCU_DC065 : 1;
            uint8_t L2_DCU_DC066 : 1; //byte 27
            uint8_t L2_DCU_DC067 : 1;
            uint8_t L2_DCU_DC068 : 1;
            uint8_t L2_DCU_DC069 : 1;
            uint8_t L2_DCU_DC090 : 1;
            uint8_t L2_DCU_DC091 : 1;
            uint8_t L2_DCU_DC098 : 1;
            uint8_t L2_DCU_DC099 : 1;
            uint8_t L2_DCU_DC101 : 1; //byte 28
            uint8_t L2_DCU_DC102 : 1;
            uint8_t L2_DCU_DC103 : 1;
            uint8_t L2_DCU_DC105 : 1;
            uint8_t L2_DCU_DC106 : 1;
            uint8_t L2_DCU_DC111 : 1;
            uint8_t L2_DCU_DC116 : 1;
            uint8_t L2_DCU_DiagPrioA : 1;
            uint8_t L2_DCU_DiagPrioB : 1; //byte 29
            uint8_t bit233 : 1;
            uint8_t bit234 : 1;
            uint8_t bit235 : 1;
            uint8_t bit236 : 1;
            uint8_t bit237 : 1;
            uint8_t bit238 : 1;
            uint8_t bit239 : 1;
            uint8_t reserved_30;
            uint8_t reserved_31;

        } bits;
        time_t last_update;
    };
};
/**
 * SKA1_VH	0x414
 * OA1	-
 * OA2	-
 * SKA2_VH	0x4D4
 * v1.07
*/
struct ska_vh_riom_ccu_mvb4_dcu3 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint8_t L3_DCU_IFESmartAssistDCU : 1; //byte 0
            uint8_t L3_DCU_SuppEmergOp : 1;
            uint8_t L3_DCU_DoorAntiDrag : 1;
            uint8_t L3_DCU_DoorObstDet : 1;
            uint8_t L3_DCU_DoorMoveMonit : 1;
            uint8_t L3_DCU_EntrRel : 1;
            uint8_t L3_DCU_DoorClosed : 1;
            uint8_t L3_DCU_DoorClosedAndLocked : 1;
            uint8_t L3_DCU_DoorFullyOpen : 1; //byte 1
            uint8_t L3_DCU_DoorOutOfService : 1;
            uint8_t L3_DCU_DoorUnlEmergOp : 1;
            uint8_t L3_DCU_EEDOp : 1;
            uint8_t L3_DCU_EADOp : 1;
            uint8_t L3_DCU_PBOpenDLRightOutsideOp : 1;
            uint8_t L3_DCU_PBOpenDLRightInsideOp : 1;
            uint8_t L3_DCU_PBPRMPortalInsideOp : 1;
            uint8_t L3_DCU_LightBarrierPortalInsideInterr : 1; //byte 2
            uint8_t L3_DCU_OutputTIL1 : 1;
            uint8_t L3_DCU_DC001 : 1;
            uint8_t L3_DCU_DC002 : 1;
            uint8_t L3_DCU_DC003 : 1;
            uint8_t L3_DCU_DC004 : 1;
            uint8_t L3_DCU_DC005 : 1;
            uint8_t L3_DCU_DC006 : 1;
            uint8_t L3_DCU_DC007 : 1; //byte 3
            uint8_t L3_DCU_DC008 : 1;
            uint8_t L3_DCU_DC009 : 1;
            uint8_t L3_DCU_DC010 : 1;
            uint8_t L3_DCU_DC013 : 1;
            uint8_t L3_DCU_DC014 : 1;
            uint8_t L3_DCU_DC015 : 1;
            uint8_t L3_DCU_DC016 : 1;
            uint8_t L3_DCU_DC017 : 1; //byte 4
            uint8_t L3_DCU_DC018 : 1;
            uint8_t L3_DCU_DC019 : 1;
            uint8_t L3_DCU_DC020 : 1;
            uint8_t L3_DCU_DC021 : 1;
            uint8_t L3_DCU_DC022 : 1;
            uint8_t L3_DCU_DC027 : 1;
            uint8_t L3_DCU_DC028 : 1;
            uint8_t L3_DCU_DC029 : 1; //byte 5
            uint8_t L3_DCU_DC030 : 1;
            uint8_t L3_DCU_DC031 : 1;
            uint8_t L3_DCU_DC033 : 1;
            uint8_t L3_DCU_DC037 : 1;
            uint8_t L3_DCU_DC042 : 1;
            uint8_t L3_DCU_DC043 : 1;
            uint8_t L3_DCU_DC044 : 1;
            uint8_t L3_DCU_DC046 : 1; //byte 6
            uint8_t L3_DCU_DC048 : 1;
            uint8_t L3_DCU_DC049 : 1;
            uint8_t L3_DCU_DC050 : 1;
            uint8_t L3_DCU_DC051 : 1;
            uint8_t L3_DCU_DC052 : 1;
            uint8_t L3_DCU_DC053 : 1;
            uint8_t L3_DCU_DC065 : 1;
            uint8_t L3_DCU_DC066 : 1; //byte 7
            uint8_t L3_DCU_DC067 : 1;
            uint8_t L3_DCU_DC068 : 1;
            uint8_t L3_DCU_DC069 : 1;
            uint8_t L3_DCU_DC090 : 1;
            uint8_t L3_DCU_DC091 : 1;
            uint8_t L3_DCU_DC098 : 1;
            uint8_t L3_DCU_DC099 : 1;
            uint8_t L3_DCU_DC101 : 1; //byte 8
            uint8_t L3_DCU_DC102 : 1;
            uint8_t L3_DCU_DC103 : 1;
            uint8_t L3_DCU_DC105 : 1;
            uint8_t L3_DCU_DC106 : 1;
            uint8_t L3_DCU_DC111 : 1;
            uint8_t L3_DCU_DC116 : 1;
            uint8_t L3_DCU_DiagPrioA : 1;
            uint8_t L3_DCU_DiagPrioB : 1; //byte 9
            uint8_t bit73 : 1;
            uint8_t bit74 : 1;
            uint8_t bit75 : 1;
            uint8_t bit76 : 1;
            uint8_t bit77 : 1;
            uint8_t bit78 : 1;
            uint8_t bit79 : 1;
            uint8_t L4_DCU_IFESmartAssistDCU : 1; //byte 10
            uint8_t L4_DCU_SuppEmergOp : 1;
            uint8_t L4_DCU_DoorAntiDrag : 1;
            uint8_t L4_DCU_DoorObstDet : 1;
            uint8_t L4_DCU_DoorMoveMonit : 1;
            uint8_t L4_DCU_EntrRel : 1;
            uint8_t L4_DCU_DoorClosed : 1;
            uint8_t L4_DCU_DoorClosedAndLocked : 1;
            uint8_t L4_DCU_DoorFullyOpen : 1; //byte 11
            uint8_t L4_DCU_DoorOutOfService : 1;
            uint8_t L4_DCU_DoorUnlEmergOp : 1;
            uint8_t L4_DCU_EEDOp : 1;
            uint8_t L4_DCU_EADOp : 1;
            uint8_t L4_DCU_PBOpenDLRightOutsideOp : 1;
            uint8_t L4_DCU_PBOpenDLRightInsideOp : 1;
            uint8_t L4_DCU_PBPRMPortalInsideOp : 1;
            uint8_t L4_DCU_LightBarrierPortalInsideInterr : 1; //byte 12
            uint8_t L4_DCU_OutputTIL1 : 1;
            uint8_t L4_DCU_DC001 : 1;
            uint8_t L4_DCU_DC002 : 1;
            uint8_t L4_DCU_DC003 : 1;
            uint8_t L4_DCU_DC004 : 1;
            uint8_t L4_DCU_DC005 : 1;
            uint8_t L4_DCU_DC006 : 1;
            uint8_t L4_DCU_DC007 : 1; //byte 13
            uint8_t L4_DCU_DC008 : 1;
            uint8_t L4_DCU_DC009 : 1;
            uint8_t L4_DCU_DC010 : 1;
            uint8_t L4_DCU_DC013 : 1;
            uint8_t L4_DCU_DC014 : 1;
            uint8_t L4_DCU_DC015 : 1;
            uint8_t L4_DCU_DC016 : 1;
            uint8_t L4_DCU_DC017 : 1; //byte 14
            uint8_t L4_DCU_DC018 : 1;
            uint8_t L4_DCU_DC019 : 1;
            uint8_t L4_DCU_DC020 : 1;
            uint8_t L4_DCU_DC021 : 1;
            uint8_t L4_DCU_DC022 : 1;
            uint8_t L4_DCU_DC027 : 1;
            uint8_t L4_DCU_DC028 : 1;
            uint8_t L4_DCU_DC029 : 1; //byte 15
            uint8_t L4_DCU_DC030 : 1;
            uint8_t L4_DCU_DC031 : 1;
            uint8_t L4_DCU_DC033 : 1;
            uint8_t L4_DCU_DC037 : 1;
            uint8_t L4_DCU_DC042 : 1;
            uint8_t L4_DCU_DC043 : 1;
            uint8_t L4_DCU_DC044 : 1;
            uint8_t L4_DCU_DC046 : 1; //byte 16
            uint8_t L4_DCU_DC048 : 1;
            uint8_t L4_DCU_DC049 : 1;
            uint8_t L4_DCU_DC050 : 1;
            uint8_t L4_DCU_DC051 : 1;
            uint8_t L4_DCU_DC052 : 1;
            uint8_t L4_DCU_DC053 : 1;
            uint8_t L4_DCU_DC065 : 1;
            uint8_t L4_DCU_DC066 : 1; //byte 17
            uint8_t L4_DCU_DC067 : 1;
            uint8_t L4_DCU_DC068 : 1;
            uint8_t L4_DCU_DC069 : 1;
            uint8_t L4_DCU_DC090 : 1;
            uint8_t L4_DCU_DC091 : 1;
            uint8_t L4_DCU_DC098 : 1;
            uint8_t L4_DCU_DC099 : 1;
            uint8_t L4_DCU_DC101 : 1; //byte 18
            uint8_t L4_DCU_DC102 : 1;
            uint8_t L4_DCU_DC103 : 1;
            uint8_t L4_DCU_DC105 : 1;
            uint8_t L4_DCU_DC106 : 1;
            uint8_t L4_DCU_DC111 : 1;
            uint8_t L4_DCU_DC116 : 1;
            uint8_t L4_DCU_DiagPrioA : 1;
            uint8_t L4_DCU_DiagPrioB : 1; //byte 19
            uint8_t bit153 : 1;
            uint8_t bit154 : 1;
            uint8_t bit155 : 1;
            uint8_t bit156 : 1;
            uint8_t bit157 : 1;
            uint8_t bit158 : 1;
            uint8_t bit159 : 1;
            uint8_t reserved_20;
            uint8_t reserved_21;
            uint8_t reserved_22;
            uint8_t reserved_23;
            uint8_t reserved_24;
            uint8_t reserved_25;
            uint8_t reserved_26;
            uint8_t reserved_27;
            uint8_t reserved_28;
            uint8_t reserved_29;
            uint8_t reserved_30;
            uint8_t reserved_31;

        } bits;
        time_t last_update;
    };
};

/**
 * SKA1_VH	0x415
 * OA1	-
 * OA2	-
 * SKA2_VH	0x4D5
 * v1.07
*/
struct ska_vh_riom_ccu_mvb5_dcu4 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_16];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_16)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_16)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_16)];

        struct {
            uint8_t Door_Number; //byte 0
            uint8_t reserved1;
            uint8_t DCU_CycleCounter_Byte_1;
            uint8_t DCU_CycleCounter_Byte_2;
            uint8_t DCU_CycleCounter_Byte_3;
            uint8_t reserved_5;
            uint8_t DCU_SWVer_Char_1;
            uint8_t DCU_SWVer_Char_2;
            uint8_t DCU_SWVer_Char_3;
            uint8_t DCU_SWVer_Char_4;
            uint8_t DCU_SWVer_Char_5;
            uint8_t DCU_SWVer_Char_6;
            uint8_t reserved_12;
            uint8_t reserved_13;
            uint8_t reserved_14;
            uint8_t reserved_15;
        } bits;
        time_t last_update;
    };
};

/**
 * SKA1_VH	0x416
 * OA1	-
 * OA2	-
 * SKA2_VH	0x4D6
 * v1.07
*/
struct ska_vh_riom_ccu_mvb6_fds1 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint8_t S_FDCU_Master : 1; //byte 0
            uint8_t S_FDCU_General_fire : 1;
            uint8_t S_FDCU_Unmuted_fire_alarm : 1;
            uint8_t S_FDCU_Fire_fault_reset_feedback_RPDO : 1;
            uint8_t S_FDCU_General_fault : 1;
            uint8_t S_FDCU_Unmuted_fault_alarm : 1;
            uint8_t S_FDCU_Prealarm : 1;
            uint8_t S_FDCU_Resound_alarm_feedback_RPDO : 1;
            uint8_t reserved1 ; //byte 1
            uint8_t S_SKA1_SFD1_Smoke_alarm : 1; //byte 2
            uint8_t S_SKA1_SFD1_Heat_alarm : 1;
            uint8_t D_SKA1_SFD1_Disconnection : 1;
            uint8_t D_SKA1_SFD1_FC128 : 1;
            uint8_t bit20 : 1;
            uint8_t D_SKA1_SFD1_FC159 : 1;
            uint8_t D_SKA1_SFD1_FC130 : 1;
            uint8_t D_SKA1_SFD1_FC143 : 1;
            uint8_t D_SKA1_SFD1_FC129 : 1; //byte 3
            uint8_t D_SKA1_SFD1_FC181 : 1;
            uint8_t D_SKA1_SFD1_FC190 : 1;
            uint8_t D_SKA1_SFD1_FC229 : 1;
            uint8_t D_SKA1_SFD1_FC232 : 1;
            uint8_t D_SKA1_SFD1_FC138 : 1;
            uint8_t bit30 : 1;
            uint8_t bit31 : 1;
            uint8_t S_SKA1_SFD2_Smoke_alarm : 1; //byte 4
            uint8_t S_SKA1_SFD2_Heat_alarm : 1;
            uint8_t D_SKA1_SFD2_Disconnection : 1;
            uint8_t D_SKA1_SFD2_FC128 : 1;
            uint8_t bit36 : 1;
            uint8_t D_SKA1_SFD2_FC159 : 1;
            uint8_t D_SKA1_SFD2_FC130 : 1;
            uint8_t D_SKA1_SFD2_FC143 : 1;
            uint8_t D_SKA1_SFD2_FC129 : 1; //byte 5
            uint8_t D_SKA1_SFD2_FC181 : 1;
            uint8_t D_SKA1_SFD2_FC190 : 1;
            uint8_t D_SKA1_SFD2_FC229 : 1;
            uint8_t D_SKA1_SFD2_FC232 : 1;
            uint8_t D_SKA1_SFD2_FC138 : 1;
            uint8_t bit46 : 1;
            uint8_t bit47 : 1;
            uint8_t S_SKA1_SFD3_Smoke_alarm : 1; //byte 6
            uint8_t S_SKA1_SFD3_Heat_alarm : 1;
            uint8_t D_SKA1_SFD3_Disconnection : 1;
            uint8_t D_SKA1_SFD3_FC128 : 1;
            uint8_t bit52 : 1;
            uint8_t D_SKA1_SFD3_FC159 : 1;
            uint8_t D_SKA1_SFD3_FC130 : 1;
            uint8_t D_SKA1_SFD3_FC143 : 1;
            uint8_t D_SKA1_SFD3_FC129 : 1; //byte 7
            uint8_t D_SKA1_SFD3_FC181 : 1;
            uint8_t D_SKA1_SFD3_FC190 : 1;
            uint8_t D_SKA1_SFD3_FC229 : 1;
            uint8_t D_SKA1_SFD3_FC232 : 1;
            uint8_t D_SKA1_SFD3_FC138 : 1;
            uint8_t bit62 : 1;
            uint8_t bit63 : 1;
            uint8_t S_SKA1_SFD4_Smoke_alarm : 1; //byte 8
            uint8_t S_SKA1_SFD4_Heat_alarm : 1;
            uint8_t D_SKA1_SFD4_Disconnection : 1;
            uint8_t D_SKA1_SFD4_FC128 : 1;
            uint8_t bit68 : 1;
            uint8_t D_SKA1_SFD4_FC159 : 1;
            uint8_t D_SKA1_SFD4_FC130 : 1;
            uint8_t D_SKA1_SFD4_FC143 : 1;
            uint8_t D_SKA1_SFD4_FC129 : 1; //byte 9
            uint8_t D_SKA1_SFD4_FC181 : 1;
            uint8_t D_SKA1_SFD4_FC190 : 1;
            uint8_t D_SKA1_SFD4_FC229 : 1;
            uint8_t D_SKA1_SFD4_FC232 : 1;
            uint8_t D_SKA1_SFD4_FC138 : 1;
            uint8_t bit78 : 1;
            uint8_t bit79 : 1;
            uint8_t S_SKA1_SFD5_Smoke_alarm : 1; //byte 10
            uint8_t S_SKA1_SFD5_Heat_alarm : 1;
            uint8_t D_SKA1_SFD5_Disconnection : 1;
            uint8_t D_SKA1_SFD5_FC128 : 1;
            uint8_t bit84 : 1;
            uint8_t D_SKA1_SFD5_FC159 : 1;
            uint8_t D_SKA1_SFD5_FC130 : 1;
            uint8_t D_SKA1_SFD5_FC143 : 1;
            uint8_t D_SKA1_SFD5_FC129 : 1; //byte 11
            uint8_t D_SKA1_SFD5_FC181 : 1;
            uint8_t D_SKA1_SFD5_FC190 : 1;
            uint8_t D_SKA1_SFD5_FC229 : 1;
            uint8_t D_SKA1_SFD5_FC232 : 1;
            uint8_t D_SKA1_SFD5_FC138 : 1;
            uint8_t bit94 : 1;
            uint8_t bit95 : 1;
            uint8_t S_OA1_SFD1_Smoke_alarm : 1; //byte 12
            uint8_t S_OA1_SFD1_Heat_alarm : 1;
            uint8_t D_OA1_SFD1_Disconnection : 1;
            uint8_t D_OA1_SFD1_FC128 : 1;
            uint8_t bit100 : 1;
            uint8_t D_OA1_SFD1_FC159 : 1;
            uint8_t D_OA1_SFD1_FC130 : 1;
            uint8_t D_OA1_SFD1_FC143 : 1;
            uint8_t D_OA1_SFD1_FC129 : 1; //byte 13
            uint8_t D_OA1_SFD1_FC181 : 1;
            uint8_t D_OA1_SFD1_FC190 : 1;
            uint8_t D_OA1_SFD1_FC229 : 1;
            uint8_t D_OA1_SFD1_FC232 : 1;
            uint8_t D_OA1_SFD1_FC138 : 1;
            uint8_t bit110 : 1;
            uint8_t bit111 : 1;
            uint8_t S_OA1_SFD2_Smoke_alarm : 1; //byte 14
            uint8_t S_OA1_SFD2_Heat_alarm : 1;
            uint8_t D_OA1_SFD2_Disconnection : 1;
            uint8_t D_OA1_SFD2_FC128 : 1;
            uint8_t bit116 : 1;
            uint8_t D_OA1_SFD2_FC159 : 1;
            uint8_t D_OA1_SFD2_FC130 : 1;
            uint8_t D_OA1_SFD2_FC143 : 1;
            uint8_t D_OA1_SFD2_FC129 : 1; //byte 15
            uint8_t D_OA1_SFD2_FC181 : 1;
            uint8_t D_OA1_SFD2_FC190 : 1;
            uint8_t D_OA1_SFD2_FC229 : 1;
            uint8_t D_OA1_SFD2_FC232 : 1;
            uint8_t D_OA1_SFD2_FC138 : 1;
            uint8_t bit126 : 1;
            uint8_t bit127 : 1;
            uint8_t S_OA1_SFD3_Smoke_alarm : 1; //byte 16
            uint8_t S_OA1_SFD3_Heat_alarm : 1;
            uint8_t D_OA1_SFD3_Disconnection : 1;
            uint8_t D_OA1_SFD3_FC128 : 1;
            uint8_t bit132 : 1;
            uint8_t D_OA1_SFD3_FC159 : 1;
            uint8_t D_OA1_SFD3_FC130 : 1;
            uint8_t D_OA1_SFD3_FC143 : 1;
            uint8_t D_OA1_SFD3_FC129 : 1; //byte 17
            uint8_t D_OA1_SFD3_FC181 : 1;
            uint8_t D_OA1_SFD3_FC190 : 1;
            uint8_t D_OA1_SFD3_FC229 : 1;
            uint8_t D_OA1_SFD3_FC232 : 1;
            uint8_t D_OA1_SFD3_FC138 : 1;
            uint8_t bit142 : 1;
            uint8_t bit143 : 1;
            uint8_t S_OA1_SFD4_Smoke_alarm : 1; //byte 18
            uint8_t S_OA1_SFD4_Heat_alarm : 1;
            uint8_t D_OA1_SFD4_Disconnection : 1;
            uint8_t D_OA1_SFD4_FC128 : 1;
            uint8_t bit148 : 1;
            uint8_t D_OA1_SFD4_FC159 : 1;
            uint8_t D_OA1_SFD4_FC130 : 1;
            uint8_t D_OA1_SFD4_FC143 : 1;
            uint8_t D_OA1_SFD4_FC129 : 1; //byte 19
            uint8_t D_OA1_SFD4_FC181 : 1;
            uint8_t D_OA1_SFD4_FC190 : 1;
            uint8_t D_OA1_SFD4_FC229 : 1;
            uint8_t D_OA1_SFD4_FC232 : 1;
            uint8_t D_OA1_SFD4_FC138 : 1;
            uint8_t bit158 : 1;
            uint8_t bit159 : 1;
            uint8_t S_OA1_SFD5_Smoke_alarm : 1; //byte 20
            uint8_t S_OA1_SFD5_Heat_alarm : 1;
            uint8_t D_OA1_SFD5_Disconnection : 1;
            uint8_t D_OA1_SFD5_FC128 : 1;
            uint8_t bit164 : 1;
            uint8_t D_OA1_SFD5_FC159 : 1;
            uint8_t D_OA1_SFD5_FC130 : 1;
            uint8_t D_OA1_SFD5_FC143 : 1;
            uint8_t D_OA1_SFD5_FC129 : 1; //byte 21
            uint8_t D_OA1_SFD5_FC181 : 1;
            uint8_t D_OA1_SFD5_FC190 : 1;
            uint8_t D_OA1_SFD5_FC229 : 1;
            uint8_t D_OA1_SFD5_FC232 : 1;
            uint8_t D_OA1_SFD5_FC138 : 1;
            uint8_t bit174 : 1;
            uint8_t bit175 : 1;
            uint8_t S_OA2_SFD1_Smoke_alarm : 1; //byte 22
            uint8_t S_OA2_SFD1_Heat_alarm : 1;
            uint8_t D_OA2_SFD1_Disconnection : 1;
            uint8_t D_OA2_SFD1_FC128 : 1;
            uint8_t bit180 : 1;
            uint8_t D_OA2_SFD1_FC159 : 1;
            uint8_t D_OA2_SFD1_FC130 : 1;
            uint8_t D_OA2_SFD1_FC143 : 1;
            uint8_t D_OA2_SFD1_FC129 : 1; //byte 23
            uint8_t D_OA2_SFD1_FC181 : 1;
            uint8_t D_OA2_SFD1_FC190 : 1;
            uint8_t D_OA2_SFD1_FC229 : 1;
            uint8_t D_OA2_SFD1_FC232 : 1;
            uint8_t D_OA2_SFD1_FC138 : 1;
            uint8_t bit190 : 1;
            uint8_t bit191 : 1;
            uint8_t S_OA2_SFD2_Smoke_alarm : 1; //byte 24
            uint8_t S_OA2_SFD2_Heat_alarm : 1;
            uint8_t D_OA2_SFD2_Disconnection : 1;
            uint8_t D_OA2_SFD2_FC128 : 1;
            uint8_t bit196 : 1;
            uint8_t D_OA2_SFD2_FC159 : 1;
            uint8_t D_OA2_SFD2_FC130 : 1;
            uint8_t D_OA2_SFD2_FC143 : 1;
            uint8_t D_OA2_SFD2_FC129 : 1; //byte 25
            uint8_t D_OA2_SFD2_FC181 : 1;
            uint8_t D_OA2_SFD2_FC190 : 1;
            uint8_t D_OA2_SFD2_FC229 : 1;
            uint8_t D_OA2_SFD2_FC232 : 1;
            uint8_t D_OA2_SFD2_FC138 : 1;
            uint8_t bit206 : 1;
            uint8_t bit207 : 1;
            uint8_t S_OA2_SFD3_Smoke_alarm : 1; //byte 26
            uint8_t S_OA2_SFD3_Heat_alarm : 1;
            uint8_t D_OA2_SFD3_Disconnection : 1;
            uint8_t D_OA2_SFD3_FC128 : 1;
            uint8_t bit212 : 1;
            uint8_t D_OA2_SFD3_FC159 : 1;
            uint8_t D_OA2_SFD3_FC130 : 1;
            uint8_t D_OA2_SFD3_FC143 : 1;
            uint8_t D_OA2_SFD3_FC129 : 1; //byte 27
            uint8_t D_OA2_SFD3_FC181 : 1;
            uint8_t D_OA2_SFD3_FC190 : 1;
            uint8_t D_OA2_SFD3_FC229 : 1;
            uint8_t D_OA2_SFD3_FC232 : 1;
            uint8_t D_OA2_SFD3_FC138 : 1;
            uint8_t bit222 : 1;
            uint8_t bit223 : 1;
            uint8_t S_OA2_SFD4_Smoke_alarm : 1; //byte 28
            uint8_t S_OA2_SFD4_Heat_alarm : 1;
            uint8_t D_OA2_SFD4_Disconnection : 1;
            uint8_t D_OA2_SFD4_FC128 : 1;
            uint8_t bit228 : 1;
            uint8_t D_OA2_SFD4_FC159 : 1;
            uint8_t D_OA2_SFD4_FC130 : 1;
            uint8_t D_OA2_SFD4_FC143 : 1;
            uint8_t D_OA2_SFD4_FC129 : 1; //byte 29
            uint8_t D_OA2_SFD4_FC181 : 1;
            uint8_t D_OA2_SFD4_FC190 : 1;
            uint8_t D_OA2_SFD4_FC229 : 1;
            uint8_t D_OA2_SFD4_FC232 : 1;
            uint8_t D_OA2_SFD4_FC138 : 1;
            uint8_t bit238 : 1;
            uint8_t bit239 : 1;
            uint8_t reserved_30;
            uint8_t reserved_31;

        } bits;
        time_t last_update;
    };
};

/**
 * SKA1_VH	0x417
 * OA1	-
 * OA2	-
 * SKA2_VH	0x4D7
 * v1.07
*/
struct ska_vh_riom_ccu_mvb7_fds2 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint8_t S_OA2_SFD5_Smoke_alarm : 1; //byte 0
            uint8_t S_OA2_SFD5_Heat_alarm : 1;
            uint8_t D_OA2_SFD5_Disconnection : 1;
            uint8_t D_OA2_SFD5_FC128 : 1;
            uint8_t bit4 : 1;
            uint8_t D_OA2_SFD5_FC159 : 1;
            uint8_t D_OA2_SFD5_FC130 : 1;
            uint8_t D_OA2_SFD5_FC143 : 1;
            uint8_t D_OA2_SFD5_FC129 : 1; //byte 1
            uint8_t D_OA2_SFD5_FC181 : 1;
            uint8_t D_OA2_SFD5_FC190 : 1;
            uint8_t D_OA2_SFD5_FC229 : 1;
            uint8_t D_OA2_SFD5_FC232 : 1;
            uint8_t D_OA2_SFD5_FC138 : 1;
            uint8_t bit14 : 1;
            uint8_t bit15 : 1;
            uint8_t S_SKA2_SFD1_Smoke_alarm : 1; //byte 2
            uint8_t S_SKA2_SFD1_Heat_alarm : 1;
            uint8_t D_SKA2_SFD1_Disconnection : 1;
            uint8_t D_SKA2_SFD1_FC128 : 1;
            uint8_t bit20 : 1;
            uint8_t D_SKA2_SFD1_FC159 : 1;
            uint8_t D_SKA2_SFD1_FC130 : 1;
            uint8_t D_SKA2_SFD1_FC143 : 1;
            uint8_t D_SKA2_SFD1_FC129 : 1; //byte 3
            uint8_t D_SKA2_SFD1_FC181 : 1;
            uint8_t D_SKA2_SFD1_FC190 : 1;
            uint8_t D_SKA2_SFD1_FC229 : 1;
            uint8_t D_SKA2_SFD1_FC232 : 1;
            uint8_t D_SKA2_SFD1_FC138 : 1;
            uint8_t bit30 : 1;
            uint8_t bit31 : 1;
            uint8_t S_SKA2_SFD2_Smoke_alarm : 1; //byte 4
            uint8_t S_SKA2_SFD2_Heat_alarm : 1;
            uint8_t D_SKA2_SFD2_Disconnection : 1;
            uint8_t D_SKA2_SFD2_FC128 : 1;
            uint8_t bit36 : 1;
            uint8_t D_SKA2_SFD2_FC159 : 1;
            uint8_t D_SKA2_SFD2_FC130 : 1;
            uint8_t D_SKA2_SFD2_FC143 : 1;
            uint8_t D_SKA2_SFD2_FC129 : 1; //byte 5
            uint8_t D_SKA2_SFD2_FC181 : 1;
            uint8_t D_SKA2_SFD2_FC190 : 1;
            uint8_t D_SKA2_SFD2_FC229 : 1;
            uint8_t D_SKA2_SFD2_FC232 : 1;
            uint8_t D_SKA2_SFD2_FC138 : 1;
            uint8_t bit46 : 1;
            uint8_t bit47 : 1;
            uint8_t S_SKA2_SFD3_Smoke_alarm : 1; //byte 6
            uint8_t S_SKA2_SFD3_Heat_alarm : 1;
            uint8_t D_SKA2_SFD3_Disconnection : 1;
            uint8_t D_SKA2_SFD3_FC128 : 1;
            uint8_t bit52 : 1;
            uint8_t D_SKA2_SFD3_FC159 : 1;
            uint8_t D_SKA2_SFD3_FC130 : 1;
            uint8_t D_SKA2_SFD3_FC143 : 1;
            uint8_t D_SKA2_SFD3_FC129 : 1; //byte 7
            uint8_t D_SKA2_SFD3_FC181 : 1;
            uint8_t D_SKA2_SFD3_FC190 : 1;
            uint8_t D_SKA2_SFD3_FC229 : 1;
            uint8_t D_SKA2_SFD3_FC232 : 1;
            uint8_t D_SKA2_SFD3_FC138 : 1;
            uint8_t bit62 : 1;
            uint8_t bit63 : 1;
            uint8_t S_SKA2_SFD4_Smoke_alarm : 1; //byte 8
            uint8_t S_SKA2_SFD4_Heat_alarm : 1;
            uint8_t D_SKA2_SFD4_Disconnection : 1;
            uint8_t D_SKA2_SFD4_FC128 : 1;
            uint8_t bit68 : 1;
            uint8_t D_SKA2_SFD4_FC159 : 1;
            uint8_t D_SKA2_SFD4_FC130 : 1;
            uint8_t D_SKA2_SFD4_FC143 : 1;
            uint8_t D_SKA2_SFD4_FC129 : 1; //byte 9
            uint8_t D_SKA2_SFD4_FC181 : 1;
            uint8_t D_SKA2_SFD4_FC190 : 1;
            uint8_t D_SKA2_SFD4_FC229 : 1;
            uint8_t D_SKA2_SFD4_FC232 : 1;
            uint8_t D_SKA2_SFD4_FC138 : 1;
            uint8_t bit78 : 1;
            uint8_t bit79 : 1;
            uint8_t S_SKA2_SFD5_Smoke_alarm : 1; //byte 10
            uint8_t S_SKA2_SFD5_Heat_alarm : 1;
            uint8_t D_SKA2_SFD5_Disconnection : 1;
            uint8_t D_SKA2_SFD5_FC128 : 1;
            uint8_t bit84 : 1;
            uint8_t D_SKA2_SFD5_FC159 : 1;
            uint8_t D_SKA2_SFD5_FC130 : 1;
            uint8_t D_SKA2_SFD5_FC143 : 1;
            uint8_t D_SKA2_SFD5_FC129 : 1; //byte 11
            uint8_t D_SKA2_SFD5_FC181 : 1;
            uint8_t D_SKA2_SFD5_FC190 : 1;
            uint8_t D_SKA2_SFD5_FC229 : 1;
            uint8_t D_SKA2_SFD5_FC232 : 1;
            uint8_t D_SKA2_SFD5_FC138 : 1;
            uint8_t bit94 : 1;
            uint8_t bit95 : 1;
            uint8_t bit96 : 1; //byte 12
            uint8_t S_SKA1_CS_IC22_1_Heat_alarm : 1;
            uint8_t D_SKA1_CS_IC22_1_Disconnection : 1;
            uint8_t D_SKA1_CS_IC22_1_FC128 : 1;
            uint8_t D_SKA1_CS_IC22_1_FC149 : 1;
            uint8_t D_SKA1_CS_IC22_1_FC159 : 1;
            uint8_t D_SKA1_CS_IC22_1_FC143 : 1;
            uint8_t D_SKA1_CS_IC22_1_FC129 : 1;
            uint8_t D_SKA1_CS_IC22_1_FC137 : 1; //byte 13
            uint8_t D_SKA1_CS_IC22_1_FC181 : 1;
            uint8_t D_SKA1_CS_IC22_1_FC190 : 1;
            uint8_t D_SKA1_CS_IC22_1_FC229 : 1;
            uint8_t D_SKA1_CS_IC22_1_FC232 : 1;
            uint8_t D_SKA1_CS_IC22_1_FC233 : 1;
            uint8_t D_SKA1_CS_IC22_1_FC138 : 1;
            uint8_t bit111 : 1;
            uint8_t bit112 : 1; //byte 14
            uint8_t S_SKA1_CS_IC22_2_Heat_alarm : 1;
            uint8_t D_SKA1_CS_IC22_2_Disconnection : 1;
            uint8_t D_SKA1_CS_IC22_2_FC128 : 1;
            uint8_t D_SKA1_CS_IC22_2_FC149 : 1;
            uint8_t D_SKA1_CS_IC22_2_FC159 : 1;
            uint8_t D_SKA1_CS_IC22_2_FC143 : 1;
            uint8_t D_SKA1_CS_IC22_2_FC129 : 1;
            uint8_t D_SKA1_CS_IC22_2_FC137 : 1; //byte 15
            uint8_t D_SKA1_CS_IC22_2_FC181 : 1;
            uint8_t D_SKA1_CS_IC22_2_FC190 : 1;
            uint8_t D_SKA1_CS_IC22_2_FC229 : 1;
            uint8_t D_SKA1_CS_IC22_2_FC232 : 1;
            uint8_t D_SKA1_CS_IC22_2_FC233 : 1;
            uint8_t D_SKA1_CS_IC22_2_FC138 : 1;
            uint8_t bit127 : 1;
            uint8_t bit128 : 1; //byte 16
            uint8_t S_SKA1_CS_IC22_3_Heat_alarm : 1;
            uint8_t D_SKA1_CS_IC22_3_Disconnection : 1;
            uint8_t D_SKA1_CS_IC22_3_FC128 : 1;
            uint8_t D_SKA1_CS_IC22_3_FC149 : 1;
            uint8_t D_SKA1_CS_IC22_3_FC159 : 1;
            uint8_t D_SKA1_CS_IC22_3_FC143 : 1;
            uint8_t D_SKA1_CS_IC22_3_FC129 : 1;
            uint8_t D_SKA1_CS_IC22_3_FC137 : 1; //byte 17
            uint8_t D_SKA1_CS_IC22_3_FC181 : 1;
            uint8_t D_SKA1_CS_IC22_3_FC190 : 1;
            uint8_t D_SKA1_CS_IC22_3_FC229 : 1;
            uint8_t D_SKA1_CS_IC22_3_FC232 : 1;
            uint8_t D_SKA1_CS_IC22_3_FC233 : 1;
            uint8_t D_SKA1_CS_IC22_3_FC138 : 1;
            uint8_t bit143 : 1;
            uint8_t bit144 : 1; //byte 18
            uint8_t S_OA1_CS_IC22_1_Heat_alarm : 1;
            uint8_t D_OA1_CS_IC22_1_Disconnection : 1;
            uint8_t D_OA1_CS_IC22_1_FC128 : 1;
            uint8_t D_OA1_CS_IC22_1_FC149 : 1;
            uint8_t D_OA1_CS_IC22_1_FC159 : 1;
            uint8_t D_OA1_CS_IC22_1_FC143 : 1;
            uint8_t D_OA1_CS_IC22_1_FC129 : 1;
            uint8_t D_OA1_CS_IC22_1_FC137 : 1; //byte 19
            uint8_t D_OA1_CS_IC22_1_FC181 : 1;
            uint8_t D_OA1_CS_IC22_1_FC190 : 1;
            uint8_t D_OA1_CS_IC22_1_FC229 : 1;
            uint8_t D_OA1_CS_IC22_1_FC232 : 1;
            uint8_t D_OA1_CS_IC22_1_FC233 : 1;
            uint8_t D_OA1_CS_IC22_1_FC138 : 1;
            uint8_t bit159 : 1;
            uint8_t bit160 : 1; //byte 20
            uint8_t S_OA1_CS_IC22_2_Heat_alarm : 1;
            uint8_t D_OA1_CS_IC22_2_Disconnection : 1;
            uint8_t D_OA1_CS_IC22_2_FC128 : 1;
            uint8_t D_OA1_CS_IC22_2_FC149 : 1;
            uint8_t D_OA1_CS_IC22_2_FC159 : 1;
            uint8_t D_OA1_CS_IC22_2_FC143 : 1;
            uint8_t D_OA1_CS_IC22_2_FC129 : 1;
            uint8_t D_OA1_CS_IC22_2_FC137 : 1; //byte 21
            uint8_t D_OA1_CS_IC22_2_FC181 : 1;
            uint8_t D_OA1_CS_IC22_2_FC190 : 1;
            uint8_t D_OA1_CS_IC22_2_FC229 : 1;
            uint8_t D_OA1_CS_IC22_2_FC232 : 1;
            uint8_t D_OA1_CS_IC22_2_FC233 : 1;
            uint8_t D_OA1_CS_IC22_2_FC138 : 1;
            uint8_t bit175 : 1;
            uint8_t bit176 : 1; //byte 22
            uint8_t S_OA1_CS_IC22_3_Heat_alarm : 1;
            uint8_t D_OA1_CS_IC22_3_Disconnection : 1;
            uint8_t D_OA1_CS_IC22_3_FC128 : 1;
            uint8_t D_OA1_CS_IC22_3_FC149 : 1;
            uint8_t D_OA1_CS_IC22_3_FC159 : 1;
            uint8_t D_OA1_CS_IC22_3_FC143 : 1;
            uint8_t D_OA1_CS_IC22_3_FC129 : 1;
            uint8_t D_OA1_CS_IC22_3_FC137 : 1; //byte 23
            uint8_t D_OA1_CS_IC22_3_FC181 : 1;
            uint8_t D_OA1_CS_IC22_3_FC190 : 1;
            uint8_t D_OA1_CS_IC22_3_FC229 : 1;
            uint8_t D_OA1_CS_IC22_3_FC232 : 1;
            uint8_t D_OA1_CS_IC22_3_FC233 : 1;
            uint8_t D_OA1_CS_IC22_3_FC138 : 1;
            uint8_t bit191 : 1;
            uint8_t bit192 : 1; //byte 24
            uint8_t S_OA2_CS_IC22_1_Heat_alarm : 1;
            uint8_t D_OA2_CS_IC22_1_Disconnection : 1;
            uint8_t D_OA2_CS_IC22_1_FC128 : 1;
            uint8_t D_OA2_CS_IC22_1_FC149 : 1;
            uint8_t D_OA2_CS_IC22_1_FC159 : 1;
            uint8_t D_OA2_CS_IC22_1_FC143 : 1;
            uint8_t D_OA2_CS_IC22_1_FC129 : 1;
            uint8_t D_OA2_CS_IC22_1_FC137 : 1; //byte 25
            uint8_t D_OA2_CS_IC22_1_FC181 : 1;
            uint8_t D_OA2_CS_IC22_1_FC190 : 1;
            uint8_t D_OA2_CS_IC22_1_FC229 : 1;
            uint8_t D_OA2_CS_IC22_1_FC232 : 1;
            uint8_t D_OA2_CS_IC22_1_FC233 : 1;
            uint8_t D_OA2_CS_IC22_1_FC138 : 1;
            uint8_t bit207 : 1;
            uint8_t bit208 : 1; //byte 26
            uint8_t S_OA2_CS_IC22_2_Heat_alarm : 1;
            uint8_t D_OA2_CS_IC22_2_Disconnection : 1;
            uint8_t D_OA2_CS_IC22_2_FC128 : 1;
            uint8_t D_OA2_CS_IC22_2_FC149 : 1;
            uint8_t D_OA2_CS_IC22_2_FC159 : 1;
            uint8_t D_OA2_CS_IC22_2_FC143 : 1;
            uint8_t D_OA2_CS_IC22_2_FC129 : 1;
            uint8_t D_OA2_CS_IC22_2_FC137 : 1; //byte 27
            uint8_t D_OA2_CS_IC22_2_FC181 : 1;
            uint8_t D_OA2_CS_IC22_2_FC190 : 1;
            uint8_t D_OA2_CS_IC22_2_FC229 : 1;
            uint8_t D_OA2_CS_IC22_2_FC232 : 1;
            uint8_t D_OA2_CS_IC22_2_FC233 : 1;
            uint8_t D_OA2_CS_IC22_2_FC138 : 1;
            uint8_t bit223 : 1;
            uint8_t bit224 : 1; //byte 28
            uint8_t S_OA2_CS_IC22_3_Heat_alarm : 1;
            uint8_t D_OA2_CS_IC22_3_Disconnection : 1;
            uint8_t D_OA2_CS_IC22_3_FC128 : 1;
            uint8_t D_OA2_CS_IC22_3_FC149 : 1;
            uint8_t D_OA2_CS_IC22_3_FC159 : 1;
            uint8_t D_OA2_CS_IC22_3_FC143 : 1;
            uint8_t D_OA2_CS_IC22_3_FC129 : 1;
            uint8_t D_OA2_CS_IC22_3_FC137 : 1; //byte 29
            uint8_t D_OA2_CS_IC22_3_FC181 : 1;
            uint8_t D_OA2_CS_IC22_3_FC190 : 1;
            uint8_t D_OA2_CS_IC22_3_FC229 : 1;
            uint8_t D_OA2_CS_IC22_3_FC232 : 1;
            uint8_t D_OA2_CS_IC22_3_FC233 : 1;
            uint8_t D_OA2_CS_IC22_3_FC138 : 1;
            uint8_t bit239 : 1;
            uint8_t reserved_30;
            uint8_t reserved_31;
        } bits;
        time_t last_update;
    };
};

/**
 * SKA1_VH	0x418
 * OA1	-
 * OA2	-
 * SKA2_VH	0x4D8
 * v1.07
*/
struct ska_vh_riom_ccu_mvb8_fds3 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint8_t bit0 :1;//byte 0
            uint8_t S_SKA2_CS_IC22_1_Heat_alarm  :1;
            uint8_t D_SKA2_CS_IC22_1_Disconnection  :1;
            uint8_t D_SKA2_CS_IC22_1_FC128 :1;
            uint8_t D_SKA2_CS_IC22_1_FC149 :1;
            uint8_t D_SKA2_CS_IC22_1_FC159 :1;
            uint8_t D_SKA2_CS_IC22_1_FC143 :1;
            uint8_t D_SKA2_CS_IC22_1_FC129 :1;
            uint8_t D_SKA2_CS_IC22_1_FC137 :1;//byte 1
            uint8_t D_SKA2_CS_IC22_1_FC181 :1;
            uint8_t D_SKA2_CS_IC22_1_FC190 :1;
            uint8_t D_SKA2_CS_IC22_1_FC229 :1;
            uint8_t D_SKA2_CS_IC22_1_FC232 :1;
            uint8_t D_SKA2_CS_IC22_1_FC233 :1;
            uint8_t D_SKA2_CS_IC22_1_FC138 :1;
            uint8_t bit15 :1;
            uint8_t bit16 :1;//byte 2
            uint8_t S_SKA2_CS_IC22_2_Heat_alarm  :1;
            uint8_t D_SKA2_CS_IC22_2_Disconnection  :1;
            uint8_t D_SKA2_CS_IC22_2_FC128 :1;
            uint8_t D_SKA2_CS_IC22_2_FC149 :1;
            uint8_t D_SKA2_CS_IC22_2_FC159 :1;
            uint8_t D_SKA2_CS_IC22_2_FC143 :1;
            uint8_t D_SKA2_CS_IC22_2_FC129 :1;
            uint8_t D_SKA2_CS_IC22_2_FC137 :1;//byte 3
            uint8_t D_SKA2_CS_IC22_2_FC181 :1;
            uint8_t D_SKA2_CS_IC22_2_FC190 :1;
            uint8_t D_SKA2_CS_IC22_2_FC229 :1;
            uint8_t D_SKA2_CS_IC22_2_FC232 :1;
            uint8_t D_SKA2_CS_IC22_2_FC233 :1;
            uint8_t D_SKA2_CS_IC22_2_FC138 :1;
            uint8_t bit31 :1;
            uint8_t bit32 :1;//byte 4
            uint8_t S_SKA2_CS_IC22_3_Heat_alarm  :1;
            uint8_t D_SKA2_CS_IC22_3_Disconnection  :1;
            uint8_t D_SKA2_CS_IC22_3_FC128 :1;
            uint8_t D_SKA2_CS_IC22_3_FC149 :1;
            uint8_t D_SKA2_CS_IC22_3_FC159 :1;
            uint8_t D_SKA2_CS_IC22_3_FC143 :1;
            uint8_t D_SKA2_CS_IC22_3_FC129 :1;
            uint8_t D_SKA2_CS_IC22_3_FC137 :1;//byte 5
            uint8_t D_SKA2_CS_IC22_3_FC181 :1;
            uint8_t D_SKA2_CS_IC22_3_FC190 :1;
            uint8_t D_SKA2_CS_IC22_3_FC229 :1;
            uint8_t D_SKA2_CS_IC22_3_FC232 :1;
            uint8_t D_SKA2_CS_IC22_3_FC233 :1;
            uint8_t D_SKA2_CS_IC22_3_FC138 :1;
            uint8_t bit47 :1;
            uint8_t D_SKA1_CS_Loop_M_FC128 :1;//byte 6
            uint8_t D_SKA1_CS_Loop_M_FC230 :1;
            uint8_t D_SKA1_CS_Loop_M_FC231 :1;
            uint8_t D_SKA1_CS_Loop_M_FC168 :1;
            uint8_t bit52 :1;
            uint8_t D_SKA1_CS_Loop_M_FC140 :1;
            uint8_t D_SKA1_CS_Loop_M_FC159 :1;
            uint8_t D_SKA1_CS_Loop_M_FC155 :1;
            uint8_t D_SKA1_CS_Loop_M_FC156 :1;//byte 7
            uint8_t D_SKA1_CS_Loop_M_FC141 :1;
            uint8_t D_SKA1_CS_Loop_M_FC142 :1;
            uint8_t D_SKA1_CS_Loop_M_FC143 :1;
            uint8_t D_SKA1_CS_Loop_M_FC169 :1;
            uint8_t D_SKA1_CS_Loop_M_FC183 :1;
            uint8_t D_SKA1_CS_Loop_M_FC184 :1;
            uint8_t D_SKA1_CS_Loop_M_FC153 :1;
            uint8_t D_SKA1_CS_Loop_M_FC176 :1;//byte 8
            uint8_t D_SKA1_CS_Loop_M_FC181 :1;
            uint8_t D_SKA1_CS_Loop_M_FC189 :1;
            uint8_t D_SKA1_CS_Loop_M_FC210 :1;
            uint8_t D_SKA1_CS_Loop_M_FC213 :1;
            uint8_t D_SKA1_CS_Loop_M_FC217 :1;
            uint8_t D_SKA1_CS_Loop_M_FC218 :1;
            uint8_t D_SKA1_CS_Loop_M_FC229 :1;
            uint8_t D_SKA1_CS_Loop_M_FC232 :1;//byte 9
            uint8_t D_SKA1_CS_Loop_M_FC152 :1;
            uint8_t D_SKA1_CS_Loop_M_FC209 :1;
            uint8_t bit75 :1;
            uint8_t bit76 :1;
            uint8_t bit77 :1;
            uint8_t bit78 :1;
            uint8_t bit79 :1;
            uint8_t D_SKA1_CM_22_FC128 :1;//byte 10
            uint8_t D_SKA1_CM_22_FC230 :1;
            uint8_t D_SKA1_CM_22_FC231 :1;
            uint8_t D_SKA1_CM_22_FC168 :1;
            uint8_t bit84 :1;
            uint8_t D_SKA1_CM_22_FC137 :1;
            uint8_t bit86 :1;
            uint8_t D_SKA1_CM_22_FC143 :1;
            uint8_t D_SKA1_CM_22_FC169 :1;//byte 11
            uint8_t D_SKA1_CM_22_FC225 :1;
            uint8_t D_SKA1_CM_22_FC176 :1;
            uint8_t D_SKA1_CM_22_FC210 :1;
            uint8_t D_SKA1_CM_22_FC213 :1;
            uint8_t bit93 :1;
            uint8_t bit94 :1;
            uint8_t bit95 :1;
            uint8_t D_SKA2_CS_Loop_M_FC128 :1;//byte 12
            uint8_t D_SKA2_CS_Loop_M_FC230 :1;
            uint8_t D_SKA2_CS_Loop_M_FC231 :1;
            uint8_t D_SKA2_CS_Loop_M_FC168 :1;
            uint8_t bit100 :1;
            uint8_t D_SKA2_CS_Loop_M_FC140 :1;
            uint8_t D_SKA2_CS_Loop_M_FC159 :1;
            uint8_t D_SKA2_CS_Loop_M_FC155 :1;
            uint8_t D_SKA2_CS_Loop_M_FC156 :1;//byte 13
            uint8_t D_SKA2_CS_Loop_M_FC141 :1;
            uint8_t D_SKA2_CS_Loop_M_FC142 :1;
            uint8_t D_SKA2_CS_Loop_M_FC143 :1;
            uint8_t D_SKA2_CS_Loop_M_FC169 :1;
            uint8_t D_SKA2_CS_Loop_M_FC183 :1;
            uint8_t D_SKA2_CS_Loop_M_FC184 :1;
            uint8_t D_SKA2_CS_Loop_M_FC153 :1;
            uint8_t D_SKA2_CS_Loop_M_FC176 :1;//byte 14
            uint8_t D_SKA2_CS_Loop_M_FC181 :1;
            uint8_t D_SKA2_CS_Loop_M_FC189 :1;
            uint8_t D_SKA2_CS_Loop_M_FC210 :1;
            uint8_t D_SKA2_CS_Loop_M_FC213 :1;
            uint8_t D_SKA2_CS_Loop_M_FC217 :1;
            uint8_t D_SKA2_CS_Loop_M_FC218 :1;
            uint8_t D_SKA2_CS_Loop_M_FC229 :1;
            uint8_t D_SKA2_CS_Loop_M_FC232 :1;//byte 15
            uint8_t D_SKA2_CS_Loop_M_FC152 :1;
            uint8_t D_SKA2_CS_Loop_M_FC209 :1;
            uint8_t bit123 :1;
            uint8_t bit124 :1;
            uint8_t bit125 :1;
            uint8_t bit126 :1;
            uint8_t bit127 :1;
            uint8_t D_SKA2_CM_22_FC128 :1;//byte 16
            uint8_t D_SKA2_CM_22_FC230 :1;
            uint8_t D_SKA2_CM_22_FC231 :1;
            uint8_t D_SKA2_CM_22_FC168 :1;
            uint8_t bit132 :1;
            uint8_t D_SKA2_CM_22_FC137 :1;
            uint8_t bit134 :1;
            uint8_t D_SKA2_CM_22_FC143 :1;
            uint8_t D_SKA2_CM_22_FC169 :1;// byte 17
            uint8_t D_SKA2_CM_22_FC225 :1;
            uint8_t D_SKA2_CM_22_FC176 :1;
            uint8_t D_SKA2_CM_22_FC210 :1;
            uint8_t D_SKA2_CM_22_FC213 :1;
            uint8_t bit141 :1;
            uint8_t bit142 :1;
            uint8_t bit143 :1;
            uint8_t D_SKA1_Relay_M8_FC128 :1;//byte 18
            uint8_t D_SKA1_Relay_M8_FC230 :1;
            uint8_t D_SKA1_Relay_M8_FC231 :1;
            uint8_t D_SKA1_Relay_M8_FC168 :1;
            uint8_t bit148 :1;
            uint8_t bit149 :1;
            uint8_t bit150 :1;
            uint8_t D_SKA1_Relay_M8_FC143 :1;
            uint8_t D_SKA1_Relay_M8_FC169 :1;//bit 19
            uint8_t D_SKA1_Relay_M8_FC183 :1;
            uint8_t D_SKA1_Relay_M8_FC184 :1;
            uint8_t D_SKA1_Relay_M8_FC216 :1;
            uint8_t D_SKA1_Relay_M8_FC232 :1;
            uint8_t D_SKA1_Relay_M8_Relay_1_Any_fault :1;
            uint8_t D_SKA1_Relay_M8_Relay_2_Any_fault :1;
            uint8_t D_SKA1_Relay_M8_Relay_3_Any_fault :1;
            uint8_t D_SKA1_Relay_M8_Relay_4_Any_fault :1;//bit 20
            uint8_t D_SKA1_Relay_M8_Relay_5_Any_fault :1;
            uint8_t D_SKA1_Relay_M8_Relay_6_Any_fault :1;
            uint8_t D_SKA1_Relay_M8_Relay_7_Any_fault :1;
            uint8_t D_SKA1_Relay_M8_Relay_8_Any_fault :1;
            uint8_t bit165 :1;
            uint8_t bit166 :1;
            uint8_t bit167 :1;
            uint8_t D_SKA2_Relay_M8_FC128 :1;//byte 21
            uint8_t D_SKA2_Relay_M8_FC230 :1;
            uint8_t D_SKA2_Relay_M8_FC231 :1;
            uint8_t D_SKA2_Relay_M8_FC168 :1;
            uint8_t bit172 :1;
            uint8_t bit173 :1;
            uint8_t bit174 :1;
            uint8_t D_SKA2_Relay_M8_FC143 :1;
            uint8_t D_SKA2_Relay_M8_FC169 :1;//byte 22
            uint8_t D_SKA2_Relay_M8_FC183 :1;
            uint8_t D_SKA2_Relay_M8_FC184 :1;
            uint8_t D_SKA2_Relay_M8_FC216 :1;
            uint8_t D_SKA2_Relay_M8_FC232 :1;
            uint8_t D_SKA2_Relay_M8_Relay_1_Any_fault :1;
            uint8_t D_SKA2_Relay_M8_Relay_2_Any_fault :1;
            uint8_t D_SKA2_Relay_M8_Relay_3_Any_fault :1;
            uint8_t D_SKA2_Relay_M8_Relay_4_Any_fault :1;//byte 23
            uint8_t D_SKA2_Relay_M8_Relay_5_Any_fault :1;
            uint8_t D_SKA2_Relay_M8_Relay_6_Any_fault :1;
            uint8_t D_SKA2_Relay_M8_Relay_7_Any_fault :1;
            uint8_t D_SKA2_Relay_M8_Relay_8_Any_fault :1;
            uint8_t bit189 :1;
            uint8_t bit190 :1;
            uint8_t bit191 :1;
            uint8_t reserved_24;
            uint8_t SW_Release_Version;//byte 25
            uint8_t SW_Major_Version ;//byte 26
            uint8_t SW_Minor_Version ;//byte 27
            //uint8_t SW_Built_Version ;//byte 28
            uint8_t Application_Identifier ;//byte 28
            uint8_t reserved_29;
            uint8_t reserved_30;
            uint8_t reserved_31;


        } bits;
        time_t last_update;
    };
};

/**
 * SKA1_VH	0x419
 * OA1	-
 * OA2	-
 * SKA2_VH	0x4D9
 * v1.07
*/
struct ska_vh_riom_ccu_mvb9_ats {
    union {
        uint8_t bytes[IO_RAW_NBYTES_16];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_16)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_16)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_16)];

        struct {
            uint8_t ATS_major_software_version_major; //byte 0
            uint8_t ATS_minor_software_version; //byte1
            uint8_t ATS_bypass : 1; //byte2
            uint8_t ATS_mode_on : 1;
            uint8_t ATS_brake_applied : 1;
            uint8_t ATS_magnet_type : 1;
            uint8_t ATS_ERTMS_con : 1;
            uint8_t ATS_ERTMS_ack : 1;
            uint8_t bit22 : 1;
            uint8_t Self_test_result_updated : 1;
            uint8_t reserved_3;
            uint8_t Self_test_magnet : 1; //byte 4
            uint8_t Self_test_skb : 1;
            uint8_t Self_test_pressure : 1;
            uint8_t Self_test_brake : 1;
            uint8_t Self_test_direction : 1;
            uint8_t Self_test_sd_card : 1;
            uint8_t Self_test_rtc : 1;
            uint8_t Self_test_temperature : 1;
            uint8_t Self_test_cabin : 1; //byte 5
            uint8_t Self_test_speed : 1;
            uint8_t Self_test_contact_v12 : 1;
            uint8_t Self_test_contact_v40 : 1;
            uint8_t Self_test_contact_v65 : 1;
            uint8_t Self_test_ethernet : 1;
            uint8_t Self_test_zdata : 1;
            uint8_t Self_test_bypass : 1;
            uint8_t reserved_6;
            uint8_t Brake_application_reason; //byte 7
            uint8_t Fault_magnet_connection : 1; //byte 8
            uint8_t Fault_magnet_frequency : 1;
            uint8_t Fault_skb_communication : 1;
            uint8_t Fault_pressure_sensor : 1;
            uint8_t Fault_brake_conflict : 1;
            uint8_t Fault_direction_conflict : 1;
            uint8_t Fault_sd_card_communication : 1;
            uint8_t Fault_sd_card_full : 1;
            uint8_t Fault_rtc_read_write : 1; //byte 9
            uint8_t Fault_temp_sensor : 1;
            uint8_t Fault_cabin_data : 1;
            uint8_t Fault_speed_data : 1;
            uint8_t Fault_v12_contact : 1;
            uint8_t Fault_v40_contact : 1;
            uint8_t Fault_v65_contact : 1;
            uint8_t Fault_ethernet : 1;
            uint8_t reserved_10 : 1; //byte 10
            uint8_t Status_zz : 1; //byte 11
            uint8_t Status_zw : 1;
            uint8_t Status_zg : 1;
            uint8_t Status_ze : 1;
            uint8_t Status_zc : 1;
            uint8_t Status_zb : 1;
            uint8_t Status_tekrar_tanzim_bt_pressed : 1;
            uint8_t Status_reset_bt_pressed : 1;
            uint8_t Status_uyari_onay_bt_pressed : 1; //byte 12
            uint8_t Status_izinli_gecis_activated : 1;
            uint8_t Status_hiz_serbest_activated : 1;
            uint8_t bit100 : 1;
            uint8_t bit101 : 1;
            uint8_t bit102 : 1;
            uint8_t bit103 : 1;
            uint8_t ATS_CANopen_Fault : 1;
            uint8_t reserved_13; //byte 13
            uint8_t reserved_14; //byte 14
            uint8_t reserved_15; //byte 15

        } bits;
        time_t last_update;
    };
};

/**
 * SKA1_VH	0x41A
 * OA1	-
 * OA2	-
 * SKA2_VH	0x4DA
 * v1.07
*/

struct ska_vh_riom_ccu_mvb10_papis1 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint8_t PapisINF_Piscu_SKA1_M : 1; //byte 0
            uint8_t PapisINF_Piscu_SKA2_M : 1;
            uint8_t bit2 : 1;
            uint8_t bit3 : 1;
            uint8_t PapisINF_nvr_SKA1_M : 1;
            uint8_t PapisINF_nvr_SKA2_M : 1;
            uint8_t bit6 : 1;
            uint8_t bit7 : 1;
            uint8_t Piscu_SKA1_Network_Failure :1; //byte 1
            uint8_t Piscu_SKA1_Power_Failure :1;
            uint8_t Piscu_SKA1_Version_Error :1;
            uint8_t Piscu_SKA1_OS_Error :1;
            uint8_t bit12 : 1;
            uint8_t bit13 : 1;
            uint8_t bit14 : 1;
            uint8_t bit15 : 1;
            uint8_t Piscu_SKA2_Network_Failure :1; //byte 2
            uint8_t Piscu_SKA2_Power_Failure :1;
            uint8_t Piscu_SKA2_Version_Error :1;
            uint8_t Piscu_SKA2_OS_Error :1;
            uint8_t bit20 : 1;
            uint8_t bit21 : 1;
            uint8_t bit22 : 1;
            uint8_t bit23 : 1;
            uint8_t Pis_01_02_SKA1_Error : 1; //byte 3
            uint8_t Pis_03_04_SKA1_Error : 1;
            uint8_t Pis_05_06_SKA1_Error : 1;
            uint8_t Pis_07_08_SKA1_Error : 1;
            uint8_t Pis_01_02_OA1_Error : 1;
            uint8_t Pis_03_04_OA1_Error : 1;
            uint8_t Pis_05_06_OA1_Error : 1;
            uint8_t Pis_07_08_OA1_Error : 1;
            uint8_t Pis_01_02_OA2_Error : 1; //byte 4
            uint8_t Pis_03_04_OA2_Error : 1;
            uint8_t Pis_05_06_OA2_Error : 1;
            uint8_t Pis_07_08_OA2_Error : 1;
            uint8_t Pis_01_02_SKA2_Error : 1;
            uint8_t Pis_03_04_SKA2_Error : 1;
            uint8_t Pis_05_06_SKA2_Error : 1;
            uint8_t Pis_07_08_SKA2_Error : 1;
            uint8_t FrontLed1_SKA1_Process_Error : 1; //byte 5
            uint8_t FrontLed1_SKA1_Version_Error : 1;
            uint8_t FrontLed1_SKA1_Device_Busy : 1;
            uint8_t FrontLed1_SKA1_System_Error : 1;
            uint8_t bit44 : 1;
            uint8_t OutLed1_SKA1_Process_Error : 1;
            uint8_t OutLed1_SKA1_Version_Error : 1;
            uint8_t OutLed1_SKA1_Device_Busy : 1;
            uint8_t OutLed1_SKA1_System_Error : 1;	//byte 6
            uint8_t bit49 : 1;
            uint8_t OutLed2_SKA1_Process_Error : 1;
            uint8_t OutLed2_SKA1_Version_Error : 1;
            uint8_t OutLed2_SKA1_Device_Busy : 1;
            uint8_t OutLed2_SKA1_System_Error : 1;
            uint8_t bit54 : 1;
            uint8_t OutLed1_OA1_Process_Error : 1;
            uint8_t OutLed1_OA1_Version_Error : 1; //byte 7
            uint8_t OutLed1_OA1_Device_Busy : 1;
            uint8_t OutLed1_OA1_System_Error : 1;
            uint8_t bit59: 1;
            uint8_t OutLed2_OA1_Process_Error : 1;
            uint8_t OutLed2_OA1_Version_Error : 1;
            uint8_t OutLed2_OA1_Device_Busy : 1;
            uint8_t OutLed2_OA1_System_Error : 1;
            uint8_t bit64 : 1; //byte 8
            uint8_t OutLed1_OA2_Process_Error : 1;
            uint8_t OutLed1_OA2_Version_Error : 1;
            uint8_t OutLed1_OA2_Device_Busy : 1;
            uint8_t OutLed1_OA2_System_Error : 1;
            uint8_t bit69 : 1;
            uint8_t OutLed2_OA2_Process_Error : 1;
            uint8_t OutLed2_OA2_Version_Error : 1;
            uint8_t OutLed2_OA2_Device_Busy : 1; //byte 9
            uint8_t OutLed2_OA2_System_Error : 1;
            uint8_t bit74 : 1;
            uint8_t FrontLed1_SKA2_Process_Error : 1;
            uint8_t FrontLed1_SKA2_Version_Error : 1;
            uint8_t FrontLed1_SKA2_Device_Busy : 1;
            uint8_t FrontLed1_SKA2_System_Error : 1;
            uint8_t bit79: 1;
            uint8_t OutLed1_SKA2_Process_Error : 1; //byte 10
            uint8_t OutLed1_SKA2_Version_Error : 1;
            uint8_t OutLed1_SKA2_Device_Busy : 1;
            uint8_t OutLed1_SKA2_System_Error : 1;
            uint8_t bit84 : 1;
            uint8_t OutLed2_SKA2_Process_Error : 1;
            uint8_t OutLed2_SKA2_Version_Error : 1;
            uint8_t OutLed2_SKA2_Device_Busy : 1;
            uint8_t OutLed2_SKA2_System_Error : 1; //byte 11
            uint8_t bit89: 1;
            uint8_t CCTV_HMI_SKA1_Network_Failure : 1;
            uint8_t CCTV_HMI_SKA1_Power_Failure : 1;
            uint8_t CCTV_HMI_SKA1_Server_Error : 1;
            uint8_t bit93 : 1;
            uint8_t CCTV_HMI_SKA2_Network_Failure : 1;
            uint8_t CCTV_HMI_SKA2_Power_Failure : 1;
            uint8_t CCTV_HMI_SKA2_Server_Error : 1; //byte 12
            uint8_t bit97 : 1;
            uint8_t F_Cam1_SKA1_Network_Failure : 1;
            uint8_t F_Cam1_SKA1_Power_Failure : 1;
            uint8_t bit100 : 1;
            uint8_t C_Cam1_SKA1_Network_Failure : 1;
            uint8_t C_Cam1_SKA1_Power_Failure : 1;
            uint8_t bit103: 1;
            uint8_t PS_Cam1_SKA1_Network_Failure : 1; //byte13
            uint8_t PS_Cam1_SKA1_Power_Failure : 1;
            uint8_t bit106 : 1;
            uint8_t PS_Cam2_SKA1_Network_Failure : 1;
            uint8_t PS_Cam2_SKA1_Power_Failure : 1;
            uint8_t bit109 : 1;
            uint8_t PS_Cam3_SKA1_Network_Failure : 1;
            uint8_t PS_Cam3_SKA1_Power_Failure : 1;
            uint8_t bit112 : 1;						//byte14
            uint8_t PS_Cam4_SKA1_Network_Failure : 1;
            uint8_t PS_Cam4_SKA1_Power_Failure : 1;
            uint8_t bit115 : 1;
            uint8_t RL_Cam4_SKA1_Network_Failure : 1;
            uint8_t RL_Cam4_SKA1_Power_Failure : 1;
            uint8_t bit118 : 1;
            uint8_t RR_Cam1_SKA1_Network_Failure : 1;
            uint8_t RR_Cam1_SKA1_Power_Failure : 1; //byte 15
            uint8_t bit121 : 1;
            uint8_t PS_Cam1_OA1_Network_Failure : 1;
            uint8_t PS_Cam1_OA1_Power_Failure : 1;
            uint8_t bit124 : 1;
            uint8_t PS_Cam2_OA1_Network_Failure : 1;
            uint8_t PS_Cam2_OA1_Power_Failure : 1;
            uint8_t bit127 : 1;
            uint8_t PS_Cam3_OA1_Network_Failure : 1; //byte16
            uint8_t PS_Cam3_OA1_Power_Failure : 1;
            uint8_t bit130 : 1;
            uint8_t PS_Cam4_OA1_Network_Failure : 1;
            uint8_t PS_Cam4_OA1_Power_Failure : 1;
            uint8_t bit133 : 1;
            uint8_t PN_Cam1_OA1_Network_Failure : 1;
            uint8_t PN_Cam1_OA1_Power_Failure : 1;
            uint8_t bit136: 1; 						//byte17
            uint8_t PN_Cam1_OA2_Network_Failure : 1;
            uint8_t PN_Cam1_OA2_Power_Failure : 1;
            uint8_t bit139 : 1;
            uint8_t PS_Cam1_OA2_Network_Failure : 1;
            uint8_t PS_Cam1_OA2_Power_Failure : 1;
            uint8_t bit142 : 1;
            uint8_t PS_Cam2_OA2_Network_Failure : 1;
            uint8_t PS_Cam2_OA2_Power_Failure : 1; //byte 18
            uint8_t bit145 : 1;
            uint8_t PS_Cam3_OA2_Network_Failure : 1;
            uint8_t PS_Cam3_OA2_Power_Failure : 1;
            uint8_t bit148 : 1;
            uint8_t PS_Cam4_OA2_Network_Failure : 1;
            uint8_t PS_Cam4_OA2_Power_Failure : 1;
            uint8_t bit151: 1;
            uint8_t F_Cam1_SKA2_Network_Failure : 1; //byte 19
            uint8_t F_Cam1_SKA2_Power_Failure : 1;
            uint8_t bit154 : 1;
            uint8_t C_Cam1_SKA2_Network_Failure : 1;
            uint8_t C_Cam1_SKA2_Power_Failure : 1;
            uint8_t bit157 : 1;
            uint8_t PS_Cam1_SKA2_Network_Failure : 1;
            uint8_t PS_Cam1_SKA2_Power_Failure : 1;
            uint8_t bit160 : 1;						//byte 20
            uint8_t PS_Cam2_SKA2_Network_Failure : 1;
            uint8_t PS_Cam2_SKA2_Power_Failure : 1;
            uint8_t bit163 : 1;
            uint8_t PS_Cam3_SKA2_Network_Failure : 1;
            uint8_t PS_Cam3_SKA2_Power_Failure : 1;
            uint8_t bit166 : 1;
            uint8_t PS_Cam4_SKA2_Network_Failure : 1;
            uint8_t PS_Cam4_SKA2_Power_Failure : 1; //byte 21
            uint8_t bit169 : 1;
            uint8_t RL_Cam1_SKA2_Network_Failure : 1;
            uint8_t RL_Cam1_SKA2_Power_Failure : 1;
            uint8_t bit172 : 1;
            uint8_t RR_Cam2_SKA2_Network_Failure : 1;
            uint8_t RR_Cam2_SKA2_Power_Failure : 1;
            uint8_t bit175 : 1;
            uint8_t Intercom1_SKA1_Network_Failure : 1; //byte 22
            uint8_t Intercom1_SKA1_Power_Failure : 1;
            uint8_t Intercom1_SKA1_Timeout : 1;
            uint8_t Intercom1_SKA1_Not_Found : 1;
            uint8_t bit180: 1;
            uint8_t Intercom2_SKA1_Network_Failure : 1;
            uint8_t Intercom2_SKA1_Power_Failure : 1;
            uint8_t Intercom2_SKA1_Timeout : 1;
            uint8_t Intercom2_SKA1_Not_Found : 1; //byte 23
            uint8_t bit185 : 1;
            uint8_t Intercom3_SKA1_Network_Failure : 1;
            uint8_t Intercom3_SKA1_Power_Failure : 1;
            uint8_t Intercom3_SKA1_Timeout : 1;
            uint8_t Intercom3_SKA1_Not_Found : 1;
            uint8_t bit190 : 1;
            uint8_t bit191 : 1;
            uint8_t Intercom4_SKA1_Network_Failure : 1; //byte24
            uint8_t Intercom4_SKA1_Power_Failure : 1;
            uint8_t Intercom4_SKA1_Timeout : 1;
            uint8_t Intercom4_SKA1_Not_Found : 1;
            uint8_t bit196 : 1;
            uint8_t Intercom5_SKA1_Network_Failure : 1;
            uint8_t Intercom5_SKA1_Power_Failure : 1;
            uint8_t Intercom5_SKA1_Timeout : 1;
            uint8_t Intercom5_SKA1_Not_Found : 1; //byte25
            uint8_t bit201 : 1;
            uint8_t Intercom6_SKA1_Network_Failure : 1;
            uint8_t Intercom6_SKA1_Power_Failure : 1;
            uint8_t Intercom6_SKA1_Timeout : 1;
            uint8_t Intercom6_SKA1_Not_Found : 1;
            uint8_t bit206 : 1;
            uint8_t Intercom7_SKA1_Network_Failure : 1;
            uint8_t Intercom7_SKA1_Power_Failure : 1; //byte26
            uint8_t Intercom7_SKA1_Timeout : 1;
            uint8_t Intercom7_SKA1_Not_Found : 1;
            uint8_t bit211 : 1;
            uint8_t Intercom8_SKA1_Network_Failure : 1;
            uint8_t Intercom8_SKA1_Power_Failure : 1;
            uint8_t Intercom8_SKA1_Timeout : 1;
            uint8_t Intercom8_SKA1_Not_Found : 1;
            uint8_t bit216: 1;						//byte27
            uint8_t Intercom9_SKA1_Network_Failure : 1;
            uint8_t Intercom9_SKA1_Power_Failure : 1;
            uint8_t Intercom9_SKA1_Timeout : 1;
            uint8_t Intercom9_SKA1_Not_Found : 1;
            uint8_t bit221 : 1;
            uint8_t Intercom1_OA1_Network_Failure : 1;
            uint8_t Intercom1_OA1_Power_Failure : 1;
            uint8_t	Intercom1_OA1_Timeout : 1;  	//byte28
            uint8_t	Intercom1_OA1_Not_Found : 1;
            uint8_t	bit226: 1;
            uint8_t	Intercom2_OA1_Network_Failure : 1;
            uint8_t	Intercom2_OA1_Power_Failure : 1;
            uint8_t	Intercom2_OA1_Timeout : 1;
            uint8_t	Intercom2_OA1_Not_Found : 1;
            uint8_t	bit231 : 1;
            uint8_t	Intercom3_OA1_Network_Failure : 1;   //byte29
            uint8_t	Intercom3_OA1_Power_Failure : 1;
            uint8_t	Intercom3_OA1_Timeout : 1;
            uint8_t	Intercom3_OA1_Not_Found : 1;
            uint8_t	bit236 : 1;
            uint8_t	Intercom4_OA1_Network_Failure : 1;
            uint8_t	Intercom4_OA1_Power_Failure : 1;
            uint8_t	Intercom4_OA1_Timeout : 1;
            uint8_t	Intercom4_OA1_Not_Found : 1; 		//byte30
            uint8_t	bit241 : 1;
            uint8_t	Intercom5_OA1_Network_Failure : 1;
            uint8_t	Intercom5_OA1_Power_Failure : 1;
            uint8_t	Intercom5_OA1_Timeout : 1;
            uint8_t	Intercom5_OA1_Not_Found : 1;
            uint8_t	bit246 : 1;
            uint8_t	Intercom6_OA1_Network_Failure : 1;
            uint8_t	Intercom6_OA1_Power_Failure : 1;	//byte31
            uint8_t	Intercom6_OA1_Timeout : 1;
            uint8_t	Intercom6_OA1_Not_Found : 1;
            uint8_t	bit251 : 1;
            uint8_t	Intercom7_OA1_Network_Failure : 1;
            uint8_t	Intercom7_OA1_Power_Failure : 1;
            uint8_t	Intercom7_OA1_Timeout : 1;
            uint8_t	Intercom7_OA1_Not_Found : 1;

        } bits;
        time_t last_update;
    };
};

/**
 * SKA1_VH	0x41B
 * OA1	-
 * OA2	-
 * SKA2_VH	0x4DB
 * v1.07
*/
struct ska_vh_riom_ccu_mvb11_papis2 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint8_t bit0 : 1;			//byte0
            uint8_t Intercom8_OA1_Network_Failure : 1;
            uint8_t Intercom8_OA1_Power_Failure : 1;
            uint8_t Intercom8_OA1_Timeout : 1;
            uint8_t Intercom8_OA1_Not_Found : 1;
            uint8_t bit5 : 1;
            uint8_t Intercom1_OA2_Network_Failure : 1;
            uint8_t Intercom1_OA2_Power_Failure : 1;
            uint8_t Intercom1_OA2_Timeout : 1; 		//byte 1
            uint8_t Intercom1_OA2_Not_Found : 1;
            uint8_t bit10 : 1;
            uint8_t Intercom2_OA2_Network_Failure : 1;
            uint8_t Intercom2_OA2_Power_Failure : 1;
            uint8_t Intercom2_OA2_Timeout : 1;
            uint8_t Intercom2_OA2_Not_Found : 1;
            uint8_t bit15 : 1;
            uint8_t Intercom3_OA2_Network_Failure : 1; //byte2
            uint8_t Intercom3_OA2_Power_Failure : 1;
            uint8_t Intercom3_OA2_Timeout : 1;
            uint8_t Intercom3_OA2_Not_Found : 1;
            uint8_t bit20 : 1;
            uint8_t Intercom4_OA2_Network_Failure : 1;
            uint8_t Intercom4_OA2_Power_Failure : 1;
            uint8_t Intercom4_OA2_Timeout : 1;
            uint8_t Intercom4_OA2_Not_Found : 1; 	//byte3
            uint8_t bit25 : 1;
            uint8_t Intercom5_OA2_Network_Failure : 1;
            uint8_t Intercom5_OA2_Power_Failure : 1;
            uint8_t Intercom5_OA2_Timeout : 1;
            uint8_t Intercom5_OA2_Not_Found : 1;
            uint8_t bit30 : 1;
            uint8_t Intercom6_OA2_Network_Failure : 1;
            uint8_t Intercom6_OA2_Power_Failure : 1;	//byte4
            uint8_t Intercom6_OA2_Timeout : 1;
            uint8_t Intercom6_OA2_Not_Found : 1;
            uint8_t bit35 : 1;
            uint8_t Intercom7_OA2_Network_Failure : 1;
            uint8_t Intercom7_OA2_Power_Failure : 1;
            uint8_t Intercom7_OA2_Timeout : 1;
            uint8_t Intercom7_OA2_Not_Found : 1;
            uint8_t bit40 : 1;						//byte 5
            uint8_t Intercom8_OA2_Network_Failure : 1;
            uint8_t Intercom8_OA2_Power_Failure : 1;
            uint8_t Intercom8_OA2_Timeout : 1;
            uint8_t Intercom8_OA2_Not_Found : 1;
            uint8_t bit45 : 1;
            uint8_t Intercom1_SKA2_Network_Failure : 1;
            uint8_t Intercom1_SKA2_Power_Failure : 1;
            uint8_t Intercom1_SKA2_Timeout : 1;		//byte 6
            uint8_t Intercom1_SKA2_Not_Found : 1;
            uint8_t bit50 : 1;
            uint8_t Intercom2_SKA2_Network_Failure : 1;
            uint8_t Intercom2_SKA2_Power_Failure : 1;
            uint8_t Intercom2_SKA2_Timeout : 1;
            uint8_t Intercom2_SKA2_Not_Found : 1;
            uint8_t bit55 : 1;
            uint8_t Intercom3_SKA2_Network_Failure : 1;	//byte 7
            uint8_t Intercom3_SKA2_Power_Failure : 1;
            uint8_t Intercom3_SKA2_Timeout : 1;
            uint8_t Intercom3_SKA2_Not_Found : 1;
            uint8_t bit60 : 1;
            uint8_t bit61 : 1;
            uint8_t bit62 : 1;
            uint8_t bit63 : 1;
            uint8_t Intercom4_SKA2_Network_Failure : 1;	//byte 8
            uint8_t Intercom4_SKA2_Power_Failure : 1;
            uint8_t Intercom4_SKA2_Timeout : 1;
            uint8_t Intercom4_SKA2_Not_Found : 1;
            uint8_t bit68 : 1;
            uint8_t Intercom5_SKA2_Network_Failure : 1;
            uint8_t Intercom5_SKA2_Power_Failure : 1;
            uint8_t Intercom5_SKA2_Timeout : 1;
            uint8_t Intercom5_SKA2_Not_Found : 1;	//byte 9
            uint8_t bit73 : 1;
            uint8_t Intercom6_SKA2_Network_Failure : 1;
            uint8_t Intercom6_SKA2_Power_Failure : 1;
            uint8_t Intercom6_SKA2_Timeout : 1;
            uint8_t Intercom6_SKA2_Not_Found : 1;
            uint8_t bit78 : 1;
            uint8_t Intercom7_SKA2_Network_Failure : 1;
            uint8_t Intercom7_SKA2_Power_Failure : 1;	//byte10
            uint8_t Intercom7_SKA2_Timeout : 1;
            uint8_t Intercom7_SKA2_Not_Found : 1;
            uint8_t bit83 : 1;
            uint8_t Intercom8_SKA2_Network_Failure : 1;
            uint8_t Intercom8_SKA2_Power_Failure : 1;
            uint8_t Intercom8_SKA2_Timeout : 1;
            uint8_t Intercom8_SKA2_Not_Found : 1;
            uint8_t bit88 : 1;				//byte 11
            uint8_t Intercom9_SKA2_Network_Failure : 1;
            uint8_t Intercom9_SKA2_Power_Failure : 1;
            uint8_t Intercom9_SKA2_Timeout : 1;
            uint8_t Intercom9_SKA2_Not_Found : 1;
            uint8_t bit93 : 1;
            uint8_t SIntercom_1_SKA1 : 1;
            uint8_t SIntercom_2_SKA1 : 1;
            uint8_t SIntercom_3_SKA1 : 1;	//byte 12
            uint8_t SIntercom_4_SKA1 : 1;
            uint8_t SIntercom_5_SKA1 : 1;
            uint8_t SIntercom_6_SKA1 : 1;
            uint8_t SIntercom_7_SKA1 : 1;
            uint8_t SIntercom_8_SKA1 : 1;
            uint8_t SIntercom_9_SKA1 : 1;
            uint8_t bit103 : 1;
            uint8_t SIntercom_1_OA1 : 1;	//byte13
            uint8_t SIntercom_2_OA1 : 1;
            uint8_t SIntercom_3_OA1 : 1;
            uint8_t SIntercom_4_OA1 : 1;
            uint8_t SIntercom_5_OA1 : 1;
            uint8_t SIntercom_6_OA1 : 1;
            uint8_t SIntercom_7_OA1 : 1;
            uint8_t SIntercom_8_OA1 : 1;
            uint8_t SIntercom_1_OA2 : 1;	//byte14
            uint8_t SIntercom_2_OA2 : 1;
            uint8_t SIntercom_3_OA2 : 1;
            uint8_t SIntercom_4_OA2 : 1;
            uint8_t SIntercom_5_OA2 : 1;
            uint8_t SIntercom_6_OA2 : 1;
            uint8_t SIntercom_7_OA2 : 1;
            uint8_t SIntercom_8_OA2 : 1;
            uint8_t bit120 : 1;				//byte15
            uint8_t SIntercom_1_SKA2 : 1;
            uint8_t SIntercom_2_SKA2 : 1;
            uint8_t SIntercom_3_SKA2 : 1;
            uint8_t SIntercom_4_SKA2 : 1;
            uint8_t SIntercom_5_SKA2 : 1;
            uint8_t SIntercom_6_SKA2 : 1;
            uint8_t SIntercom_7_SKA2 : 1;
            uint8_t SIntercom_8_SKA2 : 1;	//byte16
            uint8_t SIntercom_9_SKA2 : 1;
            uint8_t bit130 : 1;
            uint8_t CIntercom_1_SKA1 : 1;
            uint8_t CIntercom_2_SKA1 : 1;
            uint8_t CIntercom_3_SKA1 : 1;
            uint8_t CIntercom_4_SKA1 : 1;
            uint8_t CIntercom_5_SKA1 : 1;
            uint8_t CIntercom_6_SKA1 : 1;	//byte17
            uint8_t CIntercom_7_SKA1 : 1;
            uint8_t CIntercom_8_SKA1 : 1;
            uint8_t CIntercom_9_SKA1 : 1;
            uint8_t bit140 : 1;
            uint8_t CIntercom_1_OA1 : 1;
            uint8_t CIntercom_2_OA1 : 1;
            uint8_t CIntercom_3_OA1 : 1;
            uint8_t CIntercom_4_OA1 : 1;	//byte18
            uint8_t CIntercom_5_OA1 : 1;
            uint8_t CIntercom_6_OA1 : 1;
            uint8_t CIntercom_7_OA1 : 1;
            uint8_t CIntercom_8_OA1 : 1;
            uint8_t CIntercom_1_OA2 : 1;
            uint8_t CIntercom_2_OA2 : 1;
            uint8_t CIntercom_3_OA2 : 1;
            uint8_t CIntercom_4_OA2 : 1;	//byte19
            uint8_t CIntercom_5_OA2 : 1;
            uint8_t CIntercom_6_OA2 : 1;
            uint8_t CIntercom_7_OA2 : 1;
            uint8_t CIntercom_8_OA2 : 1;
            uint8_t CIntercom_1_SKA2 : 1;
            uint8_t CIntercom_2_SKA2 : 1;
            uint8_t CIntercom_3_SKA2 : 1;
            uint8_t CIntercom_4_SKA2 : 1;	//byte20
            uint8_t CIntercom_5_SKA2 : 1;
            uint8_t CIntercom_6_SKA2 : 1;
            uint8_t CIntercom_7_SKA2 : 1;
            uint8_t CIntercom_8_SKA2 : 1;
            uint8_t CIntercom_9_SKA2 : 1;
            uint8_t bit166 : 1;
            uint8_t Amplifier1_SKA1_Network_Failure : 1;
            uint8_t Amplifier1_SKA1_Power_Failure : 1;	//byte21
            uint8_t Amplifier1_SKA1_Not_Found : 1;
            uint8_t Amplifier1_SKA1_Busy : 1;
            uint8_t Amplifier1_SKA1_Timeout : 1;
            uint8_t Amplifier1_SKA1_Call1_Not_Reg : 1;
            uint8_t Amplifier1_SKA1_Call2_Not_Reg : 1;
            uint8_t bit174 : 1;
            uint8_t Amplifier1_OA1_Network_Failure : 1;
            uint8_t Amplifier1_OA1_Power_Failure : 1;	//byte22
            uint8_t Amplifier1_OA1_Not_Found : 1;
            uint8_t Amplifier1_OA1_Busy : 1;
            uint8_t Amplifier1_OA1_Timeout : 1;
            uint8_t Amplifier1_OA1_Call1_Not_Reg : 1;
            uint8_t Amplifier1_OA1_Call2_Not_Reg : 1;
            uint8_t bit182 : 1;
            uint8_t Amplifier1_OA2_Network_Failure : 1;
            uint8_t Amplifier1_OA2_Power_Failure : 1;	//byte23
            uint8_t Amplifier1_OA2_Not_Found : 1;
            uint8_t Amplifier1_OA2_Busy : 1;
            uint8_t Amplifier1_OA2_Timeout : 1;
            uint8_t Amplifier1_OA2_Call1_Not_Reg : 1;
            uint8_t Amplifier1_OA2_Call2_Not_Reg : 1;
            uint8_t bit190 : 1;
            uint8_t bit191 : 1;
            uint8_t Amplifier1_SKA2_Network_Failure : 1;	//byte24
            uint8_t Amplifier1_SKA2_Power_Failure : 1;
            uint8_t Amplifier1_SKA2_Not_Found : 1;
            uint8_t Amplifier1_SKA2_Busy : 1;
            uint8_t Amplifier1_SKA2_Timeout : 1;
            uint8_t Amplifier1_SKA2_Call1_Not_Reg : 1;
            uint8_t Amplifier1_SKA2_Call2_Not_Reg : 1;
            uint8_t bit199 : 1;
            uint8_t NoiseMic_SKA1_Power_Failure : 1;	//byte25
            uint8_t bit201 : 1;
            uint8_t NoiseMic_OA1_Power_Failure : 1;
            uint8_t bit203 : 1;
            uint8_t NoiseMic_OA2_Power_Failure : 1;
            uint8_t bit205 : 1;
            uint8_t NoiseMic_SKA2_Power_Failure : 1;
            uint8_t bit207 : 1;
            uint8_t PerrCCTV_SKA1_Memory_Full : 1;	//byte26
            uint8_t PerrCCTV_SKA1_Reg_Error : 1;
            uint8_t PerrCCTV_SKA1_Standby_Error : 1;
            uint8_t PerrCCTV_SKA1_Alarm_Error : 1;
            uint8_t PerrCCTV_SKA1_Time_Error : 1;
            uint8_t bit213 : 1;
            uint8_t PerrCCTV_SKA2_Memory_Full : 1;
            uint8_t PerrCCTV_SKA2_Reg_Error : 1;
            uint8_t PerrCCTV_SKA2_Standby_Error : 1;	//byte27
            uint8_t PerrCCTV_SKA2_Alarm_Error : 1;
            uint8_t PerrCCTV_SKA2_Time_Error : 1;
            uint8_t bit219 : 1;
            uint8_t PerrSwnNecMic_SKA1_Network_Failure : 1;
            uint8_t PerrSwnNecMic_SKA1_Power_Failure : 1;
            uint8_t bit222 : 1;
            uint8_t PerrSwnNecMic_SKA2_Network_Failure : 1;
            uint8_t	PerrSwnNecMic_SKA2_Power_Failure : 1; //byte28
            uint8_t	bit225 : 1;
            uint8_t	bit226 : 1;
            uint8_t	bit227 : 1;
            uint8_t	bit228 : 1;
            uint8_t	bit229 : 1;
            uint8_t	bit230 : 1;
            uint8_t	bit231 : 1;
            uint8_t reserved29;
            uint8_t reserved30;
            uint8_t reserved31;

        } bits;
        time_t last_update;
    };
};

/**
 * SKA1_VH	0x41C
 * OA1	-
 * OA2	-
 * SKA2_VH	0x4DC,
 * v1.07
*/

struct ska_vh_riom_ccu_mvb12_papis3 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint32_t GPS_longtitude_master; 	//byte0
            uint32_t GPS_latitude_master;		//byte4
            uint32_t Timestamp_time;		//byte8
            uint16_t Timestamp_date;		//byte 12
            uint8_t reserved14;
            uint8_t reserved15;
            uint8_t ServiceID_Byte1; //byte 16
            uint8_t ServiceID_Byte2;
            uint8_t ServiceID_Byte3;
            uint8_t ServiceID_Byte4;
            uint8_t ServiceID_Byte5;
            uint8_t ServiceID_Byte6;
            uint8_t ServiceID_Byte7;
            uint8_t ServiceID_Byte8;
            uint8_t reserved24;
            uint8_t reserved25;
            uint8_t reserved26;
            uint8_t reserved27;
            uint8_t reserved28;
            uint8_t reserved29;
            uint8_t reserved30;
            uint8_t reserved31;

        } bits;
        time_t last_update;
    };
};

/**
 * SKA1_VH	0x41D
 * OA1	-
 * OA2	-
 * SKA2_VH	0x4DD
 * v1.07
*/
struct ska_vh_riom_ccu_mvb13_hvac1 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint8_t Software_Version_Major ;  //byte 0
            uint8_t Software_Version_Minor ;
            int8_t Outside_Air_Temp ;
            int8_t Ice_Temp ;
            int8_t Supply_Air_Temp ;
            int8_t Inside_Air_Temp ;
            uint8_t Set_Point_Temp ;
            uint8_t Evap_Fans_Speed ; //byte 7
            uint8_t reserved_8 ;
            uint8_t reserved_9 ;
            uint8_t Smoke_Detector : 1;  //byte10
            uint8_t HVAC_On : 1;
            uint8_t Auto_Mode : 1;
            uint8_t Manual_Mode : 1;
            uint8_t Ventilation_Mode : 1;
            uint8_t Ventilation_Fan_Speed_Bit1 : 1;
            uint8_t Ventilation_Fan_Speed_Bit2 : 1;
            uint8_t Ventilation_Fan_Speed_Bit3 : 1;
            uint8_t Reduce_Mode : 1; //byte 11
            uint8_t Emergency_Mode : 1;
            uint8_t Self_Test_Mode : 1;
            uint8_t Standby_Mode : 1;
            uint8_t Fire_Mode : 1;
            uint8_t Inside_Fire_On : 1;
            uint8_t bit94 : 1;
            uint8_t Full_Cooling : 1;
            uint8_t bit96 : 1; //byte 12
            uint8_t Full_Heating : 1;
            uint8_t Off_Enable : 1;
            uint8_t Self_Test_Not_Ok : 1;
            uint8_t Self_Test_Ok : 1;
            uint8_t PC_Software_Connected : 1;
            uint8_t bit102 : 1;
            uint8_t bit103 : 1;
            uint8_t Heat1_On : 1; //byte13
            uint8_t Heat2_On : 1;
            uint8_t bit106 : 1;
            uint8_t bit107 : 1;
            uint8_t Compressor1_On : 1;
            uint8_t bit109 : 1;
            uint8_t Emerg_Inv_On : 1;
            uint8_t Evap_Sel1_On : 1;
            uint8_t reserved14 ;
            uint8_t reserved15 ;
            uint8_t Fresh_Air_Damp_Pos ; //byte 16
            uint8_t Minor_Fault : 1; //byte17
            uint8_t Major_Fault : 1;
            uint8_t Low_Press1_Fault : 1;
            uint8_t bit139 : 1;
            uint8_t High_Press1_Fault : 1;
            uint8_t bit141 : 1;
            uint8_t Cond_Fan1_Therm_Fault : 1;
            uint8_t bit143 : 1;
            uint8_t First_Lev_Therm_75_Fault : 1; //byte18
            uint8_t First_Lev_Therm_85_Fault : 1;
            uint8_t Evap_Fan1_Fault : 1;
            uint8_t bit147 : 1;
            uint8_t bit148 : 1;
            uint8_t Three_Phase_Fault : 1;
            uint8_t Emerg_Inv_Input_Fault : 1;
            uint8_t Emerg_Inv_Output_Fault : 1;
            uint8_t Third_Level_Therm_Fault : 1; //byte19
            uint8_t Evap_Therm1_Fault : 1;
            uint8_t bit154 : 1;
            uint8_t Smoke_Detector_Fault : 1;
            uint8_t Comp1_Therm_Fault : 1;
            uint8_t bit157 : 1;
            uint8_t bit158 : 1;
            uint8_t bit159 : 1;
            uint8_t bit160 : 1; //byte20
            uint8_t bit161 : 1;
            uint8_t Cont_Evap_Solenoid1_Fault : 1;
            uint8_t bit163 : 1;
            uint8_t bit164 : 1;
            uint8_t bit165 : 1;
            uint8_t Cont_Bypass_Solenoid1_Fault : 1;
            uint8_t Cont_Heater1_Fault : 1;
            uint8_t Cont_Heater2_Fault : 1; //byte21
            uint8_t Cont_Evap_Fault : 1;
            uint8_t Cont_Cond_Fault : 1;
            uint8_t bit171 : 1;
            uint8_t bit172 : 1;
            uint8_t Cont_Emergency_Fault : 1;
            uint8_t Comp1_Contc_Fault : 1;
            uint8_t bit175 : 1;
            uint8_t Icing_Detect_Fault : 1; //byte22
            uint8_t Supply_Cooling_Detect_Fault : 1;
            uint8_t Supply_Heating_Detect_Fault : 1;
            uint8_t Cooling_Fault : 1;
            uint8_t Heating_Fault : 1;
            uint8_t bit181 : 1;
            uint8_t bit182 : 1;
            uint8_t bit183 : 1;
            uint8_t reserved23 ;
            uint8_t reserved24 ;
            uint8_t reserved25 ;
            uint8_t reserved26 ;
            uint8_t reserved27 ;
            uint8_t reserved28 ;
            uint8_t reserved29 ;
            uint8_t reserved30 ;
            uint8_t reserved31 ;
        } bits;
        time_t last_update;
    };
};

/**
 * SKA1_VH	0x41E
 * OA1	-
 * OA2	-
 * SKA2_VH	0x4DE
 * v1.07
*/
struct ska_vh_riom_ccu_mvb14_hvac2 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];
        struct {
            uint8_t Software_Version_Major ;//byte0
            uint8_t Software_Version_Minor ;
            int8_t Outside_Air_Temp ;
            int8_t Ice_Temp ;
            int8_t Supply_Air_Temp ;
            int8_t Inside_Air_Temp ;
            uint8_t Set_Point_Temp ;
            uint8_t Evap_Fans_Speed ;
            uint16_t CO2_Sensor ; //byte8
            uint8_t Smoke_Detector : 1; //byte10
            uint8_t HVAC_On : 1;
            uint8_t Auto_Mode : 1;
            uint8_t bit83 : 1;
            uint8_t bit84 : 1;
            uint8_t bit85 : 1;
            uint8_t bit86 : 1;
            uint8_t bit87 : 1;
            uint8_t Reduce_Mode : 1; //byte11
            uint8_t Emergency_Mode : 1;
            uint8_t Self_Test_Mode : 1;
            uint8_t bit91 : 1;
            uint8_t Fire_Mode : 1;
            uint8_t Inside_Fire_On : 1;
            uint8_t Half_Cooling : 1;
            uint8_t Full_Cooling : 1;
            uint8_t Half_Heating : 1; //byte 12
            uint8_t Full_Heating : 1;
            uint8_t Off_Enable : 1;
            uint8_t Self_Test_Not_Ok : 1;
            uint8_t Self_Test_Ok : 1;
            uint8_t PC_Software_Connected : 1;
            uint8_t Cond_Fans_Low : 1;
            uint8_t Cond_Fans_High : 1;
            uint8_t Heat1_On : 1; //byte 13
            uint8_t Heat2_On : 1;
            uint8_t Floor_Heat1_On : 1;
            uint8_t Floor_Heat2_On : 1;
            uint8_t Compressor1_On : 1;
            uint8_t Compressor2_On : 1;
            uint8_t Emerg_Inv_On : 1;
            uint8_t Evap_Sel1_On : 1;
            uint8_t Evap_Sel2_On : 1; //byte14
            uint8_t bit113 : 1;
            uint8_t bit114 : 1;
            uint8_t bit115 : 1;
            uint8_t bit116 : 1;
            uint8_t bit117 : 1;
            uint8_t bit118 : 1;
            uint8_t bit119 : 1;
            uint8_t Emerg_Shut_Air_Damp_Pos ;
            uint8_t Fresh_Air_Damp_Pos ; //byte16
            uint8_t Minor_Fault : 1; //byte17
            uint8_t Major_Fault : 1;
            uint8_t Low_Press1_Fault : 1;
            uint8_t Low_Press2_Fault : 1;
            uint8_t High_Press1_Fault : 1;
            uint8_t High_Press2_Fault : 1;
            uint8_t Cond_Fan1_Therm_Fault : 1;
            uint8_t First_Lev_Therm_7585_Fault : 1;
            uint8_t bit144 : 1; //byte 18
            uint8_t bit145 : 1;
            uint8_t Evap_Fan1_Fault : 1;
            uint8_t Evap_Fan2_Fault : 1;
            uint8_t Evap_Fan12_Fault : 1;
            uint8_t Three_Phase_Fault : 1;
            uint8_t Emerg_Inv_Input_Fault : 1;
            uint8_t Emerg_Inv_Output_Fault : 1;
            uint8_t Third_Level_Therm_Fault : 1;
            uint8_t Evap_Therm1_Fault : 1;
            uint8_t Evap_Therm2_Fault : 1;
            uint8_t Smoke_Detector_Fault : 1;
            uint8_t Comp1_Therm_Fault : 1;
            uint8_t Comp1_Overload_Fault : 1;
            uint8_t Comp2_Therm_Fault : 1;
            uint8_t Comp2_Overload_Fault : 1;
            uint8_t Evap_Inv_Fault : 1; 	//byte20
            uint8_t Cond_Fan2_Therm_Fault : 1;
            uint8_t Cont_Evap_Solenoid1_Fault : 1;
            uint8_t Cont_Evap_Solenoid2_Fault : 1;
            uint8_t Cont_Cap_Solenoid1_Fault : 1;
            uint8_t Cont_Cap_Solenoid2_Fault : 1;
            uint8_t bit166 : 1;
            uint8_t Cont_Heater1_Fault : 1;
            uint8_t Cont_Heater2_Fault : 1; //byte21
            uint8_t Cont_Evap_Fault : 1;
            uint8_t Cont_Cond_Fault : 1;
            uint8_t Cont_Cond_Fan_Low_Fault : 1;
            uint8_t Cont_Cond_Fan_High_Fault : 1;
            uint8_t Cont_Emergency_Fault : 1;
            uint8_t Comp1_Contc_Fault : 1;
            uint8_t Comp2_Contc_Fault : 1;
            uint8_t Icing_Detect_Fault : 1;  //byte22
            uint8_t Supply_Cooling_Detect_Fault : 1;
            uint8_t Supply_Heating_Detect_Fault : 1;
            uint8_t Cooling_Fault : 1;
            uint8_t Heating_Fault : 1;
            uint8_t bit180 : 1;
            uint8_t bit181 : 1;
            uint8_t bit182 : 1;
            uint8_t reserved23;
            uint8_t reserved24;
            uint8_t reserved25;
            uint8_t reserved26;
            uint8_t reserved27;
            uint8_t reserved28;
            uint8_t reserved29;
            uint8_t reserved30;
            uint8_t reserved31;
        } bits;
        time_t last_update;
    };
};

/**
 * SKA1_VH	0x41F
 * OA1	-
 * OA2	-
 * SKA2_VH	0x4DF
 * v1.07
*/
struct ska_vh_riom_ccu_mvb15_hvac3 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];
        struct {
            uint8_t Software_Version_Major ; //byte0
            uint8_t Software_Version_Minor ; //byte1
            int8_t Outside_Air_Temp ;
            int8_t Ice_Temp ;
            int8_t Supply_Air_Temp ;
            int8_t Inside_Air_Temp ;
            uint8_t Set_Point_Temp ;
            uint8_t Evap_Fans_Speed ;
            uint16_t CO2_Sensor ; //byte8
            uint8_t Smoke_Detector : 1; //byte10
            uint8_t HVAC_On : 1;
            uint8_t Auto_Mode : 1;
            uint8_t bit83 : 1;
            uint8_t bit84 : 1;
            uint8_t bit85 : 1;
            uint8_t bit86 : 1;
            uint8_t bit87 : 1;
            uint8_t Reduce_Mode : 1; //byte11
            uint8_t Emergency_Mode : 1;
            uint8_t Self_Test_Mode : 1;
            uint8_t Spare : 1;
            uint8_t Fire_Mode : 1;
            uint8_t Inside_Fire_On : 1;
            uint8_t Half_Cooling : 1;
            uint8_t Full_Cooling : 1;
            uint8_t Half_Heating : 1; //byte12
            uint8_t Full_Heating : 1;
            uint8_t Off_Enable : 1;
            uint8_t Self_Test_Not_Ok : 1;
            uint8_t Self_Test_Ok : 1;
            uint8_t PC_Software_Connected : 1;
            uint8_t Cond_Fans_Low : 1;
            uint8_t Cond_Fans_High : 1;
            uint8_t Heat1_On : 1; //byte13
            uint8_t Heat2_On : 1;
            uint8_t Floor_Heat1_On : 1;
            uint8_t Floor_Heat2_On : 1;
            uint8_t Compressor1_On : 1;
            uint8_t Compressor2_On : 1;
            uint8_t Emerg_Inv_On : 1;
            uint8_t Evap_Sel1_On : 1;
            uint8_t Evap_Sel2_On : 1; //byte14
            uint8_t bit97 : 1;
            uint8_t bit98 : 1;
            uint8_t bit99 : 1;
            uint8_t bit100 : 1;
            uint8_t bit101 : 1;
            uint8_t bit102 : 1;
            uint8_t bit103 : 1;
            uint8_t Emerg_Shut_Air_Damp_Pos ; //byte15
            uint8_t Fresh_Air_Damp_Pos ; //byte16
            uint8_t Minor_Fault : 1; //byte 17
            uint8_t Major_Fault : 1;
            uint8_t Low_Press1_Fault : 1;
            uint8_t Low_Press2_Fault : 1;
            uint8_t High_Press1_Fault : 1;
            uint8_t High_Press2_Fault : 1;
            uint8_t Cond_Fan1_Therm_Fault : 1;
            uint8_t First_Lev_Therm_7585_Fault : 1;
            uint8_t bit144 : 1;  //byte18
            uint8_t bit145 : 1;
            uint8_t Evap_Fan1_Fault : 1;
            uint8_t Evap_Fan2_Fault : 1;
            uint8_t Evap_Fan12_Fault : 1;
            uint8_t Three_Phase_Fault : 1;
            uint8_t Emerg_Inv_Input_Fault : 1;
            uint8_t Emerg_Inv_Output_Fault : 1;
            uint8_t Third_Level_Therm_Fault : 1; //byte19
            uint8_t Evap_Therm1_Fault : 1;
            uint8_t Evap_Therm2_Fault : 1;
            uint8_t Smoke_Detector_Fault : 1;
            uint8_t Comp1_Therm_Fault : 1;
            uint8_t Comp1_Overload_Fault : 1;
            uint8_t Comp2_Therm_Fault : 1;
            uint8_t Comp2_Overload_Fault : 1;
            uint8_t Evap_Inv_Fault : 1; //byte20
            uint8_t Cond_Fan2_Therm_Fault : 1;
            uint8_t Cont_Evap_Solenoid1_Fault : 1;
            uint8_t Cont_Evap_Solenoid2_Fault : 1;
            uint8_t Cont_Cap_Solenoid1_Fault : 1;
            uint8_t Cont_Cap_Solenoid2_Fault : 1;
            uint8_t bit166 : 1;
            uint8_t Cont_Heater1_Fault : 1;
            uint8_t Cont_Heater2_Fault : 1; //byte21
            uint8_t Cont_Evap_Fault : 1;
            uint8_t Cont_Cond_Fault : 1;
            uint8_t Cont_Cond_Fan_Low_Fault : 1;
            uint8_t Cont_Cond_Fan_High_Fault : 1;
            uint8_t Cont_Emergency_Fault : 1;
            uint8_t Comp1_Contc_Fault : 1;
            uint8_t Comp2_Contc_Fault : 1;
            uint8_t Icing_Detect_Fault : 1;  //byte22
            uint8_t Supply_Cooling_Detect_Fault : 1;
            uint8_t Supply_Heating_Detect_Fault : 1;
            uint8_t Cooling_Fault : 1;
            uint8_t Heating_Fault : 1;
            uint8_t bit181 : 1;
            uint8_t bit182 : 1;
            uint8_t bit183 : 1;
            uint8_t reserved23 : 1;
            uint8_t reserved24 : 1;
            uint8_t reserved25 : 1;
            uint8_t reserved26 : 1;
            uint8_t reserved27 : 1;
            uint8_t reserved28 : 1;
            uint8_t reserved29 : 1;
            uint8_t reserved30 : 1;
            uint8_t reserved31 : 1;
        } bits;
        time_t last_update;
    };
};


/**
 * OA1_VH_M	0x441
 * OA1_VH_R	0x442
 * OA2_VH_M	0x481
 * OA2_VH_R	0x482
 * v1.09
*/

struct oa_vh_riom_ccu_mvb_status {
    union {
        uint8_t bytes[IO_RAW_NBYTES_16];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_16)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_16)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_16)];

        struct {
            uint16_t lifesign;//byte 0
            uint8_t DIO01_Module_Error : 1;//byte 2
            uint8_t DIO01_Output_Overcurrent : 1;
            uint8_t DIO01_Heartbeat_error : 1;
            uint8_t DIO01_Group_1_Voltage_error : 1;
            uint8_t DIO01_Group_2_Voltage_error : 1;
            uint8_t DIO01_Board_Temperature_error : 1;
            uint8_t bit22 : 1;
            uint8_t bit23 : 1;
            uint8_t DIO02_Module_Error : 1;//byte 3
            uint8_t DIO02_Output_Overcurrent : 1;
            uint8_t DIO02_Heartbeat_error : 1;
            uint8_t DIO02_Group_1_Voltage_error : 1;
            uint8_t DIO02_Group_2_Voltage_error : 1;
            uint8_t DIO02_Board_Temperature_error : 1;
            uint8_t bit30 : 1;
            uint8_t bit31 : 1;
            uint8_t DIO03_Module_Error : 1;//byte 4
            uint8_t DIO03_Output_Overcurrent : 1;
            uint8_t DIO03_Heartbeat_error : 1;
            uint8_t DIO03_Group_1_Voltage_error : 1;
            uint8_t DIO03_Group_2_Voltage_error : 1;
            uint8_t DIO03_Board_Temperature_error : 1;
            uint8_t bit38 : 1;
            uint8_t bit39 : 1;
            uint8_t DIO04_Module_Error : 1;//byte 5
            uint8_t DIO04_Output_Overcurrent : 1;
            uint8_t DIO04_Heartbeat_error : 1;
            uint8_t DIO04_Group_1_Voltage_error : 1;
            uint8_t DIO04_Group_2_Voltage_error : 1;
            uint8_t DIO04_Board_Temperature_error : 1;
            uint8_t bit46 : 1;
            uint8_t bit47 : 1;
            uint8_t DIO05_Module_Error : 1;//byte 6
            uint8_t DIO05_Output_Overcurrent : 1;
            uint8_t DIO05_Heartbeat_error : 1;
            uint8_t DIO05_Group_1_Voltage_error : 1;
            uint8_t DIO05_Group_2_Voltage_error : 1;
            uint8_t DIO05_Board_Temperature_error : 1;
            uint8_t bit54 : 1;
            uint8_t bit55 : 1;
            uint8_t DIO06_Module_Error : 1;//byte 7
            uint8_t DIO06_Output_Overcurrent : 1;
            uint8_t DIO06_Heartbeat_error : 1;
            uint8_t DIO06_Group_1_Voltage_error : 1;
            uint8_t DIO06_Group_2_Voltage_error : 1;
            uint8_t DIO06_Board_Temperature_error : 1;
            uint8_t bit62 : 1;
            uint8_t bit63 : 1;
            uint8_t DIO07_Module_Error : 1;//byte 8
            uint8_t DIO07_Output_Overcurrent : 1;
            uint8_t DIO07_Heartbeat_error : 1;
            uint8_t DIO07_Group_1_Voltage_error : 1;
            uint8_t DIO07_Group_2_Voltage_error : 1;
            uint8_t DIO07_Board_Temperature_error : 1;
            uint8_t bit70 : 1;
            uint8_t bit71 : 1;
            uint8_t AIM01_Module_Error : 1;//byte 9
            uint8_t AIM01_Heartbeat_error : 1;
            uint8_t bit74 : 1;
            uint8_t bit75 : 1;
            uint8_t bit76 : 1;
            uint8_t bit77 : 1;
            uint8_t bit78 : 1;
            uint8_t bit79 : 1;
            uint8_t PTI2037A_Module_Error : 1;//byte 10
            uint8_t PTI2037A_Heartbeat_error : 1;
            uint8_t PTI2037A_Channel_1_Status : 1;
            uint8_t PTI2037A_Channel_2_Status : 1;
            uint8_t PTI2037A_Channel_3_Status : 1;
            uint8_t PTI2037A_Channel_4_Status : 1;
            uint8_t PTI2037A_Channel_5_Status : 1;
            uint8_t PTI2037A_Channel_6_Status : 1;
            uint8_t reserved_11;//byte 11
            uint8_t reserved_12;//byte 12
            uint8_t R1_DCU_CANopen_Fault : 1; //byte13
            uint8_t R2_DCU_CANopen_Fault : 1;
            uint8_t R3_DCU_CANopen_Fault : 1;
            uint8_t R4_DCU_CANopen_Fault : 1;
            uint8_t L1_DCU_CANopen_Fault : 1;
            uint8_t L2_DCU_CANopen_Fault : 1;
            uint8_t L3_DCU_CANopen_Fault : 1;
            uint8_t L4_DCU_CANopen_Fault : 1;
            uint8_t HVAC1_CANopen_Fault : 1;  //byte14
            uint8_t HVAC2_CANopen_Fault : 1;
            uint8_t bit114 : 1;
            uint8_t bit115 : 1;
            uint8_t bit116 : 1;
            uint8_t bit117 : 1;
            uint8_t bit118 : 1;
            uint8_t bit119 : 1;
            uint8_t reserved_15;		//byte 15
        } bits;
        time_t last_update;
    };
};

/**
 * SKA1	-
 * OA1_VH	0x451
 * OA2_VH	0x491
 * SKA2	-
 * v1.09
*/


struct oa_vh_riom_ccu_mvb1_inputs {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint8_t MANUAL_POWER_SUPPLY_PRIVILEGED_LOAD_Lp : 1; //byte 0
            uint8_t CONTACTOR_PRIVILEGE_LOAD_Lp : 1;
            uint8_t SAFETY_BATTERY_CASE : 1;
            uint8_t SL_APS_START : 1;
            uint8_t CONVERTER_APS_OK : 1;
            uint8_t CONVERTER_MV_OK : 1;
            uint8_t CONVERTER_HV_PRESENCE : 1;
            uint8_t BATTERY_CHARGER_OK : 1;
            uint8_t PLANT_3_0_CB_PROTECTION : 1; //byte 1
            uint8_t CONTACTORS_SOCKETS_WORKSHOP_LEFT_INSERTED : 1;
            uint8_t CONTACTORS_SOCKETS_WORKSHOP_RIGHT_INSERTED : 1;
            uint8_t CONTACTOR_DEGRADE_MODE_MV_OA_CARS : 1;
            uint8_t READY_VCB : 1;
            uint8_t VCB_CLOSE : 1;
            uint8_t OPEN_VCB_FOR_HIGH_CURRENT : 1;
            uint8_t FAST_OPEN_VCB : 1;
            uint8_t CONTACTOR_2_1_NORMAL_LOAD_Ln : 1; //byte 2
            uint8_t DEVICE_ID_DI_0 : 1;
            uint8_t DEVICE_ID_DI_1 : 1;
            uint8_t DEVICE_ID_DI_2 : 1;
            uint8_t DEVICE_ID_DI_3 : 1;
            uint8_t DEVICE_ID_DI_4 : 1;
            uint8_t DEVICE_ID_DI_5 : 1;
            uint8_t CABINET_TEST_HW_OK_HEALT_RIOM_2 : 1;
            uint8_t EARTHING_SWITCH_SERVICE_POSITION : 1; //byte 3
            uint8_t EARTHING_SWITCH_EARTH_POSITION : 1;
            uint8_t EARTHING_PANEL_YELLOW_KEY_EXTRACTED : 1;
            uint8_t HV_DISCONNECTOR_MOVING_OR_CLOSE_D : 1;
            uint8_t HV_DISCONNECTOR_CLOSED_E : 1;
            uint8_t HV_DISCONNECTOR_MOVING_OR_OPEN_A : 1;
            uint8_t HV_DISCONNECTOR_OPENED_B : 1;
            uint8_t PLANT_3_1_CB_PROTECTION : 1;
            uint8_t PANTOGRAPH_AIR_PRESSURE_COMPRESSOR : 1; //byte 4
            uint8_t PANTOGRAPH_COMMAND_MOTOR_COMPRESSOR_INPUT : 1;
            uint8_t PLANT_3_2_CB_PROTECTION : 1;
            uint8_t FAST_OPEN_ADD : 1;
            uint8_t PRESSURE_PS1_SAFEGUARD_ADD : 1;
            uint8_t PANTOGRAPH_INSULATED : 1;
            uint8_t PRESSURE_GOVERNOR_PANTOGRAPH : 1;
            uint8_t POSITION_1_PANTOGRAPH_ENABLED : 1;
            uint8_t POSITION_0_PANTOGRAPH_ISOLATED : 1; //byte 5
            uint8_t bit41 : 1;
            uint8_t bit42 : 1;
            uint8_t bit43 : 1;
            uint8_t bit44 : 1;
            uint8_t bit45 : 1;
            uint8_t bit46 : 1;
            uint8_t bit47 : 1;
            uint8_t TRAFO_NOT_FULL_SPEED : 1; //byte 6
            uint8_t TRAFO_FULL_SPEED : 1;
            uint8_t TRAFO_NOT_LOW_SPEED : 1;
            uint8_t TRAFO_LOW_SPEED : 1;
            uint8_t PLANT_3_7_CB_PROTECTION : 1;
            uint8_t TRAFO_PRESSURE_RELIEF_DEVICE_TRIP_1 : 1;
            uint8_t TRAFO_PRESSURE_RELIEF_DEVICE_TRIP_2 : 1;
            uint8_t TRAFO_OIL_FLOW_ALARM : 1;
            uint8_t TRAFO_COOLANT_LEVEL_ALARM : 1; //byte 7
            uint8_t TRAFO_OVER_TEMP_OTP1_ALARM : 1;
            uint8_t TRAFO_OVER_TEMP_OTP2_ALARM : 1;
            uint8_t VENTILATION_TRANSFORMER_CB_PROTECTION : 1;
            uint8_t HVAC_1_FLOOR_HEATER_1_START : 1;
            uint8_t HVAC_1_FLOOR_HEATER_2_START : 1;
            uint8_t HVAC_1_CB_PROTECTION : 1;
            uint8_t HVAC_2_FLOOR_HEATER_1_START : 1;
            uint8_t HVAC_2_FLOOR_HEATER_2_START : 1; //byte 8
            uint8_t bit65 : 1;
            uint8_t bit66 : 1;
            uint8_t bit67 : 1;
            uint8_t bit68 : 1;
            uint8_t bit69 : 1;
            uint8_t bit70 : 1;
            uint8_t bit71 : 1;
            uint8_t HVAC_2_CB_PROTECTION : 1; //byte 9
            uint8_t HVAC_1_ON_INPUT : 1;
            uint8_t HVAC_2_ON_INPUT : 1;
            uint8_t THERMOSTAT_HEATING_LEFT_SIDE : 1;
            uint8_t CONTACTOR_HEATING_COMPARTMENT_LEFT_SIDE : 1;
            uint8_t HEATING_COMPARTMENT_LEFT_SIDE_CB_PROTECTION : 1;
            uint8_t THERMOSTAT_HEATING_RIGHT_SIDE : 1;
            uint8_t CONTACTOR_HEATING_COMPARTMENT_RIGHT_SIDE : 1;
            uint8_t HEATING_COMPARTMENT_RIGHT_SIDE_CB_PROTECTION : 1; //byte 10
            uint8_t PLANT_4_0_CB_PROTECTION : 1;
            uint8_t COMPRESSOR_ON : 1;
            uint8_t MOTOR_COMPRESSOR_CB_PROTECTION : 1;
            uint8_t PLANT_4_4_CB_PROTECTION : 1;
            uint8_t PRESSURE_GOVERNORS_COMPRESSOR_CONTROL_1 : 1;
            uint8_t PRESSURE_GOVERNORS_COMPRESSOR_CONTROL_2 : 1;
            uint8_t ISOLATION_COCKS_AIR_SUPPLY_UNIT : 1;
            uint8_t PRESSURE_GOVERNOR_BP_NO_EMERGENCY_BRAKE : 1; //byte 11
            uint8_t MOTOR_COMPRESSOR_CURRENT_MONITORING : 1;
            uint8_t bit90 : 1;
            uint8_t bit91 : 1;
            uint8_t bit92 : 1;
            uint8_t bit93 : 1;
            uint8_t bit94 : 1;
            uint8_t bit95 : 1;
            uint8_t PRESSURE_GOVERNOR_PB_RELEASED : 1; //byte 12
            uint8_t PRESSURE_GOVERNOR_R_CPRESS__APPL_BO1 : 1;
            uint8_t PRESSURE_GOVERNOR_R_CPRESS__APPL_BO2 : 1;
            uint8_t ISOLATION_COCKS_PNEUMATIC_BRAKE : 1;
            uint8_t ISOLATION_COCKS_DIRECT_BRAKE : 1;
            uint8_t ISOLATION_COCKS_INDIRECT_BRAKE : 1;
            uint8_t ISOLATION_COCKS_DIRECT_BRAKE_BO1 : 1;
            uint8_t ISOLATION_COCKS_DIRECT_BRAKE_BO2 : 1;
            uint8_t ISOLATION_COCKS_PB_ISOLATED : 1; //byte 13
            uint8_t ISOLATION_COCKS_RESERVE : 1;
            uint8_t EBCU_C_FCTOK : 1;
            uint8_t EBCU_SPEED_10_Km_H : 1;
            uint8_t PRESSURE_GOVERNORS_AIR_SUSPENSION_BO1 : 1;
            uint8_t PRESSURE_GOVERNORS_AIR_SUSPENSION_BO2 : 1;
            uint8_t LOW_MRP_PRESSUR_GOVERNOR : 1;
            uint8_t ZERO_SPEED : 1;
            uint8_t PLANT_4_5_CB_PROTECTION : 1; //byte 14
            uint8_t CABINET_RIOM_1_CB_PROTECTION : 1;
            uint8_t EMERGENCY_BRAKE_FROM_BCU : 1;
            uint8_t WSP_R_vGt5kmhDoor : 1;
            uint8_t BCU_ZERO_SPEED : 1;
            uint8_t RESERVE : 1;
            uint8_t FIRE_EXTINGUISHER_1_PRESENCE : 1;
            uint8_t FIRE_EXTINGUISHER_2_PRESENCE : 1;
            uint8_t RELAY_CONTROL_EMERGENCY_LOOP : 1; //byte 15
            uint8_t PLANT_4_7_CB_PROTECTION : 1;
            uint8_t HANDLE_1_PASSENGER_ALARM : 1;
            uint8_t HANDLE_3_PASSENGER_ALARM : 1;
            uint8_t HANDLE_5_PASSENGER_ALARM : 1;
            uint8_t HANDLE_7_PASSENGER_ALARM : 1;
            uint8_t HANDLE_2_PASSENGER_ALARM : 1;
            uint8_t HANDLE_4_PASSENGER_ALARM : 1;
            uint8_t HANDLE_6_PASSENGER_ALARM : 1; //byte 16
            uint8_t HANDLE_8_PASSENGER_ALARM : 1;
            uint8_t DOOR_1_FULLY_OPENED : 1;
            uint8_t DOOR_2_FULLY_OPENED : 1;
            uint8_t DOOR_3_FULLY_OPENED : 1;
            uint8_t DOOR_4_FULLY_OPENED : 1;
            uint8_t DOOR_5_FULLY_OPENED : 1;
            uint8_t DOOR_6_FULLY_OPENED : 1;
            uint8_t DOOR_7_FULLY_OPENED : 1; //byte 17
            uint8_t CABINET_RIOM_2_CB_PROTECTION : 1;
            uint8_t ETCS_EMERGENCY_BRAKE_COMMAND_1 : 1;
            uint8_t ETCS_EMERGENCY_BRAKE_COMMAND_2 : 1;
            uint8_t ETCS_MAIN_POWER_COMMAND : 1;
            uint8_t ETCS_TRACTION_CUT_OFF : 1;
            uint8_t ETCS_REGENERATIVE_BRAKE_INHIBIT : 1;
            uint8_t bit143 : 1;
            uint8_t DOOR_8_FULLY_OPENED : 1; //byte 18
            uint8_t PLANT_5_3_CB_PROTECTION : 1;
            uint8_t PLANT_6_0_CB_PROTECTION : 1;
            uint8_t PLANT_6_5_CB_PROTECTION : 1;
            uint8_t CONTACTOR_VEHICLE_LIGHTS_ON : 1;
            uint8_t CONTACTOR_VEHICLE_HALF_LIGHT : 1;
            uint8_t CONTACTOR_VEHICLE_EMERGENCY_LIGHT : 1;
            uint8_t PLANT_7_0_CB_PROTECTION : 1;
            uint8_t ETCS_EQUIPMENT_POWER_SUPPLY_APPLIED : 1; //byte 19
            uint8_t PLANT_7_8_CB_PROTECTION : 1;
            uint8_t JRU_FAULT : 1;
            uint8_t ETHERNET_SWITCH_1_PAPIS_ALARM : 1;
            uint8_t ETHERNET_SWITCH_2_PAPIS_ALARM : 1;
            uint8_t ETCS_reserved_1 : 1;
            uint8_t ETCS_PANTOGRAPH_COMMAND : 1;
            uint8_t ETCS_AIR_TIGHTNESS : 1;
            uint8_t ETCS_LEFT_DOORS_OPEN_PERMISSION : 1; //byte 20
            uint8_t ETCS_RIGHT_DOORS_OPEN_PERMISSION : 1;
            uint8_t ETCS_FULL_SERVICE_BRAKING_COMMAND : 1;
            uint8_t bit163 : 1;
            uint8_t bit164 : 1;
            uint8_t bit165 : 1;
            uint8_t CB_PROTECTION_AXLE_BOX : 1;
            uint8_t bit167 : 1;
            uint16_t TEMPERATURE_PROBE_RTD_1; //byte 21
            uint16_t TEMPERATURE_PROBE_RTD_2; //byte 23
            uint16_t MEASURING_BATTERY_VOLTAGE; //byte 25
            uint16_t TRANSDUCER_HV_VOLTAGE_VCB_IN; //byte 27
            uint16_t TRANSDUCER_HV_CURRENT_VCB_IN; //byte 29
            uint8_t reserved_31; //byte 31

        } bits;
        time_t last_update;
    };
};
/**
 * SKA1	-
 * OA1_VH	0x452
 * OA2_VH	0x492
 * SKA2	-
 * v1.09
*/

struct oa_vh_riom_ccu_mvb2_dcu1 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint8_t R1_DCU_IFESmartAssistDCU : 1; //byte 0
            uint8_t R1_DCU_SuppEmergOp : 1;
            uint8_t R1_DCU_DoorAntiDrag : 1;
            uint8_t R1_DCU_DoorObstDet : 1;
            uint8_t R1_DCU_DoorMoveMonit : 1;
            uint8_t R1_DCU_EntrRel : 1;
            uint8_t R1_DCU_DoorClosed : 1;
            uint8_t R1_DCU_DoorClosedAndLocked : 1;
            uint8_t R1_DCU_DoorFullyOpen : 1; //byte 1
            uint8_t R1_DCU_DoorOutOfService : 1;
            uint8_t R1_DCU_DoorUnlEmergOp : 1;
            uint8_t R1_DCU_EEDOp : 1;
            uint8_t R1_DCU_EADOp : 1;
            uint8_t R1_DCU_PBOpenDLRightOutsideOp : 1;
            uint8_t R1_DCU_PBOpenDLRightInsideOp : 1;
            uint8_t R1_DCU_PBPRMPortalInsideOp : 1;
            uint8_t R1_DCU_LightBarrierPortalInsideInterr : 1; //byte 2
            uint8_t R1_DCU_OutputTIL1 : 1;
            uint8_t R1_DCU_DC001 : 1;
            uint8_t R1_DCU_DC002 : 1;
            uint8_t R1_DCU_DC003 : 1;
            uint8_t R1_DCU_DC004 : 1;
            uint8_t R1_DCU_DC005 : 1;
            uint8_t R1_DCU_DC006 : 1;
            uint8_t R1_DCU_DC007 : 1; //byte 3
            uint8_t R1_DCU_DC008 : 1;
            uint8_t R1_DCU_DC009 : 1;
            uint8_t R1_DCU_DC010 : 1;
            uint8_t R1_DCU_DC013 : 1;
            uint8_t R1_DCU_DC014 : 1;
            uint8_t R1_DCU_DC015 : 1;
            uint8_t R1_DCU_DC016 : 1;
            uint8_t R1_DCU_DC017 : 1; //byte 4
            uint8_t R1_DCU_DC018 : 1;
            uint8_t R1_DCU_DC019 : 1;
            uint8_t R1_DCU_DC020 : 1;
            uint8_t R1_DCU_DC021 : 1;
            uint8_t R1_DCU_DC022 : 1;
            uint8_t R1_DCU_DC027 : 1;
            uint8_t R1_DCU_DC028 : 1;
            uint8_t R1_DCU_DC029 : 1; //byte 5
            uint8_t R1_DCU_DC030 : 1;
            uint8_t R1_DCU_DC031 : 1;
            uint8_t R1_DCU_DC033 : 1;
            uint8_t R1_DCU_DC037 : 1;
            uint8_t R1_DCU_DC042 : 1;
            uint8_t R1_DCU_DC043 : 1;
            uint8_t R1_DCU_DC044 : 1;
            uint8_t R1_DCU_DC046 : 1; //byte 6
            uint8_t R1_DCU_DC048 : 1;
            uint8_t R1_DCU_DC049 : 1;
            uint8_t R1_DCU_DC050 : 1;
            uint8_t R1_DCU_DC051 : 1;
            uint8_t R1_DCU_DC052 : 1;
            uint8_t R1_DCU_DC053 : 1;
            uint8_t R1_DCU_DC065 : 1;
            uint8_t R1_DCU_DC066 : 1; //byte 7
            uint8_t R1_DCU_DC067 : 1;
            uint8_t R1_DCU_DC068 : 1;
            uint8_t R1_DCU_DC069 : 1;
            uint8_t R1_DCU_DC090 : 1;
            uint8_t R1_DCU_DC091 : 1;
            uint8_t R1_DCU_DC098 : 1;
            uint8_t R1_DCU_DC099 : 1;
            uint8_t R1_DCU_DC101 : 1; //byte 8
            uint8_t R1_DCU_DC102 : 1;
            uint8_t R1_DCU_DC103 : 1;
            uint8_t R1_DCU_DC105 : 1;
            uint8_t R1_DCU_DC106 : 1;
            uint8_t R1_DCU_DC111 : 1;
            uint8_t R1_DCU_DC116 : 1;
            uint8_t R1_DCU_DiagPrioA : 1;
            uint8_t R1_DCU_DiagPrioB : 1; //byte 9
            uint8_t bit73 : 1;
            uint8_t bit74 : 1;
            uint8_t bit75 : 1;
            uint8_t bit76 : 1;
            uint8_t bit77 : 1;
            uint8_t bit78 : 1;
            uint8_t bit79 : 1;
            uint8_t R2_DCU_IFESmartAssistDCU : 1; //byte 10
            uint8_t R2_DCU_SuppEmergOp : 1;
            uint8_t R2_DCU_DoorAntiDrag : 1;
            uint8_t R2_DCU_DoorObstDet : 1;
            uint8_t R2_DCU_DoorMoveMonit : 1;
            uint8_t R2_DCU_EntrRel : 1;
            uint8_t R2_DCU_DoorClosed : 1;
            uint8_t R2_DCU_DoorClosedAndLocked : 1;
            uint8_t R2_DCU_DoorFullyOpen : 1; //byte 11
            uint8_t R2_DCU_DoorOutOfService : 1;
            uint8_t R2_DCU_DoorUnlEmergOp : 1;
            uint8_t R2_DCU_EEDOp : 1;
            uint8_t R2_DCU_EADOp : 1;
            uint8_t R2_DCU_PBOpenDLRightOutsideOp : 1;
            uint8_t R2_DCU_PBOpenDLRightInsideOp : 1;
            uint8_t R2_DCU_PBPRMPortalInsideOp : 1;
            uint8_t R2_DCU_LightBarrierPortalInsideInterr : 1; //byte 12
            uint8_t R2_DCU_OutputTIL1 : 1;
            uint8_t R2_DCU_DC001 : 1;
            uint8_t R2_DCU_DC002 : 1;
            uint8_t R2_DCU_DC003 : 1;
            uint8_t R2_DCU_DC004 : 1;
            uint8_t R2_DCU_DC005 : 1;
            uint8_t R2_DCU_DC006 : 1;
            uint8_t R2_DCU_DC007 : 1; //byte 13
            uint8_t R2_DCU_DC008 : 1;
            uint8_t R2_DCU_DC009 : 1;
            uint8_t R2_DCU_DC010 : 1;
            uint8_t R2_DCU_DC013 : 1;
            uint8_t R2_DCU_DC014 : 1;
            uint8_t R2_DCU_DC015 : 1;
            uint8_t R2_DCU_DC016 : 1;
            uint8_t R2_DCU_DC017 : 1; //byte 14
            uint8_t R2_DCU_DC018 : 1;
            uint8_t R2_DCU_DC019 : 1;
            uint8_t R2_DCU_DC020 : 1;
            uint8_t R2_DCU_DC021 : 1;
            uint8_t R2_DCU_DC022 : 1;
            uint8_t R2_DCU_DC027 : 1;
            uint8_t R2_DCU_DC028 : 1;
            uint8_t R2_DCU_DC029 : 1; //byte 15
            uint8_t R2_DCU_DC030 : 1;
            uint8_t R2_DCU_DC031 : 1;
            uint8_t R2_DCU_DC033 : 1;
            uint8_t R2_DCU_DC037 : 1;
            uint8_t R2_DCU_DC042 : 1;
            uint8_t R2_DCU_DC043 : 1;
            uint8_t R2_DCU_DC044 : 1;
            uint8_t R2_DCU_DC046 : 1; //byte 16
            uint8_t R2_DCU_DC048 : 1;
            uint8_t R2_DCU_DC049 : 1;
            uint8_t R2_DCU_DC050 : 1;
            uint8_t R2_DCU_DC051 : 1;
            uint8_t R2_DCU_DC052 : 1;
            uint8_t R2_DCU_DC053 : 1;
            uint8_t R2_DCU_DC065 : 1;
            uint8_t R2_DCU_DC066 : 1; //byte 17
            uint8_t R2_DCU_DC067 : 1;
            uint8_t R2_DCU_DC068 : 1;
            uint8_t R2_DCU_DC069 : 1;
            uint8_t R2_DCU_DC090 : 1;
            uint8_t R2_DCU_DC091 : 1;
            uint8_t R2_DCU_DC098 : 1;
            uint8_t R2_DCU_DC099 : 1;
            uint8_t R2_DCU_DC101 : 1; //byte 18
            uint8_t R2_DCU_DC102 : 1;
            uint8_t R2_DCU_DC103 : 1;
            uint8_t R2_DCU_DC105 : 1;
            uint8_t R2_DCU_DC106 : 1;
            uint8_t R2_DCU_DC111 : 1;
            uint8_t R2_DCU_DC116 : 1;
            uint8_t R2_DCU_DiagPrioA : 1;
            uint8_t R2_DCU_DiagPrioB : 1; //byte 19
            uint8_t bit153 : 1;
            uint8_t bit154 : 1;
            uint8_t bit155 : 1;
            uint8_t bit156 : 1;
            uint8_t bit157 : 1;
            uint8_t bit158 : 1;
            uint8_t bit159 : 1;
            uint8_t R3_DCU_IFESmartAssistDCU : 1; //byte 20
            uint8_t R3_DCU_SuppEmergOp : 1;
            uint8_t R3_DCU_DoorAntiDrag : 1;
            uint8_t R3_DCU_DoorObstDet : 1;
            uint8_t R3_DCU_DoorMoveMonit : 1;
            uint8_t R3_DCU_EntrRel : 1;
            uint8_t R3_DCU_DoorClosed : 1;
            uint8_t R3_DCU_DoorClosedAndLocked : 1;
            uint8_t R3_DCU_DoorFullyOpen : 1; //byte 21
            uint8_t R3_DCU_DoorOutOfService : 1;
            uint8_t R3_DCU_DoorUnlEmergOp : 1;
            uint8_t R3_DCU_EEDOp : 1;
            uint8_t R3_DCU_EADOp : 1;
            uint8_t R3_DCU_PBOpenDLRightOutsideOp : 1;
            uint8_t R3_DCU_PBOpenDLRightInsideOp : 1;
            uint8_t R3_DCU_PBPRMPortalInsideOp : 1;
            uint8_t R3_DCU_LightBarrierPortalInsideInterr : 1; //byte 22
            uint8_t R3_DCU_OutputTIL1 : 1;
            uint8_t R3_DCU_DC001 : 1;
            uint8_t R3_DCU_DC002 : 1;
            uint8_t R3_DCU_DC003 : 1;
            uint8_t R3_DCU_DC004 : 1;
            uint8_t R3_DCU_DC005 : 1;
            uint8_t R3_DCU_DC006 : 1;
            uint8_t R3_DCU_DC007 : 1; //byte 23
            uint8_t R3_DCU_DC008 : 1;
            uint8_t R3_DCU_DC009 : 1;
            uint8_t R3_DCU_DC010 : 1;
            uint8_t R3_DCU_DC013 : 1;
            uint8_t R3_DCU_DC014 : 1;
            uint8_t R3_DCU_DC015 : 1;
            uint8_t R3_DCU_DC016 : 1;
            uint8_t R3_DCU_DC017 : 1; //byte 24
            uint8_t R3_DCU_DC018 : 1;
            uint8_t R3_DCU_DC019 : 1;
            uint8_t R3_DCU_DC020 : 1;
            uint8_t R3_DCU_DC021 : 1;
            uint8_t R3_DCU_DC022 : 1;
            uint8_t R3_DCU_DC027 : 1;
            uint8_t R3_DCU_DC028 : 1;
            uint8_t R3_DCU_DC029 : 1; //byte 25
            uint8_t R3_DCU_DC030 : 1;
            uint8_t R3_DCU_DC031 : 1;
            uint8_t R3_DCU_DC033 : 1;
            uint8_t R3_DCU_DC037 : 1;
            uint8_t R3_DCU_DC042 : 1;
            uint8_t R3_DCU_DC043 : 1;
            uint8_t R3_DCU_DC044 : 1;
            uint8_t R3_DCU_DC046 : 1; //byte 26
            uint8_t R3_DCU_DC048 : 1;
            uint8_t R3_DCU_DC049 : 1;
            uint8_t R3_DCU_DC050 : 1;
            uint8_t R3_DCU_DC051 : 1;
            uint8_t R3_DCU_DC052 : 1;
            uint8_t R3_DCU_DC053 : 1;
            uint8_t R3_DCU_DC065 : 1;
            uint8_t R3_DCU_DC066 : 1; //byte 27
            uint8_t R3_DCU_DC067 : 1;
            uint8_t R3_DCU_DC068 : 1;
            uint8_t R3_DCU_DC069 : 1;
            uint8_t R3_DCU_DC090 : 1;
            uint8_t R3_DCU_DC091 : 1;
            uint8_t R3_DCU_DC098 : 1;
            uint8_t R3_DCU_DC099 : 1;
            uint8_t R3_DCU_DC101 : 1; //byte 28
            uint8_t R3_DCU_DC102 : 1;
            uint8_t R3_DCU_DC103 : 1;
            uint8_t R3_DCU_DC105 : 1;
            uint8_t R3_DCU_DC106 : 1;
            uint8_t R3_DCU_DC111 : 1;
            uint8_t R3_DCU_DC116 : 1;
            uint8_t R3_DCU_DiagPrioA : 1;
            uint8_t R3_DCU_DiagPrioB : 1; //byte 29
            uint8_t bit233 : 1;
            uint8_t bit234 : 1;
            uint8_t bit235 : 1;
            uint8_t bit236 : 1;
            uint8_t bit237 : 1;
            uint8_t bit238 : 1;
            uint8_t bit239 : 1;
            uint8_t reserved_30; //byte 30
            uint8_t reserved_31; //byte 31
        } bits;
        time_t last_update;
    };
};

/**
 * SKA1	-
 * OA1_VH	0x453
 * OA2_VH	0x493
 * SKA2	-
 * v1.09
*/

struct oa_vh_riom_ccu_mvb3_dcu2 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint8_t R4_DCU_IFESmartAssistDCU : 1; //byte 0
            uint8_t R4_DCU_SuppEmergOp : 1;
            uint8_t R4_DCU_DoorAntiDrag : 1;
            uint8_t R4_DCU_DoorObstDet : 1;
            uint8_t R4_DCU_DoorMoveMonit : 1;
            uint8_t R4_DCU_EntrRel : 1;
            uint8_t R4_DCU_DoorClosed : 1;
            uint8_t R4_DCU_DoorClosedAndLocked : 1;
            uint8_t R4_DCU_DoorFullyOpen : 1; //byte 1
            uint8_t R4_DCU_DoorOutOfService : 1;
            uint8_t R4_DCU_DoorUnlEmergOp : 1;
            uint8_t R4_DCU_EEDOp : 1;
            uint8_t R4_DCU_EADOp : 1;
            uint8_t R4_DCU_PBOpenDLRightOutsideOp : 1;
            uint8_t R4_DCU_PBOpenDLRightInsideOp : 1;
            uint8_t R4_DCU_PBPRMPortalInsideOp : 1;
            uint8_t R4_DCU_LightBarrierPortalInsideInterr : 1; //byte 2
            uint8_t R4_DCU_OutputTIL1 : 1;
            uint8_t R4_DCU_DC001 : 1;
            uint8_t R4_DCU_DC002 : 1;
            uint8_t R4_DCU_DC003 : 1;
            uint8_t R4_DCU_DC004 : 1;
            uint8_t R4_DCU_DC005 : 1;
            uint8_t R4_DCU_DC006 : 1;
            uint8_t R4_DCU_DC007 : 1; //byte 3
            uint8_t R4_DCU_DC008 : 1;
            uint8_t R4_DCU_DC009 : 1;
            uint8_t R4_DCU_DC010 : 1;
            uint8_t R4_DCU_DC013 : 1;
            uint8_t R4_DCU_DC014 : 1;
            uint8_t R4_DCU_DC015 : 1;
            uint8_t R4_DCU_DC016 : 1;
            uint8_t R4_DCU_DC017 : 1; //byte 4
            uint8_t R4_DCU_DC018 : 1;
            uint8_t R4_DCU_DC019 : 1;
            uint8_t R4_DCU_DC020 : 1;
            uint8_t R4_DCU_DC021 : 1;
            uint8_t R4_DCU_DC022 : 1;
            uint8_t R4_DCU_DC027 : 1;
            uint8_t R4_DCU_DC028 : 1;
            uint8_t R4_DCU_DC029 : 1; //byte 5
            uint8_t R4_DCU_DC030 : 1;
            uint8_t R4_DCU_DC031 : 1;
            uint8_t R4_DCU_DC033 : 1;
            uint8_t R4_DCU_DC037 : 1;
            uint8_t R4_DCU_DC042 : 1;
            uint8_t R4_DCU_DC043 : 1;
            uint8_t R4_DCU_DC044 : 1;
            uint8_t R4_DCU_DC046 : 1; //byte 6
            uint8_t R4_DCU_DC048 : 1;
            uint8_t R4_DCU_DC049 : 1;
            uint8_t R4_DCU_DC050 : 1;
            uint8_t R4_DCU_DC051 : 1;
            uint8_t R4_DCU_DC052 : 1;
            uint8_t R4_DCU_DC053 : 1;
            uint8_t R4_DCU_DC065 : 1;
            uint8_t R4_DCU_DC066 : 1; //byte 7
            uint8_t R4_DCU_DC067 : 1;
            uint8_t R4_DCU_DC068 : 1;
            uint8_t R4_DCU_DC069 : 1;
            uint8_t R4_DCU_DC090 : 1;
            uint8_t R4_DCU_DC091 : 1;
            uint8_t R4_DCU_DC098 : 1;
            uint8_t R4_DCU_DC099 : 1;
            uint8_t R4_DCU_DC101 : 1; //byte 8
            uint8_t R4_DCU_DC102 : 1;
            uint8_t R4_DCU_DC103 : 1;
            uint8_t R4_DCU_DC105 : 1;
            uint8_t R4_DCU_DC106 : 1;
            uint8_t R4_DCU_DC111 : 1;
            uint8_t R4_DCU_DC116 : 1;
            uint8_t R4_DCU_DiagPrioA : 1;
            uint8_t R4_DCU_DiagPrioB : 1; //byte 9
            uint8_t bit73 : 1;
            uint8_t bit74 : 1;
            uint8_t bit75 : 1;
            uint8_t bit76 : 1;
            uint8_t bit77 : 1;
            uint8_t bit78 : 1;
            uint8_t bit79 : 1;
            uint8_t L1_DCU_IFESmartAssistDCU : 1; //byte 10
            uint8_t L1_DCU_SuppEmergOp : 1;
            uint8_t L1_DCU_DoorAntiDrag : 1;
            uint8_t L1_DCU_DoorObstDet : 1;
            uint8_t L1_DCU_DoorMoveMonit : 1;
            uint8_t L1_DCU_EntrRel : 1;
            uint8_t L1_DCU_DoorClosed : 1;
            uint8_t L1_DCU_DoorClosedAndLocked : 1;
            uint8_t L1_DCU_DoorFullyOpen : 1; //byte 11
            uint8_t L1_DCU_DoorOutOfService : 1;
            uint8_t L1_DCU_DoorUnlEmergOp : 1;
            uint8_t L1_DCU_EEDOp : 1;
            uint8_t L1_DCU_EADOp : 1;
            uint8_t L1_DCU_PBOpenDLRightOutsideOp : 1;
            uint8_t L1_DCU_PBOpenDLRightInsideOp : 1;
            uint8_t L1_DCU_PBPRMPortalInsideOp : 1;
            uint8_t L1_DCU_LightBarrierPortalInsideInterr : 1; //byte 12
            uint8_t L1_DCU_OutputTIL1 : 1;
            uint8_t L1_DCU_DC001 : 1;
            uint8_t L1_DCU_DC002 : 1;
            uint8_t L1_DCU_DC003 : 1;
            uint8_t L1_DCU_DC004 : 1;
            uint8_t L1_DCU_DC005 : 1;
            uint8_t L1_DCU_DC006 : 1;
            uint8_t L1_DCU_DC007 : 1; //byte 13
            uint8_t L1_DCU_DC008 : 1;
            uint8_t L1_DCU_DC009 : 1;
            uint8_t L1_DCU_DC010 : 1;
            uint8_t L1_DCU_DC013 : 1;
            uint8_t L1_DCU_DC014 : 1;
            uint8_t L1_DCU_DC015 : 1;
            uint8_t L1_DCU_DC016 : 1;
            uint8_t L1_DCU_DC017 : 1; //byte 14
            uint8_t L1_DCU_DC018 : 1;
            uint8_t L1_DCU_DC019 : 1;
            uint8_t L1_DCU_DC020 : 1;
            uint8_t L1_DCU_DC021 : 1;
            uint8_t L1_DCU_DC022 : 1;
            uint8_t L1_DCU_DC027 : 1;
            uint8_t L1_DCU_DC028 : 1;
            uint8_t L1_DCU_DC029 : 1; //byte 15
            uint8_t L1_DCU_DC030 : 1;
            uint8_t L1_DCU_DC031 : 1;
            uint8_t L1_DCU_DC033 : 1;
            uint8_t L1_DCU_DC037 : 1;
            uint8_t L1_DCU_DC042 : 1;
            uint8_t L1_DCU_DC043 : 1;
            uint8_t L1_DCU_DC044 : 1;
            uint8_t L1_DCU_DC046 : 1; //byte 16
            uint8_t L1_DCU_DC048 : 1;
            uint8_t L1_DCU_DC049 : 1;
            uint8_t L1_DCU_DC050 : 1;
            uint8_t L1_DCU_DC051 : 1;
            uint8_t L1_DCU_DC052 : 1;
            uint8_t L1_DCU_DC053 : 1;
            uint8_t L1_DCU_DC065 : 1;
            uint8_t L1_DCU_DC066 : 1; //byte 17
            uint8_t L1_DCU_DC067 : 1;
            uint8_t L1_DCU_DC068 : 1;
            uint8_t L1_DCU_DC069 : 1;
            uint8_t L1_DCU_DC090 : 1;
            uint8_t L1_DCU_DC091 : 1;
            uint8_t L1_DCU_DC098 : 1;
            uint8_t L1_DCU_DC099 : 1;
            uint8_t L1_DCU_DC101 : 1; //byte 18
            uint8_t L1_DCU_DC102 : 1;
            uint8_t L1_DCU_DC103 : 1;
            uint8_t L1_DCU_DC105 : 1;
            uint8_t L1_DCU_DC106 : 1;
            uint8_t L1_DCU_DC111 : 1;
            uint8_t L1_DCU_DC116 : 1;
            uint8_t L1_DCU_DiagPrioA : 1;
            uint8_t L1_DCU_DiagPrioB : 1; //byte 19
            uint8_t bit153 : 1;
            uint8_t bit154 : 1;
            uint8_t bit155 : 1;
            uint8_t bit156 : 1;
            uint8_t bit157 : 1;
            uint8_t bit158 : 1;
            uint8_t bit159 : 1;
            uint8_t L2_DCU_IFESmartAssistDCU : 1; //byte 20
            uint8_t L2_DCU_SuppEmergOp : 1;
            uint8_t L2_DCU_DoorAntiDrag : 1;
            uint8_t L2_DCU_DoorObstDet : 1;
            uint8_t L2_DCU_DoorMoveMonit : 1;
            uint8_t L2_DCU_EntrRel : 1;
            uint8_t L2_DCU_DoorClosed : 1;
            uint8_t L2_DCU_DoorClosedAndLocked : 1;
            uint8_t L2_DCU_DoorFullyOpen : 1; //byte 21
            uint8_t L2_DCU_DoorOutOfService : 1;
            uint8_t L2_DCU_DoorUnlEmergOp : 1;
            uint8_t L2_DCU_EEDOp : 1;
            uint8_t L2_DCU_EADOp : 1;
            uint8_t L2_DCU_PBOpenDLRightOutsideOp : 1;
            uint8_t L2_DCU_PBOpenDLRightInsideOp : 1;
            uint8_t L2_DCU_PBPRMPortalInsideOp : 1;
            uint8_t L2_DCU_LightBarrierPortalInsideInterr : 1; //byte 22
            uint8_t L2_DCU_OutputTIL1 : 1;
            uint8_t L2_DCU_DC001 : 1;
            uint8_t L2_DCU_DC002 : 1;
            uint8_t L2_DCU_DC003 : 1;
            uint8_t L2_DCU_DC004 : 1;
            uint8_t L2_DCU_DC005 : 1;
            uint8_t L2_DCU_DC006 : 1;
            uint8_t L2_DCU_DC007 : 1; //byte 23
            uint8_t L2_DCU_DC008 : 1;
            uint8_t L2_DCU_DC009 : 1;
            uint8_t L2_DCU_DC010 : 1;
            uint8_t L2_DCU_DC013 : 1;
            uint8_t L2_DCU_DC014 : 1;
            uint8_t L2_DCU_DC015 : 1;
            uint8_t L2_DCU_DC016 : 1;
            uint8_t L2_DCU_DC017 : 1; //byte 24
            uint8_t L2_DCU_DC018 : 1;
            uint8_t L2_DCU_DC019 : 1;
            uint8_t L2_DCU_DC020 : 1;
            uint8_t L2_DCU_DC021 : 1;
            uint8_t L2_DCU_DC022 : 1;
            uint8_t L2_DCU_DC027 : 1;
            uint8_t L2_DCU_DC028 : 1;
            uint8_t L2_DCU_DC029 : 1; //byte 25
            uint8_t L2_DCU_DC030 : 1;
            uint8_t L2_DCU_DC031 : 1;
            uint8_t L2_DCU_DC033 : 1;
            uint8_t L2_DCU_DC037 : 1;
            uint8_t L2_DCU_DC042 : 1;
            uint8_t L2_DCU_DC043 : 1;
            uint8_t L2_DCU_DC044 : 1;
            uint8_t L2_DCU_DC046 : 1; //byte 26
            uint8_t L2_DCU_DC048 : 1;
            uint8_t L2_DCU_DC049 : 1;
            uint8_t L2_DCU_DC050 : 1;
            uint8_t L2_DCU_DC051 : 1;
            uint8_t L2_DCU_DC052 : 1;
            uint8_t L2_DCU_DC053 : 1;
            uint8_t L2_DCU_DC065 : 1;
            uint8_t L2_DCU_DC066 : 1; //byte 27
            uint8_t L2_DCU_DC067 : 1;
            uint8_t L2_DCU_DC068 : 1;
            uint8_t L2_DCU_DC069 : 1;
            uint8_t L2_DCU_DC090 : 1;
            uint8_t L2_DCU_DC091 : 1;
            uint8_t L2_DCU_DC098 : 1;
            uint8_t L2_DCU_DC099 : 1;
            uint8_t L2_DCU_DC101 : 1; //byte 28
            uint8_t L2_DCU_DC102 : 1;
            uint8_t L2_DCU_DC103 : 1;
            uint8_t L2_DCU_DC105 : 1;
            uint8_t L2_DCU_DC106 : 1;
            uint8_t L2_DCU_DC111 : 1;
            uint8_t L2_DCU_DC116 : 1;
            uint8_t L2_DCU_DiagPrioA : 1;
            uint8_t L2_DCU_DiagPrioB : 1; //byte 29
            uint8_t bit233 : 1;
            uint8_t bit234 : 1;
            uint8_t bit235 : 1;
            uint8_t bit236 : 1;
            uint8_t bit237 : 1;
            uint8_t bit238 : 1;
            uint8_t bit239 : 1;
            uint8_t reserved_30; //byte 30
            uint8_t reserved_31; //byte 31
        } bits;
        time_t last_update;
    };
};

/**
 * SKA1	-
 * OA1_VH	0x454
 * OA2_VH	0x494
 * SKA2	-
 * v1.09
*/

struct oa_vh_riom_ccu_mvb4_dcu3 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint8_t L3_DCU_IFESmartAssistDCU : 1; //byte 0
            uint8_t L3_DCU_SuppEmergOp : 1;
            uint8_t L3_DCU_DoorAntiDrag : 1;
            uint8_t L3_DCU_DoorObstDet : 1;
            uint8_t L3_DCU_DoorMoveMonit : 1;
            uint8_t L3_DCU_EntrRel : 1;
            uint8_t L3_DCU_DoorClosed : 1;
            uint8_t L3_DCU_DoorClosedAndLocked : 1;
            uint8_t L3_DCU_DoorFullyOpen : 1; //byte 1
            uint8_t L3_DCU_DoorOutOfService : 1;
            uint8_t L3_DCU_DoorUnlEmergOp : 1;
            uint8_t L3_DCU_EEDOp : 1;
            uint8_t L3_DCU_EADOp : 1;
            uint8_t L3_DCU_PBOpenDLRightOutsideOp : 1;
            uint8_t L3_DCU_PBOpenDLRightInsideOp : 1;
            uint8_t L3_DCU_PBPRMPortalInsideOp : 1;
            uint8_t L3_DCU_LightBarrierPortalInsideInterr : 1; //byte 2
            uint8_t L3_DCU_OutputTIL1 : 1;
            uint8_t L3_DCU_DC001 : 1;
            uint8_t L3_DCU_DC002 : 1;
            uint8_t L3_DCU_DC003 : 1;
            uint8_t L3_DCU_DC004 : 1;
            uint8_t L3_DCU_DC005 : 1;
            uint8_t L3_DCU_DC006 : 1;
            uint8_t L3_DCU_DC007 : 1; //byte 3
            uint8_t L3_DCU_DC008 : 1;
            uint8_t L3_DCU_DC009 : 1;
            uint8_t L3_DCU_DC010 : 1;
            uint8_t L3_DCU_DC013 : 1;
            uint8_t L3_DCU_DC014 : 1;
            uint8_t L3_DCU_DC015 : 1;
            uint8_t L3_DCU_DC016 : 1;
            uint8_t L3_DCU_DC017 : 1; //byte 4
            uint8_t L3_DCU_DC018 : 1;
            uint8_t L3_DCU_DC019 : 1;
            uint8_t L3_DCU_DC020 : 1;
            uint8_t L3_DCU_DC021 : 1;
            uint8_t L3_DCU_DC022 : 1;
            uint8_t L3_DCU_DC027 : 1;
            uint8_t L3_DCU_DC028 : 1;
            uint8_t L3_DCU_DC029 : 1; //byte 5
            uint8_t L3_DCU_DC030 : 1;
            uint8_t L3_DCU_DC031 : 1;
            uint8_t L3_DCU_DC033 : 1;
            uint8_t L3_DCU_DC037 : 1;
            uint8_t L3_DCU_DC042 : 1;
            uint8_t L3_DCU_DC043 : 1;
            uint8_t L3_DCU_DC044 : 1;
            uint8_t L3_DCU_DC046 : 1; //byte 6
            uint8_t L3_DCU_DC048 : 1;
            uint8_t L3_DCU_DC049 : 1;
            uint8_t L3_DCU_DC050 : 1;
            uint8_t L3_DCU_DC051 : 1;
            uint8_t L3_DCU_DC052 : 1;
            uint8_t L3_DCU_DC053 : 1;
            uint8_t L3_DCU_DC065 : 1;
            uint8_t L3_DCU_DC066 : 1; //byte 7
            uint8_t L3_DCU_DC067 : 1;
            uint8_t L3_DCU_DC068 : 1;
            uint8_t L3_DCU_DC069 : 1;
            uint8_t L3_DCU_DC090 : 1;
            uint8_t L3_DCU_DC091 : 1;
            uint8_t L3_DCU_DC098 : 1;
            uint8_t L3_DCU_DC099 : 1;
            uint8_t L3_DCU_DC101 : 1; //byte 8
            uint8_t L3_DCU_DC102 : 1;
            uint8_t L3_DCU_DC103 : 1;
            uint8_t L3_DCU_DC105 : 1;
            uint8_t L3_DCU_DC106 : 1;
            uint8_t L3_DCU_DC111 : 1;
            uint8_t L3_DCU_DC116 : 1;
            uint8_t L3_DCU_DiagPrioA : 1;
            uint8_t L3_DCU_DiagPrioB : 1; //byte 9
            uint8_t bit73 : 1;
            uint8_t bit74 : 1;
            uint8_t bit75 : 1;
            uint8_t bit76 : 1;
            uint8_t bit77 : 1;
            uint8_t bit78 : 1;
            uint8_t bit79 : 1;
            uint8_t L4_DCU_IFESmartAssistDCU : 1; //byte 10
            uint8_t L4_DCU_SuppEmergOp : 1;
            uint8_t L4_DCU_DoorAntiDrag : 1;
            uint8_t L4_DCU_DoorObstDet : 1;
            uint8_t L4_DCU_DoorMoveMonit : 1;
            uint8_t L4_DCU_EntrRel : 1;
            uint8_t L4_DCU_DoorClosed : 1;
            uint8_t L4_DCU_DoorClosedAndLocked : 1;
            uint8_t L4_DCU_DoorFullyOpen : 1; //byte 11
            uint8_t L4_DCU_DoorOutOfService : 1;
            uint8_t L4_DCU_DoorUnlEmergOp : 1;
            uint8_t L4_DCU_EEDOp : 1;
            uint8_t L4_DCU_EADOp : 1;
            uint8_t L4_DCU_PBOpenDLRightOutsideOp : 1;
            uint8_t L4_DCU_PBOpenDLRightInsideOp : 1;
            uint8_t L4_DCU_PBPRMPortalInsideOp : 1;
            uint8_t L4_DCU_LightBarrierPortalInsideInterr : 1; //byte 12
            uint8_t L4_DCU_OutputTIL1 : 1;
            uint8_t L4_DCU_DC001 : 1;
            uint8_t L4_DCU_DC002 : 1;
            uint8_t L4_DCU_DC003 : 1;
            uint8_t L4_DCU_DC004 : 1;
            uint8_t L4_DCU_DC005 : 1;
            uint8_t L4_DCU_DC006 : 1;
            uint8_t L4_DCU_DC007 : 1; //byte 13
            uint8_t L4_DCU_DC008 : 1;
            uint8_t L4_DCU_DC009 : 1;
            uint8_t L4_DCU_DC010 : 1;
            uint8_t L4_DCU_DC013 : 1;
            uint8_t L4_DCU_DC014 : 1;
            uint8_t L4_DCU_DC015 : 1;
            uint8_t L4_DCU_DC016 : 1;
            uint8_t L4_DCU_DC017 : 1; //byte 14
            uint8_t L4_DCU_DC018 : 1;
            uint8_t L4_DCU_DC019 : 1;
            uint8_t L4_DCU_DC020 : 1;
            uint8_t L4_DCU_DC021 : 1;
            uint8_t L4_DCU_DC022 : 1;
            uint8_t L4_DCU_DC027 : 1;
            uint8_t L4_DCU_DC028 : 1;
            uint8_t L4_DCU_DC029 : 1; //byte 15
            uint8_t L4_DCU_DC030 : 1;
            uint8_t L4_DCU_DC031 : 1;
            uint8_t L4_DCU_DC033 : 1;
            uint8_t L4_DCU_DC037 : 1;
            uint8_t L4_DCU_DC042 : 1;
            uint8_t L4_DCU_DC043 : 1;
            uint8_t L4_DCU_DC044 : 1;
            uint8_t L4_DCU_DC046 : 1; //byte 16
            uint8_t L4_DCU_DC048 : 1;
            uint8_t L4_DCU_DC049 : 1;
            uint8_t L4_DCU_DC050 : 1;
            uint8_t L4_DCU_DC051 : 1;
            uint8_t L4_DCU_DC052 : 1;
            uint8_t L4_DCU_DC053 : 1;
            uint8_t L4_DCU_DC065 : 1;
            uint8_t L4_DCU_DC066 : 1; //byte 17
            uint8_t L4_DCU_DC067 : 1;
            uint8_t L4_DCU_DC068 : 1;
            uint8_t L4_DCU_DC069 : 1;
            uint8_t L4_DCU_DC090 : 1;
            uint8_t L4_DCU_DC091 : 1;
            uint8_t L4_DCU_DC098 : 1;
            uint8_t L4_DCU_DC099 : 1;
            uint8_t L4_DCU_DC101 : 1; //byte 18
            uint8_t L4_DCU_DC102 : 1;
            uint8_t L4_DCU_DC103 : 1;
            uint8_t L4_DCU_DC105 : 1;
            uint8_t L4_DCU_DC106 : 1;
            uint8_t L4_DCU_DC111 : 1;
            uint8_t L4_DCU_DC116 : 1;
            uint8_t L4_DCU_DiagPrioA : 1;
            uint8_t L4_DCU_DiagPrioB : 1; //byte 19
            uint8_t bit153 : 1;
            uint8_t bit154 : 1;
            uint8_t bit155 : 1;
            uint8_t bit156 : 1;
            uint8_t bit157 : 1;
            uint8_t bit158 : 1;
            uint8_t bit159 : 1;
            uint8_t reserved_20; //byte 20
            uint8_t reserved_21; //byte 21
            uint8_t reserved_22; //byte 22
            uint8_t reserved_23; //byte 23
            uint8_t reserved_24; //byte 24
            uint8_t reserved_25; //byte 25
            uint8_t reserved_26; //byte 26
            uint8_t reserved_27; //byte 27
            uint8_t reserved_28; //byte 28
            uint8_t reserved_29; //byte 29
            uint8_t reserved_30; //byte 30
            uint8_t reserved_31; //byte 31

        } bits;
        time_t last_update;
    };
};

/**
 * SKA1	-
 * OA1_VH	0x455
 * OA2_VH	0x495
 * SKA2	-
 * v1.09
*/

struct oa_vh_riom_ccu_mvb5_dcu4 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_16];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_16)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_16)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_16)];

        struct {
            uint8_t Door_name_Byte1; //byte 0
            uint8_t DCU_CycleCounter_Byte_1;
            uint8_t DCU_CycleCounter_Byte_2;
            uint8_t DCU_CycleCounter_Byte_3;
            uint8_t reserved5;
            uint8_t DCU_SWVer_Char_1;
            uint8_t DCU_SWVer_Char_2;
            uint8_t DCU_SWVer_Char_3;
            uint8_t DCU_SWVer_Char_4;
            uint8_t DCU_SWVer_Char_5;
            uint8_t DCU_SWVer_Char_6;
            uint8_t reserved12;
            uint8_t reserved13;
            uint8_t reserved14;
            uint8_t reserved15;
        } bits;
        time_t last_update;
    };
};

/**
 * SKA1	-
 * OA1_VH	0x456
 * OA2_VH	0x496
 * SKA2	-
 * v1.09
*/

struct oa_vh_riom_ccu_mvb6_hvac1 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint8_t Software_Version_Major ; //byte 0
            uint8_t Software_Version_Minor ; //byte1
            uint8_t Outside_Air_Temp ; //byte2
            uint8_t Ice_Temp ; //byte3
            uint8_t Supply_Air_Temp ; //byte4
            uint8_t Inside_Air_Temp ; //byte5
            uint8_t Set_Point_Temp ; //byte6
            uint8_t Evap_Fans_Speed ;
            uint16_t CO2_Sensor ; //byte8
            uint8_t Smoke_Detector : 1; //byte 10
            uint8_t HVAC_On : 1;
            uint8_t Auto_Mode : 1;
            uint8_t bit83 : 1;
            uint8_t bit84 : 1;
            uint8_t bit85 : 1;
            uint8_t bit86 : 1;
            uint8_t bit87 : 1;
            uint8_t Reduce_Mode : 1; //byte11
            uint8_t Emergency_Mode : 1;
            uint8_t Self_Test_Mode : 1;
            uint8_t bit91 : 1;
            uint8_t Fire_Mode : 1;
            uint8_t Inside_Fire_On : 1;
            uint8_t Half_Cooling : 1;
            uint8_t Full_Cooling : 1;
            uint8_t Half_Heating : 1; //byte12
            uint8_t Full_Heating : 1;
            uint8_t Off_Enable : 1;
            uint8_t Self_Test_Not_Ok : 1;
            uint8_t Self_Test_Ok : 1;
            uint8_t PC_Software_Connected : 1;
            uint8_t Cond_Fans_Low : 1;
            uint8_t Cond_Fans_High : 1;
            uint8_t Heat1_On : 1; //byte13
            uint8_t Heat2_On : 1;
            uint8_t Floor_Heat1_On : 1;
            uint8_t Floor_Heat2_On : 1;
            uint8_t Compressor1_On : 1;
            uint8_t Compressor2_On : 1;
            uint8_t Emerg_Inv_On : 1;
            uint8_t Evap_Sel1_On : 1;
            uint8_t Evap_Sel2_On : 1; //byte14
            uint8_t bit113 : 1;
            uint8_t bit114 : 1;
            uint8_t bit115 : 1;
            uint8_t bit116 : 1;
            uint8_t bit117 : 1;
            uint8_t bit118 : 1;
            uint8_t bit119 : 1;
            uint8_t Emerg_Shut_Air_Damp_Pos ; //byte15
            uint8_t Fresh_Air_Damp_Pos ;  //byte16
            uint8_t Minor_Fault : 1; //byte17
            uint8_t Major_Fault : 1;
            uint8_t Low_Press1_Fault : 1;
            uint8_t Low_Press2_Fault : 1;
            uint8_t High_Press1_Fault : 1;
            uint8_t High_Press2_Fault : 1;
            uint8_t Cond_Fan1_Therm_Fault : 1;
            uint8_t First_Lev_Therm_7585_Fault : 1;
            uint8_t bit144 : 1; //byte18
            uint8_t bit145 : 1;
            uint8_t Evap_Fan1_Fault : 1;
            uint8_t Evap_Fan2_Fault : 1;
            uint8_t Evap_Fan12_Fault : 1;
            uint8_t Three_Phase_Fault : 1;
            uint8_t Emerg_Inv_Input_Fault : 1;
            uint8_t Emerg_Inv_Output_Fault : 1;
            uint8_t Third_Level_Therm_Fault : 1; //byte 19
            uint8_t Evap_Therm1_Fault : 1;
            uint8_t Evap_Therm2_Fault : 1;
            uint8_t Smoke_Detector_Fault : 1;
            uint8_t Comp1_Therm_Fault : 1;
            uint8_t Comp1_Overload_Fault : 1;
            uint8_t Comp2_Therm_Fault : 1;
            uint8_t Comp2_Overload_Fault : 1;
            uint8_t Evap_Inv_Fault : 1; //byte20
            uint8_t Cond_Fan2_Therm_Fault : 1;
            uint8_t Cont_Evap_Solenoid1_Fault : 1;
            uint8_t Cont_Evap_Solenoid2_Fault : 1;
            uint8_t Cont_Cap_Solenoid1_Fault : 1;
            uint8_t Cont_Cap_Solenoid2_Fault : 1;
            uint8_t bit166 : 1;
            uint8_t Cont_Heater1_Fault : 1;
            uint8_t Cont_Heater2_Fault : 1; //byte21
            uint8_t Cont_Evap_Fault : 1;
            uint8_t Cont_Cond_Fault : 1;
            uint8_t Cont_Cond_Fan_Low_Fault : 1;
            uint8_t Cont_Cond_Fan_High_Fault : 1;
            uint8_t Cont_Emergency_Fault : 1;
            uint8_t Comp1_Contc_Fault : 1;
            uint8_t Comp2_Contc_Fault : 1;
            uint8_t Icing_Detect_Fault : 1; //byte22
            uint8_t Supply_Cooling_Detect_Fault : 1;
            uint8_t Supply_Heating_Detect_Fault : 1;
            uint8_t Cooling_Fault : 1;
            uint8_t Heating_Fault : 1;
            uint8_t bit181 : 1;
            uint8_t bit182 : 1;
            uint8_t bit183 : 1;
            uint8_t reserved_23 : 1;
            uint8_t reserved_24 : 1;
            uint8_t reserved_25 : 1;
            uint8_t reserved_26 : 1;
            uint8_t reserved_27 : 1;
            uint8_t reserved_28 : 1;
            uint8_t reserved_29 : 1;
            uint8_t reserved_30 : 1;
            uint8_t reserved_31 : 1;


        } bits;
        time_t last_update;
    };
};
/**
 * SKA1	-
 * OA1_VH	0x457
 * OA2_VH	0x497
 * SKA2	-
 * v1.09
*/

struct oa_vh_riom_ccu_mvb7_hvac2 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint8_t Software_Version_Major ; //byte 0
            uint8_t Software_Version_Minor ; //byte1
            uint8_t Outside_Air_Temp ; //byte2
            uint8_t Ice_Temp ; //byte3
            uint8_t Supply_Air_Temp ; //byte4
            uint8_t Inside_Air_Temp ; //byte5
            uint8_t Set_Point_Temp ; //byte6
            uint8_t Evap_Fans_Speed ;
            uint16_t CO2_Sensor ; //byte8
            uint8_t Smoke_Detector : 1; //byte 10
            uint8_t HVAC_On : 1;
            uint8_t Auto_Mode : 1;
            uint8_t bit83 : 1;
            uint8_t bit84 : 1;
            uint8_t bit85 : 1;
            uint8_t bit86 : 1;
            uint8_t bit87 : 1;
            uint8_t Reduce_Mode : 1; //byte11
            uint8_t Emergency_Mode : 1;
            uint8_t Self_Test_Mode : 1;
            uint8_t bit91 : 1;
            uint8_t Fire_Mode : 1;
            uint8_t Inside_Fire_On : 1;
            uint8_t Half_Cooling : 1;
            uint8_t Full_Cooling : 1;
            uint8_t Half_Heating : 1; //byte12
            uint8_t Full_Heating : 1;
            uint8_t Off_Enable : 1;
            uint8_t Self_Test_Not_Ok : 1;
            uint8_t Self_Test_Ok : 1;
            uint8_t PC_Software_Connected : 1;
            uint8_t Cond_Fans_Low : 1;
            uint8_t Cond_Fans_High : 1;
            uint8_t Heat1_On : 1; //byte13
            uint8_t Heat2_On : 1;
            uint8_t Floor_Heat1_On : 1;
            uint8_t Floor_Heat2_On : 1;
            uint8_t Compressor1_On : 1;
            uint8_t Compressor2_On : 1;
            uint8_t Emerg_Inv_On : 1;
            uint8_t Evap_Sel1_On : 1;
            uint8_t Evap_Sel2_On : 1; //byte14
            uint8_t bit113 : 1;
            uint8_t bit114 : 1;
            uint8_t bit115 : 1;
            uint8_t bit116 : 1;
            uint8_t bit117 : 1;
            uint8_t bit118 : 1;
            uint8_t bit119 : 1;
            uint8_t Emerg_Shut_Air_Damp_Pos ; //byte15
            uint8_t Fresh_Air_Damp_Pos ;  //byte16
            uint8_t Minor_Fault : 1; //byte17
            uint8_t Major_Fault : 1;
            uint8_t Low_Press1_Fault : 1;
            uint8_t Low_Press2_Fault : 1;
            uint8_t High_Press1_Fault : 1;
            uint8_t High_Press2_Fault : 1;
            uint8_t Cond_Fan1_Therm_Fault : 1;
            uint8_t First_Lev_Therm_7585_Fault : 1;
            uint8_t bit144 : 1; //byte18
            uint8_t bit145 : 1;
            uint8_t Evap_Fan1_Fault : 1;
            uint8_t Evap_Fan2_Fault : 1;
            uint8_t Evap_Fan12_Fault : 1;
            uint8_t Three_Phase_Fault : 1;
            uint8_t Emerg_Inv_Input_Fault : 1;
            uint8_t Emerg_Inv_Output_Fault : 1;
            uint8_t Third_Level_Therm_Fault : 1; //byte 19
            uint8_t Evap_Therm1_Fault : 1;
            uint8_t Evap_Therm2_Fault : 1;
            uint8_t Smoke_Detector_Fault : 1;
            uint8_t Comp1_Therm_Fault : 1;
            uint8_t Comp1_Overload_Fault : 1;
            uint8_t Comp2_Therm_Fault : 1;
            uint8_t Comp2_Overload_Fault : 1;
            uint8_t Evap_Inv_Fault : 1; //byte20
            uint8_t Cond_Fan2_Therm_Fault : 1;
            uint8_t Cont_Evap_Solenoid1_Fault : 1;
            uint8_t Cont_Evap_Solenoid2_Fault : 1;
            uint8_t Cont_Cap_Solenoid1_Fault : 1;
            uint8_t Cont_Cap_Solenoid2_Fault : 1;
            uint8_t bit166 : 1;
            uint8_t Cont_Heater1_Fault : 1;
            uint8_t Cont_Heater2_Fault : 1; //byte21
            uint8_t Cont_Evap_Fault : 1;
            uint8_t Cont_Cond_Fault : 1;
            uint8_t Cont_Cond_Fan_Low_Fault : 1;
            uint8_t Cont_Cond_Fan_High_Fault : 1;
            uint8_t Cont_Emergency_Fault : 1;
            uint8_t Comp1_Contc_Fault : 1;
            uint8_t Comp2_Contc_Fault : 1;
            uint8_t Icing_Detect_Fault : 1; //byte22
            uint8_t Supply_Cooling_Detect_Fault : 1;
            uint8_t Supply_Heating_Detect_Fault : 1;
            uint8_t Cooling_Fault : 1;
            uint8_t Heating_Fault : 1;
            uint8_t bit181 : 1;
            uint8_t bit182 : 1;
            uint8_t bit183 : 1;
            uint8_t reserved_23 : 1;
            uint8_t reserved_24 : 1;
            uint8_t reserved_25 : 1;
            uint8_t reserved_26 : 1;
            uint8_t reserved_27 : 1;
            uint8_t reserved_28 : 1;
            uint8_t reserved_29 : 1;
            uint8_t reserved_30 : 1;
            uint8_t reserved_31 : 1;

        } bits;
        time_t last_update;
    };
};

/*BCU*/
/**
 * v3.03
 * SKA1_BCU		0x601
 * OA1_BCU		0x641
 * OA2_BCU		0x681
 * SKA2_BCU		0x6C1
*/
struct bcu_ccu_mvb1
{
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct
        {
            uint16_t XLifeSign; //byte 0
            uint8_t EBCU_MainVersion; //byte2
            uint8_t EBCU_SubVersion;
            uint8_t X_Cpress;
            uint8_t X_Tpress;
            uint8_t X_PrkBrPress_1;
            uint8_t X_PrkBrPress_2;
            uint8_t X_BPPress;
            uint8_t X_MRPPress;
            uint8_t reserved10;
            uint16_t X_LoadWeight; //byte11
            uint16_t X_VAxl1; //byte13
            uint16_t X_VAxl2; //byte15
            uint16_t X_VAxl3; //byte17
            uint16_t X_VAxl4; //byte19
            uint16_t X_Vref;  //byte21
            uint8_t reserved23  ;
            uint8_t reserved24  ;
            uint8_t S_HolBrRe : 1 ; //byte25
            uint8_t V_HolBrRe : 1 ;
            uint8_t S_HolBrAp : 1 ;
            uint8_t V_HolBrAp : 1 ;
            uint8_t S_PrkBrRe : 1 ;
            uint8_t V_PrkBrRe : 1 ;
            uint8_t S_PrkBrReNot : 1 ;
            uint8_t V_PrkBrReNot : 1 ;
            uint8_t S_PnBrRe_Bo1 : 1 ; //byte26
            uint8_t V_PnBrRe_Bo1 : 1 ;
            uint8_t S_PnBrAp_Bo1 : 1 ;
            uint8_t V_PnBrAp_Bo1 : 1 ;
            uint8_t S_PnBrRe_Bo2 : 1 ;
            uint8_t V_PnBrRe_Bo2 : 1 ;
            uint8_t S_PnBrAp_Bo2 : 1 ;
            uint8_t V_PnBrAp_Bo2 : 1 ;
            uint8_t S_EmergBrLoopOpen : 1 ; //byte27
            uint8_t S_TLHolBrRe : 1 ;
            uint8_t S_TLBrakingBit1 : 1 ;
            uint8_t S_TLBrakingBit2 : 1 ;
            uint8_t S_TLBrakingBit3 : 1 ;
            uint8_t S_TLTraction : 1 ;
            uint8_t S_WSPTest_Run : 1 ;
            uint8_t S_WSPTest_Run_abbort : 1 ;
            uint8_t S_WSPactive_Bo1 : 1 ; //byte28
            uint8_t S_WSPok_Bo1 : 1 ;
            uint8_t S_WSPactive_Bo2 : 1 ;
            uint8_t S_WSPok_Bo2 : 1 ;
            uint8_t S_Degraded_Mode : 1 ;
            uint8_t S_ASC_Mode_active : 1 ;
            uint8_t S_Standstill : 1 ;
            uint8_t S_EBCU_EBL_Open_PB : 1 ;
            uint8_t IC_PneuBr : 1 ; //byte29
            uint8_t IC_DirectBr : 1 ;
            uint8_t IC_Cpress_Bo1 : 1 ;
            uint8_t IC_Cpress_Bo2 : 1 ;
            uint8_t IC_PrkBr : 1 ;
            uint8_t IC_Sanding : 1 ;
            uint8_t IC_InDirectBr : 1 ;
            uint8_t S_DoorsClosedLocked : 1 ;
            uint8_t S_ED_fade_Out : 1 ; //byte30
            uint8_t S_BpApValid : 1 ;
            uint8_t S_BpAP : 1 ;
            uint8_t S_Sanding_Heating_Release : 1 ;
            uint8_t S_Sanding_Active : 1 ;
            uint8_t bit246 :1 ;
            uint8_t bit247  :1;
            uint8_t bit248  :1;
            //uint8_t reserved31:1 ;

        }bits;
        time_t last_update;
    };
};
/**
 * v3.03
 * SKA1_BCU		0x603
 * OA1_BCU		0x643
 * OA2_BCU		0x683
 * SKA2_BCU		0x6C3
*/
struct bcu_ccu_mvb2
{
    union {
        uint8_t bytes[IO_RAW_NBYTES_16];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_16)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_16)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_16)];

        struct
        {
            uint16_t XLifeSign ; //byte0
            uint8_t DIA_BOARD_CB09_02 : 1; //byte 2
            uint8_t DIA_BOARD_MB04_04 : 1;
            uint8_t DIA_BOARD_MB03_06 : 1;
            uint8_t DIA_BOARD_MB03_07 : 1;
            uint8_t DIA_BOARD_EB01_08 : 1;
            uint8_t DIA_BOARD_EB02_09 : 1;
            uint8_t bit23 : 1;
            uint8_t bit24 : 1;
            uint8_t DIA_BOARDCODING_MB04_04 : 1; //byte3
            uint8_t DIA_BOARDCODING_MB03_06 : 1;
            uint8_t DIA_BOARDCODING_MB03_07 : 1;
            uint8_t DIA_BOARDCODING_EB01_08 : 1;
            uint8_t DIA_BOARDCODING_EB02_09 : 1;
            uint8_t bit30 : 1;
            uint8_t bit31 : 1;
            uint8_t bit32 : 1;
            uint8_t DIA_CAN_COMM_CB09_02 : 1; //byte4
            uint8_t DIA_CAN_COMM_MB04_03 : 1;
            uint8_t DIA_CAN_COMM_MB03_06 : 1;
            uint8_t DIA_CAN_COMM_MB03_07 : 1;
            uint8_t DIA_CAN_COMM_EB01_08 : 1;
            uint8_t DIA_CAN_COMM_EB02_09 : 1;
            uint8_t bit39 : 1;
            uint8_t bit40 : 1;
            uint8_t DIA_PSENSOR_C : 1; //byte5
            uint8_t DIA_PSENSOR_BP : 1;
            uint8_t DIA_PSENSOR1_PB : 1;
            uint8_t DIA_PSENSOR2_PB : 1;
            uint8_t DIA_PSENSOR_CVD : 1;
            uint8_t DIA_PSENSOR_T : 1;
            uint8_t DIA_PSENSOR_R : 1;
            uint8_t DIA_PSENSOR_CVI : 1;
            uint8_t DIA_PSENSOR_MRP : 1; //byte6
            uint8_t DIA_REL_EBCU_FCT_OK : 1;
            uint8_t DIA_REL_EBCU_EBLOOP_Y_OPEN : 1;
            uint8_t DIA_REL_EBCU_C_EDCUTOFF : 1;
            uint8_t DIA_REL_WSP_R_VLT5KMHDOOR : 1;
            uint8_t DIA_REL_WSP_R_VGT5KMHDOOR : 1;
            uint8_t DIA_REL_WSP_R_VGT10KMHDOOR : 1;
            uint8_t bit56 : 1;
            uint8_t DIA_WSP_FSI_AXLE1 : 1; //byte7
            uint8_t DIA_WSP_FSI_AXLE2 : 1;
            uint8_t DIA_WSP_FSI_AXLE3 : 1;
            uint8_t DIA_WSP_FSI_AXLE4 : 1;
            uint8_t DIA_SPEED_DV1 : 1;
            uint8_t DIA_SPEED_DV2 : 1;
            uint8_t DIA_SPEED_DV3 : 1;
            uint8_t DIA_SPEED_DV4 : 1;
            uint8_t DIA_POP_WSP_Y_HOLD_AX1 : 1; //byte8
            uint8_t DIA_POP_WSP_Y_HOLD_AX2 : 1;
            uint8_t DIA_POP_WSP_Y_HOLD_AX3 : 1;
            uint8_t DIA_POP_WSP_Y_HOLD_AX4 : 1;
            uint8_t DIA_POP_WSP_Y_RELEASE_AX1 : 1;
            uint8_t DIA_POP_WSP_Y_RELEASE_AX2 : 1;
            uint8_t DIA_POP_WSP_Y_RELEASE_AX3 : 1;
            uint8_t DIA_POP_WSP_Y_RELEASE_AX4 : 1;
            uint8_t DIA_WSP_TIMEOUT_AX1 : 1; //byte9
            uint8_t DIA_WSP_TIMEOUT_AX2 : 1;
            uint8_t DIA_WSP_TIMEOUT_AX3 : 1;
            uint8_t DIA_WSP_TIMEOUT_AX4 : 1;
            uint8_t DIA_UWR_TIMEOUT_BO1 : 1;
            uint8_t DIA_UWR_TIMEOUT_BO2 : 1;
            uint8_t DIA_WSP_FAILURE_BO1 : 1;
            uint8_t DIA_WSP_FAILURE_BO2 : 1;
            uint8_t DIA_ASSF : 1; //byte10
            uint8_t DIA_WSP_TEST_ABORTED : 1;
            uint8_t DIA_WSP_CONF : 1;
            uint8_t DIA_CAR_CONFIGURATION : 1;
            uint8_t DIA_EDACTUAL_Bo1_FAILURE : 1;
            uint8_t DIA_EDACTUAL_Bo2_FAILURE : 1;
            uint8_t bit87 : 1;
            uint8_t bit88 : 1;
            uint8_t DIA_POP_SA_DIRECTION_S1 : 1; //byte11
            uint8_t DIA_POP_SA_DIRECTION_S2 : 1;
            uint8_t DIA_POP_SA_DRYING : 1;
            uint8_t DIA_POP_SA_BLOWOUT : 1;
            uint8_t DIA_SANDING_DISTURBED : 1;
            uint8_t bit94 : 1;
            uint8_t bit95 : 1;
            uint8_t bit96 : 1;
            uint8_t DIA_DCL_INCPRESS : 1; //byte12
            uint8_t DIA_DCL_DECPRESS : 1;
            uint8_t DIA_DCL_CONFIG : 1;
            uint8_t DIA_DCL_DEVIATION : 1;
            uint8_t DIA_DCL_OFFSET : 1;
            uint8_t DIA_DIRECTBRAKE_DIST : 1;
            uint8_t DIA_EMERGVALVE : 1;
            uint8_t bit104 : 1;
            uint8_t DIA_AIR_SUSP_PRESS_LOW : 1; //byte13
            uint8_t DIA_AIR_SUSP_PRESS_HIGH : 1;
            uint8_t DIA_AIR_SUSP_PRESS_BURST : 1;
            uint8_t DIA_AIR_SUSP_PRESS_ERROR : 1;
            uint8_t DIA_MR_PRESS_LOW : 1;
            uint8_t DIA_MR_PRESS_ERR : 1;
            uint8_t DIA_R_PRESS_LOW : 1;
            uint8_t DIA_R_PRESS_ERROR : 1;
            uint8_t DIA_HBRELEASE_TRAINLINE_IMPL : 1; //byte14
            uint8_t DIA_TRACTION_TRAINLINE_IMPL : 1;
            uint8_t DIA_EMERGENCY_TRAINLINE_IMPL : 1;
            uint8_t DIA_BRAKE_BITS_IMPL : 1;
            uint8_t DIA_BRAKE_NOT_RELEASED_Bo1 : 1;
            uint8_t DIA_BRAKE_NOT_RELEASED_Bo2 : 1;
            uint8_t DIA_BRAKE_NOT_APPLIED_Bo1 : 1;
            uint8_t DIA_BRAKE_NOT_APPLIED_Bo2 : 1;
            uint8_t DIA_PB_NOT_RELEASED : 1; //byte15
            uint8_t DIA_PB_HOSE_BURST : 1;
            uint8_t DIA_PB_PG_IMPLAUSIBLE : 1;
            uint8_t DIA_MVB_ERROR_BCU : 1;
            uint8_t DIA_MVB_ERROR_TCU : 1;
            uint8_t DIA_MVB_ERROR_VCU : 1;
            uint8_t bit127 : 1;
            uint8_t bit128 : 1;


        }bits;
        time_t last_update;
    };
};


/**
 * v1.02
 * SKA1_TCU1	0x701
 * SKA1_TCU2	0x708
 * SKA2_TCU1	0x7C1
 * SKA2_TCU2	0x7C8
*/
struct tcu_ccu_mvb1
{
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct
        {
            uint16_t Lifesign ; //byte0
            uint8_t Ack_Reset : 1; //byte2
            uint8_t Ack_OOS : 1;
            uint8_t Mode_Traction : 1;
            uint8_t Mode_Brake : 1;
            uint8_t Mode_Forward : 1;
            uint8_t Mode_Reverse : 1;
            uint8_t Mode_Cab_SKA1 : 1;
            uint8_t Mode_Cab_SKA2 : 1;
            uint8_t Mode_Slip_Slide_Control : 1; //byte3
            uint8_t Mode_Traction_Null : 1;
            uint8_t Mode_Traction_Cutoff : 1;
            uint8_t Mode_Traction_OOS : 1;
            uint8_t Mode_Traction_Failure : 1;
            uint8_t Mode_Emergency : 1;
            uint8_t Mode_EDB_Cutoff : 1;
            uint8_t bit31 : 1;
            uint8_t V_MV_Output_Motor1_Ok : 1; //byte4
            uint8_t V_MV_Output_Motor2_Ok : 1;
            uint8_t V_HV_Presence : 1;
            uint8_t V_Traction_DC_Link_Ok : 1;
            uint8_t V_Pantograph_Permission : 1;
            uint8_t V_Traction1_Ok : 1;
            uint8_t V_Traction2_Ok : 1;
            uint8_t V_VCB_Loop_Out : 1;
            uint8_t V_Traction_Active : 1; //byte5
            uint8_t V_ED_Brake_Active : 1;
            uint8_t V_System_Reset : 1;
            uint8_t bit43 : 1;
            uint8_t bit44 : 1;
            uint8_t bit45 : 1;
            uint8_t bit46 : 1;
            uint8_t bit47 : 1;
            uint8_t STS_Main_Cont1 : 1; //byte6
            uint8_t STS_Main_Cont2 : 1;
            uint8_t STS_Pre_Cont1 : 1;
            uint8_t STS_Pre_Cont2 : 1;
            uint8_t STS_TC_Cover_Open : 1;
            uint8_t STS_TL_VCB : 1;
            uint8_t bit54 : 1;
            uint8_t bit55 : 1;
            uint16_t Catenary_Voltage ; //byte7
            uint8_t reserved_9 ; //byte9
            uint8_t SW_Version_Major ; //byte10
            uint8_t SW_Version_Minor ; //byte11
            uint8_t reserved_12 ;  //byte12
            uint8_t TCU_Location_SKA1_1 : 1; //byte13
            uint8_t TCU_Location_SKA1_2 : 1;
            uint8_t TCU_Location_SKA2_1 : 1;
            uint8_t TCU_Location_SKA2_2 : 1;
            uint8_t bit108 : 1;
            uint8_t bit109 : 1;
            uint8_t bit110 : 1;
            uint8_t bit111 : 1;
            uint8_t bit112 : 1;
            uint8_t reserved_14; //byte14
            uint8_t DIA_TL_Enable : 1; //byte15
            uint8_t DIA_TL_Normal_Rescue : 1;
            uint8_t DIA_TL_Speed_Limit : 1;
            uint8_t DIA_TL_Cabs_Mode : 1;
            uint8_t DIA_TL_Traction_Null : 1;
            uint8_t DIA_TL_Forward : 1;
            uint8_t DIA_TL_Reverse : 1;
            uint8_t DIA_TL_Traction_CutOff : 1;
            uint8_t DIA_TL_Relay_Security_Emergency_Loop : 1; //byte16
            uint8_t DIA_TL_MC_S1 : 1;
            uint8_t DIA_TL_MC_S2 : 1;
            uint8_t DIA_TL_MC_S3 : 1;
            uint8_t DIA_TL_MC_S4 : 1;
            uint8_t DIA_TL_MC_S5 : 1;
            uint8_t DIA_TL_MC_S6 : 1;
            uint8_t DIA_TL_VCB_On_Off : 1;
            uint8_t DIA_Conflict_Catenary_Voltage : 1; //byte17
            uint8_t DIA_Catenary_Out_Of_Range : 1;
            uint8_t DIA_DC_Link_OV : 1;
            uint8_t DIA_DC_Link_LV : 1;
            uint8_t DIA_Input1_OC : 1;
            uint8_t DIA_Input2_OC : 1;
            uint8_t DIA_Input1_OL : 1;
            uint8_t DIA_Input2_OL : 1;
            uint8_t DIA_Motor_OC : 1; //byte18
            uint8_t DIA_Motor_Phase_Unbalance : 1;
            uint8_t DIA_Speed_Sensor_Fault : 1;
            uint8_t DIA_Motor1_Overspeed : 1;
            uint8_t DIA_Motor2_Overspeed : 1;
            uint8_t DIA_Motor1_OT : 1;
            uint8_t DIA_Motor2_OT : 1;
            uint8_t DIA_Motor1_Gearbox_OT : 1;
            uint8_t DIA_Motor2_Gearbox_OT : 1;  //byte19
            uint8_t DIA_Module1_OT : 1;
            uint8_t DIA_Module2_OT : 1;
            uint8_t DIA_Module3_OT : 1;
            uint8_t DIA_Module4_OT : 1;
            uint8_t DIA_TC_OT : 1;
            uint8_t DIA_TC_OH : 1;
            uint8_t DIA_Coolant_OT : 1;
            uint8_t DIA_Low_Coolant_Flow : 1;  //byte20
            uint8_t DIA_Coolant_Pressure : 1;
            uint8_t DIA_Coolant_Lvl_Warning : 1;
            uint8_t DIA_Coolant_Lvl_Fault : 1;
            uint8_t DIA_Coolant_Fan_CB : 1;
            uint8_t DIA_Cabinet_Fan_CB : 1;
            uint8_t DIA_TCU_Fan_CB : 1;
            uint8_t DIA_Pump_CB : 1;
            uint8_t DIA_Input_Contactor1_Jammed : 1; //byte21
            uint8_t DIA_Input_Contactor2_Jammed : 1;
            uint8_t DIA_Input_Contactor1_OER : 1;
            uint8_t DIA_Input_Contactor2_OER : 1;
            uint8_t DIA_PreCharge_Contactor1_Jammed : 1;
            uint8_t DIA_PreCharge_Contactor2_Jammed : 1;
            uint8_t DIA_PreCharge_Contactor1_OER : 1;
            uint8_t DIA_PreCharge_Contactor2_OER : 1;
            uint8_t DIA_Capacitor_Fault : 1;  //byte22
            uint8_t DIA_110VDC_Input_Fault : 1;
            uint8_t DIA_15VDC_GPLV_Fault : 1;
            uint8_t DIA_24VDC_P_Fault : 1;
            uint8_t DIA_24VDC_N_Fault : 1;
            uint8_t DIA_5VDC_D_Fault : 1;
            uint8_t DIA_5VDC_A_Fault : 1;
            uint8_t DIA_CPU_Fault : 1;
            uint8_t DIA_Rec1_IGBT_UP_Fault : 1; //byte23
            uint8_t DIA_Rec1_IGBT_UN_Fault : 1;
            uint8_t DIA_Rec1_IGBT_VP_Fault : 1;
            uint8_t DIA_Rec1_IGBT_VN_Fault : 1;
            uint8_t DIA_Rec2_IGBT_UP_Fault : 1;
            uint8_t DIA_Rec2_IGBT_UN_Fault : 1;
            uint8_t DIA_Rec2_IGBT_VP_Fault : 1;
            uint8_t DIA_Rec2_IGBT_VN_Fault : 1;
            uint8_t DIA_Inv_IGBT_UP_Fault : 1; //byte24
            uint8_t DIA_Inv_IGBT_UN_Fault : 1;
            uint8_t DIA_Inv_IGBT_VP_Fault : 1;
            uint8_t DIA_Inv_IGBT_VN_Fault : 1;
            uint8_t DIA_Inv_IGBT_WP_Fault : 1;
            uint8_t DIA_Inv_IGBT_WN_Fault : 1;
            uint8_t DIA_Chop_IGBT_OVP_Fault : 1;
            uint8_t DIA_Chop_IGBT_FWD_Fault : 1;
            uint8_t DIA_CFD_Fault : 1;  //byte25
            uint8_t DIA_Insulation_Fault : 1;
            uint8_t DIA_PreCh_Fault : 1;
            uint8_t DIA_Frequency_Irregular : 1;
            uint8_t DIA_WF_Irregular : 1;
            uint8_t bit205 : 1;
            uint8_t bit206 : 1;
            uint8_t bit207 : 1;
            uint8_t reserved_26;
            uint8_t reserved_27;
            uint8_t reserved_28;
            uint8_t reserved_29;
            uint8_t reserved_30;
            uint8_t reserved_31;

        }bits;
        time_t last_update;
    };
};


/**
 * v1.02
 * SKA1_TCU1	0x702
 * SKA1_TCU2	0x709
 * SKA2_TCU1	0x7C2
 * SKA2_TCU2	0x7C9
*/
struct tcu_ccu_mvb2
{
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct
        {
            uint16_t Lifesign ; //byte0
            uint16_t Traction_Achieved ; //byte2
            uint16_t ED_Brake_Achieved ; //byte4
            int8_t Temp_Converter ; //byte6
            int8_t Temp_Power_Module ; //byte7
            int8_t Temp_Coolant ; //byte8
            int8_t Temp_Motor1 ; //byte9
            int8_t Temp_Motor2 ; //byte10
            int8_t Temp_Gear_Box1 ; //byte11
            int8_t Temp_Gear_Box2 ; //byte12
            uint16_t Motor_Current ; //byte13
            uint16_t Secondary_Current1 ; //byte15
            uint16_t Secondary_Current2 ; //byte17
            uint16_t Motor_Speed1 ; //byte19
            uint16_t Motor_Speed2 ; //byte21
            uint8_t reserved23 ;
            uint8_t reserved24 ;
            uint8_t reserved25 ;
            uint8_t reserved26 ;
            uint8_t reserved27 ;
            uint8_t reserved28 ;
            uint8_t reserved29 ;
            uint8_t reserved30 ;
            uint8_t reserved31 ;

        }bits;
        time_t last_update;
    };
};




/**
 * SKA1_BCU		0x608
 * OA1_BCU		-
 * OA2_BCU		-
 * SKA2_BCU		0x6C8
*/
/* ben açtım burayı
struct bcu_ccu_mvb3
{
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct
        {
            uint16_t XLifeSign ; //byte0
            uint16_t C_EDdemand_Bogie1 ; //byte2
            uint16_t C_EDdemand_Bogie2 ; //byte4
            uint16_t C_WSPreduction_Bogie1 ; //byte6
            uint16_t C_WSPreduction_Bogie2 ; //byte8
            uint8_t C_EDCutOff_Bogie1 : 1;   //byte10
            uint8_t C_EDCutOff_Bogie2 : 1;
            uint8_t bit83 ;
            uint8_t bit84 ;
            uint8_t bit85 ;
            uint8_t bit86 ;
            uint8_t bit87 ;
            uint8_t bit88 ;
            uint8_t reserved11 ; //byte11
            uint8_t reserved12 ; //byte12
            uint8_t reserved13 ; //byte13
            uint8_t reserved14 ; //byte14
            uint8_t reserved15 ; //byte15

        }bits;
        time_t last_update;
    };
};
*/
/**
 * SKA1
 * OA1_ETCS		0x941
 * OA2_ETCS		0x981
 * SKA2
*/

struct etcs_ccu_mvb1
{
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct
        {
            uint16_t Lifesign;//byte 0
            uint8_t Valid:2;//byte 2
            uint8_t bit2:1;
            uint8_t bit3:1;
            uint8_t bit4:1;
            uint8_t bit5:1;
            uint8_t bit6:1;
            uint8_t bit7:1;
            uint8_t OBU_TR_ServiceBrake:1;//byte 3
            uint8_t bit9:1;
            uint8_t OBU_TR_TCO_Cmd:1;
            uint8_t OBU_TR_RBInhibit_Cmd:1;
            uint8_t bit12:1;
            uint8_t bit13:1;
            uint8_t bit14:1;
            uint8_t OBU_TR_AT_Cmd:1;
            uint8_t OBU_TR_MPS_Cmd:1;//byte 4
            uint8_t OBU_TR_PG_Cmd:1;
            uint8_t OBU_TR_V_Real_Flag:1;
            uint8_t OBU_TR_EB_Active_Status:1;
            uint8_t OBU_TR_EB_Test_Status:1;
            uint8_t OBU_TR_ETCS_Isolated:1;
            uint8_t bit22:1;
            uint8_t bit23:1;
            uint16_t OBU_TR_CTS_D_Change;//byte  5
            uint8_t reserved7;
            uint8_t reserved8;
            uint8_t reserved9;
            uint16_t OBU_TR_ACC_D_Change;//byte 10
            uint16_t OBU_TR_ACC_Limit;//byte 12
            uint16_t OBU_TR_Train_Speed;//byte 14
            uint8_t OBU_TR_EVC_M_LEVEL;//byte 16
            uint8_t OBU_TR_EVC_M_MODE;//byte 17
            uint8_t bit128:1;//byte 18
            uint8_t bit129:1;
            uint8_t bit130:1;
            uint8_t bit131:1;
            uint8_t bit132:1;
            uint8_t bit133:1;
            uint8_t EB1_Test_Output:1;
            uint8_t EB2_Test_Output:1;
            char    Train_Number[12];//byte 19
            uint8_t reserved31;/*reserved for terminating character*/
        }bits;
        time_t last_update;
    };
};

/**
 * SKA1
 * OA1_ETCS		0x942
 * OA2_ETCS		0x982
 * SKA2
*/
struct etcs_ccu_mvb2
{
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct
        {
            uint16_t Lifesign;//byte 0
            uint8_t Valid:2;//byte 2
            uint8_t bit2:1;
            uint8_t bit3:1;
            uint8_t bit4:1;
            uint8_t bit5:1;
            uint8_t bit6:1;
            uint8_t bit7:1;
            uint8_t Validity1:1;//byte 3
            uint8_t Validity2:1;
            uint8_t Validity3:1;
            uint8_t Validity4:1;
            uint8_t Validity5:1;
            uint8_t bit13:1;
            uint8_t bit14:1;
            uint8_t bit15:1;
            uint8_t OBU_TR_SP_Left1:1;//byte 4
            uint8_t OBU_TR_SP_Right1:1;
            uint8_t bit18:1;
            uint8_t bit19:1;
            uint8_t OBU_TR_SP_Height1_Bit0:1;
            uint8_t OBU_TR_SP_Height1_Bit1:1;
            uint8_t OBU_TR_SP_Height1_Bit2:1;
            uint8_t OBU_TR_SP_Height1_Bit3:1;
            uint8_t OBU_TR_SP_Left2:1;//byte 5
            uint8_t OBU_TR_SP_Right2:1;
            uint8_t bit26:1;
            uint8_t bit27:1;
            uint8_t OBU_TR_SP_Height2_Bit0:1;
            uint8_t OBU_TR_SP_Height2_Bit1:1;
            uint8_t OBU_TR_SP_Height2_Bit2:1;
            uint8_t OBU_TR_SP_Height2_Bit3:1;
            uint8_t OBU_TR_SP_Left3:1;//byte 6
            uint8_t OBU_TR_SP_Right3:1;
            uint8_t bit34:1;
            uint8_t bit35:1;
            uint8_t OBU_TR_SP_Height3_Bit0:1;
            uint8_t OBU_TR_SP_Height3_Bit1:1;
            uint8_t OBU_TR_SP_Height3_Bit2:1;
            uint8_t OBU_TR_SP_Height3_Bit3:1;
            uint8_t OBU_TR_SP_Left4:1;//byte 7
            uint8_t OBU_TR_SP_Right4:1;
            uint8_t bit42:1;
            uint8_t bit43:1;
            uint8_t OBU_TR_SP_Height4_Bit0:1;
            uint8_t OBU_TR_SP_Height4_Bit1:1;
            uint8_t OBU_TR_SP_Height4_Bit2:1;
            uint8_t OBU_TR_SP_Height4_Bit3:1;
            uint8_t OBU_TR_SP_Left5:1;//byte 8
            uint8_t OBU_TR_SP_Right5:1;
            uint8_t bit50:1;
            uint8_t bit51:1;
            uint8_t OBU_TR_SP_Height5_Bit0:1;
            uint8_t OBU_TR_SP_Height5_Bit1:1;
            uint8_t OBU_TR_SP_Height5_Bit2:1;
            uint8_t OBU_TR_SP_Height5_Bit3:1;
            int16_t OBU_TR_SP_D_Entry1;//byte 9
            int16_t OBU_TR_SP_D_Exit1;//byte 11
            int16_t OBU_TR_SP_D_Entry2;//byte 13
            int16_t OBU_TR_SP_D_Exit2;//byte 15
            int16_t OBU_TR_SP_D_Entry3;//byte 17
            int16_t OBU_TR_SP_D_Exit3;//byte 19
            int16_t OBU_TR_SP_D_Entry4;//byte 21
            int16_t OBU_TR_SP_D_Exit4;//byte 23
            int16_t OBU_TR_SP_D_Entry5;//byte 25
            int16_t OBU_TR_SP_D_Exit5;//byte 27
            uint8_t reserved29;//byte 29
            uint8_t reserved30;//byte 30
            uint8_t reserved31;//byte 31
        }bits;
        time_t last_update;
    };
};
/**
 * SKA1
 * OA1_ETCS		0x943
 * OA2_ETCS		0x983
 * SKA2
*/
struct etcs_ccu_mvb3
{
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct
        {
            uint16_t Lifesign;//byte 0
            uint8_t Valid:2;//byte 2
            uint8_t bit2:1;
            uint8_t bit3:1;
            uint8_t bit4:1;
            uint8_t bit5:1;
            uint8_t bit6:1;
            uint8_t bit7:1;
            uint8_t OB_TR_TC_ID1;//byte 3
            uint8_t OB_TR_TC_TYPE1;//byte 4
            int16_t OBU_TR_D_ENTRY1;//byte 5
            int16_t OBU_TR_D_EXIT1;//byte 7
            uint8_t OB_TR_TC_ID2;//byte 9
            uint8_t OB_TR_TC_TYPE2;//byte 10
            int16_t OBU_TR_D_ENTRY2;//byte 11
            int16_t OBU_TR_D_EXIT2;//byte 13
            uint8_t OB_TR_TC_ID3;//byte 15
            uint8_t OB_TR_TC_TYPE3;//byte 16
            int16_t OBU_TR_D_ENTRY3;//byte 17
            int16_t OBU_TR_D_EXIT3;//byte 19
            uint8_t OB_TR_TC_ID4;//byte 21
            uint8_t OB_TR_TC_TYPE4;//byte 22
            int16_t OBU_TR_D_ENTRY4;//byte 23
            int16_t OBU_TR_D_EXIT4;//byte 25
            uint8_t reserved27;//byte 27
            uint8_t reserved28;//byte 28
            uint8_t reserved29;//byte 29
            uint8_t reserved30;//byte 30
            uint8_t reserved31;//byte 31

        }bits;
        time_t last_update;
    };
};
/**
 * SKA1
 * OA1_JRU		0xA41
 * OA2_JRU		0xA81
 * SKA2
*/
struct jru_ccu_mvb1
{
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct
        {
            /*first 2 bytes are equal to lifesign*/
            uint16_t Speed;//byte 2
            uint32_t Milage_today;
            uint32_t Milage_total;
            uint8_t Badge_id_byte1;//byte 12
            uint8_t Badge_id_byte2;//byte 13
            uint8_t Badge_id_byte3;//byte 14
            uint8_t Badge_id_byte4;//byte 15
            uint8_t Badge_id_byte5;//byte 16
            uint8_t Badge_id_byte6;//byte 17
            uint8_t Badge_id_byte7;//byte 18
            uint8_t Memory_fullness;//byte 19
            uint8_t Current_internal_temp;//byte 20
            uint8_t Number_of_active_warnings;//byte 21
            uint8_t Number_of_active_errors;//byte 22
            uint8_t Number_of_active_criticals;//byte 23
            uint8_t Temp_warning:1;//byte 24
            uint8_t SABO_speed_difference:1;
            uint8_t SABO_comp_result_fail:1;
            uint8_t Zero_speed:1;
            uint8_t Emergency_brake:1;
            uint8_t Emergency_reset:1;
            uint8_t bit182:1;
            uint8_t bit183:1;
            uint8_t Code_01:1;//byte 25
            uint8_t Code_02:1;
            uint8_t Code_03:1;
            uint8_t Code_04:1;
            uint8_t Code_05:1;
            uint8_t Code_06:1;
            uint8_t Code_07:1;
            uint8_t Code_08:1;
            uint8_t Code_09:1;//byte 26
            uint8_t Code_10:1;
            uint8_t Code_11:1;
            uint8_t Code_12:1;
            uint8_t Code_13:1;
            uint8_t Code_14:1;
            uint8_t Code_15:1;
            uint8_t Code_16:1;
            uint8_t Code_17:1;//byte 27
            uint8_t Code_18:1;
            uint8_t Code_19:1;
            uint8_t Code_20:1;
            uint8_t Code_21:1;
            uint8_t Code_22:1;
            uint8_t Code_23:1;
            uint8_t Code_24:1;
            uint8_t Code_25:1;//byte 28
            uint8_t Code_26:1;
            uint8_t Code_27:1;
            uint8_t Code_28:1;
            uint8_t Code_29:1;
            uint8_t Code_30:1;
            uint8_t Code_32:1;
            uint8_t Code_33:1;
            uint8_t Code_34:1;//byte 29
            uint8_t Code_35:1;
            uint8_t bit218:1;
            uint8_t bit219:1;
            uint8_t bit220:1;
            uint8_t bit221:1;
            uint8_t bit222:1;
            uint8_t bit223:1;
            uint8_t Code_100:1;//byte 30
            uint8_t Code_101:1;
            uint8_t Code_102:1;
            uint8_t Code_103:1;
            uint8_t Code_104:1;
            uint8_t Code_105:1;
            uint8_t Code_106:1;
            uint8_t Code_107:1;
            uint8_t Code_108:1;//byte 31
            uint8_t Code_109:1;
            uint8_t Code_110:1;
            uint8_t bit227:1;
            uint8_t bit228:1;
            uint8_t bit229:1;
            uint8_t bit230:1;
            uint8_t bit231:1;

        }bits;
        time_t last_update;
    };
};

struct oax_jru_id {
    union {
        uint8_t bytes[IO_RAW_NBYTES_16];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_16)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_16)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_16)];

        struct {
            uint8_t badge_id_byte_local_1;
            uint8_t badge_id_byte_local_2;
            uint8_t badge_id_byte_local_3;
            uint8_t badge_id_byte_local_4;
            uint8_t badge_id_byte_local_5;
            uint8_t badge_id_byte_local_6;
            uint8_t badge_id_byte_local_7;
            uint8_t badge_id_byte_local_8;

        } bits;
        time_t last_update;
    };
};


/**
 * SKA1
 * OA1		0x841
 * OA2 		0x881
 * SKA2
 * v1.02
*/
struct apu_ccu_mvb1 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_16];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_16)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_16)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_16)];

        struct {
            uint16_t Lifesign; //byte 0
            uint8_t APUC_App_State : 2; //byte2
            uint8_t Door_Open : 1;
            uint8_t Mode_Select : 1;
            uint8_t APU_Emergency : 1;
            uint8_t APU_Start_Status : 1;
            uint8_t Reset_Ack : 1;
            uint8_t bit23 : 1;
            uint8_t APS_Ok : 1; //byte3
            uint8_t MV_Output_Ok : 1;
            uint8_t HV_Presence : 1;
            uint8_t APS_Out_Con_Loop_out : 1;
            uint8_t LV_Output_Ok : 1;
            uint8_t bit29 : 1;
            uint8_t bit30 : 1;
            uint8_t bit31 : 1;
            uint8_t reserved_4 ; //byte 4
            uint8_t SW_Ver ; //byte5
            uint16_t Catenary_Voltage ; //byte6
            uint8_t Fault_Code_APUC ; //byte8
            uint8_t Fault_Code_PFC1 ; //byte9
            uint8_t Fault_Code_PFC2 ; //byte10
            uint8_t Fault_Code_VSI1 ; //byte11
            uint8_t Fault_Code_VSI2 ; //byte12
            uint8_t Fault_Code_BCH ;  //byte13
            uint8_t reserved_14 ;
            uint8_t reserved_15 ;
        } bits;
        time_t last_update;
    };
};

/**
 * SKA1
 * OA1		0x842
 * OA2 		0x882
 * SKA2
 * v1.02
*/
struct apu_ccu_mvb2 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint16_t Lifesign ; //byte0
            uint8_t PFC1_App_State : 2; //byte2
            uint8_t PFC2_App_State : 2;
            uint8_t VSI1_App_State : 2;
            uint8_t VSI2_App_State : 2;
            uint8_t BCH_App_State : 2; //byte3
            uint8_t bit26 : 1;
            uint8_t bit27 : 1;
            uint8_t bit28 : 1;
            uint8_t bit29 : 1;
            uint8_t bit30 : 1;
            uint8_t bit31 : 1;
            uint8_t PFC_A_CAN : 1; //byte4
            uint8_t PFC_B_CAN : 1;
            uint8_t VSI_A_CAN : 1;
            uint8_t VSI_B_CAN : 1;
            uint8_t BCH_CAN : 1;
            uint8_t bit37 : 1;
            uint8_t bit38 : 1;
            uint8_t bit39 : 1;
            uint8_t reserved_5 ; //byte5
            int16_t PFC1_Vs ; //byte6
            int16_t PFC1_Is ; //byte8
            int16_t PFC1_Fs ; //byte10
            int16_t PFC1_Vo ; //byte12
            int8_t PFC1_Temp1 ; //byte14
            int8_t PFC1_Temp2 ; //byte15
            uint8_t reserved_16 ;
            int16_t PFC2_Vs ; //byte17
            int16_t PFC2_Is ; //byte19
            int16_t PFC2_Fs ; //byte21
            int16_t PFC2_Vo ; //byte23
            int8_t PFC2_Temp1 ; //byte25
            int8_t PFC2_Temp2 ; //byte26
            uint8_t reserved_27 ;
            uint8_t reserved_28 ;
            uint8_t reserved_29 ;
            uint8_t reserved_30 ;
            uint8_t reserved_31 ;

        } bits;
        time_t last_update;
    };
};
/**
 * SKA1
 * OA1		0x843
 * OA2 		0x883
 * SKA2
 * v1.02
*/
struct apu_ccu_mvb3 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint16_t Lifesign ; //byte0
            int16_t VSI1_Vs ; //byte2
            int16_t VSI1_Vo ; //byte4
            int16_t VSI1_Io ; //byte6
            int16_t VSI1_Fo ; //byte8
            int8_t VSI1_Temp1 ; //byte10
            int8_t VSI1_Temp2 ; //byte11
            int8_t reserved_12 ;
            int16_t VSI2_Vs ; //byte13
            int16_t VSI2_Vo ; //byte15
            int16_t VSI2_Io ; //byte17
            int16_t VSI2_Fo ; //byte19
            int8_t VSI2_Temp1 ; //byte21
            int8_t VSI2_Temp2 ; //byte22
            int8_t reserved_23 ;
            int8_t BCH_Vs ; //byte24
            int8_t BCH_Vo ; //byte26
            int8_t BCH_Io ; //byte28
            int8_t BCH_Temp1 ; //byte30
            int8_t BCH_Temp2 ; //byte31


        } bits;
        time_t last_update;
    };
};


/*************************CCU OUT DATA*****************************************/
typedef struct
{
    uint32_t seconds;
    uint16_t ticks;
} ccu_time_t;
/*CCU GLOBAL OUT DATA*/
/**
 *  GLOBAL PORT NO: 0x101
*/

struct ska_ccu_global_out_mvb1 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_16];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_16)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_16)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_16)];

        struct {
            uint16_t Lifesign; //byte0
            uint8_t reserved_1; //byte 2
            uint8_t reserved_2; //byte 3
            ccu_time_t ccu_time;  //created forActualTime  //byte4
            uint8_t S_Coupling : 2; //byte 10
            uint8_t S_Lead_Follow_consist : 2;
            uint8_t S_CAB_Active : 2;
            uint8_t S_Direction : 2;
            uint8_t CouplingStatus : 2; //byte 11
            uint8_t _1stTrainSetConfiguration : 3;
            uint8_t _2ndTrainSetConfiguration : 3;
            uint8_t reserved_12; //byte 12
            uint8_t reserved_13; //byte 13
            uint8_t reserved_14; //byte 14
            uint8_t reserved_15; //byte 15

        } bits;
        time_t last_update;
    };
};


/**
 *  GLOBAL PORT NO: 0x102
*/
struct ska_ccu_global_out_mvb2 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_16];
        int8_t signed_bytes[IO_RAW_NBYTES_16];
        int32_t signed_dwords[BYTES_TO_WORDS(IO_RAW_NBYTES_16)];

        struct {
            /*first two bytes are equal to lifesign*/
            uint16_t lifesign;
            int32_t GPS_latitude_masterTCMS; //byte 2
            int32_t GPS_longtitude_masterTCMS; //byte 6
            int8_t Outside_air_temperature; //byte 10
            uint8_t Train_speed; //byte 11
            uint8_t reserved_12;
            uint8_t reserved_13;
            uint8_t reserved_14;
            uint8_t reserved_15;
        } bits;
        time_t last_update;
    };
};

/**
 *  GLOBAL PORT NO: 0x103
*/
struct ska_ccu_global_out_mvb3 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_16];
        int8_t signed_bytes[IO_RAW_NBYTES_16];
        int32_t signed_dwords[BYTES_TO_WORDS(IO_RAW_NBYTES_16)];

        struct {
            uint16_t lifesign;//byte 0
            uint8_t  Current_badge_id_byte1;// byte 2
            uint8_t  Current_badge_id_byte2;// byte 3
            uint8_t  Current_badge_id_byte3;// byte 4
            uint8_t  Current_badge_id_byte4;// byte 5
            uint8_t  Current_badge_id_byte5;// byte 6
            uint8_t  Current_badge_id_byte6;// byte 7
            uint8_t  Current_badge_id_byte7;// byte 8
            uint8_t  Login_status :1; // byte 9
            uint8_t  HMI_logout: 1;
            uint8_t  SecondaryID_read :1;
            uint8_t  Park_mode_on: 1;
            uint8_t  bit76 :1;
            uint8_t  bit77 :1;
            uint8_t  bit78 :1;
            uint8_t  bit79 :1;
            uint8_t  reserved10;//byte 10
            uint8_t  reserved11;//byte 11
            uint8_t  reserved12;//byte 12
            uint8_t  reserved13;//byte 13
            uint8_t  reserved14;//byte 14
            uint8_t  reserved15;//byte 15

        } bits;
        time_t last_update;
    };
};


/**
 *   PORT NO: 0x111
*/
struct ska_ccu_to_all_rioms_mvb1 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint8_t Lifesign ; //byte0
            uint32_t Timestamp_Time ; //byte2
            uint16_t Timestamp_Date ; //byte6
            int32_t GPS_latitude_masterTCMS ; //byte8
            int32_t GPS_longtitude_masterTCMS ; //byte12
            uint8_t Coupling : 2; //byte16
            uint8_t Lead_follow : 2;
            uint8_t Cabin_active : 2;
            uint8_t Direction : 2;
            uint8_t Zero_speed : 1; //byte17
            uint8_t Doors_enabled_left_side : 1;
            uint8_t Doors_enabled_right_side : 1;
            uint8_t Doors_open_left_side : 1;
            uint8_t Doors_open_right_side : 1;
            uint8_t OA1_PantoUp : 1;
            uint8_t OA2_PantoUp : 1;
            uint8_t Parking_mode : 1;
            uint8_t Train_Speed ; //byte18
            uint8_t reserved_19 ;
            int8_t Outside_Temp ; //byte20
            int8_t Inside_Temp ; //byte21
            uint8_t reserved_22 ;
            uint8_t SKA1_DCU1_EEDOp : 1; //byte23
            uint8_t SKA1_DCU2_EEDOp : 1;
            uint8_t SKA1_DCU3_EEDOp : 1;
            uint8_t SKA1_DCU4_EEDOp : 1;
            uint8_t SKA1_DCU5_EEDOp : 1;
            uint8_t SKA1_DCU6_EEDOp : 1;
            uint8_t SKA1_DCU7_EEDOp : 1;
            uint8_t SKA1_DCU8_EEDOp : 1;
            uint8_t OA1_DCU1_EEDOp : 1; //byte24
            uint8_t OA1_DCU2_EEDOp : 1;
            uint8_t OA1_DCU3_EEDOp : 1;
            uint8_t OA1_DCU4_EEDOp : 1;
            uint8_t OA1_DCU5_EEDOp : 1;
            uint8_t OA1_DCU6_EEDOp : 1;
            uint8_t OA1_DCU7_EEDOp : 1;
            uint8_t OA1_DCU8_EEDOp : 1;
            uint8_t OA2_DCU1_EEDOp : 1; //byte25
            uint8_t OA2_DCU2_EEDOp : 1;
            uint8_t OA2_DCU3_EEDOp : 1;
            uint8_t OA2_DCU4_EEDOp : 1;
            uint8_t OA2_DCU5_EEDOp : 1;
            uint8_t OA2_DCU6_EEDOp : 1;
            uint8_t OA2_DCU7_EEDOp : 1;
            uint8_t OA2_DCU8_EEDOp : 1;
            uint8_t SKA2_DCU1_EEDOp : 1; //byte26
            uint8_t SKA2_DCU2_EEDOp : 1;
            uint8_t SKA2_DCU3_EEDOp : 1;
            uint8_t SKA2_DCU4_EEDOp : 1;
            uint8_t SKA2_DCU5_EEDOp : 1;
            uint8_t SKA2_DCU6_EEDOp : 1;
            uint8_t SKA2_DCU7_EEDOp : 1;
            uint8_t SKA2_DCU8_EEDOp : 1;
            uint8_t SKA1_Brake_Handle_1 : 1; //byte27
            uint8_t SKA1_Brake_Handle_2 : 1;
            uint8_t SKA1_Brake_Handle_3 : 1;
            uint8_t SKA1_Brake_Handle_4 : 1;
            uint8_t SKA1_Brake_Handle_5 : 1;
            uint8_t SKA1_Brake_Handle_6 : 1;
            uint8_t SKA1_Brake_Handle_7 : 1;
            uint8_t SKA1_Brake_Handle_8 : 1;
            uint8_t OA1_Brake_Handle_1 : 1; //byte28
            uint8_t OA1_Brake_Handle_2 : 1;
            uint8_t OA1_Brake_Handle_3 : 1;
            uint8_t OA1_Brake_Handle_4 : 1;
            uint8_t OA1_Brake_Handle_5 : 1;
            uint8_t OA1_Brake_Handle_6 : 1;
            uint8_t OA1_Brake_Handle_7 : 1;
            uint8_t OA1_Brake_Handle_8 : 1;
            uint8_t OA2_Brake_Handle_1 : 1; //byte29
            uint8_t OA2_Brake_Handle_2 : 1;
            uint8_t OA2_Brake_Handle_3 : 1;
            uint8_t OA2_Brake_Handle_4 : 1;
            uint8_t OA2_Brake_Handle_5 : 1;
            uint8_t OA2_Brake_Handle_6 : 1;
            uint8_t OA2_Brake_Handle_7 : 1;
            uint8_t OA2_Brake_Handle_8 : 1;
            uint8_t SKA2_Brake_Handle_1 : 1; //byte30
            uint8_t SKA2_Brake_Handle_2 : 1;
            uint8_t SKA2_Brake_Handle_3 : 1;
            uint8_t SKA2_Brake_Handle_4 : 1;
            uint8_t SKA2_Brake_Handle_5 : 1;
            uint8_t SKA2_Brake_Handle_6 : 1;
            uint8_t SKA2_Brake_Handle_7 : 1;
            uint8_t SKA2_Brake_Handle_8 : 1;
            uint8_t reserved_31 : 1;

        } bits;
        time_t last_update;
    };
};

/**
 *   PORT NO: 0x112
*/
struct ska_ccu_to_all_rioms_mvb2 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_16];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_16)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_16)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_16)];

        struct {
            uint8_t DriverID_Byte1 ; //byte0
            uint8_t DriverID_Byte2 ; //byte1
            uint8_t DriverID_Byte3 ; //byte2
            uint8_t DriverID_Byte4 ; //byte3
            uint8_t DriverID_Byte5 ; //byte4
            uint8_t DriverID_Byte6 ; //byte5
            uint8_t DriverID_Byte7 ; //byte6
            uint8_t reserved_7 ;
            uint8_t TrainID_Byte1 ;  //byte8
            uint8_t TrainID_Byte2 ;  //byte9
            uint8_t TrainID_Byte3 ;  //byte10
            uint8_t TrainID_Byte4 ;  //byte11
            uint8_t TrainID_Byte5 ;  //byte12
            uint8_t TrainID_Byte6 ;  //byte13
            uint8_t TrainID_Byte7 ;  //byte14
            uint8_t TrainID_Byte8 ;  //byte15
            uint8_t TrainID_Byte9 ;  //byte16
            uint8_t TrainID_Byte10 ; //byte17
            uint8_t TrainID_Byte11 ; //byte18
            uint8_t TrainID_Byte12 ; //byte19
            uint8_t reserved_20 ;
            uint32_t Distance_in_pulse ; //byte21
            uint8_t reserved_25 ;
            uint8_t TCMS_TLCentrClose : 1 ; //byte26
            uint8_t TCMS_TLStandstill : 1;
            uint8_t TCMS_TLCentrOpen : 1;
            uint8_t TCMS_TLSuppEmergOp : 1;
            uint8_t TCMS_TIL : 1;
            uint8_t TCMS_LoopLSDoorNotEmergOp : 1;
            uint8_t bit214 ;
            uint8_t bit215 ;
            uint8_t reserved_27 ;
            int8_t HVAC_Offset ; //byte28
            uint8_t reserved_29 ;
            uint8_t reserved_30 ;
            uint8_t reserved_31 ;

        } bits;
        time_t last_update;
    };
};
/*CCU to RIOM DATA*/

/**
 * SKA1_DD	0x011
 * OA1	-
 * OA2	-
 * SKA2_DD	0x021
*/

struct ska_ccu_dd_riom_mvb1_d_outputs {
    union {
        uint8_t bytes[IO_RAW_NBYTES_8];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_8)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_8)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_8)];

        struct {
            uint8_t bit0 : 1; //byte 0
            uint8_t bit1 : 1;
            uint8_t MODE_PARKING_ON : 1;
            uint8_t SIGNALING_AIR_SUSPENSION_FAILURE : 1;
            uint8_t bit4 : 1;
            uint8_t bit5 : 1;
            uint8_t bit6 : 1;
            uint8_t CONTROL_DESK_TEST_HW_HEALT_RIOM_1 : 1;
            uint8_t bit8 : 1; //byte 1
            uint8_t WFL_SPRAY_ENABLE : 1;
            uint8_t WFL_DIRECTION : 1;
            uint8_t EMERGENCY_EGRESS_DEVICE_OUTPUT : 1;
            uint8_t BY_PASS_HATCH_UNLOCK : 1;
            uint8_t HATCH_UNLOCK : 1;
            uint8_t COMMAND_OPENING_HATCH : 1;
            uint8_t COMMAND_CLOSING_HATCH : 1;
            uint8_t WIPER_MIDDLE_POSITION_REQUEST : 1; //byte 2
            uint8_t DIMMED_HEAD_LIGHT_LEFT_CENTRAL : 1;
            uint8_t TAIL_RED_LIGHT_LEFT : 1;
            uint8_t DIMMED_HEAD_LIGHT_RIGHT_CENTRAL : 1;
            uint8_t bit20 : 1;
            uint8_t bit21 : 1;
            uint8_t bit22 : 1;
            uint8_t bit23 : 1;
            uint8_t TAIL_RED_LIGHT_RIGHT : 1; //byte 3
            uint8_t DIMMED_MARKER_LIGHT_LEFT_RIGHT_CENTRAL : 1;
            uint8_t FULL_MARKER_LIGHT_LEFT_RIGHT_CENTRAL : 1;
            uint8_t FULL_HEAD_LIGHT_LEFT_RIGHT_CENTRAL : 1;
            uint8_t bit28 : 1;
            uint8_t bit29 : 1;
            uint8_t bit30 : 1;
            uint8_t bit31 : 1;
            uint8_t reserved4 ; //byte 4
            uint8_t reserved5 ; //byte 5
            uint8_t reserved6 ; //byte 6
            uint8_t reserved7 ; //byte 7

        } bits;
        time_t last_update;
    };
};

/**
 * SKA1_VH	0x031
 * OA1	-
 * OA2	-
 * SKA2_VH	0x091
 * v1.09
*/

struct ska_ccu_vh_riom_mvb1_d_outputs {
    union {
        uint8_t bytes[IO_RAW_NBYTES_8];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_8)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_8)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_8)];

        struct {
            uint8_t CONTACTOR_MAINTENANCE_COMMAND : 1; //byte 0
            uint8_t ENABLE_TC_1 : 1;
            uint8_t ENABLE_TC_2 : 1;
            uint8_t IDRELAY_1 : 1;
            uint8_t IDRELAY_2 : 1;
            uint8_t bit5 : 1;
            uint8_t bit6 : 1;
            uint8_t CABINET_TEST_HW_HEALT_RIOM_1 : 1;
            uint8_t NORMAL_RESCUE_MODE : 1; //byte 1
            uint8_t SPEED_LIMIT : 1;
            uint8_t TRACTION_NULL : 1;
            uint8_t bit11 : 1;
            uint8_t bit12 : 1;
            uint8_t bit13 : 1;
            uint8_t bit14 : 1;
            uint8_t bit15 : 1;
            uint8_t CAB_MODE : 1; //byte 2
            uint8_t HVAC_1_ON_OFF : 1;
            uint8_t HVAC_1_FAILURE : 1;
            uint8_t bit19 : 1;
            uint8_t bit20 : 1;
            uint8_t bit21 : 1;
            uint8_t bit22 : 1;
            uint8_t bit23 : 1;
            uint8_t HVAC_2_ON_OFF : 1; //byte 3
            uint8_t HVAC_2_FAILURE : 1;
            uint8_t TL_HB_C_RELEASE : 1;
            uint8_t bit27 : 1;
            uint8_t bit28 : 1;
            uint8_t bit29 : 1;
            uint8_t bit30 : 1;
            uint8_t bit31 : 1;
            uint8_t MRP_ISOLATION_COMMAND : 1; //byte 4
            uint8_t PASSENGERS_ALARM_OUT_OF_SERVICE : 1;
            uint8_t HEATING_CARTRIGE_HEATER : 1;
            uint8_t bit35 : 1;
            uint8_t bit36 : 1;
            uint8_t bit37 : 1;
            uint8_t bit38 : 1;
            uint8_t bit39 : 1;
            uint8_t HEATING_SAND_TUBE : 1; //byte 5
            uint8_t TEST_SAND_LEVELS_SENSORS_BOGIE_1 : 1;
            uint8_t TEST_SAND_LEVELS_SENSORS_BOGIE_2 : 1;
            uint8_t bit43 : 1;
            uint8_t bit44 : 1;
            uint8_t bit45 : 1;
            uint8_t bit46 : 1;
            uint8_t bit47 : 1;
            uint8_t LIGHT_OFF_COMMAND : 1; //byte 6
            uint8_t LIGHT_COMMAND_FULL_LIGHT : 1;
            uint8_t HALF_LIGHT_COMMAND : 1;
            uint8_t EMERGENCY_LIGHT_COMMAND : 1;
            uint8_t bit52 : 1;
            uint8_t bit53 : 1;
            uint8_t bit54 : 1;
            uint8_t bit55 : 1;
            uint8_t reserved_7; //byte 7
        } bits;
        time_t last_update;
    };
};

/**
 * SKA1_VH	0x032
 * OA1	-
 * OA2	-
 * SKA2_VH	0x092
 * v1.09
*/

struct ska_ccu_vh_riom_mvb2_dcu_hvac {
    union {
        uint8_t bytes[IO_RAW_NBYTES_16];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_16)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_16)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_16)];

        struct {
            uint8_t R1_TCMS_EEDreset : 1; //byte0
            uint8_t R1_TCMS_TLRelease : 1;
            uint8_t R1_TCMS_LoopLSDoorNotEmergOp : 1;
            uint8_t R1_TCMS_DoorFullyOpen : 1;
            uint8_t R2_TCMS_EEDreset : 1;
            uint8_t R2_TCMS_TLRelease : 1;
            uint8_t R2_TCMS_LoopLSDoorNotEmergOp : 1;
            uint8_t R2_TCMS_DoorFullyOpen : 1;
            uint8_t R3_TCMS_EEDreset : 1; //byte1
            uint8_t R3_TCMS_TLRelease : 1;
            uint8_t R3_TCMS_LoopLSDoorNotEmergOp : 1;
            uint8_t R3_TCMS_DoorFullyOpen : 1;
            uint8_t R4_TCMS_EEDreset : 1;
            uint8_t R4_TCMS_TLRelease : 1;
            uint8_t R4_TCMS_LoopLSDoorNotEmergOp : 1;
            uint8_t R4_TCMS_DoorFullyOpen : 1;
            uint8_t L1_TCMS_EEDreset : 1; //byte2
            uint8_t L1_TCMS_TLRelease : 1;
            uint8_t L1_TCMS_LoopLSDoorNotEmergOp : 1;
            uint8_t L1_TCMS_DoorFullyOpen : 1;
            uint8_t L2_TCMS_EEDreset : 1;
            uint8_t L2_TCMS_TLRelease : 1;
            uint8_t L2_TCMS_LoopLSDoorNotEmergOp : 1;
            uint8_t L2_TCMS_DoorFullyOpen : 1;
            uint8_t L3_TCMS_EEDreset : 1; //byte3
            uint8_t L3_TCMS_TLRelease : 1;
            uint8_t L3_TCMS_LoopLSDoorNotEmergOp : 1;
            uint8_t L3_TCMS_DoorFullyOpen : 1;
            uint8_t L4_TCMS_EEDreset : 1;
            uint8_t L4_TCMS_TLRelease : 1;
            uint8_t L4_TCMS_LoopLSDoorNotEmergOp : 1;
            uint8_t L4_TCMS_DoorFullyOpen : 1;
            uint8_t reserved_4 : 1;
            uint8_t reserved_5 : 1;
            uint8_t bit48 : 1;
            uint8_t HVACC_Reduce_Mode : 1;
            uint8_t bit50 : 1;
            uint8_t HVACC_Cabin_Active : 1;
            uint8_t HVACC_Automatic_Dumper_Switch : 1;
            uint8_t HVACC_Close_Dumper : 1;
            uint8_t bit54 : 1;
            uint8_t bit55 : 1;
            uint8_t HVAC1_HVAC_On : 1; //byte 7
            uint8_t HVAC1_Reduce_Mode : 1;
            uint8_t HVAC1_Door_Open : 1;
            uint8_t bit59 : 1;
            uint8_t HVAC1_Automatic_Dumper_Switch : 1;
            uint8_t HVAC1_Close_Dumper : 1;
            uint8_t bit62 : 1;
            uint8_t bit63 : 1;
            uint8_t HVAC2_HVAC_On : 1; //byte8
            uint8_t HVAC2_Reduce_Mode : 1;
            uint8_t HVAC2_Door_Open : 1;
            uint8_t bit67 : 1;
            uint8_t HVAC2_Automatic_Dumper_Switch : 1;
            uint8_t HVAC2_Close_Dumper : 1;
            uint8_t bit70 : 1;
            uint8_t bit71 : 1;
            uint8_t reserved_9 : 1;
            uint8_t reserved_10 : 1;
            uint8_t reserved_11 : 1;
            uint8_t C_RstFduX : 1; //byte12
            uint8_t bit97 : 1;
            uint8_t C_Resound : 1;
            uint8_t bit99 : 1;
            uint8_t bit100 : 1;
            uint8_t bit101 : 1;
            uint8_t bit102 : 1;
            uint8_t bit103 : 1;
            uint8_t reserved_13 : 1;
            uint8_t reserved_14 : 1;
            uint8_t reserved_15 : 1;

        } bits;
        time_t last_update;
    };
};


/**
 * SKA1	-
 * OA1	0x051
 * OA2	0x071
 * SKA2	-
 * v1.09
*/

struct oa_ccu_vh_riom_mvb1_d_outputs {
    union {
        uint8_t bytes[IO_RAW_NBYTES_8];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_8)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_8)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_8)];

        struct {
            uint8_t COMMAND_CONTACTOR_PRIVILEGED_LOAD_Lp : 1; //byte 0
            uint8_t TCMS_IN_RUN : 1;
            uint8_t INIBHIT_APS : 1;
            uint8_t DEGRADE_MODE_MV_OA_CARS : 1;
            uint8_t bit4 : 1;
            uint8_t bit5 : 1;
            uint8_t bit6 : 1;
            uint8_t CABINET_TEST_HW_HEALT_RIOM_1 : 1;
            uint8_t VCB_CLOSING_COMMAND_1 : 1; //byte 1
            uint8_t VCB_CLOSING_COMMAND_2 : 1;
            uint8_t VCB_OPENING_COMMAND : 1;
            uint8_t OPENING_HV_DISCONNECTOR : 1;
            uint8_t bit12 : 1;
            uint8_t bit13 : 1;
            uint8_t bit14 : 1;
            uint8_t bit15 : 1;
            uint8_t CLOSING_HV_DISCONNECTOR : 1; //byte 2
            uint8_t PANTOGRAPH_COMMAND_MOTOR_COMPRESSOR_OUTPUT : 1;
            uint8_t PANTOGRAPH_COMMAND_RAISING_VALVE : 1;
            uint8_t ADD_LOOP_CONTROL : 1;
            uint8_t bit20 : 1;
            uint8_t bit21 : 1;
            uint8_t bit22 : 1;
            uint8_t bit23 : 1;
            uint8_t TRAFO_CONTROL_VOLTAGE_LOW_SPEED : 1; //byte 3
            uint8_t TRAFO_CONTROL_VOLTAGE_FULL_SPEED : 1;
            uint8_t HVAC_1_ON_OFF : 1;
            uint8_t HVAC_1_FAILURE : 1;
            uint8_t bit28 : 1;
            uint8_t bit29 : 1;
            uint8_t bit30 : 1;
            uint8_t bit31 : 1;
            uint8_t HVAC_2_ON_OFF : 1; //byte 4
            uint8_t HVAC_2_FAILURE : 1;
            uint8_t MOTOR_COMPRESSOR : 1;
            uint8_t bit35 : 1;
            uint8_t bit36 : 1;
            uint8_t bit37 : 1;
            uint8_t bit38 : 1;
            uint8_t bit39 : 1;
            uint8_t START_COMPRESSOR : 1; //byte 5
            uint8_t TL_HB_C_RELEASE : 1;
            uint8_t TRAIN_IN_MOVING_TO_ACTIVE_SKA_FRONT_DIRECTION : 1;
            uint8_t SLEEPING_SIGNAL_ETCS : 1;
            uint8_t TRACTION_BRAKE_HANDLE_TRACTION_SIGNAL_ETCS : 1;
            uint8_t TRACTION_BRAKE_HANDLE_BRAKE_SIGNAL_ETCS : 1;
            uint8_t NON_LEADING_SIGNAL_ETCS : 1;
            uint8_t TRAIN_INTEGRITY_SIGNAL_ETCS : 1;
            uint8_t TRAIN_IN_MOVING_TO_OPPOSITE_ACTIVE_SKA_DIRECTION : 1; //byte 6
            uint8_t BRAKE_DEMAND_FROM_ACTIVE_CABIN : 1;
            uint8_t TRACTION_DEMAND_FROM_ACTIVE_CABIN : 1;
            uint8_t CAB_ACTIVATION_SIGNAL : 1;
            uint8_t bit52 : 1;
            uint8_t bit53 : 1;
            uint8_t bit54 : 1;
            uint8_t bit55 : 1;
            uint8_t reserved_7 ; //byte 7

        }bits;
        time_t last_update;
    };
};

/**
 * SKA1	-
 * OA1	0x052
 * OA2	0x072
 * SKA2	-
 * V1.09
*/

struct oa_ccu_vh_riom_mvb2_dcu_hvac {
    union {
        uint8_t bytes[IO_RAW_NBYTES_16];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_16)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_16)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_16)];

        struct {
            uint8_t R1_TCMS_EEDreset : 1; //byte 0
            uint8_t R1_TCMS_TLRelease : 1;
            uint8_t R1_TCMS_LoopLSDoorNotEmergOp : 1;
            uint8_t R1_TCMS_DoorFullyOpen : 1;
            uint8_t R2_TCMS_EEDreset : 1;
            uint8_t R2_TCMS_TLRelease : 1;
            uint8_t R2_TCMS_LoopLSDoorNotEmergOp : 1;
            uint8_t R2_TCMS_DoorFullyOpen : 1;
            uint8_t R3_TCMS_EEDreset : 1; //byte1
            uint8_t R3_TCMS_TLRelease : 1;
            uint8_t R3_TCMS_LoopLSDoorNotEmergOp : 1;
            uint8_t R3_TCMS_DoorFullyOpen : 1;
            uint8_t R4_TCMS_EEDreset : 1;
            uint8_t R4_TCMS_TLRelease : 1;
            uint8_t R4_TCMS_LoopLSDoorNotEmergOp : 1;
            uint8_t R4_TCMS_DoorFullyOpen : 1;
            uint8_t L1_TCMS_EEDreset : 1; //byte 2
            uint8_t L1_TCMS_TLRelease : 1;
            uint8_t L1_TCMS_LoopLSDoorNotEmergOp : 1;
            uint8_t L1_TCMS_DoorFullyOpen : 1;
            uint8_t L2_TCMS_EEDreset : 1;
            uint8_t L2_TCMS_TLRelease : 1;
            uint8_t L2_TCMS_LoopLSDoorNotEmergOp : 1;
            uint8_t L2_TCMS_DoorFullyOpen : 1;
            uint8_t L3_TCMS_EEDreset : 1; //byte 3
            uint8_t L3_TCMS_TLRelease : 1;
            uint8_t L3_TCMS_LoopLSDoorNotEmergOp : 1;
            uint8_t L3_TCMS_DoorFullyOpen : 1;
            uint8_t L4_TCMS_EEDreset : 1;
            uint8_t L4_TCMS_TLRelease : 1;
            uint8_t L4_TCMS_LoopLSDoorNotEmergOp : 1;
            uint8_t L4_TCMS_DoorFullyOpen : 1;
            uint8_t reserved_4 ;
            uint8_t reserved_5 ;
            uint8_t reserved_6 ;
            uint8_t HVAC1_HVAC_On : 1;
            uint8_t HVAC1_Reduce_Mode : 1;
            uint8_t HVAC1_Door_Open : 1;
            uint8_t bit59 : 1;
            uint8_t HVAC1_Automatic_Dumper_Switch : 1;
            uint8_t HVAC1_Close_Dumper : 1;
            uint8_t bit62 : 1;
            uint8_t bit63 : 1;
            uint8_t HVAC2_HVAC_On : 1; //byte 8
            uint8_t HVAC2_Reduce_Mode : 1;
            uint8_t HVAC2_Door_Open : 1;
            uint8_t bit67 : 1;
            uint8_t HVAC2_Automatic_Dumper_Switch : 1;
            uint8_t HVAC2_Close_Dumper : 1;
            uint8_t bit70 : 1;
            uint8_t bit71 : 1;
            uint8_t reserved_9 : 1;
            uint8_t reserved_10 : 1;
            uint8_t reserved_11 : 1;
            uint8_t reserved_12 : 1;
            uint8_t reserved_13 : 1;
            uint8_t reserved_14 : 1;
            uint8_t reserved_15 : 1;


        } bits;
        time_t last_update;
    };
};

/**
 * CCU to ALL BCU
 * 0x161
*/
struct ccu_to_all_bcus {
    union {
        uint8_t bytes[IO_RAW_NBYTES_16];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_16)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_16)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_16)];

        struct {
            uint16_t XLifeSign ; //byte0
            uint8_t ReleaseHoldingBrakeRequest : 1; //byte2
            uint8_t bit17 : 1;
            uint8_t bit18 : 1;
            uint8_t C_WSP_start_testrun : 1;
            uint8_t bit20 : 1;
            uint8_t C_ASC_active : 1;
            uint8_t C_CalcMass : 1;
            uint8_t bit23 : 1;
            uint8_t C_Sanding_activated : 1; //byte3
            uint8_t C_Sanding_Request_Short : 1;
            uint8_t C_Sanding_Request_Long : 1;
            uint8_t C_Sanding_Test : 1;
            uint8_t C_Sanding_drying_on : 1;
            uint8_t bit29 : 1;
            uint8_t bit30 : 1;
            uint8_t bit31 : 1;
            uint8_t TL_EBLoop_R_Closed : 1; //byte4
            uint8_t bit33: 1;
            uint8_t TL_Braking_Bit1 : 1;
            uint8_t TL_Braking_Bit2 : 1;
            uint8_t TL_Braking_Bit3 : 1;
            uint8_t TL_Traction : 1;
            uint8_t bit38 : 1;
            uint8_t bit39 : 1;
            uint8_t reserved_5; //byte5
            uint8_t S_PB_EmerRel_Conf_SKA1 : 1; //byte6
            uint8_t S_PB_EmerRel_Conf_SKA2 : 1;
            uint8_t S_PB_EmerRel_Conf_OA1 : 1;
            uint8_t S_PB_EmerRel_Conf_OA2 : 1;
            uint8_t bit52 : 1;
            uint8_t bit53 : 1;
            uint8_t bit54 : 1;
            uint8_t bit55 : 1;
            uint16_t C_ASC_Brake_demand_SKA1 ; //byte7
            uint16_t C_ASC_Brake_demand_OA1 ; //byte9
            uint16_t C_ASC_Brake_demand_OA2 ; //byte11
            uint16_t C_ASC_Brake_demand_SKA2 ; //byte13
            uint8_t reserved_15 ; //byte15

        } bits;
        time_t last_update;
    };
};

/**
 * CCU to ETCS
 * OA1 0x191
 * OA2 0x192
 *
 * */
struct ccu_to_oax_etcs {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint16_t Lifesign ;//byte 0
            uint8_t bit0 : 1;//byte 2
            uint8_t bit1 : 1;
            uint8_t bit2 : 1;
            uint8_t bit3 : 1;
            uint8_t bit4 : 1;
            uint8_t bit5 : 1;
            uint8_t bit6 : 1;
            uint8_t bit7 : 1;
            uint8_t TR_OBU_TrainSleep : 1;//byte 3
            uint8_t TR_OBU_TrainSleep_Not : 1;
            uint8_t bit10 : 1;
            uint8_t TR_OBU_NLEnabled : 1;
            uint8_t TR_OBU_DirectionFW : 1;
            uint8_t TR_OBU_DirectionBW : 1;
            uint8_t TR_OBU_CabStatusA : 1;
            uint8_t TR_OBU_CabStatusB : 1;
            uint8_t bit16 : 1;//byte 4
            uint8_t bit17 : 1;
            uint8_t TR_OBU_Train_Integrity : 1;
            uint8_t bit19 : 1;
            uint8_t TR_OBU_Traction_Status : 1;
            uint8_t TR_OBU_AirTightFitted : 1;
            uint8_t bit22 : 1;
            uint8_t bit23 : 1;
            uint8_t reserved_5;//byte 5
            uint8_t reserved_6;//byte 6
            uint8_t Brake_status_EP_S : 1;//byte 7
            uint8_t Brake_status_EP_S_Not : 1;
            uint8_t bit24 : 1;
            uint8_t bit25 : 1;
            uint8_t Brake_status_RP_S : 1;
            uint8_t Brake_status_RP_S_Not : 1;
            uint8_t bit26 : 1;
            uint8_t bit27 : 1;
            uint8_t reserved_8;//byte 8
            uint16_t reserved_9_10;
            uint8_t TR_OBU_Train_Control_0 : 1;//byte 11
            uint8_t TR_OBU_Train_Control_1 : 1;
            uint8_t TR_OBU_Train_Control_2 : 1;
            uint8_t TR_OBU_Train_Control_3 : 1;
            uint8_t bit28 : 1;
            uint8_t bit29 : 1;
            uint8_t bit30 : 1;
            uint8_t bit31 : 1;
            uint8_t reserved_12;//byte 12
            uint8_t reserved_13;//byte 13
            uint8_t reserved_14;//byte 14
            uint8_t reserved_15;//byte 15
            uint8_t reserved_16;//byte 16
            uint8_t reserved_17;//byte 17
            uint8_t reserved_18;//byte 18
            uint8_t reserved_19;//byte 19
            uint8_t reserved_20;//byte 20
            uint8_t reserved_21;//byte 21
            uint8_t reserved_22;//byte 22
            uint8_t reserved_23;//byte 23
            uint8_t reserved_24;//byte 24
            uint8_t reserved_25;//byte 25
            uint8_t reserved_26;//byte 26
            uint8_t reserved_27;//byte 27
            uint8_t reserved_28;//byte 28
            uint8_t reserved_29;//byte 29
            uint8_t reserved_30;//byte 30
            uint8_t reserved_31;//byte 31

        } bits;
        time_t last_update;
    };
};

/**
 * CCU to all ETCS
 * 0x197
 *
 * */
struct ccu_to_all_etcs {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint16_t Lifesign ;//byte 0
            uint8_t bit0 : 1;//byte 2
            uint8_t bit1 : 1;
            uint8_t bit2 : 1;
            uint8_t bit3 : 1;
            uint8_t bit4 : 1;
            uint8_t bit5 : 1;
            uint8_t bit6 : 1;
            uint8_t bit7 : 1;
            uint8_t bit8 : 1;//byte 3
            uint8_t bit9 : 1;
            uint8_t Train_data_Brake_Position:4;
            uint8_t bit14 : 1;
            uint8_t bit15 : 1;
            uint8_t reserved_4;//byte 4
            uint8_t reserved_5;//byte 5
            uint8_t TR_OBU_BrakePercentage;//byte 6
            uint8_t reserved_7;//byte 7
            uint8_t reserved_8;//byte 8
            uint16_t TR_OBU_TrainLength ;//byte 9-10
            uint8_t TR_OBU_LoadingGauge ;//byte 11
            uint8_t TR_OBU_AxleLoadCat ; //byte 12
            uint8_t TR_OBU_TrainCatCantDef ;//byte 13
            uint8_t TR_OBU_TS_M_VOLTAGE ;//byte 14
            uint16_t TR_OBU_TS_NID_CTRACTION ;//byte 15-16
            uint8_t reserved_17;//byte 17
            uint8_t reserved_18;//byte 18
            uint8_t reserved_19;//byte 19
            uint8_t reserved_20;//byte 20
            uint8_t reserved_21;//byte 21
            uint8_t reserved_22;//byte 22
            uint8_t reserved_23;//byte 23
            uint8_t reserved_24;//byte 24
            uint8_t reserved_25;//byte 25
            uint8_t reserved_26;//byte 26
            uint8_t reserved_27;//byte 27
            uint8_t reserved_28;//byte 28
            uint8_t reserved_29;//byte 29
            uint8_t reserved_30;//byte 30
            uint8_t reserved_31;//byte 31

        } bits;
        time_t last_update;
    };
};


/**
 * CCU to JRU
 * 0x1A1
 * */

struct ccu_to_all_jrus_1 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {

            uint16_t Lifesign;//byte 0 1
            uint8_t Badge_id_byte1;//byte 2
            uint8_t Badge_id_byte2;//byte 3
            uint8_t Badge_id_byte3;//byte 4
            uint8_t Badge_id_byte4;//byte 5
            uint8_t Badge_id_byte5;//byte 6
            uint8_t Badge_id_byte6;//byte 7
            uint8_t Badge_id_byte7;//byte 8
            uint8_t reserved_9;//byte 9
            uint8_t OA1_JRU_ID_valid:1;//byte 10
            uint8_t OA1_JRU_ID_invalid:1;
            uint8_t OA2_JRU_ID_valid:1;
            uint8_t OA2_JRU_ID_invalid:1;
            uint8_t Login_status:1;
            uint8_t bit85:1;
            uint8_t bit86:1;
            uint8_t bit87:1;
            uint8_t ATS_brake_request:1;//byte 11
            uint8_t DAC_brake_request:1;
            uint8_t HORN_request:1;
            uint8_t bit91:1;
            uint8_t bit92:1;
            uint8_t bit93:1;
            uint8_t bit94:1;
            uint8_t bit95:1;
            uint8_t S_PrkBrAp:1;//byte 12
            uint8_t S_HolBrAp:1;
            uint8_t Park_mode_active:1;
            uint8_t S_PnBrAp_SKA1_Bo1:1;
            uint8_t S_PnBrAp_SKA1_Bo2:1;
            uint8_t S_PnBrAp_OA1_Bo1:1;
            uint8_t S_PnBrAp_OA1_Bo2:1;
            uint8_t S_PnBrAp_OA2_Bo1:1;
            uint8_t S_PnBrAp_OA2_Bo2:1;//byte 13
            uint8_t S_PnBrAp_SKA2_Bo1:1;
            uint8_t S_PnBrAp_SKA2_Bo2:1;
            uint8_t S_PrkBrRe_SKA1:1;
            uint8_t S_PrkBrRe_SKA2:1;
            uint8_t S_PrkBrRe_OA1:1;
            uint8_t S_PrkBrRe_OA2:1;
            uint8_t bit111:1;
            uint16_t X_VAxl1;//byte 14 15
            uint16_t X_VAxl2;//byte 16 17
            uint16_t X_VAxl3;//byte 18 19
            uint16_t X_VAxl4;//byte 20 21
            uint16_t X_Vref;// byte 22 23
            uint8_t S_WSPTest_Run:1;//byte 24
            uint8_t S_WSPactive_SKA1_Bo1:1;
            uint8_t S_WSPactive_SKA1_Bo2:1;
            uint8_t S_WSPactive_OA1_Bo1:1;
            uint8_t S_WSPactive_OA1_Bo2:1;
            uint8_t S_WSPactive_OA2_Bo1:1;
            uint8_t S_WSPactive_OA2_Bo2:1;
            uint8_t S_WSPactive_SKA2_Bo1:1;
            uint8_t S_WSPactive_SKA2_Bo2:1;//byte 25
            uint8_t S_Sanding_Heating_Release:1;
            uint8_t S_Sanding_requested:1;
            uint8_t WFL_Spray_Enable:1;
            uint8_t S_ASC_Mode_active:1;
            uint8_t bit205:1;
            uint8_t bit206:1;
            uint8_t bit207:1;
            uint16_t SIGNAL_SPEED;//byte 26 27
            uint8_t SKA1_HVAC1_ON:1;//byte 28
            uint8_t SKA1_HVAC2_ON:1;
            uint8_t SKA2_HVAC1_ON:1;
            uint8_t SKA2_HVAC2_ON:1;
            uint8_t OA1_HVAC1_ON:1;
            uint8_t OA1_HVAC2_ON:1;
            uint8_t OA2_HVAC1_ON:1;
            uint8_t OA2_HVAC2_ON:1;
            uint8_t SKA1_CONTACTOR_HVAC_LEFT_SIDE:1;//byte 29
            uint8_t SKA1_CONTACTOR_HVAC_RIGHT_SIDE:1;
            uint8_t SKA2_CONTACTOR_HVAC_LEFT_SIDE:1;
            uint8_t SKA2_CONTACTOR_HVAC_RIGHT_SIDE:1;
            uint8_t OA1_CONTACTOR_HVAC_LEFT_SIDE:1;
            uint8_t OA1_CONTACTOR_HVAC_RIGHT_SIDE:1;
            uint8_t OA2_CONTACTOR_HVAC_LEFT_SIDE:1;
            uint8_t OA2_CONTACTOR_HVAC_RIGHT_SIDE:1;
            uint8_t SKA1_DUMPER:1;//byte 30
            uint8_t SKA2_DUMPER:1;
            uint8_t SKA1_WINDSCREEN_HEATING:1;
            uint8_t SKA1_WIPER_SYSTEM_FUNCTION_OK:1;
            uint8_t SKA1_WIPER_LEVEL_WASH_WATER_TANK:1;
            uint8_t SKA1_FULL_LIGHT_MARKER_LIGHT:1;
            uint8_t SKA1_DIMMED_HEAD_LIGHT_MARKER_LIGHT:1;
            uint8_t SKA1_MARKER_LIGHT:1;
            uint8_t SKA1_DIMMED_MARKER_LIGHT:1;//byte 31
            uint8_t SKA2_WINDSCREEN_HEATING:1;
            uint8_t SKA2_WIPER_SYSTEM_FUNCTION_OK:1;
            uint8_t SKA2_WIPER_LEVEL_WASH_WATER_TANK:1;
            uint8_t SKA2_FULL_LIGHT_MARKER_LIGHT:1;
            uint8_t SKA2_DIMMED_HEAD_LIGHT_MARKER_LIGHT:1;
            uint8_t SKA2_MARKER_LIGHT:1;
            uint8_t SKA2_DIMMED_MARKER_LIGHT:1;

        } bits;
        time_t last_update;
    };
};

/**
 * CCU to JRU
 * 0x1A2
 * */

struct ccu_to_all_jrus_2 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint16_t Lifesign ;//byte 0 1
            uint8_t SKA1_Inside_temperature;//byte 2
            uint8_t SKA2_Inside_temperature;//byte 3
            uint8_t OA1_Inside_temperature; //byte 4
            uint8_t OA2_Inside_temperature; //byte 5
            uint8_t SKA1_FAST_OPEN_ADD : 1;//byte 6
            uint8_t SKA2_FAST_OPEN_ADD : 1;
            uint8_t OA1_FAST_OPEN_ADD : 1;
            uint8_t OA2_FAST_OPEN_ADD : 1;
            uint8_t SKA1_TRACTION_CUT_OFF_LOOP : 1;
            uint8_t SKA2_TRACTION_CUT_OFF_LOOP : 1;
            uint8_t OA1_BATTERY_CHARGER_OK : 1;
            uint8_t OA2_BATTERY_CHARGER_OK : 1;
            uint8_t SKA1_DOOR_1_FULLY_OPENED : 1;//byte 7
            uint8_t SKA1_DOOR_2_FULLY_OPENED : 1;
            uint8_t SKA1_DOOR_3_FULLY_OPENED : 1;
            uint8_t SKA1_DOOR_4_FULLY_OPENED : 1;
            uint8_t SKA1_DOOR_5_FULLY_OPENED : 1;
            uint8_t SKA1_DOOR_6_FULLY_OPENED : 1;
            uint8_t SKA1_DOOR_7_FULLY_OPENED : 1;
            uint8_t SKA1_DOOR_8_FULLY_OPENED : 1;
            uint8_t SKA2_DOOR_1_FULLY_OPENED : 1;//byte 8
            uint8_t SKA2_DOOR_2_FULLY_OPENED : 1;
            uint8_t SKA2_DOOR_3_FULLY_OPENED : 1;
            uint8_t SKA2_DOOR_4_FULLY_OPENED : 1;
            uint8_t SKA2_DOOR_5_FULLY_OPENED : 1;
            uint8_t SKA2_DOOR_6_FULLY_OPENED : 1;
            uint8_t SKA2_DOOR_7_FULLY_OPENED : 1;
            uint8_t SKA2_DOOR_8_FULLY_OPENED : 1;
            uint8_t OA1_DOOR_1_FULLY_OPENED : 1;//byte 9
            uint8_t OA1_DOOR_2_FULLY_OPENED : 1;
            uint8_t OA1_DOOR_3_FULLY_OPENED : 1;
            uint8_t OA1_DOOR_4_FULLY_OPENED : 1;
            uint8_t OA1_DOOR_5_FULLY_OPENED : 1;
            uint8_t OA1_DOOR_6_FULLY_OPENED : 1;
            uint8_t OA1_DOOR_7_FULLY_OPENED : 1;
            uint8_t OA1_DOOR_8_FULLY_OPENED : 1;
            uint8_t OA2_DOOR_1_FULLY_OPENED : 1;//byte 10
            uint8_t OA2_DOOR_2_FULLY_OPENED : 1;
            uint8_t OA2_DOOR_3_FULLY_OPENED : 1;
            uint8_t OA2_DOOR_4_FULLY_OPENED : 1;
            uint8_t OA2_DOOR_5_FULLY_OPENED : 1;
            uint8_t OA2_DOOR_6_FULLY_OPENED : 1;
            uint8_t OA2_DOOR_7_FULLY_OPENED : 1;
            uint8_t OA2_DOOR_8_FULLY_OPENED : 1;
            uint8_t SKA1_DCU_DoorR1_DoorClosedAndLocked : 1;//byte 11
            uint8_t SKA1_DCU_DoorR2_DoorClosedAndLocked : 1;
            uint8_t SKA1_DCU_DoorR3_DoorClosedAndLocked : 1;
            uint8_t SKA1_DCU_DoorR4_DoorClosedAndLocked : 1;
            uint8_t SKA1_DCU_DoorL1_DoorClosedAndLocked : 1;
            uint8_t SKA1_DCU_DoorL2_DoorClosedAndLocked : 1;
            uint8_t SKA1_DCU_DoorL3_DoorClosedAndLocked : 1;
            uint8_t SKA1_DCU_DoorL4_DoorClosedAndLocked : 1;
            uint8_t SKA2_DCU_DoorR1_DoorClosedAndLocked : 1;//byte 12
            uint8_t SKA2_DCU_DoorR2_DoorClosedAndLocked : 1;
            uint8_t SKA2_DCU_DoorR3_DoorClosedAndLocked : 1;
            uint8_t SKA2_DCU_DoorR4_DoorClosedAndLocked : 1;
            uint8_t SKA2_DCU_DoorL1_DoorClosedAndLocked : 1;
            uint8_t SKA2_DCU_DoorL2_DoorClosedAndLocked : 1;
            uint8_t SKA2_DCU_DoorL3_DoorClosedAndLocked : 1;
            uint8_t SKA2_DCU_DoorL4_DoorClosedAndLocked : 1;
            uint8_t OA1_DCU_DoorR1_DoorClosedAndLocked : 1;//byte 13
            uint8_t OA1_DCU_DoorR2_DoorClosedAndLocked : 1;
            uint8_t OA1_DCU_DoorR3_DoorClosedAndLocked : 1;
            uint8_t OA1_DCU_DoorR4_DoorClosedAndLocked : 1;
            uint8_t OA1_DCU_DoorL1_DoorClosedAndLocked : 1;
            uint8_t OA1_DCU_DoorL2_DoorClosedAndLocked : 1;
            uint8_t OA1_DCU_DoorL3_DoorClosedAndLocked : 1;
            uint8_t OA1_DCU_DoorL4_DoorClosedAndLocked : 1;
            uint8_t OA2_DCU_DoorR1_DoorClosedAndLocked : 1;//byte 14
            uint8_t OA2_DCU_DoorR2_DoorClosedAndLocked : 1;
            uint8_t OA2_DCU_DoorR3_DoorClosedAndLocked : 1;
            uint8_t OA2_DCU_DoorR4_DoorClosedAndLocked : 1;
            uint8_t OA2_DCU_DoorL1_DoorClosedAndLocked : 1;
            uint8_t OA2_DCU_DoorL2_DoorClosedAndLocked : 1;
            uint8_t OA2_DCU_DoorL3_DoorClosedAndLocked : 1;
            uint8_t OA2_DCU_DoorL4_DoorClosedAndLocked : 1;
            uint8_t SKA1_DCU_DoorR1_TCMS_TLRelease : 1;//byte 15
            uint8_t SKA1_DCU_DoorR2_TCMS_TLRelease : 1;
            uint8_t SKA1_DCU_DoorR3_TCMS_TLRelease : 1;
            uint8_t SKA1_DCU_DoorR4_TCMS_TLRelease : 1;
            uint8_t SKA1_DCU_DoorL1_TCMS_TLRelease : 1;
            uint8_t SKA1_DCU_DoorL2_TCMS_TLRelease : 1;
            uint8_t SKA1_DCU_DoorL3_TCMS_TLRelease : 1;
            uint8_t SKA1_DCU_DoorL4_TCMS_TLRelease : 1;
            uint8_t SKA2_DCU_DoorR1_TCMS_TLRelease : 1;//byte 16
            uint8_t SKA2_DCU_DoorR2_TCMS_TLRelease : 1;
            uint8_t SKA2_DCU_DoorR3_TCMS_TLRelease : 1;
            uint8_t SKA2_DCU_DoorR4_TCMS_TLRelease : 1;
            uint8_t SKA2_DCU_DoorL1_TCMS_TLRelease : 1;
            uint8_t SKA2_DCU_DoorL2_TCMS_TLRelease : 1;
            uint8_t SKA2_DCU_DoorL3_TCMS_TLRelease : 1;
            uint8_t SKA2_DCU_DoorL4_TCMS_TLRelease : 1;
            uint8_t OA1_DCU_DoorR1_TCMS_TLRelease : 1;//byte 17
            uint8_t OA1_DCU_DoorR2_TCMS_TLRelease : 1;
            uint8_t OA1_DCU_DoorR3_TCMS_TLRelease : 1;
            uint8_t OA1_DCU_DoorR4_TCMS_TLRelease : 1;
            uint8_t OA1_DCU_DoorL1_TCMS_TLRelease : 1;
            uint8_t OA1_DCU_DoorL2_TCMS_TLRelease : 1;
            uint8_t OA1_DCU_DoorL3_TCMS_TLRelease : 1;
            uint8_t OA1_DCU_DoorL4_TCMS_TLRelease : 1;
            uint8_t OA2_DCU_DoorR1_TCMS_TLRelease : 1;//byte 18
            uint8_t OA2_DCU_DoorR2_TCMS_TLRelease : 1;
            uint8_t OA2_DCU_DoorR3_TCMS_TLRelease : 1;
            uint8_t OA2_DCU_DoorR4_TCMS_TLRelease : 1;
            uint8_t OA2_DCU_DoorL1_TCMS_TLRelease : 1;
            uint8_t OA2_DCU_DoorL2_TCMS_TLRelease : 1;
            uint8_t OA2_DCU_DoorL3_TCMS_TLRelease : 1;
            uint8_t OA2_DCU_DoorL4_TCMS_TLRelease : 1;
            uint8_t SKA1_DCU_DoorR1_TCMS_OutofService : 1;//byte 19
            uint8_t SKA1_DCU_DoorR2_TCMS_OutofService : 1;
            uint8_t SKA1_DCU_DoorR3_TCMS_OutofService : 1;
            uint8_t SKA1_DCU_DoorR4_TCMS_OutofService : 1;
            uint8_t SKA1_DCU_DoorL1_TCMS_OutofService : 1;
            uint8_t SKA1_DCU_DoorL2_TCMS_OutofService : 1;
            uint8_t SKA1_DCU_DoorL3_TCMS_OutofService : 1;
            uint8_t SKA1_DCU_DoorL4_TCMS_OutofService : 1;
            uint8_t SKA2_DCU_DoorR1_TCMS_OutofService : 1;//byte 20
            uint8_t SKA2_DCU_DoorR2_TCMS_OutofService : 1;
            uint8_t SKA2_DCU_DoorR3_TCMS_OutofService : 1;
            uint8_t SKA2_DCU_DoorR4_TCMS_OutofService : 1;
            uint8_t SKA2_DCU_DoorL1_TCMS_OutofService : 1;
            uint8_t SKA2_DCU_DoorL2_TCMS_OutofService : 1;
            uint8_t SKA2_DCU_DoorL3_TCMS_OutofService : 1;
            uint8_t SKA2_DCU_DoorL4_TCMS_OutofService : 1;
            uint8_t OA1_DCU_DoorR1_TCMS_OutofService : 1;//byte 21
            uint8_t OA1_DCU_DoorR2_TCMS_OutofService : 1;
            uint8_t OA1_DCU_DoorR3_TCMS_OutofService : 1;
            uint8_t OA1_DCU_DoorR4_TCMS_OutofService : 1;
            uint8_t OA1_DCU_DoorL1_TCMS_OutofService : 1;
            uint8_t OA1_DCU_DoorL2_TCMS_OutofService : 1;
            uint8_t OA1_DCU_DoorL3_TCMS_OutofService : 1;
            uint8_t OA1_DCU_DoorL4_TCMS_OutofService : 1;
            uint8_t OA2_DCU_DoorR1_TCMS_OutofService : 1;//byte 22
            uint8_t OA2_DCU_DoorR2_TCMS_OutofService : 1;
            uint8_t OA2_DCU_DoorR3_TCMS_OutofService : 1;
            uint8_t OA2_DCU_DoorR4_TCMS_OutofService : 1;
            uint8_t OA2_DCU_DoorL1_TCMS_OutofService : 1;
            uint8_t OA2_DCU_DoorL2_TCMS_OutofService : 1;
            uint8_t OA2_DCU_DoorL3_TCMS_OutofService : 1;
            uint8_t OA2_DCU_DoorL4_TCMS_OutofService : 1;
            uint8_t SKA1_DCU_DoorR1_DoorObstDet : 1;//byte 23
            uint8_t SKA1_DCU_DoorR2_DoorObstDet : 1;
            uint8_t SKA1_DCU_DoorR3_DoorObstDet : 1;
            uint8_t SKA1_DCU_DoorR4_DoorObstDet : 1;
            uint8_t SKA1_DCU_DoorL1_DoorObstDet : 1;
            uint8_t SKA1_DCU_DoorL2_DoorObstDet : 1;
            uint8_t SKA1_DCU_DoorL3_DoorObstDet : 1;
            uint8_t SKA1_DCU_DoorL4_DoorObstDet : 1;
            uint8_t SKA2_DCU_DoorR1_DoorObstDet : 1;//byte 24
            uint8_t SKA2_DCU_DoorR2_DoorObstDet : 1;
            uint8_t SKA2_DCU_DoorR3_DoorObstDet : 1;
            uint8_t SKA2_DCU_DoorR4_DoorObstDet : 1;
            uint8_t SKA2_DCU_DoorL1_DoorObstDet : 1;
            uint8_t SKA2_DCU_DoorL2_DoorObstDet : 1;
            uint8_t SKA2_DCU_DoorL3_DoorObstDet : 1;
            uint8_t SKA2_DCU_DoorL4_DoorObstDet : 1;
            uint8_t OA1_DCU_DoorR1_DoorObstDet : 1;//byte 25
            uint8_t OA1_DCU_DoorR2_DoorObstDet : 1;
            uint8_t OA1_DCU_DoorR3_DoorObstDet : 1;
            uint8_t OA1_DCU_DoorR4_DoorObstDet : 1;
            uint8_t OA1_DCU_DoorL1_DoorObstDet : 1;
            uint8_t OA1_DCU_DoorL2_DoorObstDet : 1;
            uint8_t OA1_DCU_DoorL3_DoorObstDet : 1;
            uint8_t OA1_DCU_DoorL4_DoorObstDet : 1;
            uint8_t OA2_DCU_DoorR1_DoorObstDet : 1;//byte 26
            uint8_t OA2_DCU_DoorR2_DoorObstDet : 1;
            uint8_t OA2_DCU_DoorR3_DoorObstDet : 1;
            uint8_t OA2_DCU_DoorR4_DoorObstDet : 1;
            uint8_t OA2_DCU_DoorL1_DoorObstDet : 1;
            uint8_t OA2_DCU_DoorL2_DoorObstDet : 1;
            uint8_t OA2_DCU_DoorL3_DoorObstDet : 1;
            uint8_t OA2_DCU_DoorL4_DoorObstDet : 1;
            uint8_t SKA1_DCU_DoorR1_DoorAntiDrag : 1;//byte 27
            uint8_t SKA1_DCU_DoorR2_DoorAntiDrag : 1;
            uint8_t SKA1_DCU_DoorR3_DoorAntiDrag : 1;
            uint8_t SKA1_DCU_DoorR4_DoorAntiDrag : 1;
            uint8_t SKA1_DCU_DoorL1_DoorAntiDrag : 1;
            uint8_t SKA1_DCU_DoorL2_DoorAntiDrag : 1;
            uint8_t SKA1_DCU_DoorL3_DoorAntiDrag : 1;
            uint8_t SKA1_DCU_DoorL4_DoorAntiDrag : 1;
            uint8_t SKA2_DCU_DoorR1_DoorAntiDrag : 1;//byte 28
            uint8_t SKA2_DCU_DoorR2_DoorAntiDrag : 1;
            uint8_t SKA2_DCU_DoorR3_DoorAntiDrag : 1;
            uint8_t SKA2_DCU_DoorR4_DoorAntiDrag : 1;
            uint8_t SKA2_DCU_DoorL1_DoorAntiDrag : 1;
            uint8_t SKA2_DCU_DoorL2_DoorAntiDrag : 1;
            uint8_t SKA2_DCU_DoorL3_DoorAntiDrag : 1;
            uint8_t SKA2_DCU_DoorL4_DoorAntiDrag : 1;
            uint8_t OA1_DCU_DoorR1_DoorAntiDrag : 1;//byte 29
            uint8_t OA1_DCU_DoorR2_DoorAntiDrag : 1;
            uint8_t OA1_DCU_DoorR3_DoorAntiDrag : 1;
            uint8_t OA1_DCU_DoorR4_DoorAntiDrag : 1;
            uint8_t OA1_DCU_DoorL1_DoorAntiDrag : 1;
            uint8_t OA1_DCU_DoorL2_DoorAntiDrag : 1;
            uint8_t OA1_DCU_DoorL3_DoorAntiDrag : 1;
            uint8_t OA1_DCU_DoorL4_DoorAntiDrag : 1;
            uint8_t OA2_DCU_DoorR1_DoorAntiDrag : 1;//byte 30
            uint8_t OA2_DCU_DoorR2_DoorAntiDrag : 1;
            uint8_t OA2_DCU_DoorR3_DoorAntiDrag : 1;
            uint8_t OA2_DCU_DoorR4_DoorAntiDrag : 1;
            uint8_t OA2_DCU_DoorL1_DoorAntiDrag : 1;
            uint8_t OA2_DCU_DoorL2_DoorAntiDrag : 1;
            uint8_t OA2_DCU_DoorL3_DoorAntiDrag : 1;
            uint8_t OA2_DCU_DoorL4_DoorAntiDrag : 1;
            uint8_t bit248 : 1;//byte 31
            uint8_t bit249 : 1;
            uint8_t bit250 : 1;
            uint8_t bit251 : 1;
            uint8_t bit252 : 1;
            uint8_t bit253 : 1;
            uint8_t bit254 : 1;
            uint8_t bit255 : 1;

        } bits;
        time_t last_update;
    };
};
/**
 * CCU to JRU
 * 0x1A3
 * */

struct ccu_to_all_jrus_3 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint16_t Lifesign ;//byte 0 1
            int32_t GPSLongtitudeMasterTCMS;//byte 2 3 4 5
            int32_t GPSLatitudeMasterTCMS;// byte  6 7 8 9
            uint8_t ServiceID_Byte0;//byte 10
            uint8_t ServiceID_Byte1;//byte 11
            uint8_t ServiceID_Byte2;//byte 12
            uint8_t ServiceID_Byte3;//byte 13
            uint8_t ServiceID_Byte4;//byte 14
            uint8_t ServiceID_Byte5;//byte 15
            uint8_t ServiceID_Byte6;//byte 16
            uint8_t ServiceID_Byte7;//byte 17
            uint8_t SKA1_D_SFD1_FC129 :1;//byte 18
            uint8_t SKA1_D_SFD2_FC129 :1;
            uint8_t SKA1_D_SFD3_FC129 :1;
            uint8_t SKA1_D_SFD4_FC129 :1;
            uint8_t SKA1_D_SFD5_FC129 :1;
            uint8_t SKA2_D_SFD1_FC129 :1;
            uint8_t SKA2_D_SFD2_FC129 :1;
            uint8_t SKA2_D_SFD3_FC129 :1;
            uint8_t SKA2_D_SFD4_FC129 :1;//byte 19
            uint8_t SKA2_D_SFD5_FC129 :1;
            uint8_t OA1_D_SFD1_FC129 :1;
            uint8_t OA1_D_SFD2_FC129 :1;
            uint8_t OA1_D_SFD3_FC129 :1;
            uint8_t OA1_D_SFD4_FC129 :1;
            uint8_t OA1_D_SFD5_FC129 :1;
            uint8_t OA2_D_SFD1_FC129 :1;
            uint8_t OA2_D_SFD2_FC129 :1;//byte 20
            uint8_t OA2_D_SFD3_FC129 :1;
            uint8_t OA2_D_SFD4_FC129 :1;
            uint8_t OA2_D_SFD5_FC129 :1;
            uint8_t SKA1_D_CS_IC22_1_FC129 :1;
            uint8_t SKA1_D_CS_IC22_2_FC129 :1;
            uint8_t SKA1_D_CS_IC22_3_FC129 :1;
            uint8_t SKA2_D_CS_IC22_1_FC129 :1;
            uint8_t SKA2_D_CS_IC22_2_FC129 :1;//byte 21
            uint8_t SKA2_D_CS_IC22_3_FC129 :1;
            uint8_t OA1_D_CS_IC22_1_FC129 :1;
            uint8_t OA1_D_CS_IC22_2_FC129 :1;
            uint8_t bit172 :1;
            uint8_t bit173 :1;
            uint8_t bit174 :1;
            uint8_t bit175 :1;
            uint8_t S_SKA1_FDCU_General_fire :1;//byte 22
            uint8_t S_SKA1_FDCU_Unmuted_fire_alarm :1;
            uint8_t S_SKA1_FDCU_Fire_fault_reset_feedback_RPDO :1;
            uint8_t S_SKA1_FDCU_General_fault :1;
            uint8_t S_SKA1_FDCU_Unmuted_fault_alarm :1;
            uint8_t S_SKA2_FDCU_General_fire :1;
            uint8_t S_SKA2_FDCU_Unmuted_fire_alarm :1;
            uint8_t S_SKA2_FDCU_Fire_fault_reset_feedback_RPDO :1;
            uint8_t S_SKA2_FDCU_General_fault :1;//byte 23
            uint8_t S_SKA2_FDCU_Unmuted_fault_alarm :1;
            uint8_t bit186 :1;
            uint8_t bit187 :1;
            uint8_t bit188 :1;
            uint8_t bit189 :1;
            uint8_t bit190 :1;
            uint8_t bit191 :1;
            uint8_t SKA1_DCU_DoorR1_EEDOp :1;//byte 24
            uint8_t SKA1_DCU_DoorR2_EEDOp :1;
            uint8_t SKA1_DCU_DoorR3_EEDOp :1;
            uint8_t SKA1_DCU_DoorR4_EEDOp :1;
            uint8_t SKA1_DCU_DoorL1_EEDOp :1;
            uint8_t SKA1_DCU_DoorL2_EEDOp :1;
            uint8_t SKA1_DCU_DoorL3_EEDOp :1;
            uint8_t SKA1_DCU_DoorL4_EEDOp :1;
            uint8_t SKA2_DCU_DoorR1_EEDOp :1;//byte 25
            uint8_t SKA2_DCU_DoorR2_EEDOp :1;
            uint8_t SKA2_DCU_DoorR3_EEDOp :1;
            uint8_t SKA2_DCU_DoorR4_EEDOp :1;
            uint8_t SKA2_DCU_DoorL1_EEDOp :1;
            uint8_t SKA2_DCU_DoorL2_EEDOp :1;
            uint8_t SKA2_DCU_DoorL3_EEDOp :1;
            uint8_t SKA2_DCU_DoorL4_EEDOp :1;
            uint8_t OA1_DCU_DoorR1_EEDOp :1;//byte 26
            uint8_t OA1_DCU_DoorR2_EEDOp :1;
            uint8_t OA1_DCU_DoorR3_EEDOp :1;
            uint8_t OA1_DCU_DoorR4_EEDOp :1;
            uint8_t OA1_DCU_DoorL1_EEDOp :1;
            uint8_t OA1_DCU_DoorL2_EEDOp :1;
            uint8_t OA1_DCU_DoorL3_EEDOp :1;
            uint8_t OA1_DCU_DoorL4_EEDOp :1;
            uint8_t OA2_DCU_DoorR1_EEDOp :1;//byte 27
            uint8_t OA2_DCU_DoorR2_EEDOp :1;
            uint8_t OA2_DCU_DoorR3_EEDOp :1;
            uint8_t OA2_DCU_DoorR4_EEDOp :1;
            uint8_t OA2_DCU_DoorL1_EEDOp :1;
            uint8_t OA2_DCU_DoorL2_EEDOp :1;
            uint8_t OA2_DCU_DoorL3_EEDOp :1;
            uint8_t OA2_DCU_DoorL4_EEDOp :1;
            uint8_t OA1_ETCS_LEFT_DOORS_OPEN_PER :1;//byte 28
            uint8_t OA1_ETCS_RIGHT_DOORS_OPEN_PER :1;
            uint8_t OA2_ETCS_LEFT_DOORS_OPEN_PER :1;
            uint8_t OA2_ETCS_RIGHT_DOORS_OPEN_PER :1;
            uint8_t SKA1_ENABLE_DOORS_1357 :1;
            uint8_t SKA1_ENABLE_DOORS_2468 :1;
            uint8_t SKA2_ENABLE_DOORS_1357 :1;
            uint8_t SKA2_ENABLE_DOORS_2468 :1;
            int8_t Outside_Temperature;//byte 29
            uint16_t X_LoadWeight;//byte 30 31

        } bits;
        time_t last_update;
    };
};
/**
 * CCU to JRU
 * 0x1A4
 * */

struct ccu_to_all_jrus_4 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint16_t Lifesign ;//byte 0 1
            uint8_t X_MRPPress ;//byte 2
            uint8_t X_BPPress ;//byte 3
            uint8_t EB_applied :1;//byte 4
            uint8_t SKA1_S_PB_EmerRel_Conf :1;
            uint8_t SKA2_S_PB_EmerRel_Conf :1;
            uint8_t OA1_S_PB_EmerRel_Conf :1;
            uint8_t OA2_S_PB_EmerRel_Conf :1;
            uint8_t Service_brake_applied :1;
            uint8_t SKA1_INDIRECT_BRAKE_MANIPOLATOR :1;
            uint8_t SKA2_INDIRECT_BRAKE_MANIPOLATOR :1;
            uint8_t OA1_ETCS_LEFT_DOORS_OPEN_PERMISSION :1;//byte 5
            uint8_t OA1_ETCS_RIGHT_DOORS_OPEN_PERMISSION :1;
            uint8_t OA2_ETCS_LEFT_DOORS_OPEN_PERMISSION :1;
            uint8_t OA2_ETCS_RIGHT_DOORS_OPEN_PERMISSION :1;
            uint8_t bit44 :1;
            uint8_t bit45 :1;
            uint8_t bit46 :1;
            uint8_t bit47 :1;
            uint8_t Parking_mode_on_off :1;//byte 6
            uint8_t PG_NDIRECT_BRAKE_CONTROL :1;
            uint8_t SKA1_PB_Emergency :1;
            uint8_t SKA2_PB_Emergency :1;
            uint8_t SKA1_MC_S1 :1;
            uint8_t SKA1_MC_S2 :1;
            uint8_t SKA1_MC_S3 :1;
            uint8_t SKA1_MC_S4 :1;
            uint8_t SKA1_MC_S5 :1;//byte 7
            uint8_t SKA1_MC_S6 :1;
            uint8_t SKA2_MC_S1 :1;
            uint8_t SKA2_MC_S2 :1;
            uint8_t SKA2_MC_S3 :1;
            uint8_t SKA2_MC_S4 :1;
            uint8_t SKA2_MC_S5 :1;
            uint8_t SKA2_MC_S6 :1;
            uint8_t HORN_1_IC :1;//byte 8
            uint8_t HORN_2_IC  :1;
            uint8_t OA1_PG_COMPRESSOR_CONTROL :1;
            uint8_t OA1_IC_ASU :1;
            uint8_t OA2_PG_COMPRESSOR_CONTROL :1;
            uint8_t OA2_IC_ASU :1;
            uint8_t ISOLATION_COCKS_PNEUMATIC_BRAKE :1;
            uint8_t ISOLATION_COCKS_INDIRECT_BRAKE :1;
            uint8_t ISOLATION_COCKS_DIRECT_BRAKE_BO1 :1;//byte 9
            uint8_t ISOLATION_COCKS_DIRECT_BRAKE_BO2 :1;
            uint8_t ISOLATION_COCKS_PB_ISOLATED :1;
            uint8_t ISOLATION_COCKS_SAND_ISOLATED :1;
            uint8_t ISOLATION_COCKS_BP_TO_MRP_BYPASS :1;
            uint8_t bit77 :1;
            uint8_t bit78 :1;
            uint8_t bit79 :1;
            uint8_t SL_CUT_OFF_BYPASS :1;//byte 10
            uint8_t SL_DEAD_MAN_BYPASS :1;
            uint8_t SL_DOORS_SIDE_CONTROL_ETCS_BYPASS :1;
            uint8_t SL_ETCS_BYPASS :1;
            uint8_t ATS_BYPASS :1;
            uint8_t VACUUM_OPENING_BYPASS :1;
            uint8_t ZERO_SPEED_BYPASS :1;
            uint8_t SELECTOR_BYPASS_PASSANGER_ALARM :1;
            uint8_t SL_DOORS_LOOP_BYPASS :1;//byte 11
            uint8_t bit89 :1;
            uint8_t bit90 :1;
            uint8_t bit91 :1;
            uint8_t bit92 :1;
            uint8_t bit93 :1;
            uint8_t bit94 :1;
            uint8_t bit95 :1;
            uint8_t ATS_mode_on :1;//byte 12
            uint8_t ZERO_SPEED :1;
            uint8_t OA1_POSITION_1_PANTOGRAPH_ENABLED :1;
            uint8_t OA1_POSITION_0_PANTOGRAPH_ISOLATED :1;
            uint8_t OA2_POSITION_1_PANTOGRAPH_ENABLED :1;
            uint8_t OA2_POSITION_0_PANTOGRAPH_ISOLATED :1;
            uint8_t OA1_READY_VCB :1;
            uint8_t OA1_VCB_CLOSE :1;
            uint8_t OA1_OPEN_VCB_FOR_HIGH_CURRENT :1;//byte 13
            uint8_t OA1_FAST_OPEN_VCB :1;
            uint8_t OA2_READY_VCB :1;
            uint8_t OA2_VCB_CLOSE :1;
            uint8_t OA2_OPEN_VCB_FOR_HIGH_CURRENT :1;
            uint8_t OA2_FAST_OPEN_VCB :1;
            uint8_t OA1_HV_DISCONNECTOR_MOVING_OR_CLOSE_D :1;
            uint8_t OA1_HV_DISCONNECTOR_CLOSED_E :1;
            uint8_t OA1_HV_DISCONNECTOR_MOVING_OR_OPEN_A :1;//byte 14
            uint8_t OA1_HV_DISCONNECTOR_OPENED_B :1;
            uint8_t OA2_HV_DISCONNECTOR_MOVING_OR_CLOSE_D :1;
            uint8_t OA2_HV_DISCONNECTOR_CLOSED_E :1;
            uint8_t OA2_HV_DISCONNECTOR_MOVING_OR_OPEN_A :1;
            uint8_t OA2_HV_DISCONNECTOR_OPENED_B :1;
            uint8_t RAISING_PANTOGRAPH_1 :1;
            uint8_t DOWN_PANTOGRAPH_1 :1;
            uint8_t RAISING_PANTOGRAPH_2 :1;//byte 15
            uint8_t DOWN_PANTOGRAPH_2 :1;
            uint8_t SKA1_CLOSING_VACUUM_CIRCUIT_BREAKER :1;
            uint8_t SKA1_OPENING_VACUUM_CIRCUIT_BREAKER :1;
            uint8_t SKA2_CLOSING_VACUUM_CIRCUIT_BREAKER :1;
            uint8_t SKA2_OPENING_VACUUM_CIRCUIT_BREAKER :1;
            uint8_t OA1_EARTHING_SWITCH_SERVICE_POSITION :1;
            uint8_t OA1_EARTHING_SWITCH_EARTH_POSITION :1;
            uint8_t EARTHING_PANEL_YELLOW_KEY_EXTRACTED :1;//byte 16
            uint8_t OA2_EARTHING_SWITCH_SERVICE_POSITION :1;
            uint8_t OA2_EARTHING_SWITCH_EARTH_POSITION :1;
            uint8_t EARTHING_PANEL_YELLOW_KEY_EXTRACTED_1 :1;
            uint8_t bit132 :1;
            uint8_t bit133 :1;
            uint8_t bit134 :1;
            uint8_t bit135:1;
            uint16_t TRANSDUCER_HV_VOLTAGE_VCB_IN;//byte 17 18
            uint16_t TRANSDUCER_HV_CURRENT_VCB_IN;//byte 19 20
            uint8_t SKA1_HANDLE_1_PASSENGER_ALARM :1;//byte 21
            uint8_t SKA1_HANDLE_2_PASSENGER_ALARM :1;
            uint8_t SKA1_HANDLE_3_PASSENGER_ALARM :1;
            uint8_t SKA1_HANDLE_4_PASSENGER_ALARM :1;
            uint8_t SKA1_HANDLE_5_PASSENGER_ALARM :1;
            uint8_t SKA1_HANDLE_6_PASSENGER_ALARM :1;
            uint8_t SKA1_HANDLE_7_PASSENGER_ALARM :1;
            uint8_t SKA1_HANDLE_8_PASSENGER_ALARM :1;
            uint8_t SKA2_HANDLE_1_PASSENGER_ALARM :1;//byte 22
            uint8_t SKA2_HANDLE_2_PASSENGER_ALARM :1;
            uint8_t SKA2_HANDLE_3_PASSENGER_ALARM :1;
            uint8_t SKA2_HANDLE_4_PASSENGER_ALARM :1;
            uint8_t SKA2_HANDLE_5_PASSENGER_ALARM :1;
            uint8_t SKA2_HANDLE_6_PASSENGER_ALARM :1;
            uint8_t SKA2_HANDLE_7_PASSENGER_ALARM :1;
            uint8_t SKA2_HANDLE_8_PASSENGER_ALARM :1;
            uint8_t OA1_HANDLE_1_PASSENGER_ALARM :1;//byte 23
            uint8_t OA1_HANDLE_2_PASSENGER_ALARM :1;
            uint8_t OA1_HANDLE_3_PASSENGER_ALARM :1;
            uint8_t OA1_HANDLE_4_PASSENGER_ALARM :1;
            uint8_t OA1_HANDLE_5_PASSENGER_ALARM :1;
            uint8_t OA1_HANDLE_6_PASSENGER_ALARM :1;
            uint8_t OA1_HANDLE_7_PASSENGER_ALARM :1;
            uint8_t OA1_HANDLE_8_PASSENGER_ALARM :1;
            uint8_t OA2_HANDLE_1_PASSENGER_ALARM :1;//byte 24
            uint8_t OA2_HANDLE_2_PASSENGER_ALARM :1;
            uint8_t OA2_HANDLE_3_PASSENGER_ALARM :1;
            uint8_t OA2_HANDLE_4_PASSENGER_ALARM :1;
            uint8_t OA2_HANDLE_5_PASSENGER_ALARM :1;
            uint8_t OA2_HANDLE_6_PASSENGER_ALARM :1;
            uint8_t OA2_HANDLE_7_PASSENGER_ALARM :1;
            uint8_t OA2_HANDLE_8_PASSENGER_ALARM :1;
            uint8_t SKA1_SAND_LV_SENSOR_BOG1_BEARING_RIGHT :1;//byte 25
            uint8_t SKA1_SAND_LV_SENSOR_BOG1_BEARING_LEFT :1;
            uint8_t SKA1_SAND_LV_SENSOR_BOG2_BEARING_RIGHT :1;
            uint8_t SKA1_SAND_LV_SENSOR_BOG2_BEARING_LEFT :1;
            uint8_t SKA2_SAND_LV_SENSOR_BOG1_BEARING_RIGHT :1;
            uint8_t SKA2_SAND_LV_SENSOR_BOG1_BEARING_LEFT :1;
            uint8_t SKA2_SAND_LV_SENSOR_BOG2_BEARING_RIGHT :1;
            uint8_t SKA2_SAND_LV_SENSOR_BOG2_BEARING_LEFT :1;
            uint8_t SKA1_CCU_OK :1;//byte 26
            uint8_t SKA2_CCU_OK :1;
            uint8_t SKA1_DD_RIOM_M_OK :1;
            uint8_t SKA1_DD_RIOM_R_OK :1;
            uint8_t SKA2_DD_RIOM_M_OK :1;
            uint8_t SKA2_DD_RIOM_R_OK :1;
            uint8_t SKA1_VH_RIOM_M_OK :1;
            uint8_t SKA1_VH_RIOM_R_OK :1;
            uint8_t SKA2_VH_RIOM_M_OK :1;//byte 27
            uint8_t SKA2_VH_RIOM_R_OK :1;
            uint8_t OA1_VH_RIOM_M_OK :1;
            uint8_t OA1_VH_RIOM_R_OK :1;
            uint8_t OA2_VH_RIOM_M_OK :1;
            uint8_t OA2_VH_RIOM_R_OK :1;
            uint8_t SKA1_HMI_OK :1;
            uint8_t SKA2_HMI_OK :1;
            uint8_t OA1_MVB_REPEATER_OK :1;//byte 28
            uint8_t OA2_MVB_REPEATER_OK :1;
            uint8_t SKA1_WTB_GW_OK :1;
            uint8_t SKA2_WTB_GW_OK :1;
            uint8_t SKA1_ETH_SW_OK :1;
            uint8_t SKA2_ETH_SW_OK :1;
            uint8_t OA1_ETH_SW_OK :1;
            uint8_t OA2_ETH_SW_OK :1;
            uint8_t OA1_APU_OK :1;//byte 29
            uint8_t OA2_APU_OK :1;
            uint8_t SKA1_TCU1_OK :1;
            uint8_t SKA1_TCU2_OK :1;
            uint8_t SKA2_TCU1_OK :1;
            uint8_t SKA2_TCU2_OK :1;
            uint8_t SKA1_SIGNALING_AIRSUSP_FAIL :1;
            uint8_t SKA2_SIGNALING_AIRSUSP_FAIL :1;
            uint8_t reserved_30;
            uint8_t reserved_31;

        } bits;
        time_t last_update;
    };
};
/**
 * CCU to JRU
 * 0x1A5
 * */

struct ccu_to_all_jrus_5 {
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint16_t Lifesign;//byte 0 1
            uint16_t Total_applied_traction_power;// byte 2 3
            uint8_t OA1_FAST_OPEN_ADD :1;//byte 4
            uint8_t OA2_FAST_OPEN_ADD :1;
            uint8_t OA1_DEGRADE_MODE_CONTACTOR  :1;
            uint8_t OA2_DEGRADE_MODE_CONTACTOR  :1;
            uint8_t SKA1_TRAIN_KEY_DDESK :1;
            uint8_t SKA2_TRAIN_KEY_DDESK :1;
            uint8_t SKA1_COUPLED_TRAIN_TAIL_RELAY :1;
            uint8_t SKA2_COUPLED_TRAIN_TAIL_RELAY :1;
            uint8_t SPEED_LIMIT :1;//byte 5
            uint8_t bit41 :1;
            uint8_t SKA1_Control_Unit_Radio_Thales_CB_Protection :1;
            uint8_t SKA2_Control_Unit_Radio_Thales_CB_Protection :1;
            uint8_t SKA1_GSMR_Radio_Voice :1;
            uint8_t SKA2_GSMR_Radio_Voice :1;
            uint8_t bit46 :1;
            uint8_t bit47 :1;
            uint8_t SKA1_TEST_SAND_LEVELS_SENSORS_BOGIE1 :1;//byte 6
            uint8_t SKA1_TEST_SAND_LEVELS_SENSORS_BOGIE2 :1;
            uint8_t SKA2_TEST_SAND_LEVELS_SENSORS_BOGIE1 :1;
            uint8_t SKA2_TEST_SAND_LEVELS_SENSORS_BOGIE2 :1;
            uint8_t C_Sanding_Test :1;
            uint8_t bit53 :1;
            uint8_t bit54 :1;
            uint8_t bit55 :1;
            uint8_t reserved_7;
            uint8_t reserved_8;
            uint8_t reserved_9;
            uint8_t reserved_10;
            uint8_t reserved_11;
            uint8_t reserved_12;
            uint8_t reserved_13;
            uint8_t reserved_14;
            uint8_t reserved_15;
            uint8_t reserved_16;
            uint8_t reserved_17;
            uint8_t reserved_18;
            uint8_t reserved_19;
            uint8_t reserved_20;
            uint8_t reserved_21;
            uint8_t reserved_22;
            uint8_t reserved_23;
            uint8_t reserved_24;
            uint8_t reserved_25;
            uint8_t reserved_26;
            uint8_t reserved_27;
            uint8_t reserved_28;
            uint8_t reserved_29;
            uint8_t reserved_30;
            uint8_t reserved_31;

        } bits;
        time_t last_update;
    };
};

/**
 * CCU TO APU
 * PORT NO 0x181
*/
struct ccu_to_all_apus{
    union {
        uint8_t bytes[IO_RAW_NBYTES_8];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_8)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_8)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_8)];

        struct {
            uint16_t Lifesign : 1;
            uint8_t APU_OA1_Start : 1;
            uint8_t APU_OA2_Start : 1;
            uint8_t APU_OA1_Reset : 1;
            uint8_t APU_OA2_Reset : 1;
            uint8_t APU_OA1_LV_Inhibit : 1;
            uint8_t APU_OA2_LV_Inhibit : 1;
            uint8_t bit22 : 1;
            uint8_t bit23 : 1;
            uint8_t APU_OA1_HV_Expected : 1;
            uint8_t APU_OA2_HV_Expected : 1;
            uint8_t Workshop_OA1_Left : 1;
            uint8_t Workshop_OA1_Right : 1;
            uint8_t Workshop_OA2_Left : 1;
            uint8_t Workshop_OA2_Right : 1;
            uint8_t Degraded_Mode : 1;
            uint8_t bit31 : 1;
            uint8_t reserved_4 ;
            uint16_t Catenary_Voltage ;
            uint8_t reserved_7;

        } bits;
        time_t last_update;
    };
};

/*CCU to TCU*/
/* PORT NO : 0x171*/
struct ccu_to_all_tcus{
    union {
        uint8_t bytes[IO_RAW_NBYTES_32];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_32)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_32)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_32)];

        struct {
            uint16_t Lifesign ;	//byte0
            uint8_t	TL_Enable_TC1_SKA1 : 1; //byte2
            uint8_t	TL_Enable_TC2_SKA1 : 1;
            uint8_t	TL_Enable_TC1_SKA2 : 1;
            uint8_t	TL_Enable_TC2_SKA2 : 1;
            uint8_t	TL_Normal_Rescue_SKA1 : 1;
            uint8_t	TL_Normal_Rescue_SKA2 : 1;
            uint8_t	TL_Speed_Limit_SKA1 : 1;
            uint8_t	TL_Speed_Limit_SKA2 : 1;
            uint8_t	TL_Cabs_Mode : 1;	//byte3
            uint8_t	TL_SKA1_Forward : 1;
            uint8_t	TL_SKA1_Reverse : 1;
            uint8_t	TL_SKA2_Forward : 1;
            uint8_t	TL_SKA2_Reverse : 1;
            uint8_t	TL_Traction_CutOff_SKA1 : 1;
            uint8_t	TL_Traction_CutOff_SKA2 : 1;
            uint8_t	bit31 : 1;
            uint8_t	TL_Relay_Security_Emergency_Loop_SKA1 : 1; //byte4
            uint8_t	TL_Relay_Security_Emergency_Loop_SKA2 : 1;
            uint8_t	TL_MC_S1 : 1;
            uint8_t	TL_MC_S2 : 1;
            uint8_t	TL_MC_S3 : 1;
            uint8_t	TL_MC_S4 : 1;
            uint8_t	TL_MC_S5 : 1;
            uint8_t	TL_MC_S6 : 1;
            uint8_t	STS_Cutoff_bypass : 1; //byte5
            uint8_t	TL_VCB_On_Off_OA1 : 1;
            uint8_t	TL_VCB_On_Off_OA2 : 1;
            uint8_t	VCB_Opening_Warning : 1;
            uint8_t	TC_SKA1_HV_Expected : 1;
            uint8_t	TC_SKA2_HV_Expected : 1;
            uint8_t	bit46 : 1;
            uint8_t	bit47 : 1;
            uint8_t	Cmd_Traction_Null : 1; //byte6
            uint8_t	Cmd_Traction_Cutoff : 1;
            uint8_t	Cmd_EDB_Deactivate : 1;
            uint8_t	Cmd_Speed_Limit : 1;
            uint8_t	Cmd_ASC_Mode : 1;
            uint8_t	bit53 : 1;
            uint8_t	bit54 : 1;
            uint8_t	bit55 : 1;
            uint8_t	Cmd_Traction_Reduction_Lvl1_SKA1 : 1; //byte7
            uint8_t	Cmd_Traction_Reduction_Lvl2_SKA1 : 1;
            uint8_t	Cmd_Traction_Reduction_Lvl1_SKA2 : 1;
            uint8_t	Cmd_Traction_Reduction_Lvl2_SKA2 : 1;
            uint8_t	bit60 : 1;
            uint8_t	bit61 : 1;
            uint8_t	bit62 : 1;
            uint8_t	bit63 : 1;
            uint8_t	Cmd_Reset_SKA1_TC1 : 1; //byte8
            uint8_t	Cmd_Reset_SKA1_TC2 : 1;
            uint8_t	Cmd_Reset_SKA2_TC1 : 1;
            uint8_t	Cmd_Reset_SKA2_TC2 : 1;
            uint8_t	Cmd_OOS_SKA1_TC1 : 1;
            uint8_t	Cmd_OOS_SKA1_TC2 : 1;
            uint8_t	Cmd_OOS_SKA2_TC1 : 1;
            uint8_t	Cmd_OOS_SKA2_TC2 : 1;
            uint8_t	reserved_9 ;
            uint8_t	ASC_Target ; //byte10
            uint8_t	Train_Speed ; //byte11
            uint8_t	reserved_12 ;
            uint16_t SKA1_wheel_diameter_1 ; //byte13
            uint16_t SKA1_wheel_diameter_2 ; //byte15
            uint16_t SKA1_wheel_diameter_3 ;
            uint16_t SKA1_wheel_diameter_4 ;
            uint16_t SKA2_wheel_diameter_1 ;
            uint16_t SKA2_wheel_diameter_2 ;
            uint16_t SKA2_wheel_diameter_3 ;
            uint16_t SKA2_wheel_diameter_4 ;
            uint8_t	 reserved_29 ;
            uint16_t Catenary_Voltage ; //byte30


        } bits;
        time_t last_update;
    };
};
/*CCU to WTB*/

struct dam_oa{
    union {
        uint8_t bytes[IO_RAW_NBYTES_8];
        uint16_t words[BYTES_TO_WORDS(IO_RAW_NBYTES_8)];
        uint32_t dwords[BYTES_TO_DWORDS(IO_RAW_NBYTES_8)];
        uint64_t qwords[BYTES_TO_QWORDS(IO_RAW_NBYTES_8)];

        struct {
            uint8_t id_ok : 1;
            uint8_t id_nok : 1;
            uint8_t checking_id : 1;
            uint8_t reserved: 5 ;
        } bits;
        time_t last_update;
    };
};



/*SKA  DESK RIOM ALL Messages*/
struct ska_dd_riom
{
    struct ska_dd_riom_ccu_mvb_status ska_dd_riom_ccu_mvb_status;
    struct ska_dd_riom_ccu_mvb1_inputs ska_dd_riom_ccu_mvb1_inputs;
};

/*SKA VEHICLE RIOM ALL Messages*/

struct ska_vh_riom
{
    struct ska_vh_riom_ccu_mvb_status ska_vh_riom_ccu_mvb_status;
    struct ska_vh_riom_ccu_mvb1_d_inputs ska_vh_riom_ccu_mvb1_d_inputs;
};

struct ska_dcu
{
    struct ska_vh_riom_ccu_mvb2_dcu1 ska_vh_riom_ccu_mvb2_dcu1;
    struct ska_vh_riom_ccu_mvb3_dcu2 ska_vh_riom_ccu_mvb3_dcu2;
    struct ska_vh_riom_ccu_mvb4_dcu3 ska_vh_riom_ccu_mvb4_dcu3;
    struct ska_vh_riom_ccu_mvb5_dcu4 ska_vh_riom_ccu_mvb5_dcu4;
};
struct ska_fds
{
    struct ska_vh_riom_ccu_mvb6_fds1 ska_vh_riom_ccu_mvb6_fds1;
    struct ska_vh_riom_ccu_mvb7_fds2 ska_vh_riom_ccu_mvb7_fds2;
    struct ska_vh_riom_ccu_mvb8_fds3 ska_vh_riom_ccu_mvb8_fds3;
};

struct ska_ats
{
    struct ska_vh_riom_ccu_mvb9_ats ska_vh_riom_ccu_mvb9_ats;
};

struct ska_papis
{
    struct ska_vh_riom_ccu_mvb10_papis1 ska_vh_riom_ccu_mvb10_papis1;
    struct ska_vh_riom_ccu_mvb11_papis2 ska_vh_riom_ccu_mvb11_papis2;
    struct ska_vh_riom_ccu_mvb12_papis3 ska_vh_riom_ccu_mvb12_papis3;
};

struct ska_hvac
{
    struct ska_vh_riom_ccu_mvb13_hvac1 ska_vh_riom_ccu_mvb13_hvac1;
    struct ska_vh_riom_ccu_mvb14_hvac2 ska_vh_riom_ccu_mvb14_hvac2;
    struct ska_vh_riom_ccu_mvb15_hvac3 ska_vh_riom_ccu_mvb15_hvac3;

};


struct ska_bcu
{
    struct bcu_ccu_mvb1 ska_bcu_ccu_mvb1;
    struct bcu_ccu_mvb2 ska_bcu_ccu_mvb2;

};

struct ska_tcu
{
    struct tcu_ccu_mvb1 ska_tcu_ccu_mvb1;
    struct tcu_ccu_mvb2 ska_tcu_ccu_mvb2;
};



/*OA VEHICLE RIOM  ALL Messages*/
struct oa_vh_riom {
    struct oa_vh_riom_ccu_mvb_status    oa_vh_riom_ccu_mvb_status;
    //struct oa_vh_riom_ccu_mvb_status    oa_vh_riom_r_ccu_mvb_status;  //redundant şimdilik yoq
    struct oa_vh_riom_ccu_mvb1_inputs   oa_vh_riom_ccu_mvb1_inputs;
};
struct oa_dcu
{
    struct oa_vh_riom_ccu_mvb2_dcu1 oa_vh_riom_ccu_mvb2_dcu1;
    struct oa_vh_riom_ccu_mvb3_dcu2 oa_vh_riom_ccu_mvb3_dcu2;
    struct oa_vh_riom_ccu_mvb4_dcu3 oa_vh_riom_ccu_mvb4_dcu3;
    struct oa_vh_riom_ccu_mvb5_dcu4 oa_vh_riom_ccu_mvb5_dcu4;
};

struct oa_hvac
{
    struct oa_vh_riom_ccu_mvb6_hvac1 oa_vh_riom_ccu_mvb6_hvac1;
    struct oa_vh_riom_ccu_mvb7_hvac2 oa_vh_riom_ccu_mvb7_hvac2;
};


struct oa_bcu
{
    struct bcu_ccu_mvb1 oa_bcu_ccu_mvb1;
    struct bcu_ccu_mvb2 oa_bcu_ccu_mvb2;
};


struct oa_etcs
{
    struct etcs_ccu_mvb1 oa_etcs_ccu_mvb1;
    struct etcs_ccu_mvb2 oa_etcs_ccu_mvb2;
    struct etcs_ccu_mvb3 oa_etcs_ccu_mvb3;

};
/*
#pragma pack(push, 1)
struct oa_etcs {
    struct etcs_ccu_mvb1 oa_etcs_ccu_mvb1;
    struct etcs_ccu_mvb2 oa_etcs_ccu_mvb2;
    struct etcs_ccu_mvb3 oa_etcs_ccu_mvb3;
};
#pragma pack(pop)
*/


struct oa_jru
{
    struct jru_ccu_mvb1 oa_jru_ccu_mvb1;
};


struct oa_apu
{
    struct apu_ccu_mvb1 oa_apu_ccu_mvb1;
    struct apu_ccu_mvb2 oa_apu_ccu_mvb2;
    struct apu_ccu_mvb3 oa_apu_ccu_mvb3;

};


struct dam_obj {
    char db_path[120];
    bool db_path_status;

};
//ben ekledim
struct oa_dam {
    //struct dam_oa oa_1_dam; //******
    //struct dam_oa oa_2_dam;
    struct dam_oa oa_dam;
};



/*SKA  CCU INPUT DATA*/
struct ska_ccu_input {

    uint16_t deneme;


    time_t last_update;

    struct ska_ccu_di_card ska1_ccu_di_card;
    struct ska_ccu_di_card ska2_ccu_di_card;

    struct ska_dd_riom ska_1_dd_riom;
    struct ska_dd_riom ska_2_dd_riom;

    struct ska_vh_riom ska_1_vh_riom;
    struct ska_vh_riom ska_2_vh_riom;

    struct ska_dcu ska_1_dcu;
    struct ska_dcu ska_2_dcu;

    struct ska_fds ska_1_fds;
    struct ska_fds ska_2_fds;

    struct ska_papis ska_1_papis;
    struct ska_papis ska_2_papis;

    struct ska_hvac ska_1_hvac;
    struct ska_hvac ska_2_hvac;

    struct ska_ats ska_1_ats;
    struct ska_ats ska_2_ats;

    struct ska_bcu ska_1_bcu;
    struct ska_bcu ska_2_bcu;

    struct ska_tcu ska_1_tcu1;
    struct ska_tcu ska_1_tcu2;
    struct ska_tcu ska_2_tcu1;
    struct ska_tcu ska_2_tcu2;

    struct dam_oa oa_1_dam;
    struct dam_oa oa_2_dam;

    struct oa_vh_riom oa_1_vh_riom;
    struct oa_vh_riom oa_2_vh_riom;

    struct oa_dcu oa_1_dcu;
    struct oa_dcu oa_2_dcu;

    struct oa_hvac oa_1_hvac;
    struct oa_hvac oa_2_hvac;

    struct oa_bcu oa_1_bcu;
    struct oa_bcu oa_2_bcu;

    struct oa_etcs oa_1_etcs;
    struct oa_etcs oa_2_etcs;

    struct oa_jru oa_1_jru;
    struct oa_jru oa_2_jru;

    struct oa_apu oa_1_apu;
    struct oa_apu oa_2_apu;

    //struct emulator_config emulator_config;


    struct dam_obj dam_obj;

    struct oax_jru_id oa1_jru_id;
    struct oax_jru_id oa2_jru_id;


};

typedef struct ska_ccu_input ska_ccu_input_t;



/*TODO will be filled in whilst state information filled up on the document*/
struct sf_state_holder {
    uint16_t sf_emu_status_states[2];
    uint16_t ssf_emu_config_states[2];
    uint16_t sf_train_init_states[2];
    uint16_t ssf_ccu_location_states[2];
    uint16_t ssf_ccu_direction_states[2];
    uint16_t ssf_ccu_role_states[2];
    uint16_t ssf_idm_reply_states[2];
    uint16_t ssf_idm_session_states[2];
    uint16_t ssf_idm_user_role_states[2];
    uint16_t sf_train_config_states[2];
    uint16_t ssf_emu_cac_states[2];
};

struct sf_states_definition{
    uint16_t sf_emu_status_states;
    uint16_t ssf_emu_config_states;
    uint16_t ssf_emu_coupled_vehicle_states;
    uint16_t ssf_emu_sequence_states;
    uint16_t sf_train_init_states;
    uint16_t ssf_ccu_location_states;
    uint16_t ssf_ccu_direction_states;
    uint16_t ssf_ccu_role_states;
    uint16_t ssf_idm_reply_states;
    uint16_t ssf_idm_session_states;
    uint16_t ssf_idm_second_card_states;
    uint16_t ssf_idm_user_role_states;
    uint16_t sf_train_config_states;
    uint16_t ssf_emu_cac_states;
    uint16_t ssf_hvm_earth_states;
    uint16_t ssf_hvm_line_select_states;
    uint16_t ssf_hvm_usable_line_states;
    uint16_t ssf_hvm_reset_procedure_states;
    uint16_t ssf_hvm_action_states;
    uint16_t ssf_linm_hv_level_states;
    uint16_t ssf_linm_neutral_zone_states;
    uint16_t ssf_linm_range_check_states;
    uint16_t ssf_hvd_config_states;
    uint16_t ssf_hvd_1_status_states;
    uint16_t ssf_hvd_2_status_states;
    uint16_t ssf_hvd_1_control_states;
    uint16_t ssf_hvd_2_control_states;
    uint16_t ssf_auxc_1_status_states;
    uint16_t ssf_auxc_2_status_states;
    uint16_t ssf_auxc_1_control_states;
    uint16_t ssf_auxc_2_control_states;
    uint16_t ssf_pan_1_readiness_states;
    uint16_t ssf_pan_2_readiness_states;
    uint16_t ssf_pan_1_add_control_states;
    uint16_t ssf_pan_2_add_control_states;
    uint16_t ssf_pan_1_status_states;
    uint16_t ssf_pan_2_status_states;
    uint16_t ssf_pan_1_control_states;
    uint16_t ssf_pan_2_control_states;
    uint16_t ssf_mcb_1_readiness_states;
    uint16_t ssf_mcb_2_readiness_states;
    uint16_t ssf_mcb_1_status_states;
    uint16_t ssf_mcb_2_status_states;
    uint16_t ssf_mcb_1_control_states;
    uint16_t ssf_mcb_2_control_states;
    uint16_t ssf_trf_1_readiness_states;
    uint16_t ssf_trf_2_readiness_states;
    uint16_t ssf_trf_1_temp_states;
    uint16_t ssf_trf_2_temp_states;
    uint16_t ssf_trf_1_status_states;
    uint16_t ssf_trf_2_status_states;
    uint16_t ssf_trf_1_control_states;
    uint16_t ssf_trf_2_control_states;


    uint16_t deneme;
};


/*SKA  CCU OUTPUT DATA*/
struct ska_ccu_output {
    time_t last_update;

    //struct st_error_list error_csv;
    struct sf_state_holder sf_state_holder;
    struct sf_states_definition sf_states;

    struct ska_ccu_do_card ska1_ccu_do_card;
    struct ska_ccu_do_card ska2_ccu_do_card;

    struct life_sign_counter ccu_life_sign_counter;
    struct ska_ccu_global_out_mvb1 ska_ccu_global_out_mvb1;
    struct ska_ccu_global_out_mvb2 ska_ccu_global_out_mvb2;

    struct ska_ccu_to_all_rioms_mvb1 ska_ccu_to_all_rioms_mvb1;
    struct ska_ccu_to_all_rioms_mvb2 ska_ccu_to_all_rioms_mvb2;

    struct ccu_to_all_jrus_1 ccu_to_all_jrus_1;
    struct ccu_to_all_jrus_2 ccu_to_all_jrus_2;
    struct ccu_to_all_jrus_3 ccu_to_all_jrus_3;
    struct ccu_to_all_jrus_4 ccu_to_all_jrus_4;
    struct ccu_to_all_jrus_5 ccu_to_all_jrus_5;

    struct ska_ccu_vh_riom_mvb1_d_outputs ska1_ccu_vh_riom_mvb1_d_outputs;
    struct ska_ccu_vh_riom_mvb1_d_outputs ska2_ccu_vh_riom_mvb1_d_outputs;

    struct ska_ccu_vh_riom_mvb2_dcu_hvac ska1_ccu_vh_riom_mvb2_dcu_hvac;
    struct ska_ccu_vh_riom_mvb2_dcu_hvac ska2_ccu_vh_riom_mvb2_dcu_hvac;

    struct ska_ccu_dd_riom_mvb1_d_outputs ska1_ccu_dd_riom_mvb1_d_outputs;
    struct ska_ccu_dd_riom_mvb1_d_outputs ska2_ccu_dd_riom_mvb1_d_outputs;

    struct oa_ccu_vh_riom_mvb1_d_outputs oa1_ccu_vh_riom_mvb1_d_outputs;
    struct oa_ccu_vh_riom_mvb1_d_outputs oa2_ccu_vh_riom_mvb1_d_outputs;

    struct oa_ccu_vh_riom_mvb2_dcu_hvac oa1_ccu_vh_riom_mvb2_dcu_hvac;
    struct oa_ccu_vh_riom_mvb2_dcu_hvac oa2_ccu_vh_riom_mvb2_dcu_hvac;

    struct ccu_to_all_bcus ccu_to_all_bcus;

    struct ccu_to_all_tcus ccu_to_all_tcus;

    struct ccu_to_oax_etcs ccu_to_oa1_etcs;
    struct ccu_to_oax_etcs ccu_to_oa2_etcs;
    struct ccu_to_all_etcs ccu_to_all_etcs;

    struct ccu_to_all_apus ccu_to_all_apus;

};

typedef struct ska_ccu_output ska_ccu_output_t;

struct devices_lifesign_checker
{
    union {
        uint8_t bytes[2];
        struct
        {
            uint8_t ska1_dd_riom_m_st_ok :1;
            uint8_t ska1_dd_riom_r_st_ok :1;
            uint8_t ska1_vh_riom_m_st_ok :1;
            uint8_t ska1_vh_riom_r_st_ok :1;
            uint8_t ska2_dd_riom_m_st_ok :1;
            uint8_t ska2_dd_riom_r_st_ok :1;
            uint8_t ska2_vh_riom_m_st_ok :1;
            uint8_t ska2_vh_riom_r_st_ok :1;
            uint8_t oa1_vh_riom_m_st_ok :1;
            uint8_t oa1_vh_riom_r_st_ok :1;
            uint8_t oa2_vh_riom_m_st_ok :1;
            uint8_t oa2_vh_riom_r_st_ok :1;

        }bits;
    };
};


//#pragma pack()
#ifdef __cplusplus
}
#endif

#endif /* __SHM_DATA_H__ */
