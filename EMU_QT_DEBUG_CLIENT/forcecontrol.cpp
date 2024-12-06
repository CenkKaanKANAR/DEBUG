#include "forcecontrol.h"

ForceControl::ForceControl(const QString& checkboxLabel, const QString& buttonLabel, const QString& resetButtonLabel, QWidget *parent)
    : QWidget(parent),
    forceCheckBox(new QCheckBox(checkboxLabel, this)),
    sendButton(new QPushButton(buttonLabel, this)),
    resetButton(new QPushButton(resetButtonLabel,this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(forceCheckBox);
    layout->addWidget(sendButton);
    layout->addWidget(resetButton);
    setLayout(layout);

    customizeWidgets(); // Özelleştirme işlemi burada çağrılır
}

void ForceControl::customizeWidgets() {
    // CheckBox stilini özelleştir
    forceCheckBox->setStyleSheet(
        "QCheckBox {"
        "    font-size: 14px;"
        "    color: #333;"
        "    spacing: 5px;"
        "}"
        "QCheckBox::indicator {"
        "    width: 20px;"
        "    height: 20px;"
        "}"
        "QCheckBox::indicator:checked {"
        "    background-color: #4CAF50;"
        "    border: 1px solid #4CAF50;"
        "}"
        "QCheckBox::indicator:unchecked {"
        "    background-color: #f44336;"
        "    border: 1px solid #f44336;"
        "}"
        );

    // Button stilini özelleştir
    sendButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #2196F3;"
        "    color: white;"
        "    border-radius: 10px;"
        "    padding: 10px 20px;"
        "    font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #0b7dda;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #1976D2;"
        "}"
        );

    // Reset Button stilini özelleştir
    resetButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #f44336;" // Kırmızı renk
        "    color: white;"
        "    border-radius: 10px;" // Yuvarlak köşeler
        "    padding: 10px 20px;"
        "    font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #e53935;" // Hover durumunda biraz daha koyu kırmızı
        "}"
        "QPushButton:pressed {"
        "    background-color: #d32f2f;" // Tıklama durumunda daha koyu kırmızı
        "}"
        );
}

QCheckBox* ForceControl::getCheckBox() const {
    return forceCheckBox;
}

QPushButton* ForceControl::getSendButton() const {
    return sendButton;
}

QPushButton *ForceControl::getResetButton() const
{
    return resetButton;
}
