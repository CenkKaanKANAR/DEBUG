TEMPLATE = app
TARGET = EMU_QT_DEBUG_CLIENT
QT       += core gui  network  serialbus


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DriverDeskPanels/DriverPanels/panel12.cpp \
    DriverDeskPanels/DriverPanels/panel13.cpp \
    DriverDeskPanels/DriverPanels/panel14.cpp \
    DriverDeskPanels/DriverPanels/panel16.cpp \
    DriverDeskPanels/DriverPanels/panel22.cpp \
    DriverDeskPanels/DriverPanels/panel8.cpp \
    DriverDeskPanels/DriverPanels/panel9.cpp \
    DriverDeskPanels/DriverPanels/panelx.cpp \
    DriverDeskPanels/DriverPanels/panely.cpp \
    DriverDeskPanels/driverpanel.cpp \
    DriverDeskPanels/led/ledindicator.cpp \
    DriverDeskPanels/speedGauge/qcgaugewidget.cpp \
    DriverDeskPanels/switch/switch.cpp \
    ReadShmDialog.cpp \
    ccu_inputs.cpp \
    ccu_inputs/oa_bcu.cpp \
    ccu_inputs/oa_dam.cpp \
    ccu_inputs/oa_dcu.cpp \
    ccu_inputs/oa_etcs.cpp \
    ccu_inputs/oa_hvac.cpp \
    ccu_inputs/oa_jru.cpp \
    ccu_inputs/oa_vh_riom.cpp \
    ccu_inputs/ska_ats.cpp \
    ccu_inputs/ska_bcu.cpp \
    ccu_inputs/ska_ccu_di_card.cpp \
    ccu_inputs/ska_dcu.cpp \
    ccu_inputs/ska_dd_riom.cpp \
    ccu_inputs/ska_fds.cpp \
    ccu_inputs/ska_hvac.cpp \
    ccu_inputs/ska_papis.cpp \
    ccu_inputs/ska_vh_riom.cpp \
    ccu_outputs.cpp \
    ccu_outputs/ccu_to_all_bcus.cpp \
    ccu_outputs/ccu_to_all_etcs.cpp \
    ccu_outputs/ccu_to_all_jrus_1.cpp \
    ccu_outputs/ccu_to_all_jrus_2.cpp \
    ccu_outputs/ccu_to_all_jrus_3.cpp \
    ccu_outputs/ccu_to_all_jrus_4.cpp \
    ccu_outputs/ccu_to_all_jrus_5.cpp \
    ccu_outputs/ccu_to_oax_etcs.cpp \
    ccu_outputs/oa_ccu_vh_riom_mvb1_d_outputs.cpp \
    ccu_outputs/oa_ccu_vh_riom_mvb2_dcu.cpp \
    ccu_outputs/ska_ccu_dd_riom_mvb1_d_outputs.cpp \
    ccu_outputs/ska_ccu_do_card.cpp \
    ccu_outputs/ska_ccu_global_out_mvb1.cpp \
    ccu_outputs/ska_ccu_global_out_mvb2.cpp \
    ccu_outputs/ska_ccu_to_all_rioms_mvb1.cpp \
    ccu_outputs/ska_ccu_to_all_rioms_mvb2.cpp \
    ccu_outputs/ska_ccu_vh_riom_mvb1_d.cpp \
    ccu_outputs/ska_ccu_vh_riom_mvb2_dcu.cpp \
    ccu_table.cpp \
    ccutablehandler.cpp \
    main.cpp \
    mainwindow.cpp \
    messageconfig.cpp \
    qledlabel.cpp \
    udphandler.cpp \
    utils.cpp

HEADERS += \
    DriverDeskPanels/DriverPanels/panel12.h \
    DriverDeskPanels/DriverPanels/panel13.h \
    DriverDeskPanels/DriverPanels/panel14.h \
    DriverDeskPanels/DriverPanels/panel16.h \
    DriverDeskPanels/DriverPanels/panel22.h \
    DriverDeskPanels/DriverPanels/panel8.h \
    DriverDeskPanels/DriverPanels/panel9.h \
    DriverDeskPanels/DriverPanels/panelx.h \
    DriverDeskPanels/DriverPanels/panely.h \
    DriverDeskPanels/driverpanel.h \
    DriverDeskPanels/led/ledindicator.h \
    DriverDeskPanels/speedGauge/qcgaugewidget.h \
    DriverDeskPanels/switch/switch.h \
    ReadShmDialog.h \
    ccu_inputs.h \
    ccu_inputs/oa_bcu.h \
    ccu_inputs/oa_dam.h \
    ccu_inputs/oa_dcu.h \
    ccu_inputs/oa_etcs.h \
    ccu_inputs/oa_hvac.h \
    ccu_inputs/oa_jru.h \
    ccu_inputs/oa_vh_riom.h \
    ccu_inputs/ska_ats.h \
    ccu_inputs/ska_bcu.h \
    ccu_inputs/ska_ccu_di_card.h \
    ccu_inputs/ska_dcu.h \
    ccu_inputs/ska_dd_riom.h \
    ccu_inputs/ska_fds.h \
    ccu_inputs/ska_hvac.h \
    ccu_inputs/ska_papis.h \
    ccu_inputs/ska_vh_riom.h \
    ccu_outputs.h \
    ccu_outputs/ccu_to_all_bcus.h \
    ccu_outputs/ccu_to_all_etcs.h \
    ccu_outputs/ccu_to_all_jrus_1.h \
    ccu_outputs/ccu_to_all_jrus_2.h \
    ccu_outputs/ccu_to_all_jrus_3.h \
    ccu_outputs/ccu_to_all_jrus_4.h \
    ccu_outputs/ccu_to_all_jrus_5.h \
    ccu_outputs/ccu_to_oax_etcs.h \
    ccu_outputs/oa_ccu_vh_riom_mvb1_d_outputs.h \
    ccu_outputs/oa_ccu_vh_riom_mvb2_dcu.h \
    ccu_outputs/ska_ccu_dd_riom_mvb1_d_outputs.h \
    ccu_outputs/ska_ccu_do_card.h \
    ccu_outputs/ska_ccu_global_out_mvb1.h \
    ccu_outputs/ska_ccu_global_out_mvb2.h \
    ccu_outputs/ska_ccu_to_all_rioms_mvb1.h \
    ccu_outputs/ska_ccu_to_all_rioms_mvb2.h \
    ccu_outputs/ska_ccu_vh_riom_mvb1_d.h \
    ccu_outputs/ska_ccu_vh_riom_mvb2_dcu.h \
    ccu_table.h \
    ccutablehandler.h \
    emulator_common.h \
    mainwindow.h \
    messageconfig.h \
    mvb_ports.h \
    qledlabel.h \
    shm_data_gaziray.h \
    udphandler.h \
    utils.h

FORMS += \
    DriverDeskPanels/DriverPanels/panel12.ui \
    DriverDeskPanels/DriverPanels/panel13.ui \
    DriverDeskPanels/DriverPanels/panel14.ui \
    DriverDeskPanels/DriverPanels/panel16.ui \
    DriverDeskPanels/DriverPanels/panel22.ui \
    DriverDeskPanels/DriverPanels/panel8.ui \
    DriverDeskPanels/DriverPanels/panel9.ui \
    DriverDeskPanels/DriverPanels/panelx.ui \
    DriverDeskPanels/DriverPanels/panely.ui \
    DriverDeskPanels/driverpanel.ui \
    ReadShmDialog.ui \
    ccu_table.ui \
    mainwindow.ui \
    messageconfig.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES += \
    icons/file_5251741.png \
    icons/gaziray.png \
    icons/icons8-input-96.png
