#include "ccu_all_rioms_output.h"

// Constructor
Ccu_All_Rioms_Output::Ccu_All_Rioms_Output(QObject *parent)
    : QObject(parent),
    m_mvb1(new Ska_Ccu_To_All_Rioms_Mvb1(this)),
    m_mvb2(new Ska_Ccu_To_All_Rioms_Mvb2(this))
{
}

// Destructor
Ccu_All_Rioms_Output::~Ccu_All_Rioms_Output()
{
    delete m_mvb1; // Free allocated memory for MVB1
    delete m_mvb2; // Free allocated memory for MVB2
}
