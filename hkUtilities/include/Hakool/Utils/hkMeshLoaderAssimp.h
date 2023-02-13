#pragma once

#include "Hakool/Utils/hkMatrix4.h"
#include "Hakool/Utils/hkIMeshLoader.h"
#include "Hakool/Utils/hkAiMeshNode.h"

struct aiNode;
struct aiScene;
struct aiMesh;

namespace hk
{
  class MultiMesh;
  class MultiMeshNode;
  class MultiMeshMesh;
  class Vertex;

  class HK_UTILITY_EXPORT MeshLoaderAssimp : public IMeshLoader
  {
  public:

    MeshLoaderAssimp();

    virtual ~MeshLoaderAssimp();

    virtual MultiMesh*
    load(String path) override;

  private:

    void
    getAiMeshNodes
    (
      const aiNode* pNode,
      Vector<AiMeshNode*>& aiMeshNodes,
      const Matrix4& accTransform
    );

    MultiMesh*
    mallocMultiMeshInstance
    (
      const aiScene* pAiScene,
      Vector<AiMeshNode*>& aiMeshNodes
    );

    void
    saveMeshesData(const aiScene* pAiScene, MultiMesh* pMultiMesh);

    void
    saveMeshData
    (
      const aiMesh* pAiMesh,
      MultiMeshMesh* pMesh,
      uint32& vertexIndex,
      uint32& indexIndex,
      MultiMesh* pMultiMesh
    );

    void
    saveMeshNodesData
    (
      Vector<AiMeshNode*>& aiMeshNodes,
      MultiMesh* pMultiMesh
    );
  };
}