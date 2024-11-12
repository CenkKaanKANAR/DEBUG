#include "ReadShmDialog.h"
#include "ui_ReadShmDialog.h"
#include <QMessageBox>
#include <QDebug>
#include "ccu_table.h"
#include "utils.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "mvb_ports.h"

ReadShmDialog::ReadShmDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReadShmDialog),
    m_ccu_table(new CCU_Table()),
    m_ccu_out(new OUT::CCU_Outputs())
{
    ui->setupUi(this);
    ui->tabWidget_ccu_out->setCurrentIndex(0);


    init_ccu_out_table();
    ui->tabWidget_ccu_out->setUsesScrollButtons(true); // Kaydırma düğmelerini etkinleştir
    applyMainwindowStyleSheetConfiguration();
    ui->tabWidget_ccu_out->setTabPosition(QTabWidget::West); // Sekme çubuğunu sola taşı

}


ReadShmDialog::~ReadShmDialog()
{
    delete ui;
    delete m_ccu_out;
}

/**
 * @brief Receives and processes incoming UDP messages.
 *
 * This function processes incoming UDP messages by extracting the port ID from the received data
 * and updating the corresponding CCU output data structure. Depending on the port ID, it updates
 * the data structure for either SKA1 or SKA2 vehicle numbers and reflects the changes on the table.
 *
 * @param recv_data The received UDP message as a QByteArray.
 */
void ReadShmDialog::receive_udp_message(const QByteArray& recv_data)
{

    //utils::show_bytearray(recv_data, "receive udp_message:");
    // update ccu_out data and show on the table
    QDataStream stream(recv_data);
    stream.setByteOrder(QDataStream::LittleEndian);
    uint16_t port_id ;
    stream >> port_id;
    //ska_ccu_vh_riom_mvb1_d_outputs output;// Buraya
    // her bir out sinyalin büyüklüğü girilmelidir

    //qDebug("Port Id: %x", port_id);

    if(port_id == SKA1_VH_RIOM_1_OUTPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(2, SKA1_VH_RIOM_1_OUTPUTS_SIZE);
        m_ccu_out->get_Ska_ccu_vh_riom_mvb1_d()->set_data_struct(source, SKA_VEHICLE_NUM::SKA1);
    }
    if(port_id == SKA2_VH_RIOM_1_OUTPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(2, SKA2_VH_RIOM_1_OUTPUTS_SIZE);
        m_ccu_out->get_Ska_ccu_vh_riom_mvb1_d()->set_data_struct(source, SKA_VEHICLE_NUM::SKA2);
    }
    if (port_id == SKA1_DD_RIOM_1_OUTPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(2,SKA1_DD_RIOM_1_OUTPUTS_SIZE);
        m_ccu_out->get_Ska_Ccu_DD_Riom_Mvb1_d_Outputs()->set_data_struct(source, SKA_VEHICLE_NUM::SKA1);
    }

    if (port_id == SKA2_DD_RIOM_1_OUTPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(2, SKA2_DD_RIOM_1_OUTPUTS_SIZE);
        m_ccu_out->get_Ska_Ccu_DD_Riom_Mvb1_d_Outputs()->set_data_struct(source, SKA_VEHICLE_NUM::SKA2);
    }

    if (port_id == SKA1_VH_RIOM_1_DOOR_COMMANDS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(2, SKA1_VH_RIOM_1_DOOR_COMMANDS_SIZE);
        m_ccu_out->get_Ska_Ccu_Vh_Riom_Mvb2_Dcu()->set_data_struct(source, SKA_VEHICLE_NUM::SKA1);
    }

    if (port_id == SKA2_VH_RIOM_1_DOOR_COMMANDS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(2, SKA2_VH_RIOM_1_DOOR_COMMANDS_SIZE);
        m_ccu_out->get_Ska_Ccu_Vh_Riom_Mvb2_Dcu()->set_data_struct(source, SKA_VEHICLE_NUM::SKA2);
    }

    if (port_id == OA1_VH_RIOM_1_OUTPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(2, OA1_VH_RIOM_1_OUTPUTS_SIZE);
        m_ccu_out->get_Oa_Ccu_Vh_Riom_Mvb1_d_Outputs()->set_data_struct(source,OA_VEHICLE_NUM::OA1);
    }

    if (port_id == OA2_VH_RIOM_1_OUTPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(2, OA2_VH_RIOM_1_OUTPUTS_SIZE);
        m_ccu_out->get_Oa_Ccu_Vh_Riom_Mvb1_d_Outputs()->set_data_struct(source,OA_VEHICLE_NUM::OA2);
    }

    if (port_id == OA1_VH_RIOM_1_DOOR_COMMANDS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(2, OA1_VH_RIOM_1_DOOR_COMMANDS_SIZE);
        m_ccu_out->get_Oa_Ccu_Vh_Riom_Mvb2_Dcu()->set_data_struct(source,OA_VEHICLE_NUM::OA1);
    }

    if (port_id == OA2_VH_RIOM_1_DOOR_COMMANDS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(2, OA2_VH_RIOM_1_DOOR_COMMANDS_SIZE);
        m_ccu_out->get_Oa_Ccu_Vh_Riom_Mvb2_Dcu()->set_data_struct(source,OA_VEHICLE_NUM::OA2);
    }

    else
    {
        //qDebug() << "Invalid Port Id";
    }
}

/**
 * @brief Initializes the CCU output table for SKA vehicles.
 *
 * This function sets up the user interface by adding the CCU output tables for SKA1, SKA2, OA1, OA2 vehicles.
 * It retrieves the table widgets from the `m_ccu_out` object and adds them to the respective
 * vertical layouts in the user interface.
 */
void ReadShmDialog::init_ccu_out_table()
{
    // ska_ccu_vh_riom_mvb1_d_outputs
    ui->verticalLayout_ska1_ccu_vh_riom_mvb1_d_outputs->addWidget(m_ccu_out->get_Ska_ccu_vh_riom_mvb1_d()->getTableWidget(SKA_VEHICLE_NUM::SKA1));
    ui->verticalLayout_ska2_ccu_vh_riom_mvb1_d_outputs->addWidget(m_ccu_out->get_Ska_ccu_vh_riom_mvb1_d()->getTableWidget(SKA_VEHICLE_NUM::SKA2));

    // ska_ccu_vh_riom_mvb2_dcu
    ui->verticalLayout_ska1_ccu_vh_riom_mvb2_dcu->addWidget(m_ccu_out->get_Ska_Ccu_Vh_Riom_Mvb2_Dcu()->getTableWidget(SKA_VEHICLE_NUM::SKA1));
    ui->verticalLayout_ska2_ccu_vh_riom_mvb2_dcu->addWidget(m_ccu_out->get_Ska_Ccu_Vh_Riom_Mvb2_Dcu()->getTableWidget(SKA_VEHICLE_NUM::SKA2));

    // ska_ccu_dd_riom_mvb1_d_outputs
    ui->verticalLayout_ska1_ccu_dd_riom_mvb1_d_outputs->addWidget(m_ccu_out->get_Ska_Ccu_DD_Riom_Mvb1_d_Outputs()->getTableWidget(SKA_VEHICLE_NUM::SKA1));
    ui->verticalLayout_ska2_ccu_dd_riom_mvb1_d_outputs->addWidget(m_ccu_out->get_Ska_Ccu_DD_Riom_Mvb1_d_Outputs()->getTableWidget(SKA_VEHICLE_NUM::SKA2));

    // oa_ccu_vh_riom_mvb1_d_outputs
    ui->verticalLayout_oa1_ccu_vh_riom_mvb1_d_outputs->addWidget(m_ccu_out->get_Oa_Ccu_Vh_Riom_Mvb1_d_Outputs()->getTableWidget(OA_VEHICLE_NUM::OA1));
    ui->verticalLayout_oa2_ccu_vh_riom_mvb1_d_outputs->addWidget(m_ccu_out->get_Oa_Ccu_Vh_Riom_Mvb1_d_Outputs()->getTableWidget(OA_VEHICLE_NUM::OA2));

    // oa_ccu_vh_riom_mvb2_dcu
    ui->verticalLayout_oa1_ccu_vh_riom_mvb2_dcu->addWidget(m_ccu_out->get_Oa_Ccu_Vh_Riom_Mvb2_Dcu()->getTableWidget(OA_VEHICLE_NUM::OA1));
    ui->verticalLayout_oa2_ccu_vh_riom_mvb2_dcu->addWidget(m_ccu_out->get_Oa_Ccu_Vh_Riom_Mvb2_Dcu()->getTableWidget(OA_VEHICLE_NUM::OA2));

    // ccu_to_oax_etcs
    ui->verticalLayout_ccu_to_oa1_etcs->addWidget(m_ccu_out->get_Ccu_To_Oax_Etcs()->getTableWidget(OA_VEHICLE_NUM::OA1));
    ui->verticalLayout_ccu_to_oa2_etcs->addWidget(m_ccu_out->get_Ccu_To_Oax_Etcs()->getTableWidget(OA_VEHICLE_NUM::OA2));

    // ska_ccu_global_out_mvb2

    //m_ccu_out->get_Ska_Ccu_Global_Out_Mvb2()->getTableWidget()->setColumnWidth(0, 150);
    //m_ccu_out->get_Ska_Ccu_Global_Out_Mvb2()->getTableWidget()->setRowHeight(0, 50);
    ui->verticalLayout_ska_ccu_global_out_mvb2->addWidget(m_ccu_out->get_Ska_Ccu_Global_Out_Mvb2()->getTableWidget());
    //ui->verticalLayout_ska2_ccu_global_out_mvb2->addWidget(m_ccu_out->get_Ska_Ccu_Global_Out_Mvb2()->getTableWidget());

    //ska_ccu_global_all_rioms_mvb2_fds
    ui->verticalLayout_ska_ccu_global_all_rioms_mvb2_fds->addWidget(m_ccu_out->get_Ska_Ccu_To_All_Rioms_Mvb2()->getTableWidget());
    //ui->verticalLayout_ska2_ccu_global_all_rioms_mvb2_fds->addWidget(m_ccu_out->get_Ska_Ccu_Global_All_Rioms_Mvb2_Fds()->getTableWidget());

    //ska_ccu_global_out_mvb1
    ui->verticalLayout_ska_ccu_global_out_mvb1->addWidget(m_ccu_out->get_Ska_Ccu_Global_Out_Mvb1()->getTableWidget());

    //ska_ccu_global_all_rioms_mvb1_dcu
    ui->verticalLayout_ska_ccu_global_all_rioms_mvb1_dcu->addWidget(m_ccu_out->get_Ska_Ccu_To_All_Rioms_Mvb1()->getTableWidget());

    //ccu_to_all_bcus
    ui->verticalLayout_ccu_to_all_bcus->addWidget(m_ccu_out->get_Ccu_To_All_Bcus()->getTableWidget());

    //ccu_to_all_etcs
    ui->verticalLayout_ccu_to_all_etcs->addWidget(m_ccu_out->get_Ccu_To_All_Etcs()->getTableWidget());

    //ccu_to_all_jrus_1
    ui->verticalLayout_ccu_to_all_jrus_1->addWidget(m_ccu_out->get_Ccu_To_All_Jrus_1()->getTableWidget());

    //ccu_to_all_jrus_2
    ui->verticalLayout_ccu_to_all_jrus_2->addWidget(m_ccu_out->get_Ccu_To_All_Jrus_2()->getTableWidget());

    //ccu_to_all_jrus_3
    ui->verticalLayout_ccu_to_all_jrus_3->addWidget(m_ccu_out->get_Ccu_To_All_Jrus_3()->getTableWidget());

    //ccu_to_all_jrus_4
    ui->verticalLayout_ccu_to_all_jrus_4->addWidget(m_ccu_out->get_Ccu_To_All_Jrus_4()->getTableWidget());

    //ccu_to_all_jrus_5
    ui->verticalLayout_ccu_to_all_jrus_5->addWidget(m_ccu_out->get_Ccu_To_All_Jrus_5()->getTableWidget());

    //ska1_ccu_do_card
    ui->verticalLayout_ska1_ccu_do_card->addWidget(m_ccu_out->get_Ska_Ccu_Do_Card()->getTableWidget(SKA_VEHICLE_NUM::SKA1));

    //ska2_ccu_do_card
    ui->verticalLayout_ska2_ccu_do_card->addWidget(m_ccu_out->get_Ska_Ccu_Do_Card()->getTableWidget(SKA_VEHICLE_NUM::SKA2));


}



void ReadShmDialog::applyMainwindowStyleSheetConfiguration()
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
}
