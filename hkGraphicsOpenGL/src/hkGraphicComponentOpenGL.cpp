#include <Hakool\GraphicsOpenGL\hkGraphicComponentOpenGL.h>

namespace hk
{
  GraphicComponentOpenGL::GraphicComponentOpenGL():
    GraphicComponent()
  {
    this->_m_graphicInterfaceId = eGRAPHIC_INTERFACE::kOpenGL;
    return;
  }

  GraphicComponentOpenGL::~GraphicComponentOpenGL()
  {
    return;
  }

  eGRAPHIC_INTERFACE 
  GraphicComponentOpenGL::getGraphicInterfaceId()
  {
    return this->_m_graphicInterfaceId;
  }
}