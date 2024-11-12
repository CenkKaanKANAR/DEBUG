#ifndef OA_HVAC_H
#define OA_HVAC_H

#include <QObject>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QDebug>
#include "utils.h"


class Oa_Hvac : public QObject
{
    Q_OBJECT
public:
    explicit Oa_Hvac(QObject *parent = nullptr);
    ~Oa_Hvac();



public:
    enum HVAC_NUM {HVAC1, HVAC2};
    static constexpr int OA_HVAC_SIZE = sizeof(oa_hvac);
    QTableWidget* getTableWidget(OA_VEHICLE_NUM  oa_type, HVAC_NUM hvac_num){
        return m_tableWidget[static_cast<int>(oa_type)][hvac_num];
    }
    oa_vh_riom_ccu_mvb6_hvac1& oa_x_vh_riom_ccu_mvb13_hvac1(OA_VEHICLE_NUM oa_type) {
        return  m_oa_x_hvac[static_cast<int>(oa_type)].oa_vh_riom_ccu_mvb6_hvac1;
    }
    oa_vh_riom_ccu_mvb7_hvac2& oa_x_vh_riom_ccu_mvb14_hvac2(OA_VEHICLE_NUM oa_type) {
        return  m_oa_x_hvac[static_cast<int>(oa_type)].oa_vh_riom_ccu_mvb7_hvac2;
    }

    std::array<uint8_t, OA_HVAC_SIZE> oa_x_hvac_arr(OA_VEHICLE_NUM oa_type) const
    {
        std::array<uint8_t, OA_HVAC_SIZE> tempArr;
        memcpy(tempArr.begin(), &m_oa_x_hvac[static_cast<int>(oa_type)], OA_HVAC_SIZE);
        return tempArr;
    }

    std::vector<uint8_t> moduleData(OA_VEHICLE_NUM oa_x_num) const
    {
        std::vector<uint8_t> tempData(OA_HVAC_SIZE);
        std::memcpy(tempData.data(), &m_oa_x_hvac[static_cast<int>(oa_x_num)], OA_HVAC_SIZE);
        return tempData;
    }
    uint16_t portId(OA_VEHICLE_NUM oa_x_num) const
    {
        return m_port_id.at(static_cast<int>(oa_x_num));
    }
    void update_hvac1_map(OA_VEHICLE_NUM oa_x_num);
    void update_hvac2_map(OA_VEHICLE_NUM oa_x_num);
    void set_data_struct(const QByteArray &input, const OA_VEHICLE_NUM &oa_x_num);
    void update_table(OA_VEHICLE_NUM oa_x_num, HVAC_NUM hvac);

private:
    void make_signal_slot_connection();
    int get_index(OA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }
    int to_index(OA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }

    void update_struct_with_map(OA_VEHICLE_NUM oa_x_num, HVAC_NUM hvac_num);
    void set_struct_hvac1(OA_VEHICLE_NUM oa_x_num);
    void set_struct_hvac2(OA_VEHICLE_NUM oa_x_num);



    void init_oa_x_hvac1_table(OA_VEHICLE_NUM vehicle_type);
    void init_oa_x_hvac2_table(OA_VEHICLE_NUM vehicle_type);



private:
    const QStringList table_name[2][2] = {
        {
            {"oa_1_vh_riom_ccu_mvb6_hvac1", "value"},
            {"oa_1_vh_riom_ccu_mvb7_hvac2", "value"}


        },
        {
            {"oa_2_vh_riom_ccu_mvb6_hvac1", "value"},
            {"oa_2_vh_riom_ccu_mvb7_hvac2", "value"}


        }
    };

    struct oa_hvac m_oa_x_hvac[2];
    std::map<QString, int> m_inputs_map[2][2];
    QTableWidget *m_tableWidget[2][2];
    std::vector<uint16_t> m_port_id {0x456, 0x496}; // Direct initialization

};

#endif // OA_HVAC_H
