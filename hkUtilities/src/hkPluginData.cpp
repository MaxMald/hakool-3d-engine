#include <Hakool\Utils\hkPluginData.h>

namespace hk
{
  PluginData::PluginData() :
    data(nullptr)
  {
    return;
  }

  PluginData::PluginData(void* _pData) :
    data(_pData)
  {
    return;
  }

  PluginData::PluginData(const PluginData& _plugIn) :
    data(_plugIn.data)
  {
    return;
  }

  PluginData& 
  PluginData::operator=(const PluginData& _plugIn)
  {
    this->data = _plugIn.data;
    return;
  }
}