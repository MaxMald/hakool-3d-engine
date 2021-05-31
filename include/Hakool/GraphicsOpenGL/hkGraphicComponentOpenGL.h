#pragma once

#include <Hakool\GraphicsOpenGL\hkGraphicsOpenGLPrerequisites.h>
#include <Hakool\Core\Graphics\hkGraphicComponent.h>

namespace hk
{
  class HK_GRAPHICS_OPENGL_EXPORT GraphicComponentOpenGL :
    public GraphicComponent
  {
  public:

    GraphicComponentOpenGL();

    ~GraphicComponentOpenGL();

    virtual eGRAPHIC_INTERFACE
    getGraphicInterfaceId() override;
  };
}