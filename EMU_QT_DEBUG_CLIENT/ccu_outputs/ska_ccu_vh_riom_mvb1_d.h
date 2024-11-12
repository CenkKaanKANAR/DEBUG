#ifndef SKA_CCU_VH_RIOM_MVB1_D_H
#define SKA_CCU_VH_RIOM_MVB1_D_H
#include <map>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QObject>
#include "utils.h"


class Ska_ccu_vh_riom_mvb1_d : public QObject
{
    Q_OBJECT
public:
    explicit Ska_ccu_vh_riom_mvb1_d(QObject *parent = nullptr);
       void show_table_widget_contents();
    ~Ska_ccu_vh_riom_mvb1_d();

    void set_data_struct(const QByteArray& output, const SKA_VEHICLE_NUM& ska);

    ska_ccu_vh_riom_mvb1_d_outputs get_data_struct(const SKA_VEHICLE_NUM& ska_x_num ) const {
        return m_ska_ccu_vh_riom_mvb1_d_outputs[static_cast<int>(ska_x_num)];
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

    // Disallow copy and assignment
    Q_DISABLE_COPY(Ska_ccu_vh_riom_mvb1_d)
private:
    std::map<QString, int> m_outputs_map[2];
    //QTableWidget * m_tableWidget[2];
    std::vector<QTableWidget *>m_tableWidget;
    //ska_ccu_vh_riom_mvb1_d_outputs m_ska_ccu_vh_riom_mvb1_d_outputs[2];
    std::array<ska_ccu_vh_riom_mvb1_d_outputs, 2> m_ska_ccu_vh_riom_mvb1_d_outputs;

};

#endif // SKA_CCU_VH_RIOM_MVB1_D_H
