#pragma once

#include <Hakool\Utils\hkIWindow.h>

namespace hk
{
  /**
  * Windows 32 implementation for the window class.
  */
  class HK_UTILITY_EXPORT WindowWin32 : public IWindow
  {
  public:

    WindowWin32();

    virtual ~WindowWin32();

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
    pollEvents() override;

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

    static LRESULT CALLBACK
    WindowProc(HWND _hwnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam);

  protected:

    /**
    * Process each window events.
    */
    virtual void
    _processEvents();

  private:

    /**
    * Process a given event from the window.
    */
    void
    _processEvent(UINT _uMsg, WPARAM _wParam, LPARAM _lParam);

    /**
    * Register a window.
    */
    void
    _registerWindowClass();

    /**
    * The name that is used to register a window.
    */
    static String 
    _WINDOW_NAME;

    /**
    * Handle of the new window.
    */
    HANDLER 
    _m_winHandler;

    /**
    * Stores the callback event function of control.
    */
    LONG_PTR 
    _m_callback;

    /**
    * Indicates if the window is going to be closed.
    */
    bool
    _m_toClose;

    Vector2u 
    _m_size;

    Vector2u 
    _m_position;

    String
    _m_title;
  };
}