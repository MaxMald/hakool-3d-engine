#pragma once

#include "Hakool/Utils/hkUtilsPrerequisites.h"
#include "Hakool/Utils/hkMatrix4.h"

namespace hk
{
  struct HK_UTILITY_EXPORT MultiMeshNode
  {
  public:
    
    MultiMeshNode();

    MultiMeshNode
    (
      uint32* meshesIndices,
      const uint32& meshesIndicesSize,
      const Matrix4& transform
    );

    explicit MultiMeshNode(const MultiMeshNode& copy);

    ~MultiMeshNode();

    uint32*
    meshesIndices;

    uint32
    meshesIndicesSize;

    Matrix4
    transform;
  };
}