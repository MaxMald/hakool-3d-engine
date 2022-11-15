#pragma once

#include <Hakool\Utils\hkMatrix4.h>
#include <Hakool\Utils\hkWindowObserver.h>
#include <Hakool\Core\hkCorePrerequisites.h>
#include <Hakool\Core\hkEngineComponent.h>

namespace hk
{
  class IWindow;
  class Hakool;
  class IShader;
  class IProgram;
  class GraphicComponent;
  class ResourceManager;
  class Scene;
  class Color;
  class IMesh;

  struct WindowConfiguration;

  /**
  * Provides a common interface for graphics component.
  */
  class GraphicComponent
  : public WindowObserver
  {
  public:

    /**
    * Constructor.
    */
    GraphicComponent() = default;

    /**
    * Destructor.
    */
    virtual
    ~GraphicComponent() = default;

    /**
    * Initialize the graphic component.
    * 
    * @param _graphicConfiguration Configuration object.
    * @param resourceManager ResourceManager.
    * 
    * @return Operation result.
    */
    virtual eRESULT
    init(
      const GraphicsConfiguration& _graphicConfiguration,
      const WindowConfiguration& windowConfig,
      ResourceManager& resourceManager) = 0;    

    /**
     * Sets the color to clear the graphic buffers.
     * 
     * @param color Color.
     */
    virtual void
    setClearColor(const Color& color) = 0;

    /**
     * Clear the graphics buffers.
     */
    virtual void
    clear() = 0;

    /**
     * Prepare the GraphicComponent to draw.
     */
    virtual void
    prepareToDraw() = 0;

    /**
     * Draw the given scene in the screen.
     */
    virtual void
    drawScene(Scene* pScene) = 0;

    /*
    * Set the model space matrix. Usually used before drawing the Meshes of the
    * Model.
    * 
    * @param modelMatrix The model space matrix.
    */
    virtual void
    setModelMatrix(const Matrix4& modelMatrix) = 0;

    /**
     * Create a Mesh.
     * 
     * @returns a pointer to the Mesh.
     */
    virtual IMesh*
    createMesh() = 0;

    /**
    * Get a pointer to a new vertex shader.
    * 
    * @return Vertex shader.
    */
    virtual IShader*
    createVertexShader() = 0;

    /**
    * Get a pointer to a new fragment shader.
    * 
    * @return Fragment shader.
    */
    virtual IShader*
    createFragmentShader() = 0;

    /**
    * Get a pointer to a new program.
    * 
    * @return Program.
    */
    virtual IProgram*
    createProgram() = 0;

    /**
     * Get the pointer to the window.
     */
    virtual IWindow*
    getWindow() = 0;

    /**
    * Shutdown the graphic component and release its resources.
    */
    virtual void
    destroy() = 0;

    /**
    * Get the id that indicates the graphic API been used by this 
    * GraphicComponent.
    */
    virtual eGRAPHIC_INTERFACE
    getGraphicInterfaceId() = 0;
  };
}