#ifndef CCUTABLEHANDLER_H
#define CCUTABLEHANDLER_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QByteArray>
#include <QVBoxLayout>
class QByteArray;
namespace IN {
class CCU_Inputs;
}

namespace OUT{
class CCU_Outputs;
}


namespace Ui {
class CCU_Table;

}
class QVBoxLayout;
class CcuTableHandler
{
public:
    CcuTableHandler();

    static void processCcuInputTables(QVBoxLayout* layout, const IN::CCU_Inputs* ccu_in);
    static void processCcuInputTables(Ui::CCU_Table* ui, IN::CCU_Inputs* ccu_in);
    static void processCcuOutputTables(Ui::CCU_Table* ui, OUT::CCU_Outputs* ccu_out);
    static void handleIncomingCcuOutSystemUdpPacketes(OUT::CCU_Outputs* ccu_out, const QByteArray& recv_data);
    static void handleIncomingCcuInSystemUdpPacketes(IN::CCU_Inputs *ccu_in, const QByteArray& recv_data);

};

#endif // CCUTABLEHANDLER_H
