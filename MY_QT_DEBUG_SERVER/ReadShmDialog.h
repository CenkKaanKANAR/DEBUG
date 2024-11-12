#ifndef READSHMDIALOG_H
#define READSHMDIALOG_H
#include "shm_data_gaziray.h"
#include <QDialog>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QScrollArea>

#include <QPair>
#include <QJsonObject>
#include <QJsonDocument>
#include <QToolBar>
#include <QFileDialog>
#include <QWidget>
#include "ccu_outputs.h"
class CCU_Table;
namespace Ui {
class ReadShmDialog;
}

class ReadShmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReadShmDialog(QWidget *parent = nullptr);
    void applyMainwindowStyleSheetConfiguration();
    ~ReadShmDialog();

    void receive_udp_message(const QByteArray& recv_data);
    void init_ccu_out_table();

signals:
    void send_udp_message(QByteArray data);


private:
    Ui::ReadShmDialog *ui;
    CCU_Table * m_ccu_table = nullptr;
    OUT::CCU_Outputs* m_ccu_out;


};

#endif // READSHMDIALOG_H
