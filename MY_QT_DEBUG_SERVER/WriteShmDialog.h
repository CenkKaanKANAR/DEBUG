#ifndef WRITESHMDIALOG_H
#define WRITESHMDIALOG_H

#include <QDialog>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QScrollArea>
//#include "shm_data.h"
#include "ccu_inputs.h"
#include "ccu_outputs.h"
#include <QPair>
#include <QJsonObject>
#include <QJsonDocument>
#include <QToolBar>
#include <QFileDialog>
#include "ccu_table.h"
#include "DriverDeskPanels/driverpanel.h"

namespace Ui {
class DialogWriteShm;
}

class WriteShmDialog : public QDialog
{
    Q_OBJECT
public:
    explicit WriteShmDialog(QWidget *parent = nullptr);
    ~WriteShmDialog();

    void add_tool_bar();
    void save_write_shm_json_data_for_log(const QString& jsonFileName);
    void make_signal_slot_connection();
    void centerWidgetOnScreen(QWidget *widget);
    void showWriteShmMenuOnScreen();

    CCU_Table* m_ccu_tables_menu= nullptr;

private:
    Ui::DialogWriteShm *ui;
    //IN::CCU_Inputs ccu_in;
    //OUT::CCU_Outputs ccu_out;
    QToolBar *toolBar;

    QJsonObject jsonObject;

    DriverPanel* m_DriverPanel = nullptr;
public slots:
    void stopCcuTableTimerSlot();
signals:
    void send_shared_memory_write_data(QByteArray jsondata);
    void stopCcuTableTimer();

private slots:

    void on_pushButton_open_all_tables_clicked();
    void receive_ccu_out_from_ccu_table(QByteArray bytarray);
    void on_pushButton_DriverDeskPanel_clicked();
};

#endif // WRITESHMDIALOG_H
