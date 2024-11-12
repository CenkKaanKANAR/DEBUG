#include "WriteShmDialog.h"

#include <QFile>
#include <QMessageBox>
#include <QIntValidator>
#include "ui_WriteShmDialog.h"
#include <QDebug>
#include <QScreen>


WriteShmDialog::WriteShmDialog(QWidget *parent)
    :   QDialog{parent}, m_ccu_tables_menu (new CCU_Table()),
    ui(new Ui::DialogWriteShm)

{
    ui->setupUi(this);
    make_signal_slot_connection();
    // Ana menüyü ekranda merkeze al
    centerWidgetOnScreen(this);


}

WriteShmDialog::~WriteShmDialog()
{
    delete m_ccu_tables_menu;
    delete m_DriverPanel;
}

void WriteShmDialog::make_signal_slot_connection()
{
    connect(m_ccu_tables_menu, &CCU_Table::sendCommSystemPackageData, this, &WriteShmDialog::receive_ccu_out_from_ccu_table);
    connect(m_ccu_tables_menu, &CCU_Table::backtoMainMenuSignal, this, &WriteShmDialog::showWriteShmMenuOnScreen);

    connect(this, &WriteShmDialog::stopCcuTableTimer,  m_ccu_tables_menu, &CCU_Table::stopCcuTableTimer);

}

void WriteShmDialog::centerWidgetOnScreen(QWidget *widget)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    widget->move(screenGeometry.center() - widget->rect().center());
}

void WriteShmDialog::showWriteShmMenuOnScreen()
{
    // Ana menüyü göster
    if (m_ccu_tables_menu) {
        m_ccu_tables_menu->hide();
        //delete m_ccu_tables_menu;
        //m_ccu_tables_menu = nullptr;
    }

    if (m_DriverPanel) {
        m_DriverPanel->hide();
        //delete m_ccu_tables_menu;
        //m_ccu_tables_menu = nullptr;
    }

    this->show();
}

void WriteShmDialog::stopCcuTableTimerSlot()
{

    emit  stopCcuTableTimer();
}



void WriteShmDialog::add_tool_bar()
{
    toolBar = new QToolBar(this);
    toolBar->setMovable(false);
}



void WriteShmDialog::save_write_shm_json_data_for_log(const QString& jsonFileName)
{
    // JSON nesnesini JSON belgesine dönüştürmek
    QJsonDocument jsonDoc(jsonObject);

    // JSON belgesini dosyaya yazmak
    QFile file(jsonFileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << jsonDoc.toJson();
        file.close();
    }
}



void WriteShmDialog::on_pushButton_open_all_tables_clicked()
{

    // Ana menüyü gizle
    this->hide();

    centerWidgetOnScreen(m_ccu_tables_menu);
    m_ccu_tables_menu->show();
    //ui->verticalLayout->addWidget(m_ccu_tables_menu);


}

void WriteShmDialog::receive_ccu_out_from_ccu_table(QByteArray bytarray)
{
    emit send_shared_memory_write_data(bytarray);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






void WriteShmDialog::on_pushButton_DriverDeskPanel_clicked()
{
    this->hide();
    if(!m_DriverPanel) {
        m_DriverPanel = new DriverPanel();
        connect(m_DriverPanel, &DriverPanel::backtoMainMenuSignal, this, &WriteShmDialog::showWriteShmMenuOnScreen);

    }
    centerWidgetOnScreen(m_DriverPanel);
    m_DriverPanel->show();
}

