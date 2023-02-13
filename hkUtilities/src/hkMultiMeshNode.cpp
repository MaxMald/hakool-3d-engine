#include "Hakool/Utils/hkMultiMeshNode.h"

namespace hk
{
  MultiMeshNode::MultiMeshNode() :
    meshesIndices(nullptr),
    meshesIndicesSize(0),
    transform()
  { }

  MultiMeshNode::MultiMeshNode
  (
    uint32* _meshesIndices,
    const uint32& _meshesIndicesSize,
    const Matrix4& _transform
  ) :
    meshesIndices(_meshesIndices),
    meshesIndicesSize(_meshesIndicesSize),
    transform(_transform)
  { }

  MultiMeshNode::MultiMeshNode(const MultiMeshNode& copy) :
    meshesIndices(copy.meshesIndices),
    meshesIndicesSize(copy.meshesIndicesSize),
    transform(copy.transform)
  { }

  MultiMeshNode::~MultiMeshNode()
  {
    delete[] meshesIndices;
  }
}