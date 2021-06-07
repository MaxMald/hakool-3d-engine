#pragma once

#include <Hakool\Core\hkCorePrerequisites.h>

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

  protected:    

    /**
    * Constructor.
    */
    Scene();

    /**
    * Destructor.
    */
    virtual ~Scene();

    /**
    * Pointer to the engine.
    */
    Hakool*
    _m_pHakool;

    friend SceneManager;
  };
}