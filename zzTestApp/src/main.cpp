#include <Hakool\Utils\hkVector2.h>
#include <Hakool\Utils\hkVector3.h>
#include <Hakool\Utils\hkVector4.h>

using std::cout;
using hk::Vector2f;
using hk::Vector3f;
using hk::Vector4f;
using hk::String;

void
printVec(const String label, Vector4f v)
{
  cout << label << ": ( x: " << v[0] << " , " << v[1] << " , " << v[2] << " , " << v[3] << " )" << std::endl;
  return;
}

void
printValue(const String label, const float v)
{
  cout << label << ": " << v << std::endl;
  return;
}

int 
main()
{  
  Vector4f vA(3.0f, 5.0f, 8.0f, 6.0f);
  Vector4f vB(1.0f, 18.0f, 7.0f, 2.0f);

  printVec("Vector A", vA);
  printVec("Vector B", vB);
  
  printVec("Sum", vA + vB);
  printVec("Subtract", vA - vB);
  printVec("Negate Vector A", -vA);
  printVec("Product", vA * vB);
  printVec("Scalar Vector A (5.0) ", vA * 5.0f);
  printVec("Scalar Vector A (5.0)(swap factors)", 5.0f * vA);
  printVec("Division", vA / vB);  
  printVec("Scalar Vector A (5.0)(division)", vA / 5.0f);  
  //printVec("Cross", vA ^ vB);
  printValue("Dot", vA | vB);
  printVec("Sum (Self)", vA += vB);
  printVec("Subtract (Self)", vA -= vB);
  printVec("Product (Self)", vA *= vB);
  printVec("Scalar Vector A (5.0)(Self) ", vA *= 5.0f);
  printVec("Division (Self)", vA /= vB);  
  printVec("Scalar Vector A (5.0)(division)", vA /= 5.0f);
  //printVec("Cross (Self)", vA ^= vB);

  return 0;
}