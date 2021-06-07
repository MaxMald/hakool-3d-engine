#include <Hakool\Core\hkScene.h>

#include <Hakool\hakool.h>

namespace hk
{
  void 
  Scene::start()
  {
    // Intentionally blank
    return;
  }

  void 
  Scene::enter()
  {
    // Intentionally blank
    return;
  }

  void
  Scene::update()
  {
    // Intentionally blank
    return;
  }

  void 
  Scene::exit()
  {
    // Intentionally blank
    return;
  }

  void 
  Scene::destroy()
  {
    // Intentionally blank
    return;
  }

  Scene::Scene() :
    _m_pHakool(nullptr)
  {
    // Intentionally blank
    return;
  }

  Scene::~Scene()
  {
    _m_pHakool = nullptr;
    return;
  }
}