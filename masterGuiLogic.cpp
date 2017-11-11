#include "masterGuiLogic.h"
#include <QDebug>
#include <QString>
#include <QTimer>
#include <QTimerEvent>

MasterGuiLogic::MasterGuiLogic(QObject *parent) : QObject(parent)
{
    xPos = 0;
    yPos = 0;
}

void MasterGuiLogic::setMasterEventBroker(MasterEventBroker &ev) {
    this->eventBroker = &ev;

    this->eventBroker->Position_X.on_change().connect(
                [&](float amount) {
                    qDebug() << "POS X -> " << amount;
                });
    this->eventBroker->Position_Y.on_change().connect(
                [&](float amount) {
                    qDebug() << "POS Y -> " << amount;
                });
}

void MasterGuiLogic::timerEvent(QTimerEvent *event)
{
    qDebug() << "Timer ID:" << event->timerId();

    if(holdingYUpTimer == event->timerId()){
        yUp();
    }

    if(holdingYDownTimer == event->timerId()){
        yDown();
    }

    if(holdingXUpTimer == event->timerId()){
        xUp();
    }

    if(holdingXDownTimer == event->timerId()){
        xDown();
    }
}

void MasterGuiLogic::testComm(const QString &str) {
    qDebug() << str;
}

void MasterGuiLogic::xUp() {
    ++xPos;

    this->eventBroker->Position_XUP.post(1);
}

void MasterGuiLogic::xDown() {
    --xPos;

    this->eventBroker->Position_XDOWN.post(1);
}

void MasterGuiLogic::yUp() {
    ++yPos;

    this->eventBroker->Position_YUP.post(1);
}

void MasterGuiLogic::yDown() {
    --yPos;

    this->eventBroker->Position_YDOWN.post(1);
}


void MasterGuiLogic::yUpHold() {
    holdingYUpTimer = startTimer(50);
}

void MasterGuiLogic::yUpReleased(){
    if (holdingYUpTimer != 0) {
        killTimer(holdingYUpTimer);
        holdingYUpTimer = 0;
    }
}

void MasterGuiLogic::xUpHold() {
    holdingXUpTimer = startTimer(50);
}

void MasterGuiLogic::xUpReleased(){
    if (holdingXUpTimer != 0) {
        killTimer(holdingXUpTimer);
        holdingXUpTimer = 0;
    }
}

void MasterGuiLogic::yDownHold() {
    holdingYDownTimer = startTimer(50);
}

void MasterGuiLogic::yDownReleased(){
    if (holdingYDownTimer != 0) {
        killTimer(holdingYDownTimer);
        holdingYDownTimer = 0;
    }
}

void MasterGuiLogic::xDownHold() {
    holdingXDownTimer = startTimer(50);
}

void MasterGuiLogic::xDownReleased(){
    if (holdingXDownTimer != 0) {
        killTimer(holdingXDownTimer);
        holdingXDownTimer = 0;
    }
}


int MasterGuiLogic::getXPos(){
    return xPos;
}

int MasterGuiLogic::getYPos(){
    return yPos;
}


