#include <Hakool\Core\hkEngineComponent.h>

namespace hk
{
  EngineComponent::EngineComponent(const eENGINE_COMPONENT& _id) :
    _m_hakool(nullptr), _m_componentId(_id)
  {
    return;
  }
  
  EngineComponent::~EngineComponent()
  {
    return;
  }

  eENGINE_COMPONENT 
  EngineComponent::getId()
  {
    return this->_m_componentId;
  }

  void 
  EngineComponent::setHakool(Hakool& _hakool)
  {
    _m_hakool = &_hakool;
    return;
  }

  void
  EngineComponent::_onEngineInit(HakoolConfiguration& _configEngine)
  { 
    return;
  }

  void 
  EngineComponent::_onEngineDestroy()
  {
    return;
  }

  void 
  EngineComponent::_onUpdate(const float& _delta)
  {
    return;
  }
}