#pragma once

#include <Hakool\Utils\hkUtilitiesUtilities.h>
#include <Hakool\Utils\hkPluginManager.h>
#include <Hakool\Core\hkCorePrerequisites.h>

namespace hk
{
  class Logger;
  class Window;
  class GraphicComponent;

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
    * Initialize the Hakool engine with the desire configuration.
    */
    static eRESULT
    Init(HakoolConfiguration& _config);

    /**
    * Run the application. This will start the game loop.
    */
    static void
    Run();

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
    * Initialize the engine.
    *
    * @param _config Configuration object that describes the properties of the
    * Hakool engine.
    *
    * @return Operation result.
    */
    eRESULT
    _init(HakoolConfiguration& _config);

    /**
    * Run the game engine loop.
    */
    void
    _run();

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
    * Safely free any resources and references.
    */
    void
    _clean();

    /**
    * Pointer to the graphic system.
    */
    GraphicComponent* 
    _m_pGraphicComponent;

    /**
    * Pointer to the window.
    */
    Window*
    _m_pWindow;

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
    * Indicates if the engine has been initialized.
    */
    bool
    _m_isInitialized;

    /**
    * Indicates if the engine is running.
    */
    bool
    _m_isRunning;
  };
}