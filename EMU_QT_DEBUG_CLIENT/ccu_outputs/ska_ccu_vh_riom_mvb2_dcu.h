#ifndef SKA_CCU_VH_RIOM_MVB2_DCU_H
#define SKA_CCU_VH_RIOM_MVB2_DCU_H
#include <map>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QObject>
#include "utils.h"

class Ska_Ccu_Vh_Riom_Mvb2_Dcu : public QObject
{
    Q_OBJECT
public:
    explicit Ska_Ccu_Vh_Riom_Mvb2_Dcu(QObject *parent = nullptr);
    ~Ska_Ccu_Vh_Riom_Mvb2_Dcu();

    void set_data_struct(const QByteArray& output, const SKA_VEHICLE_NUM& ska_x_num);

    ska_ccu_vh_riom_mvb2_dcu_hvac get_data_struct(const SKA_VEHICLE_NUM& ska_x_num ) const {
        return m_ska_ccu_vh_riom_mvb2_dcu[static_cast<int>(ska_x_num)];
    }

    QTableWidget* getTableWidget(SKA_VEHICLE_NUM  indx){
        return m_tableWidget.at(static_cast<int>(indx));
    }

private:
    void init_ska1_table();
    void init_ska2_table();
    void update_table(SKA_VEHICLE_NUM ska_x_num);
    void update_map(SKA_VEHICLE_NUM ska_x_num);
    // Helper function to get index from enum
    int get_index(SKA_VEHICLE_NUM num) const {
        return static_cast<int>(num);
    }

    std::map<QString, int> get_map(SKA_VEHICLE_NUM  ska_x_num)
    {
        return m_outputs_map[static_cast<int>(ska_x_num)];
    }

private:
    std::map<QString, int> m_outputs_map[2];
    //QTableWidget * m_tableWidget[2];
    std::vector<QTableWidget *>m_tableWidget;
    std::array<ska_ccu_vh_riom_mvb2_dcu_hvac, 2> m_ska_ccu_vh_riom_mvb2_dcu;

};

#endif // SKA_CCU_VH_RIOM_MVB2_DCU_H
