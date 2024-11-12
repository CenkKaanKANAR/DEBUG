#ifndef CCU_TO_ALL_JRUS_3_H
#define CCU_TO_ALL_JRUS_3_H

#include <QObject>
#include <map>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QObject>
#include "utils.h"
#include <QDebug>

class Ccu_To_All_Jrus_3 : public QObject
{
    Q_OBJECT
public:
    explicit Ccu_To_All_Jrus_3(QObject *parent = nullptr);
    ~Ccu_To_All_Jrus_3();
    void set_data_struct(const QByteArray& output);

    ccu_to_all_jrus_3 get_data_struct() const {
        return m_ccu_to_all_jrus_3;
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
    ccu_to_all_jrus_3 m_ccu_to_all_jrus_3;

};

#endif // CCU_TO_ALL_JRUS_3_H
