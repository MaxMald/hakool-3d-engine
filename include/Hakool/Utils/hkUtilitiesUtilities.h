#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>
#include <Hakool\Utils\hkMath.h>

namespace hk
{
  class Window;

  /**
  *
  */
  enum class HK_UTILITY_EXPORT eRESULT
  {
    kFail,
    kSuccess,
    kObjectAlreadyExists,
    kObjectNotFound
  };

  /**
  *
  */
  enum class HK_UTILITY_EXPORT ePLATFORM
  {
    kUndefined,
    kWindows
  };

  /**
  * Configuration object that specifies the window's properties.
  */
  struct HK_UTILITY_EXPORT WindowConfiguration
  {
  public:
    /**
    * Constructor.
    */
    WindowConfiguration() :
      width(256),
      height(256),
      title("Hakool Window"),
      pWindow(nullptr)
    {
      return;
    }

    /**
    * Screen width in pixels.
    */
    uint32
    width;

    /**
    * Screen height in pixels.
    */
    uint32
    height;

    /**
    * The title of the window.
    */
    String
    title;

    /**
     * Window.
     */
    Window*
    pWindow;
  };

  /**
  * Check if two float values are relatively equal.
  *
  * @param _a Number.
  * @param _b Number.
  *
  * @return True if both numbers are relatively equal.
  */
  HK_UTILITY_EXPORT bool
  RelativelyEqual(const float& _a, const float& _b);

  /**
  *
  */
  inline bool
  RelativelyEqual(const float& _a, const float& _b)
  {
    float diff = Math::Abs(_a - _b);
    return diff <= Math::FLOAT_EPSILON * Math::Max(Math::Abs(_a), Math::Abs(_b));
  }

  /**
  * 
  */
  inline Queue<String>
  Split(const String& _string, const String& _delimiter)
  {
    Queue<String> pieces;

    hkSize start = 0;
    hkSize end = _string.find(_delimiter);

    while (end != String::npos)
    {
      pieces.push(_string.substr(start, end - start));
      start = end + _delimiter.length();
      end = _string.find(_delimiter, start);
    }

    return pieces;
  }
}