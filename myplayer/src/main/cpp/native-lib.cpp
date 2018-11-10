#include <jni.h>
#include <string>


extern "C" JNIEXPORT jstring JNICALL
Java_com_zkx_myplayer_Demo_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++++++++++++";
    return env->NewStringUTF(hello.c_str());//创建Java类中的String对象
}
