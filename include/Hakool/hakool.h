#pragma once

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
    * Starts the Hakool engine.
    * 
    * @param _config Configuration object that describes the properties of the
    * Hakool engine.
    */
    static void
    Start(HakoolConfiguration& _config);

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
    * Private constructor.
    */
    Hakool() = default;

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
    * 
    * @param _config Configuration object that describes the properties of the
    * engine when initialized.
    */
    void
    _onPrepare(HakoolConfiguration& _config);

    /**
    * Safely close and destroy all the engine with all its systems.
    */
    void
    _onShutdown();

    /**
    * Safely destroys the Hakool engine.
    */
    void
    _destroy();

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
  };
}