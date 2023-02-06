#include <Hakool/Core/hkCamera.h>

namespace hk
{
  Camera::Camera(const uint32& id) :
    _m_cameraId(id),
    _m_fov(1.0474f),
    _m_aspect(1.0f),
    _m_near(0.1f),
    _m_far(1000.0f),
    _m_up(0.0f, 1.0f, 0.0f),
    _m_position(),
    _m_target(0.0, 0.0, 1.0f),
    _m_projectionType(ePROJECTION::kPerspective),
    _m_view(),
    _m_projection(),
    _m_isDirtyProjection(true),
    _m_isDirtyView(true)
  { }

  Camera::~Camera()
  { }

  void
  Camera::setNear(const float& _near)
  {
    _m_near = _near;
    _m_isDirtyProjection = true;
  }

  const float& 
  Camera::getNear() const
  {
    return _m_near;
  }

  void
  Camera::setFar(const float& _far)
  {
    _m_far = _far;
    _m_isDirtyProjection = true;
  }

  const float& 
  Camera::getFar() const
  {
    return _m_far;
  }

  void
  Camera::setFieldOfView(const float& _fov)
  {
    _m_fov = _fov;
    _m_isDirtyProjection = true;
  }

  const float& 
  Camera::getFieldOfView() const
  {
    return _m_fov;
  }

  void
  Camera::setAspectRatio(const float& _aspect)
  {
    _m_aspect = _aspect;
    _m_isDirtyProjection = true;
  }

  const float&
  Camera::getAspectRatio() const
  {
    return _m_aspect;
  }

  void
  Camera::setTarget(const Vector3f& _target)
  {
    _m_target = _target;
    _m_isDirtyView = true;
  }

  void
  Camera::setTarget(const float& _x, const float& _y, const float& _z)
  {
    _m_target.x = _x;
    _m_target.y = _y;
    _m_target.z = _z;
    _m_isDirtyView = true;
  }

  const Vector3f& 
  Camera::getTarget() const
  {
    return _m_target;
  }

  void
  Camera::setPosition(const Vector3f& _position)
  {
    _m_position = _position;
    _m_isDirtyView = true;
  }

  void
  Camera::setPosition(const float& _x, const float& _y, const float& _z)
  {
    _m_position.x = _x;
    _m_position.y = _y;
    _m_position.z = _z;
    _m_isDirtyView = true;
  }

  const Vector3f& 
  Camera::getPosition() const
  {
    return _m_position;
  }

  void 
  Camera::setViewMatrix
  (
    const Vector3f& _position,
    const Vector3f& _target,
    const Vector3f& _up
  )
  {
    _m_position = _position;
    _m_target = _target;
    _m_up = _up;
    _m_isDirtyView = true;
  }

  void 
  Camera::setViewMatrix
  (
    const float& _posX,
    const float& _posY,
    const float& _posZ,
    const float& _targetX,
    const float& _targetY,
    const float& _targetZ,
    const float& _upX,
    const float& _upY,
    const float& _upZ
  )
  {
    _m_position.x = _posX;
    _m_position.y = _posY;
    _m_position.z = _posZ;
    _m_target.x = _targetX;
    _m_target.y = _targetY;
    _m_target.z = _targetZ;
    _m_up.x = _upX;
    _m_up.y = _upY;
    _m_up.z = _upZ;
    _m_isDirtyView = true;
  }

  const Matrix4&
  Camera::getProjectionMatrix() const
  {
    if (_m_isDirtyProjection)
    {
      if (_m_projectionType == ePROJECTION::kPerspective)
      {
        _m_projection.setPerspective(_m_fov, _m_aspect, _m_near, _m_far);
      }
      else
      {
        // TODO implement orthographic
        _m_projection.setPerspective(_m_fov, _m_aspect, _m_near, _m_far);
      }
      _m_isDirtyProjection = false;
    }

    return _m_projection;
  }

  const Matrix4&
  Camera::getViewMatrix() const
  {
    if (_m_isDirtyView)
    {
      // TODO implement view.
      _m_isDirtyView = false;
    }

    return _m_view;
  }

  const uint32&
  Camera::getCameraId() const
  {
    return _m_cameraId;
  }
}