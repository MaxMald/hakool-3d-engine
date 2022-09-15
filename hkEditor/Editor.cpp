#include "Editor.h"

#include <QBoxLayout>
#include <QHBoxLayout>

#include <Hakool\hakool.h>
#include <Hakool/Core/hkCoreUtilities.h>

#include "plainTextWidgetLogger.h"
#include "hkWindowQtWidget.h"
#include "hkWindowFactoryQtWidget.h"

using hk::Hakool;
using hk::Color;
using hk::PlainTextWidgetLogger;

Editor::Editor(QWidget *parent)
    : QMainWindow(parent)
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
  engineConfig.graphicsConfiguration.graphicInterface = hk::eGRAPHIC_INTERFACE::kOpenGL;
  engineConfig.graphicsConfiguration.backgroundColor = hk::Color::RED;

  pEngine->init(engineConfig, new PlainTextWidgetLogger(), windowFactory);
}
