#include <Hakool\GraphicsOpenGL\hkContextOpenGL.h>

namespace hk
{
  ContextOpenGL::ContextOpenGL() : 
    _m_context()
  {
    return;
  }
  
  ContextOpenGL::ContextOpenGL(HGLRC _context) :
    _m_context(_context)
  {
    return;
  }
  
  ContextOpenGL::ContextOpenGL(const ContextOpenGL& _context):
    _m_context(_context._m_context)  
  {
    return;
  }
  
  ContextOpenGL::~ContextOpenGL()
  {
    return;
  }

  void* 
  ContextOpenGL::get()
  {
    return reinterpret_cast<void*>(_m_context);
  }
}