#ifndef OA_CCU_VH_RIOM_MVB2_DCU_H
#define OA_CCU_VH_RIOM_MVB2_DCU_H

#include <QObject>
#include <map>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QObject>
#include <QDebug>
#include "utils.h"
#include <tsl/ordered_map.h>


class Oa_Ccu_Vh_Riom_Mvb2_Dcu : public QObject
{
    Q_OBJECT
public:
    explicit Oa_Ccu_Vh_Riom_Mvb2_Dcu(QObject *parent = nullptr);
    ~Oa_Ccu_Vh_Riom_Mvb2_Dcu();
    static constexpr int OA_VH_RIOM_DCU_OUTPUT_SIZE = sizeof(oa_ccu_vh_riom_mvb2_dcu_hvac);
    void set_data_struct(const QByteArray& output, const OA_VEHICLE_NUM& oa_x_num);

    oa_ccu_vh_riom_mvb2_dcu_hvac get_data_struct(const OA_VEHICLE_NUM& oa_x_num ) const {
        return m_oa_ccu_vh_riom_mvb2_dcu[static_cast<int>(oa_x_num)];
    }

    QTableWidget* getTableWidget(OA_VEHICLE_NUM  indx){
        return m_tableWidget.at(static_cast<int>(indx));
    }
    void update_table(OA_VEHICLE_NUM oa_x_num);
    void update_map(OA_VEHICLE_NUM oa_x_num);
    void update_struct_with_map(OA_VEHICLE_NUM oa_x_num);

    uint16_t portId(OA_VEHICLE_NUM  oa_x_num) const
    {
        return m_port_id.at(static_cast<int>(oa_x_num));
    }

    std::vector<uint8_t> moduleData(OA_VEHICLE_NUM oa_x_num) const
    {
        std::vector<uint8_t> tempData(OA_VH_RIOM_DCU_OUTPUT_SIZE);
        qDebug() << " size of OA_VH_RIOM_DCU_OUTPUT MODULE DATA :" << OA_VH_RIOM_DCU_OUTPUT_SIZE;
        qDebug() << "m_oa_ccu_vh_riom_mvb1_d_outputs[static_cast<int>(oa_x_num)] : " << m_oa_ccu_vh_riom_mvb2_dcu[static_cast<int>(oa_x_num)].bytes;
        std::memcpy(tempData.data(), &m_oa_ccu_vh_riom_mvb2_dcu[static_cast<int>(oa_x_num)], OA_VH_RIOM_DCU_OUTPUT_SIZE);
        qDebug() << " OA VH TEMP DATA : " << tempData;
        return tempData;
    }


private:
    void init_oa1_table();
    void init_oa2_table();

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
    std::array<oa_ccu_vh_riom_mvb2_dcu_hvac, 2> m_oa_ccu_vh_riom_mvb2_dcu;
    std::vector<uint16_t> m_port_id{0x051, 0x071};


};

#endif // OA_CCU_VH_RIOM_MVB2_DCU_H
