#pragma once

#include "hkCorePrerequisites.h";
#include "Graphics/hkMesh.h";
#include "hkResourceGroup.h";

namespace hk
{
  class HK_CORE_EXPORT MeshResourceGroup : public ResourceGroup<Mesh>
  {
  public:

    MeshResourceGroup();

    virtual ~MeshResourceGroup();

    /**
     * Gets the cube mesh.
     * <p>
     * The cube mesh is created only once in the life of the application, so the
     * same mesh is returned by this function each time it is called.
     * 
     * @return Mesh of the cube.
     */
    Mesh*
    getCube();
  };
}