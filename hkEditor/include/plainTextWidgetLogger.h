#pragma once

#include <Hakool/Utils/hkLogger.h>

namespace hk
{
  class PlainTextWidgetLogger : public Logger
  {
  public:

    /**
     * Constructor.
     */
    PlainTextWidgetLogger();

    /**
     * Destructor.
     */
    ~PlainTextWidgetLogger();

    /**
      * Log a message.
      *
      * @param _msg Message.
      */
    virtual void
    log(const String& _msg) override;

    /**
    * Log a message.
    *
    * @param _msg Message.
    * @param _filename The name of the file where the log is called.
    */
    virtual void
    log(const String& _msg, const String& _filename) override;

    /**
    * Logs a warning message.
    *
    * @param _msg Warning message.
    */
    virtual void
    warning(const String& _msg) override;

    /**
    * Log a warning message.
    *
    * @param _msg Warning message.
    * @param _filename The name of the file where the log is called.
    */
    virtual void
    warning(const String& _msg, const String& _filename) override;

    /**
    * Log an error message.
    *
    * @param _msg Error message.
    */
    virtual void
    error(const String& _msg) override;

    /**
    * Log an error message.
    *
    * @param _msg Error message.
    * @param _filename The name of the file where the log is called.
    */
    virtual void
    error(const String& _msg, const String& _filename) override;
  };
}