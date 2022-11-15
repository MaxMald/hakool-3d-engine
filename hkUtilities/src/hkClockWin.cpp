#include <Hakool/Utils/hkClockWin.h>

namespace hk
{
  ClockWin::ClockWin() :
    Clock()
  { }

  Time 
  ClockWin::getCurrentTime() const
  {
    LARGE_INTEGER time;
    QueryPerformanceCounter(&time);

    static double inverse = 1000000.0 / getFrequency();
    return Time(static_cast<uint64>(time.QuadPart * inverse));
  }

  LONGLONG
  ClockWin::getFrequency() const
  {
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    return frequency.QuadPart;
  }
}