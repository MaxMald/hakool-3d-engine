#include <Hakool\Utils\hkMatrix3.h>
#include <Hakool\Utils\hkUtilitiesUtilities.h>

using std::swap;

namespace hk
{
  Matrix3::Matrix3()
  {
    this->m00 = 0.0f; this->m01 = 0.0f; this->m02 = 0.0f;
    this->m10 = 0.0f; this->m11 = 0.0f; this->m12 = 0.0f;
    this->m20 = 0.0f; this->m21 = 0.0f; this->m22 = 0.0f;

    return;
  }

  Matrix3::Matrix3(const Matrix3& _mat3)
  {
    this->mRow[0] = _mat3.mRow[0];
    this->mRow[1] = _mat3.mRow[1];
    this->mRow[2] = _mat3.mRow[2];

    return;
  }

  Matrix3::Matrix3
  (
    const float& _m00, const float& _m01, const float& _m02, 
    const float& _m10, const float& _m11, const float& _m12, 
    const float& _m20, const float& _m21, const float& _m22
  )
  {
    this->m00 = _m00; this->m01 = _m01; this->m02 = _m02;
    this->m10 = _m10; this->m11 = _m11; this->m12 = _m12;
    this->m20 = _m20; this->m21 = _m21; this->m22 = _m22;

    return;
  }

  Matrix3 
  Matrix3::GetIdentity()
  {
    return Matrix3
    (
      1.0f, 0.0f, 0.0f,
      0.0f, 1.0f, 0.0f,
      0.0f, 0.0f, 1.0f
    );
  }

  Matrix3 
  Matrix3::operator+(const Matrix3& _mat3) const
  {
    return Matrix3
    (
      this->m00 + _mat3.m00, this->m01 + _mat3.m01, this->m02 + _mat3.m02,
      this->m10 + _mat3.m10, this->m11 + _mat3.m11, this->m12 + _mat3.m12,
      this->m20 + _mat3.m20, this->m21 + _mat3.m21, this->m22 + _mat3.m22
    );
  }

  Matrix3 
  Matrix3::operator-(const Matrix3& _mat3) const
  {
    return Matrix3
    (
      this->m00 - _mat3.m00, this->m01 - _mat3.m01, this->m02 - _mat3.m02,
      this->m10 - _mat3.m10, this->m11 - _mat3.m11, this->m12 - _mat3.m12,
      this->m20 - _mat3.m20, this->m21 - _mat3.m21, this->m22 - _mat3.m22
    );
  }

  Matrix3 
  Matrix3::operator*(const Matrix3& _mat3) const
  {
    return Matrix3
    (
      this->m00 * _mat3.m00 + this->m01 * _mat3.m10 + this->m02 * _mat3.m20,
      this->m00 * _mat3.m01 + this->m01 * _mat3.m11 + this->m02 * _mat3.m21,
      this->m00 * _mat3.m02 + this->m01 * _mat3.m12 + this->m02 * _mat3.m22,
      this->m10 * _mat3.m00 + this->m11 * _mat3.m10 + this->m12 * _mat3.m20,
      this->m10 * _mat3.m01 + this->m11 * _mat3.m11 + this->m12 * _mat3.m21,
      this->m10 * _mat3.m02 + this->m11 * _mat3.m12 + this->m12 * _mat3.m22,
      this->m20 * _mat3.m00 + this->m21 * _mat3.m10 + this->m22 * _mat3.m20,
      this->m20 * _mat3.m01 + this->m21 * _mat3.m11 + this->m22 * _mat3.m21,
      this->m20 * _mat3.m02 + this->m21 * _mat3.m12 + this->m22 * _mat3.m22
    );
  }

  Matrix3& 
  Matrix3::operator=(const Matrix3& _mat3)
  {
    this->m00 = _mat3.m00; this->m01 = _mat3.m01; this->m02 = _mat3.m02;
    this->m10 = _mat3.m10; this->m11 = _mat3.m11; this->m12 = _mat3.m12;
    this->m20 = _mat3.m20; this->m21 = _mat3.m21; this->m22 = _mat3.m22;

    return *this;
  }

  Matrix3& 
  Matrix3::operator=(const float& _value)
  {
    this->m00 = _value; this->m01 = _value; this->m02 = _value;
    this->m10 = _value; this->m11 = _value; this->m12 = _value;
    this->m20 = _value; this->m21 = _value; this->m22 = _value;

    return *this;
  }

  Matrix3& 
  Matrix3::operator+=(const Matrix3& _mat3)
  {
    this->m00 += _mat3.m00; this->m01 += _mat3.m01; this->m02 += _mat3.m02;
    this->m10 += _mat3.m10; this->m11 += _mat3.m11; this->m12 += _mat3.m12;
    this->m20 += _mat3.m20; this->m21 += _mat3.m21; this->m22 += _mat3.m22;

    return *this;
  }

  Matrix3& 
  Matrix3::operator-=(const Matrix3& _mat3)
  {
    this->m00 -= _mat3.m00; this->m01 -= _mat3.m01; this->m02 -= _mat3.m02;
    this->m10 -= _mat3.m10; this->m11 -= _mat3.m11; this->m12 -= _mat3.m12;
    this->m20 -= _mat3.m20; this->m21 -= _mat3.m21; this->m22 -= _mat3.m22;

    return *this;
  }

  Matrix3& 
  Matrix3::operator*=(const Matrix3& _mat3)
  {
    Matrix3 copy(*this);

    this->m00= copy.m00* _mat3.m00 + copy.m01* _mat3.m10 + copy.m02* _mat3.m20;
    this->m01= copy.m00* _mat3.m01 + copy.m01* _mat3.m11 + copy.m02* _mat3.m21;
    this->m02= copy.m00* _mat3.m02 + copy.m01* _mat3.m12 + copy.m02* _mat3.m22;
    this->m10= copy.m10* _mat3.m00 + copy.m11* _mat3.m10 + copy.m12* _mat3.m20;
    this->m11= copy.m10* _mat3.m01 + copy.m11* _mat3.m11 + copy.m12* _mat3.m21;
    this->m12= copy.m10* _mat3.m02 + copy.m11* _mat3.m12 + copy.m12* _mat3.m22;
    this->m20= copy.m20* _mat3.m00 + copy.m21* _mat3.m10 + copy.m22* _mat3.m20;
    this->m21= copy.m20* _mat3.m01 + copy.m21* _mat3.m11 + copy.m22* _mat3.m21;
    this->m22= copy.m20* _mat3.m02 + copy.m21* _mat3.m12 + copy.m22* _mat3.m22;

    return *this;
  }

  Matrix3 
  Matrix3::getTranspose() const
  {
    return Matrix3
    (
      this->m00, this->m10, this->m20,
      this->m01, this->m11, this->m21,
      this->m02, this->m12, this->m22
    );
  }

  Matrix3 
  Matrix3::getInverse() const
  {
    const float det = this->determinant();
    if (RelativelyEqual(det, 0.0f))
    {
      return Matrix3();
    }

    Matrix3 minors = this->getMinors();

    // Cofactors
    minors.m01 *= -1.0f;
    minors.m10 *= -1.0f;
    minors.m12 *= -1.0f;
    minors.m21 *= -1.0f;

    minors.transpose();

    // Inverse
    const float factor = 1.0f / det;
    return Matrix3
    (
      minors.m00 * factor, minors.m01 * factor, minors.m02 * factor,
      minors.m10 * factor, minors.m11 * factor, minors.m12 * factor,
      minors.m20 * factor, minors.m21 * factor, minors.m22 * factor
    );
  }

  Matrix3
  Matrix3::getMinors() const
  {
    return Matrix3
    (
      this->m11 * this->m22 - this->m21 * this->m12,
      this->m10 * this->m22 - this->m20 * this->m12,
      this->m10 * this->m21 - this->m20 * this->m11,
      this->m01 * this->m22 - this->m21 * this->m02,
      this->m00 * this->m22 - this->m20 * this->m02,
      this->m00 * this->m21 - this->m20 * this->m01,
      this->m01 * this->m12 - this->m11 * this->m02,
      this->m00 * this->m12 - this->m10 * this->m02,
      this->m00 * this->m11 - this->m10 * this->m01
    );
  }

  Matrix3& 
  Matrix3::transpose()
  { 
    swap(this->m01, this->m10);
    swap(this->m02, this->m20);
    swap(this->m12, this->m21);

    return *this;
  }

  Matrix3& 
  Matrix3::inverse()
  {
    const float det = this->determinant();
    if (RelativelyEqual(det, 0.0f))
    {
      return *this;
    }    
    
    Matrix3 minors = this->getMinors();

    // Cofactors
    minors.m01 *= -1.0f;
    minors.m10 *= -1.0f;
    minors.m12 *= -1.0f;
    minors.m21 *= -1.0f;
    
    minors.transpose();

    // Inverse
    const float factor = 1.0f / det;
    this->m00 = minors.m00 * factor;
    this->m01 = minors.m01 * factor;
    this->m02 = minors.m02 * factor;
    this->m10 = minors.m10 * factor;
    this->m11 = minors.m11 * factor;
    this->m12 = minors.m12 * factor;
    this->m20 = minors.m20 * factor;
    this->m21 = minors.m21 * factor;
    this->m22 = minors.m22 * factor;

    return *this;
  }

  Matrix3& 
  Matrix3::identity()
  {
    this->m00 = 1.0f; this->m01 = 0.0f; this->m02 = 0.0f;
    this->m10 = 0.0f; this->m11 = 1.0f; this->m12 = 0.0f;
    this->m20 = 0.0f; this->m21 = 0.0f; this->m22 = 1.0f;

    return *this;
  }

  float 
  Matrix3::determinant() const
  {
    return this->m00* (this->m11* this->m22- this->m12* this->m21)
          -this->m01* (this->m10* this->m22- this->m20* this->m12)
          +this->m02* (this->m10* this->m21- this->m11* this->m20);
  }
}