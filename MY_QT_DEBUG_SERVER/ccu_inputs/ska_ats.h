#ifndef SKA_ATS_H
#define SKA_ATS_H

#include <QObject>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QDebug>
#include "utils.h"
#include <memory>
#include <cstring>
#include <vector>



class Ska_Ats : public QObject
{
    Q_OBJECT
public:
    explicit Ska_Ats(QObject *parent = nullptr);
    //Ska_Ats(const Ska_Ats &r); // copy constructor
    ~Ska_Ats();
    static constexpr int SKA_ATS_SIZE = sizeof(ska_ats);
    QTableWidget* getTableWidget(SKA_VEHICLE_NUM  indx){
        return m_tableWidget.at(static_cast<int>(indx));
    }
    std::array<uint8_t, SKA_ATS_SIZE> data_arr(SKA_VEHICLE_NUM ska_x_num) const
    {
        std::array<uint8_t, SKA_ATS_SIZE> tempArr;
        memcpy(tempArr.begin(), &m_ska_x_ats[static_cast<int>(ska_x_num)],SKA_ATS_SIZE);
        return tempArr;
    }

    std::vector<uint8_t> moduleData(SKA_VEHICLE_NUM ska_x_num) const
    {
        std::vector<uint8_t> tempData(SKA_ATS_SIZE);
        std::memcpy(tempData.data(), &m_ska_x_ats[static_cast<int>(ska_x_num)], SKA_ATS_SIZE);
        return tempData;
    }

    uint16_t portId(SKA_VEHICLE_NUM ska_x_num) const
    {
        return m_port_id.at(static_cast<int>(ska_x_num));
    }


    ska_vh_riom_ccu_mvb9_ats& ska_x_vh_riom_ccu_mvb9_ats(SKA_VEHICLE_NUM ska_x_num) {
        return m_ska_x_ats[static_cast<int>(ska_x_num)].ska_vh_riom_ccu_mvb9_ats;
    }

    void update_map(SKA_VEHICLE_NUM ska_x_num);
    void update_table(SKA_VEHICLE_NUM ska_x_num);
    void set_data_struct(const QByteArray &input, const SKA_VEHICLE_NUM &ska_x_num);
private:
    void make_signal_slot_connection();
    void init_ska_x_table(SKA_VEHICLE_NUM ska_x_num);
    void update_struct_with_map(SKA_VEHICLE_NUM ska_x_num);
    void set_struct(SKA_VEHICLE_NUM ska_x_num);
    int get_index(SKA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }

private:
    const QStringList table_name[2] = {
        {"ska_1_vh_riom_ccu_mvb9_ats", "value"},
        {"ska_2_vh_riom_ccu_mvb9_ats", "value"}
    };

    struct ska_ats m_ska_x_ats[2];
    std::map<QString, int> m_inputs_map[2];
    std::vector<QTableWidget *>m_tableWidget;
    //std::vector<std::unique_ptr<QTableWidget>>m_tableWidget;
    std::vector<uint16_t> m_port_id {0x419, 0x4D9}; // Direct initialization

};

#endif // SKA_ATS_H
