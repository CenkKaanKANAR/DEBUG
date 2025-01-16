#ifndef CCU_ALL_RIOMS_OUTPUT_H
#define CCU_ALL_RIOMS_OUTPUT_H


#include "ska_ccu_to_all_rioms_mvb1.h"
#include "ska_ccu_to_all_rioms_mvb2.h"

class Ccu_All_Rioms_Output : public QObject
{
    Q_OBJECT
public:
    explicit Ccu_All_Rioms_Output(QObject *parent = nullptr);
    ~Ccu_All_Rioms_Output();

    // Access MVB1 functions
    Ska_Ccu_To_All_Rioms_Mvb1* mvb1() const { return m_mvb1; }

    // Access MVB2 functions
    Ska_Ccu_To_All_Rioms_Mvb2* mvb2() const { return m_mvb2; }

    // Combined module data function
    std::vector<uint8_t> moduleData() const
    {
        // Get module data from both MVB1 and MVB2
        auto mvb1_data = m_mvb1->moduleData();
        auto mvb2_data = m_mvb2->moduleData();

        // Combine the two vectors
        std::vector<uint8_t> combined_data;
        combined_data.reserve(mvb1_data.size() + mvb2_data.size());
        combined_data.insert(combined_data.end(), mvb1_data.begin(), mvb1_data.end());
        combined_data.insert(combined_data.end(), mvb2_data.begin(), mvb2_data.end());

        // Return the combined data
        qDebug() << "Combined Module Data Size:" << combined_data.size();
        qDebug() << "Combined Module Data:" << QByteArray::fromRawData(reinterpret_cast<const char*>(combined_data.data()), combined_data.size());

        return combined_data;
    }
    uint16_t portId(SKA_VEHICLE_NUM ska_x_num) const
    {
        return m_port_id.at(static_cast<int>(ska_x_num));
    }
private:
    Ska_Ccu_To_All_Rioms_Mvb1* m_mvb1;
    Ska_Ccu_To_All_Rioms_Mvb2* m_mvb2;
    std::vector<uint16_t> m_port_id{0x111};
};

#endif // CCU_ALL_RIOMS_OUTPUT_H
