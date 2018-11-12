#include <jni.h>
#include <string>

#include "pthread.h"
#include "AndroidLog.h"


pthread_t thread;

void *normalCallBack(void *data) {
    LOGD("create normal thread from C++")
    pthread_exit(&thread);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_zkx_myplayer_Demo_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++++++++++++";
    return env->NewStringUTF(hello.c_str());//创建Java类中的String对象
}

extern "C"
JNIEXPORT void JNICALL
Java_com_zkx_ffmpeg1_ThreadDemo_normalThread(JNIEnv *env, jobject instance) {

    // TODO
    pthread_create(&thread, NULL, normalCallBack, NULL);

}


#include "queue"
#include "unistd.h"

pthread_t produc;
pthread_t custom;
pthread_mutex_t mutex;//线程锁
pthread_cond_t cond;//条件变量

std::queue<int> queue;

void *producCallback(void *data) {
    while (1) {
        pthread_mutex_lock(&mutex);
        queue.push(1);
        LOGD("生产者生产一个产品,通知消费者消费,产品数量为 %d", queue.size())
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(5);
    }

    pthread_exit(&produc);

}


void *customCallback(void *data) {
    while (1) {

        pthread_mutex_lock(&mutex);
        if (queue.size() > 0) {
            queue.pop();
            LOGD("消费者生产一个产品,产品还剩余数量为 %d", queue.size())
        } else {
            LOGD("消没有产品可以消费,等待中.......")
            pthread_cond_wait(&cond, &mutex);//等待时会谁释放锁(暂停,释放锁)
        }
        pthread_mutex_unlock(&mutex);

        usleep(1000 * 500);//微秒
    }

    pthread_exit(&custom);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_zkx_ffmpeg1_ThreadDemo_mutexThread(JNIEnv *env, jobject instance) {

    // TODO
    for (int i = 0; i < 10; ++i) {
        queue.push(i);//初始产品数量10
    }
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);


    pthread_create(&produc, NULL, producCallback, NULL);
    pthread_create(&produc, NULL, customCallback, NULL);


}