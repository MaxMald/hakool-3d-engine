#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>
#include <Hakool\Utils\hkVector4.h>

namespace hk
{
  /**
  * 4x4 Matrix that represents 3D transformations.
  *
  * Row major 4x4 Matrix that represent 3D transformations. All its members are
  * "float" values.
  */
  class HK_UTILITY_EXPORT Matrix4
  {
  public:
    Matrix4();

    Matrix4(const Matrix4& _mat4);

    Matrix4
    (
      const float& _m00, const float& _m01, const float& _m02, const float& _m03,
      const float& _m10, const float& _m11, const float& _m12, const float& _m13,
      const float& _m20, const float& _m21, const float& _m22, const float& _m23,
      const float& _m30, const float& _m31, const float& _m32, const float& _m33
    );

    ~Matrix4() = default;

    /**
    * Get a new Matrix representing an identity matrix.
    *
    * @returns Identity matrix.
    */
    static Matrix4
    GetIdentity();

    /**
    * Calculates the sum between two matrices and returns the resulted matrix.
    *
    * @param _mat4 Matrix.
    *
    * @return A new matrix representing the operation's result.
    */
    Matrix4
    operator+ (const Matrix4& _mat4) const;

    /**
    * Calculates the subtraction between two matrices and returns the
    * resulted matrix.
    *
    * @param _mat4 Matrix.
    *
    * @return A new matrix representing the operation's result.
    */
    Matrix4
    operator- (const Matrix4& _mat4) const;

    /**
    * Calculates the multiplication between two matrices and returns the
    * resulted matrix.
    *
    * @param _mat4 Matrix.
    *
    * @return A new matrix representing the operation's result.
    */
    Matrix4
    operator* (const Matrix4& _mat4) const;

    /**
    * Calculates the sum of two matrices and returns the result matrix.
    *
    * @param _mat4 Matrix.
    *
    * @return A new matrix representing the operation's result.
    */
    template<typename U>
    Vector4<float>
    operator* (const Vector4<U>& _vec4) const;

    /**
    * Copy data from other matrix.
    *
    * @param _mat4 Matrix.
    *
    * @return self.
    */
    Matrix4&
    operator= (const Matrix4& _mat4);

    /**
    * Assign the value to all the members of the matrix.
    *
    * @param _value Number.
    *
    * @return self.
    */
    Matrix4&
    operator= (const float& _value);

    /**
    * Calculates the sum between two matrices and returns set the result in the
    * left matrix.
    *
    * @param _mat4 Matrix.
    *
    * @return self.
    */
    Matrix4&
    operator+= (const Matrix4& _mat4);

    /**
    * Calculates the subtraction between two matrices and returns set the
    * result in the left matrix.
    *
    * @param _mat4 Matrix.
    *
    * @return self.
    */
    Matrix4&
    operator-= (const Matrix4& _mat4);

    /**
    * Calculates the multiplication between two matrices and returns set the
    * result in the left matrix.
    *
    * @param _mat4 Matrix.
    *
    * @return self.
    */
    Matrix4&
    operator*= (const Matrix4& _mat4);

    /**
    * Gets a new matrix representing the transposed matrix of this one.
    *
    * @return A new matrix representing the transposed matrix of this one.
    */
    Matrix4
    getTranspose() const;

    /**
    * Gets a new matrix representing the inverse matrix of this one.
    *
    * @return A new matrix representing the inverse matrix of this one.
    */
    Matrix4
    getInverse() const;

    /**
    * Gets a new matrix representing the matrix of minors.
    *
    * @return A new matrix representing the matrix of minors of this one.
    */
    Matrix4
    getMinors() const;

    /**
    * Transpose this matrix. This method modifies the matrix's current values.
    *
    * @return self.
    */
    Matrix4&
    transpose();

    /**
    * Inverse this matrix. This method modifies the matrix's current values.
    *
    * @return self.
    */
    Matrix4&
    inverse();

    /**
    * Set this matrix as an identity matrix. This method modifies the matrix's
    * current values.
    *
    * @return self.
    */
    Matrix4&
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
      float m[4][4];

      struct
      {
        float m00,m01,m02,m03,
              m10,m11,m12,m13,
              m20,m21,m22,m23,
              m30,m31,m32,m33;
      };

      Vector4f mRow[4];
    };
  };

  template<typename U>
  inline Vector4<float>
  Matrix4::operator*(const Vector4<U>& _vec4) const
  {
    Vector4<float> fVector
    (
      static_cast<float>(_vec4.x),
      static_cast<float>(_vec4.y),
      static_cast<float>(_vec4.z),
      static_cast<float>(_vec4.w)
    );

    return Vector4<float>
    (
      fVector | this->mRow[0],
      fVector | this->mRow[1],
      fVector | this->mRow[2],
      fVector | this->mRow[3]
    );
  }

  template<>
  inline Vector4<float>
  Matrix4::operator*(const Vector4<float>& _vec4) const
  {
    return Vector4<float>
    (
      _vec4 | this->mRow[0],
      _vec4 | this->mRow[1],
      _vec4 | this->mRow[2],
      _vec4 | this->mRow[3]
    );
  }
}
