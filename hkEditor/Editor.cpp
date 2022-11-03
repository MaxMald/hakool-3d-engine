#include "Editor.h"

#include <QBoxLayout>
#include <QHBoxLayout>

#include <Hakool\hakool.h>
#include <Hakool/Core/hkCoreUtilities.h>
#include <Hakool/Core/hkScene.h>
#include <Hakool/Core/hkModelComponent.h>

#include "plainTextWidgetLogger.h"
#include "hkWindowQtWidget.h"
#include "hkWindowFactoryQtWidget.h"

using hk::Hakool;
using hk::Color;
using hk::PlainTextWidgetLogger;
using hk::Scene;
using hk::GameObject;
using hk::ModelComponent;

Editor::Editor(QWidget *parent) : 
  QMainWindow(parent),
  _m_pDefaultScene(nullptr)
{
    ui.setupUi(this);
}

Editor::~Editor()
{}

void 
Editor::init()
{
  Hakool::Start();
  Hakool* pEngine = Hakool::GetEngine();  

  hk::WindowFactoryQtWidget windowFactory(*pEngine, ui.viewGroup);

  hk::HakoolConfiguration engineConfig;
  engineConfig.windowConfiguration.height = 800;
  engineConfig.windowConfiguration.width = 800;
  engineConfig.graphicsConfiguration.graphicInterface = hk::eGRAPHIC_INTERFACE::kOpenGL;
  engineConfig.graphicsConfiguration.backgroundColor = hk::Color::BLACK;

  pEngine->init(engineConfig, new PlainTextWidgetLogger(), windowFactory);

  Scene& scene = pEngine->getSceneManager().create("Default");
  GameObject& cube = scene.createGameObject("cube");
  
  ModelComponent* pModelComponent = new ModelComponent(pEngine->getResourceManager());
  cube.addComponent(pModelComponent);
  pModelComponent->setMesh(pEngine->getResourceManager().getMeshes().getCube());
  cube.init();

  pEngine->getSceneManager().setActive("Default");
}