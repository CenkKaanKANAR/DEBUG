#include "sysfuncstate.h"

SysFuncState::SysFuncState() {
    initializeStates();
}

// Tüm state map'i al
const std::map<std::string, std::vector<StateInfo>>& SysFuncState::getStateMap() const {
    return stateMap;
}

// Belirli bir anahtar için state listesi al
const std::vector<StateInfo>& SysFuncState::getStates(const std::string& key) const {
    static const std::vector<StateInfo> emptyState; // Anahtar bulunamazsa boş döner
    auto it = stateMap.find(key);
    return it != stateMap.end() ? it->second : emptyState;
}

// State'leri başlat
void SysFuncState::initializeStates() {
    // İlk state listesi
    std::vector<StateInfo> ssf_linm_range_check_states = {
        {"INIT", 1},
        {"WAIT", 2},
        {"IN_RANGE", 3},
        {"HIGH_TIMER", 4},
        {"OUT_OF_RANGE", 5},
        {"CHECK_RANGE", 6},
        {"RANGE_TIMER", 7},
        {"BACK_IN_RANGE", 8}
    };

    // Yeni state dizisi
    std::vector<StateInfo> ssf_emu_config_states = {
        {"INIT", 1},
        {"WAIT", 2},
        {"SINGLE", 3},
        {"MULTIPLE", 4}
    };

    // Map'e ekleme
    stateMap["ssf_linm_range_check_states_name"] = ssf_linm_range_check_states;
    stateMap["ssf_emu_config_states_name"] = ssf_emu_config_states;
}

