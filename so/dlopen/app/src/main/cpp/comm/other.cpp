
#include "other.h"
#include <jni.h>
#include <string>
#include <android/log.h>

#define LOG_TAG "other-lib"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

const char* otherFunction() {
    LOGI("otherFunction called");
    return "Hello from other-lib!";
}