#pragma once

#include <Hakool\Utils\hkVector2.h>

namespace hk
{
  template<typename T>
  inline Vector2<T>::Vector2() :
  x(0), y(0)
  {
    return;
  }

  template<typename T>
  inline Vector2<T>::Vector2(T _x, T _y) :
  x(_x), y(_y)
  {
    return;
  }

  template<typename T>
  template<typename U>
  inline Vector2<T>::Vector2(const Vector2<U>& _vector) :
  x(static_cast<T>(_vector.x)),
  y(static_cast<T>(_vector.y))
  {
    return;
  }

  template<typename T>
  inline Vector2<T>::~Vector2()
  {
    return;
  }

  template<typename T>
  inline T&
  Vector2<T>::operator[](const uint32& _index)
  {
    // TODO: Assert
    return (&this->x)[_index];
  }

  template<typename T>
  inline Vector2<T>&
  Vector2<T>::operator=(const Vector2<T>& _v2)
  {
    this->x = _v2.x;
    this->y = _v2.y;
    return *this;
  }

  template<typename T>
  inline Vector2<T> 
  operator+(const Vector2<T>& _a, const Vector2<T> _b)
  {
    return Vector2<T>(_a.x + _b.x, _a.y + _b.y);
  }

  template<typename T>
  inline Vector2<T> 
  operator-(const Vector2<T>& _v2)
  {
    return Vector2<T>(-_v2.x, -_v2,y);
  }

  template <typename T>
  inline Vector2<T> 
  operator-(const Vector2<T>& _a, const Vector2<T>& _b)
  {
    return Vector2<T>(_a.x - _b.x, _a.y - _b.y);
  }

  template <typename T>
  Vector2<T>
  operator*(const Vector2<T>& _a, const Vector2<T>& _b)
  {
    return Vector2<T>(_a.x * _b.x, _a.y * _b.y);
  }

  template<typename T>
  inline Vector2<T>
  operator*(const Vector2<T>& _v2, T _s)
  {
    return Vector2<T>(_v2.x * _s, _v2.y * _s);
  }

  template<typename T>
  inline Vector2<T>
  operator*(const T _s, Vector2<T>& _v2)
  {
    return Vector2<T>(_v2.x * _s, _v2.y * _s);
  }

  template <typename T>
  Vector2<T>
  operator/ (const Vector2<T>& _a, const Vector2<T>& _b)
  {
    return Vector2<T>(_a.x / _b.x, _a.y / _b.y);
  }

  template<typename T>
  inline Vector2<T>
  operator/ (const Vector2<T>& _v2, T _divisor)
  {
    return Vector2<T>(_v2.x / _divisor, _v2.y / _divisor);
  }

  template <typename T>
  T&
  operator| (const Vector2<T>& _a, const Vector2<T>& _b)
  {
    return _a.x * _b.x + _a.y * _b.y;
  }
    
  template<typename T>
  inline Vector2<T>& 
  operator+=(Vector2<T>& _a, const Vector2<T>& _b)
  {
    _a.x += _b.x;
    _a.y += _b.y;
    
    return _a;
  }
    
  template<typename T>
  inline Vector2<T>& 
  operator-=(Vector2<T>& _a, const Vector2<T>& _b)
  {
    _a.x -= _b.x;
    _a.y -= _b.y;

    return _a;
  }

  template <typename T>
  Vector2<T>&
  operator*= (Vector2<T>& _a, Vector2<T>& _b)
  {
    _a.x *= _b.x;
    _a.y *= _b.y;

    return _a;
  }

  template<typename T>
  inline Vector2<T>& 
  operator*=(Vector2<T>& _v2, T _s)
  {
    _v2.x *= _s;
    _v2.y *= _s;

    return _v2;
  }

  template <typename T>
  Vector2<T>&
  operator/= (Vector2<T>& _a, Vector2<T>& _b)
  {
    _a.x /= _b.x;
    _a.y /= _b.y;

    return _a;
  }

  template<typename T>
  inline Vector2<T>& 
  operator/=(Vector2<T>& _v2, T _divisor)
  {
    _v2.x /= _divisor;
    _v2.y /= _divisor;

    return _v2;
  }

  template<typename T>
  inline bool 
  operator==(const Vector2<T>& _a, const Vector2<T>& _b)
  {
    return (_a.x == _b.x && _a.y == _b.y);
  }

  template<typename T>
  inline bool 
  operator!=(const Vector2<T>& _a, const Vector2<T>& _b)
  {
    return (_a.x != _b.x || _a.y != _b.y);
  }
}