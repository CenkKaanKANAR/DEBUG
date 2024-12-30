#ifndef CCU_TO_OAX_ETCS_H
#define CCU_TO_OAX_ETCS_H

#include <QObject>
#include <map>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QObject>
#include "utils.h"
#include <tsl/ordered_map.h>
#include <QDebug>

class Ccu_To_Oax_Etcs : public QObject
{
    Q_OBJECT
public:
    explicit Ccu_To_Oax_Etcs(QObject *parent = nullptr);
    ~Ccu_To_Oax_Etcs();

    static constexpr int OA_ETCS_OUTPUT_SIZE = sizeof(ccu_to_oax_etcs);
    void set_data_struct(const QByteArray& output, const OA_VEHICLE_NUM& oa_x_num);

    ccu_to_oax_etcs get_data_struct(const OA_VEHICLE_NUM& oa_x_num ) const {
        return m_ccu_to_oax_etcs[static_cast<int>(oa_x_num)];
    }

    QTableWidget* getTableWidget(OA_VEHICLE_NUM  indx){
        return m_tableWidget.at(static_cast<int>(indx));
    }

    uint16_t portId(OA_VEHICLE_NUM  oa_x_num) const
    {
        return m_port_id.at(static_cast<int>(oa_x_num));
    }

    std::vector<uint8_t> moduleData(OA_VEHICLE_NUM oa_x_num) const
    {
        std::vector<uint8_t> tempData(OA_ETCS_OUTPUT_SIZE);
        qDebug() << " size of OA_ETCS_OUTPUT_SIZE MODULE DATA :" << OA_ETCS_OUTPUT_SIZE;
        qDebug() << "m_oa_ccu_vh_riom_mvb1_d_outputs[static_cast<int>(oa_x_num)] : " << m_ccu_to_oax_etcs[static_cast<int>(oa_x_num)].bytes;
        std::memcpy(tempData.data(), &m_ccu_to_oax_etcs[static_cast<int>(oa_x_num)], OA_ETCS_OUTPUT_SIZE);
        qDebug() << " OA ETCS TEMP DATA : " << tempData;
        return tempData;
    }


    void update_struct_with_map(OA_VEHICLE_NUM oa_x_num);
private:
    void init_oa1_table();
    void init_oa2_table();
    void update_table(OA_VEHICLE_NUM oa_x_num);
    void update_map(OA_VEHICLE_NUM oa_x_num);
    void set_struct(OA_VEHICLE_NUM oa_x_num);
    // Helper function to get index from enum
    int get_index(OA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }

    tsl::ordered_map<QString, int> get_map(OA_VEHICLE_NUM  oa_x_num)
    {
        return m_outputs_map[static_cast<int>(oa_x_num)];
    }

private:
    tsl::ordered_map<QString, int> m_outputs_map[2];
    std::vector<QTableWidget *>m_tableWidget;
    std::array<ccu_to_oax_etcs, 2> m_ccu_to_oax_etcs;
    std::vector<uint16_t> m_port_id{0x191, 0x192};

};

#endif // CCU_TO_OAX_ETCS_H
