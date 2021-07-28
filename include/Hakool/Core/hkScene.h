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
    * Get the root's node of the scene.
    * 
    * @return The GameObject that represent the root of this scene.
    */
    GameObject&
    getRoot();
    
    /**
    * Create a new GameObject and add it to the scene's root.
    * 
    * @param _name GameObject's name.
    * 
    * @return GameObject.
    */
    GameObject&
    createGameObject(String _name);

    /**
    * Create a new GameObject and add it as a child of another GameObject in the scene.
    * Returns the null object if the parent's is not found.
    *
    * @param _name GameObject's name.
    * @param _parentPath The parent's path.
    *
    * @return GameObject.
    */
    GameObject&
    createGameObject(String _name, String _parentPath);
    
    /**
    * Check if the GameObject exists in the given path.
    * 
    * @param _path The GameObject's path, relative to the Scene's root.
    * 
    * @return True if the GameObject exists.
    */
    bool
    hasGameObject(const String& _path);

    /**
    * Get the GameObject from the given path.
    * 
    * @param _path The GameObject's path, relative to the Scene's root.
    * 
    * @return Reference to the GameObject.
    */
    GameObject&
    getGameObject(const String& _path);

    /**
    * Get the scene manager.
    * 
    * @return The scene manager.
    */
    SceneManager&
    getSceneManager();

    /**
    * Register GameObject in this scene.
    * 
    * @param _gameObject GameObject.
    */
    void
    registerGameObject(GameObject& _gameObject);

    /**
    * Unregister GameObject from this scene.
    * 
    * @param _uuid GameObject's uuid.
    */
    void
    unregisterGameObject(const String& _uuid);

    /**
    * Unregister GameObject from this scene.
    * 
    * @param _gameObject GameObject.
    */
    void
    unregisterGameObject(GameObject& _gameObject);

    /**
    * Check if this scene has a registered GameObject.
    * 
    * @param _uuid GameObject's uuid.
    * 
    * @return True if the GameObject is registered in this scene.
    */
    bool
    hasRegisteredGameObject(const String& _uuid) const;

    /**
    * Check if the given GameObject is regitered in this scene.
    * 
    * @param _gameObject GameObject.
    * 
    * @return True if the GameObject is registerd in this scene.
    */
    bool
    hasRegisteredGameObject(const GameObject& _gameObject) const;

  protected:    

    /**
    * Constructor.
    */
    Scene();

    /**
    * Destructor.
    */
    virtual ~Scene();

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
    * Destroy the scene and all its resources.
    */
    void
    _destroy();

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
    * Map of registered GameObjects in this scene.
    */
    Map<String, GameObject*> _m_hGameObjects;

    friend SceneManager;
  };
}