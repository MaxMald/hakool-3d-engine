#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>
#include <Hakool\Utils\hkUtilitiesUtilities.h>
#include <Hakool\Utils\hkIPluginSlot.h>

#include <Windows.h>
#include <libloaderapi.h>

namespace hk
{
  class IPlugin;

  class HK_UTILITY_EXPORT PluginSlotWin: 
    public IPluginSlot
  {
  public:
    
    PluginSlotWin();

    virtual
    ~PluginSlotWin();

    /**
    * Attempts to connect to the plug-in slot.
    *
    * @param _key The identifier of this plug-in.
    * @param _constructorFunctionName The name of the function that builds the
    * plug-in.
    * @param _destructorFunctionName The name of the function that destroys the
    * plug-in.
    * 
    * @return 
    */
    virtual eRESULT
    connect
    (
      const String& _key,
      const String& _constructorFunctionName,
      const String& _destructorFunctionName
    ) override;

    /**
    * Get the identifier of this Plug-in.
    */
    virtual String
    getKey() override;

    /**
    * Get the pointer of the wrapped plug-in.
    *
    * @return The wrapped plug-in's pointer.
    */
    virtual IPlugin*
    getPluginPtr() override;

    /**
    * Safely close this plug-in.
    */
    virtual void
    close() override;

  private:

    /**
    * The name of the constructor function.
    */
    String
    _m_constructorFunctionName;

    /**
    * The name of the destructor function.
    */
    String
    _m_destructorFunctionName;

    /**
    * The Plug-in's key.
    */
    String
    _m_key;

    /**
    * The instance of the plug-in.
    */
    HINSTANCE
    _m_pluginHandler;

    /**
    * Pointer of the hakool Plug-in interface.
    */
    IPlugin*
    _m_hakoolPluginPtr;

    /**
    * Indicates if the plug-in slot is connected.
    */
    bool
    _m_isConnected;
  };
}