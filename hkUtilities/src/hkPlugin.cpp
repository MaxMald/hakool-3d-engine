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

  String 
  Plugin::getKey()
  {
    return "";
  }

  PluginData* 
  Plugin::getData()
  {
    return nullptr;
  }

  void 
  Plugin::_onCreate()
  {
    return;
  }

  void 
  Plugin::_onDestroy()
  {
    return;
  }
}