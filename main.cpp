/* Process entry point for ARTQ. Init some data*/
#include "AppCore/AppCore.h"
#include "Utils/GlobalConfig.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDirIterator>
#include <QtWidgets/QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
// Process init
    gProcessConfig.app_root_path = QGuiApplication::applicationDirPath();
    gProcessConfig.qml_root_path = gProcessConfig.app_root_path + "/qml";

#ifndef NDEBUG
    // remove compiled .qmlc file
    {
        QDirIterator dirIt(gProcessConfig.qml_root_path, QDirIterator::Subdirectories);
        while(dirIt.hasNext()) {
            auto filePath = dirIt.next();
            auto info  = QFileInfo(filePath);
            if(info.completeSuffix() == "qmlc") {
                QFile::remove(info.absoluteFilePath());
            }
        }
    };
#endif

    // start process
    QQmlApplicationEngine engine;
    // Import for extra qml
    engine.addImportPath(gProcessConfig.qml_root_path + "/Extra");
//    engine.load(QUrl(QStringLiteral("qrc:///res/qml/main.qml")));
    engine.load(QUrl::fromLocalFile(gProcessConfig.qml_root_path + "/main.qml"));

    auto rootObjects = engine.rootObjects();
    if(rootObjects.isEmpty()) {
        return -1;
    }
    auto appCore = AppCore::instance();
    for(auto &obj: rootObjects) {
        if(obj->objectName() == "RootWindow") {
            appCore->init(obj);
            break;
        }
    }
    if(!appCore->isInited()) {
        QDebug(QtMsgType::QtFatalMsg) << "Unable to init core application, Please "
                "check your qml source";
        return -1;
    }


    return app.exec();
}



