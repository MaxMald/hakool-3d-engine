#include <Hakool/Core/Graphics/hkMesh.h>

namespace hk
{
  Mesh::Mesh() :
    _m_aVertexes(nullptr),
    _m_vertexesSize(0)
  {
  }

  Mesh::Mesh(const Mesh& _mesh) :
    _m_aVertexes(nullptr),
    _m_vertexesSize(0)
  {
    // TODO.
  }

  Mesh::~Mesh()
  {
    destroy();

    return;
  }

  void 
  Mesh::destroy()
  {
    if (_m_aVertexes != nullptr)
    {
      delete _m_aVertexes;
    }
    _m_vertexesSize = 0;

    return;
  }

  uint32 
  Mesh::getVertexesSize()
  {
    return _m_vertexesSize;
  }

  float* 
  Mesh::getVertexesArray()
  {
    return _m_aVertexes;
  }

  void 
  Mesh::setVertexesArray(float* _aVertexes, const uint32& _size)
  {
    _m_aVertexes = _aVertexes;
    _m_vertexesSize = _size;

    return;
  }
}