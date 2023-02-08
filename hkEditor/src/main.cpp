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

    // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
    {
      static float f = 0.0f;
      static int counter = 0;

      
      ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

      ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
      ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
      if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
        counter++;
      ImGui::SameLine();
      ImGui::Text("counter = %d", counter);

      ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
      ImGui::End();
    }

    float dt = pEngine->getDeltaTime().asSeconds();
    time += dt;
    float x = hk::Math::Sin(time) * 3.0f;
    float y = hk::Math::Cos(time) * 3.0f;

    cube.setLocalPosition(x, y, cube.getLocalPosition().z);

    pEngine->update();
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