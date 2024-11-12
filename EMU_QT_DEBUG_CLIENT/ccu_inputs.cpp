#include "ccu_inputs.h"
#include <QDebug>

namespace IN {


    CCU_Inputs::CCU_Inputs(QObject *parent)
        : QObject{parent}
    {

    }

    CCU_Inputs::~CCU_Inputs()
    {
        qDebug() << "CCU_INPUTS DESTRUCTOR";

    }

}
