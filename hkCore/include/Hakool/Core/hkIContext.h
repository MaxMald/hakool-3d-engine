#pragma once

#include <Hakool\Core\hkCorePrerequisites.h>

namespace hk
{
  /**
  * State associated to the Graphics API instance.
  */
  class IContext
  {
  public:

    /**
    * Constructor.
    */
    IContext() = default;

    /**
    * Destructor.
    */
    virtual ~IContext() = default;

    /**
    * Get the Graphics API context.
    */
    virtual void*
    get() = 0;
  };
}