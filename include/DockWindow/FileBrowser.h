//===------------------------------------------------------------*- C++ -*-===//
//
//                     Created by F8LEFT on 2017/8/7.
//                   Copyright (c) 2017. All rights reserved.
//===----------------------------------------------------------------------===//
// Display system file tree to show project files.
//===----------------------------------------------------------------------===//

#ifndef ANDROIDREVERSETOOLKITQ_FILEBROWSER_H
#define ANDROIDREVERSETOOLKITQ_FILEBROWSER_H

#include <QDebug>
#include <QFileSystemModel>

class FileBrowser: QObject {
    Q_OBJECT
public:
    static FileBrowser* instance() {
        static FileBrowser* mPtr = nullptr;
        if(mPtr == nullptr) {
            mPtr = new FileBrowser();
        }
        return mPtr;
    }

    bool init(QObject* root);

    bool isInited() { return m_isInit; }
private:
    FileBrowser();

    QFileSystemModel* fileSystemModel = nullptr;

    bool m_isInit = false;
};


#endif //ANDROIDREVERSETOOLKITQ_FILEBROWSER_H
