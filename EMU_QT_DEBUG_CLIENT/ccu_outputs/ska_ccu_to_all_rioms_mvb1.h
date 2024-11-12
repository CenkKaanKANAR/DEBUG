#ifndef SKA_CCU_TO_ALL_RIOMS_MVB1_H
#define SKA_CCU_TO_ALL_RIOMS_MVB1_H

#include <QObject>
#include <map>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QObject>
#include "utils.h"

class Ska_Ccu_To_All_Rioms_Mvb1 : public QObject
{
    Q_OBJECT
public:
    explicit Ska_Ccu_To_All_Rioms_Mvb1(QObject *parent = nullptr);
    ~Ska_Ccu_To_All_Rioms_Mvb1();
    void set_data_struct(const QByteArray& output);

    ska_ccu_to_all_rioms_mvb1 get_data_struct() const {
        return m_ska_ccu_to_all_rioms_mvb1;
    }

    QTableWidget* getTableWidget(){
        return m_tableWidget;
    }

private:
    void init_table();
    void update_table();
    void update_map();

    std::map<QString, int> get_map()
    {
        return m_outputs_map;
    }

private:
    std::map<QString, int> m_outputs_map;
    QTableWidget *m_tableWidget;
    ska_ccu_to_all_rioms_mvb1 m_ska_ccu_to_all_rioms_mvb1;

};

#endif // SKA_CCU_TO_ALL_RIOMS_MVB1_H
