#pragma once

#include <Hakool\Utils\hkLogger.h>

namespace hk
{
  Logger Logger::_NULL = Logger();

  Logger::Logger()
  {
    return;
  }

  Logger::~Logger()
  {
    return;
  }

  Logger&
  Logger::GetReference()
  {
    if (!Logger::IsReady())
    {
      return Logger::_NULL;
    }

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
  Logger::Log(const String& _msg)
  {
    if (Logger::IsReady()) 
    {
      Logger::_Singleton()->log(_msg);
    }

    return;
  }

  void 
  Logger::Log(const String& _msg, const String& _filename)
  {
    if (Logger::IsReady()) 
    {
      Logger::_Singleton()->log(_msg, _filename);
    }

    return;
  }

  void 
  Logger::Warning(const String& _msg)
  {
    if (Logger::IsReady()) 
    {
      Logger::_Singleton()->warning(_msg);
    }

    return;
  }

  void 
  Logger::Warning(const String& _msg, const String& _filename)
  {
    if (Logger::IsReady()) 
    {
      Logger::_Singleton()->warning(_msg, _filename);
    }

    return;
  }

  void 
  Logger::Error(const String& _msg)
  {
    if (Logger::IsReady()) 
    {
      Logger::_Singleton()->error(_msg);
    }

    return;
  }

  void 
  Logger::Error(const String& _msg, const String& _filename)
  {
    if (Logger::IsReady()) 
    {
      Logger::_Singleton()->error(_msg, _filename);
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
  Logger::log(const String& _msg)
  {
    // Intentionally blank.
    return;
  }

  void 
  Logger::log(const String& _msg, const String& _filename)
  {
    // Intentionally blank.
    return;
  }

  void 
  Logger::warning(const String& _msg)
  {
    // Intentionally blank.
    return;
  }

  void 
  Logger::warning(const String& _msg, const String& _filename)
  {
    // Intentionally blank.
    return;
  }

  void 
  Logger::error(const String& _msg)
  {
    // Intentionally blank.
    return;
  }

  void 
  Logger::error(const String& _msg, const String& _filename)
  {
    // Intentionally blank.
    return;
  }

  void
  Logger::_onPrepare()
  {
    // Intentionally blank.
    return;
  }

  void
  Logger::_onShutdown()
  {
    // Intentionally blank.
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