#pragma once

#include <Hakool\Utils\hkVector3.h>

namespace hk
{
  template<typename T>
  inline Vector3<T>::Vector3() :
  x(0), y(0), z(0)
  {
    return;
  }

  template<typename T>
  inline Vector3<T>::Vector3(T& _x, T& _y, T& _z) :
  x(_x), y(_y), z(_z)
  {
    return;
  }

  template<typename T>
  template<typename U>
  inline Vector3<T>::Vector3(const Vector3<U>& _v3) :
  x(static_cast<T>(_v3.x)),
  y(static_cast<T>(_v3.y)),
  z(static_cast<T>(_v3.z))
  {
    return
  }

  template<typename T>
  inline Vector3<T>::~Vector3()
  {
    return;
  }

  template<typename T>
  inline T&
  Vector3<T>::operator[](const uint32& _index)
  {
    // TODO: Assert
    return (&this->x)[_index];
  }

  template<typename T>
  inline Vector3<T>&
  Vector3<T>::operator=(const Vector3<T>& _v3)
  {
    this->x = _v3.x;
    this->y = _v3.y;
    this->z = _v3.z;
    return *this;
  }

  template <typename T>
  Vector3<T>
  operator+(const Vector3<T>& _a, const Vector3<T>& _b)
  {
    return new Vector3<T>(_a.x + _b.x, _a.y + _b.y, _a.z + _b.z);
  }

  template <typename T>
  Vector3<T>
  operator- (const Vector3<T>& _a, const Vector3<T>& _b)
  {
    return new Vector3<T>(_a.x - _b.x, _a.y - _b.y, _a.z - _b.z);
  }

  template <typename T>
  Vector3<T>
  operator- (const Vector3<T>& _v3)
  {
    return new Vector3<T>(-_v3.x, -_v3.y, -_v3.z);
  }

  template <typename T>
  Vector3<T>
  operator* (const Vector3<T>& _a, const Vector3<T>& _b)
  {
    return new Vector3<T>(_a.x * _b.x, _a.y * _b.y, _a.z * _b.z);
  }

  template <typename T>
  Vector3<T>
  operator* (const Vector3<T>& _v3, const T& _s)
  {
    return new Vector3<T>(_v3.x * _s, _v3.y * _s, _v3.z * _s);
  }

  template <typename T>
  Vector3<T>
  operator* (const T& _s, const Vector3<T>& _v3)
  {
    return new Vector3<T>(_v3.x * _s, _v3.y * _s, _v3.z * _s);
  }

  template <typename T>
  Vector3<T>
  operator/ (const Vector3<T>& _a, const Vector3<T>& _b)
  {
    return new Vector3<T>(_a.x / _b.x, _a.y / _b.y, _a.z / _b.z);
  }

  template <typename T>
  Vector3<T>
  operator/ (const Vector3<T>& _v3, const T& _divisor)
  {
    return new Vector3<T>(_v3.x / _divisor, _v3.y / _divisor, _v3.z / _divisor);
  }

  template <typename T>
  Vector3<T>
  operator^ (const Vector3<T>& _a, const Vector3<T>& _b)
  {
    return new Vector3<T>
    (
      _a.y * _b.z - _a.z * _b.y,
      _a.z * _b.x - _a.x * _b.z,
      _a.x * _b.y - _a.y * _b.x
    );
  }

  template <typename T>
  T&
  operator| (const Vector3<T>& _a, const Vector3<T>& _b)
  {
    return _a.x * _b.x + _a.y * _b.y + _a.z * _b.z;
  }

  template <typename T>
  Vector3<T>&
  operator+= (Vector3<T>& _a, const Vector3<T>& _b)
  {
    _a.x += _b.x;
    _a.y += _b.y;
    _a.z += _b.z;

    return _a;
  }

  template <typename T>
  Vector3<T>&
  operator-= (Vector3<T>& _a, const Vector3<T>& _b)
  {
    _a.x -= _b.x;
    _a.y -= _b.y;
    _a.z -= _b.z;

    return *this;
  }

  template <typename T>
  Vector3<T>&
  operator*= (Vector3<T>& _a, const Vector3<T>& _b)
  {
    _a.x *= _b.x;
    _a.y *= _b.y;
    _a.z *= _b.z;

    return *this;
  }

  template <typename T>
  Vector3<T>&
  operator*= (Vector3<T>& _v3, const T& _s)
  {
    _v3.x *= _s;
    _v3.y *= _s;
    _v3.z *= _s;

    return *this;
  }

  template <typename T>
  Vector3<T>&
  operator/= (Vector3<T>& _a, const Vector3<T>& _b)
  {
    _a.x /= _b.x;
    _a.y /= _b.y;
    _a.z /= _b.z;

    return *this;
  }

  template <typename T>
  Vector3<T>&
  operator/= (Vector3<T>& _v3, const T& _s)
  {
    _v3.x /= _s;
    _v3.y /= _s;
    _v3.z /= _s;

    return *this;
  }

  template <typename T>
  Vector3<T>&
  operator^= (Vector3<T>& _a, const Vector3<T>& _b)
  {
    T tx = _a.x;
    T ty = _a.y;
    T tz = _a.z;

    _a.x = ty * _b.z - tz * _b.y;
    _a.y = tz * _b.x - tx * _b.z;
    _a.z = tx * _b.y - ty * _b.x;

    return *this;
  }

  template <typename T>
  bool&
  operator== (const Vector3<T>& _a, const Vector3<T>& _b)
  {
    return (_a.x == _b.x && _a.y == _b.y && _a.z == _b.z);
  }

  template <typename T>
  bool&
  operator!= (const Vector3<T>& _a, const Vector3<T>& _b)
  {
    return (_a.x != _b.x || _a.y != _b.y || _a.z != _b.z);
  }
}