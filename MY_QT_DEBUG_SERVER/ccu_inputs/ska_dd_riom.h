#ifndef SKA_DD_RIOM_H
#define SKA_DD_RIOM_H
#include <QTableWidget>
#include <QDebug>
#include <QObject>
#include "utils.h"
#include "shm_data_gaziray.h"

#include <vector>
#include <cstring> // for memcpy


class SKA_DD_RIOM : public QObject
{
    Q_OBJECT
public:
    explicit SKA_DD_RIOM(QObject *parent = nullptr);
    ~SKA_DD_RIOM();
    enum MVB_NUM {STATUS0,MVB1};
    static constexpr int SKA_DD_SIZE = sizeof(ska_dd_riom);


    QTableWidget* getTableWidget(SKA_VEHICLE_NUM  veh_num,MVB_NUM mvb_num){
        return m_tableWidget[static_cast<int>(veh_num)][mvb_num];

    }

    ska_dd_riom_ccu_mvb1_inputs& ska_dd_x_riom_ccu_mvb1_inputs(SKA_VEHICLE_NUM ska_x_num) {
        return m_ska_x_dd_riom[static_cast<int>(ska_x_num)].ska_dd_riom_ccu_mvb1_inputs;

    }
    ska_dd_riom_ccu_mvb_status& ska_dd_x_riom_ccu_mvb_status(SKA_VEHICLE_NUM ska_x_num) {
        return m_ska_x_dd_riom[static_cast<int>(ska_x_num)].ska_dd_riom_ccu_mvb_status;
    }


    std::array<uint8_t, SKA_DD_SIZE> data_arr(SKA_VEHICLE_NUM ska_x_num) const
    {
        std::array<uint8_t, SKA_DD_SIZE> tempArr;
        memcpy(tempArr.begin(), &m_ska_x_dd_riom[static_cast<int>(ska_x_num)], SKA_DD_SIZE);
        return tempArr;
    }
    std::vector<uint8_t> moduleData(SKA_VEHICLE_NUM ska_x_num) const
    {
        std::vector<uint8_t> tempData(SKA_DD_SIZE);
        std::memcpy(tempData.data(), &m_ska_x_dd_riom[static_cast<int>(ska_x_num)], SKA_DD_SIZE);
        return tempData;
    }

    uint16_t portId(SKA_VEHICLE_NUM ska_x_num) const
    {
        return m_port_id.at(static_cast<int>(ska_x_num));
    }

    void update_inputs_map(SKA_VEHICLE_NUM ska_x_num);
    void update_status_map(SKA_VEHICLE_NUM ska_x_num);
    //void update_table(SKA_VEHICLE_NUM ska_x_num);
    void update_table(SKA_VEHICLE_NUM ska_x_num, MVB_NUM mvb_num);
    void set_data_struct(const QByteArray &input, const SKA_VEHICLE_NUM &ska_x_num);
private:
    void make_signal_slot_connection();
    void init_inputs_table(SKA_VEHICLE_NUM ska_x_num);
    void init_status_table(SKA_VEHICLE_NUM ska_x_num);
    void update_struct_with_map(SKA_VEHICLE_NUM ska_x_num, MVB_NUM mvb_num);
    void set_inputs_struct(SKA_VEHICLE_NUM ska_x_num);
    void set_status_struct(SKA_VEHICLE_NUM ska_x_num);
    int get_index(SKA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }


private:
    enum VEHICLE_NUM{V1, V2};
    //struct ska_dd_riom m_ska_x_dd_riom[2];
    //QList<QPair<QString, uint64_t>>ska_x_dd_riom_ccu_mvb1_inputs_list[2];
    //QTableWidget *ska_x_dd_riom_ccu_mvb1_inputs_tableWidget[2] = {nullptr};

    std::vector<uint16_t> m_port_id{0x201, 0x2C1};
    struct ska_dd_riom m_ska_x_dd_riom[2];
    std::map<QString, int> m_inputs_map[2][2];
    QTableWidget *m_tableWidget[2][2];

};

#endif // SKA_DD_RIOM_H
