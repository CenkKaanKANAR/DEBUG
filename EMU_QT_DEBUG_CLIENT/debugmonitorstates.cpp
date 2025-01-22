#include "debugmonitorstates.h"
#include <QVBoxLayout>



void DebugMonitorStates::initVectors()
{

    ssf_emu_config_states_name = {"INIT", "WAIT", "SINGLE", "MULTIPLE"};
    ssf_emu_coupled_vehicle_states_name = {"INIT", "WAIT", "SKA1", "SKA2"};
    ssf_emu_sequence_states_name = {"INIT", "WAIT", "HEAD_TO_TAIL", "HEAD_TO_HEAD", "TAIL_TO_TAIL"};
    ssf_emu_cac_states_name = {"INIT", "WAIT", "NO_CAB", "SKA1_ACTIVE", "SKA2_ACTIVE", "SET2_ACTIVE", "ERROR"};
    ssf_emu_dir_states_name = {"INIT", "WAIT", "NEUTRAL", "FORWARD", "REVERSE"};
    ssf_emu_mascon_states_name = {"INIT", "WAIT", "NEUTRAL", "TRACTION", "BRAKE"};
    ssf_emu_pan_1_up_cmd_states_name = {"INIT", "WAIT", "NO_CMD", "CHECK_CMD", "CMD_ON", "WAIT_NEXT"};
    ssf_emu_pan_2_up_cmd_states_name = {"INIT", "WAIT", "NO_CMD", "CHECK_CMD", "CMD_ON", "WAIT_NEXT"};
    ssf_emu_mcb_close_cmd_states_name = {"INIT", "WAIT", "NO_CMD", "CHECK_CMD", "CMD_ON", "WAIT_NEXT"};
    ssf_bcu_wsp_test_states_name = {"INIT", "WAIT", "NOT_READY", "READY", "TEST_CMD"};
    ssf_ccu_location_states_name = {"INIT", "WAIT", "SKA1", "SKA2"};
    ssf_ccu_direction_states_name = {"INIT", "WAIT", "INWARD", "OUTWARD"};
    ssf_ccu_role_states_name = {"INIT", "WAIT", "DEFAULT_SET_MASTER", "DEFAULT_SET_REDUNDANT", "EMU_MASTER", "EMU_REDUNDANT", "FOLLOWING_SET_MASTER", "FOLLOWING_SET_REDUNDANT"};
    ssf_apu_1_enable_states_name = {"INIT", "WAIT", "ENABLE", "OUT_OF_SERVICE"};
    ssf_apu_2_enable_states_name = {"INIT", "WAIT", "ENABLE", "OUT_OF_SERVICE"};
    ssf_apu_1_reset_states_name = {"INIT", "WAIT", "NO_RESET", "RESET"};
    ssf_apu_2_reset_states_name = {"INIT", "WAIT", "NO_RESET", "RESET"};
    ssf_auxc_1_status_states_name = {"INIT", "WAIT", "NOT_READY", "READY", "CHECK_MOTOR", "RUNNING", "PRESS_OK", "TIMEOUT", "ERROR"};
    ssf_auxc_2_status_states_name = {"INIT", "WAIT", "NOT_READY", "READY", "CHECK_MOTOR", "RUNNING", "PRESS_OK", "TIMEOUT", "ERROR"};
    ssf_auxc_1_control_states_name = {"INIT", "WAIT", "STOP", "START", "WAIT4MIN"};
    ssf_auxc_2_control_states_name = {"INIT", "WAIT", "STOP", "START", "WAIT4MIN"};
    ssf_park_mode_states_name = {"INIT", "WAIT", "OFF", "CHECK_ON", "ON", "CHECK_OFF", "ERROR"};
    ssf_hvd_select_states_name = {"INIT", "WAIT", "OPEN_SELECTED", "DDU_REQ_CHECK", "CLOSE_SELECTED"};
    ssf_hvd_confirm_states_name = {"INIT", "WAIT", "UNCONFIRMED", "CHECK_CONFIRM", "CONFIRMED"};
    ssf_hvd_config_states_name = {"INIT", "WAIT", "WAIT_CONFIRM", "WAIT_HVD_OPEN", "WAIT_HVD_CLOSE", "DONE", "ERROR"};
    ssf_hvd_1_status_states_name = {"INIT", "WAIT", "OPENED", "CLOSED", "MOVING"};
    ssf_hvd_2_status_states_name = {"INIT", "WAIT", "OPENED", "CLOSED", "MOVING"};
    ssf_hvd_1_control_states_name = {"INIT", "WAIT", "NO_CMD", "OPEN", "OPEN_250_MS", "CLOSE", "CLOSE_250_MS", "WAIT_20_SEC", "WAIT_15_MIN"};
    ssf_hvd_2_control_states_name = {"INIT", "WAIT", "NO_CMD", "OPEN", "OPEN_250_MS", "CLOSE", "CLOSE_250_MS", "WAIT_20_SEC", "WAIT_15_MIN"};
    ssf_idm_1_reply_states_name = {"INIT", "WAIT", "ID_VALID", "ID_INVALID"};
    ssf_idm_2_reply_states_name = {"INIT", "WAIT", "ID_VALID", "ID_INVALID"};
    ssf_idm_session_states_name = {"INIT", "WAIT", "LOGOUT", "ID_CHECK", "LOGIN", "DDU_LOGOUT"};
    ssf_idm_second_card_states_name = {"INIT", "WAIT", "SECONDARY_ID"};
    ssf_idm_user_role_states_name = {"INIT", "WAIT", "DRIVER", "MAINTENANCE", "DEVELOPER_ADMIN"};
    ssf_pan_1_readiness_states_name = {"INIT", "WAIT", "NOT_READY", "READY", "ISOLATED"};
    ssf_pan_2_readiness_states_name = {"INIT", "WAIT", "NOT_READY", "READY", "ISOLATED"};
    ssf_pan_1_add_status_states_name = {"INIT", "WAIT", "WAIT_PAN_UP", "ADD_OK", "ADD_DROP"};
    ssf_pan_2_add_status_states_name = {"INIT", "WAIT", "WAIT_PAN_UP", "ADD_OK", "ADD_DROP"};
    ssf_pan_1_add_control_states_name = {"INIT", "WAIT", "RELEASE","HOLD"};
    ssf_pan_2_add_control_states_name = {"INIT", "WAIT", "RELEASE","HOLD"};
    ssf_pan_1_status_states_name = {"INIT", "WAIT", "DOWN","CHECK_UP", "UP", "UP_ERROR"};
    ssf_pan_2_status_states_name = {"INIT", "WAIT", "DOWN","CHECK_UP", "UP", "UP_ERROR"};
    ssf_pan_1_control_states_name = {"INIT", "WAIT", "LOWER","WAIT_PRESS", "RAISE"};
    ssf_pan_2_control_states_name = {"INIT", "WAIT", "LOWER","WAIT_PRESS", "RAISE"};
    ssf_mcb_1_readiness_states_name = {"INIT", "WAIT", "NOT_READY","READY"};
    ssf_mcb_2_readiness_states_name = {"INIT", "WAIT", "NOT_READY","READY"};
    ssf_mcb_1_status_states_name = {"INIT", "WAIT", "OPENED", "CHECK_CLOSE", "CLOSE_ERROR", "CLOSED", "CHECK_OPEN", "OPEN_ERROR", "CHECK_UNK_ERROR", "ERROR"};
    ssf_mcb_2_status_states_name = {"INIT", "WAIT", "OPENED", "CHECK_CLOSE", "CLOSE_ERROR", "CLOSED", "CHECK_OPEN", "OPEN_ERROR", "CHECK_UNK_ERROR", "ERROR"};
    ssf_mcb_1_control_states_name = {"INIT", "WAIT","OPEN", "CLOSE", "WARN_OPEN", "WAIT_RECLOSE"};
    ssf_mcb_2_control_states_name = {"INIT", "WAIT","OPEN", "CLOSE", "WARN_OPEN", "WAIT_RECLOSE"};
    ssf_door_close_req_states_name = {"INIT", "WAIT", "NO_REQ", "CLOSE"};
    ssf_door_right_req_states_name = {"INIT", "WAIT", "NO_REQ", "RELEASE_RIGHT", "OPEN_RIGHT"};
    ssf_door_left_req_states_name = {"INIT", "WAIT", "NO_REQ", "RELEASE_LEFT", "OPEN_LEFT"};
    ssf_door_reset_req_states_name = {"INIT", "WAIT", "NO_REQ", "EED_RESET"};
    ssf_ska_1_tcu_1_mcb_open_states_name = {"INIT", "WAIT", "OPENED_MCB", "CATENARY", "JAMMED", "UNKNOWN"};
    ssf_ska_1_tcu_2_mcb_open_states_name = {"INIT", "WAIT", "OPENED_MCB", "CATENARY", "JAMMED", "UNKNOWN"};
    ssf_ska_2_tcu_1_mcb_open_states_name = {"INIT", "WAIT", "OPENED_MCB", "CATENARY", "JAMMED", "UNKNOWN"};
    ssf_ska_2_tcu_2_mcb_open_states_name = {"INIT", "WAIT", "OPENED_MCB", "CATENARY", "JAMMED", "UNKNOWN"};
    ssf_ska_1_tcu_1_enable_states_name = {"INIT", "WAIT", "ENABLE","OUT_OF_SERVICE"};
    ssf_ska_1_tcu_2_enable_states_name = {"INIT", "WAIT", "ENABLE","OUT_OF_SERVICE"};
    ssf_ska_2_tcu_1_enable_states_name = {"INIT", "WAIT", "ENABLE","OUT_OF_SERVICE"};
    ssf_ska_2_tcu_2_enable_states_name = {"INIT", "WAIT", "ENABLE","OUT_OF_SERVICE"};
    ssf_ska_1_tcu_1_reset_states_name = {"INIT", "WAIT", "NO_RESET","RESET"};
    ssf_ska_1_tcu_2_reset_states_name = {"INIT", "WAIT", "NO_RESET","RESET"};
    ssf_ska_2_tcu_1_reset_states_name = {"INIT", "WAIT", "NO_RESET","RESET"};
    ssf_ska_2_tcu_2_reset_states_name = {"INIT", "WAIT", "NO_RESET","RESET"};
    ssf_linm_hv_level_states_name = {"INIT", "WAIT", "LOWER_10KV", "LOW_HV", "RED_PWR", "NOM_PWR", "HIGH_HV"};
    ssf_linm_neutral_zone_states_name = {"INIT", "WAIT", "ETCS_CONTROL", "IN_RANGE","ZONE_BEGIN", "CHECK_LINE", "ZONE_END"};
    ssf_linm_range_check_states_name = {"INIT", "WAIT", "IN_RANGE", "HIGH_TIMER","OUT_OF_RANGE", "CHECK_RANGE", "RANGE_TIMER", "BACK_IN_RANGE"};
    ssf_linm_1_current_check_states_name = {"INIT", "WAIT","NORMAL", "CHECK_ZERO","HV_ZERO", "CHECK_SHORT","HV_SHORT"};
    ssf_linm_2_current_check_states_name = {"INIT", "WAIT","NORMAL", "CHECK_ZERO","HV_ZERO", "CHECK_SHORT","HV_SHORT"};
    ssf_comp_select_states_name = {"INIT", "WAIT", "NONE","OA1", "OA2", "BOTH"};
    ssf_comp_1_heater_states_name = {"INIT", "WAIT","NO_HEAT", "INACTIVE","PREHEAT", "HEAT"};
    ssf_comp_2_heater_states_name = {"INIT", "WAIT","NO_HEAT", "INACTIVE","PREHEAT", "HEAT"};
    ssf_comp_1_status_states_name = {"INIT", "WAIT", "NOT_READY", "READY", "CHECK_MOTOR","RUNNING", "SUPPLY_ERROR", "HIGH_CURRENT", "RELAY_ERROR"};
    ssf_comp_2_status_states_name = {"INIT", "WAIT", "NOT_READY", "READY", "CHECK_MOTOR","RUNNING", "SUPPLY_ERROR", "HIGH_CURRENT", "RELAY_ERROR"};
    ssf_comp_1_control_states_name = {"INIT", "WAIT", "STOP","WAIT_PREHEAT", "START"};
    ssf_comp_2_control_states_name = {"INIT", "WAIT", "STOP","WAIT_PREHEAT", "START"};
    ssf_sand_enable_states_name = {"INIT", "WAIT", "ENABLED","DISABLED"};
    ssf_sand_dry_states_name = {"INIT", "WAIT", "NOT_READY", "DRY_60MIN", "PAUSE_60MIN","WAIT_330MIN", "DRY_30MIN", "PAUSE_30MIN", "DRY", "NO_DRY"};
    ssf_sand_1_heater_states_name = {"INIT", "WAIT", "NO_HEAT","HEAT"};
    ssf_sand_2_heater_states_name = {"INIT", "WAIT", "NO_HEAT","HEAT"};
    ssf_sand_control_states_name = {"INIT", "WAIT", "NO_CMD","SHORT", "LONG", "REQ_END"};
    ssf_sand_test_states_name = {"INIT", "WAIT", "READY", "TEST_CMD", "TESTING", "NOT_READY"};
    ssf_sand_level_test_states_name = {"INIT", "WAIT", "READY","TEST_CMD", "NOT_READY"};
    ssf_lvm_control_states_name = {"INIT", "WAIT", "LP_OFF", "LP_ON","LAST_HOLD"};
    ssf_trf_1_readiness_states_name = {"INIT", "WAIT", "READY", "FAULT", "CHECK_OOS", "OUT_OF_SERVICE"};
    ssf_trf_2_readiness_states_name = {"INIT", "WAIT", "READY", "FAULT", "CHECK_OOS", "OUT_OF_SERVICE"};
    ssf_trf_1_temp_states_name = {"INIT", "WAIT", "NORMAL","OVER60", "OVER90", "OVER110"};
    ssf_trf_2_temp_states_name = {"INIT", "WAIT", "NORMAL", "OVER60", "OVER90", "OVER110"};
    ssf_trf_1_status_states_name = {"INIT", "WAIT", "OFF", "LOW", "CHECK_FULL","FULL", "CHECK_LOW", "FULL_ERROR", "LOW_ERROR"};
    ssf_trf_2_status_states_name = {"INIT", "WAIT", "OFF", "LOW", "CHECK_FULL","FULL", "CHECK_LOW", "FULL_ERROR", "LOW_ERROR"};
    ssf_trf_1_control_states_name = {"INIT", "WAIT", "NO_CMD","LOW_CMD", "FULL_CMD"};
    ssf_trf_2_control_states_name = {"INIT", "WAIT", "NO_CMD","LOW_CMD", "FULL_CMD"};
    ssf_hvm_earth_states_name = {"INIT", "WAIT", "ERROR", "SERVICE", "YK_EXTRACTED", "EARTH"};
    ssf_hvm_line_select_states_name = {"INIT", "WAIT", "NO_LINE","OA1", "OA2"};
    ssf_hvm_usable_line_states_name = {"INIT", "WAIT", "ALL_USABLE", "OA1_USABLE", "OA2_USABLE", "NONE_USABLE"};
    ssf_hvm_reset_procedure_states_name = {"INIT", "WAIT", "NO_RESET", "CHECK_COND","INIT_HV_LINE", "DR_DECIDE", "DR_PAN1_UP", "DR_MCB1_CLOSE","CHECK_OC1", "DR_MCB1_OPEN", "DR_PAN1_DOWN", "DR_PAN2_UP","DR_MCB2_CLOSE", "CHECK_OC2", "DR_MCB2_OPEN", "DR_PAN2_DOWN","OC1_DETECTED", "OC_PAN1_DOWN", "OC2_DETECTED", "OC_PAN2_DOWN"};
    ssf_hvm_action_states_name = {"INIT", "WAIT", "NO_ACTION", "HVD_IN", "HVD_OUT","PAN_IN", "PAN_MCB_OUT", "MCB_BACK_IN", "MCB_IN", "MCB_OUT","ALL_IN", "ALL_OUT", "WAIT_MCB_OUT", "WAIT_ALL_OUT"};
    ssf_susp_fault_lamp_states_name = {"INIT", "WAIT","OFF", "BLINK_ON","BLINK_OFF", "ON"};
    sf_stat_states_name = {"INIT", "WAIT"};


    stateCounts = {
        ssf_emu_config_states_name.size(),
        ssf_emu_coupled_vehicle_states_name.size(),
        ssf_emu_sequence_states_name.size(),
        ssf_emu_cac_states_name.size(),
        ssf_emu_dir_states_name.size(),
        ssf_emu_mascon_states_name.size(),
        ssf_emu_pan_1_up_cmd_states_name.size(),
        ssf_emu_pan_2_up_cmd_states_name.size(),
        ssf_emu_mcb_close_cmd_states_name.size(),
        ssf_bcu_wsp_test_states_name.size(),
        ssf_ccu_location_states_name.size(),
        ssf_ccu_direction_states_name.size(),
        ssf_ccu_role_states_name.size(),
        ssf_apu_1_enable_states_name.size(),
        ssf_apu_2_enable_states_name.size(),
        ssf_apu_1_reset_states_name.size(),
        ssf_apu_2_reset_states_name.size(),
        ssf_auxc_1_status_states_name.size(),
        ssf_auxc_2_status_states_name.size(),
        ssf_auxc_1_control_states_name.size(),
        ssf_auxc_2_control_states_name.size(),
        ssf_park_mode_states_name.size(),
        ssf_hvd_select_states_name.size(),
        ssf_hvd_confirm_states_name.size(),
        ssf_hvd_config_states_name.size(),
        ssf_hvd_1_status_states_name.size(),
        ssf_hvd_2_status_states_name.size(),
        ssf_hvd_1_control_states_name.size(),
        ssf_hvd_2_control_states_name.size(),
        ssf_idm_1_reply_states_name.size(),
        ssf_idm_2_reply_states_name.size(),
        ssf_idm_session_states_name.size(),
        ssf_idm_second_card_states_name.size(),
        ssf_idm_user_role_states_name.size(),
        ssf_pan_1_readiness_states_name.size(),
        ssf_pan_2_readiness_states_name.size(),
        ssf_pan_1_add_status_states_name.size(),
        ssf_pan_2_add_status_states_name.size(),
        ssf_pan_1_add_control_states_name.size(),
        ssf_pan_2_add_control_states_name.size(),
        ssf_pan_1_status_states_name.size(),
        ssf_pan_2_status_states_name.size(),
        ssf_pan_1_control_states_name.size(),
        ssf_pan_2_control_states_name.size(),
        ssf_mcb_1_readiness_states_name.size(),
        ssf_mcb_2_readiness_states_name.size(),
        ssf_mcb_1_status_states_name.size(),
        ssf_mcb_2_status_states_name.size(),
        ssf_mcb_1_control_states_name.size(),
        ssf_mcb_2_control_states_name.size(),
        ssf_door_close_req_states_name.size(),
        ssf_door_right_req_states_name.size(),
        ssf_door_left_req_states_name.size(),
        ssf_door_reset_req_states_name.size(),
        ssf_ska_1_tcu_1_mcb_open_states_name.size(),
        ssf_ska_1_tcu_2_mcb_open_states_name.size(),
        ssf_ska_2_tcu_1_mcb_open_states_name.size(),
        ssf_ska_2_tcu_2_mcb_open_states_name.size(),
        ssf_ska_1_tcu_1_enable_states_name.size(),
        ssf_ska_1_tcu_2_enable_states_name.size(),
        ssf_ska_2_tcu_1_enable_states_name.size(),
        ssf_ska_2_tcu_2_enable_states_name.size(),
        ssf_ska_1_tcu_1_reset_states_name.size(),
        ssf_ska_1_tcu_2_reset_states_name.size(),
        ssf_ska_2_tcu_1_reset_states_name.size(),
        ssf_ska_2_tcu_2_reset_states_name.size(),
        ssf_linm_hv_level_states_name.size(),
        ssf_linm_neutral_zone_states_name.size(),
        ssf_linm_range_check_states_name.size(),
        ssf_linm_1_current_check_states_name.size(),
        ssf_linm_2_current_check_states_name.size(),
        ssf_comp_select_states_name.size(),
        ssf_comp_1_heater_states_name.size(),
        ssf_comp_2_heater_states_name.size(),
        ssf_comp_1_status_states_name.size(),
        ssf_comp_2_status_states_name.size(),
        ssf_comp_1_control_states_name.size(),
        ssf_comp_2_control_states_name.size(),
        ssf_sand_enable_states_name.size(),
        ssf_sand_dry_states_name.size(),
        ssf_sand_1_heater_states_name.size(),
        ssf_sand_2_heater_states_name.size(),
        ssf_sand_control_states_name.size(),
        ssf_sand_test_states_name.size(),
        ssf_sand_level_test_states_name.size(),
        ssf_lvm_control_states_name.size(),
        ssf_trf_1_readiness_states_name.size(),
        ssf_trf_2_readiness_states_name.size(),
        ssf_trf_1_temp_states_name.size(),
        ssf_trf_2_temp_states_name.size(),
        ssf_trf_1_status_states_name.size(),
        ssf_trf_2_status_states_name.size(),
        ssf_trf_1_control_states_name.size(),
        ssf_trf_2_control_states_name.size(),
        ssf_hvm_earth_states_name.size(),
        ssf_hvm_line_select_states_name.size(),
        ssf_hvm_usable_line_states_name.size(),
        ssf_hvm_reset_procedure_states_name.size(),
        ssf_hvm_action_states_name.size(),
        ssf_susp_fault_lamp_states_name.size(),
        sf_stat_states_name.size()
    };

    functionNames

        << "ssf_emu_config"
        << "ssf_emu_coupled_vehicle"
        << "ssf_emu_sequence"
        << "ssf_emu_cac"
        << "ssf_emu_dir"
        << "ssf_emu_mascon"
        << "ssf_emu_pan_1_up_cmd"
        << "ssf_emu_pan_2_up_cmd"
        << "ssf_emu_mcb_close_cmd"
        << "ssf_bcu_wsp_test"
        << "ssf_ccu_location"
        << "ssf_ccu_direction"
        << "ssf_ccu_role"
        << "ssf_apu_1_enable"
        << "ssf_apu_2_enable"
        << "ssf_apu_1_reset"
        << "ssf_apu_2_reset"
        << "ssf_auxc_1_status"
        << "ssf_auxc_2_status"
        << "ssf_auxc_1_control"
        << "ssf_auxc_2_control"
        << "ssf_park_mode"
        << "ssf_hvd_select"
        << "ssf_hvd_confirm"
        << "ssf_hvd_config"
        << "ssf_hvd_1_status"
        << "ssf_hvd_2_status"
        << "ssf_hvd_1_control"
        << "ssf_hvd_2_control"
        << "ssf_idm_1_reply"
        << "ssf_idm_2_reply"
        << "ssf_idm_session"
        << "ssf_idm_second_card"
        << "ssf_idm_user_role"
        << "ssf_pan_1_readiness"
        << "ssf_pan_2_readiness"
        << "ssf_pan_1_add_status"
        << "ssf_pan_2_add_status"
        << "ssf_pan_1_add_control"
        << "ssf_pan_2_add_control"
        << "ssf_pan_1_status"
        << "ssf_pan_2_status"
        << "ssf_pan_1_control"
        << "ssf_pan_2_control"
        << "ssf_mcb_1_readiness"
        << "ssf_mcb_2_readiness"
        << "ssf_mcb_1_status"
        << "ssf_mcb_2_status"
        << "ssf_mcb_1_control"
        << "ssf_mcb_2_control"
        << "ssf_door_close_req"
        << "ssf_door_right_req"
        << "ssf_door_left_req"
        << "ssf_door_reset_req"
        << "ssf_ska_1_tcu_1_mcb_open"
        << "ssf_ska_1_tcu_2_mcb_open"
        << "ssf_ska_2_tcu_1_mcb_open"
        << "ssf_ska_2_tcu_2_mcb_open"
        << "ssf_ska_1_tcu_1_enable"
        << "ssf_ska_1_tcu_2_enable"
        << "ssf_ska_2_tcu_1_enable"
        << "ssf_ska_2_tcu_2_enable"
        << "ssf_ska_1_tcu_1_reset"
        << "ssf_ska_1_tcu_2_reset"
        << "ssf_ska_2_tcu_1_reset"
        << "ssf_ska_2_tcu_2_reset"
        << "ssf_linm_hv_level"
        << "ssf_linm_neutral_zone"
        << "ssf_linm_range_check"
        << "ssf_linm_1_current_check"
        << "ssf_linm_2_current_check"
        << "ssf_comp_select"
        << "ssf_comp_1_heater"
        << "ssf_comp_2_heater"
        << "ssf_comp_1_status"
        << "ssf_comp_2_status"
        << "ssf_comp_1_control"
        << "ssf_comp_2_control"
        << "ssf_sand_enable"
        << "ssf_sand_dry"
        << "ssf_sand_1_heater"
        << "ssf_sand_2_heater"
        << "ssf_sand_control"
        << "ssf_sand_test"
        << "ssf_sand_level_test"
        << "ssf_lvm_control"
        << "ssf_trf_1_readiness"
        << "ssf_trf_2_readiness"
        << "ssf_trf_1_temp"
        << "ssf_trf_2_temp"
        << "ssf_trf_1_status"
        << "ssf_trf_2_status"
        << "ssf_trf_1_control"
        << "ssf_trf_2_control"
        << "ssf_hvm_earth"
        << "ssf_hvm_line_select"
        << "ssf_hvm_usable_line"
        << "ssf_hvm_reset_procedure"
        << "ssf_hvm_action"
        << "ssf_susp_fault_lamp"
        << "sf_stat"

    ;

    stateNames = {

      ssf_emu_config_states_name,
      ssf_emu_coupled_vehicle_states_name ,
      ssf_emu_sequence_states_name ,
      ssf_emu_cac_states_name ,
      ssf_emu_dir_states_name ,
      ssf_emu_mascon_states_name ,
      ssf_emu_pan_1_up_cmd_states_name ,
      ssf_emu_pan_2_up_cmd_states_name ,
      ssf_emu_mcb_close_cmd_states_name ,
      ssf_bcu_wsp_test_states_name,
      ssf_ccu_location_states_name ,
      ssf_ccu_direction_states_name ,
      ssf_ccu_role_states_name ,
      ssf_apu_1_enable_states_name ,
      ssf_apu_2_enable_states_name,
      ssf_apu_1_reset_states_name ,
      ssf_apu_2_reset_states_name ,
      ssf_auxc_1_status_states_name ,
      ssf_auxc_2_status_states_name ,
      ssf_auxc_1_control_states_name ,
      ssf_auxc_2_control_states_name ,
      ssf_park_mode_states_name ,
      ssf_hvd_select_states_name ,
      ssf_hvd_confirm_states_name ,
      ssf_hvd_config_states_name,
      ssf_hvd_1_status_states_name ,
      ssf_hvd_2_status_states_name ,
      ssf_hvd_1_control_states_name,
      ssf_hvd_2_control_states_name,
      ssf_idm_1_reply_states_name ,
      ssf_idm_2_reply_states_name  ,
      ssf_idm_session_states_name ,
      ssf_idm_second_card_states_name ,
      ssf_idm_user_role_states_name,
      ssf_pan_1_readiness_states_name ,
      ssf_pan_2_readiness_states_name ,
      ssf_pan_1_add_status_states_name ,
      ssf_pan_2_add_status_states_name ,
      ssf_pan_1_add_control_states_name ,
      ssf_pan_2_add_control_states_name ,
      ssf_pan_1_status_states_name ,
      ssf_pan_2_status_states_name ,
      ssf_pan_1_control_states_name ,
      ssf_pan_2_control_states_name ,
      ssf_mcb_1_readiness_states_name ,
      ssf_mcb_2_readiness_states_name ,
      ssf_mcb_1_status_states_name ,
      ssf_mcb_2_status_states_name ,
      ssf_mcb_1_control_states_name ,
      ssf_mcb_2_control_states_name ,
      ssf_door_close_req_states_name ,
      ssf_door_right_req_states_name ,
      ssf_door_left_req_states_name ,
      ssf_door_reset_req_states_name ,
      ssf_ska_1_tcu_1_mcb_open_states_name,
      ssf_ska_1_tcu_2_mcb_open_states_name,
      ssf_ska_2_tcu_1_mcb_open_states_name,
      ssf_ska_2_tcu_2_mcb_open_states_name,
      ssf_ska_1_tcu_1_enable_states_name ,
      ssf_ska_1_tcu_2_enable_states_name ,
      ssf_ska_2_tcu_1_enable_states_name ,
      ssf_ska_2_tcu_2_enable_states_name ,
      ssf_ska_1_tcu_1_reset_states_name ,
      ssf_ska_1_tcu_2_reset_states_name ,
      ssf_ska_2_tcu_1_reset_states_name ,
      ssf_ska_2_tcu_2_reset_states_name ,
      ssf_linm_hv_level_states_name,
      ssf_linm_neutral_zone_states_name ,
      ssf_linm_range_check_states_name,
      ssf_linm_1_current_check_states_name,
      ssf_linm_2_current_check_states_name,
      ssf_comp_select_states_name  ,
      ssf_comp_1_heater_states_name ,
      ssf_comp_2_heater_states_name ,
      ssf_comp_1_status_states_name ,
      ssf_comp_2_status_states_name ,
      ssf_comp_1_control_states_name ,
      ssf_comp_2_control_states_name ,
      ssf_sand_enable_states_name  ,
      ssf_sand_dry_states_name,
      ssf_sand_1_heater_states_name ,
      ssf_sand_2_heater_states_name ,
      ssf_sand_control_states_name ,
      ssf_sand_test_states_name ,
      ssf_sand_level_test_states_name ,
      ssf_lvm_control_states_name ,
      ssf_trf_1_readiness_states_name ,
      ssf_trf_2_readiness_states_name ,
      ssf_trf_1_temp_states_name ,
      ssf_trf_2_temp_states_name,
      ssf_trf_1_status_states_name ,
      ssf_trf_2_status_states_name,
      ssf_trf_1_control_states_name ,
      ssf_trf_2_control_states_name,
      ssf_hvm_earth_states_name,
      ssf_hvm_line_select_states_name,
      ssf_hvm_usable_line_states_name,
      ssf_hvm_reset_procedure_states_name,
      ssf_hvm_action_states_name,
      ssf_susp_fault_lamp_states_name,
      sf_stat_states_name



    };

}
DebugMonitorStates::DebugMonitorStates(QWidget *parent)
    : QWidget(parent),
    table(new QTableWidget(this)),
    openUdpMessagesButton(new QPushButton("Open UDP Messages", this)),
    udpMessagesDialog(new UdpMessagesDialog(this)),systemFunctionComboBox(new QComboBox(this)),
    stateLabel(new QLabel(this))// Her bir nesne için doğru üyelik tanımlanmalı
    //layout(new QVBoxLayout(this))
    //udpSocket(new QUdpSocket(this))

{
    // Initialize the layout
    //QVBoxLayout *layout = new QVBoxLayout(this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    setLayout(layout);  // Set the layout for the widget


    // Initialize UDP socket
    udpSocket = new QUdpSocket(this);

    //QHostAddress ipAddress("192.128.56.28");
    //quint16 port = 7000;

    connect(udpSocket, &QUdpSocket::readyRead, this, &DebugMonitorStates::onReadyRead);

    // Optionally, bind the socket to a specific port (e.g., 12345)
    udpSocket->bind(12345, QUdpSocket::ShareAddress);

    //connect(this,&DebugMonitorStates::customSignal,this,&DebugMonitorStates::updateTable,Qt::QueuedConnection);


    initVectors();
    setupTable();  // Setup the table after setting the layout
    setupUdpDialog(); //Setup pushbutton and UDP Dialog to monitor coming udp state messages
    setupOptionSystemFunc(); //Setup combobox to view a System Function States
    // Ensure button and table are added to the layout in setupTable()



}

DebugMonitorStates::~DebugMonitorStates() {
    //delete table;
        // QWidget automatically handles child widget deletion, so no need to delete table manually
}

void DebugMonitorStates::setupTable() {

    table->setColumnCount(3);
    table->setHorizontalHeaderLabels({"Function", "Pre-State", "Current State"});
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);



    // Initialize table with "Unknown" values
    table->setRowCount(101);  // Adjust row count based on the number of functions
    for (int row = 0; row < 101; ++row) {  // 5 functions in total
        table->setItem(row, 0, new QTableWidgetItem(functionNames.at(row)));
        table->setItem(row,1,new QTableWidgetItem("Unknown"));
        table->setItem(row, 1, new QTableWidgetItem("Unknown"));
        table->setItem(row, 2, new QTableWidgetItem("Unknown"));
    }
    table->resizeColumnsToContents();

    // Get the layout
    //QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(this->layout());
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(this->layout());
    if (layout) {
        // Add button first, then the table

        layout->addWidget(table);
        //mainLayout->addLayout(layout);
    }

    // Create test button
    // Test button callback
    QPushButton *testButton = new QPushButton("Load Test Data", this);
    connect(testButton, &QPushButton::clicked, [this]() {
        QByteArray testData(50, 0); // 50-byte length test data

        // Test data for each function and their corresponding pre-state and current-state
        testData[40] = 0; // Pre-state for ssf_emu_config_states_name (Function 1)
        testData[41] = 3; // Current-state for ssf_emu_config_states_name
        testData[42] = 1; // Pre-state for ssf_emu_coupled_vehicle_states_name (Function 2)
        testData[43] = 2; // Current-state for ssf_emu_coupled_vehicle_states_name
        testData[44] = 0; // Pre-state for ssf_emu_sequence_states_name (Function 3)
        testData[45] = 4; // Current-state for ssf_emu_sequence_states_name
        testData[46] = 2; // Pre-state for ssf_emu_cac_states_name (Function 4)
        testData[47] = 6; // Current-state for ssf_emu_cac_states_name
        testData[48] = 3; // Pre-state for ssf_emu_dir_states_name (Function 5)
        testData[49] = 4; // Current-state for ssf_emu_dir_states_name

        testData[50] = 1; // Pre-state for ssf_emu_mascon_states_name (Function 6)
        testData[51] = 3; // Current-state for ssf_emu_mascon_states_name
        testData[52] = 2; // Pre-state for ssf_ccu_location_states_name (Function 7)
        testData[52] = 3; // Current-state for ssf_ccu_location_states_name
        testData[54] = 0; // Pre-state for ssf_ccu_direction_states_name (Function 8)
        testData[55] = 2; // Current-state for ssf_ccu_direction_states_name

        testData[56] = 2; // Pre-state for ssf_ccu_role_states_name (Function 9)
        testData[57] = 4; // Current-state for ssf_ccu_role_states_name
        testData[58] = 1; // Pre-state for ssf_idm_reply_states_name (Function 10)
        testData[59] = 3; // Current-state for ssf_idm_reply_states_name
        testData[60] = 2; // Pre-state for ssf_idm_session_states_name (Function 11)
        testData[61] = 4; // Current-state for ssf_idm_session_states_name
        qDebug() << " TEST VERİSİ" << testData;
        parseSystemStates(testData);
    });
    layout->addWidget(testButton);


}




void DebugMonitorStates::parseSystemStates(const QByteArray& recv_data) {


    int offset = 0;
    QList<SystemFunctionState> states;

    //QList<std::vector<std::string>> stateNames
    //QList<const char**> stateNames


    QByteArray data = recv_data.mid(129,202);
    //QByteArray data = recv_data.mid(0,202);

    // Gelen veriyi DebugMonitorStates'den gelen pencereye iletelim
    if (udpMessagesDialog) {
        udpMessagesDialog->appendMessage(data, data.size());  // Veriyi ekle
    }


    /*for (int i = 0; i < stateNames.size(); i++) {
        int preStateIndex = static_cast<unsigned char>(data[offset]); // Pre-state
        int currentStateIndex = static_cast<unsigned char>(data[offset + 1]); // Current-state

        //
        if (preStateIndex < 0 || currentStateIndex < 0 || preStateIndex >= stateCounts[i]
            || currentStateIndex >= stateCounts[i]) {
            qDebug() << "STATE ATLAMA:" << i;
            qDebug() << "preStateIndex:" << preStateIndex;
            qDebug() << "stateNames[i][preStateIndex]:" << QString::fromStdString(stateNames[i][preStateIndex]);
            offset += 1;
            continue; // Invalid data
        }

        states.append({
            functionNames.at(i),
            QString::fromStdString(stateNames[i][preStateIndex]), // std::string -> QString
            QString::fromStdString(stateNames[i][currentStateIndex]) // std::string -> QString
        });

        offset += 2; // Advance by 1 bytes
    }*/

    for (int i = 0; i < stateNames.size(); i++) {

        int currentStateIndex = static_cast<unsigned char>(data[offset]); // Current-state
        int preStateIndex = static_cast<unsigned char>(data[offset + 1]); // Pre-state
        //
        if (preStateIndex < 0 || currentStateIndex < 0 || preStateIndex >= stateCounts[i]
            || currentStateIndex >= stateCounts[i]) {
            qDebug() << "STATE ATLAMA:" << i;
            //qDebug() << "currentStateIndex:" << currentStateIndex;
            //qDebug() << "stateNames[i][currentStateIndex]:" << QString::fromStdString(stateNames[i][currentStateIndex]);
            states.append({
                functionNames.at(i),
                QString::fromStdString("WRONG"), // std::string -> QString
                QString::fromStdString("WRONG") // std::string -> QString
            });
            offset += 1;
            continue; // Invalid data
        }

        states.append({
            functionNames.at(i),
            QString::fromStdString(stateNames[i][preStateIndex]), // std::string -> QString
            QString::fromStdString(stateNames[i][currentStateIndex]) // std::string -> QString
        });

        offset += 2; // Advance by 1 bytes
    }

    qDebug() << "SIZE OF STATES :" << states.size();
    qDebug() << "SIZE OF STATENAMES :" << stateNames.size();
    updateTable(states);



}

void DebugMonitorStates::updateTable(const QList<SystemFunctionState> &states) {


    table->setRowCount(states.size());

    for (int row = 0; row < states.size(); ++row) {
        //table->setItem(row, 0, new QTableWidgetItem(states[row].functionName));
        table->setItem(row, 1, new QTableWidgetItem(states[row].preState));
        table->setItem(row, 2, new QTableWidgetItem(states[row].currentState));

        // Highlight changes
        if (states[row].preState != states[row].currentState) {
            highlightStateChange(table->item(row, 2), true);
        }
        if (table->item(row, 1) && table->item(row, 1)->text() == "WRONG") {
            table->item(row, 1)->setBackground(Qt::red);
            qDebug() << "RED COLOR";
        }
       if (table->item(row, 2) && table->item(row, 2)->text() == "WRONG") {
            table->item(row, 2)->setBackground(Qt::red);
            qDebug() << "RED COLOR";
        }

    }

    table->resizeColumnsToContents();
}

void DebugMonitorStates::highlightStateChange(QTableWidgetItem *item, bool isChanged) {

    if (isChanged) {
        item->setBackground(Qt::yellow);
    }
    else {
        item->setBackground(Qt::white);
    }
}



void DebugMonitorStates::onReadyRead() {

    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        qint64 size = udpSocket->readDatagram(datagram.data(), datagram.size());

        if (size == -1) {
            qWarning() << "Error reading datagram from UDP socket!";
            return;
        }
        // Gelen veriyi DebugMonitorStates'den gelen pencereye iletelim
        if (udpMessagesDialog) {
            udpMessagesDialog->appendMessage(datagram, size);  // Veriyi ekle
        }
        qDebug() << "onReadyRead okunan veri : " << datagram;
        // Gelen veriyi parseSystemStates fonksiyonuna ilet
        parseSystemStates(datagram);
    }


}


void DebugMonitorStates::setupUdpDialog()
{

    // Get the layout
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(this->layout());
    if (layout) {
        layout->addWidget(openUdpMessagesButton);

    }

    connect(openUdpMessagesButton, &QPushButton::clicked, this, &DebugMonitorStates::openUdpMessages);



}

void DebugMonitorStates::openUdpMessages()
{
    udpMessagesDialog->exec();  // Dialog'u modal olarak açıyoruz
}

void DebugMonitorStates::setupOptionSystemFunc()
{
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(this->layout());

    systemFunctionComboBox->addItem("SELECT A SYSTEM FUCTION");
    for(int i = 0; i < functionNames.size(); i ++) {
        systemFunctionComboBox->addItem(functionNames[i]);
    }


    // Add combo box and label to the layout
    layout->addWidget(systemFunctionComboBox);
    layout->addWidget(stateLabel);
    customizeCombobox();

    // Connect the combo box change signal to the slot
    connect(systemFunctionComboBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &DebugMonitorStates::onStateFunctionChanged);


}


//Combobox işlemleri
void DebugMonitorStates::onStateFunctionChanged(int index)
{
    QStringList states;

    switch (index) {
    case 1:  // ssf_emu_config_states_name
        states = QStringList{"INIT", "WAIT", "SINGLE", "MULTIPLE"};
        break;
    case 2:  // ssf_emu_coupled_vehicle_states_name
        states = QStringList{"INIT", "WAIT", "SKA1", "SKA2"};
        break;
    case 3:  // ssf_emu_sequence_states_name
        states = QStringList{"INIT", "WAIT", "HEAD_TO_TAIL", "HEAD_TO_HEAD", "TAIL_TO_TAIL"};
        break;
    case 4:  // ssf_emu_cac_states_name
        states = QStringList{"INIT", "WAIT", "NO_CAB", "SKA1_ACTIVE", "SKA2_ACTIVE", "SET2_ACTIVE", "ERROR"};
        break;
    case 5:  // ssf_emu_dir_states_name
        states = QStringList {"INIT", "WAIT", "NEUTRAL", "FORWARD", "REVERSE"};
        break;
    case 6:  // ssf_emu_mascon_states_name
        states = QStringList {"INIT", "WAIT", "NEUTRAL", "TRACTION", "BRAKE"};
        break;
    case 7:  // ssf_emu_pan_1_up_cmd_states_name
        states = QStringList {"INIT", "WAIT", "NO_CMD", "CHECK_CMD", "CMD_ON", "WAIT_NEXT"};
        break;
    case 8:  // ssf_emu_pan_2_up_cmd_states_name
        states = QStringList  {"INIT", "WAIT", "NO_CMD", "CHECK_CMD", "CMD_ON", "WAIT_NEXT"};
        break;
    case 9:  // ssf_emu_mcb_close_cmd_states_name
        states = QStringList {"INIT", "WAIT", "NO_CMD", "CHECK_CMD", "CMD_ON", "WAIT_NEXT"};
        break;
    case 10:  // ssf_bcu_wsp_test_states_name
        states = QStringList {"INIT", "WAIT", "NOT_READY", "READY", "TEST_CMD"};
        break;
    case 11:  // ssf_ccu_location_states_name
        states = QStringList {"INIT", "WAIT", "SKA1", "SKA2"};
        break;
    case 12:  // ssf_ccu_direction_states_name
        states = QStringList {"INIT", "WAIT", "INWARD", "OUTWARD"};
        break;
    case 13:  // ssf_ccu_role_states_name
        states = QStringList {"INIT", "WAIT", "DEFAULT_SET_MASTER", "DEFAULT_SET_REDUNDANT", "EMU_MASTER", "EMU_REDUNDANT", "FOLLOWING_SET_MASTER", "FOLLOWING_SET_REDUNDANT"};
        break;
    case 14:  // ssf_apu_1_enable_states_name
        states = QStringList {"INIT", "WAIT", "ENABLE", "OUT_OF_SERVICE"};
        break;
    case 15:  // ssf_apu_2_enable_states_name
        states = QStringList {"INIT", "WAIT", "ENABLE", "OUT_OF_SERVICE"};
        break;
    case 16:  // ssf_apu_1_reset_states_name
        states = QStringList {"INIT", "WAIT", "NO_RESET", "RESET"};
        break;
    case 17:  // ssf_apu_2_reset_states_name
        states = QStringList {"INIT", "WAIT", "NO_RESET", "RESET"};
        break;
    case 18:  // ssf_auxc_1_status_states_name
        states = QStringList {"INIT", "WAIT", "NOT_READY", "READY", "CHECK_MOTOR", "RUNNING", "PRESS_OK", "TIMEOUT", "ERROR"};
        break;
    case 19:  // ssf_auxc_2_status_states_name
        states = QStringList {"INIT", "WAIT", "NOT_READY", "READY", "CHECK_MOTOR", "RUNNING", "PRESS_OK", "TIMEOUT", "ERROR"};
        break;
    case 20:  // ssf_auxc_1_control_states_name
        states = QStringList {"INIT", "WAIT", "STOP", "START", "WAIT4MIN"};
        break;
    case 21:  // ssf_auxc_2_control_states_name
        states = QStringList {"INIT", "WAIT", "STOP", "START", "WAIT4MIN"};
        break;
    case 22:  // ssf_park_mode_states_name
        states = QStringList  {"INIT", "WAIT", "OFF", "CHECK_ON", "ON", "CHECK_OFF", "ERROR"};
        break;
    case 23:  // ssf_hvd_select_states_name
        states = QStringList  {"INIT", "WAIT", "OPEN_SELECTED", "DDU_REQ_CHECK", "CLOSE_SELECTED"};
        break;
    case 24:  // ssf_hvd_confirm_states_name
        states = QStringList  {"INIT", "WAIT", "UNCONFIRMED", "CHECK_CONFIRM", "CONFIRMED"};
        break;
    case 25:  // ssf_hvd_config_states_name
        states = QStringList  {"INIT", "WAIT", "WAIT_CONFIRM", "WAIT_HVD_OPEN", "WAIT_HVD_CLOSE", "DONE", "ERROR"};
        break;
    case 26:  // ssf_hvd_1_status_states_name
        states = QStringList {"INIT", "WAIT", "OPENED", "CLOSED", "MOVING"};
        break;
    case 27:  // ssf_hvd_2_status_states_name
        states = QStringList {"INIT", "WAIT", "OPENED", "CLOSED", "MOVING"};
        break;
    case 28:  // ssf_hvd_1_control_states_name
        states = QStringList {"INIT", "WAIT", "NO_CMD", "OPEN", "OPEN_250_MS", "CLOSE", "CLOSE_250_MS", "WAIT_20_SEC", "WAIT_15_MIN"};
        break;
    case 29:  // ssf_hvd_2_control_states_name
        states = QStringList {"INIT", "WAIT", "NO_CMD", "OPEN", "OPEN_250_MS", "CLOSE", "CLOSE_250_MS", "WAIT_20_SEC", "WAIT_15_MIN"};
        break;
    case 30:  // ssf_idm_1_reply_states_name
        states = QStringList {"INIT", "WAIT", "ID_VALID", "ID_INVALID"};
        break;
    case 31:  // ssf_idm_2_reply_states_name
        states = QStringList {"INIT", "WAIT", "ID_VALID", "ID_INVALID"};
        break;
    case 32:  // ssf_idm_session_states_name
        states = QStringList {"INIT", "WAIT", "LOGOUT", "ID_CHECK", "LOGIN", "DDU_LOGOUT"};
        break;
    case 33:  // ssf_idm_second_card_states_name
        states = QStringList {"INIT", "WAIT", "SECONDARY_ID"};
        break;
    case 34:  // ssf_idm_user_role_states_name
        states = QStringList {"INIT", "WAIT", "DRIVER", "MAINTENANCE", "DEVELOPER_ADMIN"};
        break;
        break;
    case 35:  // ssf_pan_1_readiness_states_name
        states = QStringList{"INIT", "WAIT", "NOT_READY", "READY", "ISOLATED"};
        break;
    case 36:  // ssf_pan_2_readiness_states_name
        states = QStringList{"INIT", "WAIT", "NOT_READY", "READY", "ISOLATED"};
        break;
    case 37:  // ssf_pan_1_add_status_states_name
        states = QStringList{"INIT", "WAIT", "WAIT_PAN_UP", "ADD_OK", "ADD_DROP"};
        break;
    case 38:  // ssf_pan_2_add_status_states_name
        states = QStringList{"INIT", "WAIT", "WAIT_PAN_UP", "ADD_OK", "ADD_DROP"};
        break;
    case 39:  // ssf_pan_1_add_control_states_name
        states = QStringList{"INIT", "WAIT", "RELEASE", "HOLD"};
        break;
    case 40:  // ssf_pan_2_add_control_states_name
        states = QStringList{"INIT", "WAIT", "RELEASE", "HOLD"};
        break;
    case 41:  // ssf_pan_1_status_states_name
        states = QStringList{"INIT", "WAIT", "DOWN", "CHECK_UP", "UP", "UP_ERROR"};
        break;
    case 42:  // ssf_pan_2_status_states_name
        states = QStringList{"INIT", "WAIT", "DOWN", "CHECK_UP", "UP", "UP_ERROR"};
        break;
    case 43:  // ssf_pan_1_control_states_name
        states = QStringList{"INIT", "WAIT", "LOWER", "WAIT_PRESS", "RAISE"};
        break;
    case 44:  // ssf_pan_2_control_states_name
        states = QStringList{"INIT", "WAIT", "LOWER", "WAIT_PRESS", "RAISE"};
        break;
    case 45:  // ssf_mcb_1_readiness_states_name
        states = QStringList{"INIT", "WAIT", "NOT_READY", "READY"};
        break;
    case 46:  // ssf_mcb_2_readiness_states_name
        states = QStringList{"INIT", "WAIT", "NOT_READY", "READY"};
        break;
    case 47:  // ssf_mcb_1_status_states_name
        states = QStringList{"INIT", "WAIT", "OPENED", "CHECK_CLOSE", "CLOSE_ERROR", "CLOSED", "CHECK_OPEN", "OPEN_ERROR", "CHECK_UNK_ERROR", "ERROR"};
        break;
    case 48:  // ssf_mcb_2_status_states_name
        states = QStringList{"INIT", "WAIT", "OPENED", "CHECK_CLOSE", "CLOSE_ERROR", "CLOSED", "CHECK_OPEN", "OPEN_ERROR", "CHECK_UNK_ERROR", "ERROR"};
        break;
    case 49:  // ssf_mcb_1_control_states_name
        states = QStringList{"INIT", "WAIT", "OPEN", "CLOSE", "WARN_OPEN", "WAIT_RECLOSE"};
        break;
    case 50:  // ssf_mcb_2_control_states_name
        states = QStringList{"INIT", "WAIT", "OPEN", "CLOSE", "WARN_OPEN", "WAIT_RECLOSE"};
        break;
    case 51:  // ssf_door_close_req_states_name
        states = QStringList{"INIT", "WAIT", "NO_REQ", "CLOSE"};
        break;
    case 52:  // ssf_door_right_req_states_name
        states = QStringList{"INIT", "WAIT", "NO_REQ", "RELEASE_RIGHT", "OPEN_RIGHT"};
        break;
    case 53:  // ssf_door_left_req_states_name
        states = QStringList{"INIT", "WAIT", "NO_REQ", "RELEASE_LEFT", "OPEN_LEFT"};
        break;
    case 54:  // ssf_door_reset_req_states_name
        states = QStringList{"INIT", "WAIT", "NO_REQ", "EED_RESET"};
        break;
    case 55:  // ssf_ska_1_tcu_1_mcb_open_states_name
        states = QStringList{"INIT", "WAIT", "OPENED_MCB", "CATENARY", "JAMMED", "UNKNOWN"};
        break;
    case 56:  // ssf_ska_1_tcu_2_mcb_open_states_name
        states = QStringList{"INIT", "WAIT", "OPENED_MCB", "CATENARY", "JAMMED", "UNKNOWN"};
        break;
    case 57:  // ssf_ska_2_tcu_1_mcb_open_states_name
        states = QStringList{"INIT", "WAIT", "OPENED_MCB", "CATENARY", "JAMMED", "UNKNOWN"};
        break;
    case 58:  // ssf_ska_2_tcu_2_mcb_open_states_name
        states = QStringList{"INIT", "WAIT", "OPENED_MCB", "CATENARY", "JAMMED", "UNKNOWN"};
        break;
    case 59:  // ssf_ska_1_tcu_1_enable_states_name
        states = QStringList{"INIT", "WAIT", "ENABLE", "OUT_OF_SERVICE"};
        break;
    case 60:  // ssf_ska_1_tcu_2_enable_states_name
        states = QStringList{"INIT", "WAIT", "ENABLE", "OUT_OF_SERVICE"};
        break;
    case 61:  // ssf_ska_2_tcu_1_enable_states_name
        states = QStringList{"INIT", "WAIT", "ENABLE", "OUT_OF_SERVICE"};
        break;
    case 62:  // ssf_ska_2_tcu_2_enable_states_name
        states = QStringList{"INIT", "WAIT", "ENABLE", "OUT_OF_SERVICE"};
        break;
    case 63:  // ssf_ska_1_tcu_1_reset_states_name
        states = QStringList{"INIT", "WAIT", "NO_RESET", "RESET"};
        break;
    case 64:  // ssf_ska_1_tcu_2_reset_states_name
        states = QStringList{"INIT", "WAIT", "NO_RESET", "RESET"};
        break;
    case 65:  // ssf_ska_2_tcu_1_reset_states_name
        states = QStringList{"INIT", "WAIT", "NO_RESET", "RESET"};
        break;
    case 66:  // ssf_ska_2_tcu_2_reset_states_name
        states = QStringList{"INIT", "WAIT", "NO_RESET", "RESET"};
        break;
    case 67:  // ssf_linm_hv_level_states_name
        states = QStringList{"INIT", "WAIT", "LOWER_10KV", "LOW_HV", "RED_PWR", "NOM_PWR", "HIGH_HV"};
        break;

    case 68:  // ssf_linm_neutral_zone_states_name
        states = QStringList{"INIT", "WAIT", "ETCS_CONTROL", "IN_RANGE", "ZONE_BEGIN", "CHECK_LINE", "ZONE_END"};
        break;

    case 69:  // ssf_linm_range_check_states_name
        states = QStringList{"INIT", "WAIT", "IN_RANGE", "HIGH_TIMER", "OUT_OF_RANGE", "CHECK_RANGE", "RANGE_TIMER", "BACK_IN_RANGE"};
        break;

    case 70:  // ssf_linm_1_current_check_states_name
        states = QStringList{"INIT", "WAIT", "NORMAL", "CHECK_ZERO", "HV_ZERO", "CHECK_SHORT", "HV_SHORT"};
        break;

    case 71:  // ssf_linm_2_current_check_states_name
        states = QStringList{"INIT", "WAIT", "NORMAL", "CHECK_ZERO", "HV_ZERO", "CHECK_SHORT", "HV_SHORT"};
        break;

    case 72:  // ssf_comp_select_states_name
        states = QStringList{"INIT", "WAIT", "NONE", "OA1", "OA2", "BOTH"};
        break;

    case 73:  // ssf_comp_1_heater_states_name
        states = QStringList{"INIT", "WAIT", "NO_HEAT", "INACTIVE", "PREHEAT", "HEAT"};
        break;

    case 74:  // ssf_comp_2_heater_states_name
        states = QStringList{"INIT", "WAIT", "NO_HEAT", "INACTIVE", "PREHEAT", "HEAT"};
        break;

    case 75:  // ssf_comp_1_status_states_name
        states = QStringList{"INIT", "WAIT", "NOT_READY", "READY", "CHECK_MOTOR", "RUNNING", "SUPPLY_ERROR", "HIGH_CURRENT", "RELAY_ERROR"};
        break;

    case 76:  // ssf_comp_2_status_states_name
        states = QStringList{"INIT", "WAIT", "NOT_READY", "READY", "CHECK_MOTOR", "RUNNING", "SUPPLY_ERROR", "HIGH_CURRENT", "RELAY_ERROR"};
        break;

    case 77:  // ssf_comp_1_control_states_name
        states = QStringList{"INIT", "WAIT", "STOP", "WAIT_PREHEAT", "START"};
        break;

    case 78:  // ssf_comp_2_control_states_name
        states = QStringList{"INIT", "WAIT", "STOP", "WAIT_PREHEAT", "START"};
        break;

    case 79:  // ssf_sand_enable_states_name
        states = QStringList{"INIT", "WAIT", "ENABLED", "DISABLED"};
        break;

    case 80:  // ssf_sand_dry_states_name
        states = QStringList{"INIT", "WAIT", "NOT_READY", "DRY_60MIN", "PAUSE_60MIN", "WAIT_330MIN", "DRY_30MIN", "PAUSE_30MIN", "DRY", "NO_DRY"};
        break;

    case 81:  // ssf_sand_1_heater_states_name
        states = QStringList{"INIT", "WAIT", "NO_HEAT", "HEAT"};
        break;

    case 82:  // ssf_sand_2_heater_states_name
        states = QStringList{"INIT", "WAIT", "NO_HEAT", "HEAT"};
        break;

    case 83:  // ssf_sand_control_states_name
        states = QStringList{"INIT", "WAIT", "NO_CMD", "SHORT", "LONG", "REQ_END"};
        break;

    case 84:  // ssf_sand_test_states_name
        states = QStringList{"INIT", "WAIT", "READY", "TEST_CMD", "TESTING", "NOT_READY"};
        break;

    case 85:  // ssf_sand_level_test_states_name
        states = QStringList{"INIT", "WAIT", "READY", "TEST_CMD", "NOT_READY"};
        break;

    case 86:  // ssf_lvm_control_states_name
        states = QStringList{"INIT", "WAIT", "LP_OFF", "LP_ON", "LAST_HOLD"};
        break;

    case 87:  // ssf_trf_1_readiness_states_name
        states = QStringList{"INIT", "WAIT", "READY", "FAULT", "CHECK_OOS", "OUT_OF_SERVICE"};
        break;

    case 88:  // ssf_trf_2_readiness_states_name
        states = QStringList{"INIT", "WAIT", "READY", "FAULT", "CHECK_OOS", "OUT_OF_SERVICE"};
        break;

    case 89:  // ssf_trf_1_temp_states_name
        states = QStringList{"INIT", "WAIT", "NORMAL", "OVER60", "OVER90", "OVER110"};
        break;

    case 90:  // ssf_trf_2_temp_states_name
        states = QStringList{"INIT", "WAIT", "NORMAL", "OVER60", "OVER90", "OVER110"};
        break;

    case 91:  // ssf_trf_1_status_states_name
        states = QStringList{"INIT", "WAIT", "OFF", "LOW", "CHECK_FULL", "FULL", "CHECK_LOW", "FULL_ERROR", "LOW_ERROR"};
        break;

    case 92:  // ssf_trf_2_status_states_name
        states = QStringList{"INIT", "WAIT", "OFF", "LOW", "CHECK_FULL", "FULL", "CHECK_LOW", "FULL_ERROR", "LOW_ERROR"};
        break;

    case 93:  // ssf_trf_1_control_states_name
        states = QStringList{"INIT", "WAIT", "NO_CMD", "LOW_CMD", "FULL_CMD"};
        break;

    case 94:  // ssf_trf_2_control_states_name
        states = QStringList{"INIT", "WAIT", "NO_CMD", "LOW_CMD", "FULL_CMD"};
        break;

    case 95:  // ssf_hvm_earth_states_name
        states = QStringList{"INIT", "WAIT", "ERROR", "SERVICE", "YK_EXTRACTED", "EARTH"};
        break;

    case 96:  // ssf_hvm_line_select_states_name
        states = QStringList{"INIT", "WAIT", "NO_LINE", "OA1", "OA2"};
        break;

    case 97:  // ssf_hvm_usable_line_states_name
        states = QStringList{"INIT", "WAIT", "ALL_USABLE", "OA1_USABLE", "OA2_USABLE", "NONE_USABLE"};
        break;

    case 98:  // ssf_hvm_reset_procedure_states_name
        states = QStringList{"INIT", "WAIT", "NO_RESET", "CHECK_COND", "INIT_HV_LINE", "DR_DECIDE", "DR_PAN1_UP", "DR_MCB1_CLOSE", "CHECK_OC1", "DR_MCB1_OPEN", "DR_PAN1_DOWN", "DR_PAN2_UP", "DR_MCB2_CLOSE", "CHECK_OC2", "DR_MCB2_OPEN", "DR_PAN2_DOWN", "OC1_DETECTED", "OC_PAN1_DOWN", "OC2_DETECTED", "OC_PAN2_DOWN"};
        break;

    case 99:  // ssf_hvm_action_states_name
        states = QStringList{"INIT", "WAIT", "NO_ACTION", "HVD_IN", "HVD_OUT", "PAN_IN", "PAN_MCB_OUT", "MCB_BACK_IN", "MCB_IN", "MCB_OUT", "ALL_IN", "ALL_OUT", "WAIT_MCB_OUT", "WAIT_ALL_OUT"};
        break;

    case 100:  // ssf_susp_fault_lamp_states_name
        states = QStringList{"INIT", "WAIT", "OFF", "BLINK_ON", "BLINK_OFF", "ON"};
        break;

    case 101:  // sf_stat_states_name
        states = QStringList{"INIT", "WAIT"};
        break;

    default:
        states = QStringList{"No states available"};
        break;
    }


    stateLabel->setText(states.join("\n"));

    int sizeOfStates = stateCounts.size();
    qDebug() << "size of states array : " << sizeOfStates;


}

void DebugMonitorStates::customizeCombobox()
{
    systemFunctionComboBox->setStyleSheet(
        "QComboBox {"
        "    border: 2px solid #5A5A5A;"
        "    border-radius: 5px;"
        "    padding: 5px;"
        "    background-color: #FFFFFF;"
        "    color: #333333;"
        "}"
        "QComboBox::drop-down {"
        "    border: 0px;"
        "    width: 30px;"
        "    background-color: #EEEEEE;"
        "}"
        "QComboBox::down-arrow {"
        "    image: url(:/icons/chevron-down-solid.svg);"
        "    width: 16px;"
        "    height: 16px;"
        "}"
        "QComboBox QAbstractItemView {"
        "    border: 1px solid #CCCCCC;"
        "    background-color: #F9F9F9;"
        "    selection-background-color: #D6D6D6;"
        "    selection-color: #000000;"
        "}"
        );
}




void DebugMonitorStates::handleUdpMessage(const QByteArray& recv_data) {

    qDebug() << "Received Udp message in Debug Monitor States :" << recv_data;
    parseSystemStates(recv_data);

}

