#pragma once

#include "Hakool/Utils/hkUtilsPrerequisites.h"
#include "Hakool/Utils/hkIInputManager.h"
#include "Hakool/Utils/hkKey.h"

namespace hk
{
  class InputManagerWin32 : IInputManager
  {
  public:

    InputManagerWin32();
    virtual ~InputManagerWin32();

    virtual void update() override;

    virtual bool isKeyDown(uint32 key) const override;
    virtual bool isKeyUp(uint32 key) const override;
    virtual bool isKeyPressed(uint32 key) const override;
    virtual bool isKeyReleased(uint32 key) const override;

    virtual bool isMouseButtonDown(uint32 button) const override;
    virtual bool isMouseButtonUp(uint32 button) const override;
    virtual bool isMouseButtonPressed(uint32 button) const override;
    virtual bool isMouseButtonReleased(uint32 button) const override;

    virtual uint32 getMouseX() const override;
    virtual uint32 getMouseY() const override;
    virtual uint32 getMouseWheel() const override;

    virtual void setMousePosition(uint32 x, uint32 y) override;
    virtual void setMouseWheel(uint32 wheel) override;

    virtual void setMouseCursorVisible(bool visible) override;
    virtual bool isMouseCursorVisible() const override;

    virtual void setMouseCursorLocked(bool locked) override;
    virtual bool isMouseCursorLocked() const override;

    virtual void setMouseCursorGrabbed(bool grabbed) override;
    virtual bool isMouseCursorGrabbed() const override;

    virtual void setMouseCursor(const char* filename) override;

  private:

    /**
     * Gets a Key value and returns its virtual key code.
     * 
     * @returns The virtual key code of the given key.
     */
    int32 
      keyToVirtualKeyCode(Key key) const;
  };
}