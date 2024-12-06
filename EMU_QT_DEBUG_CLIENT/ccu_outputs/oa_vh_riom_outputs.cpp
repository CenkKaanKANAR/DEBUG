#include "oa_vh_riom_outputs.h"

// Constructor
Oa_Vh_Riom_Outputs::Oa_Vh_Riom_Outputs(QObject *parent)
    : QObject(parent),
    m_mvb1_d(new Oa_Ccu_Vh_Riom_Mvb1_d_Outputs(this)),
    m_mvb2_dcu(new Oa_Ccu_Vh_Riom_Mvb2_Dcu(this))
{
}

// Destructor
Oa_Vh_Riom_Outputs::~Oa_Vh_Riom_Outputs()
{
    delete m_mvb1_d; // Free allocated memory for MVB1
    delete m_mvb2_dcu; // Free allocated memory for MVB2
}
