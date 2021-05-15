#pragma once

#include <Hakool\Utils\hkVector4.h>

namespace hk
{
  template<typename T>
  inline Vector4<T>::Vector4() :
    x(0), y(0), z(0), w(0)
  {
    return;
  }

  template<typename T>
  inline Vector4<T>::Vector4(T& _x, T& _y, T& _z, T& _w) :
    x(_x), y(_y), z(_z), w(_w)
  {
    return;
  }

  template<typename T>
  template<typename U>
  inline Vector4<T>::Vector4(const Vector4<U>& _v4) :
    x(static_cast<T>(_v4.x)),
    y(static_cast<T>(_v4.y)),
    z(static_cast<T>(_v4.z)),
    w(static_cast<T>(_v4.w))
  {
    return
  }

  template<typename T>
  inline Vector4<T>::~Vector4()
  {
    return;
  }

  template<typename T>
  inline T&
  Vector4<T>::operator[](const uint32& _index)
  {
    // TODO: Assert
    return (&this->x)[_index];
  }

  template<typename T>
  inline Vector4<T>&
    Vector4<T>::operator=(const Vector4<T>& _v4)
  {
    this->x = _v4.x;
    this->y = _v4.y;
    this->z = _v4.z;
    this->w = _v4.w;

    return *this;
  }

  template <typename T>
  Vector4<T>
  operator+(const Vector4<T>& _a, const Vector4<T>& _b)
  {
    return new Vector4<T>
    (
      _a.x + _b.x, 
      _a.y + _b.y, 
      _a.z + _b.z,
      _a.w + _b.w
    );
  }

  template <typename T>
  Vector4<T>
  operator- (const Vector4<T>& _a, const Vector4<T>& _b)
  {
    return new Vector4<T>
    (
      _a.x - _b.x, 
      _a.y - _b.y, 
      _a.z - _b.z,
      _a.w - _b.w
    );
  }

  template <typename T>
  Vector4<T>
  operator- (const Vector4<T>& _v4)
  {
    return new Vector4<T>(-_v4.x, -_v4.y, -_v4.z, -_v4.w);
  }

  template <typename T>
  Vector4<T>
  operator* (const Vector4<T>& _a, const Vector4<T>& _b)
  {
    return new Vector4<T>
    (
      _a.x * _b.x, 
      _a.y * _b.y, 
      _a.z * _b.z,
      _a.w * _b.w
    );
  }

  template <typename T>
  Vector4<T>
  operator* (const Vector4<T>& _v4, const T& _s)
  {
    return new Vector4<T>
    (
      _v4.x * _s, 
      _v4.y * _s, 
      _v4.z * _s,
      _v4.w * _s
    );
  }

  template <typename T>
  Vector4<T>
  operator* (const T& _s, const Vector4<T>& _v4)
  {
    return new Vector4<T>
    (
      _v4.x * _s, 
      _v4.y * _s, 
      _v4.z * _s,
      _v4.w * _s
    );
  }

  template <typename T>
  Vector4<T>
  operator/ (const Vector4<T>& _a, const Vector4<T>& _b)
  {
    return new Vector4<T>
    (
      _a.x / _b.x, 
      _a.y / _b.y, 
      _a.z / _b.z,
      _a.w / _b.w
    );
  }

  template <typename T>
  Vector4<T>
  operator/ (const Vector4<T>& _v4, const T& _divisor)
  {
    return new Vector4<T>
    (
      _v4.x / _divisor, 
      _v4.y / _divisor, 
      _v4.z / _divisor,
      _v4.w / _divisor
    );
  }

  template <typename T>
  T&
  operator| (const Vector4<T>& _a, const Vector4<T>& _b)
  {
    return _a.x * _b.x + _a.y * _b.y + _a.z * _b.z + _a.w * _b.w;
  }

  template <typename T>
  Vector4<T>&
  operator+= (Vector4<T>& _a, const Vector4<T>& _b)
  {
    _a.x += _b.x;
    _a.y += _b.y;
    _a.z += _b.z;
    _a.w += _b.w;

    return _a;
  }

  template <typename T>
  Vector4<T>&
  operator-= (Vector4<T>& _a, const Vector4<T>& _b)
  {
    _a.x -= _b.x;
    _a.y -= _b.y;
    _a.z -= _b.z;
    _a.w -= _b.w;

    return *this;
  }

  template <typename T>
  Vector4<T>&
  operator*= (Vector4<T>& _a, const Vector4<T>& _b)
  {
    _a.x *= _b.x;
    _a.y *= _b.y;
    _a.z *= _b.z;
    _a.w *= _b.w;

    return *this;
  }

  template <typename T>
  Vector4<T>&
  operator*= (Vector4<T>& _v4, const T& _s)
  {
    _v4.x *= _s;
    _v4.y *= _s;
    _v4.z *= _s;
    _v4.w *= _s;

    return *this;
  }

  template <typename T>
  Vector4<T>&
  operator/= (Vector4<T>& _a, const Vector4<T>& _b)
  {
    _a.x /= _b.x;
    _a.y /= _b.y;
    _a.z /= _b.z;
    _a.w /= _b.w;

    return *this;
  }

  template <typename T>
  Vector4<T>&
  operator/= (Vector4<T>& _v4, const T& _s)
  {
    _v4.x /= _s;
    _v4.y /= _s;
    _v4.z /= _s;
    _v4.w /= _s;

    return *this;
  }

  template <typename T>
  bool&
  operator== (const Vector4<T>& _a, const Vector4<T>& _b)
  {
    return (_a.x == _b.x && _a.y == _b.y && _a.z == _b.z && _a.w == _b.w);
  }

  template <typename T>
  bool&
  operator!= (const Vector4<T>& _a, const Vector4<T>& _b)
  {
    return (_a.x != _b.x || _a.y != _b.y || _a.z != _b.z || _a.w != _b.w);
  }
}
