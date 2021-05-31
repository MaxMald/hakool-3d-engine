#include <Hakool\Utils\hkPluginManager.h>

#if HK_PLATFORM == HK_PLATFORM_WIN32
#include <Hakool\Utils\hkPluginSlotWin.h>
#endif

namespace hk
{
  PluginManager::PluginManager()
  {
    return;
  }

  PluginManager::~PluginManager()
  {
    this->destroy();
    return;
  }

  void 
  PluginManager::init()
  {
    return;
  }

  void 
  PluginManager::destroy()
  {
    this->closeAll();
    return;
  }

  eRESULT 
  PluginManager::connectPlugin
  (
    const String& _key, 
    const String& _libraryName,
    const String& _constructorFunctionName, 
    const String& _destructorFunctionName
  )
  {
    if (this->hasPlugin(_key)) {
      return eRESULT::kObjectAlreadyExists;
    }

    IPluginSlot* pPluginSlot = this->createPluginSlot();
    eRESULT result = pPluginSlot->connect
    (
      _key,
      _libraryName,
      _constructorFunctionName, 
      _destructorFunctionName
    );

    if (result != eRESULT::kSuccess)
    {
      delete pPluginSlot;
      return result;
    }

    this->_m_hPluginSlots.insert
    (
      Map<String, IPluginSlot*>::value_type(_key, pPluginSlot)
    );

    return result;
  }

  eRESULT 
  PluginManager::closePlugin(const String& _key)
  {
    if (!this->hasPlugin(_key))
    {
      return eRESULT::kObjectNotFound;
    }

    IPluginSlot* pPluginSlot = this->_m_hPluginSlots.find(_key)->second;
    pPluginSlot->close();
    delete pPluginSlot;

    this->_m_hPluginSlots.erase(_key);

    return eRESULT::kSuccess;
  }

  void 
  PluginManager::closeAll()
  {
    for (auto iterator : this->_m_hPluginSlots)
    {
      IPluginSlot* pPluginSlot = iterator.second;
      pPluginSlot->close();
      delete pPluginSlot;
    }
    this->_m_hPluginSlots.clear();

    return;
  }

  bool 
  PluginManager::hasPlugin(const String& _key)
  {
    return this->_m_hPluginSlots.find(_key) != this->_m_hPluginSlots.end();
  }

  IPlugin* 
  PluginManager::getPlugin(const String& _key)
  {
    auto iterator = this->_m_hPluginSlots.find(_key);
    return iterator->second->getPluginPtr();
  }

#if HK_PLATFORM == HK_PLATFORM_WIN32
  
  IPluginSlot* 
  PluginManager::createPluginSlot()
  {
    return new PluginSlotWin();
  }

#else

  IPluginSlot*
  PluginManager::createPluginSlot()
  {
    throw "There is no implementation for this platform type.";
  }

#endif
}