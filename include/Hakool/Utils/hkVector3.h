#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>

namespace hk
{
  /**
  * A representation of a vector in 3-dimensional space.
  */
  template <typename T>
  class HK_UTILITY_EXPORT Vector3
  {
  public:    

    Vector3();

    Vector3(T& _x, T& _y, T& _z);

    template<typename U>
    explicit Vector3(const Vector3<U>& _v3);

    ~Vector3();

    T&
    operator[] (const uint32& _index);

    Vector3<T>&
    operator= (const Vector3<T>& _v3);

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
  T&
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

#include <Hakool\Utils\hkVector3.inl>

  typedef Vector3<int32> Vector3i;
  typedef Vector3<uint32> Vector3u;
  typedef Vector3<float> Vector3f;
}
