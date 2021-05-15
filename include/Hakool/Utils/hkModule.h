#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>

namespace hk
{
  template<typename T>
  class HK_UTILITY_EXPORT Module
  {
  public:

    /**
    * Get the instance-reference of this module.
    * 
    * @returns The instance-reference of this module.
    */
    static T&
    GetReference();

    /**
    * Create and prepare this module.
    */
    template<class... Args>
    static void
    Prepare(Args&& ...args);

    /**
    * Create and prepare this module.
    */
    template<class SubType, class... Args>
    static void
    Prepare(Args&& ...args)
    {
      static_assert
      (
        std::is_base_of<T, SubType>::value,
        "Type isn't derived from type the Module is initialized with."
      );

      if (IsReady())
      {
        throw "Module has been created before.";
      }

      _singleton() = new SubType(std::forward<Args>(args)...);
      isReady() = true;

      static_cast<Module*>(_singleton())->onPrepare();
    }

    /**
    * Prepare this module using an existing instance of 
    */
    static void
    Prepare(T* _pClass);

    /**
    * Safely shutdown this module.
    */
    static void
    Shutdown();

    /**
    * Indicates if the module have been prepared and is ready to be called.
    * 
    * @return True if the module has been prepared, otherwise returns false.
    */
    static bool
    IsReady();

  protected:

    Module() = default;

    virtual
    ~Module() = default;

    Module(Module&&) = delete;

    Module&
    operator=(Module&&) = delete;

    Module&
    operator=(const Module&&) = delete;

    /**
    * Called when the module is being prepared.
    */
    virtual void
    _onPrepare();

    /**
    * Called when the module is being shutdown.
    */
    virtual void
    _onShutdown();

    /**
    * Get the module's instance.
    * 
    * @retrun The module instance. 
    */
    static T*&
    _Singleton();

    /**
    * Get the "isReady" boolean instance.
    * 
    * @return "isReady" boolean instance.
    */
    static bool&
    _IsReady();
  };  

#include <Hakool\Utils\hkModule.inl>
}

