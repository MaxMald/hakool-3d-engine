#include "Hakool/Utils/hkMultiMesh.h"

#include "Hakool/Utils/hkVertex.h"
#include "Hakool/Utils/hkMultiMeshMesh.h"
#include "Hakool/Utils/hkMultiMeshNode.h"

namespace hk
{
  MultiMesh::MultiMesh
  (
    Vertex* vertices,
    uint32 verticesSize,
    uint32* indices,
    uint32 indicesSize,
    MultiMeshMesh* meshes,
    uint32 meshesSize,
    MultiMeshNode* nodes,
    uint32 nodesSize
  ) :
    _m_vertices(vertices),
    _m_verticesSize(verticesSize),
    _m_indices(indices),
    _m_indicesSize(indicesSize),
    _m_meshes(meshes),
    _m_meshesSize(meshesSize),
    _m_nodes(nodes),
    _m_nodesSize(nodesSize)
  { }

  MultiMesh::~MultiMesh()
  {
    delete[] _m_vertices;
    delete[] _m_indices;
    delete[] _m_meshes;
    delete[] _m_nodes;
  }

  Vertex* const
  MultiMesh::getVerticesPtr()
  {
    return _m_vertices;
  }

  const uint32&
  MultiMesh::getVerticesSize() const
  {
    return _m_verticesSize;
  }

  uint32* const
  MultiMesh::getIndicesPtr()
  {
    return _m_indices;
  }

  const uint32&
  MultiMesh::getIndicesSize() const
  {
    return _m_indicesSize;
  }

  MultiMeshMesh* const
  MultiMesh::getMeshesPtr()
  {
    return _m_meshes;
  }

  const uint32& 
  MultiMesh::getMeshesSize() const
  {
    return _m_meshesSize;
  }

  MultiMeshNode* const 
  MultiMesh::getNodes()
  {
    return _m_nodes;
  }

  const uint32& 
  MultiMesh::getNodesSize() const
  {
    return _m_nodesSize;
  }
}