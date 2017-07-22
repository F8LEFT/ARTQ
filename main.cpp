/* Process entry point for ARTQ. Init some data*/
#include <QGuiApplication>
#include <QQmlApplicationEngine>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    auto path = QGuiApplication::applicationDirPath();
    auto qmlPath = path + "/qml";


    QQmlApplicationEngine engine;
    engine.load(QUrl::fromLocalFile(qmlPath + "/main.qml"));

    return app.exec();
}
