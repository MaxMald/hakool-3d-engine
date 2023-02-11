#include <Hakool/Core/hakool.h>
#include <Hakool/Utils/hkLoggerConsole.h>
#include <Hakool/Core/hkScene.h>
#include <Hakool/Core/hkModelComponent.h>
#include <Hakool/Core/hkCameraComponent.h>
#include <Hakool/Core/hkGraphicComponent.h>
#include <Hakool/Utils/hkIWindow.h>
#include <Hakool/GraphicsOpenGL/hkWindowOpenGL.h>
#include <imgui_impl_opengl3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <cameraComponentView.h>

using hk::IWindow;
using hk::Hakool;
using hk::HakoolConfiguration;
using hk::Color;
using hk::Logger;
using hk::LoggerConsole;
using hk::SceneManager;
using hk::Scene;
using hk::GameObject;
using hk::ModelComponent;
using hk::CameraManager;
using hk::CameraComponent;
using hk::GraphicComponent;
using hk::WindowOpenGL;
using hk::editor::CameraComponentView;

/**
 * 
 */
int main(int argc, char* argv[])
{  
  Hakool::Start();
  Hakool* pEngine = Hakool::GetEngine();

  HakoolConfiguration engineConfig;
  engineConfig.graphicsConfiguration.graphicInterface = hk::eGRAPHIC_INTERFACE::kOpenGL;
  engineConfig.graphicsConfiguration.backgroundColor = hk::Color::BLACK;
  engineConfig.windowConfiguration.width = 1200;
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
  CameraComponent* pCamera = new CameraComponent(pEngine->getCameraManager());
  pCamera->setAsActiveCamera();
  pCamera->dolly(-8.0f);
  cubeModel->setMesh(pEngine->getResourceManager().getMeshes().getCube());
  cube.addComponent(cubeModel);
  cube.init();

  CameraComponentView camView(pCamera);

  sceneManager.setActive("Test Scene");

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
  //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
  ImGui::StyleColorsDark();
  
  GraphicComponent* pGraphicComponent = pEngine->getGraphicComponent();
  WindowOpenGL* pWindowOpenGL = reinterpret_cast<WindowOpenGL*>(pGraphicComponent->getWindow());
  ImGui_ImplGlfw_InitForOpenGL(pWindowOpenGL->getGLFWindow(), true);
  ImGui_ImplOpenGL3_Init("#version 130");

  float time = 0;
  while (pEngine->isWindowOpen())
  {
    pEngine->clear();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Engine Status");    
    ImGui::Text("FPS %.1f", ImGui::GetIO().Framerate);
    ImGui::End();
    
    float dt = pEngine->getDeltaTime().asSeconds();
    time += dt;

    float x = hk::Math::Sin(time) * 3.0f;
    float y = hk::Math::Cos(time) * 3.0f;

    cube.setLocalPosition(x, y, cube.getLocalPosition().z);

    camView.updateController();

    pEngine->update();

    camView.draw();

    pEngine->draw();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    pEngine->present();
  }

  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  Hakool::Shutdown();
  Logger::Shutdown();
  return 1;
}