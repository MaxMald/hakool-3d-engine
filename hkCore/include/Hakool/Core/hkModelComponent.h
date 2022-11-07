#pragma once

#include <Hakool/Utils/hkUtilitiesUtilities.h>
#include <Hakool/Core/hkCorePrerequisites.h>
#include <Hakool/Core/hkIGameObjectComponent.h>
#include <Hakool/Core/hkModel.h>
#include <Hakool/Core/hkModelObserver.h>

namespace hk
{
  class ResourceManager;

  /**
  * TODO
  */
  class HK_CORE_EXPORT ModelComponent : public IGameObjectComponent, public ModelObserver
  {
  public:

    ModelComponent(ResourceManager&);

    virtual ~ModelComponent();

    void
    init(GameObject* pGameObject);
    
    void
    update();

    void
    draw(GraphicComponent* pGraphicComponent);

    void
    destroy();

    eCOMPONENT
    getID();

    GameObject*
    getGameObject();

    /**
     * 
     */
    eRESULT
    setMesh(const String& meshKey);

    /**
     * Set the Mesh of the Model.
     * 
     * @param pMesh The Mesh's pointer.
     */
    void
    setMesh(IMesh* pMesh);

  private:

    /**
    * Reference to the Model which this component belongs to.
    */
    Model
    _m_model;

    /**
     * Pointer to the GameObject which this component belongs to.
     */
    GameObject*
    _m_pGameObject;

    /**
     * Reference to the ResourceManager.
     */
    ResourceManager&
    _m_resourceManager;
  };
}