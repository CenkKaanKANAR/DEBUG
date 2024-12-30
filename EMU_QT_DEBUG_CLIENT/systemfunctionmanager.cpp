#include "systemfunctionmanager.h"
#include <QVBoxLayout>
#include <QHeaderView>
#include <QTableWidgetItem>

SystemFunctionManager::SystemFunctionManager(QWidget *parent)
    : QWidget(parent), udpSocket(new QUdpSocket(this)), tableWidget(new QTableWidget(this)), systemFunc1 (new SystemFunctionState())
{

    // Initialize state mapping
    stateMapping = {
        {0, "WAIT"},
        {1, "INIT"},
        {2, "RUNNING"},
        {3, "ERROR"},
        {4, "FINISHED"}
    };
    systemFunctions = {
        //{"SF1", },
        //{"SF2", },

    };


    // Initialize the table
    initializeTable();

    // Set up UDP socket
    udpSocket->bind(QHostAddress::Any, 12345);
    connect(udpSocket, &QUdpSocket::readyRead, this, &SystemFunctionManager::processPendingDatagrams);
}

SystemFunctionManager::~SystemFunctionManager() {
    delete tableWidget;
    delete udpSocket;
}

void SystemFunctionManager::initializeTable() {
    tableWidget->setColumnCount(3);
    tableWidget->setHorizontalHeaderLabels({"System Function", "Pre-State", "Current-State"});
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Add rows for system functions
    for (int i = 0; i < 5; ++i) {
        tableWidget->insertRow(i);
        tableWidget->setItem(i, 0, new QTableWidgetItem(QString("SF%1").arg(i + 1)));
        tableWidget->setItem(i,1,new QTableWidgetItem(systemFunc1->m_currentState));
        tableWidget->setItem(i,2,new QTableWidgetItem(systemFunc1->m_preState));

    }

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(tableWidget);
    setLayout(layout);
}

void SystemFunctionManager::processPendingDatagrams() {
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());

        QList<int> states;
        for (int i = 0; i < datagram.size(); ++i) {
            states.append(static_cast<int>(datagram[i]));
        }

        updateTable(states);
    }
}

void SystemFunctionManager::updateTable(const QList<int>& states) {
    for (int i = 0; i < states.size() && i < tableWidget->rowCount(); ++i) {
        QString m_currentState = stateMapping.value(states[i], "UNKNOWN");
        QString systemFunction = QString("SF%1").arg(i + 1);

        // Update pre-state
        systemFunctions[systemFunction].m_preState = systemFunctions[systemFunction].m_currentState;
        systemFunctions[systemFunction].m_currentState = systemFunctions[systemFunction].m_currentState;

        // Write to table
        tableWidget->setItem(i, 1, new QTableWidgetItem(systemFunctions[systemFunction].m_preState));
        tableWidget->setItem(i, 2, new QTableWidgetItem(systemFunctions[systemFunction].m_currentState));
    }
}

