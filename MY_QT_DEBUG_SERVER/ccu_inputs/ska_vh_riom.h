#ifndef SKA_VH_RIOM_H
#define SKA_VH_RIOM_H
#include <QTableWidget>
#include <QDebug>
#include <QObject>

#include "shm_data_gaziray.h"
#include "utils.h"
#include <cstring>
#include <vector>



class SKA_VH_RIOM : public QObject
{
    Q_OBJECT
public:
    explicit SKA_VH_RIOM(QObject *parent = nullptr);
    ~SKA_VH_RIOM();
    static constexpr int SKA_VH_RIOM_SIZE = sizeof(ska_vh_riom);
    enum MVB_NUM {STATUS0,MVB1};
    QTableWidget* getTableWidget(SKA_VEHICLE_NUM  veh_num,MVB_NUM mvb_num){
        return m_tableWidget[static_cast<int>(veh_num)][mvb_num];

    }

    ska_vh_riom_ccu_mvb1_d_inputs& ska_vh_x_riom_ccu_mvb1_d_inputs(SKA_VEHICLE_NUM ska_x_num) {
        return m_ska_x_vh_riom[static_cast<int>(ska_x_num)].ska_vh_riom_ccu_mvb1_d_inputs;

    }
    ska_vh_riom_ccu_mvb_status& ska_vh_x_riom_ccu_mvb_status(SKA_VEHICLE_NUM ska_x_num) {
        return m_ska_x_vh_riom[static_cast<int>(ska_x_num)].ska_vh_riom_ccu_mvb_status;

    }

    std::array<uint8_t, SKA_VH_RIOM_SIZE> data_arr(SKA_VEHICLE_NUM ska_x_num) const
    {
        std::array<uint8_t, SKA_VH_RIOM_SIZE> tempArr;
        memcpy(tempArr.begin(), &m_ska_x_vh_riom[static_cast<int>(ska_x_num)], SKA_VH_RIOM_SIZE);
        return tempArr;
    }

    std::vector<uint8_t> moduleData(SKA_VEHICLE_NUM ska_x_num) const
    {
        std::vector<uint8_t> tempData(SKA_VH_RIOM_SIZE);
        std::memcpy(tempData.data(), &m_ska_x_vh_riom[static_cast<int>(ska_x_num)], SKA_VH_RIOM_SIZE);
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

    struct ska_vh_riom m_ska_x_vh_riom[2];
    std::map<QString, unsigned int> m_inputs_map[2][2];
    QTableWidget *m_tableWidget[2][2];
    std::vector<uint16_t> m_port_id {0x401, 0x4C1}; // Direct initialization


};

#endif // SKA_VH_RIOM_H
