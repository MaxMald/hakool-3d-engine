#pragma once

#include <Hakool/Core/hkCorePrerequisites.h>
#include <Hakool/Core/hkComponent.h>
#include <Hakool/Core/Graphics/hkModel.h>

namespace hk
{
  /**
  * TODO
  */
  class HK_CORE_EXPORT ModelComponent :
    public Component
  {
  public:
    
    /**
    * Constructor.
    */
    ModelComponent();

    /**
    * Destructor.
    */
    virtual ~ModelComponent();

    /**
    * Called when the game object is been created.
    */
    virtual void
    create() override;

    /**
    * Called when the game object is been initialized.
    */
    virtual void
    init() override;

    /**
    * Called every game cycle.
    */
    virtual void
    update() override;

    /**
    * Called when the game object is been destroyed.
    */
    virtual void
    destroy() override;

  private:

    /**
    * Model.
    */
    Model
    _m_model;
  };
}