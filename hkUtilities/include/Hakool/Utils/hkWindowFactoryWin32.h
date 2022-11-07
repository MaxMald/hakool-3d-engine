#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>
#include <Hakool\Utils\hkIWindowFactory.h>

#if HK_PLATFORM == HK_PLATFORM_WIN32
namespace hk
{
  class IWindow;

  /**
  * Creates specific windows for the Win32 platform.
  */
  class HK_UTILITY_EXPORT WindowFactoryWin32 : public IWindowFactory
  {
  public:

    /**
     * Creates a new window.
     *
     * @return A new Window.
     */
    virtual IWindow*
    createHakoolWindow();
  };
}
#endif