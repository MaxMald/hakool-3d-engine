#include <Hakool/Core/hkGameObjectBuilder.h>
#include <Hakool/Core/hkGameObject.h>

namespace hk
{
  GameObjectBuilder::GameObjectBuilder() :
    _m_pActiveGameObject(nullptr)
  { }

  GameObjectBuilder::~GameObjectBuilder()
  {
    if (_m_pActiveGameObject != nullptr)
    {
      _m_pActiveGameObject->destroy();
      delete _m_pActiveGameObject;
    }
  }

  GameObjectBuilder& 
  GameObjectBuilder::startDesign(String name)
  {
    if (_m_pActiveGameObject != nullptr)
    {
      throw std::exception("GameObjectBuilder hasn't finished the construction of the current GameObject.");
    }

    _m_pActiveGameObject = new GameObject(name);
    return *this;
  }

  GameObjectBuilder& 
  GameObjectBuilder::startDesign(String name, GameObject* pParent)
  {
    if (_m_pActiveGameObject != nullptr)
    {
      throw std::exception("GameObjectBuilder hasn't finished the construction of the current GameObject.");
    }

    try 
    {
      _m_pActiveGameObject = new GameObject(name, *pParent);
    }
    catch (...)
    {
      throw;
    }
    return *this;
  }

  GameObjectBuilder& 
  GameObjectBuilder::position(const Vector3f& pos)
  {
    _m_pActiveGameObject->setLocalPosition(pos);
    return *this;
  }

  GameObjectBuilder& 
  GameObjectBuilder::component(IGameObjectComponent* pComponent)
  {
    try
    {
      _m_pActiveGameObject->addComponent(pComponent);
    }
    catch (...)
    {
      if (_m_pActiveGameObject != nullptr)
      {
        delete _m_pActiveGameObject;
        _m_pActiveGameObject = nullptr;
      }

      throw;
    }
    return *this;
  }

  GameObject* 
  GameObjectBuilder::build()
  {
    if (_m_pActiveGameObject != nullptr)
    {
      throw std::exception("GameObjectBuilder doesn't have an active GameObject.");
    }

    _m_pActiveGameObject->init();

    GameObject* pGameObject = _m_pActiveGameObject;
    _m_pActiveGameObject = nullptr;
    return pGameObject;
  }
}