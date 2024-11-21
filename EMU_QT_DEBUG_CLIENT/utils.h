#ifndef UTILS_H
#define UTILS_H
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <cstring>
#include <vector>
#include <QGraphicsColorizeEffect>
#include <QTimer>
#include <QPropertyAnimation>
enum class SKA_VEHICLE_NUM{SKA1, SKA2};
enum class OA_VEHICLE_NUM{OA1, OA2};
enum class VEHICLE_NUM {
    SKA1,
    SKA2,
    OA1,
    OA2,
    ALL
};

namespace utils {
    long long get_table_item(QTableWidget * table, size_t row);
    QString get_table_item_name(QTableWidget * table, size_t row);
    bool check_if_inputs_valid(const QString& binary, QString inputTypeRange);
    void show_bytearray(QByteArray byteData, QString data_name);
    QString getTableWidgetValueByName(QTableWidget* tableWidget, const QString& cellName,int valueColumn);
    void setTableWidgetValueByName(QTableWidget* tableWidget, const QString& cellName,int valueColumn, int value);

    QString getTableWidgetValueByNameWithoutColumn(QTableWidget* tableWidget, const QString& cellName);
    void setTableWidgetValueByNameWithoutColumn(QTableWidget* tableWidget, const QString& cellName, int value);
    void addGlowEffect(QTableWidget* table, int row, int column, QColor glowColor, int durationMs);
    void addBorderBlinkEffect(QWidget* widget, int durationMs);
    SKA_VEHICLE_NUM convertToSKAVehicleNum(VEHICLE_NUM vehicle);
    OA_VEHICLE_NUM convertToOAVehicleNum(VEHICLE_NUM vehicle);
}

namespace OA_TYPE{
    enum
{
    OA1 = 0,
    OA2
};

}

#endif // UTILS_H
