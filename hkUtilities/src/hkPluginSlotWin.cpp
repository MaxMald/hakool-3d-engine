#include <Hakool\Utils\hkPluginSlotWin.h>

#include <Hakool\Utils\hkIPlugin.h>

namespace hk
{
  typedef IPlugin* (*fnCreatePlugin)(void);
  typedef void (*fnDestroyPlugin)(void);

  PluginSlotWin::PluginSlotWin():
    _m_constructorFunctionName(""),
    _m_destructorFunctionName(""),
    _m_hakoolPluginPtr(nullptr),
    _m_pluginHandler(),
    _m_isConnected(false)
  {
    return;
  }

  PluginSlotWin::~PluginSlotWin()
  {
    if (this->_m_isConnected)
    {
      this->close();
    }

    return;
  }

  eRESULT
  PluginSlotWin::connect
  (
    const String& _key, 
    const String& _constructorFunctionName, 
    const String& _destructorFunctionName
  )
  {   
    if(this->_m_isConnected)
    {
      return eRESULT::kFail;
    }

    HINSTANCE pluginHandle = LoadLibraryEx(_key.c_str(),
                                           0,
                                           LOAD_WITH_ALTERED_SEARCH_PATH);
    if(pluginHandle == NULL)
    {
      return eRESULT::kFail;
    }

    FARPROC proc = GetProcAddress(pluginHandle, _constructorFunctionName.c_str());
    if (proc == NULL)
    {
      FreeLibrary(pluginHandle);
      return eRESULT::kFail;
    }

    fnCreatePlugin constructorFunction = reinterpret_cast<fnCreatePlugin>(proc);
    IPlugin* pluginPtr = constructorFunction();
    if (pluginPtr == nullptr)
    {
      FreeLibrary(pluginHandle);
      return eRESULT::kFail;
    }
    pluginPtr->onConnect();

    this->_m_key = _key;
    this->_m_constructorFunctionName = _constructorFunctionName;
    this->_m_destructorFunctionName = _destructorFunctionName;
    this->_m_pluginHandler = pluginHandle;
    this->_m_hakoolPluginPtr = pluginPtr;

    this->_m_isConnected = !this->_m_isConnected;

    return eRESULT::kSuccess;
  }

  String 
  PluginSlotWin::getKey()
  {
    return this->_m_key;
  }

  IPlugin* 
  PluginSlotWin::getPluginPtr()
  {
    return this->_m_hakoolPluginPtr;
  }

  void
  PluginSlotWin::close()
  {
    if (this->_m_isConnected)
    {
      this->_m_hakoolPluginPtr->onClose();

      delete this->_m_hakoolPluginPtr;
      this->_m_hakoolPluginPtr = nullptr;

      FARPROC proc = GetProcAddress
      (
        this->_m_pluginHandler, 
        this->_m_destructorFunctionName.c_str()
      );
      if (proc != NULL)
      {
        fnDestroyPlugin destructionFunction = reinterpret_cast<fnDestroyPlugin>(proc);
        destructionFunction();
      }

      FreeLibrary(this->_m_pluginHandler);
      this->_m_isConnected = !this->_m_isConnected;
    }

    return;
  }
}