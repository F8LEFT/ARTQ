//===------------------------------------------------------------*- C++ -*-===//
//
//                     Created by F8LEFT on 2017/8/7.
//                   Copyright (c) 2017. All rights reserved.
//===----------------------------------------------------------------------===//
// Main work window.....
//===----------------------------------------------------------------------===//

#ifndef ANDROIDREVERSETOOLKITQ_MAINWINDOW_H
#define ANDROIDREVERSETOOLKITQ_MAINWINDOW_H

#include "DockWindow/FileBrowser.h"

#include <QDebug>

class MainWindow: public QObject {
    Q_OBJECT
public:
    static MainWindow* instance() {
        static MainWindow* mPtr = nullptr;
        if(mPtr == nullptr) {
            mPtr = new MainWindow();
        }
        return mPtr;
    }

    bool init(QObject* root);
    bool isInited() { return m_isInit; }

private:
    MainWindow();

    bool m_isInit = false;

    // Window info
    FileBrowser *fileBrowser = FileBrowser::instance();

};


#endif //ANDROIDREVERSETOOLKITQ_MAINWINDOW_H
