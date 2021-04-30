#pragma once

#include <Hakool\Utils\hkSharedPointer.h>

namespace hk
{
  template<typename T>
  inline void 
  SharedPointer<T>::Release(SharedPointer<T>& _sharedptr)
  {
    if (_sharedptr._m_pCounter != nullptr)
    {
      if (--_sharedptr._m_pCounter->counter <= 0)
      {
        delete _sharedptr._m_pCounter;
        _sharedptr._m_pCounter = nullptr;

        if (_sharedptr._m_pObject != nullptr)
        {
          delete _sharedptr._m_pObject;
          _sharedptr._m_pObject = nullptr;
        }
      }
    }
    else if(_sharedptr._m_pObject != nullptr)
    {
      delete _sharedptr._m_pObject;
      _sharedptr._m_pObject = nullptr;
    }

    return;
  }

  template<typename T>
  inline T* 
  SharedPointer<T>::Get(const SharedPointer<T>& _sharedptr)
  {
    return _sharedptr._m_pObject;
  }
  template<typename T>
  inline T** 
  SharedPointer<T>::GetAddress(const SharedPointer<T>& _sharedptr)
  {
    return &(_sharedptr._m_pObject);
  }

  template<typename T>
  inline bool 
  SharedPointer<T>::IsNull(const SharedPointer<T>& _sharedptr)
  {
    return _sharedptr._m_pObject == nullptr;
  }

  template<typename T>
  inline SharedPointer<T>::SharedPointer()
    : _m_pObject(nullptr),
      _m_pCounter(nullptr)
  {
    return;
  }

  template<typename T>
  inline SharedPointer<T>::SharedPointer(T* _obj)
    : _m_pObject(_obj)
  {
    _m_pCounter = new SharedPointerCounter();
    _m_pCounter->counter++;
    
    return;
  }

  template<typename T>
  inline SharedPointer<T>::SharedPointer(const SharedPointer<T>& _sharedptr)
    : _m_pCounter(nullptr),
    _m_pObject(nullptr)
  {
    if (!SharedPointer<T>::IsNull(*_sharedptr))
    {
      this->_m_pObject = _sharedptr._m_pObject;
      this->_m_pCounter = _sharedptr._m_pCounter;
      this->_m_pCounter->counter++;
    }

    return;
  }

  template<typename T>
  inline SharedPointer<T>::~SharedPointer()
  {
    SharedPointer<T>::Release(*this);
  }

  template<typename T>
  inline SharedPointer<T>& 
  SharedPointer<T>::operator=(const SharedPointer<T>& _sharedptr)
  {
    if (!SharedPointer<T>::IsNull(*_sharedptr) && this != &_sharedptr)
    {
      SharedPointer<T>::Release(*this);
      this->_m_pObject = _sharedptr._m_pObject;
      this->_m_pCounter = _sharedptr._m_pCounter;
      this->_m_pCounter->counter++:
    }

    return *this;
  }

  template<typename T>
  inline T& 
  SharedPointer<T>::operator*() const
  {
    return *(this->_m_pObject);
  }

  template<typename T>
  inline T* 
  SharedPointer<T>::operator->() const
  {
    return this->_m_pObject;
  }

  template<typename T>
  inline bool 
  SharedPointer<T>::operator==(const SharedPointer<T>& _sharedptr)
  {
    return this->_m_pObject == _sharedptr._m_pObject;
  }

  template<typename T>
  inline bool
  SharedPointer<T>::operator!=(const SharedPointer<T>& _sharedptr)
  {
    return this->_m_pObject != _sharedptr._m_pObject;
  }
}