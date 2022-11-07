#pragma once

#include "Hakool/Utils/hkMatrix4.h"

#include "Hakool/Core/hkCorePrerequisites.h"
#include "Hakool/Core/hkCoreUtilities.h"

namespace hk
{
  /**
  * Class to render objects in Hakool. It can be rotated, positioned and zoomed.
  */
  class HK_CORE_EXPORT Camera
  {
  public:

    /**
    * Create a camera with default values.
    */
    Camera();

    /**
    * Create a copy from another camera.
    */
    Camera(const Camera& _camera);

    /**
    * Destructor.
    */
    ~Camera();

    /**
    *
    */
    void
    init(const eCAMERA_VIEW& _view);

    /**
    * Safely destroys this camera.
    */
    void
    destroy();

    /**
    * Get the view (look-at) matrix of this camera.
    * 
    * @return Reference to the view matrix.
    */
    Matrix4&
    getViewMatrix();

    /**
    * Get the perspective matrix of this camera.
    * 
    * @return Reference to the perspective matrix.
    */
    Matrix4&
    getPerspectiveMatrix();

    /**
    * Set the camera's near value.
    * 
    * @param _near Near.
    */
    void
    setNear(const float& _near);

    /**
    * Set the camera's far value.
    * 
    * @param _far Far.
    */
    void
    setFar(const float& _far);

    /**
    * Set the field of view of this camera.
    * 
    * @param _fov Field of view.
    */
    void
    setFOV(const float& _fov);

    /**
    * Set aspect ratio of this camera.
    * 
    * @param _aspect Aspect ratio.
    */
    void
    setAspectRatio(const float& _aspect);

    /**
    * Set the target's position of this camera.
    * 
    * @param _target Target's position.
    */
    void
    SetTarget(const Vector3f& _target);

    /**
    * Set the target's position of this camera.
    * 
    * @param _x X.
    * @param _y Y.
    * @param _z Z.
    */
    void
    setTarget(const float& _x, const float& _y, const float& _z);

    /**
    * Set the camera's position.
    * 
    * @param _position Camera's position.
    */
    void
    setPosition(const Vector3f& _position);

    /**
    * Set the camera's position.
    * 
    * @param _x X.
    * @param _y Y.
    * @param _z Z.
    */
    void
    setPosition(const float& _x, const float& _y, const float& _z);

    /**
    * Set this camera with perspective view.
    * 
    * @param _fov Field of view.
    * @param _aspect Aspect ration.
    * @param _near Near.
    * @param _far Far.
    */
    void
    setPerspective
    (
      const float& _fov, 
      const float& _aspect, 
      const float& _near, 
      const float& _far
    );

    /**
    * Set this camera with orthographic view.
    * 
    * @param _left Left.
    * @param _top Top.
    * @param _right Right.
    * @param _bottom Bottom.
    * @param _near Near.
    * @param _far Far.
    */
    void
    setOrthographic
    (
      const float& _left,
      const float& _top,
      const float& _right,
      const float& _bottom,
      const float& _near,
      const float& _far
    );

    /**
    * Set the view matrix of this camera.
    * 
    * @param _position Camera's position.
    * @param _target Camera's target.
    * @param _up Camera's up.
    */
    void
    setViewMatrix
    (
      const Vector3f& _position,
      const Vector3f& _target,
      const Vector3f& _up
    );

    /**
    * Set the view matrix of this camera.
    * 
    * @param _posX Position X value.
    * @param _posY Position Y value.
    * @param _posZ Position Z value.
    * @param _targetX Target's position X value.
    * @param _targetY Target's position Y value.
    * @param _targetZ Target's position Z value.
    * @param _upX Up X value.
    * @param _upY Up Y value.
    * @param _upZ Up Z value.
    */
    void
    setViewMatrix
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
    );

    /**
    * Get the view type of this camera.
    * 
    * @returns Camera's view type.
    */
    eCAMERA_VIEW
    getCameraViewType();

  private:
  
    /**
    * Update camera's matrices.
    */
    void
    _updateMatrices();

    /**
    * Field of view.
    */
    float _m_fov;

    /**
    * Aspect ratio.
    */
    float _m_aspect;

    /**
    * Near.
    */
    float _m_near;

    /**
    * Far.
    */
    float _m_far;

    /**
    * Left.
    */
    float _m_left;

    /**
    * Right.
    */
    float _m_right;

    /**
    * Top.
    */
    float _m_top;

    /**
    * Down.
    */
    float _m_bottom;

    /**
    * Up vector.
    */
    Vector3f _m_up;

    /**
    * Camera's position.
    */
    Vector3f _m_position;

    /**
    * Camera's target
    */
    Vector3f _m_target;

    /**
    * Indicates the type of view of this camera.
    */
    eCAMERA_VIEW _m_viewType;

    /**
    * View matrix.
    */
    Matrix4 _m_view;

    /**
    * Perspective matrix.
    */
    Matrix4 _m_perspective;

    /**
    * Indicates if the camera matrices need to be updated.
    */
    bool _m_isDirty;
  };
}