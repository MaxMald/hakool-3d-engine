#pragma once

#include "Hakool/Utils/hkMatrix4.h"

#include "Hakool/Core/hkCorePrerequisites.h"
#include "Hakool/Core/hkCoreUtilities.h"

namespace hk
{
  /**
  * 
  */
  class HK_CORE_EXPORT Camera
  {
  public:

    /**
    * 
    */
    Camera();

    /**
    *
    */
    Camera(const Camera& _camera);

    /**
    *
    */
    ~Camera();

    /**
    *
    */
    void
    init(const eCAMERA_VIEW& _view);

    /**
    *
    */
    void
    destroy();

    /**
    *
    */
    Matrix4&
    getViewMatrix() const;

    /**
    *
    */
    Matrix4&
    getPerspectiveMatrix() const;

  private:

    /**
    * View matrix.
    */
    Matrix4 _m_view;

    /**
    * Perspective matrix.
    */
    Matrix4 _m_perspective;
  };
}