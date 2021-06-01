#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>
#include <Hakool\Utils\hkVector2.h>

namespace hk
{
  /**
  * TODO
  */
  class HK_UTILITY_EXPORT Window
  {
  public:

    Window();

    /**
    * Closes the window and frees all the resources attached to it.
    */
    virtual ~Window();

    /**
    * Creates a new window with the size and title specified.
    *
    * @param _width The width of the window.
    * @param _height The height of the window.
    * @param _title The title of the window.
    */
    virtual void
    init
    (
      const uint32& _width,
      const uint32& _height,
      const String& _title
    );

    /**
    * Close Window.
    */
    virtual void
    close();   

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
    * @para _title Window's title.
    */
    virtual void
    setTitle(const String& _title);

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