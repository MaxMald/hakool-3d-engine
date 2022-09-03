#pragma once

#include <Hakool\Core\hkCorePrerequisites.h>
#include <Hakool\Core\hkCoreUtilities.h>

namespace hk
{
  class GameObject;

  /**
  * TODO
  */
  class HK_CORE_EXPORT Component
  {
  public:

    /**
    * Constructor.
    */
    Component();

    /**
    * TODO.
    */
    Component(const eCOMPONENT& _m_id);

    /**
    * Destructor.
    */
    virtual ~Component();

    /**
    * Called when the game object is been created.
    */
    virtual void
    create();

    /**
    * Called when the game object is been initialized.
    */
    virtual void
    init();

    /**
    * Called every game cycle.
    */
    virtual void
    update();

    /**
    * Called when the game object is been destroyed.
    */
    virtual void
    destroy();

    /**
    * Get the component identifier.
    */
    eCOMPONENT
    getID();

  protected:

    /**
    * Pointer to the game object which this component belongs.
    */
    GameObject*
    _m_pGameObject;

    /**
    * Component identifier.
    */
    eCOMPONENT
    _m_id;

    friend GameObject;
  };
}