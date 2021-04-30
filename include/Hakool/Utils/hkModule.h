#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>

namespace hk
{
  template<typename T>
  class HK_UTILITY_EXPORT Module
  {
  public:

    /**
    * Get the reference of this module.
    */
    static T&
    GetReference();

    /**
    * Prepare this module.
    */
    template<class... Args>
    static void
    Prepare(Args&& ...args);

    /**
    * Prepare this module.
    */
    template<class S, class... A>
    static void
    Prepare(Args&& ...args);

    /**
    * Safely shutdown this module.
    */
    static void
    Shutdown();

    /**
    * Indicates if the module have been created and is ready to be called.
    */
    static bool&
    IsReady();

    /**
    * Set this module pointer.
    */
    static void
    _Set(void* _module);

  protected:

    Module() = default;

    virtual
    ~Module() = default;

    Module(Module&&) = delete;

    Module&
    operator=(Module&&) = delete;

    Module&
    operator=(const Module&&) = delete;

    virtual void
    onPrepare();

    virtual void
    onShutdown();
  };
}

