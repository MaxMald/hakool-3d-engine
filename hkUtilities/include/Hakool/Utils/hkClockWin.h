#pragma once

#include <Hakool/Utils/hkClock.h>
#include <windows.h>

namespace hk
{
  class ClockWin : public Clock
  {
  public:

    ClockWin();

  protected:

    virtual Time
    getCurrentTime() const override;

  private:

    LONGLONG
    getFrequency() const;
  };
}