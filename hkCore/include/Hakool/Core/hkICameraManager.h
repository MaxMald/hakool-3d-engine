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

    /**
     * Initializes the ICameraManager.
     */
    virtual void
    init() = 0;

    /**
     * Creates a new camera instance.
     *
     * @return Returns the Id of the new camera.
     */
    virtual const uint32&
    createCamera() = 0;

    /**
     * Creates a copy of a given camera.
     * 
     * @return Returns the ID of the new camera.
     */
    virtual const uint32&
    copyCamera(Camera& camera) = 0;
    
    /**
     * Get a Camera by its Id.
     *
     * @param id The Id of the Camera you want to get.
     * 
     * @return The pointer to the Camera. Returns a nullptr if the Camera wasn't
     * found.
     */
    virtual Camera*
    getCamera(const uint32& id) const = 0;

    /**
     * Set the active Camera by its Id.
     * 
     * @param id The Id of the Camera.
     */
    virtual void
    setActiveCamera(const uint32& id) = 0;

    /**
     * Get the current active Camera.
     * 
     * @return The pointer to the active camera.
     */
    virtual Camera *
    getActiveCamera() = 0;

    /**
     * Destroy a Camera by its Id.
     * 
     * @return The Id of the Camera you want to destroy.
     */
    virtual void
    destroyCamera(const uint32& id) = 0;

    /**
     * Destroy all the Cameras in this ICameraManager.
     */
    virtual void
    clearCameras() = 0;

    /**
     * Safely destroy the ICameraManager.
     */
    virtual void
    destroy() = 0;

  private:

    ICameraManager(const ICameraManager&) = delete;

    ICameraManager&
    operator= (const ICameraManager&) = delete;
  };
}