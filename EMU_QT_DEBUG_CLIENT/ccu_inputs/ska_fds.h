#ifndef SKA_FDS_H
#define SKA_FDS_H

#include <QTableWidget>
#include <QDebug>
#include <QObject>

#include "shm_data_gaziray.h"
#include "utils.h"
#include <vector>
#include <cstring>




class SKA_FDS : public QObject
{
    Q_OBJECT
public:
    explicit SKA_FDS(QObject *parent = nullptr);
    ~SKA_FDS();
    enum FDS_NUM{FDS1, FDS2, FDS3};
    static constexpr int SKA_FDS_SIZE = sizeof(ska_fds);
    QTableWidget* getTableWidget(SKA_VEHICLE_NUM  ska_x_num, FDS_NUM fds){
        return m_tableWidget[static_cast<int>(ska_x_num)][fds];
    }

    ska_vh_riom_ccu_mvb6_fds1& ska_x_vh_riom_ccu_mvb6_fds1(SKA_VEHICLE_NUM ska_type)  {
        return m_ska_x_fds[static_cast<int>(ska_type)].ska_vh_riom_ccu_mvb6_fds1;
    }

    ska_vh_riom_ccu_mvb7_fds2& ska_x_vh_riom_ccu_mvb7_fds2(SKA_VEHICLE_NUM ska_type)  {
        return m_ska_x_fds[static_cast<int>(ska_type)].ska_vh_riom_ccu_mvb7_fds2;
    }

    ska_vh_riom_ccu_mvb8_fds3& ska_x_vh_riom_ccu_mvb8_fds3(SKA_VEHICLE_NUM ska_type)  {
        return m_ska_x_fds[static_cast<int>(ska_type)].ska_vh_riom_ccu_mvb8_fds3;
    }

    std::array<uint8_t, SKA_FDS_SIZE> ska_x_fds_arr(SKA_VEHICLE_NUM ska_x_num) const
    {
        std::array<uint8_t, SKA_FDS_SIZE> tempArr;
        memcpy(tempArr.begin(), &m_ska_x_fds[static_cast<int>(ska_x_num)], SKA_FDS_SIZE);
        return tempArr;
    }

    std::vector<uint8_t> moduleData(SKA_VEHICLE_NUM ska_x_num) const
    {
        std::vector<uint8_t> tempData(SKA_FDS_SIZE);
        std::memcpy(tempData.data(), &m_ska_x_fds[static_cast<int>(ska_x_num)], SKA_FDS_SIZE);
        return tempData;
    }

    uint16_t portId(SKA_VEHICLE_NUM ska_x_num) const
    {
        return m_port_id.at(static_cast<int>(ska_x_num));
    }

    void update_fds1_map(SKA_VEHICLE_NUM ska_x_num);
    void update_fds2_map(SKA_VEHICLE_NUM ska_x_num);
    void update_fds3_map(SKA_VEHICLE_NUM ska_x_num);
    void update_table(SKA_VEHICLE_NUM ska_x_num,FDS_NUM fds_num);
    void set_data_struct(const QByteArray &input, const SKA_VEHICLE_NUM &ska_x_num);


private:

    void make_signal_slot_connection();
    int get_index(SKA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }
    int to_index(SKA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }
    void update_struct_with_map(SKA_VEHICLE_NUM ska_x_num, FDS_NUM fds_num);
    void set_struct_fds1(SKA_VEHICLE_NUM ska_x_num);
    void set_struct_fds2(SKA_VEHICLE_NUM ska_x_num);
    void set_struct_fds3(SKA_VEHICLE_NUM ska_x_num);

    void init_ska_x_fds1_table(SKA_VEHICLE_NUM vehicle_type);
    void init_ska_x_fds2_table(SKA_VEHICLE_NUM vehicle_type);
    void init_ska_x_fds3_table(SKA_VEHICLE_NUM vehicle_type);

    const QStringList table_name[2][3] = {
        {
            {"ska_1_vh_riom_ccu_mvb6_fds1", "value"},
            {"ska_1_vh_riom_ccu_mvb7_fds2", "value"},
            {"ska_1_vh_riom_ccu_mvb7_fds3", "value"}
        },
        {
            {"ska_2_vh_riom_ccu_mvb6_fds1", "value"},
            {"ska_2_vh_riom_ccu_mvb7_fds2", "value"},
            {"ska_2_vh_riom_ccu_mvb7_fds3", "value"}
        }
    };
    struct ska_fds m_ska_x_fds[2];
    std::map<QString, int> m_inputs_map[2][3];
    QTableWidget *m_tableWidget[2][3];
    std::vector<uint16_t> m_port_id {0x416, 0x4D6}; // Direct initialization



};

#endif // SKA_FDS_H
