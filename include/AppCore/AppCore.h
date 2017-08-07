//===------------------------------------------------------------*- C++ -*-===//
//
//                     Created by F8LEFT on 2017/8/6.
//                   Copyright (c) 2017. All rights reserved.
//===----------------------------------------------------------------------===//
// define the action of core application.
//===----------------------------------------------------------------------===//

#ifndef ANDROIDREVERSETOOLKITQ_APPCORE_H
#define ANDROIDREVERSETOOLKITQ_APPCORE_H

#include <QDebug>

class AppCore {
public:
    static AppCore* instance() {
        static AppCore* mPtr = nullptr;
        if(mPtr == nullptr) {
            mPtr = new AppCore();
        }
        Q_ASSERT(mPtr != nullptr && "init AppCore error?");
        return mPtr;
    }

    bool init(QObject* root);
    bool isInited() { return m_isInit; }

private:
    AppCore();

    bool m_isInit = false;
    QObject* m_root = nullptr;
};


#endif //ANDROIDREVERSETOOLKITQ_APPCORE_H
