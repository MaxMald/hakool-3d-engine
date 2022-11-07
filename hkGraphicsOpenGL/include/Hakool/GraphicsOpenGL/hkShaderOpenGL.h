#pragma once

#include <Hakool\Core\hkShader.h>
#include <Hakool\GraphicsOpenGL\hkGraphicsOpenGLPrerequisites.h>

namespace hk
{
  class GraphicComponentOpenGL;

  /**
  * TODO.
  */
  class HK_GRAPHICS_OPENGL_EXPORT ShaderOpenGL :
    public IShader
  {
  public:

    /**
    * Constructor.
    */
    ShaderOpenGL();

    /**
    * Destructor.
    */
    ~ShaderOpenGL();

    /**
    * Get the pointer to the wrapped API's shader.
    *
    * @return The pointer to the wrapped API's shader.
    */
    virtual void*
    getShaderPtr() override;

    /**
    * Initialize the shader. OpenGL shader doesn't use method.
    *
    * @return Operation result.
    */
    virtual eRESULT
    init(GraphicComponent*) override;

    /**
    * Create the shader from a source.
    *
    * @param _pSource The shader's source.
    *
    * @return Operation result.
    */
    virtual eRESULT
    create(const char* _pSource, const eSHADER_TYPE& _type) override;

    /**
    * Check if this shader is ready to be used.
    *
    * @return True is the shader is ready, otherwise returns false.
    */
    virtual bool
    isReady() override;

    /**
    * Safely destroy this shader.
    */
    virtual void
    destroy() override;

    /**
    * Get the type of this shader.
    */
    virtual eSHADER_TYPE
    getType() override;

  private:

    /**
    * Indicates the type of this shader.
    */
    eSHADER_TYPE
    _m_type;

    /**
    * The Shader's id gave by the OpenGL API.
    */
    uint32
    _m_shaderId;

    /**
    * Indicates if the shader is ready to be used.
    */
    bool
    _m_isReady;

    friend GraphicComponentOpenGL;
  };
}