#ifndef SKA_VH_RIOM_OUTPUTS_H
#define SKA_VH_RIOM_OUTPUTS_H

#include "ska_ccu_vh_riom_mvb1_d.h"
#include "ska_ccu_vh_riom_mvb2_dcu.h"

class Ska_Vh_Riom_Outputs : public QObject
{
    Q_OBJECT
public:
    explicit Ska_Vh_Riom_Outputs(QObject *parent = nullptr);
    ~Ska_Vh_Riom_Outputs();

    // Access MVB1 functions
    Ska_ccu_vh_riom_mvb1_d* mvb1() const { return m_mvb1_d; }

    // Access MVB2 functions
    Ska_Ccu_Vh_Riom_Mvb2_Dcu* mvb2() const { return m_mvb2_dcu; }

    // Combined module data function
    std::vector<uint8_t> moduleData(SKA_VEHICLE_NUM ska_x_num) const
    {
        // Get module data from both MVB1 and MVB2
        auto mvb1_data = m_mvb1_d->moduleData(ska_x_num);
        auto mvb2_data = m_mvb2_dcu->moduleData(ska_x_num);

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
    Ska_ccu_vh_riom_mvb1_d* m_mvb1_d;
    Ska_Ccu_Vh_Riom_Mvb2_Dcu* m_mvb2_dcu;
    std::vector<uint16_t> m_port_id{0x031, 0x091};
};


#endif // SKA_VH_RIOM_OUTPUTS_H
