//===------------------------------------------------------------*- C++ -*-===//
//
//                     Created by F8LEFT on 2017/8/6.
//                   Copyright (c) 2017. All rights reserved.
//===----------------------------------------------------------------------===//
//
//===----------------------------------------------------------------------===//
#include "AppCore/AppCore.h"
#include "Utils/GlobalConfig.h"
#include "Utils/StringUtil.h"

#include <QQmlProperty>


AppCore::AppCore() {

}

bool AppCore::init(QObject *root) {
    Q_ASSERT(!m_isInit && "AppCore has been init");
    Q_ASSERT(root != nullptr && "root shoule be empty");
    if(m_isInit) {
        return true;
    }

    m_root = root;
    // init AppCore property
    QQmlProperty::write(root, "version", GlobalConfig::GetCompileVersion());
    QQmlProperty::write(root, "compileTime",
                        StringUtil::ToDateString(GlobalConfig::GetCompileData())
                        + ", " + GlobalConfig::GetCompileString());

    // init other window info
    mainWindow->init(m_root->findChild<QObject*>("mainWindow", Qt::FindDirectChildrenOnly));


    m_isInit = true;
    return m_isInit;
}
