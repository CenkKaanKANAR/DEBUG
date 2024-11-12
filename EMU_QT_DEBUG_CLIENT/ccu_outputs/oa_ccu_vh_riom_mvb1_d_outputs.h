#ifndef OA_CCU_VH_RIOM_MVB1_D_OUTPUTS_H
#define OA_CCU_VH_RIOM_MVB1_D_OUTPUTS_H


#include <QObject>
#include <map>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QObject>
#include "utils.h"

class Oa_Ccu_Vh_Riom_Mvb1_d_Outputs : public QObject
{
    Q_OBJECT
public:
    explicit Oa_Ccu_Vh_Riom_Mvb1_d_Outputs(QObject *parent = nullptr);
    ~Oa_Ccu_Vh_Riom_Mvb1_d_Outputs();

    void set_data_struct(const QByteArray& output, const OA_VEHICLE_NUM& oa_x_num);

    oa_ccu_vh_riom_mvb1_d_outputs get_data_struct(const OA_VEHICLE_NUM& oa_x_num ) const {
        return m_oa_ccu_vh_riom_mvb1_d_outputs[static_cast<int>(oa_x_num)];
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
    std::array<oa_ccu_vh_riom_mvb1_d_outputs, 2> m_oa_ccu_vh_riom_mvb1_d_outputs;

};

#endif // OA_CCU_VH_RIOM_MVB1_D_OUTPUTS_H
