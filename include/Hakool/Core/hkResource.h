#pragma once

#include <Hakool\Core\hkCorePrerequisites.h>

namespace hk
{
  /**
  * TODO
  */
  class HK_CORE_EXPORT Resource
  {
  public:

    /**
    * Constructor.
    */
    Resource();

    /**
    * Destructor.
    */
    virtual ~Resource();

    /**
    * Safely destroys this resource.
    */
    virtual void
    destroy();
  };
}