#pragma once

#include <Hakool/Utils/hkMatrix4.h>
#include <Hakool/Core/hkCorePrerequisites.h>
#include <Hakool/Core/hkIGameObjectComponent.h>

namespace hk
{
  class HK_CORE_EXPORT CameraComponent : public IGameObjectComponent
  {
  public:

    CameraComponent();

    CameraComponent(const CameraComponent& copy);

    CameraComponent&
    operator= (const CameraComponent& copy);

    virtual
    ~CameraComponent();

    virtual void
    init(GameObject* _m_pGameObject) override;
       
    virtual void
    update() override;

    virtual void
    draw(GraphicComponent* pGraphicComponent) override;

    virtual void
    destroy() override;

    virtual eCOMPONENT
    getID() override;
    
    virtual GameObject*
    getGameObject() override;

    const Color&
    getBackgroundColor() const;

    void
    setBackgroundColor(const Color& color);

    void
    setNear(const float& near);

    const float&
    getNear() const;

    void
    setFar(const float& far);

    const float&
    getFar() const;

    void
    setAspectRatio(const float& aspectRatio);

    const float&
    getAspectRatio() const;

    void
    setFieldOfView(const float& fov);

    const float&
    getFieldOfView() const;

    void
    setProjection(const ePROJECTION& projection);

    Matrix4&
    getProjectionMatrix();

  private:

    ePROJECTION
    _m_projectionType;

    Matrix4
    _m_projection;

    Color
    _m_backgroundColor;

    float
    _m_near;

    float
    _m_far;

    float
    _m_aspect;

    float
    _m_fov;

    bool
    _m_isDirtyProjection;

    GameObject*
    _m_pGameObject;
  };
}