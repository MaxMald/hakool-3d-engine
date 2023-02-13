#include "Hakool/Utils/hkAiMeshNode.h"

namespace hk
{
  AiMeshNode::AiMeshNode():
    pAiNode(nullptr),
    transformation()
  { }

  AiMeshNode::AiMeshNode(const aiNode* _pAiNode, const Matrix4& _transformation) :
    pAiNode(_pAiNode),
    transformation(_transformation)
  { }

  AiMeshNode::AiMeshNode(const AiMeshNode& copy) :
    pAiNode(copy.pAiNode),
    transformation(copy.transformation)
  { }
}