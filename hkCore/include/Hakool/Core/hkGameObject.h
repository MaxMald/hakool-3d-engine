#pragma once

#include <Hakool\Utils\hkUtilitiesUtilities.h>
#include <Hakool\Utils\hkLogger.h>
#include <Hakool/Utils/hkVector3.h>
#include <Hakool/Utils/hkMatrix4.h>
#include <Hakool\Core\hkCorePrerequisites.h>
#include <Hakool\Core\hkCoreUtilities.h>
#include <Hakool\Core\hkIGameObjectComponent.h>
#include <Hakool\Core\hkNode.h>

namespace hk
{
  class Scene;
  class GraphicComponent;

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
    * Comparison between two GameObjects.
    * 
    * @param _gameObject GameObject.
    * 
    * @return True if both GameObjects have the same uuid value.
    */
    bool
    operator==(const GameObject& _gameObject);

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
     * TODO
     */
    void
    draw(GraphicComponent* pGraphicComponet);

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
    addComponent(IGameObjectComponent* _pComponent);

    /**
    * Check if the game object has a component.
    * 
    * @param _id Component's id.
    * 
    * @return True if the component exists, otherwise returns false.
    */
    bool
    hasComponent(const eCOMPONENT& _id) const;

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
    hasScene() const;

    /**
    * Get the scene this GameObject belongs to.
    * 
    * @return Scene.
    */
    Scene&
    getScene();

    /**
    * Get a GameObject by a relative path.
    * 
    * @param _path Relative path.
    * 
    * @return GameObject.
    */
    GameObject&
    getGameObjectByPath(String _path);

    /**
    * Get GameObject's UUID.
    * 
    * @return GameObject's UUID.
    */
    String
    getUUID() const;

    const Vector3f&
    getLocalPosition() const;

    void
    setLocalPosition(const Vector3f&);

    void
    setLocalPosition(const float& x, const float& y, const float& z);

    Matrix4
    calculateLocalToParentMatrix();

    /**
    * Safely destroys this GameObject. Destroys and deletes its children.
    */
    void
    destroy();

  protected:

    virtual void
    _onParentChanged(GameObject* pGameObject) override;

    void
    _setScene(Scene* pScene);

    const Matrix4&
    _updateLocalToWorld();

    void
    _setDirty();

    Vector3f
    _m_localPosition;

    Vector3f
    _m_localRotation;

    Vector3f
    _m_localScale;

    Matrix4
    _m_localToWorld;

    Matrix4
    _m_worldToLocal;

    Matrix4
    _m_modelMatrix;

    float
    _m_isDirty;

    float
    _m_isInverseDirty;

  private:

    /**
    * Pointer to the scene where this GameObject belongs.
    */
    Scene*
    _m_pScene;

    /**
    * Map of components attached to this game object.
    */
    Map<eCOMPONENT, IGameObjectComponent*>
    _m_hComponents;

    /**
    * Indicates if this GameObject is marked to be destroyed.
    */
    bool
    _m_toDestroy;

    /**
    * Indicates if the GameObject is already initialized.
    */
    bool
    _m_isInitialized;

    /**
    * Unique identifier of this gameObject.
    */
    String
    _m_uuid;

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

    if (!IsBaseOf<IGameObjectComponent, T>::value)
    {
      throw "GameObject: " + getName() + " cannot convert to a type that is not base of Component";
    }

    return reinterpret_cast<T&>(*(_m_hComponents.find(_id)->second));
  }
}