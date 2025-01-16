#include "ccu_outputs.h"

#include <QFile>
#include <QMessageBox>
#include <QIntValidator>
#include <QDebug>
#include <QTableWidget>

namespace OUT {
    CCU_Outputs::CCU_Outputs(QObject *parent)
        :QObject{parent},
    m_ska_ccu_vh_riom_mvb1_d_ptr(new Ska_ccu_vh_riom_mvb1_d(this)),
    m_ska_ccu_dd_riom_mvb1_d_outputs_ptr(new Ska_Ccu_DD_Riom_Mvb1_d_Outputs(this)),
    m_oa_ccu_vh_riom_mvb1_d_outputs_ptr(new Oa_Ccu_Vh_Riom_Mvb1_d_Outputs(this)),
    m_ska_ccu_global_out_mvb1_ptr(new Ska_Ccu_Global_Out_Mvb1(this)),
    m_ccu_to_all_bcus_ptr(new Ccu_To_All_Bcus(this)),
    m_ska_ccu_vh_riom_mvb2_dcu_hvac_fdu_ptr(new Ska_Ccu_Vh_Riom_Mvb2_Dcu),
    m_ska_vh_riom_outputs_ptr(new Ska_Vh_Riom_Outputs),
    m_oa_vh_riom_outputs_ptr(new Oa_Vh_Riom_Outputs),
    m_ccu_to_oax_etcs_ptr(new Ccu_To_Oax_Etcs),
    m_ccu_to_all_etcs_ptr(new Ccu_To_All_Etcs),
    m_ccu_to_all_tcus_ptr(new Ccu_To_All_TCUS),
    m_ccu_to_all_apus_ptr(new Ccu_To_All_APUS),
    m_Ccu_To_All_Jrus_1_ptr(new Ccu_To_All_Jrus_1(this)),
    m_Ccu_To_All_Jrus_2_ptr(new Ccu_To_All_Jrus_2(this)),
    m_Ccu_To_All_Jrus_3_ptr(new Ccu_To_All_Jrus_3(this)),
    m_Ccu_To_All_Jrus_4_ptr(new Ccu_To_All_Jrus_4(this)),
    m_Ccu_To_All_Jrus_5_ptr(new Ccu_To_All_Jrus_5(this)),
    m_ska_ccu_do_card_ptr(new Ska_Ccu_Do_Card(this)),
    m_ska_ccu_vh_riom_mvb1_d_force_ptr(new Ska_ccu_vh_riom_mvb1_d(this)),
    m_ska_ccu_dd_riom_mvb1_d_outputs_force_ptr(new Ska_Ccu_DD_Riom_Mvb1_d_Outputs(this)),
    m_oa_ccu_vh_riom_mvb1_d_outputs_force_ptr(new Oa_Ccu_Vh_Riom_Mvb1_d_Outputs(this)),
    m_ska_ccu_global_out_mvb1_force_ptr(new Ska_Ccu_Global_Out_Mvb1(this)),
    m_ccu_to_all_bcus_force_ptr(new Ccu_To_All_Bcus(this)),
    m_ska_ccu_vh_riom_mvb2_dcu_hvac_fdu_force_ptr(new Ska_Ccu_Vh_Riom_Mvb2_Dcu),
    m_ska_vh_riom_outputs_force_ptr(new Ska_Vh_Riom_Outputs),
    m_oa_vh_riom_outputs_force_ptr(new Oa_Vh_Riom_Outputs),
    m_ccu_to_oax_etcs_force_ptr(new Ccu_To_Oax_Etcs),
    m_ccu_to_all_etcs_force_ptr(new Ccu_To_All_Etcs),
    m_ccu_to_all_tcus_force_ptr(new Ccu_To_All_TCUS),
    m_ccu_to_all_apus_force_ptr(new Ccu_To_All_APUS),
    m_ccu_to_all_rioms_force_ptr(new Ccu_All_Rioms_Output)
    {





    }

    CCU_Outputs::~CCU_Outputs()
    {

    }

}

