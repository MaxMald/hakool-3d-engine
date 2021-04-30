#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>

namespace hk
{  
  /**
  * Tracks the number of references that belongs to pointer's object.
  */
  struct SharedPointerCounter
  {
  public:

    /**
    * Constructor.
    */
    SharedPointerCounter()
      : counter(0)
    {
    }

    /**
    * Destructor.
    */
    ~SharedPointerCounter()
    {
    }

    /**
    * Tracks the number of references that belongs to the pointer's object.
    */
    uint32 counter;
  };

  template<typename T>
  class HK_UTILITY_EXPORT SharedPointer
  {
  public:

    static void
    Release(SharedPointer<T>& _sharedptr);

    static T*
    Get(const SharedPointer<T>& _sharedptr);

    static T**
    GetAddress(const SharedPointer<T>& _sharedptr);

    static bool
    IsNull(const SharedPointer<T>& _sharedptr);

    SharedPointer();

    explicit SharedPointer(T* _obj);

    SharedPointer(const SharedPointer<T>& _sharedptr);

    ~SharedPointer();

    SharedPointer<T>&
    operator=(const SharedPointer<T>& _sharedptr);
    
    T&
    operator*() const;

    T*
    operator->() const;

    bool
    operator==(const SharedPointer<T>& _sharedptr);

    bool
    operator!=(const SharedPointer<T>& _sharedptr);

  private:

    /**
    * Pointer to the wrapped object.
    */
    T* _m_pObject;

    /**
    * Counter of references that belongs to the wrapped objects.
    */
    SharedPointerCounter* _m_pCounter;
  };

#include <Hakool\Utils\hkSharedPointer.inl>
}
