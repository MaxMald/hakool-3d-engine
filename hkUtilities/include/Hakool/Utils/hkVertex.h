#pragma once

#include "hkUtilsPrerequisites.h"

namespace hk
{
  struct HK_UTILITY_EXPORT Vertex
  {
  public:

    Vertex();

    Vertex(const float& x, const float& y, const float& z);

    explicit Vertex(const Vertex&);

    float
    x;

    float
    y;

    float
    z;
  };
}