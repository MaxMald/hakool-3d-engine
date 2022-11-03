#include <Hakool/GraphicsOpenGL/hkMeshOpenGL.h>

#include <Hakool/GraphicsOpenGL/hkGraphicComponentOpenGL.h>

namespace hk
{
  MeshOpenGL::MeshOpenGL() :
    Mesh(),
    _m_vbo()
  {
    return;
  }

  MeshOpenGL::MeshOpenGL(const MeshOpenGL& _copy) :
    Mesh(_copy),
    _m_vbo()
  {
    // TODO create copy
    return;
  }

  MeshOpenGL::~MeshOpenGL()
  {
  }

  void 
  MeshOpenGL::init(float* _aVertexes, const uint32& _size)
  {
    Mesh::init(_aVertexes, _size);

    float vertexes[108] {
      -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 1.0f, -1.0f,
        1.0f, -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f, -1.0f,
        1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, -1.0f,
        1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f,
        -1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, -1.0f,
    };

    glGenBuffers(2,_m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _m_vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexes), vertexes, GL_STATIC_DRAW);

    GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR)
    {
      // Process/log the error.
      return;
    }
  }

  void 
  MeshOpenGL::draw(GraphicComponent* pGraphicComponent)
  {
    glBindBuffer(GL_ARRAY_BUFFER, _m_vbo[0]);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDrawArrays(GL_TRIANGLES, 0, _m_vertexesSize / 3);

    GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR)
    {
      // Process/log the error.
      return;
    }
  }
}