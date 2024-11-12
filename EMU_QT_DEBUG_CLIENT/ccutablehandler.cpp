#include "ccutablehandler.h"
#include "ccu_inputs.h"
#include "ccu_outputs.h"
#include <QVBoxLayout>
#include <QByteArray>
#include "ui_ccu_table.h"
#include "mvb_ports.h"
#include <QDebug>
#include "ccu_inputs/ska_dcu.h"
CcuTableHandler::CcuTableHandler()
{

}


/**
 * @brief Processes and sets up the CCU input tables in the UI.
 *
 * This function is responsible for populating the user interface (UI) with the
 * Control and Command Unit (CCU) input tables. It takes the UI object and
 * the CCU input data object as parameters and adds the respective tables
 * to the designated vertical layouts in the UI.
 *
 * @param ui A pointer to the UI object which contains the layout widgets
 *           for the CCU tables.
 * @param ccu_in A pointer to the CCU input data object that provides the
 *               necessary table widgets for each SKA vehicle.
 */
void CcuTableHandler::processCcuInputTables(Ui::CCU_Table *ui, IN::CCU_Inputs *ccu_in)
{

    // SKA CCU DI Card

    ui->verticalLayout_ska_1_ccu_di_card->addWidget(ccu_in->getSkaCcuDiCard().getTableWidget(SKA_VEHICLE_NUM::SKA1));
    ui->verticalLayout_ska_2_ccu_di_card->addWidget(ccu_in->getSkaCcuDiCard().getTableWidget(SKA_VEHICLE_NUM::SKA2));

    // SKA DD RIOM
    ui->verticalLayout_ska_dd_riom_1->addWidget(ccu_in->getSkaDDRiom().getTableWidget(SKA_VEHICLE_NUM::SKA1,SKA_DD_RIOM::MVB1));
    ui->verticalLayout_ska_dd_riom_2->addWidget(ccu_in->getSkaDDRiom().getTableWidget(SKA_VEHICLE_NUM::SKA2,SKA_DD_RIOM::MVB1));
    //verticalLayout_ska2_dd_riom_ccu_mvb_status
    ui->verticalLayout_ska1_dd_riom_ccu_mvb_status->addWidget(ccu_in->getSkaDDRiom().getTableWidget(SKA_VEHICLE_NUM::SKA1,SKA_DD_RIOM::STATUS0));
    ui->verticalLayout_ska2_dd_riom_ccu_mvb_status->addWidget(ccu_in->getSkaDDRiom().getTableWidget(SKA_VEHICLE_NUM::SKA2,SKA_DD_RIOM::STATUS0));


    //ska_dd_riom_ccu_mvb_status_inputs

    // SKA VH RIOM
    ui->verticalLayout_ska_vh_riom_1->addWidget(ccu_in->getSkaVhRiom().getTableWidget(SKA_VEHICLE_NUM::SKA1,SKA_VH_RIOM::MVB1));
    ui->verticalLayout_ska_vh_riom_2->addWidget(ccu_in->getSkaVhRiom().getTableWidget(SKA_VEHICLE_NUM::SKA2,SKA_VH_RIOM::MVB1));

    ui->verticalLayout_ska1_vh_riom_ccu_mvb_status->addWidget(ccu_in->getSkaVhRiom().getTableWidget(SKA_VEHICLE_NUM::SKA1,SKA_VH_RIOM::STATUS0));
    ui->verticalLayout_ska2_vh_riom_ccu_mvb_status->addWidget(ccu_in->getSkaVhRiom().getTableWidget(SKA_VEHICLE_NUM::SKA2,SKA_VH_RIOM::STATUS0));


    // SKA 1 DCU
    ui->verticalLayout_ska_1_dcu_1->addWidget(ccu_in->getSkaDcu().getTableWidget(SKA_VEHICLE_NUM::SKA1,SKA_DCU::DCU1));
    ui->verticalLayout_ska_1_dcu_2->addWidget(ccu_in->getSkaDcu().getTableWidget(SKA_VEHICLE_NUM::SKA1,SKA_DCU::DCU2));
    ui->verticalLayout_ska_1_dcu_3->addWidget(ccu_in->getSkaDcu().getTableWidget(SKA_VEHICLE_NUM::SKA1,SKA_DCU::DCU3));
    ui->verticalLayout_ska_1_dcu_4->addWidget(ccu_in->getSkaDcu().getTableWidget(SKA_VEHICLE_NUM::SKA1,SKA_DCU::DCU4));

    // SKA 2 DCU
    ui->verticalLayout_ska_2_dcu_1->addWidget(ccu_in->getSkaDcu().getTableWidget(SKA_VEHICLE_NUM::SKA2,SKA_DCU::DCU1));
    ui->verticalLayout_ska_2_dcu_2->addWidget(ccu_in->getSkaDcu().getTableWidget(SKA_VEHICLE_NUM::SKA2,SKA_DCU::DCU2));
    ui->verticalLayout_ska_2_dcu_3->addWidget(ccu_in->getSkaDcu().getTableWidget(SKA_VEHICLE_NUM::SKA2,SKA_DCU::DCU3));
    ui->verticalLayout_ska_2_dcu_4->addWidget(ccu_in->getSkaDcu().getTableWidget(SKA_VEHICLE_NUM::SKA2,SKA_DCU::DCU4));

    // SKA 1 FDS
    ui->verticalLayout_ska_1_fds_1->addWidget(ccu_in->getSkaFds().getTableWidget(SKA_VEHICLE_NUM::SKA1, SKA_FDS::FDS1));
    ui->verticalLayout_ska_1_fds_2->addWidget(ccu_in->getSkaFds().getTableWidget(SKA_VEHICLE_NUM::SKA1, SKA_FDS::FDS2));
    ui->verticalLayout_ska_1_fds_3->addWidget(ccu_in->getSkaFds().getTableWidget(SKA_VEHICLE_NUM::SKA1, SKA_FDS::FDS3));

    // SKA 2 FDS
    ui->verticalLayout_ska_2_fds_1->addWidget(ccu_in->getSkaFds().getTableWidget(SKA_VEHICLE_NUM::SKA2, SKA_FDS::FDS1));
    ui->verticalLayout_ska_2_fds_2->addWidget(ccu_in->getSkaFds().getTableWidget(SKA_VEHICLE_NUM::SKA2, SKA_FDS::FDS2));
    ui->verticalLayout_ska_2_fds_3->addWidget(ccu_in->getSkaFds().getTableWidget(SKA_VEHICLE_NUM::SKA2, SKA_FDS::FDS3));

    //SKA 1 PAPIS
    ui->verticalLayout_ska_1_papis_1->addWidget(ccu_in->getSkaPapis().getTableWidget(SKA_VEHICLE_NUM::SKA1,SKA_PAPIS::MVB1));
    ui->verticalLayout_ska_1_papis_2->addWidget(ccu_in->getSkaPapis().getTableWidget(SKA_VEHICLE_NUM::SKA1,SKA_PAPIS::MVB2));
    ui->verticalLayout_ska_1_papis_3->addWidget(ccu_in->getSkaPapis().getTableWidget(SKA_VEHICLE_NUM::SKA1,SKA_PAPIS::MVB3));
    //ui->verticalLayout_ska_1_papis_4->addWidget(ccu_in->getSkaPapis().get_ska_1_vh_riom_ccu_mvbx_papisx_tableWidget(3));

    ui->verticalLayout_ska_2_papis_1->addWidget(ccu_in->getSkaPapis().getTableWidget(SKA_VEHICLE_NUM::SKA2,SKA_PAPIS::MVB1));
    ui->verticalLayout_ska_2_papis_2->addWidget(ccu_in->getSkaPapis().getTableWidget(SKA_VEHICLE_NUM::SKA2,SKA_PAPIS::MVB2));
    ui->verticalLayout_ska_2_papis_3->addWidget(ccu_in->getSkaPapis().getTableWidget(SKA_VEHICLE_NUM::SKA2,SKA_PAPIS::MVB3));
    //ui->verticalLayout_ska_2_papis_4->addWidget(ccu_in->getSkaPapis().get_ska_2_vh_riom_ccu_mvbx_papisx_tableWidget(3));


    // SKA 1 ATS
    ui->verticalLayout_ska_1_ats_1->addWidget(ccu_in->getSkaAts().getTableWidget(SKA_VEHICLE_NUM::SKA1));
    ui->verticalLayout_ska_2_ats_1->addWidget(ccu_in->getSkaAts().getTableWidget(SKA_VEHICLE_NUM::SKA2));

    // SKA 1 BCU
    ui->verticalLayout_ska_1_bcu_1->addWidget(ccu_in->getSkaBcu().getTableWidget(SKA_VEHICLE_NUM::SKA1,Ska_Bcu::MVB1));
    ui->verticalLayout_ska_1_bcu_2->addWidget(ccu_in->getSkaBcu().getTableWidget(SKA_VEHICLE_NUM::SKA1,Ska_Bcu::MVB2));
    //ui->verticalLayout_ska_1_bcu_3->addWidget(ccu_in->getSkaBcu().getTableWidget(SKA_VEHICLE_NUM::SKA1,Ska_Bcu::MVB3));

    // SKA 2 BCU
    ui->verticalLayout_ska_2_bcu_1->addWidget(ccu_in->getSkaBcu().getTableWidget(SKA_VEHICLE_NUM::SKA2,Ska_Bcu::MVB1));
    ui->verticalLayout_ska_2_bcu_2->addWidget(ccu_in->getSkaBcu().getTableWidget(SKA_VEHICLE_NUM::SKA2,Ska_Bcu::MVB2));
    //ui->verticalLayout_ska_2_bcu_3->addWidget(ccu_in->getSkaBcu().getTableWidget(SKA_VEHICLE_NUM::SKA2,Ska_Bcu::MVB3));

    // OA VH RIOM
    ui->verticalLayout_oa_1_vh_riom_1->addWidget(ccu_in->getOaVhRiom().getTableWidget(OA_VEHICLE_NUM::OA1,Oa_Vh_Riom::MVB1));
    ui->verticalLayout_oa_2_vh_riom_1->addWidget(ccu_in->getOaVhRiom().getTableWidget(OA_VEHICLE_NUM::OA2,Oa_Vh_Riom::MVB1));

    ui->verticalLayout_oa1_vh_riom_ccu_mvb_status->addWidget(ccu_in->getOaVhRiom().getTableWidget(OA_VEHICLE_NUM::OA1,Oa_Vh_Riom::STATUS0));
    ui->verticalLayout_oa2_vh_riom_ccu_mvb_status->addWidget(ccu_in->getOaVhRiom().getTableWidget(OA_VEHICLE_NUM::OA2,Oa_Vh_Riom::STATUS0));

    // OA 1 DCU
    ui->verticalLayout_oa_1_dcu_1->addWidget(ccu_in->getOaDcu().getTableWidget(OA_VEHICLE_NUM::OA1,OA_DCU::DCU1));
    ui->verticalLayout_oa_1_dcu_2->addWidget(ccu_in->getOaDcu().getTableWidget(OA_VEHICLE_NUM::OA1,OA_DCU::DCU2));
    ui->verticalLayout_oa_1_dcu_3->addWidget(ccu_in->getOaDcu().getTableWidget(OA_VEHICLE_NUM::OA1,OA_DCU::DCU3));
    ui->verticalLayout_oa_1_dcu_4->addWidget(ccu_in->getOaDcu().getTableWidget(OA_VEHICLE_NUM::OA1,OA_DCU::DCU4));

    // OA 2 DCU

    ui->verticalLayout_oa_2_dcu_1->addWidget(ccu_in->getOaDcu().getTableWidget(OA_VEHICLE_NUM::OA2,OA_DCU::DCU1));
    ui->verticalLayout_oa_2_dcu_2->addWidget(ccu_in->getOaDcu().getTableWidget(OA_VEHICLE_NUM::OA2,OA_DCU::DCU2));
    ui->verticalLayout_oa_2_dcu_3->addWidget(ccu_in->getOaDcu().getTableWidget(OA_VEHICLE_NUM::OA2,OA_DCU::DCU3));
    ui->verticalLayout_oa_2_dcu_4->addWidget(ccu_in->getOaDcu().getTableWidget(OA_VEHICLE_NUM::OA2,OA_DCU::DCU4));

    // OA 1 BCU
    ui->verticalLayout_oa_1_bcu_1->addWidget(ccu_in->getOaBcu().getTableWidget(OA_VEHICLE_NUM::OA1,OA_BCU::MVB1));
    ui->verticalLayout_oa_1_bcu_2->addWidget(ccu_in->getOaBcu().getTableWidget(OA_VEHICLE_NUM::OA1,OA_BCU::MVB2));
    //ui->verticalLayout_oa_1_bcu_3->addWidget(ccu_in->getOaBcu().getTableWidget(OA_VEHICLE_NUM::OA1,OA_BCU::MVB3));

    // OA 2 BCU
    ui->verticalLayout_oa_2_bcu_1->addWidget(ccu_in->getOaBcu().getTableWidget(OA_VEHICLE_NUM::OA2,OA_BCU::MVB1));
    ui->verticalLayout_oa_2_bcu_2->addWidget(ccu_in->getOaBcu().getTableWidget(OA_VEHICLE_NUM::OA2,OA_BCU::MVB2));
    //ui->verticalLayout_oa_2_bcu_3->addWidget(ccu_in->getOaBcu().getTableWidget(OA_VEHICLE_NUM::OA2,OA_BCU::MVB3));

    // OA 1 ETCS
    ui->verticalLayout_oa_1_etcs_1->addWidget(ccu_in->getOaEtcs().getTableWidget(OA_VEHICLE_NUM::OA1,Oa_Etcs::MVB1));
    ui->verticalLayout_oa_1_etcs_2->addWidget(ccu_in->getOaEtcs().getTableWidget(OA_VEHICLE_NUM::OA1,Oa_Etcs::MVB2));
    ui->verticalLayout_oa_1_etcs_3->addWidget(ccu_in->getOaEtcs().getTableWidget(OA_VEHICLE_NUM::OA1,Oa_Etcs::MVB3));

    // OA 2 ETCS
    ui->verticalLayout_oa_2_etcs_1->addWidget(ccu_in->getOaEtcs().getTableWidget(OA_VEHICLE_NUM::OA2,Oa_Etcs::MVB1));
    ui->verticalLayout_oa_2_etcs_2->addWidget(ccu_in->getOaEtcs().getTableWidget(OA_VEHICLE_NUM::OA2,Oa_Etcs::MVB2));
    ui->verticalLayout_oa_2_etcs_3->addWidget(ccu_in->getOaEtcs().getTableWidget(OA_VEHICLE_NUM::OA2,Oa_Etcs::MVB3));

    // OA 1 JRU

    ui->horizontalLayout_oa_1_jru_1->addWidget(ccu_in->getOaJru().getTableWidget(OA_VEHICLE_NUM::OA1));
    //ui->horizontalLayout_oa_2_jru_1->addWidget(ccu_in->getOaJru().getTableWidget(OA_VEHICLE_NUM::OA2));

    //OA 1 DAM
    ui->verticalLayout_OA1_DAM->addWidget(ccu_in->getOaDam().getTableWidget(OA_VEHICLE_NUM::OA1));

    //OA 2 DAM GELECEK
    ui-> verticalLayout_OA2_DAM->addWidget(ccu_in->getOaDam().getTableWidget(OA_VEHICLE_NUM::OA2));

    // SKA1 HVAC
    ui->verticalLayout_ska1_vh_riom_ccu_mvb13_hvac1->addWidget(ccu_in->getSkaHvac().getTableWidget(SKA_VEHICLE_NUM::SKA1,Ska_Hvac::HVAC1));
    ui->verticalLayout_ska1_vh_riom_ccu_mvb14_hvac2->addWidget(ccu_in->getSkaHvac().getTableWidget(SKA_VEHICLE_NUM::SKA1,Ska_Hvac::HVAC2));
    ui->verticalLayout_ska1_vh_riom_ccu_mvb15_hvac3->addWidget(ccu_in->getSkaHvac().getTableWidget(SKA_VEHICLE_NUM::SKA1,Ska_Hvac::HVAC3));

    // SKA2 HVAC
    ui->verticalLayout_ska2_vh_riom_ccu_mvb13_hvac1->addWidget(ccu_in->getSkaHvac().getTableWidget(SKA_VEHICLE_NUM::SKA2,Ska_Hvac::HVAC1));
    ui->verticalLayout_ska2_vh_riom_ccu_mvb14_hvac2->addWidget(ccu_in->getSkaHvac().getTableWidget(SKA_VEHICLE_NUM::SKA2,Ska_Hvac::HVAC2));
    ui->verticalLayout_ska2_vh_riom_ccu_mvb15_hvac3->addWidget(ccu_in->getSkaHvac().getTableWidget(SKA_VEHICLE_NUM::SKA2,Ska_Hvac::HVAC3));

    //OA1 HVAC
    ui->verticalLayout_oa1_vh_riom_ccu_mvb6_hvac1->addWidget(ccu_in->getOaHvac().getTableWidget(OA_VEHICLE_NUM::OA1,Oa_Hvac::HVAC1));
    ui->verticalLayout_oa1_vh_riom_ccu_mvb7_hvac2->addWidget(ccu_in->getOaHvac().getTableWidget(OA_VEHICLE_NUM::OA1,Oa_Hvac::HVAC2));

    //OA2 HVAC
    ui->verticalLayout_oa2_vh_riom_ccu_mvb6_hvac1->addWidget(ccu_in->getOaHvac().getTableWidget(OA_VEHICLE_NUM::OA2,Oa_Hvac::HVAC1));
    ui->verticalLayout_oa2_vh_riom_ccu_mvb7_hvac2->addWidget(ccu_in->getOaHvac().getTableWidget(OA_VEHICLE_NUM::OA2,Oa_Hvac::HVAC2));
}

/**
 * @brief Processes and sets up the CCU output tables in the UI.
 *
 * This function is responsible for populating the user interface (UI) with the
 * Control and Command Unit (CCU) output tables. It takes the UI object and
 * the CCU output data object as parameters and adds the respective tables
 * to the designated vertical layouts in the UI.
 *
 * @param ui A pointer to the UI object which contains the layout widgets
 *           for the CCU tables.
 * @param ccu_in A pointer to the CCU output data object that provides the
 *               necessary table widgets for each SKA vehicle.
 */
void CcuTableHandler::processCcuOutputTables(Ui::CCU_Table* ui, OUT::CCU_Outputs* ccu_out)
{
    ui->verticalLayout_2->addWidget(ccu_out->get_Ska_ccu_vh_riom_mvb1_d()->getTableWidget(SKA_VEHICLE_NUM::SKA1));
}


///üstteki function inputlar için lazım mı?





void CcuTableHandler::handleIncomingCcuOutSystemUdpPacketes(OUT::CCU_Outputs *ccu_out, const QByteArray& recv_data)
{
    //utils::show_bytearray(recv_data, "receive udp_message:");
    // update ccu_out data and show on the table
    //qDebug() << "size of recv_data is : " << recv_data.size();
    //qDebug() << "recv_data is : " << recv_data;
    //QDataStream stream(recv_data);
    //qDebug() << "stream data is : " << stream;
    //stream.setByteOrder(QDataStream::LittleEndian);
    //uint16_t port_id ;
    //stream >> port_id;
    //ska_ccu_vh_riom_mvb1_d_outputs output;// Buraya
    // her bir out sinyalin büyüklüğü girilmelidir

    int start = 6;         // Başlangıç indeksi
    //int length = 2;        // Alınacak byte sayısı

    int port_id = (static_cast<uint8_t>(recv_data[start]) << 8) | static_cast<uint8_t>(recv_data[start + 1]);

    //qDebug() << "Port Id: " << QString::number(port_id, 16);  // Port Id'yi hexadecimal olarak görmek için

    if(port_id == SKA1_VH_RIOM_1_OUTPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(2, SKA1_VH_RIOM_1_OUTPUTS_SIZE);
        ccu_out->get_Ska_ccu_vh_riom_mvb1_d()->set_data_struct(source, SKA_VEHICLE_NUM::SKA1);
    }

    if(port_id == SKA2_VH_RIOM_1_OUTPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(2, SKA2_VH_RIOM_1_OUTPUTS_SIZE);
        ccu_out->get_Ska_ccu_vh_riom_mvb1_d()->set_data_struct(source, SKA_VEHICLE_NUM::SKA2);
    }
    if (port_id == SKA1_DD_RIOM_1_OUTPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(2,SKA1_DD_RIOM_1_OUTPUTS_SIZE);
        ccu_out->get_Ska_Ccu_DD_Riom_Mvb1_d_Outputs()->set_data_struct(source, SKA_VEHICLE_NUM::SKA1);
    }

    if (port_id == SKA2_DD_RIOM_1_OUTPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(2, SKA2_DD_RIOM_1_OUTPUTS_SIZE);
        ccu_out->get_Ska_Ccu_DD_Riom_Mvb1_d_Outputs()->set_data_struct(source, SKA_VEHICLE_NUM::SKA2);
    }

    if (port_id == SKA1_VH_RIOM_1_DOOR_COMMANDS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(2, SKA1_VH_RIOM_1_DOOR_COMMANDS_SIZE);
        ccu_out->get_Ska_Ccu_Vh_Riom_Mvb2_Dcu()->set_data_struct(source, SKA_VEHICLE_NUM::SKA1);
    }

    if (port_id == SKA2_VH_RIOM_1_DOOR_COMMANDS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(2, SKA2_VH_RIOM_1_DOOR_COMMANDS_SIZE);
        ccu_out->get_Ska_Ccu_Vh_Riom_Mvb2_Dcu()->set_data_struct(source, SKA_VEHICLE_NUM::SKA2);
    }

    if (port_id == OA1_VH_RIOM_1_OUTPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(2, OA1_VH_RIOM_1_OUTPUTS_SIZE);
        ccu_out->get_Oa_Ccu_Vh_Riom_Mvb1_d_Outputs()->set_data_struct(source,OA_VEHICLE_NUM::OA1);
    }

    if (port_id == OA2_VH_RIOM_1_OUTPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(2, OA2_VH_RIOM_1_OUTPUTS_SIZE);
        ccu_out->get_Oa_Ccu_Vh_Riom_Mvb1_d_Outputs()->set_data_struct(source,OA_VEHICLE_NUM::OA2);
    }

    if (port_id == OA1_VH_RIOM_1_DOOR_COMMANDS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(2, OA1_VH_RIOM_1_DOOR_COMMANDS_SIZE);
        ccu_out->get_Oa_Ccu_Vh_Riom_Mvb2_Dcu()->set_data_struct(source,OA_VEHICLE_NUM::OA1);
    }

    if (port_id == OA2_VH_RIOM_1_DOOR_COMMANDS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(2, OA2_VH_RIOM_1_DOOR_COMMANDS_SIZE);
        ccu_out->get_Oa_Ccu_Vh_Riom_Mvb2_Dcu()->set_data_struct(source,OA_VEHICLE_NUM::OA2);

    }
    if(port_id == OA1_ETCS_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(2, OA1_ETCS_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
       ccu_out->get_Oa_Ccu_Vh_Riom_Mvb2_Dcu()->set_data_struct(source,OA_VEHICLE_NUM::OA2);
    }
    else
    {

        QByteArray source = recv_data.mid(2, OA1_ETCS_INPUTS_SIZE);
        qDebug() << "Invalid Port Id";

        //qDebug() << "recv_data is : " << recv_data;
        //qDebug() << "source data is : " << source;

    }
}

void CcuTableHandler::handleIncomingCcuInSystemUdpPacketes(IN::CCU_Inputs *ccu_in, const QByteArray& recv_data)
{

    int start = 6;         // Başlangıç indeksi
    //int length = 2;        // Alınacak byte sayısı
    qDebug() << "size of recv_data is : " << recv_data.size();
    int port_id = (static_cast<uint8_t>(recv_data[start]) << 8) | static_cast<uint8_t>(recv_data[start + 1]);

    qDebug() << "Port Id: " << QString::number(port_id, 16);  // Port Id'yi hexadecimal olarak görmek için

    if(port_id == OA1_ETCS_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8, OA1_ETCS_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getOaEtcs().set_data_struct(source,OA_VEHICLE_NUM::OA1);
        qDebug() << "source data is : " << source;
    }
    if(port_id == OA2_ETCS_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8, OA2_ETCS_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getOaEtcs().set_data_struct(source,OA_VEHICLE_NUM::OA2);
        qDebug() << "source data is : " << source;
    }
    if(port_id == OA1_BCU_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8, OA1_BCU_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getOaBcu().set_data_struct(source,OA_VEHICLE_NUM::OA1);
        qDebug() << "source data is : " << source;
    }

    if(port_id == OA2_BCU_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8, OA2_BCU_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getOaBcu().set_data_struct(source,OA_VEHICLE_NUM::OA2);
        qDebug() << "source data is : " << source;
    }

    if(port_id == OA1_DCU_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8, OA1_DCU_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getOaDcu().set_data_struct(source,OA_VEHICLE_NUM::OA1);
        qDebug() << "source data is : " << source;
    }

    if(port_id == OA2_DCU_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8, OA2_DCU_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getOaDcu().set_data_struct(source,OA_VEHICLE_NUM::OA2);
        qDebug() << "source data is : " << source;
    }
    ////////////////////////

    if(port_id == OA1_HVAC_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8, OA1_HVAC_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getOaHvac().set_data_struct(source,OA_VEHICLE_NUM::OA1);
        qDebug() << "source data is : " << source;
    }


    if(port_id == OA2_HVAC_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8, OA2_HVAC_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getOaHvac().set_data_struct(source,OA_VEHICLE_NUM::OA2);
        qDebug() << "source data is : " << source;
    }

    if(port_id == OA1_JRU_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8, OA1_JRU_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getOaJru().set_data_struct(source,OA_VEHICLE_NUM::OA1);
        qDebug() << "source data is : " << source;
        qDebug() << "Size OF Source data is : " << source.size();
    }

    if(port_id == OA2_JRU_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8, OA2_JRU_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getOaJru().set_data_struct(source,OA_VEHICLE_NUM::OA2);
        qDebug() << "source data is : " << source;
    }

    if(port_id == OA1_VH_RIOM_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8, OA1_VH_RIOM_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getOaVhRiom().set_data_struct(source,OA_VEHICLE_NUM::OA1);
        qDebug() << "source data is : " << source;
        qDebug() << "Size OF Source data is : " << source.size();
    }

    if(port_id == OA2_VH_RIOM_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8, OA2_VH_RIOM_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getOaVhRiom().set_data_struct(source,OA_VEHICLE_NUM::OA2);
        qDebug() << "source data is : " << source;
        qDebug() << "Size OF Source data is : " << source.size();
    }

    if(port_id == SKA1_ATS_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8, SKA1_ATS_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getSkaAts().set_data_struct(source,SKA_VEHICLE_NUM::SKA1);
        qDebug() << "source data is : " << source;
        qDebug() << "Size OF Source data is : " << source.size();
    }

    if(port_id == SKA2_ATS_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8, SKA2_ATS_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getSkaAts().set_data_struct(source,SKA_VEHICLE_NUM::SKA2);
        qDebug() << "source data is : " << source;
        qDebug() << "Size OF Source data is : " << source.size();
    }

    if(port_id == SKA1_BCU_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8, SKA1_BCU_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getSkaBcu().set_data_struct(source,SKA_VEHICLE_NUM::SKA1);
        qDebug() << "source data is : " << source;
        qDebug() << "Size OF Source data is : " << source.size();
    }

    if(port_id == SKA2_BCU_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8, SKA2_BCU_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getSkaBcu().set_data_struct(source,SKA_VEHICLE_NUM::SKA2);
        qDebug() << "source data is : " << source;
        qDebug() << "Size OF Source data is : " << source.size();
    }

    if(port_id == SKA1_CCU_DI_CARD_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8, SKA1_CCU_DI_CARD_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getSkaCcuDiCard().set_data_struct(source,SKA_VEHICLE_NUM::SKA1);
        qDebug() << "source data is : " << source;
        qDebug() << "Size OF Source data is : " << source.size();
    }

    /////////
    if(port_id == SKA2_CCU_DI_CARD_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8, SKA2_CCU_DI_CARD_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getSkaCcuDiCard().set_data_struct(source,SKA_VEHICLE_NUM::SKA2); //DCU SIKINTILI
        qDebug() << "source data is : " << source;
        qDebug() << "Size OF Source data is : " << source.size();
    }

    if(port_id == SKA1_DCU_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8, SKA1_DCU_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        //ccu_in->getSkaDcu().set_data_struct(source,SKA_VEHICLE_NUM::SKA1);
        qDebug() << "source data is : " << source;
        qDebug() << "Size OF Source data is : " << source.size();
    }

    /////////

    if(port_id ==  SKA1_DD_RIOM_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8,  SKA1_DD_RIOM_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1); //SIKINTILI
        ccu_in->getSkaDDRiom().set_data_struct(source,SKA_VEHICLE_NUM::SKA1);
        qDebug() << "source data is : " << source;
        qDebug() << "Size OF Source data is : " << source.size();
    }

    if(port_id ==  SKA2_DD_RIOM_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8,  SKA2_DD_RIOM_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1); //SIKINTILI
        ccu_in->getSkaDDRiom().set_data_struct(source,SKA_VEHICLE_NUM::SKA2);
        qDebug() << "source data is : " << source;
        qDebug() << "Size OF Source data is : " << source.size();
    }


    if(port_id ==  SKA1_FDS_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8,  SKA1_FDS_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getSkaFds().set_data_struct(source,SKA_VEHICLE_NUM::SKA1);
        qDebug() << "source data is : " << source;
        qDebug() << "Size OF Source data is : " << source.size();
    }

    if(port_id ==  SKA1_HVAC_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8,  SKA1_HVAC_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getSkaHvac().set_data_struct(source,SKA_VEHICLE_NUM::SKA1);
        qDebug() << "source data is : " << source;
        qDebug() << "Size OF Source data is : " << source.size();
    }


    if(port_id ==  SKA1_VH_RIOM_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8,  SKA1_VH_RIOM_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getSkaVhRiom().set_data_struct(source,SKA_VEHICLE_NUM::SKA1);
        qDebug() << "source data is : " << source;
        qDebug() << "Size OF Source data is : " << source.size();
    }

    if(port_id ==  SKA2_VH_RIOM_INPUTS)
    {
        qDebug("Valid Port Id: %x", port_id);
        QByteArray source = recv_data.mid(8,  SKA2_VH_RIOM_INPUTS_SIZE);
        //ccu_in->getOaEtcs().update_mvb1_map(OA_VEHICLE_NUM::OA1);
        //ccu_in->getOaEtcs().update_table(OA_VEHICLE_NUM::OA1);
        ccu_in->getSkaVhRiom().set_data_struct(source,SKA_VEHICLE_NUM::SKA2);
        qDebug() << "source data is : " << source;
        qDebug() << "Size OF Source data is : " << source.size();
    }
}
















