#include "oa_bcu.h"

OA_BCU::OA_BCU(QObject *parent)
    : QObject{parent}
{
    // struct oa_bcu m_oa_x_bcu[2];
    memset(&m_oa_x_bcu, 0, sizeof(m_oa_x_bcu));

    // Init OA1 Table Contents
    init_oa_x_mvb1_table(OA_VEHICLE_NUM::OA1);
    init_oa_x_mvb2_table(OA_VEHICLE_NUM::OA1);
    //init_oa_x_mvb3_table(OA_VEHICLE_NUM::OA1);

    // Init OA2 Table Contents
    init_oa_x_mvb1_table(OA_VEHICLE_NUM::OA2);
    init_oa_x_mvb2_table(OA_VEHICLE_NUM::OA2);
    //init_oa_x_mvb3_table(OA_VEHICLE_NUM::OA2);


    make_signal_slot_connection();

}

OA_BCU::~OA_BCU()
{
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            delete m_tableWidget[i][j];
            m_tableWidget[i][j] = nullptr; // Güvenlik için nullptr atayın
        }
    }

}


void OA_BCU::make_signal_slot_connection()
{
    // OA1 MVB1 connection slot
    connect(m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)][MVB1], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(OA_VEHICLE_NUM::OA1, MVB1);
    });
     // OA1 MVB2 connection slot
    connect(m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)][MVB2], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(OA_VEHICLE_NUM::OA1, MVB2);
    });
     /* OA1 MVB3 connection slot
    connect(m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)][MVB3], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(OA_VEHICLE_NUM::OA1, MVB3);
    });*/


    // OA2 MVB1 connection slot
    connect(m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)][MVB1], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(OA_VEHICLE_NUM::OA2, MVB1);
    });
    //OA2 MVB2 connection slot
    connect(m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)][MVB2], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(OA_VEHICLE_NUM::OA2, MVB2);
    });
    /* OA2 MVB3 connection slot
    connect(m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)][MVB3], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(OA_VEHICLE_NUM::OA2, MVB3);
    });*/
}

void OA_BCU::set_data_struct(const QByteArray &input, const OA_VEHICLE_NUM &oa_x_num)
{

    //int oa_num = static_cast<int>(oa_x_num);
    qDebug() << "azdan az çoktan çok " ;
    qDebug() << "size of input " << input.size();
    qDebug() << "Gelen input verileri :  " << input;
    //qDebug() << "Gelen input veri tipi : " << typeof(input);


    int oa_num = static_cast<int>(oa_x_num);

    qDebug() << "SET DATA STRUCT SIZE of COLUMN COUNT ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;
    if (input.size() == sizeof(m_oa_x_bcu[oa_num])) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        //memcpy(&m_oa_x_etcs[oa_num], input.constData(), sizeof(m_oa_x_etcs[oa_num]));

        qDebug() << "SIZE of MVB1 :  " << sizeof(m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bytes);
        qDebug() << "SIZE of MVB2 :  " << sizeof(m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bytes);


        // İlk alanı kopyala
        memcpy(&m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bytes, input.constData(), sizeof(m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bytes));

        QByteArray data =  input.mid(0, 32);
        qDebug() << "32 Bytelık data :  " << data;
        update_mvb1_map(oa_x_num);
        //set_struct_mvb1(oa_x_num);
        update_table(oa_x_num,OA_BCU::MVB1);

        // İkinci alanı kopyala, input.constData() + sizeof(etcs_ccu_mvb1) kadar ilerleyerek
        memcpy(&m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bytes, input.constData() + sizeof(m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bytes) + 8, sizeof(m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bytes));
        update_mvb2_map(oa_x_num);
        //set_struct_mvb2(oa_x_num);
        update_table(oa_x_num,OA_BCU::MVB2);

        //update maps

        //
        //
        //update tables

        //
        //
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }


}


void OA_BCU::update_table(OA_VEHICLE_NUM oa_x_num, OA_MVB_NUM mvb_num)
{
    int oa_num = static_cast<int>(oa_x_num);
    // İndeksleri kullanarak tabloyu güncelle
    qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;
    std::vector<int> valueColumns = {1, 3, 5, 7};
    for(const auto & map:m_inputs_map[oa_num][mvb_num]){


        utils::setTableWidgetValueByNameWithoutColumn(m_tableWidget[oa_num][mvb_num], map.first, map.second);
        //qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT INSIDE FOR LOOP ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;

        //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,3, map.second);
        //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,5, map.second);
        //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,7, map.second);
    }

}














void OA_BCU::init_oa_x_mvb1_table(OA_VEHICLE_NUM vehicle_type)
{
    int oa_num = static_cast<int>(vehicle_type);
    m_inputs_map[oa_num][MVB1] = {
        {"XLifeSign", 0},               // byte 0
        {"EBCU_MainVersion", 0},        // byte 2
        {"EBCU_SubVersion", 0},
        {"X_Cpress", 0},
        {"X_Tpress", 0},
        {"X_PrkBrPress_1", 0},
        {"X_PrkBrPress_2", 0},
        {"X_BPPress", 0},
        {"X_MRPPress", 0},
        {"reserved10", 0},              // byte 10
        {"X_LoadWeight", 0},            // byte 11
        {"X_VAxl1", 0},                 // byte 13
        {"X_VAxl2", 0},                 // byte 15
        {"X_VAxl3", 0},                 // byte 17
        {"X_VAxl4", 0},                 // byte 19
        {"X_Vref", 0},                  // byte 21
        {"reserved23", 0},              // byte 23
        {"reserved24", 0},              // byte 24
        {"S_HolBrRe", 0},               // byte 25
        {"V_HolBrRe", 0},
        {"S_HolBrAp", 0},
        {"V_HolBrAp", 0},
        {"S_PrkBrRe", 0},
        {"V_PrkBrRe", 0},
        {"S_PrkBrReNot", 0},
        {"V_PrkBrReNot", 0},
        {"S_PnBrRe_Bo1", 0},           // byte 26
        {"V_PnBrRe_Bo1", 0},
        {"S_PnBrAp_Bo1", 0},
        {"V_PnBrAp_Bo1", 0},
        {"S_PnBrRe_Bo2", 0},
        {"V_PnBrRe_Bo2", 0},
        {"S_PnBrAp_Bo2", 0},
        {"V_PnBrAp_Bo2", 0},
        {"S_EmergBrLoopOpen", 0},      // byte 27
        {"S_TLHolBrRe", 0},
        {"S_TLBrakingBit1", 0},
        {"S_TLBrakingBit2", 0},
        {"S_TLBrakingBit3", 0},
        {"S_TLTraction", 0},
        {"S_WSPTest_Run", 0},
        {"S_WSPTest_Run_abbort", 0},
        {"S_WSPactive_Bo1", 0},        // byte 28
        {"S_WSPok_Bo1", 0},
        {"S_WSPactive_Bo2", 0},
        {"S_WSPok_Bo2", 0},
        {"S_Degraded_Mode", 0},
        {"S_ASC_Mode_active", 0},
        {"S_Standstill", 0},
        {"S_EBCU_EBL_Open_PB", 0},
        {"IC_PneuBr", 0},              // byte 29
        {"IC_DirectBr", 0},
        {"IC_Cpress_Bo1", 0},
        {"IC_Cpress_Bo2", 0},
        {"IC_PrkBr", 0},
        {"IC_Sanding", 0},
        {"IC_InDirectBr", 0},
        {"S_DoorsClosedLocked", 0},
        {"S_ED_fade_Out", 0},          // byte 30
        {"S_BpApValid", 0},
        {"S_BpAP", 0},
        {"S_Sanding_Heating_Release", 0},
        {"S_Sanding_Active", 0},
        {"bit246", 0},
        {"bit247", 0},
        {"bit248", 0},
        {"reserved31", 0}
    };


    /*m_tableWidget[oa_num][MVB1] = new QTableWidget();
    m_tableWidget[oa_num][MVB1]->setColumnCount(2);
    m_tableWidget[oa_num][MVB1]->setRowCount(m_inputs_map[oa_num][MVB1].size());
    m_tableWidget[oa_num][MVB1]->setHorizontalHeaderLabels(table_name[oa_num][MVB1]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[oa_num][MVB1]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[oa_num][MVB1]->setItem(row, 0, item_name);
        m_tableWidget[oa_num][MVB1]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[oa_num][MVB1]->resizeColumnsToContents();*/


    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[oa_num][MVB1].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[oa_num][MVB1] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[oa_num][MVB1]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[oa_num][MVB1]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[oa_num][MVB1]->setItem(row, column, item_name);
        m_tableWidget[oa_num][MVB1]->setItem(row, column + 1, item_val); // Değer

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[oa_num][MVB1]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;
}

void OA_BCU::init_oa_x_mvb2_table(OA_VEHICLE_NUM vehicle_type)
{
    int oa_num = static_cast<int>(vehicle_type);
    m_inputs_map[oa_num][MVB2] = {
        {"XLifeSign", 0}, // byte0
        {"DIA_BOARD_CB09_02", 0}, // byte2
        {"DIA_BOARD_MB04_04", 0},
        {"DIA_BOARD_MB03_06", 0},
        {"DIA_BOARD_MB03_07", 0},
        {"DIA_BOARD_EB01_08", 0},
        {"DIA_BOARD_EB02_09", 0},
        {"bit23", 0},
        {"bit24", 0},
        {"DIA_BOARDCODING_MB04_04", 0}, // byte3
        {"DIA_BOARDCODING_MB03_06", 0},
        {"DIA_BOARDCODING_MB03_07", 0},
        {"DIA_BOARDCODING_EB01_08", 0},
        {"DIA_BOARDCODING_EB02_09", 0},
        {"bit30", 0},
        {"bit31", 0},
        {"bit32", 0},
        {"DIA_CAN_COMM_CB09_02", 0}, // byte4
        {"DIA_CAN_COMM_MB04_03", 0},
        {"DIA_CAN_COMM_MB03_06", 0},
        {"DIA_CAN_COMM_MB03_07", 0},
        {"DIA_CAN_COMM_EB01_08", 0},
        {"DIA_CAN_COMM_EB02_09", 0},
        {"bit39", 0},
        {"bit40", 0},
        {"DIA_PSENSOR_C", 0}, // byte5
        {"DIA_PSENSOR_BP", 0},
        {"DIA_PSENSOR1_PB", 0},
        {"DIA_PSENSOR2_PB", 0},
        {"DIA_PSENSOR_CVD", 0},
        {"DIA_PSENSOR_T", 0},
        {"DIA_PSENSOR_R", 0},
        {"DIA_PSENSOR_CVI", 0},
        {"DIA_PSENSOR_MRP", 0}, // byte6
        {"DIA_REL_EBCU_FCT_OK", 0},
        {"DIA_REL_EBCU_EBLOOP_Y_OPEN", 0},
        {"DIA_REL_EBCU_C_EDCUTOFF", 0},
        {"DIA_REL_WSP_R_VLT5KMHDOOR", 0},
        {"DIA_REL_WSP_R_VGT5KMHDOOR", 0},
        {"DIA_REL_WSP_R_VGT10KMHDOOR", 0},
        {"bit56", 0},
        {"DIA_WSP_FSI_AXLE1", 0}, // byte7
        {"DIA_WSP_FSI_AXLE2", 0},
        {"DIA_WSP_FSI_AXLE3", 0},
        {"DIA_WSP_FSI_AXLE4", 0},
        {"DIA_SPEED_DV1", 0},
        {"DIA_SPEED_DV2", 0},
        {"DIA_SPEED_DV3", 0},
        {"DIA_SPEED_DV4", 0},
        {"DIA_POP_WSP_Y_HOLD_AX1", 0}, // byte8
        {"DIA_POP_WSP_Y_HOLD_AX2", 0},
        {"DIA_POP_WSP_Y_HOLD_AX3", 0},
        {"DIA_POP_WSP_Y_HOLD_AX4", 0},
        {"DIA_POP_WSP_Y_RELEASE_AX1", 0},
        {"DIA_POP_WSP_Y_RELEASE_AX2", 0},
        {"DIA_POP_WSP_Y_RELEASE_AX3", 0},
        {"DIA_POP_WSP_Y_RELEASE_AX4", 0},
        {"DIA_WSP_TIMEOUT_AX1", 0}, // byte9
        {"DIA_WSP_TIMEOUT_AX2", 0},
        {"DIA_WSP_TIMEOUT_AX3", 0},
        {"DIA_WSP_TIMEOUT_AX4", 0},
        {"DIA_UWR_TIMEOUT_BO1", 0},
        {"DIA_UWR_TIMEOUT_BO2", 0},
        {"DIA_WSP_FAILURE_BO1", 0},
        {"DIA_WSP_FAILURE_BO2", 0},
        {"DIA_ASSF", 0}, // byte10
        {"DIA_WSP_TEST_ABORTED", 0},
        {"DIA_WSP_CONF", 0},
        {"DIA_CAR_CONFIGURATION", 0},
        {"DIA_EDACTUAL_Bo1_FAILURE", 0},
        {"DIA_EDACTUAL_Bo2_FAILURE", 0},
        {"bit87", 0},
        {"bit88", 0},
        {"DIA_POP_SA_DIRECTION_S1", 0}, // byte11
        {"DIA_POP_SA_DIRECTION_S2", 0},
        {"DIA_POP_SA_DRYING", 0},
        {"DIA_POP_SA_BLOWOUT", 0},
        {"DIA_SANDING_DISTURBED", 0},
        {"bit94", 0},
        {"bit95", 0},
        {"bit96", 0},
        {"DIA_DCL_INCPRESS", 0}, // byte12
        {"DIA_DCL_DECPRESS", 0},
        {"DIA_DCL_CONFIG", 0},
        {"DIA_DCL_DEVIATION", 0},
        {"DIA_DCL_OFFSET", 0},
        {"DIA_DIRECTBRAKE_DIST", 0},
        {"DIA_EMERGVALVE", 0},
        {"bit104", 0},
        {"DIA_AIR_SUSP_PRESS_LOW", 0}, // byte13
        {"DIA_AIR_SUSP_PRESS_HIGH", 0},
        {"DIA_AIR_SUSP_PRESS_BURST", 0},
        {"DIA_AIR_SUSP_PRESS_ERROR", 0},
        {"DIA_MR_PRESS_LOW", 0},
        {"DIA_MR_PRESS_ERR", 0},
        {"DIA_R_PRESS_LOW", 0},
        {"DIA_R_PRESS_ERROR", 0},
        {"DIA_HBRELEASE_TRAINLINE_IMPL", 0}, // byte14
        {"DIA_TRACTION_TRAINLINE_IMPL", 0},
        {"DIA_EMERGENCY_TRAINLINE_IMPL", 0},
        {"DIA_BRAKE_BITS_IMPL", 0},
        {"DIA_BRAKE_NOT_RELEASED_Bo1", 0},
        {"DIA_BRAKE_NOT_RELEASED_Bo2", 0},
        {"DIA_BRAKE_NOT_APPLIED_Bo1", 0},
        {"DIA_BRAKE_NOT_APPLIED_Bo2", 0},
        {"DIA_PB_NOT_RELEASED", 0}, // byte15
        {"DIA_PB_HOSE_BURST", 0},
        {"DIA_PB_PG_IMPLAUSIBLE", 0},
        {"DIA_MVB_ERROR_BCU", 0},
        {"DIA_MVB_ERROR_TCU", 0},
        {"DIA_MVB_ERROR_VCU", 0},
        {"bit127", 0},
        {"bit128", 0}
    };


    /*m_tableWidget[oa_num][MVB2] = new QTableWidget();
    m_tableWidget[oa_num][MVB2]->setColumnCount(2);
    m_tableWidget[oa_num][MVB2]->setRowCount(m_inputs_map[oa_num][MVB2].size());
    m_tableWidget[oa_num][MVB2]->setHorizontalHeaderLabels(table_name[oa_num][MVB2]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[oa_num][MVB2]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[oa_num][MVB2]->setItem(row, 0, item_name);
        m_tableWidget[oa_num][MVB2]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[oa_num][MVB2]->resizeColumnsToContents();*/

    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[oa_num][MVB2].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[oa_num][MVB2] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[oa_num][MVB2]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[oa_num][MVB2]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[oa_num][MVB2]->setItem(row, column, item_name);
        m_tableWidget[oa_num][MVB2]->setItem(row, column + 1, item_val); // Değer

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[oa_num][MVB2]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[oa_num][MVB2]->columnCount() ;

}




void OA_BCU::update_mvb1_map(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);
    m_inputs_map[oa_num][MVB1].at("XLifeSign")                     = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.XLifeSign;
    m_inputs_map[oa_num][MVB1].at("EBCU_MainVersion")              = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.EBCU_MainVersion;
    m_inputs_map[oa_num][MVB1].at("EBCU_SubVersion")               = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.EBCU_SubVersion;
    m_inputs_map[oa_num][MVB1].at("X_Cpress")                      = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_Cpress;
    m_inputs_map[oa_num][MVB1].at("X_Tpress")                      = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_Tpress;
    m_inputs_map[oa_num][MVB1].at("X_PrkBrPress_1")                = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_PrkBrPress_1;
    m_inputs_map[oa_num][MVB1].at("X_PrkBrPress_2")                = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_PrkBrPress_2;
    m_inputs_map[oa_num][MVB1].at("X_BPPress")                     = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_BPPress;
    m_inputs_map[oa_num][MVB1].at("X_MRPPress")                    = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_MRPPress;
    m_inputs_map[oa_num][MVB1].at("reserved10")                    = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.reserved10;
    m_inputs_map[oa_num][MVB1].at("X_LoadWeight")                  = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_LoadWeight;
    m_inputs_map[oa_num][MVB1].at("X_VAxl1")                       = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_VAxl1;
    m_inputs_map[oa_num][MVB1].at("X_VAxl2")                       = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_VAxl2;
    m_inputs_map[oa_num][MVB1].at("X_VAxl3")                       = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_VAxl3;
    m_inputs_map[oa_num][MVB1].at("X_VAxl4")                       = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_VAxl4;
    m_inputs_map[oa_num][MVB1].at("X_Vref")                        = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_Vref;
    m_inputs_map[oa_num][MVB1].at("reserved23")                    = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.reserved23;
    m_inputs_map[oa_num][MVB1].at("reserved24")                    = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.reserved24;
    m_inputs_map[oa_num][MVB1].at("S_HolBrRe")                     = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_HolBrRe;
    m_inputs_map[oa_num][MVB1].at("V_HolBrRe")                     = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.V_HolBrRe;
    m_inputs_map[oa_num][MVB1].at("S_HolBrAp")                     = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_HolBrAp;
    m_inputs_map[oa_num][MVB1].at("V_HolBrAp")                     = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.V_HolBrAp;
    m_inputs_map[oa_num][MVB1].at("S_PrkBrRe")                     = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_PrkBrRe;
    m_inputs_map[oa_num][MVB1].at("V_PrkBrRe")                     = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.V_PrkBrRe;
    m_inputs_map[oa_num][MVB1].at("S_PrkBrReNot")                  = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_PrkBrReNot;
    m_inputs_map[oa_num][MVB1].at("V_PrkBrReNot")                  = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.V_PrkBrReNot;
    m_inputs_map[oa_num][MVB1].at("S_PnBrRe_Bo1")                  = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_PnBrRe_Bo1;
    m_inputs_map[oa_num][MVB1].at("V_PnBrRe_Bo1")                  = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.V_PnBrRe_Bo1;
    m_inputs_map[oa_num][MVB1].at("S_PnBrAp_Bo1")                  = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_PnBrAp_Bo1;
    m_inputs_map[oa_num][MVB1].at("V_PnBrAp_Bo1")                  = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.V_PnBrAp_Bo1;
    m_inputs_map[oa_num][MVB1].at("S_PnBrRe_Bo2")                  = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_PnBrRe_Bo2;
    m_inputs_map[oa_num][MVB1].at("V_PnBrRe_Bo2")                  = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.V_PnBrRe_Bo2;
    m_inputs_map[oa_num][MVB1].at("S_PnBrAp_Bo2")                  = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_PnBrAp_Bo2;
    m_inputs_map[oa_num][MVB1].at("V_PnBrAp_Bo2")                  = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.V_PnBrAp_Bo2;
    m_inputs_map[oa_num][MVB1].at("S_EmergBrLoopOpen")             = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_EmergBrLoopOpen;
    m_inputs_map[oa_num][MVB1].at("S_TLHolBrRe")                   = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_TLHolBrRe;
    m_inputs_map[oa_num][MVB1].at("S_TLBrakingBit1")               = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_TLBrakingBit1;
    m_inputs_map[oa_num][MVB1].at("S_TLBrakingBit2")               = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_TLBrakingBit2;
    m_inputs_map[oa_num][MVB1].at("S_TLBrakingBit3")               = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_TLBrakingBit3;
    m_inputs_map[oa_num][MVB1].at("S_TLTraction")                  = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_TLTraction;
    m_inputs_map[oa_num][MVB1].at("S_WSPTest_Run")                 = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_WSPTest_Run;
    m_inputs_map[oa_num][MVB1].at("S_WSPTest_Run_abbort")           = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_WSPTest_Run_abbort;
    m_inputs_map[oa_num][MVB1].at("S_WSPactive_Bo1")               = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_WSPactive_Bo1;
    m_inputs_map[oa_num][MVB1].at("S_WSPok_Bo1")                   = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_WSPok_Bo1;
    m_inputs_map[oa_num][MVB1].at("S_WSPactive_Bo2")               = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_WSPactive_Bo2;
    m_inputs_map[oa_num][MVB1].at("S_WSPok_Bo2")                   = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_WSPok_Bo2;
    m_inputs_map[oa_num][MVB1].at("S_Degraded_Mode")               = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_Degraded_Mode;
    m_inputs_map[oa_num][MVB1].at("S_ASC_Mode_active")             = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_ASC_Mode_active;
    m_inputs_map[oa_num][MVB1].at("S_Standstill")                  = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_Standstill;
    m_inputs_map[oa_num][MVB1].at("S_EBCU_EBL_Open_PB")            = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_EBCU_EBL_Open_PB;
    m_inputs_map[oa_num][MVB1].at("IC_PneuBr")                     = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.IC_PneuBr;
    m_inputs_map[oa_num][MVB1].at("IC_DirectBr")                   = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.IC_DirectBr;
    m_inputs_map[oa_num][MVB1].at("IC_Cpress_Bo1")                 = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.IC_Cpress_Bo1;
    m_inputs_map[oa_num][MVB1].at("IC_Cpress_Bo2")                 = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.IC_Cpress_Bo2;
    m_inputs_map[oa_num][MVB1].at("IC_PrkBr")                      = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.IC_PrkBr;
    m_inputs_map[oa_num][MVB1].at("IC_Sanding")                    = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.IC_Sanding;
    m_inputs_map[oa_num][MVB1].at("IC_InDirectBr")                 = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.IC_InDirectBr;
    m_inputs_map[oa_num][MVB1].at("S_DoorsClosedLocked")           = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_DoorsClosedLocked;
    m_inputs_map[oa_num][MVB1].at("S_ED_fade_Out")                 = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_ED_fade_Out;
    m_inputs_map[oa_num][MVB1].at("S_BpApValid")                   = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_BpApValid;
    m_inputs_map[oa_num][MVB1].at("S_BpAP")                        = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_BpAP;
    m_inputs_map[oa_num][MVB1].at("S_Sanding_Heating_Release")     = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_Sanding_Heating_Release;
    m_inputs_map[oa_num][MVB1].at("S_Sanding_Active")             = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_Sanding_Active;
    m_inputs_map[oa_num][MVB1].at("bit246")                        = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.bit246;
    m_inputs_map[oa_num][MVB1].at("bit247")                        = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.bit247;
    m_inputs_map[oa_num][MVB1].at("bit248")                        = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.bit248;
    //m_inputs_map[oa_num][MVB1].at("reserved31")                   = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.reserved31;

}

void OA_BCU::update_mvb2_map(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);

    m_inputs_map[oa_num][MVB2].at("XLifeSign") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.XLifeSign;

    // Byte 2
    m_inputs_map[oa_num][MVB2].at("DIA_BOARD_CB09_02") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARD_CB09_02;
    m_inputs_map[oa_num][MVB2].at("DIA_BOARD_MB04_04") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARD_MB04_04;
    m_inputs_map[oa_num][MVB2].at("DIA_BOARD_MB03_06") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARD_MB03_06;
    m_inputs_map[oa_num][MVB2].at("DIA_BOARD_MB03_07") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARD_MB03_07;
    m_inputs_map[oa_num][MVB2].at("DIA_BOARD_EB01_08") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARD_EB01_08;
    m_inputs_map[oa_num][MVB2].at("DIA_BOARD_EB02_09") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARD_EB02_09;
    m_inputs_map[oa_num][MVB2].at("bit23") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit23;
    m_inputs_map[oa_num][MVB2].at("bit24") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit24;

    // Byte 3
    m_inputs_map[oa_num][MVB2].at("DIA_BOARDCODING_MB04_04") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARDCODING_MB04_04;
    m_inputs_map[oa_num][MVB2].at("DIA_BOARDCODING_MB03_06") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARDCODING_MB03_06;
    m_inputs_map[oa_num][MVB2].at("DIA_BOARDCODING_MB03_07") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARDCODING_MB03_07;
    m_inputs_map[oa_num][MVB2].at("DIA_BOARDCODING_EB01_08") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARDCODING_EB01_08;
    m_inputs_map[oa_num][MVB2].at("DIA_BOARDCODING_EB02_09") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARDCODING_EB02_09;
    m_inputs_map[oa_num][MVB2].at("bit30") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit30;
    m_inputs_map[oa_num][MVB2].at("bit31") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit31;
    m_inputs_map[oa_num][MVB2].at("bit32") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit32;

    // Byte 4
    m_inputs_map[oa_num][MVB2].at("DIA_CAN_COMM_CB09_02") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_CAN_COMM_CB09_02;
    m_inputs_map[oa_num][MVB2].at("DIA_CAN_COMM_MB04_03") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_CAN_COMM_MB04_03;
    m_inputs_map[oa_num][MVB2].at("DIA_CAN_COMM_MB03_06") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_CAN_COMM_MB03_06;
    m_inputs_map[oa_num][MVB2].at("DIA_CAN_COMM_MB03_07") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_CAN_COMM_MB03_07;
    m_inputs_map[oa_num][MVB2].at("DIA_CAN_COMM_EB01_08") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_CAN_COMM_EB01_08;
    m_inputs_map[oa_num][MVB2].at("DIA_CAN_COMM_EB02_09") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_CAN_COMM_EB02_09;
    m_inputs_map[oa_num][MVB2].at("bit39") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit39;
    m_inputs_map[oa_num][MVB2].at("bit40") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit40;

    // Byte 5
    m_inputs_map[oa_num][MVB2].at("DIA_PSENSOR_C") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PSENSOR_C;
    m_inputs_map[oa_num][MVB2].at("DIA_PSENSOR_BP") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PSENSOR_BP;
    m_inputs_map[oa_num][MVB2].at("DIA_PSENSOR1_PB") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PSENSOR1_PB;
    m_inputs_map[oa_num][MVB2].at("DIA_PSENSOR2_PB") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PSENSOR2_PB;
    m_inputs_map[oa_num][MVB2].at("DIA_PSENSOR_CVD") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PSENSOR_CVD;
    m_inputs_map[oa_num][MVB2].at("DIA_PSENSOR_T") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PSENSOR_T;
    m_inputs_map[oa_num][MVB2].at("DIA_PSENSOR_R") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PSENSOR_R;
    m_inputs_map[oa_num][MVB2].at("DIA_PSENSOR_CVI") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PSENSOR_CVI;

    // Byte 6
    m_inputs_map[oa_num][MVB2].at("DIA_PSENSOR_MRP") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PSENSOR_MRP;
    m_inputs_map[oa_num][MVB2].at("DIA_REL_EBCU_FCT_OK") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_REL_EBCU_FCT_OK;
    m_inputs_map[oa_num][MVB2].at("DIA_REL_EBCU_EBLOOP_Y_OPEN") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_REL_EBCU_EBLOOP_Y_OPEN;
    m_inputs_map[oa_num][MVB2].at("DIA_REL_EBCU_C_EDCUTOFF") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_REL_EBCU_C_EDCUTOFF;
    m_inputs_map[oa_num][MVB2].at("DIA_REL_WSP_R_VLT5KMHDOOR") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_REL_WSP_R_VLT5KMHDOOR;
    m_inputs_map[oa_num][MVB2].at("DIA_REL_WSP_R_VGT5KMHDOOR") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_REL_WSP_R_VGT5KMHDOOR;
    m_inputs_map[oa_num][MVB2].at("DIA_REL_WSP_R_VGT10KMHDOOR") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_REL_WSP_R_VGT10KMHDOOR;
    m_inputs_map[oa_num][MVB2].at("bit56") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit56;

    // Byte 7
    m_inputs_map[oa_num][MVB2].at("DIA_WSP_FSI_AXLE1") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_FSI_AXLE1;
    m_inputs_map[oa_num][MVB2].at("DIA_WSP_FSI_AXLE2") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_FSI_AXLE2;
    m_inputs_map[oa_num][MVB2].at("DIA_WSP_FSI_AXLE3") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_FSI_AXLE3;
    m_inputs_map[oa_num][MVB2].at("DIA_WSP_FSI_AXLE4") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_FSI_AXLE4;
    m_inputs_map[oa_num][MVB2].at("DIA_SPEED_DV1") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_SPEED_DV1;
    m_inputs_map[oa_num][MVB2].at("DIA_SPEED_DV2") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_SPEED_DV2;
    m_inputs_map[oa_num][MVB2].at("DIA_SPEED_DV3") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_SPEED_DV3;
    m_inputs_map[oa_num][MVB2].at("DIA_SPEED_DV4") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_SPEED_DV4;

    // Byte 8
    m_inputs_map[oa_num][MVB2].at("DIA_POP_WSP_Y_HOLD_AX1") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_HOLD_AX1;
    m_inputs_map[oa_num][MVB2].at("DIA_POP_WSP_Y_HOLD_AX2") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_HOLD_AX2;
    m_inputs_map[oa_num][MVB2].at("DIA_POP_WSP_Y_HOLD_AX3") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_HOLD_AX3;
    m_inputs_map[oa_num][MVB2].at("DIA_POP_WSP_Y_HOLD_AX4") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_HOLD_AX4;
    m_inputs_map[oa_num][MVB2].at("DIA_POP_WSP_Y_RELEASE_AX1") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_RELEASE_AX1;
    m_inputs_map[oa_num][MVB2].at("DIA_POP_WSP_Y_RELEASE_AX2") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_RELEASE_AX2;
    m_inputs_map[oa_num][MVB2].at("DIA_POP_WSP_Y_RELEASE_AX3") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_RELEASE_AX3;
    m_inputs_map[oa_num][MVB2].at("DIA_POP_WSP_Y_RELEASE_AX4") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_RELEASE_AX4;

    // Byte 9
    m_inputs_map[oa_num][MVB2].at("DIA_WSP_TIMEOUT_AX1") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_TIMEOUT_AX1;
    m_inputs_map[oa_num][MVB2].at("DIA_WSP_TIMEOUT_AX2") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_TIMEOUT_AX2;
    m_inputs_map[oa_num][MVB2].at("DIA_WSP_TIMEOUT_AX3") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_TIMEOUT_AX3;
    m_inputs_map[oa_num][MVB2].at("DIA_WSP_TIMEOUT_AX4") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_TIMEOUT_AX4;
    m_inputs_map[oa_num][MVB2].at("DIA_UWR_TIMEOUT_BO1") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_UWR_TIMEOUT_BO1;
    m_inputs_map[oa_num][MVB2].at("DIA_UWR_TIMEOUT_BO2") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_UWR_TIMEOUT_BO2;
    m_inputs_map[oa_num][MVB2].at("DIA_WSP_FAILURE_BO1") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_FAILURE_BO1;
    m_inputs_map[oa_num][MVB2].at("DIA_WSP_FAILURE_BO2") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_FAILURE_BO2;

    // Byte 10
    m_inputs_map[oa_num][MVB2].at("DIA_ASSF") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_ASSF;
    m_inputs_map[oa_num][MVB2].at("DIA_WSP_TEST_ABORTED") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_TEST_ABORTED;
    m_inputs_map[oa_num][MVB2].at("DIA_WSP_CONF") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_CONF;
    m_inputs_map[oa_num][MVB2].at("DIA_CAR_CONFIGURATION") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_CAR_CONFIGURATION;
    m_inputs_map[oa_num][MVB2].at("DIA_EDACTUAL_Bo1_FAILURE") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_EDACTUAL_Bo1_FAILURE;
    m_inputs_map[oa_num][MVB2].at("DIA_EDACTUAL_Bo2_FAILURE") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_EDACTUAL_Bo2_FAILURE;
    m_inputs_map[oa_num][MVB2].at("bit87") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit87;
    m_inputs_map[oa_num][MVB2].at("bit88") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit88;

    // Byte 11
    m_inputs_map[oa_num][MVB2].at("DIA_POP_SA_DIRECTION_S1") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_SA_DIRECTION_S1;
    m_inputs_map[oa_num][MVB2].at("DIA_POP_SA_DIRECTION_S2") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_SA_DIRECTION_S2;
    m_inputs_map[oa_num][MVB2].at("DIA_POP_SA_DRYING") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_SA_DRYING;
    m_inputs_map[oa_num][MVB2].at("DIA_POP_SA_BLOWOUT") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_SA_BLOWOUT;
    m_inputs_map[oa_num][MVB2].at("DIA_SANDING_DISTURBED") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_SANDING_DISTURBED;
    m_inputs_map[oa_num][MVB2].at("bit94") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit94;
    m_inputs_map[oa_num][MVB2].at("bit95") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit95;
    m_inputs_map[oa_num][MVB2].at("bit96") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit96;

    // Byte 12
    m_inputs_map[oa_num][MVB2].at("DIA_DCL_INCPRESS") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_DCL_INCPRESS;
    m_inputs_map[oa_num][MVB2].at("DIA_DCL_DECPRESS") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_DCL_DECPRESS;
    m_inputs_map[oa_num][MVB2].at("DIA_DCL_CONFIG") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_DCL_CONFIG;
    m_inputs_map[oa_num][MVB2].at("DIA_DCL_DEVIATION") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_DCL_DEVIATION;
    m_inputs_map[oa_num][MVB2].at("DIA_DCL_OFFSET") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_DCL_OFFSET;
    m_inputs_map[oa_num][MVB2].at("DIA_DIRECTBRAKE_DIST") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_DIRECTBRAKE_DIST;
    m_inputs_map[oa_num][MVB2].at("DIA_EMERGVALVE") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_EMERGVALVE;
    m_inputs_map[oa_num][MVB2].at("bit104") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit104;

    // Byte 13
    m_inputs_map[oa_num][MVB2].at("DIA_AIR_SUSP_PRESS_LOW") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_AIR_SUSP_PRESS_LOW;
    m_inputs_map[oa_num][MVB2].at("DIA_AIR_SUSP_PRESS_HIGH") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_AIR_SUSP_PRESS_HIGH;
    m_inputs_map[oa_num][MVB2].at("DIA_AIR_SUSP_PRESS_BURST") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_AIR_SUSP_PRESS_BURST;
    m_inputs_map[oa_num][MVB2].at("DIA_AIR_SUSP_PRESS_ERROR") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_AIR_SUSP_PRESS_ERROR;
    m_inputs_map[oa_num][MVB2].at("DIA_MR_PRESS_LOW") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_MR_PRESS_LOW;
    m_inputs_map[oa_num][MVB2].at("DIA_MR_PRESS_ERR") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_MR_PRESS_ERR;
    m_inputs_map[oa_num][MVB2].at("DIA_R_PRESS_LOW") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_R_PRESS_LOW;
    m_inputs_map[oa_num][MVB2].at("DIA_R_PRESS_ERROR") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_R_PRESS_ERROR;

    // Byte 14
    m_inputs_map[oa_num][MVB2].at("DIA_HBRELEASE_TRAINLINE_IMPL") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_HBRELEASE_TRAINLINE_IMPL;
    m_inputs_map[oa_num][MVB2].at("DIA_TRACTION_TRAINLINE_IMPL") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_TRACTION_TRAINLINE_IMPL;
    m_inputs_map[oa_num][MVB2].at("DIA_EMERGENCY_TRAINLINE_IMPL") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_EMERGENCY_TRAINLINE_IMPL;
    m_inputs_map[oa_num][MVB2].at("DIA_BRAKE_BITS_IMPL") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BRAKE_BITS_IMPL;
    m_inputs_map[oa_num][MVB2].at("DIA_BRAKE_NOT_RELEASED_Bo1") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BRAKE_NOT_RELEASED_Bo1;
    m_inputs_map[oa_num][MVB2].at("DIA_BRAKE_NOT_RELEASED_Bo2") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BRAKE_NOT_RELEASED_Bo2;
    m_inputs_map[oa_num][MVB2].at("DIA_BRAKE_NOT_APPLIED_Bo1") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BRAKE_NOT_APPLIED_Bo1;
    m_inputs_map[oa_num][MVB2].at("DIA_BRAKE_NOT_APPLIED_Bo2") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BRAKE_NOT_APPLIED_Bo2;

    // Byte 15
    m_inputs_map[oa_num][MVB2].at("DIA_PB_NOT_RELEASED") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PB_NOT_RELEASED;
    m_inputs_map[oa_num][MVB2].at("DIA_PB_HOSE_BURST") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PB_HOSE_BURST;
    m_inputs_map[oa_num][MVB2].at("DIA_PB_PG_IMPLAUSIBLE") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PB_PG_IMPLAUSIBLE;
    m_inputs_map[oa_num][MVB2].at("DIA_MVB_ERROR_BCU") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_MVB_ERROR_BCU;
    m_inputs_map[oa_num][MVB2].at("DIA_MVB_ERROR_TCU") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_MVB_ERROR_TCU;
    m_inputs_map[oa_num][MVB2].at("DIA_MVB_ERROR_VCU") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_MVB_ERROR_VCU;
    m_inputs_map[oa_num][MVB2].at("bit127") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit127;
    m_inputs_map[oa_num][MVB2].at("bit128") = m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit128;

}




void OA_BCU::update_struct_with_map(OA_VEHICLE_NUM oa_x_num, OA_MVB_NUM mvb_num)
{
    int oa_num = static_cast<int>(oa_x_num);
    // Define a lambda function to reduce redundancy
    auto setInputMap = [&](const QString& signal_name) {
        m_inputs_map[oa_num][mvb_num][signal_name] = utils::getTableWidgetValueByNameWithoutColumn(m_tableWidget[oa_num][mvb_num], signal_name).toInt();
    };
    // update map with given tableWidget values
    for(const auto& map : m_inputs_map[oa_num][mvb_num])
    {
        setInputMap(map.first);
    }
    // set struct parameters with given updated map parameters
    set_struct_mvb1(oa_x_num);
    set_struct_mvb2(oa_x_num);
    //set_struct_mvb3(oa_x_num);
}

void OA_BCU::set_struct_mvb1(OA_VEHICLE_NUM oa_x_num)
{

    int oa_num = static_cast<int>(oa_x_num);
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.XLifeSign                   = m_inputs_map[oa_num][MVB1].at("XLifeSign");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.EBCU_MainVersion            = m_inputs_map[oa_num][MVB1].at("EBCU_MainVersion");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.EBCU_SubVersion             = m_inputs_map[oa_num][MVB1].at("EBCU_SubVersion");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_Cpress                   = m_inputs_map[oa_num][MVB1].at("X_Cpress");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_Tpress                   = m_inputs_map[oa_num][MVB1].at("X_Tpress");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_PrkBrPress_1             = m_inputs_map[oa_num][MVB1].at("X_PrkBrPress_1");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_PrkBrPress_2             = m_inputs_map[oa_num][MVB1].at("X_PrkBrPress_2");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_BPPress                   = m_inputs_map[oa_num][MVB1].at("X_BPPress");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_MRPPress                  = m_inputs_map[oa_num][MVB1].at("X_MRPPress");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_LoadWeight                = m_inputs_map[oa_num][MVB1].at("X_LoadWeight");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_VAxl1                    = m_inputs_map[oa_num][MVB1].at("X_VAxl1");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_VAxl2                    = m_inputs_map[oa_num][MVB1].at("X_VAxl2");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_VAxl3                    = m_inputs_map[oa_num][MVB1].at("X_VAxl3");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_VAxl4                    = m_inputs_map[oa_num][MVB1].at("X_VAxl4");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.X_Vref                      = m_inputs_map[oa_num][MVB1].at("X_Vref");
    // Reserved alanlar
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.reserved10                  = m_inputs_map[oa_num][MVB1].at("reserved10");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.reserved23                  = m_inputs_map[oa_num][MVB1].at("reserved23");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.reserved24                  = m_inputs_map[oa_num][MVB1].at("reserved24");
    // Bit alanları
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_HolBrRe                  = m_inputs_map[oa_num][MVB1].at("S_HolBrRe");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.V_HolBrRe                  = m_inputs_map[oa_num][MVB1].at("V_HolBrRe");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_HolBrAp                  = m_inputs_map[oa_num][MVB1].at("S_HolBrAp");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.V_HolBrAp                  = m_inputs_map[oa_num][MVB1].at("V_HolBrAp");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_PrkBrRe                  = m_inputs_map[oa_num][MVB1].at("S_PrkBrRe");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.V_PrkBrRe                  = m_inputs_map[oa_num][MVB1].at("V_PrkBrRe");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_PrkBrReNot               = m_inputs_map[oa_num][MVB1].at("S_PrkBrReNot");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.V_PrkBrReNot               = m_inputs_map[oa_num][MVB1].at("V_PrkBrReNot");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_PnBrRe_Bo1               = m_inputs_map[oa_num][MVB1].at("S_PnBrRe_Bo1");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.V_PnBrRe_Bo1               = m_inputs_map[oa_num][MVB1].at("V_PnBrRe_Bo1");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_PnBrAp_Bo1               = m_inputs_map[oa_num][MVB1].at("S_PnBrAp_Bo1");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.V_PnBrAp_Bo1               = m_inputs_map[oa_num][MVB1].at("V_PnBrAp_Bo1");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_PnBrRe_Bo2               = m_inputs_map[oa_num][MVB1].at("S_PnBrRe_Bo2");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.V_PnBrRe_Bo2               = m_inputs_map[oa_num][MVB1].at("V_PnBrRe_Bo2");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_PnBrAp_Bo2               = m_inputs_map[oa_num][MVB1].at("S_PnBrAp_Bo2");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.V_PnBrAp_Bo2               = m_inputs_map[oa_num][MVB1].at("V_PnBrAp_Bo2");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_EmergBrLoopOpen          = m_inputs_map[oa_num][MVB1].at("S_EmergBrLoopOpen");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_TLHolBrRe                = m_inputs_map[oa_num][MVB1].at("S_TLHolBrRe");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_TLBrakingBit1            = m_inputs_map[oa_num][MVB1].at("S_TLBrakingBit1");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_TLBrakingBit2            = m_inputs_map[oa_num][MVB1].at("S_TLBrakingBit2");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_TLBrakingBit3            = m_inputs_map[oa_num][MVB1].at("S_TLBrakingBit3");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_TLTraction               = m_inputs_map[oa_num][MVB1].at("S_TLTraction");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_WSPTest_Run              = m_inputs_map[oa_num][MVB1].at("S_WSPTest_Run");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_WSPTest_Run_abbort       = m_inputs_map[oa_num][MVB1].at("S_WSPTest_Run_abbort");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_WSPactive_Bo1            = m_inputs_map[oa_num][MVB1].at("S_WSPactive_Bo1");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_WSPok_Bo1                = m_inputs_map[oa_num][MVB1].at("S_WSPok_Bo1");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_WSPactive_Bo2            = m_inputs_map[oa_num][MVB1].at("S_WSPactive_Bo2");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_WSPok_Bo2                = m_inputs_map[oa_num][MVB1].at("S_WSPok_Bo2");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_Degraded_Mode             = m_inputs_map[oa_num][MVB1].at("S_Degraded_Mode");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_ASC_Mode_active           = m_inputs_map[oa_num][MVB1].at("S_ASC_Mode_active");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_Standstill                = m_inputs_map[oa_num][MVB1].at("S_Standstill");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_EBCU_EBL_Open_PB         = m_inputs_map[oa_num][MVB1].at("S_EBCU_EBL_Open_PB");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.IC_PneuBr                  = m_inputs_map[oa_num][MVB1].at("IC_PneuBr");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.IC_DirectBr                = m_inputs_map[oa_num][MVB1].at("IC_DirectBr");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.IC_Cpress_Bo1              = m_inputs_map[oa_num][MVB1].at("IC_Cpress_Bo1");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.IC_Cpress_Bo2              = m_inputs_map[oa_num][MVB1].at("IC_Cpress_Bo2");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.IC_PrkBr                   = m_inputs_map[oa_num][MVB1].at("IC_PrkBr");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.IC_Sanding                  = m_inputs_map[oa_num][MVB1].at("IC_Sanding");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.IC_InDirectBr               = m_inputs_map[oa_num][MVB1].at("IC_InDirectBr");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_DoorsClosedLocked         = m_inputs_map[oa_num][MVB1].at("S_DoorsClosedLocked");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_ED_fade_Out              = m_inputs_map[oa_num][MVB1].at("S_ED_fade_Out");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_BpApValid                = m_inputs_map[oa_num][MVB1].at("S_BpApValid");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_BpAP                     = m_inputs_map[oa_num][MVB1].at("S_BpAP");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_Sanding_Heating_Release   = m_inputs_map[oa_num][MVB1].at("S_Sanding_Heating_Release");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.S_Sanding_Active            = m_inputs_map[oa_num][MVB1].at("S_Sanding_Active");
    // Diğer bit alanları
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.bit246                     = m_inputs_map[oa_num][MVB1].at("bit246");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.bit247                     = m_inputs_map[oa_num][MVB1].at("bit247");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.bit248                     = m_inputs_map[oa_num][MVB1].at("bit248");
    //m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb1.bits.reserved31                 = m_inputs_map[oa_num][MVB1].at("reserved31");

}

void OA_BCU::set_struct_mvb2(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);

    // Byte 0
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.XLifeSign = m_inputs_map[oa_num][MVB2].at("XLifeSign");

    // Byte 2
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARD_CB09_02 = m_inputs_map[oa_num][MVB2].at("DIA_BOARD_CB09_02");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARD_MB04_04 = m_inputs_map[oa_num][MVB2].at("DIA_BOARD_MB04_04");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARD_MB03_06 = m_inputs_map[oa_num][MVB2].at("DIA_BOARD_MB03_06");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARD_MB03_07 = m_inputs_map[oa_num][MVB2].at("DIA_BOARD_MB03_07");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARD_EB01_08 = m_inputs_map[oa_num][MVB2].at("DIA_BOARD_EB01_08");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARD_EB02_09 = m_inputs_map[oa_num][MVB2].at("DIA_BOARD_EB02_09");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit23 = m_inputs_map[oa_num][MVB2].at("bit23");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit24 = m_inputs_map[oa_num][MVB2].at("bit24");

    // Byte 3
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARDCODING_MB04_04 = m_inputs_map[oa_num][MVB2].at("DIA_BOARDCODING_MB04_04");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARDCODING_MB03_06 = m_inputs_map[oa_num][MVB2].at("DIA_BOARDCODING_MB03_06");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARDCODING_MB03_07 = m_inputs_map[oa_num][MVB2].at("DIA_BOARDCODING_MB03_07");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARDCODING_EB01_08 = m_inputs_map[oa_num][MVB2].at("DIA_BOARDCODING_EB01_08");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BOARDCODING_EB02_09 = m_inputs_map[oa_num][MVB2].at("DIA_BOARDCODING_EB02_09");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit30 = m_inputs_map[oa_num][MVB2].at("bit30");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit31 = m_inputs_map[oa_num][MVB2].at("bit31");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit32 = m_inputs_map[oa_num][MVB2].at("bit32");

    // Byte 4
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_CAN_COMM_CB09_02 = m_inputs_map[oa_num][MVB2].at("DIA_CAN_COMM_CB09_02");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_CAN_COMM_MB04_03 = m_inputs_map[oa_num][MVB2].at("DIA_CAN_COMM_MB04_03");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_CAN_COMM_MB03_06 = m_inputs_map[oa_num][MVB2].at("DIA_CAN_COMM_MB03_06");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_CAN_COMM_MB03_07 = m_inputs_map[oa_num][MVB2].at("DIA_CAN_COMM_MB03_07");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_CAN_COMM_EB01_08 = m_inputs_map[oa_num][MVB2].at("DIA_CAN_COMM_EB01_08");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_CAN_COMM_EB02_09 = m_inputs_map[oa_num][MVB2].at("DIA_CAN_COMM_EB02_09");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit39 = m_inputs_map[oa_num][MVB2].at("bit39");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit40 = m_inputs_map[oa_num][MVB2].at("bit40");

    // Byte 5
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PSENSOR_C = m_inputs_map[oa_num][MVB2].at("DIA_PSENSOR_C");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PSENSOR_BP = m_inputs_map[oa_num][MVB2].at("DIA_PSENSOR_BP");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PSENSOR1_PB = m_inputs_map[oa_num][MVB2].at("DIA_PSENSOR1_PB");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PSENSOR2_PB = m_inputs_map[oa_num][MVB2].at("DIA_PSENSOR2_PB");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PSENSOR_CVD = m_inputs_map[oa_num][MVB2].at("DIA_PSENSOR_CVD");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PSENSOR_T = m_inputs_map[oa_num][MVB2].at("DIA_PSENSOR_T");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PSENSOR_R = m_inputs_map[oa_num][MVB2].at("DIA_PSENSOR_R");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PSENSOR_CVI = m_inputs_map[oa_num][MVB2].at("DIA_PSENSOR_CVI");


    // Byte 6
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PSENSOR_MRP = m_inputs_map[oa_num][MVB2].at("DIA_PSENSOR_MRP");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_REL_EBCU_FCT_OK = m_inputs_map[oa_num][MVB2].at("DIA_REL_EBCU_FCT_OK");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_REL_EBCU_EBLOOP_Y_OPEN = m_inputs_map[oa_num][MVB2].at("DIA_REL_EBCU_EBLOOP_Y_OPEN");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_REL_EBCU_C_EDCUTOFF = m_inputs_map[oa_num][MVB2].at("DIA_REL_EBCU_C_EDCUTOFF");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_REL_WSP_R_VLT5KMHDOOR = m_inputs_map[oa_num][MVB2].at("DIA_REL_WSP_R_VLT5KMHDOOR");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_REL_WSP_R_VGT5KMHDOOR = m_inputs_map[oa_num][MVB2].at("DIA_REL_WSP_R_VGT5KMHDOOR");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_REL_WSP_R_VGT10KMHDOOR = m_inputs_map[oa_num][MVB2].at("bit56");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit56 = m_inputs_map[oa_num][MVB2].at("DIA_REL_WSP_R_VGT10KMHDOOR");




    // Byte 7
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_FSI_AXLE1 = m_inputs_map[oa_num][MVB2].at("DIA_WSP_FSI_AXLE1");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_FSI_AXLE2 = m_inputs_map[oa_num][MVB2].at("DIA_WSP_FSI_AXLE2");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_FSI_AXLE3  = m_inputs_map[oa_num][MVB2].at("DIA_WSP_FSI_AXLE3");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_FSI_AXLE4 = m_inputs_map[oa_num][MVB2].at("DIA_WSP_FSI_AXLE4");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_SPEED_DV1 = m_inputs_map[oa_num][MVB2].at("DIA_SPEED_DV1");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_SPEED_DV2  = m_inputs_map[oa_num][MVB2].at("DIA_SPEED_DV2");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_SPEED_DV3  = m_inputs_map[oa_num][MVB2].at("DIA_SPEED_DV3");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_SPEED_DV4  = m_inputs_map[oa_num][MVB2].at("DIA_SPEED_DV4");


    // Byte 8
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_HOLD_AX1 = m_inputs_map[oa_num][MVB2].at("DIA_POP_WSP_Y_HOLD_AX1");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_HOLD_AX2 = m_inputs_map[oa_num][MVB2].at("DIA_POP_WSP_Y_HOLD_AX2");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_HOLD_AX3 = m_inputs_map[oa_num][MVB2].at("DIA_POP_WSP_Y_HOLD_AX3");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_HOLD_AX4 = m_inputs_map[oa_num][MVB2].at("DIA_POP_WSP_Y_HOLD_AX4");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_RELEASE_AX1 = m_inputs_map[oa_num][MVB2].at("DIA_POP_WSP_Y_RELEASE_AX1");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_RELEASE_AX2 = m_inputs_map[oa_num][MVB2].at("DIA_POP_WSP_Y_RELEASE_AX2");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_RELEASE_AX3 = m_inputs_map[oa_num][MVB2].at("DIA_POP_WSP_Y_RELEASE_AX3");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_WSP_Y_RELEASE_AX4 = m_inputs_map[oa_num][MVB2].at("DIA_POP_WSP_Y_RELEASE_AX4");

    // Byte 9
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_TIMEOUT_AX1= m_inputs_map[oa_num][MVB2].at("DIA_WSP_TIMEOUT_AX1");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_TIMEOUT_AX2= m_inputs_map[oa_num][MVB2].at("DIA_WSP_TIMEOUT_AX2");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_TIMEOUT_AX3= m_inputs_map[oa_num][MVB2].at("DIA_WSP_TIMEOUT_AX3");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_TIMEOUT_AX4= m_inputs_map[oa_num][MVB2].at("DIA_WSP_TIMEOUT_AX4");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_UWR_TIMEOUT_BO1= m_inputs_map[oa_num][MVB2].at("DIA_UWR_TIMEOUT_BO1");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_UWR_TIMEOUT_BO2= m_inputs_map[oa_num][MVB2].at("DIA_UWR_TIMEOUT_BO2");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_FAILURE_BO1= m_inputs_map[oa_num][MVB2].at("DIA_WSP_FAILURE_BO1");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_FAILURE_BO2= m_inputs_map[oa_num][MVB2].at("DIA_WSP_FAILURE_BO2");

    // Byte 10
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_ASSF= m_inputs_map[oa_num][MVB2].at("DIA_ASSF");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_TEST_ABORTED = m_inputs_map[oa_num][MVB2].at("DIA_WSP_TEST_ABORTED");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_WSP_CONF = m_inputs_map[oa_num][MVB2].at("DIA_WSP_CONF");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_CAR_CONFIGURATION  = m_inputs_map[oa_num][MVB2].at("DIA_CAR_CONFIGURATION");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_EDACTUAL_Bo1_FAILURE= m_inputs_map[oa_num][MVB2].at("DIA_EDACTUAL_Bo1_FAILURE");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_EDACTUAL_Bo2_FAILURE= m_inputs_map[oa_num][MVB2].at("DIA_EDACTUAL_Bo2_FAILURE");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit87 = m_inputs_map[oa_num][MVB2].at("bit87");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit88 = m_inputs_map[oa_num][MVB2].at("bit88");

    // Byte 11
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_SA_DIRECTION_S1 = m_inputs_map[oa_num][MVB2].at("DIA_POP_SA_DIRECTION_S1");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_SA_DIRECTION_S2 = m_inputs_map[oa_num][MVB2].at("DIA_POP_SA_DIRECTION_S2");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_SA_DRYING  = m_inputs_map[oa_num][MVB2].at("DIA_POP_SA_DRYING");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_POP_SA_BLOWOUT  = m_inputs_map[oa_num][MVB2].at("DIA_POP_SA_BLOWOUT");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_SANDING_DISTURBED = m_inputs_map[oa_num][MVB2].at("DIA_SANDING_DISTURBED");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit94  = m_inputs_map[oa_num][MVB2].at("bit94");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit95  = m_inputs_map[oa_num][MVB2].at("bit95");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit96  = m_inputs_map[oa_num][MVB2].at("bit96");

    // Byte 12
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_DCL_INCPRESS= m_inputs_map[oa_num][MVB2].at("DIA_DCL_INCPRESS");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_DCL_DECPRESS = m_inputs_map[oa_num][MVB2].at("DIA_DCL_DECPRESS");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_DCL_CONFIG= m_inputs_map[oa_num][MVB2].at("DIA_DCL_CONFIG");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_DCL_DEVIATION  = m_inputs_map[oa_num][MVB2].at("DIA_DCL_DEVIATION");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_DCL_OFFSET  = m_inputs_map[oa_num][MVB2].at("DIA_DCL_OFFSET");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_DIRECTBRAKE_DIST  = m_inputs_map[oa_num][MVB2].at("DIA_DIRECTBRAKE_DIST");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_EMERGVALVE  = m_inputs_map[oa_num][MVB2].at("DIA_EMERGVALVE");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit104 = m_inputs_map[oa_num][MVB2].at("bit104");


    // Byte 13
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_AIR_SUSP_PRESS_LOW = m_inputs_map[oa_num][MVB2].at("DIA_AIR_SUSP_PRESS_LOW");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_AIR_SUSP_PRESS_HIGH = m_inputs_map[oa_num][MVB2].at("DIA_AIR_SUSP_PRESS_HIGH");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_AIR_SUSP_PRESS_BURST = m_inputs_map[oa_num][MVB2].at("DIA_AIR_SUSP_PRESS_BURST");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_AIR_SUSP_PRESS_ERROR = m_inputs_map[oa_num][MVB2].at("DIA_AIR_SUSP_PRESS_ERROR");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_MR_PRESS_LOW = m_inputs_map[oa_num][MVB2].at("DIA_MR_PRESS_LOW");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_MR_PRESS_ERR = m_inputs_map[oa_num][MVB2].at("DIA_MR_PRESS_ERR");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_R_PRESS_LOW = m_inputs_map[oa_num][MVB2].at("DIA_R_PRESS_LOW");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_R_PRESS_ERROR = m_inputs_map[oa_num][MVB2].at("DIA_R_PRESS_ERROR");



    // Byte 14
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_HBRELEASE_TRAINLINE_IMPL= m_inputs_map[oa_num][MVB2].at("DIA_HBRELEASE_TRAINLINE_IMPL");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_TRACTION_TRAINLINE_IMPL = m_inputs_map[oa_num][MVB2].at("DIA_TRACTION_TRAINLINE_IMPL");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_EMERGENCY_TRAINLINE_IMPL = m_inputs_map[oa_num][MVB2].at("DIA_EMERGENCY_TRAINLINE_IMPL");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BRAKE_BITS_IMPL = m_inputs_map[oa_num][MVB2].at("DIA_BRAKE_BITS_IMPL");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BRAKE_NOT_RELEASED_Bo1 = m_inputs_map[oa_num][MVB2].at("DIA_BRAKE_NOT_RELEASED_Bo1");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BRAKE_NOT_RELEASED_Bo2 = m_inputs_map[oa_num][MVB2].at("DIA_BRAKE_NOT_RELEASED_Bo2");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BRAKE_NOT_APPLIED_Bo1 = m_inputs_map[oa_num][MVB2].at("DIA_BRAKE_NOT_APPLIED_Bo1");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_BRAKE_NOT_APPLIED_Bo2 = m_inputs_map[oa_num][MVB2].at("DIA_BRAKE_NOT_APPLIED_Bo2");



    // Byte 15
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PB_NOT_RELEASED = m_inputs_map[oa_num][MVB2].at("DIA_PB_NOT_RELEASED");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PB_HOSE_BURST = m_inputs_map[oa_num][MVB2].at("DIA_PB_HOSE_BURST");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_PB_PG_IMPLAUSIBLE  = m_inputs_map[oa_num][MVB2].at("DIA_PB_PG_IMPLAUSIBLE");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_MVB_ERROR_BCU = m_inputs_map[oa_num][MVB2].at("DIA_MVB_ERROR_BCU");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_MVB_ERROR_TCU = m_inputs_map[oa_num][MVB2].at("DIA_MVB_ERROR_TCU");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.DIA_MVB_ERROR_VCU = m_inputs_map[oa_num][MVB2].at("DIA_MVB_ERROR_VCU");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit127 = m_inputs_map[oa_num][MVB2].at("bit127");
    m_oa_x_bcu[oa_num].oa_bcu_ccu_mvb2.bits.bit128 = m_inputs_map[oa_num][MVB2].at("bit128");

}






