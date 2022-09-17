#pragma once

#include <Hakool\Utils\hkColor.h>

#include <Hakool\GraphicsOpenGL\hkGraphicsOpenGLPrerequisites.h>
#include <Hakool\Core\Graphics\hkGraphicComponent.h>

namespace hk
{
  class Window;
  class ContextOpenGL;
  class ProgramOpenGL;

  /**
  * OpenGL GraphicComponent implementation.
  */
  class HK_GRAPHICS_OPENGL_EXPORT GraphicComponentOpenGL :
    public GraphicComponent
  {
  public:

    /**
    * Constructor.
    */
    GraphicComponentOpenGL();

    /**
    * Destructor.
    */
    ~GraphicComponentOpenGL();

    /**
    * Initialize the graphic component.
    *
    * @param _pWindow Pointer to the application window.
    * @param _graphicConfiguration Configuration object.
    *
    * @return Operation result.
    */
    virtual eRESULT
    init
    (
      Window* _pWindow, 
      const GraphicsConfiguration& _graphicConfiguration
    ) override;

    /**
    * Draws on screen.
    */
    virtual void
    update() override;

    /**
    * Get a pointer to a new vertex shader.
    *
    * @return Vertex shader.
    */
    virtual IShader*
    getVShader() override;

    /**
    * Get a pointer to a new fragment shader.
    *
    * @return Fragment shader.
    */
    virtual IShader*
    getFShader() override;

    /**
    * Get a pointer to a new program.
    *
    * @return Program.
    */
    virtual IProgram*
    getProgram() override;

    /**
    * Shutdown the graphic component and release its resources.
    */
    virtual void
    destroy() override;

    /**
    * Get the id that indicates the graphic API been used by this
    * GraphicComponent.
    */
    virtual eGRAPHIC_INTERFACE
    getGraphicInterfaceId() override;

    virtual void
    onWindowSizeChanged(Window& window) const override;

    /**
    * Pointer to the window.
    */
    Window*
    _m_pWindow;

    /**
    * Pointer to the context of the OpenGL instance.
    */
    ContextOpenGL*
    _m_pContextOpenGL;

    /**
    * Indicates if the graphic component is ready.
    */
    bool
    _m_isReady;

  private:

    /**
    * Draw on screen.
    */
    void
    _draw();

    /**
    * TODO
    */
    void
    _clean();

    /**
    * Screen clear color.
    */
    Color
    _m_clearColor;

    /**
    * Array of vertex array objects.
    */
    uint32 _m_aVAO[1];

    /**
    * Pointer to the program.
    */
    ProgramOpenGL*
    _m_pProgramOpenGL;
  };
}