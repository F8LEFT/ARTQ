//===------------------------------------------------------------*- C++ -*-===//
//
//                     Created by F8LEFT on 2017/8/7.
//                   Copyright (c) 2017. All rights reserved.
//===----------------------------------------------------------------------===//
//
//===----------------------------------------------------------------------===//

#include "Utils/GlobalConfig.h"
#include "DockWindow/FileBrowser.h"

#include <QtQml>

FileBrowser::FileBrowser() {

}

bool FileBrowser::init(QObject *root) {
    Q_ASSERT(!m_isInit && "FileBrowser has been init");
    Q_ASSERT(root != nullptr && "root should not be empty");
    if(m_isInit) {
        return true;
    }

    fileSystemModel = new QFileSystemModel(this);
    fileSystemModel->setRootPath(QDir::homePath());
    fileSystemModel->setResolveSymlinks(true);

    qmlRegisterUncreatableType<QFileSystemModel>("io.qt.FileSystemModel", 1, 0,
                                                 "FileSstemModel", "Unable to create file system model");

//    gProcessConfig.m_engine->rootContext()->findChild()

    auto context = gProcessConfig.m_engine->rootContext();

    context->setContextProperty("projectFileSystemModel", fileSystemModel);
    root->setProperty("rootPathIndex", fileSystemModel->index(fileSystemModel->rootPath()));


    m_isInit = true;
    return m_isInit;
}
