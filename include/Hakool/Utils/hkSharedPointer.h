#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>

namespace hk
{  
  /**
  * Keeps track of the number of pointer references that are being used.
  */
  struct SharedPointerCounter
  {
  public:
    SharedPointerCounter()
      : counter(0)
    {
      return;
    }

    ~SharedPointerCounter()
    {
      return;
    }

    /**
    * Indicates the number of pointer references that are being used.
    */
    uint32 counter;
  };
 
  /**
  * Smart pointer using a reference counter to determine when the object is no
  * longer needed.
  * 
  * Encapsulates a pointer and override standard pointer operations. Provides 
  * control on construction, destruction, copying, moving and dereferencing.
  */

  template<typename T>
  class SharedPointer
  {
  public:

    /**
    * Create a new shared pointer that initially wraps to a null pointer.
    */
    SharedPointer();

    /**
    * Create a new shared pointer from the given raw pointer. The new shared
    * pointer will wraps the given pointer.
    */
    explicit SharedPointer(T* _obj);

    /**
    * Copy constructor.
    */
    SharedPointer(const SharedPointer<T>& _sharedptr);

    /**
    * Destructor.
    */
    ~SharedPointer();

    /**
    * Unlink the given shared pointer from its wrapped pointer. The shared 
    * pointer will wraps a null pointer.
    * 
    * @param _sharedptr Shared pointer.
    */
    static void
    Release(SharedPointer<T>& _sharedptr);

    /**
    * Get the wrapped pointer of the given shared pointer.
    * 
    * @param _sharedptr Shared pointer.
    * 
    * @return Wrapped pointer.
    */
    static T*
    Get(const SharedPointer<T>& _sharedptr);

    /**
    * Get the address of the wrapped pointer of the given shared pointer.
    * 
    * @param _sharedptr Shared pointer.
    * 
    * @return Address of the wrapped pointer.
    */
    static T**
    GetAddress(const SharedPointer<T>& _sharedptr);

    /**
    * Indicates it the shared pointer wraps a null pointer.
    * 
    * @param _sharedptr Shared pointer.
    * 
    * @return True if the wrapped pointer is a null pointer, otherwise returns
    * false.
    */
    static bool
    IsNull(const SharedPointer<T>& _sharedptr);   

    /**
    * Assigns the shared pointer.
    */
    SharedPointer<T>&
    operator=(const SharedPointer<T>& _sharedptr);
    
    /**
    * Dereferences the stored pointer.
    */
    T&
    operator*() const;

    /**
    * Dereferences the stored pointer.
    */
    T*
    operator->() const;

    /**
    * Checks if the pointers reference to the same object.
    */
    bool
    operator==(const SharedPointer<T>& _sharedptr) const;

    /**
    * Checks if the pointers reference to different object.
    */
    bool
    operator!=(const SharedPointer<T>& _sharedptr) const;

  private:

    /**
    * Wrapped pointer
    */
    T* _m_pObject;

    /**
    * Keeps track of the number of pointer references that are being used.
    */
    SharedPointerCounter* _m_pCounter;
  };

  template<typename T>
  inline void
  SharedPointer<T>::Release(SharedPointer<T>& _sharedptr)
  {
    if (_sharedptr._m_pCounter != nullptr)
    {
      if (--_sharedptr->_m_pCounter->counter <= 0)
      {
        delete _sharedptr->_m_pCounter;
        delete _sharedptr->_m_pObject;
      }

      _sharedptr->_m_pCounter = nullptr;
      _sharedptr->_m_pObject = nullptr;
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
  inline SharedPointer<T>::SharedPointer() : 
    _m_pObject(nullptr),
    _m_pCounter(nullptr)
  {
    return;
  }

  template<typename T>
  inline SharedPointer<T>::SharedPointer(T* _obj)
  {
    if (_obj != nullptr)
    {
      this->_m_pObject = _obj;
      this->_m_pCounter = new SharedPointerCounter();
      this->_m_pCounter->counter++;
    }

    return;
  }

  template<typename T>
  inline SharedPointer<T>::SharedPointer(const SharedPointer<T>& _sharedptr)
  {
    this->_m_pObject = _sharedptr._m_pObject;
    this->_m_pCounter = _sharedptr._m_pCounter;

    if (this->_m_pCounter != nullptr) 
    {
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
    if (_sharedptr._m_pCounter == this->_m_pCounter)
    {
      return *this;
    }

    SharedPointer<T>::Release(*this);

    this->_m_pObject = _sharedptr._m_pObject;
    this->_m_pCounter = _sharedptr._m_pCounter;

    if (this->_m_pCounter != nullptr)
    {
      this->_m_pCounter->counter++;
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
  SharedPointer<T>::operator==(const SharedPointer<T>& _sharedptr) const
  {
    return this->_m_pObject == _sharedptr._m_pObject;
  }

  template<typename T>
  inline bool
  SharedPointer<T>::operator!=(const SharedPointer<T>& _sharedptr) const
  {
    return this->_m_pObject != _sharedptr._m_pObject;
  }
}
