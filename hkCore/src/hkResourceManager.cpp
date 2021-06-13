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

  void 
  ResourceManager::clear()
  {
    _m_shaders.clear();

    return;
  }

  void 
  ResourceManager::destroy()
  {
    _m_shaders.clear();

    return;
  }
}