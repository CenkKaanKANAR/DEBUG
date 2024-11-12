#ifndef CCU_TO_ALL_JRUS_2_H
#define CCU_TO_ALL_JRUS_2_H

#include <QObject>
#include <map>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QObject>
#include "utils.h"
#include <QDebug>

class Ccu_To_All_Jrus_2 : public QObject
{
    Q_OBJECT
public:
    explicit Ccu_To_All_Jrus_2(QObject *parent = nullptr);
    ~Ccu_To_All_Jrus_2();
    void set_data_struct(const QByteArray& output);

    ccu_to_all_jrus_2 get_data_struct() const {
        return m_ccu_to_all_jrus_2;
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
    ccu_to_all_jrus_2 m_ccu_to_all_jrus_2;

};

#endif // CCU_TO_ALL_JRUS_2_H
