#ifndef SKA_CCU_DI_CARD_H
#define SKA_CCU_DI_CARD_H

#include <QObject>
#include <QTableWidget>
#include "shm_data_gaziray.h"
#include "utils.h"
#include <cstring>
#include <vector>

class Ska_Ccu_Di_Card : public QObject
{
    Q_OBJECT
public:
    explicit Ska_Ccu_Di_Card(QObject *parent = nullptr);
    ~Ska_Ccu_Di_Card();
    static constexpr int SKA_DI_CARD_SIZE = sizeof(ska_ccu_di_card);

    QTableWidget* getTableWidget(SKA_VEHICLE_NUM  veh_num){
        return m_tableWidget[static_cast<int>(veh_num)];
    }

    std::array<uint8_t, SKA_DI_CARD_SIZE> data_arr(SKA_VEHICLE_NUM ska_x_num) const
    {
        std::array<uint8_t, SKA_DI_CARD_SIZE> tempArr;
        memcpy(tempArr.begin(), &m_ska_x_ccu_di_card[static_cast<int>(ska_x_num)], SKA_DI_CARD_SIZE);
        return tempArr;
    }

    std::vector<uint8_t> moduleData(SKA_VEHICLE_NUM ska_x_num) const
    {
        std::vector<uint8_t> tempData(SKA_DI_CARD_SIZE);
        std::memcpy(tempData.data(), &m_ska_x_ccu_di_card[static_cast<int>(ska_x_num)], SKA_DI_CARD_SIZE);
        return tempData;
    }

    uint16_t portId(SKA_VEHICLE_NUM ska_x_num) const
    {
        return m_port_id.at(static_cast<int>(ska_x_num));
    }

    void update_map(SKA_VEHICLE_NUM ska_x_num);
    void update_table(SKA_VEHICLE_NUM ska_x_num);
    void set_data_struct(const QByteArray &input, const SKA_VEHICLE_NUM &ska_x_num);
private:
    void make_signal_slot_connection();
    void init_ska_x_table(SKA_VEHICLE_NUM ska_x_num);
    void update_struct_with_map(SKA_VEHICLE_NUM ska_x_num);
    void set_struct(SKA_VEHICLE_NUM ska_x_num);
    int get_index(SKA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }

    const QStringList table_name[2] = {
            {"ska_1_ccu_di_card", "value"},
            {"ska_2_ccu_di_card", "value"},
    };
    struct ska_ccu_di_card m_ska_x_ccu_di_card[2];
    std::map<QString, int> m_inputs_map[2];
    QTableWidget *m_tableWidget[2];
    std::vector<uint16_t> m_port_id {0x250, 0x260}; // Direct initialization //Sallamasyon port


};

#endif // SKA_CCU_DI_CARD_H
