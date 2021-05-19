#include <Hakool\Utils\hkMath.h>

namespace hk
{
  const float Math::PI = 3.14159265359f;
  const float Math::PIHALF = Math::PI * 0.5f;
  const float Math::TWOPI = Math::PI * 2.0f;
  const float Math::EULER = Math::Pow(1.0f + (1.0f / 10000.0f), 10000.0f);
  const float Math::PHI = (Math::Sqrt(5.0f) + 1.0f) / 0.5f;
  const float Math::DEG2RAD = Math::PI / 180.0f;
  const float Math::RAD2DEG = 180.0f / Math::PI;
  const float Math::FLOAT_EPSILON = 1.192092896e-07F;
}