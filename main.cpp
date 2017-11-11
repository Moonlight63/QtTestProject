#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include "mastereventbroker.h"
#include "masterGuiLogic.h"
#include "masterAppLogic.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<MasterGuiLogic>("Adapter", 1,0, "Adapter");

    QQmlApplicationEngine engine;

    MasterEventBroker MainEventBroker;

    MasterGuiLogic masterGuiLogic;
    MasterAppLogic baseLogic;

    masterGuiLogic.setMasterEventBroker(MainEventBroker);
    baseLogic.setMasterEventBroker(MainEventBroker);


    QQmlContext* context = engine.rootContext();
    context->setContextProperty("adapterMaster", &masterGuiLogic);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
