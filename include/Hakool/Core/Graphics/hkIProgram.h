#pragma once

#include <Hakool\Utils\hkUtilitiesUtilities.h>

#include <Hakool\Core\hkCorePrerequisites.h>
#include <Hakool\Core\hkCoreUtilities.h>

namespace hk
{
  class IGraphicComponent;
  class IShader;

  /**
  * Provides a common interface for extended programs.
  */
  class IProgram
  {
  public:    

    /**
    * Initialize the program.
    * 
    * @param _graphicComponent Reference to the graphic component.
    * 
    * @return Operation result.
    */
    virtual eRESULT
    init(IGraphicComponent _graphicComponent) = 0;

    /**
    * Create the program with the given shader.
    * 
    * @return Operation result.
    */
    virtual eRESULT
    build() = 0;

    /**
    * Add a new shader to this program. 
    * 
    * @param _type The type of this shader.
    * @param _shader pointer to the shader.
    * 
    * @result Operation result.
    */
    virtual eRESULT
    addShader(eSHADER_TYPE _type, IShader* _pShader) = 0;

    /**
    * Check if this program has an specific type of shader.
    * 
    * @param _type THe type of the shader.
    */
    virtual bool
    hasShader(eSHADER_TYPE _type) = 0;

    /**
    * Safely destroys this program.
    */
    virtual void
    destroy() = 0;

  protected:

    /**
    * Constructor.
    */
    IProgram() = default;

    /**
    * Destructor.
    */
    virtual ~IProgram() = default;

  };
}
