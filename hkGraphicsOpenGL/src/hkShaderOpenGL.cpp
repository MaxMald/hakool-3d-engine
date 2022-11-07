#include <Hakool\GraphicsOpenGL\hkShaderOpenGL.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Hakool\Utils\hkLogger.h>
#include <Hakool\GraphicsOpenGL\hkGraphicComponentOpenGL.h>

namespace hk
{
  ShaderOpenGL::ShaderOpenGL() :
    _m_type(eSHADER_TYPE::kUndefined),
    _m_shaderId(0),
    _m_isReady(false)
  {
    // Intentionally blank
    return;
  }

  ShaderOpenGL::~ShaderOpenGL()
  {
    destroy();
    return;
  }

  void* 
  ShaderOpenGL::getShaderPtr()
  {
    return static_cast<void*>(&_m_shaderId);
  }

  eRESULT 
  ShaderOpenGL::init(GraphicComponent*)
  {
    // Intentionally blank
    return eRESULT::kSuccess;
  }

  eRESULT 
  ShaderOpenGL::create(const char* _pSource, const eSHADER_TYPE& _type)
  {
    if (_m_isReady) 
    {
      Logger::Error("| ShaderOpenGL | Shader is already created.");

      return eRESULT::kFail;
    }

    GLuint shaderID = 0;

    switch (_type)
    {
    case eSHADER_TYPE::kFragment:
      shaderID = glCreateShader(GL_FRAGMENT_SHADER);
      break;

    case eSHADER_TYPE::kVertex:
      shaderID = glCreateShader(GL_VERTEX_SHADER);
      break;

    default:
      Logger::Error("| ShaderOpenGL | Not supported shader type.");   
      return eRESULT::kFail;
    }

    if (shaderID == 0)
    {
      Logger::Error("| ShaderOpenGL | An error occurs creating the shader object.");

      return eRESULT::kFail;
    }   

    glShaderSource(shaderID, 1, &_pSource, NULL);
    glCompileShader(shaderID);

    glGetError();

    GLint isCompiled;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &isCompiled);

    if (isCompiled != 1)
    {
      Logger::Error("| ShaderOpenGL | Failed to compile the shader.");

      int32 length = 0;
      int32 charWritten = 0;

      glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length);
      if (length > 0)
      {
        char* msg = (char*)malloc(length);
       
        glGetShaderInfoLog(shaderID, length, &charWritten, msg);
        if (msg != 0)
        {
          Logger::Error("| ShaderOpenGL | Shader Log: \n\n" + String(msg));
        }
        free(msg);
      }

      glDeleteShader(shaderID);
      return eRESULT::kFail;
    }

    _m_shaderId = static_cast<uint32>(shaderID);
    _m_isReady = !_m_isReady;
    _m_type = _type;

    return eRESULT::kSuccess;
  }

  bool 
  ShaderOpenGL::isReady()
  {
    return _m_isReady;
  }

  void
  ShaderOpenGL::destroy()
  {
    if (_m_isReady)
    {
      glDeleteShader(_m_shaderId);
      _m_isReady = !_m_isReady;
    }

    _m_shaderId = 0;
    _m_type = eSHADER_TYPE::kUndefined;

    return;
  }

  eSHADER_TYPE 
  ShaderOpenGL::getType()
  {
    return _m_type;
  }
}