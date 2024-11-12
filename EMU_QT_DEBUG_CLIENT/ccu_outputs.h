#ifndef CCU_OUTPUTS_H
#define CCU_OUTPUTS_H
#include "shm_data_gaziray.h"
#include <QDialog>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QScrollArea>
//#include "shm_data.h"

#include <QPair>
#include <QJsonObject>
#include <QJsonDocument>
#include <QToolBar>
#include <QFileDialog>

#include "ccu_outputs/ska_ccu_global_out_mvb1.h"
#include "ccu_outputs/ska_ccu_global_out_mvb2.h"

#include "ccu_outputs/ska_ccu_to_all_rioms_mvb1.h"
#include "ccu_outputs/ska_ccu_to_all_rioms_mvb2.h"

#include "ccu_outputs/ccu_to_all_jrus_1.h"
#include "ccu_outputs/ccu_to_all_jrus_2.h"
#include "ccu_outputs/ccu_to_all_jrus_3.h"
#include "ccu_outputs/ccu_to_all_jrus_4.h"
#include "ccu_outputs/ccu_to_all_jrus_5.h"


#include "ccu_outputs/ska_ccu_vh_riom_mvb1_d.h"
#include "ccu_outputs/ska_ccu_vh_riom_mvb2_dcu.h"
#include "ccu_outputs/ska_ccu_dd_riom_mvb1_d_outputs.h"
#include "ccu_outputs/oa_ccu_vh_riom_mvb1_d_outputs.h"
#include "ccu_outputs/oa_ccu_vh_riom_mvb2_dcu.h"
#include "ccu_outputs/ccu_to_oax_etcs.h"
#include "ccu_outputs/ccu_to_all_bcus.h"
#include "ccu_outputs/ccu_to_all_etcs.h"
#include "ccu_outputs/ska_ccu_do_card.h"

namespace OUT {


class CCU_Outputs: public QObject
{
    Q_OBJECT
public:
    explicit CCU_Outputs(QObject *parent = nullptr);
    ~CCU_Outputs();

    Ska_Ccu_Global_Out_Mvb1* get_Ska_Ccu_Global_Out_Mvb1()
    {
        return m_ska_ccu_global_out_mvb1_ptr;
    }

    Ska_Ccu_Global_Out_Mvb2* get_Ska_Ccu_Global_Out_Mvb2()
    {
        return m_ska_ccu_global_out_mvb2_ptr;
    }

    Ska_Ccu_To_All_Rioms_Mvb1* get_Ska_Ccu_To_All_Rioms_Mvb1()
    {
        return m_ska_ccu_to_all_rioms_mvb1_ptr;
    }

    Ska_Ccu_To_All_Rioms_Mvb2* get_Ska_Ccu_To_All_Rioms_Mvb2()
    {
        return m_ska_ccu_to_all_rioms_mvb2_ptr;
    }
    Ska_ccu_vh_riom_mvb1_d* get_Ska_ccu_vh_riom_mvb1_d() {
        return m_ska_ccu_vh_riom_mvb1_d_ptr;
    }

    Ska_Ccu_DD_Riom_Mvb1_d_Outputs* get_Ska_Ccu_DD_Riom_Mvb1_d_Outputs()
    {
        return m_ska_ccu_dd_riom_mvb1_d_outputs_ptr;
    }

    Ska_Ccu_Vh_Riom_Mvb2_Dcu* get_Ska_Ccu_Vh_Riom_Mvb2_Dcu()
    {
        return m_ska_ccu_vh_riom_mvb2_dcu_ptr;
    }

    Oa_Ccu_Vh_Riom_Mvb1_d_Outputs* get_Oa_Ccu_Vh_Riom_Mvb1_d_Outputs()
    {
        return m_oa_ccu_vh_riom_mvb1_d_outputs_ptr;
    }

    Oa_Ccu_Vh_Riom_Mvb2_Dcu* get_Oa_Ccu_Vh_Riom_Mvb2_Dcu()
    {
        return m_oa_ccu_vh_riom_mvb2_dcu_ptr;
    }

    Ccu_To_Oax_Etcs* get_Ccu_To_Oax_Etcs()
    {
        return m_ccu_to_oax_etcs_ptr;
    }

    Ccu_To_All_Bcus* get_Ccu_To_All_Bcus()
    {
        return m_ccu_to_all_bcus_ptr;
    }
    Ccu_To_All_Etcs* get_Ccu_To_All_Etcs()
    {
        return m_ccu_to_all_etcs_ptr;
    }

    Ccu_To_All_Jrus_1* get_Ccu_To_All_Jrus_1()
    {
        return m_Ccu_To_All_Jrus_1_ptr;
    }
    Ccu_To_All_Jrus_2* get_Ccu_To_All_Jrus_2()
    {
        return m_Ccu_To_All_Jrus_2_ptr;
    }
    Ccu_To_All_Jrus_3* get_Ccu_To_All_Jrus_3()
    {
        return m_Ccu_To_All_Jrus_3_ptr;
    }
    Ccu_To_All_Jrus_4* get_Ccu_To_All_Jrus_4()
    {
        return m_Ccu_To_All_Jrus_4_ptr;
    }
    Ccu_To_All_Jrus_5* get_Ccu_To_All_Jrus_5()
    {
        return m_Ccu_To_All_Jrus_5_ptr;
    }
    Ska_Ccu_Do_Card *get_Ska_Ccu_Do_Card()
    {
        return m_ska_ccu_do_card_ptr;
    }

private:

    Ska_Ccu_Global_Out_Mvb1* m_ska_ccu_global_out_mvb1_ptr;
    Ska_Ccu_Global_Out_Mvb2* m_ska_ccu_global_out_mvb2_ptr;

    Ska_Ccu_To_All_Rioms_Mvb1* m_ska_ccu_to_all_rioms_mvb1_ptr;
    Ska_Ccu_To_All_Rioms_Mvb2* m_ska_ccu_to_all_rioms_mvb2_ptr;

    Ska_ccu_vh_riom_mvb1_d* m_ska_ccu_vh_riom_mvb1_d_ptr;
    Ska_Ccu_DD_Riom_Mvb1_d_Outputs *m_ska_ccu_dd_riom_mvb1_d_outputs_ptr;
    Ska_Ccu_Vh_Riom_Mvb2_Dcu* m_ska_ccu_vh_riom_mvb2_dcu_ptr;
    Oa_Ccu_Vh_Riom_Mvb1_d_Outputs* m_oa_ccu_vh_riom_mvb1_d_outputs_ptr;
    Oa_Ccu_Vh_Riom_Mvb2_Dcu* m_oa_ccu_vh_riom_mvb2_dcu_ptr;
    Ccu_To_Oax_Etcs* m_ccu_to_oax_etcs_ptr;
    Ccu_To_All_Bcus* m_ccu_to_all_bcus_ptr;
    Ccu_To_All_Etcs* m_ccu_to_all_etcs_ptr;

    Ccu_To_All_Jrus_1* m_Ccu_To_All_Jrus_1_ptr;
    Ccu_To_All_Jrus_2* m_Ccu_To_All_Jrus_2_ptr;
    Ccu_To_All_Jrus_3* m_Ccu_To_All_Jrus_3_ptr;
    Ccu_To_All_Jrus_4* m_Ccu_To_All_Jrus_4_ptr;
    Ccu_To_All_Jrus_5* m_Ccu_To_All_Jrus_5_ptr;

    Ska_Ccu_Do_Card* m_ska_ccu_do_card_ptr;

};
}
#endif // CCU_Outputs_H
