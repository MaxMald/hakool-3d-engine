#include <Hakool/Core/Graphics/hkModel.h>
#include <Hakool/Core/Graphics/hkIMesh.h>

namespace hk
{
  Model::Model():
    _m_mesh(nullptr)
  {
    return;
  }

  Model::Model(const Model& _model):
    _m_mesh(_model._m_mesh)
  {
    return;
  }

  Model::~Model()
  {
  }

  void
  Model::setMesh(IMesh* pMesh)
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