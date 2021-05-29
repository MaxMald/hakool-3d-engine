#include <Hakool\Utils\hkPlugin.h>
#include <Hakool\Utils\hkPluginData.h>

namespace hk
{
  Plugin::Plugin()
  {
    return;
  }

  Plugin::~Plugin()
  {
    return;
  }

  void Plugin::init()
  {
  }

  void Plugin::destroy()
  {
  }

  PluginData* 
  Plugin::getData()
  {
    return nullptr;
  }
}