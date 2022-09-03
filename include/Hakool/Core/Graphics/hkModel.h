#pragma once

#include <Hakool/Utils/hkUtilitiesUtilities.h>

#include <Hakool/Core/hkCorePrerequisites.h>

namespace hk
{
  class Mesh;

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
    Model(const Model& _model);

    /**
    * TODO
    */
    ~Model();

    /**
    * TODO
    */
    eRESULT
    setMesh(const String& _id);

  private:

    /**
    * Model's mesh.
    */
    Mesh* 
    _m_mesh;

  };
}