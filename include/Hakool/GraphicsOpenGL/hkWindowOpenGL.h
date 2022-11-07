#pragma once

#include <Hakool/Utils/hkUtilitiesUtilities.h>
#include <Hakool/Utils/hkIWindow.h>
#include <Hakool/GraphicsOpenGL/hkGraphicsOpenGLPrerequisites.h>

struct GLFWwindow;

namespace hk
{
  class HK_GRAPHICS_OPENGL_EXPORT WindowOpenGL : public IWindow
  {
  public:

    WindowOpenGL();

    virtual ~WindowOpenGL();

    virtual eRESULT
    init(const WindowConfiguration& _config) override;

    virtual void
    setSize(const uint32& _width, const uint32& _height) override;

    virtual void
    setSize(const Vector2u& _v2) override;

    virtual void
    setTitle(const String& _title) override;

    virtual bool
    isOpen() override;

    virtual void
    update() override;

    virtual void
    postUpdate() override;

    virtual void
    present() override;

    virtual HANDLER
    getWindowHandler() override;

    virtual void
    destroy() override;

    virtual void
    addObserver(const WindowObserver* pObserver) override;

    virtual Vector2u
    getSize() override;

    virtual uint32
    getWidth() override;

    virtual uint32
    getHeight() override;

    virtual String
    getTitle() override;

  private:

    GLFWwindow*
    _m_pWindow;

    Vector<const WindowObserver*> 
    _m_observers;

    String
    _m_title;
  };
}