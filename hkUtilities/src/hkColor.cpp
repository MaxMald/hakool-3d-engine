#include <Hakool\Utils\hkColor.h>

namespace hk
{
  const Color Color::RED = Color(1.0f, 0.0f, 0.0f);
  const Color Color::BLACK = Color(0.0f, 0.0f, 0.0f);
  const Color Color::GREEN = Color(0.0f, 1.0f, 0.0f);
  const Color Color::BLUE = Color(0.0f, 0.0f, 1.0f);
  const Color Color::WHITE = Color(1.0f, 1.0f, 1.0f);
  const Color Color::CYAN = Color(0.0f, 1.0f, 1.0f);
  const Color Color::MAGENTA = Color(1.0f, 0.0f, 1.0f);
  const Color Color::YELLOW = Color(1.0f, 1.0f, 0.0f);

  Color::Color() :
    r(0.0f),
    g(0.0f),
    b(0.0f),
    a(1.0f)
  {
    return;
  }

  Color::Color(const float& _r, const float& _g, const float& _b) :
    r(_r),
    g(_g),
    b(_b),
    a(1.0f)
  {
    return;
  }

  Color::Color(const float& _r, const float& _g, const float& _b, const float& _a) :
    r(_r),
    g(_g),
    b(_b),
    a(_a)
  {
    return;
  }

  Color::Color(const Color& _color) :
    r(_color.r),
    g(_color.g),
    b(_color.b),
    a(_color.a)
  {
    return;
  }

  Color::~Color()
  {
    return;
  }

  Color& 
  Color::operator=(const Color& _color)
  {
    r = _color.r;
    g = _color.g;
    b = _color.b;
    a = _color.a;

    return *this;
  }

  bool 
  Color::operator==(const Color& _color) const
  {
    return (r == _color.r && g == _color.g && b == _color.b && a == _color.a);
  }

  Color& 
  Color::set(const float& _r, const float& _g, const float& _b)
  {
    r = _r;
    g = _g;
    b = _b;

    return *this;
  }

  Color& 
  Color::set(const float& _r, const float& _g, const float& _b, const float& _a)
  {
    r = _r;
    g = _g;
    b = _b;
    a = _a;

    return *this;
  }

  Vector3f
  Color::toVector3() const
  {
    return Vector3f(r, g, b);
  }

  Vector4f
  Color::toVector4() const
  {
    return Vector4f(r, g, b, a);
  }
}