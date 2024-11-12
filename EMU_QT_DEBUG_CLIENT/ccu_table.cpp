#include "ccu_table.h"
#include "qevent.h"
#include "ui_ccu_table.h"
#include <cstdint>
#include <cstring>
#include <iostream>
#include "mvb_ports.h"
#include <QThread>
#include <QScreen>
#include "utils.h"
#include "ccutablehandler.h"

// udp message interval in mili seconds
constexpr int UDP_MESSAGE_INTERVAL= 300;

CCU_Table::CCU_Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CCU_Table),
    ccu_in(new IN::CCU_Inputs(this)),
    m_ccu_out(new OUT::CCU_Outputs(this)),
    m_ConfigWidget (new MessageConfig()),
    m_timer(new QTimer(this)),
    m_ldr_switch (new SwitchButton()),
    maintenanceIDButton  (new QPushButton("Maintenance ID", this)),
    developerIDButton  (new QPushButton("Developer ID",this)),
    adminIDButton  (new QPushButton("Admin ID")),
    wrongIDButton  (new QPushButton("Wrong ID",this)),
    resetIDButton (new QPushButton("ID RESET"))
    //oa1_Layout_1 (new QVBoxLayout()),
    //oa1_Layout_2  (new QVBoxLayout())
{
    ui->setupUi(this);


    setIDButtonLayout();


    connect(maintenanceIDButton, &QPushButton::clicked, this, &CCU_Table::maintenanceIDButtonClickedAction);
    connect(developerIDButton, &QPushButton::clicked, this, &CCU_Table::developerIDButtonClickedAction);
    connect(adminIDButton, &QPushButton::clicked, this, &CCU_Table::adminIDButtonClickedAction);
    connect(wrongIDButton, &QPushButton::clicked, this, &CCU_Table::wrongIDButtonClickedAction);
    connect(resetIDButton, &QPushButton::clicked, this, &CCU_Table::resetIDButtonClickedAction);


    //connect(maintenanceIDButton, &QPushButton::clicked, this, &CcuTable::testSlot);
    // Add ccu input signals to tablewidget
    init_ccu_outputs_table();

    // Add ccu output signals to tablewidget
    init_ccu_inputs_table();

    // Set tabwidget current index in the begining
    ui->tabWidget_ccu_in->setCurrentIndex(0);

    // LDR switch test status button
    init_switch();

    /*
     * udp message timer that is used for sending ccu input
     * parameters to COMM Module in TKYS software over udp
     * this message interval is set 300 milisecond
    */
    init_udp_message_timer(UDP_MESSAGE_INTERVAL);

    // initialize current ccu_table stack widget on ui
    init_current_stack_widget_index();

    // set style sheet configurations for widgets
    applyMainwindowStyleSheetConfiguration();

    // signal- slot connection configuration
    makeSignalSlotConnection();



}

CCU_Table::~CCU_Table()
{
    delete ui;
    delete m_ConfigWidget;
    //delete ccu_in;
    qDebug() << "CCU Table Destructor";
}



void CCU_Table::makeSignalSlotConnection()
{

    connect(m_ldr_switch, &SwitchButton::valueChanged, this, [=]() {

        //ccu_in->getSkaVhRiom().get_ska_1_vh_riom_ccu_mvb1_d_inputs().bits.DRIVER_LOAD_SELECTOR_ON = 1;
        //ccu_in->getSkaVhRiom().ska_x_vh_riom(SKA_VEHICLE_NUM::SKA1).ska_vh_riom_ccu_mvb1_d_inputs.bits.DRIVER_LOAD_SELECTOR_ON = m_ldr_switch->value();
        // Burada get_ska_1_vh_riom_ccu_mvb1_d_inputs() fonksiyonu ilgili strcutın referansını geri
        // döndermeli çünkü yapılan update bit bazında olduğu için struct güncellendiğinde diğer fonksiyonlarda
        // değişen bitler korunmalı bu yüzden refransı dönmeli.
        // ardından table widget içerisinde yer alan değerler güncellenmeli strcut güncellendiği durumda
        //ilk olarak bu strcut içerisindeki verileri güncelle
        //ccu_in->getSkaVhRiom().update_ska_1_vh_riom_ccu_mvb1_d_list();
        //ccu_in->getSkaVhRiom().update_map(SKA_VEHICLE_NUM::SKA1);
        //ccu_in->getSkaVhRiom().update_table(SKA_VEHICLE_NUM::SKA1);

    });

}



void CCU_Table::init_ccu_inputs_table()
{

    CcuTableHandler::processCcuInputTables(ui, ccu_in);

}

void CCU_Table::init_ccu_outputs_table()
{
    //CcuTableHandler::processCcuOutputTables(ui, m_ccu_out);

}


/**
 * @brief Initializes and starts the UDP message timer.
 *
 * This function sets up a QTimer to trigger the `sendSystemModulesToComModule` slot
 * at regular intervals specified by the `timer_interval_msec` parameter.
 * The timer is connected to the `sendSystemModulesToComModule` function, which
 * handles sending system module data to the communication module.
 *
 * @param timer_interval_msec The interval in milliseconds at which the timer will trigger.
 */
void CCU_Table::init_udp_message_timer(int timer_interval_msec)
{
    connect(m_timer, &QTimer::timeout, this, &CCU_Table::sendSystemModulesToComModule);
    m_timer->setInterval(timer_interval_msec);
}

void CCU_Table::init_current_stack_widget_index()
{
    ui->stackedWidget_ccu_table->addWidget(m_ConfigWidget);
    ui->stackedWidget_ccu_table->setCurrentIndex(0);
}


void CCU_Table::stopCcuTableTimer()  //constexpr uint16_t portId = mvb_sink_addresses_oa2.at(12).at(0);
{
    qDebug() << "stopCcuTableTimer()";
    m_timer->stop();
    sendStatusActivated = false;
    ui->pushButton_send_shm_data->setText("Send");
}


void CCU_Table::receiveUdpMessage(QByteArray recv_data)
{
    CcuTableHandler::handleIncomingCcuOutSystemUdpPacketes(m_ccu_out, recv_data);
}

void CCU_Table::receiveUdpInMessage(QByteArray recv_data)
{
    CcuTableHandler::handleIncomingCcuInSystemUdpPacketes(ccu_in, recv_data);
}

void CCU_Table::init_switch()
{
    ui->verticalLayout_driver_key->addWidget(m_ldr_switch);
}


void CCU_Table::on_pushButton_send_shm_data_clicked()
{
    if(!sendStatusActivated)
    {
        m_timer->start();
        sendStatusActivated = true;
        ui->pushButton_send_shm_data->setText("Stop");
    }
    else {
        m_timer->stop();
        sendStatusActivated = false;
        ui->pushButton_send_shm_data->setText("Send");
    }

}

/**
* @brief Processes the given submodule data and sends it to the communication module.
 *
 * This function constructs a UDP message package by appending emulator configuration data,
 * the port ID, and the provided submodule data to a `QByteArray`. The constructed message is
 * then sent to the communication module. Additionally, the function outputs debug information.
 * Required UDP message packet will be => emu_config(6 bytes) + mvb_port_id(2 bytes) + ccu_sub_system_data(n bytes)
 *
 * @param portId The MVB port ID to which the data will be sent.
 * @param A vector containing the submodule data to be appended to the message.
 * @param debugMessage A QString containing a debug message for logging purposes.
 */

void CCU_Table::processAndSendData2(const uint16_t& portId, const std::vector<uint8_t>& subModuleData, const QString &debugMessage)
{
    QByteArray udp_message_package;

    // Append Emulator Config Data (6 bytes)
    emulator_config emuConfigMessage = m_ConfigWidget->getMessageConfigStruct();
    appendEmuConfigToQByteArray(udp_message_package, emuConfigMessage.bytes, 6);

    // Append Port ID (2 bytes)
    appendPortIDToQByteArray(udp_message_package, portId);

    // Append CCU Data (n bytes)
    //appendDataToQByteArray(udp_message_package, subModuleData.data(), subModuleData.size());

    // Send data to COMM Module (6 + 2 + n) bytes
    emit sendCommSystemPackageData(udp_message_package);

    // Debug output
    //utils::show_bytearray(udp_message_package, debugMessage);

}

void CCU_Table::processIDScreenData()
{


}


/*void CCU_Table::parseAndSendCombinedValue(const QByteArray &combinedValue) {

    // Gelen combinedValue'yu parçalama işlemleri burada yapılıyor
    QByteArray portId  = combinedValue.mid(6,2);
    QByteArray subModuleData = combinedValue.mid(8,7);
    qDebug() << "Received and parsing Combined Value:" << combinedValue.toHex();
    emit sendCommSystemPackageData(combinedValue);


}*/

void CCU_Table::receiveCombinedValue(const QByteArray &combinedValue)
{

    QByteArray udp_message_package;
    qDebug() << "Received Combined Value:" << combinedValue.toHex();/////////////////////////Göndermeeeeeeeeeeee

    emulator_config emuConfigMessage = m_ConfigWidget->getMessageConfigStruct();
    appendEmuConfigToQByteArray(udp_message_package, emuConfigMessage.bytes, 6);


    udp_message_package.append(combinedValue);
    //Sending the id screen data - DATA is a BYTEARRAY

    qDebug() << "Config addition, ID Value:" << udp_message_package.toHex();/////////////////////////Göndermeeeeeeeeeeee

    emit sendCommSystemPackageData(udp_message_package);
}

/**
 * @brief Processes and sends data for various SKA1 submodules.
 *
 * This function checks the configuration settings for various SKA1 submodules and, if
 * enabled, retrieves the data from the respective submodule, processes it, and sends it
 * to the communication module. The function covers the following submodules:
 * - SKA1 DD RIOM
 * - SKA1 CCU Digital Inputs Card
 * - SKA1 VH RIOM
 * - SKA1 DCU
 * - SKA1 FDS
 * - SKA1 ATS
 * - SKA1 PAPIS
 * - SKA1 BCU
 */
void CCU_Table::processSka1()
{

    // SKA 1 DD RIOM
    if(m_ConfigWidget->isSka1DdinputsMSet()) {
        auto& ska_dd_riom  = ccu_in->getSkaDDRiom();
        uint16_t portId  = ska_dd_riom.portId(SKA_VEHICLE_NUM::SKA1);
        std::vector<uint8_t> subModuleData = ska_dd_riom.moduleData(SKA_VEHICLE_NUM::SKA1);
        processAndSendData2(portId, subModuleData, "Ska1DdinputsMSet");
    }

    /* SKA 1 CCU Digital Inputs Card
    if(m_ConfigWidget->isSka1DiCardSet()) {
        auto& ska_ccu_di_card  = ccu_in->getSkaCcuDiCard();
        uint16_t portId  = ska_ccu_di_card.portId(SKA_VEHICLE_NUM::SKA1);
        auto subModuleData = ska_ccu_di_card.moduleData(SKA_VEHICLE_NUM::SKA1);
        processAndSendData2(portId, subModuleData, "Ska1CcuDiCard");
    }*/

    // SKA 1 VH RIOM
    if(m_ConfigWidget->isSka1VhinputsMSet()) {
        auto& ska_vh_riom = ccu_in->getSkaVhRiom();
        uint16_t portId  = ska_vh_riom.portId(SKA_VEHICLE_NUM::SKA1);
        auto subModuleData = ska_vh_riom.moduleData(SKA_VEHICLE_NUM::SKA1);
        processAndSendData2(portId, subModuleData, "Ska1VhinputsMSet");
    }

    /*DCU ska1*/
    if(m_ConfigWidget->isSka1DcuSet())
    {
        auto& ska_dcu  = ccu_in->getSkaDcu();
        uint16_t portId  = ska_dcu.portId(SKA_VEHICLE_NUM::SKA1);
        auto subModuleData = ska_dcu.moduleData(SKA_VEHICLE_NUM::SKA1);
        processAndSendData2(portId, subModuleData, "Ska1DcuSet");
    }

    // SKA 1 FDS
    if(m_ConfigWidget->isSka1FdsSet()) {
        auto& ska_fds = ccu_in->getSkaFds();
        uint16_t portId  = ska_fds.portId(SKA_VEHICLE_NUM::SKA1);
        auto subModuleData = ska_fds.moduleData(SKA_VEHICLE_NUM::SKA1);
        processAndSendData2(portId, subModuleData, "ska_fds");
    }

    // SKA 1 ATS
    if(m_ConfigWidget->isSka1AtsSet()) {
        auto& ska_ats = ccu_in->getSkaAts();
        uint16_t portId  = ska_ats.portId(SKA_VEHICLE_NUM::SKA1);
        auto subModuleData = ska_ats.moduleData(SKA_VEHICLE_NUM::SKA1);
        processAndSendData2(portId, subModuleData, "Ska1AtsSet");
    }

    // SKA 1 PAPIS
    if(m_ConfigWidget->isSka1PapisSet()) {
        auto& ska_papis = ccu_in->getSkaPapis();
        uint16_t portId  = ska_papis.portId(SKA_VEHICLE_NUM::SKA1);
        auto subModuleData = ska_papis.moduleData(SKA_VEHICLE_NUM::SKA1);
        processAndSendData2(portId, subModuleData, "Ska1PapisSet");
    }

    // SKA 1 BCU
    if(m_ConfigWidget->isSka1BcuSet()) {
        auto& ska_bcu = ccu_in->getSkaBcu();
        uint16_t portId  = ska_bcu.portId(SKA_VEHICLE_NUM::SKA1);
        auto subModuleData = ska_bcu.moduleData(SKA_VEHICLE_NUM::SKA1);
        processAndSendData2(portId, subModuleData, "Ska1BcuSet");
    }

    // SKA 1 HVAC
    if(m_ConfigWidget->isSka1HvacSet()) {
        auto& ska_hvac = ccu_in->getSkaHvac();
        uint16_t portId  = ska_hvac.portId(SKA_VEHICLE_NUM::SKA1);
        auto subModuleData = ska_hvac.moduleData(SKA_VEHICLE_NUM::SKA1);
        processAndSendData2(portId, subModuleData, "Ska1HvacSet");
    }

}

/**
 * @brief Processes and sends data for various SKA2 submodules.
 *
 * This function checks the configuration settings for various SKA1 submodules and, if
 * enabled, retrieves the data from the respective submodule, processes it, and sends it
 * to the communication module. The function covers the following submodules:
 * - SKA2 DD RIOM
 * - SKA2 CCU Digital Inputs Card
 * - SKA2 VH RIOM
 * - SKA2 DCU
 * - SKA2 FDS
 * - SKA2 ATS
 * - SKA2 PAPIS
 * - SKA2 BCU
 */
void CCU_Table::processSka2()
{


    // DD RIOM ska2
    if(m_ConfigWidget->isSka2DdinputsMSet()) {
        auto& ska_dd_riom = ccu_in->getSkaDDRiom();
        uint16_t portId = ska_dd_riom.portId(SKA_VEHICLE_NUM::SKA2);
        auto subModuleData = ska_dd_riom.moduleData(SKA_VEHICLE_NUM::SKA2);
        processAndSendData2(portId, subModuleData, "Ska2DdRiom");
    }

    /* CCU Digital Inputs Card ska2
    if(m_ConfigWidget->isSka2DiCardSet()) {
        auto& ska_ccu_di_card = ccu_in->getSkaCcuDiCard();
        uint16_t portId = ska_ccu_di_card.portId(SKA_VEHICLE_NUM::SKA2);
        auto subModuleData = ska_ccu_di_card.moduleData(SKA_VEHICLE_NUM::SKA2);
        processAndSendData2(portId, subModuleData, "Ska2CcuDiCard");
    }*/

    // VH RIOM ska2
    if(m_ConfigWidget->isSka2VhinputsMSet()) {
        auto& ska_vh_riom = ccu_in->getSkaVhRiom();
        uint16_t portId = ska_vh_riom.portId(SKA_VEHICLE_NUM::SKA2);
        auto subModuleData = ska_vh_riom.moduleData(SKA_VEHICLE_NUM::SKA2);
        processAndSendData2(portId, subModuleData, "Ska2vhRiom");
    }

    // DCU ska2
    if(m_ConfigWidget->isSka2DcuSet()) {
        auto& ska_dcu = ccu_in->getSkaDcu();
        uint16_t portId = ska_dcu.portId(SKA_VEHICLE_NUM::SKA2);
        auto subModuleData = ska_dcu.moduleData(SKA_VEHICLE_NUM::SKA2);
        processAndSendData2(portId, subModuleData, "ska_dcu");
    }

    // FDS ska2
    if(m_ConfigWidget->isSka2FdsSet()) {
        auto& ska_fds = ccu_in->getSkaFds();
        uint16_t portId = ska_fds.portId(SKA_VEHICLE_NUM::SKA2);
        auto subModuleData = ska_fds.moduleData(SKA_VEHICLE_NUM::SKA2);
        processAndSendData2(portId,subModuleData, "Ska2FdsSet");
    }

    // ATS ska2
    if(m_ConfigWidget->isSka2AtsSet()) {
        auto& ska_ats = ccu_in->getSkaAts();
        uint16_t portId = ska_ats.portId(SKA_VEHICLE_NUM::SKA2);
        auto subModuleData = ska_ats.moduleData(SKA_VEHICLE_NUM::SKA2);
        processAndSendData2(portId, subModuleData, "Ska2AtsSet");
    }

    // PAPIS ska2
    if(m_ConfigWidget->isSka2PapisSet()) {
        auto& ska_papis = ccu_in->getSkaPapis();
        uint16_t portId = ska_papis.portId(SKA_VEHICLE_NUM::SKA2);
        auto subModuleData = ska_papis.moduleData(SKA_VEHICLE_NUM::SKA2);
        processAndSendData2(portId, subModuleData, "Ska2PapisSet");
    }

    // BCU ska2
    if(m_ConfigWidget->isSka2BcuSet()) {
        auto& ska_bcu = ccu_in->getSkaBcu();
        uint16_t portId = ska_bcu.portId(SKA_VEHICLE_NUM::SKA2);
        auto subModuleData = ska_bcu.moduleData(SKA_VEHICLE_NUM::SKA2);
        processAndSendData2(portId, subModuleData, "Ska2BcuSet");
    }

    // SKA 2 HVAC
    if(m_ConfigWidget->isSka2HvacSet()) {
        auto& ska_hvac = ccu_in->getSkaHvac();
        uint16_t portId  = ska_hvac.portId(SKA_VEHICLE_NUM::SKA2);
        auto subModuleData = ska_hvac.moduleData(SKA_VEHICLE_NUM::SKA2);
        processAndSendData2(portId, subModuleData, "Ska2HvacSet");
    }

}

/**
 * @brief Processes and sends data for various OA1 submodules.
 *
 * This function checks the configuration settings for various OA1 submodules and, if
 * enabled, retrieves the data from the respective submodule, processes it, and sends it
 * to the communication module. The function covers the following submodules:
 * - OA1 RIOM
 * - OA1 DCU
 * - OA1 ETCS
 * - OA1 BCU
 * - OA1 JRU
 */
void CCU_Table::processOa1()
{
    QByteArray CcuInData; // Single QByteArray for reuse

    // OA 1 RIOM
    if (m_ConfigWidget->isOa1VhinputsMSet()) {
        auto& oa_vh_riom = ccu_in->getOaVhRiom();
        uint16_t portId = oa_vh_riom.portId(OA_VEHICLE_NUM::OA1);
        std::vector<uint8_t> subModuleData = oa_vh_riom.moduleData(OA_VEHICLE_NUM::OA1);
        processAndSendData2(portId, subModuleData, "Oa1VhinputsMSet");

    }

    // OA 1 DCU
    if (m_ConfigWidget->isOa1DcuSet()) {
        auto& oa_dcu = ccu_in->getOaDcu();
        uint16_t portId = oa_dcu.portId(OA_VEHICLE_NUM::OA1);
        auto subModuleData = oa_dcu.moduleData(OA_VEHICLE_NUM::OA1);
        processAndSendData2(portId, subModuleData, "Oa1Dcu");
    }

    // OA 1 ETCS
    if (m_ConfigWidget->isOa1EtcsSet()) {
        auto& oa_etcs = ccu_in->getOaEtcs();
        uint16_t portId = oa_etcs.portId(OA_VEHICLE_NUM::OA1);
        auto subModuleData = oa_etcs.moduleData(OA_VEHICLE_NUM::OA1);
        processAndSendData2(portId, subModuleData, "Oa1Etcs");
    }

    // OA 1 BCU
    if (m_ConfigWidget->isOa1BcuSet()) {
        auto& oa_bcu = ccu_in->getOaBcu();
        uint16_t portId = oa_bcu.portId(OA_VEHICLE_NUM::OA1);
        auto subModuleData = oa_bcu.moduleData(OA_VEHICLE_NUM::OA1);
        processAndSendData2(portId, subModuleData, "Oa1Bcu");
    }

    // OA 1 JRU
    if (m_ConfigWidget->isOa1JruSet()) {
        auto& oa_jru = ccu_in->getOaJru();
        uint16_t portId = oa_jru.portId(OA_VEHICLE_NUM::OA1);
        auto subModuleData = oa_jru.moduleData(OA_VEHICLE_NUM::OA1);
        processAndSendData2(portId, subModuleData, "Oa1Jru");
    }

    /*OA 1 DAM
    if (m_ConfigWidget->isOa1DamSet()) {
        auto& oa_dam = ccu_in->getOaDam();
        uint16_t portId = oa_dam.portId(OA_VEHICLE_NUM::OA1);
        auto subModuleData = oa_dam.moduleData(OA_VEHICLE_NUM::OA1);
        processAndSendData2(portId, subModuleData, "Oa1Dam");
    }*/

    //OA 1 HVAC
    if (m_ConfigWidget->isOa1HvacSet()) {
        auto& oa_hvac = ccu_in->getOaHvac();
        uint16_t portId = oa_hvac.portId(OA_VEHICLE_NUM::OA1);
        auto subModuleData = oa_hvac.moduleData(OA_VEHICLE_NUM::OA1);
        processAndSendData2(portId, subModuleData, "Oa1Hvac");
    }
}

/**
 * @brief Processes and sends data for various OA2 submodules.
 *
 * This function checks the configuration settings for various OA1 submodules and, if
 * enabled, retrieves the data from the respective submodule, processes it, and sends it
 * to the communication module. The function covers the following submodules:
 * - OA2 RIOM
 * - OA2 DCU
 * - OA2 ETCS
 * - OA2 BCU
 * - OA2 JRU
 */
void CCU_Table::processOa2()
{
    QByteArray CcuInData; // Single QByteArray for reuse

    // OA 2 RIOM
    if (m_ConfigWidget->isOa2VhinputsMSet()) {
        auto& oa_vh_riom = ccu_in->getOaVhRiom();
        uint16_t portId = oa_vh_riom.portId(OA_VEHICLE_NUM::OA2);
        auto subModuleData = oa_vh_riom.moduleData(OA_VEHICLE_NUM::OA2);
        processAndSendData2(portId, subModuleData, "Oa2VhinputsMSet");

    }

    // OA 2 DCU
    if (m_ConfigWidget->isOa2DcuSet()) {
        auto& oa_dcu = ccu_in->getOaDcu();
        uint16_t portId = oa_dcu.portId(OA_VEHICLE_NUM::OA2);
        auto subModuleData = oa_dcu.moduleData(OA_VEHICLE_NUM::OA2);
        processAndSendData2(portId, subModuleData, "Oa2Dcu");
    }

    // OA 2 ETCS
    if (m_ConfigWidget->isOa2EtcsSet()) {
        auto& oa_etcs = ccu_in->getOaEtcs();
        uint16_t portId = oa_etcs.portId(OA_VEHICLE_NUM::OA2);
        auto subModuleData = oa_etcs.moduleData(OA_VEHICLE_NUM::OA2);
        processAndSendData2(portId, subModuleData, "Oa2Etcs");
    }

    // OA 2 BCU
    if (m_ConfigWidget->isOa2BcuSet()) {
        auto& oa_bcu = ccu_in->getOaBcu();
        uint16_t portId = oa_bcu.portId(OA_VEHICLE_NUM::OA2);
        auto subModuleData = oa_bcu.moduleData(OA_VEHICLE_NUM::OA2);
        processAndSendData2(portId, subModuleData, "Oa2Bcu");
    }

    // OA 2 JRU
    if (m_ConfigWidget->isOa2JruSet()) {
        auto& oa_jru = ccu_in->getOaJru();
        uint16_t portId = oa_jru.portId(OA_VEHICLE_NUM::OA2);
        auto subModuleData = oa_jru.moduleData(OA_VEHICLE_NUM::OA2);
        processAndSendData2(portId, subModuleData, "Oa2Jru");
    }

    /*OA 2 DAM
    if (m_ConfigWidget->isOa2DamSet()) {
        auto& oa_dam = ccu_in->getOaDam();
        uint16_t portId = oa_dam.portId(OA_VEHICLE_NUM::OA2);
        auto subModuleData = oa_dam.moduleData(OA_VEHICLE_NUM::OA2);
        processAndSendData2(portId, subModuleData, "Oa2Dam");
    }*/

    //OA 2 HVAC
    if (m_ConfigWidget->isOa2HvacSet()) {
        auto& oa_hvac = ccu_in->getOaHvac();
        uint16_t portId = oa_hvac.portId(OA_VEHICLE_NUM::OA2);
        auto subModuleData = oa_hvac.moduleData(OA_VEHICLE_NUM::OA2);
        processAndSendData2(portId, subModuleData, "Oa2Hvac");
    }
}

/**
 * @brief Processes and sends data for all system modules to the communication module.
 *
 * This function sequentially processes and sends data for SKA1, SKA2, OA1, and OA2 modules
 * by calling their respective processing functions. Each of these functions handles
 * the data preparation and transmission to the communication module.
 */
void CCU_Table::sendSystemModulesToComModule()
{
    processSka1();
    processSka2();
    processOa1();
    processOa2();


}

/**
 * @brief Slot function triggered when the configuration table button is clicked.
 *
 * This function handles the click event for the configuration table button. When the button
 * is clicked, it sets the current widget of the stacked widget to the configuration widget,
 * effectively displaying the configuration interface to the user.
 */
void CCU_Table::on_pushButton_configurationTable_clicked()
{

    ui->stackedWidget_ccu_table->setCurrentWidget(m_ConfigWidget);

}

void CCU_Table::closeEvent(QCloseEvent *event)
{
    // Timer'ı durdur
    m_timer->stop();
    qDebug() << "Close Event Occured";

    // Temel QWidget fonksiyonunu çağırarak olayı işle
    QWidget::closeEvent(event);

}

/**
 * @brief Applies a custom style sheet to the main window.
 *
 * This function sets the style sheet for various UI elements within the main window.
 * It customizes the appearance of QWidget, QPushButton, QTableWidget, and QGroupBox
 * to provide a consistent and visually appealing interface.
 */
void CCU_Table::applyMainwindowStyleSheetConfiguration()
{
    this->setStyleSheet(
        "QWidget { background-color: #E0E0E0; border: 1px solid #CCCCCC; border-radius: 10px;  }"
        "QPushButton { background-color: #005BBB; color: white; border-radius: 5px; padding: 10px 20px; font-size: 16px; }"
        "QPushButton:hover { background-color: #004B9B; }"
        "QTableWidget { alternate-background-color: #E0E0E0; }"
        "QGroupBox { border: 2px solid #005BBB; margin-top: 10px; }"
        "QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; padding: 0 3px; }"
        "QLineEdit {"
        "    background-color: #FFFFFF;"
        "    border: 1px solid #CCCCCC;"
        "    border-radius: 5px;"
        "    padding: 5px 10px;"
        "    font-size: 14px;"
        "    color: #333333;"
        "}"
        "QLineEdit:focus {"
        "    border: 1px solid #005BBB;"
        "    background-color: #E6F4FF;"
        "}"
        "QComboBox {"
        "    background-color: #FFFFFF;"
        "    border: 1px solid #CCCCCC;"
        "    border-radius: 5px;"
        "    padding: 5px;"
        "    font-size: 14px;"
        "    color: #333333;"
        "}"
        "QComboBox::drop-down {"
        "    subcontrol-origin: padding;"
        "    subcontrol-position: top right;"
        "    width: 20px;"
        "    border-left: 1px solid #CCCCCC;"
        "}"
        "QComboBox::down-arrow {"
        "    image: url(down-arrow.png);"
        "}"
        "QComboBox QAbstractItemView {"
        "    background-color: #FFFFFF;"
        "    selection-background-color: #E6F4FF;"
        "}"

        "QTableWidget {"
        "    background-color: #FFFFFF;"
        "    alternate-background-color: #E0E0E0;"
        "    gridline-color: #CCCCCC;"
        "    font-size: 14px;"
        "    color: #333333;"
        "    selection-background-color: #E6F4FF;"
        "    selection-color: #333333;"
        "}"
        "QHeaderView::section {"
        "    background-color: #005BBB;"
        "    color: white;"
        "    padding: 4px;"
        "    border: 1px solid #CCCCCC;"
        "}"
        "QTableWidget QTableCornerButton::section {"
        "    background-color: #005BBB;"
        "}"

        "QTextEdit {"
        "    background-color: #CCCCCC;"
        "    border: 1px solid #CCCCCC;"
        "    border-radius: 5px;"
        "    padding: 10px;"
        "    font-size: 14px;"
        "    color: #333333;"
        "}"
        "QTextEdit:focus {"
        "    border: 1px solid #005BBB;"
        "    background-color: #E6F4FF;"
        "}"
        "QTabWidget::pane {"
        "    border: 1px solid #CCCCCC;"
        "    border-radius: 5px;"
        "    background-color: #F5F5F5;"
        "}"
        "QTabBar::tab {"
        "    background: #E0E0E0;"
        "    border: 1px solid #CCCCCC;"
        "    border-radius: 5px;"
        "    padding: 10px;"
        "    margin-right: 2px;"
        "}"
        "QTabBar::tab:selected {"
        "    background: #FFFFFF;"
        "    border-color: #005BBB;"
        "    color: #005BBB;"
        "}"
        "QTabBar::tab:hover {"
        "    background: #DDDDDD;"
        "}"
        "QTabBar::tab:!selected {"
        "    margin-top: 2px;"
        "}"
        "QTabWidget::tab-bar {"
        "    alignment: center;"
        "}"

        "QLabel {"
        "    color: #333333;" /* Metin rengi */
        "    font-size: 16px;" /* Metin boyutu */
        "}"

        "QLabel#specificLabel {"
        "    color: #FF0000;" /* Belirli metin rengi */
        "    font-style: italic;" /* Belirli metin stil */
        "}"

        "QLabel:hover {"
        "    background-color: #EFEFEF;" /* Arkaplan rengi değişimi */
        "}"

        "QLabel:pressed {"
        "    color: #0000FF;" /* Tıklama rengi değişimi */
        "}"
        );

    this->setStyleSheet(

        "QLabel:not(SwitchButton) { color: #333333; font-size: 16px; }"
        "QLabel#specificLabel:not(SwitchButton) { color: #FF0000;}"
        "QLabel:hover:not(SwitchButton) { background-color: #CCCCCC; }"
        "QLabel:pressed:not(SwitchButton) { color: #0000FF; }"

        );
        //"QLabel:hover:not(SwitchButton) { background-color: #EFEFEF; }"
    // #787878 labeloff
    //
}

void CCU_Table::on_pushButton_2_clicked()
{
    static int index = 0;
    ui->stackedWidget_ccu_table->setCurrentIndex(index);
    index++;
    if(index == 4)
        index = 0;
    qDebug() << "index:" << index;
}


void CCU_Table::on_pushButton_ccu_inputs_clicked()
{
    ui->stackedWidget_ccu_table->setCurrentIndex(0);
}

void CCU_Table::setIDButtonLayout()
{
    ui->verticalLayout_driver_key->addWidget(maintenanceIDButton);
    ui->verticalLayout_driver_key->addWidget(developerIDButton);
    ui->verticalLayout_driver_key->addWidget(adminIDButton);
    ui->verticalLayout_driver_key->addWidget(wrongIDButton);
    ui->verticalLayout_driver_key->addWidget(resetIDButton);

    //oa1_Layout_1->addWidget(maintenanceIDButton);
    //oa1_Layout_1->addWidget(developerIDButton);
    //oa1_Layout_1->addWidget(adminIDButton);
    //oa1_Layout_1->addWidget(wrongIDButton);

    //oa1_Layout_2->addWidget(ccu_in->getOaJru().getTableWidget(OA_VEHICLE_NUM::OA1));
    //ui->horizontalLayout_oa_1_jru_1->addLayout(oa1_Layout_1);
    ui->horizontalLayout_oa_1_jru_1->addWidget(ccu_in->getOaJru().getTableWidget(OA_VEHICLE_NUM::OA1));

    //ui->verticalLayout_oa_1_jru_1->addWidget(ccu_in->getOaJru().getTableWidget(OA_VEHICLE_NUM::OA1));
    ui->verticalLayout_oa_2_jru_1->addWidget(ccu_in->getOaJru().getTableWidget(OA_VEHICLE_NUM::OA2));
}

void CCU_Table::maintenanceIDButtonClickedAction(){

    //OA1 JRU
    //QMessageBox::information(this, "Wrong ID Value Sent", "Wrong ID Value: ");
    qDebug() << "maintenanceIDButtonClickedAction";
    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte1 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte2 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte3 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte4 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte5 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte6 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte7 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);


    //OA2 JRU
    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte1 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte2 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte3 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte4 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte5 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte6 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte7 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);


}


void CCU_Table::developerIDButtonClickedAction() {

    //OA1 JRU
    qDebug() << "developerIDButtonClickedAction";
    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte1 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte2 = 0;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte3 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte4 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte5 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte6 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte7 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);


    //OA2 JRU
    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte1 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte2 = 0;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte3 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte4 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte5 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte6 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte7 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);
}


void CCU_Table::adminIDButtonClickedAction() {

    //OA1 JRU
    //qDebug() << "adminIDButtonClickedAction";
    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte1 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte2 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte3 = 0;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte4 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte5 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte6 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte7 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    //OA2 JRU
    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte1 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte2 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte3 = 0;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte4 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte5 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte6 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte7 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);
}

void CCU_Table::wrongIDButtonClickedAction() {

    qDebug() << "wrongIDButtonClickedAction";
    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte1 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte2 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte3 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte4 = 0;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte5 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte6 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte7 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    //OA2 JRU
    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte1 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte2 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte3 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte4 = 0;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte5 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte6 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte7 = 1;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);
}

void CCU_Table::resetIDButtonClickedAction() {

    //OA1 JRU
    //qDebug() << "resetIDButtonClickedAction";
    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte1 = 0;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte2 = 0;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte3 = 0;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte4 = 0;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte5 = 0;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte6 = 0;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA1).bits.Badge_id_byte7 = 0;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA1);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA1);

    //OA2 JRU
    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte1 = 0;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte2 = 0;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte3 = 0;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte4 = 0;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte5 = 0;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte6 = 0;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);

    ccu_in->getOaJru().oa_x_jru_ccu_mvb1(OA_VEHICLE_NUM::OA2).bits.Badge_id_byte7 = 0;
    ccu_in->getOaJru().update_mvb1_map(OA_VEHICLE_NUM::OA2);
    ccu_in->getOaJru().update_table(OA_VEHICLE_NUM::OA2);
}
