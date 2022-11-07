#include <Hakool\Utils\hkIWindow.h>
#include <Hakool\Utils\hkIPlugin.h>
#include <Hakool\Utils\hkLoggerConsole.h>
#include <Hakool\Core\hakool.h>
#include <Hakool\Core\hkCoreUtilities.h>
#include <Hakool\Core\hkGraphicComponent.h>

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

  eRESULT
  Hakool::init(
    HakoolConfiguration& _config,
    Logger* _pLogger)
  {
    if (_m_isInitialized)
    {
      Logger::Error("Hakool is already initialized");
      return eRESULT::kFail;
    }
    Logger::Prepare(_pLogger);
    eRESULT result;   

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
        Logger::Error("Couldn't connect to the graphics library.");
        clean();

        return result;
      }

      if (_m_pluginManager.hasPlugin("GraphicsDLL"))
      {
        IPlugin* plugin = _m_pluginManager.getPlugin("GraphicsDLL");
        _m_pGraphicComponent = reinterpret_cast<GraphicComponent*>(plugin->getData());

        result = _m_pGraphicComponent->init(
          _config.graphicsConfiguration,
          _config.windowConfiguration,
          _m_resourceManager);

        if (result != eRESULT::kSuccess)
        {
          Logger::Error("Couldn't initialize the graphics.");
          clean();

          return result;
        }
      }
      else
      {
        Logger::Error("Couldn't find the graphics plug-in.");
        clean();

        return eRESULT::kFail;
      }
    }
    else
    {
      Logger::Error("Graphic API not implemented yet.");
      clean();

      return eRESULT::kFail;
    }

    _m_resourceManager.init(_m_pGraphicComponent);
    _m_sceneManager.init(this);

    _m_isInitialized = !_m_isInitialized;

    return eRESULT::kSuccess;
  }

  eRESULT 
  Hakool::update()
  { 
    _m_pGraphicComponent->getWindow()->update();
    _m_sceneManager.update();
    return eRESULT::kSuccess;
  }

  eRESULT 
  Hakool::postUpdate()
  {
    _m_pGraphicComponent->getWindow()->update();
    return eRESULT::kSuccess;
  }

  eRESULT 
  Hakool::draw()
  {
    _m_pGraphicComponent->clear();
    _m_pGraphicComponent->prepareToDraw();
    _m_sceneManager.draw(_m_pGraphicComponent);
    _m_pGraphicComponent->getWindow()->present();
    return eRESULT::kSuccess;
  }

  void 
  Hakool::clean()
  {
    _m_sceneManager.clear();

    if (_m_pGraphicComponent != nullptr)
    {
      _m_pGraphicComponent->destroy();
      _m_pGraphicComponent = nullptr;
    }

    _m_resourceManager.clear();
    _m_pluginManager.closeAll();
    return;
  }

  bool 
  Hakool::isWindowOpen()
  {
    return _m_pGraphicComponent->getWindow()->isOpen();
  }

  ResourceManager& 
  Hakool::getResourceManager()
  {
    return this->_m_resourceManager;
  }

  SceneManager& 
  Hakool::getSceneManager()
  {
    return this->_m_sceneManager;
  }

  Hakool::Hakool():
    _m_isInitialized(false),
    _m_isRunning(false),
    _m_pGraphicComponent(nullptr),
    _m_pLogger(nullptr),
    _m_sceneManager(),
    _m_resourceManager()
  {
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
    clean();

    _m_resourceManager.destroy();
    _m_pluginManager.destroy();
    _m_sceneManager.destroy();
    Logger::Shutdown();
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