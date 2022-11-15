#include <Hakool/Utils/hkTime.h>

namespace hk
{
  Time::Time() :
    _m_microseconds(0)
  { }

  Time::Time(uint64 microseconds) :
    _m_microseconds(microseconds)
  { }

  Time::Time(Time & time) :
    _m_microseconds(time._m_microseconds)
  { }

  Time::Time(const Time& time) :
    _m_microseconds(time._m_microseconds)
  { }

  float
  Time::asSeconds() const
  {
    return _m_microseconds / 1000000.f;
  }

  uint32
  Time::asMilliseconds() const
  {
    return static_cast<uint32>(_m_microseconds / 1000);
  }

  uint64
  Time::asMicroseconds() const
  {
    return _m_microseconds;
  }

  bool 
  operator ==(Time left, Time right)
  {
    return left.asMicroseconds() == right.asMicroseconds();
  }

  bool 
  operator !=(Time left, Time right)
  {
    return left.asMicroseconds() != right.asMicroseconds();
  }

  bool 
  operator <(Time left, Time right)
  {
    return left.asMicroseconds() < right.asMicroseconds();
  }

  bool 
  operator >(Time left, Time right)
  {
    return left.asMicroseconds() > right.asMicroseconds();
  }

  bool 
  operator <=(Time left, Time right)
  {
    return left.asMicroseconds() <= right.asMicroseconds();
  }

  bool 
  operator >=(Time left, Time right)
  {
    return left.asMicroseconds() >= right.asMicroseconds();
  }

  Time 
  operator -(Time right)
  {
    return Time(-right.asMicroseconds());
  }

  Time 
  operator +(Time left, Time right)
  {
    return Time(left.asMicroseconds() + right.asMicroseconds());
  }

  Time& 
  operator +=(Time& left, Time right)
  {
    return left = left + right;
  }

  Time 
  operator -(Time left, Time right)
  {
    return Time(left.asMicroseconds() - right.asMicroseconds());
  }

  Time& 
  operator -=(Time& left, Time right)
  {
    return left = left - right;
  }

  Time 
  operator *(Time left, float right)
  {
    return Time(left.asMicroseconds() * static_cast<uint64>(right * 1000000));
  }

  Time 
  operator *(Time left, uint64 right)
  {
    return Time(left.asMicroseconds() * right);
  }

  Time 
  operator *(float left, Time right)
  {
    return right * left;
  }

  Time 
  operator *(uint64 left, Time right)
  {
    return right * left;
  }

  Time& 
  operator *=(Time& left, float right)
  {
    return left = left * right;
  }

  Time& 
  operator *=(Time& left, uint64 right)
  {
    return left = left * right;
  }

  Time 
  operator /(Time left, float right)
  {
    return Time(left.asMicroseconds() / static_cast<uint64>(right * 1000000));
  }

  Time 
  operator /(Time left, uint64 right)
  {
    return Time(left.asMicroseconds() / right);
  }

  Time& 
  operator /=(Time& left, float right)
  {
    return left = left / right;
  }

  Time& 
  operator /=(Time& left, uint64 right)
  {
    return left = left / right;
  }

  float 
  operator /(Time left, Time right)
  {
    return left.asSeconds() / right.asSeconds();
  }

  Time 
  operator %(Time left, Time right)
  {
    return Time(left.asMicroseconds() % right.asMicroseconds());
  }

  Time& 
  operator %=(Time& left, Time right)
  {
    return left = left % right;
  }
}