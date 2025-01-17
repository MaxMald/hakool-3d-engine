#pragma once

#include <Hakool/Core/hkCamera.h>
#include <Hakool/Core/hkICameraManager.h>;

namespace hk
{
  class HK_CORE_EXPORT CameraManager : public ICameraManager
  {
  public:

    CameraManager();

    virtual
    ~CameraManager();

    virtual void
    init() override;

    virtual const uint32&
    createCamera() override;

    virtual const uint32&
    copyCamera(Camera& camera) override;

    virtual Camera*
    getCamera(const uint32& id) const override;

    virtual void
    setActiveCamera(const uint32& id) override;

    virtual Camera *
    getActiveCamera() override;

    virtual void
    destroyCamera(const uint32& id) override;

    virtual void
    clearCameras() override;

    virtual void
    destroy() override;

  private:

    Map<uint32, Camera*> 
    _m_cameras;

    Camera*
    _m_pActiveCamera;

    Camera
    _m_defaultCamera;

    uint32
    _m_cameraCounter;
  };
}