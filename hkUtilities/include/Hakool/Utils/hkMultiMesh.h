#pragma once

#include "Hakool/Utils/hkUtilsPrerequisites.h"

namespace hk
{
  struct Vertex;
  struct MultiMeshMesh;
  struct MultiMeshNode;

  class HK_UTILITY_EXPORT MultiMesh
  {
  public:

    MultiMesh
    (
      Vertex* vertices,
      uint32 verticesSize,
      uint32* indices,
      uint32 indicesSize,
      MultiMeshMesh* meshes,
      uint32 meshesSize,
      MultiMeshNode* nodes,
      uint32 nodesSize
    );

    virtual ~MultiMesh();

    Vertex* const
    getVerticesPtr();

    const uint32&
    getVerticesSize() const;

    uint32* const
    getIndicesPtr();

    const uint32&
    getIndicesSize() const;

    MultiMeshMesh* const
    getMeshesPtr();

    const uint32&
    getMeshesSize() const;

    MultiMeshNode* const
    getNodes();

    const uint32&
    getNodesSize() const;

   protected:

     Vertex*
     _m_vertices;

     uint32
     _m_verticesSize;

     uint32*
     _m_indices;

     uint32
     _m_indicesSize;

     MultiMeshMesh*
     _m_meshes;

     uint32
     _m_meshesSize;

     MultiMeshNode*
     _m_nodes;

     uint32
     _m_nodesSize;
  };
}