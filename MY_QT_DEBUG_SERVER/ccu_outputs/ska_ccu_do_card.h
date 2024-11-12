#ifndef SKA_CCU_DO_CARD_H
#define SKA_CCU_DO_CARD_H

#include <QObject>
#include <QTableWidget>
#include "shm_data_gaziray.h"
#include "utils.h"

class Ska_Ccu_Do_Card : public QObject
{
    Q_OBJECT
public:
    explicit Ska_Ccu_Do_Card(QObject *parent = nullptr);
    ~Ska_Ccu_Do_Card();
    static constexpr int SKA_DO_CARD_SIZE = sizeof(ska_ccu_do_card);
    QTableWidget* getTableWidget(SKA_VEHICLE_NUM  veh_num){
        return m_tableWidget[static_cast<int>(veh_num)];
    }

    std::array<uint8_t, SKA_DO_CARD_SIZE> data_arr(SKA_VEHICLE_NUM ska_x_num) const
    {
        std::array<uint8_t, SKA_DO_CARD_SIZE> tempArr;
        memcpy(tempArr.begin(), &m_ska_x_ccu_do_card[static_cast<int>(ska_x_num)], SKA_DO_CARD_SIZE);
        return tempArr;
    }
    void update_map(SKA_VEHICLE_NUM ska_x_num);
    void update_table(SKA_VEHICLE_NUM ska_x_num);
private:
    void make_signal_slot_connection();
    void init_ska_x_table(SKA_VEHICLE_NUM ska_x_num);
    void update_struct_with_map(SKA_VEHICLE_NUM ska_x_num);
    void set_struct(SKA_VEHICLE_NUM ska_x_num);
    int get_index(SKA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }
    const QStringList table_name[2] = {
                                       {"ska_1_ccu_do_card", "value"},
                                       {"ska_2_ccu_do_card", "value"},
                                       };

    struct ska_ccu_do_card m_ska_x_ccu_do_card[2];
    std::map<QString, int> m_inputs_map[2];
    QTableWidget *m_tableWidget[2];
    std::vector<uint16_t> m_port_id {0x331, 0x443};

};

#endif // SKA_CCU_DO_CARD_H
