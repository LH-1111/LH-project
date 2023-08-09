//
// Created by lh on 2023/8/9.
//
#include <jni.h>
#include <string>
#include <android/log.h>

#define  LOG_TAG    "JNI Example"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)


struct MyStruct {
    int intValue;
    float floatValue;
}MyStruct;

// 声明一个本地方法
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_demo_MainActivity_getStringFromJNI(JNIEnv* env, jobject /* this */) {
    std::string hello = "Hello from C++";
    LOGD("GetStringFromJNI() called");
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jobject JNICALL
Java_com_example_demo_MainActivity_getStruct(JNIEnv* env, jobject obj , jint x ) {
    jclass cls = env->FindClass("com/example/demo/JniClass/MyStruct");
    jmethodID constructor = env->GetMethodID(cls, "<init>", "()V");
    LOGD("getStruct() called x : %d " , x);
    jobject javaStruct = env->NewObject(cls, constructor);

    struct MyStruct myStruct;
    myStruct.intValue = 123;
    myStruct.floatValue = 4.56f;

    jfieldID intValueField = env->GetFieldID(cls, "intValue", "I");
    env->SetIntField(javaStruct, intValueField, myStruct.intValue);

    jfieldID floatValueField = env->GetFieldID(cls, "floatValue", "F");
    env->SetFloatField(javaStruct, floatValueField, myStruct.floatValue);

    return javaStruct;
}