#include <Hakool\Utils\hkWindowFactoryWin32.h>
#include <Hakool\Utils\hkWindowWin32.h>

#if HK_PLATFORM == HK_PLATFORM_WIN32
namespace hk
{
  IWindow*
  WindowFactoryWin32::createHakoolWindow()
  {
    return new WindowWin32();
  }
}
#endif