#include <Hakool\Core\hkGameObject.h>

namespace hk
{
  GameObject::GameObject() :
    Node<GameObject>(),
    _m_hComponents(),
    _m_toDestroy(false),
    _m_isInitialized(false),
    _m_pScene(nullptr)
  {
    // Intentionally blank
    return;
  }

  GameObject::GameObject(const String& _name) :
    Node<GameObject>(_name),
    _m_toDestroy(false),
    _m_isInitialized(false),
    _m_hComponents(),
    _m_pScene(nullptr)
  {
    // Intentionally blank
    return;
  }

  GameObject::GameObject(const String& _name, GameObject& _pParent) : 
    Node<GameObject>(_name, _pParent),
    _m_toDestroy(false),
    _m_isInitialized(false),
    _m_hComponents(),
    _m_pScene(nullptr)
  {
    // Intentionally blank
    return;
  }

  GameObject::~GameObject()
  {
    destroy();
    return;
  }

  void 
  GameObject::init()
  {
    if (!_m_isInitialized)
    {
      // Create callback
      for (auto iterator : _m_hComponents)
      {
        iterator.second->create();
      }

      // Init callback
      for (auto iterator : _m_hComponents)
      {
        iterator.second->init();
      }

      _m_isInitialized = !_m_isInitialized;
    }

    return;
  }

  void 
  GameObject::update()
  {
    for (auto iterator : _m_hComponents)
    {
      iterator.second->update();
    }

    return;
  }

  void
  GameObject::addComponent(Component* _pComponent)
  {
    eCOMPONENT type = _pComponent->getID();
    if (hasComponent(type))
    {
      throw "GameObject: " + getName() + " Component with same type already exists.";
    }

    if (_pComponent->_m_pGameObject != nullptr) {
      throw "GameObject: " + getName() + ": Component is already attached to a game object.";
    }

    _m_hComponents.insert
    (
      Map<eCOMPONENT, Component*>::value_type(type, _pComponent)
    );

    _pComponent->_m_pGameObject = this;

    if (_m_isInitialized)
    {
      _pComponent->create();
      _pComponent->init();
    }

    return;
  }

  bool 
  GameObject::hasComponent(const eCOMPONENT& _id)
  {
    return _m_hComponents.find(_id) != _m_hComponents.end();
  }

  void 
  GameObject::detroyComponent(const eCOMPONENT& _id)
  {
    if (!hasComponent(_id))
    {
      return;
    }

    Component* pComponent = _m_hComponents.find(_id)->second;
    pComponent->destroy();
    delete pComponent;
    _m_hComponents.erase(_id);
    
    return;
  }

  bool 
  GameObject::onScene()
  {
    return _m_pScene != nullptr;
  }

  Scene& 
  GameObject::getScene()
  {
    return *_m_pScene;
  }

  void
  GameObject::destroy()
  {
    Component* pComponent = nullptr;
    for (auto iterator : _m_hComponents)
    {
      pComponent = iterator.second;
      pComponent->destroy();
      delete pComponent;
    }

    _m_hComponents.clear();

    return;
  }
}