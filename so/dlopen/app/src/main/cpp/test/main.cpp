#include <jni.h>
#include <string>
#include <dlfcn.h>
#include <android/log.h>

#define LOG_TAG "main-lib"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_dlsymdemo_MainActivity_callOtherSo(JNIEnv* env, jobject thiz) {
    void* handle = dlopen("libcomm.so", RTLD_NOW);
    if (!handle) {
        LOGI("Failed to load other-lib: %s", dlerror());
        return env->NewStringUTF("Failed to load other-lib");
    }

    typedef const char* (*FuncType)();
    FuncType func = (FuncType)dlsym(handle, "otherFunction");
    if (!func) {
        LOGI("dlsym failed: %s", dlerror());
        dlclose(handle);
        return env->NewStringUTF("Failed to find symbol");
    }

    const char* result = func();
    jstring jresult = env->NewStringUTF(result);
    dlclose(handle);
    return jresult;
}
