#include <Hakool\Utils\hkWindowFactory.h>
#include <Hakool\Utils\hkWindow.h>
#include <Hakool\Utils\hkIPlugin.h>
#include <Hakool\Utils\hkLoggerConsole.h>

#include <Hakool\hakool.h>
#include <Hakool\Core\hkCoreUtilities.h>
#include <Hakool\Core\Graphics\hkGraphicComponent.h>

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
    _m_initialized(false),
    _m_pGraphicComponent(nullptr),
    _m_pLogger(nullptr),
    _m_pWindow(nullptr)
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
    eRESULT result = _m_pWindow->init(_config.windowConfiguration);
    if (result != eRESULT::kSuccess)
    {
      Logger::GetReference().error("Couldn't initialize the window.");
      return result;
    }

    if (_config.graphicsConfiguration.graphicInterface == eGRAPHIC_INTERFACE::kOpenGL)
    {
      result = _m_pluginManager.connectPlugin
      (
        "GraphicsDLL",
        "hkGraphicsOpenGL" + String(HK_DYN_LIB_SUFIX),
        "createGraphicComponentOpenGLPlugin",
        "destroyGraphicComponentOpenGLPlugin"
      );

      if (result != eRESULT::kSuccess)
      {
        Logger::GetReference().error("Couldn't connect to the graphics library.");
        return result;
      }

      if (_m_pluginManager.hasPlugin("GraphicsDLL"))
      {
        IPlugin* plugin = _m_pluginManager.getPlugin("GraphicsDLL");
        _m_pGraphicComponent = reinterpret_cast<GraphicComponent*>(plugin->getData());
        
        result = _m_pGraphicComponent->init(_m_pWindow, _config.graphicsConfiguration);
        if (result != eRESULT::kSuccess)
        {
          Logger::GetReference().error("Couldn't initialize the graphics.");
          return result;
        }
      }
      else
      {
        Logger::GetReference().error("Couldn't find the graphics plug-in.");
        return eRESULT::kFail;
      }
    }
    else
    {
      Logger::GetReference().error("Graphic API not implemented yet.");
      return eRESULT::kFail;
    }

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
      _m_pGraphicComponent->update();
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
    return;
  }

  void
  Hakool::_destroy()
  {
    Logger::Shutdown();



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