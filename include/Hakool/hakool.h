#pragma once

#include <Hakool\Core\hkCorePrerequisites.h>

namespace hk
{
  class Logger;

  /**
  * Hakool Engine.
  */
  class HK_CORE_EXPORT Hakool
  {    

  public:

    /**
    * Starts the Hakool engine.
    */
    static void
    Start();

    /**
    * Shutdown the Hakool engine.
    */
    static void
    Shutdown();

    /**
    * Get the Hakool engine instance.
    * 
    * @returns Hakool engine.
    */
    static Hakool*&
    GetEngine();

    /**
    * Reference to the logger.
    */
    static Logger& log;

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
    * 
    */
    void
    _onPrepare();

    /**
    * 
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
  };
}