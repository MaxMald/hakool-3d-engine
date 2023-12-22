#include "Hakool/Utils/hkInputManagerWin32.h"

#include <WinUser.h>

namespace hk
{
  InputManagerWin32::InputManagerWin32()
  { }

  InputManagerWin32::~InputManagerWin32()
  { }

  void 
    InputManagerWin32::update()
  {
  }

  bool 
    InputManagerWin32::isKeyDown(uint32 key) const
  {
    return GetKeyState(keyToVirtualKeyCode((Key)key)) && 0x8000;
  }

  bool 
    InputManagerWin32::isKeyUp(uint32 key) const
  {
    return false;
  }

  bool 
    InputManagerWin32::isKeyPressed(uint32 key) const
  {
    return false;
  }

  bool 
    InputManagerWin32::isKeyReleased(uint32 key) const
  {
    return false;
  }

  bool 
    InputManagerWin32::isMouseButtonDown(uint32 button) const
  {
    return false;
  }

  bool 
    InputManagerWin32::isMouseButtonUp(uint32 button) const
  {
    return false;
  }

  bool 
    InputManagerWin32::isMouseButtonPressed(uint32 button) const
  {
    return false;
  }

  bool 
    InputManagerWin32::isMouseButtonReleased(uint32 button) const
  {
    return false;
  }

  uint32 
    InputManagerWin32::getMouseX() const
  {
    return uint32();
  }

  uint32 
    InputManagerWin32::getMouseY() const
  {
    return uint32();
  }

  uint32 
    InputManagerWin32::getMouseWheel() const
  {
    return uint32();
  }

  void 
    InputManagerWin32::setMousePosition(uint32 x, uint32 y)
  {
  }

  void 
    InputManagerWin32::setMouseWheel(uint32 wheel)
  {
  }

  void 
    InputManagerWin32::setMouseCursorVisible(bool visible)
  {
  }

  bool 
    InputManagerWin32::isMouseCursorVisible() const
  {
    return false;
  }

  void 
    InputManagerWin32::setMouseCursorLocked(bool locked)
  {
  }

  bool 
    InputManagerWin32::isMouseCursorLocked() const
  {
    return false;
  }

  void 
    InputManagerWin32::setMouseCursorGrabbed(bool grabbed)
  {
  }

  bool 
    InputManagerWin32::isMouseCursorGrabbed() const
  {
    return false;
  }

  void 
    InputManagerWin32::setMouseCursor(const char* filename)
  {
  }

  int32 
    InputManagerWin32::keyToVirtualKeyCode(Key key) const
  {
    switch (key)
    {
      case Key::A: return 0x41;
      case Key::B: return 0x42;
      case Key::C: return 0x43;
      case Key::D: return 0x44;
      case Key::E: return 0x45;
      case Key::F: return 0x46;
      case Key::G: return 0x47;
      case Key::H: return 0x48;
      case Key::I: return 0x49;
      case Key::J: return 0x4A;
      case Key::K: return 0x4B;
      case Key::L: return 0x4C;
      case Key::M: return 0x4D;
      case Key::N: return 0x4E;
      case Key::O: return 0x4F;
      case Key::P: return 0x50;
      case Key::Q: return 0x51;
      case Key::R: return 0x52;
      case Key::S: return 0x53;
      case Key::T: return 0x54;
      case Key::U: return 0x55;
      case Key::V: return 0x56;
      case Key::W: return 0x57;
      case Key::X: return 0x58;
      case Key::Y: return 0x59;
      case Key::Z: return 0x5A;

      default: return 0;
    }
  }
}
