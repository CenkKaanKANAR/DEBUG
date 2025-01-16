#ifndef SKA_CCU_TO_ALL_RIOMS_MVB2_H
#define SKA_CCU_TO_ALL_RIOMS_MVB2_H

#include <map>
#include "shm_data_gaziray.h"
#include <QTableWidget>
#include <QObject>
#include "utils.h"
#include <tsl/ordered_map.h>
#include <QDebug>

class Ska_Ccu_To_All_Rioms_Mvb2 : public QObject
{
    Q_OBJECT
public:
    explicit Ska_Ccu_To_All_Rioms_Mvb2(QObject *parent = nullptr);
    ~Ska_Ccu_To_All_Rioms_Mvb2();
    void set_data_struct(const QByteArray& output);

    static constexpr int SKA_CCU_TO_ALL_RIOMS_MVB2_SIZE = sizeof(ska_ccu_to_all_rioms_mvb2);

    ska_ccu_to_all_rioms_mvb2 get_data_struct() const {
        return m_ska_ccu_to_all_rioms_mvb2;
    }

    QTableWidget* getTableWidget(){
        return m_tableWidget;
    }

    std::vector<uint8_t> moduleData() const
    {
        std::vector<uint8_t> tempData(SKA_CCU_TO_ALL_RIOMS_MVB2_SIZE);
        std::memcpy(tempData.data(), &m_ska_ccu_to_all_rioms_mvb2, SKA_CCU_TO_ALL_RIOMS_MVB2_SIZE);
        qDebug() << " SKA CCU TO ALL RIOMS MVB1 TEMP DATA : " << tempData;
        return tempData;
    }
    uint16_t portId() const
    {
        return m_port_id.at(0);
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
    ska_ccu_to_all_rioms_mvb2 m_ska_ccu_to_all_rioms_mvb2;
    std::vector<uint16_t> m_port_id{0x112};
};

#endif // SKA_CCU_TO_ALL_RIOMS_MVB2 _H
