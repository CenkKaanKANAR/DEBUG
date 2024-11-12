#ifndef SKA_CCU_TO_ALL_RIOMS_MVB2_H
#define SKA_CCU_TO_ALL_RIOMS_MVB2_H

#include <map>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QObject>
#include "utils.h"

class Ska_Ccu_To_All_Rioms_Mvb2 : public QObject
{
    Q_OBJECT
public:
    explicit Ska_Ccu_To_All_Rioms_Mvb2(QObject *parent = nullptr);
    ~Ska_Ccu_To_All_Rioms_Mvb2();
    void set_data_struct(const QByteArray& output);

    ska_ccu_to_all_rioms_mvb2 get_data_struct() const {
        return m_ska_ccu_to_all_rioms_mvb2;
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
    ska_ccu_to_all_rioms_mvb2 m_ska_ccu_to_all_rioms_mvb2;
};

#endif // SKA_CCU_TO_ALL_RIOMS_MVB2 _H
