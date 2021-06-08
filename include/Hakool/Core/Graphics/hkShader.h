#pragma once

#include <Hakool\Utils\hkUtilitiesUtilities.h>

#include <Hakool\Core\hkCorePrerequisites.h>
#include <Hakool\Core\hkCoreUtilities.h>

namespace hk
{
  class IGraphicComponent;

  /**
  * Provides a common interface for extended shader.
  */
  class IShader
  {
  public:   

    /**
    * Get the pointer to the wrapped API's shader.
    * 
    * @return The pointer to the wrapped API's shader.
    */
    virtual void*
    getShaderPtr() = 0;

    /**
    * Initialize the shader.
    * 
    * @return Operation result.
    */
    virtual eRESULT
    init(IGraphicComponent _graphicComponent) = 0;

    /**
    * Safely destroy this shader.
    */
    virtual void
    destroy() = 0;

    /**
    * Get the type of this shader.
    */
    virtual eSHADER_TYPE
    getType() = 0;

  protected:

    /**
    * Constructor.
    */
    IShader() = default;

    /**
    * Destructor.
    */
    virtual ~IShader() = default;
  };
}