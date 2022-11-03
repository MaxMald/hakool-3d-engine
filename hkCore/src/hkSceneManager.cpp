#include <Hakool\Utils\hkLogger.h>

#include <Hakool\Core\hkSceneManager.h>
#include <Hakool\Core\hkScene.h>

namespace hk
{
  SceneManager::SceneManager() :
    _m_pHakool(nullptr),
    _m_pActiveScene(nullptr),
    _m_pNextScene(nullptr),
    _m_isUpdating(false),
    _m_transitionRequested(false),
    _m_isInitialized(false),
    _m_hScenes()
  {
    return;
  }

  SceneManager::~SceneManager()
  {
    destroy();

    return;
  }

  void 
  SceneManager::init(Hakool* _pHakool)
  {
    if (_m_isInitialized)
    {
      Logger::Error("Scene Manager is already initialized.");
      
      return;
    }

    for (auto iterator : _m_hScenes)
    {
      Scene* pScene = iterator.second;
      pScene->start();
    }

    _m_isInitialized = !_m_isInitialized;

    return;
  }

  void
  SceneManager::update()
  {
    if (_m_isUpdating)
    {
      Logger::Error("Scene Manager is already been updating.");
      return;
    }

    _m_isUpdating = !_m_isUpdating;

    // Transition

    if (_m_transitionRequested)
    {
      if (_m_pNextScene != nullptr)
      {
        if (_m_pActiveScene != nullptr)
        {
          _m_pActiveScene->_exit();
        }

        _m_pActiveScene = _m_pNextScene;
        _m_pActiveScene->_enter();
      }

      _m_transitionRequested = !_m_transitionRequested;
    }

    // Update

    if (_m_pActiveScene != nullptr)
    {
      _m_pActiveScene->_update();
    }

    _m_isUpdating = !_m_isUpdating;

    return;
  }

  eRESULT 
  SceneManager::setActive(const String& _key)
  {
    if (!has(_key)) 
    {
      Logger::Error("Scene with key: " + _key + " not found.");

      return eRESULT::kObjectNotFound;
    }

    _m_pNextScene = _m_hScenes.find(_key)->second;
    _m_transitionRequested = true;

    return eRESULT::kSuccess;
  }

  Scene* 
  SceneManager::getActive()
  {
    return _m_pActiveScene;
  }

  Scene& 
  SceneManager::create(const String& key)
  {
    if (has(key))
    {
      throw std::invalid_argument("Scene with key: " + key + " already exists.");
    }

    Scene* pScene = new Scene();
    add(key, pScene);
    return *pScene;
  }

  eRESULT 
  SceneManager::add(const String& _key, Scene* _pScene)
  {
    if (has(_key))
    {
      Logger::Error("Scene with key: " + _key + " already exists.");
      delete _pScene;

      return eRESULT::kObjectAlreadyExists;
    }

    _m_hScenes.insert
    (
      Map<String, Scene*>::value_type(_key, _pScene)
    );

    //_pScene->_m_pHakool = _m_pHakool;

    return eRESULT::kSuccess;
  }

  eRESULT 
  SceneManager::remove(const String& _key)
  {
    if (!has(_key))
    {
      Logger::Error("Scene with key: " + _key + " not found.");

      return eRESULT::kObjectNotFound;
    }

    Scene* pScene = this->_m_hScenes.find(_key)->second;
    pScene->destroy();
    delete pScene;
    this->_m_hScenes.erase(_key);

    return eRESULT::kSuccess;
  }

  Scene* 
  SceneManager::get(const String& _key)
  {
    if (!has(_key))
    {
      Logger::Error("Scene with key: " + _key + " not found.");

      return nullptr;
    }

    return this->_m_hScenes.find(_key)->second;
  }

  bool
  SceneManager::has(const String& _key)
  {
    return _m_hScenes.find(_key) != _m_hScenes.end();
  }

  bool 
  SceneManager::hasActiveScene()
  {
    return _m_pActiveScene != nullptr;
  }

  void 
  SceneManager::draw(GraphicComponent* pGraphicComponent)
  {
    if (_m_pActiveScene != nullptr)
    {
      _m_pActiveScene->_draw(pGraphicComponent);
    }
    return;
  }

  void
  SceneManager::clear()
  {
    for (auto iterator : _m_hScenes)
    {
      Scene* pScene = iterator.second;
      pScene->destroy();
      delete pScene;
    }
    this->_m_hScenes.clear();
    this->_m_pActiveScene = nullptr;
    this->_m_pNextScene = nullptr;
    return;
  }

  void 
  SceneManager::destroy()
  {
    clear();

    _m_isInitialized = false;
    _m_pHakool = nullptr;

    return;
  }
}