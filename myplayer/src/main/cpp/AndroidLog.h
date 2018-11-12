//
// Created by zhangkexin on 18-11-12.
//

#ifndef FFMPEG1_ANDROIDLOG_H
#define FFMPEG1_ANDROIDLOG_H

#endif //FFMPEG1_ANDROIDLOG_H


#include "android/log.h"

#define LOGD(FORMAT,...) __android_log_print(ANDROID_LOG_DEBUG,"zkx123",FORMAT,##__VA_ARGS__);
