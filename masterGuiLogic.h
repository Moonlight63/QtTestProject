#ifndef MASTERADAPTER_H
#define MASTERADAPTER_H

#include <QObject>
#include <QTimer>

#include "mastereventbroker.h"

class MasterGuiLogic : public QObject
{
    Q_OBJECT
public:
    MasterEventBroker *eventBroker;
    explicit MasterGuiLogic(QObject *parent = nullptr);

    void setMasterEventBroker( MasterEventBroker &ev );
private:

    QTimer *appClock = new QTimer(this);
    void loop ();


    int xPos = 0;
    int yPos = 0;

    int holdingXUpTimer = 0;
    int holdingXDownTimer = 0;
    int holdingYUpTimer = 0;
    int holdingYDownTimer = 0;

signals:

public slots:

    void testComm(const QString &str);

    void xUp ();
    void xDown ();
    void yUp ();
    void yDown ();

    void yUpHold();
    void yUpReleased();
    void yDownHold();
    void yDownReleased();
    void xUpHold();
    void xUpReleased();
    void xDownHold();
    void xDownReleased();

    int getXPos ();
    int getYPos ();

protected:
    void timerEvent(QTimerEvent *event);

};

#endif // MASTERADAPTER_H
