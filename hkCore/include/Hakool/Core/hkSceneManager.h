#pragma once

#include <Hakool\Core\hkCorePrerequisites.h>
#include <Hakool\Core\hkCoreUtilities.h>

namespace hk
{
  class Hakool;
  class Scene;
  class GraphicComponent;

  /**
  * Create, process and updates all the scenes of the application.
  */
  class HK_CORE_EXPORT SceneManager
  {
  public:

    /**
    * Constructor.
    */
    SceneManager();

    /**
    * Destructor.
    */
    ~SceneManager();

    /**
    * Initialize the scene manager.
    * 
    * @param _pHakool Pointer to the engine.
    */
    void
    init(Hakool* _pHakool);

    /**
    * Updates the active scene.
    */
    void
    update();

    /**
    * Set the active scene.
    * 
    * @param The scene's identifier.
    * 
    * @return 'Success' if the scene was found. Returns 'ObjectNotFound' if 
    * the given key was not found.
    */
    eRESULT
    setActive(const String& _key);

    /**
    * Get the pointer to the active scene.
    * 
    * @return The pointer to the active scene. Returns null pointer if there
    * is not an active scene.
    */
    Scene*
    getActive();

    /**
     * Creates and returns a new Scene.
     * 
     * @param key Scene's key.
     * 
     * @return The new Scene.
     */
    Scene&
    create(const String& key);

    /**
    * Add a new scene to the scene manager. 
    
    * Returns 'ObjectAlreadyExits' if another scene has the same key; take into
    * account that the pointer will be deleted.
    * 
    * @param _key The scene identifier.
    * @param _pScene The pointer to the scene.
    * 
    * @return 'Success' if the scene was added without problems. Returns 
    * 'ObjectAlreadyExists' if there is another scene with the same key.
    */
    eRESULT
    add(const String& _key, Scene* _pScene);

    /**
    * Remove and delete the associated scene with the given key. If the key wasn't found,
    * it will return 'ObjectNotFound'.
    * 
    * @param _key The scene identifier.
    * 
    * @return 'Success' if the scene was removed and deleted. Returns ''ObjectNotFound'
    * if the key was not found.
    */
    eRESULT
    remove(const String& _key);

    /**
    * Get the associated scene with the given key. If the key wasn't found,
    * it will return a null pointer.
    * 
    * @param _key The scene identifier.
    * 
    * @return The pointer to the associated scene. Returns a null pointer if
    * the key wasn't found.
    */
    Scene*
    get(const String& _key);

    /**
    * Check if there is a registered key with the given value.
    * 
    * @param _key The scene identifier.
    * 
    * @return True if the key was found, otherwise returns false.
    */
    bool
    has(const String& _key);

    /**
     * Indicates if this SceneManager has an active scene.
     * 
     * @return True if the SceneManager has an active scene.
     */
    bool
    hasActiveScene();

    /**
     * Draw method.
     * 
     * @param pGraphicComponent GraphicComponent.
     */
    void
    draw(GraphicComponent* pGraphicComponent);

    /**
    * Remove and delete all the registered scenes in this scene manager.
    */
    void
    clear();

    /**
    * Safely destroys the scene manager.
    */
    void
    destroy();

  private:

    /**
    * Pointer to the engine.
    */
    Hakool* 
    _m_pHakool;

    /**
    * Table of registered scenes.
    */
    Map<String, Scene*>
    _m_hScenes;

    /**
    * Pointer to the active scene.
    */
    Scene*
    _m_pActiveScene;

    /**
    * Indicates if the scene manager is been updating.
    */
    bool
    _m_isUpdating;

    /**
    * Indicates if a scene transition was requested and has not been attended.
    */
    bool
    _m_transitionRequested;

    /**
    * Indicates if the scene is initialized.
    */
    bool
    _m_isInitialized;

    /**
    * Pointer to the next scene that will be activated.
    */
    Scene*
    _m_pNextScene;
  };
}