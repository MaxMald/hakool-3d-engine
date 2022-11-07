#include <Hakool/GraphicsOpenGL/hkMeshOpenGL.h>
#include <Hakool/GraphicsOpenGL/hkGraphicComponentOpenGL.h>

namespace hk
{
  MeshOpenGL::MeshOpenGL() :
    IMesh(),
    _m_vbo(),
    _m_size(0)
  { }

  MeshOpenGL::~MeshOpenGL()
  {
    destroy();
  }

  void 
  MeshOpenGL::init(float* aVertexes, const uint32& size)
  {
    _m_size = size;
    glGenBuffers(1, &_m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size * 3, aVertexes, GL_STATIC_DRAW);
  }

  void 
  MeshOpenGL::draw(GraphicComponent* pGraphicComponent)
  {
    glBindBuffer(GL_ARRAY_BUFFER, _m_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDrawArrays(GL_TRIANGLES, 0, _m_size);
  }

  uint32 
  MeshOpenGL::getVertexesSize()
  {
    return _m_size;
  }

  float*
  MeshOpenGL::getVertexesArray()
  {
    return nullptr;
  }

  void 
  MeshOpenGL::destroy()
  {
    // TODO
  }
}