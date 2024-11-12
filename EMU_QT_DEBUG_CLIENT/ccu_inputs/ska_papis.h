#ifndef SKA_PAPIS_H
#define SKA_PAPIS_H

#include <QObject>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QDebug>
#include "utils.h"
#include <vector>
#include <cstring>



class SKA_PAPIS : public QObject
{
    Q_OBJECT
public:
    explicit SKA_PAPIS(QObject *parent = nullptr);
    ~SKA_PAPIS();
    enum SKA_MVB_NUM {MVB1, MVB2, MVB3};
    static constexpr int SKA_PAPIS_SIZE = sizeof(ska_papis);

    QTableWidget* getTableWidget(SKA_VEHICLE_NUM  ska_x_num, SKA_MVB_NUM mvb_num){
        return m_tableWidget[static_cast<int>(ska_x_num)][mvb_num];
    }

    ska_vh_riom_ccu_mvb10_papis1& ska_x_vh_riom_ccu_mvb10_papis1(SKA_VEHICLE_NUM ska_type) {
        return  m_ska_x_papis[static_cast<int>(ska_type)].ska_vh_riom_ccu_mvb10_papis1;
    }

    ska_vh_riom_ccu_mvb11_papis2& ska_x_vh_riom_ccu_mvb11_papis2(SKA_VEHICLE_NUM ska_type) {
        return  m_ska_x_papis[static_cast<int>(ska_type)].ska_vh_riom_ccu_mvb11_papis2;
    }

    ska_vh_riom_ccu_mvb12_papis3& ska_x_vh_riom_ccu_mvb12_papis3(SKA_VEHICLE_NUM ska_type) {
        return  m_ska_x_papis[static_cast<int>(ska_type)].ska_vh_riom_ccu_mvb12_papis3;
    }

    std::array<uint8_t, SKA_PAPIS_SIZE> ska_x_papis_arr(SKA_VEHICLE_NUM ska_x_num) const
    {
        std::array<uint8_t, SKA_PAPIS_SIZE> tempArr;
        memcpy(tempArr.begin(), &m_ska_x_papis[static_cast<int>(ska_x_num)], SKA_PAPIS_SIZE);
        return tempArr;
    }

    std::vector<uint8_t> moduleData(SKA_VEHICLE_NUM ska_x_num) const
    {
        std::vector<uint8_t> tempData(SKA_PAPIS_SIZE);
        std::memcpy(tempData.data(), &m_ska_x_papis[static_cast<int>(ska_x_num)], SKA_PAPIS_SIZE);
        return tempData;
    }


    uint16_t portId(SKA_VEHICLE_NUM ska_x_num) const
    {
        return m_port_id.at(static_cast<int>(ska_x_num));
    }

    void update_mvb10_map(SKA_VEHICLE_NUM ska_x_num);
    void update_mvb11_map(SKA_VEHICLE_NUM ska_x_num);
    void update_mvb12_map(SKA_VEHICLE_NUM ska_x_num);
    void update_table(SKA_VEHICLE_NUM ska_x_num, SKA_MVB_NUM mvb);

private:
    void make_signal_slot_connection();
    int get_index(SKA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }
    int to_index(SKA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }

    void update_struct_with_map(SKA_VEHICLE_NUM ska_x_num, SKA_MVB_NUM mvb_num);
    void set_struct_mvb10(SKA_VEHICLE_NUM ska_x_num);
    void set_struct_mvb11(SKA_VEHICLE_NUM ska_x_num);
    void set_struct_mvb12(SKA_VEHICLE_NUM ska_x_num);

    void init_ska_x_mvb10_table(SKA_VEHICLE_NUM vehicle_type);
    void init_ska_x_mvb11_table(SKA_VEHICLE_NUM vehicle_type);
    void init_ska_x_mvb12_table(SKA_VEHICLE_NUM vehicle_type);
private:
    const QStringList table_name[2][3] = {
        {
            {"ska_1_vh_riom_ccu_mvb10_papis1", "value"},
            {"ska_1_vh_riom_ccu_mvb11_papis2", "value"},
            {"ska_1_vh_riom_ccu_mvb12_papis3", "value"}

        },
        {
            {"ska_2_vh_riom_ccu_mvb10_papis1", "value"},
            {"ska_2_vh_riom_ccu_mvb11_papis2", "value"},
            {"ska_2_vh_riom_ccu_mvb12_papis3", "value"}

        }
    };

    struct ska_papis m_ska_x_papis[2];
    std::map<QString, int> m_inputs_map[2][3];
    QTableWidget *m_tableWidget[2][3];
    std::vector<uint16_t> m_port_id {0x41A, 0x4DA}; // Direct initialization



};

#endif // SKA_BCU_H
