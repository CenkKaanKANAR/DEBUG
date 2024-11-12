#ifndef CCU_TABLE_H
#define CCU_TABLE_H

#include <QWidget>
#include "ccu_inputs.h"
#include "ccu_outputs.h"
#include "messageconfig.h"
#include <QStackedWidget>
#include <QMessageBox>
#include <QTimer>
#include "DriverDeskPanels/switch/switch.h"

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


public slots:
    void on_pushButton_send_shm_data_clicked();
    void sendSystemModulesToComModule();
    void on_pushButton_configurationTable_clicked();
    //void parseAndSendCombinedValue(const QByteArray &combinedValue);
    void receiveCombinedValue(const QByteArray &combinedValue);

    void maintenanceIDButtonClickedAction();
    void developerIDButtonClickedAction();
    void adminIDButtonClickedAction();
    void wrongIDButtonClickedAction();
    void resetIDButtonClickedAction();
signals:
    void sendCommSystemPackageData(QByteArray comm_module_data);
    void backtoMainMenuSignal();


protected:
    void closeEvent(QCloseEvent *event) override;


private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_ccu_inputs_clicked();


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

    //QVBoxLayout* oa1_Layout_1;
    //QVBoxLayout* oa1_Layout_2;
};

#endif // CCU_TABLE_H
