#pragma once

namespace hk
{
  namespace editor
  {
    class ImguiView
    {
    public:

      ImguiView() = default;

      virtual ~ImguiView() = default;

      virtual void
      update() = 0;

      virtual void
      draw() = 0;
    };
  }
}