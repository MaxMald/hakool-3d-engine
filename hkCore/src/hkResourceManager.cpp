#include <Hakool\Core\hkResourceManager.h>

namespace hk
{
  ResourceManager::ResourceManager() :
    _m_shaders(),
    _m_meshes()
  { }

  ResourceManager::~ResourceManager()
  {
    destroy();
    return;
  }

  void 
  ResourceManager::init(GraphicComponent* pGraphicComponent)
  {
    _m_meshes.init(pGraphicComponent);
    return;
  }

  ResourceGroup<Shader>&
  ResourceManager::getShaders()
  {
    return _m_shaders;
  }

  MeshResourceGroup&
  ResourceManager::getMeshes()
  {
    return _m_meshes;
  }

  void 
  ResourceManager::clear()
  {
    _m_shaders.clear();
    _m_meshes.clear();
    return;
  }

  void 
  ResourceManager::destroy()
  {
    clear();
    return;
  }
}