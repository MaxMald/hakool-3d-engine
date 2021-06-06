#include <Hakool\Utils\hkWindowWin32.h>

namespace hk
{
  String WindowWin32::_WINDOW_NAME = "Hakool_Window";

  WindowWin32::WindowWin32():
    _m_callback(NULL),
    _m_winHandler(NULL),
    _m_toClose(false)
  {
    return;
  }

  WindowWin32::~WindowWin32()
  {
    destroy();
    return;
  }

  eRESULT 
  WindowWin32::init(const WindowConfiguration& _config)
  {
    _registerWindowClass();

    _m_winHandler = CreateWindowA
    (
      WindowWin32::_WINDOW_NAME.c_str(),
      _config.title.c_str(),
      WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT,
      CW_USEDEFAULT,
      static_cast<int32>(_config.width),
      static_cast<int32>(_config.height),
      NULL,
      NULL,
      GetModuleHandle(NULL),
      this
    );

    if (_m_winHandler == NULL)
    {
      return eRESULT::kFail;
    }

    ShowWindow(this->_m_winHandler, SW_SHOWNORMAL);
    UpdateWindow(this->_m_winHandler);

    this->_m_size.x = _config.width;
    this->_m_size.y = _config.height;
    this->_m_title  = _config.title;

    return eRESULT::kSuccess;
  }

  void 
  WindowWin32::close()
  {
    if (!_m_callback)
    {
      if (_m_winHandler)
      {
        DestroyWindow(_m_winHandler);
        _m_winHandler = NULL;
      }

      UnregisterClassA(WindowWin32::_WINDOW_NAME.c_str(), GetModuleHandleW(NULL));
    }
    else
    {
      SetWindowLongPtrA(_m_winHandler, GWLP_WNDPROC, _m_callback);
    }

    return;
  }

  void 
  WindowWin32::setSize
  (
    const uint32& _width, 
    const uint32& _height
  )
  {
    this->_m_size.x = _width;
    this->_m_size.y = _height;

    return;
  }

  void 
  WindowWin32::setSize(const Vector2u& _v2)
  {
    this->_m_size = _v2;

    return;
  }

  void 
  WindowWin32::setTitle(const String& _title)
  {
    this->_m_title = _title;

    return;
  }

  bool 
  WindowWin32::isOpen()
  {
    return _m_winHandler != NULL;
  }

  void 
  WindowWin32::update()
  {
    if (_m_winHandler) 
    {
      this->_processEvents();
    }

    if (_m_toClose)
    {
      this->close();
    }

    return;
  }

  HANDLER 
  WindowWin32::getWindowHandler()
  {
      return _m_winHandler;
  }

  void
  WindowWin32::destroy()
  {
    this->close();

    return;
  }

  LRESULT 
  WindowWin32::WindowProc(HWND _hwnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam)
  {
    if (_uMsg == WM_CREATE)
    {
      LONG_PTR pWindow = (LONG_PTR)reinterpret_cast<CREATESTRUCTA*>(_lParam)->lpCreateParams;
      SetWindowLongPtrA(_hwnd, GWLP_USERDATA, pWindow);
    }

    WindowWin32* pWindow32 = _hwnd ? reinterpret_cast<WindowWin32*>(GetWindowLongPtr(_hwnd, GWLP_USERDATA)) : NULL;

    if (pWindow32)
    {
      pWindow32->_processEvent(_uMsg, _wParam, _lParam);

      if (pWindow32->_m_callback)
      {
        return CallWindowProcA
        (
          reinterpret_cast<WNDPROC>(pWindow32->_m_callback), 
          _hwnd,
          _uMsg,
          _wParam, 
          _lParam
        );
      }
    }

    if (_uMsg == WM_CLOSE)
    {
      if (pWindow32)
      {
        pWindow32->_m_toClose = true;
      }

      return 0;
    }

    if ((_uMsg == WM_SYSCOMMAND) && (_wParam == SC_KEYMENU))
    {
      return 0;
    }

    return DefWindowProcA(_hwnd, _uMsg, _wParam, _lParam);
  }

  void 
  WindowWin32::_processEvents()
  {
    if (!_m_callback)
    {
      MSG message;
      while (PeekMessageW(&message, NULL, 0, 0, PM_REMOVE))
      {
        TranslateMessage(&message);
        DispatchMessageW(&message);
      }
    }

    return;
  }

  void 
  WindowWin32::_processEvent(UINT _uMsg, WPARAM _wParam, LPARAM _lParam)
  {
    if (this->_m_winHandler == NULL)
    {
      return;
    }

    switch (_uMsg)
    {
      case WM_DESTROY:
        // TODO.
        break;

      case WM_SETCURSOR:
        // TODO.
        break;

      case WM_CLOSE:
        this->close();

        break;

      case WM_SIZE:
        // TODO.
        break;

      case WM_ENTERSIZEMOVE:
        // TODO.
        break;

      case WM_EXITSIZEMOVE:
        // TODO.
        break;

      case WM_GETMINMAXINFO:
        // TODO.
        break;

      case WM_SETFOCUS:
        // TODO.
        break;

      case WM_KILLFOCUS:
        // TODO.
        break;

      case WM_CHAR:
        // TODO.
        break;

      case WM_KEYDOWN:
      case WM_SYSKEYDOWN:
        // TODO.
        break;

      case WM_KEYUP:
      case WM_SYSKEYUP:
        // TODO.
        break;

      case WM_MOUSEWHEEL:
        // TODO.
        break;

      case WM_MOUSEHWHEEL:
        // TODO.
        break;

      case WM_LBUTTONDOWN:
        // TODO.
        break;

      case WM_LBUTTONUP:
        // TODO.
        break;

      case WM_RBUTTONDOWN:
        // TODO.
        break;

      case WM_RBUTTONUP:
        // TODO.
        break;

      case WM_MBUTTONDOWN:
        // TODO.
        break;

      case WM_MBUTTONUP:
        // TODO.
        break;

      case WM_XBUTTONDOWN:
        // TODO.
        break;

      case WM_XBUTTONUP:
        // TODO.
        break;

      case WM_MOUSELEAVE:
        // TODO.
        break;

      case WM_MOUSEMOVE:
        // TODO.
        break;

      case WM_DEVICECHANGE:
        // TODO.
        break;
    }

    return;
  }

  void
  WindowWin32::_registerWindowClass()
  {
    WNDCLASSA windowClass     = { 0 };

    windowClass.style         = 0;
    windowClass.cbClsExtra    = 0;
    windowClass.cbWndExtra    = 0;
    windowClass.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    windowClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
    windowClass.lpszMenuName  = NULL;
    windowClass.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
    windowClass.lpfnWndProc   = &WindowWin32::WindowProc;
    windowClass.hInstance     = GetModuleHandleA(NULL);
    windowClass.lpszClassName = WindowWin32::_WINDOW_NAME.c_str();
    
    RegisterClassA(&windowClass);

    return;
  }
}