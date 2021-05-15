#pragma once

#include <Hakool\Utils\hkLogger.h>

namespace hk
{
  /**
  * Logs message for a console application.
  */
  class HK_UTILITY_EXPORT LoggerConsole
    : public Logger
  {
  public:

    /**
    * Constructor.
    */
    LoggerConsole() = default;

    /**
    * Destructor.
    */
    virtual
    ~LoggerConsole() = default;

    /**
    * Logs a new message.
    */
    void
    log(String _msg) override;

    /**
    * Logs a new message.
    */
    void
    log(String _msg, String _filename) override;

    /**
    * Logs a warning message.
    */
    void
    warning(String _msg) override;

    /**
    * Logs a warning message.
    */
    void
    warning(String _msg, String _filename) override;

    /**
    * Logs an error message.
    */
    void
    error(String _msg) override;

    /**
    * Logs an error message.
    */
    void
    error(String _msg, String _filename) override;

  protected:

    /**
    * Prepares the console logger.
    */
    void
    _onPrepare() override;

    /**
    * Shutdowns the console logger.
    */
    void
    _onShutdown() override;
  };
}