//
//  Created by Amer Cerkic on 2019/04/01
//  Copyright 2013-2019 High Fidelity, Inc.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#include "ViveFocusDisplayPlugin.h"

#include <QtAndroidExtras/QAndroidJniEnvironment>
#include <glm/gtc/matrix_transform.hpp>

#include <AbstractViewStateInterface.h>
#include <gpu/Frame.h>
#include <gpu/Context.h>
#include <gpu/gl/GLBackend.h>
#include <ViewFrustum.h>
#include <plugins/PluginManager.h>
#include <ui-plugins/PluginContainer.h>
#include <controllers/Pose.h>
#include <display-plugins/CompositorHelper.h>
#include <gpu/Frame.h>
#include <gl/Config.h>
#include <gl/GLWidget.h>
#include <gl/Context.h>
#include <MainWindow.h>
#include <AddressManager.h>
#include <input-plugins/KeyboardMouseDevice.h>
const char* ViveFocusDisplayPlugin::NAME { "Vive Focus" };

ViveFocusDisplayPlugin::ViveFocusDisplayPlugin(){}

ViveFocusDisplayPlugin::~ViveFocusDisplayPlugin(){}

void ViveFocusDisplayPlugin::init() {
    Parent::init();
   // initVr();

    emit deviceConnected(getName());
}

void ViveFocusDisplayPlugin::deinit() {
   // shutdownVr();
    Parent::deinit();
}

bool ViveFocusDisplayPlugin::internalActivate(){


    return Parent::internalActivate();
}

void ViveFocusDisplayPlugin::internalDeactivate(){
 Parent::internalDeactivate();

}

void ViveFocusDisplayPlugin::customizeContext(){

 Parent::customizeContext();

}

void ViveFocusDisplayPlugin::uncustomizeContext(){
  Parent::uncustomizeContext();

}

QRectF ViveFocusDisplayPlugin::getPlayAreaRect() {

    return  QRectF{0,0, 1200, 1200};
}


glm::mat4 ViveFocusDisplayPlugin::getEyeProjection(Eye eye, const glm::mat4& baseProjection) const {

    return baseProjection;
}

glm::mat4 ViveFocusDisplayPlugin::getCullingProjection(const glm::mat4& baseProjection) const {

    return baseProjection;
}

void ViveFocusDisplayPlugin::resetSensors() {}

float ViveFocusDisplayPlugin::getTargetFrameRate() const {
  float result = 0.0f;
return result;
}

bool ViveFocusDisplayPlugin::beginFrameRender(uint32_t frameIndex) {


    return true;
}


void ViveFocusDisplayPlugin::updatePresentPose() {}

void ViveFocusDisplayPlugin::internalPresent(const gpu::FramebufferPointer& compsiteFramebuffer) {
   // if (!vrActive()) {
      //  QThread::msleep(1);
       // return;
   // }

    GLuint sourceTexture = 0;
    glm::uvec2 sourceSize;
    if (compsiteFramebuffer) {
        sourceTexture = getGLBackend()->getTextureID(compsiteFramebuffer->getRenderBuffer(0));
        sourceSize = { compsiteFramebuffer->getWidth(), compsiteFramebuffer->getHeight() };
    }
    //VrHandler::presentFrame(sourceTexture, sourceSize, presentTracking);
    _presentRate.increment();

}

bool ViveFocusDisplayPlugin::isHmdMounted() const {
    bool result = true;
//  VrHandler::withOvrJava([&](const ovrJava* java){
//        result = VRAPI_FALSE != vrapi_GetSystemStatusInt(java, VRAPI_SYS_STATUS_MOUNTED);
 //   });
    return result;
}

 DisplayPluginList getDisplayPlugins() {
        static DisplayPluginList result;
        static std::once_flag once;
        std::call_once(once, [&]{
            auto plugin = std::make_shared<ViveFocusDisplayPlugin>();
            plugin->isSupported();
            result.push_back(plugin);
        });
        return result;
    }

  InputPluginList getInputPlugins() {
        InputPlugin* PLUGIN_POOL[] = {
            new KeyboardMouseDevice(),
            // new OculusMobileControllerManager(),
            nullptr
        };

        InputPluginList result;
        for (int i = 0; PLUGIN_POOL[i]; ++i) {
            InputPlugin* plugin = PLUGIN_POOL[i];
            if (plugin->isSupported()) {
                result.push_back(InputPluginPointer(plugin));
            }
        }
        return result;
    }

