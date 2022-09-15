#pragma once

namespace hk
{
  class Window;

  /**
  * Creates specific windows.
  */
  class IWindowFactory
  {
  public:

    /**
     * Creates a new window.
     * 
     * @return A new Window.
     */
    virtual Window*
    createHakoolWindow() = 0;
  };
}