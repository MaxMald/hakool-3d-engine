#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>
#include <Hakool\Utils\hkMath.h>

namespace hk
{
  /**
  * A representation of a vector in 2-dimensional space.
  */
  template <typename T>
  class Vector2
  {
  public:

    Vector2();

    Vector2(const T& _x, const T& _y);

    template <typename U>
    explicit Vector2(const Vector2<U>& _vector);

    ~Vector2();

    T&
    operator[] (const uint32& _index);

    Vector2<T>&
    operator= (const Vector2<T>& _v2);

    /**
    * Get the normalized vector (a unit length vector).
    *
    * @return Normalized vector.
    */
    Vector2
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
    Vector2&
    normalize();

    /**
    * Set the vector length of this vector.
    *
    * @param _mag Desire vector length.
    *
    * @return Self.
    */
    Vector2&
    setMagnitude(const T& _mag);

    /**
    * The x component of this vector.
    */
    T x;

    /**
    * The y component of this vector.
    */
    T y;

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
  Vector2<T> 
  operator+ (const Vector2<T>& _a, const Vector2<T> _b);

  /**
  * Component-wise subtraction between two vectors.
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @returns A new vector that represents the operation's result.
  */
  template <typename T>
  Vector2<T> 
  operator- (const Vector2<T>& _a, const Vector2<T>& _b);

  /**
  * Negate a vector.
  *
  * @param _v2 Vector
  *
  * @returns Component-wise opposite of the vector.
  */
  template <typename T>
  Vector2<T> 
  operator- (const Vector2<T>& _v2);

  /**
  * Component-wise multiplication between two vectors.
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @returns A new vector that represents the operation's result.
  */
  template <typename T>
  Vector2<T>
  operator* (const Vector2<T>& _a, const Vector2<T>& _b);

  /**
  * Component-wise multiplication between a vector and an scalar.
  *
  * @param _v2 Vector.
  * @param _s Scalar.
  *
  * @returns A new vector that represents the operation's result.
  */
  template <typename T>
  Vector2<T>
  operator* (const Vector2<T>& _v2, T _s);

  /**
  * Component-wise multiplication between a vector and an scalar.
  *
  * @param _s Scalar.
  * @param _v3 Vector.
  *
  * @returns A new vector that represents the operation's result.
  */
  template <typename T>
  Vector2<T>
  operator* (const T _s, Vector2<T>& _v2);

  /**
  * Component-wise division between two vectors.
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @returns A new vector that represents the operation's result.
  */
  template <typename T>
  Vector2<T>
  operator/ (const Vector2<T>& _a, const Vector2<T>& _b);
  
  /**
  * Component-wise division between a vector and a single value.
  *
  * @param _v2 Vector.
  * @param _divisor Divisor.
  *
  * @returns A new vector that represents the operation's result.
  */
  template <typename T>
  Vector2<T>
  operator/ (const Vector2<T>& _v2, T _divisor);

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
  operator| (const Vector2<T>& _a, const Vector2<T>& _b);

  /**
  *  Calculate the projected vector from vector a onto vector _b
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @return Projected vector from vector a onto vector _b.
  */
  template <typename T>
  Vector2<T>
  operator^ (const Vector2<T>& _a, const Vector2<T>& _b);

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
  Vector2<T>&
  operator+= (Vector2<T>& _a, const Vector2<T>& _b);

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
  Vector2<T>&
  operator-= (Vector2<T>& _a, const Vector2<T>& _b);

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
  Vector2<T>&
  operator*= (Vector2<T>& _a, Vector2<T>& _b);

  /**
  * Component-wise multiplication between a vector and an scalar. The result is
  * set in the left vector.
  *
  * @param _v2 Vector.
  * @param _s Scalar.
  *
  * @returns Reference to the left vector.
  */
  template <typename T>
  Vector2<T>&
  operator*= (Vector2<T>& _v2, T _s); 

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
  Vector2<T>&
  operator/= (Vector2<T>& _a, Vector2<T>& _b);

  /**
  * Component-wise division between a vector and an scalar. The result is
  * set in the left vector.
  *
  * @param _v2 Vector.
  * @param _divisor Divisor.
  *
  * @returns Reference to the left vector.
  */
  template <typename T>
  Vector2<T>& 
  operator/= (Vector2<T>& _v2, T _divisor);

  /**
  * Calculate the projected vector from vector a onto vector _b. The result
  * is set in the left vector.
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @return Projected vector from vector a onto vector _b.
  */
  template <typename T>
  Vector2<T>&
  operator^= (Vector2<T>& _a, const Vector2<T>& _b);

  /**
  * Compares strict equality between two vectors.
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @returns Returns true if both vectors are equal.
  */
  template <typename T>
  bool 
  operator== (const Vector2<T>& _a, const Vector2<T>& _b);

  /**
  * Compares strict inequality between two vectors.
  *
  * @param _a Vector.
  * @param _b Vector.
  *
  * @returns Returns true if both vectors are not equal.
  */
  template <typename T>
  bool 
  operator!= (const Vector2<T>& _a, const Vector2<T>& _b);

  /***************************************************************************/
  /* Definitions                                                             */
  /***************************************************************************/

  template<typename T>
  inline Vector2<T>::Vector2() :
    x(static_cast<T>(0.0f)), y(static_cast<T>(0.0f))
  {
    return;
  }

  template<typename T>
  inline Vector2<T>::Vector2(const T& _x, const T& _y) :
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
    return (&(this->x))[_index];
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
  Vector2<T>::getNormalize() const
  {
    T m = static_cast<T>(1.0f) / this->magnitude();

    return Vector2(this->x * m, this->y * m);
  }

  template<>
  inline Vector2<float>
  Vector2<float>::getNormalize() const
  {
    float m = 1.0f / this->magnitude();

    return Vector2(this->x * m, this->y * m);
  }

  template<typename T>
  inline T 
  Vector2<T>::magnitude() const
  {
    return Math::Sqrt(this->x * this->x + this->y * this->y);
  }

  template<typename T>
  inline T 
  Vector2<T>::magnitudeSqr() const
  {
    return this->x * this->x + this->y * this->y;
  }

  template<typename T>
  inline Vector2<T>& 
  Vector2<T>::normalize()
  {
    T m = static_cast<T>(1.0f) / this->magnitude();
    this->x *= m;
    this->y *= m;

    return *this;
  }

  template<>
  inline Vector2<float>&
  Vector2<float>::normalize()
  {
    float m = 1.0f / this->magnitude();
    this->x *= m;
    this->y *= m;

    return *this;
  }

  template<typename T>
  inline Vector2<T>& 
  Vector2<T>::setMagnitude(const T& _mag)
  {
    T m = _mag / this->magnitude();
    this->x *= m;
    this->y *= m;

    return *this;
  }

  template<>
  inline Vector2<float>&
  Vector2<float>::setMagnitude(const float& _mag)
  {
    float m = _mag / this->magnitude();
    this->x *= m;
    this->y *= m;

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
    return Vector2<T>(-_v2.x, -_v2.y);
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
  inline T
  operator| (const Vector2<T>& _a, const Vector2<T>& _b)
  {
    return _a.x * _b.x + _a.y * _b.y;
  }

  template<typename T>
  Vector2<T> operator^(const Vector2<T>& _a, const Vector2<T>& _b)
  {
    const T factor = (_a.x * _b.x + _a.y * _b.y)
                   / (_b.x * _b.x + _b.y * _b.y);
    return Vector2<T>
    (
      _b.x * factor,
      _b.y * factor
    );
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
  inline Vector2<T>&
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
  Vector2<T>& 
  operator^=(Vector2<T>& _a, const Vector2<T>& _b)
  {
    const T factor = (_a.x * _b.x + _a.y * _b.y)
                   / (_b.x * _b.x + _b.y * _b.y);
    _a.x = _b.x * factor;
    _a.y = _b.y * factor;

    return _a;
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

  /***************************************************************************/
  /*                                                                         */
  /***************************************************************************/

  typedef Vector2<int32> Vector2i;
  typedef Vector2<uint32> Vector2u;
  typedef Vector2<float> Vector2f;
}