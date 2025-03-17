#pragma once

#include <android/log.h>

#define LOG_TAG "Sneaky"

enum LogType {
    eDEBUG = 3,
    eINFO  = 4,
    eWARN  = 5,
    eERROR = 6,
};

#define LOGD(...) ((void)__android_log_print(eDEBUG, LOG_TAG, __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(eERROR, LOG_TAG, __VA_ARGS__))
#define LOGI(...) ((void)__android_log_print(eINFO,  LOG_TAG, __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(eWARN,  LOG_TAG, __VA_ARGS__))
