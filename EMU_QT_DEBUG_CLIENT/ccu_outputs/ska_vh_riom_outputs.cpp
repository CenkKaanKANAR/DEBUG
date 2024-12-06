#include "ska_vh_riom_outputs.h"

// Constructor
Ska_Vh_Riom_Outputs::Ska_Vh_Riom_Outputs(QObject *parent)
    : QObject(parent),
    m_mvb1_d(new Ska_ccu_vh_riom_mvb1_d(this)),
    m_mvb2_dcu(new Ska_Ccu_Vh_Riom_Mvb2_Dcu(this))
{
}

// Destructor
Ska_Vh_Riom_Outputs::~Ska_Vh_Riom_Outputs()
{
    delete m_mvb1_d; // Free allocated memory for MVB1
    delete m_mvb2_dcu; // Free allocated memory for MVB2
}

