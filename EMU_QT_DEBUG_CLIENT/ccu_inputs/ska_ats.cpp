#include "ska_ats.h"

Ska_Ats::Ska_Ats(QObject *parent)
    : QObject{parent}
{
    // reset values
    memset(&m_ska_x_ats, 0, sizeof(m_ska_x_ats));

    // Init SKA1 Table Contents
    init_ska_x_table(SKA_VEHICLE_NUM::SKA1);

    // Init SKA2 Table Contents
    init_ska_x_table(SKA_VEHICLE_NUM::SKA2);
    make_signal_slot_connection();
}


Ska_Ats::~Ska_Ats()
{
    for (auto& tableWidget : m_tableWidget) {
        delete tableWidget;
    }
}



void Ska_Ats::make_signal_slot_connection()
{
    // SKA1 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA1);
    });
    // SKA2 connection slot
    connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(SKA_VEHICLE_NUM::SKA2);
    });
}

void Ska_Ats::update_map(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);

m_inputs_map[ska_num].at("ATS_major_software_version_major")   =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.ATS_major_software_version_major ;
m_inputs_map[ska_num].at("ATS_minor_software_version")         =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.ATS_minor_software_version       ;
m_inputs_map[ska_num].at("ATS_bypass")                         =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.ATS_bypass                       ;
m_inputs_map[ska_num].at("ATS_mode_on")                        =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.ATS_mode_on                      ;
m_inputs_map[ska_num].at("ATS_brake_applied")                  =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.ATS_brake_applied                ;
m_inputs_map[ska_num].at("ATS_magnet_type")                    =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.ATS_magnet_type                  ;
m_inputs_map[ska_num].at("ATS_ERTMS_con")                      =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.ATS_ERTMS_con                    ;
m_inputs_map[ska_num].at("ATS_ERTMS_ack")                      =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.ATS_ERTMS_ack                    ;
m_inputs_map[ska_num].at("bit22")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit22                            ;
m_inputs_map[ska_num].at("Self_test_result_updated")           =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_result_updated         ;
/*m_inputs_map[ska_num].at("bit24")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit24                            ;
m_inputs_map[ska_num].at("bit25")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit25                            ;
m_inputs_map[ska_num].at("bit26")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit26                            ;
m_inputs_map[ska_num].at("bit27")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit27                            ;
m_inputs_map[ska_num].at("bit28")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit28                            ;
m_inputs_map[ska_num].at("bit29")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit29                            ;
m_inputs_map[ska_num].at("bit30")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit30                            ;
m_inputs_map[ska_num].at("bit31")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit31*/                           ;
m_inputs_map[ska_num].at("Self_test_magnet")                   =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_magnet                 ;
m_inputs_map[ska_num].at("Self_test_skb")                      =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_skb                    ;
m_inputs_map[ska_num].at("Self_test_pressure")                 =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_pressure               ;
m_inputs_map[ska_num].at("Self_test_brake")                    =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_brake                  ;
m_inputs_map[ska_num].at("Self_test_direction")                =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_direction              ;
m_inputs_map[ska_num].at("Self_test_sd_card")                  =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_sd_card                ;
m_inputs_map[ska_num].at("Self_test_rtc")                      =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_rtc                    ;
m_inputs_map[ska_num].at("Self_test_temperature")              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_temperature            ;
m_inputs_map[ska_num].at("Self_test_cabin")                    =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_cabin                  ;
m_inputs_map[ska_num].at("Self_test_speed")                    =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_speed                  ;
m_inputs_map[ska_num].at("Self_test_contact_v12")              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_contact_v12            ;
m_inputs_map[ska_num].at("Self_test_contact_v40")              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_contact_v40            ;
m_inputs_map[ska_num].at("Self_test_contact_v65")              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_contact_v65            ;
m_inputs_map[ska_num].at("Self_test_ethernet")                 =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_ethernet               ;
m_inputs_map[ska_num].at("Self_test_zdata")                    =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_zdata                  ;
m_inputs_map[ska_num].at("Self_test_bypass")                   =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_bypass                 ;
/*m_inputs_map[ska_num].at("bit48")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit48                            ;
m_inputs_map[ska_num].at("bit49")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit49                            ;
m_inputs_map[ska_num].at("bit50")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit50                            ;
m_inputs_map[ska_num].at("bit51")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit51                            ;
m_inputs_map[ska_num].at("bit52")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit52                            ;
m_inputs_map[ska_num].at("bit53")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit53                            ;
m_inputs_map[ska_num].at("bit54")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit54                            ;
m_inputs_map[ska_num].at("bit55")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit55*/                            ;
m_inputs_map[ska_num].at("Brake_application_reason")           =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Brake_application_reason         ;
m_inputs_map[ska_num].at("Fault_magnet_connection")            =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_magnet_connection          ;
m_inputs_map[ska_num].at("Fault_magnet_frequency")             =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_magnet_frequency           ;
m_inputs_map[ska_num].at("Fault_skb_communication")            =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_skb_communication          ;
m_inputs_map[ska_num].at("Fault_pressure_sensor")              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_pressure_sensor            ;
m_inputs_map[ska_num].at("Fault_brake_conflict")               =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_brake_conflict             ;
m_inputs_map[ska_num].at("Fault_direction_conflict")           =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_direction_conflict         ;
m_inputs_map[ska_num].at("Fault_sd_card_communication")        =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_sd_card_communication      ;
m_inputs_map[ska_num].at("Fault_sd_card_full")                 =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_sd_card_full               ;
m_inputs_map[ska_num].at("Fault_rtc_read_write")               =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_rtc_read_write             ;
m_inputs_map[ska_num].at("Fault_temp_sensor")                  =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_temp_sensor                ;
m_inputs_map[ska_num].at("Fault_cabin_data")                   =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_cabin_data                 ;
m_inputs_map[ska_num].at("Fault_speed_data")                   =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_speed_data                 ;
m_inputs_map[ska_num].at("Fault_v12_contact")                  =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_v12_contact                ;
m_inputs_map[ska_num].at("Fault_v40_contact")                  =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_v40_contact                ;
m_inputs_map[ska_num].at("Fault_v65_contact")                  =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_v65_contact                ;
m_inputs_map[ska_num].at("Fault_ethernet")                     =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_ethernet                   ;
/*m_inputs_map[ska_num].at("bit80")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit80                            ;
m_inputs_map[ska_num].at("bit81")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit81                            ;
m_inputs_map[ska_num].at("bit82")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit82                            ;
m_inputs_map[ska_num].at("bit83")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit83                            ;
m_inputs_map[ska_num].at("bit84")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit84                            ;
m_inputs_map[ska_num].at("bit85")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit85                            ;
m_inputs_map[ska_num].at("bit86")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit86                            ;
m_inputs_map[ska_num].at("bit87")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit87*/                            ;
m_inputs_map[ska_num].at("Status_zz")                          =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_zz                        ;
m_inputs_map[ska_num].at("Status_zw")                          =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_zw                        ;
m_inputs_map[ska_num].at("Status_zg")                          =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_zg                        ;
m_inputs_map[ska_num].at("Status_ze")                          =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_ze                        ;
m_inputs_map[ska_num].at("Status_zc")                          =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_zc                        ;
m_inputs_map[ska_num].at("Status_zb")                          =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_zb                        ;
m_inputs_map[ska_num].at("Status_tekrar_tanzim_bt_pressed")    =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_tekrar_tanzim_bt_pressed  ;
m_inputs_map[ska_num].at("Status_reset_bt_pressed")            =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_reset_bt_pressed          ;
m_inputs_map[ska_num].at("Status_uyari_onay_bt_pressed")       =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_uyari_onay_bt_pressed     ;
m_inputs_map[ska_num].at("Status_izinli_gecis_activated")      =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_izinli_gecis_activated    ;
m_inputs_map[ska_num].at("Status_hiz_serbest_activated")       =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_hiz_serbest_activated     ;
m_inputs_map[ska_num].at("bit100")                              =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit100                            ;
m_inputs_map[ska_num].at("bit101")                             =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit101                           ;
m_inputs_map[ska_num].at("bit102")                             =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit102                           ;
m_inputs_map[ska_num].at("bit103")                             =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit103                           ;
m_inputs_map[ska_num].at("ATS_CANopen_Fault")                  =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.ATS_CANopen_Fault                ;
m_inputs_map[ska_num].at("reserved_13")                        =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.reserved_13                      ;
m_inputs_map[ska_num].at("reserved_14")                        =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.reserved_14                      ;
m_inputs_map[ska_num].at("reserved_15")                        =m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.reserved_15                      ;

}

void Ska_Ats::update_table(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    // İndeksleri kullanarak tabloyu güncelle
    qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num]->columnCount() ;
    std::vector<int> valueColumns = {1, 3, 5, 7};
    for(const auto & map:m_inputs_map[ska_num]){


        utils::setTableWidgetValueByNameWithoutColumn(m_tableWidget[ska_num], map.first, map.second);
        //qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT INSIDE FOR LOOP ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;

        //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,3, map.second);
        //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,5, map.second);
        //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,7, map.second);
    }
}

void Ska_Ats::set_data_struct(const QByteArray &input, const SKA_VEHICLE_NUM &ska_x_num)
{
    //int oa_num = static_cast<int>(oa_x_num);
    qDebug() << "azdan az çoktan çok " ;
    qDebug() << "size of input " << input.size();
    qDebug() << "Gelen input verileri :  " << input;
    //qDebug() << "Gelen input veri tipi : " << typeof(input);


    int ska_num = static_cast<int>(ska_x_num);
    qDebug() << "bassana lan şunu sizeof(m_oa_x_jru[oa_num])  " << sizeof(m_ska_x_ats[ska_num]);

    if (input.size() == sizeof(m_ska_x_ats[ska_num])) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        //memcpy(&m_oa_x_etcs[oa_num], input.constData(), sizeof(m_oa_x_etcs[oa_num]));

        qDebug() << "SIZE of MVB1 :  " << sizeof(m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bytes);



        // İlk alanı kopyala
        memcpy(&m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bytes, input.constData(), sizeof(m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bytes));

        QByteArray data =  input.mid(0, 32);
        qDebug() << "32 Bytelık data :  " << data;
        update_map(ska_x_num);
        //set_struct_mvb1(oa_x_num);
        update_table(ska_x_num);

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

void Ska_Ats::init_ska_x_table(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_inputs_map[ska_num] = {
        {"ATS_major_software_version_major", 0},
        {"ATS_minor_software_version", 0},
        {"ATS_bypass", 0},
        {"ATS_mode_on", 0},
        {"ATS_brake_applied", 0},
        {"ATS_magnet_type", 0},
        {"ATS_ERTMS_con", 0},
        {"ATS_ERTMS_ack", 0},
        {"bit22", 0},
        {"Self_test_result_updated", 0},
        {"Self_test_magnet", 0},
        {"Self_test_skb", 0},
        {"Self_test_pressure", 0},
        {"Self_test_brake", 0},
        {"Self_test_direction", 0},
        {"Self_test_sd_card", 0},
        {"Self_test_rtc", 0},
        {"Self_test_temperature", 0},
        {"Self_test_cabin", 0},
        {"Self_test_speed", 0},
        {"Self_test_contact_v12", 0},
        {"Self_test_contact_v40", 0},
        {"Self_test_contact_v65", 0},
        {"Self_test_ethernet", 0},
        {"Self_test_zdata", 0},
        {"Self_test_bypass", 0},
        {"Brake_application_reason", 0},
        {"Fault_magnet_connection", 0},
        {"Fault_magnet_frequency", 0},
        {"Fault_skb_communication", 0},
        {"Fault_pressure_sensor", 0},
        {"Fault_brake_conflict", 0},
        {"Fault_direction_conflict", 0},
        {"Fault_sd_card_communication", 0},
        {"Fault_sd_card_full", 0},
        {"Fault_rtc_read_write", 0},
        {"Fault_temp_sensor", 0},
        {"Fault_cabin_data", 0},
        {"Fault_speed_data", 0},
        {"Fault_v12_contact", 0},
        {"Fault_v40_contact", 0},
        {"Fault_v65_contact", 0},
        {"Fault_ethernet", 0},
        {"Status_zz", 0},
        {"Status_zw", 0},
        {"Status_zg", 0},
        {"Status_ze", 0},
        {"Status_zc", 0},
        {"Status_zb", 0},
        {"Status_tekrar_tanzim_bt_pressed", 0},
        {"Status_reset_bt_pressed", 0},
        {"Status_uyari_onay_bt_pressed", 0},
        {"Status_izinli_gecis_activated", 0},
        {"Status_hiz_serbest_activated", 0},
        {"bit100", 0},
        {"bit101", 0},
        {"bit102", 0},
        {"bit103", 0},
        {"ATS_CANopen_Fault", 0},
        {"reserved_13", 0},
        {"reserved_14", 0},
        {"reserved_15", 0}
    };

    /*m_tableWidget.push_back(new QTableWidget());
    m_tableWidget[ska_num]->setColumnCount(2);
    m_tableWidget[ska_num]->setRowCount(m_inputs_map[ska_num].size());
    m_tableWidget[ska_num]->setHorizontalHeaderLabels(table_name[ska_num]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[ska_num]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[ska_num]->setItem(row, 0, item_name);
        m_tableWidget[ska_num]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[ska_num]->resizeColumnsToContents();*/

    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[ska_num].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    //m_tableWidget[ska_num] = new QTableWidget(rowCount, numColumns);
    m_tableWidget.push_back(new QTableWidget(rowCount, numColumns));
    m_tableWidget[ska_num]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[ska_num]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[ska_num]->setItem(row, column, item_name);
        m_tableWidget[ska_num]->setItem(row, column + 1, item_val); // Değer

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[ska_num]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num]->columnCount() ;
}

void Ska_Ats::update_struct_with_map(SKA_VEHICLE_NUM ska_x_num)
{

    int ska_num = static_cast<int>(ska_x_num);
    // Define a lambda function to reduce redundancy
    auto setInputMap = [&](const QString& signal_name) {
        m_inputs_map[ska_num][signal_name] = utils::getTableWidgetValueByNameWithoutColumn(m_tableWidget[ska_num], signal_name).toInt();
    };
    // update map with given tableWidget values
    for(const auto& map : m_inputs_map[ska_num])
    {
        setInputMap(map.first);
    }
    // set struct parameters with given updated map parameters
    set_struct(ska_x_num);
}


void Ska_Ats::set_struct(SKA_VEHICLE_NUM ska_x_num)
{
    int ska_num = static_cast<int>(ska_x_num);

    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.ATS_major_software_version_major = m_inputs_map[ska_num].at("ATS_major_software_version_major");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.ATS_minor_software_version       = m_inputs_map[ska_num].at("ATS_minor_software_version");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.ATS_bypass                       = m_inputs_map[ska_num].at("ATS_bypass");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.ATS_mode_on                      = m_inputs_map[ska_num].at("ATS_mode_on");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.ATS_brake_applied                = m_inputs_map[ska_num].at("ATS_brake_applied");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.ATS_magnet_type                  = m_inputs_map[ska_num].at("ATS_magnet_type");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.ATS_ERTMS_con                    = m_inputs_map[ska_num].at("ATS_ERTMS_con");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.ATS_ERTMS_ack                    = m_inputs_map[ska_num].at("ATS_ERTMS_ack");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit22                            = m_inputs_map[ska_num].at("bit22");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_result_updated         = m_inputs_map[ska_num].at("Self_test_result_updated");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_magnet                 = m_inputs_map[ska_num].at("Self_test_magnet");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_skb                    = m_inputs_map[ska_num].at("Self_test_skb");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_pressure               = m_inputs_map[ska_num].at("Self_test_pressure");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_brake                  = m_inputs_map[ska_num].at("Self_test_brake");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_direction              = m_inputs_map[ska_num].at("Self_test_direction");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_sd_card                = m_inputs_map[ska_num].at("Self_test_sd_card");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_rtc                    = m_inputs_map[ska_num].at("Self_test_rtc");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_temperature            = m_inputs_map[ska_num].at("Self_test_temperature");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_cabin                  = m_inputs_map[ska_num].at("Self_test_cabin");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_speed                  = m_inputs_map[ska_num].at("Self_test_speed");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_contact_v12            = m_inputs_map[ska_num].at("Self_test_contact_v12");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_contact_v40            = m_inputs_map[ska_num].at("Self_test_contact_v40");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_contact_v65            = m_inputs_map[ska_num].at("Self_test_contact_v65");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_ethernet               = m_inputs_map[ska_num].at("Self_test_ethernet");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_zdata                  = m_inputs_map[ska_num].at("Self_test_zdata");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Self_test_bypass                 = m_inputs_map[ska_num].at("Self_test_bypass");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Brake_application_reason         = m_inputs_map[ska_num].at("Brake_application_reason");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_magnet_connection          = m_inputs_map[ska_num].at("Fault_magnet_connection");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_magnet_frequency           = m_inputs_map[ska_num].at("Fault_magnet_frequency");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_skb_communication          = m_inputs_map[ska_num].at("Fault_skb_communication");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_pressure_sensor            = m_inputs_map[ska_num].at("Fault_pressure_sensor");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_brake_conflict             = m_inputs_map[ska_num].at("Fault_brake_conflict");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_direction_conflict         = m_inputs_map[ska_num].at("Fault_direction_conflict");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_sd_card_communication      = m_inputs_map[ska_num].at("Fault_sd_card_communication");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_sd_card_full               = m_inputs_map[ska_num].at("Fault_sd_card_full");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_rtc_read_write             = m_inputs_map[ska_num].at("Fault_rtc_read_write");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_temp_sensor                = m_inputs_map[ska_num].at("Fault_temp_sensor");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_cabin_data                 = m_inputs_map[ska_num].at("Fault_cabin_data");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_speed_data                 = m_inputs_map[ska_num].at("Fault_speed_data");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_v12_contact                = m_inputs_map[ska_num].at("Fault_v12_contact");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_v40_contact                = m_inputs_map[ska_num].at("Fault_v40_contact");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_v65_contact                = m_inputs_map[ska_num].at("Fault_v65_contact");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Fault_ethernet                   = m_inputs_map[ska_num].at("Fault_ethernet");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_zz                        = m_inputs_map[ska_num].at("Status_zz");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_zw                        = m_inputs_map[ska_num].at("Status_zw");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_zg                        = m_inputs_map[ska_num].at("Status_zg");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_ze                        = m_inputs_map[ska_num].at("Status_ze");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_zc                        = m_inputs_map[ska_num].at("Status_zc");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_zb                        = m_inputs_map[ska_num].at("Status_zb");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_tekrar_tanzim_bt_pressed  = m_inputs_map[ska_num].at("Status_tekrar_tanzim_bt_pressed");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_reset_bt_pressed          = m_inputs_map[ska_num].at("Status_reset_bt_pressed");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_uyari_onay_bt_pressed     = m_inputs_map[ska_num].at("Status_uyari_onay_bt_pressed");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_izinli_gecis_activated    = m_inputs_map[ska_num].at("Status_izinli_gecis_activated");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.Status_hiz_serbest_activated     = m_inputs_map[ska_num].at("Status_hiz_serbest_activated");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit100                            = m_inputs_map[ska_num].at("bit100");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit101                           = m_inputs_map[ska_num].at("bit101");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit102                           = m_inputs_map[ska_num].at("bit102");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.bit103                           = m_inputs_map[ska_num].at("bit103");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.ATS_CANopen_Fault                = m_inputs_map[ska_num].at("ATS_CANopen_Fault");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.reserved_13                      = m_inputs_map[ska_num].at("reserved_13");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.reserved_14                      = m_inputs_map[ska_num].at("reserved_14");
    m_ska_x_ats[ska_num].ska_vh_riom_ccu_mvb9_ats.bits.reserved_15                      = m_inputs_map[ska_num].at("reserved_15");



}

