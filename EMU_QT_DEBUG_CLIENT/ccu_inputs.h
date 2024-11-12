#ifndef CCU_INPUTS_H
#define CCU_INPUTS_H
#include "shm_data_gaziray.h"
#include <QObject>
#include <QList>
#include <QPair>
#include <QTableWidget>
#include "ccu_inputs/ska_ccu_di_card.h"
#include "ccu_inputs/ska_ats.h"
#include "ccu_inputs/ska_bcu.h"
#include "ccu_inputs/oa_vh_riom.h"
#include "ccu_inputs/oa_dcu.h"
#include "ccu_inputs/oa_bcu.h"
#include "ccu_inputs/ska_dd_riom.h"
#include "ccu_inputs/ska_vh_riom.h"
#include "ccu_inputs/ska_dcu.h"
#include "ccu_inputs/ska_fds.h"
#include "ccu_inputs/ska_papis.h"
#include "ccu_inputs/oa_etcs.h"
#include "ccu_inputs/oa_jru.h"
#include "ccu_inputs/oa_dam.h"
#include "ccu_inputs/ska_hvac.h"
#include "ccu_inputs/oa_hvac.h"


namespace IN{


class CCU_Inputs : public QObject
{
    Q_OBJECT
public:
    explicit CCU_Inputs(QObject *parent = nullptr);
    ~CCU_Inputs();


    Ska_Ccu_Di_Card& getSkaCcuDiCard(){
        return  m_ska_ccu_di_card;
    }

    SKA_DD_RIOM& getSkaDDRiom() {
        return  m_ska_dd_riom;
    }

    SKA_VH_RIOM& getSkaVhRiom()  {
        return  m_ska_vh_riom;
    }

    Ska_Ats& getSkaAts() {
        return m_ska_ats;
    }

    Ska_Bcu& getSkaBcu() {
        return  m_ska_bcu;
    }

    Oa_Vh_Riom& getOaVhRiom() {
        return  m_oa_vh_riom;
    }

    SKA_DCU& getSkaDcu() {
        return  m_ska_dcu;
    }

    SKA_FDS& getSkaFds() {
        return  m_ska_fds;
    }

    SKA_PAPIS& getSkaPapis() {
        return  m_ska_papis;
    }


    OA_DCU& getOaDcu() {
        return  m_oa_dcu;
    }

     OA_BCU& getOaBcu() {
        return  m_oa_bcu;
    }

    Oa_Etcs& getOaEtcs() {
        return  m_oa_etcs;
    }

    Oa_Jru& getOaJru() {
        return  m_oa_jru;
    }

    Oa_Dam& getOaDam() {
        return  m_oa_dam;
    }

    Ska_Hvac& getSkaHvac() {
        return  m_ska_hvac;
    }

    Oa_Hvac& getOaHvac() {
        return  m_oa_hvac;
    }
private:

    //struct ska_ccu_input ska_ccu_input_w;
    Ska_Ccu_Di_Card m_ska_ccu_di_card;
    SKA_DD_RIOM m_ska_dd_riom;
    SKA_VH_RIOM m_ska_vh_riom;
    SKA_DCU m_ska_dcu;
    SKA_FDS m_ska_fds;
    SKA_PAPIS m_ska_papis;
    Ska_Ats m_ska_ats;
    Ska_Bcu m_ska_bcu;
    Oa_Vh_Riom m_oa_vh_riom;
    OA_DCU m_oa_dcu;
    OA_BCU m_oa_bcu;
    Oa_Etcs m_oa_etcs;
    Oa_Jru m_oa_jru;
    Oa_Dam m_oa_dam;
    Ska_Hvac m_ska_hvac;
    Oa_Hvac m_oa_hvac;
signals:

};
}
#endif // CCU_INPUTS_H
