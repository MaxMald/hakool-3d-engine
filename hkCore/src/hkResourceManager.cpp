#include <Hakool\Core\hkResourceManager.h>

namespace hk
{
  ResourceManager::ResourceManager()
  {
    // Intentionally blank.
    return;
  }

  ResourceManager::~ResourceManager()
  {
    destroy();
    return;
  }

  eRESULT 
  ResourceManager::init()
  {
    // TODO.
    return eRESULT::kSuccess;
  }

  ResourceGroup<Shader>&
  ResourceManager::getShaders()
  {
    return _m_shaders;
  }

  ResourceGroup<Mesh>& 
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