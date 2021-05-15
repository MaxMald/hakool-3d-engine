#pragma once

#include <Hakool\Core\hkCorePrerequisites.h>

namespace hk
{
  class Hakool;
  struct ConfigEngine;

  class HK_CORE_EXPORT EngineComponent
  {
  protected:

    virtual void
    _onEngineInit(Hakool& _hakool, ConfigEngine& _configEngine) = 0;

    virtual void
    _onEngineDestroy(Hakool& _hakool) = 0;

    friend class Hakool;
  };
}