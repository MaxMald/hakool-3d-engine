#pragma once

#include <Hakool\Utils\hkWindow.h>
#include <Hakool\Utils\hkConfigWindow.h>

namespace hk
{
  /**
  * TODO
  */
  class HK_UTILITY_EXPORT WindowWin32 :
    public Window
  {
  public:

    /**
    * 
    */
    WindowWin32();

    /**
    * 
    */
    virtual ~WindowWin32();

    /**
    * Creates a new window with the size and title specified.
    *
    * @param _width The width of the window.
    * @param _height The height of the window.
    * @param _title The title of the window.
    */
    virtual eRESULT
    init
    (
      const uint32& _width,
      const uint32& _height,
      const String& _title
    );

    /**
    * Close Window.
    */
    virtual void
    close();

    /**
    * Set the size of the rendering region of the window (pixels).
    *
    * @param _width The width in pixels.
    * @param _heiht The height in pixels.
    */
    virtual void
    setSize(const uint32& _width, const uint32& _height);

    /**
    * Set the size of the rendering region of the window (pixels).
    *
    * @param _width The width in pixels.
    * @param _heiht The height in pixels.
    */
    virtual void
    setSize(const Vector2u& _v2);

    /**
    * Set the title of this window.
    *
    * @para _title Window's title.
    */
    virtual void
    setTitle(const String& _title);

    /**
    * 
    */
    virtual void
    destroy() override;

    /**
    * 
    */
    static LRESULT CALLBACK
    WindowProc(HWND _hwnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam);

  protected:

    /**
    * 
    */
    virtual void
    _processEvents();

  private:

    /**
    * 
    */
    void
    _processEvent(UINT _uMsg, WPARAM _wParam, LPARAM _lParam);

    /**
    * 
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
  };
}