#pragma once

#include "hkUtilsPrerequisites.h"

namespace hk
{
  class Window;

  /**
   * Provides a base interface to listen Window's events.
   */
  class WindowObserver
  {
  public:

    /**
     * Called when the window's size has changed.
     * 
     * @param window Reference to the window which size has changed.
     */
    virtual void
    onWindowSizeChanged(Window& window) const = 0;
  };
}