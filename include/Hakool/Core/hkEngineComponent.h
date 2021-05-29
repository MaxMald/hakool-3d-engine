#pragma once

#include <Hakool\Core\hkCorePrerequisites.h>
#include <Hakool\Core\hkCoreUtilities.h>

namespace hk
{
  class Hakool;
  struct HakoolConfiguration;

  /**
  * Provides a common interface for all the engine components.
  */
  class HK_CORE_EXPORT EngineComponent
  {
  public:

    EngineComponent(const eENGINE_COMPONENT& _id);

    virtual
    ~EngineComponent();

    /**
    * Get this component identifier.
    * 
    * @return The id of the component.
    */
    eENGINE_COMPONENT
    getId();

  protected:

    /**
    * This method is called when the game engine has been initialized.
    * 
    * @param _config Engine configuration object.
    */
    virtual void
    _onEngineInit(HakoolConfiguration& _config);

    /**
    * This method is called when the game engine is going to be destroyed.
    */
    virtual void
    _onEngineDestroy();

    /**
    * This method is called once on each game loop.
    * 
    * @param _delta delta time in seconds.
    */
    virtual void
    _onUpdate(const float& _delta);

    /**
    * Instance of the game engine.
    */
    Hakool*
    _m_hakool;
  
    /**
    * The id of this component.
    */
    eENGINE_COMPONENT
    _m_componentId;

  private:

    /**
    * Initializes this component.
    * 
    * @param _config Engine configuration object.
    */
    void
    _init(HakoolConfiguration& _config);

    /**
    * Set the game engine reference of this component.
    * 
    * @param _hakool Game engine reference.
    */
    void
    _setHakool(Hakool& _hakool);

    friend class Hakool;
  };
}