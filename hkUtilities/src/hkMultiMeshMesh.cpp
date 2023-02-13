#include "Hakool/Utils/hkMultiMeshMesh.h"

namespace hk
{
  MultiMeshMesh::MultiMeshMesh() :
    name(""),
    firstVertexIndex(0),
    verticesSize(0),
    firstIndexIndex(0),
    indicesSize(0)
  { }

  MultiMeshMesh::MultiMeshMesh
  (
    String _name,
    uint32 _firstVertexIndex,
    uint32 _verticesSize,
    uint32 _firstIndexIndex,
    uint32 _indicesSize
  ) :
    name(_name),
    firstVertexIndex(_firstVertexIndex),
    verticesSize(_verticesSize),
    firstIndexIndex(_firstIndexIndex),
    indicesSize(_indicesSize)
  { }

  MultiMeshMesh::MultiMeshMesh(const MultiMeshMesh& copy):
    name(copy.name),
    firstVertexIndex(copy.firstVertexIndex),
    verticesSize(copy.verticesSize),
    firstIndexIndex(copy.firstIndexIndex),
    indicesSize(copy.indicesSize)
  { }
}