#include <Hakool/Utils/hkClock.h>

#include <exception>

#if HK_PLATFORM == HK_PLATFORM_WIN32

#include <Hakool/Utils/hkClockWin.h>

#endif

namespace hk
{
  Clock*
  Clock::Create()
  {

#if HK_PLATFORM == HK_PLATFORM_WIN32

    return new ClockWin();

#else

    throw std::system_error("Clock not defined for the specified platform.");

#endif

  }

  Clock::Clock() :
    _m_startTime(getCurrentTime())
  { }

  Time
  Clock::getElapsedTime() const 
  { 
    return getCurrentTime() - _m_startTime;
  }

  Time
  Clock::restart()
  { 
    Time now = getCurrentTime();
    Time elapsed = now - _m_startTime;
    _m_startTime = now;
    return elapsed;
  }

  Time
  Clock::getCurrentTime() const
  { 
    return Time();
  }
}