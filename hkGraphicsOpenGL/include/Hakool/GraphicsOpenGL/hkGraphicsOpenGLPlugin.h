#pragma once

#include <Hakool\GraphicsOpenGL\hkGraphicsOpenGLPrerequisites.h>
#include <Hakool\Utils\hkIPlugin.h>

namespace hk
{
  extern "C"
  {
    HK_GRAPHICS_OPENGL_EXPORT IPlugin* createGraphicComponentOpenGLPlugin();
    HK_GRAPHICS_OPENGL_EXPORT void destroyGraphicComponentOpenGLPlugin();
  }

  class GraphicComponentOpenGL;

  /**
  * Provides connection from a PluginManager to a DLL services.
  *
  * Creates and provides access to a GraphicComponentOpenGL instance, also 
  * it delete and free its memory when the plug-in is about to close. note that
  * this object doesn't initialize the GraphicComponentOpenGL, instead a 
  * properly initialization is expected by the system that requires the
  * service.
  */
  class HK_GRAPHICS_OPENGL_EXPORT GraphicsOpengGLPlugin:
    public IPlugin
  {
  public:

    GraphicsOpengGLPlugin();

    ~GraphicsOpengGLPlugin();

    /**
     * Creates a GraphicComponentOpenGL instance;
     */
    virtual void
    onConnect() override;

    /**
    * Delete and free the memory utilized by the GraphicComponentOpenGL.
    */
    virtual void
    onClose() override;

    /**
    * Get a pointer to the GraphicComponentOpenGL instance.
    *
    * @return Pointer to the GraphicComponentOpenGL instance.
    */
    virtual void*
    getData() override;

  private:

    /**
    * Pointer to the Graphic Component Open GL.
    */
    GraphicComponentOpenGL*
    _m_pGraphicComponentOpenGL;
  };  
}