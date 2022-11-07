#pragma once

#include <Hakool\Utils\hkUtilitiesUtilities.h>

#include <Hakool\Core\hkCorePrerequisites.h>
#include <Hakool\Core\hkCoreUtilities.h>
#include <Hakool\Core\hkIResource.h>

namespace hk
{
  class GraphicComponent;

  /**
  * Provides a common interface for extended shader.
  */
  class IShader :
    public IResource
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
    * @param _pGraphicComponent pointer to the graphic component.
    * 
    * @return Operation result.
    */
    virtual eRESULT
    init(GraphicComponent* _pGraphicComponent) = 0;

    /**
    * Create the shader from a source.
    * 
    * @param _pSource The shader's source.
    * 
    * @return Operation result.
    */
    virtual eRESULT
    create(const char* _pSource, const eSHADER_TYPE& _type) = 0;

    /**
    * Check if this shader is ready to be used.
    * 
    * @return True is the shader is ready, otherwise returns false.
    */
    virtual bool
    isReady() = 0;

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