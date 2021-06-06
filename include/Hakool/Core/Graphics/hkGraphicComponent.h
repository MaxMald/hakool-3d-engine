#pragma once

#include <Hakool\Core\hkCorePrerequisites.h>
#include <Hakool\Core\hkEngineComponent.h>

namespace hk
{
  class Window;
  class Hakool;

  /**
  * Provides a common interface for graphics component.
  */
  class HK_CORE_EXPORT GraphicComponent
  : public EngineComponent 
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

  protected:

    /**
    * Indicates the graphic API been used by this GraphicComponent.
    */
    eGRAPHIC_INTERFACE
    _m_graphicInterfaceId;
  };
}