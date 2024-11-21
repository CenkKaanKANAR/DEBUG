#ifndef SKA_CCU_DI_CARD_H
#define SKA_CCU_DI_CARD_H

#include <QObject>
#include <QTableWidget>
#include "shm_data_gaziray.h"
#include "utils.h"
#include <cstring>
#include <vector>
#include <tsl/ordered_map.h>

class Ska_Ccu_Di_Card : public QObject
{
    Q_OBJECT
public:
    explicit Ska_Ccu_Di_Card(QObject *parent = nullptr);
    ~Ska_Ccu_Di_Card();
    static constexpr int SKA_DI_CARD_SIZE = sizeof(ska_ccu_di_card);

    QTableWidget* getTableWidget(){
        return m_tableWidget;
    }

    std::array<uint8_t, SKA_DI_CARD_SIZE> data_arr() const
    {
        std::array<uint8_t, SKA_DI_CARD_SIZE> tempArr;
        memcpy(tempArr.begin(), &m_ska_x_ccu_di_card, SKA_DI_CARD_SIZE);
        return tempArr;
    }

    std::vector<uint8_t> moduleData() const
    {
        std::vector<uint8_t> tempData(SKA_DI_CARD_SIZE);
        std::memcpy(tempData.data(), &m_ska_x_ccu_di_card, SKA_DI_CARD_SIZE);
        return tempData;
    }

    uint16_t portId() const
    {
        return m_port_id.at(0);
    }

    void update_map();
    void update_table();
    void set_data_struct(const QByteArray &input);
private:
    void make_signal_slot_connection();
    void init_ska_x_table();
    void update_struct_with_map();
    void set_struct();
    /*int get_index(SKA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }*/

    const QStringList table_name[2] = {
            {"ska_ccu_di_card", "value"},

    };
    struct ska_ccu_di_card m_ska_x_ccu_di_card;
    tsl::ordered_map<QString, int> m_inputs_map;
    QTableWidget *m_tableWidget;
    std::vector<uint16_t> m_port_id {0x250}; // Direct initialization //Sallamasyon port


};

#endif // SKA_CCU_DI_CARD_H
