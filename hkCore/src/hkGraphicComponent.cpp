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

  eRESULT 
  GraphicComponent::init
  (
    Window* _pWindow, 
    const GraphicsConfiguration& _graphicConfiguration
  )
  {
    return eRESULT::kFail;
  }

  void 
  GraphicComponent::update()
  {
    return;
  }

  IShader* 
  GraphicComponent::getVShader()
  {
      return nullptr;
  }

  IShader* 
  GraphicComponent::getFShader()
  {
      return nullptr;
  }

  IProgram* 
  GraphicComponent::getProgram()
  {
      return nullptr;
  }

  void
  GraphicComponent::destroy()
  {
    return;
  }

  eGRAPHIC_INTERFACE 
  GraphicComponent::getGraphicInterfaceId()
  {
    return this->_m_graphicInterfaceId;
  }

  void 
  GraphicComponent::onWindowSizeChanged(Window& window) const
  {
  }
}