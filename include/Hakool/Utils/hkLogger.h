#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>

namespace hk
{
  class HK_UTILITY_EXPORT Logger
  {
  public:

    /**
    * Get the pointer to this logger.
    */
    static Logger*
    Get();

    /**
    * Get the reference of this module.
    */
    static Logger&
    GetReference();

    static void
    Prepare();

    static void
    Shutdown();

    static bool
    IsReady();

    void
    log(String _msg);

    void
    log(String _msg, String _filename);

    void
    warning(String _msg);

    void
    warning(String _msg, String _filename);

    void
    error(String _msg);

    void
    error(String _msg, String _filename);

  private:

    static Logger*&
    _Singleton();

    static bool&
    _IsReady();

    Logger() = default;

    ~Logger() = default;

    Logger(Logger&&) = delete;

    Logger&
    operator=(Logger&&) = delete;

    Logger&
    operator=(const Logger&&) = delete;

    void
    _onPrepare();

    void
    _onShutdown();    
  };
}