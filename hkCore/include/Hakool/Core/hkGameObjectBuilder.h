#pragma once

#include <Hakool/Utils/hkVector3.h>
#include <Hakool/Core/hkCorePrerequisites.h>

namespace hk
{

  class GameObject;
  class IGameObjectComponent;

  class HK_CORE_EXPORT GameObjectBuilder
  {

  public:

    GameObjectBuilder();

    ~GameObjectBuilder();

    GameObjectBuilder&
    startDesign(String name);

    GameObjectBuilder&
    startDesign(String name, GameObject* pParent);

    GameObjectBuilder&
    position(const Vector3f& pos);

    GameObjectBuilder&
    component(IGameObjectComponent* pComponent);

    GameObject*
    build();

  private:

    GameObject*
    _m_pActiveGameObject;

    GameObjectBuilder(const GameObjectBuilder&) = delete;
    GameObjectBuilder&
    operator= (const GameObjectBuilder&) = delete;
  };
}