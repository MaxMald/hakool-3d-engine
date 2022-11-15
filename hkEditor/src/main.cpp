#include <Hakool/Core/hakool.h>
#include <Hakool/Utils/hkLoggerConsole.h>
#include <Hakool/Core/hkScene.h>
#include <Hakool/Core/hkModelComponent.h>

using hk::Hakool;
using hk::HakoolConfiguration;
using hk::Color;
using hk::Logger;
using hk::LoggerConsole;
using hk::SceneManager;
using hk::Scene;
using hk::GameObject;
using hk::ModelComponent;

/**
 * 
 */
int main(int argc, char* argv[])
{  
  Hakool::Start();
  Hakool* pEngine = Hakool::GetEngine();

  HakoolConfiguration engineConfig;
  engineConfig.graphicsConfiguration.graphicInterface = hk::eGRAPHIC_INTERFACE::kOpenGL;
  engineConfig.graphicsConfiguration.backgroundColor = hk::Color::BLUE;
  engineConfig.windowConfiguration.width = 800;
  engineConfig.windowConfiguration.height = 800;
  engineConfig.windowConfiguration.title = "Hakool Editor";

  Logger::Prepare(new LoggerConsole());
  if (pEngine->init(engineConfig, &(Logger::GetReference())) != hk::eRESULT::kSuccess)
  {
    Hakool::Shutdown();
    Logger::Shutdown();
    return 0;
  }

  SceneManager& sceneManager = pEngine->getSceneManager();
  Scene& scene = sceneManager.create("Test Scene");
  GameObject& cube = scene.createGameObject("cube");
  ModelComponent* cubeModel = new ModelComponent(pEngine->getResourceManager());
  cubeModel->setMesh(pEngine->getResourceManager().getMeshes().getCube());
  cube.addComponent(cubeModel);
  cube.init();  

  sceneManager.setActive("Test Scene");

  float time = 0;
  while (pEngine->isWindowOpen())
  {
    float dt = pEngine->getDeltaTime().asSeconds();
    time += dt;
    float x = hk::Math::Sin(time) * 3.0f;
    float y = hk::Math::Cos(time) * 3.0f;

    cube.setLocalPosition(x, y, cube.getLocalPosition().z);

    pEngine->update();
    pEngine->draw();
  }

  Hakool::Shutdown();
  Logger::Shutdown();
  return 1;
}