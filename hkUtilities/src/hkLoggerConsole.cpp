#pragma once

#include <Hakool\Utils\hkLoggerConsole.h>

using std::cout;

namespace hk
{
  void 
  LoggerConsole::log(const String& _msg)
  {
    cout << _msg << '\n';
    return;
  }

  void 
  LoggerConsole::log(const String& _msg, const String& _filename)
  {
    cout << "File: " + _filename + ": " + _msg + '\n';
    return;
  }

  void 
  LoggerConsole::warning(const String& _msg)
  {
    cout << "|WARNING| " + _msg + '\n';
    return;
  }

  void 
  LoggerConsole::warning(const String& _msg, const String& _filename)
  {
    cout << "|WARNING| File: " + _filename + ": " + _msg + '\n';
    return;
  }

  void 
  LoggerConsole::error(const String& _msg)
  {
    cout << "|ERROR| " + _msg + '\n';
    return;
  }

  void 
  LoggerConsole::error(const String& _msg, const String& _filename)
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