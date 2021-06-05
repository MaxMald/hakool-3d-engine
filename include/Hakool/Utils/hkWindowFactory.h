#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>

namespace hk
{
  class Window;

  /**
  * 
  */
  class HK_UTILITY_EXPORT WindowFactory
  {
  public:

    /**
    * 
    */
    static Window*
    GetWindow();
  };
}