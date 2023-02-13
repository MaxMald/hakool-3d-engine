#pragma once

#include "Hakool/Utils/hkUtilsPrerequisites.h"

namespace hk
{
  class MultiMesh;

  class IMeshLoader
  {
  public:

    IMeshLoader() = default;

    virtual ~IMeshLoader() = default;

    virtual MultiMesh*
    load(String path) = 0;
  };
}