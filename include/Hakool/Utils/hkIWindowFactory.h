#pragma once

namespace hk
{
  class IWindow;

  /**
  * Creates specific windows.
  */
  class IWindowFactory
  {
  public:

    virtual ~IWindowFactory() = default;

    /**
     * Creates a new window.
     * 
     * @return A new Window.
     */
    virtual IWindow*
    createHakoolWindow() = 0;
  };
}