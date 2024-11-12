#ifndef OA_DCU_H
#define OA_DCU_H

#include <QObject>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QDebug>
#include "utils.h"


class OA_DCU : public QObject
{
    Q_OBJECT
public:
    explicit OA_DCU(QObject *parent = nullptr);
    ~OA_DCU();



public:
    enum DCU_NUM {DCU1, DCU2, DCU3, DCU4};
    static constexpr int OA_DCU_SIZE = sizeof(oa_dcu);
    QTableWidget* getTableWidget(OA_VEHICLE_NUM  oa_type, DCU_NUM dcu_num){
        return m_tableWidget[static_cast<int>(oa_type)][dcu_num];
    }
    oa_vh_riom_ccu_mvb2_dcu1& oa_x_vh_riom_ccu_mvb2_dcu1(OA_VEHICLE_NUM oa_type) {
        return  m_oa_x_dcu[static_cast<int>(oa_type)].oa_vh_riom_ccu_mvb2_dcu1;
    }
    oa_vh_riom_ccu_mvb3_dcu2& oa_x_vh_riom_ccu_mvb2_dcu2(OA_VEHICLE_NUM oa_type) {
        return  m_oa_x_dcu[static_cast<int>(oa_type)].oa_vh_riom_ccu_mvb3_dcu2;
    }

    oa_vh_riom_ccu_mvb4_dcu3& oa_x_vh_riom_ccu_mvb2_dcu3(OA_VEHICLE_NUM oa_type) {
        return  m_oa_x_dcu[static_cast<int>(oa_type)].oa_vh_riom_ccu_mvb4_dcu3;
    }

    oa_vh_riom_ccu_mvb5_dcu4& oa_x_vh_riom_ccu_mvb2_dcu4(OA_VEHICLE_NUM oa_type) {
        return  m_oa_x_dcu[static_cast<int>(oa_type)].oa_vh_riom_ccu_mvb5_dcu4;
    }

    std::array<uint8_t, OA_DCU_SIZE> oa_x_dcu_arr(OA_VEHICLE_NUM oa_type) const
    {
        std::array<uint8_t, OA_DCU_SIZE> tempArr;
        memcpy(tempArr.begin(), &m_oa_x_dcu[static_cast<int>(oa_type)], OA_DCU_SIZE);
        return tempArr;
    }

    std::vector<uint8_t> moduleData(OA_VEHICLE_NUM oa_x_num) const
    {
        std::vector<uint8_t> tempData(OA_DCU_SIZE);
        std::memcpy(tempData.data(), &m_oa_x_dcu[static_cast<int>(oa_x_num)], OA_DCU_SIZE);
        return tempData;
    }
    uint16_t portId(OA_VEHICLE_NUM oa_x_num) const
    {
        return m_port_id.at(static_cast<int>(oa_x_num));
    }
    void update_dcu1_map(OA_VEHICLE_NUM oa_x_num);
    void update_dcu2_map(OA_VEHICLE_NUM oa_x_num);
    void update_dcu3_map(OA_VEHICLE_NUM oa_x_num);
    void update_dcu4_map(OA_VEHICLE_NUM oa_x_num);
    void set_data_struct(const QByteArray &input, const OA_VEHICLE_NUM &oa_x_num);
private:
    void make_signal_slot_connection();
    int get_index(OA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }
    int to_index(OA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }

    void update_struct_with_map(OA_VEHICLE_NUM oa_x_num, DCU_NUM dcu_num);
    void set_struct_dcu1(OA_VEHICLE_NUM oa_x_num);
    void set_struct_dcu2(OA_VEHICLE_NUM oa_x_num);
    void set_struct_dcu3(OA_VEHICLE_NUM oa_x_num);
    void set_struct_dcu4(OA_VEHICLE_NUM oa_x_num);

    void init_oa_x_dcu1_table(OA_VEHICLE_NUM vehicle_type);
    void init_oa_x_dcu2_table(OA_VEHICLE_NUM vehicle_type);
    void init_oa_x_dcu3_table(OA_VEHICLE_NUM vehicle_type);
    void init_oa_x_dcu4_table(OA_VEHICLE_NUM vehicle_type);
    void update_table(OA_VEHICLE_NUM oa_x_num, DCU_NUM mvb_num);

private:
    const QStringList table_name[2][4] = {
        {
            {"oa_1_vh_riom_ccu_mvb2_dcu1", "value"},
            {"oa_1_vh_riom_ccu_mvb3_dcu2", "value"},
            {"oa_1_vh_riom_ccu_mvb4_dcu3", "value"},
            {"oa_1_vh_riom_ccu_mvb5_dcu4", "value"}
        },
        {
            {"oa_2_vh_riom_ccu_mvb2_dcu1", "value"},
            {"oa_2_vh_riom_ccu_mvb3_dcu2", "value"},
            {"oa_2_vh_riom_ccu_mvb4_dcu3", "value"},
            {"oa_2_vh_riom_ccu_mvb5_dcu4", "value"}
        }
    };

    struct oa_dcu m_oa_x_dcu[2];
    std::map<QString, int> m_inputs_map[2][4];
    QTableWidget *m_tableWidget[2][4];
    std::vector<uint16_t> m_port_id {0x452, 0x492}; // Direct initialization
    // * OA1_VH	0x452
    // * OA2_VH	0x492
};

#endif // OA_VH_RIOM_H
