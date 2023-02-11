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
  CameraComponent::getClearColor() const
  {
    return _m_pCamera->getClearColor();
  }

  void 
  CameraComponent::setClearColor(const Color& color)
  {
    _m_pCamera->setClearColor(color);
  }

  void 
  CameraComponent::setNear(const float& near)
  {
    _m_pCamera->setNear(near);
  }

  const float& 
  CameraComponent::getNear() const
  {
    return _m_pCamera->getNear();
  }

  void 
  CameraComponent::setFar(const float& far)
  {
    _m_pCamera->setFar(far);
  }

  const float& 
  CameraComponent::getFar() const
  {
    return _m_pCamera->getFar();
  }

  void 
  CameraComponent::setAspectRatio(const float& aspectRatio)
  {
    _m_pCamera->setAspectRatio(aspectRatio);
  }

  const float& 
  CameraComponent::getAspectRatio() const
  {
    return _m_pCamera->getAspectRatio();
  }

  void 
  CameraComponent::setFieldOfView(const float& fov)
  {
    _m_pCamera->setFieldOfView(fov);
  }

  const float& 
  CameraComponent::getFieldOfView() const
  {
    return _m_pCamera->getFieldOfView();
  }

  void 
  CameraComponent::setProjection(const ePROJECTION& projection)
  {
    _m_projectionType = projection;
    _m_isDirtyProjection = true;
  }

  const Vector3f &
  CameraComponent::getPosition()
  {
    return _m_pCamera->getPosition();
  }

  const uint32&
  CameraComponent::getCameraId()
  {
    return _m_cameraId;
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