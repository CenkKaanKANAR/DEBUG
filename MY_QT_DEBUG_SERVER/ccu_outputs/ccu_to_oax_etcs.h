#ifndef CCU_TO_OAX_ETCS_H
#define CCU_TO_OAX_ETCS_H

#include <QObject>
#include <map>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QObject>
#include "utils.h"
class Ccu_To_Oax_Etcs : public QObject
{
    Q_OBJECT
public:
    explicit Ccu_To_Oax_Etcs(QObject *parent = nullptr);
    ~Ccu_To_Oax_Etcs();
    void set_data_struct(const QByteArray& output, const OA_VEHICLE_NUM& oa_x_num);

    ccu_to_oax_etcs get_data_struct(const OA_VEHICLE_NUM& oa_x_num ) const {
        return m_ccu_to_oax_etcs[static_cast<int>(oa_x_num)];
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
    std::array<ccu_to_oax_etcs, 2> m_ccu_to_oax_etcs;

};

#endif // CCU_TO_OAX_ETCS_H
