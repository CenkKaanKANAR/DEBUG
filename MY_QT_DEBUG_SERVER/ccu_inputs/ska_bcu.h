#ifndef SKA_BCU_H
#define SKA_BCU_H

#include <QObject>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QDebug>
#include "utils.h"
#include <vector>
#include <cstring>



class Ska_Bcu : public QObject
{
    Q_OBJECT
public:
    explicit Ska_Bcu(QObject *parent = nullptr);
    ~Ska_Bcu();
    enum SKA_MVB_NUM {MVB1, MVB2, MVB3};
    static constexpr int SKA_BCU_SIZE = sizeof(ska_bcu);

    QTableWidget* getTableWidget(SKA_VEHICLE_NUM  ska_x_num, SKA_MVB_NUM mvb_num){
        return m_tableWidget[static_cast<int>(ska_x_num)][mvb_num];
    }

    bcu_ccu_mvb1& ska_x_bcu_ccu_mvb1(SKA_VEHICLE_NUM ska_type) {
        return  m_ska_x_bcu[static_cast<int>(ska_type)].ska_bcu_ccu_mvb1;
    }

    bcu_ccu_mvb2& ska_x_bcu_ccu_mvb2(SKA_VEHICLE_NUM ska_type) {
        return  m_ska_x_bcu[static_cast<int>(ska_type)].ska_bcu_ccu_mvb2;
    }

    /*bcu_ccu_mvb3& ska_x_bcu_ccu_mvb3(SKA_VEHICLE_NUM ska_type) {
        return  m_ska_x_bcu[static_cast<int>(ska_type)].ska_bcu_ccu_mvb3;
    }*/

    std::array<uint8_t, SKA_BCU_SIZE> ska_x_bcu_arr(SKA_VEHICLE_NUM ska_x_num) const
    {
        std::array<uint8_t, SKA_BCU_SIZE> tempArr;
        memcpy(tempArr.begin(), &m_ska_x_bcu[static_cast<int>(ska_x_num)], SKA_BCU_SIZE);
        return tempArr;
    }

    std::vector<uint8_t> moduleData(SKA_VEHICLE_NUM ska_x_num) const
    {
        std::vector<uint8_t> tempData(SKA_BCU_SIZE);
        std::memcpy(tempData.data(), &m_ska_x_bcu[static_cast<int>(ska_x_num)], SKA_BCU_SIZE);
        return tempData;
    }


    uint16_t portId(SKA_VEHICLE_NUM ska_x_num) const
    {
        return m_port_id.at(static_cast<int>(ska_x_num));
    }

    void update_mvb1_map(SKA_VEHICLE_NUM ska_x_num);
    void update_mvb2_map(SKA_VEHICLE_NUM ska_x_num);
    //void update_mvb3_map(SKA_VEHICLE_NUM ska_x_num);
    void update_table(SKA_VEHICLE_NUM ska_x_num, SKA_MVB_NUM mvb_num);
    void set_data_struct(const QByteArray &input, const SKA_VEHICLE_NUM &ska_x_num);


private:
    void make_signal_slot_connection();
    int get_index(SKA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }
    int to_index(SKA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }

    void update_struct_with_map(SKA_VEHICLE_NUM ska_x_num, SKA_MVB_NUM mvb_num);
    void set_struct_mvb1(SKA_VEHICLE_NUM ska_x_num);
    void set_struct_mvb2(SKA_VEHICLE_NUM ska_x_num);
    //void set_struct_mvb3(SKA_VEHICLE_NUM ska_x_num);

    void init_oa_x_mvb1_table(SKA_VEHICLE_NUM vehicle_type);
    void init_oa_x_mvb2_table(SKA_VEHICLE_NUM vehicle_type);
    //void init_oa_x_mvb3_table(SKA_VEHICLE_NUM vehicle_type);
private:
    const QStringList table_name[2][3] = {
        {
            {"ska_1_bcu_ccu_mvb1", "value"},
            {"ska_1_bcu_ccu_mvb2", "value"},

        },
        {
            {"ska_2_bcu_ccu_mvb1", "value"},
            {"ska_2_bcu_ccu_mvb2", "value"},

        }
    };

    struct ska_bcu m_ska_x_bcu[2];
    std::map<QString, int> m_inputs_map[2][3];
    QTableWidget *m_tableWidget[2][3];
    std::vector<uint16_t> m_port_id {0x601, 0x6C1}; // Direct initialization



};

#endif // SKA_BCU_H
