#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>

namespace hk
{
  /**
  * A representation of a vector in 4-dimensional space.
  */
  template <typename T>
  class Vector4
  {
  public:

    Vector4();

    Vector4(const T& _x, const T& _y, const T& _z, const T& _w);

    template<typename U>
    explicit Vector4(const Vector4<U>& _v4);

    ~Vector4() = default;

    T&
    operator[] (const uint32& _index);

    Vector4<T>&
    operator= (const Vector4<T>& _v4);

    /**
    * The x component of this vector.
    */
    T x;

    /**
    * The y component of this vector.
    */
    T y;

    /**
    * The z component of this vector.
    */
    T z;

    /**
    * The w component of this vector.
    */
    T w;
  };

  /**
  * Component-wise addition between two vectors.
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @returns A new vector that represents the operation's result.
  */
  template <typename T>
  Vector4<T>
  operator+ (const Vector4<T>& _a, const Vector4<T>& _b);

  /**
  * Component-wise subtraction between two vectors.
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @returns A new vector that represents the operation's result.
  */
  template <typename T>
  Vector4<T>
  operator- (const Vector4<T>& _a, const Vector4<T>& _b);

  /**
  * Negate a vector.
  *
  * @param _v4 Vector
  *
  * @returns Component-wise opposite of the vector.
  */
  template <typename T>
  Vector4<T>
  operator- (const Vector4<T>& _v4);

  /**
  * Component-wise multiplication between two vectors.
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @returns A new vector that represents the operation's result.
  */
  template <typename T>
  Vector4<T>
  operator* (const Vector4<T>& _a, const Vector4<T>& _b);

  /**
  * Component-wise multiplication between a vector and an scalar.
  *
  * @param _v4 Vector.
  * @param _s Scalar.
  *
  * @returns A new vector that represents the operation's result.
  */
  template <typename T>
  Vector4<T>
  operator* (const Vector4<T>& _v4, const T& _s);

  /**
  * Component-wise multiplication between a vector and an scalar.
  *
  * @param _s Scalar.
  * @param _v4 Vector.
  *
  * @returns A new vector that represents the operation's result.
  */
  template <typename T>
  Vector4<T>
  operator* (const T& _s, const Vector4<T>& _v4);

  /**
  * Component-wise division between two vectors.
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @returns A new vector that represents the operation's result.
  */
  template <typename T>
  Vector4<T>
  operator/ (const Vector4<T>& _a, const Vector4<T>& _b);

  /**
  * Component-wise division between a vector and a single value.
  *
  * @param _v4 Vector.
  * @param _divisor Divisor.
  *
  * @returns A new vector that represents the operation's result.
  */
  template <typename T>
  Vector4<T>
  operator/ (const Vector4<T>& _v4, const T& _divisor);

  /**
  * Dot production between two vectors.
  *
  * This operation results in the sum of the products of the corresponding
  * components of two vectors.
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @returns The sum of the products of the corresponding components of two
  * vectors.
  */
  template <typename T>
  T
  operator| (const Vector4<T>& _a, const Vector4<T>& _b);

  /**
  * Component-wise addition between two vectors. The result is set in the left
  * vector.
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @returns Reference to the left vector.
  */
  template <typename T>
  Vector4<T>&
  operator+= (Vector4<T>& _a, const Vector4<T>& _b);

  /**
  * Component-wise subtraction between two vectors. The result is set in the
  * left vector.
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @returns Reference to the left vector.
  */
  template <typename T>
  Vector4<T>&
  operator-= (Vector4<T>& _a, const Vector4<T>& _b);

  /**
  * Component-wise multiplication between two vectors. The result is set in the
  * left vector.
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @returns Reference to the left vector.
  */
  template <typename T>
  Vector4<T>&
  operator*= (Vector4<T>& _a, const Vector4<T>& _b);

  /**
  * Component-wise multiplication between a vector and an scalar. The result is
  * set in the left vector.
  *
  * @param _v4 Vector.
  * @param _s Scalar.
  *
  * @returns Reference to the left vector.
  */
  template <typename T>
  Vector4<T>&
  operator*= (Vector4<T>& _v4, const T& _s);

  /**
  * Component-wise division between two vectors. The result is set in the
  * left vector.
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @returns Reference to the left vector.
  */
  template <typename T>
  Vector4<T>&
  operator/= (Vector4<T>& _a, const Vector4<T>& _b);

  /**
  * Component-wise division between a vector and an scalar. The result is
  * set in the left vector.
  *
  * @param _v4 Vector.
  * @param _divisor Divisor.
  *
  * @returns Reference to the left vector.
  */
  template <typename T>
  Vector4<T>&
  operator/= (Vector4<T>& _v4, const T& _divisor);

  /**
  * Compares strict equality between two vectors.
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @returns Returns true if both vectors are equal.
  */
  template <typename T>
  bool&
  operator== (const Vector4<T>& _a, const Vector4<T>& _b);

  /**
  * Compares strict inequality between two vectors.
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @returns Returns true if both vectors are not equal.
  */
  template <typename T>
  bool&
  operator!= (const Vector4<T>& _a, const Vector4<T>& _b);

  /***************************************************************************/
  /* Definitions                                                             */
  /***************************************************************************/

  template<typename T>
  inline Vector4<T>::Vector4() :
    x(static_cast<T>(0)), 
    y(static_cast<T>(0)), 
    z(static_cast<T>(0)), 
    w(static_cast<T>(0))
  {
    return;
  }

  template<typename T>
  inline Vector4<T>::Vector4(const T& _x, const T& _y, const T& _z, const T& _w) :
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
    return;
  }

  template<typename T>
  inline T&
  Vector4<T>::operator[](const uint32& _index)
  {
    return (&(this->x))[_index];
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
  inline Vector4<T>
  operator+(const Vector4<T>& _a, const Vector4<T>& _b)
  {
    return Vector4<T>
    (
      _a.x + _b.x,
      _a.y + _b.y,
      _a.z + _b.z,
      _a.w + _b.w
    );
  }

  template <typename T>
  inline Vector4<T>
  operator- (const Vector4<T>& _a, const Vector4<T>& _b)
  {
    return Vector4<T>
    (
      _a.x - _b.x,
      _a.y - _b.y,
      _a.z - _b.z,
      _a.w - _b.w
    );
  }

  template <typename T>
  inline Vector4<T>
  operator- (const Vector4<T>& _v4)
  {
    return Vector4<T>(-_v4.x, -_v4.y, -_v4.z, -_v4.w);
  }

  template <typename T>
  inline Vector4<T>
  operator* (const Vector4<T>& _a, const Vector4<T>& _b)
  {
    return Vector4<T>
    (
      _a.x * _b.x,
      _a.y * _b.y,
      _a.z * _b.z,
      _a.w * _b.w
    );
  }

  template <typename T>
  inline Vector4<T>
  operator* (const Vector4<T>& _v4, const T& _s)
  {
    return Vector4<T>
    (
      _v4.x * _s,
      _v4.y * _s,
      _v4.z * _s,
      _v4.w * _s
    );
  }

  template <typename T>
  inline Vector4<T>
  operator* (const T& _s, const Vector4<T>& _v4)
  {
    return Vector4<T>
    (
      _v4.x * _s,
      _v4.y * _s,
      _v4.z * _s,
      _v4.w * _s
    );
  }

  template <typename T>
  inline Vector4<T>
  operator/ (const Vector4<T>& _a, const Vector4<T>& _b)
  {
    return Vector4<T>
    (
      _a.x / _b.x,
      _a.y / _b.y,
      _a.z / _b.z,
      _a.w / _b.w
    );
  }

  template <typename T>
  inline Vector4<T>
  operator/ (const Vector4<T>& _v4, const T& _divisor)
  {
    return Vector4<T>
    (
      _v4.x / _divisor,
      _v4.y / _divisor,
      _v4.z / _divisor,
      _v4.w / _divisor
    );
  }

  template <typename T>
  inline T
  operator| (const Vector4<T>& _a, const Vector4<T>& _b)
  {
    return _a.x * _b.x + _a.y * _b.y + _a.z * _b.z + _a.w * _b.w;
  }

  template <typename T>
  inline Vector4<T>&
  operator+= (Vector4<T>& _a, const Vector4<T>& _b)
  {
    _a.x += _b.x;
    _a.y += _b.y;
    _a.z += _b.z;
    _a.w += _b.w;

    return _a;
  }

  template <typename T>
  inline Vector4<T>&
  operator-= (Vector4<T>& _a, const Vector4<T>& _b)
  {
    _a.x -= _b.x;
    _a.y -= _b.y;
    _a.z -= _b.z;
    _a.w -= _b.w;

    return _a;
  }

  template <typename T>
  inline Vector4<T>&
  operator*= (Vector4<T>& _a, const Vector4<T>& _b)
  {
    _a.x *= _b.x;
    _a.y *= _b.y;
    _a.z *= _b.z;
    _a.w *= _b.w;

    return _a;
  }

  template <typename T>
  inline Vector4<T>&
  operator*= (Vector4<T>& _v4, const T& _s)
  {
    _v4.x *= _s;
    _v4.y *= _s;
    _v4.z *= _s;
    _v4.w *= _s;

    return _v4;
  }

  template <typename T>
  inline Vector4<T>&
  operator/= (Vector4<T>& _a, const Vector4<T>& _b)
  {
    _a.x /= _b.x;
    _a.y /= _b.y;
    _a.z /= _b.z;
    _a.w /= _b.w;

    return _a;
  }

  template <typename T>
  inline Vector4<T>&
  operator/= (Vector4<T>& _v4, const T& _s)
  {
    _v4.x /= _s;
    _v4.y /= _s;
    _v4.z /= _s;
    _v4.w /= _s;

    return _v4;
  }

  template <typename T>
  inline bool&
  operator== (const Vector4<T>& _a, const Vector4<T>& _b)
  {
    return (_a.x == _b.x && _a.y == _b.y && _a.z == _b.z && _a.w == _b.w);
  }

  template <typename T>
  inline bool&
  operator!= (const Vector4<T>& _a, const Vector4<T>& _b)
  {
    return (_a.x != _b.x || _a.y != _b.y || _a.z != _b.z || _a.w != _b.w);
  }

  typedef Vector4<int32> Vector4i;
  typedef Vector4<uint32> Vector4u;
  typedef Vector4<float> Vector4f;
}