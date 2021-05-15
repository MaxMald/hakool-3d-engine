#pragma once

#include <Hakool\Utils\hkLoggerConsole.h>

using std::cout;

namespace hk
{
  void 
  LoggerConsole::log(String _msg)
  {
    cout << _msg << '\n';
    return;
  }

  void 
  LoggerConsole::log(String _msg, String _filename)
  {
    cout << "File: " + _filename + ": " + _msg + '\n';
    return;
  }

  void 
  LoggerConsole::warning(String _msg)
  {
    cout << "|WARNING| " + _msg + '\n';
    return;
  }

  void 
  LoggerConsole::warning(String _msg, String _filename)
  {
    cout << "|WARNING| File: " + _filename + ": " + _msg + '\n';
    return;
  }

  void 
  LoggerConsole::error(String _msg)
  {
    cout << "|ERROR| " + _msg + '\n';
    return;
  }

  void 
  LoggerConsole::error(String _msg, String _filename)
  {
    cout << "|ERROR| File: " + _filename + ": " + _msg + '\n';
    return;
  }

  void 
  LoggerConsole::_onPrepare()
  {
    return;
  }

  void 
  LoggerConsole::_onShutdown()
  {
    return;
  }
}