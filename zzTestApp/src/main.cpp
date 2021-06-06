#include <Hakool\hakool.h>
#include <Hakool\Core\hkCoreUtilities.h>

#include <Hakool\Utils\hkColor.h>

#include <Hakool\Utils\hkMatrix3.h>
#include <Hakool\Utils\hkMatrix4.h>

#include <Hakool\Utils\hkVector4.h>
#include <Hakool\Utils\hkVector3.h>
#include <Hakool\Utils\hkVector2.h>

using hk::Hakool;
using hk::HakoolConfiguration;
using hk::eGRAPHIC_INTERFACE;
using hk::eRESULT;
using hk::Color;

using std::cout;
using std::cin;

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
  /***************************************************************************/
  /* ENGINE CONFIGURATION                                                    */
  /***************************************************************************/

  HakoolConfiguration engineConfig;
  
  // Window Configuration

  engineConfig.windowConfiguration.title = "Kalebio Window";
  engineConfig.windowConfiguration.width  = 1280;
  engineConfig.windowConfiguration.height = 720;

  // Graphics Configuration.

  engineConfig.graphicsConfiguration.graphicInterface = eGRAPHIC_INTERFACE::kOpenGL;
  engineConfig.graphicsConfiguration.backgroundColor = Color::GREEN;

  /***************************************************************************/
  /* APPLICATION                                                             */
  /***************************************************************************/


  Hakool::Start();  

  Hakool* pHakool = pHakool->GetEngine();  

  if (pHakool->init(engineConfig) == eRESULT::kSuccess)
  {
    pHakool->run();
  }

  Hakool::Shutdown();

  return 0;
}