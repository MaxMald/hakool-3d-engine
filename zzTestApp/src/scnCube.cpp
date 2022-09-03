#include "scnCube.h"

#include <Hakool\Utils\hkUtilitiesUtilities.h>
#include <Hakool\Utils\hkLogger.h>

#include <Hakool\Core\hkGameObject.h>
#include <Hakool\Core\hkModelComponent.h>

using hk::Logger;
using hk::eRESULT;
using hk::GameObject;
using hk::ModelComponent;

SceneCube::SceneCube()
{
}

SceneCube::~SceneCube()
{
}

void
SceneCube::start()
{
  GameObject& cube = createGameObject("A");
  
  // Create Model.
  ModelComponent* pModel = new ModelComponent();
  cube.addComponent(pModel);

  cube.init();

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
