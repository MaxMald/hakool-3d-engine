#include <Hakool\GraphicsOpenGL\hkGraphicsOpenGLPlugin.h>
#include <Hakool\GraphicsOpenGL\hkGraphicComponentOpenGL.h>

namespace hk
{
  HK_GRAPHICS_OPENGL_EXPORT IPlugin* 
  createGraphicComponentOpenGLPlugin()
  {
    return new GraphicsOpengGLPlugin();
  }

  HK_GRAPHICS_OPENGL_EXPORT void 
  destroyGraphicComponentOpenGLPlugin()
  {
    return;
  }

  GraphicsOpengGLPlugin::GraphicsOpengGLPlugin()
    : _m_pGraphicComponentOpenGL(nullptr)
  {
    return;
  }

  GraphicsOpengGLPlugin::~GraphicsOpengGLPlugin()
  {
    return;
  }

  void 
  GraphicsOpengGLPlugin::onConnect()
  {
    if (this->_m_pGraphicComponentOpenGL == nullptr)
    {
      this->_m_pGraphicComponentOpenGL = new GraphicComponentOpenGL();
    }
    
    return;
  }

  void 
  GraphicsOpengGLPlugin::onClose()
  {
    if (this->_m_pGraphicComponentOpenGL != nullptr)
    {
      delete this->_m_pGraphicComponentOpenGL;
      this->_m_pGraphicComponentOpenGL = nullptr;
    }

    return;
  }

  void* 
  GraphicsOpengGLPlugin::getData()
  {
    return reinterpret_cast<void*>(this->_m_pGraphicComponentOpenGL);
  }
}