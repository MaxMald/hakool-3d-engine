#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>
#include <Hakool\Utils\hkUtilitiesUtilities.h>

namespace hk
{
  class IPlugin;
  class IPluginSlot;

  /**
  * Manage different plug-ins.
  */
  class HK_UTILITY_EXPORT PluginManager
  {
  public:

    PluginManager();

    ~PluginManager();

    /**
    * Initialize the plug-in manager.
    */
    void
    init();

    /**
    * Safely destroy this plug-in manager.
    */
    void
    destroy();

    /**
    * Attempts to connect to the specified plug-in.
    * 
    * @param _key The plug-in key.
    * @param _libraryName The library name of the plug-in.
    * @param _constructorFunctionName The name of the function that builds the
    * plug-in.
    * @param _destructorFunctionName The name of the function that destroys the
    * plug-in.
    * 
    * @return
    */
    eRESULT
    connectPlugin
    (
      const String& _key,
      const String& _libraryName,
      const String& _constructorFunctionName,
      const String& _destructorFunctionName
    );

    /**
    * Unload a plug-in.
    * 
    * @param _key The plug-in key.
    * 
    * @return
    */
    eRESULT
    closePlugin(const String& _key);

    /**
    * Disconnect all plug-ins.
    */
    void
    closeAll();

    /**
    * Indicates if a plug-in exists in this plug-in manager.
    * 
    * @param _key Plug-in key.
    * 
    * @return True if the plug-in exists, otherwise returns false.
    */
    bool
    hasPlugin(const String& _key);

    /**
    * Get the plug-in with the given key. A null pointer will be returned if 
    * the plug-in doesn't exists.
    * 
    * @param _key Plug-in key.
    * 
    * @return The pointer of the plug-in. This could return a null pointer if 
    * the plug-in doesn't exists.
    */
    IPlugin*
    getPlugin(const String& _key);

  private:

    PluginManager&
    operator=(const PluginManager&) = delete;

    /**
    * Create a plug-in slot instance, corresponding to the actual platform.
    * 
    * @return Pointer to a new plug-in slot instance.
    */
    IPluginSlot*
    createPluginSlot();

    /**
    * Table of plug-in slots.
    */
    Map<String, IPluginSlot*> _m_hPluginSlots;
  };
}