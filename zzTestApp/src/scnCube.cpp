#include "scnCube.h"

#include <Hakool\Utils\hkUtilitiesUtilities.h>
#include <Hakool\Utils\hkLogger.h>

#include <Hakool\Core\hkGameObject.h>

using hk::Logger;
using hk::eRESULT;
using hk::GameObject;

SceneCube::SceneCube()
{
}

SceneCube::~SceneCube()
{
}

void
SceneCube::start()
{
  GameObject& a = createGameObject("A");
  GameObject& b = createGameObject("B");
  GameObject* pC = new GameObject("C");

  registerGameObject(*pC);

  a.addChild(*pC);

  GameObject& parent = b.getParent();
  GameObject& child = a.getChild("C");

  a.removeChild(b.getName());
  
  if (a.hasParent()) {
    Logger::Log("A has a parent");
  }

  if (b.hasParent()) {
    Logger::Log("B has a parent");
  }

  b.addChild(a);

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
