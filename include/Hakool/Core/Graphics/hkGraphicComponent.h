#pragma once

#include <Hakool\Utils\hkWindowObserver.h>
#include <Hakool\Core\hkCorePrerequisites.h>
#include <Hakool\Core\hkEngineComponent.h>

namespace hk
{
  class Window;
  class Hakool;
  class IShader;
  class IProgram;

  /**
  * Provides a common interface for graphics component.
  */
  class HK_CORE_EXPORT GraphicComponent
  : public EngineComponent, public WindowObserver
  {
  public:

    /**
    * Constructor.
    */
    GraphicComponent();

    /**
    * Destructor.
    */
    virtual
    ~GraphicComponent();

    /**
    * Initialize the graphic component.
    * 
    * @param _pWindow Pointer to the application window.
    * @param _graphicConfiguration Configuration object.
    * 
    * @return Operation result.
    */
    virtual eRESULT
    init(Window* _pWindow, const GraphicsConfiguration& _graphicConfiguration);

    /**
    * Called every frame.
    */
    virtual void
    update();

    /**
    * Get a pointer to a new vertex shader.
    * 
    * @return Vertex shader.
    */
    virtual IShader*
    getVShader();

    /**
    * Get a pointer to a new fragment shader.
    * 
    * @return Fragment shader.
    */
    virtual IShader*
    getFShader();

    /**
    * Get a pointer to a new program.
    * 
    * @return Program.
    */
    virtual IProgram*
    getProgram();

    /**
    * Shutdown the graphic component and release its resources.
    */
    virtual void
    destroy();

    /**
    * Get the id that indicates the graphic API been used by this 
    * GraphicComponent.
    */
    virtual eGRAPHIC_INTERFACE
    getGraphicInterfaceId();

    /**
     * Called when the window's size has changed.
     *
     * @param window Reference to the window which size has changed.
     */
    virtual void
    onWindowSizeChanged(Window& window) const override;

  protected:

    /**
    * Indicates the graphic API been used by this GraphicComponent.
    */
    eGRAPHIC_INTERFACE
    _m_graphicInterfaceId;
  };
}