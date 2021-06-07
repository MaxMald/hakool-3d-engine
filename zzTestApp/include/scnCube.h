#pragma once

#include <Hakool\Core\hkScene.h>

using hk::Scene;

class SceneCube :
  public Scene
{
public:

  SceneCube();

  virtual ~SceneCube();

  virtual void
  start() override;

  virtual void
  enter() override;

  virtual void
  update() override;

  virtual void
  exit() override;

  virtual void
  destroy() override;
};