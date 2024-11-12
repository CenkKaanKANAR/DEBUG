#include "mainwindow.h"
#include <QStyleFactory>
#include <QApplication>
#include <QScreen>
#include "ccu_table.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    CCU_Table parser;

    a.setStyle(QStyleFactory::create("Fusion"));

    //connect(&idScreen, &IDScreen::combinedValueGenerated, &parser, &CCU_Table::parseAndSendCombinedValue);
    MainWindow w;
    w.show();
    // Pencereyi tam ekran yerine ekran boyutuna göre maksimize etme
    //w.showFullScreen();

    return a.exec();
}
