#pragma once

#include <Hakool/Utils/hkUtilsPrerequisites.h>

namespace hk
{
  /**
   * TODO
   */
  class HK_UTILITY_EXPORT Time
  {
  public:

    Time();

    Time(uint64 microseconds);

    Time(Time& time);
    
    Time(const Time& time);

    float 
    asSeconds() const;

    uint32
    asMilliseconds() const;

    uint64
    asMicroseconds() const;

  private:

    uint64 _m_microseconds;
  };

  bool
  operator == (Time left, Time right);

  bool
  operator != (Time left, Time right);

  bool
  operator < (Time left, Time right);

  bool
  operator > (Time left, Time right);

  bool
  operator <= (Time left, Time right);

  bool
  operator >= (Time left, Time right);

  Time
  operator - (Time right);

  Time
  operator - (Time left, Time right);

  Time&
  operator -= (Time& left, Time right);

  Time
  operator + (Time left, Time right);

  Time&
  operator += (Time& left, Time right);

  Time
  operator * (Time left, float right);

  Time
  operator * (Time left, uint64 right);

  Time
  operator * (float left, Time right);

  Time
  operator * (uint64 left, Time right);

  Time&
  operator *= (Time& left, float right);

  Time&
  operator *= (Time& left, uint64 right);

  Time
  operator / (Time left, float right);

  Time
  operator / (Time left, uint64 right);

  Time&
  operator /= (Time& left, float right);

  Time&
  operator /= (Time& left, uint64 right);

  float
  operator / (Time left, Time right);
}