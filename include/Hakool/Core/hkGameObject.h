#pragma once

#include <Hakool\Utils\hkUtilitiesUtilities.h>
#include <Hakool\Utils\hkLogger.h>

#include <Hakool\Core\hkCorePrerequisites.h>
#include <Hakool\Core\hkCoreUtilities.h>
#include <Hakool\Core\hkComponent.h>
#include <Hakool\Core\hkNode.h>

namespace hk
{
  class Scene;

  /**
  * Base class for any entity in scene.
  */
  class HK_CORE_EXPORT GameObject :
    public Node<GameObject>
  {
  public:

    /**
    * Empty game object.
    */
    GameObject();

    /**
    * Empty game object.
    */
    GameObject(const String& _name);

    /**
    * Empty game object.
    */
    GameObject(const String& _name, GameObject& _pParent);

    /**
    * Destructor.
    */
    ~GameObject();

    /**
    * Called by the scene manager when the scene is been created.
    */
    void
    init();

    /**
    * Called by the scene manager every cycle.
    */
    void
    update();

    /**
    * Add a new component to this game object.
    * 
    * @param _pComponent Component's pointer.
    * 
    * @return Operation result:
    * 
    * * kSuccess: The component was added successfully.
    * * kObjectAlreadyExists: A component of the same type already exists.
    * * kFail: An error occurs.
    */
    void
    addComponent(Component* _pComponent);

    /**
    * Check if the game object has a component.
    * 
    * @param _id Component's id.
    * 
    * @return True if the component exists, otherwise returns false.
    */
    bool
    hasComponent(const eCOMPONENT& _id);

    /**
    * Get a component.
    * 
    * @param _id Component's id.
    * 
    * @return Reference to the component.
    */
    template <class T>
    T&
    getComponent(const eCOMPONENT& _id);
  
    /**
    * Find, remove and destroy a component.
    * 
    * @param _id Component's id.
    */
    void
    detroyComponent(const eCOMPONENT& _id);

    /**
    * Checks if this GameObject belongs to a scene.
    *
    * @return True if the GameObject belongs to a scene, otherwise returns false.
    */
    bool
    onScene();

    /**
    * Get the scene this GameObject belongs to.
    * 
    * @return Scene.
    */
    Scene&
    getScene();

    /**
    * Safely destroys this game object.
    */
    void
    destroy();

  private:

    /**
    * Pointer to the scene where this GameObject belongs.
    */
    Scene*
    _m_pScene;

    /**
    * Map of components attached to this game object.
    */
    Map<eCOMPONENT, Component*>
    _m_hComponents;

    /**
    * Indicates if this gameObject is marked to be destroyed.
    */
    bool
    _m_toDestroy;

    /**
    * Indicates if the gameObject is already initialized.
    */
    bool
    _m_isInitialized;

    friend Scene;
  };

  template<class T>
  inline T& 
  GameObject::getComponent(const eCOMPONENT& _id)
  {
    if (!hasComponent(_id))
    {
      throw "GameObject: " + getName() + " doesn't has component.";
    }

    if (!IsBaseOf<Component, T>::value)
    {
      throw "GameObject: " + getName() + " cannot convert to a type that is not base of Component";
    }

    return reinterpret_cast<T&>(*(_m_hComponents.find(_id)->second));
  }
}