#include "messageconfig.h"
#include "ui_messageconfig.h"
#include <QDebug>



MessageConfig::MessageConfig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageConfig),

    m_checkbox_control_button_status(false)
{
    ui->setupUi(this);
    memset(&m_emulator_config, 0, sizeof(emulator_config));
    initMessageConfigBox();
    applyMainwindowStyleSheetConfiguration();

}


MessageConfig::~MessageConfig()
{
    delete ui;
    qDebug() << "Emu MessageConfig Destructor";
}



/**
 * @brief Initializes the message configuration names.
 *
 * This function sets up the `m_message_config_names` list with predefined message configuration names.
 * These names are used to create and manage checkboxes in the user interface for configuring various
 * parameters of the emulator.
 */
void MessageConfig::initConfiguration()
{
    m_message_config_names= {
        "emul_connected",
        "emul_in_config_mode",
        "emul_ready",
        "reserved3",
        "reserved4",
        "reserved5",
        "ska_input",
        "reserved7",
        "ska1_ddinputs_m",
        "ska1_vhinputs_m",
        "ska2_ddinputs_m",
        "ska2_vhinputs_m",
        "oa1_vhinputs_m",
        "oa2_vhinputs_m",
        "ska1_dcu",
        "ska2_dcu",
        "oa1_dcu",
        "oa2_dcu",
        "ska1_fds",
        "ska2_fds",
        "ska1_hvac",
        "ska2_hvac",
        "reserved22",
        "reserved23",
        "oa1_hvac",
        "oa2_hvac",
        "ska1_papis",
        "ska2_papis",
        "ska1_ats",
        "ska2_ats",
        "ska1_bcu",
        "ska2_bcu",
        "oa1_bcu",
        "oa2_bcu",
        "oa1_etcs",
        "oa2_etcs",
        "oa1_jru",
        "oa2_jru",
        "oa1_apu",
        "oa2_apu",
        "ska1_tcu1",
        "ska1_tcu2",
        "ska2_tcu1",
        "ska2_tcu2",
        "ska1_wtbgw",
        "ska2_wtbgw",
        "ska1_hmi",
        "ska2_hmi"

    };

}



/**
 * @brief Updates the emulator configuration structure based on the state of checkboxes.
 *
 * This function reads the state of each checkbox in the `checkBoxMap` and updates the corresponding
 * bits in the `m_emulator_config` structure. Each bit in the `m_emulator_config` structure represents
 * whether a specific component is connected or active, based on the checkbox state.
 */
void MessageConfig::updateEmulatorConfigStruct()
{

}

/**
 * @brief Initializes the Message Configuration UI components.
 *
 * This function initializes the message configuration UI by creating checkboxes for each configuration
 * parameter name stored in `m_message_config_names`. These checkboxes are added to various layouts based on
 * their index. The checkboxes are connected to the `updateEmulatorConfigStruct` slot, allowing for dynamic
 * updates to the emulator configuration structure when the checkboxes are clicked. Additionally, a debug
 * message is printed when the "emul_connected" checkbox is clicked.
 */
void MessageConfig::initMessageConfigBox()
{
    initConfiguration();
    // Checkbox'ları grid layout'a eklemek için satır ve sütun sayaçları
    size_t index = 0;
    int row_ska1 = 0, col_ska1 = 0;
    int row_ska2 = 0, col_ska2 = 0;
    int row_oa1 = 0, col_oa1 = 0;
    int row_oa2 = 0, col_oa2 = 0;
    for (const auto& param_name : m_message_config_names) {
        int value = 1;

        QCheckBox *checkBox = new QCheckBox(param_name);

        checkBox->setChecked(value);
        connect(checkBox,  &QCheckBox::clicked, this, &MessageConfig::updateEmulatorConfigStruct);

        if(index < 3) {
            ui->horizontalLayout_emu_conf->addWidget(checkBox);
            checkBox->setChecked(0);
        }
        else if(index>=3 && index <= 15)
        {
            ui->gridLayout_ska1->addWidget(checkBox, row_ska1, col_ska1);
            col_ska1++;
            if (col_ska1 == 4) { // Sütun sınırı
                col_ska1 = 0;
                row_ska1++;
            }
        }
        else if(index> 15 && index <29)
        {
            ui->gridLayout_ska2->addWidget(checkBox, row_ska2, col_ska2);
            col_ska2++;
            if (col_ska2 == 4) { // Sütun sınırı
                col_ska2 = 0;
                row_ska2++;
            }
        }
        else if(index>= 29 && index <36)
        {
            // Oa1 grubuna ekle
            ui->gridLayout_oa1->addWidget(checkBox, row_oa1, col_oa1);
            col_oa1++;
            if (col_oa1 == 4) { // Sütun sınırı
                col_oa1 = 0;
                row_oa1++;
            }
        }
        else
        {
            ui->gridLayout_oa2->addWidget(checkBox, row_oa2, col_oa2);
            col_oa2++;
            if (col_oa2 == 4) { // Sütun sınırı
                col_oa2 = 0;
                row_oa2++;
            }
        }


        checkBoxMap.insert(param_name, checkBox); // CheckBox'ları adlarına göre haritada sakla
        index++;

    }

    connect(checkBoxMap["emul_connected"],  &QCheckBox::clicked, this, [=](){
        qDebug() <<"emul_connected:"<< checkBoxMap["emul_connected"]->isChecked();
    });
    /*
    for (auto i =checkBoxMap.cbegin(), end = checkBoxMap.cend(); i != end; ++i)
        qDebug() << qPrintable(i.key()) << ": " << i.value() << endl;
        */


}


emulator_config MessageConfig::getMessageConfigStruct()
{

    return m_emulator_config;
}

void MessageConfig::setMessageConfigStruct(QByteArray recv_data)
{
    // Gelen veri en az 6 byte içeriyor mu kontrol edin
    if (recv_data.size() >= 6) {


        // İlk 6 byte'ı config.bytes dizisine kopyalayın
        memcpy(this->m_emulator_config.bytes, recv_data.data(), 6);

        // İlk 6 byte'ın atanmasını kontrol için çıktıyı gösterin
        for (int i = 0; i < 6; ++i) {
            qDebug() << "Byte" << i << ":" << static_cast<int>(this->m_emulator_config.bytes[i]);
        }

        qDebug() << "First 6 bytes CONFIG (hex):" << recv_data.toHex(' ').toUpper();
    } else {
        qWarning() << "Gelen veri 6 byte'tan az.";
    }
}



/**
 * @brief Updates the checked state of all checkboxes and the emulator configuration structure.
 *
 * This function iterates over all checkboxes in the `checkBoxMap` and sets their checked state
 * based on the value of `m_checkbox_control_button_status`. After updating the states of all
 * checkboxes, it calls `updateEmulatorConfigStruct` to update the emulator configuration structure
 * accordingly.
 */
void MessageConfig::update_check_states()
{
    for(auto& box : checkBoxMap)
    {
        box->setChecked(m_checkbox_control_button_status);
    }
    //updateEmulatorConfigStruct();
}

/**
 * @brief Slot for handling the check/uncheck all button click event.
 *
 * This function toggles the `m_checkbox_control_button_status` and updates the text of the
 * `pushButton_check_all` button accordingly. It then calls `update_check_states` to update
 * the checked states of all checkboxes and the emulator configuration structure.
 */
void MessageConfig::on_pushButton_check_all_clicked()
{
    qDebug() << "CHECK ALL BUTONU İÇİ" ;
    if(!m_checkbox_control_button_status)
    {
        //clear_checkBox_button->setText("uncheck all");
        ui->pushButton_check_all->setText("uncheck all");
    }
    else
    {
        //clear_checkBox_button->setText("check all");
        ui->pushButton_check_all->setText("check all");
    }
    m_checkbox_control_button_status =!m_checkbox_control_button_status;
    update_check_states();
}


void MessageConfig::applyMainwindowStyleSheetConfiguration()
{
    this->setStyleSheet(
        "QWidget { background-color: #E0E0E0; border: 1px solid #CCCCCC; border-radius: 10px;  }"
        "QPushButton { background-color: #005BBB; color: white; border-radius: 5px; padding: 10px 20px; font-size: 16px; }"
        "QPushButton:hover { background-color: #004B9B; }"
        "QTableWidget { alternate-background-color: #E0E0E0; }"
        "QGroupBox { border: 2px solid #005BBB; margin-top: 10px; }"
        "QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; padding: 0 3px; }"
        "QLineEdit {"
        "    background-color: #FFFFFF;"
        "    border: 1px solid #CCCCCC;"
        "    border-radius: 5px;"
        "    padding: 5px 10px;"
        "    font-size: 14px;"
        "    color: #333333;"
        "}"
        "QLineEdit:focus {"
        "    border: 1px solid #005BBB;"
        "    background-color: #E6F4FF;"
        "}"
        "QComboBox {"
        "    background-color: #FFFFFF;"
        "    border: 1px solid #CCCCCC;"
        "    border-radius: 5px;"
        "    padding: 5px;"
        "    font-size: 14px;"
        "    color: #333333;"
        "}"
        "QComboBox::drop-down {"
        "    subcontrol-origin: padding;"
        "    subcontrol-position: top right;"
        "    width: 20px;"
        "    border-left: 1px solid #CCCCCC;"
        "}"
        "QComboBox::down-arrow {"
        "    image: url(down-arrow.png);"
        "}"
        "QComboBox QAbstractItemView {"
        "    background-color: #FFFFFF;"
        "    selection-background-color: #E6F4FF;"
        "}"

        "QTableWidget {"
        "    background-color: #FFFFFF;"
        "    alternate-background-color: #E0E0E0;"
        "    gridline-color: #CCCCCC;"
        "    font-size: 14px;"
        "    color: #333333;"
        "    selection-background-color: #E6F4FF;"
        "    selection-color: #333333;"
        "}"
        "QHeaderView::section {"
        "    background-color: #005BBB;"
        "    color: white;"
        "    padding: 4px;"
        "    border: 1px solid #CCCCCC;"
        "}"
        "QTableWidget QTableCornerButton::section {"
        "    background-color: #005BBB;"
        "}"

        "QTextEdit {"
        "    background-color: #CCCCCC;"
        "    border: 1px solid #CCCCCC;"
        "    border-radius: 5px;"
        "    padding: 10px;"
        "    font-size: 14px;"
        "    color: #333333;"
        "}"
        "QTextEdit:focus {"
        "    border: 1px solid #005BBB;"
        "    background-color: #E6F4FF;"
        "}"
        "QTabWidget::pane {"
        "    border: 1px solid #CCCCCC;"
        "    border-radius: 5px;"
        "    background-color: #F5F5F5;"
        "}"
        "QTabBar::tab {"
        "    background: #E0E0E0;"
        "    border: 1px solid #CCCCCC;"
        "    border-radius: 5px;"
        "    padding: 10px;"
        "    margin-right: 2px;"
        "}"
        "QTabBar::tab:selected {"
        "    background: #FFFFFF;"
        "    border-color: #005BBB;"
        "    color: #005BBB;"
        "}"
        "QTabBar::tab:hover {"
        "    background: #DDDDDD;"
        "}"
        "QTabBar::tab:!selected {"
        "    margin-top: 2px;"
        "}"
        "QTabWidget::tab-bar {"
        "    alignment: center;"
        "}"

        "QLabel {"
        "    color: #333333;" /* Metin rengi */
        "    font-size: 16px;" /* Metin boyutu */
        "}"

        "QLabel#specificLabel {"
        "    color: #FF0000;" /* Belirli metin rengi */
        "    font-style: italic;" /* Belirli metin stil */
        "}"

        "QLabel:hover {"
        "    background-color: #EFEFEF;" /* Arkaplan rengi değişimi */
        "}"

        "QLabel:pressed {"
        "    color: #0000FF;" /* Tıklama rengi değişimi */
        "}"

        "QCheckBox {"
        "    background-color: #FFFFFF;"
        "    border: 1px solid #CCCCCC;"
        "    border-radius: 5px;"
        "    padding: 5px;"
        "    font-size: 14px;"
        "    color: #333333;"
        "}"
        "QCheckBox::indicator {"
        "    width: 15px;"
        "    height: 15px;"
        "}"
        "QCheckBox::indicator:unchecked {"
        "    border: 1px solid #CCCCCC;"
        "    background-color: #FFFFFF;"
        "    border-radius: 3px;"
        "}"
        "QCheckBox::indicator:unchecked:hover {"
        "    border: 1px solid #999999;"
        "}"
        "QCheckBox::indicator:checked {"
        "    border: 1px solid #CCCCCC;"
        "    background-color: red;" // İçerik kırmızı olacak
        "    border-radius: 3px;"
        "}"
        "QCheckBox::indicator:checked:hover {"
        "    border: 1px solid #999999;"
        "    background-color: red;" // İçerik kırmızı olacak
        "}"
        );
}







