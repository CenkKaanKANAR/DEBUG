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
                              "ska_di_card",
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
    qDebug() << "updateEmulatorConfigStruct() İÇİ" ;
    m_emulator_config.bits.emul_connected       = checkBoxMap["emul_connected"]->isChecked() ? 1 : 0;
    qDebug() << "updateEmulatorConfigStruct() VARAN 1" ;
    m_emulator_config.bits.emul_in_config_mode  = checkBoxMap["emul_in_config_mode"]->isChecked() ? 1 : 0;
    qDebug() << "updateEmulatorConfigStruct() VARAN 31" ;
    m_emulator_config.bits.emul_ready           = checkBoxMap["emul_ready"]->isChecked() ? 1 : 0;
    qDebug() << "updateEmulatorConfigStruct() VARAN 32" ;
    m_emulator_config.bits.reserved3            = checkBoxMap["reserved3"]->isChecked() ? 1 : 0;
    qDebug() << "updateEmulatorConfigStruct() VARAN 2" ;
    m_emulator_config.bits.reserved4            = checkBoxMap["reserved4"]->isChecked() ? 1 : 0;
    m_emulator_config.bits.reserved5            = checkBoxMap["reserved5"]->isChecked() ? 1 : 0;
    m_emulator_config.bits.ska_di_card          = checkBoxMap["ska_di_card"]->isChecked() ? 1 : 0;
    m_emulator_config.bits.reserved7            = checkBoxMap["reserved7"]->isChecked() ? 1 : 0;
    qDebug() << "updateEmulatorConfigStruct() VARAN 3" ;
    m_emulator_config.bits.ska1_ddinputs_m      = checkBoxMap["ska1_ddinputs_m"]->isChecked()? 1 : 0;
    m_emulator_config.bits.ska1_vhinputs_m      = checkBoxMap["ska1_vhinputs_m"]->isChecked()? 1 : 0;
    m_emulator_config.bits.ska2_ddinputs_m      = checkBoxMap["ska2_ddinputs_m"]->isChecked()? 1 : 0;
    m_emulator_config.bits.ska2_vhinputs_m      = checkBoxMap["ska2_vhinputs_m"]->isChecked()? 1 : 0;
    m_emulator_config.bits.oa1_vhinputs_m       = checkBoxMap["oa1_vhinputs_m"]->isChecked()? 1 : 0;
    m_emulator_config.bits.oa2_vhinputs_m       = checkBoxMap["oa2_vhinputs_m"]->isChecked()? 1 : 0;
    m_emulator_config.bits.ska1_dcu             = checkBoxMap["ska1_dcu"]->isChecked()? 1 : 0;
    qDebug() << "updateEmulatorConfigStruct() ORTALAR" ;
    m_emulator_config.bits.ska2_dcu             = checkBoxMap["ska2_dcu"]->isChecked()? 1 : 0;
    m_emulator_config.bits.oa1_dcu              = checkBoxMap["oa1_dcu"]->isChecked()? 1 : 0;
    m_emulator_config.bits.oa2_dcu              = checkBoxMap["oa2_dcu"]->isChecked()? 1 : 0;
    m_emulator_config.bits.ska1_fds             = checkBoxMap["ska1_fds"]->isChecked()? 1 : 0;
    m_emulator_config.bits.ska2_fds             = checkBoxMap["ska2_fds"]->isChecked()? 1 : 0;
    m_emulator_config.bits.ska1_hvac            = checkBoxMap["ska1_hvac"]->isChecked()? 1 : 0;
    m_emulator_config.bits.ska2_hvac            = checkBoxMap["ska2_hvac"]->isChecked()? 1 : 0;
    m_emulator_config.bits.reserved22           = checkBoxMap["reserved22"]->isChecked() ? 1 : 0;
    m_emulator_config.bits.reserved23           = checkBoxMap["reserved23"]->isChecked() ? 1 : 0;
    m_emulator_config.bits.oa1_hvac             = checkBoxMap["oa1_hvac"]->isChecked()? 1 : 0;
    m_emulator_config.bits.oa2_hvac             = checkBoxMap["oa2_hvac"]->isChecked()? 1 : 0;
    m_emulator_config.bits.ska1_papis           = checkBoxMap["ska1_papis"]->isChecked()? 1 : 0;
    m_emulator_config.bits.ska2_papis           = checkBoxMap["ska2_papis"]->isChecked()? 1 : 0;
    m_emulator_config.bits.ska1_ats             = checkBoxMap["ska1_ats"]->isChecked()? 1 : 0;
    m_emulator_config.bits.ska2_ats             = checkBoxMap["ska2_ats"]->isChecked()? 1 : 0;
    qDebug() << "updateEmulatorConfigStruct() ARALAR ORTALAR" ;
    m_emulator_config.bits.ska1_bcu             = checkBoxMap["ska1_bcu"]->isChecked()? 1 : 0;
    m_emulator_config.bits.ska2_bcu             = checkBoxMap["ska2_bcu"]->isChecked()? 1 : 0;
    m_emulator_config.bits.oa1_bcu              = checkBoxMap["oa1_bcu"]->isChecked()? 1 : 0;
    m_emulator_config.bits.oa2_bcu              = checkBoxMap["oa2_bcu"]->isChecked()? 1 : 0;
    m_emulator_config.bits.oa1_etcs             = checkBoxMap["oa1_etcs"]->isChecked()? 1 : 0;
    m_emulator_config.bits.oa2_etcs             = checkBoxMap["oa2_etcs"]->isChecked()? 1 : 0;
    m_emulator_config.bits.oa1_jru              = checkBoxMap["oa1_jru"]->isChecked()? 1 : 0;
    m_emulator_config.bits.oa2_jru              = checkBoxMap["oa2_jru"]->isChecked()? 1 : 0;
    m_emulator_config.bits.oa1_apu              = checkBoxMap["oa1_apu"]->isChecked()? 1 : 0;
    m_emulator_config.bits.oa2_apu              = checkBoxMap["oa2_apu"]->isChecked()? 1 : 0;
    m_emulator_config.bits.ska1_tcu1            = checkBoxMap["ska1_tcu1"]->isChecked()? 1 : 0;
    m_emulator_config.bits.ska1_tcu2            = checkBoxMap["ska1_tcu2"]->isChecked()? 1 : 0;
    m_emulator_config.bits.ska2_tcu1            = checkBoxMap["ska2_tcu1"]->isChecked()? 1 : 0;
    m_emulator_config.bits.ska2_tcu2            = checkBoxMap["ska2_tcu2"]->isChecked()? 1 : 0;
    m_emulator_config.bits.ska1_wtbgw           = checkBoxMap["ska1_wtbgw"]->isChecked()? 1 : 0;
    m_emulator_config.bits.ska2_wtbgw           = checkBoxMap["ska2_wtbgw"]->isChecked()? 1 : 0;
    m_emulator_config.bits.ska1_hmi             = checkBoxMap["ska1_hmi"]->isChecked()? 1 : 0;
    m_emulator_config.bits.ska2_hmi             = checkBoxMap["ska2_hmi"]->isChecked()? 1 : 0;
     qDebug() << "updateEmulatorConfigStruct() SON..." ;
    //



    /*
    for (auto i =checkBoxMap.cbegin(), end = checkBoxMap.cend(); i != end; ++i)
        qDebug() << qPrintable(i.key()) << ": " << i.value() << endl;
        */

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
    qDebug() << "UPDATE CHECK STATES İÇİ" ;
    for(auto& box : checkBoxMap)
    {
        box->setChecked(m_checkbox_control_button_status);
    }
    updateEmulatorConfigStruct();
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







