#include <Hakool/Core/hkMeshResourceGroup.h>

#include <Hakool/Core/Graphics/hkGraphicComponent.h>

namespace hk
{
  MeshResourceGroup::MeshResourceGroup() :
    ResourceGroup<IMesh>(),
    _m_pGraphicComponent(nullptr)
  { }

  MeshResourceGroup::~MeshResourceGroup()
  { }

  void 
  MeshResourceGroup::init(GraphicComponent * pGraphicComponent)
  {
    _m_pGraphicComponent = pGraphicComponent;
    return;
  }

  IMesh*
  MeshResourceGroup::getCube()
  {
    String cubeKey = "_HAKOOL_CUBE_MESH_";
    if (has(cubeKey))
    {
      return get(cubeKey);
    }
    float* pVertexes = new float[108] {
       -1.0f,  1.0f, -1.0f, -1.0f, -1.0f, -1.0f,  1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,  1.0f,  1.0f, -1.0f, -1.0f,  1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,  1.0f, -1.0f,  1.0f,  1.0f,  1.0f, -1.0f,
        1.0f, -1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f, -1.0f,
        1.0f, -1.0f,  1.0f, -1.0f, -1.0f,  1.0f,  1.0f,  1.0f,  1.0f,
       -1.0f, -1.0f,  1.0f, -1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,
       -1.0f, -1.0f,  1.0f, -1.0f, -1.0f, -1.0f, -1.0f,  1.0f,  1.0f,
       -1.0f, -1.0f, -1.0f, -1.0f,  1.0f, -1.0f, -1.0f,  1.0f,  1.0f,
       -1.0f, -1.0f,  1.0f,  1.0f, -1.0f,  1.0f,  1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f,  1.0f,
       -1.0f,  1.0f, -1.0f,  1.0f,  1.0f, -1.0f,  1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f, -1.0f,  1.0f,  1.0f, -1.0f,  1.0f, -1.0f,
    };

    IMesh* pCubeMesh = _m_pGraphicComponent->createMesh();
    pCubeMesh->init(pVertexes, (uint32)36);

    add(cubeKey, pCubeMesh);
    return pCubeMesh;
  }
}