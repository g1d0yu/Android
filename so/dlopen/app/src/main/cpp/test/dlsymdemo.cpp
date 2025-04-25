#include <jni.h>
#include <string>
#include <android/log.h>
#include <dlfcn.h>

#define TAG "dlsym-demo"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)

extern "C" JNIEXPORT void JNICALL
Java_com_example_dlsymdemo_MainActivity_testDlsym(JNIEnv *env, jobject thiz) {
    const char *lib_path = "/data/data/com.example.dlsymdemo/lib/libnative-lib.so"; // 实际可省略，用RTLD_DEFAULT

    void *handle = dlopen("libnative-lib.so", RTLD_NOW);
    if (!handle) {
        LOGI("dlopen error: %s", dlerror());
        return;
    }

    typedef const char* (*HelloFunc)();
    HelloFunc sayHello = (HelloFunc)dlsym(handle, "sayHello");

    if (!sayHello) {
        LOGI("dlsym error: %s", dlerror());
    } else {
        const char *msg = sayHello();
        LOGI("sayHello result: %s", msg);
    }

    dlclose(handle);
}

extern "C" const char* sayHello() {
    return "Hello from dlsym!";
}