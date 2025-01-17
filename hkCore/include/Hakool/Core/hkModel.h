#pragma once

#include <Hakool/Utils/hkUtilitiesUtilities.h>
#include <Hakool/Core/hkCorePrerequisites.h>

namespace hk
{
  class IMesh;
  class GraphicComponent;

  /**
  * TODO
  */
  class HK_CORE_EXPORT Model
  {
  public:

    /**
    * TODO
    */
    Model();

    /**
    * TODO
    */
    explicit Model(const Model& _model);

    /**
    * TODO
    */
    ~Model();

    /**
    * Sets the mesh of this Model.
    * 
    * @param pMesh The mesh of the model.
    */
    void
    setMesh(IMesh* pMesh);

    void
    draw(GraphicComponent* pGraphicComponent);

  private:

    /**
    * Model's mesh.
    */
    IMesh* 
    _m_mesh;
  };
}