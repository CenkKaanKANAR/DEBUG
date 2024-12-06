#ifndef SKA_TCU_H
#define SKA_TCU_H

#include <QTableWidget>
#include <QDebug>
#include <QObject>
#include "utils.h"
#include "shm_data_gaziray.h"
#include <tsl/ordered_map.h>
#include <vector>
#include <cstring> // for memcpy


class SKA_TCU: public QObject
{
    Q_OBJECT
public:
    explicit SKA_TCU(QObject *parent = nullptr);
    ~SKA_TCU();
    enum MVB_NUM {MVB1,MVB2};
    enum TCU_NUM { TCU1, TCU2 };
    static constexpr int SKA_TCU_SIZE = sizeof(ska_tcu);


    // Method to retrieve a table widget for a given vehicle and MVB port
    QTableWidget* getTableWidget(SKA_VEHICLE_NUM veh_num, TCU_NUM tcu_num, MVB_NUM mvb_num) {
        return m_tableWidget[static_cast<int>(veh_num)][static_cast<int>(tcu_num)][mvb_num];
    }

    // Data access methods
    tcu_ccu_mvb1& ska_tcu_x_ccu_mvb1(SKA_VEHICLE_NUM ska_x_num, TCU_NUM tcu_num, MVB_NUM mvb_num) {
        return m_ska_x_tcu[static_cast<int>(ska_x_num)][static_cast<int>(tcu_num)].ska_tcu_ccu_mvb1;
    }

    tcu_ccu_mvb2& ska_tcu_x_ccu_mvb2(SKA_VEHICLE_NUM ska_x_num, TCU_NUM tcu_num, MVB_NUM mvb_num) {
        return m_ska_x_tcu[static_cast<int>(ska_x_num)][static_cast<int>(tcu_num)].ska_tcu_ccu_mvb2;
    }

    std::array<uint8_t, SKA_TCU_SIZE> data_arr(SKA_VEHICLE_NUM ska_x_num, TCU_NUM tcu_num, MVB_NUM mvb_num) const {
        std::array<uint8_t, SKA_TCU_SIZE> tempArr;
        memcpy(tempArr.begin(), &m_ska_x_tcu[static_cast<int>(ska_x_num)][static_cast<int>(tcu_num)], SKA_TCU_SIZE);
        return tempArr;
    }

    std::vector<uint8_t> moduleData(SKA_VEHICLE_NUM ska_x_num, TCU_NUM tcu_num) const {
        std::vector<uint8_t> tempData(SKA_TCU_SIZE);
        std::memcpy(tempData.data(), &m_ska_x_tcu[static_cast<int>(ska_x_num)][static_cast<int>(tcu_num)], SKA_TCU_SIZE);
        return tempData;
    }

    uint16_t portId(SKA_VEHICLE_NUM ska_x_num, TCU_NUM tcu_num) const {
        return m_port_id.at(static_cast<int>(ska_x_num)).at(static_cast<int>(tcu_num));
    }

    // Update methods for each TCU-MVB mapping
    //void update_tcu_mvb_map(SKA_VEHICLE_NUM ska_x_num, TCU_NUM tcu_x_num, MVB_NUM mvb_num);
    //void update_tcu_mvb_map(SKA_VEHICLE_NUM &ska_x_num, TCU_NUM tcu_x_num, MVB_NUM mvb_num);
    //void update_tcu_mvb_map(SKA_VEHICLE_NUM &ska_x_num, TCU_NUM tcu_x_num, MVB_NUM mvb_num);

    // Setting data struct
    void set_data_struct(const QByteArray &input, const SKA_VEHICLE_NUM &ska_x_num, TCU_NUM tcu_num);

    void set_struct(SKA_VEHICLE_NUM &ska_x_num, TCU_NUM tcu_num, MVB_NUM mvb_num);
    void update_tcu_mvb_map(const SKA_VEHICLE_NUM &ska_x_num, TCU_NUM tcu_x_num, MVB_NUM mvb_num);
    void update_table(const SKA_VEHICLE_NUM &ska_x_num, TCU_NUM tcu_x_num, MVB_NUM mvb_num);


    //void update_table(SKA_VEHICLE_NUM ska_x_num);
    //void update_table(SKA_VEHICLE_NUM &ska_x_num, TCU_NUM tcu_num, MVB_NUM mvb_num);




private:
    void make_signal_slot_connection();

    void init_tcu_mvb_table(SKA_VEHICLE_NUM ska_x_num, TCU_NUM tcu_num, MVB_NUM mvb_num);

    void update_struct_with_map(SKA_VEHICLE_NUM ska_x_num, TCU_NUM tcu_num, MVB_NUM mvb_num);


    int get_index(SKA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }


private:

    //struct ska_dd_riom m_ska_x_dd_riom[2];
    //QList<QPair<QString, uint64_t>>ska_x_dd_riom_ccu_mvb1_inputs_list[2];
    //QTableWidget *ska_x_dd_riom_ccu_mvb1_inputs_tableWidget[2] = {nullptr};

    std::vector<std::vector<uint16_t>> m_port_id{
        {0x701, 0x708},   // Birinci satır
        {0x7C1, 0x7C8}    // İkinci satır
    };
    struct ska_tcu m_ska_x_tcu[2][2];
    tsl::ordered_map<QString, int> m_inputs_map[2][2][2];
    QTableWidget *m_tableWidget[2][2][2];

};

#endif // SKA_TCU_H
