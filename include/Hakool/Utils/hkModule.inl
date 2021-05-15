#pragma once

#include <Hakool\Utils\hkModule.h>

namespace hk
{
  template<typename T>
  inline T&
  Module<T>::GetReference()
  {
    return *_Singleton();
  }

  template<typename T>
  template<class ...Args>
  inline void
  Module<T>::Prepare(Args && ...args)
  {
    if (IsReady()) {
      return;
    }

    // Create module.
    T* pModule = new T(std::forward<Args>(args)...);
    _Singleton() = pModule;

    // Custom prepare method.
    reinterpret_cast<Module*>(pModule)->_onPrepare();

    // Module ready.
    _IsReady() = true;
    return;
  }


  template<typename T>
  inline void
  Module<T>::Prepare(T* _pClass)
  {
    if (IsReady()) 
    {
      throw "Module has been created before.";
    }

    // Assign singleton
    _Singleton() = _pClass;

    // Custom prepare method.
    reinterpret_cast<Module*>(_pClass)->_onPrepare();

    // Module is Ready.
    _IsReady() = true;
    return;
  }

  template<typename T>
  inline void
  Module<T>::Shutdown()
  {
    if (!IsReady())
    {
      return;
    }

    // Get singleton
    T* pModule = _Singleton();

    // Custom shutdown method.
    reinterpret_cast<Module*>(pModule)->_onShutdown();

    // Module is close.
    _Singleton() = nullptr;
    _IsReady() = false;
    return;
  }

  template<typename T>
  inline bool
  Module<T>::IsReady()
  {
    return _IsReady();
  }

  template<typename T>
  inline void
  Module<T>::_onPrepare()
  {
    return;
  }

  template<typename T>
  inline void
  Module<T>::_onShutdown()
  {
    return;
  }

  template<typename T>
  inline T*&
  Module<T>::_Singleton()
  {
    static T* _SINGLETON = nullptr;
    return _SINGLETON;
  }

  template<typename T>
  inline bool&
  Module<T>::_IsReady()
  {
    static bool _IS_READY = false;
    return _IS_READY;
  }
}