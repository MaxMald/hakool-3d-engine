#pragma once

#include <Hakool\Core\hkCorePrerequisites.h>
#include <Hakool\Core\hkCoreUtilities.h>

namespace hk
{
  class GameObject;
  class GraphicComponent;

  /**
  * Encapsulates a piece of logic that defines part of the behavior of the GameObject
  * which it belongs to.
  */
  class IGameObjectComponent
  {
  public:

    IGameObjectComponent() = default;

    virtual 
    ~IGameObjectComponent() = default;

    /**
    * Called when the GameObject is being initialized.
    */
    virtual void
    init(GameObject* _m_pGameObject) = 0;

    /**
    * Called every game cycle.
    */
    virtual void
    update() = 0;

    /**
     *
     */
    virtual void
    draw(GraphicComponent* pGraphicComponent) = 0;

    /**
    * Called when the GameObject is being destroyed.
    */
    virtual void
    destroy() = 0;

    /**
    * Get the component identifier.
    * 
    * @param eCOMPONENT.
    */
    virtual eCOMPONENT
    getID() = 0;

    /**
     * Get the GameObject.
     * 
     * @return Pointer to the GameObject which this component belongs to.
     */
    virtual GameObject*
    getGameObject() = 0;
  };
}