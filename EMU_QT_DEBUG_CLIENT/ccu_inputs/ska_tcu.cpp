#include "ska_tcu.h"
#include "utils.h"


SKA_TCU::SKA_TCU(QObject *parent)
    : QObject{parent}
{

    memset(&m_ska_x_tcu, 0, sizeof(m_ska_x_tcu));

    //init_ska_x_hvac1_table(SKA_VEHICLE_NUM::SKA1);

    init_tcu_mvb_table(SKA_VEHICLE_NUM::SKA1,TCU_NUM::TCU1,MVB_NUM::MVB1);
    init_tcu_mvb_table(SKA_VEHICLE_NUM::SKA1,TCU_NUM::TCU1,MVB_NUM::MVB2);

    init_tcu_mvb_table(SKA_VEHICLE_NUM::SKA1,TCU_NUM::TCU2,MVB_NUM::MVB1);
    init_tcu_mvb_table(SKA_VEHICLE_NUM::SKA1,TCU_NUM::TCU2,MVB_NUM::MVB2);


    init_tcu_mvb_table(SKA_VEHICLE_NUM::SKA2,TCU_NUM::TCU1,MVB_NUM::MVB1);
    init_tcu_mvb_table(SKA_VEHICLE_NUM::SKA2,TCU_NUM::TCU1,MVB_NUM::MVB2);

    init_tcu_mvb_table(SKA_VEHICLE_NUM::SKA2,TCU_NUM::TCU2,MVB_NUM::MVB1);
    init_tcu_mvb_table(SKA_VEHICLE_NUM::SKA2,TCU_NUM::TCU2,MVB_NUM::MVB2);
    qDebug() << "SIZE OF SKA TCU IS : " << sizeof(ska_tcu);


    make_signal_slot_connection();

}

void SKA_TCU::init_tcu_mvb_table(SKA_VEHICLE_NUM ska_x_num, TCU_NUM tcu_x_num, MVB_NUM mvb_num)
{
    //qDebug() << "INIT TABLE";
    int ska_num = static_cast<int>(ska_x_num);
    int tcu_num = static_cast<int>(tcu_x_num);
    if(mvb_num == MVB1) {
        //qDebug() << "INIT TABLE IF İÇİNDE";
        m_inputs_map[ska_num][tcu_num][MVB1] = {
            {"Lifesign",0},
            {"Ack_Reset",0},
            {"Ack_OOS",0},
            {"Mode_Traction",0},
            {"Mode_Brake",0},
            {"Mode_Forward",0},
            {"Mode_Reverse",0},
            {"Mode_Cab_SKA1",0},
            {"Mode_Cab_SKA2",0},
            {"Mode_Slip_Slide_Control",0}, //byte3
            {"Mode_Traction_Null",0},
            {"Mode_Traction_Cutoff",0},
            {"Mode_Traction_OOS",0},
            {"Mode_Traction_Failure",0},
            {"Mode_Emergency",0},
            {"Mode_EDB_Cutoff",0},
            {"bit31",0},
            {"V_MV_Output_Motor1_Ok",0},  //byte4
            {"V_MV_Output_Motor2_Ok",0},
            {"V_HV_Presence",0},
            {"V_Traction_DC_Link_Ok",0},
            {"V_Pantograph_Permission",0},
            {"V_Traction1_Ok",0},
            {"V_Traction2_Ok",0},
            {"V_VCB_Loop_Out",0},
            {"V_Traction_Active",0},  //byte5
            {"V_ED_Brake_Active",0},
            {"V_System_Reset",0},
            {"bit43",0},
            {"bit44",0},
            {"bit45",0},
            {"bit46",0},
            {"bit47",0},
            {"STS_Main_Cont1",0},  //byte6
            {"STS_Main_Cont2",0},
            {"STS_Pre_Cont1",0},
            {"STS_Pre_Cont2",0},
            {"STS_TC_Cover_Open",0},
            {"STS_TL_VCB",0},
            {"bit54",0},
            {"bit55",0},
            {"Catenary_Voltage",0},  //byte7
            {"reserved_9",0},  //byte9
            {"SW_Version_Major",0},  //byte10
            {"SW_Version_Minor",0},  //byte11
            {"reserved_12",0},  //byte12
            {"TCU_Location_SKA1_1",0},  //byte13
            {"TCU_Location_SKA1_2",0},
            {"TCU_Location_SKA2_1",0},
            {"TCU_Location_SKA2_2",0},
            {"bit108",0},
            {"bit109",0},
            {"bit110",0},
            {"bit111",0},
            {"reserved_14",0}, //byte14
            {"DIA_TL_Enable",0}, //byte15
            {"DIA_TL_Normal_Rescue",0},
            {"DIA_TL_Speed_Limit",0},
            {"DIA_TL_Cabs_Mode",0},
            {"DIA_TL_Traction_Null",0},
            {"DIA_TL_Forward",0},
            {"DIA_TL_Reverse",0},
            {"DIA_TL_Traction_CutOff",0},
            {"DIA_TL_Relay_Security_Emergency_Loop",0},  //byte16
            {"DIA_TL_MC_S1",0},
            {"DIA_TL_MC_S2",0},
            {"DIA_TL_MC_S3",0},
            {"DIA_TL_MC_S4",0},
            {"DIA_TL_MC_S5",0},
            {"DIA_TL_MC_S6",0},
            {"DIA_TL_VCB_On_Off",0},
            {"DIA_Conflict_Catenary_Voltage",0}, //byte17
            {"DIA_Catenary_Out_Of_Range",0},
            {"DIA_DC_Link_OV",0},
            {"DIA_DC_Link_LV",0},
            {"DIA_Input1_OC",0},
            {"DIA_Input2_OC",0},
            {"DIA_Input1_OL",0},
            {"DIA_Input2_OL",0},
            {"DIA_Motor_OC",0}, //byte18
            {"DIA_Motor_Phase_Unbalance",0},
            {"DIA_Speed_Sensor_Fault",0},
            {"DIA_Motor1_Overspeed",0},
            {"DIA_Motor2_Overspeed",0},
            {"DIA_Motor1_OT",0},
            {"DIA_Motor2_OT",0},
            {"DIA_Motor1_Gearbox_OT",0},
            {"DIA_Motor2_Gearbox_OT",0},   //byte19
            {"DIA_Module1_OT",0},
            {"DIA_Module2_OT",0},
            {"DIA_Module3_OT",0},
            {"DIA_Module4_OT",0},
            {"DIA_TC_OT",0},
            {"DIA_TC_OH",0},
            {"DIA_Coolant_OT",0},
            {"DIA_Low_Coolant_Flow",0},   //byte20
            {"DIA_Coolant_Pressure",0},
            {"DIA_Coolant_Lvl_Warning",0},
            {"DIA_Coolant_Lvl_Fault",0},
            {"DIA_Coolant_Fan_CB",0},
            {"DIA_Cabinet_Fan_CB",0},
            {"DIA_TCU_Fan_CB",0},
            {"DIA_Pump_CB",0},
            {"DIA_Input_Contactor1_Jammed",0},  //byte21
            {"DIA_Input_Contactor2_Jammed",0},
            {"DIA_Input_Contactor1_OER",0},
            {"DIA_Input_Contactor2_OER",0},
            {"DIA_PreCharge_Contactor1_Jammed",0},
            {"DIA_PreCharge_Contactor2_Jammed",0},
            {"DIA_PreCharge_Contactor1_OER",0},
            {"DIA_PreCharge_Contactor2_OER",0},
            {"DIA_Capacitor_Fault",0},   //byte22
            {"DIA_110VDC_Input_Fault",0},
            {"DIA_15VDC_GPLV_Fault",0},
            {"DIA_24VDC_P_Fault",0},
            {"DIA_24VDC_N_Fault",0},
            {"DIA_5VDC_D_Fault",0},
            {"DIA_5VDC_A_Fault",0},
            {"DIA_CPU_Fault",0},
            {"DIA_Rec1_IGBT_UP_Fault",0}, //byte23
            {"DIA_Rec1_IGBT_UN_Fault",0},
            {"DIA_Rec1_IGBT_VP_Fault",0},
            {"DIA_Rec1_IGBT_VN_Fault",0},
            {"DIA_Rec2_IGBT_UP_Fault",0},
            {"DIA_Rec2_IGBT_UN_Fault",0},
            {"DIA_Rec2_IGBT_VP_Fault",0},
            {"DIA_Rec2_IGBT_VN_Fault",0},
            {"DIA_Inv_IGBT_UP_Fault",0},  //byte24
            {"DIA_Inv_IGBT_UN_Fault",0},
            {"DIA_Inv_IGBT_VP_Fault",0},
            {"DIA_Inv_IGBT_VN_Fault",0},
            {"DIA_Inv_IGBT_WP_Fault",0},
            {"DIA_Inv_IGBT_WN_Fault",0},
            {"DIA_Chop_IGBT_OVP_Fault",0},
            {"DIA_Chop_IGBT_FWD_Fault",0},
            {"DIA_CFD_Fault",0},   //byte25
            {"DIA_Insulation_Fault",0},
            {"DIA_PreCh_Fault",0},
            {"DIA_Frequency_Irregular",0},
            {"DIA_WF_Irregular",0},
            {"bit205",0},
            {"bit206",0},
            {"bit207",0},
            {"reserved_26",0},
            {"reserved_27",0},
            {"reserved_28",0},
            {"reserved_29",0},
            {"reserved_30",0},
            {"reserved_31",0}


        };

        /*qDebug() << "MVB1 INIT TABLE NAME ÜSTÜ";
        QStringList table_name = {"ska_tcu_mvb1", "value"};

        //m_tableWidget.push_back(new QTableWidget());
        m_tableWidget[ska_num][tcu_num][MVB1] = new QTableWidget();
        m_tableWidget[ska_num][tcu_num][MVB1] ->setColumnCount(2);
        m_tableWidget[ska_num][tcu_num][MVB1] ->setRowCount(m_inputs_map[ska_num][tcu_num][MVB1].size());
        m_tableWidget[ska_num][tcu_num][MVB1]->setHorizontalHeaderLabels(table_name);
        qDebug() << "MVB1 INIT TABLE LOG 1";
        int row = 0;
        for (const auto& pair:  m_inputs_map[ska_num][tcu_num][MVB1]) {
            QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
            QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
            qDebug() << "MVB1 INIT TABLE LOG 2";
            m_tableWidget[ska_num][tcu_num][MVB1]->setItem(row, 0, item_name);
            m_tableWidget[ska_num][tcu_num][MVB1]->setItem(row, 1, item_val);
            //m_tableWidget->item(row, 0)->setText(QString(pair.first));
            //m_tableWidget->item(row, 1)->setText(QString(pair.second));
            ++row;
        }
        // Resize the table widget contents
        qDebug() << "MVB1 INIT TABLE LOG 3";
        m_tableWidget[ska_num][tcu_num][MVB1]->resizeColumnsToContents();
        qDebug() << "MVB1 INIT TABLE LOG 4";*/
        int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
        int rowCount = (m_inputs_map[ska_num][tcu_num][MVB1].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

        //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
        m_tableWidget[ska_num][tcu_num][MVB1] = new QTableWidget(rowCount, numColumns);
        m_tableWidget[ska_num][tcu_num][MVB1]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

        int row = 0;
        int column = 0; // Sütun sayacını başlat

        for (const auto& pair: m_inputs_map[ska_num][tcu_num][MVB1]) {
            QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
            QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

            m_tableWidget[ska_num][tcu_num][MVB1]->setItem(row, column, item_name);
            m_tableWidget[ska_num][tcu_num][MVB1]->setItem(row, column + 1, item_val); // Değer
            item_name->setBackground(QColor("turquoise"));  // Turkuaz
            item_val->setBackground(QColor("turquoise"));  // Turkuaz

            // Sütun sayısını güncelle
            column += 2; // İki hücre (isim ve değer) kullandık

            // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
            if (column >= numColumns) {
                column = 0; // Sütun sayacını sıfırla
                ++row; // Bir sonraki satıra geç
            }
        }

        // Tablo içeriğini yeniden boyutlandır
        m_tableWidget[ska_num][tcu_num][MVB1]->resizeColumnsToContents();
        //qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][tcu_num][MVB1]->columnCount() ;

    }
    else if(mvb_num == MVB2) {
        //qDebug() << "MVB2 INIT TABLE";
        m_inputs_map[ska_num][tcu_num][MVB2] = {
            {"Lifesign", 0},                      // byte0
            {"Traction_Achieved", 0},             // byte2
            {"ED_Brake_Achieved", 0},             // byte4
            {"Temp_Converter", 0},                // byte6
            {"Temp_Power_Module", 0},             // byte7
            {"Temp_Coolant", 0},                  // byte8
            {"Temp_Motor1", 0},                   // byte9
            {"Temp_Motor2", 0},                   // byte10
            {"Temp_Gear_Box1", 0},                // byte11
            {"Temp_Gear_Box2", 0},                // byte12
            {"Motor_Current", 0},                 // byte13
            {"Secondary_Current1", 0},            // byte15
            {"Secondary_Current2", 0},            // byte17
            {"Motor_Speed1", 0},                  // byte19
            {"Motor_Speed2", 0},                  // byte21
            {"reserved23", 0},                    // byte23
            {"reserved24", 0},                    // byte24
            {"reserved25", 0},                    // byte25
            {"reserved26", 0},                    // byte26
            {"reserved27", 0},                    // byte27
            {"reserved28", 0},                    // byte28
            {"reserved29", 0},                    // byte29
            {"reserved30", 0},                    // byte30
            {"reserved31", 0}                     // byte31
        };

        /*QStringList table_name = {"ska_tcu_mvb2", "value"};
        qDebug() << "MVB2 INIT TABLE NAME ÜSTÜ";
        //m_tableWidget.push_back(new QTableWidget());
        m_tableWidget[ska_num][tcu_num][MVB2] = new QTableWidget();
        m_tableWidget[ska_num][tcu_num][MVB2] ->setColumnCount(2);
        m_tableWidget[ska_num][tcu_num][MVB2] ->setRowCount(m_inputs_map[ska_num][tcu_num][MVB2].size());
        m_tableWidget[ska_num][tcu_num][MVB2]->setHorizontalHeaderLabels(table_name);

        int row = 0;
        for (const auto& pair:  m_inputs_map[ska_num][tcu_num][MVB2]) {
            QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
            QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
            m_tableWidget[ska_num][tcu_num][MVB2]->setItem(row, 0, item_name);
            m_tableWidget[ska_num][tcu_num][MVB2]->setItem(row, 1, item_val);
            //m_tableWidget->item(row, 0)->setText(QString(pair.first));
            //m_tableWidget->item(row, 1)->setText(QString(pair.second));
            ++row;
        }
        // Resize the table widget contents
        m_tableWidget[ska_num][tcu_num][MVB2]->resizeColumnsToContents();*/
        int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
        int rowCount = (m_inputs_map[ska_num][tcu_num][MVB2].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

        //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
        m_tableWidget[ska_num][tcu_num][MVB2] = new QTableWidget(rowCount, numColumns);
        m_tableWidget[ska_num][tcu_num][MVB2]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

        int row = 0;
        int column = 0; // Sütun sayacını başlat

        for (const auto& pair: m_inputs_map[ska_num][tcu_num][MVB2]) {
            QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
            QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

            m_tableWidget[ska_num][tcu_num][MVB2]->setItem(row, column, item_name);
            m_tableWidget[ska_num][tcu_num][MVB2]->setItem(row, column + 1, item_val); // Değer
            item_name->setBackground(QColor("turquoise"));  // Turkuaz
            item_val->setBackground(QColor("turquoise"));  // Turkuaz

            // Sütun sayısını güncelle
            column += 2; // İki hücre (isim ve değer) kullandık

            // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
            if (column >= numColumns) {
                column = 0; // Sütun sayacını sıfırla
                ++row; // Bir sonraki satıra geç
            }
        }

        // Tablo içeriğini yeniden boyutlandır
        m_tableWidget[ska_num][tcu_num][MVB2]->resizeColumnsToContents();
        //qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][tcu_num][MVB2]->columnCount() ;
    }
    else {
        qDebug() << "NOOOOOOOOOOOOOOOOOOO";
    }


}



void SKA_TCU::set_struct(SKA_VEHICLE_NUM &ska_x_num, TCU_NUM tcu_x_num, MVB_NUM mvb_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    int tcu_num = static_cast<int>(tcu_x_num);
    if(mvb_num == MVB1) {



        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Lifesign                    = m_inputs_map[ska_num][tcu_num][MVB1].at("Lifesign");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Ack_Reset                    = m_inputs_map[ska_num][tcu_num][MVB1].at("Ack_Reset");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Ack_OOS          = m_inputs_map[ska_num][tcu_num][MVB1].at("Ack_OOS");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Traction            = m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Traction");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Brake           = m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Brake");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Forward             = m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Forward");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Reverse             = m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Reverse");
        qDebug() << "CENK 1";
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Cab_SKA1            = m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Cab_SKA1");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Cab_SKA2            = m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Cab_SKA2");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Slip_Slide_Control          = m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Slip_Slide_Control");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Traction_Null           = m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Traction_Null");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Traction_Cutoff             = m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Traction_Cutoff");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Traction_OOS            = m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Traction_OOS");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Traction_Failure            = m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Traction_Failure");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Emergency           = m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Emergency");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_EDB_Cutoff          = m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_EDB_Cutoff");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit31            = m_inputs_map[ska_num][tcu_num][MVB1].at("bit31");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_MV_Output_Motor1_Ok            = m_inputs_map[ska_num][tcu_num][MVB1].at("V_MV_Output_Motor1_Ok");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_MV_Output_Motor2_Ok            = m_inputs_map[ska_num][tcu_num][MVB1].at("V_MV_Output_Motor2_Ok");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_HV_Presence            = m_inputs_map[ska_num][tcu_num][MVB1].at("V_HV_Presence");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_Traction_DC_Link_Ok            = m_inputs_map[ska_num][tcu_num][MVB1].at("V_Traction_DC_Link_Ok");
        qDebug() << "CENK 2";
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_Pantograph_Permission          = m_inputs_map[ska_num][tcu_num][MVB1].at("V_Pantograph_Permission");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_Traction1_Ok           = m_inputs_map[ska_num][tcu_num][MVB1].at("V_Traction1_Ok");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_Traction2_Ok           = m_inputs_map[ska_num][tcu_num][MVB1].at("V_Traction2_Ok");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_VCB_Loop_Out              = m_inputs_map[ska_num][tcu_num][MVB1].at("V_VCB_Loop_Out");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_Traction_Active            = m_inputs_map[ska_num][tcu_num][MVB1].at("V_Traction_Active");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_ED_Brake_Active            = m_inputs_map[ska_num][tcu_num][MVB1].at("V_ED_Brake_Active");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_System_Reset           = m_inputs_map[ska_num][tcu_num][MVB1].at("V_System_Reset");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit43            = m_inputs_map[ska_num][tcu_num][MVB1].at("bit43");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit44            = m_inputs_map[ska_num][tcu_num][MVB1].at("bit44");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit45            = m_inputs_map[ska_num][tcu_num][MVB1].at("bit45");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit46            = m_inputs_map[ska_num][tcu_num][MVB1].at("bit46");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit47            = m_inputs_map[ska_num][tcu_num][MVB1].at("bit47");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.STS_Main_Cont1           = m_inputs_map[ska_num][tcu_num][MVB1].at("STS_Main_Cont1");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.STS_Main_Cont2           = m_inputs_map[ska_num][tcu_num][MVB1].at("STS_Main_Cont2");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.STS_Pre_Cont1            = m_inputs_map[ska_num][tcu_num][MVB1].at("STS_Pre_Cont1");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.STS_Pre_Cont2            = m_inputs_map[ska_num][tcu_num][MVB1].at("STS_Pre_Cont2");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.STS_TC_Cover_Open            = m_inputs_map[ska_num][tcu_num][MVB1].at("STS_TC_Cover_Open");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.STS_TL_VCB           = m_inputs_map[ska_num][tcu_num][MVB1].at("STS_TL_VCB");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit54            = m_inputs_map[ska_num][tcu_num][MVB1].at("bit54");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit55            = m_inputs_map[ska_num][tcu_num][MVB1].at("bit55");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Catenary_Voltage             = m_inputs_map[ska_num][tcu_num][MVB1].at("Catenary_Voltage");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.reserved_9           = m_inputs_map[ska_num][tcu_num][MVB1].at("reserved_9");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.SW_Version_Major             = m_inputs_map[ska_num][tcu_num][MVB1].at("SW_Version_Major");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.SW_Version_Minor             = m_inputs_map[ska_num][tcu_num][MVB1].at("SW_Version_Minor");
        qDebug() << "CENK 3";
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.reserved_12          = m_inputs_map[ska_num][tcu_num][MVB1].at("reserved_12");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.TCU_Location_SKA1_1          = m_inputs_map[ska_num][tcu_num][MVB1].at("TCU_Location_SKA1_1");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.TCU_Location_SKA1_2          = m_inputs_map[ska_num][tcu_num][MVB1].at("TCU_Location_SKA1_2");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.TCU_Location_SKA2_1          = m_inputs_map[ska_num][tcu_num][MVB1].at("TCU_Location_SKA2_1");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.TCU_Location_SKA2_2              = m_inputs_map[ska_num][tcu_num][MVB1].at("TCU_Location_SKA2_2");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit108           = m_inputs_map[ska_num][tcu_num][MVB1].at("bit108");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit109           = m_inputs_map[ska_num][tcu_num][MVB1].at("bit109");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit110           = m_inputs_map[ska_num][tcu_num][MVB1].at("bit110");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit111           = m_inputs_map[ska_num][tcu_num][MVB1].at("bit111");
        //m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit112           = m_inputs_map[ska_num][tcu_num][MVB1].at("bit112");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.reserved_14          = m_inputs_map[ska_num][tcu_num][MVB1].at("reserved_14");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_Enable            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_Enable");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_Normal_Rescue             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_Normal_Rescue");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_Speed_Limit           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_Speed_Limit");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_Cabs_Mode             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_Cabs_Mode");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_Traction_Null             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_Traction_Null");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_Forward           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_Forward");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_Reverse           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_Reverse");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_Traction_CutOff           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_Traction_CutOff");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_Relay_Security_Emergency_Loop             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_Relay_Security_Emergency_Loop");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_MC_S1             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_MC_S1");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_MC_S2             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_MC_S2");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_MC_S3             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_MC_S3");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_MC_S4             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_MC_S4");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_MC_S5             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_MC_S5");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_MC_S6             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_MC_S6");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_VCB_On_Off            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_VCB_On_Off");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Conflict_Catenary_Voltage            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Conflict_Catenary_Voltage");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Catenary_Out_Of_Range            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Catenary_Out_Of_Range");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_DC_Link_OV           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_DC_Link_OV");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_DC_Link_LV           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_DC_Link_LV");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Input1_OC            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Input1_OC");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Input2_OC            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Input2_OC");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Input1_OL            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Input1_OL");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Input2_OL            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Input2_OL");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Motor_OC             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Motor_OC");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Motor_Phase_Unbalance            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Motor_Phase_Unbalance");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Speed_Sensor_Fault           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Speed_Sensor_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Motor1_Overspeed             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Motor1_Overspeed");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Motor2_Overspeed             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Motor2_Overspeed");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Motor1_OT            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Motor1_OT");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Motor2_OT            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Motor2_OT");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Motor1_Gearbox_OT            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Motor1_Gearbox_OT");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Motor2_Gearbox_OT            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Motor2_Gearbox_OT");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Module1_OT           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Module1_OT");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Module2_OT           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Module2_OT");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Module3_OT           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Module3_OT");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Module4_OT           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Module4_OT");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TC_OT            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TC_OT");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TC_OH            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TC_OH");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Coolant_OT           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Coolant_OT");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Low_Coolant_Flow             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Low_Coolant_Flow");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Coolant_Pressure             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Coolant_Pressure");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Coolant_Lvl_Warning          = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Coolant_Lvl_Warning");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Coolant_Lvl_Fault            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Coolant_Lvl_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Coolant_Fan_CB           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Coolant_Fan_CB");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Cabinet_Fan_CB           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Cabinet_Fan_CB");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TCU_Fan_CB           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TCU_Fan_CB");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Pump_CB          = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Pump_CB");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Input_Contactor1_Jammed          = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Input_Contactor1_Jammed");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Input_Contactor2_Jammed          = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Input_Contactor2_Jammed");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Input_Contactor1_OER             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Input_Contactor1_OER");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Input_Contactor2_OER             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Input_Contactor2_OER");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_PreCharge_Contactor1_Jammed          = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_PreCharge_Contactor1_Jammed");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_PreCharge_Contactor2_Jammed          = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_PreCharge_Contactor2_Jammed");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_PreCharge_Contactor1_OER             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_PreCharge_Contactor1_OER");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_PreCharge_Contactor2_OER             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_PreCharge_Contactor2_OER");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Capacitor_Fault          = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Capacitor_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_110VDC_Input_Fault           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_110VDC_Input_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_15VDC_GPLV_Fault             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_15VDC_GPLV_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_24VDC_P_Fault            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_24VDC_P_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_24VDC_N_Fault            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_24VDC_N_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_5VDC_D_Fault             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_5VDC_D_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_5VDC_A_Fault             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_5VDC_A_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_CPU_Fault            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_CPU_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Rec1_IGBT_UP_Fault           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Rec1_IGBT_UP_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Rec1_IGBT_UN_Fault           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Rec1_IGBT_UN_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Rec1_IGBT_VP_Fault           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Rec1_IGBT_VP_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Rec1_IGBT_VN_Fault           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Rec1_IGBT_VN_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Rec2_IGBT_UP_Fault           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Rec2_IGBT_UP_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Rec2_IGBT_UN_Fault           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Rec2_IGBT_UN_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Rec2_IGBT_VP_Fault           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Rec2_IGBT_VP_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Rec2_IGBT_VN_Fault           = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Rec2_IGBT_VN_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Inv_IGBT_UP_Fault            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Inv_IGBT_UP_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Inv_IGBT_UN_Fault            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Inv_IGBT_UN_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Inv_IGBT_VP_Fault            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Inv_IGBT_VP_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Inv_IGBT_VN_Fault            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Inv_IGBT_VN_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Inv_IGBT_WP_Fault            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Inv_IGBT_WP_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Inv_IGBT_WN_Fault            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Inv_IGBT_WN_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Chop_IGBT_OVP_Fault          = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Chop_IGBT_OVP_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Chop_IGBT_FWD_Fault          = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Chop_IGBT_FWD_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_CFD_Fault            = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_CFD_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Insulation_Fault             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Insulation_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_PreCh_Fault          = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_PreCh_Fault");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Frequency_Irregular          = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Frequency_Irregular");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_WF_Irregular             = m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_WF_Irregular");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit205           = m_inputs_map[ska_num][tcu_num][MVB1].at("bit205");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit206           = m_inputs_map[ska_num][tcu_num][MVB1].at("bit206");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit207           = m_inputs_map[ska_num][tcu_num][MVB1].at("bit207");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.reserved_26          = m_inputs_map[ska_num][tcu_num][MVB1].at("reserved_26");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.reserved_27          = m_inputs_map[ska_num][tcu_num][MVB1].at("reserved_27");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.reserved_28          = m_inputs_map[ska_num][tcu_num][MVB1].at("reserved_28");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.reserved_29          = m_inputs_map[ska_num][tcu_num][MVB1].at("reserved_29");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.reserved_30          = m_inputs_map[ska_num][tcu_num][MVB1].at("reserved_30");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.reserved_31          = m_inputs_map[ska_num][tcu_num][MVB1].at("reserved_31");


    }
    else if(mvb_num == MVB2) {
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Lifesign          = m_inputs_map[ska_num][tcu_num][MVB2].at("Lifesign");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Traction_Achieved          = m_inputs_map[ska_num][tcu_num][MVB2].at("Traction_Achieved");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.ED_Brake_Achieved          = m_inputs_map[ska_num][tcu_num][MVB2].at("ED_Brake_Achieved");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Temp_Converter          = m_inputs_map[ska_num][tcu_num][MVB2].at("Temp_Converter");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Temp_Power_Module          = m_inputs_map[ska_num][tcu_num][MVB2].at("Temp_Power_Module");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Temp_Coolant          = m_inputs_map[ska_num][tcu_num][MVB2].at("Temp_Coolant");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Temp_Motor1          = m_inputs_map[ska_num][tcu_num][MVB2].at("Temp_Motor1");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Temp_Motor2          = m_inputs_map[ska_num][tcu_num][MVB2].at("Temp_Motor2");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Temp_Gear_Box1          = m_inputs_map[ska_num][tcu_num][MVB2].at("Temp_Gear_Box1");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Temp_Gear_Box2          = m_inputs_map[ska_num][tcu_num][MVB2].at("Temp_Gear_Box2");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Motor_Current          = m_inputs_map[ska_num][tcu_num][MVB2].at("Motor_Current");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Secondary_Current1          = m_inputs_map[ska_num][tcu_num][MVB2].at("Secondary_Current1");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Secondary_Current2          = m_inputs_map[ska_num][tcu_num][MVB2].at("Secondary_Current2");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Motor_Speed1          = m_inputs_map[ska_num][tcu_num][MVB2].at("Motor_Speed1");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Motor_Speed2          = m_inputs_map[ska_num][tcu_num][MVB2].at("Motor_Speed2");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.reserved23            = m_inputs_map[ska_num][tcu_num][MVB2].at("reserved23");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.reserved24          = m_inputs_map[ska_num][tcu_num][MVB2].at("reserved24");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.reserved25          = m_inputs_map[ska_num][tcu_num][MVB2].at("reserved25");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.reserved26          = m_inputs_map[ska_num][tcu_num][MVB2].at("reserved26");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.reserved27          = m_inputs_map[ska_num][tcu_num][MVB2].at("reserved27");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.reserved28          = m_inputs_map[ska_num][tcu_num][MVB2].at("reserved28");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.reserved29          = m_inputs_map[ska_num][tcu_num][MVB2].at("reserved29");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.reserved30          = m_inputs_map[ska_num][tcu_num][MVB2].at("reserved30");
        m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.reserved31          = m_inputs_map[ska_num][tcu_num][MVB2].at("reserved31");



    }
    else {
        qDebug() << "NOOOOOOOOOOOOOOOOOOO";
    }
}

void SKA_TCU::update_table(const SKA_VEHICLE_NUM &ska_x_num, TCU_NUM tcu_x_num, MVB_NUM mvb_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    int tcu_num = static_cast<int>(tcu_x_num);
    for(const auto & map:m_inputs_map[ska_num][tcu_num][mvb_num]){
        //qDebug() <<  map.first << map.second;
        utils::setTableWidgetValueByNameWithoutColumn(m_tableWidget[ska_num][tcu_num][mvb_num], map.first, map.second );
    }

}

void SKA_TCU::update_tcu_mvb_map(const SKA_VEHICLE_NUM &ska_x_num, TCU_NUM tcu_x_num, MVB_NUM mvb_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    int tcu_num = static_cast<int>(tcu_x_num);
    qDebug() << "CENK 0";
    if(mvb_num == MVB1) {


        m_inputs_map[ska_num][tcu_num][MVB1].at("Lifesign")                                 = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Lifesign;
        m_inputs_map[ska_num][tcu_num][MVB1].at("Ack_Reset")                                = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Ack_Reset;
        m_inputs_map[ska_num][tcu_num][MVB1].at("Ack_OOS")                                  = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Ack_OOS;
        m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Traction")                            = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Traction;
        m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Brake")                               = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Brake;
        m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Forward")                             = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Forward;
        m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Reverse")                             = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Reverse;
        m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Cab_SKA1")                            = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Cab_SKA1;
        m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Cab_SKA2")                            = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Cab_SKA2;
        qDebug() << "CENK 0_1";
        m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Slip_Slide_Control")                  = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Slip_Slide_Control;
        m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Traction_Null")                       = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Traction_Null;
        m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Traction_Cutoff")                     = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Traction_Cutoff;
        m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Traction_OOS")                        = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Traction_OOS;
        m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Traction_Failure")                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Traction_Failure;
        m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_Emergency")                           = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_Emergency;
        m_inputs_map[ska_num][tcu_num][MVB1].at("Mode_EDB_Cutoff")                          = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Mode_EDB_Cutoff;
        m_inputs_map[ska_num][tcu_num][MVB1].at("bit31")                                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit31;
        m_inputs_map[ska_num][tcu_num][MVB1].at("V_MV_Output_Motor1_Ok")                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_MV_Output_Motor1_Ok;
        m_inputs_map[ska_num][tcu_num][MVB1].at("V_MV_Output_Motor2_Ok")                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_MV_Output_Motor2_Ok;
        m_inputs_map[ska_num][tcu_num][MVB1].at("V_HV_Presence")                            = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_HV_Presence;
        m_inputs_map[ska_num][tcu_num][MVB1].at("V_Traction_DC_Link_Ok")                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_Traction_DC_Link_Ok;
        m_inputs_map[ska_num][tcu_num][MVB1].at("V_Pantograph_Permission")                  = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_Pantograph_Permission;
        m_inputs_map[ska_num][tcu_num][MVB1].at("V_Traction1_Ok")                           = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_Traction1_Ok;
        m_inputs_map[ska_num][tcu_num][MVB1].at("V_Traction2_Ok")                           = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_Traction2_Ok;
        m_inputs_map[ska_num][tcu_num][MVB1].at("V_VCB_Loop_Out")                         = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_VCB_Loop_Out ;
        m_inputs_map[ska_num][tcu_num][MVB1].at("V_Traction_Active")                        = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_Traction_Active;
        m_inputs_map[ska_num][tcu_num][MVB1].at("V_ED_Brake_Active")                        = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_ED_Brake_Active;
        m_inputs_map[ska_num][tcu_num][MVB1].at("V_System_Reset")                           = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.V_System_Reset;
        m_inputs_map[ska_num][tcu_num][MVB1].at("bit43")                                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit43;
        m_inputs_map[ska_num][tcu_num][MVB1].at("bit44")                                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit44;
        m_inputs_map[ska_num][tcu_num][MVB1].at("bit45")                                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit45;
        m_inputs_map[ska_num][tcu_num][MVB1].at("bit46")                                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit46;
        m_inputs_map[ska_num][tcu_num][MVB1].at("bit47")                                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit47;
        qDebug() << "CENK 0_3";
        m_inputs_map[ska_num][tcu_num][MVB1].at("STS_Main_Cont1")                           = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.STS_Main_Cont1;
        m_inputs_map[ska_num][tcu_num][MVB1].at("STS_Main_Cont2")                           = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.STS_Main_Cont2;
        m_inputs_map[ska_num][tcu_num][MVB1].at("STS_Pre_Cont1")                            = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.STS_Pre_Cont1;
        m_inputs_map[ska_num][tcu_num][MVB1].at("STS_Pre_Cont2")                            = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.STS_Pre_Cont2;
        m_inputs_map[ska_num][tcu_num][MVB1].at("STS_TC_Cover_Open")                        = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.STS_TC_Cover_Open;
        m_inputs_map[ska_num][tcu_num][MVB1].at("STS_TL_VCB")                               = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.STS_TL_VCB;
        m_inputs_map[ska_num][tcu_num][MVB1].at("bit54")                                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit54;
        m_inputs_map[ska_num][tcu_num][MVB1].at("bit55")                                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit55;
        m_inputs_map[ska_num][tcu_num][MVB1].at("Catenary_Voltage")                         = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.Catenary_Voltage;
        qDebug() << "CENK 0_4";
        m_inputs_map[ska_num][tcu_num][MVB1].at("reserved_9")                               = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.reserved_9;
        m_inputs_map[ska_num][tcu_num][MVB1].at("SW_Version_Major")                         = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.SW_Version_Major;
        m_inputs_map[ska_num][tcu_num][MVB1].at("SW_Version_Minor")                         = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.SW_Version_Minor;
        m_inputs_map[ska_num][tcu_num][MVB1].at("reserved_12")                              = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.reserved_12;
        m_inputs_map[ska_num][tcu_num][MVB1].at("TCU_Location_SKA1_1")                      = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.TCU_Location_SKA1_1;
        m_inputs_map[ska_num][tcu_num][MVB1].at("TCU_Location_SKA1_2")                      = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.TCU_Location_SKA1_2;
        m_inputs_map[ska_num][tcu_num][MVB1].at("TCU_Location_SKA2_1")                      = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.TCU_Location_SKA2_1;
        m_inputs_map[ska_num][tcu_num][MVB1].at("TCU_Location_SKA2_2")                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.TCU_Location_SKA2_2  ;
        m_inputs_map[ska_num][tcu_num][MVB1].at("bit108")                                   = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit108;
        m_inputs_map[ska_num][tcu_num][MVB1].at("bit109")                                   = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit109;
        m_inputs_map[ska_num][tcu_num][MVB1].at("bit110")                                   = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit110;
        m_inputs_map[ska_num][tcu_num][MVB1].at("bit111")                                   = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit111;
        qDebug() << "CENK 0_5";
        //m_inputs_map[ska_num][tcu_num][MVB1].at("bit112")                                   = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit112;
        m_inputs_map[ska_num][tcu_num][MVB1].at("reserved_14")                              = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.reserved_14;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_Enable")                            = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_Enable;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_Normal_Rescue")                     = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_Normal_Rescue;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_Speed_Limit")                       = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_Speed_Limit;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_Cabs_Mode")                         = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_Cabs_Mode;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_Traction_Null")                     = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_Traction_Null;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_Forward")                           = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_Forward;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_Reverse")                           = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_Reverse;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_Traction_CutOff")                   = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_Traction_CutOff;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_Relay_Security_Emergency_Loop")     = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_Relay_Security_Emergency_Loop;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_MC_S1")                             = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_MC_S1;
        qDebug() << "CENK 0_6";
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_MC_S2")                             = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_MC_S2;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_MC_S3")                             = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_MC_S3;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_MC_S4")                             = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_MC_S4;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_MC_S5")                             = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_MC_S5;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_MC_S6")                             = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_MC_S6;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TL_VCB_On_Off")                        = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TL_VCB_On_Off;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Conflict_Catenary_Voltage")          = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Conflict_Catenary_Voltage  ;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Catenary_Out_Of_Range")                = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Catenary_Out_Of_Range;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_DC_Link_OV")                           = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_DC_Link_OV;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_DC_Link_LV")                           = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_DC_Link_LV;
        qDebug() << "CENK 0_7";
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Input1_OC")                            = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Input1_OC;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Input2_OC")                            = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Input2_OC;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Input1_OL")                            = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Input1_OL;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Input2_OL")                            = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Input2_OL;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Motor_OC")                             = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Motor_OC;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Motor_Phase_Unbalance")                = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Motor_Phase_Unbalance;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Speed_Sensor_Fault")                   = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Speed_Sensor_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Motor1_Overspeed")                     = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Motor1_Overspeed;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Motor2_Overspeed")                     = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Motor2_Overspeed;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Motor1_OT")                            = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Motor1_OT;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Motor2_OT")                            = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Motor2_OT;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Motor1_Gearbox_OT")                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Motor1_Gearbox_OT;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Motor2_Gearbox_OT")                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Motor2_Gearbox_OT;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Module1_OT")                           = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Module1_OT;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Module2_OT")                           = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Module2_OT;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Module3_OT")                           = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Module3_OT;
        qDebug() << "CENK 0_8";
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Module4_OT")                           = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Module4_OT;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TC_OT")                                = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TC_OT;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TC_OH")                                = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TC_OH;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Coolant_OT")                           = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Coolant_OT;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Low_Coolant_Flow")                     = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Low_Coolant_Flow;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Coolant_Pressure")                     = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Coolant_Pressure;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Coolant_Lvl_Warning")                  = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Coolant_Lvl_Warning;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Coolant_Lvl_Fault")                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Coolant_Lvl_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Coolant_Fan_CB")                       = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Coolant_Fan_CB;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Cabinet_Fan_CB")                       = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Cabinet_Fan_CB;
        qDebug() << "CENK 0_9";
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_TCU_Fan_CB")                           = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_TCU_Fan_CB;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Pump_CB")                              = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Pump_CB;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Input_Contactor1_Jammed")              = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Input_Contactor1_Jammed;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Input_Contactor2_Jammed")              = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Input_Contactor2_Jammed;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Input_Contactor1_OER")                 = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Input_Contactor1_OER;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Input_Contactor2_OER")                 = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Input_Contactor2_OER;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_PreCharge_Contactor1_Jammed")          = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_PreCharge_Contactor1_Jammed;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_PreCharge_Contactor2_Jammed")          = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_PreCharge_Contactor2_Jammed;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_PreCharge_Contactor1_OER")             = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_PreCharge_Contactor1_OER;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_PreCharge_Contactor2_OER")             = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_PreCharge_Contactor2_OER;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Capacitor_Fault")                      = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Capacitor_Fault;
        qDebug() << "CENK 0_10";
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_110VDC_Input_Fault")                   = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_110VDC_Input_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_15VDC_GPLV_Fault")                     = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_15VDC_GPLV_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_24VDC_P_Fault")                        = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_24VDC_P_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_24VDC_N_Fault")                        = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_24VDC_N_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_5VDC_D_Fault")                         = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_5VDC_D_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_5VDC_A_Fault")                         = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_5VDC_A_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_CPU_Fault")                            = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_CPU_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Rec1_IGBT_UP_Fault")                   = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Rec1_IGBT_UP_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Rec1_IGBT_UN_Fault")                   = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Rec1_IGBT_UN_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Rec1_IGBT_VP_Fault")                   = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Rec1_IGBT_VP_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Rec1_IGBT_VN_Fault")                   = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Rec1_IGBT_VN_Fault;
        qDebug() << "CENK 0_11";
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Rec2_IGBT_UP_Fault")                   = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Rec2_IGBT_UP_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Rec2_IGBT_UN_Fault")                   = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Rec2_IGBT_UN_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Rec2_IGBT_VP_Fault")                   = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Rec2_IGBT_VP_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Rec2_IGBT_VN_Fault")                   = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Rec2_IGBT_VN_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Inv_IGBT_UP_Fault")                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Inv_IGBT_UP_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Inv_IGBT_UN_Fault")                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Inv_IGBT_UN_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Inv_IGBT_VP_Fault")                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Inv_IGBT_VP_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Inv_IGBT_VN_Fault")                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Inv_IGBT_VN_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Inv_IGBT_WP_Fault")                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Inv_IGBT_WP_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Inv_IGBT_WN_Fault")                    = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Inv_IGBT_WN_Fault;
        qDebug() << "CENK 0_12";
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Chop_IGBT_OVP_Fault")                  = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Chop_IGBT_OVP_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Chop_IGBT_FWD_Fault")                  = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Chop_IGBT_FWD_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_CFD_Fault")                            = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_CFD_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Insulation_Fault")                     = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Insulation_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_PreCh_Fault")                          = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_PreCh_Fault;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_Frequency_Irregular")                  = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_Frequency_Irregular;
        m_inputs_map[ska_num][tcu_num][MVB1].at("DIA_WF_Irregular")                         = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.DIA_WF_Irregular;
        m_inputs_map[ska_num][tcu_num][MVB1].at("bit205")                                   = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit205;
        m_inputs_map[ska_num][tcu_num][MVB1].at("bit206")                                   = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit206;
        m_inputs_map[ska_num][tcu_num][MVB1].at("bit207")                                   = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.bit207;
        m_inputs_map[ska_num][tcu_num][MVB1].at("reserved_26")                              = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.reserved_26;
        m_inputs_map[ska_num][tcu_num][MVB1].at("reserved_27")                              = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.reserved_27;
        m_inputs_map[ska_num][tcu_num][MVB1].at("reserved_28")                              = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.reserved_28;
        m_inputs_map[ska_num][tcu_num][MVB1].at("reserved_29")                              = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.reserved_29;
        m_inputs_map[ska_num][tcu_num][MVB1].at("reserved_30")                              = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.reserved_30;
        m_inputs_map[ska_num][tcu_num][MVB1].at("reserved_31")                              = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bits.reserved_31;
        qDebug() << "CENK 0_13";





    }
    else if(mvb_num == MVB2) {

        m_inputs_map[ska_num][tcu_num][MVB2].at("Lifesign")                 = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Lifesign;
        m_inputs_map[ska_num][tcu_num][MVB2].at("Traction_Achieved")        = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Traction_Achieved;
        m_inputs_map[ska_num][tcu_num][MVB2].at("ED_Brake_Achieved")        = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.ED_Brake_Achieved;
        m_inputs_map[ska_num][tcu_num][MVB2].at("Temp_Converter")           = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Temp_Converter;
        m_inputs_map[ska_num][tcu_num][MVB2].at("Temp_Power_Module")        = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Temp_Power_Module;
        m_inputs_map[ska_num][tcu_num][MVB2].at("Temp_Coolant")             = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Temp_Coolant;
        m_inputs_map[ska_num][tcu_num][MVB2].at("Temp_Motor1")              = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Temp_Motor1;
        m_inputs_map[ska_num][tcu_num][MVB2].at("Temp_Motor2")              = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Temp_Motor2;
        m_inputs_map[ska_num][tcu_num][MVB2].at("Temp_Gear_Box1")           = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Temp_Gear_Box1;
        m_inputs_map[ska_num][tcu_num][MVB2].at("Temp_Gear_Box2")           = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Temp_Gear_Box2;
        m_inputs_map[ska_num][tcu_num][MVB2].at("Motor_Current")            = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Motor_Current;
        m_inputs_map[ska_num][tcu_num][MVB2].at("Secondary_Current1")       = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Secondary_Current1;
        m_inputs_map[ska_num][tcu_num][MVB2].at("Secondary_Current2")       = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Secondary_Current2;
        m_inputs_map[ska_num][tcu_num][MVB2].at("Motor_Speed1")             = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Motor_Speed1;
        m_inputs_map[ska_num][tcu_num][MVB2].at("Motor_Speed2")             = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.Motor_Speed2;
        m_inputs_map[ska_num][tcu_num][MVB2].at("reserved23")               = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.reserved23;
        m_inputs_map[ska_num][tcu_num][MVB2].at("reserved24")               = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.reserved24;
        m_inputs_map[ska_num][tcu_num][MVB2].at("reserved25")               = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.reserved25;
        m_inputs_map[ska_num][tcu_num][MVB2].at("reserved26")               = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.reserved26;
        m_inputs_map[ska_num][tcu_num][MVB2].at("reserved27")               = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.reserved27;
        m_inputs_map[ska_num][tcu_num][MVB2].at("reserved28")               = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.reserved28;
        m_inputs_map[ska_num][tcu_num][MVB2].at("reserved29")               = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.reserved29;
        m_inputs_map[ska_num][tcu_num][MVB2].at("reserved30")               = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.reserved30;
        m_inputs_map[ska_num][tcu_num][MVB2].at("reserved31")               = m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bits.reserved31;




    }
    else {
        qDebug() << "NOOOOOOOOOOOOOOOOOOO";
    }
}

SKA_TCU::~SKA_TCU()
{

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for(int k = 0; k < 2; k++){
                delete m_tableWidget[i][j][k];
                m_tableWidget[i][j][k] = nullptr; // Güvenlik için nullptr atayın
            }
        }
    }
}

void SKA_TCU::set_data_struct(const QByteArray &input, const SKA_VEHICLE_NUM &ska_x_num, TCU_NUM tcu_x_num)
{
    //int oa_num = static_cast<int>(oa_x_num);
    qDebug() << "azdan az çoktan çok " ;
    qDebug() << "size of input " << input.size();
    qDebug() << "Gelen input verileri :  " << input;
    //qDebug() << "Gelen input veri tipi : " << typeof(input);


    int ska_num = static_cast<int>(ska_x_num);
    int tcu_num = static_cast<int>(tcu_x_num);

    qDebug() << "TCU SKA NUM  _____________ :  " << ska_num ;
    qDebug() << "TCU NUM  _____________ :  " << tcu_num ;

    //qDebug() << "SET DATA STRUCT SIZE of COLUMN COUNT SKA_TCU ========== :  " << m_tableWidget[ska_num][TCU1][MVB1]->columnCount() ;
    if (input.size() == sizeof(m_ska_x_tcu[ska_num][tcu_num])) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        //memcpy(&m_oa_x_etcs[oa_num], input.constData(), sizeof(m_oa_x_etcs[oa_num]));

        qDebug() << "SIZE of TCU MVB1 :  " << sizeof(m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bytes);
        qDebug() << "SIZE of TCU MVB2 :  " << sizeof(m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bytes);

        //qDebug() << "SIZE of MVB3 :  " << sizeof(m_ska_x_bcu[ska_num].oa_etcs_ccu_mvb3.bytes);

        // İlk alanı kopyala
        memcpy(&m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bytes, input.constData(), sizeof(m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bytes));

        QByteArray data =  input.mid(0, 32);
        qDebug() << "32 Bytelık data :  " << data;
        qDebug() << "UPDATE TCU MAP ÜSTÜ: &&&&&&&&&&&&&&&&&&&&  ";
        update_tcu_mvb_map(ska_x_num, tcu_x_num, SKA_TCU::MVB1);
        qDebug() << "UPDATE TCU MAP ALTI: &&&&&&&&&&&&&&&&&&&&  ";
        update_table(ska_x_num, tcu_x_num, SKA_TCU::MVB1);
        qDebug() << "UPDATE TCU TABLE ALTI: &&&&&&&&&&&&&&&&&&&&  ";

        // İkinci alanı kopyala, input.constData() + sizeof(etcs_ccu_mvb1) kadar ilerleyerek
        qDebug() << "MEMCPY 2 ÜSTÜ: &&&&&&&&&&&&&&&&&&&&  ";
        memcpy(&m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bytes, input.constData() + sizeof(m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb1.bytes), sizeof(m_ska_x_tcu[ska_num][tcu_num].ska_tcu_ccu_mvb2.bytes));
        qDebug() << "MEMCPY 2 ALTI: &&&&&&&&&&&&&&&&&&&&  ";
        update_tcu_mvb_map(ska_x_num, tcu_x_num, SKA_TCU::MVB2);
        qDebug() << "UPDATE MAP 2 ALTI: &&&&&&&&&&&&&&&&&&&&  ";
        //set_struct_mvb2(oa_x_num);
        update_table(ska_x_num, tcu_x_num, SKA_TCU::MVB2);
        qDebug() << "UPDATE TABLE 2 ALTI: &&&&&&&&&&&&&&&&&&&&  ";
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


void SKA_TCU::make_signal_slot_connection()
{


    // SKA1 HVAC1 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][TCU1][MVB1], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1, TCU1, MVB1); //BURASI DÜZENLENMELİ
    });

    // SKA1 HVAC2 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][TCU1][MVB2], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1, TCU1, MVB2);
    });

    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][TCU2][MVB1], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1, TCU2, MVB1);
    });

    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][TCU2][MVB2], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1, TCU2, MVB2);
    });


    //////////////////////////////////// SKA2 //////////////////////////////////////////////
    // SKA2 HVAC1 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][TCU1][MVB1], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2, TCU1, MVB1);
    });

    // SKA2 HVAC2 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][TCU1][MVB2], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2, TCU1, MVB2);
    });

    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][TCU2][MVB1], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2, TCU2, MVB1);
    });

    // SKA2 HVAC2 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][TCU2][MVB2], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2, TCU2, MVB2);
    });

}


void SKA_TCU::update_struct_with_map(SKA_VEHICLE_NUM ska_x_num, TCU_NUM tcu_x_num, MVB_NUM mvb_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    int tcu_num = static_cast<int>(tcu_x_num);
    // Define a lambda function to reduce redundancy
    auto setInputMap = [&](const QString& signal_name) {
        m_inputs_map[ska_num][tcu_num][mvb_num][signal_name] = utils::getTableWidgetValueByNameWithoutColumn(m_tableWidget[ska_num][tcu_num][mvb_num], signal_name).toInt();
    };
    // update map with given tableWidget values
    for(const auto& map : m_inputs_map[ska_num][tcu_num][mvb_num])
    {
        setInputMap(map.first);
    }
    // set struct parameters with given updated map parameters

    set_struct(ska_x_num,tcu_x_num,mvb_num);
}


