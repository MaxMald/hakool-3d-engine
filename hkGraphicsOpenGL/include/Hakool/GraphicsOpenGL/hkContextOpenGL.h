#pragma once

#include <windows.h>

#include <Hakool\Core\hkIContext.h>
#include <Hakool\GraphicsOpenGL\hkGraphicsOpenGLPrerequisites.h>

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