#ifndef FRC_CONFIG_H
#define FRC_CONFIG_H

#include <cstdint>

class FrcConfig {
public:
    union {
        uint8_t bytes[8];
        struct {
            uint8_t frc_connected :1;
            uint8_t frc_in_config_mode :1;
            uint8_t frc_ready :1;
            uint8_t reserved3 :1;
            uint8_t reserved4 :1;
            uint8_t reserved5 :1;
            uint8_t reserved6 :1;
            uint8_t ska_ccu_do_card :1;
            uint8_t ccu_life_sign_counter:1;
            uint8_t ccu_global_outputs:1;
            uint8_t reserved10 :1;
            uint8_t ska_ccu_to_all_rioms:1;
            uint8_t reserved12 :1;
            uint8_t ccu_to_all_jrus_1:1;
            uint8_t ccu_to_all_jrus_2:1;
            uint8_t ccu_to_all_jrus_3:1;
            uint8_t ccu_to_all_jrus_4:1;
            uint8_t ccu_to_all_jrus_5:1;
            uint8_t ska1_vh_riom_outputs:1;
            uint8_t ska2_vh_riom_outputs:1;
            uint8_t reserved20 :1;
            uint8_t reserved21 :1;
            uint8_t ska1_dd_riom_outputs:1;
            uint8_t ska2_dd_riom_outputs:1;
            uint8_t reserved24 :1;
            uint8_t reserved25 :1;
            uint8_t oa1_vh_riom_outputs:1;
            uint8_t oa2_vh_riom_outputs:1;
            uint8_t reserved28 :1;
            uint8_t reserved29 :1;
            uint8_t ccu_to_all_bcus:1;
            uint8_t ccu_to_all_tcus:1;
            uint8_t ccu_to_oa1_etcs:1;
            uint8_t ccu_to_oa2_etcs:1;
            uint8_t ccu_to_all_etcs:1;
            uint8_t ccu_to_all_apus:1;
            uint8_t reserved36:1;
            uint8_t reserved37:1;
            uint8_t reserved38:1;
            uint8_t reserved39:1;
            uint8_t reserved40:1;
            uint8_t reserved41:1;
            uint8_t reserved42:1;
            uint8_t reserved43:1;
            uint8_t reserved44:1;
            uint8_t reserved46:1;
            uint8_t reserved47:1;
            uint8_t reserved48:1;
            uint16_t portId;
        } bits;
    };




public:
    //FrcConfig();  // Constructor
    // Default constructor definition
    FrcConfig();
    bool isFrcActive() const;
    void setFrcActive(bool active);

    bool isFrcConnected() const;
    void setFrcConnected(bool connected);

    uint16_t getPortId() const;
    void setPortId(uint16_t id);

    uint8_t* getBytes(); // Yapıdaki baytları almak için
};

#endif // FRC_CONFIG_H
