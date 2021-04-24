#include <Hakool\hakool.h>

namespace hk
{
  Hakool* Hakool::_ENGINE_INSTANCE = nullptr;

  void 
  Hakool::Start()
  {
    if (Hakool::_ENGINE_INSTANCE == nullptr)
    {
      Hakool::_ENGINE_INSTANCE = new Hakool();
    }

    return;
  }
  
  void 
  Hakool::Shutdown()
  {
    if (Hakool::_ENGINE_INSTANCE != nullptr)
    {
      Hakool::_ENGINE_INSTANCE->_destroy();
      Hakool::_ENGINE_INSTANCE = nullptr;
    }

    return;
  }

  Hakool*
  Hakool::GetEngine()
  {
    return Hakool::_ENGINE_INSTANCE;
  }

  Hakool::Hakool()
  { }

  Hakool::~Hakool()
  {
    return;
  }

  void 
  Hakool::_destroy()
  {
    // TODO
    return;
  }
};