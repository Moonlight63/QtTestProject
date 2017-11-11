#ifndef APPBASELOGIC_H
#define APPBASELOGIC_H

#include "mastereventbroker.h"

class MasterAppLogic
{
public:
    MasterEventBroker *eventBroker;

    MasterAppLogic();

    void setMasterEventBroker( MasterEventBroker &ev );

    void GetXUPSignal(float amount);
};

#endif // APPBASELOGIC_H
