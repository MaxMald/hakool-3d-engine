#pragma once

#include "hkCorePrerequisites.h"
#include "Graphics/hkIMesh.h"
#include "hkResourceGroup.h"

namespace hk
{
  class GraphicComponent;

  class HK_CORE_EXPORT MeshResourceGroup : public ResourceGroup<IMesh>
  {
  public:

    MeshResourceGroup();

    virtual ~MeshResourceGroup();

    /**
     * TODO
     */
    void
    init(GraphicComponent* pGraphicComponent);

    /**
     * Gets the cube mesh.
     * <p>
     * The cube mesh is created only once in the life of the application, so the
     * same mesh is returned by this function each time it is called.
     * 
     * @return Mesh of the cube.
     */
    IMesh*
    getCube();

  protected:

    /**
     * TODO 
     */
    GraphicComponent* 
    _m_pGraphicComponent;
  };
}