#pragma once

#include <Hakool\Utils\hkLogger.h>

namespace hk
{
  Logger* 
  Logger::Get()
  {
    return Logger::_Singleton();
  }

  Logger&
  Logger::GetReference()
  {
    return *Logger::_Singleton();
  }

  void 
  Logger::Prepare()
  {
    if (!Logger::_IsReady())
    {
      Logger::_Singleton() = new Logger();
      Logger::_Singleton()->_onPrepare();
      Logger::_IsReady() = true;
    }
    return;
  }

  void 
  Logger::Prepare(Logger* _pLogger)
  {
    if (!Logger::_IsReady())
    {
      Logger::_Singleton() = _pLogger;
      Logger::_Singleton()->_onPrepare();
      Logger::_IsReady() = true;
    }
    return;
  }

  void 
  Logger::Shutdown()
  {
    if (Logger::_IsReady())
    {
      Logger::_Singleton()->_onShutdown();

      delete(Logger::_Singleton());
      Logger::_Singleton() = nullptr;
      Logger::_IsReady() = false;
    }
    return;
  }

  bool
  Logger::IsReady()
  {
    return Logger::_IsReady();
  }

  void 
  Logger::log(String _msg)
  {
    return;
  }

  void 
  Logger::log(String _msg, String _filename)
  {
    return;
  }

  void 
  Logger::warning(String _msg)
  {
    return;
  }

  void 
  Logger::warning(String _msg, String _filename)
  {
    return;
  }

  void 
  Logger::error(String _msg)
  {
    return;
  }

  void 
  Logger::error(String _msg, String _filename)
  {
    return;
  }

  void
  Logger::_onPrepare()
  {
    return;
  }

  void
  Logger::_onShutdown()
  {
    return;
  }

  Logger*& 
  Logger::_Singleton()
  {
    static Logger* _pSINGLETON = nullptr;
    return _pSINGLETON;
  }

  bool& 
  Logger::_IsReady()
  {
    static bool _IS_READY = false;
    return _IS_READY;
  }  
}