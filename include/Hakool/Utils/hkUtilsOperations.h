#pragma once

#include<Hakool\Utils\hkUtilsPrerequisites.h>
#include <Hakool\Utils\hkMath.h>

namespace hk
{
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

  
  inline bool 
  RelativelyEqual(const float& _a, const float& _b)
  {
    float diff = Math::Abs(_a - _b);
    return diff <= Math::FLOAT_EPSILON * Math::Max(Math::Abs(_a), Math::Abs(_b));
  }
}