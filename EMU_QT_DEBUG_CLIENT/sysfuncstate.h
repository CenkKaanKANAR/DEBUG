#ifndef SYSFUNCSTATE_H
#define SYSFUNCSTATE_H

#include <vector>
#include <map>
#include <string>

// State bilgisi
struct StateInfo {
    std::string name;
    int code;
};

class SysFuncState
{
public:
    SysFuncState();

    // State listelerini alma
    const std::vector<StateInfo>& getStates(const std::string& key) const;

    // Mevcut tüm state map'ini alma
    const std::map<std::string, std::vector<StateInfo>>& getStateMap() const;

private:
    std::map<std::string, std::vector<StateInfo>> stateMap;

    // Sınıf içi helper (başlatma)
    void initializeStates();
};

#endif // SYSFUNCSTATE_H
