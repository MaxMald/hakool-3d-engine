#include <Hakool\GraphicsOpenGL\hkGraphicComponentOpenGL.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Hakool\Utils\hkLogger.h>
#include <Hakool\Utils\hkIWindow.h>
#include <Hakool\Core\hakool.h>
#include <Hakool\Core\hkResourceManager.h>
#include <Hakool\Core\hkScene.h>
#include <Hakool\GraphicsOpenGL\hkContextOpenGL.h>
#include <Hakool\GraphicsOpenGL\hkShaderOpenGL.h>
#include <Hakool\GraphicsOpenGL\hkProgramOpenGL.h>
#include <Hakool\GraphicsOpenGL\hkMeshOpenGL.h>
#include <Hakool\GraphicsOpenGL\hkWindowOpenGL.h>

namespace hk
{
  GraphicComponentOpenGL::GraphicComponentOpenGL() :
    _m_clearColor(0.0f, 0.0f, 0.0f, 1.0f),
    _m_aVAO(),
    _m_pProgramOpenGL(nullptr),
    _m_pResourceManager(nullptr),
    _m_projViewMatrix(),
    _m_modelViewMat(),
    _m_pWindow(nullptr),
    _m_pContextOpenGL(nullptr),
    _m_isReady(false)
  { }

  GraphicComponentOpenGL::~GraphicComponentOpenGL()
  {
    destroy();
  }

  eRESULT
  GraphicComponentOpenGL::init(
    const GraphicsConfiguration& _graphicConfiguration,
    const WindowConfiguration& windowConfig,
    ResourceManager& resourceManager)
  {
    if (_m_isReady)
    {
      Logger::GetReference().warning("OpenGL GraphicComponent already created.");
      return eRESULT::kFail;
    }
    
    _m_pResourceManager = &resourceManager;
    if (!glfwInit())
    {
      throw std::runtime_error("Couldn't initialize GLFW.");
    }
    
    try
    {
      _m_pWindow = new WindowOpenGL();
      _m_pWindow->init(windowConfig);
    }
    catch (...)
    {
      glfwTerminate();
      throw;
    }

    if (glewInit() != GLEW_OK)
    {
      _m_pWindow->destroy();
      glfwTerminate();
      
      throw std::runtime_error("Couldn't initialize GLEW.");
    }

    glfwSwapInterval(1);

    _m_clearColor = _graphicConfiguration.backgroundColor;

    // Default vertex shader.
    const char* pVertexSource =
      "#version 430 \n"
      "layout (location=0) in vec3 position;\n"
      "uniform mat4 proj_view_matrix;\n"
      "uniform mat4 model_matrix;\n"
      "void main(void) \n"
      "{\n"
      " gl_Position = proj_view_matrix * model_matrix * vec4(position,1.0);\n"
      "}";

    eRESULT result(eRESULT::kFail);
    ShaderOpenGL vertexShader;
    result = vertexShader.create(pVertexSource, eSHADER_TYPE::kVertex);

    if (result != eRESULT::kSuccess)
    {
      Logger::Error("| GraphicComponentOpenGL | Cannot initialize the component.");
      _releaseResources(resourceManager);
      glfwTerminate();
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
      glfwTerminate();
      return eRESULT::kFail;
    }

    // Create default fragment shader
    const char* pFragmentSource =
      "#version 430 \n"
      "out vec4 color; \n"
      "uniform mat4 proj_view_matrix;\n"
      "uniform mat4 model_matrix;\n"
      "void main(void) \n"
      "{ color = vec4(1.0, 0.0, 0.0, 1.0); }";    

    ShaderOpenGL fragShader;
    result = fragShader.create(pFragmentSource, eSHADER_TYPE::kFragment);

    if (result != eRESULT::kSuccess)
    {
      Logger::Error("| GraphicComponentOpenGL | Cannot initialize the component.");
      _releaseResources(resourceManager);
      glfwTerminate();
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
      glfwTerminate();
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
      glfwTerminate();
      return eRESULT::kFail;
    }

    glGenVertexArrays(1, _m_aVAO);
    glBindVertexArray(_m_aVAO[0]);

    _m_pWindow->addObserver(this);

    setClearColor(_m_clearColor);

    _m_isReady = !_m_isReady;
    return eRESULT::kSuccess;
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
    glClear(GL_DEPTH_BUFFER_BIT);
  }

  void 
  GraphicComponentOpenGL::prepareToDraw()
  {
    _m_activeProgramId = *(reinterpret_cast<uint32*>(_m_pProgramOpenGL->getProgramPtr()));
    glUseProgram(static_cast<GLuint>(_m_activeProgramId));

    GLuint projViewMatLoc = glGetUniformLocation(_m_activeProgramId, "proj_view_matrix");
    float aspect = (float)_m_pWindow->getWidth() / (float)_m_pWindow->getHeight();
    _m_projViewMatrix = (Matrix4::GetPerspective(1.0472f, aspect, 0.1f, 1000.f)
      * Matrix4::GetTranslation(0.0f, 0.0f, -8.0f)).transpose();
    
    glUniformMatrix4fv(projViewMatLoc, 1, GL_FALSE, &_m_projViewMatrix.a[0]);
  }

  void 
  GraphicComponentOpenGL::drawScene(Scene* pScene)
  {
    return;
  }

  IMesh*
  GraphicComponentOpenGL::createMesh()
  {
    return new MeshOpenGL();
  }

  void 
  GraphicComponentOpenGL::setModelMatrix(const Matrix4& modelMatrix)
  {
    GLuint modelMatLoc = glGetUniformLocation(_m_activeProgramId, "model_matrix");
    glUniformMatrix4fv(modelMatLoc, 1, GL_FALSE, &modelMatrix.a[0]);
  }

  IShader* 
  GraphicComponentOpenGL::createVertexShader()
  {
      return new ShaderOpenGL();
  }

  IShader* 
  GraphicComponentOpenGL::createFragmentShader()
  {
      return new ShaderOpenGL();
  }

  IProgram* 
  GraphicComponentOpenGL::createProgram()
  {
      return new ProgramOpenGL();
  }

  IWindow* 
  GraphicComponentOpenGL::getWindow()
  {
    return _m_pWindow;
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

    glfwTerminate();
    _m_isReady = !_m_isReady;    
    return;
  }

  eGRAPHIC_INTERFACE 
  GraphicComponentOpenGL::getGraphicInterfaceId()
  {
    return eGRAPHIC_INTERFACE::kOpenGL;
  }

  void 
  GraphicComponentOpenGL::onWindowSizeChanged(
    const uint32& width, 
    const uint32& height, 
    IWindow* pWindow) const
  {
    glViewport(0, 0, width, height);
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

    delete _m_pContextOpenGL;
    return;
  }
}