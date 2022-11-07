#pragma once

#include <Hakool/Utils/hkVector3.h>
#include <Hakool/Utils/hkMatrix4.h>

#include <Hakool/Core/hkCorePrerequisites.h>
#include <Hakool/Core/hkComponent.h>

namespace hk
{
  /**
  * TODO
  */
  class HK_CORE_EXPORT TransformComponent : public Component
  {
  public:

    TransformComponent();

    virtual ~TransformComponent();

    void
    init(GameObject* pGameObject);

    void
    update();

    void
    draw(GraphicComponent* pGraphicComponent);

    void
    destroy();

    eCOMPONENT
    getID();

    GameObject*
    getGameObject();

    TransformComponent*
    getParent();

    void
    setParent(TransformComponent* pParent);

    const Vector3f&
    getLocalPosition() const;

    void
    setLocalPosition(const Vector3f&);

    Matrix4
    calculateLocalToParentMatrix();

  private:

    const Matrix4&
    _updateLocalToWorld();

    void
    _setDirty();

    GameObject*
    _m_pGameObject;

    TransformComponent*
    _m_pParent;

    Vector<TransformComponent*>
    _m_children;

    Vector3f
    _m_localPosition;

    Vector3f
    _m_localRotation;

    Vector3f
    _m_localScale;

    Matrix4
    _m_localToWorld;

    Matrix4
    _m_worldToLocal;

    float
    _m_isDirty;

    float
    _m_isInverseDirty;
  };
}