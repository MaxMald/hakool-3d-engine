#pragma once

namespace hk
{
  /**
  * Defines a mathematical vector with two dimension. This structure is 
  * usually used to represent a size, position, velocity, etc.
  * 
  * The template parameter must be a type that supports arithmetic operations
  * like: +, -, /, *; also comparison operations like == and !=.
  */
  template <typename T>
  class Vector2
  {
  public:

    /**
    * Constructs the vector with default values. (0,0).
    */
    Vector2();

    /**
    * Construct the vector from its x and y values.
    * 
    * @param _x x component.
    * @param _y y component.
    */
    Vector2(T _x, T _y);

    /**
    * Construct the vector from another type of vector.
    */
    template <typename U>
    explicit Vector2(const Vector2<U>& _vector);

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
  * Vectors addition.
  *
  * @param _addendL Left vector.
  * @param _addendR Right vector.
  *
  * @return Addition of both vectors.
  */
  template <typename T>
  Vector2<T> operator+ (const Vector2<T>& _addendL, const Vector2<T> _addendR);

  /**
  * Vectors subtraction.
  *
  * @param _subtrahendL Left vector.
  * @param _subtrahendR Right vector.
  *
  * @return Subtraction of both vectors.
  */
  template <typename T>
  Vector2<T> operator- (const Vector2<T>& _minuend, const Vector2<T>& _subtrahend);

  /**
  * Vectors subtraction.
  *
  * @param _subtrahendL Left vector.
  * @param _subtrahendR Right vector.
  *
  * @return Subtraction of both vectors.
  */
  template <typename T>
  Vector2<T> operator- (const Vector2<T>& _subtrahend);

  /**
  * Performs a member addition of both vectors and assigns the result to
  * the left.
  *
  * @param _addendL Left addend.
  * @param _addendR Right addend.
  *
  * @return Reference to left vector.
  */
  template <typename T>
  Vector2<T>& operator+= (Vector2<T>& _addendL, const Vector2<T>& _addendR);

  /**
  * Performs a member subtraction of both vectors, and assigns the result to
  * the left.
  *
  * @param _minuend Minuend vector.
  * @param _subtrahend Subtrahend vector.
  *
  * @result Reference to the left vector.
  */
  template <typename T>
  Vector2<T>& operator-= (Vector2<T>& _minuend, const Vector2<T>& _subtrahend);

  /**
  * Performs a multiplication by an scalar.
  *
  * @param _factorL Left vector.
  * @param _factorR scalar.
  *
  * @result Vector multiplied by the scale.
  */
  template <typename T>
  Vector2<T> operator* (const Vector2<T>& _factorL, T _factorR);

  /**
  * Performs a multiplication by an scalar.
  *
  * @param _factorL scalar.
  * @param _factorR Right factor.
  *
  * @result Vector multiplied by the scale.
  */
  template <typename T>
  Vector2<T> operator* (const T _factorL, Vector2<T>& _factorR);

  /**
  * This operator performs a multiplication by an scalar and assigns the
  * result to the left.
  *
  * @param _factorL Left vector.
  * @param _factorR Scalar.
  *
  * @return Reference to the left vector.
  */
  template <typename T>
  Vector2<T>& operator*= (Vector2<T>& _factorL, T _factorR);

  /**
  * This operator performs a multiplication by an scalar and assigns the
  * result to the left.
  *
  * @param _dividend Vector left.
  * @param _divisor Scalar.
  *
  * @return Divided vector.
  */
  template <typename T>
  Vector2<T> operator/ (const Vector2<T>& _dividend, T _divisor);

  /**
  * This operator performs a multiplication by an scalar and assigns the
  * result to the left.
  *
  * @param _dividend Vector left.
  * @param _divisor Scalar
  *
  * @return Reference to the left vector.
  */
  template <typename T>
  Vector2<T>& operator/= (Vector2<T>& _dividend, T _divisor);

  /**
  * Compares equality between two vectors.
  *
  * @param _left Left vector.
  * @param _right Right vector.
  *
  * @return True if both vectors have equal members.
  */
  template <typename T>
  bool operator== (const Vector2<T>& _left, const Vector2<T>& _right);

  /**
  * Compares difference between two vectors.
  *
  * @param _left Left vector.
  * @param _right Right vector.
  *
  * @return True if both vectors have not equal members.
  */
  template <typename T>
  bool operator!= (const Vector2<T>& _left, const Vector2<T>& _right);  

#include <Hakool\Utils\hkVector2.inl>

  typedef Vector2<int>          Vector2i;
  typedef Vector2<unsigned int> Vector2u;
  typedef Vector2<float>        Vector2f;
}