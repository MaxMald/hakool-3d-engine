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
    Camera(const uint32& id);

    /**
    * Destructor.
    */
    ~Camera();

    /**
    * Set the camera's near value.
    * 
    * @param _near Near.
    */
    void
    setNear(const float& _near);

    const float&
    getNear() const;

    /**
    * Set the camera's far value.
    * 
    * @param _far Far.
    */
    void
    setFar(const float& _far);
    
    const float&
    getFar() const;

    /**
    * Set the field of view of this camera.
    * 
    * @param _fov Field of view.
    */
    void
    setFieldOfView(const float& _fov);
    
    const float&
    getFieldOfView() const;

    /**
    * Set aspect ratio of this camera.
    * 
    * @param _aspect Aspect ratio.
    */
    void
    setAspectRatio(const float& _aspect);

    const float&
    getAspectRatio() const;

    /**
    * Set the target's position of this camera.
    * 
    * @param _target Target's position.
    */
    void
    setTarget(const Vector3f& _target);

    /**
    * Set the target's position of this camera.
    * 
    * @param _x X.
    * @param _y Y.
    * @param _z Z.
    */
    void
    setTarget(const float& _x, const float& _y, const float& _z);

    const Vector3f&
    getTarget() const;

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

    const Vector3f&
    getPosition() const;

    void
    setViewMatrix(
      const Vector3f& _position,
      const Vector3f& _target,
      const Vector3f& _up);

    void
    setViewMatrix(
      const float& _posX,
      const float& _posY,
      const float& _posZ,
      const float& _targetX,
      const float& _targetY,
      const float& _targetZ,
      const float& _upX,
      const float& _upY,
      const float& _upZ);

    void
    setProjection(const ePROJECTION& projection);
    
    const Matrix4&
    getProjectionMatrix() const;

    const Matrix4&
    getViewMatrix() const;

    const uint32&
    getCameraId() const;

  private:
    
    Camera(const Camera& _camera) = delete;

    Camera&
    operator= (const Camera& copy) = delete;

    uint32
    _m_cameraId;

    /**
    * Field of view.
    */
    float 
    _m_fov;

    /**
    * Aspect ratio.
    */
    float 
    _m_aspect;

    /**
    * Near.
    */
    float 
    _m_near;

    /**
    * Far.
    */
    float 
    _m_far;

    /**
    * Up vector.
    */
    Vector3f 
    _m_up;

    /**
    * Camera's position.
    */
    Vector3f 
    _m_position;

    /**
    * Camera's target
    */
    Vector3f 
    _m_target;

    /**
    * Indicates the type of view of this camera.
    */
    ePROJECTION 
    _m_projectionType;

    /**
    * View matrix.
    */
    mutable Matrix4 
    _m_view;

    /**
    * Projection matrix.
    */
    mutable Matrix4 
    _m_projection;

    /**
    * Indicates if the Projection matrix requires a recalculation.
    */
    mutable bool 
    _m_isDirtyProjection;

    /**
     * Indicates if the View matrix requires a recalculation.
     */
    mutable bool
    _m_isDirtyView;
  };
}