#include <Hakool/Core/hkGameObject.h>
#include <imgui.h>
#include "gameObjectView.h"

namespace hk
{
  namespace editor
  {
    GameObjectView::GameObjectView() :
      _m_pGameObject(nullptr),
      _m_position()
    { }

    GameObjectView::~GameObjectView()
    { }

    void
    GameObjectView::setGameObject(GameObject* pGameObject)
    {
      _m_pGameObject = pGameObject;
    }

    void
    GameObjectView::draw()
    {
      if (_m_pGameObject == nullptr)
        return;

      ImGui::Begin("GameObject Viewer");
      ImGui::Text("Name: %", _m_pGameObject->getName().c_str());
      ImGui::InputFloat3("position", _m_position.a);
      ImGui::End();
    }

    void
    GameObjectView::update()
    {
      if (_m_pGameObject == nullptr)
        return;

      _m_position = _m_pGameObject->getLocalPosition();
    }
  }
}