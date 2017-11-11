#include "masterAppLogic.h"
#include <QDebug>
//#include "eventmanager.h"
#include "masterGuiLogic.h"
#include "logicposition.h"
#include <functional>
#include <memory>

MasterAppLogic::MasterAppLogic()
{

    this->logicPosition = new LogicPosition();

}

void MasterAppLogic::setMasterEventBroker(MasterEventBroker &ev) {
    this->eventBroker = &ev;

    this->eventBroker->Position_XUP.connect_member(this, &MasterAppLogic::GetXUPSignal);
    this->eventBroker->Position_XDOWN.connect(
        [&](float amount) {
            //qDebug() << "Got Signal: XDOWN -> " << amount;
        this->eventBroker->Position_X.set(this->eventBroker->Position_X.get() - amount);
        }
    );
    this->eventBroker->Position_YUP.connect(
        [&](float amount) {
            //qDebug() << "Got Signal: YUP -> " << amount;
        this->eventBroker->Position_Y.set(this->eventBroker->Position_Y.get() + amount);
        }
    );
    this->eventBroker->Position_YDOWN.connect(
        [&](float amount) {
            //qDebug() << "Got Signal: YDOWN -> " << amount;
        this->eventBroker->Position_Y.set(this->eventBroker->Position_Y.get() - amount);
        }
    );
}

void MasterAppLogic::GetXUPSignal(float amount) {
    //qDebug() << "Got Signal: XUP -> " << amount;
    this->eventBroker->Position_X.set(this->eventBroker->Position_X.get() + amount);
}
