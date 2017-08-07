//===------------------------------------------------------------*- C++ -*-===//
//
//                     Created by F8LEFT on 2017/7/22.
//                   Copyright (c) 2017. All rights reserved.
//===----------------------------------------------------------------------===//
// Collect process global config.
//===----------------------------------------------------------------------===//

#ifndef ANDROIDREVERSETOOLKITQ_GLOBALCONFIG_H
#define ANDROIDREVERSETOOLKITQ_GLOBALCONFIG_H

#include <QString>
#include <QDate>

struct GlobalConfig {
public:
    GlobalConfig() {};

    bool load();
    bool save();

    QString app_root_path;
    QString qml_root_path;

    static QDate GetCompileData();
    static QString GetCompileVersion();
    static int GetCompileMajor();
    static int GetCompileMinor();
    static int GetComplePatch();
private:


};


extern GlobalConfig gProcessConfig;

#endif //ANDROIDREVERSETOOLKITQ_GLOBALCONFIG_H
