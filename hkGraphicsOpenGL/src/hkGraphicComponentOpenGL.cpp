#include <Hakool\Utils\hkLogger.h>
#include <Hakool\Utils\hkWindow.h>

#include <Hakool\GraphicsOpenGL\hkGraphicComponentOpenGL.h>
#include <Hakool\GraphicsOpenGL\hkContextOpenGL.h>

#define GL_LITE_IMPLEMENTATION
#include <Hakool\GraphicsOpenGL\gl_lite.h>

namespace hk
{
  GraphicComponentOpenGL::GraphicComponentOpenGL():
    GraphicComponent()
  {
    _m_graphicInterfaceId = eGRAPHIC_INTERFACE::kOpenGL;
    _m_isReady = false;
    return;
  }

  GraphicComponentOpenGL::~GraphicComponentOpenGL()
  {
    destroy();

    return;
  }

  eRESULT 
  GraphicComponentOpenGL::init
  (
    Window* _pWindow, 
    const GraphicsConfiguration& _graphicConfiguration
  )
  {
    if (_m_isReady)
    {
      Logger::GetReference().warning("OpenGL GraphicComponent already created.");
      return eRESULT::kFail;
    }

    _m_pWindow = _pWindow;

    // Creates the OpenGL Context.
    
    PIXELFORMATDESCRIPTOR pfd =
    {
      sizeof(PIXELFORMATDESCRIPTOR),
      1,
      PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
      PFD_TYPE_RGBA,
      32,
      0, 0, 0, 0, 0, 0,
      0,
      0,
      0,
      0, 0, 0, 0,
      24,
      8,
      0,
      PFD_MAIN_PLANE,
      0,
      0, 0, 0
    };

    HDC windowDeviceContext = GetDC(_pWindow->getWindowHandler());

    uint32  letWindowsChooseThisPixelFormat;
    letWindowsChooseThisPixelFormat = ChoosePixelFormat(windowDeviceContext, &pfd);
    SetPixelFormat(windowDeviceContext, letWindowsChooseThisPixelFormat, &pfd);

    HGLRC contextOpenGL = wglCreateContext(windowDeviceContext);
    wglMakeCurrent(windowDeviceContext, contextOpenGL);

    gl_lite_init();

    _m_pContextOpenGL = new ContextOpenGL(contextOpenGL);
    _m_clearColor = _graphicConfiguration.backgroundColor;

    _m_isReady = !_m_isReady;

    return eRESULT::kSuccess;
  }

  void 
  GraphicComponentOpenGL::update()
  {
    _draw();

    SwapBuffers(GetDC(_m_pWindow->getWindowHandler()));

    return;
  }

  void 
  GraphicComponentOpenGL::destroy()
  {
    if (!_m_isReady)
    {
      return;
    }

    HDC windowDeviceContext = GetDC(_m_pWindow->getWindowHandler());

    wglMakeCurrent(windowDeviceContext, NULL);
    wglDeleteContext(reinterpret_cast<HGLRC>(_m_pContextOpenGL->get()));
    
    delete _m_pContextOpenGL;

    _m_isReady = !_m_isReady;
    
    return;
  }

  eGRAPHIC_INTERFACE 
  GraphicComponentOpenGL::getGraphicInterfaceId()
  {
    return this->_m_graphicInterfaceId;
  }

  void 
  GraphicComponentOpenGL::_draw()
  {
    glClearColor
    (
      _m_clearColor.r, 
      _m_clearColor.g, 
      _m_clearColor.b, 
      _m_clearColor.a
    );

    glClear(GL_COLOR_BUFFER_BIT);

    return;
  }
}