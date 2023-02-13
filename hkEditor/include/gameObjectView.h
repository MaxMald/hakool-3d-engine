#include <Hakool/Utils/hkVector3.h>
#include "imguiView.h"

namespace hk
{
  class GameObject;

  namespace editor
  {
    class GameObjectView : public ImguiView
    {
    public:

      GameObjectView();

      ~GameObjectView();

      void
      setGameObject(GameObject* pGameObject);

      virtual void
      update() override;

      virtual void
      draw() override;

    private:

      GameObject*
      _m_pGameObject;

      Vector3f
      _m_position;
    };
  }
}