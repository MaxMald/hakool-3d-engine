#include "hakool/Utils/hkVertex.h"

namespace hk
{
  Vertex::Vertex() :
    x(0.0f),
    y(0.0f),
    z(0.0f)
  { }

  Vertex::Vertex(const float& _x, const float& _y, const float& _z) :
    x(_x),
    y(_y),
    z(_z)
  { }

  Vertex::Vertex(const Vertex& copy) :
    x(copy.x),
    y(copy.y),
    z(copy.z)
  { }
}