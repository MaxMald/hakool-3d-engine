#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>

namespace hk
{
  struct HK_UTILITY_EXPORT PluginData
  {
  public:

    PluginData();

    PluginData(void* _pData);

    PluginData(const PluginData& _plugIn);

    PluginData&
    operator=(const PluginData& _plugIn);

    /**
    * Pointer to data.
    */
    void* data;
  };
}