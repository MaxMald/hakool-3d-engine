#pragma once

#include <Hakool\Utils\hkColor.h>
#include <Hakool\Utils\hkMatrix4.h>

#include <Hakool\GraphicsOpenGL\hkGraphicsOpenGLPrerequisites.h>
#include <Hakool\Core\Graphics\hkGraphicComponent.h>

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtc/type_ptr.hpp>

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
      const GraphicsConfiguration& _graphicConfiguration,
      ResourceManager& resourceManager
    ) override;

    virtual Mesh*
    createMesh() override;

    /**
     * Sets the color to clear the graphic buffers.
     *
     * @param color Color.
     */
    virtual void
    setClearColor(const Color& color) override;

    /**
     * Clear the graphics buffers.
     */
    virtual void
    clear() override;

    /**
     * Prepare the GraphicComponent to draw.
     */
    virtual void
    prepareToDraw() override;

    /**
     * Draw the given scene in the screen.
     */
    virtual void
    drawScene(Scene* pScene);

    virtual void
    drawMesh(Mesh& _Mesh) override;

    /**
     * TODO
     */
    virtual void
    present() override;

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
    uint32 _m_aVAO[1];

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
  };
}