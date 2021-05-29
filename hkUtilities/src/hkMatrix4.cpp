#include <Hakool\Utils\hkMatrix4.h>
#include <Hakool\Utils\hkUtilitiesUtilities.h>

using std::swap;

namespace hk
{
  Matrix4::Matrix4()
  {
    this->m00=0.0f;this->m01=0.0f;this->m02=0.0f;this->m03=0.0f;
    this->m10=0.0f;this->m11=0.0f;this->m12=0.0f;this->m13=0.0f;
    this->m20=0.0f;this->m21=0.0f;this->m22=0.0f;this->m23=0.0f;
    this->m30=0.0f;this->m31=0.0f;this->m32=0.0f;this->m33=0.0f;

    return;
  }

  Matrix4::Matrix4(const Matrix4& _mat4)
  {
    this->mRow[0] = _mat4.mRow[0];
    this->mRow[1] = _mat4.mRow[1];
    this->mRow[2] = _mat4.mRow[2];
    this->mRow[3] = _mat4.mRow[3];

    return;
  }

  Matrix4::Matrix4
  (
    const float& _m00, const float& _m01, const float& _m02, const float& _m03,
    const float& _m10, const float& _m11, const float& _m12, const float& _m13,
    const float& _m20, const float& _m21, const float& _m22, const float& _m23,
    const float& _m30, const float& _m31, const float& _m32, const float& _m33
  )
  {
    this->m00 = _m00; this->m01 = _m01; this->m02 = _m02; this->m03 = _m03;
    this->m10 = _m10; this->m11 = _m11; this->m12 = _m12; this->m13 = _m13;
    this->m20 = _m20; this->m21 = _m21; this->m22 = _m22; this->m23 = _m23;
    this->m30 = _m30; this->m31 = _m31; this->m32 = _m32; this->m33 = _m33;

    return;
  }

  Matrix4
  Matrix4::GetIdentity()
  {
    return Matrix4
    (
      1.0f, 0.0f, 0.0f, 0.0f,
      0.0f, 1.0f, 0.0f, 0.0f,
      0.0f, 0.0f, 1.0f, 0.0f,
      0.0f, 0.0f, 0.0f, 1.0f
    );
  }

  Matrix4 
  Matrix4::GetTranslation(const float& _x, const float& _y, const float& _z)
  {
    return Matrix4
    (
      1.0f, 0.0f, 0.0f, _x,
      0.0f, 1.0f, 0.0f, _y,
      0.0f, 0.0f, 1.0f, _z,
      0.0f, 0.0f, 0.0f, 1.0f
    );
  }

  Matrix4 
  Matrix4::GetScale(const float& _x, const float& _y, const float& _z)
  {
    return Matrix4
    (
      _x, 0.0f, 0.0f, 0.0f,
      0.0f, _y, 0.0f, 0.0f,
      0.0f, 0.0f, _z, 0.0f,
      0.0f, 0.0f, 0.0f, 1.0f
    );
  }

  Matrix4 
  Matrix4::GetRotation
  (
    const float& _theta, 
    const float& _x, 
    const float& _y, 
    const float& _z
  )
  {
    const float c = Math::Cos(_theta);
    const float s = Math::Sin(_theta);
    const float d = 1.0f - c;
    const float x = _x * d;
    const float y = _y * d;
    const float z = _z * d;
    const float vxvy = x * _y;
    const float vxvz = x * _z;
    const float vyvz = y * _z;

    return Matrix4
    (
      c + x * _x, vxvy - s * _z, vxvz + s * _y, 0.0f,
      vxvy + s * _z, c + y * _y, vyvz - s * _x, 0.0f,
      vxvz - s * _y, vyvz + s * _x, c + z * _z, 0.0f,
      0.0f, 0.0f, 0.0f, 1.0f
    );
  }

  Matrix4 
  Matrix4::GetRotation(const float& _theta, const Vector3<float>& _v3)
  {
    const float c = Math::Cos(_theta);
    const float s = Math::Sin(_theta);
    const float d = 1.0f - c;
    const float x = _v3.x * d;
    const float y = _v3.y * d;
    const float z = _v3.z * d;
    const float vxvy = x * _v3.y;
    const float vxvz = x * _v3.z;
    const float vyvz = y * _v3.z;

    return Matrix4
    (
      c + x * _v3.x, vxvy - s * _v3.z, vxvz + s * _v3.y, 0.0f,
      vxvy + s * _v3.z, c + y * _v3.y, vyvz - s * _v3.x, 0.0f,
      vxvz - s * _v3.y, vyvz + s * _v3.x, c + z * _v3.z, 0.0f,
      0.0f, 0.0f, 0.0f, 1.0f
    );
  }

  Matrix4 
  Matrix4::GetLookAt
  (
    const Vector3f& _from,
    const Vector3f& _to, 
    const Vector3f& _up
  )
  {
    // TODO
    return Matrix4();
  }

  Matrix4 
  Matrix4::GetRotationX(const float& _theta)
  {
    float c = Math::Cos(_theta);
    float s = Math::Sin(_theta);
    return Matrix4
    (
      1.0f, 0.0f, 0.0f, 0.0f,
      0.0f,    c,   -s, 0.0f,
      0.0f,    s,    c, 0.0f,
      0.0f, 0.0f, 0.0f, 1.0f
    );
  }

  Matrix4 
  Matrix4::GetRotationY(const float& _theta)
  {
    float c = Math::Cos(_theta);
    float s = Math::Sin(_theta);
    return Matrix4
    (
         c, 0.0f,   s, 0.0f,
      0.0f, 1.0f, 0.0, 0.0f,
        -s, 0.0f,   c, 0.0f,
      0.0f, 0.0f, 0.0f, 1.0f
    );
  }

  Matrix4 
  Matrix4::GetRotationZ(const float& _theta)
  {
    float c = Math::Cos(_theta);
    float s = Math::Sin(_theta);
    return Matrix4
    (
         c,   -s, 0.0f, 0.0f,
         s,    c, 0.0f, 0.0f,
      0.0f, 0.0f, 1.0f, 0.0f,
      0.0f, 0.0f, 0.0f, 1.0f
    );
  }

  Matrix4
  Matrix4::operator+(const Matrix4& _mat4) const
  {
    return Matrix4
    (
      this->m00+_mat4.m00, this->m01+_mat4.m01, this->m02+_mat4.m02, this->m03+_mat4.m03,
      this->m10+_mat4.m10, this->m11+_mat4.m11, this->m12+_mat4.m12, this->m13+_mat4.m13,
      this->m20+_mat4.m20, this->m21+_mat4.m21, this->m22+_mat4.m22, this->m23+_mat4.m23,
      this->m30+_mat4.m30, this->m31+_mat4.m31, this->m32+_mat4.m32, this->m33+_mat4.m33
    );
  }

  Matrix4
  Matrix4::operator-(const Matrix4& _mat4) const
  {
    return Matrix4
    (
      this->m00-_mat4.m00, this->m01-_mat4.m01, this->m02-_mat4.m02, this->m03-_mat4.m03,
      this->m10-_mat4.m10, this->m11-_mat4.m11, this->m12-_mat4.m12, this->m13-_mat4.m13,
      this->m20-_mat4.m20, this->m21-_mat4.m21, this->m22-_mat4.m22, this->m23-_mat4.m23,
      this->m30-_mat4.m30, this->m31-_mat4.m31, this->m32-_mat4.m32, this->m33-_mat4.m33
    );
  }

  Matrix4
  Matrix4::operator*(const Matrix4& _mat4) const
  {
    return Matrix4
    (
      this->m00*_mat4.m00+this->m01*_mat4.m10+this->m02*_mat4.m20+this->m03*_mat4.m30,
      this->m00*_mat4.m01+this->m01*_mat4.m11+this->m02*_mat4.m21+this->m03*_mat4.m31,
      this->m00*_mat4.m02+this->m01*_mat4.m12+this->m02*_mat4.m22+this->m03*_mat4.m32,
      this->m00*_mat4.m03+this->m01*_mat4.m13+this->m02*_mat4.m23+this->m03*_mat4.m33,
      this->m10*_mat4.m00+this->m11*_mat4.m10+this->m12*_mat4.m20+this->m13*_mat4.m30,
      this->m10*_mat4.m01+this->m11*_mat4.m11+this->m12*_mat4.m21+this->m13*_mat4.m31,
      this->m10*_mat4.m02+this->m11*_mat4.m12+this->m12*_mat4.m22+this->m13*_mat4.m32,
      this->m10*_mat4.m03+this->m11*_mat4.m13+this->m12*_mat4.m23+this->m13*_mat4.m33,
      this->m20*_mat4.m00+this->m21*_mat4.m10+this->m22*_mat4.m20+this->m23*_mat4.m30,
      this->m20*_mat4.m01+this->m21*_mat4.m11+this->m22*_mat4.m21+this->m23*_mat4.m31,
      this->m20*_mat4.m02+this->m21*_mat4.m12+this->m22*_mat4.m22+this->m23*_mat4.m32,
      this->m20*_mat4.m03+this->m21*_mat4.m13+this->m22*_mat4.m23+this->m23*_mat4.m33,
      this->m30*_mat4.m00+this->m31*_mat4.m10+this->m32*_mat4.m20+this->m33*_mat4.m30,
      this->m30*_mat4.m01+this->m31*_mat4.m11+this->m32*_mat4.m21+this->m33*_mat4.m31,
      this->m30*_mat4.m02+this->m31*_mat4.m12+this->m32*_mat4.m22+this->m33*_mat4.m32,
      this->m30*_mat4.m03+this->m31*_mat4.m13+this->m32*_mat4.m23+this->m33*_mat4.m33
    );
  }

  Matrix4&
  Matrix4::operator=(const Matrix4& _mat4)
  {
    this->m00=_mat4.m00;this->m01=_mat4.m01;this->m02=_mat4.m02;this->m03=_mat4.m03;
    this->m10=_mat4.m10;this->m11=_mat4.m11;this->m12=_mat4.m12;this->m13=_mat4.m13;
    this->m20=_mat4.m20;this->m21=_mat4.m21;this->m22=_mat4.m22;this->m23=_mat4.m23;
    this->m30=_mat4.m30;this->m31=_mat4.m31;this->m32=_mat4.m32;this->m33=_mat4.m33;

    return *this;
  }

  Matrix4&
  Matrix4::operator=(const float& _value)
  {
    this->m00 = _value; this->m01 = _value; this->m02 = _value; this->m03 = _value;
    this->m10 = _value; this->m11 = _value; this->m12 = _value; this->m13 = _value;
    this->m20 = _value; this->m21 = _value; this->m22 = _value; this->m23 = _value;
    this->m30 = _value; this->m31 = _value; this->m32 = _value; this->m33 = _value;

    return *this;
  }

  Matrix4&
  Matrix4::operator+=(const Matrix4& _mat4)
  {
    this->m00+=_mat4.m00;this->m01+=_mat4.m01;this->m02+=_mat4.m02;this->m03+=_mat4.m03;
    this->m10+=_mat4.m10;this->m11+=_mat4.m11;this->m12+=_mat4.m12;this->m13+=_mat4.m13;
    this->m20+=_mat4.m20;this->m21+=_mat4.m21;this->m22+=_mat4.m22;this->m23+=_mat4.m23;
    this->m30+=_mat4.m30;this->m31+=_mat4.m31;this->m32+=_mat4.m32;this->m33+=_mat4.m33;

    return *this;
  }

  Matrix4&
  Matrix4::operator-=(const Matrix4& _mat4)
  {
    this->m00-=_mat4.m00;this->m01-=_mat4.m01;this->m02-=_mat4.m02;this->m03-=_mat4.m03;
    this->m10-=_mat4.m10;this->m11-=_mat4.m11;this->m12-=_mat4.m12;this->m13-=_mat4.m13;
    this->m20-=_mat4.m20;this->m21-=_mat4.m21;this->m22-=_mat4.m22;this->m23-=_mat4.m23;
    this->m30-=_mat4.m30;this->m31-=_mat4.m31;this->m32-=_mat4.m32;this->m33-=_mat4.m33;

    return *this;
  }

  Matrix4&
  Matrix4::operator*=(const Matrix4& _mat4)
  {
    Matrix4 copy(*this);

    this->m00=copy.m00*_mat4.m00+copy.m01*_mat4.m10+copy.m02*_mat4.m20+copy.m03*_mat4.m30;
    this->m01=copy.m00*_mat4.m01+copy.m01*_mat4.m11+copy.m02*_mat4.m21+copy.m03*_mat4.m31;
    this->m02=copy.m00*_mat4.m02+copy.m01*_mat4.m12+copy.m02*_mat4.m22+copy.m03*_mat4.m32;
    this->m03=copy.m00*_mat4.m03+copy.m01*_mat4.m13+copy.m02*_mat4.m23+copy.m03*_mat4.m33;
    this->m10=copy.m10*_mat4.m00+copy.m11*_mat4.m10+copy.m12*_mat4.m20+copy.m13*_mat4.m30;
    this->m11=copy.m10*_mat4.m01+copy.m11*_mat4.m11+copy.m12*_mat4.m21+copy.m13*_mat4.m31;
    this->m12=copy.m10*_mat4.m02+copy.m11*_mat4.m12+copy.m12*_mat4.m22+copy.m13*_mat4.m32;
    this->m13=copy.m10*_mat4.m03+copy.m11*_mat4.m13+copy.m12*_mat4.m23+copy.m13*_mat4.m33;
    this->m20=copy.m20*_mat4.m00+copy.m21*_mat4.m10+copy.m22*_mat4.m20+copy.m23*_mat4.m30;
    this->m21=copy.m20*_mat4.m01+copy.m21*_mat4.m11+copy.m22*_mat4.m21+copy.m23*_mat4.m31;
    this->m22=copy.m20*_mat4.m02+copy.m21*_mat4.m12+copy.m22*_mat4.m22+copy.m23*_mat4.m32;
    this->m23=copy.m20*_mat4.m03+copy.m21*_mat4.m13+copy.m22*_mat4.m23+copy.m23*_mat4.m33;
    this->m30=copy.m30*_mat4.m00+copy.m31*_mat4.m10+copy.m32*_mat4.m20+copy.m33*_mat4.m30;
    this->m31=copy.m30*_mat4.m01+copy.m31*_mat4.m11+copy.m32*_mat4.m21+copy.m33*_mat4.m31;
    this->m32=copy.m30*_mat4.m02+copy.m31*_mat4.m12+copy.m32*_mat4.m22+copy.m33*_mat4.m32;
    this->m33=copy.m30*_mat4.m03+copy.m31*_mat4.m13+copy.m32*_mat4.m23+copy.m33*_mat4.m33;

    return *this;
  }

  Matrix4
  Matrix4::getTranspose() const
  {
    return Matrix4
    (
      this->m00, this->m10, this->m20, this->m30,
      this->m01, this->m11, this->m21, this->m31,
      this->m02, this->m12, this->m22, this->m32,
      this->m03, this->m12, this->m23, this->m33
    );
  }

  Matrix4
  Matrix4::getInverse() const
  {
    const float det = this->determinant();
    if (RelativelyEqual(det, 0.0f))
    {
      return Matrix4();
    }

    Matrix4 minors = this->getMinors();
    minors.m01 *= -1.0f;
    minors.m03 *= -1.0f;
    minors.m10 *= -1.0f;
    minors.m12 *= -1.0f;
    minors.m21 *= -1.0f;
    minors.m23 *= -1.0f;
    minors.m30 *= -1.0f;
    minors.m32 *= -1.0f;

    minors.transpose();

    const float factor = 1.0f / det;
    return Matrix4
    (
      minors.m00*factor,minors.m01*factor,minors.m02*factor,minors.m03*factor,
      minors.m10*factor,minors.m11*factor,minors.m12*factor,minors.m13*factor,
      minors.m20*factor,minors.m21*factor,minors.m22*factor,minors.m23*factor,
      minors.m30*factor,minors.m31*factor,minors.m32*factor,minors.m33*factor
    );
  }

  Matrix4
  Matrix4::getMinors() const
  {
    return Matrix4
    (
      this->m11 * (this->m22 * this->m33 - this->m32 * this->m23)
      - this->m12 * (this->m21 * this->m33 - this->m31 * this->m23)
      + this->m13 * (this->m21 * this->m32 - this->m31 * this->m22),
      this->m10 * (this->m22 * this->m33 - this->m32 * this->m23)
      - this->m12 * (this->m20 * this->m33 - this->m30 * this->m23)
      + this->m13 * (this->m20 * this->m32 - this->m30 * this->m22),
      this->m10 * (this->m21 * this->m33 - this->m31 * this->m23)
      - this->m11 * (this->m20 * this->m33 - this->m30 * this->m23)
      + this->m13 * (this->m20 * this->m31 - this->m30 * this->m21),
      this->m10 * (this->m21 * this->m32 - this->m31 * this->m22)
      - this->m11 * (this->m20 * this->m32 - this->m30 * this->m22)
      + this->m12 * (this->m20 * this->m31 - this->m30 * this->m21),
      this->m01 * (this->m22 * this->m33 - this->m32 * this->m23)
      - this->m02 * (this->m21 * this->m33 - this->m31 * this->m23)
      + this->m03 * (this->m21 * this->m32 - this->m31 * this->m22),
      this->m00 * (this->m22 * this->m33 - this->m32 * this->m23)
      - this->m02 * (this->m20 * this->m33 - this->m30 * this->m23)
      + this->m03 * (this->m20 * this->m32 - this->m30 * this->m22),
      this->m00 * (this->m21 * this->m33 - this->m31 * this->m23)
      - this->m01 * (this->m20 * this->m33 - this->m30 * this->m23)
      + this->m03 * (this->m20 * this->m31 - this->m30 * this->m21),
      this->m00 * (this->m21 * this->m32 - this->m31 * this->m22)
      - this->m01 * (this->m20 * this->m32 - this->m30 * this->m22)
      + this->m02 * (this->m20 * this->m31 - this->m30 * this->m21),
      this->m01 * (this->m12 * this->m33 - this->m32 * this->m13)
      - this->m02 * (this->m11 * this->m33 - this->m31 * this->m13)
      + this->m03 * (this->m11 * this->m32 - this->m31 * this->m12),
      this->m00 * (this->m12 * this->m33 - this->m32 * this->m13)
      - this->m02 * (this->m10 * this->m33 - this->m30 * this->m13)
      + this->m03 * (this->m10 * this->m32 - this->m30 * this->m12),
      this->m00 * (this->m11 * this->m33 - this->m31 * this->m13)
      - this->m01 * (this->m10 * this->m33 - this->m30 * this->m13)
      + this->m03 * (this->m10 * this->m31 - this->m30 * this->m11),
      this->m00 * (this->m11 * this->m32 - this->m31 * this->m12)
      - this->m01 * (this->m10 * this->m32 - this->m30 * this->m12)
      + this->m02 * (this->m10 * this->m31 - this->m30 * this->m11),
      this->m01 * (this->m12 * this->m23 - this->m22 * this->m13)
      - this->m02 * (this->m11 * this->m23 - this->m21 * this->m13)
      + this->m03 * (this->m11 * this->m22 - this->m21 * this->m12),
      this->m00 * (this->m12 * this->m23 - this->m22 * this->m13)
      - this->m02 * (this->m10 * this->m23 - this->m20 * this->m13)
      + this->m03 * (this->m10 * this->m22 - this->m20 * this->m12),
      this->m00 * (this->m11 * this->m23 - this->m21 * this->m13)
      - this->m01 * (this->m10 * this->m23 - this->m20 * this->m13)
      + this->m03 * (this->m10 * this->m21 - this->m20 * this->m11),
      this->m00 * (this->m11 * this->m22 - this->m21 * this->m12)
      - this->m01 * (this->m10 * this->m22 - this->m20 * this->m12)
      + this->m02 * (this->m10 * this->m21 - this->m20 * this->m11)
    );
  }

  Matrix4&
  Matrix4::transpose()
  {
    swap(this->m01, this->m10);
    swap(this->m02, this->m20);
    swap(this->m03, this->m30);
    swap(this->m12, this->m21);
    swap(this->m13, this->m31);
    swap(this->m23, this->m32);

    return *this;
  }

  Matrix4&
  Matrix4::inverse()
  {
    const float det = this->determinant();
    if (RelativelyEqual(det, 0.0f))
    {
      return *this;
    }

    Matrix4 minors = this->getMinors();
    minors.m01 *= -1.0f;
    minors.m03 *= -1.0f;
    minors.m10 *= -1.0f;
    minors.m12 *= -1.0f;
    minors.m21 *= -1.0f;
    minors.m23 *= -1.0f;
    minors.m30 *= -1.0f;
    minors.m32 *= -1.0f;

    minors.transpose();

    const float factor = 1.0f / det;
    this->m00 = minors.m00 * factor;
    this->m01 = minors.m01 * factor;
    this->m02 = minors.m02 * factor;
    this->m03 = minors.m03 * factor;
    this->m10 = minors.m10 * factor;
    this->m11 = minors.m11 * factor;
    this->m12 = minors.m12 * factor;
    this->m13 = minors.m13 * factor;
    this->m20 = minors.m20 * factor;
    this->m21 = minors.m21 * factor;
    this->m22 = minors.m22 * factor;
    this->m23 = minors.m23 * factor;
    this->m30 = minors.m30 * factor;
    this->m31 = minors.m31 * factor;
    this->m32 = minors.m32 * factor;
    this->m33 = minors.m33 * factor;

    return *this;
  }

  Matrix4& 
  Matrix4::setTransalation(const float& _x, const float& _y, const float& _z)
  {
    this->m00 = 1.0f; this->m01 = 0.0f; this->m02 = 0.0f; this->m03 = _x;
    this->m10 = 0.0f; this->m11 = 1.0f; this->m12 = 0.0f; this->m13 = _y;
    this->m20 = 0.0f; this->m21 = 0.0f; this->m22 = 1.0f; this->m23 = _z;
    this->m30 = 0.0f; this->m31 = 0.0f; this->m32 = 0.0f; this->m33 = 1.0f;

    return *this;
  }

  Matrix4& 
  Matrix4::setScale(const float& _x, const float& _y, const float& _z)
  {
    this->m00 = _x; this->m01 = 0.0f; this->m02 = 0.0f; this->m03 = 0.0f;
    this->m10 = 0.0f; this->m11 = _y; this->m12 = 0.0f; this->m13 = 0.0f;
    this->m20 = 0.0f; this->m21 = 0.0f; this->m22 = _z; this->m23 = 0.0f;
    this->m30 = 0.0f; this->m31 = 0.0f; this->m32 = 0.0f; this->m33 = 1.0f;

    return *this;
  }

  Matrix4& 
    Matrix4::setLookAt
  (
    const Vector3f& _from, 
    const Vector3f& _to, 
    const Vector3f& _up
  )
  {

    return *this;
  }

  Matrix4& 
  Matrix4::setRotation
  (
    const float& _theta, 
    const float& _x, 
    const float& _y, 
    const float& _z
  )
  {
    const float c = Math::Cos(_theta);
    const float s = Math::Sin(_theta);
    const float d = 1.0f - c;
    const float x = _x * d;
    const float y = _y * d;
    const float z = _z * d;
    const float vxvy = x * _y;
    const float vxvz = x * _z;
    const float vyvz = y * _z;

    this->m00 = c + x * _x; this->m01 = vxvy - s * _z; this->m02 = vxvz + s * _y; 
    this->m03 = 0.0f;
    this->m10 = vxvy + s * _z; this->m11 = c + y * _y; this->m12 = vyvz - s * _x; 
    this->m13 = 0.0f;
    this->m20 = vxvz - s * _y; this->m21 = vyvz + s * _x; this->m22 = c + z * _z; 
    this->m23 = 0.0f;
    this->m30 = 0.0f; this->m31 = 0.0f; this->m32 = 0.0f; this->m33 = 1.0f;

    return *this;
  }

  Matrix4& 
  Matrix4::setRotation(const float& _theta, const Vector3<float>& _v3)
  {
    const float c = Math::Cos(_theta);
    const float s = Math::Sin(_theta);
    const float d = 1.0f - c;
    const float x = _v3.x * d;
    const float y = _v3.y * d;
    const float z = _v3.z * d;
    const float vxvy = x * _v3.y;
    const float vxvz = x * _v3.z;
    const float vyvz = y * _v3.z;

    this->m00 = c + x * _v3.x; this->m01 = vxvy - s * _v3.z; 
    this->m02 = vxvz + s * _v3.y; this->m03 = 0.0f;
    this->m10 = vxvy + s * _v3.z; this->m11 = c + y * _v3.y; 
    this->m12 = vyvz - s * _v3.x; this->m13 = 0.0f;
    this->m20 = vxvz - s * _v3.y; this->m21 = vyvz + s * _v3.x; 
    this->m22 = c + z * _v3.z; this->m23 = 0.0f;
    this->m30 = 0.0f; this->m31 = 0.0f; this->m32 = 0.0f; this->m33 = 1.0f;

    return *this;
  }

  Matrix4&
  Matrix4::setRotationX(const float& _theta)
  {
    float c = Math::Cos(_theta);
    float s = Math::Sin(_theta);

    this->m00 = 1.0f; this->m01 = 0.0f; this->m02 = 0.0f; this->m03 = 0.0f;
    this->m10 = 0.0f; this->m11 =    c; this->m12 =   -s; this->m13 = 0.0f;
    this->m20 = 0.0f; this->m21 =    s; this->m22 =    c; this->m23 = 0.0f;
    this->m30 = 0.0f; this->m31 = 0.0f; this->m32 = 0.0f; this->m33 = 1.0f;

    return *this;
  }

  Matrix4& 
  Matrix4::setRotationY(const float& _theta)
  {
    float c = Math::Cos(_theta);
    float s = Math::Sin(_theta);

    this->m00 =    c; this->m01 = 0.0f; this->m02 =    s; this->m03 = 0.0f;
    this->m10 = 0.0f; this->m11 = 1.0f; this->m12 = 0.0f; this->m13 = 0.0f;
    this->m20 =   -s; this->m21 = 0.0f; this->m22 =    c; this->m23 = 0.0f;
    this->m30 = 0.0f; this->m31 = 0.0f; this->m32 = 0.0f; this->m33 = 1.0f;

    return *this;
  }

  Matrix4& 
  Matrix4::setRotationZ(const float& _theta)
  {
    float c = Math::Cos(_theta);
    float s = Math::Sin(_theta);

    this->m00 =    c; this->m01 =   -s; this->m02 = 0.0f; this->m03 = 0.0f;
    this->m10 =    s; this->m11 =    c; this->m12 = 0.0f; this->m13 = 0.0f;
    this->m20 = 0.0f; this->m21 = 0.0f; this->m22 = 1.0f; this->m23 = 0.0f;
    this->m30 = 0.0f; this->m31 = 0.0f; this->m32 = 0.0f; this->m33 = 1.0f;

    return *this;
  }

  Matrix4&
  Matrix4::identity()
  {
    this->m00 = 1.0f; this->m01 = 0.0f; this->m02 = 0.0f; this->m03 = 0.0f;
    this->m10 = 0.0f; this->m11 = 1.0f; this->m12 = 0.0f; this->m13 = 0.0f;
    this->m20 = 0.0f; this->m21 = 0.0f; this->m22 = 1.0f; this->m23 = 0.0f;
    this->m30 = 0.0f; this->m31 = 0.0f; this->m32 = 0.0f; this->m33 = 1.0f;

    return *this;
  }

  float
  Matrix4::determinant() const
  {
    return this->m00 * ( this->m11 * (this->m22 * this->m33 - this->m32 * this->m23)
                        -this->m12 * (this->m21 * this->m33 - this->m31 * this->m23)
                        +this->m13 * (this->m21 * this->m32 - this->m31 * this->m22))
          -this->m01 * ( this->m10 * (this->m22 * this->m33 - this->m32 * this->m23)
                        -this->m12 * (this->m20 * this->m33 - this->m30 * this->m23)
                        +this->m13 * (this->m20 * this->m32 - this->m30 * this->m22))
          +this->m02 * ( this->m10 * (this->m21 * this->m33 - this->m31 * this->m23)
                        -this->m11 * (this->m20 * this->m33 - this->m30 * this->m23)
                        +this->m13 * (this->m20 * this->m31 - this->m30 * this->m21))
          -this->m03 * ( this->m10 * (this->m21 * this->m32 - this->m31 * this->m22)
                        -this->m11 * (this->m20 * this->m32 - this->m30 * this->m22)
                        +this->m12 * (this->m20 * this->m31 - this->m30 * this->m21));
  }
}