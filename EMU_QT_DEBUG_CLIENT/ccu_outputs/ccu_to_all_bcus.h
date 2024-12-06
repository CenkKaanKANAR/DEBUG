#ifndef CCU_TO_ALL_BCUS_H
#define CCU_TO_ALL_BCUS_H


#include <map>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QObject>
#include "utils.h"
#include <QDebug>
#include <tsl/ordered_map.h>

class Ccu_To_All_Bcus : public QObject
{
    Q_OBJECT
public:
    explicit Ccu_To_All_Bcus(QObject *parent = nullptr);
    ~Ccu_To_All_Bcus();
    void set_data_struct(const QByteArray& output);
    static constexpr int CCU_TO_ALL_BCUS_SIZE = sizeof(ccu_to_all_bcus);

    ccu_to_all_bcus get_data_struct() const {
        return m_ccu_to_all_bcus;
    }

    QTableWidget* getTableWidget(){
        return m_tableWidget;
    }

    std::vector<uint8_t> moduleData() const
    {
        std::vector<uint8_t> tempData(CCU_TO_ALL_BCUS_SIZE);
        std::memcpy(tempData.data(), &m_ccu_to_all_bcus, CCU_TO_ALL_BCUS_SIZE);
        qDebug() << "CCU TO ALL BCUS TEMP DATA : " << tempData;
        return tempData;
    }

    uint16_t portId() const
    {
        return m_port_id.at(0);
    }

    void update_table();
    void update_map();
    void update_struct_with_map();
    void set_struct();

private:
    void init_table();
    //void update_table();
    //void update_map();

    tsl::ordered_map<QString, int> get_map()
    {
        return m_outputs_map;
    }

private:
    tsl::ordered_map<QString, int> m_outputs_map;
    QTableWidget *m_tableWidget;
    ccu_to_all_bcus m_ccu_to_all_bcus;
    std::vector<uint16_t> m_port_id{0x161};

};

#endif // CCU_TO_ALL_BCUS_H
