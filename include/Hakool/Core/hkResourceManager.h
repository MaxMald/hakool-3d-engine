#pragma once

#include <Hakool\Utils\hkUtilitiesUtilities.h>

#include <Hakool\Core\hkCorePrerequisites.h>
#include <Hakool\Core\hkResourceGroup.h>

namespace hk
{
  class Shader;

  /**
  * TODO
  */
  class HK_CORE_EXPORT ResourceManager
  {
  public:

    /**
    * Constructor.
    */
    ResourceManager();

    /**
    * Destructor.
    */
    ~ResourceManager();

    /**
    * Initialize the resource manager.
    * 
    * @return Operation result.
    */
    eRESULT
    init();

    /**
    * Get shader.
    */
    ResourceGroup<Shader>&
    getShaders();

    /**
    * Clear from all resources.
    */
    void
    clear();

    /**
    * Safely destroys the resource manager.
    */
    void
    destroy();

  private:

    /**
    * Group of shader.
    */
    ResourceGroup<Shader>
    _m_shaders;
  };
}