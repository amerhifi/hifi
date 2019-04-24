#pragma once

#include <display-plugins/hmd/HmdDisplayPlugin.h>
#include <EGL/egl.h>

#include <gl/Context.h>
#include <plugins/PluginManager.h>
#include <ui-plugins/PluginContainer.h>
#include <input-plugins/KeyboardMouseDevice.h>

class ViveFocusDisplayPlugin : public HmdDisplayPlugin {
    using Parent = HmdDisplayPlugin;

public:
    ViveFocusDisplayPlugin();
    virtual ~ViveFocusDisplayPlugin();
    bool isSupported() const override { return true; };
    bool hasAsyncReprojection() const override {return true;};
    bool getSupportsAutoSwitch() override final {return false;};

    QThread::Priority getPresentPriority() override {return QThread::TimeCriticalPriority;}

    glm::mat4 getEyeProjection(Eye eye, const glm::mat4& baseProjection) const override;
    glm::mat4 getCullingProjection(const glm::mat4& baseProjection) const override;

    void resetSensors() override final;
    bool beginFrameRender(uint32_t frameIndex) override;
    
    QRectF getPlayAreaRect() override;
    float getTargetFrameRate() const override;
    void init() override;
    void deinit() override;

  

protected:

    const QString getName() const override { return NAME; }

    bool internalActivate() override;
    void internalDeactivate() override;

    void customizeContext() override;
    void uncustomizeContext() override;

    void updatePresentPose() override;
    void internalPresent() override;
    void hmdPresent() override { throw std::runtime_error("Unused"); }
    bool isHmdMounted() const override;
    bool alwaysPresent() const override { return true; }

    static const char* NAME;
    mutable gl::Context* _mainContext{ nullptr };
    uint32_t _readFbo;
};