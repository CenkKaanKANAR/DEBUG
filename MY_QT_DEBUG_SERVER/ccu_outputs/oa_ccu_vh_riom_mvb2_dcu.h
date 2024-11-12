#ifndef OA_CCU_VH_RIOM_MVB2_DCU_H
#define OA_CCU_VH_RIOM_MVB2_DCU_H

#include <QObject>
#include <map>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QObject>
#include "utils.h"

class Oa_Ccu_Vh_Riom_Mvb2_Dcu : public QObject
{
    Q_OBJECT
public:
    explicit Oa_Ccu_Vh_Riom_Mvb2_Dcu(QObject *parent = nullptr);
    ~Oa_Ccu_Vh_Riom_Mvb2_Dcu();

    void set_data_struct(const QByteArray& output, const OA_VEHICLE_NUM& oa_x_num);

    oa_ccu_vh_riom_mvb2_dcu_hvac get_data_struct(const OA_VEHICLE_NUM& oa_x_num ) const {
        return m_oa_ccu_vh_riom_mvb2_dcu[static_cast<int>(oa_x_num)];
    }

    QTableWidget* getTableWidget(OA_VEHICLE_NUM  indx){
        return m_tableWidget.at(static_cast<int>(indx));
    }

private:
    void init_oa1_table();
    void init_oa2_table();
    void update_table(OA_VEHICLE_NUM oa_x_num);
    void update_map(OA_VEHICLE_NUM oa_x_num);
    // Helper function to get index from enum
    int get_index(OA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }

    std::map<QString, int> get_map(OA_VEHICLE_NUM  oa_x_num)
    {
        return m_outputs_map[static_cast<int>(oa_x_num)];
    }

private:
    std::map<QString, int> m_outputs_map[2];
    std::vector<QTableWidget *>m_tableWidget;
    std::array<oa_ccu_vh_riom_mvb2_dcu_hvac, 2> m_oa_ccu_vh_riom_mvb2_dcu;


};

#endif // OA_CCU_VH_RIOM_MVB2_DCU_H
