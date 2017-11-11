#ifndef MASTEREVENTBROKER_H
#define MASTEREVENTBROKER_H

#include "signal.h"
#include "property.h"

class MasterEventBroker
{
public:
    MasterEventBroker();

    Property<float> Position_X = 0;
    Property<float> Position_Y = 0;

    Signal<float> Position_YUP;
    Signal<float> Position_YDOWN;
    Signal<float> Position_XUP;
    Signal<float> Position_XDOWN;

};

#endif // MASTEREVENTBROKER_H
