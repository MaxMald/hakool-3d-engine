#include <Hakool\Utils\hkWindow.h>
#include <Hakool/Utils/hkWindowObserver.h>

namespace hk
{
  Window::Window() :
    _m_size(0, 0),
    _m_title(""),
    _m_observers()
  {
    return;
  }

  Window::~Window()
  {
    this->destroy();
    return;
  }

  eRESULT 
  Window::init(const WindowConfiguration& _config)
  {
    this->_m_size.x = _config.width;
    this->_m_size.y = _config.height;
    this->_m_title  = _config.title;

    return eRESULT::kSuccess;
  }

  void 
  Window::setSize(const uint32& _width, const uint32& _height)
  {
    this->_m_size.x = _width;
    this->_m_size.y = _height;
    for (auto pObserver : _m_observers)
    {
      pObserver->onWindowSizeChanged(*this);
    }
    return;
  }

  void 
  Window::setSize(const Vector2u& _v2)
  {
    this->_m_size = _v2;
    for (auto pObserver : _m_observers)
    {
      pObserver->onWindowSizeChanged(*this);
    }
    return;
  }

  void 
  Window::setTitle(const String& _title)
  {
    this->_m_title = _title;

    return;
  }

  HANDLER 
  Window::getWindowHandler()
  {
      return HANDLER();
  }

  bool 
  Window::isOpen()
  {
    return false;
  }

  void 
  Window::update()
  {
    return;
  }

  void 
  Window::postUpdate()
  {
    return;
  }

  void 
  Window::destroy()
  {
    return;
  }

  void 
  Window::addObserver(const WindowObserver* pObserver)
  {
    _m_observers.push_back(pObserver);
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