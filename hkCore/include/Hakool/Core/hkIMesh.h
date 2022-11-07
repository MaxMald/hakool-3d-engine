#pragma once

#include <Hakool/Core/hkCorePrerequisites.h>
#include <Hakool/Core/hkIResource.h>

namespace hk
{
  class GraphicComponent;

  /**
  * Represents a 3d mesh.
  */
  class IMesh
    : public IResource
  {
  public:

    virtual ~IMesh() = default;

    /**
     * Initialize the mesh with vertices data.
     * 
     * @param aVertexes Array of vertexes.
     * @param size Total count of vertexes.
     */
    virtual void
    init(float* aVertexes, const uint32& size) = 0;

    /**
     * Transfer the mesh data to the graphic component to be drawn properly.
     * 
     * @param pGraphicComponent Pointer to the GraphicComponent.
     */
    virtual void
    draw(GraphicComponent* pGraphicComponent) = 0;

    /**
    * Get the size of the array of vertexes.
    * 
    * @return The size of the array of vertexes.
    */
    virtual uint32
    getVertexesSize() = 0;

    /**
    * Get the array of vertexes.
    * 
    * @return The array of vertexes.
    */
    virtual float*
    getVertexesArray() = 0;
  };
}