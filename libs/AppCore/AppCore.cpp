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
    if(m_isInit) {
        return true;
    }
    Q_ASSERT(root != nullptr && "root shoule be empty");

    m_root = root;

    QQmlProperty version(root, "version");
    version.write(GlobalConfig::GetCompileVersion());
    QQmlProperty compileTime(root, "compileTime");
    compileTime.write(StringUtil::ToDateString(GlobalConfig::GetCompileData())
                      + "," + __TIME__);

    m_isInit = true;
    return m_isInit;
}
