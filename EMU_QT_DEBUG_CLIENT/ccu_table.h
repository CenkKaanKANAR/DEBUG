#ifndef CCU_TABLE_H
#define CCU_TABLE_H

#include <QWidget>
#include "ccu_inputs.h"
#include "ccu_outputs.h"
#include "forcecontrol.h"
#include "frcconfig.h"
#include "messageconfig.h"
#include <QStackedWidget>
#include <QMessageBox>
#include <QTimer>
#include "DriverDeskPanels/switch/switch.h"
#include <QTcpServer>
#include <QUdpSocket>
#include <QMessageBox>

namespace Ui {
class CCU_Table;
}

class CCU_Table : public QWidget
{
    Q_OBJECT

public:
    explicit CCU_Table(QWidget *parent = nullptr);
    ~CCU_Table();
    void applyMainwindowStyleSheetConfiguration();
    void makeSignalSlotConnection();
    void init_ccu_inputs_table();
    void init_ccu_outputs_table();
    void init_udp_message_timer(int timer_interval_msec);
    void init_current_stack_widget_index();
    void stopCcuTableTimer();
    void init_id_screen();

    void receiveUdpMessage(QByteArray data);
    void receiveUdpInMessage(QByteArray recv_data);


    void lockOtherCells(QTableWidget *table);//FORCE
    void unlockAllCells(QTableWidget *table);//FORCE
    void resetTableValues(QTableWidget *table);//FORCE
    void initializeCheckboxTableMap();//FORCE



private:
    void appendPortIDToQByteArray(QByteArray& array, uint16_t value){
        // Append the lower and upper bytes of the value to the array
        array.append(static_cast<char>(value >> 8));  // Upper byte
        array.append(static_cast<char>(value & 0xFF));  // Lower byte
    }
    void appendDataToQByteArray(QByteArray& array, const uint8_t *data, size_t byteCount){
        array.append(reinterpret_cast<const char*>(data), byteCount);
    }

    void appendEmuConfigToQByteArray(QByteArray& array, const uint8_t *data, size_t byteCount){
        array.append(reinterpret_cast<const char*>(data), byteCount);
    }
    void init_switch();
    void processSka1();

    void processSka2();
    void processOa1();
    void processOa2();
    void processAndSendData2(const uint16_t& portId, const std::vector<uint8_t>& data, const QString &debugMessage);
    void processIDScreenData();
    void setIDButtonLayout();
    void processAndSendDataForce(const uint16_t& portId, const std::vector<uint8_t>& subModuleData, const QString &debugMessage);//Force
    void setupSendDataConnections();//FORCE

public slots:
    void on_pushButton_send_shm_data_clicked();
    void sendSystemModulesToComModule();
    void on_pushButton_configurationTable_clicked();
    //void parseAndSendCombinedValue(const QByteArray &combinedValue);
    void receiveCombinedValue(const QByteArray &combinedValue);


    void onSendButtonClicked();//FORCE


    void maintenanceIDButtonClickedAction();
    void developerIDButtonClickedAction();
    void adminIDButtonClickedAction();
    void wrongIDButtonClickedAction();
    void resetIDButtonClickedAction();

    //void on_tableCellChanged(int row, int column);//FORCE
    void on_tableItemChanged(QTableWidgetItem *item); //FORCE
    //void sendDataFromCcuTableForce(); //FORCE

signals:
    void sendCommSystemPackageData(QByteArray comm_module_data);
    void backtoMainMenuSignal();
    void dataReady();

protected:
    void closeEvent(QCloseEvent *event) override;


private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_ccu_inputs_clicked();

    void onForceCheckboxToggled(int state); // Checkbox için slot bildirimi - FORCE
    void onOnOffForceControlToggled(); //FORCEEE
    void onResetButtonClicked();//FORCE RESET BUTONU

private:

    Ui::CCU_Table *ui;
    IN::CCU_Inputs* ccu_in = nullptr;
    OUT::CCU_Outputs* m_ccu_out = nullptr;
    MessageConfig * m_ConfigWidget= nullptr;
    bool sendStatusActivated = false;
    QTimer * m_timer = nullptr;
    SwitchButton * m_ldr_switch = nullptr;

    QPushButton *maintenanceIDButton;
    QPushButton *developerIDButton;
    QPushButton *adminIDButton;
    QPushButton *wrongIDButton;
    QPushButton *resetIDButton;


    //Force
    //FORCE CONFIG

    QPushButton *onOffForceControlButton;  // On/Off switch button

    QUdpSocket *forceSocket; // Force datası için özel UDP soket
    QHostAddress forceTargetAddress = QHostAddress("127.0.0.1"); // Force verisi için hedef adres
    quint16 forceTargetPort = 12345; // Force verisi için hedef port



    //Force ska1_vh_riom_outputs
    //ForceControl *forceControl1;    //Silinecek
    //Force ska2_vh_riom_outputs
    //ForceControl *forceControl2;    //Silinecek

    //Force ska1_dd_riom_outputs
    ForceControl *forceControl3;
    //Force ska2_dd_riom_outputs
    ForceControl *forceControl4;

    //Force oa1_vh_riom_outputs
    //ForceControl *forceControl5;    //Silinecek
    //Force oa2_vh_riom_outputs
    //ForceControl *forceControl6;    //Silinecek

    //Force ska_ccu_global_out_mvb1
    ForceControl *forceControl7;
    //Force ccu_to_all_bcus
    ForceControl *forceControl8;
    //Force ska_ccu_vh_riom_mvb2_dcu_hvac_fdu
    //ForceControl *forceControl9;    //Silinecek
    //Force ska1_vh_riom_outputs
    ForceControl *forceControl10;
    //Force ska2_vh_riom_outputs
    ForceControl *forceControl12;
    //Force oa1_vh_riom_outputs
    ForceControl *forceControl11;
    //Force oa2_vh_riom_outputs
    ForceControl *forceControl13;

    //Force oa1_etcs
    ForceControl *forceControl14;
    //Force oa2_etcs
    ForceControl *forceControl15;
    //Force all_etcs
    ForceControl *forceControl16;
    //ccu_to_all_tcus
    ForceControl *forceControl17;
    //ccu_to_all_apus
    ForceControl *forceControl18;


    // Iterate over all ForceControl instances to uncheck other checkboxes
    QMap<QCheckBox*, QPair<QList<QTableWidget*>, VEHICLE_NUM>> checkboxTableMap;
    //QMap<QCheckBox*, QPair<QTableWidget*, VEHICLE_NUM>> checkboxTableMap;

    FrcConfig *frcConfig;

};

#endif // CCU_TABLE_H
