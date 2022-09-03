#include <Hakool/Core/Graphics/hkCamera.h>

namespace hk
{
  Camera::Camera() :
    _m_fov(1.0474f),
    _m_aspect(1.0f),
    _m_near(0.1f),
    _m_far(1000.0f),
    _m_left(100.0f),
    _m_top(100.0f),
    _m_right(100.0f),
    _m_bottom(100.0f),
    _m_viewType(eCAMERA_VIEW::kPerspective),
    _m_view(),
    _m_perspective(),
    _m_up(0.0f, 1.0f, 0.0f),
    _m_position(),
    _m_target(0.0, 0.0, 1.0f),
    _m_isDirty(true)
  {
    // Intentionally blank.
    return;
  }

  Camera::Camera(const Camera& _camera) :
    _m_fov(_camera._m_fov),
    _m_aspect(_camera._m_aspect),
    _m_near(_camera._m_near),
    _m_far(_camera._m_far),
    _m_left(_camera._m_left),
    _m_top(_camera._m_top),
    _m_right(_camera._m_right),
    _m_bottom(_camera._m_bottom),
    _m_viewType(_camera._m_viewType),
    _m_view(_camera._m_view),
    _m_perspective(_camera._m_perspective),
    _m_up(_camera._m_up),
    _m_position(_camera._m_position),
    _m_target(_camera._m_target),
    _m_isDirty(true)
  {
    // Intentionally blank.
    return;
  }

  Camera::~Camera()
  {
    destroy();
    return;
  }

  void
  Camera::init(const eCAMERA_VIEW& _view)
  {
    // TODO
    return;
  }

  void
  Camera::destroy()
  {
    // TODO
    return;
  }

  Matrix4&
  Camera::getViewMatrix()
  {
    if (_m_isDirty)
    {
      _updateMatrices();
      _m_isDirty = !_m_isDirty;
    }

    return _m_view;
  }

  Matrix4&
  Camera::getPerspectiveMatrix()
  {
    if (_m_isDirty)
    {
      _updateMatrices();
      _m_isDirty = !_m_isDirty;
    }

    return _m_perspective;
  }

  void
  Camera::setNear(const float& _near)
  {
    _m_near = _near;
    _m_isDirty = true;

    return;
  }

  void
  Camera::setFar(const float& _far)
  {
    _m_far = _far;
    _m_isDirty = true;

    return;
  }

  void
  Camera::setFOV(const float& _fov)
  {
    _m_fov = _fov;
    _m_isDirty = true;

    return;
  }

  void
  Camera::setAspectRatio(const float& _aspect)
  {
    _m_aspect = _aspect;
    _m_isDirty = true;

    return;
  }

  void
  Camera::SetTarget(const Vector3f& _target)
  {
    _m_target = _target;
    _m_isDirty = true;

    return;
  }

  void
  Camera::setTarget(const float& _x, const float& _y, const float& _z)
  {
    _m_target.x = _x;
    _m_target.y = _y;
    _m_target.z = _z;
    _m_isDirty = true;

    return;
  }

  void
  Camera::setPosition(const Vector3f& _position)
  {
    _m_position = _position;
    _m_isDirty = true;

    return;
  }

  void
  Camera::setPosition(const float& _x, const float& _y, const float& _z)
  {
    _m_position.x = _x;
    _m_position.y = _y;
    _m_position.z = _z;
    _m_isDirty = true;

    return;
  }

  void
  Camera::setPerspective
  (
    const float& _fov,
    const float& _aspect,
    const float& _near,
    const float& _far
  )
  {
    _m_fov = _fov;
    _m_aspect = _aspect;
    _m_near = _near;
    _m_far = _far;
    _m_viewType = eCAMERA_VIEW::kPerspective;
    _m_isDirty = true;

    return;
  }

  void
  Camera::setOrthographic
  (
    const float& _left,
    const float& _top,
    const float& _right,
    const float& _bottom,
    const float& _near,
    const float& _far
  )
  {
    _m_left = _left;
    _m_top = _top;
    _m_right = _right;
    _m_bottom = _bottom;
    _m_near = _near;
    _m_far = _far;
    _m_viewType = eCAMERA_VIEW::kOrthographic;
    _m_isDirty = true;

    return;
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
    _m_isDirty = true;

    return;
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
    _m_isDirty = true;

    return;
  }

  eCAMERA_VIEW
  Camera::getCameraViewType()
  {
    return _m_viewType;
  }

  void 
  Camera::_updateMatrices()
  {
    // Update perspective matrix.
    if (_m_viewType == eCAMERA_VIEW::kPerspective)
    {
      _m_perspective.setPerspective(_m_fov, _m_aspect, _m_near, _m_far);
    }
    else
    {
      _m_perspective.setOrthographic
      (
        _m_left,
        _m_top,
        _m_right,
        _m_bottom,
        _m_near,
        _m_far
      );
    }

    // Update look-at matrix.
    _m_view.setLookAt(_m_position, _m_target, _m_up);

    return;
  }
}