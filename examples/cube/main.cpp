#include <QApplication>
#include <QQmlApplicationEngine>
#include <registerosgtypes.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    registerOsgTypes();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
