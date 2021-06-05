#include <Hakool\Utils\hkWindowFactory.h>
#include <Hakool\Utils\hkWindow.h>

#include <Hakool\hakool.h>
#include <Hakool\Utils\hkLoggerConsole.h>
#include <Hakool\Core\hkCoreUtilities.h>

namespace hk
{
  void 
  Hakool::Start()
  {
    if (!Hakool::_IsReady())
    {
      Hakool::_Singleton() = new Hakool();
      Hakool::_Singleton()->_onPrepare();
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

  Hakool::Hakool():
    _m_initialized(false)
  {
    return;
  }

  eRESULT
  Hakool::init(HakoolConfiguration& _config)
  {
    if (_m_initialized)
    {
      return eRESULT::kFail;
    }

    if (!Logger::IsReady())
    {
      Logger::Prepare(new LoggerConsole());
    }

    _m_pWindow = WindowFactory::GetWindow();
    _m_pWindow->init
    (
      _config.windowConfiguration.width,
      _config.windowConfiguration.height,
      _config.windowConfiguration.title
    );

    _m_initialized = !_m_initialized;

    return eRESULT::kSuccess;
  }

  void
  Hakool::run()
  {
    if (!_m_initialized)
    {
      return;
    }

    while (_m_pWindow->isOpen())
    {
      _m_pWindow->update();
    }

    return;
  }
  
  void 
  Hakool::_onPrepare()
  {
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