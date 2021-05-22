#include <Hakool\Utils\hkMatrix3.h>
#include <Hakool\Utils\hkMatrix4.h>

#include <Hakool\Utils\hkVector4.h>
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
printMatrix(const String& _label, Matrix4 _mat)
{
  cout << _label << std::endl << "___________________________" << std::endl;
  cout << _mat.m[0][0] << " | " << _mat.m[0][1] << " | " << _mat.m[0][2] << " | " << _mat.m[0][3] << std::endl;
  cout << _mat.m[1][0] << " | " << _mat.m[1][1] << " | " << _mat.m[1][2] << " | " << _mat.m[1][3] << std::endl;
  cout << _mat.m[2][0] << " | " << _mat.m[2][1] << " | " << _mat.m[2][2] << " | " << _mat.m[2][3] << std::endl;
  cout << _mat.m[3][0] << " | " << _mat.m[3][1] << " | " << _mat.m[3][2] << " | " << _mat.m[3][3] << std::endl;
  cout << "___________________________" << std::endl;
}

void
printVector(const String& _label, Vector4f _v)
{
  cout << _label << " v: ( " << _v.x << " , " << _v.y << " , " << _v.z << " , " << _v.w << " ) " << std::endl;
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

  printMatrix("Translation", Matrix4::GetTranslation(1.5f, 6.0f, 3.0f));
  printMatrix("Scale", Matrix4::GetScale(8.0f, 5.0f, 1.0f));
  printMatrix("Rotation X", Matrix4::GetRotationX(Math::PI));
  printMatrix("Rotation Y", Matrix4::GetRotationY(Math::PI));
  printMatrix("Rotation Z", Matrix4::GetRotationZ(Math::PI));

  printVector("Vector", vecA);
  printVector("Vector", vecB);
  printVector("Sum : ", vecA + vecB);
  printVector("Sub : ", vecA - vecB);
  printVector("Pro : ", vecA * vecB);
  printVector("Div : ", vecA / vecB);
  //printVector("Cross : ", vecA ^ vecB);
  printVector("Normalize: ", vecA.getNormalize());
  printValue("Magnitude: ", vecA.magnitude());
  printVector("Set Magnitude ", vecA.setMagnitude(100.0f));
  printValue("Magnitude ", vecA.magnitude());
  //printVector("Cross : ", vecA ^= vecB);
  //printVector("Sum (self): ", vecA += vecB);
  //printVector("Sub (self): ", vecA -= vecB);
  printVector("Pro (self): ", vecA *= vecB);
  printVector("Div (self): ", vecA /= vecB);
  printValue("Dot: ", vecA | vecB);

  return 0;
}