#ifndef APPBASELOGIC_H
#define APPBASELOGIC_H

#include "mastereventbroker.h"
#include "logicposition.h"

class MasterAppLogic
{
public:
    MasterEventBroker *eventBroker;

    LogicPosition *logicPosition;

    MasterAppLogic();

    void setMasterEventBroker( MasterEventBroker &ev );

    void GetXUPSignal(float amount);
};

#endif // APPBASELOGIC_H
