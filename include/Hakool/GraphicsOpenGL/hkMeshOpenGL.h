#pragma once

#include <Hakool\Core\Graphics\hkIContext.h>
#include <Hakool\Core\Graphics\hkMesh.h>

#include <Hakool\GraphicsOpenGL\hkGraphicsOpenGLPrerequisites.h>
#include <Hakool\GraphicsOpenGL\gl_lite.h>

namespace hk
{
  /**
   * Object that handles a single Mesh.
   */
  class MeshOpenGL : 
    public Mesh
  {
  public:

    /**
    * Constructor.
    */
    MeshOpenGL();

    /**
    * Copy constructor.
    */
    explicit MeshOpenGL(const MeshOpenGL& _context);

    /**
    * Destructor.
    */
    virtual ~MeshOpenGL();

    virtual void
    init(float* _aVertexes, const uint32& _size) override;

    virtual void
    draw(GraphicComponent* pGraphicComponent) override;

  private:

    GLuint 
    _m_vbo[2];
  };
}