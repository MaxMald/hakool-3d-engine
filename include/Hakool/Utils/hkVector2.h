#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>

namespace hk
{
  /**
  * A representation of a vector in 2-dimensional space.
  */
  template <typename T>
  class HK_UTILITY_EXPORT Vector2
  {
  public:

    Vector2();

    Vector2(T _x, T _y);

    template <typename U>
    explicit Vector2(const Vector2<U>& _vector);

    ~Vector2();

    T&
    operator[] (const uint32& _index);

    Vector2<T>&
    operator= (const Vector2<T>& _v2);   

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
  T&
  operator| (const Vector2<T>& _a, const Vector2<T>& _b);

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

#include <Hakool\Utils\hkVector2.inl>

  typedef Vector2<int32> Vector2i;
  typedef Vector2<uint32> Vector2u;
  typedef Vector2<float> Vector2f;
}