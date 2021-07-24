#include <Hakool\Core\hkScene.h>
#include <Hakool\hakool.h>

namespace hk
{
  void 
  Scene::start()
  {
    // Intentionally blank
    return;
  }

  void 
  Scene::enter()
  {
    // Intentionally blank
    return;
  }

  void
  Scene::update()
  {
    // Intentionally blank
    return;
  }

  void 
  Scene::exit()
  {
    // Intentionally blank
    return;
  }

  void 
  Scene::destroy()
  {
    // Intentionally blank
    return;
  }

  GameObject& 
  Scene::getRoot()
  {
    return _m_root;
  }

  bool 
  Scene::hasGameObject(const String& _path)
  {
      
      return false;
  }

  GameObject& 
  Scene::getGameObject(const String& _path)
  {
    return _m_root.getGameObjectByPath(_path);
  }

  SceneManager&
  Scene::getSceneManager()
  {
    if (_m_pSceneManager == nullptr)
    {
      throw "Scene doesn't has a Scene Manager";
    }

    return *_m_pSceneManager;
  }

  Scene::Scene() :
    _m_pSceneManager(nullptr),
    _m_root()
  {
    // Intentionally blank
    return;
  }

  Scene::~Scene()
  {
    _m_pSceneManager = nullptr;

    return;
  }

  void 
  Scene::_start()
  {
    start();

    return;
  }

  void 
  Scene::_enter()
  {
    enter();

    return;
  }

  void 
  Scene::_update()
  {
    update();

    return;
  }

  void 
  Scene::_exit()
  {
    exit();

    return;
  }
}