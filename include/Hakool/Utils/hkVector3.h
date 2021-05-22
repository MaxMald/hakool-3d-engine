#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>
#include <Hakool\Utils\hkMath.h>

namespace hk
{
  /**
  * A representation of a vector in 3-dimensional space.
  */
  template <typename T>
  class Vector3
  {
  public:    

    Vector3();

    Vector3(const T& _x, const T& _y, const T& _z);

    ~Vector3() = default;

    template<typename U>
    explicit Vector3(const Vector3<U>& _v3);

    T&
    operator[] (const uint32& _index);

    Vector3<T>&
    operator= (const Vector3<T>& _v3);

    /**
    * Get the normalized vector (a unit length vector).
    * 
    * @return Normalized vector.
    */
    Vector3
    getNormalize() const;
    
    /**
    * Get the length of this vector.
    * 
    * @return The length of this vector. 
    */
    T
    magnitude() const;

    /**
    * Get the length of this vector squared.
    * 
    * @return The length of this vector squared.
    */
    T
    magnitudeSqr() const;

    /**
    * Makes this vector a unit length vector in the same direction.
    * 
    * @return Self.
    */
    Vector3&
    normalize();

    /**
    * Set the vector length of this vector.
    * 
    * @param _mag Desire vector length.
    * 
    * @return Self.
    */
    Vector3&
    setMagnitude(const T& _mag);

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
  Vector3<T>
  operator+ (const Vector3<T>& _a, const Vector3<T>& _b);

  /**
  * Component-wise subtraction between two vectors.
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @returns A new vector that represents the operation's result.
  */
  template <typename T>
  Vector3<T>
  operator- (const Vector3<T>& _a, const Vector3<T>& _b);

  /**
  * Negate a vector.
  *
  * @param _v3 Vector
  *
  * @returns Component-wise opposite of the vector.
  */
  template <typename T>
  Vector3<T>
  operator- (const Vector3<T>& _v3);

  /**
  * Component-wise multiplication between two vectors.
  * 
  * @param _a Vector.
  * @param _b Vector.
  * 
  * @returns A new vector that represents the operation's result.
  */
  template <typename T>
  Vector3<T>
  operator* (const Vector3<T>& _a, const Vector3<T>& _b);

  /**
  * Component-wise multiplication between a vector and an scalar.
  *
  * @param _v3 Vector.
  * @param _s Scalar.
  *
  * @returns A new vector that represents the operation's result.
  */
  template <typename T>
  Vector3<T>
  operator* (const Vector3<T>& _v3, const T& _s);

  /**
  * Component-wise multiplication between a vector and an scalar.
  *
  * @param _s Scalar.
  * @param _v3 Vector.
  *
  * @returns A new vector that represents the operation's result.
  */
  template <typename T>
  Vector3<T>
  operator* (const T& _s, const Vector3<T>& _v3);

  /**
  * Component-wise division between two vectors.
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @returns A new vector that represents the operation's result.
  */
  template <typename T>
  Vector3<T>
  operator/ (const Vector3<T>& _a, const Vector3<T>& _b);

  /**
  * Component-wise division between a vector and a single value.
  *
  * @param _v3 Vector.
  * @param _divisor Divisor.  
  *
  * @returns A new vector that represents the operation's result.
  */
  template <typename T>
  Vector3<T>
  operator/ (const Vector3<T>& _v3, const T& _divisor);

  /**
  * Cross product between two vectors.
  * 
  * This operation results in a perpendicular vector to both "_a" and "_b" 
  * vectors.
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @returns A perpendicular vector to both "_a" and "_b" vectors.
  */
  template <typename T>
  Vector3<T>
  operator^ (const Vector3<T>& _a, const Vector3<T>& _b);

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
  operator| (const Vector3<T>& _a, const Vector3<T>& _b);  

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
  Vector3<T>&
  operator+= (Vector3<T>& _a, const Vector3<T>& _b);

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
  Vector3<T>&
  operator-= (Vector3<T>& _a, const Vector3<T>& _b);

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
  Vector3<T>&
  operator*= (Vector3<T>& _a, const Vector3<T>& _b);

  /**
  * Component-wise multiplication between a vector and an scalar. The result is 
  * set in the left vector.
  *
  * @param _a Vector.
  * @param _s Scalar.
  *
  * @returns Reference to the left vector.
  */
  template <typename T>
  Vector3<T>&
  operator*= (Vector3<T>& _v3, const T& _s);

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
  Vector3<T>&
  operator/= (Vector3<T>& _a, const Vector3<T>& _b);

  /**
  * Component-wise division between a vector and an scalar. The result is
  * set in the left vector.
  *
  * @param _a Vector.
  * @param _divisor Divisor.
  *
  * @returns Reference to the left vector.
  */
  template <typename T>
  Vector3<T>&
  operator/= (Vector3<T>& _v3, const T& _divisor);

  /**
  * Cross product between two vectors. The result is set in the left vector.
  *
  * This operation results in a perpendicular vector to both "_a" and "_b"
  * vectors.
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @returns Reference to the left vector.
  */
  template <typename T>
  Vector3<T>&
  operator^= (Vector3<T>& _a, const Vector3<T>& _b);  

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
  operator== (const Vector3<T>& _a, const Vector3<T>& _b);

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
  operator!= (const Vector3<T>& _a, const Vector3<T>& _b);

  /***************************************************************************/
  /* Definitions                                                             */
  /***************************************************************************/

  template<typename T>
  inline Vector3<T>::Vector3() :
    x(static_cast<T>(0.0f)), 
    y(static_cast<T>(0.0f)),
    z(static_cast<T>(0.0f))
  {
    return;
  }

  template<typename T>
  inline Vector3<T>::Vector3(const T& _x, const T& _y, const T& _z) :
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
    return;
  }

  template<typename T>
  inline T&
  Vector3<T>::operator[](const uint32& _index)
  {
    // TODO: Assert
    return (&(this->x))[_index];
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

  template<typename T>
  inline Vector3<T> 
  Vector3<T>::getNormalize() const
  {
    T m = static_cast<T>(1.0f) / this->magnitude();
    return Vector3(this->x * m, this->y * m, this->z * m);
  }

  template<>
  inline Vector3<float>
  Vector3<float>::getNormalize() const
  {
    float m = 1.0f / this->magnitude();
    return Vector3(this->x * m, this->y * m, this->z * m);
  }

  template<typename T>
  inline T 
  Vector3<T>::magnitude() const
  {
    return Math::Sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
  }

  template<typename T>
  inline T 
  Vector3<T>::magnitudeSqr() const
  {
    return this->x * this->x + this->y * this->y + this->z * this->z;
  }

  template<typename T>
  inline Vector3<T>& 
  Vector3<T>::normalize()
  {
    T m = static_cast<T>(1.0f) / this->magnitude();
    this->x *= m;
    this->y *= m;
    this->z *= m;

    return *this;
  }

  template<>
  inline Vector3<float>&
  Vector3<float>::normalize()
  {
    float m = 1.0f / this->magnitude();
    this->x *= m;
    this->y *= m;
    this->z *= m;

    return *this;
  }

  template<typename T>
  inline Vector3<T>& 
  Vector3<T>::setMagnitude(const T& _mag)
  {
    T m = _mag / this->magnitude();
    this->x *= m;
    this->y *= m;
    this->z *= m;

    return *this;
  }

  template<>
  inline Vector3<float>&
  Vector3<float>::setMagnitude(const float& _mag)
  {
    float m = _mag / this->magnitude();
    this->x *= m;
    this->y *= m;
    this->z *= m;

    return *this;
  }

  template <typename T>
  inline Vector3<T>
  operator+(const Vector3<T>& _a, const Vector3<T>& _b)
  {
    return Vector3<T>(_a.x + _b.x, _a.y + _b.y, _a.z + _b.z);
  }

  template <typename T>
  inline Vector3<T>
  operator- (const Vector3<T>& _a, const Vector3<T>& _b)
  {
    return Vector3<T>(_a.x - _b.x, _a.y - _b.y, _a.z - _b.z);
  }

  template <typename T>
  inline Vector3<T>
  operator- (const Vector3<T>& _v3)
  {
    return Vector3<T>(-_v3.x, -_v3.y, -_v3.z);
  }

  template <typename T>
  inline Vector3<T>
  operator* (const Vector3<T>& _a, const Vector3<T>& _b)
  {
    return Vector3<T>(_a.x * _b.x, _a.y * _b.y, _a.z * _b.z);
  }

  template <typename T>
  inline Vector3<T>
  operator* (const Vector3<T>& _v3, const T& _s)
  {
    return Vector3<T>(_v3.x * _s, _v3.y * _s, _v3.z * _s);
  }

  template <typename T>
  inline Vector3<T>
  operator* (const T& _s, const Vector3<T>& _v3)
  {
    return Vector3<T>(_v3.x * _s, _v3.y * _s, _v3.z * _s);
  }

  template <typename T>
  inline Vector3<T>
  operator/ (const Vector3<T>& _a, const Vector3<T>& _b)
  {
    return Vector3<T>(_a.x / _b.x, _a.y / _b.y, _a.z / _b.z);
  }

  template <typename T>
  inline Vector3<T>
  operator/ (const Vector3<T>& _v3, const T& _divisor)
  {
    return Vector3<T>(_v3.x / _divisor, _v3.y / _divisor, _v3.z / _divisor);
  }

  template <typename T>
  inline Vector3<T>
  operator^ (const Vector3<T>& _a, const Vector3<T>& _b)
  {
    return Vector3<T>
    (
      _a.y * _b.z - _a.z * _b.y,
      _a.z * _b.x - _a.x * _b.z,
      _a.x * _b.y - _a.y * _b.x
    );
  }

  template <typename T>
  inline T
  operator| (const Vector3<T>& _a, const Vector3<T>& _b)
  {
    return (_a.x * _b.x + _a.y * _b.y + _a.z * _b.z);
  }

  template <typename T>
  inline Vector3<T>&
  operator+= (Vector3<T>& _a, const Vector3<T>& _b)
  {
    _a.x += _b.x;
    _a.y += _b.y;
    _a.z += _b.z;

    return _a;
  }

  template <typename T>
  inline Vector3<T>&
  operator-= (Vector3<T>& _a, const Vector3<T>& _b)
  {
    _a.x -= _b.x;
    _a.y -= _b.y;
    _a.z -= _b.z;

    return _a;
  }

  template <typename T>
  inline Vector3<T>&
  operator*= (Vector3<T>& _a, const Vector3<T>& _b)
  {
    _a.x *= _b.x;
    _a.y *= _b.y;
    _a.z *= _b.z;

    return _a;
  }

  template <typename T>
  inline Vector3<T>&
  operator*= (Vector3<T>& _v3, const T& _s)
  {
    _v3.x *= _s;
    _v3.y *= _s;
    _v3.z *= _s;

    return _v3;
  }

  template <typename T>
  inline Vector3<T>&
  operator/= (Vector3<T>& _a, const Vector3<T>& _b)
  {
    _a.x /= _b.x;
    _a.y /= _b.y;
    _a.z /= _b.z;

    return _a;
  }

  template <typename T>
  inline Vector3<T>&
  operator/= (Vector3<T>& _v3, const T& _s)
  {
    _v3.x /= _s;
    _v3.y /= _s;
    _v3.z /= _s;

    return _v3;
  }

  template <typename T>
  inline Vector3<T>&
  operator^= (Vector3<T>& _a, const Vector3<T>& _b)
  {
    T tx = _a.x;
    T ty = _a.y;
    T tz = _a.z;

    _a.x = ty * _b.z - tz * _b.y;
    _a.y = tz * _b.x - tx * _b.z;
    _a.z = tx * _b.y - ty * _b.x;

    return _a;
  }

  template <typename T>
  inline bool&
  operator== (const Vector3<T>& _a, const Vector3<T>& _b)
  {
    return (_a.x == _b.x && _a.y == _b.y && _a.z == _b.z);
  }

  template <typename T>
  inline bool&
  operator!= (const Vector3<T>& _a, const Vector3<T>& _b)
  {
    return (_a.x != _b.x || _a.y != _b.y || _a.z != _b.z);
  }

  /***************************************************************************/
  /*                                                                         */
  /***************************************************************************/

  typedef Vector3<int32> Vector3i;
  typedef Vector3<uint32> Vector3u;
  typedef Vector3<float> Vector3f;
}
