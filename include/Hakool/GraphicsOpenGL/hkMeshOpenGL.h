#pragma once

#include <Hakool\Core\Graphics\hkIContext.h>

#include <Hakool\GraphicsOpenGL\hkGraphicsOpenGLPrerequisites.h>
#include <Hakool\GraphicsOpenGL\gl_lite.h>

namespace hk
{
  /**
   * Object that handles a single Mesh.
   */
  class MeshOpenGL
  {
  public:

    /**
    * Constructor.
    */
    MeshOpenGL();

    /**
    *
    */
    MeshOpenGL(HGLRC _context);

    /**
    * Copy constructor.
    */
    MeshOpenGL(const MeshOpenGL& _context);

    /**
    * Destructor.
    */
    virtual ~MeshOpenGL();

    /**
    * Get the OpenGL Context.
    *
    * @return the OpenGL Context.
    */
    virtual void*
      get() override;

  private:

    int vbo;

    int v
  };
}