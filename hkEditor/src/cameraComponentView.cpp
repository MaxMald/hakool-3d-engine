#include "cameraComponentView.h"

#include <Hakool/Core/hkCameraComponent.h>
#include <imgui.h>

namespace hk
{
  namespace editor
  {
    CameraComponentView::CameraComponentView(CameraComponent* pComponent) :
      _m_pComponent(pComponent),
      _m_position(pComponent->getPosition()),
      _m_clearColor(pComponent->getClearColor().toVector3()),
      _m_fov(pComponent->getFieldOfView())
    { }

    void
    CameraComponentView::updateController()
    {
      _m_pComponent->setFieldOfView(_m_fov);
      _m_pComponent->setClearColor(Color(_m_clearColor.x, _m_clearColor.y, _m_clearColor.z));
    }

    void
    CameraComponentView::draw()
    {
      _m_position = _m_pComponent->getPosition();
      _m_fov = _m_pComponent->getFieldOfView();
      _m_clearColor = _m_pComponent->getClearColor().toVector3();

      ImGui::Begin("Camera Component");
      ImGui::InputFloat3("position", _m_position.a);
      ImGui::InputFloat("FOV", &_m_fov);
      ImGui::ColorEdit3("clear color", _m_clearColor.a);
      ImGui::End();
    }
  }
}