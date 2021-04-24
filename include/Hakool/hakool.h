#pragma once

#include <Hakool\Core\hkCorePrerequisites.h>

namespace hk
{
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
    * @returns {Hakool} Hakool engine.
    */
    static Hakool*
    GetEngine();

  private:

    /**
    * Private constructor.
    */
    Hakool();

    /**
    * Private destructor.
    */
    ~Hakool();

    /**
    * Safely destroys the Hakool engine.
    */
    void
    _destroy();

    /**
    * Pointer to the engine instance.
    */
    static Hakool* _ENGINE_INSTANCE;

  };

};