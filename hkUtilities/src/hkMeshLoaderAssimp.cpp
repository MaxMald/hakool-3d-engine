#include "Hakool/Utils/hkMeshLoaderAssimp.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/matrix4x4.h>
#include "Hakool/Utils/hkVertex.h"
#include "Hakool/Utils/hkMultiMesh.h"
#include "Hakool/Utils/hkMultiMeshMesh.h"
#include "Hakool/Utils/hkMultiMeshNode.h"

namespace hk
{
  MeshLoaderAssimp::MeshLoaderAssimp()
  {
  }

  MeshLoaderAssimp::~MeshLoaderAssimp()
  {
  }

  MultiMesh*
  MeshLoaderAssimp::load(String path)
  {
    Assimp::Importer importer;
    const aiScene* pAiScene = importer.ReadFile
    (
      path,
      aiProcess_CalcTangentSpace |
      aiProcess_Triangulate |
      aiProcess_JoinIdenticalVertices |
      aiProcess_SortByPType
    );

    if (nullptr == pAiScene)
      throw std::exception(importer.GetErrorString());

    if (!pAiScene->HasMeshes())
      return nullptr;

    Vector<AiMeshNode*> aiMeshNodes;
    getAiMeshNodes
    (
      pAiScene->mRootNode,
      aiMeshNodes,
      Matrix4::GetIdentity()
    );
    MultiMesh* pMultiMesh = mallocMultiMeshInstance(pAiScene, aiMeshNodes);
    saveMeshesData(pAiScene, pMultiMesh);
    saveMeshNodesData(aiMeshNodes, pMultiMesh);

    for (AiMeshNode* pMeshNode : aiMeshNodes)
      delete pMeshNode;
    aiMeshNodes.clear();

    return pMultiMesh;
  }

  void 
  MeshLoaderAssimp::getAiMeshNodes
  (
    const aiNode* pNode,
    Vector<AiMeshNode*>& aiMeshNodes,
    const Matrix4& accTransform
  )
  {
    aiMatrix4x4 aiNodeTransform = pNode->mTransformation;
    Matrix4 transformation = Matrix4
    (
      aiNodeTransform.a1, aiNodeTransform.a2, aiNodeTransform.a3, aiNodeTransform.a4,
      aiNodeTransform.b1, aiNodeTransform.b2, aiNodeTransform.b3, aiNodeTransform.b4,
      aiNodeTransform.c1, aiNodeTransform.c2, aiNodeTransform.c3, aiNodeTransform.c4,
      aiNodeTransform.d1, aiNodeTransform.d2, aiNodeTransform.d3, aiNodeTransform.d4
    ) * accTransform;

    if (pNode->mNumMeshes > 0)
      aiMeshNodes.push_back(new AiMeshNode(pNode, transformation));

    for (uint32 i = 0; i < pNode->mNumChildren; ++i)
      getAiMeshNodes(pNode->mChildren[i], aiMeshNodes, transformation);
  }

  MultiMesh*
    MeshLoaderAssimp::mallocMultiMeshInstance
    (
      const aiScene* pAiScene,
      Vector<AiMeshNode*>& aiMeshNodes
    )
  {
    uint32 numMeshes = pAiScene->mNumMeshes;
    uint32 numVertices = 0;
    uint32 numIndices = 0;
    for (uint32 aiMeshIndex = 0; aiMeshIndex < numMeshes; ++aiMeshIndex)
    {
      aiMesh* pAiMesh = pAiScene->mMeshes[aiMeshIndex];
      numVertices += pAiMesh->mNumVertices;

      for (uint32 aiFaceIndex = 0; aiFaceIndex < pAiMesh->mNumFaces; ++aiFaceIndex)
        numIndices += pAiMesh->mFaces[aiFaceIndex].mNumIndices;
    }

    uint32 numNodes = aiMeshNodes.size();
    return new MultiMesh
    (
      new Vertex[numVertices],
      numVertices,
      new uint32[numIndices],
      numIndices,
      new MultiMeshMesh[numMeshes],
      numMeshes,
      new MultiMeshNode[numNodes],
      numNodes
    );
  }

  void 
  MeshLoaderAssimp::saveMeshesData(const aiScene* pAiScene, MultiMesh* pMultiMesh)
  {
    uint32 indexIndex = 0;
    uint32 vertexIndex = 0;
    for (uint32 aiMeshIndex = 0; aiMeshIndex < pAiScene->mNumMeshes; ++aiMeshIndex)
    {      
      saveMeshData
      (
        pAiScene->mMeshes[aiMeshIndex],
        &(pMultiMesh->getMeshesPtr()[aiMeshIndex]),
        vertexIndex,
        indexIndex,
        pMultiMesh
      );
    }
  }

  void 
  MeshLoaderAssimp::saveMeshData
  (
    const aiMesh* pAiMesh,
    MultiMeshMesh* pMesh,
    uint32& vertexIndex,
    uint32& indexIndex,
    MultiMesh* pMultiMesh
  )
  {
    pMesh->name = String(pAiMesh->mName.C_Str());
    pMesh->firstVertexIndex = vertexIndex;
    pMesh->firstIndexIndex = indexIndex;

    pMesh->verticesSize = pAiMesh->mNumVertices;
    for (int32 aiVertexIndex = 0; aiVertexIndex < pAiMesh->mNumVertices; ++aiVertexIndex)
    {
      Vertex* pVertex = &(pMultiMesh->getVerticesPtr()[vertexIndex]);
      pVertex->x = pAiMesh->mVertices[aiVertexIndex].x;
      pVertex->y = pAiMesh->mVertices[aiVertexIndex].y;
      pVertex->z = pAiMesh->mVertices[aiVertexIndex].z;
      ++vertexIndex;
    }

    pMesh->indicesSize = 0;
    for (int32 aiFaceIndex = 0; aiFaceIndex < pAiMesh->mNumFaces; ++aiFaceIndex)
    {
      aiFace aiFace = pAiMesh->mFaces[aiFaceIndex];
      pMesh->indicesSize += aiFace.mNumIndices;
      for (int32 aiIndexIndex = 0; aiIndexIndex < aiFace.mNumIndices; ++aiIndexIndex)
      {
        pMultiMesh->getIndicesPtr()[indexIndex] = aiFace.mIndices[aiIndexIndex];
        ++indexIndex;
      }
    }
  }

  void
  MeshLoaderAssimp::saveMeshNodesData
  (
    Vector<AiMeshNode*>& aiMeshNodes,
    MultiMesh* pMultiMesh
  )
  {
    for (uint32 i = 0; i < aiMeshNodes.size(); ++i)
    {
      AiMeshNode* pAiMeshNode = aiMeshNodes[i];
      uint32* meshesIndices = new uint32[pAiMeshNode->pAiNode->mNumMeshes];
      for (int32 j = 0; j < pAiMeshNode->pAiNode->mNumMeshes; ++j)
        meshesIndices[j] = pAiMeshNode->pAiNode->mMeshes[j];

      MultiMeshNode* pMultiMeshNode = &(pMultiMesh->getNodes()[i]);
      pMultiMeshNode->meshesIndices = meshesIndices;
      pMultiMeshNode->meshesIndicesSize = pAiMeshNode->pAiNode->mNumMeshes;
      pMultiMeshNode->transform = pAiMeshNode->transformation;
    }
  }
}