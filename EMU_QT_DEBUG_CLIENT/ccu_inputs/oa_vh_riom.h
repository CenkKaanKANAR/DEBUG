#ifndef OA_VH_RIOM_H
#define OA_VH_RIOM_H
#include "utils.h"
#include <QObject>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QDebug>
#include <cstring>
#include <vector>
#include <tsl/ordered_map.h>



class Oa_Vh_Riom : public QObject
{
    Q_OBJECT
public:
    explicit Oa_Vh_Riom(QObject *parent = nullptr);
    ~Oa_Vh_Riom();
    enum MVB_NUM {STATUS0,MVB1};
    static constexpr int OA_VH_RIOM_SIZE = sizeof(oa_vh_riom);
    ////////////////////////////////////////////////////////////////////////
    QTableWidget* getTableWidget(OA_VEHICLE_NUM  veh_num,MVB_NUM mvb_num){
        return m_tableWidget[static_cast<int>(veh_num)][mvb_num];

    }

    oa_vh_riom_ccu_mvb1_inputs& oa_vh_x_riom_ccu_mvb1_inputs(OA_VEHICLE_NUM oa_x_num) {
        return m_oa_x_vh_riom[static_cast<int>(oa_x_num)].oa_vh_riom_ccu_mvb1_inputs;

    }
    oa_vh_riom_ccu_mvb_status& oa_vh_x_riom_ccu_mvb_status(OA_VEHICLE_NUM oa_x_num) {
        return m_oa_x_vh_riom[static_cast<int>(oa_x_num)].oa_vh_riom_ccu_mvb_status;
    }


    oa_vh_riom& oa_x_vh_riom(OA_VEHICLE_NUM oa_x_num) {
        return m_oa_x_vh_riom[static_cast<int>(oa_x_num)];
    }


    std::array<uint8_t, OA_VH_RIOM_SIZE> data_arr(OA_VEHICLE_NUM oa_x_num) const
    {
        std::array<uint8_t, OA_VH_RIOM_SIZE> tempArr;
        memcpy(tempArr.begin(), &m_oa_x_vh_riom[static_cast<int>(oa_x_num)], OA_VH_RIOM_SIZE);
        return tempArr;
    }

    std::vector<uint8_t> moduleData(OA_VEHICLE_NUM oa_x_num) const
    {
        std::vector<uint8_t> tempData(OA_VH_RIOM_SIZE);
        std::memcpy(tempData.data(), &m_oa_x_vh_riom[static_cast<int>(oa_x_num)], OA_VH_RIOM_SIZE);
        return tempData;
    }

    uint16_t portId(OA_VEHICLE_NUM oa_x_num) const
    {
        return m_port_id.at(static_cast<int>(oa_x_num));
    }

    void update_inputs_map(OA_VEHICLE_NUM oa_x_num);
    void update_status_map(OA_VEHICLE_NUM oa_x_num);
    //void update_table(SKA_VEHICLE_NUM ska_x_num);
    void update_table(OA_VEHICLE_NUM oa_x_num, MVB_NUM mvb_num);
    void set_data_struct(const QByteArray &input, const OA_VEHICLE_NUM &oa_x_num);
private:
    void make_signal_slot_connection();
    void init_inputs_table(OA_VEHICLE_NUM oa_x_num);
    void init_status_table(OA_VEHICLE_NUM oa_x_num);
    void update_struct_with_map(OA_VEHICLE_NUM oa_x_num, MVB_NUM mvb_num);
    void set_inputs_struct(OA_VEHICLE_NUM oa_x_num);
    void set_status_struct(OA_VEHICLE_NUM oa_x_num);
    int get_index(OA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }

private:
    struct oa_vh_riom m_oa_x_vh_riom[2];
    tsl::ordered_map<QString, int> m_inputs_map[2][2];
    QTableWidget *m_tableWidget[2][2];
    std::vector<uint16_t> m_port_id {0x441, 0x481}; // Direct initialization
};

#endif // OA_VH_RIOM_H


