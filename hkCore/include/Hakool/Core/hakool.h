#pragma once

#include <Hakool\Utils\hkUtilitiesUtilities.h>
#include <Hakool\Utils\hkPluginManager.h>
#include <Hakool\Utils\hkIWindowFactory.h>
#include <Hakool\Utils\hkClock.h>
#include <Hakool\Utils\hkTime.h>
#include <Hakool\Core\hkCorePrerequisites.h>
#include <Hakool\Core\hkSceneManager.h>
#include <Hakool\Core\hkResourceManager.h>
#include <Hakool\Core\hkCameraManager.h>

namespace hk
{
  class Logger;
  class IWindow;
  class GraphicComponent;
  class SceneManager;
  class Scene;

  struct HakoolConfiguration;

  /**
  * Hakool Engine.
  */
  class HK_CORE_EXPORT Hakool
  {
  public:
    /**
    * Prepares the Hakool engine.    
    */
    static void
    Start();

    /**
    * Safely close and destroy the engine and all its systems.
    */
    static void
    Shutdown();

    /**
    * Get the Hakool engine instance.
    * 
    * @return Hakool engine.
    */
    static Hakool*&
    GetEngine();

    /**
    * Initialize the engine.
    *
    * @param _config Configuration object that describes the properties of the
    * Hakool engine.
    * @param _pLogger Pointer to the logger.
    * @param _windowFactory Reference to the window factory.
    *
    * @return Operation result.
    */
    eRESULT
    init(
      HakoolConfiguration& _config, 
      Logger* _pLogger);

    /**
     * @brief TODO
     */
    eRESULT
    update();

    /**
     * @brief TODO
     */
    eRESULT
    postUpdate();

    /**
     * @brief TODO
     */
    eRESULT
    draw();

    /**
    * Safely free any resources and references.
    */
    void
    clean();

    /**
     * Indicates if the window is open.
     * 
     * @returns True if the window is open.
     */
    bool
    isWindowOpen();

    /**
     * 
     */
    const Time&
    getDeltaTime();

    /**
    * Get the reference to the resource manager.
    * 
    * @return Resource manager.
    */
    ResourceManager&
    getResourceManager();

    /**
    * Get the reference to the scene manager.
    */
    SceneManager&
    getSceneManager();

    /**
     * Get the CameraManager.
     * 
     * @return CameraManager.
     */
    CameraManager&
    getCameraManager();

  private:

    /**
    * Get the Hakool singleton.
    */
    static Hakool*&
    _Singleton();

    /**
    * Indicates if Hakool singleton has been started.
    */
    static bool&
    _IsReady();

    /**
    * Private constructor.
    */
    Hakool();

    /**
    * Private destructor.
    */
    ~Hakool() = default;

    /**
    * Disable copy constructor.
    */
    Hakool(Hakool&&) = delete;

    /**
    * Disable assignment operator
    */
    Hakool&
    operator=(Hakool&&) = delete;

    /**
    * Disable assignment operator.
    */
    Hakool&
    operator=(const Hakool&&) = delete;   

    /**
    * Prepare and initialize the engine with all its system.
    */
    void
    _onPrepare();

    /**
    * Safely close and destroy all the engine with all its systems.
    */
    void
    _onShutdown();

    /**
    * Pointer to the graphic system.
    */
    GraphicComponent* 
    _m_pGraphicComponent;

    /**
    * Pointer to the message logger.
    */
    Logger* 
    _m_pLogger;

    /**
    * Plug-in manager.
    */
    PluginManager
    _m_pluginManager;

    /**
    * Reference to the scene manager.
    */
    SceneManager
    _m_sceneManager;

    /**
     * CameraManager.
     */
    CameraManager
    _m_cameraManager;

    /**
    * Resource manager.
    */
    ResourceManager
    _m_resourceManager;

    /**
    * Indicates if the engine has been initialized.
    */
    bool
    _m_isInitialized;

    /**
    * Indicates if the engine is running.
    */
    bool
    _m_isRunning;

    Clock*
    _m_pClock;

    /**
     * Duration of the last update.
     */
    Time
    _m_deltaTime;
  };
}