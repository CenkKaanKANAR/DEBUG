#ifndef SKA_CCU_GLOBAL_OUT_MVB1_H
#define SKA_CCU_GLOBAL_OUT_MVB1_H

#include <QObject>
#include <map>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QObject>
#include "utils.h"
#include <QDebug>
#include <tsl/ordered_map.h>

class Ska_Ccu_Global_Out_Mvb1 : public QObject
{
    Q_OBJECT
public:
    explicit Ska_Ccu_Global_Out_Mvb1(QObject *parent = nullptr);
    ~Ska_Ccu_Global_Out_Mvb1();

    static constexpr int SKA_CCU_GLOBAL_OUTPUT_SIZE = sizeof(ska_ccu_global_out_mvb1);

    void set_data_struct(const QByteArray& output);

    ska_ccu_global_out_mvb1 get_data_struct() const {
        return m_ska_ccu_global_out_mvb1;
    }

    QTableWidget* getTableWidget(){
        return m_tableWidget;
    }

    std::vector<uint8_t> moduleData() const
    {
        std::vector<uint8_t> tempData(SKA_CCU_GLOBAL_OUTPUT_SIZE);
        std::memcpy(tempData.data(), &m_ska_ccu_global_out_mvb1, SKA_CCU_GLOBAL_OUTPUT_SIZE);
        qDebug() << " SKA GLOBAL OUT MVB1 TEMP DATA : " << tempData;
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
    ska_ccu_global_out_mvb1 m_ska_ccu_global_out_mvb1;
    std::vector<uint16_t> m_port_id{0x101};
};

#endif // SKA_CCU_GLOBAL_OUT_MVB1_H
