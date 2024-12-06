#ifndef OA_APU_H
#define OA_APU_H

#include <QObject>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QDebug>
#include "utils.h"
#include <tsl/ordered_map.h>


class OA_APU : public QObject
{
    Q_OBJECT
public:
    explicit OA_APU(QObject *parent = nullptr);
    ~OA_APU();
public:
    enum OA_MVB_NUM {MVB1, MVB2, MVB3};
    static constexpr int OA_APU_SIZE = sizeof(oa_apu);

    QTableWidget* getTableWidget(OA_VEHICLE_NUM  oa_type, OA_MVB_NUM mvb_num){
        return m_tableWidget[static_cast<int>(oa_type)][mvb_num];
    }

    apu_ccu_mvb1& oa_x_apu_ccu_mvb1(OA_VEHICLE_NUM oa_type) {
        return m_oa_x_apu[static_cast<int>(oa_type)].oa_apu_ccu_mvb1;
    }

    apu_ccu_mvb2& oa_x_apu_ccu_mvb2(OA_VEHICLE_NUM oa_type) {
        return m_oa_x_apu[static_cast<int>(oa_type)].oa_apu_ccu_mvb2;
    }

    apu_ccu_mvb3& oa_x_apu_ccu_mvb3(OA_VEHICLE_NUM oa_type) {
        return m_oa_x_apu[static_cast<int>(oa_type)].oa_apu_ccu_mvb3;
    }

    std::array<uint8_t,  OA_APU_SIZE> oa_x_apu_arr(OA_VEHICLE_NUM oa_type) const
    {
        std::array<uint8_t,  OA_APU_SIZE> tempArr;
        memcpy(tempArr.begin(), &m_oa_x_apu[static_cast<int>(oa_type)], OA_APU_SIZE);
        return tempArr;
    }

    std::vector<uint8_t> moduleData(OA_VEHICLE_NUM oa_x_num) const
    {
        std::vector<uint8_t> tempData(OA_APU_SIZE);
        std::memcpy(tempData.data(), &m_oa_x_apu[static_cast<int>(oa_x_num)], OA_APU_SIZE);
        return tempData;
    }
    uint16_t portId(OA_VEHICLE_NUM oa_x_num) const
    {
        return m_port_id.at(static_cast<int>(oa_x_num));
    }

    void update_mvb1_map(OA_VEHICLE_NUM oa_x_num);
    void update_mvb2_map(OA_VEHICLE_NUM oa_x_num);
    void update_mvb3_map(OA_VEHICLE_NUM oa_x_num);
    void update_table(OA_VEHICLE_NUM oa_x_num, OA_MVB_NUM mvb);
    void update_struct_with_map(OA_VEHICLE_NUM oa_x_num, OA_MVB_NUM mvb_num);

    void set_data_struct(const QByteArray &input, const OA_VEHICLE_NUM &oa_x_num);
private:
    void make_signal_slot_connection();
    int get_index(OA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }
    int to_index(OA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }

    //void update_struct_with_map(OA_VEHICLE_NUM oa_x_num, OA_MVB_NUM mvb_num);
    void set_struct_mvb1(OA_VEHICLE_NUM oa_x_num);
    void set_struct_mvb2(OA_VEHICLE_NUM oa_x_num);
    void set_struct_mvb3(OA_VEHICLE_NUM oa_x_num);

    void init_oa_apu_mvb1_table(OA_VEHICLE_NUM vehicle_type);
    void init_oa_apu_mvb2_table(OA_VEHICLE_NUM vehicle_type);
    void init_oa_apu_mvb3_table(OA_VEHICLE_NUM vehicle_type);
    //void set_data_struct(const QByteArray &input, const OA_VEHICLE_NUM &oa_x_num);

private:
    const QStringList table_name[2][3] = {
        {
            {"oa_1_apu_ccu_mvb1", "value"},
            {"oa_1_apu_ccu_mvb2", "value"},
            {"oa_1_apu_ccu_mvb3", "value"}
        },
        {
            {"oa_2_apu_ccu_mvb1", "value"},
            {"oa_2_apu_ccu_mvb2", "value"},
            {"oa_2_apu_ccu_mvb3", "value"}
        }
    };

    struct oa_apu m_oa_x_apu[2];
    tsl::ordered_map<QString, int> m_inputs_map[2][3];
    QTableWidget *m_tableWidget[2][3];
    std::vector<uint16_t> m_port_id {0x841, 0x881}; // Direct initialization

};

#endif // OA_APU_H
