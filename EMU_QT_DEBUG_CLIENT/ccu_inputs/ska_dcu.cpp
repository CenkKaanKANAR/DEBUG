#include "ska_dcu.h"
#include "utils.h"

SKA_DCU::SKA_DCU(QObject *parent)
    : QObject{parent}
{

    memset(&m_ska_x_dcu, 0, sizeof(m_ska_x_dcu));
    init_ska_x_mvb2_dcu1_table(SKA_VEHICLE_NUM::SKA1);
    init_ska_x_mvb3_dcu2_table(SKA_VEHICLE_NUM::SKA1);
    init_ska_x_mvb4_dcu3_table(SKA_VEHICLE_NUM::SKA1);
    init_ska_x_mvb5_dcu4_table(SKA_VEHICLE_NUM::SKA1);

    init_ska_x_mvb2_dcu1_table(SKA_VEHICLE_NUM::SKA2);
    init_ska_x_mvb3_dcu2_table(SKA_VEHICLE_NUM::SKA2);
    init_ska_x_mvb4_dcu3_table(SKA_VEHICLE_NUM::SKA2);
    init_ska_x_mvb5_dcu4_table(SKA_VEHICLE_NUM::SKA2);


    make_signal_slot_connection();

}

SKA_DCU::~SKA_DCU()
{

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            delete m_tableWidget[i][j];
            m_tableWidget[i][j] = nullptr; // Güvenlik için nullptr atayın
        }
    }
}

void SKA_DCU::make_signal_slot_connection()
{


     // SKA1 DCU1 connection slot
     connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][DCU1], &QTableWidget::itemChanged,this, [&](){
         update_struct_with_map(SKA_VEHICLE_NUM::SKA1, DCU1);
     });

     //SKA1 DCU2 connection slot
     connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][DCU2], &QTableWidget::itemChanged,this, [&](){
         update_struct_with_map(SKA_VEHICLE_NUM::SKA1, DCU2);
     });

     // SKA1 DCU3 connection slot
     connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][DCU3], &QTableWidget::itemChanged,this, [&](){
         update_struct_with_map(SKA_VEHICLE_NUM::SKA1, DCU3);
     });

     // SKA1 DCU4 connection slot
     connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA1)][DCU4], &QTableWidget::itemChanged,this, [&](){
         update_struct_with_map(SKA_VEHICLE_NUM::SKA1, DCU4);
     });
     //////////////////////////////////// SKA2 //////////////////////////////////////////////
     // SKA2 DCU1 connection slot
     connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][DCU1], &QTableWidget::itemChanged,this, [&](){
         update_struct_with_map(SKA_VEHICLE_NUM::SKA2, DCU1);
     });

     // SKA2 DCU2 connection slot
     connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][DCU2], &QTableWidget::itemChanged,this, [&](){
         update_struct_with_map(SKA_VEHICLE_NUM::SKA2, DCU2);
     });

     // SKA2 DCU3 connection slot
     connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][DCU3], &QTableWidget::itemChanged,this, [&](){
         update_struct_with_map(SKA_VEHICLE_NUM::SKA2, DCU3);
     });

     // SKA2 DCU4 connection slot
     connect(m_tableWidget[get_index(SKA_VEHICLE_NUM::SKA2)][DCU4], &QTableWidget::itemChanged,this, [&](){
         update_struct_with_map(SKA_VEHICLE_NUM::SKA2, DCU4);
     });

}

void SKA_DCU::update_table(SKA_VEHICLE_NUM ska_x_num, DCU_LIST dcu_num)
{
    int ska_num = static_cast<int>(ska_x_num);
    // İndeksleri kullanarak tabloyu güncelle
    qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][DCU1]->columnCount() ;
    std::vector<int> valueColumns = {1, 3, 5, 7};
    for(const auto & map:m_inputs_map[ska_num][dcu_num]){


            utils::setTableWidgetValueByNameWithoutColumn(m_tableWidget[ska_num][dcu_num], map.first, map.second);
            //qDebug() << "UPDATE STRUCT WITH MAP SIZE of COLUMN COUNT INSIDE FOR LOOP ========== :  " << m_tableWidget[oa_num][MVB1]->columnCount() ;

            //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,3, map.second);
            //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,5, map.second);
            //utils::setTableWidgetValueByName(m_tableWidget[oa_num][mvb_num], map.first,7, map.second);
    }
}

void SKA_DCU::set_data_struct(const QByteArray &input, const SKA_VEHICLE_NUM &ska_x_num)
{
    //int oa_num = static_cast<int>(oa_x_num);
    qDebug() << "azdan az çoktan çok " ;
    qDebug() << "size of input " << input.size();
    qDebug() << "Gelen input verileri :  " << input;
    //qDebug() << "Gelen input veri tipi : " << typeof(input);


    int ska_num = static_cast<int>(ska_x_num);

    qDebug() << "SET DATA STRUCT SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][DCU1]->columnCount() ;
    if (input.size() == sizeof(m_ska_x_dcu[ska_num])) {
        //std::copy(output.begin(), output.begin() + sizeof(m_ska_ccu_vh_riom_mvb1_d_outputs.bytes), m_ska_ccu_vh_riom_mvb1_d_outputs.bytes);
        //memcpy(&m_oa_x_etcs[oa_num], input.constData(), sizeof(m_oa_x_etcs[oa_num]));

        qDebug() << "SIZE of MVB1 :  " << sizeof(m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bytes);
        qDebug() << "SIZE of MVB2 :  " << sizeof(m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bytes);
        //qDebug() << "SIZE of MVB3 :  " << sizeof(m_ska_x_bcu[ska_num].oa_etcs_ccu_mvb3.bytes);


        // İlk alanı kopyala
        memcpy(&m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bytes, input.constData(), sizeof(m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bytes));

        QByteArray data =  input.mid(0, 32);
        qDebug() << "32 Bytelık data :  " << data;
        update_dcu1_map(ska_x_num,DCU1);
        //set_struct_mvb1(oa_x_num);
        update_table(ska_x_num,SKA_DCU::DCU1);

        // İkinci alanı kopyala, input.constData() + sizeof(etcs_ccu_mvb1) kadar ilerleyerek
        memcpy(&m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bytes, input.constData() + sizeof(m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bytes), sizeof(m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bytes));
        update_dcu2_map(ska_x_num,DCU2);
        //set_struct_mvb2(oa_x_num);
        update_table(ska_x_num,SKA_DCU::DCU2);


        // Üçüncü alanı kopyala
        memcpy(&m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bytes, input.constData() + sizeof(m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bytes) + sizeof(m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bytes) , sizeof(m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bytes));
        update_dcu2_map(ska_x_num,DCU3);
        //set_struct_mvb2(oa_x_num);
        update_table(ska_x_num,SKA_DCU::DCU3);
        //update maps

        // Dördüncü alanı kopyala
        memcpy(&m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bytes, input.constData() + sizeof(m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bytes) + sizeof(m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bytes) + sizeof(m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bytes), sizeof(m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bytes));
        update_dcu2_map(ska_x_num,DCU4);
        //set_struct_mvb2(oa_x_num);
        update_table(ska_x_num,SKA_DCU::DCU4);
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


void SKA_DCU::update_dcu1_map(SKA_VEHICLE_NUM ska_x_num, DCU_LIST dcu)
{
    int ska_num = static_cast<int>(ska_x_num);
m_inputs_map[ska_num][dcu].at("R1_DCU_IFESmartAssistDCU")             =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_IFESmartAssistDCU;
m_inputs_map[ska_num][dcu].at("R1_DCU_SuppEmergOp")                   =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_SuppEmergOp;
m_inputs_map[ska_num][dcu].at("R1_DCU_DoorAntiDrag")                  =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DoorAntiDrag;
m_inputs_map[ska_num][dcu].at("R1_DCU_DoorObstDet")                   =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DoorObstDet;
m_inputs_map[ska_num][dcu].at("R1_DCU_DoorMoveMonit")                 =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DoorMoveMonit;
m_inputs_map[ska_num][dcu].at("R1_DCU_EntrRel")                       =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_EntrRel;
m_inputs_map[ska_num][dcu].at("R1_DCU_DoorClosed")                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DoorClosed;
m_inputs_map[ska_num][dcu].at("R1_DCU_DoorClosedAndLocked")           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DoorClosedAndLocked;
m_inputs_map[ska_num][dcu].at("R1_DCU_DoorFullyOpen")                 =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DoorFullyOpen;
m_inputs_map[ska_num][dcu].at("R1_DCU_DoorOutOfService")              =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DoorOutOfService;
m_inputs_map[ska_num][dcu].at("R1_DCU_DoorUnlEmergOp")                =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DoorUnlEmergOp;
m_inputs_map[ska_num][dcu].at("R1_DCU_EEDOp")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_EEDOp;
m_inputs_map[ska_num][dcu].at("R1_DCU_EADOp")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_EADOp;
m_inputs_map[ska_num][dcu].at("R1_DCU_PBOpenDLRightOutsideOp")        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_PBOpenDLRightOutsideOp;
m_inputs_map[ska_num][dcu].at("R1_DCU_PBOpenDLRightInsideOp")         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_PBOpenDLRightInsideOp;
m_inputs_map[ska_num][dcu].at("R1_DCU_PBPRMPortalInsideOp")           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_PBPRMPortalInsideOp;
m_inputs_map[ska_num][dcu].at("R1_DCU_LightBarrierPortalInsideInterr")=m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_LightBarrierPortalInsideInterr;
m_inputs_map[ska_num][dcu].at("R1_DCU_OutputTIL1")                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_OutputTIL1;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC001")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC001;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC002")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC002;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC003")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC003;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC004")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC004;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC005")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC005;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC006")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC006;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC007")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC007;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC008")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC008;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC009")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC009;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC010")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC010;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC013")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC013;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC014")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC014;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC015")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC015;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC016")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC016;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC017")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC017;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC018")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC018;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC019")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC019;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC020")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC020;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC021")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC021;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC022")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC022;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC027")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC027;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC028")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC028;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC029")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC029;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC030")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC030;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC031")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC031;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC033")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC033;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC037")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC037;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC042")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC042;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC043")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC043;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC044")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC044;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC046")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC046;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC048")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC048;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC049")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC049;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC050")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC050;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC051")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC051;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC052")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC052;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC053")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC053;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC065")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC065;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC066")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC066;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC067")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC067;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC068")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC068;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC069")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC069;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC090")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC090;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC091")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC091;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC098")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC098;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC099")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC099;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC101")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC101;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC102")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC102;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC103")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC103;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC105")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC105;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC106")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC106;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC111")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC111;
m_inputs_map[ska_num][dcu].at("R1_DCU_DC116")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC116;
m_inputs_map[ska_num][dcu].at("R1_DCU_DiagPrioA")                     =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DiagPrioA;
m_inputs_map[ska_num][dcu].at("R1_DCU_DiagPrioB")                     =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DiagPrioB;
//m_inputs_map[ska_num][dcu].at("R1_SKA1_DoorR1_CANopen_Fault")                 =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.DCU_SKA1_DoorR1_CANopen_Fault;
m_inputs_map[ska_num][dcu].at("bit73")                                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit73;
m_inputs_map[ska_num][dcu].at("bit74")                                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit74;
m_inputs_map[ska_num][dcu].at("bit75")                                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit75;
m_inputs_map[ska_num][dcu].at("bit76")                                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit76;
m_inputs_map[ska_num][dcu].at("bit77")                                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit77;
m_inputs_map[ska_num][dcu].at("bit78")                                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit78;
m_inputs_map[ska_num][dcu].at("bit79")                                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit79;
m_inputs_map[ska_num][dcu].at("R2_DCU_IFESmartAssistDCU")             =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_IFESmartAssistDCU;
m_inputs_map[ska_num][dcu].at("R2_DCU_SuppEmergOp")                   =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_SuppEmergOp;
m_inputs_map[ska_num][dcu].at("R2_DCU_DoorAntiDrag")                  =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DoorAntiDrag;
m_inputs_map[ska_num][dcu].at("R2_DCU_DoorObstDet")                   =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DoorObstDet;
m_inputs_map[ska_num][dcu].at("R2_DCU_DoorMoveMonit")                 =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DoorMoveMonit;
m_inputs_map[ska_num][dcu].at("R2_DCU_EntrRel")                       =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_EntrRel;
m_inputs_map[ska_num][dcu].at("R2_DCU_DoorClosed")                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DoorClosed;
m_inputs_map[ska_num][dcu].at("R2_DCU_DoorClosedAndLocked")           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DoorClosedAndLocked;
m_inputs_map[ska_num][dcu].at("R2_DCU_DoorFullyOpen")                 =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DoorFullyOpen;
m_inputs_map[ska_num][dcu].at("R2_DCU_DoorOutOfService")              =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DoorOutOfService;
m_inputs_map[ska_num][dcu].at("R2_DCU_DoorUnlEmergOp")                =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DoorUnlEmergOp;
m_inputs_map[ska_num][dcu].at("R2_DCU_EEDOp")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_EEDOp;
m_inputs_map[ska_num][dcu].at("R2_DCU_EADOp")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_EADOp;
m_inputs_map[ska_num][dcu].at("R2_DCU_PBOpenDLRightOutsideOp")        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_PBOpenDLRightOutsideOp;
m_inputs_map[ska_num][dcu].at("R2_DCU_PBOpenDLRightInsideOp")         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_PBOpenDLRightInsideOp;
m_inputs_map[ska_num][dcu].at("R2_DCU_PBPRMPortalInsideOp")           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_PBPRMPortalInsideOp;
m_inputs_map[ska_num][dcu].at("R2_DCU_LightBarrierPortalInsideInterr")=m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_LightBarrierPortalInsideInterr;
m_inputs_map[ska_num][dcu].at("R2_DCU_OutputTIL1")                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_OutputTIL1;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC001")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC001;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC002")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC002;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC003")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC003;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC004")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC004;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC005")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC005;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC006")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC006;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC007")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC007;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC008")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC008;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC009")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC009;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC010")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC010;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC013")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC013;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC014")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC014;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC015")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC015;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC016")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC016;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC017")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC017;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC018")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC018;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC019")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC019;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC020")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC020;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC021")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC021;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC022")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC022;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC027")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC027;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC028")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC028;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC029")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC029;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC030")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC030;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC031")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC031;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC033")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC033;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC037")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC037;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC042")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC042;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC043")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC043;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC044")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC044;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC046")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC046;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC048")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC048;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC049")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC049;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC050")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC050;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC051")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC051;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC052")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC052;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC053")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC053;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC065")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC065;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC066")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC066;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC067")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC067;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC068")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC068;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC069")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC069;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC090")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC090;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC091")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC091;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC098")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC098;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC099")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC099;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC101")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC101;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC102")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC102;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC103")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC103;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC105")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC105;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC106")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC106;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC111")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC111;
m_inputs_map[ska_num][dcu].at("R2_DCU_DC116")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC116;
m_inputs_map[ska_num][dcu].at("R2_DCU_DiagPrioA")                     =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DiagPrioA;
m_inputs_map[ska_num][dcu].at("R2_DCU_DiagPrioB")                     =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DiagPrioB;
//m_inputs_map[ska_num][dcu].at("R2_DCU_CANopen_Fault")                 =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.DCU_SKA1_DoorR2_CANopen_Fault;
m_inputs_map[ska_num][dcu].at("bit153")                                        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit154;
m_inputs_map[ska_num][dcu].at("bit154")                                        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit154;
m_inputs_map[ska_num][dcu].at("bit155")                                        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit155;
m_inputs_map[ska_num][dcu].at("bit156")                                        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit156;
m_inputs_map[ska_num][dcu].at("bit157")                                        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit157;
m_inputs_map[ska_num][dcu].at("bit158")                                        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit158;
m_inputs_map[ska_num][dcu].at("bit159")                                        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit159;
m_inputs_map[ska_num][dcu].at("R3_DCU_IFESmartAssistDCU")             =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_IFESmartAssistDCU;
m_inputs_map[ska_num][dcu].at("R3_DCU_SuppEmergOp")                   =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_SuppEmergOp;
m_inputs_map[ska_num][dcu].at("R3_DCU_DoorAntiDrag")                  =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DoorAntiDrag;
m_inputs_map[ska_num][dcu].at("R3_DCU_DoorObstDet")                   =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DoorObstDet;
m_inputs_map[ska_num][dcu].at("R3_DCU_DoorMoveMonit")                 =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DoorMoveMonit;
m_inputs_map[ska_num][dcu].at("R3_DCU_EntrRel")                       =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_EntrRel;
m_inputs_map[ska_num][dcu].at("R3_DCU_DoorClosed")                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DoorClosed;
m_inputs_map[ska_num][dcu].at("R3_DCU_DoorClosedAndLocked")           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DoorClosedAndLocked;
m_inputs_map[ska_num][dcu].at("R3_DCU_DoorFullyOpen")                 =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DoorFullyOpen;
m_inputs_map[ska_num][dcu].at("R3_DCU_DoorOutOfService")              =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DoorOutOfService;
m_inputs_map[ska_num][dcu].at("R3_DCU_DoorUnlEmergOp")                =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DoorUnlEmergOp;
m_inputs_map[ska_num][dcu].at("R3_DCU_EEDOp")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_EEDOp;
m_inputs_map[ska_num][dcu].at("R3_DCU_EADOp")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_EADOp;
m_inputs_map[ska_num][dcu].at("R3_DCU_PBOpenDLRightOutsideOp")        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_PBOpenDLRightOutsideOp;
m_inputs_map[ska_num][dcu].at("R3_DCU_PBOpenDLRightInsideOp")         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_PBOpenDLRightInsideOp;
m_inputs_map[ska_num][dcu].at("R3_DCU_PBPRMPortalInsideOp")           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_PBPRMPortalInsideOp;
m_inputs_map[ska_num][dcu].at("R3_DCU_LightBarrierPortalInsideInterr")=m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_LightBarrierPortalInsideInterr;
m_inputs_map[ska_num][dcu].at("R3_DCU_OutputTIL1")                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_OutputTIL1;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC001")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC001;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC002")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC002;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC003")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC003;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC004")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC004;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC005")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC005;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC006")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC006;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC007")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC007;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC008")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC008;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC009")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC009;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC010")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC010;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC013")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC013;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC014")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC014;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC015")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC015;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC016")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC016;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC017")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC017;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC018")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC018;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC019")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC019;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC020")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC020;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC021")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC021;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC022")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC022;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC027")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC027;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC028")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC028;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC029")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC029;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC030")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC030;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC031")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC031;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC033")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC033;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC037")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC037;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC042")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC042;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC043")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC043;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC044")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC044;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC046")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC046;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC048")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC048;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC049")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC049;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC050")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC050;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC051")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC051;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC052")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC052;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC053")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC053;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC065")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC065;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC066")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC066;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC067")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC067;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC068")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC068;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC069")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC069;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC090")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC090;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC091")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC091;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC098")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC098;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC099")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC099;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC101")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC101;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC102")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC102;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC103")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC103;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC105")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC105;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC106")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC106;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC111")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC111;
m_inputs_map[ska_num][dcu].at("R3_DCU_DC116")                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC116;
m_inputs_map[ska_num][dcu].at("R3_DCU_DiagPrioA")                     =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DiagPrioA;
m_inputs_map[ska_num][dcu].at("R3_DCU_DiagPrioB")                     =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DiagPrioB;
//m_inputs_map[ska_num][dcu].at("R3_DCU_CANopen_Fault")                 =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.DCU_SKA1_DoorR3_CANopen_Fault;
m_inputs_map[ska_num][dcu].at("bit233")                                        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit233;
m_inputs_map[ska_num][dcu].at("bit234")                                        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit234;
m_inputs_map[ska_num][dcu].at("bit235")                                        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit235;
m_inputs_map[ska_num][dcu].at("bit236")                                        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit236;
m_inputs_map[ska_num][dcu].at("bit237")                                        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit237;
m_inputs_map[ska_num][dcu].at("bit238")                                        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit238;
m_inputs_map[ska_num][dcu].at("bit239")                                        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit239;
m_inputs_map[ska_num][dcu].at("reserved_30")                                   =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.reserved_30;
m_inputs_map[ska_num][dcu].at("reserved_31")                                   =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.reserved_31;

}

void SKA_DCU::set_struct_dcu1(SKA_VEHICLE_NUM ska_x_num, DCU_LIST dcu)
{
int ska_num = static_cast<int>(ska_x_num);

m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_IFESmartAssistDCU               =m_inputs_map[ska_num][dcu].at("R1_DCU_IFESmartAssistDCU");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_SuppEmergOp                     =m_inputs_map[ska_num][dcu].at("R1_DCU_SuppEmergOp");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DoorAntiDrag                    =m_inputs_map[ska_num][dcu].at("R1_DCU_DoorAntiDrag")                  ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DoorObstDet                     =m_inputs_map[ska_num][dcu].at("R1_DCU_DoorObstDet")                   ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DoorMoveMonit                   =m_inputs_map[ska_num][dcu].at("R1_DCU_DoorMoveMonit")                 ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_EntrRel                         =m_inputs_map[ska_num][dcu].at("R1_DCU_EntrRel")                       ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DoorClosed                      =m_inputs_map[ska_num][dcu].at("R1_DCU_DoorClosed")                    ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DoorClosedAndLocked             =m_inputs_map[ska_num][dcu].at("R1_DCU_DoorClosedAndLocked")           ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DoorFullyOpen                   =m_inputs_map[ska_num][dcu].at("R1_DCU_DoorFullyOpen")                 ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DoorOutOfService                =m_inputs_map[ska_num][dcu].at("R1_DCU_DoorOutOfService")              ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DoorUnlEmergOp                  =m_inputs_map[ska_num][dcu].at("R1_DCU_DoorUnlEmergOp")                ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_EEDOp                           =m_inputs_map[ska_num][dcu].at("R1_DCU_EEDOp")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_EADOp                           =m_inputs_map[ska_num][dcu].at("R1_DCU_EADOp")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_PBOpenDLRightOutsideOp          =m_inputs_map[ska_num][dcu].at("R1_DCU_PBOpenDLRightOutsideOp")        ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_PBOpenDLRightInsideOp           =m_inputs_map[ska_num][dcu].at("R1_DCU_PBOpenDLRightInsideOp")         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_PBPRMPortalInsideOp             =m_inputs_map[ska_num][dcu].at("R1_DCU_PBPRMPortalInsideOp")           ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_LightBarrierPortalInsideInterr  =m_inputs_map[ska_num][dcu].at("R1_DCU_LightBarrierPortalInsideInterr");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_OutputTIL1                      =m_inputs_map[ska_num][dcu].at("R1_DCU_OutputTIL1")                    ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC001=m_inputs_map[ska_num][dcu].at("R1_DCU_DC001")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC002=m_inputs_map[ska_num][dcu].at("R1_DCU_DC002")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC003=m_inputs_map[ska_num][dcu].at("R1_DCU_DC003")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC004=m_inputs_map[ska_num][dcu].at("R1_DCU_DC004")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC005=m_inputs_map[ska_num][dcu].at("R1_DCU_DC005")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC006=m_inputs_map[ska_num][dcu].at("R1_DCU_DC006")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC007=m_inputs_map[ska_num][dcu].at("R1_DCU_DC007")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC008=m_inputs_map[ska_num][dcu].at("R1_DCU_DC008")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC009=m_inputs_map[ska_num][dcu].at("R1_DCU_DC009")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC010=m_inputs_map[ska_num][dcu].at("R1_DCU_DC010")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC013=m_inputs_map[ska_num][dcu].at("R1_DCU_DC013")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC014=m_inputs_map[ska_num][dcu].at("R1_DCU_DC014")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC015=m_inputs_map[ska_num][dcu].at("R1_DCU_DC015")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC016=m_inputs_map[ska_num][dcu].at("R1_DCU_DC016")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC017=m_inputs_map[ska_num][dcu].at("R1_DCU_DC017")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC018=m_inputs_map[ska_num][dcu].at("R1_DCU_DC018")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC019=m_inputs_map[ska_num][dcu].at("R1_DCU_DC019")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC020=m_inputs_map[ska_num][dcu].at("R1_DCU_DC020")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC021=m_inputs_map[ska_num][dcu].at("R1_DCU_DC021")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC022=m_inputs_map[ska_num][dcu].at("R1_DCU_DC022")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC027=m_inputs_map[ska_num][dcu].at("R1_DCU_DC027")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC028=m_inputs_map[ska_num][dcu].at("R1_DCU_DC028")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC029=m_inputs_map[ska_num][dcu].at("R1_DCU_DC029")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC030=m_inputs_map[ska_num][dcu].at("R1_DCU_DC030")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC031=m_inputs_map[ska_num][dcu].at("R1_DCU_DC031")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC033=m_inputs_map[ska_num][dcu].at("R1_DCU_DC033")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC037=m_inputs_map[ska_num][dcu].at("R1_DCU_DC037")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC042=m_inputs_map[ska_num][dcu].at("R1_DCU_DC042")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC043=m_inputs_map[ska_num][dcu].at("R1_DCU_DC043")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC044=m_inputs_map[ska_num][dcu].at("R1_DCU_DC044")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC046=m_inputs_map[ska_num][dcu].at("R1_DCU_DC046")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC048=m_inputs_map[ska_num][dcu].at("R1_DCU_DC048")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC049=m_inputs_map[ska_num][dcu].at("R1_DCU_DC049")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC050=m_inputs_map[ska_num][dcu].at("R1_DCU_DC050")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC051=m_inputs_map[ska_num][dcu].at("R1_DCU_DC051")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC052=m_inputs_map[ska_num][dcu].at("R1_DCU_DC052")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC053=m_inputs_map[ska_num][dcu].at("R1_DCU_DC053")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC065=m_inputs_map[ska_num][dcu].at("R1_DCU_DC065")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC066=m_inputs_map[ska_num][dcu].at("R1_DCU_DC066")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC067=m_inputs_map[ska_num][dcu].at("R1_DCU_DC067")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC068=m_inputs_map[ska_num][dcu].at("R1_DCU_DC068")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC069=m_inputs_map[ska_num][dcu].at("R1_DCU_DC069")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC090=m_inputs_map[ska_num][dcu].at("R1_DCU_DC090")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC091=m_inputs_map[ska_num][dcu].at("R1_DCU_DC091")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC098=m_inputs_map[ska_num][dcu].at("R1_DCU_DC098")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC099=m_inputs_map[ska_num][dcu].at("R1_DCU_DC099")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC101=m_inputs_map[ska_num][dcu].at("R1_DCU_DC101")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC102=m_inputs_map[ska_num][dcu].at("R1_DCU_DC102")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC103=m_inputs_map[ska_num][dcu].at("R1_DCU_DC103")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC105=m_inputs_map[ska_num][dcu].at("R1_DCU_DC105")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC106=m_inputs_map[ska_num][dcu].at("R1_DCU_DC106")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC111=m_inputs_map[ska_num][dcu].at("R1_DCU_DC111")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DC116=m_inputs_map[ska_num][dcu].at("R1_DCU_DC116")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DiagPrioA=m_inputs_map[ska_num][dcu].at("R1_DCU_DiagPrioA")                     ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_DiagPrioB=m_inputs_map[ska_num][dcu].at("R1_DCU_DiagPrioB")                     ;
//m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R1_DCU_CANopen_Fault=m_inputs_map[ska_num][dcu].at("DCU_SKA1_DoorR1_CANopen_Fault")                 ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit73=m_inputs_map[ska_num][dcu].at("bit73")                                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit74=m_inputs_map[ska_num][dcu].at("bit74")                                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit75=m_inputs_map[ska_num][dcu].at("bit75")                                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit76=m_inputs_map[ska_num][dcu].at("bit76")                                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit77=m_inputs_map[ska_num][dcu].at("bit77")                                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit78=m_inputs_map[ska_num][dcu].at("bit78")                                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit79=m_inputs_map[ska_num][dcu].at("bit79")                                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_IFESmartAssistDCU               =m_inputs_map[ska_num][dcu].at("R2_DCU_IFESmartAssistDCU")             ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_SuppEmergOp                     =m_inputs_map[ska_num][dcu].at("R2_DCU_SuppEmergOp")                   ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DoorAntiDrag                    =m_inputs_map[ska_num][dcu].at("R2_DCU_DoorAntiDrag")                  ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DoorObstDet                     =m_inputs_map[ska_num][dcu].at("R2_DCU_DoorObstDet")                   ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DoorMoveMonit                   =m_inputs_map[ska_num][dcu].at("R2_DCU_DoorMoveMonit")                 ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_EntrRel                         =m_inputs_map[ska_num][dcu].at("R2_DCU_EntrRel")                       ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DoorClosed                      =m_inputs_map[ska_num][dcu].at("R2_DCU_DoorClosed")                    ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DoorClosedAndLocked             =m_inputs_map[ska_num][dcu].at("R2_DCU_DoorClosedAndLocked")           ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DoorFullyOpen                   =m_inputs_map[ska_num][dcu].at("R2_DCU_DoorFullyOpen")                 ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DoorOutOfService                =m_inputs_map[ska_num][dcu].at("R2_DCU_DoorOutOfService")              ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DoorUnlEmergOp                  =m_inputs_map[ska_num][dcu].at("R2_DCU_DoorUnlEmergOp")                ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_EEDOp                           =m_inputs_map[ska_num][dcu].at("R2_DCU_EEDOp")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_EADOp                           =m_inputs_map[ska_num][dcu].at("R2_DCU_EADOp")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_PBOpenDLRightOutsideOp          =m_inputs_map[ska_num][dcu].at("R2_DCU_PBOpenDLRightOutsideOp")        ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_PBOpenDLRightInsideOp           =m_inputs_map[ska_num][dcu].at("R2_DCU_PBOpenDLRightInsideOp")         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_PBPRMPortalInsideOp             =m_inputs_map[ska_num][dcu].at("R2_DCU_PBPRMPortalInsideOp")           ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_LightBarrierPortalInsideInterr  =m_inputs_map[ska_num][dcu].at("R2_DCU_LightBarrierPortalInsideInterr");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_OutputTIL1                      =m_inputs_map[ska_num][dcu].at("R2_DCU_OutputTIL1")                    ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC001=m_inputs_map[ska_num][dcu].at("R2_DCU_DC001")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC002=m_inputs_map[ska_num][dcu].at("R2_DCU_DC002")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC003=m_inputs_map[ska_num][dcu].at("R2_DCU_DC003")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC004=m_inputs_map[ska_num][dcu].at("R2_DCU_DC004")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC005=m_inputs_map[ska_num][dcu].at("R2_DCU_DC005")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC006=m_inputs_map[ska_num][dcu].at("R2_DCU_DC006")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC007=m_inputs_map[ska_num][dcu].at("R2_DCU_DC007")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC008=m_inputs_map[ska_num][dcu].at("R2_DCU_DC008")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC009=m_inputs_map[ska_num][dcu].at("R2_DCU_DC009")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC010=m_inputs_map[ska_num][dcu].at("R2_DCU_DC010")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC013=m_inputs_map[ska_num][dcu].at("R2_DCU_DC013")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC014=m_inputs_map[ska_num][dcu].at("R2_DCU_DC014")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC015=m_inputs_map[ska_num][dcu].at("R2_DCU_DC015")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC016=m_inputs_map[ska_num][dcu].at("R2_DCU_DC016")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC017=m_inputs_map[ska_num][dcu].at("R2_DCU_DC017")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC018=m_inputs_map[ska_num][dcu].at("R2_DCU_DC018")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC019=m_inputs_map[ska_num][dcu].at("R2_DCU_DC019")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC020=m_inputs_map[ska_num][dcu].at("R2_DCU_DC020")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC021=m_inputs_map[ska_num][dcu].at("R2_DCU_DC021")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC022=m_inputs_map[ska_num][dcu].at("R2_DCU_DC022")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC027=m_inputs_map[ska_num][dcu].at("R2_DCU_DC027")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC028=m_inputs_map[ska_num][dcu].at("R2_DCU_DC028")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC029=m_inputs_map[ska_num][dcu].at("R2_DCU_DC029")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC030=m_inputs_map[ska_num][dcu].at("R2_DCU_DC030")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC031=m_inputs_map[ska_num][dcu].at("R2_DCU_DC031")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC033=m_inputs_map[ska_num][dcu].at("R2_DCU_DC033")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC037=m_inputs_map[ska_num][dcu].at("R2_DCU_DC037")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC042=m_inputs_map[ska_num][dcu].at("R2_DCU_DC042")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC043=m_inputs_map[ska_num][dcu].at("R2_DCU_DC043")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC044=m_inputs_map[ska_num][dcu].at("R2_DCU_DC044")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC046=m_inputs_map[ska_num][dcu].at("R2_DCU_DC046")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC048=m_inputs_map[ska_num][dcu].at("R2_DCU_DC048")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC049=m_inputs_map[ska_num][dcu].at("R2_DCU_DC049")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC050=m_inputs_map[ska_num][dcu].at("R2_DCU_DC050")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC051=m_inputs_map[ska_num][dcu].at("R2_DCU_DC051")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC052=m_inputs_map[ska_num][dcu].at("R2_DCU_DC052")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC053=m_inputs_map[ska_num][dcu].at("R2_DCU_DC053")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC065=m_inputs_map[ska_num][dcu].at("R2_DCU_DC065")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC066=m_inputs_map[ska_num][dcu].at("R2_DCU_DC066")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC067=m_inputs_map[ska_num][dcu].at("R2_DCU_DC067")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC068=m_inputs_map[ska_num][dcu].at("R2_DCU_DC068")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC069=m_inputs_map[ska_num][dcu].at("R2_DCU_DC069")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC090=m_inputs_map[ska_num][dcu].at("R2_DCU_DC090")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC091=m_inputs_map[ska_num][dcu].at("R2_DCU_DC091")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC098=m_inputs_map[ska_num][dcu].at("R2_DCU_DC098")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC099=m_inputs_map[ska_num][dcu].at("R2_DCU_DC099")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC101=m_inputs_map[ska_num][dcu].at("R2_DCU_DC101")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC102=m_inputs_map[ska_num][dcu].at("R2_DCU_DC102")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC103=m_inputs_map[ska_num][dcu].at("R2_DCU_DC103")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC105=m_inputs_map[ska_num][dcu].at("R2_DCU_DC105")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC106=m_inputs_map[ska_num][dcu].at("R2_DCU_DC106")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC111=m_inputs_map[ska_num][dcu].at("R2_DCU_DC111")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DC116=m_inputs_map[ska_num][dcu].at("R2_DCU_DC116")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DiagPrioA       =m_inputs_map[ska_num][dcu].at("R2_DCU_DiagPrioA")                     ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_DiagPrioB       =m_inputs_map[ska_num][dcu].at("R2_DCU_DiagPrioB")                     ;
//m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R2_DCU_CANopen_Fault   =m_inputs_map[ska_num][dcu].at("DCU_SKA1_DoorR2_CANopen_Fault");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit153=m_inputs_map[ska_num][dcu].at("bit153")                                        ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit154=m_inputs_map[ska_num][dcu].at("bit154")                                        ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit155=m_inputs_map[ska_num][dcu].at("bit155")                                        ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit156=m_inputs_map[ska_num][dcu].at("bit156")                                        ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit157=m_inputs_map[ska_num][dcu].at("bit157")                                        ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit158=m_inputs_map[ska_num][dcu].at("bit158")                                        ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit159=m_inputs_map[ska_num][dcu].at("bit159")                                        ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_IFESmartAssistDCU               =m_inputs_map[ska_num][dcu].at("R3_DCU_IFESmartAssistDCU")             ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_SuppEmergOp                     =m_inputs_map[ska_num][dcu].at("R3_DCU_SuppEmergOp")                   ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DoorAntiDrag                    =m_inputs_map[ska_num][dcu].at("R3_DCU_DoorAntiDrag")                  ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DoorObstDet                     =m_inputs_map[ska_num][dcu].at("R3_DCU_DoorObstDet")                   ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DoorMoveMonit                   =m_inputs_map[ska_num][dcu].at("R3_DCU_DoorMoveMonit")                 ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_EntrRel                         =m_inputs_map[ska_num][dcu].at("R3_DCU_EntrRel")                       ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DoorClosed                      =m_inputs_map[ska_num][dcu].at("R3_DCU_DoorClosed")                    ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DoorClosedAndLocked             =m_inputs_map[ska_num][dcu].at("R3_DCU_DoorClosedAndLocked")           ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DoorFullyOpen                   =m_inputs_map[ska_num][dcu].at("R3_DCU_DoorFullyOpen")                 ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DoorOutOfService                =m_inputs_map[ska_num][dcu].at("R3_DCU_DoorOutOfService")              ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DoorUnlEmergOp                  =m_inputs_map[ska_num][dcu].at("R3_DCU_DoorUnlEmergOp")                ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_EEDOp                           =m_inputs_map[ska_num][dcu].at("R3_DCU_EEDOp")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_EADOp                           =m_inputs_map[ska_num][dcu].at("R3_DCU_EADOp")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_PBOpenDLRightOutsideOp          =m_inputs_map[ska_num][dcu].at("R3_DCU_PBOpenDLRightOutsideOp")        ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_PBOpenDLRightInsideOp           =m_inputs_map[ska_num][dcu].at("R3_DCU_PBOpenDLRightInsideOp")         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_PBPRMPortalInsideOp             =m_inputs_map[ska_num][dcu].at("R3_DCU_PBPRMPortalInsideOp")           ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_LightBarrierPortalInsideInterr  =m_inputs_map[ska_num][dcu].at("R3_DCU_LightBarrierPortalInsideInterr");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_OutputTIL1                      =m_inputs_map[ska_num][dcu].at("R3_DCU_OutputTIL1")                    ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC001=m_inputs_map[ska_num][dcu].at("R3_DCU_DC001")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC002=m_inputs_map[ska_num][dcu].at("R3_DCU_DC002")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC003=m_inputs_map[ska_num][dcu].at("R3_DCU_DC003")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC004=m_inputs_map[ska_num][dcu].at("R3_DCU_DC004")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC005=m_inputs_map[ska_num][dcu].at("R3_DCU_DC005")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC006=m_inputs_map[ska_num][dcu].at("R3_DCU_DC006")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC007=m_inputs_map[ska_num][dcu].at("R3_DCU_DC007")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC008=m_inputs_map[ska_num][dcu].at("R3_DCU_DC008")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC009=m_inputs_map[ska_num][dcu].at("R3_DCU_DC009")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC010=m_inputs_map[ska_num][dcu].at("R3_DCU_DC010")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC013=m_inputs_map[ska_num][dcu].at("R3_DCU_DC013")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC014=m_inputs_map[ska_num][dcu].at("R3_DCU_DC014")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC015=m_inputs_map[ska_num][dcu].at("R3_DCU_DC015")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC016=m_inputs_map[ska_num][dcu].at("R3_DCU_DC016")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC017=m_inputs_map[ska_num][dcu].at("R3_DCU_DC017")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC018=m_inputs_map[ska_num][dcu].at("R3_DCU_DC018")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC019=m_inputs_map[ska_num][dcu].at("R3_DCU_DC019")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC020=m_inputs_map[ska_num][dcu].at("R3_DCU_DC020")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC021=m_inputs_map[ska_num][dcu].at("R3_DCU_DC021")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC022=m_inputs_map[ska_num][dcu].at("R3_DCU_DC022")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC027=m_inputs_map[ska_num][dcu].at("R3_DCU_DC027")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC028=m_inputs_map[ska_num][dcu].at("R3_DCU_DC028")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC029=m_inputs_map[ska_num][dcu].at("R3_DCU_DC029")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC030=m_inputs_map[ska_num][dcu].at("R3_DCU_DC030")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC031=m_inputs_map[ska_num][dcu].at("R3_DCU_DC031")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC033=m_inputs_map[ska_num][dcu].at("R3_DCU_DC033")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC037=m_inputs_map[ska_num][dcu].at("R3_DCU_DC037")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC042=m_inputs_map[ska_num][dcu].at("R3_DCU_DC042")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC043=m_inputs_map[ska_num][dcu].at("R3_DCU_DC043")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC044=m_inputs_map[ska_num][dcu].at("R3_DCU_DC044")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC046=m_inputs_map[ska_num][dcu].at("R3_DCU_DC046")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC048=m_inputs_map[ska_num][dcu].at("R3_DCU_DC048")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC049=m_inputs_map[ska_num][dcu].at("R3_DCU_DC049")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC050=m_inputs_map[ska_num][dcu].at("R3_DCU_DC050")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC051=m_inputs_map[ska_num][dcu].at("R3_DCU_DC051")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC052=m_inputs_map[ska_num][dcu].at("R3_DCU_DC052")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC053=m_inputs_map[ska_num][dcu].at("R3_DCU_DC053")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC065=m_inputs_map[ska_num][dcu].at("R3_DCU_DC065")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC066=m_inputs_map[ska_num][dcu].at("R3_DCU_DC066")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC067=m_inputs_map[ska_num][dcu].at("R3_DCU_DC067")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC068=m_inputs_map[ska_num][dcu].at("R3_DCU_DC068")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC069=m_inputs_map[ska_num][dcu].at("R3_DCU_DC069")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC090=m_inputs_map[ska_num][dcu].at("R3_DCU_DC090")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC091=m_inputs_map[ska_num][dcu].at("R3_DCU_DC091")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC098=m_inputs_map[ska_num][dcu].at("R3_DCU_DC098")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC099=m_inputs_map[ska_num][dcu].at("R3_DCU_DC099")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC101=m_inputs_map[ska_num][dcu].at("R3_DCU_DC101")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC102=m_inputs_map[ska_num][dcu].at("R3_DCU_DC102")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC103=m_inputs_map[ska_num][dcu].at("R3_DCU_DC103")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC105=m_inputs_map[ska_num][dcu].at("R3_DCU_DC105")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC106=m_inputs_map[ska_num][dcu].at("R3_DCU_DC106")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC111=m_inputs_map[ska_num][dcu].at("R3_DCU_DC111")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DC116=m_inputs_map[ska_num][dcu].at("R3_DCU_DC116")                         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DiagPrioA=m_inputs_map[ska_num][dcu].at("R3_DCU_DiagPrioA")                     ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_DiagPrioB=m_inputs_map[ska_num][dcu].at("R3_DCU_DiagPrioB")                     ;
//m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.R3_DCU_CANopen_Fault=m_inputs_map[ska_num][dcu].at("DCU_SKA1_DoorR3_CANopen_Fault")                 ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit233=m_inputs_map[ska_num][dcu].at("bit233")                                        ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit234=m_inputs_map[ska_num][dcu].at("bit234")                                        ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit235=m_inputs_map[ska_num][dcu].at("bit235")                                        ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit236=m_inputs_map[ska_num][dcu].at("bit236")                                        ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit237=m_inputs_map[ska_num][dcu].at("bit237")                                        ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit238=m_inputs_map[ska_num][dcu].at("bit238")                                        ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.bit239=m_inputs_map[ska_num][dcu].at("bit239")                                        ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.reserved_30=m_inputs_map[ska_num][dcu].at("reserved_30")                                   ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb2_dcu1.bits.reserved_31=m_inputs_map[ska_num][dcu].at("reserved_31")                                   ;
}



void SKA_DCU::init_ska_x_mvb2_dcu1_table(SKA_VEHICLE_NUM vehicle_type)
{
    int ska_num = static_cast<int>(vehicle_type);
    m_inputs_map[ska_num][DCU1] = {
            {"R1_DCU_IFESmartAssistDCU", 0},
            {"R1_DCU_SuppEmergOp", 0},
            {"R1_DCU_DoorAntiDrag", 0},
            {"R1_DCU_DoorObstDet", 0},
            {"R1_DCU_DoorMoveMonit", 0},
            {"R1_DCU_EntrRel", 0},
            {"R1_DCU_DoorClosed", 0},
            {"R1_DCU_DoorClosedAndLocked", 0},
            {"R1_DCU_DoorFullyOpen", 0},
            {"R1_DCU_DoorOutOfService", 0},
            {"R1_DCU_DoorUnlEmergOp", 0},
            {"R1_DCU_EEDOp", 0},
            {"R1_DCU_EADOp", 0},
            {"R1_DCU_PBOpenDLRightOutsideOp", 0},
            {"R1_DCU_PBOpenDLRightInsideOp", 0},
            {"R1_DCU_PBPRMPortalInsideOp", 0},
            {"R1_DCU_LightBarrierPortalInsideInterr", 0},
            {"R1_DCU_OutputTIL1", 0},
            {"R1_DCU_DC001", 0},
            {"R1_DCU_DC002", 0},
            {"R1_DCU_DC003", 0},
            {"R1_DCU_DC004", 0},
            {"R1_DCU_DC005", 0},
            {"R1_DCU_DC006", 0},
            {"R1_DCU_DC007", 0},
            {"R1_DCU_DC008", 0},
            {"R1_DCU_DC009", 0},
            {"R1_DCU_DC010", 0},
            {"R1_DCU_DC013", 0},
            {"R1_DCU_DC014", 0},
            {"R1_DCU_DC015", 0},
            {"R1_DCU_DC016", 0},
            {"R1_DCU_DC017", 0},
            {"R1_DCU_DC018", 0},
            {"R1_DCU_DC019", 0},
            {"R1_DCU_DC020", 0},
            {"R1_DCU_DC021", 0},
            {"R1_DCU_DC022", 0},
            {"R1_DCU_DC027", 0},
            {"R1_DCU_DC028", 0},
            {"R1_DCU_DC029", 0},
            {"R1_DCU_DC030", 0},
            {"R1_DCU_DC031", 0},
            {"R1_DCU_DC033", 0},
            {"R1_DCU_DC037", 0},
            {"R1_DCU_DC042", 0},
            {"R1_DCU_DC043", 0},
            {"R1_DCU_DC044", 0},
            {"R1_DCU_DC046", 0},
            {"R1_DCU_DC048", 0},
            {"R1_DCU_DC049", 0},
            {"R1_DCU_DC050", 0},
            {"R1_DCU_DC051", 0},
            {"R1_DCU_DC052", 0},
            {"R1_DCU_DC053", 0},
            {"R1_DCU_DC065", 0},
            {"R1_DCU_DC066", 0},
            {"R1_DCU_DC067", 0},
            {"R1_DCU_DC068", 0},
            {"R1_DCU_DC069", 0},
            {"R1_DCU_DC090", 0},
            {"R1_DCU_DC091", 0},
            {"R1_DCU_DC098", 0},
            {"R1_DCU_DC099", 0},
            {"R1_DCU_DC101", 0},
            {"R1_DCU_DC102", 0},
            {"R1_DCU_DC103", 0},
            {"R1_DCU_DC105", 0},
            {"R1_DCU_DC106", 0},
            {"R1_DCU_DC111", 0},
            {"R1_DCU_DC116", 0},
            {"R1_DCU_DiagPrioA", 0},
            {"R1_DCU_DiagPrioB", 0},
            {"bit73", 0},
            {"bit74", 0},
            {"bit75", 0},
            {"bit76", 0},
            {"bit77", 0},
            {"bit78", 0},
            {"bit79", 0},
            {"R2_DCU_IFESmartAssistDCU", 0},
            {"R2_DCU_SuppEmergOp", 0},
            {"R2_DCU_DoorAntiDrag", 0},
            {"R2_DCU_DoorObstDet", 0},
            {"R2_DCU_DoorMoveMonit", 0},
            {"R2_DCU_EntrRel", 0},
            {"R2_DCU_DoorClosed", 0},
            {"R2_DCU_DoorClosedAndLocked", 0},
            {"R2_DCU_DoorFullyOpen", 0},
            {"R2_DCU_DoorOutOfService", 0},
            {"R2_DCU_DoorUnlEmergOp", 0},
            {"R2_DCU_EEDOp", 0},
            {"R2_DCU_EADOp", 0},
            {"R2_DCU_PBOpenDLRightOutsideOp", 0},
            {"R2_DCU_PBOpenDLRightInsideOp", 0},
            {"R2_DCU_PBPRMPortalInsideOp", 0},
            {"R2_DCU_LightBarrierPortalInsideInterr", 0},
            {"R2_DCU_OutputTIL1", 0},
            {"R2_DCU_DC001", 0},
            {"R2_DCU_DC002", 0},
            {"R2_DCU_DC003", 0},
            {"R2_DCU_DC004", 0},
            {"R2_DCU_DC005", 0},
            {"R2_DCU_DC006", 0},
            {"R2_DCU_DC007", 0},
            {"R2_DCU_DC008", 0},
            {"R2_DCU_DC009", 0},
            {"R2_DCU_DC010", 0},
            {"R2_DCU_DC013", 0},
            {"R2_DCU_DC014", 0},
            {"R2_DCU_DC015", 0},
            {"R2_DCU_DC016", 0},
            {"R2_DCU_DC017", 0},
            {"R2_DCU_DC018", 0},
            {"R2_DCU_DC019", 0},
            {"R2_DCU_DC020", 0},
            {"R2_DCU_DC021", 0},
            {"R2_DCU_DC022", 0},
            {"R2_DCU_DC027", 0},
            {"R2_DCU_DC028", 0},
            {"R2_DCU_DC029", 0},
            {"R2_DCU_DC030", 0},
            {"R2_DCU_DC031", 0},
            {"R2_DCU_DC033", 0},
            {"R2_DCU_DC037", 0},
            {"R2_DCU_DC042", 0},
            {"R2_DCU_DC043", 0},
            {"R2_DCU_DC044", 0},
            {"R2_DCU_DC046", 0},
            {"R2_DCU_DC048", 0},
            {"R2_DCU_DC049", 0},
            {"R2_DCU_DC050", 0},
            {"R2_DCU_DC051", 0},
            {"R2_DCU_DC052", 0},
            {"R2_DCU_DC053", 0},
            {"R2_DCU_DC065", 0},
            {"R2_DCU_DC066", 0},
            {"R2_DCU_DC067", 0},
            {"R2_DCU_DC068", 0},
            {"R2_DCU_DC069", 0},
            {"R2_DCU_DC090", 0},
            {"R2_DCU_DC091", 0},
            {"R2_DCU_DC098", 0},
            {"R2_DCU_DC099", 0},
            {"R2_DCU_DC101", 0},
            {"R2_DCU_DC102", 0},
            {"R2_DCU_DC103", 0},
            {"R2_DCU_DC105", 0},
            {"R2_DCU_DC106", 0},
            {"R2_DCU_DC111", 0},
            {"R2_DCU_DC116", 0},
            {"R2_DCU_DiagPrioA", 0},
            {"R2_DCU_DiagPrioB", 0},
            {"bit153", 0},
            {"bit154", 0},
            {"bit155", 0},
            {"bit156", 0},
            {"bit157", 0},
            {"bit158", 0},
            {"bit159", 0},
            {"R3_DCU_IFESmartAssistDCU", 0},
            {"R3_DCU_SuppEmergOp", 0},
            {"R3_DCU_DoorAntiDrag", 0},
            {"R3_DCU_DoorObstDet", 0},
            {"R3_DCU_DoorMoveMonit", 0},
            {"R3_DCU_EntrRel", 0},
            {"R3_DCU_DoorClosed", 0},
            {"R3_DCU_DoorClosedAndLocked", 0},
            {"R3_DCU_DoorFullyOpen", 0},
            {"R3_DCU_DoorOutOfService", 0},
            {"R3_DCU_DoorUnlEmergOp", 0},
            {"R3_DCU_EEDOp", 0},
            {"R3_DCU_EADOp", 0},
            {"R3_DCU_PBOpenDLRightOutsideOp", 0},
            {"R3_DCU_PBOpenDLRightInsideOp", 0},
            {"R3_DCU_PBPRMPortalInsideOp", 0},
            {"R3_DCU_LightBarrierPortalInsideInterr", 0},
            {"R3_DCU_OutputTIL1", 0},
            {"R3_DCU_DC001", 0},
            {"R3_DCU_DC002", 0},
            {"R3_DCU_DC003", 0},
            {"R3_DCU_DC004", 0},
            {"R3_DCU_DC005", 0},
            {"R3_DCU_DC006", 0},
            {"R3_DCU_DC007", 0},
            {"R3_DCU_DC008", 0},
            {"R3_DCU_DC009", 0},
            {"R3_DCU_DC010", 0},
            {"R3_DCU_DC013", 0},
            {"R3_DCU_DC014", 0},
            {"R3_DCU_DC015", 0},
            {"R3_DCU_DC016", 0},
            {"R3_DCU_DC017", 0},
            {"R3_DCU_DC018", 0},
            {"R3_DCU_DC019", 0},
            {"R3_DCU_DC020", 0},
            {"R3_DCU_DC021", 0},
            {"R3_DCU_DC022", 0},
            {"R3_DCU_DC027", 0},
            {"R3_DCU_DC028", 0},
            {"R3_DCU_DC029", 0},
            {"R3_DCU_DC030", 0},
            {"R3_DCU_DC031", 0},
            {"R3_DCU_DC033", 0},
            {"R3_DCU_DC037", 0},
            {"R3_DCU_DC042", 0},
            {"R3_DCU_DC043", 0},
            {"R3_DCU_DC044", 0},
            {"R3_DCU_DC046", 0},
            {"R3_DCU_DC048", 0},
            {"R3_DCU_DC049", 0},
            {"R3_DCU_DC050", 0},
            {"R3_DCU_DC051", 0},
            {"R3_DCU_DC052", 0},
            {"R3_DCU_DC053", 0},
            {"R3_DCU_DC065", 0},
            {"R3_DCU_DC066", 0},
            {"R3_DCU_DC067", 0},
            {"R3_DCU_DC068", 0},
            {"R3_DCU_DC069", 0},
            {"R3_DCU_DC090", 0},
            {"R3_DCU_DC091", 0},
            {"R3_DCU_DC098", 0},
            {"R3_DCU_DC099", 0},
            {"R3_DCU_DC101", 0},
            {"R3_DCU_DC102", 0},
            {"R3_DCU_DC103", 0},
            {"R3_DCU_DC105", 0},
            {"R3_DCU_DC106", 0},
            {"R3_DCU_DC111", 0},
            {"R3_DCU_DC116", 0},
            {"R3_DCU_DiagPrioA", 0},
            {"R3_DCU_DiagPrioB", 0},
            {"bit233", 0},
            {"bit234", 0},
            {"bit235", 0},
            {"bit236", 0},
            {"bit237", 0},
            {"bit238", 0},
            {"bit239", 0},
            {"reserved_30", 0},
            {"reserved_31", 0},

    };

    /*m_tableWidget[ska_num][DCU1] = new QTableWidget();
    m_tableWidget[ska_num][DCU1]->setColumnCount(2);
    m_tableWidget[ska_num][DCU1]->setRowCount(m_inputs_map[ska_num][DCU1].size());
    m_tableWidget[ska_num][DCU1]->setHorizontalHeaderLabels(table_name[ska_num][DCU1]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[ska_num][DCU1]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[ska_num][DCU1]->setItem(row, 0, item_name);
        m_tableWidget[ska_num][DCU1]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[ska_num][DCU1]->resizeColumnsToContents();*/

    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[ska_num][DCU1].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[ska_num][DCU1] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[ska_num][DCU1]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[ska_num][DCU1]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[ska_num][DCU1]->setItem(row, column, item_name);
        m_tableWidget[ska_num][DCU1]->setItem(row, column + 1, item_val); // Değer

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[ska_num][DCU1]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][DCU1]->columnCount() ;
}



void SKA_DCU::update_dcu2_map(SKA_VEHICLE_NUM ska_x_num, DCU_LIST dcu)
{
    int ska_num = static_cast<int>(ska_x_num);
 m_inputs_map[ska_num][dcu].at("R4_DCU_IFESmartAssistDCU")                =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_IFESmartAssistDCU;
 m_inputs_map[ska_num][dcu].at("R4_DCU_SuppEmergOp")                      =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_SuppEmergOp;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DoorAntiDrag")                     =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DoorAntiDrag;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DoorObstDet")                      =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DoorObstDet;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DoorMoveMonit")                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DoorMoveMonit;
 m_inputs_map[ska_num][dcu].at("R4_DCU_EntrRel")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_EntrRel;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DoorClosed")                       =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DoorClosed;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DoorClosedAndLocked")              =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DoorClosedAndLocked;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DoorFullyOpen")                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DoorFullyOpen;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DoorOutOfService")                 =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DoorOutOfService;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DoorUnlEmergOp")                   =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DoorUnlEmergOp;
 m_inputs_map[ska_num][dcu].at("R4_DCU_EEDOp")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_EEDOp;
 m_inputs_map[ska_num][dcu].at("R4_DCU_EADOp")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_EADOp;
 m_inputs_map[ska_num][dcu].at("R4_DCU_PBOpenDLRightOutsideOp")           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_PBOpenDLRightOutsideOp;
 m_inputs_map[ska_num][dcu].at("R4_DCU_PBOpenDLRightInsideOp")            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_PBOpenDLRightInsideOp;
 m_inputs_map[ska_num][dcu].at("R4_DCU_PBPRMPortalInsideOp")              =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_PBPRMPortalInsideOp;
 m_inputs_map[ska_num][dcu].at("R4_DCU_LightBarrierPortalInsideInterr")   =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_LightBarrierPortalInsideInterr;
 m_inputs_map[ska_num][dcu].at("R4_DCU_OutputTIL1")                       =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_OutputTIL1;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC001")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC001;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC002")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC002;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC003")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC003;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC004")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC004;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC005")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC005;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC006")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC006;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC007")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC007;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC008")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC008;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC009")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC009;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC010")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC010;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC013")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC013;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC014")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC014;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC015")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC015;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC016")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC016;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC017")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC017;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC018")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC018;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC019")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC019;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC020")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC020;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC021")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC021;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC022")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC022;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC027")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC027;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC028")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC028;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC029")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC029;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC030")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC030;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC031")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC031;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC033")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC033;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC037")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC037;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC042")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC042;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC043")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC043;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC044")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC044;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC046")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC046;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC048")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC048;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC049")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC049;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC050")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC050;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC051")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC051;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC052")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC052;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC053")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC053;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC065")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC065;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC066")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC066;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC067")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC067;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC068")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC068;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC069")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC069;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC090")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC090;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC091")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC091;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC098")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC098;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC099")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC099;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC101")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC101;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC102")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC102;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC103")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC103;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC105")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC105;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC106")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC106;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC111")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC111;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DC116")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC116;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DiagPrioA")                        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DiagPrioA;
 m_inputs_map[ska_num][dcu].at("R4_DCU_DiagPrioB")                        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DiagPrioB;
 //m_inputs_map[ska_num][dcu].at("R4_DCU_CANopen_Fault")                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.DCU_SKA1_DoorR4_CANopen_Fault;
  m_inputs_map[ska_num][dcu].at("bit73")                                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit73;
 m_inputs_map[ska_num][dcu].at("bit74")                                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit74;
 m_inputs_map[ska_num][dcu].at("bit75")                                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit75;
 m_inputs_map[ska_num][dcu].at("bit76")                                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit76;
 m_inputs_map[ska_num][dcu].at("bit77")                                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit77;
 m_inputs_map[ska_num][dcu].at("bit78")                                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit78;
 m_inputs_map[ska_num][dcu].at("bit79")                                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit79;
 m_inputs_map[ska_num][dcu].at("L1_DCU_IFESmartAssistDCU")                =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_IFESmartAssistDCU;
 m_inputs_map[ska_num][dcu].at("L1_DCU_SuppEmergOp")                      =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_SuppEmergOp;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DoorAntiDrag")                     =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DoorAntiDrag;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DoorObstDet")                      =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DoorObstDet;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DoorMoveMonit")                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DoorMoveMonit;
 m_inputs_map[ska_num][dcu].at("L1_DCU_EntrRel")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_EntrRel;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DoorClosed")                       =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DoorClosed;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DoorClosedAndLocked")              =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DoorClosedAndLocked;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DoorFullyOpen")                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DoorFullyOpen;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DoorOutOfService")                 =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DoorOutOfService;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DoorUnlEmergOp")                   =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DoorUnlEmergOp;
 m_inputs_map[ska_num][dcu].at("L1_DCU_EEDOp")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_EEDOp;
 m_inputs_map[ska_num][dcu].at("L1_DCU_EADOp")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_EADOp;
 m_inputs_map[ska_num][dcu].at("L1_DCU_PBOpenDLRightOutsideOp")           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_PBOpenDLRightOutsideOp;
 m_inputs_map[ska_num][dcu].at("L1_DCU_PBOpenDLRightInsideOp")            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_PBOpenDLRightInsideOp;
 m_inputs_map[ska_num][dcu].at("L1_DCU_PBPRMPortalInsideOp")              =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_PBPRMPortalInsideOp;
 m_inputs_map[ska_num][dcu].at("L1_DCU_LightBarrierPortalInsideInterr")   =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_LightBarrierPortalInsideInterr;
 m_inputs_map[ska_num][dcu].at("L1_DCU_OutputTIL1")                       =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_OutputTIL1;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC001")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC001;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC002")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC002;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC003")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC003;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC004")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC004;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC005")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC005;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC006")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC006;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC007")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC007;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC008")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC008;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC009")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC009;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC010")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC010;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC013")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC013;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC014")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC014;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC015")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC015;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC016")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC016;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC017")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC017;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC018")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC018;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC019")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC019;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC020")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC020;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC021")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC021;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC022")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC022;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC027")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC027;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC028")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC028;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC029")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC029;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC030")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC030;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC031")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC031;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC033")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC033;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC037")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC037;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC042")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC042;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC043")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC043;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC044")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC044;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC046")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC046;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC048")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC048;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC049")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC049;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC050")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC050;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC051")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC051;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC052")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC052;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC053")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC053;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC065")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC065;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC066")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC066;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC067")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC067;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC068")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC068;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC069")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC069;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC090")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC090;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC091")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC091;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC098")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC098;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC099")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC099;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC101")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC101;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC102")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC102;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC103")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC103;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC105")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC105;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC106")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC106;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC111")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC111;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DC116")                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC116;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DiagPrioA")                       =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DiagPrioA;
 m_inputs_map[ska_num][dcu].at("L1_DCU_DiagPrioB")                       =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DiagPrioB;
 //m_inputs_map[ska_num][dcu].at("L1_DCU_CANopen_Fault")                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.DCU_SKA1_DoorL1_CANopen_Fault;
  m_inputs_map[ska_num][dcu].at("bit153")                                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit153;
 m_inputs_map[ska_num][dcu].at("bit154")                                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit154;
 m_inputs_map[ska_num][dcu].at("bit155")                                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit155;
 m_inputs_map[ska_num][dcu].at("bit156")                                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit156;
 m_inputs_map[ska_num][dcu].at("bit157")                                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit157;
 m_inputs_map[ska_num][dcu].at("bit158")                                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit158;
 m_inputs_map[ska_num][dcu].at("bit159")                                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit159;
 m_inputs_map[ska_num][dcu].at("L2_DCU_IFESmartAssistDCU")                =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_IFESmartAssistDCU;
 m_inputs_map[ska_num][dcu].at("L2_DCU_SuppEmergOp")                      =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_SuppEmergOp;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DoorAntiDrag")                     =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DoorAntiDrag;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DoorObstDet")                      =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DoorObstDet;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DoorMoveMonit")                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DoorMoveMonit;
 m_inputs_map[ska_num][dcu].at("L2_DCU_EntrRel")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_EntrRel;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DoorClosed")                       =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DoorClosed;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DoorClosedAndLocked")              =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DoorClosedAndLocked;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DoorFullyOpen")                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DoorFullyOpen;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DoorOutOfService")                 =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DoorOutOfService;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DoorUnlEmergOp")                   =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DoorUnlEmergOp;
 m_inputs_map[ska_num][dcu].at("L2_DCU_EEDOp")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_EEDOp;
 m_inputs_map[ska_num][dcu].at("L2_DCU_EADOp")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_EADOp;
 m_inputs_map[ska_num][dcu].at("L2_DCU_PBOpenDLRightOutsideOp")           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_PBOpenDLRightOutsideOp;
 m_inputs_map[ska_num][dcu].at("L2_DCU_PBOpenDLRightInsideOp")            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_PBOpenDLRightInsideOp;
 m_inputs_map[ska_num][dcu].at("L2_DCU_PBPRMPortalInsideOp")              =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_PBPRMPortalInsideOp;
 m_inputs_map[ska_num][dcu].at("L2_DCU_LightBarrierPortalInsideInterr")   =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_LightBarrierPortalInsideInterr;
 m_inputs_map[ska_num][dcu].at("L2_DCU_OutputTIL1")                       =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_OutputTIL1;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC001")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC001;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC002")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC002;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC003")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC003;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC004")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC004;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC005")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC005;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC006")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC006;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC007")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC007;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC008")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC008;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC009")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC009;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC010")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC010;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC013")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC013;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC014")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC014;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC015")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC015;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC016")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC016;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC017")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC017;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC018")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC018;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC019")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC019;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC020")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC020;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC021")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC021;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC022")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC022;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC027")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC027;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC028")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC028;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC029")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC029;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC030")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC030;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC031")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC031;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC033")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC033;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC037")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC037;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC042")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC042;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC043")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC043;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC044")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC044;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC046")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC046;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC048")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC048;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC049")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC049;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC050")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC050;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC051")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC051;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC052")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC052;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC053")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC053;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC065")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC065;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC066")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC066;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC067")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC067;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC068")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC068;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC069")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC069;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC090")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC090;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC091")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC091;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC098")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC098;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC099")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC099;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC101")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC101;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC102")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC102;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC103")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC103;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC105")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC105;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC106")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC106;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC111")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC111;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DC116")                            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC116;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DiagPrioA")                        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DiagPrioA;
 m_inputs_map[ska_num][dcu].at("L2_DCU_DiagPrioB")                        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DiagPrioB;
 //m_inputs_map[ska_num][dcu].at("L2_DCU_CANopen_Fault")                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.DCU_SKA1_DoorL2_CANopen_Fault;
  m_inputs_map[ska_num][dcu].at("bit233")                                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit233;
 m_inputs_map[ska_num][dcu].at("bit234")                                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit234;
 m_inputs_map[ska_num][dcu].at("bit235")                                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit235;
 m_inputs_map[ska_num][dcu].at("bit236")                                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit236;
 m_inputs_map[ska_num][dcu].at("bit237")                                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit237;
 m_inputs_map[ska_num][dcu].at("bit238")                                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit238;
 m_inputs_map[ska_num][dcu].at("bit239")                                           =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit239;
 m_inputs_map[ska_num][dcu].at("reserved_30")                                      =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.reserved_30;
 m_inputs_map[ska_num][dcu].at("reserved_31")                                      =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.reserved_31;


}

void SKA_DCU::set_struct_dcu2(SKA_VEHICLE_NUM ska_x_num, DCU_LIST dcu)
{
 int ska_num = static_cast<int>(ska_x_num);
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_IFESmartAssistDCU                      =m_inputs_map[ska_num][dcu].at("R4_DCU_IFESmartAssistDCU")                ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_SuppEmergOp                            =m_inputs_map[ska_num][dcu].at("R4_DCU_SuppEmergOp")                      ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DoorAntiDrag                           =m_inputs_map[ska_num][dcu].at("R4_DCU_DoorAntiDrag")                     ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DoorObstDet                            =m_inputs_map[ska_num][dcu].at("R4_DCU_DoorObstDet")                      ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DoorMoveMonit                          =m_inputs_map[ska_num][dcu].at("R4_DCU_DoorMoveMonit")                    ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_EntrRel                                =m_inputs_map[ska_num][dcu].at("R4_DCU_EntrRel")                          ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DoorClosed                             =m_inputs_map[ska_num][dcu].at("R4_DCU_DoorClosed")                       ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DoorClosedAndLocked                    =m_inputs_map[ska_num][dcu].at("R4_DCU_DoorClosedAndLocked")              ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DoorFullyOpen                          =m_inputs_map[ska_num][dcu].at("R4_DCU_DoorFullyOpen")                    ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DoorOutOfService                       =m_inputs_map[ska_num][dcu].at("R4_DCU_DoorOutOfService")                 ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DoorUnlEmergOp                         =m_inputs_map[ska_num][dcu].at("R4_DCU_DoorUnlEmergOp")                   ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_EEDOp                                  =m_inputs_map[ska_num][dcu].at("R4_DCU_EEDOp")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_EADOp                                  =m_inputs_map[ska_num][dcu].at("R4_DCU_EADOp")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_PBOpenDLRightOutsideOp                 =m_inputs_map[ska_num][dcu].at("R4_DCU_PBOpenDLRightOutsideOp")           ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_PBOpenDLRightInsideOp                  =m_inputs_map[ska_num][dcu].at("R4_DCU_PBOpenDLRightInsideOp")            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_PBPRMPortalInsideOp                    =m_inputs_map[ska_num][dcu].at("R4_DCU_PBPRMPortalInsideOp")              ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_LightBarrierPortalInsideInterr         =m_inputs_map[ska_num][dcu].at("R4_DCU_LightBarrierPortalInsideInterr")   ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_OutputTIL1                             =m_inputs_map[ska_num][dcu].at("R4_DCU_OutputTIL1")                       ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC001=m_inputs_map[ska_num][dcu].at("R4_DCU_DC001")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC002=m_inputs_map[ska_num][dcu].at("R4_DCU_DC002")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC003=m_inputs_map[ska_num][dcu].at("R4_DCU_DC003")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC004=m_inputs_map[ska_num][dcu].at("R4_DCU_DC004")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC005=m_inputs_map[ska_num][dcu].at("R4_DCU_DC005")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC006=m_inputs_map[ska_num][dcu].at("R4_DCU_DC006")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC007=m_inputs_map[ska_num][dcu].at("R4_DCU_DC007")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC008=m_inputs_map[ska_num][dcu].at("R4_DCU_DC008")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC009=m_inputs_map[ska_num][dcu].at("R4_DCU_DC009")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC010=m_inputs_map[ska_num][dcu].at("R4_DCU_DC010")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC013=m_inputs_map[ska_num][dcu].at("R4_DCU_DC013")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC014=m_inputs_map[ska_num][dcu].at("R4_DCU_DC014")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC015=m_inputs_map[ska_num][dcu].at("R4_DCU_DC015")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC016=m_inputs_map[ska_num][dcu].at("R4_DCU_DC016")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC017=m_inputs_map[ska_num][dcu].at("R4_DCU_DC017")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC018=m_inputs_map[ska_num][dcu].at("R4_DCU_DC018")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC019=m_inputs_map[ska_num][dcu].at("R4_DCU_DC019")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC020=m_inputs_map[ska_num][dcu].at("R4_DCU_DC020")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC021=m_inputs_map[ska_num][dcu].at("R4_DCU_DC021")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC022=m_inputs_map[ska_num][dcu].at("R4_DCU_DC022")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC027=m_inputs_map[ska_num][dcu].at("R4_DCU_DC027")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC028=m_inputs_map[ska_num][dcu].at("R4_DCU_DC028")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC029=m_inputs_map[ska_num][dcu].at("R4_DCU_DC029")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC030=m_inputs_map[ska_num][dcu].at("R4_DCU_DC030")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC031=m_inputs_map[ska_num][dcu].at("R4_DCU_DC031")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC033=m_inputs_map[ska_num][dcu].at("R4_DCU_DC033")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC037=m_inputs_map[ska_num][dcu].at("R4_DCU_DC037")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC042=m_inputs_map[ska_num][dcu].at("R4_DCU_DC042")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC043=m_inputs_map[ska_num][dcu].at("R4_DCU_DC043")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC044=m_inputs_map[ska_num][dcu].at("R4_DCU_DC044")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC046=m_inputs_map[ska_num][dcu].at("R4_DCU_DC046")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC048=m_inputs_map[ska_num][dcu].at("R4_DCU_DC048")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC049=m_inputs_map[ska_num][dcu].at("R4_DCU_DC049")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC050=m_inputs_map[ska_num][dcu].at("R4_DCU_DC050")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC051=m_inputs_map[ska_num][dcu].at("R4_DCU_DC051")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC052=m_inputs_map[ska_num][dcu].at("R4_DCU_DC052")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC053=m_inputs_map[ska_num][dcu].at("R4_DCU_DC053")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC065=m_inputs_map[ska_num][dcu].at("R4_DCU_DC065")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC066=m_inputs_map[ska_num][dcu].at("R4_DCU_DC066")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC067=m_inputs_map[ska_num][dcu].at("R4_DCU_DC067")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC068=m_inputs_map[ska_num][dcu].at("R4_DCU_DC068")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC069=m_inputs_map[ska_num][dcu].at("R4_DCU_DC069")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC090=m_inputs_map[ska_num][dcu].at("R4_DCU_DC090")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC091=m_inputs_map[ska_num][dcu].at("R4_DCU_DC091")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC098=m_inputs_map[ska_num][dcu].at("R4_DCU_DC098")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC099=m_inputs_map[ska_num][dcu].at("R4_DCU_DC099")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC101=m_inputs_map[ska_num][dcu].at("R4_DCU_DC101")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC102=m_inputs_map[ska_num][dcu].at("R4_DCU_DC102")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC103=m_inputs_map[ska_num][dcu].at("R4_DCU_DC103")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC105=m_inputs_map[ska_num][dcu].at("R4_DCU_DC105")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC106=m_inputs_map[ska_num][dcu].at("R4_DCU_DC106")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC111=m_inputs_map[ska_num][dcu].at("R4_DCU_DC111")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DC116=m_inputs_map[ska_num][dcu].at("R4_DCU_DC116")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DiagPrioA      =m_inputs_map[ska_num][dcu].at("R4_DCU_DiagPrioA")                        ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_DiagPrioB      =m_inputs_map[ska_num][dcu].at("R4_DCU_DiagPrioB")                        ;
 //m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.R4_DCU_CANopen_Fault  =m_inputs_map[ska_num][dcu].at("DCU_SKA1_DoorR4_CANopen_Fault")                    ;
  m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit73=m_inputs_map[ska_num][dcu].at("bit73")                                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit74=m_inputs_map[ska_num][dcu].at("bit74")                                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit75=m_inputs_map[ska_num][dcu].at("bit75")                                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit76=m_inputs_map[ska_num][dcu].at("bit76")                                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit77=m_inputs_map[ska_num][dcu].at("bit77")                                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit78=m_inputs_map[ska_num][dcu].at("bit78")                                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit79=m_inputs_map[ska_num][dcu].at("bit79")                                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_IFESmartAssistDCU                  =m_inputs_map[ska_num][dcu].at("L1_DCU_IFESmartAssistDCU")                ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_SuppEmergOp                        =m_inputs_map[ska_num][dcu].at("L1_DCU_SuppEmergOp")                      ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DoorAntiDrag                       =m_inputs_map[ska_num][dcu].at("L1_DCU_DoorAntiDrag")                     ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DoorObstDet                        =m_inputs_map[ska_num][dcu].at("L1_DCU_DoorObstDet")                      ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DoorMoveMonit                      =m_inputs_map[ska_num][dcu].at("L1_DCU_DoorMoveMonit")                    ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_EntrRel                            =m_inputs_map[ska_num][dcu].at("L1_DCU_EntrRel")                          ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DoorClosed                         =m_inputs_map[ska_num][dcu].at("L1_DCU_DoorClosed")                       ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DoorClosedAndLocked                =m_inputs_map[ska_num][dcu].at("L1_DCU_DoorClosedAndLocked")              ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DoorFullyOpen                      =m_inputs_map[ska_num][dcu].at("L1_DCU_DoorFullyOpen")                    ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DoorOutOfService                   =m_inputs_map[ska_num][dcu].at("L1_DCU_DoorOutOfService")                 ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DoorUnlEmergOp                     =m_inputs_map[ska_num][dcu].at("L1_DCU_DoorUnlEmergOp")                   ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_EEDOp                              =m_inputs_map[ska_num][dcu].at("L1_DCU_EEDOp")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_EADOp                              =m_inputs_map[ska_num][dcu].at("L1_DCU_EADOp")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_PBOpenDLRightOutsideOp             =m_inputs_map[ska_num][dcu].at("L1_DCU_PBOpenDLRightOutsideOp")           ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_PBOpenDLRightInsideOp              =m_inputs_map[ska_num][dcu].at("L1_DCU_PBOpenDLRightInsideOp")            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_PBPRMPortalInsideOp                =m_inputs_map[ska_num][dcu].at("L1_DCU_PBPRMPortalInsideOp")              ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_LightBarrierPortalInsideInterr     =m_inputs_map[ska_num][dcu].at("L1_DCU_LightBarrierPortalInsideInterr")   ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_OutputTIL1                         =m_inputs_map[ska_num][dcu].at("L1_DCU_OutputTIL1")                       ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC001=m_inputs_map[ska_num][dcu].at("L1_DCU_DC001")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC002=m_inputs_map[ska_num][dcu].at("L1_DCU_DC002")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC003=m_inputs_map[ska_num][dcu].at("L1_DCU_DC003")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC004=m_inputs_map[ska_num][dcu].at("L1_DCU_DC004")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC005=m_inputs_map[ska_num][dcu].at("L1_DCU_DC005")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC006=m_inputs_map[ska_num][dcu].at("L1_DCU_DC006")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC007=m_inputs_map[ska_num][dcu].at("L1_DCU_DC007")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC008=m_inputs_map[ska_num][dcu].at("L1_DCU_DC008")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC009=m_inputs_map[ska_num][dcu].at("L1_DCU_DC009")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC010=m_inputs_map[ska_num][dcu].at("L1_DCU_DC010")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC013=m_inputs_map[ska_num][dcu].at("L1_DCU_DC013")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC014=m_inputs_map[ska_num][dcu].at("L1_DCU_DC014")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC015=m_inputs_map[ska_num][dcu].at("L1_DCU_DC015")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC016=m_inputs_map[ska_num][dcu].at("L1_DCU_DC016")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC017=m_inputs_map[ska_num][dcu].at("L1_DCU_DC017")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC018=m_inputs_map[ska_num][dcu].at("L1_DCU_DC018")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC019=m_inputs_map[ska_num][dcu].at("L1_DCU_DC019")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC020=m_inputs_map[ska_num][dcu].at("L1_DCU_DC020")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC021=m_inputs_map[ska_num][dcu].at("L1_DCU_DC021")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC022=m_inputs_map[ska_num][dcu].at("L1_DCU_DC022")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC027=m_inputs_map[ska_num][dcu].at("L1_DCU_DC027")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC028=m_inputs_map[ska_num][dcu].at("L1_DCU_DC028")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC029=m_inputs_map[ska_num][dcu].at("L1_DCU_DC029")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC030=m_inputs_map[ska_num][dcu].at("L1_DCU_DC030")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC031=m_inputs_map[ska_num][dcu].at("L1_DCU_DC031")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC033=m_inputs_map[ska_num][dcu].at("L1_DCU_DC033")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC037=m_inputs_map[ska_num][dcu].at("L1_DCU_DC037")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC042=m_inputs_map[ska_num][dcu].at("L1_DCU_DC042")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC043=m_inputs_map[ska_num][dcu].at("L1_DCU_DC043")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC044=m_inputs_map[ska_num][dcu].at("L1_DCU_DC044")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC046=m_inputs_map[ska_num][dcu].at("L1_DCU_DC046")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC048=m_inputs_map[ska_num][dcu].at("L1_DCU_DC048")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC049=m_inputs_map[ska_num][dcu].at("L1_DCU_DC049")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC050=m_inputs_map[ska_num][dcu].at("L1_DCU_DC050")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC051=m_inputs_map[ska_num][dcu].at("L1_DCU_DC051")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC052=m_inputs_map[ska_num][dcu].at("L1_DCU_DC052")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC053=m_inputs_map[ska_num][dcu].at("L1_DCU_DC053")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC065=m_inputs_map[ska_num][dcu].at("L1_DCU_DC065")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC066=m_inputs_map[ska_num][dcu].at("L1_DCU_DC066")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC067=m_inputs_map[ska_num][dcu].at("L1_DCU_DC067")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC068=m_inputs_map[ska_num][dcu].at("L1_DCU_DC068")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC069=m_inputs_map[ska_num][dcu].at("L1_DCU_DC069")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC090=m_inputs_map[ska_num][dcu].at("L1_DCU_DC090")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC091=m_inputs_map[ska_num][dcu].at("L1_DCU_DC091")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC098=m_inputs_map[ska_num][dcu].at("L1_DCU_DC098")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC099=m_inputs_map[ska_num][dcu].at("L1_DCU_DC099")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC101=m_inputs_map[ska_num][dcu].at("L1_DCU_DC101")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC102=m_inputs_map[ska_num][dcu].at("L1_DCU_DC102")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC103=m_inputs_map[ska_num][dcu].at("L1_DCU_DC103")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC105=m_inputs_map[ska_num][dcu].at("L1_DCU_DC105")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC106=m_inputs_map[ska_num][dcu].at("L1_DCU_DC106")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC111=m_inputs_map[ska_num][dcu].at("L1_DCU_DC111")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DC116=m_inputs_map[ska_num][dcu].at("L1_DCU_DC116")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DiagPrioA      =m_inputs_map[ska_num][dcu].at("L1_DCU_DiagPrioA")                        ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_DiagPrioB      =m_inputs_map[ska_num][dcu].at("L1_DCU_DiagPrioB")                        ;
 //m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L1_DCU_CANopen_Fault  =m_inputs_map[ska_num][dcu].at("DCU_SKA1_DoorL1_CANopen_Fault")                    ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit153=m_inputs_map[ska_num][dcu].at("bit153") ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit154=m_inputs_map[ska_num][dcu].at("bit154");                                        ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit155=m_inputs_map[ska_num][dcu].at("bit155")                                           ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit156=m_inputs_map[ska_num][dcu].at("bit156")                                           ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit157=m_inputs_map[ska_num][dcu].at("bit157")                                           ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit158=m_inputs_map[ska_num][dcu].at("bit158")                                           ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit159=m_inputs_map[ska_num][dcu].at("bit159")                                           ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_IFESmartAssistDCU              =m_inputs_map[ska_num][dcu].at("L2_DCU_IFESmartAssistDCU")                ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_SuppEmergOp                    =m_inputs_map[ska_num][dcu].at("L2_DCU_SuppEmergOp")                      ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DoorAntiDrag                   =m_inputs_map[ska_num][dcu].at("L2_DCU_DoorAntiDrag")                     ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DoorObstDet                    =m_inputs_map[ska_num][dcu].at("L2_DCU_DoorObstDet")                      ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DoorMoveMonit                  =m_inputs_map[ska_num][dcu].at("L2_DCU_DoorMoveMonit")                    ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_EntrRel                        =m_inputs_map[ska_num][dcu].at("L2_DCU_EntrRel")                          ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DoorClosed                     =m_inputs_map[ska_num][dcu].at("L2_DCU_DoorClosed")                       ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DoorClosedAndLocked            =m_inputs_map[ska_num][dcu].at("L2_DCU_DoorClosedAndLocked")              ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DoorFullyOpen                  =m_inputs_map[ska_num][dcu].at("L2_DCU_DoorFullyOpen")                    ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DoorOutOfService               =m_inputs_map[ska_num][dcu].at("L2_DCU_DoorOutOfService")                 ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DoorUnlEmergOp                 =m_inputs_map[ska_num][dcu].at("L2_DCU_DoorUnlEmergOp")                   ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_EEDOp                          =m_inputs_map[ska_num][dcu].at("L2_DCU_EEDOp")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_EADOp                          =m_inputs_map[ska_num][dcu].at("L2_DCU_EADOp")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_PBOpenDLRightOutsideOp         =m_inputs_map[ska_num][dcu].at("L2_DCU_PBOpenDLRightOutsideOp")           ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_PBOpenDLRightInsideOp          =m_inputs_map[ska_num][dcu].at("L2_DCU_PBOpenDLRightInsideOp")            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_PBPRMPortalInsideOp            =m_inputs_map[ska_num][dcu].at("L2_DCU_PBPRMPortalInsideOp")              ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_LightBarrierPortalInsideInterr =m_inputs_map[ska_num][dcu].at("L2_DCU_LightBarrierPortalInsideInterr")   ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_OutputTIL1                     =m_inputs_map[ska_num][dcu].at("L2_DCU_OutputTIL1")                       ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC001=m_inputs_map[ska_num][dcu].at("L2_DCU_DC001")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC002=m_inputs_map[ska_num][dcu].at("L2_DCU_DC002")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC003=m_inputs_map[ska_num][dcu].at("L2_DCU_DC003")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC004=m_inputs_map[ska_num][dcu].at("L2_DCU_DC004")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC005=m_inputs_map[ska_num][dcu].at("L2_DCU_DC005")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC006=m_inputs_map[ska_num][dcu].at("L2_DCU_DC006")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC007=m_inputs_map[ska_num][dcu].at("L2_DCU_DC007")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC008=m_inputs_map[ska_num][dcu].at("L2_DCU_DC008")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC009=m_inputs_map[ska_num][dcu].at("L2_DCU_DC009")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC010=m_inputs_map[ska_num][dcu].at("L2_DCU_DC010")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC013=m_inputs_map[ska_num][dcu].at("L2_DCU_DC013")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC014=m_inputs_map[ska_num][dcu].at("L2_DCU_DC014")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC015=m_inputs_map[ska_num][dcu].at("L2_DCU_DC015")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC016=m_inputs_map[ska_num][dcu].at("L2_DCU_DC016")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC017=m_inputs_map[ska_num][dcu].at("L2_DCU_DC017")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC018=m_inputs_map[ska_num][dcu].at("L2_DCU_DC018")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC019=m_inputs_map[ska_num][dcu].at("L2_DCU_DC019")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC020=m_inputs_map[ska_num][dcu].at("L2_DCU_DC020")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC021=m_inputs_map[ska_num][dcu].at("L2_DCU_DC021")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC022=m_inputs_map[ska_num][dcu].at("L2_DCU_DC022")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC027=m_inputs_map[ska_num][dcu].at("L2_DCU_DC027")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC028=m_inputs_map[ska_num][dcu].at("L2_DCU_DC028")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC029=m_inputs_map[ska_num][dcu].at("L2_DCU_DC029")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC030=m_inputs_map[ska_num][dcu].at("L2_DCU_DC030")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC031=m_inputs_map[ska_num][dcu].at("L2_DCU_DC031")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC033=m_inputs_map[ska_num][dcu].at("L2_DCU_DC033")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC037=m_inputs_map[ska_num][dcu].at("L2_DCU_DC037")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC042=m_inputs_map[ska_num][dcu].at("L2_DCU_DC042")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC043=m_inputs_map[ska_num][dcu].at("L2_DCU_DC043")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC044=m_inputs_map[ska_num][dcu].at("L2_DCU_DC044")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC046=m_inputs_map[ska_num][dcu].at("L2_DCU_DC046")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC048=m_inputs_map[ska_num][dcu].at("L2_DCU_DC048")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC049=m_inputs_map[ska_num][dcu].at("L2_DCU_DC049")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC050=m_inputs_map[ska_num][dcu].at("L2_DCU_DC050")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC051=m_inputs_map[ska_num][dcu].at("L2_DCU_DC051")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC052=m_inputs_map[ska_num][dcu].at("L2_DCU_DC052")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC053=m_inputs_map[ska_num][dcu].at("L2_DCU_DC053")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC065=m_inputs_map[ska_num][dcu].at("L2_DCU_DC065")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC066=m_inputs_map[ska_num][dcu].at("L2_DCU_DC066")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC067=m_inputs_map[ska_num][dcu].at("L2_DCU_DC067")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC068=m_inputs_map[ska_num][dcu].at("L2_DCU_DC068")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC069=m_inputs_map[ska_num][dcu].at("L2_DCU_DC069")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC090=m_inputs_map[ska_num][dcu].at("L2_DCU_DC090")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC091=m_inputs_map[ska_num][dcu].at("L2_DCU_DC091")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC098=m_inputs_map[ska_num][dcu].at("L2_DCU_DC098")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC099=m_inputs_map[ska_num][dcu].at("L2_DCU_DC099")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC101=m_inputs_map[ska_num][dcu].at("L2_DCU_DC101")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC102=m_inputs_map[ska_num][dcu].at("L2_DCU_DC102")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC103=m_inputs_map[ska_num][dcu].at("L2_DCU_DC103")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC105=m_inputs_map[ska_num][dcu].at("L2_DCU_DC105")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC106=m_inputs_map[ska_num][dcu].at("L2_DCU_DC106")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC111=m_inputs_map[ska_num][dcu].at("L2_DCU_DC111")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DC116=m_inputs_map[ska_num][dcu].at("L2_DCU_DC116")                            ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DiagPrioA      =m_inputs_map[ska_num][dcu].at("L2_DCU_DiagPrioA")                        ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_DiagPrioB      =m_inputs_map[ska_num][dcu].at("L2_DCU_DiagPrioB")                        ;
 //m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.L2_DCU_CANopen_Fault  =m_inputs_map[ska_num][dcu].at("DCU_SKA1_DoorL2_CANopen_Fault")                    ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit233=m_inputs_map[ska_num][dcu].at("bit233")                                           ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit234=m_inputs_map[ska_num][dcu].at("bit234");

 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit235=m_inputs_map[ska_num][dcu].at("bit235")                                           ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit236=m_inputs_map[ska_num][dcu].at("bit236")                                           ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit237=m_inputs_map[ska_num][dcu].at("bit237")                                           ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit238=m_inputs_map[ska_num][dcu].at("bit238")                                           ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.bit239=m_inputs_map[ska_num][dcu].at("bit239")                                           ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.reserved_30=m_inputs_map[ska_num][dcu].at("reserved_30")                                      ;
 m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb3_dcu2.bits.reserved_31=m_inputs_map[ska_num][dcu].at("reserved_31")                                      ;
}



void SKA_DCU::init_ska_x_mvb3_dcu2_table(SKA_VEHICLE_NUM vehicle_type)
{

    int ska_num = static_cast<int>(vehicle_type);
    m_inputs_map[ska_num][DCU2] = {
{"R4_DCU_IFESmartAssistDCU", 0},
{"R4_DCU_SuppEmergOp", 0},
{"R4_DCU_DoorAntiDrag", 0},
{"R4_DCU_DoorObstDet", 0},
{"R4_DCU_DoorMoveMonit", 0},
{"R4_DCU_EntrRel", 0},
{"R4_DCU_DoorClosed", 0},
{"R4_DCU_DoorClosedAndLocked", 0},
{"R4_DCU_DoorFullyOpen", 0},
{"R4_DCU_DoorOutOfService", 0},
{"R4_DCU_DoorUnlEmergOp", 0},
{"R4_DCU_EEDOp", 0},
{"R4_DCU_EADOp", 0},
{"R4_DCU_PBOpenDLRightOutsideOp", 0},
{"R4_DCU_PBOpenDLRightInsideOp", 0},
{"R4_DCU_PBPRMPortalInsideOp", 0},
{"R4_DCU_LightBarrierPortalInsideInterr", 0},
{"R4_DCU_OutputTIL1", 0},
{"R4_DCU_DC001", 0},
{"R4_DCU_DC002", 0},
{"R4_DCU_DC003", 0},
{"R4_DCU_DC004", 0},
{"R4_DCU_DC005", 0},
{"R4_DCU_DC006", 0},
{"R4_DCU_DC007", 0},
{"R4_DCU_DC008", 0},
{"R4_DCU_DC009", 0},
{"R4_DCU_DC010", 0},
{"R4_DCU_DC013", 0},
{"R4_DCU_DC014", 0},
{"R4_DCU_DC015", 0},
{"R4_DCU_DC016", 0},
{"R4_DCU_DC017", 0},
{"R4_DCU_DC018", 0},
{"R4_DCU_DC019", 0},
{"R4_DCU_DC020", 0},
{"R4_DCU_DC021", 0},
{"R4_DCU_DC022", 0},
{"R4_DCU_DC027", 0},
{"R4_DCU_DC028", 0},
{"R4_DCU_DC029", 0},
{"R4_DCU_DC030", 0},
{"R4_DCU_DC031", 0},
{"R4_DCU_DC033", 0},
{"R4_DCU_DC037", 0},
{"R4_DCU_DC042", 0},
{"R4_DCU_DC043", 0},
{"R4_DCU_DC044", 0},
{"R4_DCU_DC046", 0},
{"R4_DCU_DC048", 0},
{"R4_DCU_DC049", 0},
{"R4_DCU_DC050", 0},
{"R4_DCU_DC051", 0},
{"R4_DCU_DC052", 0},
{"R4_DCU_DC053", 0},
{"R4_DCU_DC065", 0},
{"R4_DCU_DC066", 0},
{"R4_DCU_DC067", 0},
{"R4_DCU_DC068", 0},
{"R4_DCU_DC069", 0},
{"R4_DCU_DC090", 0},
{"R4_DCU_DC091", 0},
{"R4_DCU_DC098", 0},
{"R4_DCU_DC099", 0},
{"R4_DCU_DC101", 0},
{"R4_DCU_DC102", 0},
{"R4_DCU_DC103", 0},
{"R4_DCU_DC105", 0},
{"R4_DCU_DC106", 0},
{"R4_DCU_DC111", 0},
{"R4_DCU_DC116", 0},
{"R4_DCU_DiagPrioA", 0},
{"R4_DCU_DiagPrioB", 0},
{"bit73", 0},
{"bit74", 0},
{"bit75", 0},
{"bit76", 0},
{"bit77", 0},
{"bit78", 0},
{"bit79", 0},
{"L1_DCU_IFESmartAssistDCU", 0},
{"L1_DCU_SuppEmergOp", 0},
{"L1_DCU_DoorAntiDrag", 0},
{"L1_DCU_DoorObstDet", 0},
{"L1_DCU_DoorMoveMonit", 0},
{"L1_DCU_EntrRel", 0},
{"L1_DCU_DoorClosed", 0},
{"L1_DCU_DoorClosedAndLocked", 0},
{"L1_DCU_DoorFullyOpen", 0},
{"L1_DCU_DoorOutOfService", 0},
{"L1_DCU_DoorUnlEmergOp", 0},
{"L1_DCU_EEDOp", 0},
{"L1_DCU_EADOp", 0},
{"L1_DCU_PBOpenDLRightOutsideOp", 0},
{"L1_DCU_PBOpenDLRightInsideOp", 0},
{"L1_DCU_PBPRMPortalInsideOp", 0},
{"L1_DCU_LightBarrierPortalInsideInterr", 0},
{"L1_DCU_OutputTIL1", 0},
{"L1_DCU_DC001", 0},
{"L1_DCU_DC002", 0},
{"L1_DCU_DC003", 0},
{"L1_DCU_DC004", 0},
{"L1_DCU_DC005", 0},
{"L1_DCU_DC006", 0},
{"L1_DCU_DC007", 0},
{"L1_DCU_DC008", 0},
{"L1_DCU_DC009", 0},
{"L1_DCU_DC010", 0},
{"L1_DCU_DC013", 0},
{"L1_DCU_DC014", 0},
{"L1_DCU_DC015", 0},
{"L1_DCU_DC016", 0},
{"L1_DCU_DC017", 0},
{"L1_DCU_DC018", 0},
{"L1_DCU_DC019", 0},
{"L1_DCU_DC020", 0},
{"L1_DCU_DC021", 0},
{"L1_DCU_DC022", 0},
{"L1_DCU_DC027", 0},
{"L1_DCU_DC028", 0},
{"L1_DCU_DC029", 0},
{"L1_DCU_DC030", 0},
{"L1_DCU_DC031", 0},
{"L1_DCU_DC033", 0},
{"L1_DCU_DC037", 0},
{"L1_DCU_DC042", 0},
{"L1_DCU_DC043", 0},
{"L1_DCU_DC044", 0},
{"L1_DCU_DC046", 0},
{"L1_DCU_DC048", 0},
{"L1_DCU_DC049", 0},
{"L1_DCU_DC050", 0},
{"L1_DCU_DC051", 0},
{"L1_DCU_DC052", 0},
{"L1_DCU_DC053", 0},
{"L1_DCU_DC065", 0},
{"L1_DCU_DC066", 0},
{"L1_DCU_DC067", 0},
{"L1_DCU_DC068", 0},
{"L1_DCU_DC069", 0},
{"L1_DCU_DC090", 0},
{"L1_DCU_DC091", 0},
{"L1_DCU_DC098", 0},
{"L1_DCU_DC099", 0},
{"L1_DCU_DC101", 0},
{"L1_DCU_DC102", 0},
{"L1_DCU_DC103", 0},
{"L1_DCU_DC105", 0},
{"L1_DCU_DC106", 0},
{"L1_DCU_DC111", 0},
{"L1_DCU_DC116", 0},
{"L1_DCU_DiagPrioA", 0},
{"L1_DCU_DiagPrioB", 0},
{"bit153", 0},
{"bit154", 0},
{"bit155", 0},
{"bit156", 0},
{"bit157", 0},
{"bit158", 0},
{"bit159", 0},
{"L2_DCU_IFESmartAssistDCU", 0},
{"L2_DCU_SuppEmergOp", 0},
{"L2_DCU_DoorAntiDrag", 0},
{"L2_DCU_DoorObstDet", 0},
{"L2_DCU_DoorMoveMonit", 0},
{"L2_DCU_EntrRel", 0},
{"L2_DCU_DoorClosed", 0},
{"L2_DCU_DoorClosedAndLocked", 0},
{"L2_DCU_DoorFullyOpen", 0},
{"L2_DCU_DoorOutOfService", 0},
{"L2_DCU_DoorUnlEmergOp", 0},
{"L2_DCU_EEDOp", 0},
{"L2_DCU_EADOp", 0},
{"L2_DCU_PBOpenDLRightOutsideOp", 0},
{"L2_DCU_PBOpenDLRightInsideOp", 0},
{"L2_DCU_PBPRMPortalInsideOp", 0},
{"L2_DCU_LightBarrierPortalInsideInterr", 0},
{"L2_DCU_OutputTIL1", 0},
{"L2_DCU_DC001", 0},
{"L2_DCU_DC002", 0},
{"L2_DCU_DC003", 0},
{"L2_DCU_DC004", 0},
{"L2_DCU_DC005", 0},
{"L2_DCU_DC006", 0},
{"L2_DCU_DC007", 0},
{"L2_DCU_DC008", 0},
{"L2_DCU_DC009", 0},
{"L2_DCU_DC010", 0},
{"L2_DCU_DC013", 0},
{"L2_DCU_DC014", 0},
{"L2_DCU_DC015", 0},
{"L2_DCU_DC016", 0},
{"L2_DCU_DC017", 0},
{"L2_DCU_DC018", 0},
{"L2_DCU_DC019", 0},
{"L2_DCU_DC020", 0},
{"L2_DCU_DC021", 0},
{"L2_DCU_DC022", 0},
{"L2_DCU_DC027", 0},
{"L2_DCU_DC028", 0},
{"L2_DCU_DC029", 0},
{"L2_DCU_DC030", 0},
{"L2_DCU_DC031", 0},
{"L2_DCU_DC033", 0},
{"L2_DCU_DC037", 0},
{"L2_DCU_DC042", 0},
{"L2_DCU_DC043", 0},
{"L2_DCU_DC044", 0},
{"L2_DCU_DC046", 0},
{"L2_DCU_DC048", 0},
{"L2_DCU_DC049", 0},
{"L2_DCU_DC050", 0},
{"L2_DCU_DC051", 0},
{"L2_DCU_DC052", 0},
{"L2_DCU_DC053", 0},
{"L2_DCU_DC065", 0},
{"L2_DCU_DC066", 0},
{"L2_DCU_DC067", 0},
{"L2_DCU_DC068", 0},
{"L2_DCU_DC069", 0},
{"L2_DCU_DC090", 0},
{"L2_DCU_DC091", 0},
{"L2_DCU_DC098", 0},
{"L2_DCU_DC099", 0},
{"L2_DCU_DC101", 0},
{"L2_DCU_DC102", 0},
{"L2_DCU_DC103", 0},
{"L2_DCU_DC105", 0},
{"L2_DCU_DC106", 0},
{"L2_DCU_DC111", 0},
{"L2_DCU_DC116", 0},
{"L2_DCU_DiagPrioA", 0},
{"L2_DCU_DiagPrioB", 0},
{"bit233", 0},
{"bit234", 0},
{"bit235", 0},
{"bit236", 0},
{"bit237", 0},
{"bit238", 0},
{"bit239", 0},
{"reserved_30", 0},
{"reserved_31", 0}

    };

    /*m_tableWidget[ska_num][DCU2] = new QTableWidget();
    m_tableWidget[ska_num][DCU2]->setColumnCount(2);
    m_tableWidget[ska_num][DCU2]->setRowCount(m_inputs_map[ska_num][DCU2].size());
    m_tableWidget[ska_num][DCU2]->setHorizontalHeaderLabels(table_name[ska_num][DCU2]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[ska_num][DCU2]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[ska_num][DCU2]->setItem(row, 0, item_name);
        m_tableWidget[ska_num][DCU2]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[ska_num][DCU2]->resizeColumnsToContents();*/

    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[ska_num][DCU2].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[ska_num][DCU2] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[ska_num][DCU2]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[ska_num][DCU2]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[ska_num][DCU2]->setItem(row, column, item_name);
        m_tableWidget[ska_num][DCU2]->setItem(row, column + 1, item_val); // Değer

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[ska_num][DCU2]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][DCU2]->columnCount() ;
}

void SKA_DCU::update_dcu3_map(SKA_VEHICLE_NUM ska_x_num, DCU_LIST dcu)
{
    int ska_num = static_cast<int>(ska_x_num);
m_inputs_map[ska_num][dcu].at("L3_DCU_IFESmartAssistDCU")              =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_IFESmartAssistDCU;
m_inputs_map[ska_num][dcu].at("L3_DCU_SuppEmergOp")                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_SuppEmergOp;
m_inputs_map[ska_num][dcu].at("L3_DCU_DoorAntiDrag")                   =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DoorAntiDrag;
m_inputs_map[ska_num][dcu].at("L3_DCU_DoorObstDet")                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DoorObstDet;
m_inputs_map[ska_num][dcu].at("L3_DCU_DoorMoveMonit")                  =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DoorMoveMonit;
m_inputs_map[ska_num][dcu].at("L3_DCU_EntrRel")                        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_EntrRel;
m_inputs_map[ska_num][dcu].at("L3_DCU_DoorClosed")                     =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DoorClosed;
m_inputs_map[ska_num][dcu].at("L3_DCU_DoorClosedAndLocked")            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DoorClosedAndLocked;
m_inputs_map[ska_num][dcu].at("L3_DCU_DoorFullyOpen")                  =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DoorFullyOpen;
m_inputs_map[ska_num][dcu].at("L3_DCU_DoorOutOfService")               =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DoorOutOfService;
m_inputs_map[ska_num][dcu].at("L3_DCU_DoorUnlEmergOp")                 =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DoorUnlEmergOp;
m_inputs_map[ska_num][dcu].at("L3_DCU_EEDOp")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_EEDOp;
m_inputs_map[ska_num][dcu].at("L3_DCU_EADOp")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_EADOp;
m_inputs_map[ska_num][dcu].at("L3_DCU_PBOpenDLRightOutsideOp")         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_PBOpenDLRightOutsideOp;
m_inputs_map[ska_num][dcu].at("L3_DCU_PBOpenDLRightInsideOp")          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_PBOpenDLRightInsideOp;
m_inputs_map[ska_num][dcu].at("L3_DCU_PBPRMPortalInsideOp")            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_PBPRMPortalInsideOp;
m_inputs_map[ska_num][dcu].at("L3_DCU_LightBarrierPortalInsideInterr") =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_LightBarrierPortalInsideInterr;
m_inputs_map[ska_num][dcu].at("L3_DCU_OutputTIL1")                     =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_OutputTIL1;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC001")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC001;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC002")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC002;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC003")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC003;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC004")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC004;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC005")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC005;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC006")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC006;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC007")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC007;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC008")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC008;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC009")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC009;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC010")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC010;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC013")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC013;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC014")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC014;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC015")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC015;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC016")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC016;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC017")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC017;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC018")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC018;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC019")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC019;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC020")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC020;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC021")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC021;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC022")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC022;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC027")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC027;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC028")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC028;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC029")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC029;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC030")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC030;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC031")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC031;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC033")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC033;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC037")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC037;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC042")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC042;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC043")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC043;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC044")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC044;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC046")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC046;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC048")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC048;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC049")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC049;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC050")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC050;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC051")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC051;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC052")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC052;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC053")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC053;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC065")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC065;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC066")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC066;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC067")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC067;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC068")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC068;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC069")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC069;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC090")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC090;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC091")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC091;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC098")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC098;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC099")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC099;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC101")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC101;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC102")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC102;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC103")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC103;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC105")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC105;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC106")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC106;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC111")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC111;
m_inputs_map[ska_num][dcu].at("L3_DCU_DC116")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC116;
m_inputs_map[ska_num][dcu].at("L3_DCU_DiagPrioA")                      =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DiagPrioA;
m_inputs_map[ska_num][dcu].at("L3_DCU_DiagPrioB")                      =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DiagPrioB;
m_inputs_map[ska_num][dcu].at("bit73")                                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit73;
m_inputs_map[ska_num][dcu].at("bit74")                                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit74;
m_inputs_map[ska_num][dcu].at("bit75")                                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit75;
m_inputs_map[ska_num][dcu].at("bit76")                                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit76;
m_inputs_map[ska_num][dcu].at("bit77")                                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit77;
m_inputs_map[ska_num][dcu].at("bit78")                                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit78;
m_inputs_map[ska_num][dcu].at("bit79")                                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit79;
m_inputs_map[ska_num][dcu].at("L4_DCU_IFESmartAssistDCU")              =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_IFESmartAssistDCU;
m_inputs_map[ska_num][dcu].at("L4_DCU_SuppEmergOp")                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_SuppEmergOp;
m_inputs_map[ska_num][dcu].at("L4_DCU_DoorAntiDrag")                   =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DoorAntiDrag;
m_inputs_map[ska_num][dcu].at("L4_DCU_DoorObstDet")                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DoorObstDet;
m_inputs_map[ska_num][dcu].at("L4_DCU_DoorMoveMonit")                  =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DoorMoveMonit;
m_inputs_map[ska_num][dcu].at("L4_DCU_EntrRel")                        =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_EntrRel;
m_inputs_map[ska_num][dcu].at("L4_DCU_DoorClosed")                     =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DoorClosed;
m_inputs_map[ska_num][dcu].at("L4_DCU_DoorClosedAndLocked")            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DoorClosedAndLocked;
m_inputs_map[ska_num][dcu].at("L4_DCU_DoorFullyOpen")                  =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DoorFullyOpen;
m_inputs_map[ska_num][dcu].at("L4_DCU_DoorOutOfService")               =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DoorOutOfService;
m_inputs_map[ska_num][dcu].at("L4_DCU_DoorUnlEmergOp")                 =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DoorUnlEmergOp;
m_inputs_map[ska_num][dcu].at("L4_DCU_EEDOp")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_EEDOp;
m_inputs_map[ska_num][dcu].at("L4_DCU_EADOp")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_EADOp;
m_inputs_map[ska_num][dcu].at("L4_DCU_PBOpenDLRightOutsideOp")         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_PBOpenDLRightOutsideOp;
m_inputs_map[ska_num][dcu].at("L4_DCU_PBOpenDLRightInsideOp")          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_PBOpenDLRightInsideOp;
m_inputs_map[ska_num][dcu].at("L4_DCU_PBPRMPortalInsideOp")            =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_PBPRMPortalInsideOp;
m_inputs_map[ska_num][dcu].at("L4_DCU_LightBarrierPortalInsideInterr") =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_LightBarrierPortalInsideInterr;
m_inputs_map[ska_num][dcu].at("L4_DCU_OutputTIL1")                     =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_OutputTIL1;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC001")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC001;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC002")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC002;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC003")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC003;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC004")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC004;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC005")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC005;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC006")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC006;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC007")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC007;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC008")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC008;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC009")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC009;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC010")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC010;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC013")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC013;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC014")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC014;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC015")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC015;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC016")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC016;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC017")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC017;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC018")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC018;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC019")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC019;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC020")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC020;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC021")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC021;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC022")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC022;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC027")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC027;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC028")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC028;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC029")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC029;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC030")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC030;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC031")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC031;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC033")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC033;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC037")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC037;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC042")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC042;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC043")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC043;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC044")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC044;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC046")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC046;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC048")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC048;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC049")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC049;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC050")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC050;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC051")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC051;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC052")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC052;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC053")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC053;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC065")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC065;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC066")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC066;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC067")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC067;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC068")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC068;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC069")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC069;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC090")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC090;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC091")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC091;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC098")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC098;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC099")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC099;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC101")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC101;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC102")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC102;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC103")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC103;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC105")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC105;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC106")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC106;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC111")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC111;
m_inputs_map[ska_num][dcu].at("L4_DCU_DC116")                          =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC116;
m_inputs_map[ska_num][dcu].at("L4_DCU_DiagPrioA")                      =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DiagPrioA;
m_inputs_map[ska_num][dcu].at("L4_DCU_DiagPrioB")                      =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DiagPrioB;
m_inputs_map[ska_num][dcu].at("bit153")                                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit153;
m_inputs_map[ska_num][dcu].at("bit154")                                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit154;
m_inputs_map[ska_num][dcu].at("bit155")                                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit155;
m_inputs_map[ska_num][dcu].at("bit156")                                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit156;
m_inputs_map[ska_num][dcu].at("bit157")                                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit157;
m_inputs_map[ska_num][dcu].at("bit158")                                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit158;
m_inputs_map[ska_num][dcu].at("bit159")                                         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit159;
m_inputs_map[ska_num][dcu].at("reserved_20")                                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_20;
m_inputs_map[ska_num][dcu].at("reserved_21")                                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_21;
m_inputs_map[ska_num][dcu].at("reserved_22")                                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_22;
m_inputs_map[ska_num][dcu].at("reserved_23")                                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_23;
m_inputs_map[ska_num][dcu].at("reserved_24")                                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_24;
m_inputs_map[ska_num][dcu].at("reserved_25")                                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_25;
m_inputs_map[ska_num][dcu].at("reserved_26")                                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_26;
m_inputs_map[ska_num][dcu].at("reserved_27")                                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_27;
m_inputs_map[ska_num][dcu].at("reserved_28")                                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_28;
m_inputs_map[ska_num][dcu].at("reserved_29")                                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_29;
m_inputs_map[ska_num][dcu].at("reserved_30")                                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_30;
m_inputs_map[ska_num][dcu].at("reserved_31")                                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_31;

}

void SKA_DCU::set_struct_dcu3(SKA_VEHICLE_NUM ska_x_num, DCU_LIST dcu)
{
    int ska_num = static_cast<int>(ska_x_num);

m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_IFESmartAssistDCU               =m_inputs_map[ska_num][dcu].at("L3_DCU_IFESmartAssistDCU")              ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_SuppEmergOp                     =m_inputs_map[ska_num][dcu].at("L3_DCU_SuppEmergOp")                    ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DoorAntiDrag                    =m_inputs_map[ska_num][dcu].at("L3_DCU_DoorAntiDrag")                   ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DoorObstDet                     =m_inputs_map[ska_num][dcu].at("L3_DCU_DoorObstDet")                    ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DoorMoveMonit                   =m_inputs_map[ska_num][dcu].at("L3_DCU_DoorMoveMonit")                  ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_EntrRel                         =m_inputs_map[ska_num][dcu].at("L3_DCU_EntrRel")                        ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DoorClosed                      =m_inputs_map[ska_num][dcu].at("L3_DCU_DoorClosed")                     ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DoorClosedAndLocked             =m_inputs_map[ska_num][dcu].at("L3_DCU_DoorClosedAndLocked")            ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DoorFullyOpen                   =m_inputs_map[ska_num][dcu].at("L3_DCU_DoorFullyOpen")                  ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DoorOutOfService                =m_inputs_map[ska_num][dcu].at("L3_DCU_DoorOutOfService")               ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DoorUnlEmergOp                  =m_inputs_map[ska_num][dcu].at("L3_DCU_DoorUnlEmergOp")                 ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_EEDOp                           =m_inputs_map[ska_num][dcu].at("L3_DCU_EEDOp")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_EADOp                           =m_inputs_map[ska_num][dcu].at("L3_DCU_EADOp")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_PBOpenDLRightOutsideOp          =m_inputs_map[ska_num][dcu].at("L3_DCU_PBOpenDLRightOutsideOp")         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_PBOpenDLRightInsideOp           =m_inputs_map[ska_num][dcu].at("L3_DCU_PBOpenDLRightInsideOp")          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_PBPRMPortalInsideOp             =m_inputs_map[ska_num][dcu].at("L3_DCU_PBPRMPortalInsideOp")            ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_LightBarrierPortalInsideInterr  =m_inputs_map[ska_num][dcu].at("L3_DCU_LightBarrierPortalInsideInterr") ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_OutputTIL1                      =m_inputs_map[ska_num][dcu].at("L3_DCU_OutputTIL1")                     ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC001=m_inputs_map[ska_num][dcu].at("L3_DCU_DC001")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC002=m_inputs_map[ska_num][dcu].at("L3_DCU_DC002")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC003=m_inputs_map[ska_num][dcu].at("L3_DCU_DC003")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC004=m_inputs_map[ska_num][dcu].at("L3_DCU_DC004")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC005=m_inputs_map[ska_num][dcu].at("L3_DCU_DC005")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC006=m_inputs_map[ska_num][dcu].at("L3_DCU_DC006")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC007=m_inputs_map[ska_num][dcu].at("L3_DCU_DC007")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC008=m_inputs_map[ska_num][dcu].at("L3_DCU_DC008")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC009=m_inputs_map[ska_num][dcu].at("L3_DCU_DC009")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC010=m_inputs_map[ska_num][dcu].at("L3_DCU_DC010")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC013=m_inputs_map[ska_num][dcu].at("L3_DCU_DC013")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC014=m_inputs_map[ska_num][dcu].at("L3_DCU_DC014")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC015=m_inputs_map[ska_num][dcu].at("L3_DCU_DC015")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC016=m_inputs_map[ska_num][dcu].at("L3_DCU_DC016")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC017=m_inputs_map[ska_num][dcu].at("L3_DCU_DC017")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC018=m_inputs_map[ska_num][dcu].at("L3_DCU_DC018")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC019=m_inputs_map[ska_num][dcu].at("L3_DCU_DC019")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC020=m_inputs_map[ska_num][dcu].at("L3_DCU_DC020")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC021=m_inputs_map[ska_num][dcu].at("L3_DCU_DC021")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC022=m_inputs_map[ska_num][dcu].at("L3_DCU_DC022")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC027=m_inputs_map[ska_num][dcu].at("L3_DCU_DC027")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC028=m_inputs_map[ska_num][dcu].at("L3_DCU_DC028")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC029=m_inputs_map[ska_num][dcu].at("L3_DCU_DC029")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC030=m_inputs_map[ska_num][dcu].at("L3_DCU_DC030")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC031=m_inputs_map[ska_num][dcu].at("L3_DCU_DC031")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC033=m_inputs_map[ska_num][dcu].at("L3_DCU_DC033")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC037=m_inputs_map[ska_num][dcu].at("L3_DCU_DC037")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC042=m_inputs_map[ska_num][dcu].at("L3_DCU_DC042")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC043=m_inputs_map[ska_num][dcu].at("L3_DCU_DC043")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC044=m_inputs_map[ska_num][dcu].at("L3_DCU_DC044")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC046=m_inputs_map[ska_num][dcu].at("L3_DCU_DC046")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC048=m_inputs_map[ska_num][dcu].at("L3_DCU_DC048")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC049=m_inputs_map[ska_num][dcu].at("L3_DCU_DC049")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC050=m_inputs_map[ska_num][dcu].at("L3_DCU_DC050")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC051=m_inputs_map[ska_num][dcu].at("L3_DCU_DC051")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC052=m_inputs_map[ska_num][dcu].at("L3_DCU_DC052")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC053=m_inputs_map[ska_num][dcu].at("L3_DCU_DC053")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC065=m_inputs_map[ska_num][dcu].at("L3_DCU_DC065")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC066=m_inputs_map[ska_num][dcu].at("L3_DCU_DC066")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC067=m_inputs_map[ska_num][dcu].at("L3_DCU_DC067")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC068=m_inputs_map[ska_num][dcu].at("L3_DCU_DC068")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC069=m_inputs_map[ska_num][dcu].at("L3_DCU_DC069")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC090=m_inputs_map[ska_num][dcu].at("L3_DCU_DC090")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC091=m_inputs_map[ska_num][dcu].at("L3_DCU_DC091")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC098=m_inputs_map[ska_num][dcu].at("L3_DCU_DC098")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC099=m_inputs_map[ska_num][dcu].at("L3_DCU_DC099")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC101=m_inputs_map[ska_num][dcu].at("L3_DCU_DC101")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC102=m_inputs_map[ska_num][dcu].at("L3_DCU_DC102")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC103=m_inputs_map[ska_num][dcu].at("L3_DCU_DC103")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC105=m_inputs_map[ska_num][dcu].at("L3_DCU_DC105")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC106=m_inputs_map[ska_num][dcu].at("L3_DCU_DC106")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC111=m_inputs_map[ska_num][dcu].at("L3_DCU_DC111")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DC116=m_inputs_map[ska_num][dcu].at("L3_DCU_DC116")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DiagPrioA=m_inputs_map[ska_num][dcu].at("L3_DCU_DiagPrioA")                      ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L3_DCU_DiagPrioB=m_inputs_map[ska_num][dcu].at("L3_DCU_DiagPrioB")                      ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit73=m_inputs_map[ska_num][dcu].at("bit73")                  ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit74=m_inputs_map[ska_num][dcu].at("bit74")                                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit75=m_inputs_map[ska_num][dcu].at("bit75")                                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit76=m_inputs_map[ska_num][dcu].at("bit76")                                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit77=m_inputs_map[ska_num][dcu].at("bit77")                                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit78=m_inputs_map[ska_num][dcu].at("bit78")                                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit79=m_inputs_map[ska_num][dcu].at("bit79")                                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_IFESmartAssistDCU                =m_inputs_map[ska_num][dcu].at("L4_DCU_IFESmartAssistDCU")              ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_SuppEmergOp                      =m_inputs_map[ska_num][dcu].at("L4_DCU_SuppEmergOp")                    ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DoorAntiDrag                     =m_inputs_map[ska_num][dcu].at("L4_DCU_DoorAntiDrag")                   ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DoorObstDet                      =m_inputs_map[ska_num][dcu].at("L4_DCU_DoorObstDet")                    ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DoorMoveMonit                    =m_inputs_map[ska_num][dcu].at("L4_DCU_DoorMoveMonit")                  ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_EntrRel                          =m_inputs_map[ska_num][dcu].at("L4_DCU_EntrRel")                        ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DoorClosed                       =m_inputs_map[ska_num][dcu].at("L4_DCU_DoorClosed")                     ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DoorClosedAndLocked              =m_inputs_map[ska_num][dcu].at("L4_DCU_DoorClosedAndLocked")            ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DoorFullyOpen                    =m_inputs_map[ska_num][dcu].at("L4_DCU_DoorFullyOpen")                  ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DoorOutOfService                 =m_inputs_map[ska_num][dcu].at("L4_DCU_DoorOutOfService")               ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DoorUnlEmergOp                   =m_inputs_map[ska_num][dcu].at("L4_DCU_DoorUnlEmergOp")                 ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_EEDOp                            =m_inputs_map[ska_num][dcu].at("L4_DCU_EEDOp")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_EADOp                            =m_inputs_map[ska_num][dcu].at("L4_DCU_EADOp")                          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_PBOpenDLRightOutsideOp           =m_inputs_map[ska_num][dcu].at("L4_DCU_PBOpenDLRightOutsideOp")         ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_PBOpenDLRightInsideOp            =m_inputs_map[ska_num][dcu].at("L4_DCU_PBOpenDLRightInsideOp")          ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_PBPRMPortalInsideOp              =m_inputs_map[ska_num][dcu].at("L4_DCU_PBPRMPortalInsideOp")            ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_LightBarrierPortalInsideInterr   =m_inputs_map[ska_num][dcu].at("L4_DCU_LightBarrierPortalInsideInterr") ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_OutputTIL1                       =m_inputs_map[ska_num][dcu].at("L4_DCU_OutputTIL1")                     ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC001=m_inputs_map[ska_num][dcu].at("L4_DCU_DC001");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC002=m_inputs_map[ska_num][dcu].at("L4_DCU_DC002");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC003=m_inputs_map[ska_num][dcu].at("L4_DCU_DC003");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC004=m_inputs_map[ska_num][dcu].at("L4_DCU_DC004");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC005=m_inputs_map[ska_num][dcu].at("L4_DCU_DC005");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC006=m_inputs_map[ska_num][dcu].at("L4_DCU_DC006");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC007=m_inputs_map[ska_num][dcu].at("L4_DCU_DC007");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC008=m_inputs_map[ska_num][dcu].at("L4_DCU_DC008");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC009=m_inputs_map[ska_num][dcu].at("L4_DCU_DC009");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC010=m_inputs_map[ska_num][dcu].at("L4_DCU_DC010");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC013=m_inputs_map[ska_num][dcu].at("L4_DCU_DC013");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC014=m_inputs_map[ska_num][dcu].at("L4_DCU_DC014");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC015=m_inputs_map[ska_num][dcu].at("L4_DCU_DC015");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC016=m_inputs_map[ska_num][dcu].at("L4_DCU_DC016");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC017=m_inputs_map[ska_num][dcu].at("L4_DCU_DC017");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC018=m_inputs_map[ska_num][dcu].at("L4_DCU_DC018");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC019=m_inputs_map[ska_num][dcu].at("L4_DCU_DC019");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC020=m_inputs_map[ska_num][dcu].at("L4_DCU_DC020");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC021=m_inputs_map[ska_num][dcu].at("L4_DCU_DC021");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC022=m_inputs_map[ska_num][dcu].at("L4_DCU_DC022");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC027=m_inputs_map[ska_num][dcu].at("L4_DCU_DC027");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC028=m_inputs_map[ska_num][dcu].at("L4_DCU_DC028");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC029=m_inputs_map[ska_num][dcu].at("L4_DCU_DC029");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC030=m_inputs_map[ska_num][dcu].at("L4_DCU_DC030");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC031=m_inputs_map[ska_num][dcu].at("L4_DCU_DC031");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC033=m_inputs_map[ska_num][dcu].at("L4_DCU_DC033");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC037=m_inputs_map[ska_num][dcu].at("L4_DCU_DC037");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC042=m_inputs_map[ska_num][dcu].at("L4_DCU_DC042");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC043=m_inputs_map[ska_num][dcu].at("L4_DCU_DC043");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC044=m_inputs_map[ska_num][dcu].at("L4_DCU_DC044");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC046=m_inputs_map[ska_num][dcu].at("L4_DCU_DC046");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC048=m_inputs_map[ska_num][dcu].at("L4_DCU_DC048");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC049=m_inputs_map[ska_num][dcu].at("L4_DCU_DC049");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC050=m_inputs_map[ska_num][dcu].at("L4_DCU_DC050");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC051=m_inputs_map[ska_num][dcu].at("L4_DCU_DC051");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC052=m_inputs_map[ska_num][dcu].at("L4_DCU_DC052");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC053=m_inputs_map[ska_num][dcu].at("L4_DCU_DC053");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC065=m_inputs_map[ska_num][dcu].at("L4_DCU_DC065");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC066=m_inputs_map[ska_num][dcu].at("L4_DCU_DC066");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC067=m_inputs_map[ska_num][dcu].at("L4_DCU_DC067");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC068=m_inputs_map[ska_num][dcu].at("L4_DCU_DC068");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC069=m_inputs_map[ska_num][dcu].at("L4_DCU_DC069");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC090=m_inputs_map[ska_num][dcu].at("L4_DCU_DC090");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC091=m_inputs_map[ska_num][dcu].at("L4_DCU_DC091");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC098=m_inputs_map[ska_num][dcu].at("L4_DCU_DC098");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC099=m_inputs_map[ska_num][dcu].at("L4_DCU_DC099");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC101=m_inputs_map[ska_num][dcu].at("L4_DCU_DC101");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC102=m_inputs_map[ska_num][dcu].at("L4_DCU_DC102");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC103=m_inputs_map[ska_num][dcu].at("L4_DCU_DC103");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC105=m_inputs_map[ska_num][dcu].at("L4_DCU_DC105");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC106=m_inputs_map[ska_num][dcu].at("L4_DCU_DC106");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC111=m_inputs_map[ska_num][dcu].at("L4_DCU_DC111");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DC116=m_inputs_map[ska_num][dcu].at("L4_DCU_DC116");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DiagPrioA=m_inputs_map[ska_num][dcu].at("L4_DCU_DiagPrioA")                      ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.L4_DCU_DiagPrioB=m_inputs_map[ska_num][dcu].at("L4_DCU_DiagPrioB")                      ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit153=m_inputs_map[ska_num][dcu].at("bit153")                  ;
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit154=m_inputs_map[ska_num][dcu].at("bit154");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit155=m_inputs_map[ska_num][dcu].at("bit155");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit156=m_inputs_map[ska_num][dcu].at("bit156");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit157=m_inputs_map[ska_num][dcu].at("bit157");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit158=m_inputs_map[ska_num][dcu].at("bit158");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.bit159=m_inputs_map[ska_num][dcu].at("bit159");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_20=m_inputs_map[ska_num][dcu].at("reserved_20");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_21=m_inputs_map[ska_num][dcu].at("reserved_21");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_22=m_inputs_map[ska_num][dcu].at("reserved_22");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_23=m_inputs_map[ska_num][dcu].at("reserved_23");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_24=m_inputs_map[ska_num][dcu].at("reserved_24");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_25=m_inputs_map[ska_num][dcu].at("reserved_25");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_26=m_inputs_map[ska_num][dcu].at("reserved_26");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_27=m_inputs_map[ska_num][dcu].at("reserved_27");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_28=m_inputs_map[ska_num][dcu].at("reserved_28");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_29=m_inputs_map[ska_num][dcu].at("reserved_29");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_30=m_inputs_map[ska_num][dcu].at("reserved_30");
m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb4_dcu3.bits.reserved_31=m_inputs_map[ska_num][dcu].at("reserved_31");
}



void SKA_DCU::init_ska_x_mvb4_dcu3_table(SKA_VEHICLE_NUM vehicle_type)
{
    int ska_num = static_cast<int>(vehicle_type);
    m_inputs_map[ska_num][DCU3] = {
    {"L3_DCU_IFESmartAssistDCU", 0},
    {"L3_DCU_SuppEmergOp", 0},
    {"L3_DCU_DoorAntiDrag", 0},
    {"L3_DCU_DoorObstDet", 0},
    {"L3_DCU_DoorMoveMonit", 0},
    {"L3_DCU_EntrRel", 0},
    {"L3_DCU_DoorClosed", 0},
    {"L3_DCU_DoorClosedAndLocked", 0},
    {"L3_DCU_DoorFullyOpen", 0},
    {"L3_DCU_DoorOutOfService", 0},
    {"L3_DCU_DoorUnlEmergOp", 0},
    {"L3_DCU_EEDOp", 0},
    {"L3_DCU_EADOp", 0},
    {"L3_DCU_PBOpenDLRightOutsideOp", 0},
    {"L3_DCU_PBOpenDLRightInsideOp", 0},
    {"L3_DCU_PBPRMPortalInsideOp", 0},
    {"L3_DCU_LightBarrierPortalInsideInterr", 0},
    {"L3_DCU_OutputTIL1", 0},
    {"L3_DCU_DC001", 0},
    {"L3_DCU_DC002", 0},
    {"L3_DCU_DC003", 0},
    {"L3_DCU_DC004", 0},
    {"L3_DCU_DC005", 0},
    {"L3_DCU_DC006", 0},
    {"L3_DCU_DC007", 0},
    {"L3_DCU_DC008", 0},
    {"L3_DCU_DC009", 0},
    {"L3_DCU_DC010", 0},
    {"L3_DCU_DC013", 0},
    {"L3_DCU_DC014", 0},
    {"L3_DCU_DC015", 0},
    {"L3_DCU_DC016", 0},
    {"L3_DCU_DC017", 0},
    {"L3_DCU_DC018", 0},
    {"L3_DCU_DC019", 0},
    {"L3_DCU_DC020", 0},
    {"L3_DCU_DC021", 0},
    {"L3_DCU_DC022", 0},
    {"L3_DCU_DC027", 0},
    {"L3_DCU_DC028", 0},
    {"L3_DCU_DC029", 0},
    {"L3_DCU_DC030", 0},
    {"L3_DCU_DC031", 0},
    {"L3_DCU_DC033", 0},
    {"L3_DCU_DC037", 0},
    {"L3_DCU_DC042", 0},
    {"L3_DCU_DC043", 0},
    {"L3_DCU_DC044", 0},
    {"L3_DCU_DC046", 0},
    {"L3_DCU_DC048", 0},
    {"L3_DCU_DC049", 0},
    {"L3_DCU_DC050", 0},
    {"L3_DCU_DC051", 0},
    {"L3_DCU_DC052", 0},
    {"L3_DCU_DC053", 0},
    {"L3_DCU_DC065", 0},
    {"L3_DCU_DC066", 0},
    {"L3_DCU_DC067", 0},
    {"L3_DCU_DC068", 0},
    {"L3_DCU_DC069", 0},
    {"L3_DCU_DC090", 0},
    {"L3_DCU_DC091", 0},
    {"L3_DCU_DC098", 0},
    {"L3_DCU_DC099", 0},
    {"L3_DCU_DC101", 0},
    {"L3_DCU_DC102", 0},
    {"L3_DCU_DC103", 0},
    {"L3_DCU_DC105", 0},
    {"L3_DCU_DC106", 0},
    {"L3_DCU_DC111", 0},
    {"L3_DCU_DC116", 0},
    {"L3_DCU_DiagPrioA", 0},
    {"L3_DCU_DiagPrioB", 0},
    {"bit73", 0},
    {"bit74", 0},
    {"bit75", 0},
    {"bit76", 0},
    {"bit77", 0},
    {"bit78", 0},
    {"bit79", 0},
    {"L4_DCU_IFESmartAssistDCU", 0},
    {"L4_DCU_SuppEmergOp", 0},
    {"L4_DCU_DoorAntiDrag", 0},
    {"L4_DCU_DoorObstDet", 0},
    {"L4_DCU_DoorMoveMonit", 0},
    {"L4_DCU_EntrRel", 0},
    {"L4_DCU_DoorClosed", 0},
    {"L4_DCU_DoorClosedAndLocked", 0},
    {"L4_DCU_DoorFullyOpen", 0},
    {"L4_DCU_DoorOutOfService", 0},
    {"L4_DCU_DoorUnlEmergOp", 0},
    {"L4_DCU_EEDOp", 0},
    {"L4_DCU_EADOp", 0},
    {"L4_DCU_PBOpenDLRightOutsideOp", 0},
    {"L4_DCU_PBOpenDLRightInsideOp", 0},
    {"L4_DCU_PBPRMPortalInsideOp", 0},
    {"L4_DCU_LightBarrierPortalInsideInterr", 0},
    {"L4_DCU_OutputTIL1", 0},
    {"L4_DCU_DC001", 0},
    {"L4_DCU_DC002", 0},
    {"L4_DCU_DC003", 0},
    {"L4_DCU_DC004", 0},
    {"L4_DCU_DC005", 0},
    {"L4_DCU_DC006", 0},
    {"L4_DCU_DC007", 0},
    {"L4_DCU_DC008", 0},
    {"L4_DCU_DC009", 0},
    {"L4_DCU_DC010", 0},
    {"L4_DCU_DC013", 0},
    {"L4_DCU_DC014", 0},
    {"L4_DCU_DC015", 0},
    {"L4_DCU_DC016", 0},
    {"L4_DCU_DC017", 0},
    {"L4_DCU_DC018", 0},
    {"L4_DCU_DC019", 0},
    {"L4_DCU_DC020", 0},
    {"L4_DCU_DC021", 0},
    {"L4_DCU_DC022", 0},
    {"L4_DCU_DC027", 0},
    {"L4_DCU_DC028", 0},
    {"L4_DCU_DC029", 0},
    {"L4_DCU_DC030", 0},
    {"L4_DCU_DC031", 0},
    {"L4_DCU_DC033", 0},
    {"L4_DCU_DC037", 0},
    {"L4_DCU_DC042", 0},
    {"L4_DCU_DC043", 0},
    {"L4_DCU_DC044", 0},
    {"L4_DCU_DC046", 0},
    {"L4_DCU_DC048", 0},
    {"L4_DCU_DC049", 0},
    {"L4_DCU_DC050", 0},
    {"L4_DCU_DC051", 0},
    {"L4_DCU_DC052", 0},
    {"L4_DCU_DC053", 0},
    {"L4_DCU_DC065", 0},
    {"L4_DCU_DC066", 0},
    {"L4_DCU_DC067", 0},
    {"L4_DCU_DC068", 0},
    {"L4_DCU_DC069", 0},
    {"L4_DCU_DC090", 0},
    {"L4_DCU_DC091", 0},
    {"L4_DCU_DC098", 0},
    {"L4_DCU_DC099", 0},
    {"L4_DCU_DC101", 0},
    {"L4_DCU_DC102", 0},
    {"L4_DCU_DC103", 0},
    {"L4_DCU_DC105", 0},
    {"L4_DCU_DC106", 0},
    {"L4_DCU_DC111", 0},
    {"L4_DCU_DC116", 0},
    {"L4_DCU_DiagPrioA", 0},
    {"L4_DCU_DiagPrioB", 0},
    {"bit153", 0},
    {"bit154", 0},
    {"bit155", 0},
    {"bit156", 0},
    {"bit157", 0},
    {"bit158", 0},
    {"bit159", 0},
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
    {"reserved_31", 0}

    };

    /*m_tableWidget[ska_num][DCU3] = new QTableWidget();
    m_tableWidget[ska_num][DCU3]->setColumnCount(2);
    m_tableWidget[ska_num][DCU3]->setRowCount(m_inputs_map[ska_num][DCU3].size());
    m_tableWidget[ska_num][DCU3]->setHorizontalHeaderLabels(table_name[ska_num][DCU3]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[ska_num][DCU3]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[ska_num][DCU3]->setItem(row, 0, item_name);
        m_tableWidget[ska_num][DCU3]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[ska_num][DCU3]->resizeColumnsToContents();*/

    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[ska_num][DCU3].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[ska_num][DCU3] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[ska_num][DCU3]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[ska_num][DCU3]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[ska_num][DCU3]->setItem(row, column, item_name);
        m_tableWidget[ska_num][DCU3]->setItem(row, column + 1, item_val); // Değer

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[ska_num][DCU3]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][DCU3]->columnCount() ;
}


void SKA_DCU::update_dcu4_map(SKA_VEHICLE_NUM ska_x_num, DCU_LIST dcu)
{
    int ska_num = static_cast<int>(ska_x_num);

    m_inputs_map[ska_num][dcu].at("Door_Number")               =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.Door_Number;
    m_inputs_map[ska_num][dcu].at("reserved1")               =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.reserved1;
    m_inputs_map[ska_num][dcu].at("DCU_CycleCounter_Byte_1")  =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.DCU_CycleCounter_Byte_1;
    m_inputs_map[ska_num][dcu].at("DCU_CycleCounter_Byte_2")  =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.DCU_CycleCounter_Byte_2;
    m_inputs_map[ska_num][dcu].at("DCU_CycleCounter_Byte_3")  =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.DCU_CycleCounter_Byte_3;
    m_inputs_map[ska_num][dcu].at("reserved_5")                    =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.reserved_5;
    m_inputs_map[ska_num][dcu].at("DCU_SWVer_Char_1")         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.DCU_SWVer_Char_1;
    m_inputs_map[ska_num][dcu].at("DCU_SWVer_Char_2")         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.DCU_SWVer_Char_2;
    m_inputs_map[ska_num][dcu].at("DCU_SWVer_Char_3")         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.DCU_SWVer_Char_3;
    m_inputs_map[ska_num][dcu].at("DCU_SWVer_Char_4")         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.DCU_SWVer_Char_4;
    m_inputs_map[ska_num][dcu].at("DCU_SWVer_Char_5")         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.DCU_SWVer_Char_5;
    m_inputs_map[ska_num][dcu].at("DCU_SWVer_Char_6")         =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.DCU_SWVer_Char_6;
    m_inputs_map[ska_num][dcu].at("reserved_12")                   =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.reserved_12;
    m_inputs_map[ska_num][dcu].at("reserved_13")                   =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.reserved_13;
    m_inputs_map[ska_num][dcu].at("reserved_14")                   =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.reserved_14;
    m_inputs_map[ska_num][dcu].at("reserved_15")                   =m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.reserved_15;

}

void SKA_DCU::update_struct_with_map(SKA_VEHICLE_NUM ska_x_num, DCU_LIST DCU_NUM)
{
    int ska_num = static_cast<int>(ska_x_num);
    // Define a lambda function to reduce redundancy
    auto setInputMap = [&](const QString& signal_name) {
        m_inputs_map[ska_num][DCU_NUM][signal_name] = utils::getTableWidgetValueByNameWithoutColumn(m_tableWidget[ska_num][DCU_NUM], signal_name).toInt();
    };
    // update map with given tableWidget values
    for(const auto& map : m_inputs_map[ska_num][DCU_NUM])
    {
        setInputMap(map.first);
    }
    // set struct parameters with given updated map parameters
    set_struct_dcu1(ska_x_num, DCU1);
    set_struct_dcu2(ska_x_num, DCU2);
    set_struct_dcu3(ska_x_num, DCU3);
    set_struct_dcu4(ska_x_num, DCU4);
}

void SKA_DCU::set_struct_dcu4(SKA_VEHICLE_NUM ska_x_num, DCU_LIST dcu)
{
    int ska_num = static_cast<int>(ska_x_num);
    m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.Door_Number=m_inputs_map[ska_num][dcu].at("Door_Number");
    m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.reserved1=m_inputs_map[ska_num][dcu].at("reserved1");
    m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.DCU_CycleCounter_Byte_1=m_inputs_map[ska_num][dcu].at("DCU_CycleCounter_Byte_1");
    m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.DCU_CycleCounter_Byte_2=m_inputs_map[ska_num][dcu].at("DCU_CycleCounter_Byte_2");
    m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.DCU_CycleCounter_Byte_3=m_inputs_map[ska_num][dcu].at("DCU_CycleCounter_Byte_3");
    m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.reserved_5=m_inputs_map[ska_num][dcu].at("reserved_5");
    m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.DCU_SWVer_Char_1=m_inputs_map[ska_num][dcu].at("DCU_SWVer_Char_1");
    m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.DCU_SWVer_Char_2=m_inputs_map[ska_num][dcu].at("DCU_SWVer_Char_2");
    m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.DCU_SWVer_Char_3=m_inputs_map[ska_num][dcu].at("DCU_SWVer_Char_3");
    m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.DCU_SWVer_Char_4=m_inputs_map[ska_num][dcu].at("DCU_SWVer_Char_4");
    m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.DCU_SWVer_Char_5=m_inputs_map[ska_num][dcu].at("DCU_SWVer_Char_5");
    m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.DCU_SWVer_Char_6=m_inputs_map[ska_num][dcu].at("DCU_SWVer_Char_6");
    m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.reserved_12=m_inputs_map[ska_num][dcu].at("reserved_12");
    m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.reserved_13=m_inputs_map[ska_num][dcu].at("reserved_13");
    m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.reserved_14=m_inputs_map[ska_num][dcu].at("reserved_14");
    m_ska_x_dcu[ska_num].ska_vh_riom_ccu_mvb5_dcu4.bits.reserved_15=m_inputs_map[ska_num][dcu].at("reserved_15");
}


void SKA_DCU::init_ska_x_mvb5_dcu4_table(SKA_VEHICLE_NUM vehicle_type)
{
    int ska_num = static_cast<int>(vehicle_type);
    m_inputs_map[ska_num][DCU4] = {
        {"Door_Number", 0},
        {"reserved1", 0},
        {"DCU_CycleCounter_Byte_1", 0},
        {"DCU_CycleCounter_Byte_2", 0},
        {"DCU_CycleCounter_Byte_3", 0},
        {"reserved_5", 0},
        {"DCU_SWVer_Char_1", 0},
        {"DCU_SWVer_Char_2", 0},
        {"DCU_SWVer_Char_3", 0},
        {"DCU_SWVer_Char_4", 0},
        {"DCU_SWVer_Char_5", 0},
        {"DCU_SWVer_Char_6", 0},
        {"reserved_12", 0},
        {"reserved_13", 0},
        {"reserved_14", 0},
        {"reserved_15", 0},
    };

    /*m_tableWidget[ska_num][DCU4] = new QTableWidget();
    m_tableWidget[ska_num][DCU4]->setColumnCount(2);
    m_tableWidget[ska_num][DCU4]->setRowCount(m_inputs_map[ska_num][DCU4].size());
    m_tableWidget[ska_num][DCU4]->setHorizontalHeaderLabels(table_name[ska_num][DCU4]);

    int row = 0;
    for (const auto& pair:  m_inputs_map[ska_num][DCU4]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first);// name of parameter
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // value of param
        m_tableWidget[ska_num][DCU4]->setItem(row, 0, item_name);
        m_tableWidget[ska_num][DCU4]->setItem(row, 1, item_val);
        //m_tableWidget->item(row, 0)->setText(QString(pair.first));
        //m_tableWidget->item(row, 1)->setText(QString(pair.second));
        ++row;
    }
    // Resize the table widget contents
    m_tableWidget[ska_num][DCU4]->resizeColumnsToContents();*/

    int numColumns = 8; // Sütun sayısını 8 (4 çift name-value) olarak belirleme
    int rowCount = (m_inputs_map[ska_num][DCU4].size() + numColumns/2 - 1) / (numColumns /2); // Gerekli satır sayısını hesapla

    //m_tableWidget[oa_num][MVB1]->setColumnCount(8);
    m_tableWidget[ska_num][DCU4] = new QTableWidget(rowCount, numColumns);
    m_tableWidget[ska_num][DCU4]->setHorizontalHeaderLabels({"Parameter", "Value", "Parameter", "Value","Parameter", "Value", "Parameter", "Value"}); // Başlıkları ayarla

    int row = 0;
    int column = 0; // Sütun sayacını başlat

    for (const auto& pair: m_inputs_map[ska_num][DCU4]) {
        QTableWidgetItem *item_name = new QTableWidgetItem(pair.first); // Parametre adı
        QTableWidgetItem *item_val = new QTableWidgetItem(QString("%1").arg(pair.second)); // Parametre değeri

        m_tableWidget[ska_num][DCU4]->setItem(row, column, item_name);
        m_tableWidget[ska_num][DCU4]->setItem(row, column + 1, item_val); // Değer

        // Sütun sayısını güncelle
        column += 2; // İki hücre (isim ve değer) kullandık

        // Eğer sütun sayısına ulaştıysak bir sonraki satıra geç
        if (column >= numColumns) {
            column = 0; // Sütun sayacını sıfırla
            ++row; // Bir sonraki satıra geç
        }
    }

    // Tablo içeriğini yeniden boyutlandır
    m_tableWidget[ska_num][DCU4]->resizeColumnsToContents();
    qDebug() << "SIZE of COLUMN COUNT ========== :  " << m_tableWidget[ska_num][DCU4]->columnCount() ;

}


