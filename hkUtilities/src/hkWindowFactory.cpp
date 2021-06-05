#include <Hakool\Utils\hkWindowFactory.h>

#if HK_PLATFORM == HK_PLATFORM_WIN32
#include <Hakool\Utils\hkWindowWin32.h>
#endif

namespace hk
{
#if HK_PLATFORM == HK_PLATFORM_WIN32
  Window* 
  WindowFactory::GetWindow()
  {
    return new WindowWin32();
  }
#endif
}