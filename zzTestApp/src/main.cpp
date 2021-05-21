#include <Hakool\Utils\hkMatrix3.h>

using std::cout;
using hk::Matrix3;
using hk::Vector3f;
using hk::String;

void
printMatrix(const String& _label, Matrix3 _mat)
{
  cout << _label << std::endl << "___________________________" << std::endl;
  cout << _mat.m[0][0] << " | " << _mat.m[0][1] << " | " << _mat.m[0][2] << std::endl;
  cout << _mat.m[1][0] << " | " << _mat.m[1][1] << " | " << _mat.m[1][2] << std::endl;
  cout << _mat.m[2][0] << " | " << _mat.m[2][1] << " | " << _mat.m[2][2] << std::endl;
  cout << "___________________________" << std::endl;
}

void
printVector(const String& _label, Vector3f _v)
{
  cout << _label << " ( " << _v.x << " , " << _v.y << " , " << _v.z << " ) " << std::endl;
  return;
}

int 
main()
{    
  Matrix3 matA
  (
    5.0f, 2.0f, 2.0f,
    9.0f, 4.0f, 3.0f,
    3.0f, 7.0f, 5.0f
  );
  Matrix3 matB
  (
    2.0f, 1.0f, 0.0f,
    7.0f, 2.0f, 6.0f,
    1.0f, 8.0f, 8.0f
  );

  Vector3f vec4(3.0f, 10.0f, 1.0f);

  printMatrix("Matrix A", matA);
  printMatrix("Matrix B", matB);
  //printMatrix("Sum", matA + matB);
  //printMatrix("Sub", matA - matB);
  //printMatrix("Product", matA * matB);
  //printVector("Product Vector", matA * vec4);
  //printMatrix("Equal", matA = matB);
  //printMatrix("Equal to Scalar", matA = 5.0f);
  //printMatrix("Sum (Self)", matA += matB);
  //printMatrix("Sub (Self)", matA -= matB);
  //printMatrix("Product (Self)", matA *= matB);
  //printMatrix("Inverse (Self)", matA.inverse());
  //printMatrix("Minors", matA.getMinors());
  //printMatrix("Inverse", matA.getInverse());
  printMatrix("Identity", matA.identity());
  printMatrix("Identity", Matrix3::GetIdentity());

  return 0;
}