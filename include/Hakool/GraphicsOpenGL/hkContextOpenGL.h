#pragma once

#include <Hakool\Core\Graphics\hkIContext.h>

#include <Hakool\GraphicsOpenGL\hkGraphicsOpenGLPrerequisites.h>
#include <Hakool\GraphicsOpenGL\gl_lite.h>

namespace hk
{
  class ContextOpenGL :
    public IContext
  {
  public:

    /**
    * Constructor.
    */
    ContextOpenGL();

    /**
    * 
    */
    ContextOpenGL(HGLRC _context);

    /**
    * Copy constructor.
    */
    ContextOpenGL(const ContextOpenGL& _context);

    /**
    * Destructor.
    */
    virtual ~ContextOpenGL();

    /**
    * Get the OpenGL Context.
    * 
    * @return the OpenGL Context.
    */
    virtual void*
    get() override;

  private:

    /**
    * WebGL context.
    */
    HGLRC
    _m_context;
  };
}