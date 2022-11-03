#pragma once

#include <Hakool/Core/hkCorePrerequisites.h>
#include <Hakool/Core/hkResource.h>

namespace hk
{
  class GraphicComponent;

  /**
  * TODO
  */
  class HK_CORE_EXPORT Mesh
    : public Resource
  {
  public:
    /**
    * 
    */
    Mesh();

    /**
    * 
    */
    explicit Mesh(const Mesh& _mesh);

    /**
    * Destructor.
    */
    virtual ~Mesh();

    /**
    * Set the array of vertexes.
    *
    * @param _aVertexes Array of vertexes.
    * @param _size Array size.
    */
    virtual void
    init(float* _aVertexes, const uint32& _size);

    /**
     * TODO
     */
    virtual void
    draw(GraphicComponent* pGraphicComponent);

    /**
    * Safely destroys this object.
    */
    void
    destroy() override;

    /**
    * Get the size of the array of vertexes.
    * 
    * @return The size of the array of vertexes.
    */
    uint32
    getVertexesSize();

    /**
    * Get the array of vertexes.
    * 
    * @return The array of vertexes.
    */
    float*
    getVertexesArray();

  protected:
    
    /**
    * Size of the list of vertexes.
    */
    uint32
    _m_vertexesSize;

    /**
    * List of vertexes.
    */
    float*
    _m_aVertexes;
  };
}