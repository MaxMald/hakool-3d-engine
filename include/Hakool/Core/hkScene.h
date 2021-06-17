#pragma once

#include <Hakool\Core\hkCorePrerequisites.h>
#include <Hakool\Core\hkGameObject.h>

namespace hk
{
  class Hakool;
  class SceneManager;

  /**
  * Base class that provides an interface which can be extended for custom
  * scenes.
  */
  class HK_CORE_EXPORT Scene
  {
  public:

    /**
    * Called by the engine when the application has started. This method can
    * be defined on extended classes.
    */
    virtual void
    start();

    /**
    * Called by the engine when is just been activated. This method can be 
    * defined on extended classes.
    */
    virtual void
    enter();

    /**
    * Called by the engine each frame. This method can be defined on extended
    * classes.
    */
    virtual void
    update();

    /**
    * Called by the engine when the scene is about to be deactivated. This method
    * can be defined on extended classes.
    */
    virtual void
    exit();

    /**
    * Called by the engine when the scene is about to be destroyed. This method 
    * can be defined on extended classes.
    */
    virtual void
    destroy();

    /**
    * Creates and adds a new GameObject to this scene's root.
    * 
    * The scene root behaves like a GameObject, in fact it is a GameObject, so
    * every child should have a unique name or won't be added to the scene.
    * 
    * @param _name The name of the GameObject.
    * 
    * @return GameOject.
    */
    GameObject&
    createGameObject(const String& _name);

    /**
    * Add a new game object to the scene's root. 
    *
    * The scene root behaves like a GameObject, in fact it is a GameObject, so
    * every child should have a unique name or won't be added to the scene.
    *
    * @param _pGameObject The pointer to the new game object.
    */
    void
    addGameObject(GameObject* _pGameObject);

    /**
    * Check if the scene's root has a GameObject.
    * 
    * @param _name The name of the GameObject.
    * 
    * @return True if the GameObject exists, otherwise returns false.
    */
    bool
    hasGameObject(const String& _name);

    /**
    * Get a GameObject from the scene's root.
    * 
    * @param _name The name of the GameObject.
    * 
    * @return GameObject.
    */
    GameObject&
    getGameObject(const String& _name);

    /**
    * Get the scene manager.
    * 
    * @return The scene manager.
    */
    SceneManager&
    getSceneManager();

  protected:    

    /**
    * Constructor.
    */
    Scene();

    /**
    * Destructor.
    */
    virtual ~Scene();

    // TODO REMOVE GAME OBJECT METHOD

    // TODO DESTROY GAME OBJECT METHOD

  private:

    /**
    * Called by the engine when the application has started.
    */
    void
    _start();

    /**
    * Called by the engine when is just been activated.
    */
    void
    _enter();

    /**
    * Called by the engine each frame.
    */
    void
    _update();

    /**
    * Called by the engine when the scene is about to be deactivated.
    */
    void
    _exit();

    /**
    * Pointer to the scene manager.
    */
    SceneManager*
    _m_pSceneManager;

    /**
    * The root of the game object.
    */
    GameObject
    _m_root;

    /**
    * List of gameObjects.
    */
    Map<String, GameObject*>
    _m_hGameObjects;

    /**
    * List of gameObjects that are flagged to be destroyed.
    */
    Vector<GameObject*>
    _m_lTrashCan;

    friend SceneManager;
  };
}