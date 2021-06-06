#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>

namespace hk
{
  /**
  * Holds a single color value.
  */
  class HK_UTILITY_EXPORT Color
  {
  public:

    /**
    * Creates a new color.
    * 
    * * red = 0.0f
    * * green = 0.0f
    * * blue = 0.0f
    * * alpha = 1.0f
    */
    Color();

    /**
    * Creates a new color. Alpha value will be 1.0f.
    * 
    * @param _r Red value.
    * @param _g Green value.
    * @param _b Blue value.
    */
    Color(const float& _r, const float& _g, const float& _b);

    /**
    * Create a new color.
    * 
    * @param _r Red value.
    * @param _g Green value.
    * @param _b Blue value.
    * @param _a Alpha value.
    */
    Color(const float& _r, const float& _g, const float& _b, const float& _a);

    /**
    * Creates a copy of another color.
    * 
    * @param _color prototype color.
    */
    Color(const Color& _color);

    /**
    * Destructor.
    */
    ~Color();

    /**
    * TODO
    * 
    * @param _color color.
    * 
    * @return self.
    */
    Color&
    operator=(const Color& _color);

    /**
    * Compares strict equality between two colors.
    * 
    * @param _color color.
    * 
    * @return True if both color are equal.
    */
    bool
    operator==(const Color& _color) const;

    /**
    * Set component values.
    * 
    * @param _r Red value.
    * @param _g Green value.
    * @param _b Blue value.
    */
    Color&
    set(const float& _r, const float& _g, const float& _b);

    /**
    * Set component values.
    *
    * @param _r Red value.
    * @param _g Green value.
    * @param _b Blue value.
    * @param _a Alpha value.
    */
    Color&
    set(const float& _r, const float& _g, const float& _b, const float& _a);

    union 
    {      
      float m[4];

      struct
      {
        float r, g, b, a;
      };
    };
  };
}