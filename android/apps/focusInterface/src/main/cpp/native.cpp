//
// Created by amer on 3/1/2019.
//

#include <functional>

#include <QtCore/QBuffer>
#include <QtCore/QDebug>
#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QThread>
#include <QtCore/QStringList>
#include <QtCore/QStandardPaths>
#include <QtCore/QTextStream>
#include <QtCore/QObject>

#include <QtAndroidExtras/QAndroidJniObject>
#include <QtAndroidExtras/QtAndroid>
#include <android/log.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

#include <shared/Storage.h>

#include <AddressManager.h>
#include <AndroidHelper.h>
#include <udt/PacketHeaders.h>

extern "C" {
    QAndroidJniObject __interfaceActivity;

    JNIEXPORT void JNICALL
   
    Java_io_highfidelity_focusInterface_InterfaceActivity_NativeOnCreate(JNIEnv *env, jobject obj, jobject obj1) {
        __android_log_print(ANDROID_LOG_INFO, "QQQ", __FUNCTION__);
        __interfaceActivity = QAndroidJniObject(obj);

        QObject::connect(&AndroidHelper::instance(), &AndroidHelper::qtAppLoadComplete, []() {
            __interfaceActivity.callMethod<void>("onAppLoadedComplete", "()V");

            QObject::disconnect(&AndroidHelper::instance(), &AndroidHelper::qtAppLoadComplete,
                                nullptr,
                                nullptr);
        });
    }

    JNIEXPORT void JNICALL
    Java_io_highfidelity_focusInterface_InterfaceActivity_NativeAwayMode(JNIEnv *env, jobject obj) {
            AndroidHelper::instance().toggleAwayMode();
    }


JNIEXPORT void Java_io_highfidelity_focusInterface_InterfaceActivity_OnAppAfterLoad(JNIEnv* env, jobject obj) {
    AndroidHelper::instance().moveToThread(qApp->thread());
}

    JNIEXPORT void JNICALL
        Java_io_highfidelity_focusInterface_InterfaceActivity_NativeOnPause(JNIEnv *env, jobject obj) {
        AndroidHelper::instance().notifyEnterBackground();
    }

    JNIEXPORT void JNICALL
        Java_io_highfidelity_focusInterface_InterfaceActivity_NativeOnResume(JNIEnv *env, jobject obj) {
        AndroidHelper::instance().notifyEnterForeground();
    }

    JNIEXPORT void JNICALL
    Java_io_highfidelity_focusInterface_InterfaceActivity_NotifyHeadsetOn(JNIEnv *env,jobject instance, jboolean pluggedIn) {
        AndroidHelper::instance().notifyHeadsetOn(pluggedIn);
    }

}
