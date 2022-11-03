#include <Hakool\Utils\hkLogger.h>
#include <Hakool\Utils\hkWindow.h>

#include <Hakool\hakool.h>
#include <Hakool\Core\hkResourceManager.h>
#include <Hakool\Core\hkScene.h>

#include <Hakool\GraphicsOpenGL\hkGraphicComponentOpenGL.h>
#include <Hakool\GraphicsOpenGL\hkContextOpenGL.h>
#include <Hakool\GraphicsOpenGL\hkShaderOpenGL.h>
#include <Hakool\GraphicsOpenGL\hkProgramOpenGL.h>
#include <Hakool\GraphicsOpenGL\hkMeshOpenGL.h>

#define GL_LITE_IMPLEMENTATION
#include <Hakool\GraphicsOpenGL\gl_lite.h>

namespace hk
{
  GraphicComponentOpenGL::GraphicComponentOpenGL():
    GraphicComponent(),
    _m_pResourceManager(nullptr),
    _m_perspectiveMat(),
    _m_modelViewMat()
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
    const GraphicsConfiguration& _graphicConfiguration,
    ResourceManager& resourceManager
  )
  {
    if (_m_isReady)
    {
      Logger::GetReference().warning("OpenGL GraphicComponent already created.");
      return eRESULT::kFail;
    }

    _m_pWindow = _pWindow;
    _m_pResourceManager = &resourceManager;

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
      "#version 410 \n"
      "layout (location=0) in vec3 position;\n"
      "uniform mat4 mv_matrix;\n"
      "uniform mat4 proj_matrix;\n"
      "void main(void) \n"
      "{\n"
      " gl_Position = proj_matrix * mv_matrix * vec4(position,1.0);\n"
      "}";

    eRESULT result(eRESULT::kFail);
    ShaderOpenGL vertexShader;
    result = vertexShader.create(pVertexSource, eSHADER_TYPE::kVertex);

    if (result != eRESULT::kSuccess)
    {
      Logger::Error("| GraphicComponentOpenGL | Cannot initialize the component.");
      _releaseResources(resourceManager);

      return eRESULT::kFail;
    }

    // Add vertex shader to the resource manager.
    ResourceGroup<Shader>& shaders = resourceManager.getShaders();
    result = shaders.add
    (
      "__vertex_default", 
      reinterpret_cast<Shader*>(&vertexShader)
    );

    if (result != eRESULT::kSuccess)
    {
      Logger::Error("| GraphicComponentOpenGL | Cannot initialize the component.");
      _releaseResources(resourceManager);

      return eRESULT::kFail;
    }

    // Create default fragment shader

    const char* pFragmentSource =
      "#version 410 \n"
      "out vec4 color; \n"
      "uniform mat4 mv_matrix;\n"
      "uniform mat4 proj_matrix;\n"
      "void main(void) \n"
      "{ color = vec4(1.0, 0.0, 0.0, 1.0); }";    

    ShaderOpenGL fragShader;
    result = fragShader.create(pFragmentSource, eSHADER_TYPE::kFragment);

    if (result != eRESULT::kSuccess)
    {
      Logger::Error("| GraphicComponentOpenGL | Cannot initialize the component.");

      _releaseResources(resourceManager);
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
      _releaseResources(resourceManager);

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

      _releaseResources(resourceManager);
      return eRESULT::kFail;
    }

    //glSwapInterval(1);
    glGenVertexArrays(1, _m_aVAO);
    glBindVertexArray(_m_aVAO[0]);
    
    GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR)
    {
      // Process/log the error.
      return eRESULT::kFail;
    }

    _m_pWindow->addObserver(this);

    setClearColor(_m_clearColor);

    _m_isReady = !_m_isReady;
    return eRESULT::kSuccess;
  }

  Mesh* 
  GraphicComponentOpenGL::createMesh()
  {
    return new MeshOpenGL();
  }

  void 
  GraphicComponentOpenGL::setClearColor(const Color& color)
  {
    _m_clearColor = color;
    glClearColor
    (
      _m_clearColor.r,
      _m_clearColor.g,
      _m_clearColor.b,
      _m_clearColor.a
    );
    return;
  }

  void
  GraphicComponentOpenGL::clear()
  {
    glClear(GL_COLOR_BUFFER_BIT);
    return;
  }

  void 
  GraphicComponentOpenGL::prepareToDraw()
  {
    uint32 programId = *(reinterpret_cast<uint32*>(_m_pProgramOpenGL->getProgramPtr()));
    glUseProgram(static_cast<GLuint>(programId));

    GLuint mvLoc = glGetUniformLocation(programId, "mv_matrix");
    GLuint projLoc = glGetUniformLocation(programId, "proj_matrix");

    float aspect = (float)_m_pWindow->getWidth() / (float)_m_pWindow->getHeight();
    
    /*
    _m_perspectiveMat = Matrix4::GetPerspective(1.0472f, aspect, 0.1f, 1000.f).transpose();
    Matrix4 view = Matrix4::GetTranslation(0.0f, 0.0f, 8.0f).transpose();
    Matrix4 model = Matrix4::GetTranslation(0.0f, 0.0f, 0.0f).transpose();
    _m_modelViewMat = view * model;    
    */

    
    _m_pers = glm::perspective(1.0472f, aspect, 0.1f, 1000.0f);
    _m_model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -8.0f)) * glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -2.0f, 0.0f));

    //glUniformMatrix4fv(mvLoc, 1, GL_FALSE, &_m_modelViewMat.a[0]);
    //glUniformMatrix4fv(projLoc, 1, GL_FALSE, &_m_perspectiveMat.a[0]);

    glUniformMatrix4fv(mvLoc, 1, GL_FALSE, glm::value_ptr(_m_model));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(_m_pers));
    return;
  }

  void 
  GraphicComponentOpenGL::drawScene(Scene* pScene)
  {
    return;
  }

  void 
  GraphicComponentOpenGL::drawMesh(Mesh& _Mesh)
  {

  }

  void 
  GraphicComponentOpenGL::present()
  { 
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

    if (_m_pResourceManager != nullptr)
    {
      _releaseResources(*_m_pResourceManager);
    }

    _m_isReady = !_m_isReady;    
    return;
  }

  eGRAPHIC_INTERFACE 
  GraphicComponentOpenGL::getGraphicInterfaceId()
  {
    return this->_m_graphicInterfaceId;
  }

  void 
  GraphicComponentOpenGL::onWindowSizeChanged(Window& window) const
  {
    glViewport(0, 0, window.getWidth(), window.getHeight());
    return;
  }

  void 
  GraphicComponentOpenGL::_releaseResources(ResourceManager& resourceManager)
  {
    if (_m_pProgramOpenGL != nullptr)
    {
      _m_pProgramOpenGL->destroy();
      delete _m_pProgramOpenGL;
      _m_pProgramOpenGL = nullptr;
    }

    ResourceGroup<Shader>& shaders = resourceManager.getShaders();    
    if (shaders.has("__fragment_default"))
    {
      shaders.removeAndDestroy("__fragment_default");
    }
    if (shaders.has("__vertex_default"))
    {
      shaders.removeAndDestroy("__vertex_default");
    }

    HDC windowDeviceContext = GetDC(_m_pWindow->getWindowHandler());

    wglMakeCurrent(windowDeviceContext, NULL);
    wglDeleteContext(reinterpret_cast<HGLRC>(_m_pContextOpenGL->get()));

    delete _m_pContextOpenGL;
    return;
  }
}