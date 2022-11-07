#include <Hakool/GraphicsOpenGL/hkWindowOpenGL.h>

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include <Hakool/Utils/hkWindowObserver.h>

namespace hk
{
  WindowOpenGL::WindowOpenGL() :
    _m_observers(),
    _m_pWindow(nullptr),
    _m_title("")
  { }

  WindowOpenGL::~WindowOpenGL()
  {
    destroy();
  }

  eRESULT 
  WindowOpenGL::init(const WindowConfiguration& _config)
  {
    if (_m_pWindow != nullptr)
    {
      throw std::logic_error("WindowOpenGL is already initialized.");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    _m_pWindow = glfwCreateWindow(
      _config.width, 
      _config.height, 
      _config.title.c_str(), 
      NULL, 
      NULL);
    _m_title = _config.title;

    if (_m_pWindow == nullptr)
    {
      throw std::runtime_error("Could not create an OpenGL Window.");
    }

    glfwMakeContextCurrent(_m_pWindow);
    return eRESULT::kSuccess;
  }

  void 
  WindowOpenGL::setSize(const uint32& _width, const uint32& _height)
  {
    if (_m_pWindow != nullptr)
    {
      glfwSetWindowSize(_m_pWindow, (int)_width, (int)_height);
      for (auto pObserver : _m_observers)
      {
        pObserver->onWindowSizeChanged((int)_width, (int)_height, this);
      }
    }
  }

  void 
  WindowOpenGL::setSize(const Vector2u& _v2)
  {
    if (_m_pWindow != nullptr)
    {
      glfwSetWindowSize(_m_pWindow, (int)_v2.x, (int)_v2.y);
      for (auto pObserver : _m_observers)
      {
        pObserver->onWindowSizeChanged((int)_v2.x, (int)_v2.y, this);
      }
    }
  }

  void 
  WindowOpenGL::setTitle(const String& _title)
  {
    if (_m_pWindow != nullptr)
    {
      glfwSetWindowTitle(_m_pWindow, _title.c_str());
      _m_title = _title;
    }
  }

  HANDLER 
  WindowOpenGL::getWindowHandler()
  {
    if (_m_pWindow != nullptr)
    {
#ifdef GLFW_EXPOSE_NATIVE_WIN32
      return glfwGetWin32Window(_m_pWindow);
#endif
    }
    return NULL;
  }

  bool 
  WindowOpenGL::isOpen()
  {
    if (_m_pWindow != nullptr)
    {
      return !glfwWindowShouldClose(_m_pWindow);
    }
    return false;
  }

  void 
  WindowOpenGL::update()
  {
  }

  void 
  WindowOpenGL::postUpdate()
  {
  }

  void 
  WindowOpenGL::present()
  {
    if (_m_pWindow != nullptr)
    {
      glfwSwapBuffers(_m_pWindow);
      glfwPollEvents();
    }
  }

  void 
  WindowOpenGL::destroy()
  {
    if (_m_pWindow != nullptr)
    {
      glfwDestroyWindow(_m_pWindow);
    }

    _m_title = "";
    _m_pWindow = nullptr;
    _m_observers.clear();
  }

  void 
  WindowOpenGL::addObserver(const WindowObserver* pObserver)
  {
    _m_observers.push_back(pObserver);
  }

  Vector2u 
  WindowOpenGL::getSize()
  {
    int width { 0 };
    int height { 0 };
    if (_m_pWindow != nullptr)
    { 
      glfwGetFramebufferSize(_m_pWindow, &width, &height);
    }
    return Vector2u((uint32)width, (uint32)height);
  }

  uint32 
  WindowOpenGL::getWidth()
  {
    int width { 0 };
    if (_m_pWindow != nullptr)
    {
      glfwGetFramebufferSize(_m_pWindow, &width, NULL);
    }
    return (uint32)width;
  }

  uint32 
  WindowOpenGL::getHeight()
  {
    int height { 0 };
    if (_m_pWindow != nullptr)
    {
      glfwGetFramebufferSize(_m_pWindow, NULL, &height);
    }
    return (uint32)height;
  }

  String 
  WindowOpenGL::getTitle()
  {
    return _m_title;
  }
}