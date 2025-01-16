#ifndef SKA_CCU_TO_ALL_RIOMS_MVB1_H
#define SKA_CCU_TO_ALL_RIOMS_MVB1_H

#include <QObject>
#include <map>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QObject>
#include "utils.h"
#include <tsl/ordered_map.h>
#include <QDebug>

class Ska_Ccu_To_All_Rioms_Mvb1 : public QObject
{
    Q_OBJECT
public:
    explicit Ska_Ccu_To_All_Rioms_Mvb1(QObject *parent = nullptr);
    ~Ska_Ccu_To_All_Rioms_Mvb1();

    static constexpr int SKA_CCU_TO_ALL_RIOMS_OUTPUT_SIZE = sizeof(ska_ccu_to_all_rioms_mvb1);
    void set_data_struct(const QByteArray& output);

    ska_ccu_to_all_rioms_mvb1 get_data_struct() const {
        return m_ska_ccu_to_all_rioms_mvb1;
    }

    QTableWidget* getTableWidget(){
        return m_tableWidget;
    }

    std::vector<uint8_t> moduleData() const
    {
        std::vector<uint8_t> tempData(SKA_CCU_TO_ALL_RIOMS_OUTPUT_SIZE);
        std::memcpy(tempData.data(), &m_ska_ccu_to_all_rioms_mvb1, SKA_CCU_TO_ALL_RIOMS_OUTPUT_SIZE);
        qDebug() << " SKA CCU TO ALL RIOMS MVB1 TEMP DATA : " << tempData;
        return tempData;
    }

private:
    void init_table();
    void update_table();
    void update_map();
    void update_struct_with_map();
    void set_struct();

    tsl::ordered_map<QString, int> get_map()
    {
        return m_outputs_map;
    }

private:
    tsl::ordered_map<QString, int> m_outputs_map;
    QTableWidget *m_tableWidget;
    ska_ccu_to_all_rioms_mvb1 m_ska_ccu_to_all_rioms_mvb1;

};

#endif // SKA_CCU_TO_ALL_RIOMS_MVB1_H
