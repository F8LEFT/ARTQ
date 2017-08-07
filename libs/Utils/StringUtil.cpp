//===------------------------------------------------------------*- C++ -*-===//
//
//                     Created by F8LEFT on 2017/8/6.
//                   Copyright (c) 2017. All rights reserved.
//===----------------------------------------------------------------------===//
//
//===----------------------------------------------------------------------===//

#include "Utils/StringUtil.h"

using namespace StringUtil;


QString StringUtil::ToDateString(const QDate &date) {
    static const char* months[] = {
            "Jan",
            "Feb",
            "Mar",
            "Arp",
            "May",
            "Jun",
            "Jul",
            "Aug",
            "Sep",
            "Oct",
            "Nov",
            "Dec"
    };
    return QString().sprintf("%s %d %d", months[date.month() - 1], date.day(), date.year());
}
