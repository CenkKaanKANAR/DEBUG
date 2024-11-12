#ifndef MESSAGECONFIG_H
#define MESSAGECONFIG_H
#include <QTableWidget>
#include <QWidget>
#include "emulator_common.h"
#include <QBoxLayout>
#include <QToolBar>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QPushButton>


enum class CheckBoxSelection
{
    CHECK_BOX_SELECTED,
    CHECK_BOX_UNSELECTED
};

namespace Ui {
class MessageConfig;
}

class MessageConfig : public QWidget
{
    Q_OBJECT

public:
    explicit MessageConfig(QWidget *parent = nullptr);
    ~MessageConfig();

    void initConfiguration();
    void initMessageConfigBox();
    void updateEmulatorConfigStruct();


    emulator_config getMessageConfigStruct();

    bool isEmulConnected() const {
        return m_emulator_config.bits.emul_connected;
    }

    bool isEmulInConfigMode() const {
        return m_emulator_config.bits.emul_in_config_mode;
    }

    bool isEmulReady() const {
        return m_emulator_config.bits.emul_ready;
    }



    bool isReserved3Set() const {
        return m_emulator_config.bits.reserved3;
    }
    bool isReserved4Set() const {
        return m_emulator_config.bits.reserved4;
    }
    bool isReserved5Set() const {
        return m_emulator_config.bits.reserved5;
    }

    bool isSkaInputSet() const {
        return m_emulator_config.bits.ska_input;
    }



    /*bool isSka1DiCardSet() const {
        return m_emulator_config.bits.ska1_di_card;
    }*/

    bool isSka1DdinputsMSet() const {
        return m_emulator_config.bits.ska1_ddinputs_m;
    }

    bool isSka1VhinputsMSet() const {
        return m_emulator_config.bits.ska1_vhinputs_m;
    }

    /*bool isSka2DiCardSet() const {
        return m_emulator_config.bits.ska2_di_card;
    }*/

    bool isSka2DdinputsMSet() const {
        return m_emulator_config.bits.ska2_ddinputs_m;
    }

    bool isSka2VhinputsMSet() const {
        return m_emulator_config.bits.ska2_vhinputs_m;
    }


    bool isOa1VhinputsMSet() const {
        return m_emulator_config.bits.oa1_vhinputs_m;
    }


    bool isOa2VhinputsMSet() const {
        return m_emulator_config.bits.oa2_vhinputs_m;
    }


    bool isSka1DcuSet() const {
        return m_emulator_config.bits.ska1_dcu;
    }

    bool isSka2DcuSet() const {
        return m_emulator_config.bits.ska2_dcu;
    }

    bool isOa1DcuSet() const {
        return m_emulator_config.bits.oa1_dcu;
    }

    bool isOa2DcuSet() const {
        return m_emulator_config.bits.oa2_dcu;
    }

    bool isSka1FdsSet() const {
        return m_emulator_config.bits.ska1_fds;
    }

    bool isSka2FdsSet() const {
        return m_emulator_config.bits.ska2_fds;
    }

    /*bool isSka1HvacDrSet() const {
        return m_emulator_config.bits.ska1_hvac_dr;
    }*/

    /*bool isSka2HvacDrSet() const {
        return m_emulator_config.bits.ska2_hvac_dr;
    }*/

    /*bool isSka1HvacPsSet() const {
        return m_emulator_config.bits.ska1_hvac_ps;
    }*/

    /*bool isSka2HvacPsSet() const {
        return m_emulator_config.bits.ska2_hvac_ps;
    }*/

    /*bool isOa1HvacPsSet() const {
        return m_emulator_config.bits.oa1_hvac_ps;
    }*/

    /*bool isOa2HvacPsSet() const {
        return m_emulator_config.bits.oa2_hvac_ps;
    }*/

    bool isSka1PapisSet() const {
        return m_emulator_config.bits.ska1_papis;
    }

    bool isSka2PapisSet() const {
        return m_emulator_config.bits.ska2_papis;
    }

    bool isSka1AtsSet() const {
        return m_emulator_config.bits.ska1_ats;
    }

    bool isSka2AtsSet() const {
        return m_emulator_config.bits.ska2_ats;
    }

    bool isSka1BcuSet() const {
        return m_emulator_config.bits.ska1_bcu;
    }

    bool isSka2BcuSet() const {
        return m_emulator_config.bits.ska2_bcu;
    }

    bool isOa1BcuSet() const {
        return m_emulator_config.bits.oa1_bcu;
    }

    bool isOa2BcuSet() const {
        return m_emulator_config.bits.oa2_bcu;
    }

    bool isOa1EtcsSet() const {
        return m_emulator_config.bits.oa1_etcs;
    }

    bool isOa2EtcsSet() const {
        return m_emulator_config.bits.oa2_etcs;
    }

    bool isOa1JruSet() const {
        return m_emulator_config.bits.oa1_jru;
    }

    bool isOa2JruSet() const {
        return m_emulator_config.bits.oa2_jru;
    }

    bool isOa1ApuSet() const {
        return m_emulator_config.bits.oa1_apu;
    }

    bool isOa2ApuSet() const {
        return m_emulator_config.bits.oa2_apu;
    }

    bool isSka1Tcu1Set() const {
        return m_emulator_config.bits.ska1_tcu1;
    }

    bool isSka2Tcu1Set() const {
        return m_emulator_config.bits.ska2_tcu1;
    }

    bool isSka1Tcu2Set() const {
        return m_emulator_config.bits.ska1_tcu2;
    }

    bool isSka2Tcu2Set() const {
        return m_emulator_config.bits.ska2_tcu2;
    }

    bool isSka1WtbgwSet() const {
        return m_emulator_config.bits.ska1_wtbgw;
    }

    bool isSka2WtbgwSet() const {
        return m_emulator_config.bits.ska2_wtbgw;
    }

    bool isSka1HmiSet() const {
        return m_emulator_config.bits.ska1_hmi;
    }

    bool isSka2HmiSet() const {
        return m_emulator_config.bits.ska2_hmi;
    }

   /* bool isOa1DamSet() const {//
        return m_emulator_config.bits.oa1_dam;
    }

    bool isOa2DamSet() const {//
        return m_emulator_config.bits.oa2_dam;
    }
    */
    bool isSka1HvacSet() const {//
        return m_emulator_config.bits.ska1_hvac;
    }

    bool isSka2HvacSet() const {//
        return m_emulator_config.bits.ska2_hvac;
    }

    bool isOa1HvacSet() const {//
        return m_emulator_config.bits.oa1_hvac;
    }

    bool isOa2HvacSet() const {//
        return m_emulator_config.bits.oa2_hvac;
    }

    void update_check_states();

    void applyMainwindowStyleSheetConfiguration();


private slots:

    void on_pushButton_check_all_clicked();

private:

    Ui::MessageConfig *ui;
    QMap<QString, QCheckBox*> checkBoxMap;
    QVector<QString>m_message_config_names;
    bool m_checkbox_control_button_status;

    struct emulator_config m_emulator_config;
    QToolBar * toolbar = nullptr;

    CheckBoxSelection clearCheckBoxState;
};

#endif // MESSAGECONFIG_H
