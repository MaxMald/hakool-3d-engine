#pragma once

#include "Hakool/Core/hkCorePrerequisites.h"

namespace hk
{
  class Camera;

  class ICameraManager
  {
  public:

    ICameraManager() = default;

    virtual
    ~ICameraManager() = default;

    virtual const uint32&
    createCamera() = 0;
    
    virtual Camera&
    getCamera(const uint32& id) const = 0;

    virtual void
    setActiveCamera(const uint32& id) = 0;

    virtual Camera const *
    getActiveCamera() const = 0;

    virtual void
    destroyCamera(const uint32& id) = 0;

    virtual void
    clearCameras() = 0;

    virtual void
    destroy() = 0;

  private:

    ICameraManager(const ICameraManager&) = delete;

    ICameraManager&
    operator= (const ICameraManager&) = delete;
  };
}