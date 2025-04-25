
#ifndef MY_APPLICATION_OTHER_H
#define MY_APPLICATION_OTHER_H

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif
// 使用 JNIEXPORT 和 JNICALL 宏确保函数导出
// 这是必须的，使得函数对其他库可见
JNIEXPORT const char* JNICALL otherFunction();

#ifdef __cplusplus
}
#endif

#endif
