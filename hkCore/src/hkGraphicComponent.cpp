#include <Hakool\Core\Graphics\hkGraphicComponent.h>

namespace hk
{
  GraphicComponent::GraphicComponent()
    : EngineComponent(eENGINE_COMPONENT::kGraphics), 
    _m_graphicInterfaceId(eGRAPHIC_INTERFACE::kUndefined)
  {
    return;
  }

  GraphicComponent::~GraphicComponent()
  {
  }

  eGRAPHIC_INTERFACE 
  GraphicComponent::getGraphicInterfaceId()
  {
    return this->_m_graphicInterfaceId;
  }
}