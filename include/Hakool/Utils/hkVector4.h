#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>

namespace hk
{
  /**
  * A representation of a vector in 4-dimensional space.
  */
  template <typename T>
  class HK_UTILITY_EXPORT Vector4
  {
  public:

    Vector4();

    Vector4(T& _x, T& _y, T& _z, T& _w);

    template<typename U>
    explicit Vector4(const Vector4<U>& _v4);

    ~Vector4();

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
  T&
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

#include <Hakool\Utils\hkVector4.inl>

  typedef Vector4<int32> Vector4i;
  typedef Vector4<uint32> Vector4u;
  typedef Vector4<float> Vector4f;
}