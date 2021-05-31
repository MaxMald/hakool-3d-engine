#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>

namespace hk
{
  class IPluginManager;
  struct PluginData;

  class HK_UTILITY_EXPORT IPlugin
  {
  public:

    IPlugin() = default;

    virtual ~IPlugin() = default;

    /**
    * Called when the plug-in is been connected.
    */
    virtual void
    onConnect() = 0;

    /**
    * Called when the plug-in is about to been closed.
    */
    virtual void
    onClose() = 0;

    /**
    * Get the wrapped data of this plug-in.
    * 
    * @return Wrapped data.
    */
    virtual PluginData*
    getData() = 0;
  };
}