#include "scnCube.h"

#include <Hakool\Utils\hkLogger.h>

using hk::Logger;

SceneCube::SceneCube()
{
}

SceneCube::~SceneCube()
{
}

void
SceneCube::start()
{
  Logger::Log("-Start-");
  return;
}

void 
SceneCube::enter()
{
  Logger::Log("-Enter-");
  return;
}

void 
SceneCube::update()
{
  return;
}

void 
SceneCube::exit()
{
  Logger::Log("-Exit-");
}

void 
SceneCube::destroy()
{
  Logger::Log("-Destroy-");
}
