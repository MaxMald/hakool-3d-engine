#pragma once

#include "Hakool/Utils/hkUtilsPrerequisites.h"
#include "Hakool/Utils/hkMatrix4.h"

struct aiNode;

namespace hk
{
  struct AiMeshNode
  {
  public:

    AiMeshNode();

    AiMeshNode(const aiNode* pAiNode, const Matrix4& transformation);

    AiMeshNode(const AiMeshNode& copy);

    const aiNode*
    pAiNode;

    Matrix4
    transformation;
  };
}