#include <Hakool\Utils\hkMatrix3.h>
#include <Hakool\Utils\hkMatrix4.h>

#include <Hakool\Utils\hkVector4.h>
#include <Hakool\Utils\hkVector3.h>
#include <Hakool\Utils\hkVector2.h>

using std::cout;
using hk::Matrix3;
using hk::Matrix4;
using hk::Vector2f;
using hk::Vector3f;
using hk::Vector4f;
using hk::String;
using hk::Math;

void
printMatrix4(const String& _label, Matrix4 _mat)
{
  cout << _label << std::endl << "___________________________" << std::endl;
  cout << _mat.m[0][0] << " | " << _mat.m[0][1] << " | " << _mat.m[0][2] << " | " << _mat.m[0][3] << std::endl;
  cout << _mat.m[1][0] << " | " << _mat.m[1][1] << " | " << _mat.m[1][2] << " | " << _mat.m[1][3] << std::endl;
  cout << _mat.m[2][0] << " | " << _mat.m[2][1] << " | " << _mat.m[2][2] << " | " << _mat.m[2][3] << std::endl;
  cout << _mat.m[3][0] << " | " << _mat.m[3][1] << " | " << _mat.m[3][2] << " | " << _mat.m[3][3] << std::endl;
  cout << "___________________________" << std::endl;
}

void
printVector4(const String& _label, Vector4f _v)
{
  cout << _label << " v4: ( " << _v.x << " , " << _v.y << " , " << _v.z << " , " << _v.w << " ) " << std::endl;
  return;
}

void
printVector3(const String& _label, Vector3f _v)
{
  cout << _label << " v3: ( " << _v.x << " , " << _v.y << " , " << _v.z << " ) " << std::endl;
  return;
}

void
printVector2(const String& _label, Vector2f _v)
{
  cout << _label << " v2: ( " << _v.x << " , " << _v.y << " ) " << std::endl;
  return;
}

void
printValue(const String& _label, float _v)
{
  cout << _label << " : " << _v << std::endl;
  return;
}

int 
main()
{
 

  Vector4f vecA(3.0f, 10.0f, 2.0f, 4.0f);
  Vector4f vecB(1.0f, 5.0f, 17.0f, 8.0f);

  Vector3f vec3A(5.0f, 2.0f, 3.0f);
  printMatrix4("Rotation", Matrix4::GetRotation(0.5, vec3A.getNormalize()));

  //printMatrix4("Translation", Matrix4::GetTranslation(1.5f, 6.0f, 3.0f));
  //printMatrix4("Scale", Matrix4::GetScale(8.0f, 5.0f, 1.0f));
  //printMatrix4("Rotation X", Matrix4::GetRotationX(Math::PI));
  //printMatrix4("Rotation Y", Matrix4::GetRotationY(Math::PI));
  //printMatrix4("Rotation Z", Matrix4::GetRotationZ(Math::PI));

  //printVector4("Vector", vecA);
  //printVector4("Vector", vecB);
  //printVector4("Sum : ", vecA + vecB);
  //printVector4("Sub : ", vecA - vecB);
  //printVector4("Pro : ", vecA * vecB);
  //printVector4("Div : ", vecA / vecB);
  //printVector4("Cross : ", vecA % vecB);
  //printVector4("Normalize: ", vecA.getNormalize());
  //printValue("Magnitude: ", vecA.magnitude());
  //printVector4("Set Magnitude ", vecA.setMagnitude(100.0f));
  //printValue("Magnitude ", vecA.magnitude());
  //printVector4("Cross : ", vecA %= vecB);
  //printVector4("Sum (self): ", vecA += vecB);
  //printVector4("Sub (self): ", vecA -= vecB);
  //printVector4("Pro (self): ", vecA *= vecB);
  //printVector4("Div (self): ", vecA /= vecB);
  //printValue("Dot: ", vecA | vecB);

  //Vector3f v3A(2.0f, 9.0f, 4.0f);
  //Vector3f v3B(9.0f, 7.0f, 1.0f);
  //printVector3("Vector A", v3A);
  //printVector3("Vector B", v3B);
 //printVector3("Proj", v3A ^ v3B);
  //printVector3("Proj (self)", v3A ^= v3B);
  //printVector3("Norm", v3A.normalize());
  //printVector3("Norm", v3B.normalize());

  //Vector2f v2A(2.0f, 9.0f);
  //Vector2f v2B(9.0f, 7.0f);
  //printVector2("Vector A", v2A);
  //printVector2("Vector B", v2B);
  //printVector2("Proj", v2A ^ v2B);
  //printVector2("Proj (self)", v2A ^= v2B);
  //printVector2("Norm", v2A.normalize());
  //printVector2("Norm", v2B.normalize());



  return 0;
}