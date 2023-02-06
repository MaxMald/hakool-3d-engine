#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>
#include <Hakool\Utils\hkVector3.h>
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
    * Get a new translation matrix.
    * 
    * @param _x The x component.
    * @param _y The y component.
    * @param _z The z component.
    * 
    * @return Translation Matrix.
    */
    static Matrix4
    GetTranslation(const float& _x, const float& _y, const float& _z);

    /**
     * Get a new translation matrix.
     * 
     * @param vector Vector3f.
     * 
     * @return Translation Matrix.
     */
    static Matrix4
    GetTranslation(const Vector3f& vector);

    /**
    * Get a new scale matrix.
    * 
    * @param _x The x component.
    * @param _y The y component.
    * @param _z The z component.
    * 
    * @return Scaling Matrix.
    */
    static Matrix4
    GetScale(const float& _x, const float& _y, const float& _z);

    /**
    * Get a new scale matrix.
    *
    * @param vector Vector3f.
    *
    * @return Scaling Matrix.
    */
    static Matrix4
    GetScale(const Vector3f& vector);

    /**
    * Get a new rotation matrix about the given axis (normalized) and a given 
    * angle.
    *
    * @param _theta Angle in radians.
    * @param _x The x component.
    * @param _y The y component.
    * @param _z The z component.
    *
    * @return Rotate Matrix.
    */
    static Matrix4
    GetRotation
    (
      const float& _theta, 
      const float& _x, 
      const float& _y, 
      const float& _z
    );

    /**
    * Get a new rotation matrix about the given axis (normalized) and a given
    * angle.
    *
    * @param vector Vector3f.
    *
    * @return Rotate Matrix.
    */
    static Matrix4
    GetRotation(const Vector3f& vector);

    /**
    * Get a new rotation matrix about the given axis (normalized) and a given 
    * angle.
    *
    * @param _theta Angle in radians.
    * @param _v3 Normalized axis vector.
    *
    * @return Rotate Matrix.
    */
    static Matrix4
    GetRotation(const float& _theta, const Vector3<float>& _v3);

    /**
    * Get a new LookAt Matrix.
    * 
    * @param _from Position of the eye.
    * @param _to Position of the center.
    * @param _up Up Vector.
    * 
    * @return LookAt Matrix.
    */
    static Matrix4
    GetLookAt(const Vector3f& _from, const Vector3f& _to, const Vector3f& _up);

    /**
    * Get a perspective matrix.
    * 
    * @param _fov Field of view.
    * @param _ratio Aspect ratio.
    * @param _n Near.
    * @param _f Far.
    * 
    * @return Perspective matrix.
    */
    static Matrix4
    GetPerspective
    (
      const float& _fov, 
      const float& _ratio, 
      const float& _n, 
      const float& _f
    );

    /**
    * Get an Orthographic matrix.
    * 
    * @param _left Left.
    * @param _top Top.
    * @param _right Right.
    * @param _bottom Bottom.
    * @param _near Near.
    * @param _far Far.
    * 
    * @return Orthographic matrix.
    */
    static Matrix4
    GetOrthographic
    (
      const float& _left,
      const float& _top,
      const float& _right,
      const float& _bottom,
      const float& _near,
      const float& _far
    );

    /**
    * Get the rotational matrix around the x axis.
    * 
    * @param _theta Angle in radians.
    * 
    * @return Rotation matrix around the x axis.
    */
    static Matrix4
    GetRotationX(const float& _theta);

    /**
    * Get the rotational matrix around the y axis.
    *
    * @param _theta Angle in radians.
    *
    * @return Rotation matrix around the y axis.
    */
    static Matrix4
    GetRotationY(const float& _theta);

    /**
    * Get the rotational matrix around the z axis.
    *
    * @param _theta Angle in radians.
    *
    * @return Rotation matrix around the z axis.
    */
    static Matrix4
    GetRotationZ(const float& _theta);

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
    * Set this matrix as a translation matrix.
    *
    * @param _x The x component.
    * @param _y The y component.
    * @param _z The z component.
    *
    * @return self.
    */
    Matrix4&
    setTransalation(const float& _x, const float& _y, const float& _z);

    /**
    * Set this matrix as a scale matrix.
    *
    * @param _x The x component.
    * @param _y The y component.
    * @param _z The z component.
    *
    * @return self.
    */
    Matrix4&
    setScale(const float& _x, const float& _y, const float& _z);

    /**
    * Get a new rotate matrix.
    *
    * @param _x The x component.
    * @param _y The y component.
    * @param _z The z component.
    *
    * @return Rotate Matrix.
    */
    //static Matrix4
    //setRotate(const float& _x, const float& _y, const float& _z);

    /**
    * Set this matrix as a look at matrix.
    *
    * @param _from Camera's position.
    * @param _to Target's position.
    * @param _up Up Vector.
    *
    * @return self.
    */
    Matrix4&
    setLookAt(const Vector3f& _from, const Vector3f& _to, const Vector3f& _up);

    /**
    * Set this matrix as a perspective matrix.
    *
    * @param _fov Field of view.
    * @param _ratio Aspect ratio.
    * @param _n Near.
    * @param _f Far.
    *
    * @return self.
    */
    Matrix4&
    setPerspective
    (
      const float& _fov,
      const float& _ratio,
      const float& _n,
      const float& _f
    );

    /**
    * Set this matrix as an orthographic matrix.
    *
    * @param _left Left.
    * @param _top Top.
    * @param _right Right.
    * @param _bottom Bottom.
    * @param _near Near.
    * @param _far Far.
    *
    * @return self.
    */
    Matrix4&
    setOrthographic
    (
      const float& _left,
      const float& _top,
      const float& _right,
      const float& _bottom,
      const float& _near,
      const float& _far
    );

    /**
    * Set this matrix as a rotation matrix about the given axis (normalized) 
    * and a given angle.
    *
    * @param _theta Angle in radians.
    * @param _x The x component.
    * @param _y The y component.
    * @param _z The z component.
    *
    * @return Self.
    */
    Matrix4&
    setRotation
    (
      const float& _theta,
      const float& _x,
      const float& _y,
      const float& _z
    );

    /**
    * Set this matrix as a rotation matrix about the given axis (normalized) 
    * and a given angle.
    *
    * @param _theta Angle in radians.
    * @param _v3 Axis vector (normalized).
    *
    * @return Self.
    */
    Matrix4&
    setRotation(const float& _theta, const Vector3<float>& _v3);

    /**
    * Set this matrix as a rotate matrix around the x axis.
    *
    * @param _theta Angle in radians.
    *
    * @return Self.
    */
    Matrix4&
    setRotationX(const float& _theta);

    /**
    * Set this matrix as a rotate matrix around the y axis.
    *
    * @param _theta Angle in radians.
    *
    * @return Self.
    */
    Matrix4&
    setRotationY(const float& _theta);

    /**
    * Set this matrix as a rotate matrix around the z axis.
    *
    * @param _theta Angle in radians.
    *
    * @return Self.
    */
    Matrix4&
    setRotationZ(const float& _theta);

    /**
    * Set this matrix as an identity matrix. This method modifies the matrix's
    * current values.
    *
    * @return Self.
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

    float*
    getMatrixPtr();

    union
    {
      float a[16];
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
