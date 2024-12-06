#ifndef FORCECONTROL_H
#define FORCECONTROL_H

#include <QWidget>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>


class ForceControl : public QWidget {
    Q_OBJECT

public:
    explicit ForceControl(const QString& checkboxLabel, const QString& buttonLabel, const QString& resetButtonLabel, QWidget *parent = nullptr);

    QCheckBox* getCheckBox() const;
    QPushButton* getSendButton() const;
    QPushButton* getResetButton() const;

private:
    QCheckBox *forceCheckBox;
    QPushButton *sendButton;
    QPushButton *resetButton;

    void customizeWidgets(); //Colors and image views
};

#endif // FORCECONTROL_H

