#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>

namespace hk
{
  class IPluginManager;
  struct PluginData;

  class HK_UTILITY_EXPORT Plugin
  {
  public:

    Plugin();

    virtual ~Plugin();

    /**
    * Initialize the plug-in.
    */
    virtual void
    init();

    /**
    * Destroy the plug-in.
    */
    virtual void
    destroy();

    /**
    * Get the wrapped data of this plug-in.
    * 
    * @return Wrapped data.
    */
    virtual PluginData*
    getData();
  };
}