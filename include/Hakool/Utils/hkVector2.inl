#pragma once

#include <Hakool\Utils\hkVector2.h>

namespace hk
{
  template<typename T>
  inline Vector2<T>::Vector2() :
  x(0), y(0)
  {
  }

  template<typename T>
  inline Vector2<T>::Vector2(T _x, T _y) :
  x(_x), y(_y)
  {
  }

  template<typename T>
  template<typename U>
  inline Vector2<T>::Vector2(const Vector2<U>& _vector) :
  x(static_cast<T>(_vector.x)),
  y(static_cast<T>(_vector.y))
  {
  }

  template<typename T>
  inline Vector2<T> 
  operator+(const Vector2<T>& _addendL, const Vector2<T> _addendR)
  {
    return Vector2<T>(_addendL.x + _addendR.x, _addendL.y + _addendR.y);
  }

  template<typename T>
  inline Vector2<T> 
  operator-(const Vector2<T>& _subtrahend)
  {
    return Vector2<T>(-_subtrahend.x, -_subtrahend,y);
  }

  template <typename T>
  inline Vector2<T> 
  operator-(const Vector2<T>& _minuend, const Vector2<T>& _subtrahend)
  {
    return Vector2<T>(_minuend.x - _subtrahend.x, _minuend.y - _subtrahend.y);
  }
    
  template<typename T>
  inline Vector2<T>& 
  operator+=(Vector2<T>& _addendL, const Vector2<T>& _addendR)
  {
    _addendL.x += _addendR.x;
    _addendR.y += _addendR.y;
    
    return _addendL;
  }
    
  template<typename T>
  inline Vector2<T>& 
  operator-=(Vector2<T>& _minuend, const Vector2<T>& _subtrahend)
  {
    _minuend.x -= _subtrahend.x;
    _minuend.y -= _subtrahend.y;

    return _minuend;
  }

  template<typename T>
  inline Vector2<T> 
  operator*(const Vector2<T>& _factorL, T _factorR)
  {
    return Vector2<T>(_factorL.x * _factorR, _factorL.y * _factorR);
  }

  template<typename T>
  inline Vector2<T> 
  operator*(const T _factorL, Vector2<T>& _factorR)
  {
    return Vector2<T>(_factorR.x * _factorL, _factorR.y * _factorL);
  }

  template<typename T>
  inline Vector2<T>& 
  operator*=(Vector2<T>& _factorL, T _factorR)
  {
    _factorL.x *= _factorR;
    _factorL.y *= _factorR;
    return _factorL;
  }

  template<typename T>
  inline Vector2<T> 
  operator/(const Vector2<T>& _dividend, T _divisor)
  {
    return Vector2<T>(_dividend.x / _divisor, _dividend.y / _divisor);
  }

  template<typename T>
  inline Vector2<T>& 
  operator/=(Vector2<T>& _dividend, T _divisor)
  {
    _dividend.x /= _divisor;
    _dividend.y /= _divisor;
    return _dividend;
  }

  template<typename T>
  inline bool 
  operator==(const Vector2<T>& _left, const Vector2<T>& _right)
  {
    return (_left.x == _right.x && _left.y == _right.y);
  }

  template<typename T>
  inline bool 
  operator!=(const Vector2<T>& _left, const Vector2<T>& _right)
  {
    return (_left.x != _right.x || _left.y != _right.y);
  }
}