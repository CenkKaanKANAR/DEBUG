#ifndef OA_BCU_H
#define OA_BCU_H

#include <QObject>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QDebug>
#include "utils.h"



class OA_BCU : public QObject
{
    Q_OBJECT
public:
    explicit OA_BCU(QObject *parent = nullptr);
    ~OA_BCU();
public:
    enum OA_MVB_NUM {MVB1, MVB2, MVB3};
    static constexpr int OA_BCU_SIZE = sizeof(oa_bcu);
    QTableWidget* getTableWidget(OA_VEHICLE_NUM  oa_type, OA_MVB_NUM mvb_num){
        return m_tableWidget[static_cast<int>(oa_type)][mvb_num];
    }

    bcu_ccu_mvb1& oa_x_bcu_ccu_mvb1(OA_VEHICLE_NUM oa_type) {
        return  m_oa_x_bcu[static_cast<int>(oa_type)].oa_bcu_ccu_mvb1;
    }

    bcu_ccu_mvb2& oa_x_bcu_ccu_mvb2(OA_VEHICLE_NUM oa_type) {
        return  m_oa_x_bcu[static_cast<int>(oa_type)].oa_bcu_ccu_mvb2;
    }

    /*bcu_ccu_mvb3& oa_x_bcu_ccu_mvb3(OA_VEHICLE_NUM oa_type) {
        return  m_oa_x_bcu[static_cast<int>(oa_type)].oa_bcu_ccu_mvb3;
    }*/

    std::array<uint8_t, OA_BCU_SIZE> oa_x_bcu_arr(OA_VEHICLE_NUM oa_type) const
    {
        std::array<uint8_t, OA_BCU_SIZE> tempArr;
        memcpy(tempArr.begin(), &m_oa_x_bcu[static_cast<int>(oa_type)], OA_BCU_SIZE);
        return tempArr;
    }

    std::vector<uint8_t> moduleData(OA_VEHICLE_NUM oa_x_num) const
    {
        std::vector<uint8_t> tempData(OA_BCU_SIZE);
        std::memcpy(tempData.data(), &m_oa_x_bcu[static_cast<int>(oa_x_num)], OA_BCU_SIZE);
        return tempData;
    }

    uint16_t portId(OA_VEHICLE_NUM oa_x_num) const
    {
        return m_port_id.at(static_cast<int>(oa_x_num));
    }

    //void update_table(OA_VEHICLE_NUM oa_x_num);
    void update_mvb1_map(OA_VEHICLE_NUM oa_x_num);
    void update_mvb2_map(OA_VEHICLE_NUM oa_x_num);
    //void update_mvb3_map(OA_VEHICLE_NUM oa_x_num);
    void update_table(OA_VEHICLE_NUM oa_x_num, OA_MVB_NUM mvb);

    void set_data_struct(const QByteArray &input, const OA_VEHICLE_NUM &oa_x_num);

private:
    void make_signal_slot_connection();
    int get_index(OA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }
    int to_index(OA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }

    void update_struct_with_map(OA_VEHICLE_NUM oa_x_num, OA_MVB_NUM mvb_num);
    void set_struct_mvb1(OA_VEHICLE_NUM oa_x_num);
    void set_struct_mvb2(OA_VEHICLE_NUM oa_x_num);
    //void set_struct_mvb3(OA_VEHICLE_NUM oa_x_num);

    void init_oa_x_mvb1_table(OA_VEHICLE_NUM vehicle_type);
    void init_oa_x_mvb2_table(OA_VEHICLE_NUM vehicle_type);
    //void init_oa_x_mvb3_table(OA_VEHICLE_NUM vehicle_type);

private:
    const QStringList table_name[2][2] = {
        {
            {"oa_1_bcu_ccu_mvb1", "value"},
            {"oa_1_bcu_ccu_mvb2", "value"},

        },
        {
            {"oa_2_bcu_ccu_mvb1", "value"},
            {"oa_2_bcu_ccu_mvb2", "value"},

        }
    };

    struct oa_bcu m_oa_x_bcu[2];
    std::map<QString, int> m_inputs_map[2][2];
    QTableWidget *m_tableWidget[2][2];
    std::vector<uint16_t> m_port_id {0x641, 0x681}; // Direct initialization
};

#endif // OA_VH_RIOM_H
