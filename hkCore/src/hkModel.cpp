#include <Hakool/Core/Graphics/hkModel.h>

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
}