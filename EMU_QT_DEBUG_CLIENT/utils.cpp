#include "utils.h"
#include <QDebug>


#define SET_INPUT_VALUE(ska_num, key) \
m_ska_x_vh_riom[ska_num].ska_vh_riom_ccu_mvb1_d_inputs.bits.key = m_inputs_map[ska_num][#key]

namespace utils {
    long long get_table_item(QTableWidget * table, size_t row)
    {
        return table->item(row, 1)->text().toLongLong();
    }

    bool check_if_inputs_valid(const QString& binary, QString inputTypeRange)
    {
        bool ok;
        if(inputTypeRange == "BINARY" )
        {
            if (binary == '1' || binary == '0') {
                return true;
            } else {
                //QMessageBox::warning(this, QString("Invalid value %1").arg(binary), "Input failed");
                return false;
            }
        }
        else
        {
            binary.toInt(&ok);
            if (ok) {
                return true;
            } else {

                //QMessageBox::warning(this, QString("Invalid value %1").arg(binary), "Input failed");
                return false;
            }

        }
    }

    QString get_table_item_name(QTableWidget *table, size_t row)
    {
        return table->item(row, 0)->text();
    }

    void show_bytearray(QByteArray byteData, QString data_name)
    {

        QString hexString;
        for (int i = 0; i < byteData.size(); ++i) {
            hexString.append(QString::number(static_cast<unsigned char>(byteData.at(i)), 16).rightJustified(2, '0').toUpper());
            hexString.append(' ');
        }
        qDebug() << data_name <<":"<< hexString.trimmed();

    }


    void convertQByteArrayToUint8Array(const QByteArray &qByteArray, uint8_t *uint8Array)
    {
        // QByteArray'i uint8_t dizisine dönüştürme
        const uint8_t* byteArrayData = reinterpret_cast<const uint8_t*>(qByteArray.constData());

        // Dönüştürülen uint8_t dizisini kopyalama
        for (int i = 0; i < qByteArray.size(); ++i) {
            uint8Array[i] = byteArrayData[i];
        }
    }

    void convertUint8ArrayToQByteArray(uint8_t *uint8Array, QByteArray &qByteArray , size_t byte_count)
    {
        qByteArray = QByteArray::fromRawData(reinterpret_cast<char*>(uint8Array),
                                             byte_count);
    }



    void appendModulToQByteArray(QByteArray &array, const uint8_t *data, size_t byteCount)
    {
        array.append(reinterpret_cast<const char*>(data), byteCount);
    }

    QString getTableWidgetValueByName(QTableWidget* tableWidget, const QString& cellName, int valueColumn)
    {
        QList<QTableWidgetItem*> items = tableWidget->findItems(cellName, Qt::MatchExactly);
        if (!items.isEmpty()) {
            int row = items.first()->row();
            QTableWidgetItem* valueItem = tableWidget->item(row, valueColumn);
            if (valueItem) {
                return valueItem->text();
            }
        }
        return QString(); // Hücre boşsa veya geçersizse boş bir string döner
    }

    void setTableWidgetValueByName(QTableWidget* tableWidget, const QString& cellName, int valueColumn, int value)
    {
        QList<QTableWidgetItem*> items = tableWidget->findItems(cellName, Qt::MatchExactly);
        if (!items.isEmpty()) {
            int row = items.first()->row();
            //tableWidget->setItem(row, valueColumn, new QTableWidgetItem(QString::number(value)));
            tableWidget->item(row,valueColumn )->setText(QString::number(value));
        }
        else
        {
            qDebug() << "Given: " << cellName << " cellname is not found";
        }

    }

    QString getTableWidgetValueByNameWithoutColumn(QTableWidget* tableWidget, const QString& cellName)
    {
        QList<QTableWidgetItem*> items = tableWidget->findItems(cellName, Qt::MatchExactly);


        if (!items.isEmpty()) {

            int row = items.first()->row();
            int column = items.first()->column();
            //qDebug() << "@@@ROW NUMBER IS  OUTSIDE :  " << row << " @@@COLUMN NUMBER IS  OUTSIDE : " << column;
            column++;
            QTableWidgetItem* valueItem = tableWidget->item(row, column);


            if (valueItem  && column % 2 != 0) {
                return valueItem->text();
                qDebug() << "___ROW NUMBER IS : " << row << " ___COLUMN NUMBER IS INSIDE : " << column;
            }
        }
        return QString(); // Hücre boşsa veya geçersizse boş bir string döner
    }


    void setTableWidgetValueByNameWithoutColumn(QTableWidget* tableWidget, const QString& cellName, int value)
    {
        QList<QTableWidgetItem*> items = tableWidget->findItems(cellName, Qt::MatchExactly);

        if (!items.isEmpty()) {

            int row = items.first()->row();
            int column = items.first()->column();
            //qDebug() << "@@@ROW NUMBER IS OUTSIDE : " << row << " @@@COLUMN NUMBER IS OUTSIDE : " << column;
            column++;
            //tableWidget->setItem(row, valueColumn, new QTableWidgetItem(QString::number(value)));
            if(column % 2 != 0) {

                tableWidget->item(row,column )->setText(QString::number(value));
                if( value == 1) {
                    tableWidget->item(row,column -1)->setBackground(QColor(57, 255, 20));  // Neon Yeşil
                    tableWidget->item(row,column )->setBackground(QColor(57, 255, 20));  // Neon Yeşil
                    addGlowEffect(tableWidget, row, column -1, QColor(255, 125, 100), 500);// Kısa süreli sarı parlatma (500 ms)
                    addGlowEffect(tableWidget, row, column, QColor(125, 255, 0), 500);// Kısa süreli sarı parlatma (500 ms)
                    //addGlowEffect(tableWidget->item(row,column), tableWidget, QColor(255, 255, 0), 500);
                    //addBorderBlinkEffect(tableWidget, 500);  // Kısa süreli çerçeve büyütme efekti (500 ms)
                    //addGlowEffect(QTableWidget* table, int row, int column, QColor glowColor, int durationMs)
                  }
                else {
                    tableWidget->item(row,column -1)->setBackground(QColor("turquoise"));
                    tableWidget->item(row,column )->setBackground(QColor("turquoise"));
                    //addGlowEffect(tableWidget->item(row,column -1), tableWidget, QColor(255, 255, 0), 500);// Kısa süreli sarı parlatma (500 ms)
                    //addBorderBlinkEffect(tableWidget, 500);  // Kısa süreli çerçeve büyütme efekti (500 ms)
                  }

                qDebug() << "___ROW NUMBER IS : " << row << " ___COLUMN NUMBER IS INSIDE : " << column;
            }
        }
        else
        {
            qDebug() << "Given: " << cellName << " cellname is not found";
        }

    }
    void addGlowEffect(QTableWidget* table, int row, int column, QColor glowColor, int durationMs) {
        // Hücreyi al
        QTableWidgetItem* item = table->item(row, column);
        if (!item) return;  // Eğer hücre yoksa çık

        // Hücre widget'ını al
        QWidget* cellWidget = table->cellWidget(row, column);
        if (!cellWidget) return;  // Eğer widget yoksa çık

        // Glow efekti ekle
        QGraphicsColorizeEffect* effect = new QGraphicsColorizeEffect();
        effect->setColor(glowColor);
        cellWidget->setGraphicsEffect(effect);

        // Belirtilen süre sonunda efekti kaldır
        QTimer::singleShot(durationMs, [=]() {
            cellWidget->setGraphicsEffect(nullptr);
            delete effect;
        });

        // Ekstra efekt olarak bir animasyon ekleyelim
        QPropertyAnimation* animation = new QPropertyAnimation(cellWidget, "opacity");
        animation->setDuration(durationMs);
        animation->setStartValue(1.0);
        animation->setEndValue(0.0);
        animation->setLoopCount(-1);  // Sonsuz döngü
        animation->setEasingCurve(QEasingCurve::InOutSine);
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }


    /*void addBorderBlinkEffect(QWidget* widget, int durationMs) {
        QPropertyAnimation* animation = new QPropertyAnimation(widget, "geometry");
        QRect originalGeometry = widget->geometry();
        QRect expandedGeometry = originalGeometry.adjusted(-2, -2, 2, 2);  // Çerçeveyi büyüt

        animation->setDuration(durationMs);
        animation->setStartValue(originalGeometry);
        animation->setKeyValueAt(0.5, expandedGeometry);
        animation->setEndValue(originalGeometry);
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }*/

}



