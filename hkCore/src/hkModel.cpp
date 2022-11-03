#include <Hakool/Core/Graphics/hkModel.h>

#include <Hakool/Core/Graphics/hkMesh.h>

namespace hk
{
  Model::Model()
  {
    return;
  }

  Model::Model(const Model& _model)
  {
    return;
  }

  Model::~Model()
  {
  }

  void
  Model::setMesh(Mesh* pMesh)
  {
    this->_m_mesh = pMesh;
  }

  void 
  Model::draw(GraphicComponent* pGraphicComponent)
  {
    _m_mesh->draw(pGraphicComponent);
    return;
  }
}