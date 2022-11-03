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
  Scene::draw()
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
    _m_root.addChild(pNewGameObject);
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
    parent.addChild(pNewGameObject);

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

  Scene::Scene() :
    _m_pSceneManager(nullptr),
    _m_root("__root")
  {
    _m_root._m_pScene = this;
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
    _m_root.update();
    update();
    return;
  }

  void 
  Scene::_draw(GraphicComponent* pGraphicComponent)
  {
    _m_root.draw(pGraphicComponent);
    draw();
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
    _m_root.destroy();
    destroy();
    return;
  }
}