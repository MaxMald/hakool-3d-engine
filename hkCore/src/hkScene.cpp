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

  GameObject& 
  Scene::createGameObject(String _name)
  {
    if (_m_root.hasChild(_name))
    {
      Logger::Error("| Scene | The scene's root already has a GameObject of name: " + _name + ".");
      return GameObject::GetNull();
    }

    GameObject* pNewGameObject = new GameObject(_name);
    registerGameObject(*pNewGameObject);
    _m_root.addChild(*pNewGameObject);

    return *pNewGameObject;
  }

  GameObject& 
  Scene::createGameObject(String _name, String _parentPath)
  {
    GameObject& parent = getGameObject(_parentPath);
    if (GameObject::IsNull(parent))
    {
      Logger::Error("| Scene | Parent was not found. Parent's path: " + _parentPath + ".");
      return GameObject::GetNull();
    }

    if (parent.hasChild(_name))
    {
      Logger::Error("| Scene | Parent already has a GameObject of name: " + _name + ".");
      return GameObject::GetNull();
    }

    GameObject* pNewGameObject = new GameObject(_name);
    registerGameObject(*pNewGameObject);
    parent.addChild(*pNewGameObject);

    return *pNewGameObject;
  }

  bool
  Scene::hasGameObject(const String& _path)
  {      
    return !GameObject::IsNull(_m_root.getGameObjectByPath(_path));
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

  void 
  Scene::registerGameObject(GameObject& _gameObject)
  {
    // Check if GameObject is already registered.
    if (hasRegisteredGameObject(_gameObject))
    {
      Logger::Log("| Scene | GameObject: " + _gameObject.getName() + " is already registered in this scene.");
      return;
    }

    // Dettach GameObject from current scene.
    if (_gameObject._m_pScene != nullptr)
    {
      _gameObject._m_pScene->unregisterGameObject(_gameObject);
    }
    _gameObject._m_pScene = this;
    
    // Add GameObject to list.
    String uuid = _gameObject._m_uuid;
    _m_hGameObjects.insert(Map<String, GameObject*>::value_type(uuid, &_gameObject));
  }

  void 
  Scene::unregisterGameObject(const String& _uuid)
  {
    // Check if GameObject is registered.
    if (!hasRegisteredGameObject(_uuid))
    {
      Logger::Error("| Scene | GameObject with UUID: " + _uuid + " doesn't exists in this scene.");
      return;
    }

    // Dettach GameObject from this scene.
    GameObject* pGameObject = _m_hGameObjects.find(_uuid)->second;
    pGameObject->_m_pScene = nullptr;

    // Remove reference.
    _m_hGameObjects.erase(_uuid);

    return;
  }

  void 
  Scene::unregisterGameObject(GameObject& _gameObject)
  {
    unregisterGameObject(_gameObject.getUUID());
    return;
  }

  bool 
  Scene::hasRegisteredGameObject(const String& _uuid) const
  {
    return _m_hGameObjects.find(_uuid) != _m_hGameObjects.end();
  }

  bool
  Scene::hasRegisteredGameObject(const GameObject& _gameObject) const
  {
    return _m_hGameObjects.find(_gameObject.getUUID()) != _m_hGameObjects.end();
  }

  Scene::Scene() :
    _m_pSceneManager(nullptr),
    _m_root("__root")
  {
    // Intentionally blank
    return;
  }

  Scene::~Scene()
  {
    _destroy();
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
    // Update each registered GameObject.
    for (auto it : _m_hGameObjects)
    {
      it.second->update();
    }

    update();

    return;
  }

  void 
  Scene::_exit()
  {
    exit();

    return;
  }
  
  void 
  Scene::_destroy()
  {
    // Destroy scene root.
    _m_root.destroy();

    if (_m_hGameObjects.size() > 0)
    {
      // Delete each registered GameObject.
      for (auto it : _m_hGameObjects)
      {
        delete it.second;
      }

      // Clear map.
      _m_hGameObjects.clear();
    }

    return;
  }
}