#pragma once

#include "Hakool/Utils/hkUtilsPrerequisites.h"
#include "Hakool/Utils/hkMultiMeshNode.h"

namespace hk
{
  struct HK_UTILITY_EXPORT MultiMeshMesh
  {
    MultiMeshMesh();

    MultiMeshMesh
    (
      String name,
      uint32 firstVertexIndex,
      uint32 verticesSize,
      uint32 firstIndexIndex,
      uint32 indicesSize
    );

    explicit MultiMeshMesh(const MultiMeshMesh&);

    String
    name;

    uint32
    firstVertexIndex;

    uint32
    verticesSize;

    uint32
    firstIndexIndex;

    uint32
    indicesSize;
  };
}