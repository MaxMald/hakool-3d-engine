#pragma once

#include <Hakool\Utils\hkUtilitiesUtilities.h>
#include <Hakool\Utils\hkColor.h>

#include <Hakool\Core\hkCorePrerequisites.h>

namespace hk
{
  /***************************************************************************/
  /* Enumerators                                                             */
  /***************************************************************************/

  /**
  * Enumerates the different types of shader used  by the Hakool Engine.
  */
  enum class HK_CORE_EXPORT eSHADER_TYPE :
    uchar
  {
    kUndefined,
    kFragment,
    kVertex,
    kGeometry,
    kTesselation
  };

  enum class HK_CORE_EXPORT eCAMERA_VIEW :
    uchar
  {
    kPerspective,
    kOrthographic
  };

  /**
  * Enumerates the different types of components (or modular systems) used by
  * the Hakool Engine.
  */
  enum class HK_CORE_EXPORT eENGINE_COMPONENT : 
    uchar
  {
    kUndefined,
    kGraphics
  };

  /**
  * Enumerates the different types of graphic APIs supported by the Hakool
  * Engine.
  */
  enum class HK_CORE_EXPORT eGRAPHIC_INTERFACE : 
    uchar
  {
    kUndefined,
    kOpenGL
  };

  /**
  * Enumerates the different types of component that a game object can has.
  */
  enum class HK_CORE_EXPORT eCOMPONENT :
    uchar
  {
    kUndefined,
    kModel
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
      graphicInterface(eGRAPHIC_INTERFACE::kUndefined),
      backgroundColor()
    {
      return;
    }
    
    /**
    * Indicates the preferred graphic API.
    */
    eGRAPHIC_INTERFACE
    graphicInterface;

    /**
    * Defines the background color of the screen. This is the color used when
    * the canvas is been cleared from the previous drawing.
    */
    Color
    backgroundColor;
  };

  /**
  * Configuration object used to describe the preferred properties of the 
  * Hakool Engine when initialized.
  */
  struct HK_CORE_EXPORT HakoolConfiguration
  {
  public:

    /**
    * Constructor.
    */
    HakoolConfiguration() :
      graphicsConfiguration(),
      windowConfiguration()
    {
      return;
    }

    /**
    * Configuration object used to describe the preferred properties of the 
    * Graphic System when initialized.
    */
    GraphicsConfiguration
    graphicsConfiguration;

    /**
    * Configuration object used to describe the preferred properties of the
    * Window when initialized.
    */
    WindowConfiguration
    windowConfiguration;
  };  
}

