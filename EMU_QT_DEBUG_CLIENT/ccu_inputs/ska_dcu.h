#ifndef SKA_DCU_H
#define SKA_DCU_H

#include <QTableWidget>
#include <QDebug>
#include <QObject>

#include "shm_data_gaziray.h"
#include "utils.h"
#include <cstring>
#include <vector>



class SKA_DCU : public QObject
{
    Q_OBJECT
public:
    explicit SKA_DCU(QObject *parent = nullptr);
    ~SKA_DCU();
    static constexpr int SKA_DCU_SIZE = sizeof(ska_dcu);
    enum DCU_LIST {DCU1, DCU2, DCU3, DCU4};

    QTableWidget* getTableWidget(SKA_VEHICLE_NUM  ska_x_num, DCU_LIST dcu){
        return m_tableWidget[static_cast<int>(ska_x_num)][dcu];
    }

    ska_vh_riom_ccu_mvb2_dcu1& ska_x_vh_riom_ccu_mvb2_dcu1(SKA_VEHICLE_NUM ska_type) {
        return  m_ska_x_dcu[static_cast<int>(ska_type)].ska_vh_riom_ccu_mvb2_dcu1;
    }

    ska_vh_riom_ccu_mvb3_dcu2& ska_x_vh_riom_ccu_mvb3_dcu2(SKA_VEHICLE_NUM ska_type) {
        return  m_ska_x_dcu[static_cast<int>(ska_type)].ska_vh_riom_ccu_mvb3_dcu2;
    }

    ska_vh_riom_ccu_mvb4_dcu3& ska_x_vh_riom_ccu_mvb4_dcu3(SKA_VEHICLE_NUM ska_type) {
        return  m_ska_x_dcu[static_cast<int>(ska_type)].ska_vh_riom_ccu_mvb4_dcu3;
    }

    ska_vh_riom_ccu_mvb5_dcu4& ska_x_vh_riom_ccu_mvb5_dcu4(SKA_VEHICLE_NUM ska_type) {
        return  m_ska_x_dcu[static_cast<int>(ska_type)].ska_vh_riom_ccu_mvb5_dcu4;
    }

    std::array<uint8_t, SKA_DCU_SIZE> ska_x_dcu_arr(SKA_VEHICLE_NUM ska_x_num) const
    {
        std::array<uint8_t, SKA_DCU_SIZE> tempArr;
        memcpy(tempArr.begin(), &m_ska_x_dcu[static_cast<int>(ska_x_num)], SKA_DCU_SIZE);
        return tempArr;
    }

    std::vector<uint8_t> moduleData(SKA_VEHICLE_NUM ska_x_num) const
    {
        std::vector<uint8_t> tempData(SKA_DCU_SIZE);
        std::memcpy(tempData.data(), &m_ska_x_dcu[static_cast<int>(ska_x_num)], SKA_DCU_SIZE);
        return tempData;
    }

    uint16_t portId(SKA_VEHICLE_NUM ska_x_num) const
    {
        return m_port_id.at(static_cast<int>(ska_x_num));
    }

    void update_dcu1_map(SKA_VEHICLE_NUM ska_x_num, DCU_LIST dcu);
    void update_dcu2_map(SKA_VEHICLE_NUM ska_x_num, DCU_LIST dcu);
    void update_dcu3_map(SKA_VEHICLE_NUM ska_x_num, DCU_LIST dcu);
    void update_dcu4_map(SKA_VEHICLE_NUM ska_x_num, DCU_LIST dcu);
    //void update_struct_with_map(SKA_VEHICLE_NUM ska_x_num, DCU_LIST DCU_NUM);
    void update_table(SKA_VEHICLE_NUM ska_x_num, DCU_LIST dcu_num);
    void set_data_struct(const QByteArray &input, const SKA_VEHICLE_NUM &ska_x_num);

private:
    void make_signal_slot_connection();
    //void update_table(SKA_VEHICLE_NUM ska_x_num, DCU_LIST dcu);

    int get_index(SKA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }
    int to_index(SKA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }

    void update_struct_with_map(SKA_VEHICLE_NUM ska_x_num, DCU_LIST DCU_NUM);
    void set_struct_dcu1(SKA_VEHICLE_NUM ska_x_num, DCU_LIST dcu);
    void set_struct_dcu2(SKA_VEHICLE_NUM ska_x_num, DCU_LIST dcu);
    void set_struct_dcu3(SKA_VEHICLE_NUM ska_x_num, DCU_LIST dcu);
    void set_struct_dcu4(SKA_VEHICLE_NUM ska_x_num, DCU_LIST dcu);


    void init_ska_x_mvb2_dcu1_table(SKA_VEHICLE_NUM vehicle_type);
    void init_ska_x_mvb3_dcu2_table(SKA_VEHICLE_NUM vehicle_type);
    void init_ska_x_mvb4_dcu3_table(SKA_VEHICLE_NUM vehicle_type);
    void init_ska_x_mvb5_dcu4_table(SKA_VEHICLE_NUM vehicle_type);

    const QStringList table_name[2][4] = {
        {
            {"ska_1_vh_riom_ccu_mvb2_dcu1", "value"},
            {"ska_1_vh_riom_ccu_mvb3_dcu2", "value"},
            {"ska_1_vh_riom_ccu_mvb4_dcu3", "value"},
            {"ska_1_vh_riom_ccu_mvb5_dcu4", "value"}
        },
        {
            {"ska_2_vh_riom_ccu_mvb2_dcu1", "value"},
            {"ska_2_vh_riom_ccu_mvb3_dcu2", "value"},
            {"ska_2_vh_riom_ccu_mvb4_dcu3", "value"},
            {"ska_2_vh_riom_ccu_mvb5_dcu4", "value"}
        }
    };

    struct ska_dcu m_ska_x_dcu[2];
    std::map<QString, int> m_inputs_map[2][4];
    QTableWidget *m_tableWidget[2][4];
    std::vector<uint16_t> m_port_id {0x412, 0x4D2}; // Direct initialization


};

#endif // SKA_DCU_H
