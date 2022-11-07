#pragma once

#include <Hakool\Utils\hkUtilitiesUtilities.h>

#include <Hakool\Core\hkCorePrerequisites.h>
#include <Hakool\Core\hkMeshResourceGroup.h>

namespace hk
{
  class Shader;
  class IMesh;
  class GraphicComponent;

  /**
  * Manage all type of resources in the engine.
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
    void
    init(GraphicComponent* pGraphicComponent);

    /**
    * Gets the Shader group.
    * 
    * @return A reference to the ShaderResourceGroup.
    */
    ResourceGroup<Shader>&
    getShaders();

    /**
    * Gets the Mesh group.
    * 
    * @return A reference to the MeshResourceGroup.
    */
    MeshResourceGroup&
    getMeshes();

    /**
    * Clears all the resources.
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
    * The Shader group in this ResourceManager.
    */
    ResourceGroup<Shader>
    _m_shaders;

    /**
    * The Mesh group in this ResourceManager.
    */
    MeshResourceGroup
    _m_meshes;
  };
}