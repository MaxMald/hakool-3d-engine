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
  Scene::createGameObject(const String& _name)
  {
    if (_m_root.hasChild(_name))
    {
      throw "Scene's root already has a child with name: " + _name;
    }

    GameObject* pNewGameObject = new GameObject(_name, _m_root);
    pNewGameObject->_m_pScene = this;

    // TODO ADD GAME OBJECT TO LIST

    return *pNewGameObject;
  }

  void 
  Scene::addGameObject(GameObject* _pGameObject)
  {
    if (_m_root.hasChild(_pGameObject->getName()))
    {
      throw "Scene's root already has a child with name: " + _pGameObject->getName();
    }

    // TODO REMOVE GAME OBJECT FROM CURRENT SCENE.

    _pGameObject->_m_pScene = this;

    // TODO ADD GAME OBJECT TO LIST.

    return;
  }

  bool
  Scene::hasGameObject(const String& _name)
  {
    return _m_root.hasChild(_name);
  }

  GameObject& 
  Scene::getGameObject(const String& _name)
  {
    return _m_root.getChild(_name);
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
    _m_hGameObjects(),
    _m_root(),
    _m_lTrashCan()
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