#include "oa_dam.h"

#include "utils.h"

Oa_Dam::Oa_Dam(QObject *parent)
    : QObject{parent}
{
    // reset values
    memset(&m_oa_x_dam, 0, sizeof(m_oa_x_dam));
    // Init OA1 Table Contents
    init_oa_x_mvb1_table(OA_VEHICLE_NUM::OA1);
    // Init OA2 Table Contents
    init_oa_x_mvb1_table(OA_VEHICLE_NUM::OA2);

    make_signal_slot_connection();


}

Oa_Dam::~Oa_Dam()
{
    for (int i = 0; i < 2; ++i) {
        delete m_tableWidget[i];
        m_tableWidget[i]= nullptr;
    }
}


void Oa_Dam::make_signal_slot_connection()
{
    // OA1 MVB1 connection slot
    connect(m_tableWidget[get_index(OA_VEHICLE_NUM::OA1)], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(OA_VEHICLE_NUM::OA1, MVB1);
    });
    // OA1 MVB2 connection slot
    connect(m_tableWidget[get_index(OA_VEHICLE_NUM::OA2)], &QTableWidget::itemChanged,this, [&](){
        update_struct_with_map(OA_VEHICLE_NUM::OA2, MVB1);
    });
}

void Oa_Dam::update_mvb1_map(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);
    m_inputs_map[oa_num].at("id_ok")                            = m_oa_x_dam[oa_num].oa_dam.bits.id_ok;
    m_inputs_map[oa_num].at("id_nok")                           = m_oa_x_dam[oa_num].oa_dam.bits.id_nok;
    m_inputs_map[oa_num].at("checking_id")                      = m_oa_x_dam[oa_num].oa_dam.bits.checking_id;
    m_inputs_map[oa_num].at("reserved")                           = m_oa_x_dam[oa_num].oa_dam.bits.reserved;


}
void Oa_Dam::update_struct_with_map(OA_VEHICLE_NUM oa_x_num, OA_MVB_NUM mvb_num)
{
    (void)mvb_num; // unused_variable
    int oa_num = static_cast<int>(oa_x_num);
    // Define a lambda function to reduce redundancy
    auto setInputMap = [&](const QString& signal_name) {
        m_inputs_map[oa_num][signal_name] = utils::getTableWidgetValueByName(m_tableWidget[oa_num], signal_name, 1).toInt();
    };
    // update map with given tableWidget values
    for(const auto& map : m_inputs_map[oa_num])
    {
        setInputMap(map.first);
    }
    // set struct parameters with given updated map parameters
    set_struct_mvb1(oa_x_num);
}

void Oa_Dam::update_table(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);
    qDebug() << "OA_DAM" <<oa_num<< " table updated";
    qDebug() << "OA_DAM_SIZE" <<oa_num<< sizeof(oa_dam);

    for(const auto & map:m_inputs_map[oa_num]){
        //qDebug() <<  map.first << map.second;
        utils::setTableWidgetValueByName(m_tableWidget[oa_num], map.first, 1, map.second );
    }
}

void Oa_Dam::set_struct_mvb1(OA_VEHICLE_NUM oa_x_num)
{
    int oa_num = static_cast<int>(oa_x_num);

    m_oa_x_dam[oa_num].oa_dam.bits.id_ok             = m_inputs_map[oa_num].at("id_ok");
    m_oa_x_dam[oa_num].oa_dam.bits.id_nok            = m_inputs_map[oa_num].at("id_nok");
    m_oa_x_dam[oa_num].oa_dam.bits.checking_id       = m_inputs_map[oa_num].at("checking_id");
    m_oa_x_dam[oa_num].oa_dam.bits.reserved          = m_inputs_map[oa_num].at("reserved");



}

void Oa_Dam::init_oa_x_mvb1_table(OA_VEHICLE_NUM vehicle_type)
{
    int oa_num = static_cast<int>(vehicle_type);
    m_inputs_map[oa_num] = {
        {"id_ok", 0},
        {"id_nok", 0},
        {"checking_id", 0},
        {"reserved", 0}
    };

    m_tableWidget[oa_num] = new QTableWidget();
    m_tableWidget[oa_num]->setColumnCount(2);
    m_tableWidget[oa_num]->setRowCount(m_inputs_map[oa_num].size());
    m_tableWidget[oa_num]->setHorizontalHeaderLabels(table_name[oa_num]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[oa_num]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[oa_num]->setItem(row, 0, item_name);
        m_tableWidget[oa_num]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[oa_num]->resizeColumnsToContents();
}
