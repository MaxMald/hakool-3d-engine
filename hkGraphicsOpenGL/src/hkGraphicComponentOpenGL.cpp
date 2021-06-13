#include <Hakool\Utils\hkLogger.h>
#include <Hakool\Utils\hkWindow.h>

#include <Hakool\hakool.h>
#include <Hakool\Core\hkResourceManager.h>

#include <Hakool\GraphicsOpenGL\hkGraphicComponentOpenGL.h>
#include <Hakool\GraphicsOpenGL\hkContextOpenGL.h>
#include <Hakool\GraphicsOpenGL\hkShaderOpenGL.h>
#include <Hakool\GraphicsOpenGL\hkProgramOpenGL.h>

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

    // Create default vertex shader

    const char* pVertexSource =
      "#version 430 \n"
      "void main(void) \n"
      "{ gl_Position = vec4(0.0, 0.0, 0.0, 1.0); }";

    eRESULT result(eRESULT::kFail);
    ShaderOpenGL vertexShader;
    result = vertexShader.create(pVertexSource, eSHADER_TYPE::kVertex);

    if (result != eRESULT::kSuccess)
    {
      Logger::Error("| GraphicComponentOpenGL | Cannot initialize the component.");
      _clean();

      return eRESULT::kFail;
    }

    // Add vertex shader to the resource manager.

    ResourceManager& resourceManager = _m_hakool->getResource();
    ResourceGroup<Shader>& shaders = resourceManager.getShaders();
    result = shaders.add
    (
      "__vertex_default", 
      reinterpret_cast<Shader*>(&vertexShader)
    );

    if (result != eRESULT::kSuccess)
    {
      Logger::Error("| GraphicComponentOpenGL | Cannot initialize the component.");
      _clean();

      return eRESULT::kFail;
    }

    // Create default fragment shader

    const char* pFragmentSource =
      "#version 430 \n"
      "out vec4 color; \n"
      "void main() \n"
      "{ color = vec4(0.0, 0.0, 1.0, 1.0); }";    

    ShaderOpenGL fragShader;
    result = fragShader.create(pFragmentSource, eSHADER_TYPE::kFragment);

    if (result != eRESULT::kSuccess)
    {
      Logger::Error("| GraphicComponentOpenGL | Cannot initialize the component.");

      _clean();
      return eRESULT::kFail;
    }

    // Add fragment shader to the resource manager.

    result = shaders.add
    (
      "__fragment_default", 
      reinterpret_cast<Shader*>(&fragShader)
    );

    if (result != eRESULT::kSuccess)
    {
      Logger::Error("| GraphicComponentOpenGL | Cannot initialize the component.");
      _clean();

      return eRESULT::kFail;
    }

    // Create default program.

    _m_pProgramOpenGL = new ProgramOpenGL();
    result = _m_pProgramOpenGL->create
    (
      "__fragment_default",
      "__vertex_default",
      &resourceManager
    );

    if (result != eRESULT::kSuccess)
    {
      Logger::Error("| GraphicComponentOpenGL | Cannot initialize the component.");

      _clean();
      return eRESULT::kFail;
    }

    // Create vertex array objects.

    glGenVertexArrays(1, _m_aVAO);
    glBindVertexArray(_m_aVAO[0]);

    // Component is ready.

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

  IShader* 
  GraphicComponentOpenGL::getVShader()
  {
      return new ShaderOpenGL();
  }

  IShader* 
  GraphicComponentOpenGL::getFShader()
  {
      return new ShaderOpenGL();
  }

  IProgram* 
  GraphicComponentOpenGL::getProgram()
  {
      return new ProgramOpenGL();
  }

  void
  GraphicComponentOpenGL::destroy()
  {
    if (!_m_isReady)
    {
      return;
    }

    _clean();
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

    uint32 programId = *(reinterpret_cast<uint32*>(_m_pProgramOpenGL->getProgramPtr()));
    glUseProgram(static_cast<GLuint>(programId));

    glPointSize(5.0f);
    glDrawArrays(GL_POINTS, 0, 1);

    return;
  }

  void 
  GraphicComponentOpenGL::_clean()
  {
    // Destroy default program

    if (_m_pProgramOpenGL != nullptr)
    {
      _m_pProgramOpenGL->destroy();
      delete _m_pProgramOpenGL;
      _m_pProgramOpenGL = nullptr;
    }

    // Destroy default shader objects

    ResourceManager & resourceManager = _m_hakool->getResource();
    ResourceGroup<Shader>& shaders = resourceManager.getShaders();
    
    if (shaders.has("__fragment_default"))
    {
      shaders.removeAndDestroy("__fragment_default");
    }

    if (shaders.has("__vertex_default"))
    {
      shaders.removeAndDestroy("__vertex_default");
    }

    // Detach context

    HDC windowDeviceContext = GetDC(_m_pWindow->getWindowHandler());

    wglMakeCurrent(windowDeviceContext, NULL);
    wglDeleteContext(reinterpret_cast<HGLRC>(_m_pContextOpenGL->get()));

    delete _m_pContextOpenGL;
  }
}