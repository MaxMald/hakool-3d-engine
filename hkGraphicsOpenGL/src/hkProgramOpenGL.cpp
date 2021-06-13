#include <Hakool\Utils\hkLogger.h>

#include <Hakool\Core\hkResourceManager.h>

#include <Hakool\GraphicsOpenGL\hkProgramOpenGL.h>
#include <Hakool\GraphicsOpenGL\hkShaderOpenGL.h>
#include <Hakool\GraphicsOpenGL\gl_lite.h>

namespace hk
{
    ProgramOpenGL::ProgramOpenGL() :
      _m_isReady(false),
      _m_programId(0)
    {
      return;
    }

    ProgramOpenGL::~ProgramOpenGL()
    {
      destroy();
      return;
    }

    eRESULT 
    ProgramOpenGL::init(GraphicComponent* _pGraphicComponent)
    {
      // Intentionally blank
      return eRESULT::kSuccess;
    }

    eRESULT 
    ProgramOpenGL::create
    (
      const String& _fragment, 
      const String& _vertex, 
      ResourceManager* _pResourceManager
    )
    {
      if (_m_isReady)
      {
        Logger::Error("| ProgramGL | Shader is already created.");

        return eRESULT::kFail;
      }

      ResourceGroup<Shader>& shaders = _pResourceManager->getShaders();
      
      if (!shaders.has(_fragment))
      {
        Logger::Error("| ProgramGL | Shader : " + _fragment + " was not found.");

        return eRESULT::kFail;
      }

      ShaderOpenGL* pFragment 
         = reinterpret_cast<ShaderOpenGL*>(shaders.get(_fragment));
      if (pFragment->getType() != eSHADER_TYPE::kFragment)
      {
        Logger::Error("| ProgramGL | THe shader : " + _fragment + " is not a fragment shader");

        return eRESULT::kFail;
      }

      if (!shaders.has(_vertex))
      {
        Logger::Error("| ProgramGL | Shader : " + _vertex + " was not found.");

        return eRESULT::kFail;
      }

      ShaderOpenGL* pVertex
        = reinterpret_cast<ShaderOpenGL*>(shaders.get(_vertex));
      if (pVertex->getType() != eSHADER_TYPE::kVertex)
      {
        Logger::Error("| ProgramGL | THe shader : " + _fragment + " is not a vertex shader");

        return eRESULT::kFail;
      }

      GLuint programID = glCreateProgram();
      if (programID == 0)
      {
        Logger::Error("| ProgramGL | An error occurs creating the program object.");

        return eRESULT::kFail;
      }

      uint32 fragmentID = *(reinterpret_cast<uint32*>(pFragment->getShaderPtr()));
      uint32 vertexID = *(reinterpret_cast<uint32*>(pVertex->getShaderPtr()));
      
      glAttachShader(programID, static_cast<GLuint>(fragmentID));
      glAttachShader(programID, static_cast<GLuint>(vertexID));

      glLinkProgram(programID);

      glGetError();

      GLint isLinked;
      glGetProgramiv(programID, GL_LINK_STATUS, &isLinked);
      if (isLinked != 1)
      {
        Logger::Error("| ProgramGL | Failed to link program");

        int32 length = 0;
        int32 charWritten = 0;

        glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &length);
        if (length > 0)
        {
          char* msg = (char*)malloc(length);

          glGetShaderInfoLog(programID, length, &charWritten, msg);
          if (msg != 0)
          {
            Logger::Error("| ProgramGL | Program Log: \n\n" + String(msg));
          }
          free(msg);
        }

        glDeleteProgram(programID);

        return eRESULT::kFail;
      }

      _m_programId = programID;
      _m_isReady = !_m_isReady;

      return eRESULT::kSuccess;
    }

    void* 
    ProgramOpenGL::getProgramPtr()
    {
      return reinterpret_cast<void*>(&_m_programId);
    }

    bool 
    ProgramOpenGL::isReady()
    {
      return _m_isReady;
    }

    void 
    ProgramOpenGL::destroy()
    {
      if (_m_isReady)
      {
        glDeleteProgram(_m_programId);
        _m_isReady = !_m_isReady;
      }

      _m_programId = 0;

      return;
    }
}