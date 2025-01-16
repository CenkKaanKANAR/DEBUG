#include "ccu_to_oax_etcs.h"
#include <QDebug>

Ccu_To_Oax_Etcs::Ccu_To_Oax_Etcs(QObject *parent)
    : QObject{parent}
{
    memset(m_ccu_to_oax_etcs.data(), 0, sizeof(m_ccu_to_oax_etcs));
    init_oa1_table();
    init_oa2_table();
}

Ccu_To_Oax_Etcs::~Ccu_To_Oax_Etcs()
{
    for (auto tableWidget : m_tableWidget) {
        delete tableWidget;
    }
}

void Ccu_To_Oax_Etcs::set_data_struct(const QByteArray &output, const OA_VEHICLE_NUM &oa_x_num)
{
    int ska_num = static_cast<int>(oa_x_num);
    if (output.size() == sizeof(m_ccu_to_oax_etcs[ska_num].bytes)) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        memcpy(m_ccu_to_oax_etcs[ska_num].bytes, output.constData(), sizeof(m_ccu_to_oax_etcs[ska_num].bytes));
        update_map(oa_x_num);
        update_table(oa_x_num);
    }
    else
    {
        qDebug() << "Error: Output size mismatch";
    }
}

void Ccu_To_Oax_Etcs::update_struct_with_map(OA_VEHICLE_NUM oa_x_num)
{
    qDebug() << "OA ETCS UPDATE_STRUCT_WITH_MAP";
    //(void)mvb_num; // unused_variable
    int oa_num = static_cast<int>(oa_x_num);
    // Define a lambda function to reduce redundancy
    auto setInputMap = [&](const QString& signal_name) {
        m_outputs_map[oa_num][signal_name] = utils::getTableWidgetValueByNameWithoutColumn(m_tableWidget[oa_num], signal_name).toInt();
    };
    // update map with given tableWidget values
    for(const auto& map : m_outputs_map[oa_num])
    {
        setInputMap(map.first);
    }
    // set struct parameters with given updated map parameters
    set_struct(oa_x_num);
}

void Ccu_To_Oax_Etcs::init_oa1_table()
{
    m_outputs_map[get_index(OA_VEHICLE_NUM::OA1)] = {
         {"Lifesign", 0},
         {"bit16", 0},
         {"bit18", 0},
         {"bit19", 0},
         {"bit20", 0},
         {"bit21", 0},
         {"bit22", 0},
         {"bit23", 0},

         {"TR_OBU_TrainSleep", 0},
         {"TR_OBU_TrainSleep_Not", 0},
         {"bit26", 0},
         {"TR_OBU_NLEnabled", 0},
         {"TR_OBU_DirectionFW", 0},
         {"TR_OBU_DirectionBW", 0},
         {"TR_OBU_CabStatusA", 0},
         {"TR_OBU_CabStatusB", 0},
         {"bit32", 0},
         {"bit33", 0},
         {"TR_OBU_Train_Integrity", 0},
         {"bit35",0},
         {"TR_OBU_Traction_Status", 0},
         {"TR_OBU_AirTightFitted", 0},
         {"bit38", 0},
         {"bit39", 0},
         {"reserved_5", 0},
         {"reserved_6", 0},
         {"Brake_status_EP_S", 0},
         {"Brake_status_EP_S_Not", 0},
         {"bit58", 0},
         {"bit59", 0},
         {"Brake_status_RB_S", 0},
         {"Brake_status_RB_S_Not", 0},
         {"bit62", 0},
         {"bit63", 0},
         {"reserved_8", 0},
         {"reserved_9_10", 0},
         {"TR_OBU_Train_Control", 0},
         {"bit92", 0},
         {"bit93", 0},
         {"bit94", 0},
         {"bit95", 0},
         {"reserved_12", 0},
         {"reserved_13", 0},
         {"reserved_14", 0},
         {"reserved_15", 0},
         {"reserved_16", 0},
         {"reserved_17", 0},
         {"reserved_18", 0},
         {"reserved_19", 0},
         {"reserved_20", 0},
         {"reserved_21", 0},
         {"reserved_22", 0},
         {"reserved_23", 0},
         {"reserved_24", 0},
         {"reserved_25", 0},
         {"reserved_26", 0},
         {"reserved_27", 0},
         {"reserved_28", 0},
         {"reserved_29", 0},
         {"reserved_30", 0},
         {"reserved_31", 0},
        };
    QStringList table_name = {"ccu_to_oa1_etcs", "value"};

    m_tableWidget.push_back(new QTableWidget());
    m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)] ->setColumnCount(2);
    m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)] ->setRowCount(m_outputs_map[get_index(OA_VEHICLE_NUM::OA1)].size());
    m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)]->setHorizontalHeaderLabels(table_name);
    m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)]->setObjectName("oa_1_ccu_to_all_etcs");


    int row = 0;
    for (const auto& pair:  m_outputs_map[get_index(OA_VEHICLE_NUM::OA1)]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)]->setItem(row, 0, item_name);
        m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }

    m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)]->resizeColumnsToContents();
}

void Ccu_To_Oax_Etcs::init_oa2_table()
{
    // Copy Assignment Operator
    m_outputs_map[get_index(OA_VEHICLE_NUM::OA2)] =  m_outputs_map[get_index(OA_VEHICLE_NUM::OA1)];
    QStringList table_name = {"ccu_to_oa2_etcs", "value"};

    m_tableWidget.push_back(new QTableWidget());
    m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)] ->setColumnCount(2);
    m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)] ->setRowCount(m_outputs_map[get_index(OA_VEHICLE_NUM::OA2)].size());
    m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)]->setHorizontalHeaderLabels(table_name);
    m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)]->setObjectName("oa_2_ccu_to_all_etcs");

    int row = 0;
    for (const auto& pair:  m_outputs_map[get_index(OA_VEHICLE_NUM::OA2)]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)]->setItem(row, 0, item_name);
        m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)]->resizeColumnsToContents();
}

void Ccu_To_Oax_Etcs::update_table(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);

    // Tabloyu temizleyin

    m_tableWidget[oa_num]->setRowCount(0);
    //tableWidget->clear();

    // Haritadaki verilerle tabloyu doldurun
    int row = 0;
    for (auto it = m_outputs_map[oa_num].begin(); it != m_outputs_map[oa_num].end(); ++it)
    {
        m_tableWidget[oa_num]->insertRow(row);
        //qDebug() <<"first:" << it->first << "second:" << it->second;
        QTableWidgetItem *keyItem   = new QTableWidgetItem(it->first); // Anahtar
        QTableWidgetItem *valueItem = new QTableWidgetItem(QString::number(it->second)); // Değer

        m_tableWidget[oa_num]->setItem(row, 0, keyItem);
        m_tableWidget[oa_num]->setItem(row, 1, valueItem);

        row++;
    }
}

void Ccu_To_Oax_Etcs::update_map(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);

    m_outputs_map[oa_num].at("Lifesign")                = m_ccu_to_oax_etcs.at(oa_num).bits.Lifesign;
    m_outputs_map[oa_num].at("bit16")                    = m_ccu_to_oax_etcs.at(oa_num).bits.bit16;
    m_outputs_map[oa_num].at("bit18")                    = m_ccu_to_oax_etcs.at(oa_num).bits.bit18;
    m_outputs_map[oa_num].at("bit19")                    = m_ccu_to_oax_etcs.at(oa_num).bits.bit19;
    m_outputs_map[oa_num].at("bit20")                    = m_ccu_to_oax_etcs.at(oa_num).bits.bit20;
    m_outputs_map[oa_num].at("bit21")                    = m_ccu_to_oax_etcs.at(oa_num).bits.bit21;
    m_outputs_map[oa_num].at("bit22")                    = m_ccu_to_oax_etcs.at(oa_num).bits.bit22;
    m_outputs_map[oa_num].at("bit23")                    = m_ccu_to_oax_etcs.at(oa_num).bits.bit23;

    m_outputs_map[oa_num].at("TR_OBU_TrainSleep")       = m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_TrainSleep;
    m_outputs_map[oa_num].at("TR_OBU_TrainSleep_Not")   = m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_TrainSleep_Not;
    m_outputs_map[oa_num].at("bit26")                   = m_ccu_to_oax_etcs.at(oa_num).bits.bit26;
    m_outputs_map[oa_num].at("TR_OBU_NLEnabled")        = m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_NLEnabled;
    m_outputs_map[oa_num].at("TR_OBU_DirectionFW")      = m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_DirectionFW;
    m_outputs_map[oa_num].at("TR_OBU_DirectionBW")      = m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_DirectionBW;
    m_outputs_map[oa_num].at("TR_OBU_CabStatusA")       = m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_CabStatusA;
    m_outputs_map[oa_num].at("TR_OBU_CabStatusB")       = m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_CabStatusB;
    m_outputs_map[oa_num].at("bit32")                   = m_ccu_to_oax_etcs.at(oa_num).bits.bit32;
    m_outputs_map[oa_num].at("bit33")                   = m_ccu_to_oax_etcs.at(oa_num).bits.bit33;
    m_outputs_map[oa_num].at("TR_OBU_Train_Integrity")  = m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_Train_Integrity;
    m_outputs_map[oa_num].at("bit35")                   = m_ccu_to_oax_etcs.at(oa_num).bits.bit35;
    m_outputs_map[oa_num].at("TR_OBU_Traction_Status")  = m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_Traction_Status;
    m_outputs_map[oa_num].at("TR_OBU_AirTightFitted")   = m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_AirTightFitted;
    m_outputs_map[oa_num].at("bit38")                   = m_ccu_to_oax_etcs.at(oa_num).bits.bit38;
    m_outputs_map[oa_num].at("bit39")                   = m_ccu_to_oax_etcs.at(oa_num).bits.bit39;
    m_outputs_map[oa_num].at("reserved_5")              = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_5;
    m_outputs_map[oa_num].at("reserved_6")              = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_6;
    m_outputs_map[oa_num].at("Brake_status_EP_S")       = m_ccu_to_oax_etcs.at(oa_num).bits.Brake_status_EP_S;
    m_outputs_map[oa_num].at("Brake_status_EP_S_Not")   = m_ccu_to_oax_etcs.at(oa_num).bits.Brake_status_EP_S_Not;
    m_outputs_map[oa_num].at("bit58")                   = m_ccu_to_oax_etcs.at(oa_num).bits.bit58;
    m_outputs_map[oa_num].at("bit59")                   = m_ccu_to_oax_etcs.at(oa_num).bits.bit59;
    m_outputs_map[oa_num].at("Brake_status_RB_S")       = m_ccu_to_oax_etcs.at(oa_num).bits.Brake_status_RB_S;
    m_outputs_map[oa_num].at("Brake_status_RB_S_Not")   = m_ccu_to_oax_etcs.at(oa_num).bits.Brake_status_RB_S_Not;
    m_outputs_map[oa_num].at("bit62")                   = m_ccu_to_oax_etcs.at(oa_num).bits.bit62;
    m_outputs_map[oa_num].at("bit63")                   = m_ccu_to_oax_etcs.at(oa_num).bits.bit63;
    m_outputs_map[oa_num].at("reserved_8")              = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_8;
    m_outputs_map[oa_num].at("reserved_9_10")           = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_9_10;
    m_outputs_map[oa_num].at("TR_OBU_Train_Control")  = m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_Train_Control;
    m_outputs_map[oa_num].at("bit92")                   = m_ccu_to_oax_etcs.at(oa_num).bits.bit92;
    m_outputs_map[oa_num].at("bit93")                   = m_ccu_to_oax_etcs.at(oa_num).bits.bit93;
    m_outputs_map[oa_num].at("bit94")                   = m_ccu_to_oax_etcs.at(oa_num).bits.bit94;
    m_outputs_map[oa_num].at("bit95")                   = m_ccu_to_oax_etcs.at(oa_num).bits.bit95;
    m_outputs_map[oa_num].at("reserved_12")             = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_12;
    m_outputs_map[oa_num].at("reserved_13")             = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_13;
    m_outputs_map[oa_num].at("reserved_14")             = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_14;
    m_outputs_map[oa_num].at("reserved_15")             = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_15;
    m_outputs_map[oa_num].at("reserved_16")             = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_16;
    m_outputs_map[oa_num].at("reserved_17")             = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_17;
    m_outputs_map[oa_num].at("reserved_18")             = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_18;
    m_outputs_map[oa_num].at("reserved_19")             = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_19;
    m_outputs_map[oa_num].at("reserved_20")             = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_20;
    m_outputs_map[oa_num].at("reserved_21")             = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_21;
    m_outputs_map[oa_num].at("reserved_22")             = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_22;
    m_outputs_map[oa_num].at("reserved_23")             = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_23;
    m_outputs_map[oa_num].at("reserved_24")             = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_24;
    m_outputs_map[oa_num].at("reserved_25")             = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_25;
    m_outputs_map[oa_num].at("reserved_26")             = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_26;
    m_outputs_map[oa_num].at("reserved_27")             = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_27;
    m_outputs_map[oa_num].at("reserved_28")             = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_28;
    m_outputs_map[oa_num].at("reserved_29")             = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_29;
    m_outputs_map[oa_num].at("reserved_30")             = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_30;
    m_outputs_map[oa_num].at("reserved_31")             = m_ccu_to_oax_etcs.at(oa_num).bits.reserved_31;
}

void Ccu_To_Oax_Etcs::set_struct(OA_VEHICLE_NUM oa_x_num)
{
        int oa_num = static_cast<int>(oa_x_num);
        m_ccu_to_oax_etcs.at(oa_num).bits.Lifesign         =         m_outputs_map[oa_num].at("Lifesign")              ;
        m_ccu_to_oax_etcs.at(oa_num).bits.bit16         =         m_outputs_map[oa_num].at("bit16")                  ;
        m_ccu_to_oax_etcs.at(oa_num).bits.bit18         =         m_outputs_map[oa_num].at("bit18")                  ;
        m_ccu_to_oax_etcs.at(oa_num).bits.bit19         =         m_outputs_map[oa_num].at("bit19")                  ;
        m_ccu_to_oax_etcs.at(oa_num).bits.bit20         =         m_outputs_map[oa_num].at("bit20")                  ;
        m_ccu_to_oax_etcs.at(oa_num).bits.bit21         =         m_outputs_map[oa_num].at("bit21")                  ;
        m_ccu_to_oax_etcs.at(oa_num).bits.bit22         =         m_outputs_map[oa_num].at("bit22")                  ;
        m_ccu_to_oax_etcs.at(oa_num).bits.bit23         =         m_outputs_map[oa_num].at("bit23")                  ;

        m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_TrainSleep            =         m_outputs_map[oa_num].at("TR_OBU_TrainSleep")     ;
        m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_TrainSleep_Not            =         m_outputs_map[oa_num].at("TR_OBU_TrainSleep_Not") ;
        m_ccu_to_oax_etcs.at(oa_num).bits.bit26            =         m_outputs_map[oa_num].at("bit26")                 ;
        m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_NLEnabled         =         m_outputs_map[oa_num].at("TR_OBU_NLEnabled")      ;
        m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_DirectionFW           =         m_outputs_map[oa_num].at("TR_OBU_DirectionFW")    ;
        m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_DirectionBW           =         m_outputs_map[oa_num].at("TR_OBU_DirectionBW")    ;
        m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_CabStatusA            =         m_outputs_map[oa_num].at("TR_OBU_CabStatusA")     ;
        m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_CabStatusB            =         m_outputs_map[oa_num].at("TR_OBU_CabStatusB")     ;
        m_ccu_to_oax_etcs.at(oa_num).bits.bit32            =         m_outputs_map[oa_num].at("bit32")                 ;
        m_ccu_to_oax_etcs.at(oa_num).bits.bit33            =         m_outputs_map[oa_num].at("bit33")                 ;
        m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_Train_Integrity           =         m_outputs_map[oa_num].at("TR_OBU_Train_Integrity");
        m_ccu_to_oax_etcs.at(oa_num).bits.bit35            =         m_outputs_map[oa_num].at("bit35")                 ;
        m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_Traction_Status           =         m_outputs_map[oa_num].at("TR_OBU_Traction_Status");
        m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_AirTightFitted            =         m_outputs_map[oa_num].at("TR_OBU_AirTightFitted") ;
        m_ccu_to_oax_etcs.at(oa_num).bits.bit38            =         m_outputs_map[oa_num].at("bit38")                 ;
        m_ccu_to_oax_etcs.at(oa_num).bits.bit39            =         m_outputs_map[oa_num].at("bit39")                 ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_5           =         m_outputs_map[oa_num].at("reserved_5")            ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_6           =         m_outputs_map[oa_num].at("reserved_6")            ;
        m_ccu_to_oax_etcs.at(oa_num).bits.Brake_status_EP_S            =         m_outputs_map[oa_num].at("Brake_status_EP_S")     ;
        m_ccu_to_oax_etcs.at(oa_num).bits.Brake_status_EP_S_Not            =         m_outputs_map[oa_num].at("Brake_status_EP_S_Not") ;
        m_ccu_to_oax_etcs.at(oa_num).bits.bit58            =         m_outputs_map[oa_num].at("bit58")                 ;
        m_ccu_to_oax_etcs.at(oa_num).bits.bit59            =         m_outputs_map[oa_num].at("bit59")                 ;
        m_ccu_to_oax_etcs.at(oa_num).bits.Brake_status_RB_S            =         m_outputs_map[oa_num].at("Brake_status_RB_S")     ;
        m_ccu_to_oax_etcs.at(oa_num).bits.Brake_status_RB_S_Not            =         m_outputs_map[oa_num].at("Brake_status_RB_S_Not") ;
        m_ccu_to_oax_etcs.at(oa_num).bits.bit62            =         m_outputs_map[oa_num].at("bit62")                 ;
        m_ccu_to_oax_etcs.at(oa_num).bits.bit63            =         m_outputs_map[oa_num].at("bit63")                 ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_8           =         m_outputs_map[oa_num].at("reserved_8")            ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_9_10            =         m_outputs_map[oa_num].at("reserved_9_10")         ;
        m_ccu_to_oax_etcs.at(oa_num).bits.TR_OBU_Train_Control           =         m_outputs_map[oa_num].at("TR_OBU_Train_Control");
        m_ccu_to_oax_etcs.at(oa_num).bits.bit92            =         m_outputs_map[oa_num].at("bit92")                 ;
        m_ccu_to_oax_etcs.at(oa_num).bits.bit93            =         m_outputs_map[oa_num].at("bit93")                 ;
        m_ccu_to_oax_etcs.at(oa_num).bits.bit94            =         m_outputs_map[oa_num].at("bit94")                 ;
        m_ccu_to_oax_etcs.at(oa_num).bits.bit95            =         m_outputs_map[oa_num].at("bit95")                 ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_12          =         m_outputs_map[oa_num].at("reserved_12")           ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_13          =         m_outputs_map[oa_num].at("reserved_13")           ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_14          =         m_outputs_map[oa_num].at("reserved_14")           ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_15          =         m_outputs_map[oa_num].at("reserved_15")           ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_16          =         m_outputs_map[oa_num].at("reserved_16")           ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_17          =         m_outputs_map[oa_num].at("reserved_17")           ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_18          =         m_outputs_map[oa_num].at("reserved_18")           ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_19          =         m_outputs_map[oa_num].at("reserved_19")           ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_20          =         m_outputs_map[oa_num].at("reserved_20")           ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_21          =         m_outputs_map[oa_num].at("reserved_21")           ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_22          =         m_outputs_map[oa_num].at("reserved_22")           ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_23          =         m_outputs_map[oa_num].at("reserved_23")           ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_24          =         m_outputs_map[oa_num].at("reserved_24")           ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_25          =         m_outputs_map[oa_num].at("reserved_25")           ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_26          =         m_outputs_map[oa_num].at("reserved_26")           ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_27          =         m_outputs_map[oa_num].at("reserved_27")           ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_28          =         m_outputs_map[oa_num].at("reserved_28")           ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_29          =         m_outputs_map[oa_num].at("reserved_29")           ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_30          =         m_outputs_map[oa_num].at("reserved_30")           ;
        m_ccu_to_oax_etcs.at(oa_num).bits.reserved_31          =         m_outputs_map[oa_num].at("reserved_31")           ;
}
