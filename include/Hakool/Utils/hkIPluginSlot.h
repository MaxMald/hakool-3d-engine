#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>
#include <Hakool\Utils\hkUtilitiesUtilities.h>

namespace hk
{
  class IPlugin;

  /**
  * A plug-in slot manage the connection and disconnection of an individual 
  * plug-in.
  */
  class HK_UTILITY_EXPORT IPluginSlot
  {
  public:

    IPluginSlot() = default;

    virtual
    ~IPluginSlot() = default;

    /**
    * Attempts to connect to the specified plug-in.
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
    ) = 0;

    /**
    * Get the identifier of this Plug-in slot.
    * 
    * @return The identifier of this Plug-in slot.
    */
    virtual String
    getKey() = 0;

    /**
    * Get the pointer of the wrapped plug-in.
    * 
    * @return The wrapped plug-in's pointer.
    */
    virtual IPlugin*
    getPluginPtr() = 0;

    /**
    * Safely disconnect this plug-in.
    */
    virtual void
    close() = 0;
  };
}