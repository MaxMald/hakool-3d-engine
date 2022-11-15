#pragma once

#include <Hakool/Utils/hkUtilsPrerequisites.h>
#include <Hakool/Utils/hkTime.h>

namespace hk
{
  class HK_UTILITY_EXPORT Clock
  {
  public:

    virtual
    ~Clock() = default;

    static Clock*
    Create();

    Time
    getElapsedTime() const;

    Time
    restart();

  protected:

    Clock();

    virtual Time
    getCurrentTime() const;

    Time
    _m_startTime;
  };
}
