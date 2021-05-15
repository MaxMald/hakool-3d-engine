#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>

namespace hk
{
  /**
  * Provides methods to write messages. 
  *
  * The Logger gives an abstract layer over the platform specific logger, so 
  * the engine can log messages no matter what platform it is on.
  */
  class HK_UTILITY_EXPORT Logger
  {
  public:

    Logger() = default;

    virtual
    ~Logger() = default;

    /**
    * Get the logger instance pointer.
    * 
    * @returns The logger instance pointer.
    */
    static Logger*
    Get();

    /**
    * Get the logger instance reference.
    * 
    * @returns The logger instance reference.
    */
    static Logger&
    GetReference();

    /**
    * Creates and prepares the logger module.
    */
    static void
    Prepare();

    /**
    * Prepares the logger module with the given Logger instance pointer.
    * 
    * @param _pLogger The logger instance.
    */
    static void
    Prepare(Logger* _pLogger);

    /**
    * Shutdown the logger module.
    */
    static void
    Shutdown();

    /**
    * Indicates if the logger has been prepared and is ready to be used.
    * 
    * @returns True if the logger is ready to be used. False if the logger has
    * not been initialized.
    */
    static bool
    IsReady();

    /**
    * Log a message.
    * 
    * @param _msg Message.
    */
    virtual void
    log(String _msg);

    /**
    * Log a message.
    *
    * @param _msg Message.
    * @param _filename The name of the file where the log is called.
    */
    virtual void
    log(String _msg, String _filename);

    /**
    * Logs a warning message.
    * 
    * @param _msg Warning message.
    */
    virtual void
    warning(String _msg);

    /**
    * Log a warning message.
    *
    * @param _msg Warning message.
    * @param _filename The name of the file where the log is called.
    */
    virtual void
    warning(String _msg, String _filename);

    /**
    * Log an error message.
    *
    * @param _msg Error message.
    */
    virtual void
    error(String _msg);

    /**
    * Log an error message.
    *
    * @param _msg Error message.
    * @param _filename The name of the file where the log is called.
    */
    virtual void
    error(String _msg, String _filename);

  protected:

    /**
    * Called when the logger is being prepared.
    */
    virtual void
    _onPrepare();

    /**
    * Called when the logger is being shutdown.
    */
    virtual void
    _onShutdown();    

    Logger(Logger&&) = delete;

    Logger&
    operator=(Logger&&) = delete;

    Logger&
    operator=(const Logger&&) = delete;

  private:    

    /**
    * Get the logger singleton.
    * 
    * @returns Logger singleton.
    */
    static Logger*&
    _Singleton();

    /**
    * Get the "isReady" boolean reference.
    * 
    * @returns The "isReady" boolean reference.
    */
    static bool&
    _IsReady();           
  };
}