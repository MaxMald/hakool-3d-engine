#pragma once

#include <Hakool\Core\hkCorePrerequisites.h>

namespace hk
{
  /***************************************************************************/
  /* Enumerators                                                             */
  /***************************************************************************/

  /**
  * Enumerates the different types of components (or modular systems) used by
  * the Hakool Engine.
  */
  enum class HK_CORE_EXPORT eENGINE_COMPONENT
    : uchar
  {
    kUndefined,
    kGraphics
  };

  /**
  * Enumerates the different types of graphic APIs supported by the Hakool
  * Engine.
  */
  enum class HK_CORE_EXPORT eGRAPHIC_INTERFACE
    : uchar
  {
    kUndefined,
    kOpenGL
  };

  /***************************************************************************/
  /* Configuration Objects                                                   */
  /***************************************************************************/

  /**
  * Configuration object used to describe the preferred properties of the 
  * Graphic System when initialized.
  */
  struct HK_CORE_EXPORT GraphicsConfiguration
  {
  public:

    GraphicsConfiguration() :
      graphicInterface(eGRAPHIC_INTERFACE::kUndefined)
    {
      return;
    }
    
    /**
    * Indicates the preferred graphic API.
    */
    eGRAPHIC_INTERFACE
    graphicInterface;

  };

  /**
  * Configuration object used to describes the preferred properties of the 
  * Hakool Engine when initialized.
  */
  struct HK_CORE_EXPORT HakoolConfiguration
  {
  public:

    /**
    * Configuration object used to describe the preferred properties of the 
    * Graphic System when initialized.
    */
    GraphicsConfiguration
    graphicsConfiguration;

  };  
}

