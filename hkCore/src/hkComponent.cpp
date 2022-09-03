#include <Hakool\Core\hkComponent.h>

namespace hk
{
  Component::Component() : 
    _m_pGameObject(nullptr),
    _m_id(eCOMPONENT::kUndefined)
  {
    // Intentionally blank
    return;
  }

  Component::Component(const eCOMPONENT& _m_id) :
    _m_pGameObject(nullptr),
    _m_id(_m_id)
  {
    // Intentionally blank
    return;
  }

  Component::~Component()
  {
    // Intentionally blank
    return;
  }

  void 
  Component::create()
  {
    // Intentionally blank
    return;
  }

  void 
  Component::init()
  {
    // Intentionally blank
    return;
  }

  void 
  Component::update()
  {
    // Intentionally blank
    return;
  }

  void 
  Component::destroy()
  {
    // Intentionally blank
    return;
  }

  eCOMPONENT 
  Component::getID()
  {
    return _m_id;
  }
}