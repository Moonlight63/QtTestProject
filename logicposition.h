#ifndef LOGICPOSITION_H
#define LOGICPOSITION_H

#include "property.h"

class LogicPosition
{
public:
    LogicPosition();

    Property<float> posX = 0;
    Property<float> posY = 0;

    void updateX(float newPos);
    void updateY(float newPos);
};

#endif // LOGICPOSITION_H
