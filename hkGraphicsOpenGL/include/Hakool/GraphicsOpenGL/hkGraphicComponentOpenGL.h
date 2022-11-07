#pragma once

#include <Hakool\Utils\hkColor.h>
#include <Hakool\Utils\hkMatrix4.h>

#include <Hakool\GraphicsOpenGL\hkGraphicsOpenGLPrerequisites.h>
#include <Hakool\Core\hkGraphicComponent.h>

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace hk
{
  class IWindow;
  class WindowOpenGL;
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
    virtual
    ~GraphicComponentOpenGL();

    virtual eRESULT
    init(
      const GraphicsConfiguration& _graphicConfiguration,
      const WindowConfiguration& windowConfig,
      ResourceManager& resourceManager) override;

    virtual void
    setClearColor(const Color& color) override;

    virtual void
    clear() override;

    virtual void
    prepareToDraw() override;

    virtual void
    drawScene(Scene* pScene);

    virtual IMesh*
    createMesh() override;

    virtual IShader*
    createVertexShader() override;

    virtual IShader*
    createFragmentShader() override;

    virtual IProgram*
    createProgram() override;

    virtual IWindow*
    getWindow() override;

    virtual void
    destroy() override;

    virtual eGRAPHIC_INTERFACE
    getGraphicInterfaceId() override;

    virtual void
    onWindowSizeChanged(
      const uint32& width, 
      const uint32& height, 
      IWindow* pWindow) const override;
    

  private:
    /**
    * TODO
    */
    void
    _releaseResources(ResourceManager& resourceManager);

    /**
    * Screen clear color.
    */
    Color
    _m_clearColor;

    /**
    * Array of vertex array objects.
    */
    uint32 
    _m_aVAO[1];

    /**
    * Pointer to the program.
    */
    ProgramOpenGL*
    _m_pProgramOpenGL;

    ResourceManager*
    _m_pResourceManager;

    Matrix4 
    _m_perspectiveMat;

    Matrix4
    _m_modelViewMat;

    glm::mat4x4
    _m_pers;

    glm::mat4x4
    _m_model;

    WindowOpenGL*
    _m_pWindow;

    ContextOpenGL*
    _m_pContextOpenGL;

    bool
    _m_isReady;
  };
}