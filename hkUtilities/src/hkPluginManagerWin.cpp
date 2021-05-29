#include <Hakool\Utils\hkIPluginManager.h>
#include <Hakool\Utils\hkPluginManagerWin.h>
#include <Hakool\Utils\hkPlugin.h>

namespace hk
{
  typedef Plugin* (*fnCreatePlugin)(void);
  typedef void (*fnDestroyPlugin)(void);

  PluginManagerWin::PluginManagerWin()
  {
    return;
  }

  PluginManagerWin::~PluginManagerWin()
  {
    return;
  }

  void 
  PluginManagerWin::init()
  {
    return;
  }

  void 
  PluginManagerWin::destroy()
  {
    this->unloadAll();
    return;
  }

  eRESULT 
  PluginManagerWin::loadPlugin(const String& _key)
  {
    if (this->hasPlugin(_key)) 
    {
      return eRESULT::kObjectAlreadyExists;
    }

    HINSTANCE dllHandle = LoadLibraryEx(_key.c_str(), 
                                        0, 
                                        LOAD_WITH_ALTERED_SEARCH_PATH);
    if (dllHandle == NULL)
    {
      return eRESULT::kFail;
    }

    fnCreatePlugin constructorFunction = reinterpret_cast<fnCreatePlugin>(
                                        GetProcAddress(dllHandle, "createPlugin"));
    if (!constructorFunction)
    {
      !FreeLibrary(dllHandle);
      return eRESULT::kFail;
    }

    Plugin* plugInPtr = nullptr;
    plugInPtr = constructorFunction();
    if (plugInPtr == nullptr)
    {
      !FreeLibrary(dllHandle);
      return eRESULT::kFail;
    }

    plugInPtr->init();

    this->_m_hLibraryMap.insert
    (
      Map<String, HINSTANCE>::value_type(_key, dllHandle)
    );
    this->_m_hPlugInMap.insert
    (
      Map<String, Plugin*>::value_type(_key, plugInPtr)
    );

    return eRESULT::kSuccess;
  }

  eRESULT 
  PluginManagerWin::unloadPlugin(const String& _key)
  {
    if (!this->hasPlugin(_key))
    {
      return eRESULT::kObjectNotFound;
    }

    Plugin* plugInPtr = this->_m_hPlugInMap[_key];
    plugInPtr->destroy();

    HINSTANCE dllHandle = this->_m_hLibraryMap[_key];
    fnDestroyPlugin destructionFunction = reinterpret_cast<fnDestroyPlugin>(
                                            dllHandle,
                                            "destroyPlugin"
                                          );
    if (!destructionFunction)
    {
      destructionFunction();
    }

    !FreeLibrary(dllHandle);

    this->_m_hLibraryMap.erase(_key);
    this->_m_hPlugInMap.erase(_key);

    return eRESULT::kSuccess;
  }

  void 
  PluginManagerWin::unloadAll()
  {
    for (auto iterator : this->_m_hPlugInMap)
    {
      iterator.second->destroy();
    }

    for (auto iterator : this->_m_hLibraryMap)
    {
      fnDestroyPlugin destructionFunction = reinterpret_cast<fnDestroyPlugin>(
                                            iterator.second,
                                            "destroyPlugin"
                                            );
      if (!destructionFunction)
      {
        destructionFunction();
      }

      !FreeLibrary(iterator.second);
    }

    this->_m_hLibraryMap.clear();
    this->_m_hPlugInMap.clear();

    return;
  }

  bool 
  PluginManagerWin::hasPlugin(const String& _key)
  {
    return (this->_m_hPlugInMap.find(_key) != this->_m_hPlugInMap.end());
  }

  Plugin* 
  PluginManagerWin::getPlugin(const String& _key)
  {
    auto iterator = this->_m_hPlugInMap.find(_key);
    return iterator->second;
  }
}