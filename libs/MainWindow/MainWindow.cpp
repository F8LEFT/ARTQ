//===------------------------------------------------------------*- C++ -*-===//
//
//                     Created by F8LEFT on 2017/8/7.
//                   Copyright (c) 2017. All rights reserved.
//===----------------------------------------------------------------------===//
//
//===----------------------------------------------------------------------===//

#include <QtQml/QQmlProperties>
#include "MainWindow/MainWindow.h"


MainWindow::MainWindow() {

}

bool MainWindow::init(QObject *root) {
    Q_ASSERT(!m_isInit && "MainWindow has been inited");
    Q_ASSERT(root != nullptr && "root should be empty");
    if(m_isInit) {
        return true;
    }

    // init DockWindows

    fileBrowser->init(root->findChild<QObject*>("fileBrowser"));

    m_isInit = true;
    return true;
}
