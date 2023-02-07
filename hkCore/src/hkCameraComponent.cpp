#include <Hakool/Core/hkCameraComponent.h>
#include <Hakool/Core/hkCameraManager.h>

namespace hk
{
  CameraComponent::CameraComponent(CameraManager& _cameraManager) :
    _m_projectionType(ePROJECTION::kPerspective),
    _m_projection(),
    _m_backgroundColor(Color::BLACK),
    _m_near(0.1f),
    _m_far(1000.0f),
    _m_aspect(1.0f),
    _m_fov(1.0472f),
    _m_isDirtyProjection(true),
    _m_pGameObject(nullptr),
    _m_pCameraManager(&_cameraManager)
  {
    _m_cameraId = _cameraManager.createCamera();
    _m_pCamera = _cameraManager.getCamera(_m_cameraId);
  }

  CameraComponent::CameraComponent(const CameraComponent& copy, CameraManager& _cameraManager) :
    _m_projectionType(copy._m_projectionType),
    _m_projection(copy._m_projection),
    _m_backgroundColor(copy._m_backgroundColor),
    _m_near(copy._m_near),
    _m_far(copy._m_far),
    _m_aspect(copy._m_aspect),
    _m_fov(copy._m_fov),
    _m_isDirtyProjection(true),
    _m_pGameObject(nullptr),
    _m_pCameraManager(copy._m_pCameraManager)
  {
    _m_cameraId = _m_pCameraManager->copyCamera(*copy._m_pCamera);
    _m_pCamera = _m_pCameraManager->getCamera(_m_cameraId);
  }

  CameraComponent& 
  CameraComponent::operator=(const CameraComponent& copy)
  {
    _m_projection = copy._m_projection;
    _m_backgroundColor = copy._m_backgroundColor;
    return *this;
  }

  CameraComponent::~CameraComponent()
  { }

  void 
  CameraComponent::init(GameObject* _m_pGameObject)
  {
    _m_pGameObject = _m_pGameObject;
  }

  void 
  CameraComponent::update()
  { }

  void 
  CameraComponent::draw(GraphicComponent* pGraphicComponent)
  { }

  void 
  CameraComponent::destroy()
  {
    _m_pCameraManager->destroyCamera(_m_cameraId);
  }

  eCOMPONENT 
  CameraComponent::getID()
  {
    return eCOMPONENT::kCamera;
  }

  GameObject* 
  CameraComponent::getGameObject()
  {
    return _m_pGameObject;
  }

  const Color& 
  CameraComponent::getBackgroundColor() const
  {
    return _m_backgroundColor;
  }

  void 
  CameraComponent::setBackgroundColor(const Color& color)
  {
    _m_backgroundColor = color;
  }

  void 
  CameraComponent::setNear(const float& near)
  {
    _m_near = near;
    _m_isDirtyProjection = true;
  }

  const float& 
  CameraComponent::getNear() const
  {
    return _m_near;
  }

  void 
  CameraComponent::setFar(const float& far)
  {
    _m_far = far;
    _m_isDirtyProjection = true;
  }

  const float& 
  CameraComponent::getFar() const
  {
    return _m_far;
  }

  void 
  CameraComponent::setAspectRatio(const float& aspectRatio)
  {
    _m_aspect = aspectRatio;
    _m_isDirtyProjection = true;
  }

  const float& 
  CameraComponent::getAspectRatio() const
  {
    return _m_aspect;
  }

  void 
  CameraComponent::setFieldOfView(const float& fov)
  {
    _m_fov = fov;
    _m_isDirtyProjection = true;
  }

  const float& 
  CameraComponent::getFieldOfView() const
  {
    return _m_fov;
  }

  void 
  CameraComponent::setProjection(const ePROJECTION& projection)
  {
    _m_projectionType = projection;
    _m_isDirtyProjection = true;
  }

  void 
  CameraComponent::setAsActiveCamera()
  {
    _m_pCameraManager->setActiveCamera(_m_cameraId);
  }

  Matrix4&
  CameraComponent::getProjectionMatrix()
  {
    if (_m_isDirtyProjection)
    {
      if (_m_projectionType == ePROJECTION::kPerspective)
      {
        _m_projection.setPerspective(_m_fov, _m_aspect, _m_near, _m_far);
      }
      else
      {
        // TODO Implement Orthographic Perspective.
        _m_projection.setPerspective(_m_fov, _m_aspect, _m_near, _m_far);
      }
      
      _m_isDirtyProjection = false;
    }

    return _m_projection;
  }
  
  void CameraComponent::dolly(int32 units)
  {
    Vector3f pos = _m_pCamera->getPosition();
    _m_pCamera->setPosition(
      pos.x,
      pos.y,
      pos.z + units
    );
  }
}