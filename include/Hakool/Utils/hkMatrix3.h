#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>
#include <Hakool\Utils\hkVector3.h>

namespace hk
{
  /**
  * 3x3 Matrix that represents 2D transformations.
  * 
  * Row major 3x3 Matrix that represent 2D transformations. All its members are
  * "float" values.
  */
  class HK_UTILITY_EXPORT Matrix3
  {
  public:
    Matrix3();

    Matrix3(const Matrix3& _mat3);

    Matrix3
    (
      const float& _m00, const float& _m01, const float& _m02,
      const float& _m10, const float& _m11, const float& _m12,
      const float& _m20, const float& _m21, const float& _m22
    );

    ~Matrix3() = default;

    /**
    * Get a new Matrix representing an identity matrix.
    * 
    * @returns Identity matrix.
    */
    static Matrix3
    GetIdentity();

    /**
    * Calculates the sum between two matrices and returns the resulted matrix.
    * 
    * @param _mat3 Matrix.
    * 
    * @return A new matrix representing the operation's result.
    */
    Matrix3
    operator+ (const Matrix3& _mat3) const;

    /**
    * Calculates the subtraction between two matrices and returns the 
    * resulted matrix.
    *
    * @param _mat3 Matrix.
    *
    * @return A new matrix representing the operation's result.
    */
    Matrix3
    operator- (const Matrix3& _mat3) const;

    /**
    * Calculates the multiplication between two matrices and returns the 
    * resulted matrix.
    *
    * @param _mat3 Matrix.
    *
    * @return A new matrix representing the operation's result.
    */
    Matrix3
    operator* (const Matrix3& _mat3) const;

    /**
    * Calculates the sum of two matrices and returns the result matrix.
    *
    * @param _mat3 Matrix.
    *
    * @return A new matrix representing the operation's result.
    */
    template<typename U>
    Vector3<float>
    operator* (const Vector3<U>& _vec3) const;

    /**
    * Copy data from other matrix.
    * 
    * @param _mat3 Matrix.
    * 
    * @return self.
    */
    Matrix3&
    operator= (const Matrix3& _mat3);

    /**
    * Assign the value to all the members of the matrix.
    * 
    * @param _value Number.
    * 
    * @return self.
    */
    Matrix3&
    operator= (const float& _value);

    /**
    * Calculates the sum between two matrices and returns set the result in the
    * left matrix.
    * 
    * @param _mat3 Matrix.
    * 
    * @return self.
    */
    Matrix3&
    operator+= (const Matrix3& _mat3);

    /**
    * Calculates the subtraction between two matrices and returns set the 
    * result in the left matrix.
    *
    * @param _mat3 Matrix.
    *
    * @return self.
    */
    Matrix3&
    operator-= (const Matrix3& _mat3);

    /**
    * Calculates the multiplication between two matrices and returns set the 
    * result in the left matrix.
    *
    * @param _mat3 Matrix.
    *
    * @return self.
    */
    Matrix3&
    operator*= (const Matrix3& _mat3);

    /**
    * Gets a new matrix representing the transposed matrix of this one.
    * 
    * @return A new matrix representing the transposed matrix of this one.
    */
    Matrix3
    getTranspose() const;

    /**
    * Gets a new matrix representing the inverse matrix of this one.
    * 
    * @return A new matrix representing the inverse matrix of this one.
    */
    Matrix3
    getInverse() const;

    /**
    * Gets a new matrix representing the matrix of minors.
    * 
    * @return A new matrix representing the matrix of minors of this one.
    */
    Matrix3
    getMinors() const;

    /**
    * Transpose this matrix. This method modifies the matrix's current values.
    * 
    * @return self.
    */
    Matrix3&
    transpose();

    /**
    * Inverse this matrix. This method modifies the matrix's current values.
    * 
    * @return self.
    */
    Matrix3&
    inverse();

    /**
    * Set this matrix as an identity matrix. This method modifies the matrix's 
    * current values.
    * 
    * @return self.
    */
    Matrix3&
    identity();

    /**
    * Get the determinant of this matrix.
    * 
    * @return Determinant of this matrix.
    */
    float
    determinant() const;

    union
    {
      float m[3][3];
      
      struct 
      {
        float m00, m01, m02,
              m10, m11, m12,
              m20, m21, m22;
      };

      Vector3f mRow[3];
    };
  };

  template<typename U>
  inline Vector3<float>
  Matrix3::operator*(const Vector3<U>& _vec3) const
  {
    Vector3<float> fVector
    (
      static_cast<float>(_vec3.x),
      static_cast<float>(_vec3.y),
      static_cast<float>(_vec3.z)
    );

    return Vector3<float>
    (
      fVector | this->mRow[0],
      fVector | this->mRow[1],
      fVector | this->mRow[2]
    );
  }

  template<>
  inline Vector3<float>
  Matrix3::operator*(const Vector3<float>& _vec3) const
  {
    return Vector3<float>
    (
      _vec3 | this->mRow[0],
      _vec3 | this->mRow[1],
      _vec3 | this->mRow[2]
    );
  }
}