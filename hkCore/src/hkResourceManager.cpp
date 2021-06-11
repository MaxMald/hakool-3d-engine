#include <Hakool\Core\hkResourceManager.h>

namespace hk
{
  ResourceManager::ResourceManager()
  {
    return;
  }

  ResourceManager::~ResourceManager()
  {
    return;
  }

  ResourceGroup<Shader>&
  ResourceManager::getShaders()
  {
    return this->_m_shaders;
  }
}