#include <Hakool\Core\Graphics\hkGraphicComponent.h>

namespace hk
{
  GraphicComponent::GraphicComponent() :
    _m_graphicInterfaceId(eGRAPHIC_INTERFACE::kUndefined)
  {
    return;
  }

  GraphicComponent::~GraphicComponent()
  {
    destroy();
    return;
  }

  eRESULT 
  GraphicComponent::init
  (
    Window* _pWindow, 
    const GraphicsConfiguration& _graphicConfiguration,
    ResourceManager& resourceManager
  )
  {
    return eRESULT::kFail;
  }

  Mesh* 
  GraphicComponent::createMesh()
  {
    return nullptr;
  }

  void 
  GraphicComponent::setClearColor(const Color& color)
  {
    return;
  }

  void
  GraphicComponent::clear()
  {
    return;
  }

  void 
  GraphicComponent::prepareToDraw()
  {
    return;
  }

  void 
  GraphicComponent::drawScene(Scene* pScene)
  {
    return;
  }

  void 
  GraphicComponent::drawMesh(Mesh& _Mesh)
  {
    return;
  }

  void 
  GraphicComponent::present()
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
    return;
  }
}