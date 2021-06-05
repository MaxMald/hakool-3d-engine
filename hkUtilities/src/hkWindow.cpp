#include <Hakool\Utils\hkWindow.h>

namespace hk
{
  Window::Window() :
    _m_size(0, 0),
    _m_title("")
  {
    return;
  }

  Window::~Window()
  {
    this->close();

    return;
  }

  eRESULT 
  Window::init
  (
    const uint32& _width, 
    const uint32& _height, 
    const String& _title
  )
  {
    this->_m_size.x = _width;
    this->_m_size.y = _height;
    this->_m_title = _title;

    return eRESULT::kSuccess;
  }

  void 
  Window::close()
  {
    return;
  }

  void 
  Window::setSize(const uint32& _width, const uint32& _height)
  {
    this->_m_size.x = _width;
    this->_m_size.y = _height;

    return;
  }

  void 
  Window::setSize(const Vector2u& _v2)
  {
    this->_m_size = _v2;

    return;
  }

  void 
  Window::setTitle(const String& _title)
  {
    this->_m_title = _title;

    return;
  }

  void 
  Window::destroy()
  {
    return;
  }

  Vector2u 
  Window::getSize()
  {
    return Vector2u(this->_m_size);
  }

  uint32 
  Window::getWidth()
  {
    return uint32(this->_m_size.x);
  }

  uint32 
  Window::getHeight()
  {
    return uint32(this->_m_size.y);
  }

  String 
  Window::getTitle()
  {
    return String(this->_m_title);
  }
}