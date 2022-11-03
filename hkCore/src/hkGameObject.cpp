#include <Hakool\Utils\guid.hpp>

#include <Hakool\Core\hkGameObject.h>

using std::pair;

namespace hk
{
  GameObject::GameObject(const String& _name) :
    Node<GameObject>(_name),
    _m_toDestroy(false),
    _m_isInitialized(false),
    _m_hComponents(),
    _m_pScene(nullptr),
    _m_uuid(xg::newGuid()),
    _m_localPosition(0.0f, 0.0f, 0.0f),
    _m_localRotation(0.0f, 0.0f, 0.0f),
    _m_localScale(1.0f, 1.0f, 1.0f),
    _m_isDirty(true),
    _m_isInverseDirty(true)
  {
    return;
  }

  GameObject::GameObject(const String& _name, GameObject& _pParent) :
    Node<GameObject>(_name, _pParent),
    _m_toDestroy(false),
    _m_isInitialized(false),
    _m_hComponents(),
    _m_pScene(nullptr),
    _m_uuid(xg::newGuid()),
    _m_localPosition(0.0f, 0.0f, 0.0f),
    _m_localRotation(0.0f, 0.0f, 0.0f),
    _m_localScale(1.0f, 1.0f, 1.0f),
    _m_isDirty(true),
    _m_isInverseDirty(true)
  {
    return;
  }

  GameObject::~GameObject()
  {
    destroy();
    return;
  }

  bool
    GameObject::operator==(const GameObject& _gameObject)
  {
    return _m_uuid == _gameObject._m_uuid;
  }

  void
    GameObject::init()
  {
    if (!_m_isInitialized)
    {
      for (auto iterator : _m_hComponents)
      {
        iterator.second->init(this);
      }
      _m_isInitialized = !_m_isInitialized;
    }
    return;
  }

  void
    GameObject::update()
  {
    for (pair<const eCOMPONENT, Component*> item : _m_hComponents)
    {
      item.second->update();
    }
    return;
  }

  void
    GameObject::draw(GraphicComponent* pGraphicComponet)
  {
    for (pair<const eCOMPONENT, Component*> item : _m_hComponents)
    {
      item.second->draw(pGraphicComponet);
    }

    for (pair <String, GameObject*> item : _m_hChildren)
    {
      item.second->draw(pGraphicComponet);
    }
    return;
  }

  void
  GameObject::addComponent(Component* _pComponent)
  {
    eCOMPONENT type = _pComponent->getID();
    if (hasComponent(type))
    {
      throw "GameObject: " + getName() + " Component already exists.";
    }
    if (_pComponent->getGameObject() != nullptr) {
      throw "GameObject: " + getName() + ": Component is already attached to a game object.";
    }

    _m_hComponents.insert
    (
      Map<eCOMPONENT, Component*>::value_type(type, _pComponent)
    );

    if (_m_isInitialized)
    {
      _pComponent->init(this);
    }
    return;
  }

  bool 
  GameObject::hasComponent(const eCOMPONENT& _id) const
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
  GameObject::hasScene() const
  {
    return _m_pScene != nullptr;
  }

  Scene& 
  GameObject::getScene()
  {
    return *_m_pScene;
  }

  GameObject& 
  GameObject::getGameObjectByPath(String _path)
  {
    Queue<String> levels = Split(_path, "/");
    GameObject* pCurrent = this;

    while (levels.size() > 0)
    {
      String level = levels.front();
      levels.pop();

      pCurrent = &(pCurrent->getChild(level));
      if (IsNull(*pCurrent))
      {
        Logger::Error("| GameObject : " + getName() + " | Child not found. Path: " + _path);
        return *pCurrent;
      }
    }

    return *pCurrent;
  }

  String 
  GameObject::getUUID() const
  {
    return String(_m_uuid);
  }

  const Vector3f& 
  GameObject::getLocalPosition() const
  {
    return _m_localPosition;
  }

  void 
  GameObject::setLocalPosition(const Vector3f& localPosition)
  {
    _m_localPosition = localPosition;
    _setDirty();
    return;
  }

  Matrix4 
  GameObject::calculateLocalToParentMatrix()
  {
    // TODO
    return Matrix4();
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
    
    if (_m_hChildren.size() > 0)
    {
      for (auto child : _m_hChildren)
      {
        child.second->destroy();
        delete child.second;
      }
      _m_hChildren.clear();
    }
    return;
  }
  
  void 
  GameObject::_onParentChanged(GameObject* pParent)
  {
    _setScene(pParent->_m_pScene);
    _setDirty();
    return;
  }

  void 
  GameObject::_setScene(Scene* pScene)
  {
    _m_pScene = pScene;
    for (auto child : _m_hChildren)
    {
      child.second->_setScene(pScene);
    }
    return;
  }

  const Matrix4& 
  GameObject::_updateLocalToWorld()
  {
    // TODO
    _m_isDirty = false;
    return _m_localToWorld;
  }

  void 
  GameObject::_setDirty()
  {
    if (!_m_isDirty)
    {
      _m_isDirty = true;
      _m_isInverseDirty = true;

      for (auto child : _m_hChildren)
      {
        child.second->_setDirty();
      }
    }
    return;
  }
}