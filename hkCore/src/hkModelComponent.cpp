#include <Hakool/Core/hkModelComponent.h>

#include <Hakool\Utils\hkLogger.h>

namespace hk
{
  ModelComponent::ModelComponent() :
    Component(eCOMPONENT::kModel)
  {
  }

  ModelComponent::~ModelComponent()
  {
    destroy();
    
    return;
  }

  void 
  ModelComponent::create()
  {
  }

  void 
  ModelComponent::init()
  {
  }

  void 
  ModelComponent::update()
  {
  }

  void 
  ModelComponent::destroy()
  {
  }
}
