#pragma once

#include <Hakool\Core\hkCorePrerequisites.h>
#include <Hakool\Core\hkEngineComponent.h>

namespace hk
{
  class Hakool;

  /**
  * Provides a common interface for graphics component.
  */
  class HK_CORE_EXPORT GraphicComponent
  : public EngineComponent 
  {
  public:

    GraphicComponent();

    virtual
    ~GraphicComponent();

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