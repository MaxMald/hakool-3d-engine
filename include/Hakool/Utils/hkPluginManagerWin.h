#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>
#include <Hakool\Utils\hkIPluginManager.h>

#include <Windows.h>
#include <libloaderapi.h>

namespace hk
{
  /**
  * Manage different plug-ins.
  */
  class HK_UTILITY_EXPORT PluginManagerWin
    : public IPluginManager
  {
  public:

    PluginManagerWin();

    virtual
    ~PluginManagerWin();

    /**
    * Initialize the plug-in manager.
    */
    virtual void
    init() override;

    /**
    * Safely destroy this plug-in manager.
    */
    virtual void
    destroy() override;

    /**
    * Load a plug-in
    *
    * @param _key The plug-in key.
    *
    * @return
    */
    virtual eRESULT
    loadPlugin(const String & _key) override;

    /**
    * Unload a plug-in.
    *
    * @param _key The plug-in key.
    *
    * @return
    */
    virtual eRESULT
    unloadPlugin(const String & _key) override;

    /**
    * Unload all subscripted plug-in.
    */
    virtual void
    unloadAll() override;

    /**
    * Indicates if a plug-in exists in this plug-in manager.
    *
    * @param _key Plug-in key.
    *
    * @return True if the plug-in exists, otherwise returns false.
    */
    virtual bool
    hasPlugin(const String & _key) override;

    /**
    * Get the plug-in with the given key. A null pointer will be returned if
    * the plug-in doesn't exists.
    *
    * @param _key Plug-in key.
    *
    * @return The pointer of the plug-in. This could return a null pointer if
    * the plug-in doesn't exists.
    */
    virtual Plugin*
    getPlugin(const String & _key) override;

  private:

    /**
    * Store a list of library instances.
    */
    Map<String, HINSTANCE>
    _m_hLibraryMap;

    /**
    * Store a list of Plug-in instances.
    */
    Map<String, Plugin*> 
    _m_hPlugInMap;
  };
}