#pragma once

#include <Hakool\Utils\hkUtilitiesUtilities.h>

#include <Hakool\Core\hkCorePrerequisites.h>
#include <Hakool\Core\hkCoreUtilities.h>

namespace hk
{
  class ResourceManager;
  class GraphicComponent;

  /**
  * Provides a common interface for extended programs.
  */
  class IProgram
  {
  public:    

    /**
    * Initialize the program.
    * 
    * @param _pGraphicComponent Pointer to the graphic component.
    * 
    * @return Operation result.
    */
    virtual eRESULT
    init(GraphicComponent* _pGraphicComponent) = 0;

    /**
    * Create the program with the given shader.
    * 
    * @param _fragment The key of the fragment shader.
    * @param _vertex The key of the vertex shader.
    * @param _pResourceManager The pointer to the resource manager.
    * 
    * @return Operation result.
    */
    virtual eRESULT
    create
    (
      const String& _fragment,
      const String& _vertex,
      ResourceManager* _pResourceManager
    ) = 0;

    /**
    * Get the pointer to the wrapped API's shader.
    *
    * @return The pointer to the wrapped API's shader.
    */
    virtual void*
    getProgramPtr() = 0;

    /**
    * Check if the program is ready to be used.
    * 
    * @return True if the program is ready, otherwise returns false.
    */
    virtual bool
    isReady() = 0;

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
