#pragma once

#include <Hakool/Core/hkCorePrerequisites.h>
#include <Hakool/Core/hkResource.h>

namespace hk
{
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
    Mesh(const Mesh& _mesh);

    /**
    * Destructor.
    */
    ~Mesh();

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

    /**
    * Set the array of vertexes.
    * 
    * @param _aVertexes Array of vertexes.
    * @param _size Array size.
    */
    void
    setVertexesArray(float* _aVertexes, const uint32& _size);

  private:
    
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