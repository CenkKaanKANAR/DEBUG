#ifndef SKA_HVAC_H
#define SKA_HVAC_H

#include <QObject>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QDebug>
#include "utils.h"


class Ska_Hvac : public QObject
{
    Q_OBJECT
public:
    explicit Ska_Hvac(QObject *parent = nullptr);
    ~Ska_Hvac();



public:
    enum HVAC_NUM {HVAC1, HVAC2, HVAC3};
    static constexpr int SKA_HVAC_SIZE = sizeof(ska_hvac);
    QTableWidget* getTableWidget(SKA_VEHICLE_NUM  ska_type, HVAC_NUM hvac_num){
        return m_tableWidget[static_cast<int>(ska_type)][hvac_num];
    }
    ska_vh_riom_ccu_mvb13_hvac1& ska_x_vh_riom_ccu_mvb13_hvac1(SKA_VEHICLE_NUM ska_type) {
        return  m_ska_x_hvac[static_cast<int>(ska_type)].ska_vh_riom_ccu_mvb13_hvac1;
    }
    ska_vh_riom_ccu_mvb14_hvac2& ska_x_vh_riom_ccu_mvb14_hvac2(SKA_VEHICLE_NUM ska_type) {
        return  m_ska_x_hvac[static_cast<int>(ska_type)].ska_vh_riom_ccu_mvb14_hvac2;
    }

    ska_vh_riom_ccu_mvb15_hvac3& ska_x_vh_riom_ccu_mvb15_hvac3(SKA_VEHICLE_NUM ska_type) {
        return  m_ska_x_hvac[static_cast<int>(ska_type)].ska_vh_riom_ccu_mvb15_hvac3;
    }

    std::array<uint8_t, SKA_HVAC_SIZE> ska_x_hvac_arr(SKA_VEHICLE_NUM ska_type) const
    {
        std::array<uint8_t, SKA_HVAC_SIZE> tempArr;
        memcpy(tempArr.begin(), &m_ska_x_hvac[static_cast<int>(ska_type)], SKA_HVAC_SIZE);
        return tempArr;
    }

    std::vector<uint8_t> moduleData(SKA_VEHICLE_NUM ska_x_num) const
    {
        std::vector<uint8_t> tempData(SKA_HVAC_SIZE);
        std::memcpy(tempData.data(), &m_ska_x_hvac[static_cast<int>(ska_x_num)], SKA_HVAC_SIZE);
        return tempData;
    }
    uint16_t portId(SKA_VEHICLE_NUM ska_x_num) const
    {
        return m_port_id.at(static_cast<int>(ska_x_num));
    }
    void update_hvac1_map(SKA_VEHICLE_NUM ska_x_num);
    void update_hvac2_map(SKA_VEHICLE_NUM ska_x_num);
    void update_hvac3_map(SKA_VEHICLE_NUM ska_x_num);

    void set_data_struct(const QByteArray &input, const SKA_VEHICLE_NUM &ska_x_num);
    void update_table(SKA_VEHICLE_NUM ska_x_num, HVAC_NUM hvac_num);
private:
    void make_signal_slot_connection();
    int get_index(SKA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }
    int to_index(SKA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }

    void update_struct_with_map(SKA_VEHICLE_NUM ska_x_num, HVAC_NUM hvac_num);
    void set_struct_hvac1(SKA_VEHICLE_NUM ska_x_num);
    void set_struct_hvac2(SKA_VEHICLE_NUM ska_x_num);
    void set_struct_hvac3(SKA_VEHICLE_NUM ska_x_num);


    void init_ska_x_hvac1_table(SKA_VEHICLE_NUM vehicle_type);
    void init_ska_x_hvac2_table(SKA_VEHICLE_NUM vehicle_type);
    void init_ska_x_hvac3_table(SKA_VEHICLE_NUM vehicle_type);


private:
    const QStringList table_name[2][3] = {
        {
            {"ska_1_vh_riom_ccu_mvb13_hvac1", "value"},
            {"ska_1_vh_riom_ccu_mvb14_hvac2", "value"},
            {"ska_1_vh_riom_ccu_mvb15_hvac3", "value"}

        },
        {
            {"ska_2_vh_riom_ccu_mvb13_hvac1", "value"},
            {"ska_2_vh_riom_ccu_mvb14_hvac2", "value"},
            {"ska_2_vh_riom_ccu_mvb15_hvac3", "value"}

        }
    };

    struct ska_hvac m_ska_x_hvac[2];
    std::map<QString, int> m_inputs_map[2][3];
    QTableWidget *m_tableWidget[2][3];
    std::vector<uint16_t> m_port_id {0x41D, 0x4DD}; // Direct initialization

};

#endif // SKA_HVAC_H
