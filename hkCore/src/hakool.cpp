#include <Hakool\hakool.h>
#include <Hakool\Utils\hkLoggerConsole.h>
#include <Hakool\Core\hkCoreUtilities.h>

namespace hk
{
  void 
  Hakool::Start(HakoolConfiguration& _config)
  {
    if (!Hakool::_IsReady())
    {
      Hakool::_Singleton() = new Hakool();
      Hakool::_Singleton()->_onPrepare(_config);
      Hakool::_IsReady() = true;
    }
    return;
  }
  
  void 
  Hakool::Shutdown()
  {
    if (Hakool::_IsReady())
    {
      Hakool::_Singleton()->_onShutdown();

      delete(Hakool::_Singleton());
      Hakool::_Singleton() = nullptr;
      Hakool::_IsReady() = false;
    }
    return;
  }

  Hakool*&
  Hakool::GetEngine()
  {
    return Hakool::_Singleton();
  }
  
  void 
  Hakool::_onPrepare(HakoolConfiguration& _config)
  {
    if (!Logger::IsReady())
    {
      Logger::Prepare(new LoggerConsole());
    }    
    return;
  }

  void 
  Hakool::_onShutdown()
  {
    Logger::Shutdown();
    return;
  }

  void
  Hakool::_destroy()
  {
    // TODO
    return;
  }

  Hakool*& 
  Hakool::_Singleton()
  {
    static Hakool* _pSINGLETON = nullptr;
    return _pSINGLETON;
  }

  bool& 
  Hakool::_IsReady()
  {
    static bool _IS_READY = false;
    return _IS_READY;
  }
};