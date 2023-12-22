#pragma once
#include "hkConfigTypes.h"

namespace hk
{  
  /**
   * An IInputManager instance is responsible for handling all input events and
   * providing a simple interface to query the current state of the input
   * devices.
   */
  class IInputManager
  {
  public:
    virtual ~IInputManager() {}

    virtual void update() = 0;

    virtual bool isKeyDown(uint32 key) const = 0;
    virtual bool isKeyUp(uint32 key) const = 0;
    virtual bool isKeyPressed(uint32 key) const = 0;
    virtual bool isKeyReleased(uint32 key) const = 0;

    virtual bool isMouseButtonDown(uint32 button) const = 0;
    virtual bool isMouseButtonUp(uint32 button) const = 0;
    virtual bool isMouseButtonPressed(uint32 button) const = 0;
    virtual bool isMouseButtonReleased(uint32 button) const = 0;

    virtual uint32 getMouseX() const = 0;
    virtual uint32 getMouseY() const = 0;
    virtual uint32 getMouseWheel() const = 0;

    virtual void setMousePosition(uint32 x, uint32 y) = 0;
    virtual void setMouseWheel(uint32 wheel) = 0;

    virtual void setMouseCursorVisible(bool visible) = 0;
    virtual bool isMouseCursorVisible() const = 0;

    virtual void setMouseCursorLocked(bool locked) = 0;
    virtual bool isMouseCursorLocked() const = 0;

    virtual void setMouseCursorGrabbed(bool grabbed) = 0;
    virtual bool isMouseCursorGrabbed() const = 0;

    virtual void setMouseCursor(const char* filename) = 0;
  };
}