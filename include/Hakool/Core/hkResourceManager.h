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
    * Get shader.
    */
    ResourceGroup<Shader>&
    getShaders();

  private:

    /**
    * Group of shader.
    */
    ResourceGroup<Shader>
    _m_shaders;
  };
}