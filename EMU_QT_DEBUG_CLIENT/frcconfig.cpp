#include "frcconfig.h"
#include <cstring>  // memset


// Constructor definition
FrcConfig::FrcConfig() {
    for (int i = 0; i < 8; ++i) {
        bytes[i] = 0;  // Set all bytes to zero by default
    }
    bits.portId = 0;  // Initialize portId or any other necessary members
}

// Other member function definitions...

/*bool FrcConfig::isFrcActive() const {
    return bits.frc_active == 1;
}

void FrcConfig::setFrcActive(bool active) {
    bits.frc_active = active ? 1 : 0;
}*/

bool FrcConfig::isFrcConnected() const {
    return bits.frc_connected == 1;
}

void FrcConfig::setFrcConnected(bool connected) {
    bits.frc_connected = connected ? 1 : 0;
}

uint16_t FrcConfig::getPortId() const {
    return bits.portId;
}

void FrcConfig::setPortId(uint16_t id) {
    bits.portId = id;
}

uint8_t* FrcConfig::getBytes() {
    return bytes;
}
