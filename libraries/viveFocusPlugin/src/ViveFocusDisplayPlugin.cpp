#include "VivefocusdDisplayPlugin.h"

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

const char* OculusMobileDisplayPlugin::NAME { "Vive Focus" };

ViveFocusDisplayPlugin::ViveFocusDisplayPlugin(){}

ViveFocusDisplayPlugin::~ViveFocusDisplayPlugin(){}

void OculusMobileDisplayPlugin::init() {
    Parent::init();
    initVr();

    emit deviceConnected(getName());
}

void OculusMobileDisplayPlugin::deinit() {
    shutdownVr();
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

]
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
    if (!vrActive()) {
        QThread::msleep(1);
        return;
    }

    GLuint sourceTexture = 0;
    glm::uvec2 sourceSize;
    if (compsiteFramebuffer) {
        sourceTexture = getGLBackend()->getTextureID(compsiteFramebuffer->getRenderBuffer(0));
        sourceSize = { compsiteFramebuffer->getWidth(), compsiteFramebuffer->getHeight() };
    }
    //VrHandler::presentFrame(sourceTexture, sourceSize, presentTracking);
    _presentRate.increment();

}
