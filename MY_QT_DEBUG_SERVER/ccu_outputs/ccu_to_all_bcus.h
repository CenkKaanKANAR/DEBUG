#ifndef CCU_TO_ALL_BCUS_H
#define CCU_TO_ALL_BCUS_H


#include <map>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QObject>
#include "utils.h"
class Ccu_To_All_Bcus : public QObject
{
    Q_OBJECT
public:
    explicit Ccu_To_All_Bcus(QObject *parent = nullptr);
    ~Ccu_To_All_Bcus();
    void set_data_struct(const QByteArray& output);

    ccu_to_all_bcus get_data_struct() const {
        return m_ccu_to_all_bcus;
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
    ccu_to_all_bcus m_ccu_to_all_bcus;

};

#endif // CCU_TO_ALL_BCUS_H
