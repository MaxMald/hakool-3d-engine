#include <Hakool/Core/hkModelComponent.h>

#include <Hakool\Utils\hkLogger.h>
#include <Hakool\Core\hkResourceManager.h>

namespace hk
{
  ModelComponent::ModelComponent(ResourceManager& resourceManager) :
    _m_pGameObject(nullptr),
    _m_resourceManager(resourceManager)
  {
  }

  ModelComponent::~ModelComponent()
  {
    destroy();
    return;
  }

  void 
  ModelComponent::init(GameObject* pGameObject)
  {
    _m_pGameObject = pGameObject;
    return;
  }

  void 
  ModelComponent::update()
  {
  }

  void
  ModelComponent::draw(GraphicComponent* pGraphicComponent)
  { 
    _m_model.draw(pGraphicComponent);
    return;
  }

  void 
  ModelComponent::destroy()
  {
  }

  eCOMPONENT 
  ModelComponent::getID()
  {
    return eCOMPONENT::kModel;
  }

  GameObject* 
  ModelComponent::getGameObject()
  {
      return _m_pGameObject;
  }

  eRESULT 
  ModelComponent::setMesh(const String& meshKey)
  {
     MeshResourceGroup meshGroup = _m_resourceManager.getMeshes();
     if (!meshGroup.has(meshKey))
     {
       Logger::Error("Mesh was not found: " + meshKey);
       return eRESULT::kObjectNotFound;
     }

     _m_model.setMesh(meshGroup.get(meshKey));
    return eRESULT::kSuccess;
  }

  void
  ModelComponent::setMesh(Mesh* pMesh)
  {
    _m_model.setMesh(pMesh);
    return;
  }
}
