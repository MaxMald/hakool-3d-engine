#pragma once

#include <Hakool\Core\hkIContext.h>
#include <Hakool\Core\hkIMesh.h>
#include <Hakool\GraphicsOpenGL\hkGraphicsOpenGLPrerequisites.h>
#include <GL/glew.h>

namespace hk
{
  class MeshOpenGL : public IMesh
  {
  public:

    MeshOpenGL();

    virtual 
    ~MeshOpenGL();

    virtual void
    init(float* _aVertexes, const uint32& _size) override;

    virtual void
    draw(GraphicComponent* pGraphicComponent) override;

    virtual uint32
    getVertexesSize() override;

    virtual float*
    getVertexesArray() override;

    virtual void
    destroy() override;

  private:

    GLuint 
    _m_vbo;

    uint32
    _m_size;
  };
}