#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>
#include <Hakool\Utils\hkUtilitiesUtilities.h>
#include <Hakool\Utils\hkConfigWindow.h>
#include <Hakool\Utils\hkVector2.h>

namespace hk
{
  class WindowObserver;

  /**
  * Provides a common interface for all specific-platform window instances.
  */
  class IWindow
  {
  public:

    IWindow() = default;

    virtual ~IWindow() = default;

    /**
    * Creates a new window using the specified configuration.
    *
    * @param _config Window preferred properties.
    * 
    * @returns Operation result.
    */
    virtual eRESULT
    init(const WindowConfiguration& _config) = 0;

    /**
    * Set the size of the rendering region of the window (pixels).
    * 
    * @param _width The width in pixels.
    * @param _heiht The height in pixels.
    */
    virtual void
    setSize(const uint32& _width, const uint32& _height) = 0;

    /**
    * Set the size of the rendering region of the window (pixels).
    *
    * @param _width The width in pixels.
    * @param _heiht The height in pixels.
    */
    virtual void
    setSize(const Vector2u& _v2) = 0;

    /**
    * Set the title of this window.
    * 
    * @param _title Window's title.
    */
    virtual void
    setTitle(const String& _title) = 0;

    /**
    * Get the window system handler.
    * 
    * @return Handler.
    */
    virtual HANDLER
    getWindowHandler() = 0;

    /**
    * Indicates if the window is open.
    * 
    * @return True if the window is open.
    */
    virtual bool
    isOpen() = 0;

    /**
     * 
     */
    virtual void
    pollEvents() = 0;

    /**
    * Called every frame.
    */
    virtual void
    update() = 0;

    /**
    * Called every frame after the update stage.
    */
    virtual void
    postUpdate() = 0;

    /**
     * Presents on screen what has been rendered to the window.
     */
    virtual void
    present() = 0;

    /**
    * Destroy this window and release its resources.
    */
    virtual void
    destroy() = 0;

    /**
     * Adds an observer to this Window.
     *
     * @param observer Observer.
     */
    virtual void
    addObserver(const WindowObserver* pObserver) = 0;

    /**
    * Get the size of the rendering region of the window (pixels).
    *
    * @return The size in pixels.
    */
    virtual Vector2u
    getSize() = 0;

    /**
    * Get the width of the rendering region of the window (pixels).
    * 
    * @return The window's width in pixels.
    */
    virtual uint32
    getWidth() = 0;

    /**
    * Get the height of the rendering region of the window (pixels).
    *
    * @return The window's height in pixels.
    */
    virtual uint32
    getHeight() = 0;

    /**
    * Get the name of the window.
    * 
    * @return Window's name.
    */
    virtual String
    getTitle() = 0;

    IWindow(const IWindow&) = delete;
    IWindow& operator= (const IWindow&) = delete;
  };
}