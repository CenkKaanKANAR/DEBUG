#include "ska_papis.h"
#include "utils.h"

SKA_PAPIS::SKA_PAPIS(QObject *parent)
    : QObject{parent}
{
    // Reset Struct values
    memset(&m_ska_x_papis, 0, sizeof(m_ska_x_papis));

    // Init SKA1 Table Contents
    init_ska_x_mvb10_table(SKA_VEHICLE_NUM::SKA1);
    init_ska_x_mvb11_table(SKA_VEHICLE_NUM::SKA1);
    init_ska_x_mvb12_table(SKA_VEHICLE_NUM::SKA1);

    // Init SKA2 Table Contents
    init_ska_x_mvb10_table(SKA_VEHICLE_NUM::SKA2);
    init_ska_x_mvb11_table(SKA_VEHICLE_NUM::SKA2);
    init_ska_x_mvb12_table(SKA_VEHICLE_NUM::SKA2);

    make_signal_slot_connection();;
}

SKA_PAPIS::~SKA_PAPIS()
{

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            delete m_tableWidget[i][j];
            m_tableWidget[i][j] = nullptr; // Güvenlik için nullptr atayın
        }
    }

}

void SKA_PAPIS::make_signal_slot_connection()
{

    // SKA1 MVB1 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][MVB1], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1, MVB1);
    });

    //SKA1 MVB2 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][MVB2], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1, MVB2);
    });

    //SKA1 MVB3 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][MVB3], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1, MVB3);
    });


    // SKA2 MVB1 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][MVB1], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2, MVB1);
    });

    // SKA2 MVB2 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][MVB2], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2, MVB2);
    });

    //SKA2 MVB3 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][MVB3], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2, MVB3);
    });
}

void SKA_PAPIS::update_struct_with_map(SKA_VEHICLE_NUM ska_x_num, SKA_MVB_NUM mvb_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    // Define a lambda function to reduce redundancy
    auto setInputMap = [&](const QString& signal_name) {
        m_inputs_map[ska_num][mvb_num][signal_name] = utils::getTableWidgetValueByName(m_tableWidget[ska_num][mvb_num], signal_name, 1).toInt();
    };
    // update map with given tableWidget values
    for(const auto& map : m_inputs_map[ska_num][mvb_num])
    {
        setInputMap(map.first);
    }
    // set struct parameters with given updated map parameters

    set_struct_mvb10(ska_x_num);
    set_struct_mvb11(ska_x_num);
    set_struct_mvb12(ska_x_num);
}

void SKA_PAPIS::update_mvb10_map(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);

    m_inputs_map[ska_num][MVB1].at("PapisINF_Piscu_SKA1_M")             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PapisINF_Piscu_SKA1_M;
    m_inputs_map[ska_num][MVB1].at("PapisINF_Piscu_SKA2_M")             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PapisINF_Piscu_SKA2_M;
    m_inputs_map[ska_num][MVB1].at("bit2")                              = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit2;
    m_inputs_map[ska_num][MVB1].at("bit3")                              = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit3;
    m_inputs_map[ska_num][MVB1].at("PapisINF_nvr_SKA1_M")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PapisINF_nvr_SKA1_M;
    m_inputs_map[ska_num][MVB1].at("PapisINF_nvr_SKA2_M")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PapisINF_nvr_SKA2_M;
    m_inputs_map[ska_num][MVB1].at("bit6")                              = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit6;
    m_inputs_map[ska_num][MVB1].at("bit7")                              = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit7;
    m_inputs_map[ska_num][MVB1].at("Piscu_SKA1_Network_Failure")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Piscu_SKA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("Piscu_SKA1_Power_Failure")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Piscu_SKA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("Piscu_SKA1_Version_Error")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Piscu_SKA1_Version_Error;
    m_inputs_map[ska_num][MVB1].at("Piscu_SKA1_OS_Error")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Piscu_SKA1_OS_Error;
    m_inputs_map[ska_num][MVB1].at("bit12")                             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit12;
    m_inputs_map[ska_num][MVB1].at("bit13")                             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit13;
    m_inputs_map[ska_num][MVB1].at("bit14")                             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit14;
    m_inputs_map[ska_num][MVB1].at("bit15")                             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit15;
    m_inputs_map[ska_num][MVB1].at("Piscu_SKA2_Network_Failure")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Piscu_SKA2_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("Piscu_SKA2_Power_Failure")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Piscu_SKA2_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("Piscu_SKA2_Version_Error")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Piscu_SKA2_Version_Error;
    m_inputs_map[ska_num][MVB1].at("Piscu_SKA2_OS_Error")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Piscu_SKA2_OS_Error;
    m_inputs_map[ska_num][MVB1].at("bit20")                             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit20;
    m_inputs_map[ska_num][MVB1].at("bit21")                             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit21;
    m_inputs_map[ska_num][MVB1].at("bit22")                             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit22;
    m_inputs_map[ska_num][MVB1].at("bit23")                             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit23;
    m_inputs_map[ska_num][MVB1].at("Pis_01_02_SKA1_Error")              = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_01_02_SKA1_Error;
    m_inputs_map[ska_num][MVB1].at("Pis_03_04_SKA1_Error")              = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_03_04_SKA1_Error;
    m_inputs_map[ska_num][MVB1].at("Pis_05_06_SKA1_Error")              = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_05_06_SKA1_Error;
    m_inputs_map[ska_num][MVB1].at("Pis_07_08_SKA1_Error")              = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_07_08_SKA1_Error;
    m_inputs_map[ska_num][MVB1].at("Pis_01_02_OA1_Error")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_01_02_OA1_Error;
    m_inputs_map[ska_num][MVB1].at("Pis_03_04_OA1_Error")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_03_04_OA1_Error;
    m_inputs_map[ska_num][MVB1].at("Pis_05_06_OA1_Error")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_05_06_OA1_Error;
    m_inputs_map[ska_num][MVB1].at("Pis_07_08_OA1_Error")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_07_08_OA1_Error;
    m_inputs_map[ska_num][MVB1].at("Pis_01_02_OA2_Error")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_01_02_OA2_Error;
    m_inputs_map[ska_num][MVB1].at("Pis_03_04_OA2_Error")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_03_04_OA2_Error;
    m_inputs_map[ska_num][MVB1].at("Pis_05_06_OA2_Error")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_05_06_OA2_Error;
    m_inputs_map[ska_num][MVB1].at("Pis_07_08_OA2_Error")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_07_08_OA2_Error;
    m_inputs_map[ska_num][MVB1].at("Pis_01_02_SKA2_Error")              = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_01_02_SKA2_Error;
    m_inputs_map[ska_num][MVB1].at("Pis_03_04_SKA2_Error")              = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_03_04_SKA2_Error;
    m_inputs_map[ska_num][MVB1].at("Pis_05_06_SKA2_Error")              = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_05_06_SKA2_Error;
    m_inputs_map[ska_num][MVB1].at("Pis_07_08_SKA2_Error")              = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_07_08_SKA2_Error;
    m_inputs_map[ska_num][MVB1].at("FrontLed1_SKA1_Process_Error")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.FrontLed1_SKA1_Process_Error;
    m_inputs_map[ska_num][MVB1].at("FrontLed1_SKA1_Version_Error")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.FrontLed1_SKA1_Version_Error;
    m_inputs_map[ska_num][MVB1].at("FrontLed1_SKA1_Device_Busy")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.FrontLed1_SKA1_Device_Busy;
    m_inputs_map[ska_num][MVB1].at("FrontLed1_SKA1_System_Error")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.FrontLed1_SKA1_System_Error;
    m_inputs_map[ska_num][MVB1].at("bit44")                             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit44;
    m_inputs_map[ska_num][MVB1].at("OutLed1_SKA1_Process_Error")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_SKA1_Process_Error;
    m_inputs_map[ska_num][MVB1].at("OutLed1_SKA1_Version_Error")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_SKA1_Version_Error;
    m_inputs_map[ska_num][MVB1].at("OutLed1_SKA1_Device_Busy")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_SKA1_Device_Busy;
    m_inputs_map[ska_num][MVB1].at("OutLed1_SKA1_System_Error")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_SKA1_System_Error;
    m_inputs_map[ska_num][MVB1].at("bit49")                             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit49;
    m_inputs_map[ska_num][MVB1].at("OutLed2_SKA1_Process_Error")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_SKA1_Process_Error;
    m_inputs_map[ska_num][MVB1].at("OutLed2_SKA1_Version_Error")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_SKA1_Version_Error;
    m_inputs_map[ska_num][MVB1].at("OutLed2_SKA1_Device_Busy")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_SKA1_Device_Busy;
    m_inputs_map[ska_num][MVB1].at("OutLed2_SKA1_System_Error")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_SKA1_System_Error;
    m_inputs_map[ska_num][MVB1].at("bit54")                             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit54;
    // New signal mappings added
    //dönüm1

    m_inputs_map[ska_num][MVB1].at("OutLed1_OA1_Process_Error")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_OA1_Process_Error;
    m_inputs_map[ska_num][MVB1].at("OutLed1_OA1_Version_Error")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_OA1_Version_Error;
    m_inputs_map[ska_num][MVB1].at("OutLed1_OA1_Device_Busy")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_OA1_Device_Busy;
    m_inputs_map[ska_num][MVB1].at("OutLed1_OA1_System_Error")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_OA1_System_Error;
    m_inputs_map[ska_num][MVB1].at("bit59")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit59;
    m_inputs_map[ska_num][MVB1].at("OutLed2_OA1_Process_Error")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_OA1_Process_Error;
    m_inputs_map[ska_num][MVB1].at("OutLed2_OA1_Version_Error")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_OA1_Version_Error;
    m_inputs_map[ska_num][MVB1].at("OutLed2_OA1_Device_Busy")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_OA1_Device_Busy;
    m_inputs_map[ska_num][MVB1].at("OutLed2_OA1_System_Error")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_OA1_System_Error;
    m_inputs_map[ska_num][MVB1].at("bit64")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit64;
    m_inputs_map[ska_num][MVB1].at("OutLed1_OA2_Process_Error")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_OA2_Process_Error;
    m_inputs_map[ska_num][MVB1].at("OutLed1_OA2_Version_Error")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_OA2_Version_Error;
    m_inputs_map[ska_num][MVB1].at("OutLed1_OA2_Device_Busy")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_OA2_Device_Busy;
    m_inputs_map[ska_num][MVB1].at("OutLed1_OA2_System_Error")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_OA2_System_Error;
    m_inputs_map[ska_num][MVB1].at("bit69")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit69;
    m_inputs_map[ska_num][MVB1].at("OutLed2_OA2_Process_Error")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_OA2_Process_Error;
    m_inputs_map[ska_num][MVB1].at("OutLed2_OA2_Version_Error")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_OA2_Version_Error;
    m_inputs_map[ska_num][MVB1].at("OutLed2_OA2_Device_Busy")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_OA2_Device_Busy;
    m_inputs_map[ska_num][MVB1].at("OutLed2_OA2_System_Error")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_OA2_System_Error;
    m_inputs_map[ska_num][MVB1].at("bit74")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit74;
    m_inputs_map[ska_num][MVB1].at("FrontLed1_SKA2_Process_Error")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.FrontLed1_SKA2_Process_Error;
    m_inputs_map[ska_num][MVB1].at("FrontLed1_SKA2_Version_Error")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.FrontLed1_SKA2_Version_Error;
    m_inputs_map[ska_num][MVB1].at("FrontLed1_SKA2_Device_Busy")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.FrontLed1_SKA2_Device_Busy;
    m_inputs_map[ska_num][MVB1].at("FrontLed1_SKA2_System_Error")     = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.FrontLed1_SKA2_System_Error;
    m_inputs_map[ska_num][MVB1].at("bit79")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit79;
    m_inputs_map[ska_num][MVB1].at("OutLed1_SKA2_Process_Error")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_SKA2_Process_Error;
    m_inputs_map[ska_num][MVB1].at("OutLed1_SKA2_Version_Error")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_SKA2_Version_Error;
    m_inputs_map[ska_num][MVB1].at("OutLed1_SKA2_Device_Busy")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_SKA2_Device_Busy;
    m_inputs_map[ska_num][MVB1].at("OutLed1_SKA2_System_Error")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_SKA2_System_Error;
    m_inputs_map[ska_num][MVB1].at("bit84")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit84;
    m_inputs_map[ska_num][MVB1].at("OutLed2_SKA2_Process_Error")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_SKA2_Process_Error;
    m_inputs_map[ska_num][MVB1].at("OutLed2_SKA2_Version_Error")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_SKA2_Version_Error;
    m_inputs_map[ska_num][MVB1].at("OutLed2_SKA2_Device_Busy")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_SKA2_Device_Busy;
    m_inputs_map[ska_num][MVB1].at("OutLed2_SKA2_System_Error")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_SKA2_System_Error;
    m_inputs_map[ska_num][MVB1].at("bit89")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit89;

    //dönüm2


    m_inputs_map[ska_num][MVB1].at("CCTV_HMI_SKA1_Network_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.CCTV_HMI_SKA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("CCTV_HMI_SKA1_Power_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.CCTV_HMI_SKA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("CCTV_HMI_SKA1_Server_Error")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.CCTV_HMI_SKA1_Server_Error;
    m_inputs_map[ska_num][MVB1].at("bit93")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit93;
    m_inputs_map[ska_num][MVB1].at("CCTV_HMI_SKA2_Network_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.CCTV_HMI_SKA2_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("CCTV_HMI_SKA2_Power_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.CCTV_HMI_SKA2_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("CCTV_HMI_SKA2_Server_Error")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.CCTV_HMI_SKA2_Server_Error;
    m_inputs_map[ska_num][MVB1].at("bit97")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit97;
    m_inputs_map[ska_num][MVB1].at("F_Cam1_SKA1_Network_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.F_Cam1_SKA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("F_Cam1_SKA1_Power_Failure")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.F_Cam1_SKA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit100")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit100;
    m_inputs_map[ska_num][MVB1].at("C_Cam1_SKA1_Network_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.C_Cam1_SKA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("C_Cam1_SKA1_Power_Failure")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.C_Cam1_SKA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit103")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit103;
    m_inputs_map[ska_num][MVB1].at("PS_Cam1_SKA1_Network_Failure")     = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam1_SKA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("PS_Cam1_SKA1_Power_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam1_SKA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit106")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit106;
    m_inputs_map[ska_num][MVB1].at("PS_Cam2_SKA1_Network_Failure")     = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam2_SKA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("PS_Cam2_SKA1_Power_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam2_SKA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit109")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit109;
    m_inputs_map[ska_num][MVB1].at("PS_Cam3_SKA1_Network_Failure")     = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam3_SKA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("PS_Cam3_SKA1_Power_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam3_SKA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit112")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit112;
    m_inputs_map[ska_num][MVB1].at("PS_Cam4_SKA1_Network_Failure")     = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam4_SKA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("PS_Cam4_SKA1_Power_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam4_SKA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit115")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit115;


    m_inputs_map[ska_num][MVB1].at("RL_Cam4_SKA1_Network_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.RL_Cam4_SKA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("RL_Cam4_SKA1_Power_Failure")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.RL_Cam4_SKA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit118")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit118;
    m_inputs_map[ska_num][MVB1].at("RR_Cam1_SKA1_Network_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.RR_Cam1_SKA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("RR_Cam1_SKA1_Power_Failure")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.RR_Cam1_SKA1_Power_Failure; //byte 15
    m_inputs_map[ska_num][MVB1].at("bit121")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit121;
    m_inputs_map[ska_num][MVB1].at("PS_Cam1_OA1_Network_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam1_OA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("PS_Cam1_OA1_Power_Failure")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam1_OA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit124")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit124;
    m_inputs_map[ska_num][MVB1].at("PS_Cam2_OA1_Network_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam2_OA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("PS_Cam2_OA1_Power_Failure")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam2_OA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit127")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit127;
    m_inputs_map[ska_num][MVB1].at("PS_Cam3_OA1_Network_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam3_OA1_Network_Failure; //byte 16
    m_inputs_map[ska_num][MVB1].at("PS_Cam3_OA1_Power_Failure")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam3_OA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit130")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit130;
    m_inputs_map[ska_num][MVB1].at("PS_Cam4_OA1_Network_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam4_OA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("PS_Cam4_OA1_Power_Failure")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam4_OA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit133")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit133;
    m_inputs_map[ska_num][MVB1].at("PN_Cam1_OA1_Network_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PN_Cam1_OA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("PN_Cam1_OA1_Power_Failure")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PN_Cam1_OA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit136")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit136; //byte 17
    m_inputs_map[ska_num][MVB1].at("PN_Cam1_OA2_Network_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PN_Cam1_OA2_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("PN_Cam1_OA2_Power_Failure")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PN_Cam1_OA2_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit139")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit139;
    m_inputs_map[ska_num][MVB1].at("PS_Cam1_OA2_Network_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam1_OA2_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("PS_Cam1_OA2_Power_Failure")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam1_OA2_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit142")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit142;
    m_inputs_map[ska_num][MVB1].at("PS_Cam2_OA2_Network_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam2_OA2_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("PS_Cam2_OA2_Power_Failure")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam2_OA2_Power_Failure; //byte 18
    m_inputs_map[ska_num][MVB1].at("bit145")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit145;
    m_inputs_map[ska_num][MVB1].at("PS_Cam3_OA2_Network_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam3_OA2_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("PS_Cam3_OA2_Power_Failure")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam3_OA2_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit148")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit148;
    m_inputs_map[ska_num][MVB1].at("PS_Cam4_OA2_Network_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam4_OA2_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("PS_Cam4_OA2_Power_Failure")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam4_OA2_Power_Failure;

    // Additional mappings
    m_inputs_map[ska_num][MVB1].at("bit151")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit151; //byte 19
    m_inputs_map[ska_num][MVB1].at("F_Cam1_SKA2_Network_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.F_Cam1_SKA2_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("F_Cam1_SKA2_Power_Failure")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.F_Cam1_SKA2_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit154")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit154;
    m_inputs_map[ska_num][MVB1].at("C_Cam1_SKA2_Network_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.C_Cam1_SKA2_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("C_Cam1_SKA2_Power_Failure")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.C_Cam1_SKA2_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit157")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit157;
    m_inputs_map[ska_num][MVB1].at("PS_Cam1_SKA2_Network_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam1_SKA2_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("PS_Cam1_SKA2_Power_Failure")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam1_SKA2_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit160")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit160; //byte 20
    m_inputs_map[ska_num][MVB1].at("PS_Cam2_SKA2_Network_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam2_SKA2_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("PS_Cam2_SKA2_Power_Failure")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam2_SKA2_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit163")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit163;
    m_inputs_map[ska_num][MVB1].at("PS_Cam3_SKA2_Network_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam3_SKA2_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("PS_Cam3_SKA2_Power_Failure")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam3_SKA2_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit166")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit166;
    m_inputs_map[ska_num][MVB1].at("PS_Cam4_SKA2_Network_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam4_SKA2_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("PS_Cam4_SKA2_Power_Failure")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam4_SKA2_Power_Failure; //byte 21
    m_inputs_map[ska_num][MVB1].at("bit169")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit169;
    m_inputs_map[ska_num][MVB1].at("RL_Cam1_SKA2_Network_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.RL_Cam1_SKA2_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("RL_Cam1_SKA2_Power_Failure")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.RL_Cam1_SKA2_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit172")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit172;
    m_inputs_map[ska_num][MVB1].at("RR_Cam2_SKA2_Network_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.RR_Cam2_SKA2_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("RR_Cam2_SKA2_Power_Failure")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.RR_Cam2_SKA2_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("bit175")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit175;
    m_inputs_map[ska_num][MVB1].at("Intercom1_SKA1_Network_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom1_SKA1_Network_Failure; //byte 22
    m_inputs_map[ska_num][MVB1].at("Intercom1_SKA1_Power_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom1_SKA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom1_SKA1_Timeout")            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom1_SKA1_Timeout;
    m_inputs_map[ska_num][MVB1].at("Intercom1_SKA1_Not_Found")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom1_SKA1_Not_Found;
    m_inputs_map[ska_num][MVB1].at("bit180")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit180;
    m_inputs_map[ska_num][MVB1].at("Intercom2_SKA1_Network_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom2_SKA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom2_SKA1_Power_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom2_SKA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom2_SKA1_Timeout")            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom2_SKA1_Timeout;
    m_inputs_map[ska_num][MVB1].at("Intercom2_SKA1_Not_Found")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom2_SKA1_Not_Found; //byte 23
    m_inputs_map[ska_num][MVB1].at("bit185")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit185;
    m_inputs_map[ska_num][MVB1].at("Intercom3_SKA1_Network_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom3_SKA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom3_SKA1_Power_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom3_SKA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom3_SKA1_Timeout")            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom3_SKA1_Timeout;
    m_inputs_map[ska_num][MVB1].at("Intercom3_SKA1_Not_Found")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom3_SKA1_Not_Found;
    m_inputs_map[ska_num][MVB1].at("bit190")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit190;
    m_inputs_map[ska_num][MVB1].at("bit191")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit191;
    m_inputs_map[ska_num][MVB1].at("Intercom4_SKA1_Network_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom4_SKA1_Network_Failure; //byte 24
    m_inputs_map[ska_num][MVB1].at("Intercom4_SKA1_Power_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom4_SKA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom4_SKA1_Timeout")            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom4_SKA1_Timeout;
    m_inputs_map[ska_num][MVB1].at("Intercom4_SKA1_Not_Found")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom4_SKA1_Not_Found;
    m_inputs_map[ska_num][MVB1].at("bit196")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit196;



    // Additional mappings for Intercom 5 to 9
    m_inputs_map[ska_num][MVB1].at("Intercom5_SKA1_Network_Failure")     = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom5_SKA1_Network_Failure; //byte 25
    m_inputs_map[ska_num][MVB1].at("Intercom5_SKA1_Power_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom5_SKA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom5_SKA1_Timeout")             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom5_SKA1_Timeout;
    m_inputs_map[ska_num][MVB1].at("Intercom5_SKA1_Not_Found")           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom5_SKA1_Not_Found;
    m_inputs_map[ska_num][MVB1].at("bit201")                             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit201;
    m_inputs_map[ska_num][MVB1].at("Intercom6_SKA1_Network_Failure")     = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom6_SKA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom6_SKA1_Power_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom6_SKA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom6_SKA1_Timeout")             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom6_SKA1_Timeout;
    m_inputs_map[ska_num][MVB1].at("Intercom6_SKA1_Not_Found")           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom6_SKA1_Not_Found;
    m_inputs_map[ska_num][MVB1].at("bit206")                             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit206;
    m_inputs_map[ska_num][MVB1].at("Intercom7_SKA1_Network_Failure")     = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom7_SKA1_Network_Failure; //byte 26
    m_inputs_map[ska_num][MVB1].at("Intercom7_SKA1_Power_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom7_SKA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom7_SKA1_Timeout")             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom7_SKA1_Timeout;
    m_inputs_map[ska_num][MVB1].at("Intercom7_SKA1_Not_Found")           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom7_SKA1_Not_Found;
    m_inputs_map[ska_num][MVB1].at("bit211")                             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit211;
    m_inputs_map[ska_num][MVB1].at("Intercom8_SKA1_Network_Failure")     = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom8_SKA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom8_SKA1_Power_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom8_SKA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom8_SKA1_Timeout")             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom8_SKA1_Timeout;
    m_inputs_map[ska_num][MVB1].at("Intercom8_SKA1_Not_Found")           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom8_SKA1_Not_Found; //byte 27
    m_inputs_map[ska_num][MVB1].at("bit216")                             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit216;
    m_inputs_map[ska_num][MVB1].at("Intercom9_SKA1_Network_Failure")     = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom9_SKA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom9_SKA1_Power_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom9_SKA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom9_SKA1_Timeout")             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom9_SKA1_Timeout;
    m_inputs_map[ska_num][MVB1].at("Intercom9_SKA1_Not_Found")           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom9_SKA1_Not_Found;
    m_inputs_map[ska_num][MVB1].at("bit221")                             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit221; //byte 28
    // Additional mappings for OA1 Intercoms 1 to 3
    m_inputs_map[ska_num][MVB1].at("Intercom1_OA1_Network_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom1_OA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom1_OA1_Power_Failure")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom1_OA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom1_OA1_Timeout")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom1_OA1_Timeout; //byte 28
    m_inputs_map[ska_num][MVB1].at("Intercom1_OA1_Not_Found")             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom1_OA1_Not_Found;
    m_inputs_map[ska_num][MVB1].at("bit226")                              = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit226;
    m_inputs_map[ska_num][MVB1].at("Intercom2_OA1_Network_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom2_OA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom2_OA1_Power_Failure")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom2_OA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom2_OA1_Timeout")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom2_OA1_Timeout;
    m_inputs_map[ska_num][MVB1].at("Intercom2_OA1_Not_Found")             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom2_OA1_Not_Found;
    m_inputs_map[ska_num][MVB1].at("bit231")                              = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit231;
    m_inputs_map[ska_num][MVB1].at("Intercom3_OA1_Network_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom3_OA1_Network_Failure; //byte 29
    m_inputs_map[ska_num][MVB1].at("Intercom3_OA1_Power_Failure")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom3_OA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom3_OA1_Timeout")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom3_OA1_Timeout;
    m_inputs_map[ska_num][MVB1].at("Intercom3_OA1_Not_Found")             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom3_OA1_Not_Found;
    m_inputs_map[ska_num][MVB1].at("bit236")                             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit236;

    // Additional mappings for Intercom4, Intercom5, Intercom6, and Intercom7
    m_inputs_map[ska_num][MVB1].at("Intercom4_OA1_Network_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom4_OA1_Network_Failure; //byte 30
    m_inputs_map[ska_num][MVB1].at("Intercom4_OA1_Power_Failure")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom4_OA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom4_OA1_Timeout")              = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom4_OA1_Timeout;
    m_inputs_map[ska_num][MVB1].at("Intercom4_OA1_Not_Found")            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom4_OA1_Not_Found;
    m_inputs_map[ska_num][MVB1].at("bit241")                             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit241;
    m_inputs_map[ska_num][MVB1].at("Intercom5_OA1_Network_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom5_OA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom5_OA1_Power_Failure")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom5_OA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom5_OA1_Timeout")              = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom5_OA1_Timeout;
    m_inputs_map[ska_num][MVB1].at("Intercom5_OA1_Not_Found")            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom5_OA1_Not_Found;
    m_inputs_map[ska_num][MVB1].at("bit246")                             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit246;
    m_inputs_map[ska_num][MVB1].at("Intercom6_OA1_Network_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom6_OA1_Network_Failure; //byte 31
    m_inputs_map[ska_num][MVB1].at("Intercom6_OA1_Power_Failure")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom6_OA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom6_OA1_Timeout")              = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom6_OA1_Timeout;
    m_inputs_map[ska_num][MVB1].at("Intercom6_OA1_Not_Found")            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom6_OA1_Not_Found;
    m_inputs_map[ska_num][MVB1].at("bit251")                             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit251;
    m_inputs_map[ska_num][MVB1].at("Intercom7_OA1_Network_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom7_OA1_Network_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom7_OA1_Power_Failure")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom7_OA1_Power_Failure;
    m_inputs_map[ska_num][MVB1].at("Intercom7_OA1_Timeout")              = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom7_OA1_Timeout;
    m_inputs_map[ska_num][MVB1].at("Intercom7_OA1_Not_Found")            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom7_OA1_Not_Found;




}


void SKA_PAPIS::update_mvb11_map(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    // Assigning values to m_inputs_map for MVB2 from ska_vh_riom_ccu_mvb11_papis2
    m_inputs_map[ska_num][MVB2].at("bit0")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit0; // byte 0
    m_inputs_map[ska_num][MVB2].at("Intercom8_OA1_Network_Failure")  = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_OA1_Network_Failure;
    m_inputs_map[ska_num][MVB2].at("Intercom8_OA1_Power_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_OA1_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Intercom8_OA1_Timeout")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_OA1_Timeout;
    m_inputs_map[ska_num][MVB2].at("Intercom8_OA1_Not_Found")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_OA1_Not_Found;
    m_inputs_map[ska_num][MVB2].at("bit5")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit5;
    m_inputs_map[ska_num][MVB2].at("Intercom1_OA2_Network_Failure")  = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom1_OA2_Network_Failure; // byte 1
    m_inputs_map[ska_num][MVB2].at("Intercom1_OA2_Power_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom1_OA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Intercom1_OA2_Timeout")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom1_OA2_Timeout;
    m_inputs_map[ska_num][MVB2].at("Intercom1_OA2_Not_Found")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom1_OA2_Not_Found;
    m_inputs_map[ska_num][MVB2].at("bit10")                          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit10;
    m_inputs_map[ska_num][MVB2].at("Intercom2_OA2_Network_Failure")  = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom2_OA2_Network_Failure; // byte 2
    m_inputs_map[ska_num][MVB2].at("Intercom2_OA2_Power_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom2_OA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Intercom2_OA2_Timeout")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom2_OA2_Timeout;
    m_inputs_map[ska_num][MVB2].at("Intercom2_OA2_Not_Found")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom2_OA2_Not_Found;
    m_inputs_map[ska_num][MVB2].at("bit15")                          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit15;
    m_inputs_map[ska_num][MVB2].at("Intercom3_OA2_Network_Failure")  = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom3_OA2_Network_Failure; // byte 3
    m_inputs_map[ska_num][MVB2].at("Intercom3_OA2_Power_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom3_OA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Intercom3_OA2_Timeout")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom3_OA2_Timeout;
    m_inputs_map[ska_num][MVB2].at("Intercom3_OA2_Not_Found")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom3_OA2_Not_Found;
    m_inputs_map[ska_num][MVB2].at("bit20")                          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit20;
    m_inputs_map[ska_num][MVB2].at("Intercom4_OA2_Network_Failure")  = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom4_OA2_Network_Failure; // byte 4
    m_inputs_map[ska_num][MVB2].at("Intercom4_OA2_Power_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom4_OA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Intercom4_OA2_Timeout")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom4_OA2_Timeout;
    m_inputs_map[ska_num][MVB2].at("Intercom4_OA2_Not_Found")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom4_OA2_Not_Found;
    m_inputs_map[ska_num][MVB2].at("bit25")                          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit25;
    m_inputs_map[ska_num][MVB2].at("Intercom5_OA2_Network_Failure")  = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom5_OA2_Network_Failure;
    m_inputs_map[ska_num][MVB2].at("Intercom5_OA2_Power_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom5_OA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Intercom5_OA2_Timeout")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom5_OA2_Timeout;
    m_inputs_map[ska_num][MVB2].at("Intercom5_OA2_Not_Found")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom5_OA2_Not_Found;
    m_inputs_map[ska_num][MVB2].at("bit30")                          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit30;
    m_inputs_map[ska_num][MVB2].at("Intercom6_OA2_Network_Failure")  = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom6_OA2_Network_Failure;
    m_inputs_map[ska_num][MVB2].at("Intercom6_OA2_Power_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom6_OA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Intercom6_OA2_Timeout")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom6_OA2_Timeout;
    m_inputs_map[ska_num][MVB2].at("Intercom6_OA2_Not_Found")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom6_OA2_Not_Found;
    m_inputs_map[ska_num][MVB2].at("bit35")                          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit35;
    // Assigning values to m_inputs_map for MVB2 from ska_vh_riom_ccu_mvb11_papis2
    m_inputs_map[ska_num][MVB2].at("Intercom7_OA2_Network_Failure")   = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom7_OA2_Network_Failure; // byte 5
    m_inputs_map[ska_num][MVB2].at("Intercom7_OA2_Power_Failure")     = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom7_OA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Intercom7_OA2_Timeout")           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom7_OA2_Timeout;
    m_inputs_map[ska_num][MVB2].at("Intercom7_OA2_Not_Found")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom7_OA2_Not_Found;
    m_inputs_map[ska_num][MVB2].at("bit40")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit40;



    m_inputs_map[ska_num][MVB2].at("Intercom8_OA2_Network_Failure")   = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_OA2_Network_Failure; // byte 6
    m_inputs_map[ska_num][MVB2].at("Intercom8_OA2_Power_Failure")     = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_OA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Intercom8_OA2_Timeout")           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_OA2_Timeout;
    m_inputs_map[ska_num][MVB2].at("Intercom8_OA2_Not_Found")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_OA2_Not_Found;
    m_inputs_map[ska_num][MVB2].at("bit45")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit45;
    m_inputs_map[ska_num][MVB2].at("Intercom1_SKA2_Network_Failure")  = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom1_SKA2_Network_Failure; // byte 7
    m_inputs_map[ska_num][MVB2].at("Intercom1_SKA2_Power_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom1_SKA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Intercom1_SKA2_Timeout")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom1_SKA2_Timeout;
    m_inputs_map[ska_num][MVB2].at("Intercom1_SKA2_Not_Found")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom1_SKA2_Not_Found;
    m_inputs_map[ska_num][MVB2].at("bit50")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit50;
    m_inputs_map[ska_num][MVB2].at("Intercom2_SKA2_Network_Failure")  = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom2_SKA2_Network_Failure; // byte 8
    m_inputs_map[ska_num][MVB2].at("Intercom2_SKA2_Power_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom2_SKA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Intercom2_SKA2_Timeout")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom2_SKA2_Timeout;
    m_inputs_map[ska_num][MVB2].at("Intercom2_SKA2_Not_Found")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom2_SKA2_Not_Found;
    m_inputs_map[ska_num][MVB2].at("bit55")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit55;
    m_inputs_map[ska_num][MVB2].at("Intercom3_SKA2_Network_Failure")  = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom3_SKA2_Network_Failure; // byte 9
    m_inputs_map[ska_num][MVB2].at("Intercom3_SKA2_Power_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom3_SKA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Intercom3_SKA2_Timeout")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom3_SKA2_Timeout;
    m_inputs_map[ska_num][MVB2].at("Intercom3_SKA2_Not_Found")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom3_SKA2_Not_Found;
    m_inputs_map[ska_num][MVB2].at("bit60")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit60;
    m_inputs_map[ska_num][MVB2].at("bit61")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit61;
    m_inputs_map[ska_num][MVB2].at("bit62")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit62;
    m_inputs_map[ska_num][MVB2].at("bit63")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit63;
    m_inputs_map[ska_num][MVB2].at("Intercom4_SKA2_Network_Failure")  = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom4_SKA2_Network_Failure; // byte 10
    m_inputs_map[ska_num][MVB2].at("Intercom4_SKA2_Power_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom4_SKA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Intercom4_SKA2_Timeout")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom4_SKA2_Timeout;
    m_inputs_map[ska_num][MVB2].at("Intercom4_SKA2_Not_Found")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom4_SKA2_Not_Found;
    m_inputs_map[ska_num][MVB2].at("bit68")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit68;
    // Assigning values to m_inputs_map for MVB2 from ska_vh_riom_ccu_mvb11_papis2
    m_inputs_map[ska_num][MVB2].at("Intercom5_SKA2_Network_Failure")  = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom5_SKA2_Network_Failure; // byte 9
    m_inputs_map[ska_num][MVB2].at("Intercom5_SKA2_Power_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom5_SKA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Intercom5_SKA2_Timeout")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom5_SKA2_Timeout;
    m_inputs_map[ska_num][MVB2].at("Intercom5_SKA2_Not_Found")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom5_SKA2_Not_Found;
    m_inputs_map[ska_num][MVB2].at("bit73")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit73;
    m_inputs_map[ska_num][MVB2].at("Intercom6_SKA2_Network_Failure")  = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom6_SKA2_Network_Failure; // byte 10
    m_inputs_map[ska_num][MVB2].at("Intercom6_SKA2_Power_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom6_SKA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Intercom6_SKA2_Timeout")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom6_SKA2_Timeout;
    m_inputs_map[ska_num][MVB2].at("Intercom6_SKA2_Not_Found")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom6_SKA2_Not_Found;
    m_inputs_map[ska_num][MVB2].at("bit78")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit78;
    m_inputs_map[ska_num][MVB2].at("Intercom7_SKA2_Network_Failure")  = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom7_SKA2_Network_Failure; // byte 11
    m_inputs_map[ska_num][MVB2].at("Intercom7_SKA2_Power_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom7_SKA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Intercom7_SKA2_Timeout")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom7_SKA2_Timeout;
    m_inputs_map[ska_num][MVB2].at("Intercom7_SKA2_Not_Found")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom7_SKA2_Not_Found;
    m_inputs_map[ska_num][MVB2].at("bit83")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit83;


    m_inputs_map[ska_num][MVB2].at("Intercom8_SKA2_Network_Failure")  = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_SKA2_Network_Failure; // byte 12
    m_inputs_map[ska_num][MVB2].at("Intercom8_SKA2_Power_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_SKA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Intercom8_SKA2_Timeout")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_SKA2_Timeout;
    m_inputs_map[ska_num][MVB2].at("Intercom8_SKA2_Not_Found")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_SKA2_Not_Found;
    m_inputs_map[ska_num][MVB2].at("bit88")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit88;
    m_inputs_map[ska_num][MVB2].at("Intercom9_SKA2_Network_Failure")  = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom9_SKA2_Network_Failure; // byte 13
    m_inputs_map[ska_num][MVB2].at("Intercom9_SKA2_Power_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom9_SKA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Intercom9_SKA2_Timeout")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom9_SKA2_Timeout;
    m_inputs_map[ska_num][MVB2].at("Intercom9_SKA2_Not_Found")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom9_SKA2_Not_Found;
    m_inputs_map[ska_num][MVB2].at("bit93")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit93;
    m_inputs_map[ska_num][MVB2].at("SIntercom_1_SKA1")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_1_SKA1; // byte 14
    m_inputs_map[ska_num][MVB2].at("SIntercom_2_SKA1")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_2_SKA1;
    m_inputs_map[ska_num][MVB2].at("SIntercom_3_SKA1")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_3_SKA1;
    m_inputs_map[ska_num][MVB2].at("SIntercom_4_SKA1")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_4_SKA1;
    m_inputs_map[ska_num][MVB2].at("SIntercom_5_SKA1")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_5_SKA1;
    m_inputs_map[ska_num][MVB2].at("SIntercom_6_SKA1")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_6_SKA1;
    m_inputs_map[ska_num][MVB2].at("SIntercom_7_SKA1")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_7_SKA1;
    m_inputs_map[ska_num][MVB2].at("SIntercom_8_SKA1")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_8_SKA1;
    m_inputs_map[ska_num][MVB2].at("SIntercom_9_SKA1")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_9_SKA1;
    m_inputs_map[ska_num][MVB2].at("bit103")                          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit103;
    // Assigning values to m_inputs_map for MVB2 from ska_vh_riom_ccu_mvb11_papis2
    m_inputs_map[ska_num][MVB2].at("SIntercom_1_OA1")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_1_OA1; // byte 13
    m_inputs_map[ska_num][MVB2].at("SIntercom_2_OA1")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_2_OA1;
    m_inputs_map[ska_num][MVB2].at("SIntercom_3_OA1")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_3_OA1;
    m_inputs_map[ska_num][MVB2].at("SIntercom_4_OA1")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_4_OA1;
    m_inputs_map[ska_num][MVB2].at("SIntercom_5_OA1")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_5_OA1;
    m_inputs_map[ska_num][MVB2].at("SIntercom_6_OA1")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_6_OA1;
    m_inputs_map[ska_num][MVB2].at("SIntercom_7_OA1")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_7_OA1;
    m_inputs_map[ska_num][MVB2].at("SIntercom_8_OA1")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_8_OA1;
    m_inputs_map[ska_num][MVB2].at("SIntercom_1_OA2")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_1_OA2; // byte 14
    m_inputs_map[ska_num][MVB2].at("SIntercom_2_OA2")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_2_OA2;
    m_inputs_map[ska_num][MVB2].at("SIntercom_3_OA2")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_3_OA2;
    m_inputs_map[ska_num][MVB2].at("SIntercom_4_OA2")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_4_OA2;
    m_inputs_map[ska_num][MVB2].at("SIntercom_5_OA2")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_5_OA2;
    m_inputs_map[ska_num][MVB2].at("SIntercom_6_OA2")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_6_OA2;
    m_inputs_map[ska_num][MVB2].at("SIntercom_7_OA2")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_7_OA2;
    m_inputs_map[ska_num][MVB2].at("SIntercom_8_OA2")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_8_OA2;
    m_inputs_map[ska_num][MVB2].at("bit120")                          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit120; // byte 15
    m_inputs_map[ska_num][MVB2].at("SIntercom_1_SKA2")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_1_SKA2;
    m_inputs_map[ska_num][MVB2].at("SIntercom_2_SKA2")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_2_SKA2;
    m_inputs_map[ska_num][MVB2].at("SIntercom_3_SKA2")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_3_SKA2;
    m_inputs_map[ska_num][MVB2].at("SIntercom_4_SKA2")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_4_SKA2;
    m_inputs_map[ska_num][MVB2].at("SIntercom_5_SKA2")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_5_SKA2;
    m_inputs_map[ska_num][MVB2].at("SIntercom_6_SKA2")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_6_SKA2;
    m_inputs_map[ska_num][MVB2].at("SIntercom_7_SKA2")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_7_SKA2;
    m_inputs_map[ska_num][MVB2].at("SIntercom_8_SKA2")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_8_SKA2; // byte 16
    m_inputs_map[ska_num][MVB2].at("SIntercom_9_SKA2")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_9_SKA2;
    m_inputs_map[ska_num][MVB2].at("bit130")                          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit130;
    m_inputs_map[ska_num][MVB2].at("CIntercom_1_SKA1")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_1_SKA1; // byte 17
    m_inputs_map[ska_num][MVB2].at("CIntercom_2_SKA1")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_2_SKA1;
    m_inputs_map[ska_num][MVB2].at("CIntercom_3_SKA1")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_3_SKA1;
    m_inputs_map[ska_num][MVB2].at("CIntercom_4_SKA1")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_4_SKA1;
    m_inputs_map[ska_num][MVB2].at("CIntercom_5_SKA1")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_5_SKA1;
    m_inputs_map[ska_num][MVB2].at("CIntercom_6_SKA1")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_6_SKA1;
    m_inputs_map[ska_num][MVB2].at("CIntercom_7_SKA1")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_7_SKA1;
    m_inputs_map[ska_num][MVB2].at("CIntercom_8_SKA1")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_8_SKA1;
    m_inputs_map[ska_num][MVB2].at("CIntercom_9_SKA1")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_9_SKA1;
    m_inputs_map[ska_num][MVB2].at("bit140")                          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit140;



    // Assigning values to m_inputs_map for MVB2 from ska_vh_riom_ccu_mvb11_papis2
    m_inputs_map[ska_num][MVB2].at("CIntercom_1_OA1")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_1_OA1; // byte 18
    m_inputs_map[ska_num][MVB2].at("CIntercom_2_OA1")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_2_OA1;
    m_inputs_map[ska_num][MVB2].at("CIntercom_3_OA1")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_3_OA1;
    m_inputs_map[ska_num][MVB2].at("CIntercom_4_OA1")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_4_OA1;
    m_inputs_map[ska_num][MVB2].at("CIntercom_5_OA1")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_5_OA1;
    m_inputs_map[ska_num][MVB2].at("CIntercom_6_OA1")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_6_OA1;
    m_inputs_map[ska_num][MVB2].at("CIntercom_7_OA1")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_7_OA1;
    m_inputs_map[ska_num][MVB2].at("CIntercom_8_OA1")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_8_OA1;
    m_inputs_map[ska_num][MVB2].at("CIntercom_1_OA2")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_1_OA2; // byte 19
    m_inputs_map[ska_num][MVB2].at("CIntercom_2_OA2")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_2_OA2;
    m_inputs_map[ska_num][MVB2].at("CIntercom_3_OA2")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_3_OA2;
    m_inputs_map[ska_num][MVB2].at("CIntercom_4_OA2")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_4_OA2;
    m_inputs_map[ska_num][MVB2].at("CIntercom_5_OA2")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_5_OA2;
    m_inputs_map[ska_num][MVB2].at("CIntercom_6_OA2")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_6_OA2;
    m_inputs_map[ska_num][MVB2].at("CIntercom_7_OA2")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_7_OA2;
    m_inputs_map[ska_num][MVB2].at("CIntercom_8_OA2")                 = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_8_OA2;
    m_inputs_map[ska_num][MVB2].at("CIntercom_1_SKA2")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_1_SKA2; // byte 20
    m_inputs_map[ska_num][MVB2].at("CIntercom_2_SKA2")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_2_SKA2;
    m_inputs_map[ska_num][MVB2].at("CIntercom_3_SKA2")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_3_SKA2;
    m_inputs_map[ska_num][MVB2].at("CIntercom_4_SKA2")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_4_SKA2;
    m_inputs_map[ska_num][MVB2].at("CIntercom_5_SKA2")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_5_SKA2;
    m_inputs_map[ska_num][MVB2].at("CIntercom_6_SKA2")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_6_SKA2;
    m_inputs_map[ska_num][MVB2].at("CIntercom_7_SKA2")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_7_SKA2;
    m_inputs_map[ska_num][MVB2].at("CIntercom_8_SKA2")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_8_SKA2; // byte 21
    m_inputs_map[ska_num][MVB2].at("CIntercom_9_SKA2")                = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_9_SKA2;
    m_inputs_map[ska_num][MVB2].at("bit166")                          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit166;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA1_Network_Failure") = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA1_Network_Failure;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA1_Power_Failure")   = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA1_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA1_Not_Found")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA1_Not_Found;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA1_Busy")            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA1_Busy;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA1_Timeout")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA1_Timeout;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA1_Call1_Not_Reg")   = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA1_Call1_Not_Reg;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA1_Call2_Not_Reg")   = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA1_Call2_Not_Reg;
    m_inputs_map[ska_num][MVB2].at("bit174")                          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit174;

    // Assigning values to m_inputs_map for MVB2 from ska_vh_riom_ccu_mvb11_papis2
    m_inputs_map[ska_num][MVB2].at("Amplifier1_OA1_Network_Failure")   = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA1_Network_Failure; // byte 22
    m_inputs_map[ska_num][MVB2].at("Amplifier1_OA1_Power_Failure")     = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA1_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_OA1_Not_Found")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA1_Not_Found;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_OA1_Busy")              = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA1_Busy;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_OA1_Timeout")           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA1_Timeout;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_OA1_Call1_Not_Reg")     = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA1_Call1_Not_Reg;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_OA1_Call2_Not_Reg")     = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA1_Call2_Not_Reg;
    m_inputs_map[ska_num][MVB2].at("bit182")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit182;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_OA2_Network_Failure")   = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA2_Network_Failure; // byte 23
    m_inputs_map[ska_num][MVB2].at("Amplifier1_OA2_Power_Failure")     = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_OA2_Not_Found")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA2_Not_Found;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_OA2_Busy")              = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA2_Busy;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_OA2_Timeout")           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA2_Timeout;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_OA2_Call1_Not_Reg")     = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA2_Call1_Not_Reg;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_OA2_Call2_Not_Reg")     = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA2_Call2_Not_Reg;
    m_inputs_map[ska_num][MVB2].at("bit190")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit190;
    m_inputs_map[ska_num][MVB2].at("bit191")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit191;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA2_Network_Failure")  = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA2_Network_Failure; // byte 24
    m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA2_Power_Failure")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA2_Not_Found")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA2_Not_Found;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA2_Busy")             = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA2_Busy;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA2_Timeout")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA2_Timeout;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA2_Call1_Not_Reg")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA2_Call1_Not_Reg;
    m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA2_Call2_Not_Reg")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA2_Call2_Not_Reg;
    m_inputs_map[ska_num][MVB2].at("bit199")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit199;
    m_inputs_map[ska_num][MVB2].at("NoiseMic_SKA1_Power_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.NoiseMic_SKA1_Power_Failure; // byte 25
    m_inputs_map[ska_num][MVB2].at("bit201")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit201;
    m_inputs_map[ska_num][MVB2].at("NoiseMic_OA1_Power_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.NoiseMic_OA1_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("bit203")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit203;
    m_inputs_map[ska_num][MVB2].at("NoiseMic_OA2_Power_Failure")       = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.NoiseMic_OA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("bit205")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit205;
    m_inputs_map[ska_num][MVB2].at("NoiseMic_SKA2_Power_Failure")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.NoiseMic_SKA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("bit207")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit207;
    m_inputs_map[ska_num][MVB2].at("PerrCCTV_SKA1_Memory_Full")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrCCTV_SKA1_Memory_Full; // byte 26
    m_inputs_map[ska_num][MVB2].at("PerrCCTV_SKA1_Reg_Error")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrCCTV_SKA1_Reg_Error;
    m_inputs_map[ska_num][MVB2].at("PerrCCTV_SKA1_Standby_Error")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrCCTV_SKA1_Standby_Error;
    m_inputs_map[ska_num][MVB2].at("PerrCCTV_SKA1_Alarm_Error")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrCCTV_SKA1_Alarm_Error;
    m_inputs_map[ska_num][MVB2].at("PerrCCTV_SKA1_Time_Error")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrCCTV_SKA1_Time_Error;
    m_inputs_map[ska_num][MVB2].at("bit213")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit213;
    m_inputs_map[ska_num][MVB2].at("PerrCCTV_SKA2_Memory_Full")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrCCTV_SKA2_Memory_Full; // byte 27
    m_inputs_map[ska_num][MVB2].at("PerrCCTV_SKA2_Reg_Error")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrCCTV_SKA2_Reg_Error;
    m_inputs_map[ska_num][MVB2].at("PerrCCTV_SKA2_Standby_Error")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrCCTV_SKA2_Standby_Error;
    m_inputs_map[ska_num][MVB2].at("PerrCCTV_SKA2_Alarm_Error")        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrCCTV_SKA2_Alarm_Error;
    m_inputs_map[ska_num][MVB2].at("PerrCCTV_SKA2_Time_Error")         = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrCCTV_SKA2_Time_Error;
    m_inputs_map[ska_num][MVB2].at("bit219")                           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit219;
    m_inputs_map[ska_num][MVB2].at("PerrSwnNecMic_SKA1_Network_Failure")= m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrSwnNecMic_SKA1_Network_Failure; // byte 28
    m_inputs_map[ska_num][MVB2].at("PerrSwnNecMic_SKA1_Power_Failure")  = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrSwnNecMic_SKA1_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("bit222")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit222;
    m_inputs_map[ska_num][MVB2].at("PerrSwnNecMic_SKA2_Network_Failure")= m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrSwnNecMic_SKA2_Network_Failure;
    m_inputs_map[ska_num][MVB2].at("PerrSwnNecMic_SKA2_Power_Failure")  = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrSwnNecMic_SKA2_Power_Failure;
    m_inputs_map[ska_num][MVB2].at("bit225")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit225;
    m_inputs_map[ska_num][MVB2].at("bit226")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit226;
    m_inputs_map[ska_num][MVB2].at("bit227")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit227;
    m_inputs_map[ska_num][MVB2].at("bit228")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit228;
    m_inputs_map[ska_num][MVB2].at("bit229")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit229;
    m_inputs_map[ska_num][MVB2].at("bit230")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit230;
    m_inputs_map[ska_num][MVB2].at("bit231")                            = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit231;
    m_inputs_map[ska_num][MVB2].at("reserved29")                        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.reserved29;
    m_inputs_map[ska_num][MVB2].at("reserved30")                        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.reserved30;
    m_inputs_map[ska_num][MVB2].at("reserved31")                        = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.reserved31;



}

void SKA_PAPIS::update_mvb12_map(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    // Mapping for GPS and Timestamp variables
    m_inputs_map[ska_num][MVB3].at("GPS_longtitude_master")    = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.GPS_longtitude_master; // byte 0
    m_inputs_map[ska_num][MVB3].at("GPS_latitude_master")      = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.GPS_latitude_master; // byte 4
    m_inputs_map[ska_num][MVB3].at("Timestamp_time")           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.Timestamp_time; // byte 8
    m_inputs_map[ska_num][MVB3].at("Timestamp_date")           = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.Timestamp_date; // byte 12
    m_inputs_map[ska_num][MVB3].at("reserved14")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.reserved14; // byte 14
    m_inputs_map[ska_num][MVB3].at("reserved15")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.reserved15; // byte 15
    m_inputs_map[ska_num][MVB3].at("ServiceID_Byte1")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.ServiceID_Byte1; // byte 16
    m_inputs_map[ska_num][MVB3].at("ServiceID_Byte2")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.ServiceID_Byte2; // byte 17
    m_inputs_map[ska_num][MVB3].at("ServiceID_Byte3")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.ServiceID_Byte3; // byte 18
    m_inputs_map[ska_num][MVB3].at("ServiceID_Byte4")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.ServiceID_Byte4; // byte 19
    m_inputs_map[ska_num][MVB3].at("ServiceID_Byte5")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.ServiceID_Byte5; // byte 20
    m_inputs_map[ska_num][MVB3].at("ServiceID_Byte6")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.ServiceID_Byte6; // byte 21
    m_inputs_map[ska_num][MVB3].at("ServiceID_Byte7")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.ServiceID_Byte7; // byte 22
    m_inputs_map[ska_num][MVB3].at("ServiceID_Byte8")          = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.ServiceID_Byte8; // byte 23
    m_inputs_map[ska_num][MVB3].at("reserved24")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.reserved24; // byte 24
    m_inputs_map[ska_num][MVB3].at("reserved25")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.reserved25; // byte 25
    m_inputs_map[ska_num][MVB3].at("reserved26")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.reserved26; // byte 26
    m_inputs_map[ska_num][MVB3].at("reserved27")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.reserved27; // byte 27
    m_inputs_map[ska_num][MVB3].at("reserved28")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.reserved28; // byte 28
    m_inputs_map[ska_num][MVB3].at("reserved29")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.reserved29; // byte 29
    m_inputs_map[ska_num][MVB3].at("reserved30")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.reserved30; // byte 30
    m_inputs_map[ska_num][MVB3].at("reserved31")               = m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.reserved31; // byte 31

}


void SKA_PAPIS::set_struct_mvb10(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PapisINF_Piscu_SKA1_M = m_inputs_map[ska_num][MVB1].at("PapisINF_Piscu_SKA1_M")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PapisINF_Piscu_SKA2_M = m_inputs_map[ska_num][MVB1].at("PapisINF_Piscu_SKA2_M")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit2 = m_inputs_map[ska_num][MVB1].at("bit2")                        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit3 = m_inputs_map[ska_num][MVB1].at("bit3")                        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PapisINF_nvr_SKA1_M = m_inputs_map[ska_num][MVB1].at("PapisINF_nvr_SKA1_M")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PapisINF_nvr_SKA2_M = m_inputs_map[ska_num][MVB1].at("PapisINF_nvr_SKA2_M")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit6 = m_inputs_map[ska_num][MVB1].at("bit6")                        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit7 = m_inputs_map[ska_num][MVB1].at("bit7")                        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Piscu_SKA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("Piscu_SKA1_Network_Failure")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Piscu_SKA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("Piscu_SKA1_Power_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Piscu_SKA1_Version_Error = m_inputs_map[ska_num][MVB1].at("Piscu_SKA1_Version_Error")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Piscu_SKA1_OS_Error = m_inputs_map[ska_num][MVB1].at("Piscu_SKA1_OS_Error")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit12 = m_inputs_map[ska_num][MVB1].at("bit12")                       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit13 = m_inputs_map[ska_num][MVB1].at("bit13")                       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit14 = m_inputs_map[ska_num][MVB1].at("bit14")                       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit15 = m_inputs_map[ska_num][MVB1].at("bit15")                       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Piscu_SKA2_Network_Failure = m_inputs_map[ska_num][MVB1].at("Piscu_SKA2_Network_Failure")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Piscu_SKA2_Power_Failure = m_inputs_map[ska_num][MVB1].at("Piscu_SKA2_Power_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Piscu_SKA2_Version_Error = m_inputs_map[ska_num][MVB1].at("Piscu_SKA2_Version_Error")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Piscu_SKA2_OS_Error = m_inputs_map[ska_num][MVB1].at("Piscu_SKA2_OS_Error")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit20 = m_inputs_map[ska_num][MVB1].at("bit20")                       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit21 = m_inputs_map[ska_num][MVB1].at("bit21")                       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit22 = m_inputs_map[ska_num][MVB1].at("bit22")                       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit23 = m_inputs_map[ska_num][MVB1].at("bit23")                       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_01_02_SKA1_Error = m_inputs_map[ska_num][MVB1].at("Pis_01_02_SKA1_Error")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_03_04_SKA1_Error = m_inputs_map[ska_num][MVB1].at("Pis_03_04_SKA1_Error")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_05_06_SKA1_Error = m_inputs_map[ska_num][MVB1].at("Pis_05_06_SKA1_Error")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_07_08_SKA1_Error = m_inputs_map[ska_num][MVB1].at("Pis_07_08_SKA1_Error")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_01_02_OA1_Error = m_inputs_map[ska_num][MVB1].at("Pis_01_02_OA1_Error")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_03_04_OA1_Error = m_inputs_map[ska_num][MVB1].at("Pis_03_04_OA1_Error")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_05_06_OA1_Error = m_inputs_map[ska_num][MVB1].at("Pis_05_06_OA1_Error")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_07_08_OA1_Error = m_inputs_map[ska_num][MVB1].at("Pis_07_08_OA1_Error")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_01_02_OA2_Error = m_inputs_map[ska_num][MVB1].at("Pis_01_02_OA2_Error")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_03_04_OA2_Error = m_inputs_map[ska_num][MVB1].at("Pis_03_04_OA2_Error")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_05_06_OA2_Error = m_inputs_map[ska_num][MVB1].at("Pis_05_06_OA2_Error")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_07_08_OA2_Error = m_inputs_map[ska_num][MVB1].at("Pis_07_08_OA2_Error")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_01_02_SKA2_Error = m_inputs_map[ska_num][MVB1].at("Pis_01_02_SKA2_Error")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_03_04_SKA2_Error = m_inputs_map[ska_num][MVB1].at("Pis_03_04_SKA2_Error")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_05_06_SKA2_Error = m_inputs_map[ska_num][MVB1].at("Pis_05_06_SKA2_Error")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Pis_07_08_SKA2_Error = m_inputs_map[ska_num][MVB1].at("Pis_07_08_SKA2_Error")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.FrontLed1_SKA1_Process_Error = m_inputs_map[ska_num][MVB1].at("FrontLed1_SKA1_Process_Error");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.FrontLed1_SKA1_Version_Error = m_inputs_map[ska_num][MVB1].at("FrontLed1_SKA1_Version_Error");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.FrontLed1_SKA1_Device_Busy = m_inputs_map[ska_num][MVB1].at("FrontLed1_SKA1_Device_Busy")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.FrontLed1_SKA1_System_Error = m_inputs_map[ska_num][MVB1].at("FrontLed1_SKA1_System_Error") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit44 = m_inputs_map[ska_num][MVB1].at("bit44")                       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_SKA1_Process_Error = m_inputs_map[ska_num][MVB1].at("OutLed1_SKA1_Process_Error")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_SKA1_Version_Error = m_inputs_map[ska_num][MVB1].at("OutLed1_SKA1_Version_Error")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_SKA1_Device_Busy = m_inputs_map[ska_num][MVB1].at("OutLed1_SKA1_Device_Busy")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_SKA1_System_Error = m_inputs_map[ska_num][MVB1].at("OutLed1_SKA1_System_Error")   ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit49 = m_inputs_map[ska_num][MVB1].at("bit49")                       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_SKA1_Process_Error = m_inputs_map[ska_num][MVB1].at("OutLed2_SKA1_Process_Error")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_SKA1_Version_Error = m_inputs_map[ska_num][MVB1].at("OutLed2_SKA1_Version_Error")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_SKA1_Device_Busy = m_inputs_map[ska_num][MVB1].at("OutLed2_SKA1_Device_Busy")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_SKA1_System_Error = m_inputs_map[ska_num][MVB1].at("OutLed2_SKA1_System_Error")   ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit54 = m_inputs_map[ska_num][MVB1].at("bit54")                       ;



    // New signal mappings added

    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_OA1_Process_Error = m_inputs_map[ska_num][MVB1].at("OutLed1_OA1_Process_Error")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_OA1_Version_Error = m_inputs_map[ska_num][MVB1].at("OutLed1_OA1_Version_Error")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_OA1_Device_Busy = m_inputs_map[ska_num][MVB1].at("OutLed1_OA1_Device_Busy")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_OA1_System_Error = m_inputs_map[ska_num][MVB1].at("OutLed1_OA1_System_Error")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit59 = m_inputs_map[ska_num][MVB1].at("bit59")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_OA1_Process_Error = m_inputs_map[ska_num][MVB1].at("OutLed2_OA1_Process_Error")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_OA1_Version_Error = m_inputs_map[ska_num][MVB1].at("OutLed2_OA1_Version_Error")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_OA1_Device_Busy = m_inputs_map[ska_num][MVB1].at("OutLed2_OA1_Device_Busy")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_OA1_System_Error = m_inputs_map[ska_num][MVB1].at("OutLed2_OA1_System_Error")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit64 = m_inputs_map[ska_num][MVB1].at("bit64")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_OA2_Process_Error = m_inputs_map[ska_num][MVB1].at("OutLed1_OA2_Process_Error")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_OA2_Version_Error = m_inputs_map[ska_num][MVB1].at("OutLed1_OA2_Version_Error")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_OA2_Device_Busy = m_inputs_map[ska_num][MVB1].at("OutLed1_OA2_Device_Busy")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_OA2_System_Error = m_inputs_map[ska_num][MVB1].at("OutLed1_OA2_System_Error")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit69 = m_inputs_map[ska_num][MVB1].at("bit69")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_OA2_Process_Error = m_inputs_map[ska_num][MVB1].at("OutLed2_OA2_Process_Error")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_OA2_Version_Error = m_inputs_map[ska_num][MVB1].at("OutLed2_OA2_Version_Error")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_OA2_Device_Busy = m_inputs_map[ska_num][MVB1].at("OutLed2_OA2_Device_Busy")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_OA2_System_Error = m_inputs_map[ska_num][MVB1].at("OutLed2_OA2_System_Error")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit74 = m_inputs_map[ska_num][MVB1].at("bit74")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.FrontLed1_SKA2_Process_Error = m_inputs_map[ska_num][MVB1].at("FrontLed1_SKA2_Process_Error")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.FrontLed1_SKA2_Version_Error = m_inputs_map[ska_num][MVB1].at("FrontLed1_SKA2_Version_Error")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.FrontLed1_SKA2_Device_Busy = m_inputs_map[ska_num][MVB1].at("FrontLed1_SKA2_Device_Busy")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.FrontLed1_SKA2_System_Error = m_inputs_map[ska_num][MVB1].at("FrontLed1_SKA2_System_Error")     ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit79 = m_inputs_map[ska_num][MVB1].at("bit79")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_SKA2_Process_Error = m_inputs_map[ska_num][MVB1].at("OutLed1_SKA2_Process_Error")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_SKA2_Version_Error = m_inputs_map[ska_num][MVB1].at("OutLed1_SKA2_Version_Error")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_SKA2_Device_Busy = m_inputs_map[ska_num][MVB1].at("OutLed1_SKA2_Device_Busy")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed1_SKA2_System_Error = m_inputs_map[ska_num][MVB1].at("OutLed1_SKA2_System_Error")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit84 = m_inputs_map[ska_num][MVB1].at("bit84")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_SKA2_Process_Error = m_inputs_map[ska_num][MVB1].at("OutLed2_SKA2_Process_Error")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_SKA2_Version_Error = m_inputs_map[ska_num][MVB1].at("OutLed2_SKA2_Version_Error")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_SKA2_Device_Busy = m_inputs_map[ska_num][MVB1].at("OutLed2_SKA2_Device_Busy")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.OutLed2_SKA2_System_Error = m_inputs_map[ska_num][MVB1].at("OutLed2_SKA2_System_Error")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit89 = m_inputs_map[ska_num][MVB1].at("bit89") ;

    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.CCTV_HMI_SKA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("CCTV_HMI_SKA1_Network_Failure")   ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.CCTV_HMI_SKA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("CCTV_HMI_SKA1_Power_Failure")     ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.CCTV_HMI_SKA1_Server_Error = m_inputs_map[ska_num][MVB1].at("CCTV_HMI_SKA1_Server_Error")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit93 = m_inputs_map[ska_num][MVB1].at("bit93")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.CCTV_HMI_SKA2_Network_Failure = m_inputs_map[ska_num][MVB1].at("CCTV_HMI_SKA2_Network_Failure")   ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.CCTV_HMI_SKA2_Power_Failure = m_inputs_map[ska_num][MVB1].at("CCTV_HMI_SKA2_Power_Failure")     ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.CCTV_HMI_SKA2_Server_Error = m_inputs_map[ska_num][MVB1].at("CCTV_HMI_SKA2_Server_Error")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit97 = m_inputs_map[ska_num][MVB1].at("bit97")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.F_Cam1_SKA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("F_Cam1_SKA1_Network_Failure")     ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.F_Cam1_SKA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("F_Cam1_SKA1_Power_Failure")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit100 = m_inputs_map[ska_num][MVB1].at("bit100")                          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.C_Cam1_SKA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("C_Cam1_SKA1_Network_Failure")     ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.C_Cam1_SKA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("C_Cam1_SKA1_Power_Failure")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit103 = m_inputs_map[ska_num][MVB1].at("bit103")                          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam1_SKA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam1_SKA1_Network_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam1_SKA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam1_SKA1_Power_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit106 = m_inputs_map[ska_num][MVB1].at("bit106")                          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam2_SKA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam2_SKA1_Network_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam2_SKA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam2_SKA1_Power_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit109 = m_inputs_map[ska_num][MVB1].at("bit109")                          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam3_SKA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam3_SKA1_Network_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam3_SKA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam3_SKA1_Power_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit112 = m_inputs_map[ska_num][MVB1].at("bit112")                          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam4_SKA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam4_SKA1_Network_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam4_SKA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam4_SKA1_Power_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit115 = m_inputs_map[ska_num][MVB1].at("bit115")                          ;


    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.RL_Cam4_SKA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("RL_Cam4_SKA1_Network_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.RL_Cam4_SKA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("RL_Cam4_SKA1_Power_Failure")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit118 = m_inputs_map[ska_num][MVB1].at("bit118")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.RR_Cam1_SKA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("RR_Cam1_SKA1_Network_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.RR_Cam1_SKA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("RR_Cam1_SKA1_Power_Failure")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit121 = m_inputs_map[ska_num][MVB1].at("bit121")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam1_OA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam1_OA1_Network_Failure")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam1_OA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam1_OA1_Power_Failure")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit124 = m_inputs_map[ska_num][MVB1].at("bit124")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam2_OA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam2_OA1_Network_Failure")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam2_OA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam2_OA1_Power_Failure")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit127 = m_inputs_map[ska_num][MVB1].at("bit127")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam3_OA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam3_OA1_Network_Failure")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam3_OA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam3_OA1_Power_Failure")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit130 = m_inputs_map[ska_num][MVB1].at("bit130")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam4_OA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam4_OA1_Network_Failure")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam4_OA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam4_OA1_Power_Failure")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit133 = m_inputs_map[ska_num][MVB1].at("bit133")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PN_Cam1_OA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("PN_Cam1_OA1_Network_Failure")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PN_Cam1_OA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("PN_Cam1_OA1_Power_Failure")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit136 = m_inputs_map[ska_num][MVB1].at("bit136")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PN_Cam1_OA2_Network_Failure = m_inputs_map[ska_num][MVB1].at("PN_Cam1_OA2_Network_Failure")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PN_Cam1_OA2_Power_Failure = m_inputs_map[ska_num][MVB1].at("PN_Cam1_OA2_Power_Failure")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit139 = m_inputs_map[ska_num][MVB1].at("bit139")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam1_OA2_Network_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam1_OA2_Network_Failure")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam1_OA2_Power_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam1_OA2_Power_Failure")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit142 = m_inputs_map[ska_num][MVB1].at("bit142")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam2_OA2_Network_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam2_OA2_Network_Failure")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam2_OA2_Power_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam2_OA2_Power_Failure")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit145 = m_inputs_map[ska_num][MVB1].at("bit145")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam3_OA2_Network_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam3_OA2_Network_Failure")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam3_OA2_Power_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam3_OA2_Power_Failure")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit148 = m_inputs_map[ska_num][MVB1].at("bit148")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam4_OA2_Network_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam4_OA2_Network_Failure")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam4_OA2_Power_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam4_OA2_Power_Failure")         ;

    // Additional mappings
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit151 = m_inputs_map[ska_num][MVB1].at("bit151")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.F_Cam1_SKA2_Network_Failure = m_inputs_map[ska_num][MVB1].at("F_Cam1_SKA2_Network_Failure")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.F_Cam1_SKA2_Power_Failure = m_inputs_map[ska_num][MVB1].at("F_Cam1_SKA2_Power_Failure")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit154 = m_inputs_map[ska_num][MVB1].at("bit154")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.C_Cam1_SKA2_Network_Failure = m_inputs_map[ska_num][MVB1].at("C_Cam1_SKA2_Network_Failure")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.C_Cam1_SKA2_Power_Failure = m_inputs_map[ska_num][MVB1].at("C_Cam1_SKA2_Power_Failure")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit157 = m_inputs_map[ska_num][MVB1].at("bit157")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam1_SKA2_Network_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam1_SKA2_Network_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam1_SKA2_Power_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam1_SKA2_Power_Failure")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit160 = m_inputs_map[ska_num][MVB1].at("bit160")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam2_SKA2_Network_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam2_SKA2_Network_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam2_SKA2_Power_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam2_SKA2_Power_Failure")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit163 = m_inputs_map[ska_num][MVB1].at("bit163")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam3_SKA2_Network_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam3_SKA2_Network_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam3_SKA2_Power_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam3_SKA2_Power_Failure")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit166 = m_inputs_map[ska_num][MVB1].at("bit166")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam4_SKA2_Network_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam4_SKA2_Network_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.PS_Cam4_SKA2_Power_Failure = m_inputs_map[ska_num][MVB1].at("PS_Cam4_SKA2_Power_Failure")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit169 = m_inputs_map[ska_num][MVB1].at("bit169")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.RL_Cam1_SKA2_Network_Failure = m_inputs_map[ska_num][MVB1].at("RL_Cam1_SKA2_Network_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.RL_Cam1_SKA2_Power_Failure = m_inputs_map[ska_num][MVB1].at("RL_Cam1_SKA2_Power_Failure")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit172 = m_inputs_map[ska_num][MVB1].at("bit172")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.RR_Cam2_SKA2_Network_Failure = m_inputs_map[ska_num][MVB1].at("RR_Cam2_SKA2_Network_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.RR_Cam2_SKA2_Power_Failure = m_inputs_map[ska_num][MVB1].at("RR_Cam2_SKA2_Power_Failure")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit175 = m_inputs_map[ska_num][MVB1].at("bit175")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom1_SKA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("Intercom1_SKA1_Network_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom1_SKA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("Intercom1_SKA1_Power_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom1_SKA1_Timeout = m_inputs_map[ska_num][MVB1].at("Intercom1_SKA1_Timeout")            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom1_SKA1_Not_Found = m_inputs_map[ska_num][MVB1].at("Intercom1_SKA1_Not_Found")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit180 = m_inputs_map[ska_num][MVB1].at("bit180")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom2_SKA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("Intercom2_SKA1_Network_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom2_SKA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("Intercom2_SKA1_Power_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom2_SKA1_Timeout = m_inputs_map[ska_num][MVB1].at("Intercom2_SKA1_Timeout")            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom2_SKA1_Not_Found= m_inputs_map[ska_num][MVB1].at("Intercom2_SKA1_Not_Found")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit185 = m_inputs_map[ska_num][MVB1].at("bit185")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom3_SKA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("Intercom3_SKA1_Network_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom3_SKA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("Intercom3_SKA1_Power_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom3_SKA1_Timeout = m_inputs_map[ska_num][MVB1].at("Intercom3_SKA1_Timeout")            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom3_SKA1_Not_Found = m_inputs_map[ska_num][MVB1].at("Intercom3_SKA1_Not_Found")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit190 = m_inputs_map[ska_num][MVB1].at("bit190")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit191 = m_inputs_map[ska_num][MVB1].at("bit191")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom4_SKA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("Intercom4_SKA1_Network_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom4_SKA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("Intercom4_SKA1_Power_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom4_SKA1_Timeout = m_inputs_map[ska_num][MVB1].at("Intercom4_SKA1_Timeout")            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom4_SKA1_Not_Found = m_inputs_map[ska_num][MVB1].at("Intercom4_SKA1_Not_Found")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit196 = m_inputs_map[ska_num][MVB1].at("bit196")                            ;



    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom5_SKA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("Intercom5_SKA1_Network_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom5_SKA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("Intercom5_SKA1_Power_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom5_SKA1_Timeout = m_inputs_map[ska_num][MVB1].at("Intercom5_SKA1_Timeout")            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom5_SKA1_Not_Found = m_inputs_map[ska_num][MVB1].at("Intercom5_SKA1_Not_Found")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit201 = m_inputs_map[ska_num][MVB1].at("bit201")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom6_SKA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("Intercom6_SKA1_Network_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom6_SKA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("Intercom6_SKA1_Power_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom6_SKA1_Timeout = m_inputs_map[ska_num][MVB1].at("Intercom6_SKA1_Timeout")            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom6_SKA1_Not_Found = m_inputs_map[ska_num][MVB1].at("Intercom6_SKA1_Not_Found")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit206 = m_inputs_map[ska_num][MVB1].at("bit206")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom7_SKA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("Intercom7_SKA1_Network_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom7_SKA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("Intercom7_SKA1_Power_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom7_SKA1_Timeout = m_inputs_map[ska_num][MVB1].at("Intercom7_SKA1_Timeout")            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom7_SKA1_Not_Found = m_inputs_map[ska_num][MVB1].at("Intercom7_SKA1_Not_Found")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit211 = m_inputs_map[ska_num][MVB1].at("bit211")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom8_SKA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("Intercom8_SKA1_Network_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom8_SKA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("Intercom8_SKA1_Power_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom8_SKA1_Timeout = m_inputs_map[ska_num][MVB1].at("Intercom8_SKA1_Timeout")            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom8_SKA1_Not_Found = m_inputs_map[ska_num][MVB1].at("Intercom8_SKA1_Not_Found")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit216 = m_inputs_map[ska_num][MVB1].at("bit216")                            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom9_SKA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("Intercom9_SKA1_Network_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom9_SKA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("Intercom9_SKA1_Power_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom9_SKA1_Timeout = m_inputs_map[ska_num][MVB1].at("Intercom9_SKA1_Timeout")            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom9_SKA1_Not_Found = m_inputs_map[ska_num][MVB1].at("Intercom9_SKA1_Not_Found")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit221 = m_inputs_map[ska_num][MVB1].at("bit221")                            ;

    // Additional mappings for OA1 Intercoms 1 to 3
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom1_OA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("Intercom1_OA1_Network_Failure")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom1_OA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("Intercom1_OA1_Power_Failure")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom1_OA1_Timeout = m_inputs_map[ska_num][MVB1].at("Intercom1_OA1_Timeout")               ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom1_OA1_Not_Found = m_inputs_map[ska_num][MVB1].at("Intercom1_OA1_Not_Found")             ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit226 = m_inputs_map[ska_num][MVB1].at("bit226")                              ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom2_OA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("Intercom2_OA1_Network_Failure")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom2_OA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("Intercom2_OA1_Power_Failure")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom2_OA1_Timeout = m_inputs_map[ska_num][MVB1].at("Intercom2_OA1_Timeout")               ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom2_OA1_Not_Found = m_inputs_map[ska_num][MVB1].at("Intercom2_OA1_Not_Found")             ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit231 = m_inputs_map[ska_num][MVB1].at("bit231")                              ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom3_OA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("Intercom3_OA1_Network_Failure")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom3_OA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("Intercom3_OA1_Power_Failure")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom3_OA1_Timeout = m_inputs_map[ska_num][MVB1].at("Intercom3_OA1_Timeout")               ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom3_OA1_Not_Found = m_inputs_map[ska_num][MVB1].at("Intercom3_OA1_Not_Found")             ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit236 = m_inputs_map[ska_num][MVB1].at("bit236")                              ;


    // Additional mappings for Intercom4, Intercom5, Intercom6, and Intercom7
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom4_OA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("Intercom4_OA1_Network_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom4_OA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("Intercom4_OA1_Power_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom4_OA1_Timeout = m_inputs_map[ska_num][MVB1].at("Intercom4_OA1_Timeout")            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom4_OA1_Not_Found = m_inputs_map[ska_num][MVB1].at("Intercom4_OA1_Not_Found")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit241 = m_inputs_map[ska_num][MVB1].at("bit241")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom5_OA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("Intercom5_OA1_Network_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom5_OA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("Intercom5_OA1_Power_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom5_OA1_Timeout = m_inputs_map[ska_num][MVB1].at("Intercom5_OA1_Timeout")            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom5_OA1_Not_Found = m_inputs_map[ska_num][MVB1].at("Intercom5_OA1_Not_Found")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit246 = m_inputs_map[ska_num][MVB1].at("bit246")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom6_OA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("Intercom6_OA1_Network_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom6_OA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("Intercom6_OA1_Power_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom6_OA1_Timeout = m_inputs_map[ska_num][MVB1].at("Intercom6_OA1_Timeout")            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom6_OA1_Not_Found = m_inputs_map[ska_num][MVB1].at("Intercom6_OA1_Not_Found")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.bit251 = m_inputs_map[ska_num][MVB1].at("bit251")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom7_OA1_Network_Failure = m_inputs_map[ska_num][MVB1].at("Intercom7_OA1_Network_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom7_OA1_Power_Failure = m_inputs_map[ska_num][MVB1].at("Intercom7_OA1_Power_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom7_OA1_Timeout = m_inputs_map[ska_num][MVB1].at("Intercom7_OA1_Timeout")            ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb10_papis1.bits.Intercom7_OA1_Not_Found = m_inputs_map[ska_num][MVB1].at("Intercom7_OA1_Not_Found")          ;
}

void SKA_PAPIS::set_struct_mvb11(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    // Assigning values to m_inputs_map for MVB2 from ska_vh_riom_ccu_mvb11_papis2
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit0  = m_inputs_map[ska_num][MVB2].at("bit0")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_OA1_Network_Failure = m_inputs_map[ska_num][MVB2].at("Intercom8_OA1_Network_Failure")   ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_OA1_Power_Failure = m_inputs_map[ska_num][MVB2].at("Intercom8_OA1_Power_Failure")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_OA1_Timeout = m_inputs_map[ska_num][MVB2].at("Intercom8_OA1_Timeout")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_OA1_Not_Found = m_inputs_map[ska_num][MVB2].at("Intercom8_OA1_Not_Found")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit5 = m_inputs_map[ska_num][MVB2].at("bit5")                           ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom1_OA2_Network_Failure = m_inputs_map[ska_num][MVB2].at("Intercom1_OA2_Network_Failure") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom1_OA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("Intercom1_OA2_Power_Failure")    ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom1_OA2_Timeout = m_inputs_map[ska_num][MVB2].at("Intercom1_OA2_Timeout")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom1_OA2_Not_Found = m_inputs_map[ska_num][MVB2].at("Intercom1_OA2_Not_Found")       ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit10 = m_inputs_map[ska_num][MVB2].at("bit10")                          ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom2_OA2_Network_Failure = m_inputs_map[ska_num][MVB2].at("Intercom2_OA2_Network_Failure")  ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom2_OA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("Intercom2_OA2_Power_Failure")    ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom2_OA2_Timeout = m_inputs_map[ska_num][MVB2].at("Intercom2_OA2_Timeout")   ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom2_OA2_Not_Found = m_inputs_map[ska_num][MVB2].at("Intercom2_OA2_Not_Found") ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit15 = m_inputs_map[ska_num][MVB2].at("bit15")                          ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom3_OA2_Network_Failure  = m_inputs_map[ska_num][MVB2].at("Intercom3_OA2_Network_Failure") ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom3_OA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("Intercom3_OA2_Power_Failure")   ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom3_OA2_Timeout = m_inputs_map[ska_num][MVB2].at("Intercom3_OA2_Timeout")      ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom3_OA2_Not_Found = m_inputs_map[ska_num][MVB2].at("Intercom3_OA2_Not_Found")   ,
         m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit20 = m_inputs_map[ska_num][MVB2].at("bit20")     ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom4_OA2_Network_Failure  = m_inputs_map[ska_num][MVB2].at("Intercom4_OA2_Network_Failure")  ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom4_OA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("Intercom4_OA2_Power_Failure")  ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom4_OA2_Timeout = m_inputs_map[ska_num][MVB2].at("Intercom4_OA2_Timeout")     ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom4_OA2_Not_Found = m_inputs_map[ska_num][MVB2].at("Intercom4_OA2_Not_Found")  ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit25 = m_inputs_map[ska_num][MVB2].at("bit25")                   ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom5_OA2_Network_Failure = m_inputs_map[ska_num][MVB2].at("Intercom5_OA2_Network_Failure")  ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom5_OA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("Intercom5_OA2_Power_Failure");
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom5_OA2_Timeout = m_inputs_map[ska_num][MVB2].at("Intercom5_OA2_Timeout")   ;
         m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom5_OA2_Not_Found = m_inputs_map[ska_num][MVB2].at("Intercom5_OA2_Not_Found") ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit30 = m_inputs_map[ska_num][MVB2].at("bit30")      ;
         m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom6_OA2_Network_Failure = m_inputs_map[ska_num][MVB2].at("Intercom6_OA2_Network_Failure");
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom6_OA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("Intercom6_OA2_Power_Failure");
         m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom6_OA2_Timeout = m_inputs_map[ska_num][MVB2].at("Intercom6_OA2_Timeout")   ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom6_OA2_Not_Found = m_inputs_map[ska_num][MVB2].at("Intercom6_OA2_Not_Found") ;
         m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit35 = m_inputs_map[ska_num][MVB2].at("bit35");

    // Assigning values to m_inputs_map for MVB2 from ska_vh_riom_ccu_mvb11_papis2
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom7_OA2_Network_Failure  = m_inputs_map[ska_num][MVB2].at("Intercom7_OA2_Network_Failure")   ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom7_OA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("Intercom7_OA2_Power_Failure")     ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom7_OA2_Timeout = m_inputs_map[ska_num][MVB2].at("Intercom7_OA2_Timeout")           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom7_OA2_Not_Found = m_inputs_map[ska_num][MVB2].at("Intercom7_OA2_Not_Found")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit40 = m_inputs_map[ska_num][MVB2].at("bit40")                           ;


    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_OA2_Network_Failure  = m_inputs_map[ska_num][MVB2].at("Intercom8_OA2_Network_Failure")   ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_OA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("Intercom8_OA2_Power_Failure")     ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_OA2_Timeout = m_inputs_map[ska_num][MVB2].at("Intercom8_OA2_Timeout")           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_OA2_Not_Found = m_inputs_map[ska_num][MVB2].at("Intercom8_OA2_Not_Found")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit45 = m_inputs_map[ska_num][MVB2].at("bit45")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom1_SKA2_Network_Failure  = m_inputs_map[ska_num][MVB2].at("Intercom1_SKA2_Network_Failure")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom1_SKA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("Intercom1_SKA2_Power_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom1_SKA2_Timeout = m_inputs_map[ska_num][MVB2].at("Intercom1_SKA2_Timeout")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom1_SKA2_Not_Found = m_inputs_map[ska_num][MVB2].at("Intercom1_SKA2_Not_Found")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit50 = m_inputs_map[ska_num][MVB2].at("bit50")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom2_SKA2_Network_Failure  = m_inputs_map[ska_num][MVB2].at("Intercom2_SKA2_Network_Failure")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom2_SKA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("Intercom2_SKA2_Power_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom2_SKA2_Timeout = m_inputs_map[ska_num][MVB2].at("Intercom2_SKA2_Timeout")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom2_SKA2_Not_Found = m_inputs_map[ska_num][MVB2].at("Intercom2_SKA2_Not_Found")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit55 = m_inputs_map[ska_num][MVB2].at("bit55")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom3_SKA2_Network_Failure  = m_inputs_map[ska_num][MVB2].at("Intercom3_SKA2_Network_Failure")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom3_SKA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("Intercom3_SKA2_Power_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom3_SKA2_Timeout = m_inputs_map[ska_num][MVB2].at("Intercom3_SKA2_Timeout")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom3_SKA2_Not_Found = m_inputs_map[ska_num][MVB2].at("Intercom3_SKA2_Not_Found")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit60 = m_inputs_map[ska_num][MVB2].at("bit60")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit61 = m_inputs_map[ska_num][MVB2].at("bit61")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit62 = m_inputs_map[ska_num][MVB2].at("bit62")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit63 = m_inputs_map[ska_num][MVB2].at("bit63")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom4_SKA2_Network_Failure = m_inputs_map[ska_num][MVB2].at("Intercom4_SKA2_Network_Failure")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom4_SKA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("Intercom4_SKA2_Power_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom4_SKA2_Timeout = m_inputs_map[ska_num][MVB2].at("Intercom4_SKA2_Timeout")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom4_SKA2_Not_Found = m_inputs_map[ska_num][MVB2].at("Intercom4_SKA2_Not_Found")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit68 = m_inputs_map[ska_num][MVB2].at("bit68")                           ;
    // Assigning values to m_inputs_map for MVB2 from ska_vh_riom_ccu_mvb11_papis2

    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom5_SKA2_Network_Failure  = m_inputs_map[ska_num][MVB2].at("Intercom5_SKA2_Network_Failure");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom5_SKA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("Intercom5_SKA2_Power_Failure")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom5_SKA2_Timeout = m_inputs_map[ska_num][MVB2].at("Intercom5_SKA2_Timeout")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom5_SKA2_Not_Found = m_inputs_map[ska_num][MVB2].at("Intercom5_SKA2_Not_Found")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit73 = m_inputs_map[ska_num][MVB2].at("bit73")                         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom6_SKA2_Network_Failure = m_inputs_map[ska_num][MVB2].at("Intercom6_SKA2_Network_Failure");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom6_SKA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("Intercom6_SKA2_Power_Failure")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom6_SKA2_Timeout = m_inputs_map[ska_num][MVB2].at("Intercom6_SKA2_Timeout")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom6_SKA2_Not_Found = m_inputs_map[ska_num][MVB2].at("Intercom6_SKA2_Not_Found")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit78 = m_inputs_map[ska_num][MVB2].at("bit78")                         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom7_SKA2_Network_Failure = m_inputs_map[ska_num][MVB2].at("Intercom7_SKA2_Network_Failure");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom7_SKA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("Intercom7_SKA2_Power_Failure")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom7_SKA2_Timeout = m_inputs_map[ska_num][MVB2].at("Intercom7_SKA2_Timeout")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom7_SKA2_Not_Found = m_inputs_map[ska_num][MVB2].at("Intercom7_SKA2_Not_Found")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit83 = m_inputs_map[ska_num][MVB2].at("bit83")                         ;


    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_SKA2_Network_Failure = m_inputs_map[ska_num][MVB2].at("Intercom8_SKA2_Network_Failure");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_SKA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("Intercom8_SKA2_Power_Failure")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_SKA2_Timeout = m_inputs_map[ska_num][MVB2].at("Intercom8_SKA2_Timeout")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom8_SKA2_Not_Found = m_inputs_map[ska_num][MVB2].at("Intercom8_SKA2_Not_Found")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit88 = m_inputs_map[ska_num][MVB2].at("bit88")                         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom9_SKA2_Network_Failure = m_inputs_map[ska_num][MVB2].at("Intercom9_SKA2_Network_Failure");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom9_SKA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("Intercom9_SKA2_Power_Failure")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom9_SKA2_Timeout = m_inputs_map[ska_num][MVB2].at("Intercom9_SKA2_Timeout")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Intercom9_SKA2_Not_Found = m_inputs_map[ska_num][MVB2].at("Intercom9_SKA2_Not_Found")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit93 = m_inputs_map[ska_num][MVB2].at("bit93")                         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_1_SKA1 = m_inputs_map[ska_num][MVB2].at("SIntercom_1_SKA1")              ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_2_SKA1 = m_inputs_map[ska_num][MVB2].at("SIntercom_2_SKA1")              ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_3_SKA1 = m_inputs_map[ska_num][MVB2].at("SIntercom_3_SKA1")              ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_4_SKA1 = m_inputs_map[ska_num][MVB2].at("SIntercom_4_SKA1")              ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_5_SKA1 = m_inputs_map[ska_num][MVB2].at("SIntercom_5_SKA1")              ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_6_SKA1 = m_inputs_map[ska_num][MVB2].at("SIntercom_6_SKA1")              ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_7_SKA1 = m_inputs_map[ska_num][MVB2].at("SIntercom_7_SKA1")              ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_8_SKA1 = m_inputs_map[ska_num][MVB2].at("SIntercom_8_SKA1")              ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_9_SKA1 = m_inputs_map[ska_num][MVB2].at("SIntercom_9_SKA1")              ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit103 = m_inputs_map[ska_num][MVB2].at("bit103");

    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_1_OA1 = m_inputs_map[ska_num][MVB2].at("SIntercom_1_OA1") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_2_OA1 = m_inputs_map[ska_num][MVB2].at("SIntercom_2_OA1") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_3_OA1 = m_inputs_map[ska_num][MVB2].at("SIntercom_3_OA1") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_4_OA1 = m_inputs_map[ska_num][MVB2].at("SIntercom_4_OA1") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_5_OA1 = m_inputs_map[ska_num][MVB2].at("SIntercom_5_OA1") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_6_OA1 = m_inputs_map[ska_num][MVB2].at("SIntercom_6_OA1") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_7_OA1 = m_inputs_map[ska_num][MVB2].at("SIntercom_7_OA1") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_8_OA1 = m_inputs_map[ska_num][MVB2].at("SIntercom_8_OA1") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_1_OA2 = m_inputs_map[ska_num][MVB2].at("SIntercom_1_OA2") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_2_OA2 = m_inputs_map[ska_num][MVB2].at("SIntercom_2_OA2") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_3_OA2 = m_inputs_map[ska_num][MVB2].at("SIntercom_3_OA2") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_4_OA2 = m_inputs_map[ska_num][MVB2].at("SIntercom_4_OA2") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_5_OA2 = m_inputs_map[ska_num][MVB2].at("SIntercom_5_OA2") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_6_OA2 = m_inputs_map[ska_num][MVB2].at("SIntercom_6_OA2") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_7_OA2 = m_inputs_map[ska_num][MVB2].at("SIntercom_7_OA2") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_8_OA2 = m_inputs_map[ska_num][MVB2].at("SIntercom_8_OA2") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit120 = m_inputs_map[ska_num][MVB2].at("bit120")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_1_SKA2 = m_inputs_map[ska_num][MVB2].at("SIntercom_1_SKA2");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_2_SKA2 = m_inputs_map[ska_num][MVB2].at("SIntercom_2_SKA2");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_3_SKA2 = m_inputs_map[ska_num][MVB2].at("SIntercom_3_SKA2");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_4_SKA2 = m_inputs_map[ska_num][MVB2].at("SIntercom_4_SKA2");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_5_SKA2 = m_inputs_map[ska_num][MVB2].at("SIntercom_5_SKA2");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_6_SKA2 = m_inputs_map[ska_num][MVB2].at("SIntercom_6_SKA2");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_7_SKA2 = m_inputs_map[ska_num][MVB2].at("SIntercom_7_SKA2");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_8_SKA2  = m_inputs_map[ska_num][MVB2].at("SIntercom_8_SKA2");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.SIntercom_9_SKA2 = m_inputs_map[ska_num][MVB2].at("SIntercom_9_SKA2");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit130 = m_inputs_map[ska_num][MVB2].at("bit130")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_1_SKA1 = m_inputs_map[ska_num][MVB2].at("CIntercom_1_SKA1");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_2_SKA1 = m_inputs_map[ska_num][MVB2].at("CIntercom_2_SKA1");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_3_SKA1 = m_inputs_map[ska_num][MVB2].at("CIntercom_3_SKA1");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_4_SKA1 = m_inputs_map[ska_num][MVB2].at("CIntercom_4_SKA1");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_5_SKA1 = m_inputs_map[ska_num][MVB2].at("CIntercom_5_SKA1");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_6_SKA1 = m_inputs_map[ska_num][MVB2].at("CIntercom_6_SKA1");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_7_SKA1 = m_inputs_map[ska_num][MVB2].at("CIntercom_7_SKA1");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_8_SKA1 = m_inputs_map[ska_num][MVB2].at("CIntercom_8_SKA1");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_9_SKA1 = m_inputs_map[ska_num][MVB2].at("CIntercom_9_SKA1");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit140 = m_inputs_map[ska_num][MVB2].at("bit140")          ;


    // Assigning values to m_inputs_map for MVB2 from ska_vh_riom_ccu_mvb11_papis2
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_1_OA1 =m_inputs_map[ska_num][MVB2].at("CIntercom_1_OA1");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_2_OA1 =m_inputs_map[ska_num][MVB2].at("CIntercom_2_OA1")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_3_OA1 =m_inputs_map[ska_num][MVB2].at("CIntercom_3_OA1")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_4_OA1 =m_inputs_map[ska_num][MVB2].at("CIntercom_4_OA1")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_5_OA1 =m_inputs_map[ska_num][MVB2].at("CIntercom_5_OA1")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_6_OA1 =m_inputs_map[ska_num][MVB2].at("CIntercom_6_OA1")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_7_OA1 =m_inputs_map[ska_num][MVB2].at("CIntercom_7_OA1")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_8_OA1 =m_inputs_map[ska_num][MVB2].at("CIntercom_8_OA1")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_1_OA2 =m_inputs_map[ska_num][MVB2].at("CIntercom_1_OA2");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_2_OA2 =m_inputs_map[ska_num][MVB2].at("CIntercom_2_OA2") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_3_OA2 =m_inputs_map[ska_num][MVB2].at("CIntercom_3_OA2") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_4_OA2 =m_inputs_map[ska_num][MVB2].at("CIntercom_4_OA2") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_5_OA2 =m_inputs_map[ska_num][MVB2].at("CIntercom_5_OA2") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_6_OA2 =m_inputs_map[ska_num][MVB2].at("CIntercom_6_OA2") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_7_OA2 =m_inputs_map[ska_num][MVB2].at("CIntercom_7_OA2") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_8_OA2 =m_inputs_map[ska_num][MVB2].at("CIntercom_8_OA2") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_1_SKA2 =m_inputs_map[ska_num][MVB2].at("CIntercom_1_SKA2");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_2_SKA2 =m_inputs_map[ska_num][MVB2].at("CIntercom_2_SKA2");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_3_SKA2 =m_inputs_map[ska_num][MVB2].at("CIntercom_3_SKA2");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_4_SKA2 =m_inputs_map[ska_num][MVB2].at("CIntercom_4_SKA2");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_5_SKA2 =m_inputs_map[ska_num][MVB2].at("CIntercom_5_SKA2");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_6_SKA2 =m_inputs_map[ska_num][MVB2].at("CIntercom_6_SKA2");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_7_SKA2 =m_inputs_map[ska_num][MVB2].at("CIntercom_7_SKA2");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_8_SKA2 =m_inputs_map[ska_num][MVB2].at("CIntercom_8_SKA2");
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.CIntercom_9_SKA2 =m_inputs_map[ska_num][MVB2].at("CIntercom_9_SKA2") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit166 =m_inputs_map[ska_num][MVB2].at("bit166")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA1_Network_Failure =m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA1_Network_Failure") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA1_Power_Failure =m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA1_Power_Failure")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA1_Not_Found =m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA1_Not_Found")   ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA1_Busy =m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA1_Busy")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA1_Timeout =m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA1_Timeout")   ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA1_Call1_Not_Reg =m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA1_Call1_Not_Reg") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA1_Call2_Not_Reg =m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA1_Call2_Not_Reg") ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit174 =m_inputs_map[ska_num][MVB2].at("bit174") ;

    // Assigning values to m_inputs_map for MVB2 from ska_vh_riom_ccu_mvb11_papis2
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA1_Network_Failure = m_inputs_map[ska_num][MVB2].at("Amplifier1_OA1_Network_Failure")   ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA1_Power_Failure = m_inputs_map[ska_num][MVB2].at("Amplifier1_OA1_Power_Failure")     ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA1_Not_Found = m_inputs_map[ska_num][MVB2].at("Amplifier1_OA1_Not_Found")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA1_Busy = m_inputs_map[ska_num][MVB2].at("Amplifier1_OA1_Busy")              ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA1_Timeout = m_inputs_map[ska_num][MVB2].at("Amplifier1_OA1_Timeout")           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA1_Call1_Not_Reg = m_inputs_map[ska_num][MVB2].at("Amplifier1_OA1_Call1_Not_Reg")     ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA1_Call2_Not_Reg = m_inputs_map[ska_num][MVB2].at("Amplifier1_OA1_Call2_Not_Reg")     ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit182 = m_inputs_map[ska_num][MVB2].at("bit182")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA2_Network_Failure = m_inputs_map[ska_num][MVB2].at("Amplifier1_OA2_Network_Failure")   ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("Amplifier1_OA2_Power_Failure")     ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA2_Not_Found = m_inputs_map[ska_num][MVB2].at("Amplifier1_OA2_Not_Found")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA2_Busy = m_inputs_map[ska_num][MVB2].at("Amplifier1_OA2_Busy")              ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA2_Timeout = m_inputs_map[ska_num][MVB2].at("Amplifier1_OA2_Timeout")           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA2_Call1_Not_Reg = m_inputs_map[ska_num][MVB2].at("Amplifier1_OA2_Call1_Not_Reg")     ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_OA2_Call2_Not_Reg = m_inputs_map[ska_num][MVB2].at("Amplifier1_OA2_Call2_Not_Reg")     ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit190 = m_inputs_map[ska_num][MVB2].at("bit190")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit191 = m_inputs_map[ska_num][MVB2].at("bit191")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA2_Network_Failure = m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA2_Network_Failure")  ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA2_Power_Failure")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA2_Not_Found = m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA2_Not_Found")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA2_Busy = m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA2_Busy")             ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA2_Timeout = m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA2_Timeout")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA2_Call1_Not_Reg = m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA2_Call1_Not_Reg")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.Amplifier1_SKA2_Call2_Not_Reg = m_inputs_map[ska_num][MVB2].at("Amplifier1_SKA2_Call2_Not_Reg")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit199 = m_inputs_map[ska_num][MVB2].at("bit199")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.NoiseMic_SKA1_Power_Failure = m_inputs_map[ska_num][MVB2].at("NoiseMic_SKA1_Power_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit201 = m_inputs_map[ska_num][MVB2].at("bit201")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.NoiseMic_OA1_Power_Failure = m_inputs_map[ska_num][MVB2].at("NoiseMic_OA1_Power_Failure")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit203 = m_inputs_map[ska_num][MVB2].at("bit203")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.NoiseMic_OA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("NoiseMic_OA2_Power_Failure")       ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit205 = m_inputs_map[ska_num][MVB2].at("bit205")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.NoiseMic_SKA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("NoiseMic_SKA2_Power_Failure")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit207 = m_inputs_map[ska_num][MVB2].at("bit207")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrCCTV_SKA1_Memory_Full = m_inputs_map[ska_num][MVB2].at("PerrCCTV_SKA1_Memory_Full")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrCCTV_SKA1_Reg_Error = m_inputs_map[ska_num][MVB2].at("PerrCCTV_SKA1_Reg_Error")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrCCTV_SKA1_Standby_Error = m_inputs_map[ska_num][MVB2].at("PerrCCTV_SKA1_Standby_Error")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrCCTV_SKA1_Alarm_Error = m_inputs_map[ska_num][MVB2].at("PerrCCTV_SKA1_Alarm_Error")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrCCTV_SKA1_Time_Error = m_inputs_map[ska_num][MVB2].at("PerrCCTV_SKA1_Time_Error")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit213 = m_inputs_map[ska_num][MVB2].at("bit213")                           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrCCTV_SKA2_Memory_Full = m_inputs_map[ska_num][MVB2].at("PerrCCTV_SKA2_Memory_Full")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrCCTV_SKA2_Reg_Error = m_inputs_map[ska_num][MVB2].at("PerrCCTV_SKA2_Reg_Error")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrCCTV_SKA2_Standby_Error = m_inputs_map[ska_num][MVB2].at("PerrCCTV_SKA2_Standby_Error")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrCCTV_SKA2_Alarm_Error = m_inputs_map[ska_num][MVB2].at("PerrCCTV_SKA2_Alarm_Error")        ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrCCTV_SKA2_Time_Error = m_inputs_map[ska_num][MVB2].at("PerrCCTV_SKA2_Time_Error")         ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit219 = m_inputs_map[ska_num][MVB2].at("bit219")                           ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrSwnNecMic_SKA1_Network_Failure = m_inputs_map[ska_num][MVB2].at("PerrSwnNecMic_SKA1_Network_Failure");
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrSwnNecMic_SKA1_Power_Failure = m_inputs_map[ska_num][MVB2].at("PerrSwnNecMic_SKA1_Power_Failure")  ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit222 = m_inputs_map[ska_num][MVB2].at("bit222")                            ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrSwnNecMic_SKA2_Network_Failure = m_inputs_map[ska_num][MVB2].at("PerrSwnNecMic_SKA2_Network_Failure");
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.PerrSwnNecMic_SKA2_Power_Failure = m_inputs_map[ska_num][MVB2].at("PerrSwnNecMic_SKA2_Power_Failure")  ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit225 = m_inputs_map[ska_num][MVB2].at("bit225")                            ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit226 = m_inputs_map[ska_num][MVB2].at("bit226")                            ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit227 = m_inputs_map[ska_num][MVB2].at("bit227")                            ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit228 = m_inputs_map[ska_num][MVB2].at("bit228")                            ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit229 = m_inputs_map[ska_num][MVB2].at("bit229")                            ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit230 = m_inputs_map[ska_num][MVB2].at("bit230")                            ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.bit231 = m_inputs_map[ska_num][MVB2].at("bit231")                            ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.reserved29 = m_inputs_map[ska_num][MVB2].at("reserved29")                        ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.reserved30 = m_inputs_map[ska_num][MVB2].at("reserved30")                        ;
     m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb11_papis2.bits.reserved31 = m_inputs_map[ska_num][MVB2].at("reserved31")                        ;

}

void SKA_PAPIS::set_struct_mvb12(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    // Mapping for GPS and Timestamp variables
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.GPS_longtitude_master =m_inputs_map[ska_num][MVB3].at("GPS_longtitude_master")    ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.GPS_latitude_master =m_inputs_map[ska_num][MVB3].at("GPS_latitude_master")      ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.Timestamp_time =m_inputs_map[ska_num][MVB3].at("Timestamp_time")           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.Timestamp_date  =m_inputs_map[ska_num][MVB3].at("Timestamp_date")           ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.reserved14  =m_inputs_map[ska_num][MVB3].at("reserved14")               ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.reserved15  =m_inputs_map[ska_num][MVB3].at("reserved15")               ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.ServiceID_Byte1  =m_inputs_map[ska_num][MVB3].at("ServiceID_Byte1")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.ServiceID_Byte2  =m_inputs_map[ska_num][MVB3].at("ServiceID_Byte2")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.ServiceID_Byte3  =m_inputs_map[ska_num][MVB3].at("ServiceID_Byte3")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.ServiceID_Byte4  =m_inputs_map[ska_num][MVB3].at("ServiceID_Byte4")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.ServiceID_Byte5  =m_inputs_map[ska_num][MVB3].at("ServiceID_Byte5")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.ServiceID_Byte6  =m_inputs_map[ska_num][MVB3].at("ServiceID_Byte6")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.ServiceID_Byte7  =m_inputs_map[ska_num][MVB3].at("ServiceID_Byte7")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.ServiceID_Byte8  =m_inputs_map[ska_num][MVB3].at("ServiceID_Byte8")          ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.reserved24  =m_inputs_map[ska_num][MVB3].at("reserved24")               ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.reserved25  =m_inputs_map[ska_num][MVB3].at("reserved25")               ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.reserved26  =m_inputs_map[ska_num][MVB3].at("reserved26")               ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.reserved27  =m_inputs_map[ska_num][MVB3].at("reserved27")               ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.reserved28  =m_inputs_map[ska_num][MVB3].at("reserved28")               ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.reserved29  =m_inputs_map[ska_num][MVB3].at("reserved29")               ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.reserved30  =m_inputs_map[ska_num][MVB3].at("reserved30")               ;
    m_ska_x_papis[ska_num].ska_vh_riom_ccu_mvb12_papis3.bits.reserved31  =m_inputs_map[ska_num][MVB3].at("reserved31")               ;
}

void SKA_PAPIS::init_ska_x_mvb10_table(SKA_VEHICLE_NUM vehicle_type)
{
    int ska_num = static_cast<int>(vehicle_type);
    m_inputs_map[ska_num][MVB1] = {
            {"PapisINF_Piscu_SKA1_M", 0}, // byte 0
            {"PapisINF_Piscu_SKA2_M", 0},
            {"bit2", 0},
            {"bit3", 0},
            {"PapisINF_nvr_SKA1_M", 0},
            {"PapisINF_nvr_SKA2_M", 0},
            {"bit6", 0},
            {"bit7", 0},     
            {"Piscu_SKA1_Network_Failure", 0}, // byte 1
            {"Piscu_SKA1_Power_Failure", 0},
            {"Piscu_SKA1_Version_Error", 0},
            {"Piscu_SKA1_OS_Error", 0},
            {"bit12", 0},
            {"bit13", 0},
            {"bit14", 0},
            {"bit15", 0},       
            {"Piscu_SKA2_Network_Failure", 0}, // byte 2
            {"Piscu_SKA2_Power_Failure", 0},
            {"Piscu_SKA2_Version_Error", 0},
            {"Piscu_SKA2_OS_Error", 0},
            {"bit20", 0},
            {"bit21", 0},
            {"bit22", 0},
            {"bit23", 0},
            {"Pis_01_02_SKA1_Error", 0}, // byte 3
            {"Pis_03_04_SKA1_Error", 0},
            {"Pis_05_06_SKA1_Error", 0},
            {"Pis_07_08_SKA1_Error", 0},
            {"Pis_01_02_OA1_Error", 0},
            {"Pis_03_04_OA1_Error", 0},
            {"Pis_05_06_OA1_Error", 0},
            {"Pis_07_08_OA1_Error", 0},
            {"Pis_01_02_OA2_Error", 0}, // byte 4
            {"Pis_03_04_OA2_Error", 0},
            {"Pis_05_06_OA2_Error", 0},
            {"Pis_07_08_OA2_Error", 0},
            {"Pis_01_02_SKA2_Error", 0},
            {"Pis_03_04_SKA2_Error", 0},
            {"Pis_05_06_SKA2_Error", 0},
            {"Pis_07_08_SKA2_Error", 0},
            {"FrontLed1_SKA1_Process_Error", 0}, // byte 5
            {"FrontLed1_SKA1_Version_Error", 0},
            {"FrontLed1_SKA1_Device_Busy", 0},
            {"FrontLed1_SKA1_System_Error", 0},
            {"bit44", 0},
            {"OutLed1_SKA1_Process_Error", 0},
            {"OutLed1_SKA1_Version_Error", 0},
            {"OutLed1_SKA1_Device_Busy", 0},
            {"OutLed1_SKA1_System_Error", 0}, // byte 6
            {"bit49", 0},
            {"OutLed2_SKA1_Process_Error", 0},
            {"OutLed2_SKA1_Version_Error", 0},
            {"OutLed2_SKA1_Device_Busy", 0},
            {"OutLed2_SKA1_System_Error", 0},

            {"bit54", 0},
            {"OutLed1_OA1_Process_Error", 0},
            {"OutLed1_OA1_Version_Error", 0}, // byte 7
            {"OutLed1_OA1_Device_Busy", 0},
            {"OutLed1_OA1_System_Error", 0},
            {"bit59", 0},
            {"OutLed2_OA1_Process_Error", 0},
            {"OutLed2_OA1_Version_Error", 0},
            {"OutLed2_OA1_Device_Busy", 0},
            {"OutLed2_OA1_System_Error", 0},
            {"bit64", 0},
            {"OutLed1_OA2_Process_Error", 0}, // byte 8
            {"OutLed1_OA2_Version_Error", 0},
            {"OutLed1_OA2_Device_Busy", 0},
            {"OutLed1_OA2_System_Error", 0},
            {"bit69", 0},
            {"OutLed2_OA2_Process_Error", 0},
            {"OutLed2_OA2_Version_Error", 0},
            {"OutLed2_OA2_Device_Busy", 0},
            {"OutLed2_OA2_System_Error", 0}, // byte 9
            {"bit74", 0},
            {"FrontLed1_SKA2_Process_Error", 0},
            {"FrontLed1_SKA2_Version_Error", 0},
            {"FrontLed1_SKA2_Device_Busy", 0},
            {"FrontLed1_SKA2_System_Error", 0},
            {"bit79", 0},
            {"OutLed1_SKA2_Process_Error", 0},
            {"OutLed1_SKA2_Version_Error", 0}, // byte 10
            {"OutLed1_SKA2_Device_Busy", 0},
            {"OutLed1_SKA2_System_Error", 0},
            {"bit84", 0},
            {"OutLed2_SKA2_Process_Error", 0},
            {"OutLed2_SKA2_Version_Error", 0},
            {"OutLed2_SKA2_Device_Busy", 0},
            {"OutLed2_SKA2_System_Error", 0},
            {"bit89", 0}, // byte 11

            {"CCTV_HMI_SKA1_Network_Failure", 0},
            {"CCTV_HMI_SKA1_Power_Failure", 0},
            {"CCTV_HMI_SKA1_Server_Error", 0},
            {"bit93", 0},
            {"CCTV_HMI_SKA2_Network_Failure", 0},
            {"CCTV_HMI_SKA2_Power_Failure", 0},
            {"CCTV_HMI_SKA2_Server_Error", 0},
            {"bit97", 0}, // byte 12
            {"F_Cam1_SKA1_Network_Failure", 0},
            {"F_Cam1_SKA1_Power_Failure", 0},
            {"bit100", 0},
            {"C_Cam1_SKA1_Network_Failure", 0},
            {"C_Cam1_SKA1_Power_Failure", 0},
            {"bit103", 0},
            {"PS_Cam1_SKA1_Network_Failure", 0},
            {"PS_Cam1_SKA1_Power_Failure", 0}, // byte 13
            {"bit106", 0},
            {"PS_Cam2_SKA1_Network_Failure", 0},
            {"PS_Cam2_SKA1_Power_Failure", 0},
            {"bit109", 0},
            {"PS_Cam3_SKA1_Network_Failure", 0},
            {"PS_Cam3_SKA1_Power_Failure", 0},
            {"bit112", 0},
            {"PS_Cam4_SKA1_Network_Failure", 0}, // byte 14
            {"PS_Cam4_SKA1_Power_Failure", 0},
            {"bit115", 0},

            {"RL_Cam4_SKA1_Network_Failure", 0},
            {"RL_Cam4_SKA1_Power_Failure", 0},
            {"bit118", 0},
            {"RR_Cam1_SKA1_Network_Failure", 0},
            {"RR_Cam1_SKA1_Power_Failure", 0}, // byte 15
            {"bit121", 0},
            {"PS_Cam1_OA1_Network_Failure", 0},
            {"PS_Cam1_OA1_Power_Failure", 0},
            {"bit124", 0},
            {"PS_Cam2_OA1_Network_Failure", 0},
            {"PS_Cam2_OA1_Power_Failure", 0},
            {"bit127", 0},
            {"PS_Cam3_OA1_Network_Failure", 0}, // byte 16
            {"PS_Cam3_OA1_Power_Failure", 0},
            {"bit130", 0},
            {"PS_Cam4_OA1_Network_Failure", 0},
            {"PS_Cam4_OA1_Power_Failure", 0},
            {"bit133", 0},
            {"PN_Cam1_OA1_Network_Failure", 0},
            {"PN_Cam1_OA1_Power_Failure", 0}, // byte 17
            {"bit136", 0},
            {"PN_Cam1_OA2_Network_Failure", 0},
            {"PN_Cam1_OA2_Power_Failure", 0},
            {"bit139", 0},
            {"PS_Cam1_OA2_Network_Failure", 0},
            {"PS_Cam1_OA2_Power_Failure", 0},
            {"bit142", 0},

            {"PS_Cam2_OA2_Network_Failure", 0},
            {"PS_Cam2_OA2_Power_Failure", 0},
            {"bit145", 0},

            {"PS_Cam3_OA2_Network_Failure", 0},
            {"PS_Cam3_OA2_Power_Failure", 0},
            {"bit148", 0},

            {"PS_Cam4_OA2_Network_Failure", 0},
            {"PS_Cam4_OA2_Power_Failure", 0},



            {"bit151", 0},
            {"F_Cam1_SKA2_Network_Failure", 0}, // byte 19
            {"F_Cam1_SKA2_Power_Failure", 0},
            {"bit154", 0},
            {"C_Cam1_SKA2_Network_Failure", 0},
            {"C_Cam1_SKA2_Power_Failure", 0},
            {"bit157", 0},
            {"PS_Cam1_SKA2_Network_Failure", 0},
            {"PS_Cam1_SKA2_Power_Failure", 0},
            {"bit160", 0}, // byte 20
            {"PS_Cam2_SKA2_Network_Failure", 0},
            {"PS_Cam2_SKA2_Power_Failure", 0},
            {"bit163", 0},
            {"PS_Cam3_SKA2_Network_Failure", 0},
            {"PS_Cam3_SKA2_Power_Failure", 0},
            {"bit166", 0},
            {"PS_Cam4_SKA2_Network_Failure", 0},
            {"PS_Cam4_SKA2_Power_Failure", 0}, // byte 21
            {"bit169", 0},
            {"RL_Cam1_SKA2_Network_Failure", 0},
            {"RL_Cam1_SKA2_Power_Failure", 0},
            {"bit172", 0},
            {"RR_Cam2_SKA2_Network_Failure", 0},
            {"RR_Cam2_SKA2_Power_Failure", 0},
            {"bit175", 0},
            {"Intercom1_SKA1_Network_Failure", 0}, // byte 22
            {"Intercom1_SKA1_Power_Failure", 0},
            {"Intercom1_SKA1_Timeout", 0},
            {"Intercom1_SKA1_Not_Found", 0},
            {"bit180", 0},
            {"Intercom2_SKA1_Network_Failure", 0},
            {"Intercom2_SKA1_Power_Failure", 0},
            {"Intercom2_SKA1_Timeout", 0},
            {"Intercom2_SKA1_Not_Found", 0}, // byte 23
            {"bit185", 0},
            {"Intercom3_SKA1_Network_Failure", 0},
            {"Intercom3_SKA1_Power_Failure", 0},
            {"Intercom3_SKA1_Timeout", 0},
            {"Intercom3_SKA1_Not_Found", 0},
            {"bit190", 0},
            {"bit191", 0},
            {"Intercom4_SKA1_Network_Failure", 0}, // byte 24
            {"Intercom4_SKA1_Power_Failure", 0},
            {"Intercom4_SKA1_Timeout", 0},
            {"Intercom4_SKA1_Not_Found", 0},
            {"bit196", 0},
            {"Intercom5_SKA1_Network_Failure", 0},
            {"Intercom5_SKA1_Power_Failure", 0},
            {"Intercom5_SKA1_Timeout", 0},
            {"Intercom5_SKA1_Not_Found", 0}, // byte 25
            {"bit201", 0},
            {"Intercom6_SKA1_Network_Failure", 0},
            {"Intercom6_SKA1_Power_Failure", 0},
            {"Intercom6_SKA1_Timeout", 0},
            {"Intercom6_SKA1_Not_Found", 0},
            {"bit206", 0},
            {"Intercom7_SKA1_Network_Failure", 0},
            {"Intercom7_SKA1_Power_Failure", 0}, // byte 26
            {"Intercom7_SKA1_Timeout", 0},
            {"Intercom7_SKA1_Not_Found", 0},
            {"bit211", 0},
            {"Intercom8_SKA1_Network_Failure", 0},
            {"Intercom8_SKA1_Power_Failure", 0},
            {"Intercom8_SKA1_Timeout", 0},
            {"Intercom8_SKA1_Not_Found", 0},
            {"bit216", 0}, // byte 27
            {"Intercom9_SKA1_Network_Failure", 0},
            {"Intercom9_SKA1_Power_Failure", 0},
            {"Intercom9_SKA1_Timeout", 0},
            {"Intercom9_SKA1_Not_Found", 0},
            {"bit221", 0},
            {"Intercom1_OA1_Network_Failure", 0},
            {"Intercom1_OA1_Power_Failure", 0},
            {"Intercom1_OA1_Timeout", 0}, // byte 28
            {"Intercom1_OA1_Not_Found", 0},
            {"bit226", 0},
            {"Intercom2_OA1_Network_Failure", 0},
            {"Intercom2_OA1_Power_Failure", 0},
            {"Intercom2_OA1_Timeout", 0},
            {"Intercom2_OA1_Not_Found", 0},
            {"bit231", 0},
            {"Intercom3_OA1_Network_Failure", 0}, // byte 29
            {"Intercom3_OA1_Power_Failure", 0},
            {"Intercom3_OA1_Timeout", 0},
            {"Intercom3_OA1_Not_Found", 0},
            {"bit236", 0},
            {"Intercom4_OA1_Network_Failure", 0},
            {"Intercom4_OA1_Power_Failure", 0},
            {"Intercom4_OA1_Timeout", 0},
            {"Intercom4_OA1_Not_Found", 0}, // byte 30
            {"bit241", 0},
            {"Intercom5_OA1_Network_Failure", 0},
            {"Intercom5_OA1_Power_Failure", 0},
            {"Intercom5_OA1_Timeout", 0},
            {"Intercom5_OA1_Not_Found", 0},
            {"bit246", 0},
            {"Intercom6_OA1_Network_Failure", 0},
            {"Intercom6_OA1_Power_Failure", 0}, // byte 31
            {"Intercom6_OA1_Timeout", 0},
            {"Intercom6_OA1_Not_Found", 0},
            {"bit251", 0},
            {"Intercom7_OA1_Network_Failure", 0},
            {"Intercom7_OA1_Power_Failure", 0},
            {"Intercom7_OA1_Timeout", 0},
            {"Intercom7_OA1_Not_Found", 0},

    };


    /*m_tableWidget[ska_num][MVB1] = new QTableWidget();
    m_tableWidget[ska_num][MVB1]->setColumnCount(2);
    m_tableWidget[ska_num][MVB1]->setRowCount(m_inputs_map[ska_num][MVB1].size());
    m_tableWidget[ska_num][MVB1]->setHorizontalHeaderLabels(table_name[ska_num][MVB1]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[ska_num][MVB1]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[ska_num][MVB1]->setItem(row, 0, item_name);
        m_tableWidget[ska_num][MVB1]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[ska_num][MVB1]->resizeColumnsToContents();*/
    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[ska_num][MVB1].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[ska_num][MVB1] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[ska_num][MVB1]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[ska_num][MVB1]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[ska_num][MVB1]->setItem(row, column, item_name);
        m_tableWidget[ska_num][MVB1]->setItem(row, column + 1, item_val); // Değer

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[ska_num][MVB1]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][MVB1]->columnCount() ;

}

void SKA_PAPIS::init_ska_x_mvb11_table(SKA_VEHICLE_NUM vehicle_type)
{
    int ska_num = static_cast<int>(vehicle_type);

    m_inputs_map[ska_num][MVB2] = {

                                   {"bit0", 0},// byte 0
                                   {"Intercom8_OA1_Network_Failure", 0},
                                   {"Intercom8_OA1_Power_Failure", 0},
                                   {"Intercom8_OA1_Timeout", 0},
                                   {"Intercom8_OA1_Not_Found", 0},
                                   {"bit5", 0},
                                   {"Intercom1_OA2_Network_Failure", 0},
                                   {"Intercom1_OA2_Power_Failure", 0},
                                   // byte 1
                                   {"Intercom1_OA2_Timeout", 0},
                                   {"Intercom1_OA2_Not_Found", 0},
                                   {"bit10", 0},
                                   {"Intercom2_OA2_Network_Failure", 0},
                                   {"Intercom2_OA2_Power_Failure", 0},
                                   {"Intercom2_OA2_Timeout", 0},
                                   {"Intercom2_OA2_Not_Found", 0},
                                   {"bit15", 0},
                                   // byte 2
                                   {"Intercom3_OA2_Network_Failure", 0},
                                   {"Intercom3_OA2_Power_Failure", 0},
                                   {"Intercom3_OA2_Timeout", 0},
                                   {"Intercom3_OA2_Not_Found", 0},
                                   {"bit20", 0},
                                   {"Intercom4_OA2_Network_Failure", 0},
                                   {"Intercom4_OA2_Power_Failure", 0},
                                   {"Intercom4_OA2_Timeout", 0},
                                   // byte 3
                                   {"Intercom4_OA2_Not_Found", 0},
                                   {"bit25", 0},
                                   {"Intercom5_OA2_Network_Failure", 0},
                                   {"Intercom5_OA2_Power_Failure", 0},
                                   {"Intercom5_OA2_Timeout", 0},
                                   {"Intercom5_OA2_Not_Found", 0},
                                   {"bit30", 0},
                                   {"Intercom6_OA2_Network_Failure", 0},


                                           // byte 4
                                           {"Intercom6_OA2_Power_Failure", 0},
                                           {"Intercom6_OA2_Timeout", 0},
                                           {"Intercom6_OA2_Not_Found", 0},
                                           {"bit35", 0},
                                           {"Intercom7_OA2_Network_Failure", 0},
                                           {"Intercom7_OA2_Power_Failure", 0},
                                           {"Intercom7_OA2_Timeout", 0},
                                           {"Intercom7_OA2_Not_Found", 0},


        // byte 5
                                           {"bit40", 0},
                                           {"Intercom8_OA2_Network_Failure", 0},
                                           {"Intercom8_OA2_Power_Failure", 0},
                                           {"Intercom8_OA2_Timeout", 0},
                                           {"Intercom8_OA2_Not_Found", 0},
                                           {"bit45", 0},
                                           {"Intercom1_SKA2_Network_Failure", 0},
                                           {"Intercom1_SKA2_Power_Failure", 0},
                                           // byte 6
                                           {"Intercom1_SKA2_Timeout", 0},
                                           {"Intercom1_SKA2_Not_Found", 0},
                                           {"bit50", 0},
                                           {"Intercom2_SKA2_Network_Failure", 0},
                                           {"Intercom2_SKA2_Power_Failure", 0},
                                           {"Intercom2_SKA2_Timeout", 0},
                                           {"Intercom2_SKA2_Not_Found", 0},
                                           {"bit55", 0},
                                           // byte 7
                                           {"Intercom3_SKA2_Network_Failure", 0},
                                           {"Intercom3_SKA2_Power_Failure", 0},
                                           {"Intercom3_SKA2_Timeout", 0},
                                           {"Intercom3_SKA2_Not_Found", 0},
                                           {"bit60", 0},
                                           {"bit61", 0},
                                           {"bit62", 0},
                                           {"bit63", 0},
                                           // byte 8
                                           {"Intercom4_SKA2_Network_Failure", 0},
                                           {"Intercom4_SKA2_Power_Failure", 0},
                                           {"Intercom4_SKA2_Timeout", 0},
                                           {"Intercom4_SKA2_Not_Found", 0},
                                           {"bit68", 0},
                                           {"Intercom5_SKA2_Network_Failure", 0},
                                           {"Intercom5_SKA2_Power_Failure", 0},
                                           {"Intercom5_SKA2_Timeout", 0},

                                               // byte 9
                                               {"Intercom5_SKA2_Not_Found", 0},
                                               {"bit73", 0},
                                               {"Intercom6_SKA2_Network_Failure", 0},
                                               {"Intercom6_SKA2_Power_Failure", 0},
                                               {"Intercom6_SKA2_Timeout", 0},
                                               {"Intercom6_SKA2_Not_Found", 0},
                                               {"bit78", 0},
                                               {"Intercom7_SKA2_Network_Failure", 0},
                                               // byte 10
                                               {"Intercom7_SKA2_Power_Failure", 0},
                                               {"Intercom7_SKA2_Timeout", 0},
                                               {"Intercom7_SKA2_Not_Found", 0},
                                               {"bit83", 0},


        {"Intercom8_SKA2_Network_Failure", 0},
                                               {"Intercom8_SKA2_Power_Failure", 0},
                                               {"Intercom8_SKA2_Timeout", 0},
                                               {"Intercom8_SKA2_Not_Found", 0},
                                               // byte 11
                                               {"bit88", 0},
                                               {"Intercom9_SKA2_Network_Failure", 0},
                                               {"Intercom9_SKA2_Power_Failure", 0},
                                               {"Intercom9_SKA2_Timeout", 0},
                                               {"Intercom9_SKA2_Not_Found", 0},
                                               {"bit93", 0},
                                               {"SIntercom_1_SKA1", 0},
                                               {"SIntercom_2_SKA1", 0},
                                               // byte 12
                                               {"SIntercom_3_SKA1", 0},
                                               {"SIntercom_4_SKA1", 0},
                                               {"SIntercom_5_SKA1", 0},
                                               {"SIntercom_6_SKA1", 0},
                                               {"SIntercom_7_SKA1", 0},
                                               {"SIntercom_8_SKA1", 0},
                                               {"SIntercom_9_SKA1", 0},
                                               {"bit103", 0},

                                           // byte 13
                                           {"SIntercom_1_OA1", 0},
                                           {"SIntercom_2_OA1", 0},
                                           {"SIntercom_3_OA1", 0},
                                           {"SIntercom_4_OA1", 0},
                                           {"SIntercom_5_OA1", 0},
                                           {"SIntercom_6_OA1", 0},
                                           {"SIntercom_7_OA1", 0},
                                           {"SIntercom_8_OA1", 0},
                                           // byte 14
                                           {"SIntercom_1_OA2", 0},
                                           {"SIntercom_2_OA2", 0},
                                           {"SIntercom_3_OA2", 0},
                                           {"SIntercom_4_OA2", 0},
                                           {"SIntercom_5_OA2", 0},
                                           {"SIntercom_6_OA2", 0},
                                           {"SIntercom_7_OA2", 0},
                                           {"SIntercom_8_OA2", 0},
                                           // byte 15
                                           {"bit120", 0},
                                           {"SIntercom_1_SKA2", 0},
                                           {"SIntercom_2_SKA2", 0},
                                           {"SIntercom_3_SKA2", 0},
                                           {"SIntercom_4_SKA2", 0},
                                           {"SIntercom_5_SKA2", 0},
                                           {"SIntercom_6_SKA2", 0},
                                           {"SIntercom_7_SKA2", 0},
                                           // byte 16
                                           {"SIntercom_8_SKA2", 0},
                                           {"SIntercom_9_SKA2", 0},
                                           {"bit130", 0},
                                           {"CIntercom_1_SKA1", 0},
                                           {"CIntercom_2_SKA1", 0},
                                           {"CIntercom_3_SKA1", 0},
                                           {"CIntercom_4_SKA1", 0},
                                           {"CIntercom_5_SKA1", 0},
                                           // byte 17
                                           {"CIntercom_6_SKA1", 0},
                                           {"CIntercom_7_SKA1", 0},
                                           {"CIntercom_8_SKA1", 0},
                                           {"CIntercom_9_SKA1", 0},
                                           {"bit140", 0},
                                           {"CIntercom_1_OA1", 0},
                                           {"CIntercom_2_OA1", 0},
                                           {"CIntercom_3_OA1", 0},


                                           // byte 18
                                           {"CIntercom_4_OA1", 0},
                                           {"CIntercom_5_OA1", 0},
                                           {"CIntercom_6_OA1", 0},
                                           {"CIntercom_7_OA1", 0},
                                           {"CIntercom_8_OA1", 0},
                                           {"CIntercom_1_OA2", 0},
                                           {"CIntercom_2_OA2", 0},
                                           {"CIntercom_3_OA2", 0},
                                           // byte 19
                                           {"CIntercom_4_OA2", 0},
                                           {"CIntercom_5_OA2", 0},
                                           {"CIntercom_6_OA2", 0},
                                           {"CIntercom_7_OA2", 0},
                                           {"CIntercom_8_OA2", 0},
                                           {"CIntercom_1_SKA2", 0},
                                           {"CIntercom_2_SKA2", 0},
                                           {"CIntercom_3_SKA2", 0},
                                           // byte 20
                                           {"CIntercom_4_SKA2", 0},
                                           {"CIntercom_5_SKA2", 0},
                                           {"CIntercom_6_SKA2", 0},
                                           {"CIntercom_7_SKA2", 0},
                                           {"CIntercom_8_SKA2", 0},
                                           {"CIntercom_9_SKA2", 0},
                                           {"bit166", 0},
                                           {"Amplifier1_SKA1_Network_Failure", 0},
                                           // byte 21
                                           {"Amplifier1_SKA1_Power_Failure", 0},
                                           {"Amplifier1_SKA1_Not_Found", 0},
                                           {"Amplifier1_SKA1_Busy", 0},
                                           {"Amplifier1_SKA1_Timeout", 0},
                                           {"Amplifier1_SKA1_Call1_Not_Reg", 0},
                                           {"Amplifier1_SKA1_Call2_Not_Reg", 0},
                                           {"bit174", 0},
                                           {"Amplifier1_OA1_Network_Failure", 0},
                                           // byte 22
                                           {"Amplifier1_OA1_Power_Failure", 0},
                                           {"Amplifier1_OA1_Not_Found", 0},
                                           {"Amplifier1_OA1_Busy", 0},
                                           {"Amplifier1_OA1_Timeout", 0},
                                           {"Amplifier1_OA1_Call1_Not_Reg", 0},
                                           {"Amplifier1_OA1_Call2_Not_Reg", 0},
                                           {"bit182", 0},
                                           {"Amplifier1_OA2_Network_Failure", 0},
                                           // byte 23
                                           {"Amplifier1_OA2_Power_Failure", 0},
                                           {"Amplifier1_OA2_Not_Found", 0},
                                           {"Amplifier1_OA2_Busy", 0},
                                           {"Amplifier1_OA2_Timeout", 0},
                                           {"Amplifier1_OA2_Call1_Not_Reg", 0},
                                           {"Amplifier1_OA2_Call2_Not_Reg", 0},
                                           {"bit190", 0},
                                           {"bit191", 0},
                                           // byte 24
                                           {"Amplifier1_SKA2_Network_Failure", 0},
                                           {"Amplifier1_SKA2_Power_Failure", 0},
                                           {"Amplifier1_SKA2_Not_Found", 0},
                                           {"Amplifier1_SKA2_Busy", 0},
                                           {"Amplifier1_SKA2_Timeout", 0},
                                           {"Amplifier1_SKA2_Call1_Not_Reg", 0},
                                           {"Amplifier1_SKA2_Call2_Not_Reg", 0},
                                           {"bit199", 0},
                                           // byte 25
                                           {"NoiseMic_SKA1_Power_Failure", 0},
                                           {"bit201", 0},
                                           {"NoiseMic_OA1_Power_Failure", 0},
                                           {"bit203", 0},
                                           {"NoiseMic_OA2_Power_Failure", 0},
                                           {"bit205", 0},
                                           {"NoiseMic_SKA2_Power_Failure", 0},
                                           {"bit207", 0},
                                           // byte 26
                                           {"PerrCCTV_SKA1_Memory_Full", 0},
                                           {"PerrCCTV_SKA1_Reg_Error", 0},
                                           {"PerrCCTV_SKA1_Standby_Error", 0},
                                           {"PerrCCTV_SKA1_Alarm_Error", 0},
                                           {"PerrCCTV_SKA1_Time_Error", 0},
                                           {"bit213", 0},
                                           {"PerrCCTV_SKA2_Memory_Full", 0},
                                           {"PerrCCTV_SKA2_Reg_Error", 0},
                                           // byte 27
                                           {"PerrCCTV_SKA2_Standby_Error", 0},
                                           {"PerrCCTV_SKA2_Alarm_Error", 0},
                                           {"PerrCCTV_SKA2_Time_Error", 0},
                                           {"bit219", 0},
                                           {"PerrSwnNecMic_SKA1_Network_Failure", 0},
                                           {"PerrSwnNecMic_SKA1_Power_Failure", 0},
                                           {"bit222", 0},
                                           {"PerrSwnNecMic_SKA2_Network_Failure", 0},
                                           // byte 28
                                           {"PerrSwnNecMic_SKA2_Power_Failure", 0},
                                           {"bit225", 0},
                                           {"bit226", 0},
                                           {"bit227", 0},
                                           {"bit228", 0},
                                           {"bit229", 0},
                                           {"bit230", 0},
                                           {"bit231", 0},
                                           // byte 29-31
                                           {"reserved29", 0},
                                           {"reserved30", 0},
                                           {"reserved31", 0},
                                           };


    /*m_tableWidget[ska_num][MVB2] = new QTableWidget();
    m_tableWidget[ska_num][MVB2]->setColumnCount(2);
    m_tableWidget[ska_num][MVB2]->setRowCount(m_inputs_map[ska_num][MVB2].size());
    m_tableWidget[ska_num][MVB2]->setHorizontalHeaderLabels(table_name[ska_num][MVB2]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[ska_num][MVB2]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[ska_num][MVB2]->setItem(row, 0, item_name);
        m_tableWidget[ska_num][MVB2]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[ska_num][MVB2]->resizeColumnsToContents();*/

    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[ska_num][MVB2].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[ska_num][MVB2] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[ska_num][MVB2]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[ska_num][MVB2]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[ska_num][MVB2]->setItem(row, column, item_name);
        m_tableWidget[ska_num][MVB2]->setItem(row, column + 1, item_val); // Değer

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[ska_num][MVB2]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][MVB2]->columnCount() ;

}


void SKA_PAPIS::init_ska_x_mvb12_table(SKA_VEHICLE_NUM vehicle_type)
{
    int ska_num = static_cast<int>(vehicle_type);

    m_inputs_map[ska_num][MVB3] = {
                                   // byte 0
                                   {"GPS_longtitude_master", 0},
                                   // byte 4
                                   {"GPS_latitude_master", 0},
                                   // byte 8
                                   {"Timestamp_time", 0},
                                   // byte 12
                                   {"Timestamp_date", 0},
                                   {"reserved14", 0},
                                   {"reserved15", 0},
                                   // byte 16
                                   {"ServiceID_Byte1", 0},
                                   {"ServiceID_Byte2", 0},
                                   {"ServiceID_Byte3", 0},
                                   {"ServiceID_Byte4", 0},
                                   {"ServiceID_Byte5", 0},
                                   {"ServiceID_Byte6", 0},
                                   {"ServiceID_Byte7", 0},
                                   {"ServiceID_Byte8", 0},
                                   // byte 24-31
                                   {"reserved24", 0},
                                   {"reserved25", 0},
                                   {"reserved26", 0},
                                   {"reserved27", 0},
                                   {"reserved28", 0},
                                   {"reserved29", 0},
                                   {"reserved30", 0},
                                   {"reserved31", 0},
                                   };

    /*m_tableWidget[ska_num][MVB3] = new QTableWidget();
    m_tableWidget[ska_num][MVB3]->setColumnCount(2);
    m_tableWidget[ska_num][MVB3]->setRowCount(m_inputs_map[ska_num][MVB3].size());
    m_tableWidget[ska_num][MVB3]->setHorizontalHeaderLabels(table_name[ska_num][MVB3]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[ska_num][MVB3]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[ska_num][MVB3]->setItem(row, 0, item_name);
        m_tableWidget[ska_num][MVB3]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[ska_num][MVB3]->resizeColumnsToContents();*/
    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[ska_num][MVB3].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[ska_num][MVB3] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[ska_num][MVB3]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[ska_num][MVB3]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[ska_num][MVB3]->setItem(row, column, item_name);
        m_tableWidget[ska_num][MVB3]->setItem(row, column + 1, item_val); // Değer

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[ska_num][MVB3]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][MVB3]->columnCount() ;

}
