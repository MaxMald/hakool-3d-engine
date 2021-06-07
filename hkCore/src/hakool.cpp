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
    else
    {
      Logger::Error
      (
        "You cannot start a Hakool application if another one has been created."
      );
    }

    return;
  }

  eRESULT 
  Hakool::Init(HakoolConfiguration& _config)
  {
    if (!Hakool::_IsReady())
    {
      Logger::Error
      (
        "Hakool module has not been started. Did you forget to call 'Start'?"
      );
      return eRESULT::kFail;
    }

    return Hakool::_Singleton()->_init(_config);
  }

  void 
  Hakool::Run(const String& _sceneKey)
  {
    if (!Hakool::_IsReady())
    {
      Logger::Error
      (
        "Hakool module has not been started. Did you forget to call 'Start'?"
      );
      return;
    }

    return Hakool::_Singleton()->_run(_sceneKey);
  }
  
  eRESULT 
  Hakool::AddScene(const String& _key, Scene* _pScene)
  {
    if (!Hakool::_IsReady())
    {
      Logger::Error
      (
        "Hakool module has not been started. Did you forget to call 'Start'?"
      );
      return eRESULT::kFail;
    }

    return Hakool::_Singleton()->_addScene(_key, _pScene);
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
    _m_isInitialized(false),
    _m_isRunning(false),
    _m_pGraphicComponent(nullptr),
    _m_pLogger(nullptr),
    _m_pWindow(nullptr),
    _m_sceneManager()
  {
    return;
  }

  eRESULT
  Hakool::_init(HakoolConfiguration& _config)
  {
    if (_m_isInitialized)
    {
      Logger::Error("Hakool is already initialized");
      return eRESULT::kFail;
    }

    // Logger

    Logger::Prepare(new LoggerConsole());

    // Application's window

    _m_pWindow = WindowFactory::GetWindow();    
    eRESULT result = _m_pWindow->init(_config.windowConfiguration);
    if (result != eRESULT::kSuccess)
    {
      Logger::Error("Couldn't initialize the window.");
      _clean();

      return result;
    }

    // GraphicComponent

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
        _clean();

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
          _clean();

          return result;
        }
      }
      else
      {
        Logger::GetReference().error("Couldn't find the graphics plug-in.");
        _clean();

        return eRESULT::kFail;
      }
    }
    else
    {
      Logger::GetReference().error("Graphic API not implemented yet.");
      _clean();

      return eRESULT::kFail;
    }

    _m_isInitialized = !_m_isInitialized;

    return eRESULT::kSuccess;
  }

  void
  Hakool::_run(const String& _sceneKey)
  {
    if (!_m_isInitialized)
    {
      Logger::Error("Hakool has not been initialized yet.");
      return;
    }

    if (_m_isRunning)
    {
      Logger::Error("Hakool is already running.");
      return;
    }

    _m_isRunning = !_m_isRunning;

    _m_sceneManager.init(this);
    _m_sceneManager.setActive(_sceneKey);

    while (_m_pWindow->isOpen())
    {
      // Update stage
      
      _m_pWindow->update();
      _m_sceneManager.update();
      _m_pGraphicComponent->update();

      // Post-update stage

      _m_pWindow->postUpdate();
    }

    _clean();

    _m_isInitialized = !_m_isInitialized;
    _m_isRunning = !_m_isRunning;

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
    _clean();

    _m_sceneManager.destroy();
    Logger::Shutdown();

    return;
  }

  void Hakool::_clean()
  {
    _m_sceneManager.clear();

    if (_m_pGraphicComponent != nullptr)
    {
      _m_pGraphicComponent->destroy();
      _m_pGraphicComponent = nullptr;
    }

    if (_m_pWindow != nullptr)
    {
      _m_pWindow->destroy();
      _m_pWindow = nullptr;
    }

    _m_pluginManager.closeAll();

    return;
  }

  eRESULT 
  Hakool::_addScene(const String& _key, Scene* _pScene)
  {
    return this->_m_sceneManager.add(_key, _pScene);
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