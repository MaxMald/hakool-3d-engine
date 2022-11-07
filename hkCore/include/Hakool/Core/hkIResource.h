#pragma once

#include <Hakool\Core\hkCorePrerequisites.h>

namespace hk
{
  /**
  * TODO
  */
  class IResource
  {
  public:
    IResource() = default;
    virtual ~IResource() = default;

    /**
    * Safely destroys this resource.
    */
    virtual void
    destroy() = 0;

    IResource(const IResource&) = delete;
    IResource& operator= (const IResource&) = delete;
  };
}