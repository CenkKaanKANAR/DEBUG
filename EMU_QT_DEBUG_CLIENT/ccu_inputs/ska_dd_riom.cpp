#include "ska_dd_riom.h"
#include "utils.h"

SKA_DD_RIOM::SKA_DD_RIOM(QObject *parent)
    : QObject{parent}
{
    memset(&m_ska_x_dd_riom, 0, sizeof(m_ska_x_dd_riom));
    init_inputs_table(SKA_VEHICLE_NUM::SKA1);
    init_inputs_table(SKA_VEHICLE_NUM::SKA2);

    init_status_table(SKA_VEHICLE_NUM::SKA1);
    init_status_table(SKA_VEHICLE_NUM::SKA2);



    make_signal_slot_connection();

}

SKA_DD_RIOM::~SKA_DD_RIOM()
{

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                delete m_tableWidget[i][j];
                m_tableWidget[i][j] = nullptr; // Güvenlik için nullptr atayın
            }
        }

}

void SKA_DD_RIOM::init_inputs_table(SKA_VEHICLE_NUM ska_x_num)
{

    int ska_num = static_cast<int>(ska_x_num);

    m_inputs_map[ska_num][MVB1] = {
                                                      {"PB_EMERGENCY_LOWERING_PANTOGRAPH",0},
                                                      {"RELAY_KEY_DRIVER_DESK_CABINET", 0},
                                                      {"LAMP_TEST",0},
                                                      {"ON_OFF_MODE_PARKING", 0},
                                                      {"CLOSING_VACUUM_CIRCUIT_BREAKER", 0},
                                                      {"OPENING_VACUUM_CIRCUIT_BREAKER", 0},
                                                      {"RAISING_PANTOGRAPH_1", 0},
                                                      {"DOWN_PANTOGRAPH_1", 0},
                                                      {"RAISING_PANTOGRAPH_2", 0},
                                                      {"DOWN_PANTOGRAPH_2", 0},
                                                      {"LEVER_SPEED_0", 0},
                                                      {"LEVER_SPEED_1", 0},
                                                      {"bit12", 0},
                                                      {"bit13", 0},
                                                      {"bit14", 0},
                                                      {"bit15", 0},
                                                      {"bit16", 0},
                                                      {"DEVICE_ID_DI_0", 0},
                                                      {"DEVICE_ID_DI_1", 0},
                                                      {"DEVICE_ID_DI_2", 0},
                                                      {"DEVICE_ID_DI_3", 0},
                                                      {"DEVICE_ID_DI_4", 0},
                                                      {"DEVICE_ID_DI_5", 0},
                                                      {"CONTROL_DESK_TEST_HW_OK_HEALT_RIOM_2", 0},
                                                      {"MC_EMERGENCY_BRAKE", 0},
                                                      {"PRESSURE_GOVERNOR_INDIRECT_BRAKE_CONTROL", 0},
                                                      {"MC_S1", 0},
                                                      {"MC_S2", 0},
                                                      {"MC_S3", 0},
                                                      {"MC_S4", 0},
                                                      {"MC_S5", 0},
                                                      {"MC_S6", 0},
                                                      {"NEUTRAL_N_DIRECTION", 0},
                                                      {"FORWARD_F_DIRECTION", 0},
                                                      {"REVERSE_R_DIRECTION", 0},
                                                      {"AUTOMATIC_DUMPER", 0},
                                                      {"CONTROL_DESK_RIOM_1_CB_PROTECTION", 0},
                                                      {"HATCH_FULL_CLOSED", 0},
                                                      {"HATCH_FULL_OPEN", 0},
                                                      {"bit39", 0},
                                                      {"bit40", 0},
                                                      {"bit41", 0},
                                                      {"bit42", 0},
                                                      {"bit43", 0},
                                                      {"bit44", 0},
                                                      {"bit45", 0},
                                                      {"bit46", 0},
                                                      {"bit47", 0},
                                                      {"MANUAL_CLOSING_DUMPER", 0},
                                                      {"PARKING_BRAKE_APPLICATION", 0},
                                                      {"PARKING_BRAKE_RELEASE", 0},
                                                      {"PUSHBUTTON_EMERGENCY", 0},
                                                      {"INDIRECT_BRAKE_MANIPULATOR", 0},
                                                      {"DMU_FAULT_SIGNAL", 0},
                                                      {"SANDING_COMMAND_AUTO", 0},
                                                      {"SANDING_COMMAND_LONG_TIME", 0},
                                                      {"SANDING_COMMAND_SHORT_TIME", 0},
                                                      {"EMERGENCY_EGRESS_DEVICE_INPUT", 0},
                                                      {"OPENING_DOORS_1357", 0},
                                                      {"ENABLE_DOORS_1357", 0},
                                                      {"CONTROL_DESK_RIOM_2_CB_PROTECTION", 0},
                                                      {"bit61", 0},
                                                      {"bit62", 0},
                                                      {"bit63", 0},
                                                      {"bit64", 0},
                                                      {"bit65", 0},
                                                      {"bit66", 0},
                                                      {"bit67", 0},
                                                      {"bit68", 0},
                                                      {"bit69", 0},
                                                      {"bit70", 0},
                                                      {"bit71", 0},
                                                      {"OPENING_DOORS_2468", 0},
                                                      {"ENABLE_DOORS_2468", 0},
                                                      {"PB_CLOSING_DOORS", 0},
                                                      {"DECOUPLING_AUTOMATIC_COUPLER", 0},
                                                      {"FIRE_ALARM_RESET_FAULT_RESET", 0},
                                                      {"WINDSCREEN_HEATING", 0},
                                                      {"WIPER_SYSTEM_FUNCTION_OK", 0},
                                                      {"WIPER_LEVEL_WASH_WATER_TANK", 0},
                                                      {"FULL_LIGHT_MARKER_LIGHT", 0},
                                                      {"DIMMED_HEAD_LIGHT_MARKER_LIGHT", 0},
                                                      {"MARKER_LIGHT", 0},
                                                      {"DIMMED_MARKER_LIGHT", 0},
                                                      {"bit84", 0},
                                                      {"bit85", 0},
                                                      {"bit86", 0},
                                                      {"bit87", 0},
                                                      {"bit88", 0},
                                                      {"bit89", 0},
                                                      {"bit90", 0},
                                                      {"bit91", 0},
                                                      {"bit92", 0},
                                                      {"bit93", 0},
                                                      {"bit94", 0},
                                                      {"bit95", 0},
                                                      {"signal_speed", 0},
                                                      {"reserved_14", 0},
                                                      {"reserved_15", 0},
                                                      };

    /*QStringList table_name = {"ska_1_dd_riom_ccu_mvb1_inputs", "value"};

    //m_tableWidget.push_back(new QTableWidget());
    m_tableWidget[ska_num][MVB1] = new QTableWidget();
    m_tableWidget[ska_num][MVB1] ->setColumnCount(2);
    m_tableWidget[ska_num][MVB1] ->setRowCount(m_inputs_map[ska_num][MVB1].size());
    m_tableWidget[ska_num][MVB1]->setHorizontalHeaderLabels(table_name);

    int row = 0;
    for (const auto& pair:  m_inputs_map[ska_num][MVB1]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[ska_num][MVB1]->setItem(row, 0, item_name);
        m_tableWidget[ska_num][MVB1]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[ska_num][MVB1]->resizeColumnsToContents();*/
    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[ska_num][MVB1].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[ska_num][MVB1] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[ska_num][MVB1]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[ska_num][MVB1]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[ska_num][MVB1]->setItem(row, column, item_name);
        m_tableWidget[ska_num][MVB1]->setItem(row, column + 1, item_val); // Değer
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
    m_tableWidget[ska_num][MVB1]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][MVB1]->columnCount() ;


}


/*
void SKA_DD_RIOM::init_ska2_table()
{
    m_inputs_map[get_index(SKA_VEHICLE_NUM::SKA2)] =  m_inputs_map[get_index(SKA_VEHICLE_NUM::SKA1)];
    QStringList table_name = {"ska_2_dd_riom_ccu_mvb1_inputs", "value"};

    m_tableWidget.push_back(new QTableWidget());
    m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)] ->setColumnCount(2);
    m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)] ->setRowCount(m_inputs_map[get_index(SKA_VEHICLE_NUM::SKA2)].size());
    m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)]->setHorizontalHeaderLabels(table_name);

    int row = 0;
    for (const auto& pair:  m_inputs_map[get_index(SKA_VEHICLE_NUM::SKA2)]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)]->setItem(row, 0, item_name);
        m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)]->resizeColumnsToContents();
}*/

void SKA_DD_RIOM::init_status_table(SKA_VEHICLE_NUM ska_x_num)
{

    int ska_num = static_cast<int>(ska_x_num);

    m_inputs_map[ska_num][STATUS0] = {

    {"lifesign",0},
    {"DIO01_Module_Error",0},
    {"DIO01_Output_Overcurrent",0},
    {"DIO01_Heartbeat_error",0},
    {"DIO01_Group_1_Voltage_error",0},
    {"DIO01_Group_2_Voltage_error",0},
    {"DIO01_Board_Temperature_error",0},
    {"bit22",0},
    {"bit23",0},
    {"DIO02_Module_Error",0},
    {"DIO02_Output_Overcurrent",0},
    {"DIO02_Heartbeat_error",0},
    {"DIO02_Group_1_Voltage_error",0},
    {"DIO02_Group_2_Voltage_error",0},
    {"DIO02_Board_Temperature_error",0},
    {"bit30",0},
    {"bit31",0},
    {"DIO03_Module_Error",0},
    {"DIO03_Output_Overcurrent",0},
    {"DIO03_Heartbeat_error",0},
    {"DIO03_Group_1_Voltage_error",0},
    {"DIO03_Group_2_Voltage_error",0},
    {"DIO03_Board_Temperature_error",0},
    {"bit38",0},
    {"bit39",0},
    {"DIO04_Module_Error",0},
    {"DIO04_Output_Overcurrent",0},
    {"DIO04_Heartbeat_error",0},
    {"DIO04_Group_1_Voltage_error",0},
    {"DIO04_Group_2_Voltage_error",0},
    {"DIO04_Board_Temperature_error",0},
    {"bit46",0},
    {"bit47",0},
    {"reserved_6",0},
    {"reserved_7",0},
    {"reserved_8",0},
    {"AIM01_Module_Error",0},
    {"AIM01_Heartbeat_error",0},
    {"bit74",0},
    {"bit75",0},
    {"bit76",0},
    {"bit77",0},
    {"bit78",0},
    {"bit79",0},
    {"PTI2037A_Module_Error",0},
    {"PTI2037A_Heartbeat_error",0},
    {"PTI2037A_Channel_1_Status",0},
    {"PTI2037A_Channel_2_Status",0},
    {"PTI2037A_Channel_3_Status",0},
    {"PTI2037A_Channel_4_Status",0},
    {"PTI2037A_Channel_5_Status",0},
    {"PTI2037A_Channel_6_Status",0},
    {"reserved_11",0},
    {"reserved_12",0},
    {"reserved_13",0},
    {"reserved_14",0},
    {"reserved_15",0}


     };

    /*QStringList table_name = {"ska_1_dd_riom_ccu_mvb_status", "value"};

    //m_tableWidget.push_back(new QTableWidget());
    m_tableWidget[ska_num][STATUS0] = new QTableWidget();
    m_tableWidget[ska_num][STATUS0] ->setColumnCount(2);
    m_tableWidget[ska_num][STATUS0] ->setRowCount(m_inputs_map[ska_num][MVB1].size());
    m_tableWidget[ska_num][STATUS0]->setHorizontalHeaderLabels(table_name);

    int row = 0;
    for (const auto& pair:  m_inputs_map[ska_num][STATUS0]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[ska_num][STATUS0]->setItem(row, 0, item_name);
        m_tableWidget[ska_num][STATUS0]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[ska_num][STATUS0]->resizeColumnsToContents();*/
    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[ska_num][STATUS0].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[ska_num][STATUS0] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[ska_num][STATUS0]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[ska_num][STATUS0]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[ska_num][STATUS0]->setItem(row, column, item_name);
        m_tableWidget[ska_num][STATUS0]->setItem(row, column + 1, item_val); // Değer
        item_name->setBackground(QColor("turquoise"));  // Turkuaz;
        item_val->setBackground(QColor("turquoise"));  // Turkuaz;
        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[ska_num][STATUS0]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][STATUS0]->columnCount() ;
}

void SKA_DD_RIOM::make_signal_slot_connection()
{

    //SKA1_STATUS
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][STATUS0], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1, STATUS0);
    });

    //SKA1_INPUTS
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][MVB1], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1, MVB1);
    });



    //SKA2_STATUS
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][STATUS0], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2, STATUS0);
    });

    //SKA2_INPUTS
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][MVB1], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2, MVB1);
    });


}



void SKA_DD_RIOM::update_inputs_map(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_inputs_map[ska_num][MVB1].at("PB_EMERGENCY_LOWERING_PANTOGRAPH")          =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.PB_EMERGENCY_LOWERING_PANTOGRAPH;
    m_inputs_map[ska_num][MVB1].at("RELAY_KEY_DRIVER_DESK_CABINET")             =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.RELAY_KEY_DRIVER_DESK_CABINET;
    m_inputs_map[ska_num][MVB1].at("LAMP_TEST")                                 =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.LAMP_TEST;
    m_inputs_map[ska_num][MVB1].at("ON_OFF_MODE_PARKING")                       =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.ON_OFF_MODE_PARKING;
    m_inputs_map[ska_num][MVB1].at("CLOSING_VACUUM_CIRCUIT_BREAKER")            =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.CLOSING_VACUUM_CIRCUIT_BREAKER;
    m_inputs_map[ska_num][MVB1].at("OPENING_VACUUM_CIRCUIT_BREAKER")            =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.OPENING_VACUUM_CIRCUIT_BREAKER;
    m_inputs_map[ska_num][MVB1].at("RAISING_PANTOGRAPH_1")                      =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.RAISING_PANTOGRAPH_1;
    m_inputs_map[ska_num][MVB1].at("DOWN_PANTOGRAPH_1")                         =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DOWN_PANTOGRAPH_1;
    m_inputs_map[ska_num][MVB1].at("RAISING_PANTOGRAPH_2")                      =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.RAISING_PANTOGRAPH_2;
    m_inputs_map[ska_num][MVB1].at("DOWN_PANTOGRAPH_2")                         =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DOWN_PANTOGRAPH_2;
    m_inputs_map[ska_num][MVB1].at("LEVER_SPEED_0")                             =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.LEVER_SPEED_0;
    m_inputs_map[ska_num][MVB1].at("LEVER_SPEED_1")                             =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.LEVER_SPEED_1;
    m_inputs_map[ska_num][MVB1].at("bit12")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit12;
    m_inputs_map[ska_num][MVB1].at("bit13")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit13;
    m_inputs_map[ska_num][MVB1].at("bit14")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit14;
    m_inputs_map[ska_num][MVB1].at("bit15")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit15;
    m_inputs_map[ska_num][MVB1].at("bit16")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit16;
    m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_0")                            =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_0;
    m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_1")                            =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_1;
    m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_2")                            =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_2;
    m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_3")                            =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_3;
    m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_4")                            =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_4;
    m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_5")                            =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_5;
    m_inputs_map[ska_num][MVB1].at("CONTROL_DESK_TEST_HW_OK_HEALT_RIOM_2")      =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.CONTROL_DESK_TEST_HW_OK_HEALT_RIOM_2;
    m_inputs_map[ska_num][MVB1].at("MC_EMERGENCY_BRAKE")                        =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.MC_EMERGENCY_BRAKE;
    m_inputs_map[ska_num][MVB1].at("PRESSURE_GOVERNOR_INDIRECT_BRAKE_CONTROL")  =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.PRESSURE_GOVERNOR_INDIRECT_BRAKE_CONTROL;
    m_inputs_map[ska_num][MVB1].at("MC_S1")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.MC_S1;
    m_inputs_map[ska_num][MVB1].at("MC_S2")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.MC_S2;
    m_inputs_map[ska_num][MVB1].at("MC_S3")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.MC_S3;
    m_inputs_map[ska_num][MVB1].at("MC_S4")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.MC_S4;
    m_inputs_map[ska_num][MVB1].at("MC_S5")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.MC_S5;
    m_inputs_map[ska_num][MVB1].at("MC_S6")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.MC_S6;
    m_inputs_map[ska_num][MVB1].at("NEUTRAL_N_DIRECTION")                       =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.NEUTRAL_N_DIRECTION;
    m_inputs_map[ska_num][MVB1].at("FORWARD_F_DIRECTION")                       =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.FORWARD_F_DIRECTION;
    m_inputs_map[ska_num][MVB1].at("REVERSE_R_DIRECTION")                       =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.REVERSE_R_DIRECTION;
    m_inputs_map[ska_num][MVB1].at("AUTOMATIC_DUMPER")                          =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.AUTOMATIC_DUMPER;
    m_inputs_map[ska_num][MVB1].at("CONTROL_DESK_RIOM_1_CB_PROTECTION")         =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.CONTROL_DESK_RIOM_1_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("HATCH_FULL_CLOSED")                         =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.HATCH_FULL_CLOSED;
    m_inputs_map[ska_num][MVB1].at("HATCH_FULL_OPEN")                           =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.HATCH_FULL_OPEN;
    m_inputs_map[ska_num][MVB1].at("bit39")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit39;
    m_inputs_map[ska_num][MVB1].at("bit40")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit40;
    m_inputs_map[ska_num][MVB1].at("bit41")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit41;
    m_inputs_map[ska_num][MVB1].at("bit42")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit42;
    m_inputs_map[ska_num][MVB1].at("bit43")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit43;
    m_inputs_map[ska_num][MVB1].at("bit44")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit44;
    m_inputs_map[ska_num][MVB1].at("bit45")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit45;
    m_inputs_map[ska_num][MVB1].at("bit46")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit46;
    m_inputs_map[ska_num][MVB1].at("bit47")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit47;
    m_inputs_map[ska_num][MVB1].at("MANUAL_CLOSING_DUMPER")                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.MANUAL_CLOSING_DUMPER;
    m_inputs_map[ska_num][MVB1].at("PARKING_BRAKE_APPLICATION")                 =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.PARKING_BRAKE_APPLICATION;
    m_inputs_map[ska_num][MVB1].at("PARKING_BRAKE_RELEASE")                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.PARKING_BRAKE_RELEASE;
    m_inputs_map[ska_num][MVB1].at("PUSHBUTTON_EMERGENCY")                      =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.PUSHBUTTON_EMERGENCY;
    m_inputs_map[ska_num][MVB1].at("INDIRECT_BRAKE_MANIPULATOR")                =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.INDIRECT_BRAKE_MANIPULATOR;
    m_inputs_map[ska_num][MVB1].at("DMU_FAULT_SIGNAL")                          =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DMU_FAULT_SIGNAL;
    m_inputs_map[ska_num][MVB1].at("SANDING_COMMAND_AUTO")                      =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.SANDING_COMMAND_AUTO;
    m_inputs_map[ska_num][MVB1].at("SANDING_COMMAND_LONG_TIME")                 =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.SANDING_COMMAND_LONG_TIME;
    m_inputs_map[ska_num][MVB1].at("SANDING_COMMAND_SHORT_TIME")                =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.SANDING_COMMAND_SHORT_TIME;
    m_inputs_map[ska_num][MVB1].at("EMERGENCY_EGRESS_DEVICE_INPUT")             =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.EMERGENCY_EGRESS_DEVICE_INPUT;
    m_inputs_map[ska_num][MVB1].at("OPENING_DOORS_1357")                        =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.OPENING_DOORS_1357;
    m_inputs_map[ska_num][MVB1].at("ENABLE_DOORS_1357")                         =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.ENABLE_DOORS_1357;
    m_inputs_map[ska_num][MVB1].at("CONTROL_DESK_RIOM_2_CB_PROTECTION")         =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.CONTROL_DESK_RIOM_2_CB_PROTECTION;
    m_inputs_map[ska_num][MVB1].at("bit61")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit61;
    m_inputs_map[ska_num][MVB1].at("bit62")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit62;
    m_inputs_map[ska_num][MVB1].at("bit63")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit63;
    m_inputs_map[ska_num][MVB1].at("bit64")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit64;
    m_inputs_map[ska_num][MVB1].at("bit65")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit65;
    m_inputs_map[ska_num][MVB1].at("bit66")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit66;
    m_inputs_map[ska_num][MVB1].at("bit67")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit67;
    m_inputs_map[ska_num][MVB1].at("bit68")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit68;
    m_inputs_map[ska_num][MVB1].at("bit69")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit69;
    m_inputs_map[ska_num][MVB1].at("bit70")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit70;
    m_inputs_map[ska_num][MVB1].at("bit71")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit71;
    m_inputs_map[ska_num][MVB1].at("OPENING_DOORS_2468")                        =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.OPENING_DOORS_2468;
    m_inputs_map[ska_num][MVB1].at("ENABLE_DOORS_2468")                         =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.ENABLE_DOORS_2468;
    m_inputs_map[ska_num][MVB1].at("PB_CLOSING_DOORS")                          =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.PB_CLOSING_DOORS;
    m_inputs_map[ska_num][MVB1].at("DECOUPLING_AUTOMATIC_COUPLER")              =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DECOUPLING_AUTOMATIC_COUPLER;
    m_inputs_map[ska_num][MVB1].at("FIRE_ALARM_RESET_FAULT_RESET")              =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.FIRE_ALARM_RESET_FAULT_RESET;
    m_inputs_map[ska_num][MVB1].at("WINDSCREEN_HEATING")                        =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.WINDSCREEN_HEATING;
    m_inputs_map[ska_num][MVB1].at("WIPER_SYSTEM_FUNCTION_OK")                  =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.WIPER_SYSTEM_FUNCTION_OK;
    m_inputs_map[ska_num][MVB1].at("WIPER_LEVEL_WASH_WATER_TANK")               =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.WIPER_LEVEL_WASH_WATER_TANK;
    m_inputs_map[ska_num][MVB1].at("FULL_LIGHT_MARKER_LIGHT")                   =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.FULL_LIGHT_MARKER_LIGHT;
    m_inputs_map[ska_num][MVB1].at("DIMMED_HEAD_LIGHT_MARKER_LIGHT")            =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DIMMED_HEAD_LIGHT_MARKER_LIGHT;
    m_inputs_map[ska_num][MVB1].at("MARKER_LIGHT")                              =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.MARKER_LIGHT;
    m_inputs_map[ska_num][MVB1].at("DIMMED_MARKER_LIGHT")                       =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DIMMED_MARKER_LIGHT;
    m_inputs_map[ska_num][MVB1].at("bit84")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit84;
    m_inputs_map[ska_num][MVB1].at("bit85")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit85;
    m_inputs_map[ska_num][MVB1].at("bit86")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit86;
    m_inputs_map[ska_num][MVB1].at("bit87")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit87;
    m_inputs_map[ska_num][MVB1].at("bit88")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit88;
    m_inputs_map[ska_num][MVB1].at("bit89")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit89;
    m_inputs_map[ska_num][MVB1].at("bit90")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit90;
    m_inputs_map[ska_num][MVB1].at("bit91")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit91;
    m_inputs_map[ska_num][MVB1].at("bit92")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit92;
    m_inputs_map[ska_num][MVB1].at("bit93")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit93;
    m_inputs_map[ska_num][MVB1].at("bit94")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit94;
    m_inputs_map[ska_num][MVB1].at("bit95")                                     =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit95;
    m_inputs_map[ska_num][MVB1].at("signal_speed")                              =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.signal_speed;
    m_inputs_map[ska_num][MVB1].at("reserved_14")                               =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.reserved_14;
    m_inputs_map[ska_num][MVB1].at("reserved_15")                               =m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.reserved_15;

}

void SKA_DD_RIOM::update_status_map(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_inputs_map[ska_num][STATUS0].at("lifesign")                           = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.lifesign                         ;
    m_inputs_map[ska_num][STATUS0].at("DIO01_Module_Error")                 = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO01_Module_Error               ;
    m_inputs_map[ska_num][STATUS0].at("DIO01_Output_Overcurrent")           = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO01_Output_Overcurrent         ;
    m_inputs_map[ska_num][STATUS0].at("DIO01_Heartbeat_error")              = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO01_Heartbeat_error            ;
    m_inputs_map[ska_num][STATUS0].at("DIO01_Group_1_Voltage_error")        = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO01_Group_1_Voltage_error      ;
    m_inputs_map[ska_num][STATUS0].at("DIO01_Group_2_Voltage_error")        = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO01_Group_2_Voltage_error      ;
    m_inputs_map[ska_num][STATUS0].at("DIO01_Board_Temperature_error")      = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO01_Board_Temperature_error    ;
    m_inputs_map[ska_num][STATUS0].at("bit22")                              = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit22                            ;
    m_inputs_map[ska_num][STATUS0].at("bit23")                              = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit23                            ;
    m_inputs_map[ska_num][STATUS0].at("DIO02_Module_Error")                 = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO02_Module_Error               ;
    m_inputs_map[ska_num][STATUS0].at("DIO02_Output_Overcurrent")           = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO02_Output_Overcurrent         ;
    m_inputs_map[ska_num][STATUS0].at("DIO02_Heartbeat_error")              = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO02_Heartbeat_error            ;
    m_inputs_map[ska_num][STATUS0].at("DIO02_Group_1_Voltage_error")        = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO02_Group_1_Voltage_error      ;
    m_inputs_map[ska_num][STATUS0].at("DIO02_Group_2_Voltage_error")        = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO02_Group_2_Voltage_error      ;
    m_inputs_map[ska_num][STATUS0].at("DIO02_Board_Temperature_error")      = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO02_Board_Temperature_error    ;
    m_inputs_map[ska_num][STATUS0].at("bit30")                              = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit30                            ;
    m_inputs_map[ska_num][STATUS0].at("bit31")                              = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit31                            ;
    m_inputs_map[ska_num][STATUS0].at("DIO03_Module_Error")                 = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO03_Module_Error               ;
    m_inputs_map[ska_num][STATUS0].at("DIO03_Output_Overcurrent")           = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO03_Output_Overcurrent         ;
    m_inputs_map[ska_num][STATUS0].at("DIO03_Heartbeat_error")              = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO03_Heartbeat_error            ;
    m_inputs_map[ska_num][STATUS0].at("DIO03_Group_1_Voltage_error")        = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO03_Group_1_Voltage_error      ;
    m_inputs_map[ska_num][STATUS0].at("DIO03_Group_2_Voltage_error")        = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO03_Group_2_Voltage_error      ;
    m_inputs_map[ska_num][STATUS0].at("DIO03_Board_Temperature_error")      = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO03_Board_Temperature_error    ;
    m_inputs_map[ska_num][STATUS0].at("bit38")                              = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit38                            ;
    m_inputs_map[ska_num][STATUS0].at("bit39")                              = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit39                            ;
    m_inputs_map[ska_num][STATUS0].at("DIO04_Module_Error")                 = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO04_Module_Error               ;
    m_inputs_map[ska_num][STATUS0].at("DIO04_Output_Overcurrent")           = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO04_Output_Overcurrent         ;
    m_inputs_map[ska_num][STATUS0].at("DIO04_Heartbeat_error")              = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO04_Heartbeat_error            ;
    m_inputs_map[ska_num][STATUS0].at("DIO04_Group_1_Voltage_error")        = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO04_Group_1_Voltage_error      ;
    m_inputs_map[ska_num][STATUS0].at("DIO04_Group_2_Voltage_error")        = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO04_Group_2_Voltage_error      ;
    m_inputs_map[ska_num][STATUS0].at("DIO04_Board_Temperature_error")      = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO04_Board_Temperature_error    ;
    m_inputs_map[ska_num][STATUS0].at("bit46")                              = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit46                            ;
    m_inputs_map[ska_num][STATUS0].at("bit47")                              = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit47                            ;
    m_inputs_map[ska_num][STATUS0].at("reserved_6")                         = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.reserved_6                       ;
    m_inputs_map[ska_num][STATUS0].at("reserved_7")                         = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.reserved_7                       ;
    m_inputs_map[ska_num][STATUS0].at("reserved_8")                         = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.reserved_8                       ;
    m_inputs_map[ska_num][STATUS0].at("AIM01_Module_Error")                 = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.AIM01_Module_Error               ;
    m_inputs_map[ska_num][STATUS0].at("AIM01_Heartbeat_error")              = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.AIM01_Heartbeat_error            ;
    m_inputs_map[ska_num][STATUS0].at("bit74")                              = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit74                            ;
    m_inputs_map[ska_num][STATUS0].at("bit75")                              = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit75                            ;
    m_inputs_map[ska_num][STATUS0].at("bit76")                              = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit76                            ;
    m_inputs_map[ska_num][STATUS0].at("bit77")                              = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit77                            ;
    m_inputs_map[ska_num][STATUS0].at("bit78")                              = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit78                            ;
    m_inputs_map[ska_num][STATUS0].at("bit79")                              = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit79                            ;
    m_inputs_map[ska_num][STATUS0].at("PTI2037A_Module_Error")              = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.PTI2037A_Module_Error            ;
    m_inputs_map[ska_num][STATUS0].at("PTI2037A_Heartbeat_error")           = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.PTI2037A_Heartbeat_error         ;
    m_inputs_map[ska_num][STATUS0].at("PTI2037A_Channel_1_Status")          = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.PTI2037A_Channel_1_Status        ;
    m_inputs_map[ska_num][STATUS0].at("PTI2037A_Channel_2_Status")          = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.PTI2037A_Channel_2_Status        ;
    m_inputs_map[ska_num][STATUS0].at("PTI2037A_Channel_3_Status")          = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.PTI2037A_Channel_3_Status        ;
    m_inputs_map[ska_num][STATUS0].at("PTI2037A_Channel_4_Status")          = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.PTI2037A_Channel_4_Status        ;
    m_inputs_map[ska_num][STATUS0].at("PTI2037A_Channel_5_Status")          = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.PTI2037A_Channel_5_Status        ;
    m_inputs_map[ska_num][STATUS0].at("PTI2037A_Channel_6_Status")          = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.PTI2037A_Channel_6_Status        ;
    m_inputs_map[ska_num][STATUS0].at("reserved_11")                        = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.reserved_11                      ;
    m_inputs_map[ska_num][STATUS0].at("reserved_12")                        = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.reserved_12                      ;
    m_inputs_map[ska_num][STATUS0].at("reserved_13")                        = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.reserved_13                      ;
    m_inputs_map[ska_num][STATUS0].at("reserved_14")                        = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.reserved_14                      ;
    m_inputs_map[ska_num][STATUS0].at("reserved_15")                        = m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.reserved_15                      ;


}



void SKA_DD_RIOM::update_table(SKA_VEHICLE_NUM ska_x_num,MVB_NUM mvb_num)
{
    int ska_num = static_cast<int>(ska_x_num);

    for(const auto & map:m_inputs_map[ska_num][mvb_num]){
        //qDebug() <<  map.first << map.second;
        utils::setTableWidgetValueByNameWithoutColumn(m_tableWidget[ska_num][mvb_num], map.first, map.second );
    }
    /*    int ska_num = static_cast<int>(ska_x_num);
    // İndeksleri kullanarak tabloyu güncelle
    qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][FDS1]->columnCount() ;
    std::vector<int> valueColumns = {1, 3, 5, 7};
    for(const auto & map:m_inputs_map[ska_num][fds_num]){


            utils::setTableWidgetValueByNameWithoutColumn(m_tableWidget[ska_num][fds_num], map.first, map.second);
            //qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT INSIDE FOR LOOP ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;

            //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,3, map.second);
            //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,5, map.second);
            //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,7, map.second);
    }*/
}

void SKA_DD_RIOM::set_data_struct(const QByteArray &input, const SKA_VEHICLE_NUM &ska_x_num)
{
    //int oa_num = static_cast<int>(oa_x_num);
    qDebug() << "azdan az çoktan çok " ;
    qDebug() << "size of input " << input.size();
    qDebug() << "Gelen input verileri :  " << input;
    //qDebug() << "Gelen input veri tipi : " << typeof(input);


    int ska_num = static_cast<int>(ska_x_num);
    qDebug() << "bassana lan şunu sizeof(m_oa_x_jru[oa_num])  " << sizeof(m_ska_x_dd_riom[ska_num]);

    if (input.size() == sizeof(m_ska_x_dd_riom[ska_num])) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        //memcpy(&m_oa_x_etcs[oa_num], input.constData(), sizeof(m_oa_x_etcs[oa_num]));

        qDebug() << "SIZE of STATUS :  " << sizeof(m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bytes);
        qDebug() << "SIZE of MVB1 :  " << sizeof(m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bytes);


        // İlk alanı kopyala
        memcpy(&m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bytes, input.constData(), sizeof(m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bytes));
        update_status_map(ska_x_num);
        update_table(ska_x_num,STATUS0);

        // İkinci alanı kopyala
        memcpy(&m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bytes, input.constData() + sizeof(m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bytes), sizeof(m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bytes));
        update_inputs_map(ska_x_num);

        update_table(ska_x_num,MVB1);

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


void SKA_DD_RIOM::update_struct_with_map(SKA_VEHICLE_NUM ska_x_num, MVB_NUM mvb_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    // Define a lambda function to reduce redundancy
    auto setInputMap = [&](const QString& signal_name) {
        m_inputs_map[ska_num][mvb_num][signal_name] = utils::getTableWidgetValueByNameWithoutColumn(m_tableWidget[ska_num][mvb_num], signal_name).toInt();
    };

    for(const auto& map : m_inputs_map[ska_num][mvb_num])
    {
        setInputMap(map.first);
    }

    set_inputs_struct(ska_x_num);
    set_status_struct(ska_x_num);
    //????? set_status_struct...!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


    /*    int ska_num = static_cast<int>(ska_x_num);
    // Define a lambda function to reduce redundancy
    auto setInputMap = [&](const QString& signal_name) {
        m_inputs_map[ska_num][HVAC_NUM][signal_name] = utils::getTableWidgetValueByNameWithoutColumn(m_tableWidget[ska_num][HVAC_NUM], signal_name).toInt();
    };
    // update map with given tableWidget values
    for(const auto& map : m_inputs_map[ska_num][HVAC_NUM])
    {
        setInputMap(map.first);
    }
    // set struct parameters with given updated map parameters
    set_struct_hvac1(ska_x_num);
    set_struct_hvac2(ska_x_num);
    set_struct_hvac3(ska_x_num);*/
}

void SKA_DD_RIOM::set_inputs_struct(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.PB_EMERGENCY_LOWERING_PANTOGRAPH          =  m_inputs_map[ska_num][MVB1].at("PB_EMERGENCY_LOWERING_PANTOGRAPH")          ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.RELAY_KEY_DRIVER_DESK_CABINET             =  m_inputs_map[ska_num][MVB1].at("RELAY_KEY_DRIVER_DESK_CABINET")             ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.LAMP_TEST                                 =  m_inputs_map[ska_num][MVB1].at("LAMP_TEST")                                 ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.ON_OFF_MODE_PARKING                       =  m_inputs_map[ska_num][MVB1].at("ON_OFF_MODE_PARKING")                       ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.CLOSING_VACUUM_CIRCUIT_BREAKER            =  m_inputs_map[ska_num][MVB1].at("CLOSING_VACUUM_CIRCUIT_BREAKER")            ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.OPENING_VACUUM_CIRCUIT_BREAKER            =  m_inputs_map[ska_num][MVB1].at("OPENING_VACUUM_CIRCUIT_BREAKER")            ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.RAISING_PANTOGRAPH_1                      =  m_inputs_map[ska_num][MVB1].at("RAISING_PANTOGRAPH_1")                      ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DOWN_PANTOGRAPH_1                         =  m_inputs_map[ska_num][MVB1].at("DOWN_PANTOGRAPH_1")                         ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.RAISING_PANTOGRAPH_2                      =  m_inputs_map[ska_num][MVB1].at("RAISING_PANTOGRAPH_2")                      ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DOWN_PANTOGRAPH_2                         =  m_inputs_map[ska_num][MVB1].at("DOWN_PANTOGRAPH_2")                         ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.LEVER_SPEED_0                             =  m_inputs_map[ska_num][MVB1].at("LEVER_SPEED_0")                             ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.LEVER_SPEED_1                             =  m_inputs_map[ska_num][MVB1].at("LEVER_SPEED_1")                             ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit12                                     =  m_inputs_map[ska_num][MVB1].at("bit12")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit13                                     =  m_inputs_map[ska_num][MVB1].at("bit13")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit14                                     =  m_inputs_map[ska_num][MVB1].at("bit14")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit15                                     =  m_inputs_map[ska_num][MVB1].at("bit15")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit16                                     =  m_inputs_map[ska_num][MVB1].at("bit16")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_0                            =  m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_0")                            ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_1                            =  m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_1")                            ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_2                            =  m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_2")                            ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_3                            =  m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_3")                            ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_4                            =  m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_4")                            ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DEVICE_ID_DI_5                            =  m_inputs_map[ska_num][MVB1].at("DEVICE_ID_DI_5")                            ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.CONTROL_DESK_TEST_HW_OK_HEALT_RIOM_2      =  m_inputs_map[ska_num][MVB1].at("CONTROL_DESK_TEST_HW_OK_HEALT_RIOM_2")      ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.MC_EMERGENCY_BRAKE                        =  m_inputs_map[ska_num][MVB1].at("MC_EMERGENCY_BRAKE")                        ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.PRESSURE_GOVERNOR_INDIRECT_BRAKE_CONTROL  =  m_inputs_map[ska_num][MVB1].at("PRESSURE_GOVERNOR_INDIRECT_BRAKE_CONTROL")  ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.MC_S1                                     =  m_inputs_map[ska_num][MVB1].at("MC_S1")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.MC_S2                                     =  m_inputs_map[ska_num][MVB1].at("MC_S2")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.MC_S3                                     =  m_inputs_map[ska_num][MVB1].at("MC_S3")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.MC_S4                                     =  m_inputs_map[ska_num][MVB1].at("MC_S4")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.MC_S5                                     =  m_inputs_map[ska_num][MVB1].at("MC_S5")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.MC_S6                                     =  m_inputs_map[ska_num][MVB1].at("MC_S6")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.NEUTRAL_N_DIRECTION                       =  m_inputs_map[ska_num][MVB1].at("NEUTRAL_N_DIRECTION")                       ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.FORWARD_F_DIRECTION                       =  m_inputs_map[ska_num][MVB1].at("FORWARD_F_DIRECTION")                       ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.REVERSE_R_DIRECTION                       =  m_inputs_map[ska_num][MVB1].at("REVERSE_R_DIRECTION")                       ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.AUTOMATIC_DUMPER                          =  m_inputs_map[ska_num][MVB1].at("AUTOMATIC_DUMPER")                          ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.CONTROL_DESK_RIOM_1_CB_PROTECTION         =  m_inputs_map[ska_num][MVB1].at("CONTROL_DESK_RIOM_1_CB_PROTECTION")         ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.HATCH_FULL_CLOSED                         =  m_inputs_map[ska_num][MVB1].at("HATCH_FULL_CLOSED")                         ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.HATCH_FULL_OPEN                           =  m_inputs_map[ska_num][MVB1].at("HATCH_FULL_OPEN")                           ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit39                                     =  m_inputs_map[ska_num][MVB1].at("bit39")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit40                                     =  m_inputs_map[ska_num][MVB1].at("bit40")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit41                                     =  m_inputs_map[ska_num][MVB1].at("bit41")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit42                                     =  m_inputs_map[ska_num][MVB1].at("bit42")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit43                                     =  m_inputs_map[ska_num][MVB1].at("bit43")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit44                                     =  m_inputs_map[ska_num][MVB1].at("bit44")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit45                                     =  m_inputs_map[ska_num][MVB1].at("bit45")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit46                                     =  m_inputs_map[ska_num][MVB1].at("bit46")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit47                                     =  m_inputs_map[ska_num][MVB1].at("bit47")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.MANUAL_CLOSING_DUMPER                     =  m_inputs_map[ska_num][MVB1].at("MANUAL_CLOSING_DUMPER")                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.PARKING_BRAKE_APPLICATION                 =  m_inputs_map[ska_num][MVB1].at("PARKING_BRAKE_APPLICATION")                 ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.PARKING_BRAKE_RELEASE                     =  m_inputs_map[ska_num][MVB1].at("PARKING_BRAKE_RELEASE")                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.PUSHBUTTON_EMERGENCY                      =  m_inputs_map[ska_num][MVB1].at("PUSHBUTTON_EMERGENCY")                      ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.INDIRECT_BRAKE_MANIPULATOR                =  m_inputs_map[ska_num][MVB1].at("INDIRECT_BRAKE_MANIPULATOR")                ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DMU_FAULT_SIGNAL                          =  m_inputs_map[ska_num][MVB1].at("DMU_FAULT_SIGNAL")                          ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.SANDING_COMMAND_AUTO                      =  m_inputs_map[ska_num][MVB1].at("SANDING_COMMAND_AUTO")                      ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.SANDING_COMMAND_LONG_TIME                 =  m_inputs_map[ska_num][MVB1].at("SANDING_COMMAND_LONG_TIME")                 ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.SANDING_COMMAND_SHORT_TIME                =  m_inputs_map[ska_num][MVB1].at("SANDING_COMMAND_SHORT_TIME")                ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.EMERGENCY_EGRESS_DEVICE_INPUT             =  m_inputs_map[ska_num][MVB1].at("EMERGENCY_EGRESS_DEVICE_INPUT")             ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.OPENING_DOORS_1357                        =  m_inputs_map[ska_num][MVB1].at("OPENING_DOORS_1357")                        ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.ENABLE_DOORS_1357                         =  m_inputs_map[ska_num][MVB1].at("ENABLE_DOORS_1357")                         ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.CONTROL_DESK_RIOM_2_CB_PROTECTION         =  m_inputs_map[ska_num][MVB1].at("CONTROL_DESK_RIOM_2_CB_PROTECTION")         ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit61                                     =  m_inputs_map[ska_num][MVB1].at("bit61")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit62                                     =  m_inputs_map[ska_num][MVB1].at("bit62")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit63                                     =  m_inputs_map[ska_num][MVB1].at("bit63")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit64                                     =  m_inputs_map[ska_num][MVB1].at("bit64")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit65                                     =  m_inputs_map[ska_num][MVB1].at("bit65")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit66                                     =  m_inputs_map[ska_num][MVB1].at("bit66")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit67                                     =  m_inputs_map[ska_num][MVB1].at("bit67")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit68                                     =  m_inputs_map[ska_num][MVB1].at("bit68")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit69                                     =  m_inputs_map[ska_num][MVB1].at("bit69")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit70                                     =  m_inputs_map[ska_num][MVB1].at("bit70")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit71                                     =  m_inputs_map[ska_num][MVB1].at("bit71")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.OPENING_DOORS_2468                        =  m_inputs_map[ska_num][MVB1].at("OPENING_DOORS_2468")                        ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.ENABLE_DOORS_2468                         =  m_inputs_map[ska_num][MVB1].at("ENABLE_DOORS_2468")                         ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.PB_CLOSING_DOORS                          =  m_inputs_map[ska_num][MVB1].at("PB_CLOSING_DOORS")                          ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DECOUPLING_AUTOMATIC_COUPLER              =  m_inputs_map[ska_num][MVB1].at("DECOUPLING_AUTOMATIC_COUPLER")              ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.FIRE_ALARM_RESET_FAULT_RESET              =  m_inputs_map[ska_num][MVB1].at("FIRE_ALARM_RESET_FAULT_RESET")              ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.WINDSCREEN_HEATING                        =  m_inputs_map[ska_num][MVB1].at("WINDSCREEN_HEATING")                        ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.WIPER_SYSTEM_FUNCTION_OK                  =  m_inputs_map[ska_num][MVB1].at("WIPER_SYSTEM_FUNCTION_OK")                  ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.WIPER_LEVEL_WASH_WATER_TANK               =  m_inputs_map[ska_num][MVB1].at("WIPER_LEVEL_WASH_WATER_TANK")               ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.FULL_LIGHT_MARKER_LIGHT                   =  m_inputs_map[ska_num][MVB1].at("FULL_LIGHT_MARKER_LIGHT")                   ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DIMMED_HEAD_LIGHT_MARKER_LIGHT            =  m_inputs_map[ska_num][MVB1].at("DIMMED_HEAD_LIGHT_MARKER_LIGHT")            ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.MARKER_LIGHT                              =  m_inputs_map[ska_num][MVB1].at("MARKER_LIGHT")                              ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.DIMMED_MARKER_LIGHT                       =  m_inputs_map[ska_num][MVB1].at("DIMMED_MARKER_LIGHT")                       ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit84                                     =  m_inputs_map[ska_num][MVB1].at("bit84")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit85                                     =  m_inputs_map[ska_num][MVB1].at("bit85")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit86                                     =  m_inputs_map[ska_num][MVB1].at("bit86")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit87                                     =  m_inputs_map[ska_num][MVB1].at("bit87")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit88                                     =  m_inputs_map[ska_num][MVB1].at("bit88")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit89                                     =  m_inputs_map[ska_num][MVB1].at("bit89")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit90                                     =  m_inputs_map[ska_num][MVB1].at("bit90")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit91                                     =  m_inputs_map[ska_num][MVB1].at("bit91")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit92                                     =  m_inputs_map[ska_num][MVB1].at("bit92")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit93                                     =  m_inputs_map[ska_num][MVB1].at("bit93")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit94                                     =  m_inputs_map[ska_num][MVB1].at("bit94")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.bit95                                     =  m_inputs_map[ska_num][MVB1].at("bit95")                                     ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.signal_speed                              =  m_inputs_map[ska_num][MVB1].at("signal_speed")                              ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.reserved_14                               =  m_inputs_map[ska_num][MVB1].at("reserved_14")                               ;
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb1_inputs.bits.reserved_15                               =  m_inputs_map[ska_num][MVB1].at("reserved_15")                               ;

}

void SKA_DD_RIOM::set_status_struct(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.lifesign                                     =  m_inputs_map[ska_num][STATUS0].at("lifesign");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO01_Module_Error                                     =  m_inputs_map[ska_num][STATUS0].at("DIO01_Module_Error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO01_Output_Overcurrent                                     =  m_inputs_map[ska_num][STATUS0].at("DIO01_Output_Overcurrent");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO01_Heartbeat_error                                     =  m_inputs_map[ska_num][STATUS0].at("DIO01_Heartbeat_error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO01_Group_1_Voltage_error                                      =  m_inputs_map[ska_num][STATUS0].at("DIO01_Group_1_Voltage_error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO01_Group_2_Voltage_error                                      =  m_inputs_map[ska_num][STATUS0].at("DIO01_Group_2_Voltage_error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO01_Board_Temperature_error                                      =  m_inputs_map[ska_num][STATUS0].at("DIO01_Board_Temperature_error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit22                                      =  m_inputs_map[ska_num][STATUS0].at("bit22");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit23                                      =  m_inputs_map[ska_num][STATUS0].at("bit23");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO02_Module_Error                                      =  m_inputs_map[ska_num][STATUS0].at("DIO02_Module_Error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO02_Output_Overcurrent                                     =  m_inputs_map[ska_num][STATUS0].at("DIO02_Output_Overcurrent");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO02_Heartbeat_error                                      =  m_inputs_map[ska_num][STATUS0].at("DIO02_Heartbeat_error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO02_Group_1_Voltage_error                                      =  m_inputs_map[ska_num][STATUS0].at("DIO02_Group_1_Voltage_error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO02_Group_2_Voltage_error                                      =  m_inputs_map[ska_num][STATUS0].at("DIO02_Group_2_Voltage_error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO02_Board_Temperature_error                                      =  m_inputs_map[ska_num][STATUS0].at("DIO02_Board_Temperature_error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit30                                      =  m_inputs_map[ska_num][STATUS0].at("bit30");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit31                                      =  m_inputs_map[ska_num][STATUS0].at("bit31");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO03_Module_Error                                      =  m_inputs_map[ska_num][STATUS0].at("DIO03_Module_Error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO03_Output_Overcurrent                                      =  m_inputs_map[ska_num][STATUS0].at("DIO03_Output_Overcurrent");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO03_Heartbeat_error                                      =  m_inputs_map[ska_num][STATUS0].at("DIO03_Heartbeat_error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO03_Group_1_Voltage_error                                      =  m_inputs_map[ska_num][STATUS0].at("DIO03_Group_1_Voltage_error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO03_Group_2_Voltage_error                                      =  m_inputs_map[ska_num][STATUS0].at("DIO03_Group_2_Voltage_error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO03_Board_Temperature_error                                      =  m_inputs_map[ska_num][STATUS0].at("DIO03_Board_Temperature_error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit38                                      =  m_inputs_map[ska_num][STATUS0].at("bit38");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit39                                      =  m_inputs_map[ska_num][STATUS0].at("bit39");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO04_Module_Error                                      =  m_inputs_map[ska_num][STATUS0].at("DIO04_Module_Error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO04_Output_Overcurrent                                      =  m_inputs_map[ska_num][STATUS0].at("DIO04_Output_Overcurrent");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO04_Heartbeat_error                                      =  m_inputs_map[ska_num][STATUS0].at("DIO04_Heartbeat_error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO04_Group_1_Voltage_error                                      =  m_inputs_map[ska_num][STATUS0].at("DIO04_Group_1_Voltage_error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO04_Group_2_Voltage_error                                      =  m_inputs_map[ska_num][STATUS0].at("DIO04_Group_2_Voltage_error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.DIO04_Board_Temperature_error                                      =  m_inputs_map[ska_num][STATUS0].at("DIO04_Board_Temperature_error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit46                                      =  m_inputs_map[ska_num][STATUS0].at("bit46");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit47                                      =  m_inputs_map[ska_num][STATUS0].at("bit47");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.reserved_6                                     =  m_inputs_map[ska_num][STATUS0].at("reserved_6");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.reserved_7                                     =  m_inputs_map[ska_num][STATUS0].at("reserved_7");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.reserved_8                                     =  m_inputs_map[ska_num][STATUS0].at("reserved_8");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.AIM01_Module_Error                                     =  m_inputs_map[ska_num][STATUS0].at("AIM01_Module_Error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.AIM01_Heartbeat_error                                     =  m_inputs_map[ska_num][STATUS0].at("AIM01_Heartbeat_error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit74                                     =  m_inputs_map[ska_num][STATUS0].at("bit74");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit75                                     =  m_inputs_map[ska_num][STATUS0].at("bit75");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit76                                     =  m_inputs_map[ska_num][STATUS0].at("bit76");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit77                                     =  m_inputs_map[ska_num][STATUS0].at("bit77");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit78                                     =  m_inputs_map[ska_num][STATUS0].at("bit78");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.bit79                                     =  m_inputs_map[ska_num][STATUS0].at("bit79");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.PTI2037A_Module_Error                                      =  m_inputs_map[ska_num][STATUS0].at("PTI2037A_Module_Error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.PTI2037A_Heartbeat_error                                      =  m_inputs_map[ska_num][STATUS0].at("PTI2037A_Heartbeat_error");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.PTI2037A_Channel_1_Status                                     =  m_inputs_map[ska_num][STATUS0].at("PTI2037A_Channel_1_Status");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.PTI2037A_Channel_2_Status                                     =  m_inputs_map[ska_num][STATUS0].at("PTI2037A_Channel_2_Status");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.PTI2037A_Channel_3_Status                                     =  m_inputs_map[ska_num][STATUS0].at("PTI2037A_Channel_3_Status");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.PTI2037A_Channel_4_Status                                     =  m_inputs_map[ska_num][STATUS0].at("PTI2037A_Channel_4_Status");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.PTI2037A_Channel_5_Status                                     =  m_inputs_map[ska_num][STATUS0].at("PTI2037A_Channel_5_Status");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.PTI2037A_Channel_6_Status                                     =  m_inputs_map[ska_num][STATUS0].at("PTI2037A_Channel_6_Status");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.reserved_11                                     =  m_inputs_map[ska_num][STATUS0].at("reserved_11");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.reserved_12                                     =  m_inputs_map[ska_num][STATUS0].at("reserved_12");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.reserved_13                                     =  m_inputs_map[ska_num][STATUS0].at("reserved_13");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.reserved_14                                     =  m_inputs_map[ska_num][STATUS0].at("reserved_14");
    m_ska_x_dd_riom[ska_num].ska_dd_riom_ccu_mvb_status.bits.reserved_15                                     =  m_inputs_map[ska_num][STATUS0].at("reserved_15");


}



