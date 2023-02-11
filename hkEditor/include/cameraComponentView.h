#pragma once

#include <Hakool/Utils/hkVector3.h>

namespace hk
{
  class CameraComponent;

  namespace editor
  {
    class CameraComponentView
    {
    public:

      CameraComponentView(CameraComponent* cameraComponent);

      void
      updateController();

      void
      draw();

    private:

      CameraComponent* _m_pComponent;

      Vector3f _m_position;

      Vector3f _m_clearColor;

      float _m_fov;
    };
  }
}