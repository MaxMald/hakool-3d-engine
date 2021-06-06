#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>
#include <Hakool\Utils\hkUtilitiesUtilities.h>
#include <Hakool\Utils\hkConfigWindow.h>
#include <Hakool\Utils\hkVector2.h>

namespace hk
{
  /**
  * Provides a common interface for all specific-platform window instances.
  */
  class HK_UTILITY_EXPORT Window
  {
  public:

    /**
    * Constructor.
    */
    Window();

    /**
    * Closes the window and frees all the resources attached to it.
    */
    virtual ~Window();

    /**
    * Creates a new window using the specified configuration.
    *
    * @param _config Window preferred properties.
    * 
    * @returns Operation result.
    */
    virtual eRESULT
    init(const WindowConfiguration& _config);

    /**
    * Set the size of the rendering region of the window (pixels).
    * 
    * @param _width The width in pixels.
    * @param _heiht The height in pixels.
    */
    virtual void
    setSize(const uint32& _width, const uint32& _height);

    /**
    * Set the size of the rendering region of the window (pixels).
    *
    * @param _width The width in pixels.
    * @param _heiht The height in pixels.
    */
    virtual void
    setSize(const Vector2u& _v2);

    /**
    * Set the title of this window.
    * 
    * @param _title Window's title.
    */
    virtual void
    setTitle(const String& _title);

    /**
    * Get the window system handler.
    * 
    * @return Handler.
    */
    virtual HANDLER
    getWindowHandler();

    /**
    * Indicates if the window is open.
    * 
    * @return True if the window is open.
    */
    virtual bool
    isOpen();

    /**
    * Called every frame.
    */
    virtual void
    update();

    /**
    * Called every frame after the update stage.
    */
    virtual void
    postUpdate();

    /**
    * Destroy this window and release its resources.
    */
    virtual void
    destroy();

    /**
    * Get the size of the rendering region of the window (pixels).
    *
    * @return The size in pixels.
    */
    Vector2u
    getSize();

    /**
    * Get the width of the rendering region of the window (pixels).
    * 
    * @return The window's width in pixels.
    */
    uint32
    getWidth();

    /**
    * Get the height of the rendering region of the window (pixels).
    *
    * @return The window's height in pixels.
    */
    uint32
    getHeight();

    /**
    * Get the name of the window.
    * 
    * @return Window's name.
    */
    String
    getTitle();

  protected:

    /**
    * The title of the Window.
    */
    String 
    _m_title;

    /**
    * The size of the Window.
    */
    Vector2u 
    _m_size;
  };
}