//===------------------------------------------------------------*- C++ -*-===//
//
//                     Created by F8LEFT on 2017/7/22.
//                   Copyright (c) 2017. All rights reserved.
//===----------------------------------------------------------------------===//
//
//===----------------------------------------------------------------------===//

#include "Utils/GlobalConfig.h"
#include "art_version.h"

#include <QLocale>

GlobalConfig gProcessConfig;

QDate GlobalConfig::GetCompileData() {
    return QLocale("en_US").toDate(QString(__DATE__).simplified(), "MMM d yyyy");
}

QString GlobalConfig::GetCompileVersion() {
    return ART_VERSION_STRING;
}

int GlobalConfig::GetCompileMajor() {
    return ART_VERSION_MAJOR;
}

int GlobalConfig::GetCompileMinor() {
    return ART_VERSION_MINOR;
}

int GlobalConfig::GetComplePatch() {
    return ART_VERSION_PATCH;
}






